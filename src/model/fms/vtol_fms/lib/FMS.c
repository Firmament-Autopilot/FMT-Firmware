/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2595
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Oct 15 11:39:04 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S139>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S179>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<S734>/Motion Status' */
#define FMS_IN_Brake_bq                ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S744>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_ol                 ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S440>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S662>/Motion State' */
#define FMS_IN_Brake_m                 ((uint8_T)1U)
#define FMS_IN_Hold_ow                 ((uint8_T)2U)
#define FMS_IN_Move_a                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)

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
  1250U,
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
                                        *   '<S7>/Land_Lock_Thro'
                                        *   '<S40>/Constant'
                                        *   '<S786>/Constant1'
                                        *   '<S787>/Constant'
                                        *   '<S789>/Constant1'
                                        *   '<S790>/FW_ACCEPT_R'
                                        *   '<S790>/MC_ACCEPT_R'
                                        *   '<S793>/Constant'
                                        *   '<S53>/Gain1'
                                        *   '<S53>/Gain2'
                                        *   '<S53>/Gain6'
                                        *   '<S54>/Saturation1'
                                        *   '<S116>/Dead Zone'
                                        *   '<S116>/Gain'
                                        *   '<S117>/Dead Zone'
                                        *   '<S117>/Gain'
                                        *   '<S118>/Dead Zone'
                                        *   '<S118>/Gain'
                                        *   '<S269>/Dead Zone'
                                        *   '<S269>/Gain'
                                        *   '<S270>/Dead Zone'
                                        *   '<S270>/Gain'
                                        *   '<S271>/Dead Zone'
                                        *   '<S271>/Gain'
                                        *   '<S272>/Dead Zone'
                                        *   '<S272>/Gain'
                                        *   '<S275>/Constant4'
                                        *   '<S276>/Constant4'
                                        *   '<S644>/L1'
                                        *   '<S57>/L1'
                                        *   '<S58>/Gain6'
                                        *   '<S96>/Constant'
                                        *   '<S97>/Constant'
                                        *   '<S135>/Gain'
                                        *   '<S136>/Gain1'
                                        *   '<S137>/Saturation1'
                                        *   '<S160>/Gain1'
                                        *   '<S162>/Saturation1'
                                        *   '<S227>/Gain'
                                        *   '<S227>/Gain1'
                                        *   '<S228>/Gain1'
                                        *   '<S278>/Gain2'
                                        *   '<S278>/Saturation1'
                                        *   '<S279>/L1'
                                        *   '<S279>/R'
                                        *   '<S279>/Saturation1'
                                        *   '<S296>/Gain'
                                        *   '<S296>/Saturation1'
                                        *   '<S318>/Gain'
                                        *   '<S318>/Saturation1'
                                        *   '<S353>/Gain'
                                        *   '<S353>/Gain1'
                                        *   '<S430>/Gain'
                                        *   '<S430>/Gain1'
                                        *   '<S432>/Constant'
                                        *   '<S456>/L1'
                                        *   '<S537>/Saturation'
                                        *   '<S538>/Saturation1'
                                        *   '<S538>/Saturation2'
                                        *   '<S538>/Saturation3'
                                        *   '<S695>/Land_Speed'
                                        *   '<S696>/Saturation1'
                                        *   '<S775>/Takeoff_Speed'
                                        *   '<S776>/Gain2'
                                        *   '<S776>/Saturation1'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        *   '<S138>/Saturation1'
                                        *   '<S150>/Dead Zone'
                                        *   '<S150>/Gain'
                                        *   '<S153>/Dead Zone'
                                        *   '<S153>/Gain'
                                        *   '<S156>/Constant'
                                        *   '<S156>/Constant1'
                                        *   '<S156>/Constant2'
                                        *   '<S163>/Saturation1'
                                        *   '<S175>/Dead Zone'
                                        *   '<S175>/Gain'
                                        *   '<S178>/Saturation1'
                                        *   '<S224>/Constant'
                                        *   '<S224>/Constant1'
                                        *   '<S224>/Constant2'
                                        *   '<S230>/Dead Zone'
                                        *   '<S230>/Gain'
                                        *   '<S231>/Dead Zone'
                                        *   '<S231>/Gain'
                                        *   '<S236>/Dead Zone'
                                        *   '<S236>/Gain'
                                        *   '<S244>/Gain'
                                        *   '<S244>/Saturation1'
                                        *   '<S245>/Constant4'
                                        *   '<S245>/Saturation'
                                        *   '<S301>/L1'
                                        *   '<S301>/Saturation1'
                                        *   '<S323>/L1'
                                        *   '<S323>/Saturation1'
                                        *   '<S355>/Saturation1'
                                        *   '<S367>/Dead Zone'
                                        *   '<S367>/Gain'
                                        *   '<S368>/Dead Zone'
                                        *   '<S368>/Gain'
                                        *   '<S373>/Saturation'
                                        *   '<S389>/Saturation1'
                                        *   '<S401>/Saturation'
                                        *   '<S414>/Saturation1'
                                        *   '<S433>/Dead Zone'
                                        *   '<S433>/Gain'
                                        *   '<S434>/Dead Zone'
                                        *   '<S434>/Gain'
                                        *   '<S439>/Saturation'
                                        *   '<S593>/Gain2'
                                        *   '<S600>/Gain1'
                                        *   '<S600>/Gain2'
                                        *   '<S650>/Saturation1'
                                        *   '<S661>/Saturation'
                                        *   '<S682>/Saturation1'
                                        *   '<S697>/Constant'
                                        *   '<S700>/Gain2'
                                        *   '<S724>/Constant'
                                        *   '<S724>/vel'
                                        *   '<S724>/Acceleration_Speed'
                                        *   '<S724>/Saturation'
                                        *   '<S724>/Switch'
                                        *   '<S728>/Constant'
                                        *   '<S140>/Gain2'
                                        *   '<S141>/Gain1'
                                        *   '<S148>/Constant'
                                        *   '<S165>/Gain2'
                                        *   '<S166>/Gain1'
                                        *   '<S173>/Constant'
                                        *   '<S180>/L1'
                                        *   '<S181>/Gain6'
                                        *   '<S219>/Constant'
                                        *   '<S220>/Constant'
                                        *   '<S252>/L1'
                                        *   '<S252>/Saturation1'
                                        *   '<S358>/Gain2'
                                        *   '<S359>/Gain1'
                                        *   '<S365>/Constant'
                                        *   '<S376>/Gain2'
                                        *   '<S377>/Gain1'
                                        *   '<S384>/Constant'
                                        *   '<S392>/Gain2'
                                        *   '<S393>/Gain1'
                                        *   '<S399>/Constant'
                                        *   '<S404>/Gain2'
                                        *   '<S405>/Gain1'
                                        *   '<S412>/Constant'
                                        *   '<S416>/Gain2'
                                        *   '<S417>/Gain6'
                                        *   '<S427>/Constant'
                                        *   '<S428>/Constant'
                                        *   '<S442>/Gain2'
                                        *   '<S443>/Gain1'
                                        *   '<S450>/Constant'
                                        *   '<S475>/Gain'
                                        *   '<S475>/Saturation1'
                                        *   '<S478>/Constant'
                                        *   '<S478>/vel'
                                        *   '<S478>/Switch'
                                        *   '<S653>/Gain2'
                                        *   '<S654>/Gain1'
                                        *   '<S665>/Gain2'
                                        *   '<S666>/Gain1'
                                        *   '<S674>/Gain2'
                                        *   '<S674>/Saturation'
                                        *   '<S675>/Integrator'
                                        *   '<S685>/Gain2'
                                        *   '<S686>/Gain6'
                                        *   '<S709>/Gain2'
                                        *   '<S709>/Saturation'
                                        *   '<S710>/Integrator'
                                        *   '<S144>/Dead Zone'
                                        *   '<S144>/Gain'
                                        *   '<S169>/Dead Zone'
                                        *   '<S169>/Gain'
                                        *   '<S216>/Dead Zone'
                                        *   '<S216>/Gain'
                                        *   '<S361>/Land_Speed'
                                        *   '<S362>/Constant'
                                        *   '<S364>/Dead Zone'
                                        *   '<S364>/Gain'
                                        *   '<S381>/Dead Zone'
                                        *   '<S381>/Gain'
                                        *   '<S395>/Land_Speed'
                                        *   '<S396>/Constant'
                                        *   '<S398>/Dead Zone'
                                        *   '<S398>/Gain'
                                        *   '<S409>/Dead Zone'
                                        *   '<S409>/Gain'
                                        *   '<S421>/Dead Zone'
                                        *   '<S421>/Gain'
                                        *   '<S422>/Dead Zone'
                                        *   '<S422>/Gain'
                                        *   '<S447>/Dead Zone'
                                        *   '<S447>/Gain'
                                        *   '<S462>/Gain2'
                                        *   '<S462>/Saturation'
                                        *   '<S463>/Integrator'
                                        *   '<S656>/Dead Zone'
                                        *   '<S656>/Gain'
                                        *   '<S670>/Dead Zone'
                                        *   '<S670>/Gain'
                                        *   '<S690>/Dead Zone'
                                        *   '<S690>/Gain'
                                        *   '<S691>/Dead Zone'
                                        *   '<S691>/Gain'
                                        *   '<S733>/Saturation1'
                                        *   '<S743>/Saturation1'
                                        *   '<S493>/Saturation1'
                                        *   '<S503>/Saturation1'
                                        *   '<S736>/Gain2'
                                        *   '<S737>/Gain1'
                                        *   '<S746>/Gain2'
                                        *   '<S747>/Gain6'
                                        *   '<S496>/Gain2'
                                        *   '<S497>/Gain1'
                                        *   '<S506>/Gain2'
                                        *   '<S507>/Gain6'
                                        *   '<S739>/Dead Zone'
                                        *   '<S739>/Gain'
                                        *   '<S751>/Dead Zone'
                                        *   '<S751>/Gain'
                                        *   '<S752>/Dead Zone'
                                        *   '<S752>/Gain'
                                        *   '<S499>/Dead Zone'
                                        *   '<S499>/Gain'
                                        *   '<S511>/Dead Zone'
                                        *   '<S511>/Gain'
                                        *   '<S512>/Dead Zone'
                                        *   '<S512>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S7>/Constant1'
                                        *   '<S26>/Constant1'
                                        *   '<S785>/Constant'
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
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static void FMS_sf_msg_send_VTOL_M(void);
static void FMS_enter_internal_VTOL_Land(void);
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_VTOL_Land(void);
static void FMS_exit_internal_Mission(void);
static void FMS_Mission(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Auto(void);
static void FMS_enter_internal_Arm(void);
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
 *    '<S325>/NearbyRefWP'
 *    '<S303>/NearbyRefWP'
 *    '<S254>/NearbyRefWP'
 *    '<S726>/NearbyRefWP'
 *    '<S480>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S329>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S325>/SearchL1RefWP'
 *    '<S303>/SearchL1RefWP'
 *    '<S254>/SearchL1RefWP'
 *    '<S726>/SearchL1RefWP'
 *    '<S480>/SearchL1RefWP'
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

  /* SignalConversion: '<S331>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S303>/OutRegionRegWP'
 *    '<S254>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S308>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S128>/Unknown'
 *    '<S126>/Unknown'
 *    '<S125>/Unknown'
 *    '<S49>/Unknown'
 *    '<S343>/Unknown'
 *    '<S341>/Unknown'
 *    '<S340>/Unknown'
 *    '<S50>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S277>/Bus Assignment' incorporates:
   *  Constant: '<S277>/Constant'
   *  Constant: '<S277>/Constant2'
   *  SignalConversion: '<S277>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S277>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S138>/Hold Control'
 *    '<S163>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S140>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S138>/Hold Control'
 *    '<S163>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S140>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S138>/Hold Control'
 *    '<S163>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S140>/Delay' incorporates:
   *  Gain: '<S143>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S140>/Gain2' incorporates:
   *  Delay: '<S140>/Delay'
   *  Gain: '<S143>/Gain'
   *  Sum: '<S140>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S140>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S138>/Move Control'
 *    '<S163>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S138>/Move Control'
 *    '<S163>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S138>/Move Control'
 *    '<S163>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_cx;
  real32_T rtb_a_ft;
  real32_T rtb_Add4_pq;
  real32_T rtb_a_m;

  /* Product: '<S146>/Multiply1' incorporates:
   *  Constant: '<S146>/const1'
   *  DiscreteIntegrator: '<S145>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S144>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_ft = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_ft = 0.0F;
  } else {
    rtb_a_ft = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S144>/Dead Zone' */

  /* Sum: '<S146>/Add' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator1'
   *  Gain: '<S141>/Gain1'
   *  Gain: '<S144>/Gain'
   *  Sum: '<S145>/Subtract'
   */
  rtb_Subtract3_cx = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_ft * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_a;

  /* Signum: '<S146>/Sign' */
  if (rtb_Subtract3_cx < 0.0F) {
    rtb_a_ft = -1.0F;
  } else if (rtb_Subtract3_cx > 0.0F) {
    rtb_a_ft = 1.0F;
  } else {
    rtb_a_ft = rtb_Subtract3_cx;
  }

  /* End of Signum: '<S146>/Sign' */

  /* Sum: '<S146>/Add2' incorporates:
   *  Abs: '<S146>/Abs'
   *  Gain: '<S146>/Gain'
   *  Gain: '<S146>/Gain1'
   *  Product: '<S146>/Multiply2'
   *  Product: '<S146>/Multiply3'
   *  Sqrt: '<S146>/Sqrt'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Subtract'
   */
  rtb_a_ft = (sqrtf((8.0F * fabsf(rtb_Subtract3_cx) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_ft + rtb_Add3_a;

  /* Sum: '<S146>/Add4' */
  rtb_Add4_pq = (rtb_Subtract3_cx - rtb_a_ft) + rtb_Add3_a;

  /* Sum: '<S146>/Add3' */
  rtb_Add3_a = rtb_Subtract3_cx + localC->d;

  /* Sum: '<S146>/Subtract1' */
  rtb_Subtract3_cx -= localC->d;

  /* Signum: '<S146>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign1' */

  /* Signum: '<S146>/Sign2' */
  if (rtb_Subtract3_cx < 0.0F) {
    rtb_Subtract3_cx = -1.0F;
  } else {
    if (rtb_Subtract3_cx > 0.0F) {
      rtb_Subtract3_cx = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign2' */

  /* Sum: '<S146>/Add5' incorporates:
   *  Gain: '<S146>/Gain2'
   *  Product: '<S146>/Multiply4'
   *  Sum: '<S146>/Subtract2'
   */
  rtb_a_ft += (rtb_Add3_a - rtb_Subtract3_cx) * 0.5F * rtb_Add4_pq;

  /* SignalConversion: '<S141>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S145>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S146>/Add6' */
  rtb_Add3_a = rtb_a_ft + localC->d;

  /* Sum: '<S146>/Subtract3' */
  rtb_Subtract3_cx = rtb_a_ft - localC->d;

  /* Signum: '<S146>/Sign5' */
  if (rtb_a_ft < 0.0F) {
    rtb_Add4_pq = -1.0F;
  } else if (rtb_a_ft > 0.0F) {
    rtb_Add4_pq = 1.0F;
  } else {
    rtb_Add4_pq = rtb_a_ft;
  }

  /* End of Signum: '<S146>/Sign5' */

  /* Signum: '<S146>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign3' */

  /* Signum: '<S146>/Sign4' */
  if (rtb_Subtract3_cx < 0.0F) {
    rtb_Subtract3_cx = -1.0F;
  } else {
    if (rtb_Subtract3_cx > 0.0F) {
      rtb_Subtract3_cx = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign4' */

  /* Signum: '<S146>/Sign6' */
  if (rtb_a_ft < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_ft > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_ft;
  }

  /* End of Signum: '<S146>/Sign6' */

  /* Update for DiscreteIntegrator: '<S145>/Integrator' incorporates:
   *  Constant: '<S146>/const'
   *  Gain: '<S146>/Gain3'
   *  Product: '<S146>/Divide'
   *  Product: '<S146>/Multiply5'
   *  Product: '<S146>/Multiply6'
   *  Sum: '<S146>/Subtract4'
   *  Sum: '<S146>/Subtract5'
   *  Sum: '<S146>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_ft / localC->d - rtb_Add4_pq) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_cx) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S139>/Motion Status'
 *    '<S164>/Motion Status'
 *    '<S356>/Motion Status'
 *    '<S390>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S139>/Motion Status'
 *    '<S164>/Motion Status'
 *    '<S356>/Motion Status'
 *    '<S390>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S139>/Motion Status'
 *    '<S164>/Motion Status'
 *    '<S356>/Motion Status'
 *    '<S390>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S139>/Motion Status' */
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

  /* End of Chart: '<S139>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S178>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_l_Init(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S185>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S185>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System reset for action system:
 *    '<S178>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_g_Reset(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S185>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S185>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S178>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_b(const real32_T rtu_FMS_In[4], real32_T rtu_FMS_In_c,
  real32_T rtu_FMS_In_h, real32_T rtu_FMS_In_g, real32_T rtu_FMS_In_a, real32_T
  rtu_FMS_In_l, real32_T rtu_FMS_In_m, real32_T *rty_ay_cmd_mPs2, const
  ConstB_HoldControl_FMS_i_T *localC, DW_HoldControl_FMS_g_T *localDW)
{
  real32_T D;
  real32_T d1;
  real32_T absxk;
  real32_T b_t;
  real32_T rtb_DiscreteTimeIntegrator1_ex;
  real32_T rtb_Sign_hw;
  real32_T rtb_VectorConcatenate_l[9];
  real32_T rtb_Multiply_ppg[3];
  boolean_T rtb_Compare_dd1;
  real32_T rtb_VectorConcatenate_fy[3];
  int32_T i;
  real32_T rtb_Square_kg_idx_0;
  real32_T rtb_Square_kg_idx_1;
  real32_T rtb_Square_kg_idx_2;
  real32_T rtb_Switch_fz_idx_1;
  real32_T rtb_VectorConcatenate_fy_tmp;
  real32_T rtb_VectorConcatenate_fy_tmp_0;

  /* Sqrt: '<S192>/Sqrt' incorporates:
   *  Math: '<S192>/Square'
   *  Sum: '<S192>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_ex = sqrtf(((rtu_FMS_In[0] * rtu_FMS_In[0] +
    rtu_FMS_In[1] * rtu_FMS_In[1]) + rtu_FMS_In[2] * rtu_FMS_In[2]) +
    rtu_FMS_In[3] * rtu_FMS_In[3]);

  /* Product: '<S188>/Divide' */
  rtb_Square_kg_idx_0 = rtu_FMS_In[0] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_1 = rtu_FMS_In[1] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_2 = rtu_FMS_In[2] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_DiscreteTimeIntegrator1_ex = rtu_FMS_In[3] /
    rtb_DiscreteTimeIntegrator1_ex;

  /* Math: '<S189>/Square' incorporates:
   *  Math: '<S190>/Square'
   *  Math: '<S191>/Square'
   */
  rtb_Sign_hw = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_0;

  /* Math: '<S189>/Square2' incorporates:
   *  Math: '<S190>/Square2'
   *  Math: '<S191>/Square2'
   */
  rtb_Switch_fz_idx_1 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2;

  /* Math: '<S189>/Square1' incorporates:
   *  Math: '<S190>/Square1'
   *  Math: '<S191>/Square1'
   */
  D = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1;

  /* Math: '<S189>/Square3' incorporates:
   *  Math: '<S190>/Square3'
   *  Math: '<S191>/Square3'
   */
  absxk = rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex;

  /* Sum: '<S189>/Subtract' incorporates:
   *  Math: '<S189>/Square'
   *  Math: '<S189>/Square1'
   *  Math: '<S189>/Square2'
   *  Math: '<S189>/Square3'
   *  Sum: '<S189>/Add'
   *  Sum: '<S189>/Add1'
   */
  rtb_VectorConcatenate_l[0] = (rtb_Sign_hw + D) - (rtb_Switch_fz_idx_1 + absxk);

  /* Product: '<S189>/Multiply' incorporates:
   *  Product: '<S190>/Multiply'
   */
  b_t = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_2;

  /* Product: '<S189>/Multiply1' incorporates:
   *  Product: '<S190>/Multiply1'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_DiscreteTimeIntegrator1_ex;

  /* Gain: '<S189>/Gain' incorporates:
   *  Product: '<S189>/Multiply'
   *  Product: '<S189>/Multiply1'
   *  Sum: '<S189>/Subtract1'
   */
  rtb_VectorConcatenate_l[1] = (b_t - d1) * 2.0F;

  /* Product: '<S189>/Multiply2' incorporates:
   *  Product: '<S191>/Multiply'
   */
  rtb_VectorConcatenate_fy_tmp = rtb_Square_kg_idx_1 *
    rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S189>/Multiply3' incorporates:
   *  Product: '<S191>/Multiply1'
   */
  rtb_VectorConcatenate_fy_tmp_0 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_2;

  /* Gain: '<S189>/Gain1' incorporates:
   *  Product: '<S189>/Multiply2'
   *  Product: '<S189>/Multiply3'
   *  Sum: '<S189>/Add2'
   */
  rtb_VectorConcatenate_l[2] = (rtb_VectorConcatenate_fy_tmp +
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S190>/Gain' incorporates:
   *  Sum: '<S190>/Add3'
   */
  rtb_VectorConcatenate_l[3] = (b_t + d1) * 2.0F;

  /* Sum: '<S190>/Subtract' incorporates:
   *  Sum: '<S190>/Add'
   *  Sum: '<S190>/Add1'
   */
  rtb_VectorConcatenate_l[4] = (rtb_Sign_hw + rtb_Switch_fz_idx_1) - (D + absxk);

  /* Product: '<S190>/Multiply2' incorporates:
   *  Product: '<S191>/Multiply2'
   */
  b_t = rtb_Square_kg_idx_2 * rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S190>/Multiply3' incorporates:
   *  Product: '<S191>/Multiply3'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_1;

  /* Gain: '<S190>/Gain1' incorporates:
   *  Product: '<S190>/Multiply2'
   *  Product: '<S190>/Multiply3'
   *  Sum: '<S190>/Subtract1'
   */
  rtb_VectorConcatenate_l[5] = (b_t - d1) * 2.0F;

  /* Gain: '<S191>/Gain' incorporates:
   *  Sum: '<S191>/Subtract2'
   */
  rtb_VectorConcatenate_l[6] = (rtb_VectorConcatenate_fy_tmp -
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S191>/Gain1' incorporates:
   *  Sum: '<S191>/Add2'
   */
  rtb_VectorConcatenate_l[7] = (b_t + d1) * 2.0F;

  /* Sum: '<S191>/Subtract' incorporates:
   *  Sum: '<S191>/Add'
   *  Sum: '<S191>/Add1'
   */
  rtb_VectorConcatenate_l[8] = (rtb_Sign_hw + absxk) - (D + rtb_Switch_fz_idx_1);

  /* Product: '<S182>/Multiply' incorporates:
   *  SignalConversion: '<S182>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_ppg[i] = rtb_VectorConcatenate_l[i + 6] * rtu_FMS_In_g +
      (rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h + rtb_VectorConcatenate_l[i]
       * rtu_FMS_In_c);
  }

  /* End of Product: '<S182>/Multiply' */

  /* Trigonometry: '<S211>/Trigonometric Function1' incorporates:
   *  Gain: '<S210>/Gain'
   *  Trigonometry: '<S211>/Trigonometric Function3'
   */
  rtb_Sign_hw = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[0] = rtb_Sign_hw;

  /* Trigonometry: '<S211>/Trigonometric Function' incorporates:
   *  Gain: '<S210>/Gain'
   *  Trigonometry: '<S211>/Trigonometric Function2'
   */
  rtb_Switch_fz_idx_1 = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[1] = rtb_Switch_fz_idx_1;

  /* SignalConversion: '<S211>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S211>/Constant3'
   */
  rtb_VectorConcatenate_l[2] = 0.0F;

  /* Gain: '<S211>/Gain' */
  rtb_VectorConcatenate_l[3] = -rtb_Switch_fz_idx_1;

  /* Trigonometry: '<S211>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_Sign_hw;

  /* SignalConversion: '<S211>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S211>/Constant4'
   */
  rtb_VectorConcatenate_l[5] = 0.0F;

  /* SignalConversion: '<S211>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_l[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_l[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_l[8] = localC->VectorConcatenate3[2];

  /* Delay: '<S185>/start_vel' incorporates:
   *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
   */
  if (localDW->icLoad != 0) {
    localDW->start_vel_DSTATE[0] = rtu_FMS_In_c;
    localDW->start_vel_DSTATE[1] = rtu_FMS_In_h;
  }

  /* Sum: '<S206>/Sum of Elements' incorporates:
   *  Delay: '<S185>/start_vel'
   *  Math: '<S206>/Math Function'
   */
  rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[0] * localDW->
    start_vel_DSTATE[0] + localDW->start_vel_DSTATE[1] *
    localDW->start_vel_DSTATE[1];

  /* Math: '<S206>/Math Function1' incorporates:
   *  Sum: '<S206>/Sum of Elements'
   *
   * About '<S206>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_fz_idx_1 < 0.0F) {
    rtb_Sign_hw = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
  } else {
    rtb_Sign_hw = sqrtf(rtb_Switch_fz_idx_1);
  }

  /* End of Math: '<S206>/Math Function1' */

  /* Switch: '<S206>/Switch' incorporates:
   *  Constant: '<S206>/Constant'
   *  Delay: '<S185>/start_vel'
   *  Product: '<S206>/Product'
   */
  if (rtb_Sign_hw > 0.0F) {
    rtb_Square_kg_idx_2 = localDW->start_vel_DSTATE[0];
    rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[1];
  } else {
    rtb_Square_kg_idx_2 = 0.0F;
    rtb_Switch_fz_idx_1 = 0.0F;
    rtb_Sign_hw = 1.0F;
  }

  /* End of Switch: '<S206>/Switch' */

  /* Delay: '<S185>/start_wp' incorporates:
   *  SignalConversion: '<S185>/TmpSignal ConversionAtstart_wpInport2'
   */
  if (localDW->icLoad_e != 0) {
    localDW->start_wp_DSTATE[0] = rtu_FMS_In_l;
    localDW->start_wp_DSTATE[1] = rtu_FMS_In_m;
  }

  /* MATLAB Function: '<S183>/SearchL1RefWP' incorporates:
   *  Delay: '<S185>/start_wp'
   *  SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_Square_kg_idx_0 = localDW->start_wp_DSTATE[0] - rtu_FMS_In_l;
  rtb_Square_kg_idx_1 = localDW->start_wp_DSTATE[1] - rtu_FMS_In_m;

  /* Product: '<S206>/Divide' */
  rtb_Square_kg_idx_2 /= rtb_Sign_hw;

  /* MATLAB Function: '<S183>/SearchL1RefWP' */
  D = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_0;

  /* Product: '<S206>/Divide' */
  rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_2;
  rtb_Square_kg_idx_2 = rtb_Switch_fz_idx_1 / rtb_Sign_hw;

  /* MATLAB Function: '<S183>/SearchL1RefWP' incorporates:
   *  Constant: '<S180>/L1'
   *  Delay: '<S185>/start_wp'
   */
  D += rtb_Square_kg_idx_2 * rtb_Square_kg_idx_1;
  rtb_Switch_fz_idx_1 = 2.0F * D;
  rtb_Sign_hw = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_0;
  rtb_Square_kg_idx_0 = 0.0F;
  rtb_Sign_hw += rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1;
  rtb_Square_kg_idx_1 = 0.0F;
  D = rtb_Switch_fz_idx_1 * rtb_Switch_fz_idx_1 - (rtb_Sign_hw - FMS_PARAM.FW_L1
    * FMS_PARAM.FW_L1) * 4.0F;
  rtb_Sign_hw = -1.0F;
  if (D > 0.0F) {
    rtb_Square_kg_idx_0 = sqrtf(D);
    rtb_Sign_hw = fmaxf((-rtb_Switch_fz_idx_1 + rtb_Square_kg_idx_0) / 2.0F,
                        (-rtb_Switch_fz_idx_1 - rtb_Square_kg_idx_0) / 2.0F);
    rtb_Square_kg_idx_0 = rtb_Sign_hw * rtb_DiscreteTimeIntegrator1_ex +
      localDW->start_wp_DSTATE[0];
    rtb_Square_kg_idx_1 = rtb_Sign_hw * rtb_Square_kg_idx_2 +
      localDW->start_wp_DSTATE[1];
  } else {
    if (D == 0.0F) {
      rtb_Sign_hw = -rtb_Switch_fz_idx_1 / 2.0F;
      rtb_Square_kg_idx_0 = rtb_Sign_hw * rtb_DiscreteTimeIntegrator1_ex +
        localDW->start_wp_DSTATE[0];
      rtb_Square_kg_idx_1 = rtb_Sign_hw * rtb_Square_kg_idx_2 +
        localDW->start_wp_DSTATE[1];
    }
  }

  /* MATLAB Function: '<S183>/OutRegionRefWP' incorporates:
   *  Delay: '<S185>/start_wp'
   *  SignalConversion: '<S185>/TmpSignal ConversionAtstart_wpInport2'
   */
  rtb_Switch_fz_idx_1 = (rtu_FMS_In_l - localDW->start_wp_DSTATE[0]) *
    rtb_DiscreteTimeIntegrator1_ex + (rtu_FMS_In_m - localDW->start_wp_DSTATE[1])
    * rtb_Square_kg_idx_2;
  D = 1.29246971E-26F;
  absxk = fabsf((rtb_Switch_fz_idx_1 * rtb_DiscreteTimeIntegrator1_ex +
                 localDW->start_wp_DSTATE[0]) - rtu_FMS_In_l);
  if (absxk > 1.29246971E-26F) {
    d1 = 1.0F;
    D = absxk;
  } else {
    b_t = absxk / 1.29246971E-26F;
    d1 = b_t * b_t;
  }

  absxk = fabsf((rtb_Switch_fz_idx_1 * rtb_Square_kg_idx_2 +
                 localDW->start_wp_DSTATE[1]) - rtu_FMS_In_m);
  if (absxk > D) {
    b_t = D / absxk;
    d1 = d1 * b_t * b_t + 1.0F;
    D = absxk;
  } else {
    b_t = absxk / D;
    d1 += b_t * b_t;
  }

  d1 = D * sqrtf(d1);
  b_t = d1 * 0.577350259F + rtb_Switch_fz_idx_1;

  /* Product: '<S209>/Multiply' incorporates:
   *  SignalConversion: '<S209>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_fy[i] = rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h
      + rtb_VectorConcatenate_l[i] * rtu_FMS_In_c;
  }

  /* End of Product: '<S209>/Multiply' */

  /* DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
  if (localDW->DiscreteTimeIntegrator_PrevRese != 0) {
    localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
        localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
      }
    }
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  /* DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S207>/Constant'
   *  Sum: '<S207>/Sum'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  if (localDW->DiscreteTimeIntegrator1_PrevRes != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  /* Signum: '<S182>/Sign' */
  if (rtb_Multiply_ppg[0] < 0.0F) {
    rtb_Switch_fz_idx_1 = -1.0F;
  } else if (rtb_Multiply_ppg[0] > 0.0F) {
    rtb_Switch_fz_idx_1 = 1.0F;
  } else {
    rtb_Switch_fz_idx_1 = rtb_Multiply_ppg[0];
  }

  /* End of Signum: '<S182>/Sign' */

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S180>/L1'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S207>/Constant'
   *  Constant: '<S214>/kp'
   *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator'
   *  Gain: '<S196>/Gain'
   *  Math: '<S196>/Square'
   *  Math: '<S199>/Square'
   *  Math: '<S201>/Math Function'
   *  MinMax: '<S196>/Max'
   *  MinMax: '<S196>/Min'
   *  Product: '<S196>/Divide'
   *  Product: '<S196>/Multiply1'
   *  Product: '<S214>/Multiply'
   *  Sqrt: '<S199>/Sqrt'
   *  Sum: '<S184>/Subtract'
   *  Sum: '<S199>/Sum of Elements'
   *  Sum: '<S207>/Sum'
   *  Sum: '<S208>/Add'
   */
  if (rtb_Switch_fz_idx_1 > 0.0F) {
    /* Sum: '<S200>/Sum of Elements' incorporates:
     *  Math: '<S200>/Math Function'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     *  Sum: '<S198>/Sum of Elements'
     */
    rtb_Switch_fz_idx_1 = rtu_FMS_In_c * rtu_FMS_In_c + rtu_FMS_In_h *
      rtu_FMS_In_h;

    /* Math: '<S200>/Math Function1' incorporates:
     *  Sum: '<S200>/Sum of Elements'
     *
     * About '<S200>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Switch_fz_idx_1 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
    } else {
      d1 = sqrtf(rtb_Switch_fz_idx_1);
    }

    /* End of Math: '<S200>/Math Function1' */

    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S200>/Constant'
     *  Product: '<S200>/Product'
     */
    if (d1 > 0.0F) {
      rtb_Multiply_ppg[0] = rtu_FMS_In_c;
      rtb_Multiply_ppg[1] = rtu_FMS_In_h;
      rtb_Multiply_ppg[2] = d1;
    } else {
      rtb_Multiply_ppg[0] = 0.0F;
      rtb_Multiply_ppg[1] = 0.0F;
      rtb_Multiply_ppg[2] = 1.0F;
    }

    /* End of Switch: '<S200>/Switch' */

    /* Product: '<S200>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* RelationalOperator: '<S193>/Compare' incorporates:
     *  Constant: '<S193>/Constant'
     *  MATLAB Function: '<S183>/SearchL1RefWP'
     */
    rtb_Compare_dd1 = (rtb_Sign_hw > 0.0F);

    /* Switch: '<S183>/Switch' incorporates:
     *  Delay: '<S185>/start_wp'
     *  MATLAB Function: '<S183>/OutRegionRefWP'
     */
    if (!rtb_Compare_dd1) {
      rtb_Square_kg_idx_0 = b_t * rtb_DiscreteTimeIntegrator1_ex +
        localDW->start_wp_DSTATE[0];
      rtb_Square_kg_idx_1 = b_t * rtb_Square_kg_idx_2 + localDW->
        start_wp_DSTATE[1];
    }

    /* End of Switch: '<S183>/Switch' */

    /* Sum: '<S184>/Subtract' incorporates:
     *  SignalConversion: '<S185>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_0 - rtu_FMS_In_l;
    rtb_Square_kg_idx_0 = rtb_DiscreteTimeIntegrator1_ex;
    rtb_Sign_hw = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex;

    /* Sum: '<S184>/Subtract' incorporates:
     *  Math: '<S201>/Math Function'
     *  SignalConversion: '<S185>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_1 - rtu_FMS_In_m;

    /* Sum: '<S201>/Sum of Elements' incorporates:
     *  Math: '<S201>/Math Function'
     */
    rtb_Square_kg_idx_2 = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex + rtb_Sign_hw;

    /* Math: '<S201>/Math Function1' incorporates:
     *  Sum: '<S201>/Sum of Elements'
     *
     * About '<S201>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S201>/Math Function1' */

    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S201>/Constant'
     *  Product: '<S201>/Product'
     */
    if (d1 > 0.0F) {
      rtb_Multiply_ppg[0] = rtb_Square_kg_idx_0;
      rtb_Multiply_ppg[1] = rtb_DiscreteTimeIntegrator1_ex;
      rtb_Multiply_ppg[2] = d1;
    } else {
      rtb_Multiply_ppg[0] = 0.0F;
      rtb_Multiply_ppg[1] = 0.0F;
      rtb_Multiply_ppg[2] = 1.0F;
    }

    /* End of Switch: '<S201>/Switch' */

    /* Product: '<S201>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_0 *= rtb_Square_kg_idx_0;

    /* Product: '<S201>/Divide' incorporates:
     *  Math: '<S199>/Square'
     */
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S203>/Sum of Elements' incorporates:
     *  Math: '<S203>/Math Function'
     *  SignalConversion: '<S203>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = absxk * absxk + D * D;

    /* Math: '<S203>/Math Function1' incorporates:
     *  Sum: '<S203>/Sum of Elements'
     *
     * About '<S203>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S203>/Math Function1' */

    /* Switch: '<S203>/Switch' incorporates:
     *  Constant: '<S203>/Constant'
     *  Product: '<S203>/Product'
     */
    if (d1 > 0.0F) {
      rtb_Multiply_ppg[0] = absxk;
      rtb_Multiply_ppg[1] = D;
      rtb_Multiply_ppg[2] = d1;
    } else {
      rtb_Multiply_ppg[0] = 0.0F;
      rtb_Multiply_ppg[1] = 0.0F;
      rtb_Multiply_ppg[2] = 1.0F;
    }

    /* End of Switch: '<S203>/Switch' */

    /* Product: '<S203>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S204>/Sum of Elements' incorporates:
     *  Math: '<S204>/Math Function'
     *  SignalConversion: '<S204>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1 +
      rtb_Sign_hw * rtb_Sign_hw;

    /* Math: '<S204>/Math Function1' incorporates:
     *  Sum: '<S204>/Sum of Elements'
     *
     * About '<S204>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S204>/Math Function1' */

    /* Switch: '<S204>/Switch' incorporates:
     *  Constant: '<S204>/Constant'
     *  Product: '<S204>/Product'
     */
    if (d1 > 0.0F) {
      rtb_Multiply_ppg[0] = rtb_Square_kg_idx_1;
      rtb_Multiply_ppg[1] = rtb_Sign_hw;
      rtb_Multiply_ppg[2] = d1;
    } else {
      rtb_Multiply_ppg[0] = 0.0F;
      rtb_Multiply_ppg[1] = 0.0F;
      rtb_Multiply_ppg[2] = 1.0F;
    }

    /* End of Switch: '<S204>/Switch' */

    /* Product: '<S204>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S202>/Subtract' incorporates:
     *  Product: '<S202>/Multiply'
     *  Product: '<S202>/Multiply1'
     */
    rtb_Square_kg_idx_2 = rtb_Sign_hw * absxk - rtb_Square_kg_idx_1 * D;

    /* Signum: '<S197>/Sign1' */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      rtb_Square_kg_idx_2 = -1.0F;
    } else {
      if (rtb_Square_kg_idx_2 > 0.0F) {
        rtb_Square_kg_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S197>/Sign1' */

    /* Switch: '<S197>/Switch2' incorporates:
     *  Constant: '<S197>/Constant4'
     */
    if (rtb_Square_kg_idx_2 == 0.0F) {
      rtb_Square_kg_idx_2 = 1.0F;
    }

    /* End of Switch: '<S197>/Switch2' */

    /* DotProduct: '<S197>/Dot Product' */
    rtb_Square_kg_idx_1 = D * rtb_Sign_hw + absxk * rtb_Square_kg_idx_1;

    /* Trigonometry: '<S197>/Acos' incorporates:
     *  DotProduct: '<S197>/Dot Product'
     */
    if (rtb_Square_kg_idx_1 > 1.0F) {
      rtb_Square_kg_idx_1 = 1.0F;
    } else {
      if (rtb_Square_kg_idx_1 < -1.0F) {
        rtb_Square_kg_idx_1 = -1.0F;
      }
    }

    /* Product: '<S197>/Multiply' incorporates:
     *  Trigonometry: '<S197>/Acos'
     */
    rtb_Square_kg_idx_2 *= acosf(rtb_Square_kg_idx_1);

    /* Saturate: '<S196>/Saturation' */
    if (rtb_Square_kg_idx_2 > 1.57079637F) {
      rtb_Square_kg_idx_2 = 1.57079637F;
    } else {
      if (rtb_Square_kg_idx_2 < -1.57079637F) {
        rtb_Square_kg_idx_2 = -1.57079637F;
      }
    }

    /* End of Saturate: '<S196>/Saturation' */

    /* Trigonometry: '<S196>/Sin' */
    rtb_Square_kg_idx_1 = arm_sin_f32(rtb_Square_kg_idx_2);

    /* Sqrt: '<S198>/Sqrt' */
    rtb_Square_kg_idx_2 = sqrtf(rtb_Switch_fz_idx_1);
    *rty_ay_cmd_mPs2 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2 * 2.0F *
      rtb_Square_kg_idx_1 / fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf
      (rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex +
       rtb_Square_kg_idx_0), 0.5F));
  } else {
    *rty_ay_cmd_mPs2 = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
      localDW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Switch: '<S180>/Switch' */

  /* Update for Delay: '<S185>/start_vel' */
  localDW->icLoad = 0U;

  /* Update for Delay: '<S185>/start_wp' */
  localDW->icLoad_e = 0U;

  /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S207>/Constant'
   *  Constant: '<S213>/ki'
   *  Product: '<S213>/Multiply'
   *  Sum: '<S207>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += (0.0F - rtb_VectorConcatenate_fy[1])
    * 0.5F * 0.004F;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S207>/Constant'
   *  Gain: '<S215>/Gain'
   *  Sum: '<S207>/Sum'
   *  Sum: '<S215>/Sum5'
   */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE += ((0.0F - rtb_VectorConcatenate_fy[1])
    - localDW->DiscreteTimeIntegrator1_DSTATE) * 62.831852F * 0.004F;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System initialize for atomic system:
 *    '<S179>/Motion State'
 *    '<S55>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c26_FMS = 0U;
  localDW->is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
}

/*
 * System reset for atomic system:
 *    '<S179>/Motion State'
 *    '<S55>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c26_FMS = 0U;
  localDW->is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
}

/*
 * Output and update for atomic system:
 *    '<S179>/Motion State'
 *    '<S55>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S179>/Motion State' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c26_FMS == 0U) {
    localDW->is_active_c26_FMS = 1U;
    localDW->is_c26_FMS = FMS_IN_Move_p;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c26_FMS) {
     case FMS_IN_Brake_b:
      *rty_state = MotionState_Brake;
      if ((localDW->temporalCounter_i1 >= 625U) && (rtu_speed > 5.0F)) {
        localDW->is_c26_FMS = FMS_IN_Hold_o;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c26_FMS = FMS_IN_Move_p;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_o:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c26_FMS = FMS_IN_Move_p;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c26_FMS = FMS_IN_Brake_b;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S179>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S733>/Hold Control'
 *    '<S650>/Hold Control'
 *    '<S493>/Hold Control'
 *    '<S355>/Hold Control'
 *    '<S389>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S736>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S733>/Hold Control'
 *    '<S650>/Hold Control'
 *    '<S493>/Hold Control'
 *    '<S355>/Hold Control'
 *    '<S389>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S736>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S733>/Hold Control'
 *    '<S650>/Hold Control'
 *    '<S493>/Hold Control'
 *    '<S355>/Hold Control'
 *    '<S389>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S736>/Delay' incorporates:
   *  Gain: '<S738>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S736>/Gain2' incorporates:
   *  Delay: '<S736>/Delay'
   *  Gain: '<S738>/Gain'
   *  Sum: '<S736>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S736>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S733>/Brake Control'
 *    '<S650>/Brake Control'
 *    '<S661>/Brake Control'
 *    '<S493>/Brake Control'
 *    '<S439>/Brake Control'
 *    '<S355>/Brake Control'
 *    '<S373>/Brake Control'
 *    '<S389>/Brake Control'
 *    '<S401>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S735>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S735>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S733>/Move Control'
 *    '<S650>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S740>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S740>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S733>/Move Control'
 *    '<S650>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S740>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S740>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S733>/Move Control'
 *    '<S650>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_ho;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S741>/Multiply1' incorporates:
   *  Constant: '<S741>/const1'
   *  DiscreteIntegrator: '<S740>/Integrator'
   */
  rtb_Add3_ho = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S739>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S739>/Dead Zone' */

  /* Sum: '<S741>/Add' incorporates:
   *  DiscreteIntegrator: '<S740>/Integrator1'
   *  Gain: '<S737>/Gain1'
   *  Gain: '<S739>/Gain'
   *  Sum: '<S740>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_ho;

  /* Signum: '<S741>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S741>/Sign' */

  /* Sum: '<S741>/Add2' incorporates:
   *  Abs: '<S741>/Abs'
   *  Gain: '<S741>/Gain'
   *  Gain: '<S741>/Gain1'
   *  Product: '<S741>/Multiply2'
   *  Product: '<S741>/Multiply3'
   *  Sqrt: '<S741>/Sqrt'
   *  Sum: '<S741>/Add1'
   *  Sum: '<S741>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_ho;

  /* Sum: '<S741>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_ho;

  /* Sum: '<S741>/Add3' */
  rtb_Add3_ho = rtb_Subtract3_d + localC->d;

  /* Sum: '<S741>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S741>/Sign1' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S741>/Sign1' */

  /* Signum: '<S741>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S741>/Sign2' */

  /* Sum: '<S741>/Add5' incorporates:
   *  Gain: '<S741>/Gain2'
   *  Product: '<S741>/Multiply4'
   *  Sum: '<S741>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_ho - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S740>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S740>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S740>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S740>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S741>/Add6' */
  rtb_Add3_ho = rtb_a_o + localC->d;

  /* Sum: '<S741>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S741>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S741>/Sign5' */

  /* Signum: '<S741>/Sign3' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S741>/Sign3' */

  /* Signum: '<S741>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S741>/Sign4' */

  /* Signum: '<S741>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S741>/Sign6' */

  /* Update for DiscreteIntegrator: '<S740>/Integrator' incorporates:
   *  Constant: '<S741>/const'
   *  Gain: '<S741>/Gain3'
   *  Product: '<S741>/Divide'
   *  Product: '<S741>/Multiply5'
   *  Product: '<S741>/Multiply6'
   *  Sum: '<S741>/Subtract4'
   *  Sum: '<S741>/Subtract5'
   *  Sum: '<S741>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_ho - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S734>/Motion Status'
 *    '<S651>/Motion Status'
 *    '<S494>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S734>/Motion Status'
 *    '<S651>/Motion Status'
 *    '<S494>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S734>/Motion Status'
 *    '<S651>/Motion Status'
 *    '<S494>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S734>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c1_FMS == 0U) {
    localDW->is_active_c1_FMS = 1U;
    localDW->is_c1_FMS = FMS_IN_Move_h;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c1_FMS) {
     case FMS_IN_Brake_bq:
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
        localDW->is_c1_FMS = FMS_IN_Brake_bq;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S734>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S743>/Hold Control'
 *    '<S682>/Hold Control'
 *    '<S503>/Hold Control'
 */
void FMS_HoldControl_l0_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S746>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S743>/Hold Control'
 *    '<S682>/Hold Control'
 *    '<S503>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S746>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S743>/Hold Control'
 *    '<S682>/Hold Control'
 *    '<S503>/Hold Control'
 */
void FMS_HoldControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rtu_FMS_In_d, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_m_T *localDW)
{
  real32_T rtb_VectorConcatenate_hl[9];
  real32_T rtb_VectorConcatenate_d[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_d_tmp;
  real32_T rtb_VectorConcatenate_d_tmp_0;

  /* Delay: '<S746>/Delay' incorporates:
   *  SignalConversion: '<S746>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S750>/Trigonometric Function1' incorporates:
   *  Gain: '<S749>/Gain'
   *  Trigonometry: '<S750>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S750>/Trigonometric Function' incorporates:
   *  Gain: '<S749>/Gain'
   *  Trigonometry: '<S750>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S750>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S750>/Constant3'
   */
  rtb_VectorConcatenate_hl[2] = 0.0F;

  /* Gain: '<S750>/Gain' */
  rtb_VectorConcatenate_hl[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S750>/Trigonometric Function3' */
  rtb_VectorConcatenate_hl[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S750>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S750>/Constant4'
   */
  rtb_VectorConcatenate_hl[5] = 0.0F;

  /* SignalConversion: '<S750>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_hl[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_hl[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_hl[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S746>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S746>/Delay'
   *  SignalConversion: '<S746>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S746>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S746>/Multiply' incorporates:
   *  SignalConversion: '<S746>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_hl[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_hl[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S746>/Multiply' */

  /* Gain: '<S746>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S746>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S743>/Brake Control'
 *    '<S682>/Brake Control'
 *    '<S503>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S745>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S743>/Move Control'
 *    '<S682>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S743>/Move Control'
 *    '<S682>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S743>/Move Control'
 *    '<S682>/Move Control'
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

  /* DiscreteIntegrator: '<S753>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S754>/Multiply1' incorporates:
   *  Constant: '<S754>/const1'
   *  DiscreteIntegrator: '<S753>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S753>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S754>/Multiply1' incorporates:
   *  Constant: '<S754>/const1'
   *  DiscreteIntegrator: '<S753>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S751>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S751>/Dead Zone' */

  /* Sum: '<S754>/Add' incorporates:
   *  DiscreteIntegrator: '<S753>/Integrator1'
   *  Gain: '<S747>/Gain6'
   *  Gain: '<S751>/Gain'
   *  Sum: '<S753>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S752>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S752>/Dead Zone' */

  /* Sum: '<S754>/Add' incorporates:
   *  DiscreteIntegrator: '<S753>/Integrator1'
   *  Gain: '<S747>/Gain6'
   *  Gain: '<S752>/Gain'
   *  Sum: '<S753>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S754>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S754>/Add2' incorporates:
   *  Abs: '<S754>/Abs'
   *  Gain: '<S754>/Gain'
   *  Gain: '<S754>/Gain1'
   *  Product: '<S754>/Multiply2'
   *  Product: '<S754>/Multiply3'
   *  Signum: '<S754>/Sign'
   *  Sqrt: '<S754>/Sqrt'
   *  Sum: '<S754>/Add1'
   *  Sum: '<S754>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S754>/Add3' incorporates:
   *  Signum: '<S754>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S754>/Subtract1' incorporates:
   *  Signum: '<S754>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S754>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S754>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S754>/Add5' incorporates:
   *  Gain: '<S754>/Gain2'
   *  Product: '<S754>/Multiply4'
   *  Signum: '<S754>/Sign'
   *  Sum: '<S754>/Add2'
   *  Sum: '<S754>/Add4'
   *  Sum: '<S754>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S753>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S753>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S754>/Sign3' incorporates:
   *  Sum: '<S754>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S754>/Sign4' incorporates:
   *  Sum: '<S754>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S754>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S754>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S754>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S754>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S753>/Integrator' incorporates:
   *  Constant: '<S754>/const'
   *  Gain: '<S754>/Gain3'
   *  Product: '<S754>/Divide'
   *  Product: '<S754>/Multiply5'
   *  Product: '<S754>/Multiply6'
   *  Sum: '<S754>/Subtract4'
   *  Sum: '<S754>/Subtract5'
   *  Sum: '<S754>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S753>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S754>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S754>/Add2' incorporates:
   *  Abs: '<S754>/Abs'
   *  Gain: '<S754>/Gain'
   *  Gain: '<S754>/Gain1'
   *  Product: '<S754>/Multiply2'
   *  Product: '<S754>/Multiply3'
   *  Signum: '<S754>/Sign'
   *  Sqrt: '<S754>/Sqrt'
   *  Sum: '<S754>/Add1'
   *  Sum: '<S754>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S754>/Add3' incorporates:
   *  Signum: '<S754>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S754>/Subtract1' incorporates:
   *  Signum: '<S754>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S754>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S754>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S754>/Add5' incorporates:
   *  Gain: '<S754>/Gain2'
   *  Product: '<S754>/Multiply4'
   *  Signum: '<S754>/Sign'
   *  Sum: '<S754>/Add2'
   *  Sum: '<S754>/Add4'
   *  Sum: '<S754>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S753>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S753>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S754>/Sign3' incorporates:
   *  Sum: '<S754>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S754>/Sign4' incorporates:
   *  Sum: '<S754>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S754>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S754>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S754>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S754>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S753>/Integrator' incorporates:
   *  Constant: '<S754>/const'
   *  Gain: '<S754>/Gain3'
   *  Product: '<S754>/Divide'
   *  Product: '<S754>/Multiply5'
   *  Product: '<S754>/Multiply6'
   *  Sum: '<S754>/Subtract4'
   *  Sum: '<S754>/Subtract5'
   *  Sum: '<S754>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S753>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S744>/Motion State'
 *    '<S683>/Motion State'
 *    '<S504>/Motion State'
 */
void FMS_MotionState_c_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S744>/Motion State'
 *    '<S683>/Motion State'
 *    '<S504>/Motion State'
 */
void FMS_MotionState_f_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S744>/Motion State'
 *    '<S683>/Motion State'
 *    '<S504>/Motion State'
 */
void FMS_MotionState_p(real32_T rtu_motion_req, real32_T rtu_speed, MotionState *
  rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S744>/Motion State' */
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
        localDW->is_c2_FMS = FMS_IN_Hold_ol;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c2_FMS = FMS_IN_Move_o;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_ol:
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

  /* End of Chart: '<S744>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S726>/OutRegionRegWP'
 *    '<S480>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S759>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S661>/Hold Control'
 *    '<S439>/Hold Control'
 *    '<S373>/Hold Control'
 *    '<S401>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S665>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S661>/Hold Control'
 *    '<S439>/Hold Control'
 *    '<S373>/Hold Control'
 *    '<S401>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S665>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S661>/Hold Control'
 *    '<S439>/Hold Control'
 *    '<S373>/Hold Control'
 *    '<S401>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S665>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S665>/Sum' incorporates:
   *  Delay: '<S665>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S668>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S668>/Switch' incorporates:
   *  Constant: '<S668>/Constant'
   *  Constant: '<S669>/Constant'
   *  Product: '<S668>/Multiply'
   *  RelationalOperator: '<S669>/Compare'
   *  Sum: '<S668>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S668>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S668>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S668>/Switch' */

  /* Gain: '<S665>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S665>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S661>/Move Control'
 *    '<S439>/Move Control'
 *    '<S373>/Move Control'
 *    '<S401>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S671>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S671>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S661>/Move Control'
 *    '<S439>/Move Control'
 *    '<S373>/Move Control'
 *    '<S401>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S671>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S671>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S661>/Move Control'
 *    '<S439>/Move Control'
 *    '<S373>/Move Control'
 *    '<S401>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_px;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S672>/Multiply1' incorporates:
   *  Constant: '<S672>/const1'
   *  DiscreteIntegrator: '<S671>/Integrator'
   */
  rtb_Add3_px = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S670>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S670>/Dead Zone' */

  /* Sum: '<S672>/Add' incorporates:
   *  DiscreteIntegrator: '<S671>/Integrator1'
   *  Gain: '<S666>/Gain1'
   *  Gain: '<S670>/Gain'
   *  Sum: '<S671>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_px;

  /* Signum: '<S672>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
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
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_px;

  /* Sum: '<S672>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_px;

  /* Sum: '<S672>/Add3' */
  rtb_Add3_px = rtb_Subtract3_e + localC->d;

  /* Sum: '<S672>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S672>/Sign1' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S672>/Sign1' */

  /* Signum: '<S672>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S672>/Sign2' */

  /* Sum: '<S672>/Add5' incorporates:
   *  Gain: '<S672>/Gain2'
   *  Product: '<S672>/Multiply4'
   *  Sum: '<S672>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_px - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S671>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S671>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S671>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S671>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S672>/Add6' */
  rtb_Add3_px = rtb_a_h + localC->d;

  /* Sum: '<S672>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S672>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S672>/Sign5' */

  /* Signum: '<S672>/Sign3' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S672>/Sign3' */

  /* Signum: '<S672>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S672>/Sign4' */

  /* Signum: '<S672>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S672>/Sign6' */

  /* Update for DiscreteIntegrator: '<S671>/Integrator' incorporates:
   *  Constant: '<S672>/const'
   *  Gain: '<S672>/Gain3'
   *  Product: '<S672>/Divide'
   *  Product: '<S672>/Multiply5'
   *  Product: '<S672>/Multiply6'
   *  Sum: '<S672>/Subtract4'
   *  Sum: '<S672>/Subtract5'
   *  Sum: '<S672>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_px - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S440>/Motion State'
 *    '<S374>/Motion State'
 *    '<S402>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S440>/Motion State'
 *    '<S374>/Motion State'
 *    '<S402>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S440>/Motion State'
 *    '<S374>/Motion State'
 *    '<S402>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S440>/Motion State' */
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

  /* End of Chart: '<S440>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S355>/Move Control'
 *    '<S389>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S364>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S364>/Dead Zone' */

  /* Gain: '<S359>/Gain1' incorporates:
   *  Gain: '<S364>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S359>/Switch' incorporates:
   *  Constant: '<S361>/Land_Speed'
   *  Constant: '<S362>/Constant'
   *  Constant: '<S363>/Constant'
   *  Gain: '<S361>/Gain'
   *  Logic: '<S359>/Logical Operator'
   *  MinMax: '<S361>/Min'
   *  RelationalOperator: '<S362>/Compare'
   *  RelationalOperator: '<S363>/Compare'
   *  S-Function (sfix_bitop): '<S359>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S359>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S790>/Switch' incorporates:
   *  Constant: '<S790>/FW_ACCEPT_R'
   *  Constant: '<S790>/MC_ACCEPT_R'
   *  Constant: '<S797>/Constant'
   *  RelationalOperator: '<S797>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S790>/Switch' */
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

  /* Math: '<S808>/Rem' incorporates:
   *  Constant: '<S808>/Constant1'
   *  Sum: '<S792>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S808>/Switch' incorporates:
   *  Abs: '<S808>/Abs'
   *  Constant: '<S808>/Constant'
   *  Constant: '<S809>/Constant'
   *  Product: '<S808>/Multiply'
   *  RelationalOperator: '<S809>/Compare'
   *  Sum: '<S808>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S808>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S808>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S808>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S795>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S814>/Sum of Elements' incorporates:
   *  Math: '<S814>/Math Function'
   *  SignalConversion: '<S814>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S814>/Math Function1' incorporates:
   *  Sum: '<S814>/Sum of Elements'
   *
   * About '<S814>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S814>/Math Function1' */

  /* Switch: '<S814>/Switch' incorporates:
   *  Constant: '<S814>/Constant'
   *  Product: '<S814>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S814>/Switch' */

  /* Product: '<S814>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S812>/Subtract' incorporates:
   *  Product: '<S812>/Multiply'
   *  Product: '<S812>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S811>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S811>/Sign1' */

  /* Switch: '<S811>/Switch2' incorporates:
   *  Constant: '<S811>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S811>/Switch2' */

  /* DotProduct: '<S811>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S811>/Acos' incorporates:
   *  DotProduct: '<S811>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S811>/Multiply' incorporates:
   *  Trigonometry: '<S811>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S795>/Switch' incorporates:
   *  Bias: '<S795>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S795>/Switch' */
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

  /* Gain: '<S798>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S799>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S799>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S799>/Multiply1' incorporates:
   *  Product: '<S799>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S799>/Divide' incorporates:
   *  Constant: '<S799>/Constant'
   *  Constant: '<S799>/R'
   *  Sqrt: '<S799>/Sqrt'
   *  Sum: '<S799>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S799>/Product3' incorporates:
   *  Constant: '<S799>/Constant1'
   *  Product: '<S799>/Multiply1'
   *  Sum: '<S799>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S799>/Multiply2' incorporates:
   *  Trigonometry: '<S799>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S798>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S803>/Abs' incorporates:
   *  Abs: '<S806>/Abs1'
   *  Switch: '<S803>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S803>/Switch1' incorporates:
   *  Abs: '<S803>/Abs'
   *  Bias: '<S803>/Bias2'
   *  Bias: '<S803>/Bias3'
   *  Constant: '<S800>/Constant'
   *  Constant: '<S800>/Constant1'
   *  Constant: '<S805>/Constant'
   *  Gain: '<S803>/Gain1'
   *  Product: '<S803>/Multiply'
   *  RelationalOperator: '<S805>/Compare'
   *  Switch: '<S800>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S806>/Switch1' incorporates:
     *  Bias: '<S806>/Bias2'
     *  Bias: '<S806>/Bias3'
     *  Constant: '<S806>/Constant'
     *  Constant: '<S807>/Constant'
     *  Math: '<S806>/Math Function'
     *  RelationalOperator: '<S807>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S806>/Switch1' */

    /* Signum: '<S803>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S803>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S800>/Sum' incorporates:
   *  Sum: '<S798>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S798>/Multiply' incorporates:
   *  Gain: '<S798>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S802>/Switch1' incorporates:
   *  Abs: '<S802>/Abs1'
   *  Bias: '<S802>/Bias2'
   *  Bias: '<S802>/Bias3'
   *  Constant: '<S802>/Constant'
   *  Constant: '<S804>/Constant'
   *  Math: '<S802>/Math Function'
   *  RelationalOperator: '<S804>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S802>/Switch1' */

  /* Product: '<S798>/Multiply' incorporates:
   *  Gain: '<S798>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S798>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S801>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S801>/Sum2' incorporates:
   *  Product: '<S801>/Multiply1'
   *  Product: '<S801>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S801>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S801>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S801>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S791>/Data Type Conversion' incorporates:
   *  Gain: '<S798>/Gain'
   *  Sum: '<S798>/Sum1'
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

    /* Delay: '<S28>/Delay' */
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

    /* End of Delay: '<S28>/Delay' */
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

    /* Delay: '<S28>/Delay' */
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

    /* End of Delay: '<S28>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
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
    FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
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
    if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
    if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1 >=
        500) {
      lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
      if ((uint32_T)lla_tmp > 255U) {
        lla_tmp = 255;
      }

      FMS_B.wp_index = (uint8_T)lla_tmp;
      FMS_DW.is_VTOL_Land_m = FMS_IN_NO_ACTIVE_CHILD_p;
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
      FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
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
          FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_p;
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
          FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
        } else {
          FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_p;
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
static void FMS_exit_internal_Mission(void)
{
  FMS_DW.is_Return_n = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_VTOL_Land_m = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
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
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
      } else if (FMS_B.on_ground) {
        FMS_DW.is_Mission = FMS_IN_Disarming;
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
          FMS_DW.is_Return_n = FMS_IN_NO_ACTIVE_CHILD_p;
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
            FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_p;
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
          FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_p;
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
            FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_p;
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
        if (FMS_DW.temporalCounter_i1 >=
            FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] * 250.0F) {
          tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          FMS_B.wp_index = (uint8_T)tmp_0;
          FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_p;
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
  /* RelationalOperator: '<S810>/Compare' incorporates:
   *  Abs: '<S794>/Abs'
   *  Constant: '<S810>/Constant'
   *  MinMax: '<S794>/Max'
   *  Sum: '<S794>/Sum'
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
      FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp_0 == 2.0) {
      FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
    } else if (tmp_0 == 1.0) {
      FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_o;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
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
      FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_SubMode = FMS_IN_Hold_h;
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
              VTOLState_Fixwing) || (FMS_B.vtol_state == VTOLState_ForwardTrans)))
        {
          FMS_DW.need_forwardtrans = 1.0;
        }

        FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
        FMS_sf_msg_send_VTOL_M();
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
          FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
        if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_f)) {
          FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_f = FMS_B.on_ground;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_d >= 500) {
          FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
                FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
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
            FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.durationLastReferenceTick_1_d =
              FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_SubMode = FMS_IN_Land;
            FMS_B.state = VehicleState_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1_f = FMS_B.on_ground;
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
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Auto;
              FMS_enter_internal_Auto();
            } else if (tmp_0 == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
            } else if (tmp_0 == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_o;
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
            if (FMS_B.vtol_state == VTOLState_Multicopter) {
              FMS_DW.is_Hold = FMS_IN_Loiter;
              FMS_B.Cmd_In.sp_waypoint[0] =
                FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
              FMS_B.Cmd_In.sp_waypoint[1] =
                FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
              FMS_B.Cmd_In.sp_waypoint[2] =
                FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
              FMS_B.Cmd_In.set_yaw = -1.0F;
              FMS_B.state = VehicleState_Hold;
            } else {
              FMS_DW.is_Hold = FMS_IN_BackTrans;
              if ((FMS_B.state == VehicleState_Mission) && ((FMS_B.vtol_state ==
                    VTOLState_Fixwing) || (FMS_B.vtol_state ==
                    VTOLState_ForwardTrans))) {
                FMS_DW.need_forwardtrans = 1.0;
              }

              FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
              FMS_sf_msg_send_VTOL_M();
            }
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
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
    } else {
      FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
    }

    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real32_T tmp[2];
  real_T tmp_0;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
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
      FMS_DW.condWasTrueAtLastTimeStep_1_f = FMS_B.on_ground;
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
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.durationLastReferenceTick_1_n =
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
            if (FMS_B.vtol_state == VTOLState_Multicopter) {
              FMS_DW.is_Hold = FMS_IN_Loiter;
              FMS_B.Cmd_In.sp_waypoint[0] =
                FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
              FMS_B.Cmd_In.sp_waypoint[1] =
                FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
              FMS_B.Cmd_In.sp_waypoint[2] =
                FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
              FMS_B.Cmd_In.set_yaw = -1.0F;
              FMS_B.state = VehicleState_Hold;
            } else {
              FMS_DW.is_Hold = FMS_IN_BackTrans;
              if ((FMS_B.state == VehicleState_Mission) && ((FMS_B.vtol_state ==
                    VTOLState_Fixwing) || (FMS_B.vtol_state ==
                    VTOLState_ForwardTrans))) {
                FMS_DW.need_forwardtrans = 1.0;
              }

              FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
              FMS_sf_msg_send_VTOL_M();
            }
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
          if (FMS_sf_msg_pop_M()) {
            c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            c_sf_internal_predicateOutput = false;
          }

          if (c_sf_internal_predicateOutput) {
            if (FMS_DW.is_Auto == FMS_IN_Mission) {
              FMS_exit_internal_Mission();
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
            } else {
              FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
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
            if (FMS_B.vtol_state == VTOLState_Multicopter) {
              FMS_DW.is_Hold = FMS_IN_Loiter;
              FMS_B.Cmd_In.sp_waypoint[0] =
                FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
              FMS_B.Cmd_In.sp_waypoint[1] =
                FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
              FMS_B.Cmd_In.sp_waypoint[2] =
                FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
              FMS_B.Cmd_In.set_yaw = -1.0F;
              FMS_B.state = VehicleState_Hold;
            } else {
              FMS_DW.is_Hold = FMS_IN_BackTrans;
              if ((FMS_B.state == VehicleState_Mission) && ((FMS_B.vtol_state ==
                    VTOLState_Fixwing) || (FMS_B.vtol_state ==
                    VTOLState_ForwardTrans))) {
                FMS_DW.need_forwardtrans = 1.0;
              }

              FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
              FMS_sf_msg_send_VTOL_M();
            }
          } else {
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
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
      /* Reshape: '<S793>/Reshape' incorporates:
       *  Constant: '<S793>/Constant'
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
      FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
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
      FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
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
        if (fabsf(FMS_B.DiscreteTimeIntegrator5_p) < 2.0F) {
          b_sf_internal_predicateOutput = true;
        } else if (FMS_DW.temporalCounter_i2 >= 5000U) {
          b_sf_internal_predicateOutput = true;
        } else {
          FMS_B.flag = FMS_B.BusConversion_InsertedFor_FMSSt.flag;

          /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.IsPosValid' */
          /* RelationalOperator: '<S796>/Compare' incorporates:
           *  Constant: '<S796>/Constant'
           *  S-Function (sfix_bitop): '<S788>/Bitwise AND'
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
          /* RelationalOperator: '<S789>/Relational Operator1' incorporates:
           *  Constant: '<S789>/Constant1'
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
        /* RelationalOperator: '<S787>/Relational Operator' incorporates:
         *  Constant: '<S787>/Constant'
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
          /* RelationalOperator: '<S786>/Relational Operator1' incorporates:
           *  Constant: '<S786>/Constant1'
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
  real32_T rtb_DiscreteTimeIntegrator_n;
  real32_T rtb_VectorConcatenate_or[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_kv[3];
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint16_T rtb_Divide_dr;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Divide_p3p[4];
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Saturation_ga;
  real32_T rtb_Saturation1_d;
  real32_T rtb_Switch_c2[3];
  real32_T rtb_Divide_c14[2];
  real32_T rtb_Square_ds[2];
  real32_T rtb_Saturation_o4;
  int32_T rtb_n;
  real32_T rtb_Switch_ov[3];
  real32_T rtb_a_bx;
  real32_T rtb_Integrator1_bx;
  real32_T rtb_Sign5_p2;
  real32_T rtb_Divide_hw;
  real32_T rtb_Sign5_i;
  real32_T rtb_Divide_pq;
  real32_T rtb_Sign5_kq;
  real32_T rtb_Add4_pb;
  MotionState rtb_state_ej;
  MotionState rtb_state_fg;
  MotionState rtb_state_og;
  real_T rtb_Switch1_n;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_aw;
  uint16_T rtb_y_cc;
  real32_T rtb_u_b;
  boolean_T rtb_Compare_o3;
  boolean_T rtb_Compare_aij;
  real32_T rtb_P_ap[2];
  real32_T rtb_Subtract_hb[2];
  real32_T rtb_MatrixConcatenate1_0[3];
  boolean_T tmp[3];
  boolean_T tmp_0[3];
  boolean_T tmp_1[3];
  real32_T rtb_P_f_idx_0;
  real32_T rtb_Divide_lr_idx_3;
  real32_T rtb_Divide_lr_idx_2;
  real32_T rtb_Divide_lr_idx_1;
  real32_T rtb_Divide_lr_idx_0;
  real_T rtb_Multiply_g_idx_0;
  real32_T y;
  uint32_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;

  /* Sqrt: '<S826>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S826>/Square'
   *  Sqrt: '<S21>/Sqrt'
   *  Sum: '<S826>/Sum of Elements'
   *  Switch: '<S1>/Switch'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S822>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Sqrt: '<S826>/Sqrt'
   */
  rtb_Divide_lr_idx_0 = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S823>/Square' incorporates:
   *  Math: '<S824>/Square'
   *  Math: '<S825>/Square'
   */
  rtb_Saturation_ga = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

  /* Math: '<S823>/Square2' incorporates:
   *  Math: '<S824>/Square2'
   *  Math: '<S825>/Square2'
   */
  rtb_Saturation1_d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S823>/Square1' incorporates:
   *  Math: '<S824>/Square1'
   *  Math: '<S825>/Square1'
   */
  rtb_Saturation_o4 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S823>/Square3' incorporates:
   *  Math: '<S824>/Square3'
   *  Math: '<S825>/Square3'
   */
  rtb_u_b = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

  /* Sum: '<S823>/Subtract' incorporates:
   *  Math: '<S823>/Square'
   *  Math: '<S823>/Square1'
   *  Math: '<S823>/Square2'
   *  Math: '<S823>/Square3'
   *  Sum: '<S823>/Add'
   *  Sum: '<S823>/Add1'
   */
  rtb_VectorConcatenate_or[0] = (rtb_Saturation_ga + rtb_Saturation_o4) -
    (rtb_Saturation1_d + rtb_u_b);

  /* Product: '<S823>/Multiply' incorporates:
   *  Product: '<S824>/Multiply'
   */
  d = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S823>/Multiply1' incorporates:
   *  Product: '<S824>/Multiply1'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_3;

  /* Gain: '<S823>/Gain' incorporates:
   *  Product: '<S823>/Multiply'
   *  Product: '<S823>/Multiply1'
   *  Sum: '<S823>/Subtract1'
   */
  rtb_VectorConcatenate_or[1] = (d - rtb_Integrator1_bx) * 2.0F;

  /* Product: '<S823>/Multiply2' incorporates:
   *  Product: '<S825>/Multiply'
   */
  rtb_a_bx = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_3;

  /* Product: '<S823>/Multiply3' incorporates:
   *  Product: '<S825>/Multiply1'
   */
  rtb_P_f_idx_0 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_2;

  /* Gain: '<S823>/Gain1' incorporates:
   *  Product: '<S823>/Multiply2'
   *  Product: '<S823>/Multiply3'
   *  Sum: '<S823>/Add2'
   */
  rtb_VectorConcatenate_or[2] = (rtb_a_bx + rtb_P_f_idx_0) * 2.0F;

  /* Gain: '<S824>/Gain' incorporates:
   *  Sum: '<S824>/Add3'
   */
  rtb_VectorConcatenate_or[3] = (d + rtb_Integrator1_bx) * 2.0F;

  /* Sum: '<S824>/Subtract' incorporates:
   *  Sum: '<S824>/Add'
   *  Sum: '<S824>/Add1'
   */
  rtb_VectorConcatenate_or[4] = (rtb_Saturation_ga + rtb_Saturation1_d) -
    (rtb_Saturation_o4 + rtb_u_b);

  /* Product: '<S824>/Multiply2' incorporates:
   *  Product: '<S825>/Multiply2'
   */
  d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_3;

  /* Product: '<S824>/Multiply3' incorporates:
   *  Product: '<S825>/Multiply3'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1;

  /* Gain: '<S824>/Gain1' incorporates:
   *  Product: '<S824>/Multiply2'
   *  Product: '<S824>/Multiply3'
   *  Sum: '<S824>/Subtract1'
   */
  rtb_VectorConcatenate_or[5] = (d - rtb_Integrator1_bx) * 2.0F;

  /* Gain: '<S825>/Gain' incorporates:
   *  Sum: '<S825>/Subtract2'
   */
  rtb_VectorConcatenate_or[6] = (rtb_a_bx - rtb_P_f_idx_0) * 2.0F;

  /* Gain: '<S825>/Gain1' incorporates:
   *  Sum: '<S825>/Add2'
   */
  rtb_VectorConcatenate_or[7] = (d + rtb_Integrator1_bx) * 2.0F;

  /* Sum: '<S825>/Subtract' incorporates:
   *  Sum: '<S825>/Add'
   *  Sum: '<S825>/Add1'
   */
  rtb_VectorConcatenate_or[8] = (rtb_Saturation_ga + rtb_u_b) -
    (rtb_Saturation_o4 + rtb_Saturation1_d);

  /* Math: '<S7>/Transpose' */
  for (rtb_n = 0; rtb_n < 3; rtb_n++) {
    rtb_MatrixConcatenate1[3 * rtb_n] = rtb_VectorConcatenate_or[rtb_n];
    rtb_MatrixConcatenate1[1 + 3 * rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3];
    rtb_MatrixConcatenate1[2 + 3 * rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6];
  }

  for (rtb_n = 0; rtb_n < 9; rtb_n++) {
    rtb_VectorConcatenate_or[rtb_n] = rtb_MatrixConcatenate1[rtb_n];
  }

  /* End of Math: '<S7>/Transpose' */

  /* Product: '<S7>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S7>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S7>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S7>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (rtb_n = 0; rtb_n < 3; rtb_n++) {
    rtb_Multiply_kv[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
      FMS_U.INS_Out.az + (rtb_VectorConcatenate_or[rtb_n + 3] * FMS_U.INS_Out.ay
                          + rtb_VectorConcatenate_or[rtb_n] * FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S7>/Multiply' */

  /* DiscreteIntegrator: '<S817>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_kv[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_kv[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_kv[2];
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_MatrixConcatenate3[0] = FMS_U.INS_Out.vn;
  rtb_MatrixConcatenate3[1] = FMS_U.INS_Out.ve;
  rtb_MatrixConcatenate3[2] = FMS_U.INS_Out.vd;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S42>/Arm' incorporates:
   *  ActionPort: '<S44>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S340>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S340>/Position' incorporates:
   *  ActionPort: '<S347>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S414>/Hold Control' incorporates:
   *  ActionPort: '<S416>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S341>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S341>/Offboard' incorporates:
   *  ActionPort: '<S453>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S343>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S343>/Land' incorporates:
   *  ActionPort: '<S643>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S343>/Takeoff' incorporates:
   *  ActionPort: '<S645>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
   *  ActionPort: '<S125>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S125>/Position' incorporates:
   *  ActionPort: '<S131>/Action Port'
   */
  /* SwitchCase: '<S125>/Switch Case' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  MultiPortSwitch: '<S535>/Index Vector'
   *  MultiPortSwitch: '<S600>/Index Vector'
   *  MultiPortSwitch: '<S601>/Index Vector'
   *  SwitchCase: '<S340>/Switch Case'
   *  SwitchCase: '<S341>/Switch Case'
   *  SwitchCase: '<S343>/Switch Case'
   *  SwitchCase: '<S414>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function1'
   *  Trigonometry: '<S100>/Trigonometric Function3'
   *  Trigonometry: '<S15>/Trigonometric Function1'
   *  Trigonometry: '<S15>/Trigonometric Function3'
   *  Trigonometry: '<S223>/Trigonometric Function1'
   *  Trigonometry: '<S223>/Trigonometric Function3'
   *  Trigonometry: '<S420>/Trigonometric Function1'
   *  Trigonometry: '<S420>/Trigonometric Function3'
   *  Trigonometry: '<S546>/Trigonometric Function1'
   *  Trigonometry: '<S546>/Trigonometric Function3'
   *  Trigonometry: '<S609>/Trigonometric Function1'
   *  Trigonometry: '<S609>/Trigonometric Function3'
   *  Trigonometry: '<S613>/Trigonometric Function1'
   *  Trigonometry: '<S613>/Trigonometric Function3'
   *  Trigonometry: '<S639>/Trigonometric Function1'
   *  Trigonometry: '<S639>/Trigonometric Function3'
   *  Trigonometry: '<S703>/Trigonometric Function1'
   *  Trigonometry: '<S703>/Trigonometric Function3'
   *  Trigonometry: '<S784>/Trigonometric Function1'
   *  Trigonometry: '<S784>/Trigonometric Function3'
   */
  rtb_Saturation_ga = arm_cos_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S125>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S343>/Takeoff' */
  /* End of Outputs for SubSystem: '<S343>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S341>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S414>/Hold Control' */
  /* End of Outputs for SubSystem: '<S340>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Trigonometry: '<S15>/Trigonometric Function1' */
  rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S42>/Arm' incorporates:
   *  ActionPort: '<S44>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S340>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S340>/Position' incorporates:
   *  ActionPort: '<S347>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S414>/Hold Control' incorporates:
   *  ActionPort: '<S416>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S341>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S341>/Offboard' incorporates:
   *  ActionPort: '<S453>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S343>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S343>/Land' incorporates:
   *  ActionPort: '<S643>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S343>/Takeoff' incorporates:
   *  ActionPort: '<S645>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
   *  ActionPort: '<S125>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S125>/Position' incorporates:
   *  ActionPort: '<S131>/Action Port'
   */
  /* SwitchCase: '<S125>/Switch Case' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  MultiPortSwitch: '<S535>/Index Vector'
   *  MultiPortSwitch: '<S600>/Index Vector'
   *  MultiPortSwitch: '<S601>/Index Vector'
   *  SwitchCase: '<S340>/Switch Case'
   *  SwitchCase: '<S341>/Switch Case'
   *  SwitchCase: '<S343>/Switch Case'
   *  SwitchCase: '<S414>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function2'
   *  Trigonometry: '<S223>/Trigonometric Function'
   *  Trigonometry: '<S420>/Trigonometric Function'
   *  Trigonometry: '<S546>/Trigonometric Function'
   *  Trigonometry: '<S609>/Trigonometric Function'
   *  Trigonometry: '<S613>/Trigonometric Function'
   *  Trigonometry: '<S639>/Trigonometric Function'
   *  Trigonometry: '<S703>/Trigonometric Function'
   *  Trigonometry: '<S784>/Trigonometric Function'
   */
  rtb_Saturation1_d = arm_sin_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S125>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S343>/Takeoff' */
  /* End of Outputs for SubSystem: '<S343>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S341>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S414>/Hold Control' */
  /* End of Outputs for SubSystem: '<S340>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Trigonometry: '<S15>/Trigonometric Function' */
  rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

  /* SignalConversion: '<S15>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S15>/Constant3'
   */
  rtb_VectorConcatenate_or[2] = 0.0F;

  /* Gain: '<S15>/Gain' */
  rtb_VectorConcatenate_or[3] = -rtb_Saturation1_d;

  /* Trigonometry: '<S15>/Trigonometric Function3' */
  rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

  /* SignalConversion: '<S15>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  rtb_VectorConcatenate_or[5] = 0.0F;

  /* SignalConversion: '<S15>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3[2];

  /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S30>/FixPt Relational Operator'
   *  UnitDelay: '<S30>/Delay Input1'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  DataTypeConversion: '<S28>/Data Type Conversion2'
   *  Delay: '<S28>/Delay'
   *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S28>/Logical Operator'
   *  Logic: '<S28>/Logical Operator1'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S35>/Compare'
   *  RelationalOperator: '<S36>/Compare'
   *  RelationalOperator: '<S37>/FixPt Relational Operator'
   *  Switch: '<S28>/Switch1'
   *  UnitDelay: '<S37>/Delay Input1'
   *
   * Block description for '<S37>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S28>/Switch1' incorporates:
       *  DataTypeConversion: '<S28>/Data Type Conversion1'
       *  Delay: '<S28>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S28>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S28>/Delay'
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
    rtb_DiscreteTimeIntegrator_n = FMS_U.INS_Out.airspeed;
  } else {
    /* Product: '<S17>/Divide' */
    rtb_Divide_p3p[0] = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
    rtb_Divide_p3p[1] = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
    rtb_Divide_p3p[2] = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
    rtb_Divide_p3p[3] = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

    /* Math: '<S20>/Square' incorporates:
     *  Math: '<S18>/Square'
     *  Math: '<S19>/Square'
     */
    rtb_Saturation_o4 = rtb_Divide_p3p[0] * rtb_Divide_p3p[0];

    /* Math: '<S20>/Square2' incorporates:
     *  Math: '<S18>/Square2'
     *  Math: '<S19>/Square2'
     */
    rtb_u_b = rtb_Divide_p3p[2] * rtb_Divide_p3p[2];

    /* Math: '<S20>/Square1' incorporates:
     *  Math: '<S18>/Square1'
     *  Math: '<S19>/Square1'
     */
    rtb_DiscreteTimeIntegrator_n = rtb_Divide_p3p[1] * rtb_Divide_p3p[1];

    /* Math: '<S20>/Square3' incorporates:
     *  Math: '<S18>/Square3'
     *  Math: '<S19>/Square3'
     */
    rtb_Divide_lr_idx_0 = rtb_Divide_p3p[3] * rtb_Divide_p3p[3];

    /* Sum: '<S20>/Subtract' incorporates:
     *  Math: '<S20>/Square'
     *  Math: '<S20>/Square1'
     *  Math: '<S20>/Square2'
     *  Math: '<S20>/Square3'
     *  Sum: '<S20>/Add'
     *  Sum: '<S20>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Saturation_o4 + rtb_Divide_lr_idx_0) -
      (rtb_DiscreteTimeIntegrator_n + rtb_u_b);

    /* Product: '<S20>/Multiply2' incorporates:
     *  Product: '<S19>/Multiply2'
     */
    rtb_Divide_lr_idx_1 = rtb_Divide_p3p[2] * rtb_Divide_p3p[3];

    /* Product: '<S20>/Multiply3' incorporates:
     *  Product: '<S19>/Multiply3'
     */
    rtb_Divide_lr_idx_2 = rtb_Divide_p3p[0] * rtb_Divide_p3p[1];

    /* Gain: '<S20>/Gain1' incorporates:
     *  Product: '<S20>/Multiply2'
     *  Product: '<S20>/Multiply3'
     *  Sum: '<S20>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Divide_lr_idx_1 + rtb_Divide_lr_idx_2) *
      2.0F;

    /* Product: '<S20>/Multiply' incorporates:
     *  Product: '<S18>/Multiply2'
     */
    rtb_Divide_lr_idx_3 = rtb_Divide_p3p[1] * rtb_Divide_p3p[3];

    /* Product: '<S20>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply3'
     */
    d = rtb_Divide_p3p[0] * rtb_Divide_p3p[2];

    /* Gain: '<S20>/Gain' incorporates:
     *  Product: '<S20>/Multiply'
     *  Product: '<S20>/Multiply1'
     *  Sum: '<S20>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Divide_lr_idx_3 - d) * 2.0F;

    /* Gain: '<S19>/Gain1' incorporates:
     *  Sum: '<S19>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Divide_lr_idx_1 - rtb_Divide_lr_idx_2) *
      2.0F;

    /* Sum: '<S19>/Subtract' incorporates:
     *  Sum: '<S19>/Add'
     *  Sum: '<S19>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Saturation_o4 + rtb_u_b) -
      (rtb_DiscreteTimeIntegrator_n + rtb_Divide_lr_idx_0);

    /* Product: '<S19>/Multiply' incorporates:
     *  Product: '<S18>/Multiply'
     */
    rtb_Divide_lr_idx_1 = rtb_Divide_p3p[1] * rtb_Divide_p3p[2];

    /* Product: '<S19>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply1'
     */
    rtb_Divide_lr_idx_2 = rtb_Divide_p3p[0] * rtb_Divide_p3p[3];

    /* Gain: '<S19>/Gain' incorporates:
     *  Product: '<S19>/Multiply'
     *  Product: '<S19>/Multiply1'
     *  Sum: '<S19>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Divide_lr_idx_1 + rtb_Divide_lr_idx_2) *
      2.0F;

    /* Gain: '<S18>/Gain1' incorporates:
     *  Sum: '<S18>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Divide_lr_idx_3 + d) * 2.0F;

    /* Gain: '<S18>/Gain' incorporates:
     *  Sum: '<S18>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Divide_lr_idx_1 - rtb_Divide_lr_idx_2) *
      2.0F;

    /* Sum: '<S18>/Subtract' incorporates:
     *  Sum: '<S18>/Add'
     *  Sum: '<S18>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Saturation_o4 +
      rtb_DiscreteTimeIntegrator_n) - (rtb_u_b + rtb_Divide_lr_idx_0);

    /* Product: '<S13>/Multiply' */
    for (rtb_n = 0; rtb_n < 3; rtb_n++) {
      rtb_MatrixConcatenate1_0[rtb_n] = rtb_MatrixConcatenate1[rtb_n + 6] *
        rtb_MatrixConcatenate3[2] + (rtb_MatrixConcatenate1[rtb_n + 3] *
        rtb_MatrixConcatenate3[1] + rtb_MatrixConcatenate1[rtb_n] *
        rtb_MatrixConcatenate3[0]);
    }

    /* End of Product: '<S13>/Multiply' */
    rtb_DiscreteTimeIntegrator_n = rtb_MatrixConcatenate1_0[0];
  }

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_n > 100.0F) {
    rtb_DiscreteTimeIntegrator_n = 100.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator_n < 0.1F) {
      rtb_DiscreteTimeIntegrator_n = 0.1F;
    }
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_o = rtb_DiscreteTimeIntegrator_n;
  }

  FMS_B.DiscreteTimeIntegrator5 = FMS_DW.DiscreteTimeIntegrator5_DSTAT_o;

  /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */

  /* DataTypeConversion: '<S27>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant1'
   *  DataTypeConversion: '<S27>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S32>/FixPt Relational Operator'
   *  RelationalOperator: '<S33>/FixPt Relational Operator'
   *  Switch: '<S27>/Switch2'
   *  UnitDelay: '<S32>/Delay Input1'
   *  UnitDelay: '<S33>/Delay Input1'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S33>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S27>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S39>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S39>/Delay Input1'
   *
   * Block description for '<S39>/Delay Input1':
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
   *  RelationalOperator: '<S38>/FixPt Relational Operator'
   *  UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
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
   *  Constant: '<S40>/Constant'
   *  Constant: '<S4>/Constant1'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  RelationalOperator: '<S40>/Compare'
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

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S7>/Sum of Elements'
   */
  rtb_Divide_dr = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S819>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S819>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_L_af != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_u_b = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_u_b > 1.0F) {
    rtb_u_b = 1.0F;
  } else {
    if (rtb_u_b < 0.9F) {
      rtb_u_b = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_lr_idx_0 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_u_b;

  /* DiscreteIntegrator: '<S818>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_lr_idx_0;
  }

  /* Delay: '<S7>/Delay' */
  rtb_FixPtRelationalOperator_me = FMS_DW.Delay_DSTATE_a;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S7>/Delay'
   */
  if (FMS_DW.Delay_DSTATE_a || (FMS_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_c = 0U;
  }

  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_c >= 1000000U) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_c = 1000000U;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_c <= 0U) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_c = 0U;
    }
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S815>/Constant'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S817>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S818>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S819>/Discrete-Time Integrator5'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S820>/AND'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S815>/Compare'
   *  RelationalOperator: '<S820>/Lower Test'
   *  RelationalOperator: '<S820>/Upper Test'
   */
  FMS_B.on_ground = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) &&
                     ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) &&
                     ((-10.306F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d <
                      FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) &&
                     (FMS_DW.DiscreteTimeIntegrator_DSTATE_c >= 10000U));

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Delay: '<S24>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S23>/FixPt Relational Operator'
   *  Switch: '<S24>/Switch'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
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
   *  Constant: '<S22>/Constant'
   *  Constant: '<S25>/Upper Limit'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S25>/Upper Test'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion_n = (VTOLMode)FMS_U.Pilot_Cmd.cmd_2;

  /* Product: '<S12>/Multiply' */
  for (rtb_n = 0; rtb_n < 3; rtb_n++) {
    rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
      rtb_MatrixConcatenate3[2] + (rtb_VectorConcatenate_or[rtb_n + 3] *
      rtb_MatrixConcatenate3[1] + rtb_VectorConcatenate_or[rtb_n] *
      rtb_MatrixConcatenate3[0]);
  }

  /* End of Product: '<S12>/Multiply' */

  /* Signum: '<S12>/Sign' */
  if (rtb_MatrixConcatenate1_0[0] < 0.0F) {
    rtb_Divide_lr_idx_1 = -1.0F;
  } else if (rtb_MatrixConcatenate1_0[0] > 0.0F) {
    rtb_Divide_lr_idx_1 = 1.0F;
  } else {
    rtb_Divide_lr_idx_1 = rtb_MatrixConcatenate1_0[0];
  }

  /* End of Signum: '<S12>/Sign' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S42>/Arm' incorporates:
   *  ActionPort: '<S44>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S126>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
   *  ActionPort: '<S239>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S239>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S243>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
   *  ActionPort: '<S128>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
   *  ActionPort: '<S275>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Takeoff' incorporates:
   *  ActionPort: '<S276>/Action Port'
   */
  /* SwitchCase: '<S126>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S264>/Math Function'
   *  Math: '<S313>/Math Function'
   *  Math: '<S335>/Math Function'
   *  SwitchCase: '<S128>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   */
  rtb_Saturation_o4 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S128>/Takeoff' */
  /* End of Outputs for SubSystem: '<S128>/Return' */
  /* End of Outputs for SubSystem: '<S239>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S126>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */

  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S341>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S341>/Mission' incorporates:
   *  ActionPort: '<S452>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S452>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S456>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S343>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S343>/Return' incorporates:
   *  ActionPort: '<S644>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Hold' incorporates:
   *  ActionPort: '<S273>/Action Port'
   */
  /* SwitchCase: '<S128>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S290>/Sum of Elements'
   *  Sum: '<S524>/Sum of Elements'
   *  Sum: '<S764>/Sum of Elements'
   *  SwitchCase: '<S341>/Switch Case'
   *  SwitchCase: '<S343>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Integrator1_bx = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S340>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S340>/Position' incorporates:
   *  ActionPort: '<S347>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S126>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
   *  ActionPort: '<S239>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S239>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S243>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
   *  ActionPort: '<S275>/Action Port'
   */
  /* SwitchCase: '<S126>/Switch Case' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S263>/Sqrt'
   *  Sqrt: '<S289>/Sqrt'
   *  Sqrt: '<S312>/Sqrt'
   *  Sqrt: '<S415>/Sqrt'
   *  Sqrt: '<S522>/Sqrt'
   *  Sqrt: '<S762>/Sqrt'
   *  Sum: '<S1>/Add'
   *  SwitchCase: '<S128>/Switch Case'
   *  SwitchCase: '<S340>/Switch Case'
   *  SwitchCase: '<S341>/Switch Case'
   *  SwitchCase: '<S343>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Divide_lr_idx_2 = sqrtf(rtb_Integrator1_bx);

  /* End of Outputs for SubSystem: '<S128>/Return' */
  /* End of Outputs for SubSystem: '<S239>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S126>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */
  /* End of Outputs for SubSystem: '<S340>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S128>/Hold' */
  /* End of Outputs for SubSystem: '<S343>/Return' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S452>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S341>/Mission' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S49>/SubMode' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   */
  rtb_Divide_lr_idx_1 *= rtb_Divide_lr_idx_2;

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_m != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_h = rtb_Divide_lr_idx_1;
  }

  FMS_B.DiscreteTimeIntegrator5_p = FMS_DW.DiscreteTimeIntegrator5_DSTAT_h;

  /* End of DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_f)) {
    FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_f = FMS_B.on_ground;
  rtb_Compare_o3 = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Compare_o3) || (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_o = rtb_Compare_o3;
  rtb_Compare_o3 = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Compare_o3) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Compare_o3;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
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

  /* RelationalOperator: '<S816>/Compare' incorporates:
   *  Constant: '<S816>/Constant'
   *  Delay: '<S7>/Delay'
   */
  FMS_DW.Delay_DSTATE_a = (FMS_B.vtol_state != VTOLState_Multicopter);

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* SignalConversion: '<S43>/Signal Copy1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_p3p[0] = FMS_U.INS_Out.quat[0];
  rtb_Divide_p3p[1] = FMS_U.INS_Out.quat[1];
  rtb_Divide_p3p[2] = FMS_U.INS_Out.quat[2];
  rtb_Divide_p3p[3] = FMS_U.INS_Out.quat[3];

  /* SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_ov[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_ov[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_ov[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* SwitchCase: '<S42>/Switch Case' incorporates:
   *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S44>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
     case 0:
      /* Disable for SwitchCase: '<S49>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
       case 0:
        /* Disable for SwitchCase: '<S128>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S126>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S125>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S138>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S178>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S163>/Switch Case' */
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
      /* Disable for SwitchCase: '<S54>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S50>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S343>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S743>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S733>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S682>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S650>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S661>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S341>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S452>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S503>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S493>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S452>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S340>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S439>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S355>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S389>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S414>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S401>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S44>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S42>/Disarm' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S45>/Bus Assignment'
     *  BusAssignment: '<S46>/Bus Assignment'
     *  Constant: '<S46>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S46>/Bus Assignment' incorporates:
     *  BusAssignment: '<S45>/Bus Assignment'
     *  Constant: '<S46>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_mv;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ap;

    /* End of Outputs for SubSystem: '<S42>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S42>/Standby' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S45>/Bus Assignment'
     *  BusAssignment: '<S47>/Bus Assignment'
     *  Constant: '<S47>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S47>/Bus Assignment' incorporates:
     *  BusAssignment: '<S45>/Bus Assignment'
     *  Constant: '<S47>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_hd;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ft;

    /* End of Outputs for SubSystem: '<S42>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S42>/Arm' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* SwitchCase: '<S44>/Switch Case' incorporates:
     *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy8Inport1'
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
        /* Disable for SwitchCase: '<S49>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
         case 0:
          /* Disable for SwitchCase: '<S128>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S126>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S125>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S138>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S178>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S163>/Switch Case' */
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
        /* Disable for SwitchCase: '<S54>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S50>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S343>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S743>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S733>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S682>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S650>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S661>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S341>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S452>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S503>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S493>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S452>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S340>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S439>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S355>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S373>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S389>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S414>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S401>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      /* SwitchCase: '<S49>/Switch Case' */
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
          /* Disable for SwitchCase: '<S128>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S126>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S125>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S138>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S178>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S163>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
         *  ActionPort: '<S128>/Action Port'
         */
        /* SwitchCase: '<S128>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S128>/Takeoff' incorporates:
           *  ActionPort: '<S276>/Action Port'
           */
          /* Sum: '<S335>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

          /* Math: '<S335>/Math Function1' incorporates:
           *  Sum: '<S335>/Sum of Elements'
           *
           * About '<S335>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S335>/Math Function1' */

          /* Switch: '<S335>/Switch' incorporates:
           *  Constant: '<S335>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S335>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_ga > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S335>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S325>/NearbyRefWP' incorporates:
           *  Constant: '<S323>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_c14,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S325>/SearchL1RefWP' incorporates:
           *  Constant: '<S323>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_ap, &rtb_u_b);

          /* MATLAB Function: '<S325>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S320>/Sum'
           *  Sum: '<S320>/Sum1'
           */
          rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Integrator1_bx = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Integrator1_bx * rtb_Integrator1_bx;
          rtb_Saturation_ga = (rtb_a_bx * rtb_Integrator1_bx + d *
                               rtb_Divide_lr_idx_2) / (rtb_P_f_idx_0 +
            rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2);
          if (rtb_Saturation_ga <= 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_ga = FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else if (rtb_Saturation_ga >= 1.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];
            rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_p2 = (rtb_Saturation_ga * rtb_Divide_lr_idx_2 +
                            FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Sign5_p2 * rtb_Sign5_p2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_p2 = (rtb_Saturation_ga * rtb_Integrator1_bx +
                            FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_ga += sqrtf(rtb_Sign5_p2 * rtb_Sign5_p2 +
              rtb_Subtract_hb[0]) * 0.5774F / sqrtf(rtb_Divide_lr_idx_2 *
              rtb_Divide_lr_idx_2 + rtb_P_f_idx_0);
            if (rtb_Saturation_ga > 1.0F) {
              rtb_Saturation_ga = 1.0F;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = rtb_Saturation_ga * rtb_Divide_lr_idx_2 +
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_ga = rtb_Saturation_ga * rtb_Integrator1_bx +
              FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S325>/OutRegionRegWP' */

          /* Switch: '<S325>/Switch1' incorporates:
           *  Constant: '<S328>/Constant'
           *  RelationalOperator: '<S328>/Compare'
           */
          if (rtb_Saturation1_d <= 0.0F) {
            /* Switch: '<S325>/Switch' incorporates:
             *  Constant: '<S327>/Constant'
             *  RelationalOperator: '<S327>/Compare'
             */
            if (rtb_u_b >= 0.0F) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            } else {
              rtb_Divide_c14[0] = rtb_P_f_idx_0;
              rtb_Divide_c14[1] = rtb_Saturation_ga;
            }

            /* End of Switch: '<S325>/Switch' */
          }

          /* End of Switch: '<S325>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S326>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S336>/Sum of Elements' incorporates:
           *  Math: '<S336>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S336>/Math Function1' incorporates:
           *  Sum: '<S336>/Sum of Elements'
           *
           * About '<S336>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S336>/Math Function1' */

          /* Switch: '<S336>/Switch' incorporates:
           *  Constant: '<S336>/Constant'
           *  Product: '<S336>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S336>/Switch' */

          /* Product: '<S335>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S338>/Sum of Elements' incorporates:
           *  Math: '<S338>/Math Function'
           *  SignalConversion: '<S338>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S338>/Math Function1' incorporates:
           *  Sum: '<S338>/Sum of Elements'
           *
           * About '<S338>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S338>/Math Function1' */

          /* Switch: '<S338>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  Product: '<S338>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S338>/Switch' */

          /* Product: '<S336>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S339>/Sum of Elements' incorporates:
           *  Math: '<S339>/Math Function'
           *  SignalConversion: '<S339>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S339>/Math Function1' incorporates:
           *  Sum: '<S339>/Sum of Elements'
           *
           * About '<S339>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S339>/Math Function1' */

          /* Switch: '<S339>/Switch' incorporates:
           *  Constant: '<S339>/Constant'
           *  Product: '<S339>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S339>/Switch' */

          /* Product: '<S339>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S338>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S339>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S338>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S320>/Divide' incorporates:
           *  Math: '<S321>/Square'
           *  Math: '<S322>/Square'
           *  Sqrt: '<S321>/Sqrt'
           *  Sqrt: '<S322>/Sqrt'
           *  Sum: '<S321>/Sum of Elements'
           *  Sum: '<S322>/Sum of Elements'
           */
          rtb_Divide_lr_idx_2 = sqrtf(rtb_a_bx * rtb_a_bx + d * d) / sqrtf
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 + rtb_Integrator1_bx *
             rtb_Integrator1_bx);

          /* Saturate: '<S320>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S320>/Saturation' */

          /* Sum: '<S337>/Subtract' incorporates:
           *  Product: '<S337>/Multiply'
           *  Product: '<S337>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S333>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S333>/Sign1' */

          /* Switch: '<S333>/Switch2' incorporates:
           *  Constant: '<S333>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S333>/Switch2' */

          /* DotProduct: '<S333>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S333>/Acos' incorporates:
           *  DotProduct: '<S333>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S333>/Multiply' incorporates:
           *  Trigonometry: '<S333>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S332>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S332>/Saturation' */

          /* Sqrt: '<S334>/Sqrt' incorporates:
           *  Sum: '<S334>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(rtb_Saturation_o4 + rtb_Divide_lr_idx_3);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S276>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S276>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S276>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S276>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S332>/Divide' incorporates:
           *  Constant: '<S323>/L1'
           *  Gain: '<S332>/Gain'
           *  Math: '<S332>/Square'
           *  Product: '<S332>/Multiply1'
           *  Trigonometry: '<S332>/Sin'
           */
          rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F * arm_sin_f32
            (rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S323>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S276>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S276>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S276>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S323>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S318>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S320>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S318>/Sum2'
           *  Sum: '<S320>/Add'
           *  Sum: '<S320>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_lr_idx_2 +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S318>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S276>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S276>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S276>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S318>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S128>/Land' incorporates:
           *  ActionPort: '<S274>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S274>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S274>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S274>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S274>/Constant'
           *  Constant: '<S274>/Constant4'
           *  Constant: '<S274>/Constant5'
           *  Constant: '<S274>/Constant7'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S128>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
           *  ActionPort: '<S275>/Action Port'
           */
          /* Math: '<S313>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Divide_lr_idx_3;

          /* Sum: '<S313>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

          /* Math: '<S313>/Math Function1' incorporates:
           *  Sum: '<S313>/Sum of Elements'
           *
           * About '<S313>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S313>/Math Function1' */

          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S313>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S313>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S313>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S303>/NearbyRefWP' incorporates:
           *  Constant: '<S301>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S303>/SearchL1RefWP' incorporates:
           *  Constant: '<S301>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_c14, &rtb_Saturation1_d);

          /* MATLAB Function: '<S303>/OutRegionRegWP' incorporates:
           *  Constant: '<S301>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S303>/Switch1' incorporates:
           *  Constant: '<S306>/Constant'
           *  RelationalOperator: '<S306>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_c14[0] = rtb_Subtract_hb[0];
            rtb_Divide_c14[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S305>/Compare' incorporates:
             *  Constant: '<S305>/Constant'
             */
            rtb_Compare_o3 = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S303>/Switch' */
            if (!rtb_Compare_o3) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S303>/Switch' */
          }

          /* End of Switch: '<S303>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S304>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S314>/Sum of Elements' incorporates:
           *  Math: '<S314>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S314>/Math Function1' incorporates:
           *  Sum: '<S314>/Sum of Elements'
           *
           * About '<S314>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S314>/Math Function1' */

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S314>/Constant'
           *  Product: '<S314>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_o4;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S314>/Switch' */

          /* Product: '<S313>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S316>/Sum of Elements' incorporates:
           *  Math: '<S316>/Math Function'
           *  SignalConversion: '<S316>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S316>/Math Function1' incorporates:
           *  Sum: '<S316>/Sum of Elements'
           *
           * About '<S316>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S316>/Math Function1' */

          /* Switch: '<S316>/Switch' incorporates:
           *  Constant: '<S316>/Constant'
           *  Product: '<S316>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S316>/Switch' */

          /* Product: '<S314>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S317>/Sum of Elements' incorporates:
           *  Math: '<S317>/Math Function'
           *  SignalConversion: '<S317>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S317>/Math Function1' incorporates:
           *  Sum: '<S317>/Sum of Elements'
           *
           * About '<S317>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S317>/Math Function1' */

          /* Switch: '<S317>/Switch' incorporates:
           *  Constant: '<S317>/Constant'
           *  Product: '<S317>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_o4;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S317>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S298>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S317>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S316>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S298>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S317>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S316>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S298>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S298>/Divide' incorporates:
           *  Math: '<S299>/Square'
           *  Math: '<S300>/Square'
           *  Sqrt: '<S299>/Sqrt'
           *  Sqrt: '<S300>/Sqrt'
           *  Sum: '<S298>/Sum'
           *  Sum: '<S298>/Sum1'
           *  Sum: '<S299>/Sum of Elements'
           *  Sum: '<S300>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_bx * rtb_a_bx + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S298>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S298>/Saturation' */

          /* Sum: '<S315>/Subtract' incorporates:
           *  Product: '<S315>/Multiply'
           *  Product: '<S315>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S311>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S311>/Sign1' */

          /* Switch: '<S311>/Switch2' incorporates:
           *  Constant: '<S311>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S311>/Switch2' */

          /* DotProduct: '<S311>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S311>/Acos' incorporates:
           *  DotProduct: '<S311>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S311>/Multiply' incorporates:
           *  Trigonometry: '<S311>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S310>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S310>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S275>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S275>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S275>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S310>/Divide' incorporates:
           *  Constant: '<S301>/L1'
           *  Gain: '<S310>/Gain'
           *  Math: '<S310>/Square'
           *  Product: '<S310>/Multiply1'
           *  Trigonometry: '<S310>/Sin'
           */
          rtb_u_b = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S301>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S301>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S296>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S298>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S296>/Sum2'
           *  Sum: '<S298>/Add'
           *  Sum: '<S298>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S296>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S275>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S296>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S128>/Hold' incorporates:
             *  ActionPort: '<S273>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S128>/Switch Case' incorporates:
             *  Delay: '<S278>/Delay'
             *  Delay: '<S283>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S128>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S128>/Hold' incorporates:
           *  ActionPort: '<S273>/Action Port'
           */
          /* Math: '<S290>/Math Function1'
           *
           * About '<S290>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S290>/Math Function1' */

          /* Switch: '<S290>/Switch' incorporates:
           *  Constant: '<S290>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S290>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_ga > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_MatrixConcatenate3[0] = FMS_U.INS_Out.vn;
            rtb_MatrixConcatenate3[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S290>/Switch' */

          /* Delay: '<S283>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S295>/Sum of Elements' incorporates:
           *  Delay: '<S283>/start_vel'
           *  Math: '<S295>/Math Function'
           */
          rtb_u_b = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S295>/Math Function1' incorporates:
           *  Sum: '<S295>/Sum of Elements'
           *
           * About '<S295>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S295>/Math Function1' */

          /* Switch: '<S295>/Switch' incorporates:
           *  Constant: '<S295>/Constant'
           *  Delay: '<S283>/start_vel'
           *  Product: '<S295>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_ov[0] = FMS_DW.start_vel_DSTATE[0];
            rtb_Switch_ov[1] = FMS_DW.start_vel_DSTATE[1];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S295>/Switch' */

          /* Product: '<S290>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S293>/Sum of Elements' incorporates:
           *  Math: '<S293>/Math Function'
           *  SignalConversion: '<S293>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S293>/Math Function1' incorporates:
           *  Sum: '<S293>/Sum of Elements'
           *
           * About '<S293>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S293>/Math Function1' */

          /* Switch: '<S293>/Switch' incorporates:
           *  Constant: '<S293>/Constant'
           *  Product: '<S293>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Divide_c14[1];
            rtb_MatrixConcatenate3[1] = rtb_Divide_c14[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S293>/Switch' */

          /* MinMax: '<S281>/Max' incorporates:
           *  Constant: '<S279>/L1'
           *  Constant: '<S279>/R'
           *  Gain: '<S281>/Gain'
           */
          rtb_Saturation_ga = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S281>/SearchL1RefWP' incorporates:
           *  Constant: '<S279>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S286>/TmpSignal ConversionAt SFunction Inport2'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_ap[0] = 0.0F;
          rtb_P_ap[1] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.sp_waypoint[0]) &&
              (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.sp_waypoint[1]) &&
              (rtb_Saturation_ga == FMS_PARAM.FW_L1)) {
            rtb_n = 0;
          } else {
            rtb_u_b = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_u_b *
                      rtb_u_b);
            rtb_Saturation_o4 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Saturation1_d = ((d * d + rtb_Saturation_o4) - rtb_Saturation_ga
                                 * rtb_Saturation_ga) / (2.0F * d);
            rtb_Square_ds[0] = rtb_u_b / d;
            rtb_Divide_lr_idx_3 /= d;
            rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d;
            if (rtb_u_b > rtb_Saturation_o4) {
              rtb_n = 0;
            } else if (rtb_u_b == rtb_Saturation_o4) {
              rtb_n = 1;
              rtb_P_ap[0] = rtb_Saturation1_d * rtb_Square_ds[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_ap[1] = rtb_Saturation1_d * rtb_Divide_lr_idx_3 +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation_o4 = sqrtf(rtb_Saturation_o4 - rtb_u_b);
              rtb_P_ap[0] = (rtb_Saturation1_d * rtb_Square_ds[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation_o4 *
                -rtb_Divide_lr_idx_3;
              rtb_P_ap[1] = (rtb_Saturation1_d * rtb_Divide_lr_idx_3 +
                             FMS_U.INS_Out.y_R) + rtb_Saturation_o4 *
                rtb_Square_ds[0];
            }
          }

          /* End of MATLAB Function: '<S281>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S284>/Compare' incorporates:
           *  Constant: '<S284>/Constant'
           */
          rtb_Compare_o3 = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S281>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract_hb[0] = rtb_u_b * rtb_u_b;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_u_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract_hb[1] = rtb_u_b * rtb_u_b;

          /* Switch: '<S281>/Switch' incorporates:
           *  Constant: '<S279>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S281>/OutRegionRegWP'
           *  Product: '<S295>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Compare_o3) {
            rtb_Saturation1_d = rtb_P_ap[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S281>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation1_d = rtb_Switch_ov[0] / rtb_Switch_ov[2] *
              FMS_PARAM.FW_L1 + FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S282>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_ds[0] = rtb_Saturation1_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S281>/Switch' incorporates:
           *  Constant: '<S279>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S281>/OutRegionRegWP'
           *  Product: '<S295>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Compare_o3) {
            rtb_Saturation1_d = rtb_P_ap[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S281>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation1_d = rtb_Switch_ov[1] / rtb_Switch_ov[2] *
              FMS_PARAM.FW_L1 + FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S282>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_ds[1] = rtb_Saturation1_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S291>/Sum of Elements' incorporates:
           *  Math: '<S291>/Math Function'
           */
          rtb_u_b = rtb_Square_ds[0] * rtb_Square_ds[0] + rtb_Square_ds[1] *
            rtb_Square_ds[1];

          /* Math: '<S291>/Math Function1' incorporates:
           *  Sum: '<S291>/Sum of Elements'
           *
           * About '<S291>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S291>/Math Function1' */

          /* Switch: '<S291>/Switch' incorporates:
           *  Constant: '<S291>/Constant'
           *  Product: '<S291>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_ov[0] = rtb_Square_ds[0];
            rtb_Switch_ov[1] = rtb_Square_ds[1];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S291>/Switch' */

          /* Product: '<S291>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_c14[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S294>/Sum of Elements' incorporates:
           *  Math: '<S294>/Math Function'
           *  SignalConversion: '<S294>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S294>/Math Function1' incorporates:
           *  Sum: '<S294>/Sum of Elements'
           *
           * About '<S294>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S294>/Math Function1' */

          /* Switch: '<S294>/Switch' incorporates:
           *  Constant: '<S294>/Constant'
           *  Product: '<S294>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_ov[0] = rtb_Divide_c14[1];
            rtb_Switch_ov[1] = rtb_Divide_c14[0];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S294>/Switch' */

          /* Product: '<S294>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S293>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S294>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S293>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S292>/Subtract' incorporates:
           *  Product: '<S292>/Multiply'
           *  Product: '<S292>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Divide_c14[0] * rtb_Subtract_hb[1] -
            rtb_Divide_c14[1] * rtb_Subtract_hb[0];

          /* Signum: '<S288>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S288>/Sign1' */

          /* Switch: '<S288>/Switch2' incorporates:
           *  Constant: '<S288>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S288>/Switch2' */

          /* DotProduct: '<S288>/Dot Product' */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_c14[0] +
            rtb_Subtract_hb[1] * rtb_Divide_c14[1];

          /* Trigonometry: '<S288>/Acos' incorporates:
           *  DotProduct: '<S288>/Dot Product'
           */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < -1.0F) {
              rtb_Saturation_o4 = -1.0F;
            }
          }

          /* Product: '<S288>/Multiply' incorporates:
           *  Trigonometry: '<S288>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation_o4);

          /* Saturate: '<S287>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S287>/Saturation' */

          /* Delay: '<S278>/Delay' incorporates:
           *  Gain: '<S280>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S273>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S273>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S273>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S273>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S287>/Divide' incorporates:
           *  Constant: '<S279>/L1'
           *  Gain: '<S287>/Gain'
           *  Math: '<S287>/Square'
           *  Product: '<S287>/Multiply1'
           *  Trigonometry: '<S287>/Sin'
           */
          rtb_u_b = 2.0F * (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2) *
            arm_sin_f32(rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S279>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S273>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S273>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S273>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S279>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S278>/Gain2' incorporates:
           *  Delay: '<S278>/Delay'
           *  Gain: '<S280>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S278>/Sum'
           */
          rtb_u_b = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S278>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S273>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S273>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S273>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S278>/Saturation1' */

          /* Update for Delay: '<S283>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S278>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S128>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S128>/Unknown' incorporates:
           *  ActionPort: '<S277>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S128>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
         *  ActionPort: '<S126>/Action Port'
         */
        /* SwitchCase: '<S126>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S126>/Offboard' incorporates:
           *  ActionPort: '<S240>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S240>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S240>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S240>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S126>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_hd != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S126>/Mission' incorporates:
             *  ActionPort: '<S239>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S126>/Switch Case' incorporates:
             *  UnitDelay: '<S242>/Delay Input1'
             *
             * Block description for '<S242>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S126>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S126>/Mission' incorporates:
             *  ActionPort: '<S239>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S239>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S126>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S250>/Integrator'
             *  DiscreteIntegrator: '<S250>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;
            FMS_DW.Integrator_DSTATE_fk = 0.0F;

            /* End of SystemReset for SubSystem: '<S239>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S126>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
           *  ActionPort: '<S239>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S242>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S242>/Delay Input1'
           *
           * Block description for '<S242>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S239>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S243>/Reset'
           */
          if (rtb_Compare_o3 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k !=
                                 POS_ZCSIG)) {
            /* InitializeConditions for DiscreteIntegrator: '<S250>/Integrator1' */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;

            /* InitializeConditions for DiscreteIntegrator: '<S250>/Integrator' */
            FMS_DW.Integrator_DSTATE_fk = 0.0F;
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = rtb_Compare_o3;

          /* Math: '<S264>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Divide_lr_idx_3;

          /* Sum: '<S264>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

          /* Math: '<S264>/Math Function1' incorporates:
           *  Sum: '<S264>/Sum of Elements'
           *
           * About '<S264>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S264>/Math Function1' */

          /* Switch: '<S264>/Switch' incorporates:
           *  Constant: '<S264>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S264>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_ga > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S264>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S254>/NearbyRefWP' incorporates:
           *  Constant: '<S252>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S254>/SearchL1RefWP' incorporates:
           *  Constant: '<S252>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_c14, &rtb_Saturation1_d);

          /* MATLAB Function: '<S254>/OutRegionRegWP' incorporates:
           *  Constant: '<S252>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S254>/Switch1' incorporates:
           *  Constant: '<S257>/Constant'
           *  RelationalOperator: '<S257>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_c14[0] = rtb_Subtract_hb[0];
            rtb_Divide_c14[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S256>/Compare' incorporates:
             *  Constant: '<S256>/Constant'
             */
            rtb_Compare_o3 = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S254>/Switch' */
            if (!rtb_Compare_o3) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S254>/Switch' */
          }

          /* End of Switch: '<S254>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S255>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S265>/Sum of Elements' incorporates:
           *  Math: '<S265>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S265>/Math Function1' incorporates:
           *  Sum: '<S265>/Sum of Elements'
           *
           * About '<S265>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S265>/Math Function1' */

          /* Switch: '<S265>/Switch' incorporates:
           *  Constant: '<S265>/Constant'
           *  Product: '<S265>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S265>/Switch' */

          /* Product: '<S264>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S267>/Sum of Elements' incorporates:
           *  Math: '<S267>/Math Function'
           *  SignalConversion: '<S267>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S267>/Math Function1' incorporates:
           *  Sum: '<S267>/Sum of Elements'
           *
           * About '<S267>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S267>/Math Function1' */

          /* Switch: '<S267>/Switch' incorporates:
           *  Constant: '<S267>/Constant'
           *  Product: '<S267>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S267>/Switch' */

          /* Product: '<S265>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S268>/Sum of Elements' incorporates:
           *  Math: '<S268>/Math Function'
           *  SignalConversion: '<S268>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S268>/Math Function1' incorporates:
           *  Sum: '<S268>/Sum of Elements'
           *
           * About '<S268>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S268>/Math Function1' */

          /* Switch: '<S268>/Switch' incorporates:
           *  Constant: '<S268>/Constant'
           *  Product: '<S268>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S268>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S247>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S268>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S267>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S247>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S268>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S267>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S247>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S247>/Divide' incorporates:
           *  Math: '<S248>/Square'
           *  Math: '<S249>/Square'
           *  Sqrt: '<S248>/Sqrt'
           *  Sqrt: '<S249>/Sqrt'
           *  Sum: '<S247>/Sum'
           *  Sum: '<S247>/Sum1'
           *  Sum: '<S248>/Sum of Elements'
           *  Sum: '<S249>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_bx * rtb_a_bx + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S247>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S247>/Saturation' */

          /* Sum: '<S266>/Subtract' incorporates:
           *  Product: '<S266>/Multiply'
           *  Product: '<S266>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S262>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S262>/Sign1' */

          /* Switch: '<S262>/Switch2' incorporates:
           *  Constant: '<S262>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S262>/Switch2' */

          /* DotProduct: '<S262>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S262>/Acos' incorporates:
           *  DotProduct: '<S262>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S262>/Multiply' incorporates:
           *  Trigonometry: '<S262>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S261>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S261>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S243>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S243>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S243>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Saturate: '<S245>/Saturation' */
          if (FMS_DW.Integrator1_DSTATE_li > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_li < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_li;
          }

          /* End of Saturate: '<S245>/Saturation' */

          /* Product: '<S261>/Divide' incorporates:
           *  Constant: '<S252>/L1'
           *  Gain: '<S261>/Gain'
           *  Math: '<S261>/Square'
           *  Product: '<S261>/Multiply1'
           *  Trigonometry: '<S261>/Sin'
           */
          rtb_u_b = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S252>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S252>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S244>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S247>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S244>/Sum2'
           *  Sum: '<S247>/Add'
           *  Sum: '<S247>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S244>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S243>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S244>/Saturation1' */

          /* Product: '<S251>/Multiply1' incorporates:
           *  Constant: '<S251>/const1'
           *  DiscreteIntegrator: '<S250>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_fk * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S245>/Switch' incorporates:
           *  Constant: '<S245>/Constant4'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            rtb_u_b = FMS_B.Cmd_In.set_speed;
          } else {
            rtb_u_b = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S245>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S251>/Add' incorporates:
           *  DiscreteIntegrator: '<S250>/Integrator1'
           *  Sum: '<S250>/Subtract'
           */
          rtb_Saturation_o4 = (FMS_DW.Integrator1_DSTATE_li - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S251>/Sign' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_Saturation_o4 > 0.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            rtb_Saturation1_d = rtb_Saturation_o4;
          }

          /* End of Signum: '<S251>/Sign' */

          /* Sum: '<S251>/Add2' incorporates:
           *  Abs: '<S251>/Abs'
           *  Gain: '<S251>/Gain'
           *  Gain: '<S251>/Gain1'
           *  Product: '<S251>/Multiply2'
           *  Product: '<S251>/Multiply3'
           *  Sqrt: '<S251>/Sqrt'
           *  Sum: '<S251>/Add1'
           *  Sum: '<S251>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation_o4) + FMS_ConstB.d_cy) *
                           FMS_ConstB.d_cy) - FMS_ConstB.d_cy) * 0.5F *
            rtb_Saturation1_d + rtb_Saturation_ga;

          /* Sum: '<S251>/Add4' */
          rtb_Saturation1_d = (rtb_Saturation_o4 - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S251>/Add3' */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_ConstB.d_cy;

          /* Sum: '<S251>/Subtract1' */
          rtb_Saturation_o4 -= FMS_ConstB.d_cy;

          /* Signum: '<S251>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S251>/Sign1' */

          /* Signum: '<S251>/Sign2' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S251>/Sign2' */

          /* Sum: '<S251>/Add5' incorporates:
           *  Gain: '<S251>/Gain2'
           *  Product: '<S251>/Multiply4'
           *  Sum: '<S251>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation_o4) * 0.5F *
            rtb_Saturation1_d;

          /* Update for DiscreteIntegrator: '<S250>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S250>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_li += 0.004F * FMS_DW.Integrator_DSTATE_fk;

          /* Sum: '<S251>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_cy;

          /* Sum: '<S251>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_cy;

          /* Signum: '<S251>/Sign5' incorporates:
           *  Signum: '<S251>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S251>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S251>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S251>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S251>/Sign5' */

          /* Signum: '<S251>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S251>/Sign3' */

          /* Signum: '<S251>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S251>/Sign4' */

          /* Update for DiscreteIntegrator: '<S250>/Integrator' incorporates:
           *  Constant: '<S251>/const'
           *  Gain: '<S251>/Gain3'
           *  Product: '<S251>/Divide'
           *  Product: '<S251>/Multiply5'
           *  Product: '<S251>/Multiply6'
           *  Sum: '<S251>/Subtract4'
           *  Sum: '<S251>/Subtract5'
           *  Sum: '<S251>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_fk += ((rtb_u_b / FMS_ConstB.d_cy -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ka * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 78.448F) * 0.004F;

          /* End of Outputs for SubSystem: '<S239>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S242>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S242>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S126>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S126>/Unknown' incorporates:
           *  ActionPort: '<S241>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S126>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
         *  ActionPort: '<S125>/Action Port'
         */
        /* SwitchCase: '<S125>/Switch Case' */
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
            /* Disable for SwitchCase: '<S138>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S178>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S163>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S125>/Stabilize' incorporates:
             *  ActionPort: '<S132>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S125>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S232>/Integrator'
             *  DiscreteIntegrator: '<S232>/Integrator1'
             *  DiscreteIntegrator: '<S233>/Integrator'
             *  DiscreteIntegrator: '<S233>/Integrator1'
             *  DiscreteIntegrator: '<S237>/Integrator'
             *  DiscreteIntegrator: '<S237>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_av = 0.0F;
            FMS_DW.Integrator1_DSTATE_oo = 0.0F;
            FMS_DW.Integrator1_DSTATE_jv = 0.0F;
            FMS_DW.Integrator_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Stabilize' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          /* Product: '<S234>/Multiply1' incorporates:
           *  Constant: '<S234>/const1'
           *  DiscreteIntegrator: '<S232>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S230>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S230>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S234>/Add' incorporates:
           *  DiscreteIntegrator: '<S232>/Integrator1'
           *  Gain: '<S227>/Gain'
           *  Gain: '<S230>/Gain'
           *  Sum: '<S232>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) + rtb_a_bx;

          /* Signum: '<S234>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S234>/Sign' */

          /* Sum: '<S234>/Add2' incorporates:
           *  Abs: '<S234>/Abs'
           *  Gain: '<S234>/Gain'
           *  Gain: '<S234>/Gain1'
           *  Product: '<S234>/Multiply2'
           *  Product: '<S234>/Multiply3'
           *  Sqrt: '<S234>/Sqrt'
           *  Sum: '<S234>/Add1'
           *  Sum: '<S234>/Subtract'
           */
          rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_ga + rtb_a_bx;

          /* Sum: '<S234>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Integrator1_bx) +
            rtb_a_bx;

          /* Sum: '<S234>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S234>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

          /* Signum: '<S234>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S234>/Sign1' */

          /* Signum: '<S234>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S234>/Sign2' */

          /* Sum: '<S234>/Add5' incorporates:
           *  Gain: '<S234>/Gain2'
           *  Product: '<S234>/Multiply4'
           *  Sum: '<S234>/Subtract2'
           */
          rtb_Integrator1_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S132>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S132>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S132>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S232>/Integrator1'
           *  DiscreteIntegrator: '<S233>/Integrator1'
           *  DiscreteIntegrator: '<S237>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_oo;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_jv;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S229>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_u_b = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S229>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S132>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S229>/Constant5'
           *  Gain: '<S229>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S229>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_u_b), 65536.0F) + 1000U);

          /* Product: '<S238>/Multiply1' incorporates:
           *  Constant: '<S238>/const1'
           *  DiscreteIntegrator: '<S237>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_j * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S236>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S236>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S238>/Add' incorporates:
           *  DiscreteIntegrator: '<S237>/Integrator1'
           *  Gain: '<S228>/Gain1'
           *  Gain: '<S236>/Gain'
           *  Sum: '<S237>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_jv - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_bx;

          /* Signum: '<S238>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S238>/Sign' */

          /* Sum: '<S238>/Add2' incorporates:
           *  Abs: '<S238>/Abs'
           *  Gain: '<S238>/Gain'
           *  Gain: '<S238>/Gain1'
           *  Product: '<S238>/Multiply2'
           *  Product: '<S238>/Multiply3'
           *  Sqrt: '<S238>/Sqrt'
           *  Sum: '<S238>/Add1'
           *  Sum: '<S238>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_mq)
            * FMS_ConstB.d_mq) - FMS_ConstB.d_mq) * 0.5F * rtb_Divide_lr_idx_3 +
            rtb_a_bx;

          /* Sum: '<S238>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Divide_lr_idx_2) + rtb_a_bx;

          /* Sum: '<S238>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_mq;

          /* Sum: '<S238>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_mq;

          /* Signum: '<S238>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S238>/Sign1' */

          /* Signum: '<S238>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S238>/Sign2' */

          /* Sum: '<S238>/Add5' incorporates:
           *  Gain: '<S238>/Gain2'
           *  Product: '<S238>/Multiply4'
           *  Sum: '<S238>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S238>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_2 + FMS_ConstB.d_mq;

          /* Sum: '<S238>/Subtract3' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 - FMS_ConstB.d_mq;

          /* Product: '<S238>/Divide' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 / FMS_ConstB.d_mq;

          /* Signum: '<S238>/Sign5' incorporates:
           *  Signum: '<S238>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_p2 = -1.0F;

            /* Signum: '<S238>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_p2 = 1.0F;

            /* Signum: '<S238>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_p2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S238>/Sign6' */
            rtb_Saturation_o4 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S238>/Sign5' */

          /* Product: '<S235>/Multiply1' incorporates:
           *  Constant: '<S235>/const1'
           *  DiscreteIntegrator: '<S233>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S231>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S231>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S235>/Add' incorporates:
           *  DiscreteIntegrator: '<S233>/Integrator1'
           *  Gain: '<S227>/Gain1'
           *  Gain: '<S231>/Gain'
           *  Sum: '<S233>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_oo - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S235>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S235>/Sign' */

          /* Sum: '<S235>/Add2' incorporates:
           *  Abs: '<S235>/Abs'
           *  Gain: '<S235>/Gain'
           *  Gain: '<S235>/Gain1'
           *  Product: '<S235>/Multiply2'
           *  Product: '<S235>/Multiply3'
           *  Sqrt: '<S235>/Sqrt'
           *  Sum: '<S235>/Add1'
           *  Sum: '<S235>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_my) *
                            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S235>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_a_bx) + rtb_Divide_lr_idx_2;

          /* Sum: '<S235>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_my;

          /* Sum: '<S235>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_my;

          /* Signum: '<S235>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S235>/Sign1' */

          /* Signum: '<S235>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S235>/Sign2' */

          /* Sum: '<S235>/Add5' incorporates:
           *  Gain: '<S235>/Gain2'
           *  Product: '<S235>/Multiply4'
           *  Sum: '<S235>/Subtract2'
           */
          rtb_a_bx += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Update for DiscreteIntegrator: '<S232>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S232>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S234>/Subtract3' */
          rtb_Divide_lr_idx_2 = rtb_Integrator1_bx - FMS_ConstB.d_ny;

          /* Sum: '<S234>/Add6' */
          d = rtb_Integrator1_bx + FMS_ConstB.d_ny;

          /* Signum: '<S234>/Sign5' incorporates:
           *  Signum: '<S234>/Sign6'
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;

            /* Signum: '<S234>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (rtb_Integrator1_bx > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;

            /* Signum: '<S234>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Integrator1_bx;

            /* Signum: '<S234>/Sign6' */
            rtb_u_b = rtb_Integrator1_bx;
          }

          /* End of Signum: '<S234>/Sign5' */

          /* Signum: '<S234>/Sign3' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S234>/Sign3' */

          /* Signum: '<S234>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S234>/Sign4' */

          /* Update for DiscreteIntegrator: '<S232>/Integrator' incorporates:
           *  Constant: '<S234>/const'
           *  Gain: '<S234>/Gain3'
           *  Product: '<S234>/Divide'
           *  Product: '<S234>/Multiply5'
           *  Product: '<S234>/Multiply6'
           *  Sum: '<S234>/Subtract4'
           *  Sum: '<S234>/Subtract5'
           *  Sum: '<S234>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((rtb_Integrator1_bx / FMS_ConstB.d_ny
            - rtb_Divide_lr_idx_3) * FMS_ConstB.Gain4_ko * ((d -
            rtb_Divide_lr_idx_2) * 0.5F) - rtb_u_b * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S233>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S233>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_oo += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S237>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S237>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jv += 0.004F * FMS_DW.Integrator_DSTATE_j;

          /* Signum: '<S238>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S238>/Sign3' */

          /* Signum: '<S238>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S238>/Sign4' */

          /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
           *  Constant: '<S238>/const'
           *  Gain: '<S238>/Gain3'
           *  Product: '<S238>/Multiply5'
           *  Product: '<S238>/Multiply6'
           *  Sum: '<S238>/Subtract4'
           *  Sum: '<S238>/Subtract5'
           *  Sum: '<S238>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_j += ((rtb_P_f_idx_0 - rtb_Sign5_p2) *
            FMS_ConstB.Gain4_b * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 15.707963F) * 0.004F;

          /* Sum: '<S235>/Subtract3' */
          rtb_Saturation_ga = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S235>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S235>/Sign5' incorporates:
           *  Signum: '<S235>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S235>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S235>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_a_bx;

            /* Signum: '<S235>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_a_bx;
          }

          /* End of Signum: '<S235>/Sign5' */

          /* Signum: '<S235>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S235>/Sign3' */

          /* Signum: '<S235>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S235>/Sign4' */

          /* Update for DiscreteIntegrator: '<S233>/Integrator' incorporates:
           *  Constant: '<S235>/const'
           *  Gain: '<S235>/Gain3'
           *  Product: '<S235>/Divide'
           *  Product: '<S235>/Multiply5'
           *  Product: '<S235>/Multiply6'
           *  Sum: '<S235>/Subtract4'
           *  Sum: '<S235>/Subtract5'
           *  Sum: '<S235>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_bx / FMS_ConstB.d_my -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_k2 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S125>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S125>/Altitude' incorporates:
             *  ActionPort: '<S130>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S125>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S142>/Integrator'
             *  DiscreteIntegrator: '<S142>/Integrator1'
             *  DiscreteIntegrator: '<S151>/Integrator'
             *  DiscreteIntegrator: '<S151>/Integrator1'
             *  DiscreteIntegrator: '<S154>/Integrator'
             *  DiscreteIntegrator: '<S154>/Integrator1'
             *  DiscreteIntegrator: '<S157>/Integrator'
             *  DiscreteIntegrator: '<S157>/Integrator1'
             */
            FMS_DW.Integrator_DSTATE_hd = 0.0F;
            FMS_DW.Integrator1_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_jl = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator_DSTATE_n = 0.0F;
            FMS_DW.Integrator_DSTATE_er = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S125>/Altitude' incorporates:
             *  ActionPort: '<S130>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S125>/Switch Case' incorporates:
             *  Chart: '<S139>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S125>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Altitude' incorporates:
           *  ActionPort: '<S130>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S139>/Motion Status' incorporates:
           *  Abs: '<S139>/Abs'
           *  Abs: '<S139>/Abs1'
           *  Constant: '<S148>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S148>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S138>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ah;
          FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
          switch (rtb_state_ej) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_ah = 0;
            break;

           case MotionState_Brake:
           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_ah = 1;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_ah) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ah != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S138>/Hold Control' incorporates:
               *  ActionPort: '<S140>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S138>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S138>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S138>/Hold Control' incorporates:
             *  ActionPort: '<S140>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_lj,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S138>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ah != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S138>/Move Control' incorporates:
               *  ActionPort: '<S141>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S138>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S138>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S138>/Move Control' incorporates:
             *  ActionPort: '<S141>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_lj,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S138>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S138>/Switch Case' */

          /* DiscreteIntegrator: '<S142>/Integrator' */
          rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_hd;

          /* Product: '<S147>/Multiply1' incorporates:
           *  Constant: '<S147>/const1'
           *  DiscreteIntegrator: '<S142>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hd * 0.05F;

          /* Saturate: '<S138>/Saturation1' */
          if (FMS_B.Merge_lj > FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_lj < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_u_b = FMS_B.Merge_lj;
          }

          /* End of Saturate: '<S138>/Saturation1' */

          /* Sum: '<S147>/Add' incorporates:
           *  DiscreteIntegrator: '<S142>/Integrator1'
           *  Sum: '<S142>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_a - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S147>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S147>/Sign' */

          /* Sum: '<S147>/Add2' incorporates:
           *  Abs: '<S147>/Abs'
           *  Gain: '<S147>/Gain'
           *  Gain: '<S147>/Gain1'
           *  Product: '<S147>/Multiply2'
           *  Product: '<S147>/Multiply3'
           *  Sqrt: '<S147>/Sqrt'
           *  Sum: '<S147>/Add1'
           *  Sum: '<S147>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_ar) *
                            FMS_ConstB.d_ar) - FMS_ConstB.d_ar) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S147>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_a_bx) + rtb_Saturation_ga;

          /* Sum: '<S147>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ar;

          /* Sum: '<S147>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ar;

          /* Signum: '<S147>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S147>/Sign1' */

          /* Signum: '<S147>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S147>/Sign2' */

          /* Sum: '<S147>/Add5' incorporates:
           *  Gain: '<S147>/Gain2'
           *  Product: '<S147>/Multiply4'
           *  Sum: '<S147>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S130>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S130>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S130>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  DiscreteIntegrator: '<S154>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_jl;

          /* Saturate: '<S137>/Saturation1' */
          if (FMS_DW.Integrator1_DSTATE_o > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_o < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_o;
          }

          /* End of Saturate: '<S137>/Saturation1' */

          /* BusAssignment: '<S130>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S142>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S137>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < -1.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            rtb_Saturation_ga = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S137>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S158>/Multiply1' incorporates:
           *  Constant: '<S158>/const1'
           *  DiscreteIntegrator: '<S157>/Integrator'
           */
          rtb_Sign5_p2 = FMS_DW.Integrator_DSTATE_n * 0.05F;

          /* Switch: '<S156>/Switch' incorporates:
           *  Constant: '<S156>/Constant'
           *  Constant: '<S156>/Constant1'
           *  Constant: '<S156>/Constant2'
           *  Product: '<S156>/Multiply'
           *  Product: '<S156>/Multiply1'
           *  Sum: '<S156>/Subtract'
           *  Sum: '<S156>/Subtract1'
           *  Sum: '<S156>/Sum'
           *  Sum: '<S156>/Sum1'
           */
          if (rtb_Saturation_ga >= 0.0F) {
            rtb_Saturation_ga = (FMS_PARAM.FW_SPEED_MAX -
                                 FMS_PARAM.FW_CRUISE_SPEED) * rtb_Saturation_ga
              + FMS_PARAM.FW_CRUISE_SPEED;
          } else {
            rtb_Saturation_ga = (FMS_PARAM.FW_CRUISE_SPEED -
                                 FMS_PARAM.FW_SPEED_MIN) * rtb_Saturation_ga +
              FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S156>/Switch' */

          /* Sum: '<S158>/Add' incorporates:
           *  DiscreteIntegrator: '<S157>/Integrator1'
           *  Sum: '<S157>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_o - rtb_Saturation_ga) +
            rtb_Sign5_p2;

          /* Signum: '<S158>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
          }

          /* End of Signum: '<S158>/Sign' */

          /* Sum: '<S158>/Add2' incorporates:
           *  Abs: '<S158>/Abs'
           *  Gain: '<S158>/Gain'
           *  Gain: '<S158>/Gain1'
           *  Product: '<S158>/Multiply2'
           *  Product: '<S158>/Multiply3'
           *  Sqrt: '<S158>/Sqrt'
           *  Sum: '<S158>/Add1'
           *  Sum: '<S158>/Subtract'
           */
          rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_e) *
            FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F * rtb_Add4_pb +
            rtb_Sign5_p2;

          /* Sum: '<S158>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_P_f_idx_0) + rtb_Sign5_p2;

          /* Sum: '<S158>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_e;

          /* Sum: '<S158>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_e;

          /* Signum: '<S158>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S158>/Sign1' */

          /* Signum: '<S158>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S158>/Sign2' */

          /* Sum: '<S158>/Add5' incorporates:
           *  Gain: '<S158>/Gain2'
           *  Product: '<S158>/Multiply4'
           *  Sum: '<S158>/Subtract2'
           */
          rtb_P_f_idx_0 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S158>/Add6' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_e;

          /* Sum: '<S158>/Subtract3' */
          rtb_Saturation1_d = rtb_P_f_idx_0 - FMS_ConstB.d_e;

          /* Product: '<S158>/Divide' */
          rtb_Divide_hw = rtb_P_f_idx_0 / FMS_ConstB.d_e;

          /* Signum: '<S158>/Sign5' incorporates:
           *  Signum: '<S158>/Sign6'
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Sign5_i = -1.0F;

            /* Signum: '<S158>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Sign5_i = 1.0F;

            /* Signum: '<S158>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_i = rtb_P_f_idx_0;

            /* Signum: '<S158>/Sign6' */
            rtb_Saturation_o4 = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S158>/Sign5' */

          /* Product: '<S155>/Multiply1' incorporates:
           *  Constant: '<S155>/const1'
           *  DiscreteIntegrator: '<S154>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_er * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S153>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S153>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S155>/Add' incorporates:
           *  DiscreteIntegrator: '<S154>/Integrator1'
           *  Gain: '<S136>/Gain1'
           *  Gain: '<S153>/Gain'
           *  Sum: '<S154>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_jl - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_P_f_idx_0;

          /* Signum: '<S155>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
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
          rtb_Sign5_p2 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_cb) *
                                FMS_ConstB.d_cb) - FMS_ConstB.d_cb) * 0.5F *
            rtb_Add4_pb + rtb_P_f_idx_0;

          /* Sum: '<S155>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_Sign5_p2) + rtb_P_f_idx_0;

          /* Sum: '<S155>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_cb;

          /* Sum: '<S155>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_cb;

          /* Signum: '<S155>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S155>/Sign1' */

          /* Signum: '<S155>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S155>/Sign2' */

          /* Sum: '<S155>/Add5' incorporates:
           *  Gain: '<S155>/Gain2'
           *  Product: '<S155>/Multiply4'
           *  Sum: '<S155>/Subtract2'
           */
          rtb_Sign5_p2 += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S155>/Add6' */
          rtb_Divide_lr_idx_2 = rtb_Sign5_p2 + FMS_ConstB.d_cb;

          /* Sum: '<S155>/Subtract3' */
          d = rtb_Sign5_p2 - FMS_ConstB.d_cb;

          /* Product: '<S155>/Divide' */
          rtb_Divide_pq = rtb_Sign5_p2 / FMS_ConstB.d_cb;

          /* Signum: '<S155>/Sign5' incorporates:
           *  Signum: '<S155>/Sign6'
           */
          if (rtb_Sign5_p2 < 0.0F) {
            rtb_Sign5_kq = -1.0F;

            /* Signum: '<S155>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Sign5_p2 > 0.0F) {
            rtb_Sign5_kq = 1.0F;

            /* Signum: '<S155>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Sign5_kq = rtb_Sign5_p2;

            /* Signum: '<S155>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_Sign5_p2;
          }

          /* End of Signum: '<S155>/Sign5' */

          /* Product: '<S152>/Multiply1' incorporates:
           *  Constant: '<S152>/const1'
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S150>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S150>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S152>/Add' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  Gain: '<S135>/Gain'
           *  Gain: '<S150>/Gain'
           *  Sum: '<S151>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) +
            rtb_P_f_idx_0;

          /* Signum: '<S152>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
          }

          /* End of Signum: '<S152>/Sign' */

          /* Sum: '<S152>/Add2' incorporates:
           *  Abs: '<S152>/Abs'
           *  Gain: '<S152>/Gain'
           *  Gain: '<S152>/Gain1'
           *  Product: '<S152>/Multiply2'
           *  Product: '<S152>/Multiply3'
           *  Sqrt: '<S152>/Sqrt'
           *  Sum: '<S152>/Add1'
           *  Sum: '<S152>/Subtract'
           */
          rtb_Sign5_p2 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_bi) *
                                FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Add4_pb + rtb_P_f_idx_0;

          /* Sum: '<S152>/Add4' */
          rtb_Add4_pb = (rtb_u_b - rtb_Sign5_p2) + rtb_P_f_idx_0;

          /* Sum: '<S152>/Add3' */
          rtb_P_f_idx_0 = rtb_u_b + FMS_ConstB.d_bi;

          /* Sum: '<S152>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_bi;

          /* Signum: '<S152>/Sign1' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign1' */

          /* Signum: '<S152>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign2' */

          /* Sum: '<S152>/Add5' incorporates:
           *  Gain: '<S152>/Gain2'
           *  Product: '<S152>/Multiply4'
           *  Sum: '<S152>/Subtract2'
           */
          rtb_Sign5_p2 += (rtb_P_f_idx_0 - rtb_u_b) * 0.5F * rtb_Add4_pb;

          /* Sum: '<S147>/Subtract3' */
          rtb_P_f_idx_0 = rtb_a_bx - FMS_ConstB.d_ar;

          /* Sum: '<S147>/Add6' */
          rtb_Add4_pb = rtb_a_bx + FMS_ConstB.d_ar;

          /* Signum: '<S147>/Sign5' incorporates:
           *  Signum: '<S147>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_u_b = -1.0F;

            /* Signum: '<S147>/Sign6' */
            y = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_u_b = 1.0F;

            /* Signum: '<S147>/Sign6' */
            y = 1.0F;
          } else {
            rtb_u_b = rtb_a_bx;

            /* Signum: '<S147>/Sign6' */
            y = rtb_a_bx;
          }

          /* End of Signum: '<S147>/Sign5' */

          /* Signum: '<S147>/Sign3' */
          if (rtb_Add4_pb < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else {
            if (rtb_Add4_pb > 0.0F) {
              rtb_Add4_pb = 1.0F;
            }
          }

          /* End of Signum: '<S147>/Sign3' */

          /* Signum: '<S147>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S147>/Sign4' */

          /* Update for DiscreteIntegrator: '<S142>/Integrator' incorporates:
           *  Constant: '<S147>/const'
           *  Gain: '<S147>/Gain3'
           *  Product: '<S147>/Divide'
           *  Product: '<S147>/Multiply5'
           *  Product: '<S147>/Multiply6'
           *  Sum: '<S147>/Subtract4'
           *  Sum: '<S147>/Subtract5'
           *  Sum: '<S147>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hd += ((rtb_a_bx / FMS_ConstB.d_ar - rtb_u_b)
            * FMS_ConstB.Gain4_am * ((rtb_Add4_pb - rtb_P_f_idx_0) * 0.5F) - y *
            78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S142>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_a += 0.004F * rtb_Integrator1_bx;

          /* Update for DiscreteIntegrator: '<S151>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S154>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S154>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jl += 0.004F * FMS_DW.Integrator_DSTATE_er;

          /* Update for DiscreteIntegrator: '<S157>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S157>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_n;

          /* Signum: '<S158>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S158>/Sign3' */

          /* Signum: '<S158>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S158>/Sign4' */

          /* Update for DiscreteIntegrator: '<S157>/Integrator' incorporates:
           *  Constant: '<S158>/const'
           *  Gain: '<S158>/Gain3'
           *  Product: '<S158>/Multiply5'
           *  Product: '<S158>/Multiply6'
           *  Sum: '<S158>/Subtract4'
           *  Sum: '<S158>/Subtract5'
           *  Sum: '<S158>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_n += ((rtb_Divide_hw - rtb_Sign5_i) *
            FMS_ConstB.Gain4_l * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 78.448F) * 0.004F;

          /* Signum: '<S155>/Sign3' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S155>/Sign3' */

          /* Signum: '<S155>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S155>/Sign4' */

          /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
           *  Constant: '<S155>/const'
           *  Gain: '<S155>/Gain3'
           *  Product: '<S155>/Multiply5'
           *  Product: '<S155>/Multiply6'
           *  Sum: '<S155>/Subtract4'
           *  Sum: '<S155>/Subtract5'
           *  Sum: '<S155>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_er += ((rtb_Divide_pq - rtb_Sign5_kq) *
            FMS_ConstB.Gain4_ci * ((rtb_Divide_lr_idx_2 - d) * 0.5F) -
            rtb_Divide_lr_idx_3 * 15.707963F) * 0.004F;

          /* Sum: '<S152>/Subtract3' */
          rtb_Saturation_ga = rtb_Sign5_p2 - FMS_ConstB.d_bi;

          /* Sum: '<S152>/Add6' */
          rtb_Saturation1_d = rtb_Sign5_p2 + FMS_ConstB.d_bi;

          /* Signum: '<S152>/Sign5' incorporates:
           *  Signum: '<S152>/Sign6'
           */
          if (rtb_Sign5_p2 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S152>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Sign5_p2 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S152>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Sign5_p2;

            /* Signum: '<S152>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_Sign5_p2;
          }

          /* End of Signum: '<S152>/Sign5' */

          /* Signum: '<S152>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign3' */

          /* Signum: '<S152>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign4' */

          /* Update for DiscreteIntegrator: '<S151>/Integrator' incorporates:
           *  Constant: '<S152>/const'
           *  Gain: '<S152>/Gain3'
           *  Product: '<S152>/Divide'
           *  Product: '<S152>/Multiply5'
           *  Product: '<S152>/Multiply6'
           *  Sum: '<S152>/Subtract4'
           *  Sum: '<S152>/Subtract5'
           *  Sum: '<S152>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_Sign5_p2 / FMS_ConstB.d_bi -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_d1 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S125>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S125>/Position' incorporates:
             *  ActionPort: '<S131>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S125>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S167>/Integrator'
             *  DiscreteIntegrator: '<S167>/Integrator1'
             *  DiscreteIntegrator: '<S176>/Integrator'
             *  DiscreteIntegrator: '<S176>/Integrator1'
             *  DiscreteIntegrator: '<S225>/Integrator'
             *  DiscreteIntegrator: '<S225>/Integrator1'
             */
            FMS_DW.Integrator_DSTATE_c5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_i = 0.0F;
            FMS_DW.Integrator1_DSTATE_l5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_nd = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Position' */

            /* SystemReset for IfAction SubSystem: '<S125>/Position' incorporates:
             *  ActionPort: '<S131>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S125>/Switch Case' incorporates:
             *  Chart: '<S164>/Motion Status'
             *  Chart: '<S179>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState);

            /* End of SystemReset for SubSystem: '<S125>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Position' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          /* Trigonometry: '<S223>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S223>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S223>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S223>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S223>/Gain' incorporates:
           *  Gain: '<S222>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S223>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S223>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S223>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S223>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S223>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S164>/Motion Status' incorporates:
           *  Abs: '<S164>/Abs'
           *  Abs: '<S164>/Abs1'
           *  Constant: '<S173>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S173>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S179>/Multiply' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
              * FMS_U.INS_Out.vd + (rtb_VectorConcatenate_or[rtb_n + 3] *
              FMS_U.INS_Out.ve + rtb_VectorConcatenate_or[rtb_n] *
              FMS_U.INS_Out.vn);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of Product: '<S179>/Multiply' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S179>/Motion State' incorporates:
           *  Abs: '<S179>/Abs'
           *  Abs: '<S179>/Abs1'
           *  Abs: '<S179>/Abs2'
           *  Constant: '<S219>/Constant'
           *  Constant: '<S220>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Logic: '<S179>/Logical Operator'
           *  RelationalOperator: '<S219>/Compare'
           *  RelationalOperator: '<S220>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ)
                          || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
                              FMS_PARAM.YAW_DZ), fabsf(rtb_MatrixConcatenate1_0
            [0]), &rtb_state_fg, &FMS_DW.sf_MotionState);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S178>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_d;
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
          switch (rtb_state_fg) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_d = 0;
            break;

           case MotionState_Brake:
           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_d = 1;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_d) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S178>/Hold Control' incorporates:
               *  ActionPort: '<S180>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S178>/Switch Case' */
              FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_b,
                &FMS_DW.HoldControl_b);

              /* End of SystemReset for SubSystem: '<S178>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S178>/Hold Control' incorporates:
             *  ActionPort: '<S180>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_b(rtb_Divide_p3p, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                              FMS_U.INS_Out.vd, FMS_U.INS_Out.psi,
                              FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              &FMS_B.Merge_be, &FMS_ConstB.HoldControl_b,
                              &FMS_DW.HoldControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S178>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S178>/Move Control' incorporates:
             *  ActionPort: '<S181>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S216>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S216>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S181>/Gain6' incorporates:
             *  Gain: '<S216>/Gain'
             */
            FMS_B.Merge_be = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
              FMS_PARAM.FW_ACC_Y_LIM;

            /* End of Outputs for SubSystem: '<S178>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S178>/Switch Case' */

          /* SwitchCase: '<S163>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ad;
          FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
          switch (rtb_state_ej) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_ad = 0;
            break;

           case MotionState_Brake:
           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_ad = 1;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_ad) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S163>/Hold Control' incorporates:
               *  ActionPort: '<S165>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S163>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S163>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S163>/Hold Control' incorporates:
             *  ActionPort: '<S165>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S163>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S163>/Move Control' incorporates:
               *  ActionPort: '<S166>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S163>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S163>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S163>/Move Control' incorporates:
             *  ActionPort: '<S166>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S163>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S163>/Switch Case' */

          /* DiscreteIntegrator: '<S167>/Integrator' */
          rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_c5;

          /* Product: '<S172>/Multiply1' incorporates:
           *  Constant: '<S172>/const1'
           *  DiscreteIntegrator: '<S167>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_c5 * 0.05F;

          /* Saturate: '<S163>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_u_b = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S163>/Saturation1' */

          /* Sum: '<S172>/Add' incorporates:
           *  DiscreteIntegrator: '<S167>/Integrator1'
           *  Sum: '<S167>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_i - rtb_u_b) +
            rtb_P_f_idx_0;

          /* Signum: '<S172>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S172>/Sign' */

          /* Sum: '<S172>/Add2' incorporates:
           *  Abs: '<S172>/Abs'
           *  Gain: '<S172>/Gain'
           *  Gain: '<S172>/Gain1'
           *  Product: '<S172>/Multiply2'
           *  Product: '<S172>/Multiply3'
           *  Sqrt: '<S172>/Sqrt'
           *  Sum: '<S172>/Add1'
           *  Sum: '<S172>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_av) *
                            FMS_ConstB.d_av) - FMS_ConstB.d_av) * 0.5F *
            rtb_Saturation_ga + rtb_P_f_idx_0;

          /* Sum: '<S172>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_a_bx) + rtb_P_f_idx_0;

          /* Sum: '<S172>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_av;

          /* Sum: '<S172>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_av;

          /* Signum: '<S172>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S172>/Sign1' */

          /* Signum: '<S172>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S172>/Sign2' */

          /* Sum: '<S172>/Add5' incorporates:
           *  Gain: '<S172>/Gain2'
           *  Product: '<S172>/Multiply4'
           *  Sum: '<S172>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S131>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S131>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S176>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l5;

          /* Saturate: '<S162>/Saturation1' */
          if (FMS_DW.Integrator1_DSTATE_nd > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_nd < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_nd;
          }

          /* End of Saturate: '<S162>/Saturation1' */

          /* Saturate: '<S178>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S178>/Saturation1' */

          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S167>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_i;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S162>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < -1.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            rtb_Saturation_ga = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S162>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S226>/Multiply1' incorporates:
           *  Constant: '<S226>/const1'
           *  DiscreteIntegrator: '<S225>/Integrator'
           */
          rtb_u_b = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Switch: '<S224>/Switch' incorporates:
           *  Constant: '<S224>/Constant'
           *  Constant: '<S224>/Constant1'
           *  Constant: '<S224>/Constant2'
           *  Product: '<S224>/Multiply'
           *  Product: '<S224>/Multiply1'
           *  Sum: '<S224>/Subtract'
           *  Sum: '<S224>/Subtract1'
           *  Sum: '<S224>/Sum'
           *  Sum: '<S224>/Sum1'
           */
          if (rtb_Saturation_ga >= 0.0F) {
            rtb_Saturation_ga = (FMS_PARAM.FW_SPEED_MAX -
                                 FMS_PARAM.FW_CRUISE_SPEED) * rtb_Saturation_ga
              + FMS_PARAM.FW_CRUISE_SPEED;
          } else {
            rtb_Saturation_ga = (FMS_PARAM.FW_CRUISE_SPEED -
                                 FMS_PARAM.FW_SPEED_MIN) * rtb_Saturation_ga +
              FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S224>/Switch' */

          /* Sum: '<S226>/Add' incorporates:
           *  DiscreteIntegrator: '<S225>/Integrator1'
           *  Sum: '<S225>/Subtract'
           */
          rtb_P_f_idx_0 = (FMS_DW.Integrator1_DSTATE_nd - rtb_Saturation_ga) +
            rtb_u_b;

          /* Signum: '<S226>/Sign' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S226>/Sign' */

          /* Sum: '<S226>/Add2' incorporates:
           *  Abs: '<S226>/Abs'
           *  Gain: '<S226>/Gain'
           *  Gain: '<S226>/Gain1'
           *  Product: '<S226>/Multiply2'
           *  Product: '<S226>/Multiply3'
           *  Sqrt: '<S226>/Sqrt'
           *  Sum: '<S226>/Add1'
           *  Sum: '<S226>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_P_f_idx_0) +
            FMS_ConstB.d_ad) * FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F *
            rtb_Saturation_ga + rtb_u_b;

          /* Sum: '<S226>/Add4' */
          rtb_Saturation1_d = (rtb_P_f_idx_0 - rtb_Divide_lr_idx_2) + rtb_u_b;

          /* Sum: '<S226>/Add3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_ad;

          /* Sum: '<S226>/Subtract1' */
          rtb_P_f_idx_0 -= FMS_ConstB.d_ad;

          /* Signum: '<S226>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign1' */

          /* Signum: '<S226>/Sign2' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign2' */

          /* Sum: '<S226>/Add5' incorporates:
           *  Gain: '<S226>/Gain2'
           *  Product: '<S226>/Multiply4'
           *  Sum: '<S226>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S226>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ad;

          /* Sum: '<S226>/Subtract3' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 - FMS_ConstB.d_ad;

          /* Product: '<S226>/Divide' */
          rtb_Sign5_p2 = rtb_Divide_lr_idx_2 / FMS_ConstB.d_ad;

          /* Signum: '<S226>/Sign5' incorporates:
           *  Signum: '<S226>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_hw = -1.0F;

            /* Signum: '<S226>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_hw = 1.0F;

            /* Signum: '<S226>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Divide_hw = rtb_Divide_lr_idx_2;

            /* Signum: '<S226>/Sign6' */
            rtb_Saturation_o4 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S226>/Sign5' */

          /* Product: '<S177>/Multiply1' incorporates:
           *  Constant: '<S177>/const1'
           *  DiscreteIntegrator: '<S176>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S175>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S175>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S177>/Add' incorporates:
           *  DiscreteIntegrator: '<S176>/Integrator1'
           *  Gain: '<S160>/Gain1'
           *  Gain: '<S175>/Gain'
           *  Sum: '<S176>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_l5 - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S177>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S177>/Sign' */

          /* Sum: '<S177>/Add2' incorporates:
           *  Abs: '<S177>/Abs'
           *  Gain: '<S177>/Gain'
           *  Gain: '<S177>/Gain1'
           *  Product: '<S177>/Multiply2'
           *  Product: '<S177>/Multiply3'
           *  Sqrt: '<S177>/Sqrt'
           *  Sum: '<S177>/Add1'
           *  Sum: '<S177>/Subtract'
           */
          rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_l) *
            FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Divide_lr_idx_3 +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S177>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_P_f_idx_0) + rtb_Divide_lr_idx_2;

          /* Sum: '<S177>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_l;

          /* Sum: '<S177>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_l;

          /* Signum: '<S177>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S177>/Sign1' */

          /* Signum: '<S177>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S177>/Sign2' */

          /* Sum: '<S177>/Add5' incorporates:
           *  Gain: '<S177>/Gain2'
           *  Product: '<S177>/Multiply4'
           *  Sum: '<S177>/Subtract2'
           */
          rtb_P_f_idx_0 += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S172>/Subtract3' */
          rtb_Divide_lr_idx_2 = rtb_a_bx - FMS_ConstB.d_av;

          /* Sum: '<S172>/Add6' */
          d = rtb_a_bx + FMS_ConstB.d_av;

          /* Signum: '<S172>/Sign5' incorporates:
           *  Signum: '<S172>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;

            /* Signum: '<S172>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;

            /* Signum: '<S172>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_a_bx;

            /* Signum: '<S172>/Sign6' */
            rtb_u_b = rtb_a_bx;
          }

          /* End of Signum: '<S172>/Sign5' */

          /* Signum: '<S172>/Sign3' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S172>/Sign3' */

          /* Signum: '<S172>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S172>/Sign4' */

          /* Update for DiscreteIntegrator: '<S167>/Integrator' incorporates:
           *  Constant: '<S172>/const'
           *  Gain: '<S172>/Gain3'
           *  Product: '<S172>/Divide'
           *  Product: '<S172>/Multiply5'
           *  Product: '<S172>/Multiply6'
           *  Sum: '<S172>/Subtract4'
           *  Sum: '<S172>/Subtract5'
           *  Sum: '<S172>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c5 += ((rtb_a_bx / FMS_ConstB.d_av -
            rtb_Divide_lr_idx_3) * FMS_ConstB.Gain4_p5 * ((d -
            rtb_Divide_lr_idx_2) * 0.5F) - rtb_u_b * 78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S167>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_i += 0.004F * rtb_Integrator1_bx;

          /* Update for DiscreteIntegrator: '<S176>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S176>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l5 += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S225>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S225>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S226>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign3' */

          /* Signum: '<S226>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign4' */

          /* Update for DiscreteIntegrator: '<S225>/Integrator' incorporates:
           *  Constant: '<S226>/const'
           *  Gain: '<S226>/Gain3'
           *  Product: '<S226>/Multiply5'
           *  Product: '<S226>/Multiply6'
           *  Sum: '<S226>/Subtract4'
           *  Sum: '<S226>/Subtract5'
           *  Sum: '<S226>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Sign5_p2 - rtb_Divide_hw) *
            FMS_ConstB.Gain4_f * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 78.448F) * 0.004F;

          /* Sum: '<S177>/Subtract3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 - FMS_ConstB.d_l;

          /* Sum: '<S177>/Add6' */
          rtb_Saturation1_d = rtb_P_f_idx_0 + FMS_ConstB.d_l;

          /* Signum: '<S177>/Sign5' incorporates:
           *  Signum: '<S177>/Sign6'
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S177>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S177>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_P_f_idx_0;

            /* Signum: '<S177>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S177>/Sign5' */

          /* Signum: '<S177>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S177>/Sign3' */

          /* Signum: '<S177>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S177>/Sign4' */

          /* Update for DiscreteIntegrator: '<S176>/Integrator' incorporates:
           *  Constant: '<S177>/const'
           *  Gain: '<S177>/Gain3'
           *  Product: '<S177>/Divide'
           *  Product: '<S177>/Multiply5'
           *  Product: '<S177>/Multiply6'
           *  Sum: '<S177>/Subtract4'
           *  Sum: '<S177>/Subtract5'
           *  Sum: '<S177>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_P_f_idx_0 / FMS_ConstB.d_l -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ak * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 15.707963F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S125>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S125>/Unknown' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S125>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S49>/Manual' incorporates:
         *  ActionPort: '<S127>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S127>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S127>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S127>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S269>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u_b = 0.0F;
        } else {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S269>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S269>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S270>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_u_b = 0.0F;
        } else {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S270>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S127>/Gain'
         *  Gain: '<S270>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S271>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_u_b = 0.0F;
        } else {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S271>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S271>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S272>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_u_b = 0.0F;
        } else {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle - (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S272>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S272>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_u_b;

        /* End of Outputs for SubSystem: '<S49>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S49>/Unknown' incorporates:
         *  ActionPort: '<S129>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

        /* End of Outputs for SubSystem: '<S49>/Unknown' */
        break;
      }

      /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
      break;

     case 1:
      if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
         *  ActionPort: '<S48>/Action Port'
         */
        /* InitializeConditions for SwitchCase: '<S44>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S119>/Integrator'
         *  DiscreteIntegrator: '<S119>/Integrator1'
         *  DiscreteIntegrator: '<S120>/Integrator'
         *  DiscreteIntegrator: '<S120>/Integrator1'
         *  DiscreteIntegrator: '<S121>/Integrator'
         *  DiscreteIntegrator: '<S121>/Integrator1'
         */
        FMS_DW.Integrator1_DSTATE_l = 0.0F;
        FMS_DW.Integrator1_DSTATE_mb = 0.0F;
        FMS_DW.Integrator1_DSTATE_hf = 0.0F;
        FMS_DW.Integrator_DSTATE_e = 0.0F;
        FMS_DW.Integrator_DSTATE_l = 0.0F;
        FMS_DW.Integrator_DSTATE_oy = 0.0F;

        /* End of InitializeConditions for SubSystem: '<S44>/BackwardTrans_Mode' */

        /* SystemReset for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
         *  ActionPort: '<S48>/Action Port'
         */
        /* SystemReset for SwitchCase: '<S44>/Switch Case' incorporates:
         *  Chart: '<S55>/Motion State'
         */
        FMS_MotionState_Reset(&FMS_DW.sf_MotionState_j);

        /* End of SystemReset for SubSystem: '<S44>/BackwardTrans_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* Trigonometry: '<S100>/Trigonometric Function1' */
      rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

      /* Trigonometry: '<S100>/Trigonometric Function' */
      rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

      /* SignalConversion: '<S100>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S100>/Constant3'
       */
      rtb_VectorConcatenate_or[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S100>/Gain' incorporates:
       *  Gain: '<S99>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       *  Trigonometry: '<S100>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Trigonometry: '<S100>/Trigonometric Function3' */
      rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

      /* SignalConversion: '<S100>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S100>/Constant4'
       */
      rtb_VectorConcatenate_or[5] = 0.0F;

      /* SignalConversion: '<S100>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_du[0];
      rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_du[1];
      rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_du[2];

      /* Product: '<S55>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
          FMS_U.INS_Out.vd + (rtb_VectorConcatenate_or[rtb_n + 3] *
                              FMS_U.INS_Out.ve + rtb_VectorConcatenate_or[rtb_n]
                              * FMS_U.INS_Out.vn);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      }

      /* End of Product: '<S55>/Multiply' */

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Chart: '<S55>/Motion State' incorporates:
       *  Abs: '<S55>/Abs'
       *  Abs: '<S55>/Abs1'
       *  Abs: '<S55>/Abs2'
       *  Constant: '<S96>/Constant'
       *  Constant: '<S97>/Constant'
       *  Inport: '<Root>/Pilot_Cmd'
       *  Logic: '<S55>/Logical Operator'
       *  RelationalOperator: '<S96>/Compare'
       *  RelationalOperator: '<S97>/Compare'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ) ||
                      (fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ),
                      fabsf(rtb_MatrixConcatenate1_0[0]), &rtb_state_ej,
                      &FMS_DW.sf_MotionState_j);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SwitchCase: '<S54>/Switch Case' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ff;
      FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;
      switch (rtb_state_ej) {
       case MotionState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_ff = 0;
        break;

       case MotionState_Brake:
        FMS_DW.SwitchCase_ActiveSubsystem_ff = 1;
        break;

       case MotionState_Move:
        FMS_DW.SwitchCase_ActiveSubsystem_ff = 2;
        break;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_ff) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_ff != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S54>/Hold Control' incorporates:
           *  ActionPort: '<S57>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S54>/Switch Case' */
          FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_p,
            &FMS_DW.HoldControl_p);

          /* End of SystemReset for SubSystem: '<S54>/Hold Control' */
        }

        /* Outputs for IfAction SubSystem: '<S54>/Hold Control' incorporates:
         *  ActionPort: '<S57>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_HoldControl_b(rtb_Divide_p3p, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                          FMS_U.INS_Out.vd, FMS_U.INS_Out.psi, FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, &FMS_B.Merge_n,
                          &FMS_ConstB.HoldControl_p, &FMS_DW.HoldControl_p);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S54>/Hold Control' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S54>/Brake Control' incorporates:
         *  ActionPort: '<S56>/Action Port'
         */
        /* SignalConversion: '<S56>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
         *  Constant: '<S56>/Brake Speed'
         */
        FMS_B.Merge_n = 0.0F;

        /* End of Outputs for SubSystem: '<S54>/Brake Control' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S54>/Move Control' incorporates:
         *  ActionPort: '<S58>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S93>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u_b = 0.0F;
        } else {
          rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S93>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S58>/Gain6' incorporates:
         *  Gain: '<S93>/Gain'
         */
        FMS_B.Merge_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
          (FMS_PARAM.FW_ACC_Y_LIM / 2.0F);

        /* End of Outputs for SubSystem: '<S54>/Move Control' */
        break;
      }

      /* End of SwitchCase: '<S54>/Switch Case' */

      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  BusAssignment: '<S48>/Bus Assignment'
       *  Constant: '<S48>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S48>/Bus Assignment' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  Constant: '<S48>/Constant3'
       *  DiscreteIntegrator: '<S119>/Integrator1'
       *  DiscreteIntegrator: '<S120>/Integrator1'
       *  DiscreteIntegrator: '<S121>/Integrator1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_g;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_i;
      FMS_Y.FMS_Out.u_cmd = 0.0F;
      FMS_Y.FMS_Out.v_cmd = FMS_DW.Integrator1_DSTATE_l;
      FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_mb;
      FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_hf;

      /* Saturate: '<S54>/Saturation1' */
      if (FMS_B.Merge_n > FMS_PARAM.FW_ACC_Y_LIM) {
        /* BusAssignment: '<S48>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
      } else if (FMS_B.Merge_n < -FMS_PARAM.FW_ACC_Y_LIM) {
        /* BusAssignment: '<S48>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
      } else {
        /* BusAssignment: '<S48>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_n;
      }

      /* End of Saturate: '<S54>/Saturation1' */

      /* Product: '<S123>/Multiply1' incorporates:
       *  Constant: '<S123>/const1'
       *  DiscreteIntegrator: '<S120>/Integrator'
       */
      rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_e * 0.02F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S118>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
        rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
      } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
        rtb_u_b = 0.0F;
      } else {
        rtb_u_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
      }

      /* End of DeadZone: '<S118>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S123>/Add' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator1'
       *  Gain: '<S118>/Gain'
       *  Gain: '<S53>/Gain2'
       *  Sum: '<S120>/Subtract'
       */
      rtb_u_b = (FMS_DW.Integrator1_DSTATE_hf - 1.0F / (1.0F - FMS_PARAM.YAW_DZ)
                 * rtb_u_b * (FMS_PARAM.YAW_RATE_LIM / 2.0F)) +
        rtb_Integrator1_bx;

      /* Signum: '<S123>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_pq = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_pq = 1.0F;
      } else {
        rtb_Divide_pq = rtb_u_b;
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
      rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_j) *
        FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Divide_pq +
        rtb_Integrator1_bx;

      /* Sum: '<S123>/Add4' */
      rtb_Saturation1_d = (rtb_u_b - rtb_P_f_idx_0) + rtb_Integrator1_bx;

      /* Sum: '<S123>/Add3' */
      rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_j;

      /* Sum: '<S123>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_j;

      /* Signum: '<S123>/Sign1' */
      if (rtb_Saturation_ga < 0.0F) {
        rtb_Saturation_ga = -1.0F;
      } else {
        if (rtb_Saturation_ga > 0.0F) {
          rtb_Saturation_ga = 1.0F;
        }
      }

      /* End of Signum: '<S123>/Sign1' */

      /* Signum: '<S123>/Sign2' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S123>/Sign2' */

      /* Sum: '<S123>/Add5' incorporates:
       *  Gain: '<S123>/Gain2'
       *  Product: '<S123>/Multiply4'
       *  Sum: '<S123>/Subtract2'
       */
      rtb_P_f_idx_0 += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

      /* Sum: '<S123>/Add6' */
      rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_j;

      /* Sum: '<S123>/Subtract3' */
      rtb_Saturation1_d = rtb_P_f_idx_0 - FMS_ConstB.d_j;

      /* Product: '<S123>/Divide' */
      rtb_a_bx = rtb_P_f_idx_0 / FMS_ConstB.d_j;

      /* Signum: '<S123>/Sign5' incorporates:
       *  Signum: '<S123>/Sign6'
       */
      if (rtb_P_f_idx_0 < 0.0F) {
        rtb_Sign5_p2 = -1.0F;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = -1.0F;
      } else if (rtb_P_f_idx_0 > 0.0F) {
        rtb_Sign5_p2 = 1.0F;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = 1.0F;
      } else {
        rtb_Sign5_p2 = rtb_P_f_idx_0;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = rtb_P_f_idx_0;
      }

      /* End of Signum: '<S123>/Sign5' */

      /* Product: '<S124>/Multiply1' incorporates:
       *  Constant: '<S124>/const1'
       *  DiscreteIntegrator: '<S121>/Integrator'
       */
      rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_l * 0.1F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S116>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.THROTTLE_DZ) {
        rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.THROTTLE_DZ;
      } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.THROTTLE_DZ) {
        rtb_u_b = 0.0F;
      } else {
        rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.THROTTLE_DZ);
      }

      /* End of DeadZone: '<S116>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S124>/Add' incorporates:
       *  DiscreteIntegrator: '<S121>/Integrator1'
       *  Gain: '<S116>/Gain'
       *  Gain: '<S53>/Gain1'
       *  Sum: '<S121>/Subtract'
       */
      rtb_u_b = (FMS_DW.Integrator1_DSTATE_mb - 1.0F / (1.0F -
                  FMS_PARAM.THROTTLE_DZ) * rtb_u_b * (-FMS_PARAM.VEL_Z_LIM /
                  2.0F)) + rtb_P_f_idx_0;

      /* Signum: '<S124>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_pq = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_pq = 1.0F;
      } else {
        rtb_Divide_pq = rtb_u_b;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_m2) *
        FMS_ConstB.d_m2) - FMS_ConstB.d_m2) * 0.5F * rtb_Divide_pq +
        rtb_P_f_idx_0;

      /* Sum: '<S124>/Add4' */
      rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_Integrator1_bx) + rtb_P_f_idx_0;

      /* Sum: '<S124>/Add3' */
      rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_m2;

      /* Sum: '<S124>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_m2;

      /* Signum: '<S124>/Sign1' */
      if (rtb_Divide_lr_idx_2 < 0.0F) {
        rtb_Divide_lr_idx_2 = -1.0F;
      } else {
        if (rtb_Divide_lr_idx_2 > 0.0F) {
          rtb_Divide_lr_idx_2 = 1.0F;
        }
      }

      /* End of Signum: '<S124>/Sign1' */

      /* Signum: '<S124>/Sign2' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S124>/Sign2' */

      /* Sum: '<S124>/Add5' incorporates:
       *  Gain: '<S124>/Gain2'
       *  Product: '<S124>/Multiply4'
       *  Sum: '<S124>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
        rtb_Divide_lr_idx_3;

      /* Sum: '<S124>/Add6' */
      rtb_Divide_lr_idx_2 = rtb_Integrator1_bx + FMS_ConstB.d_m2;

      /* Sum: '<S124>/Subtract3' */
      d = rtb_Integrator1_bx - FMS_ConstB.d_m2;

      /* Product: '<S124>/Divide' */
      rtb_Divide_hw = rtb_Integrator1_bx / FMS_ConstB.d_m2;

      /* Signum: '<S124>/Sign5' incorporates:
       *  Signum: '<S124>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Sign5_i = -1.0F;

        /* Signum: '<S124>/Sign6' */
        rtb_Divide_lr_idx_3 = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Sign5_i = 1.0F;

        /* Signum: '<S124>/Sign6' */
        rtb_Divide_lr_idx_3 = 1.0F;
      } else {
        rtb_Sign5_i = rtb_Integrator1_bx;

        /* Signum: '<S124>/Sign6' */
        rtb_Divide_lr_idx_3 = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S124>/Sign5' */

      /* Product: '<S122>/Multiply1' incorporates:
       *  Constant: '<S122>/const1'
       *  DiscreteIntegrator: '<S119>/Integrator'
       */
      rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_oy * 0.1F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S117>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
        rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
      } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
        rtb_u_b = 0.0F;
      } else {
        rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
      }

      /* End of DeadZone: '<S117>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S122>/Add' incorporates:
       *  DiscreteIntegrator: '<S119>/Integrator1'
       *  Gain: '<S117>/Gain'
       *  Gain: '<S53>/Gain6'
       *  Sum: '<S119>/Subtract'
       */
      rtb_u_b = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F - FMS_PARAM.ROLL_DZ)
                 * rtb_u_b * (FMS_PARAM.VEL_XY_LIM / 2.0F)) + rtb_P_f_idx_0;

      /* Signum: '<S122>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_pq = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_pq = 1.0F;
      } else {
        rtb_Divide_pq = rtb_u_b;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_oj) *
        FMS_ConstB.d_oj) - FMS_ConstB.d_oj) * 0.5F * rtb_Divide_pq +
        rtb_P_f_idx_0;

      /* Sum: '<S122>/Add4' */
      rtb_Divide_pq = (rtb_u_b - rtb_Integrator1_bx) + rtb_P_f_idx_0;

      /* Sum: '<S122>/Add3' */
      rtb_P_f_idx_0 = rtb_u_b + FMS_ConstB.d_oj;

      /* Sum: '<S122>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_oj;

      /* Signum: '<S122>/Sign1' */
      if (rtb_P_f_idx_0 < 0.0F) {
        rtb_P_f_idx_0 = -1.0F;
      } else {
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_P_f_idx_0 = 1.0F;
        }
      }

      /* End of Signum: '<S122>/Sign1' */

      /* Signum: '<S122>/Sign2' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S122>/Sign2' */

      /* Sum: '<S122>/Add5' incorporates:
       *  Gain: '<S122>/Gain2'
       *  Product: '<S122>/Multiply4'
       *  Sum: '<S122>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_P_f_idx_0 - rtb_u_b) * 0.5F * rtb_Divide_pq;

      /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S119>/Integrator'
       */
      FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_oy;

      /* Update for DiscreteIntegrator: '<S121>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S121>/Integrator'
       */
      FMS_DW.Integrator1_DSTATE_mb += 0.004F * FMS_DW.Integrator_DSTATE_l;

      /* Update for DiscreteIntegrator: '<S120>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator'
       */
      FMS_DW.Integrator1_DSTATE_hf += 0.004F * FMS_DW.Integrator_DSTATE_e;

      /* Signum: '<S123>/Sign3' */
      if (rtb_Saturation_ga < 0.0F) {
        rtb_Saturation_ga = -1.0F;
      } else {
        if (rtb_Saturation_ga > 0.0F) {
          rtb_Saturation_ga = 1.0F;
        }
      }

      /* End of Signum: '<S123>/Sign3' */

      /* Signum: '<S123>/Sign4' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S123>/Sign4' */

      /* Update for DiscreteIntegrator: '<S120>/Integrator' incorporates:
       *  Constant: '<S123>/const'
       *  Gain: '<S123>/Gain3'
       *  Product: '<S123>/Multiply5'
       *  Product: '<S123>/Multiply6'
       *  Sum: '<S123>/Subtract4'
       *  Sum: '<S123>/Subtract5'
       *  Sum: '<S123>/Subtract6'
       */
      FMS_DW.Integrator_DSTATE_e += ((rtb_a_bx - rtb_Sign5_p2) *
        FMS_ConstB.Gain4_oc * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) -
        rtb_Saturation_o4 * 15.707963F) * 0.004F;

      /* Signum: '<S124>/Sign3' */
      if (rtb_Divide_lr_idx_2 < 0.0F) {
        rtb_Divide_lr_idx_2 = -1.0F;
      } else {
        if (rtb_Divide_lr_idx_2 > 0.0F) {
          rtb_Divide_lr_idx_2 = 1.0F;
        }
      }

      /* End of Signum: '<S124>/Sign3' */

      /* Signum: '<S124>/Sign4' */
      if (d < 0.0F) {
        d = -1.0F;
      } else {
        if (d > 0.0F) {
          d = 1.0F;
        }
      }

      /* End of Signum: '<S124>/Sign4' */

      /* Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
       *  Constant: '<S124>/const'
       *  Gain: '<S124>/Gain3'
       *  Product: '<S124>/Multiply5'
       *  Product: '<S124>/Multiply6'
       *  Sum: '<S124>/Subtract4'
       *  Sum: '<S124>/Subtract5'
       *  Sum: '<S124>/Subtract6'
       */
      FMS_DW.Integrator_DSTATE_l += ((rtb_Divide_hw - rtb_Sign5_i) *
        FMS_ConstB.Gain4_ht * ((rtb_Divide_lr_idx_2 - d) * 0.5F) -
        rtb_Divide_lr_idx_3 * 39.224F) * 0.004F;

      /* Sum: '<S122>/Subtract3' */
      rtb_Saturation_ga = rtb_Integrator1_bx - FMS_ConstB.d_oj;

      /* Sum: '<S122>/Add6' */
      rtb_Saturation1_d = rtb_Integrator1_bx + FMS_ConstB.d_oj;

      /* Signum: '<S122>/Sign5' incorporates:
       *  Signum: '<S122>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Saturation_o4 = -1.0F;

        /* Signum: '<S122>/Sign6' */
        rtb_Divide_lr_idx_3 = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Saturation_o4 = 1.0F;

        /* Signum: '<S122>/Sign6' */
        rtb_Divide_lr_idx_3 = 1.0F;
      } else {
        rtb_Saturation_o4 = rtb_Integrator1_bx;

        /* Signum: '<S122>/Sign6' */
        rtb_Divide_lr_idx_3 = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S122>/Sign5' */

      /* Signum: '<S122>/Sign3' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S122>/Sign3' */

      /* Signum: '<S122>/Sign4' */
      if (rtb_Saturation_ga < 0.0F) {
        rtb_Saturation_ga = -1.0F;
      } else {
        if (rtb_Saturation_ga > 0.0F) {
          rtb_Saturation_ga = 1.0F;
        }
      }

      /* End of Signum: '<S122>/Sign4' */

      /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
       *  Constant: '<S122>/const'
       *  Gain: '<S122>/Gain3'
       *  Product: '<S122>/Divide'
       *  Product: '<S122>/Multiply5'
       *  Product: '<S122>/Multiply6'
       *  Sum: '<S122>/Subtract4'
       *  Sum: '<S122>/Subtract5'
       *  Sum: '<S122>/Subtract6'
       */
      FMS_DW.Integrator_DSTATE_oy += ((rtb_Integrator1_bx / FMS_ConstB.d_oj -
        rtb_Saturation_o4) * FMS_ConstB.Gain4_i3 * ((rtb_Saturation1_d -
        rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 39.224F) * 0.004F;

      /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
       *  ActionPort: '<S50>/Action Port'
       */
      /* SwitchCase: '<S50>/Switch Case' */
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
          /* Disable for SwitchCase: '<S343>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S743>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S733>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S682>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S650>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S661>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S341>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S452>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S503>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S493>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S452>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S340>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S439>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S355>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S373>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S389>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S414>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S401>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
         *  ActionPort: '<S343>/Action Port'
         */
        /* SwitchCase: '<S343>/Switch Case' incorporates:
         *  Math: '<S765>/Math Function'
         *  Sum: '<S727>/Subtract'
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
            /* Disable for SwitchCase: '<S743>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S733>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S682>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S650>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S661>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S343>/Takeoff' incorporates:
             *  ActionPort: '<S645>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S343>/Switch Case' incorporates:
             *  Delay: '<S783>/cur_waypoint'
             *  DiscreteIntegrator: '<S779>/Integrator'
             *  DiscreteIntegrator: '<S779>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S343>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S343>/Takeoff' incorporates:
           *  ActionPort: '<S645>/Action Port'
           */
          /* Delay: '<S783>/cur_waypoint' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_hz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
            FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Product: '<S783>/Divide' incorporates:
           *  Delay: '<S783>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S783>/Sum1'
           *  Sum: '<S783>/Sum2'
           */
          rtb_Saturation_o4 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S783>/Saturation' */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_o4 = 0.0F;
            }
          }

          /* End of Saturate: '<S783>/Saturation' */

          /* Trigonometry: '<S784>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S784>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S784>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S784>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S784>/Gain' incorporates:
           *  Gain: '<S782>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S784>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S784>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S784>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S784>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S784>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S776>/Saturation1' */
          rtb_Saturation_ga = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Saturation1_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S776>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S783>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S783>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S776>/Sum'
           *  Sum: '<S783>/Sum3'
           *  Sum: '<S783>/Sum4'
           */
          d = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0]) *
               rtb_Saturation_o4 + FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_o4 +
                                FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S776>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d;
          }

          /* Saturate: '<S776>/Saturation1' incorporates:
           *  Gain: '<S776>/Gain2'
           *  Product: '<S776>/Multiply'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S645>/Bus Assignment1'
           *  Constant: '<S645>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S645>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S776>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_ga) {
            /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_ga;
          } else if (rtb_u_b < rtb_Saturation1_d) {
            /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Divide_lr_idx_2 > rtb_Saturation_ga) {
            /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_ga;
          } else if (rtb_Divide_lr_idx_2 < rtb_Saturation1_d) {
            /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_2;
          }

          /* BusAssignment: '<S645>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S779>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S780>/Multiply1' incorporates:
           *  Constant: '<S780>/const1'
           *  DiscreteIntegrator: '<S779>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S775>/Switch' incorporates:
           *  Abs: '<S775>/Abs'
           *  Abs: '<S775>/Abs1'
           *  Constant: '<S775>/Takeoff_Speed'
           *  Constant: '<S777>/Constant'
           *  Constant: '<S778>/Constant'
           *  Gain: '<S775>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S775>/Logical Operator'
           *  RelationalOperator: '<S777>/Compare'
           *  RelationalOperator: '<S778>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S775>/Sum'
           *  Sum: '<S775>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_u_b = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_u_b = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S775>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S780>/Add' incorporates:
           *  DiscreteIntegrator: '<S779>/Integrator1'
           *  Sum: '<S779>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_f - rtb_u_b) +
            rtb_Saturation_o4;

          /* Signum: '<S780>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S780>/Sign' */

          /* Sum: '<S780>/Add2' incorporates:
           *  Abs: '<S780>/Abs'
           *  Gain: '<S780>/Gain'
           *  Gain: '<S780>/Gain1'
           *  Product: '<S780>/Multiply2'
           *  Product: '<S780>/Multiply3'
           *  Sqrt: '<S780>/Sqrt'
           *  Sum: '<S780>/Add1'
           *  Sum: '<S780>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_b) *
                           FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S780>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S780>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Sum: '<S780>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_b;

          /* Signum: '<S780>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S780>/Sign1' */

          /* Signum: '<S780>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S780>/Sign2' */

          /* Sum: '<S780>/Add5' incorporates:
           *  Gain: '<S780>/Gain2'
           *  Product: '<S780>/Multiply4'
           *  Sum: '<S780>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S783>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S779>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S779>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S780>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_b;

          /* Sum: '<S780>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_b;

          /* Signum: '<S780>/Sign5' incorporates:
           *  Signum: '<S780>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S780>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S780>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S780>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S780>/Sign5' */

          /* Signum: '<S780>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S780>/Sign3' */

          /* Signum: '<S780>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S780>/Sign4' */

          /* Update for DiscreteIntegrator: '<S779>/Integrator' incorporates:
           *  Constant: '<S780>/const'
           *  Gain: '<S780>/Gain3'
           *  Product: '<S780>/Divide'
           *  Product: '<S780>/Multiply5'
           *  Product: '<S780>/Multiply6'
           *  Sum: '<S780>/Subtract4'
           *  Sum: '<S780>/Subtract5'
           *  Sum: '<S780>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_u_b / FMS_ConstB.d_b -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_i * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S343>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S343>/Land' incorporates:
             *  ActionPort: '<S643>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S343>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S698>/Integrator'
             *  DiscreteIntegrator: '<S698>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S343>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S343>/Land' incorporates:
           *  ActionPort: '<S643>/Action Port'
           */
          /* Trigonometry: '<S703>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S703>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S703>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S703>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S703>/Gain' incorporates:
           *  Gain: '<S702>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S703>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S703>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S703>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S703>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S703>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S696>/Saturation1' */
          rtb_Saturation_o4 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Divide_lr_idx_3 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S700>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S700>/Sum'
           */
          d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S700>/Multiply' incorporates:
           *  SignalConversion: '<S700>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S700>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d;
          }

          /* End of Product: '<S700>/Multiply' */

          /* Saturate: '<S696>/Saturation1' incorporates:
           *  Gain: '<S700>/Gain2'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S643>/Bus Assignment1'
           *  Constant: '<S643>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S643>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S696>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_o4) {
            /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_o4;
          } else if (rtb_u_b < rtb_Divide_lr_idx_3) {
            /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_lr_idx_3;
          } else {
            /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Divide_lr_idx_2 > rtb_Saturation_o4) {
            /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_o4;
          } else if (rtb_Divide_lr_idx_2 < rtb_Divide_lr_idx_3) {
            /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_3;
          } else {
            /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_2;
          }

          /* BusAssignment: '<S643>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S698>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S699>/Multiply1' incorporates:
           *  Constant: '<S699>/const1'
           *  DiscreteIntegrator: '<S698>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S695>/Switch' incorporates:
           *  Constant: '<S695>/Land_Speed'
           *  Constant: '<S697>/Constant'
           *  Gain: '<S695>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S695>/Logical Operator'
           *  RelationalOperator: '<S697>/Compare'
           *  S-Function (sfix_bitop): '<S695>/cmd_p valid'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_u_b = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_u_b = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S695>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S699>/Add' incorporates:
           *  DiscreteIntegrator: '<S698>/Integrator1'
           *  Sum: '<S698>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_g - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S699>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S699>/Sign' */

          /* Sum: '<S699>/Add2' incorporates:
           *  Abs: '<S699>/Abs'
           *  Gain: '<S699>/Gain'
           *  Gain: '<S699>/Gain1'
           *  Product: '<S699>/Multiply2'
           *  Product: '<S699>/Multiply3'
           *  Sqrt: '<S699>/Sqrt'
           *  Sum: '<S699>/Add1'
           *  Sum: '<S699>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_om) *
                           FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S699>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S699>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Sum: '<S699>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_om;

          /* Signum: '<S699>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S699>/Sign1' */

          /* Signum: '<S699>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S699>/Sign2' */

          /* Sum: '<S699>/Add5' incorporates:
           *  Gain: '<S699>/Gain2'
           *  Product: '<S699>/Multiply4'
           *  Sum: '<S699>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for DiscreteIntegrator: '<S698>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S698>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S699>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_om;

          /* Sum: '<S699>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_om;

          /* Signum: '<S699>/Sign5' incorporates:
           *  Signum: '<S699>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S699>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S699>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S699>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S699>/Sign5' */

          /* Signum: '<S699>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S699>/Sign3' */

          /* Signum: '<S699>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S699>/Sign4' */

          /* Update for DiscreteIntegrator: '<S698>/Integrator' incorporates:
           *  Constant: '<S699>/const'
           *  Gain: '<S699>/Gain3'
           *  Product: '<S699>/Divide'
           *  Product: '<S699>/Multiply5'
           *  Product: '<S699>/Multiply6'
           *  Sum: '<S699>/Subtract4'
           *  Sum: '<S699>/Subtract5'
           *  Sum: '<S699>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_u_b / FMS_ConstB.d_om -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_p * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S343>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S343>/Return' incorporates:
             *  ActionPort: '<S644>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S343>/Switch Case' incorporates:
             *  Delay: '<S707>/Delay'
             *  Delay: '<S728>/Delay'
             *  DiscreteIntegrator: '<S710>/Integrator'
             *  DiscreteIntegrator: '<S710>/Integrator1'
             *  DiscreteIntegrator: '<S724>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S729>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S770>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S343>/Return' */

            /* SystemReset for IfAction SubSystem: '<S343>/Return' incorporates:
             *  ActionPort: '<S644>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S343>/Switch Case' incorporates:
             *  Chart: '<S734>/Motion Status'
             *  Chart: '<S744>/Motion State'
             */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S343>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S343>/Return' incorporates:
           *  ActionPort: '<S644>/Action Port'
           */
          /* Delay: '<S728>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S723>/Compare' incorporates:
           *  Constant: '<S774>/Constant'
           *  DiscreteIntegrator: '<S729>/Discrete-Time Integrator'
           *  RelationalOperator: '<S774>/Compare'
           */
          rtb_Compare_o3 = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S724>/Acceleration_Speed' */
          if (rtb_Compare_o3 || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
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
          /* Chart: '<S744>/Motion State' incorporates:
           *  Constant: '<S744>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S744>/Square'
           *  Math: '<S744>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S744>/Sqrt'
           *  Sum: '<S744>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S743>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S743>/Hold Control' incorporates:
               *  ActionPort: '<S746>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S743>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S743>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S743>/Hold Control' incorporates:
             *  ActionPort: '<S746>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S743>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S743>/Brake Control' incorporates:
             *  ActionPort: '<S745>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S743>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S743>/Move Control' incorporates:
               *  ActionPort: '<S747>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S743>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S743>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S743>/Move Control' incorporates:
             *  ActionPort: '<S747>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S743>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S743>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S734>/Motion Status' incorporates:
           *  Abs: '<S734>/Abs'
           *  Constant: '<S734>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S733>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S733>/Hold Control' incorporates:
               *  ActionPort: '<S736>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S733>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S733>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S733>/Hold Control' incorporates:
             *  ActionPort: '<S736>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S733>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S733>/Brake Control' incorporates:
             *  ActionPort: '<S735>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S733>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S733>/Move Control' incorporates:
               *  ActionPort: '<S737>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S733>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_cg);

              /* End of SystemReset for SubSystem: '<S733>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S733>/Move Control' incorporates:
             *  ActionPort: '<S737>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_cg, &FMS_DW.MoveControl_cg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S733>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S733>/Switch Case' */

          /* Switch: '<S705>/Switch' incorporates:
           *  Product: '<S728>/Multiply'
           *  Sum: '<S728>/Sum'
           */
          if (rtb_Compare_o3) {
            /* Saturate: '<S743>/Saturation1' */
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

            /* End of Saturate: '<S743>/Saturation1' */

            /* Saturate: '<S733>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S733>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S728>/Sum' incorporates:
             *  Delay: '<S728>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S771>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_lr_idx_3;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S724>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_o4 = rtb_Divide_lr_idx_3;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S728>/Sum' incorporates:
             *  Delay: '<S728>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S724>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S730>/Sqrt' incorporates:
             *  Math: '<S730>/Square'
             *  Sum: '<S724>/Sum'
             *  Sum: '<S730>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
                            rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S773>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S773>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S773>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S772>/Gain' incorporates:
             *  DiscreteIntegrator: '<S770>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S770>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S773>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S773>/Trigonometric Function1'
             */
            rtb_Saturation_ga = arm_cos_f32(rtb_Saturation1_d);
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Trigonometry: '<S773>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S773>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation1_d);

            /* Gain: '<S773>/Gain' incorporates:
             *  Trigonometry: '<S773>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S773>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S773>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S773>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S773>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* Switch: '<S724>/Switch' incorporates:
             *  Constant: '<S724>/vel'
             */
            if (rtb_u_b > FMS_PARAM.L1) {
              rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S724>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_u_b;

              /* Saturate: '<S724>/Saturation' */
              if (rtb_Saturation1_d > FMS_PARAM.CRUISE_SPEED) {
                rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Saturate: '<S724>/Saturation' */
            }

            /* End of Switch: '<S724>/Switch' */

            /* Switch: '<S724>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S724>/Acceleration_Speed'
             *  Sum: '<S724>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S724>/Switch1' */

            /* Sum: '<S771>/Sum of Elements' incorporates:
             *  Math: '<S771>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Divide_lr_idx_3 *
              rtb_Divide_lr_idx_3;

            /* Math: '<S771>/Math Function1' incorporates:
             *  Sum: '<S771>/Sum of Elements'
             *
             * About '<S771>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_Saturation_ga = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S771>/Math Function1' */

            /* Switch: '<S771>/Switch' incorporates:
             *  Constant: '<S771>/Constant'
             *  Product: '<S771>/Product'
             */
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Divide_p3p[0] = rtb_Saturation_o4;
              rtb_Divide_p3p[1] = rtb_Divide_lr_idx_3;
              rtb_Divide_p3p[3] = rtb_Saturation_ga;
            } else {
              rtb_Divide_p3p[0] = 0.0F;
              rtb_Divide_p3p[1] = 0.0F;
              rtb_Divide_p3p[3] = 1.0F;
            }

            /* End of Switch: '<S771>/Switch' */

            /* Product: '<S769>/Multiply2' incorporates:
             *  Product: '<S771>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_p3p[0] / rtb_Divide_p3p[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_p3p[1] / rtb_Divide_p3p[3];
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_c2[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Saturation1_d + rtb_VectorConcatenate_or[rtb_n] *
                rtb_Saturation_ga;
            }
          }

          /* End of Switch: '<S705>/Switch' */

          /* Delay: '<S707>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S710>/Integrator1' incorporates:
           *  Delay: '<S707>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S714>/Rem' incorporates:
           *  Constant: '<S714>/Constant1'
           *  DiscreteIntegrator: '<S710>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S709>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S714>/Switch' incorporates:
           *  Abs: '<S714>/Abs'
           *  Constant: '<S714>/Constant'
           *  Constant: '<S715>/Constant'
           *  Product: '<S714>/Multiply'
           *  RelationalOperator: '<S715>/Compare'
           *  Sum: '<S714>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S714>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S714>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S714>/Switch' */

          /* Gain: '<S709>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S709>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S709>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S644>/Bus Assignment1'
           *  Constant: '<S644>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S644>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_o4;

          /* Math: '<S764>/Math Function1'
           *
           * About '<S764>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S764>/Math Function1' */

          /* Switch: '<S764>/Switch' incorporates:
           *  Constant: '<S764>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S764>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S764>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S644>/Sum' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_c14[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_c14[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S721>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S644>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S721>/Math Function' incorporates:
           *  Sum: '<S644>/Sum'
           */
          rtb_Square_ds[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_ds[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S721>/Sum of Elements' */
          rtb_u_b = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S721>/Math Function1' incorporates:
           *  Sum: '<S721>/Sum of Elements'
           *
           * About '<S721>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S721>/Math Function1' */

          /* Switch: '<S721>/Switch' incorporates:
           *  Constant: '<S721>/Constant'
           *  Product: '<S721>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Integrator1_bx = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S721>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S726>/NearbyRefWP' incorporates:
           *  Constant: '<S644>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_c14,
                          &rtb_u_b);

          /* MATLAB Function: '<S726>/SearchL1RefWP' incorporates:
           *  Constant: '<S644>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S726>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S726>/Switch1' incorporates:
           *  Constant: '<S757>/Constant'
           *  RelationalOperator: '<S757>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_c14[0];
            rtb_P_ap[1] = rtb_Divide_c14[1];
          } else {
            /* RelationalOperator: '<S756>/Compare' incorporates:
             *  Constant: '<S756>/Constant'
             */
            rtb_Compare_aij = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S726>/Switch' */
            if (!rtb_Compare_aij) {
              rtb_P_ap[0] = rtb_Square_ds[0];
              rtb_P_ap[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S726>/Switch' */
          }

          /* End of Switch: '<S726>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S727>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Divide_lr_idx_3;
          rtb_Subtract_hb[0] = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S727>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S765>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S765>/Sum of Elements' incorporates:
           *  Math: '<S765>/Math Function'
           *  Sum: '<S763>/Sum of Elements'
           */
          rtb_u_b = rtb_Subtract_hb[0] + rtb_Divide_lr_idx_3 *
            rtb_Divide_lr_idx_3;

          /* Math: '<S765>/Math Function1' incorporates:
           *  Sum: '<S765>/Sum of Elements'
           *
           * About '<S765>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S765>/Math Function1' */

          /* Switch: '<S765>/Switch' incorporates:
           *  Constant: '<S765>/Constant'
           *  Product: '<S765>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_P_ap[0];
            rtb_MatrixConcatenate3[1] = rtb_Divide_lr_idx_3;
            rtb_MatrixConcatenate3[2] = rtb_Saturation_o4;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S765>/Switch' */

          /* Product: '<S764>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S767>/Sum of Elements' incorporates:
           *  Math: '<S767>/Math Function'
           *  SignalConversion: '<S767>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S767>/Math Function1' incorporates:
           *  Sum: '<S767>/Sum of Elements'
           *
           * About '<S767>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S767>/Math Function1' */

          /* Switch: '<S767>/Switch' incorporates:
           *  Constant: '<S767>/Constant'
           *  Product: '<S767>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_c14[1];
            rtb_Switch_c2[1] = rtb_Divide_c14[0];
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S767>/Switch' */

          /* Product: '<S765>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S768>/Sum of Elements' incorporates:
           *  Math: '<S768>/Math Function'
           *  SignalConversion: '<S768>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S768>/Math Function1' incorporates:
           *  Sum: '<S768>/Sum of Elements'
           *
           * About '<S768>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S768>/Math Function1' */

          /* Switch: '<S768>/Switch' incorporates:
           *  Constant: '<S768>/Constant'
           *  Product: '<S768>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Divide_c14[1];
            rtb_MatrixConcatenate3[1] = rtb_Divide_c14[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_o4;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S768>/Switch' */

          /* Product: '<S768>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S767>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S721>/Divide' */
          rtb_Square_ds[0] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S768>/Divide' */
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S767>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S721>/Divide' */
          rtb_Square_ds[1] = rtb_Saturation1_d / rtb_Integrator1_bx;

          /* Sum: '<S766>/Subtract' incorporates:
           *  Product: '<S766>/Multiply'
           *  Product: '<S766>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_c14[0] * rtb_P_ap[1] - rtb_Divide_c14[1]
            * rtb_P_ap[0];

          /* Signum: '<S761>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S761>/Sign1' */

          /* Switch: '<S761>/Switch2' incorporates:
           *  Constant: '<S761>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S761>/Switch2' */

          /* DotProduct: '<S761>/Dot Product' */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] * rtb_Divide_c14[0] + rtb_P_ap[1] *
            rtb_Divide_c14[1];

          /* Trigonometry: '<S761>/Acos' incorporates:
           *  DotProduct: '<S761>/Dot Product'
           */
          if (rtb_Divide_lr_idx_3 > 1.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 < -1.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            }
          }

          /* Product: '<S761>/Multiply' incorporates:
           *  Trigonometry: '<S761>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Divide_lr_idx_3);

          /* Saturate: '<S727>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S727>/Saturation' */

          /* Product: '<S727>/Divide' incorporates:
           *  Constant: '<S644>/L1'
           *  Constant: '<S727>/Constant'
           *  Gain: '<S727>/Gain'
           *  Math: '<S727>/Square'
           *  MinMax: '<S727>/Max'
           *  MinMax: '<S727>/Min'
           *  Product: '<S727>/Multiply1'
           *  Sqrt: '<S763>/Sqrt'
           *  Trigonometry: '<S727>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S719>/Subtract' incorporates:
           *  Product: '<S719>/Multiply'
           *  Product: '<S719>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S708>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S708>/Sign1' */

          /* Switch: '<S708>/Switch2' incorporates:
           *  Constant: '<S708>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S708>/Switch2' */

          /* DotProduct: '<S708>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide_m[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S708>/Acos' incorporates:
           *  DotProduct: '<S708>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S708>/Multiply' incorporates:
           *  Trigonometry: '<S708>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_u_b);

          /* Math: '<S711>/Rem' incorporates:
           *  Constant: '<S711>/Constant1'
           *  Delay: '<S707>/Delay'
           *  Sum: '<S707>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S711>/Switch' incorporates:
           *  Abs: '<S711>/Abs'
           *  Constant: '<S711>/Constant'
           *  Constant: '<S717>/Constant'
           *  Product: '<S711>/Multiply'
           *  RelationalOperator: '<S717>/Compare'
           *  Sum: '<S711>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S711>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S711>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S711>/Switch' */

          /* Sum: '<S707>/Sum' incorporates:
           *  Delay: '<S707>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S716>/Multiply1' incorporates:
           *  Constant: '<S716>/const1'
           *  DiscreteIntegrator: '<S710>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S716>/Add' incorporates:
           *  DiscreteIntegrator: '<S710>/Integrator1'
           *  Sum: '<S710>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S716>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S716>/Sign' */

          /* Sum: '<S716>/Add2' incorporates:
           *  Abs: '<S716>/Abs'
           *  Gain: '<S716>/Gain'
           *  Gain: '<S716>/Gain1'
           *  Product: '<S716>/Multiply2'
           *  Product: '<S716>/Multiply3'
           *  Sqrt: '<S716>/Sqrt'
           *  Sum: '<S716>/Add1'
           *  Sum: '<S716>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_n) *
                           FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S716>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S716>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_n;

          /* Sum: '<S716>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_n;

          /* Signum: '<S716>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S716>/Sign1' */

          /* Signum: '<S716>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S716>/Sign2' */

          /* Sum: '<S716>/Add5' incorporates:
           *  Gain: '<S716>/Gain2'
           *  Product: '<S716>/Multiply4'
           *  Sum: '<S716>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S716>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_n;

          /* Sum: '<S716>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_n;

          /* Product: '<S716>/Divide' */
          d = rtb_u_b / FMS_ConstB.d_n;

          /* Signum: '<S716>/Sign5' incorporates:
           *  Signum: '<S716>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S716>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S716>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = rtb_u_b;

            /* Signum: '<S716>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S716>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S707>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S712>/Rem' incorporates:
           *  Constant: '<S712>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S712>/Switch' incorporates:
           *  Abs: '<S712>/Abs'
           *  Constant: '<S712>/Constant'
           *  Constant: '<S718>/Constant'
           *  Product: '<S712>/Multiply'
           *  RelationalOperator: '<S718>/Compare'
           *  Sum: '<S712>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S712>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_u_b;
            }

            /* End of Signum: '<S712>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S712>/Switch' */

          /* Abs: '<S705>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S728>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S729>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S722>/Constant'
           *  RelationalOperator: '<S722>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_a = (uint8_T)((uint32_T)(rtb_u_b <=
            0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_a);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S729>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S724>/Acceleration_Speed' incorporates:
           *  Constant: '<S724>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE_a += 0.004F * FMS_PARAM.CRUISE_ACC;
          if (FMS_DW.Acceleration_Speed_DSTATE_a >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE_a = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE_a <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            }
          }

          FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_o3;

          /* End of Update for DiscreteIntegrator: '<S724>/Acceleration_Speed' */

          /* Product: '<S728>/Divide1' incorporates:
           *  Constant: '<S728>/Constant'
           */
          rtb_u_b = rtb_Divide_lr_idx_2 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S728>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S728>/Saturation' */

          /* Update for DiscreteIntegrator: '<S770>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_u_b;

          /* Update for Delay: '<S707>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S710>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S710>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S716>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S716>/Sign3' */

          /* Signum: '<S716>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S716>/Sign4' */

          /* Update for DiscreteIntegrator: '<S710>/Integrator' incorporates:
           *  Constant: '<S716>/const'
           *  Gain: '<S716>/Gain3'
           *  Product: '<S716>/Multiply5'
           *  Product: '<S716>/Multiply6'
           *  Sum: '<S716>/Subtract4'
           *  Sum: '<S716>/Subtract5'
           *  Sum: '<S716>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((d - rtb_Integrator1_bx) *
            FMS_ConstB.Gain4_d * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S710>/Integrator' */
          /* End of Outputs for SubSystem: '<S343>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S343>/Hold' incorporates:
             *  ActionPort: '<S642>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S343>/Switch Case' incorporates:
             *  Delay: '<S663>/Delay'
             *  DiscreteIntegrator: '<S675>/Integrator'
             *  DiscreteIntegrator: '<S675>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S343>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S343>/Hold' incorporates:
             *  ActionPort: '<S642>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S343>/Switch Case' incorporates:
             *  Chart: '<S651>/Motion Status'
             *  Chart: '<S662>/Motion State'
             *  Chart: '<S683>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S343>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S343>/Hold' incorporates:
           *  ActionPort: '<S642>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S651>/Motion Status' incorporates:
           *  Abs: '<S651>/Abs'
           *  Constant: '<S651>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S662>/Motion State' incorporates:
           *  Abs: '<S662>/Abs'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.temporalCounter_i1_i < 255U) {
            FMS_DW.temporalCounter_i1_i++;
          }

          if (FMS_DW.is_active_c15_FMS == 0U) {
            FMS_DW.is_active_c15_FMS = 1U;
            FMS_DW.is_c15_FMS = FMS_IN_Move_a;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c15_FMS) {
             case FMS_IN_Brake_m:
              rtb_state_fg = MotionState_Brake;

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              if ((fabsf(FMS_U.INS_Out.r) <= 0.1) ||
                  (FMS_DW.temporalCounter_i1_i >= 250U)) {
                FMS_DW.is_c15_FMS = FMS_IN_Hold_ow;
                rtb_state_fg = MotionState_Hold;
              }

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              break;

             case FMS_IN_Hold_ow:
              rtb_state_fg = MotionState_Hold;
              break;

             default:
              FMS_DW.is_c15_FMS = FMS_IN_Brake_m;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_fg = MotionState_Brake;
              break;
            }
          }

          /* End of Chart: '<S662>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S683>/Motion State' incorporates:
           *  Constant: '<S683>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S683>/Square'
           *  Math: '<S683>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S683>/Sqrt'
           *  Sum: '<S683>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                            &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S682>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S682>/Hold Control' incorporates:
               *  ActionPort: '<S685>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S682>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S682>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S682>/Hold Control' incorporates:
             *  ActionPort: '<S685>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S682>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S682>/Brake Control' incorporates:
             *  ActionPort: '<S684>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S682>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S682>/Move Control' incorporates:
               *  ActionPort: '<S686>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S682>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S682>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S682>/Move Control' incorporates:
             *  ActionPort: '<S686>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S682>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S682>/Switch Case' */

          /* SwitchCase: '<S650>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k4;
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S650>/Hold Control' incorporates:
               *  ActionPort: '<S653>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S650>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S650>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S650>/Hold Control' incorporates:
             *  ActionPort: '<S653>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S650>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S650>/Brake Control' incorporates:
             *  ActionPort: '<S652>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S650>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S650>/Move Control' incorporates:
               *  ActionPort: '<S654>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S650>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S650>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S650>/Move Control' incorporates:
             *  ActionPort: '<S654>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S650>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S650>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S660>/Compare' incorporates:
           *  Constant: '<S660>/Constant'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Compare_o3 = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S663>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S675>/Integrator1' incorporates:
           *  Delay: '<S663>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_Compare_o3 || (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S661>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S661>/Hold Control' incorporates:
               *  ActionPort: '<S665>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S661>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S661>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S661>/Hold Control' incorporates:
             *  ActionPort: '<S665>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S661>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S661>/Brake Control' incorporates:
             *  ActionPort: '<S664>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S661>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S661>/Move Control' incorporates:
               *  ActionPort: '<S666>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S661>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S661>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S661>/Move Control' incorporates:
             *  ActionPort: '<S666>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S661>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S661>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S648>/Switch' incorporates:
           *  Saturate: '<S661>/Saturation'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S678>/Rem' incorporates:
             *  Constant: '<S678>/Constant1'
             *  DiscreteIntegrator: '<S675>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S674>/Sum'
             */
            rtb_Saturation_ga = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S678>/Switch' incorporates:
             *  Abs: '<S678>/Abs'
             *  Constant: '<S678>/Constant'
             *  Constant: '<S679>/Constant'
             *  Product: '<S678>/Multiply'
             *  RelationalOperator: '<S679>/Compare'
             *  Sum: '<S678>/Add'
             */
            if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
              /* Signum: '<S678>/Sign' */
              if (rtb_Saturation_ga < 0.0F) {
                rtb_Saturation1_d = -1.0F;
              } else if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              } else {
                rtb_Saturation1_d = rtb_Saturation_ga;
              }

              /* End of Signum: '<S678>/Sign' */
              rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
            }

            /* End of Switch: '<S678>/Switch' */

            /* Gain: '<S674>/Gain2' */
            rtb_Saturation_ga *= FMS_PARAM.YAW_P;

            /* Saturate: '<S674>/Saturation' */
            if (rtb_Saturation_ga > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Saturation_ga < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S674>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S661>/Saturation' */
            rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S661>/Saturation' */
            rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S661>/Saturation' */
            rtb_Saturation_ga = FMS_B.Merge_h;
          }

          /* End of Switch: '<S648>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S642>/Bus Assignment'
           *  Constant: '<S642>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S642>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_ga;

          /* Saturate: '<S682>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S682>/Saturation1' */

          /* Saturate: '<S650>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S642>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S650>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S676>/Rem' incorporates:
           *  Constant: '<S676>/Constant1'
           *  Delay: '<S663>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S663>/Sum2'
           */
          rtb_Saturation_ga = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S676>/Switch' incorporates:
           *  Abs: '<S676>/Abs'
           *  Constant: '<S676>/Constant'
           *  Constant: '<S681>/Constant'
           *  Product: '<S676>/Multiply'
           *  RelationalOperator: '<S681>/Compare'
           *  Sum: '<S676>/Add'
           */
          if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
            /* Signum: '<S676>/Sign' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_ga;
            }

            /* End of Signum: '<S676>/Sign' */
            rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S676>/Switch' */

          /* Sum: '<S663>/Sum' incorporates:
           *  Delay: '<S663>/Delay'
           */
          rtb_Saturation1_d = rtb_Saturation_ga + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S675>/Integrator' */
          if (rtb_Compare_o3 || (FMS_DW.Integrator_PrevResetState != 0)) {
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
          }

          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* Product: '<S680>/Multiply1' incorporates:
           *  Constant: '<S680>/const1'
           *  DiscreteIntegrator: '<S675>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S680>/Add' incorporates:
           *  DiscreteIntegrator: '<S675>/Integrator1'
           *  Sum: '<S675>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jz - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S680>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S680>/Sign' */

          /* Sum: '<S680>/Add2' incorporates:
           *  Abs: '<S680>/Abs'
           *  Gain: '<S680>/Gain'
           *  Gain: '<S680>/Gain1'
           *  Product: '<S680>/Multiply2'
           *  Product: '<S680>/Multiply3'
           *  Sqrt: '<S680>/Sqrt'
           *  Sum: '<S680>/Add1'
           *  Sum: '<S680>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_k) *
                           FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S680>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S680>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_k;

          /* Sum: '<S680>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_k;

          /* Signum: '<S680>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S680>/Sign1' */

          /* Signum: '<S680>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S680>/Sign2' */

          /* Sum: '<S680>/Add5' incorporates:
           *  Gain: '<S680>/Gain2'
           *  Product: '<S680>/Multiply4'
           *  Sum: '<S680>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S663>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S675>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S675>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)rtb_Compare_o3;

          /* Sum: '<S680>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_k;

          /* Sum: '<S680>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_k;

          /* Signum: '<S680>/Sign5' incorporates:
           *  Signum: '<S680>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S680>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S680>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S680>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S680>/Sign5' */

          /* Signum: '<S680>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S680>/Sign3' */

          /* Signum: '<S680>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S680>/Sign4' */

          /* Update for DiscreteIntegrator: '<S675>/Integrator' incorporates:
           *  Constant: '<S680>/const'
           *  Gain: '<S680>/Gain3'
           *  Product: '<S680>/Divide'
           *  Product: '<S680>/Multiply5'
           *  Product: '<S680>/Multiply6'
           *  Sum: '<S680>/Subtract4'
           *  Sum: '<S680>/Subtract5'
           *  Sum: '<S680>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hi += ((rtb_u_b / FMS_ConstB.d_k -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_a * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 0.785398185F) *
            0.004F;
          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          FMS_DW.Integrator_PrevResetState = (int8_T)rtb_Compare_o3;

          /* End of Update for DiscreteIntegrator: '<S675>/Integrator' */
          /* End of Outputs for SubSystem: '<S343>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S343>/Unknown' incorporates:
           *  ActionPort: '<S646>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S343>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
         *  ActionPort: '<S341>/Action Port'
         */
        /* SwitchCase: '<S341>/Switch Case' incorporates:
         *  Math: '<S525>/Math Function'
         *  Sum: '<S481>/Subtract'
         *  Sum: '<S538>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S452>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S503>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S493>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S452>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S341>/Offboard' incorporates:
           *  ActionPort: '<S453>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S619>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S622>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S623>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S623>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S623>/Multiply1' incorporates:
           *  Product: '<S623>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S623>/Divide' incorporates:
           *  Constant: '<S623>/Constant'
           *  Constant: '<S623>/R'
           *  Sqrt: '<S623>/Sqrt'
           *  Sum: '<S623>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S623>/Product3' incorporates:
           *  Constant: '<S623>/Constant1'
           *  Product: '<S623>/Multiply1'
           *  Sum: '<S623>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S623>/Multiply2' incorporates:
           *  Trigonometry: '<S623>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S622>/Sum' incorporates:
           *  Gain: '<S619>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S627>/Abs' incorporates:
           *  Abs: '<S630>/Abs1'
           *  Switch: '<S627>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S627>/Switch1' incorporates:
           *  Abs: '<S627>/Abs'
           *  Bias: '<S627>/Bias2'
           *  Bias: '<S627>/Bias3'
           *  Constant: '<S624>/Constant'
           *  Constant: '<S624>/Constant1'
           *  Constant: '<S629>/Constant'
           *  Gain: '<S627>/Gain1'
           *  Product: '<S627>/Multiply'
           *  RelationalOperator: '<S629>/Compare'
           *  Switch: '<S624>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S630>/Switch1' incorporates:
             *  Bias: '<S630>/Bias2'
             *  Bias: '<S630>/Bias3'
             *  Constant: '<S630>/Constant'
             *  Constant: '<S631>/Constant'
             *  Math: '<S630>/Math Function'
             *  RelationalOperator: '<S631>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S630>/Switch1' */

            /* Signum: '<S627>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S627>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S624>/Sum' incorporates:
           *  Gain: '<S619>/Gain1'
           *  Gain: '<S619>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S622>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S622>/Multiply' incorporates:
           *  Gain: '<S622>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S626>/Switch1' incorporates:
           *  Abs: '<S626>/Abs1'
           *  Bias: '<S626>/Bias2'
           *  Bias: '<S626>/Bias3'
           *  Constant: '<S626>/Constant'
           *  Constant: '<S628>/Constant'
           *  Math: '<S626>/Math Function'
           *  RelationalOperator: '<S628>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S626>/Switch1' */

          /* Product: '<S622>/Multiply' incorporates:
           *  Gain: '<S622>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S600>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S604>/Multiply1'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S613>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S613>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S613>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S613>/Gain' incorporates:
             *  Gain: '<S612>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S613>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S613>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S613>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S613>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S613>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S613>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S606>/Switch' incorporates:
             *  Constant: '<S621>/Constant'
             *  DataTypeConversion: '<S619>/Data Type Conversion1'
             *  Product: '<S625>/Multiply1'
             *  Product: '<S625>/Multiply2'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S618>/lat_cmd valid'
             *  Sum: '<S625>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o2 +
                                   rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S604>/Multiply' incorporates:
             *  Constant: '<S610>/Constant'
             *  Constant: '<S611>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S603>/Logical Operator'
             *  RelationalOperator: '<S610>/Compare'
             *  RelationalOperator: '<S611>/Compare'
             *  S-Function (sfix_bitop): '<S603>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/x_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S604>/Sum1'
             */
            d = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S613>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S606>/Switch' incorporates:
             *  Constant: '<S621>/Constant'
             *  DataTypeConversion: '<S619>/Data Type Conversion1'
             *  Product: '<S625>/Multiply3'
             *  Product: '<S625>/Multiply4'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S618>/lon_cmd valid'
             *  Sum: '<S625>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                   rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S604>/Multiply' incorporates:
             *  Constant: '<S610>/Constant'
             *  Constant: '<S611>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S603>/Logical Operator'
             *  RelationalOperator: '<S610>/Compare'
             *  RelationalOperator: '<S611>/Compare'
             *  S-Function (sfix_bitop): '<S603>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/y_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S604>/Sum1'
             */
            rtb_Integrator1_bx = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S613>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S606>/Switch' incorporates:
             *  Constant: '<S621>/Constant'
             *  DataTypeConversion: '<S619>/Data Type Conversion'
             *  DataTypeConversion: '<S619>/Data Type Conversion1'
             *  Gain: '<S619>/Gain2'
             *  Gain: '<S622>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S618>/alt_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S622>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_u_b = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                                    -FMS_U.INS_Out.alt_0);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S604>/Multiply' incorporates:
             *  Constant: '<S610>/Constant'
             *  Constant: '<S611>/Constant'
             *  Gain: '<S607>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S603>/Logical Operator'
             *  RelationalOperator: '<S610>/Compare'
             *  RelationalOperator: '<S611>/Compare'
             *  S-Function (sfix_bitop): '<S603>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/z_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S604>/Sum1'
             */
            rtb_Divide_lr_idx_3 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_u_b -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * rtb_Divide_lr_idx_3 + (rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d);
            }

            /* SignalConversion: '<S546>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S546>/Constant4'
             *  MultiPortSwitch: '<S535>/Index Vector'
             *  Product: '<S604>/Multiply1'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S546>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S546>/Gain' incorporates:
             *  Gain: '<S545>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S535>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S546>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S546>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S546>/Constant3'
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S546>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S546>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S546>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S535>/Multiply' incorporates:
             *  Constant: '<S544>/Constant'
             *  RelationalOperator: '<S544>/Compare'
             *  S-Function (sfix_bitop): '<S541>/ax_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ? FMS_U.Auto_Cmd.ax_cmd :
              0.0F;

            /* SignalConversion: '<S546>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S535>/Multiply' incorporates:
             *  Constant: '<S544>/Constant'
             *  RelationalOperator: '<S544>/Compare'
             *  S-Function (sfix_bitop): '<S541>/ay_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S546>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S535>/Multiply' incorporates:
             *  Constant: '<S544>/Constant'
             *  RelationalOperator: '<S544>/Compare'
             *  S-Function (sfix_bitop): '<S541>/az_cmd valid'
             */
            rtb_Divide_lr_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S535>/Index Vector' incorporates:
             *  Product: '<S542>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
                rtb_Divide_lr_idx_3 + (rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d);
            }
            break;

           case 1:
            /* SignalConversion: '<S616>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S616>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S616>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S605>/Data Store Read'
             *  Gain: '<S614>/Gain'
             *  Trigonometry: '<S616>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_or[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S616>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S605>/Data Store Read'
             *  Gain: '<S614>/Gain'
             *  Trigonometry: '<S616>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S616>/Gain' incorporates:
             *  Trigonometry: '<S616>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -rtb_u_b;

            /* SignalConversion: '<S616>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S616>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S616>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_u_b;

            /* Trigonometry: '<S616>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_o4;

            /* SignalConversion: '<S617>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S617>/Constant4'
             */
            rtb_MatrixConcatenate1[5] = 0.0F;

            /* Gain: '<S615>/Gain' incorporates:
             *  DataStoreRead: '<S605>/Data Store Read'
             *  Gain: '<S547>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S535>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S605>/Subtract'
             */
            rtb_Divide_lr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S617>/Trigonometric Function3' incorporates:
             *  Gain: '<S615>/Gain'
             *  Trigonometry: '<S617>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(rtb_Divide_lr_idx_2);
            rtb_MatrixConcatenate1[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S617>/Trigonometric Function2' incorporates:
             *  Gain: '<S615>/Gain'
             *  Trigonometry: '<S617>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(rtb_Divide_lr_idx_2);

            /* Gain: '<S617>/Gain' incorporates:
             *  Trigonometry: '<S617>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1[3] = -rtb_u_b;

            /* SignalConversion: '<S617>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S617>/Constant3'
             */
            rtb_MatrixConcatenate1[2] = 0.0F;

            /* Trigonometry: '<S617>/Trigonometric Function' */
            rtb_MatrixConcatenate1[1] = rtb_u_b;

            /* Trigonometry: '<S617>/Trigonometric Function1' */
            rtb_MatrixConcatenate1[0] = rtb_Saturation_o4;

            /* RelationalOperator: '<S621>/Compare' incorporates:
             *  Constant: '<S621>/Constant'
             *  S-Function (sfix_bitop): '<S618>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S618>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S618>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S619>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S619>/Data Type Conversion'
             *  Gain: '<S619>/Gain2'
             *  Gain: '<S622>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S625>/Multiply1'
             *  Product: '<S625>/Multiply2'
             *  Product: '<S625>/Multiply3'
             *  Product: '<S625>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S622>/Sum1'
             *  Sum: '<S625>/Sum2'
             *  Sum: '<S625>/Sum3'
             */
            rtb_MatrixConcatenate1_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S606>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S616>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S617>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S605>/Sum' incorporates:
             *  DataStoreRead: '<S605>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            d = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S616>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S617>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S605>/Sum' incorporates:
             *  DataStoreRead: '<S605>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Integrator1_bx = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S616>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S617>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S605>/Sum' incorporates:
             *  DataStoreRead: '<S605>/Data Store Read'
             *  Gain: '<S607>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_3 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S610>/Compare' incorporates:
             *  Constant: '<S610>/Constant'
             *  S-Function (sfix_bitop): '<S603>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S611>/Compare' incorporates:
             *  Constant: '<S611>/Constant'
             *  S-Function (sfix_bitop): '<S603>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S605>/Sum2' incorporates:
               *  Product: '<S605>/Multiply2'
               *  Switch: '<S606>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              /* Product: '<S605>/Multiply' incorporates:
               *  Logic: '<S603>/Logical Operator'
               *  Product: '<S605>/Multiply2'
               *  Sum: '<S605>/Sum'
               *  Sum: '<S605>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? rtb_u_b -
                ((rtb_VectorConcatenate_or[rtb_n + 3] * rtb_Integrator1_bx +
                  rtb_VectorConcatenate_or[rtb_n] * d) +
                 rtb_VectorConcatenate_or[rtb_n + 6] * rtb_Divide_lr_idx_3) :
                0.0F;
            }

            /* SignalConversion: '<S548>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S548>/Constant4'
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S548>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Divide_lr_idx_2);

            /* Gain: '<S548>/Gain' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             *  Trigonometry: '<S548>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Divide_lr_idx_2);

            /* SignalConversion: '<S548>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S548>/Constant3'
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S548>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Divide_lr_idx_2);

            /* Trigonometry: '<S548>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S535>/Index Vector'
             */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Divide_lr_idx_2);

            /* Product: '<S535>/Multiply' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S544>/Compare' incorporates:
             *  Constant: '<S544>/Constant'
             *  S-Function (sfix_bitop): '<S541>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S541>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S541>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S548>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S535>/Index Vector'
               */
              rtb_VectorConcatenate_or[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S535>/Multiply' */
              rtb_MatrixConcatenate1_0[rtb_n] = tmp[rtb_n] ? rtb_Switch_c2[rtb_n]
                : 0.0F;
              rtb_MatrixConcatenate3[rtb_n] = rtb_MatrixConcatenate1[rtb_n + 6] *
                rtb_Switch_ov[2] + (rtb_MatrixConcatenate1[rtb_n + 3] *
                                    rtb_Switch_ov[1] +
                                    rtb_MatrixConcatenate1[rtb_n] *
                                    rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S535>/Index Vector' incorporates:
             *  Product: '<S543>/Multiply3'
             *  Product: '<S605>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
                rtb_MatrixConcatenate1_0[2] + (rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_MatrixConcatenate1_0[1] +
                rtb_VectorConcatenate_or[rtb_n] * rtb_MatrixConcatenate1_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S609>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S609>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S609>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S609>/Gain' incorporates:
             *  Gain: '<S608>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S609>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S609>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S609>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S609>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S609>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* S-Function (sfix_bitop): '<S618>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S603>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S621>/Compare' incorporates:
             *  Constant: '<S621>/Constant'
             *  S-Function (sfix_bitop): '<S618>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S618>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S603>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S621>/Compare' incorporates:
             *  Constant: '<S621>/Constant'
             *  S-Function (sfix_bitop): '<S618>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S618>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S603>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S621>/Compare' incorporates:
             *  Constant: '<S621>/Constant'
             *  S-Function (sfix_bitop): '<S618>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S619>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S619>/Data Type Conversion'
             *  Gain: '<S619>/Gain2'
             *  Gain: '<S622>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S625>/Multiply1'
             *  Product: '<S625>/Multiply2'
             *  Product: '<S625>/Multiply3'
             *  Product: '<S625>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S622>/Sum1'
             *  Sum: '<S625>/Sum2'
             *  Sum: '<S625>/Sum3'
             */
            rtb_MatrixConcatenate1_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S606>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S609>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Sum: '<S602>/Sum' incorporates:
             *  DataStoreRead: '<S602>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation_o4 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S609>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Sum: '<S602>/Sum' incorporates:
             *  DataStoreRead: '<S602>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S609>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Sum: '<S602>/Sum' incorporates:
             *  DataStoreRead: '<S602>/Data Store Read'
             *  Gain: '<S607>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_3 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S610>/Compare' incorporates:
             *  Constant: '<S610>/Constant'
             *  S-Function (sfix_bitop): '<S603>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S603>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S611>/Compare' incorporates:
             *  Constant: '<S611>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S602>/Sum2' incorporates:
             *  Logic: '<S603>/Logical Operator'
             *  Product: '<S602>/Multiply'
             *  Product: '<S602>/Multiply2'
             *  Sum: '<S602>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S606>/Switch' incorporates:
               *  Product: '<S602>/Multiply2'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              rtb_MatrixConcatenate3[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_u_b - ((rtb_VectorConcatenate_or[rtb_n + 3] *
                            rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_or[rtb_n]
                            * rtb_Saturation_o4) +
                           rtb_VectorConcatenate_or[rtb_n + 6] *
                           rtb_Divide_lr_idx_3) : 0.0F;
            }

            /* End of Sum: '<S602>/Sum2' */

            /* MultiPortSwitch: '<S535>/Index Vector' incorporates:
             *  Constant: '<S544>/Constant'
             *  Product: '<S535>/Multiply'
             *  RelationalOperator: '<S544>/Compare'
             *  S-Function (sfix_bitop): '<S541>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S541>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S541>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* Sum: '<S596>/Sum1' incorporates:
           *  Constant: '<S596>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S596>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S597>/Abs' */
          rtb_Saturation_o4 = fabsf(rtb_a_bx);

          /* Switch: '<S597>/Switch' incorporates:
           *  Constant: '<S597>/Constant'
           *  Constant: '<S598>/Constant'
           *  Product: '<S597>/Multiply'
           *  RelationalOperator: '<S598>/Compare'
           *  Sum: '<S597>/Subtract'
           */
          if (rtb_Saturation_o4 > 3.14159274F) {
            /* Signum: '<S597>/Sign' */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* End of Signum: '<S597>/Sign' */
            rtb_a_bx *= rtb_Saturation_o4 - 6.28318548F;
          }

          /* End of Switch: '<S597>/Switch' */

          /* Saturate: '<S596>/Saturation' */
          if (rtb_a_bx > 0.314159274F) {
            rtb_a_bx = 0.314159274F;
          } else {
            if (rtb_a_bx < -0.314159274F) {
              rtb_a_bx = -0.314159274F;
            }
          }

          /* End of Saturate: '<S596>/Saturation' */

          /* Gain: '<S593>/Gain2' */
          rtb_a_bx *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S537>/Sum' incorporates:
           *  Constant: '<S595>/Constant'
           *  Constant: '<S599>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S593>/Multiply2'
           *  Product: '<S594>/Multiply1'
           *  RelationalOperator: '<S595>/Compare'
           *  RelationalOperator: '<S599>/Compare'
           *  S-Function (sfix_bitop): '<S593>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S594>/psi_rate_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_u_b = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_a_bx : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S600>/Gain1' */
          rtb_Saturation_o4 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

          /* Gain: '<S600>/Gain2' */
          rtb_a_bx = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S601>/Index Vector' incorporates:
           *  Constant: '<S637>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S601>/Multiply'
           *  Product: '<S634>/Multiply'
           *  Product: '<S635>/Multiply3'
           *  RelationalOperator: '<S637>/Compare'
           *  S-Function (sfix_bitop): '<S633>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S633>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S633>/w_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S639>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S639>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S639>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S639>/Gain' incorporates:
             *  Gain: '<S638>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S639>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S639>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S639>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S639>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S639>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S639>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S601>/Multiply' incorporates:
             *  Constant: '<S637>/Constant'
             *  RelationalOperator: '<S637>/Compare'
             *  S-Function (sfix_bitop): '<S633>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S639>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S601>/Multiply' incorporates:
             *  Constant: '<S637>/Constant'
             *  RelationalOperator: '<S637>/Compare'
             *  S-Function (sfix_bitop): '<S633>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S639>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S601>/Multiply' incorporates:
             *  Constant: '<S637>/Constant'
             *  RelationalOperator: '<S637>/Compare'
             *  S-Function (sfix_bitop): '<S633>/w_cmd valid'
             */
            rtb_Divide_lr_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * rtb_Divide_lr_idx_3 + (rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d);
            }
            break;

           case 1:
            /* SignalConversion: '<S641>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S641>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Gain: '<S640>/Gain' incorporates:
             *  DataStoreRead: '<S635>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S635>/Subtract'
             */
            rtb_Saturation_ga = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S641>/Trigonometric Function3' incorporates:
             *  Gain: '<S640>/Gain'
             */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Saturation_ga);

            /* Gain: '<S641>/Gain' incorporates:
             *  Gain: '<S640>/Gain'
             *  Trigonometry: '<S641>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S641>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S641>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S641>/Trigonometric Function' incorporates:
             *  Gain: '<S640>/Gain'
             */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Saturation_ga);

            /* Trigonometry: '<S641>/Trigonometric Function1' incorporates:
             *  Gain: '<S640>/Gain'
             */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S641>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gjo[0];

            /* Product: '<S601>/Multiply' incorporates:
             *  Constant: '<S637>/Constant'
             *  RelationalOperator: '<S637>/Compare'
             *  S-Function (sfix_bitop): '<S633>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S641>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gjo[1];

            /* Product: '<S601>/Multiply' incorporates:
             *  Constant: '<S637>/Constant'
             *  RelationalOperator: '<S637>/Compare'
             *  S-Function (sfix_bitop): '<S633>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S641>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gjo[2];

            /* Product: '<S601>/Multiply' incorporates:
             *  Constant: '<S637>/Constant'
             *  RelationalOperator: '<S637>/Compare'
             *  S-Function (sfix_bitop): '<S633>/w_cmd valid'
             */
            rtb_Divide_lr_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * rtb_Divide_lr_idx_3 + (rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d);
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

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MatrixConcatenate3[0] += rtb_Saturation_o4;
          rtb_MatrixConcatenate3[1] += rtb_Divide_lr_idx_2;

          /* Sum: '<S538>/Sum1' */
          rtb_Saturation_ga = rtb_a_bx + rtb_MatrixConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S556>/Switch' incorporates:
           *  Constant: '<S571>/Constant'
           *  Constant: '<S573>/Constant'
           *  Constant: '<S574>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S571>/Compare'
           *  RelationalOperator: '<S573>/Compare'
           *  RelationalOperator: '<S574>/Compare'
           *  S-Function (sfix_bitop): '<S556>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S556>/y_v_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S556>/Logical Operator' incorporates:
             *  Constant: '<S572>/Constant'
             *  Constant: '<S573>/Constant'
             *  Constant: '<S574>/Constant'
             *  RelationalOperator: '<S572>/Compare'
             *  RelationalOperator: '<S573>/Compare'
             *  RelationalOperator: '<S574>/Compare'
             *  S-Function (sfix_bitop): '<S556>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S556>/y_v_cmd'
             */
            rtb_Compare_aij = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
                               ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
                               ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_Compare_o3 = rtb_Compare_aij;
          } else {
            rtb_Compare_aij = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_Compare_o3 = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U);
          }

          /* End of Switch: '<S556>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S536>/u_cmd_valid' */
          /* MATLAB Function: '<S568>/bit_shift' incorporates:
           *  DataTypeConversion: '<S536>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_aij << 6);

          /* End of Outputs for SubSystem: '<S536>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S536>/v_cmd_valid' */
          /* MATLAB Function: '<S569>/bit_shift' incorporates:
           *  DataTypeConversion: '<S536>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_Compare_o3 << 7);

          /* End of Outputs for SubSystem: '<S536>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S557>/Switch' incorporates:
           *  Constant: '<S576>/Constant'
           *  Constant: '<S577>/Constant'
           *  Constant: '<S579>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S576>/Compare'
           *  RelationalOperator: '<S577>/Compare'
           *  RelationalOperator: '<S579>/Compare'
           *  S-Function (sfix_bitop): '<S557>/ax_cmd'
           *  S-Function (sfix_bitop): '<S557>/ay_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S557>/Logical Operator' incorporates:
             *  Constant: '<S577>/Constant'
             *  Constant: '<S579>/Constant'
             *  RelationalOperator: '<S577>/Compare'
             *  RelationalOperator: '<S579>/Compare'
             *  S-Function (sfix_bitop): '<S557>/ax_cmd'
             *  S-Function (sfix_bitop): '<S557>/ay_cmd'
             */
            rtb_Compare_aij = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                               ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_Compare_o3 = rtb_Compare_aij;
          } else {
            rtb_Compare_aij = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_Compare_o3 = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
          }

          /* End of Switch: '<S557>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S453>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S453>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S453>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Inport: '<Root>/Auto_Cmd'
           *  Outport: '<Root>/FMS_Out'
           *  SignalConversion: '<S43>/Signal Copy'
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
          FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.az_cmd = rtb_Switch_ov[2];

          /* Saturate: '<S537>/Saturation' */
          if (rtb_u_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_u_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S537>/Saturation' */

          /* Saturate: '<S538>/Saturation2' */
          if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
          }

          /* End of Saturate: '<S538>/Saturation2' */

          /* Saturate: '<S538>/Saturation1' */
          if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
          }

          /* End of Saturate: '<S538>/Saturation1' */

          /* Saturate: '<S538>/Saturation3' */
          if (rtb_Saturation_ga > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_ga < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S453>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;
          }

          /* End of Saturate: '<S538>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S536>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S536>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S536>/throttle_cmd_valid' */
          /* BusAssignment: '<S453>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S549>/Constant'
           *  Constant: '<S550>/Constant'
           *  Constant: '<S551>/Constant'
           *  Constant: '<S552>/Constant'
           *  Constant: '<S553>/Constant'
           *  Constant: '<S554>/Constant'
           *  Constant: '<S555>/Constant'
           *  Constant: '<S575>/Constant'
           *  Constant: '<S578>/Constant'
           *  DataTypeConversion: '<S536>/Data Type Conversion10'
           *  DataTypeConversion: '<S536>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S558>/bit_shift'
           *  MATLAB Function: '<S559>/bit_shift'
           *  MATLAB Function: '<S560>/bit_shift'
           *  MATLAB Function: '<S562>/bit_shift'
           *  MATLAB Function: '<S563>/bit_shift'
           *  MATLAB Function: '<S564>/bit_shift'
           *  MATLAB Function: '<S565>/bit_shift'
           *  MATLAB Function: '<S566>/bit_shift'
           *  MATLAB Function: '<S567>/bit_shift'
           *  MATLAB Function: '<S570>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S549>/Compare'
           *  RelationalOperator: '<S550>/Compare'
           *  RelationalOperator: '<S551>/Compare'
           *  RelationalOperator: '<S552>/Compare'
           *  RelationalOperator: '<S553>/Compare'
           *  RelationalOperator: '<S554>/Compare'
           *  RelationalOperator: '<S555>/Compare'
           *  RelationalOperator: '<S575>/Compare'
           *  RelationalOperator: '<S578>/Compare'
           *  S-Function (sfix_bitop): '<S536>/p_cmd'
           *  S-Function (sfix_bitop): '<S536>/phi_cmd'
           *  S-Function (sfix_bitop): '<S536>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S536>/q_cmd'
           *  S-Function (sfix_bitop): '<S536>/r_cmd'
           *  S-Function (sfix_bitop): '<S536>/theta_cmd'
           *  S-Function (sfix_bitop): '<S536>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S556>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S557>/az_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           *  Sum: '<S536>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_aw) +
            rtb_y_cc) + (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
            (rtb_Compare_aij << 9)) + (rtb_Compare_o3 << 10)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S536>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S536>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S536>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S341>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S341>/Mission' incorporates:
             *  ActionPort: '<S452>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S341>/Switch Case' incorporates:
             *  UnitDelay: '<S455>/Delay Input1'
             *
             * Block description for '<S455>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S341>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S341>/Mission' incorporates:
             *  ActionPort: '<S452>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S452>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S341>/Switch Case' incorporates:
             *  Chart: '<S494>/Motion Status'
             *  Chart: '<S504>/Motion State'
             *  Delay: '<S460>/Delay'
             *  Delay: '<S482>/Delay'
             *  DiscreteIntegrator: '<S463>/Integrator'
             *  DiscreteIntegrator: '<S463>/Integrator1'
             *  DiscreteIntegrator: '<S478>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S483>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S530>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.icLoad_m = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);

            /* End of SystemReset for SubSystem: '<S452>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S341>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S341>/Mission' incorporates:
           *  ActionPort: '<S452>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S455>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S455>/Delay Input1'
           *
           * Block description for '<S455>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S452>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S456>/Reset'
           */
          if (rtb_Compare_o3 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
                                 POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S503>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S493>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S482>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S478>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S530>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S460>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S463>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S463>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S504>/Motion State' */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S494>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Compare_o3;

          /* Delay: '<S482>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_o[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_o[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S478>/Switch2' incorporates:
           *  Constant: '<S478>/vel'
           *  Constant: '<S487>/Constant'
           *  RelationalOperator: '<S487>/Compare'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S478>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S483>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S455>/Delay Input1'
           *
           * Block description for '<S455>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S477>/Compare' incorporates:
           *  Constant: '<S534>/Constant'
           *  RelationalOperator: '<S534>/Compare'
           *  UnitDelay: '<S455>/Delay Input1'
           *
           * Block description for '<S455>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S478>/Acceleration_Speed' */
          if (rtb_Compare_o3 || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S504>/Motion State' incorporates:
           *  Constant: '<S504>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S504>/Square'
           *  Math: '<S504>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S504>/Sqrt'
           *  Sum: '<S504>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S503>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S513>/Integrator1'
           *  Gain: '<S507>/Gain6'
           *  Gain: '<S511>/Gain'
           *  Gain: '<S512>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S513>/Subtract'
           *  Sum: '<S514>/Add'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_fg;
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S503>/Hold Control' incorporates:
               *  ActionPort: '<S506>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S503>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S503>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S503>/Hold Control' incorporates:
             *  ActionPort: '<S506>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S503>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S503>/Brake Control' incorporates:
             *  ActionPort: '<S505>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S503>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S503>/Move Control' incorporates:
               *  ActionPort: '<S507>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S503>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S513>/Integrator'
               *  DiscreteIntegrator: '<S513>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S503>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S503>/Move Control' incorporates:
             *  ActionPort: '<S507>/Action Port'
             */
            /* SignalConversion: '<S507>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S514>/Multiply1' incorporates:
             *  Constant: '<S514>/const1'
             *  DiscreteIntegrator: '<S513>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S507>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S514>/Multiply1' incorporates:
             *  Constant: '<S514>/const1'
             *  DiscreteIntegrator: '<S513>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S511>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S514>/Add' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator1'
             *  Gain: '<S507>/Gain6'
             *  Gain: '<S511>/Gain'
             *  Sum: '<S513>/Subtract'
             */
            rtb_Divide_c14[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S512>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S514>/Add' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator1'
             *  Gain: '<S507>/Gain6'
             *  Gain: '<S512>/Gain'
             *  Sum: '<S513>/Subtract'
             */
            rtb_Divide_c14[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S511>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Signum: '<S514>/Sign' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator1'
             *  Gain: '<S507>/Gain6'
             *  Gain: '<S511>/Gain'
             *  Sum: '<S513>/Subtract'
             *  Sum: '<S514>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S514>/Add2' incorporates:
             *  Abs: '<S514>/Abs'
             *  Gain: '<S514>/Gain'
             *  Gain: '<S514>/Gain1'
             *  Product: '<S514>/Multiply2'
             *  Product: '<S514>/Multiply3'
             *  Signum: '<S514>/Sign'
             *  Sqrt: '<S514>/Sqrt'
             *  Sum: '<S514>/Add1'
             *  Sum: '<S514>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Divide_c14[0]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_Saturation1_d + rtb_Subtract_hb[0];

            /* Sum: '<S514>/Add3' incorporates:
             *  Signum: '<S514>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_c14[0] + FMS_ConstB.d_oe;

            /* Sum: '<S514>/Subtract1' incorporates:
             *  Signum: '<S514>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_c14[0] - FMS_ConstB.d_oe;

            /* Signum: '<S514>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S514>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S514>/Add5' incorporates:
             *  Gain: '<S514>/Gain2'
             *  Product: '<S514>/Multiply4'
             *  Signum: '<S514>/Sign'
             *  Sum: '<S514>/Add2'
             *  Sum: '<S514>/Add4'
             *  Sum: '<S514>/Subtract2'
             */
            rtb_Divide_lr_idx_3 += ((rtb_Divide_c14[0] - rtb_Divide_lr_idx_3) +
              rtb_Subtract_hb[0]) * ((rtb_Saturation_ga - rtb_Saturation1_d) *
              0.5F);

            /* Update for DiscreteIntegrator: '<S513>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S514>/Sign4' incorporates:
             *  Sum: '<S514>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 - FMS_ConstB.d_oe;

            /* Signum: '<S514>/Sign3' incorporates:
             *  Sum: '<S514>/Add6'
             */
            rtb_Saturation1_d = rtb_Divide_lr_idx_3 + FMS_ConstB.d_oe;

            /* Signum: '<S514>/Sign5' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Divide_lr_idx_3;
            }

            /* Signum: '<S514>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S514>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S514>/Sign6' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Divide_lr_idx_3;
            }

            /* Update for DiscreteIntegrator: '<S513>/Integrator' incorporates:
             *  Constant: '<S514>/const'
             *  Gain: '<S514>/Gain3'
             *  Product: '<S514>/Divide'
             *  Product: '<S514>/Multiply5'
             *  Product: '<S514>/Multiply6'
             *  Sum: '<S514>/Subtract4'
             *  Sum: '<S514>/Subtract5'
             *  Sum: '<S514>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Divide_lr_idx_3 /
              FMS_ConstB.d_oe - rtb_Saturation_o4) * FMS_ConstB.Gain4_g *
              ((rtb_Saturation1_d - rtb_Saturation_ga) * 0.5F) - rtb_u_b *
              58.836F) * 0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S512>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Signum: '<S514>/Sign' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator1'
             *  Gain: '<S507>/Gain6'
             *  Gain: '<S512>/Gain'
             *  Sum: '<S513>/Subtract'
             *  Sum: '<S514>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S514>/Add2' incorporates:
             *  Abs: '<S514>/Abs'
             *  Gain: '<S514>/Gain'
             *  Gain: '<S514>/Gain1'
             *  Product: '<S514>/Multiply2'
             *  Product: '<S514>/Multiply3'
             *  Signum: '<S514>/Sign'
             *  Sqrt: '<S514>/Sqrt'
             *  Sum: '<S514>/Add1'
             *  Sum: '<S514>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Divide_c14[1]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_Saturation1_d + rtb_Subtract_hb[1];

            /* Sum: '<S514>/Add3' incorporates:
             *  Signum: '<S514>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_c14[1] + FMS_ConstB.d_oe;

            /* Sum: '<S514>/Subtract1' incorporates:
             *  Signum: '<S514>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_c14[1] - FMS_ConstB.d_oe;

            /* Signum: '<S514>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S514>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S514>/Add5' incorporates:
             *  Gain: '<S514>/Gain2'
             *  Product: '<S514>/Multiply4'
             *  Signum: '<S514>/Sign'
             *  Sum: '<S514>/Add2'
             *  Sum: '<S514>/Add4'
             *  Sum: '<S514>/Subtract2'
             */
            rtb_Divide_lr_idx_3 += ((rtb_Divide_c14[1] - rtb_Divide_lr_idx_3) +
              rtb_Subtract_hb[1]) * ((rtb_Saturation_ga - rtb_Saturation1_d) *
              0.5F);

            /* Update for DiscreteIntegrator: '<S513>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S513>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S514>/Sign4' incorporates:
             *  Sum: '<S514>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 - FMS_ConstB.d_oe;

            /* Signum: '<S514>/Sign3' incorporates:
             *  Sum: '<S514>/Add6'
             */
            rtb_Saturation1_d = rtb_Divide_lr_idx_3 + FMS_ConstB.d_oe;

            /* Signum: '<S514>/Sign5' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Divide_lr_idx_3;
            }

            /* Signum: '<S514>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S514>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S514>/Sign6' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Divide_lr_idx_3;
            }

            /* Update for DiscreteIntegrator: '<S513>/Integrator' incorporates:
             *  Constant: '<S514>/const'
             *  Gain: '<S514>/Gain3'
             *  Product: '<S514>/Divide'
             *  Product: '<S514>/Multiply5'
             *  Product: '<S514>/Multiply6'
             *  Sum: '<S514>/Subtract4'
             *  Sum: '<S514>/Subtract5'
             *  Sum: '<S514>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Divide_lr_idx_3 /
              FMS_ConstB.d_oe - rtb_Saturation_o4) * FMS_ConstB.Gain4_g *
              ((rtb_Saturation1_d - rtb_Saturation_ga) * 0.5F) - rtb_u_b *
              58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S503>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S503>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S494>/Motion Status' incorporates:
           *  Abs: '<S494>/Abs'
           *  Constant: '<S494>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S493>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S493>/Hold Control' incorporates:
               *  ActionPort: '<S496>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S493>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S493>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S493>/Hold Control' incorporates:
             *  ActionPort: '<S496>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S493>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S493>/Brake Control' incorporates:
             *  ActionPort: '<S495>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S493>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S493>/Move Control' incorporates:
               *  ActionPort: '<S497>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S493>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S500>/Integrator'
               *  DiscreteIntegrator: '<S500>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S493>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S493>/Move Control' incorporates:
             *  ActionPort: '<S497>/Action Port'
             */
            /* Product: '<S501>/Multiply1' incorporates:
             *  Constant: '<S501>/const1'
             *  DiscreteIntegrator: '<S500>/Integrator'
             */
            rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S499>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ)
            {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle - (-FMS_PARAM.THROTTLE_DZ);
            }

            /* End of DeadZone: '<S499>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S501>/Add' incorporates:
             *  DiscreteIntegrator: '<S500>/Integrator1'
             *  Gain: '<S497>/Gain1'
             *  Gain: '<S499>/Gain'
             *  Sum: '<S500>/Subtract'
             */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_u_b * -FMS_PARAM.VEL_Z_LIM) +
              rtb_Saturation_ga;

            /* Signum: '<S501>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Saturation1_d;
            }

            /* End of Signum: '<S501>/Sign' */

            /* Sum: '<S501>/Add2' incorporates:
             *  Abs: '<S501>/Abs'
             *  Gain: '<S501>/Gain'
             *  Gain: '<S501>/Gain1'
             *  Product: '<S501>/Multiply2'
             *  Product: '<S501>/Multiply3'
             *  Sqrt: '<S501>/Sqrt'
             *  Sum: '<S501>/Add1'
             *  Sum: '<S501>/Subtract'
             */
            rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_oc)
                             * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_o4 + rtb_Saturation_ga;

            /* Sum: '<S501>/Add4' */
            rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) +
              rtb_Saturation_ga;

            /* Sum: '<S501>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_oc;

            /* Sum: '<S501>/Subtract1' */
            rtb_Saturation1_d -= FMS_ConstB.d_oc;

            /* Signum: '<S501>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S501>/Sign1' */

            /* Signum: '<S501>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S501>/Sign2' */

            /* Sum: '<S501>/Add5' incorporates:
             *  Gain: '<S501>/Gain2'
             *  Product: '<S501>/Multiply4'
             *  Sum: '<S501>/Subtract2'
             */
            rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
              rtb_Saturation_o4;

            /* SignalConversion: '<S497>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S500>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S500>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S500>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S501>/Subtract3' */
            rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_oc;

            /* Sum: '<S501>/Add6' */
            rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_oc;

            /* Signum: '<S501>/Sign5' incorporates:
             *  Signum: '<S501>/Sign6'
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_o4 = -1.0F;

              /* Signum: '<S501>/Sign6' */
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Saturation_o4 = 1.0F;

              /* Signum: '<S501>/Sign6' */
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_u_b;

              /* Signum: '<S501>/Sign6' */
              rtb_Divide_lr_idx_3 = rtb_u_b;
            }

            /* End of Signum: '<S501>/Sign5' */

            /* Signum: '<S501>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S501>/Sign3' */

            /* Signum: '<S501>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S501>/Sign4' */

            /* Update for DiscreteIntegrator: '<S500>/Integrator' incorporates:
             *  Constant: '<S501>/const'
             *  Gain: '<S501>/Gain3'
             *  Product: '<S501>/Divide'
             *  Product: '<S501>/Multiply5'
             *  Product: '<S501>/Multiply6'
             *  Sum: '<S501>/Subtract4'
             *  Sum: '<S501>/Subtract5'
             *  Sum: '<S501>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_u_b / FMS_ConstB.d_oc -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_j * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 78.448F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S493>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S493>/Switch Case' */

          /* Switch: '<S458>/Switch' incorporates:
           *  Product: '<S482>/Multiply'
           *  Sum: '<S482>/Sum'
           */
          if (rtb_Compare_o3) {
            /* Saturate: '<S503>/Saturation1' */
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

            /* End of Saturate: '<S503>/Saturation1' */

            /* Saturate: '<S493>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S493>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S482>/Sum' incorporates:
             *  Delay: '<S482>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S531>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S478>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S482>/Sum' incorporates:
             *  Delay: '<S482>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S478>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S490>/Sqrt' incorporates:
             *  Math: '<S490>/Square'
             *  Sum: '<S478>/Sum'
             *  Sum: '<S490>/Sum of Elements'
             */
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S533>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S533>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S533>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S532>/Gain' incorporates:
             *  DiscreteIntegrator: '<S530>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S530>/Add'
             */
            rtb_u_b = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S533>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_u_b);

            /* Gain: '<S533>/Gain' incorporates:
             *  Trigonometry: '<S533>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_u_b);

            /* SignalConversion: '<S533>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S533>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S533>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_u_b);

            /* Trigonometry: '<S533>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_u_b);

            /* Switch: '<S489>/Switch2' incorporates:
             *  Constant: '<S478>/Constant2'
             *  DiscreteIntegrator: '<S478>/Acceleration_Speed'
             *  RelationalOperator: '<S489>/LowerRelop1'
             *  RelationalOperator: '<S489>/UpperRelop'
             *  Switch: '<S489>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_u_b = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S489>/Switch' incorporates:
               *  Constant: '<S478>/Constant2'
               */
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S489>/Switch2' */

            /* Switch: '<S478>/Switch' */
            if (rtb_Saturation_ga > FMS_PARAM.L1) {
              rtb_Saturation1_d = d;
            } else {
              /* Gain: '<S478>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_Saturation_ga;

              /* Switch: '<S488>/Switch2' incorporates:
               *  Constant: '<S478>/Constant1'
               *  RelationalOperator: '<S488>/LowerRelop1'
               *  RelationalOperator: '<S488>/UpperRelop'
               *  Switch: '<S488>/Switch'
               */
              if (rtb_Saturation1_d > d) {
                rtb_Saturation1_d = d;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  /* Switch: '<S488>/Switch' incorporates:
                   *  Constant: '<S478>/Constant1'
                   */
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Switch: '<S488>/Switch2' */
            }

            /* End of Switch: '<S478>/Switch' */

            /* Switch: '<S478>/Switch1' incorporates:
             *  Sum: '<S478>/Sum1'
             */
            if (rtb_u_b - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = rtb_u_b;
            }

            /* End of Switch: '<S478>/Switch1' */

            /* Sum: '<S531>/Sum of Elements' incorporates:
             *  Math: '<S531>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Saturation_o4 *
              rtb_Saturation_o4;

            /* Math: '<S531>/Math Function1' incorporates:
             *  Sum: '<S531>/Sum of Elements'
             *
             * About '<S531>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_u_b = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_u_b = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S531>/Math Function1' */

            /* Switch: '<S531>/Switch' incorporates:
             *  Constant: '<S531>/Constant'
             *  Product: '<S531>/Product'
             */
            if (rtb_u_b > 0.0F) {
              rtb_Divide_p3p[0] = rtb_Subtract_hb[0];
              rtb_Divide_p3p[1] = rtb_Saturation_o4;
              rtb_Divide_p3p[3] = rtb_u_b;
            } else {
              rtb_Divide_p3p[0] = 0.0F;
              rtb_Divide_p3p[1] = 0.0F;
              rtb_Divide_p3p[3] = 1.0F;
            }

            /* End of Switch: '<S531>/Switch' */

            /* Product: '<S529>/Multiply2' incorporates:
             *  Product: '<S531>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_p3p[0] / rtb_Divide_p3p[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_p3p[1] / rtb_Divide_p3p[3];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S484>/Sum1' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_u_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S484>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_3 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
              [0];
            rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S484>/Divide' incorporates:
             *  Math: '<S485>/Square'
             *  Math: '<S486>/Square'
             *  Sqrt: '<S485>/Sqrt'
             *  Sqrt: '<S486>/Sqrt'
             *  Sum: '<S484>/Sum'
             *  Sum: '<S484>/Sum1'
             *  Sum: '<S485>/Sum of Elements'
             *  Sum: '<S486>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_a_bx
                            * rtb_a_bx) / sqrtf(rtb_Saturation_o4 *
              rtb_Saturation_o4 + rtb_u_b * rtb_u_b);

            /* Saturate: '<S484>/Saturation' */
            if (rtb_u_b > 1.0F) {
              rtb_u_b = 1.0F;
            } else {
              if (rtb_u_b < 0.0F) {
                rtb_u_b = 0.0F;
              }
            }

            /* End of Saturate: '<S484>/Saturation' */

            /* Product: '<S482>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_Saturation1_d + rtb_VectorConcatenate_or[rtb_n] *
                rtb_Saturation_ga;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S475>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S484>/Multiply'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S475>/Sum2'
             *  Sum: '<S484>/Add'
             *  Sum: '<S484>/Subtract'
             */
            rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_b +
                        FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_MatrixConcatenate1_0[0];
            rtb_Switch_c2[1] = rtb_MatrixConcatenate1_0[1];

            /* Saturate: '<S475>/Saturation1' incorporates:
             *  Product: '<S482>/Multiply'
             */
            if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_u_b;
            }

            /* End of Saturate: '<S475>/Saturation1' */
          }

          /* End of Switch: '<S458>/Switch' */

          /* Delay: '<S460>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S463>/Integrator1' incorporates:
           *  Delay: '<S460>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S467>/Rem' incorporates:
           *  Constant: '<S467>/Constant1'
           *  DiscreteIntegrator: '<S463>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S462>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S467>/Switch' incorporates:
           *  Abs: '<S467>/Abs'
           *  Constant: '<S467>/Constant'
           *  Constant: '<S468>/Constant'
           *  Product: '<S467>/Multiply'
           *  RelationalOperator: '<S468>/Compare'
           *  Sum: '<S467>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S467>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S467>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S467>/Switch' */

          /* Gain: '<S462>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S462>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S462>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S456>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S456>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S456>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_o4;

          /* Math: '<S524>/Math Function1'
           *
           * About '<S524>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S524>/Math Function1' */

          /* Switch: '<S524>/Switch' incorporates:
           *  Constant: '<S524>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S524>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S524>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S456>/Sum' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_c14[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_c14[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S474>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S456>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S474>/Math Function' incorporates:
           *  Sum: '<S456>/Sum'
           */
          rtb_Square_ds[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_ds[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S474>/Sum of Elements' */
          rtb_u_b = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S474>/Math Function1' incorporates:
           *  Sum: '<S474>/Sum of Elements'
           *
           * About '<S474>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S474>/Math Function1' */

          /* Switch: '<S474>/Switch' incorporates:
           *  Constant: '<S474>/Constant'
           *  Product: '<S474>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Integrator1_bx = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S474>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S480>/NearbyRefWP' incorporates:
           *  Constant: '<S456>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_c14,
                          &rtb_u_b);

          /* MATLAB Function: '<S480>/SearchL1RefWP' incorporates:
           *  Constant: '<S456>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S480>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S480>/Switch1' incorporates:
           *  Constant: '<S517>/Constant'
           *  RelationalOperator: '<S517>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_c14[0];
            rtb_P_ap[1] = rtb_Divide_c14[1];
          } else {
            /* RelationalOperator: '<S516>/Compare' incorporates:
             *  Constant: '<S516>/Constant'
             */
            rtb_Compare_aij = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S480>/Switch' */
            if (!rtb_Compare_aij) {
              rtb_P_ap[0] = rtb_Square_ds[0];
              rtb_P_ap[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S480>/Switch' */
          }

          /* End of Switch: '<S480>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S481>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Divide_lr_idx_3;
          rtb_Saturation_o4 = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S481>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S525>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S525>/Sum of Elements' incorporates:
           *  Math: '<S525>/Math Function'
           *  Sum: '<S523>/Sum of Elements'
           */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3 *
            rtb_Divide_lr_idx_3;

          /* Math: '<S525>/Math Function1' incorporates:
           *  Sum: '<S525>/Sum of Elements'
           *
           * About '<S525>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S525>/Math Function1' */

          /* Switch: '<S525>/Switch' incorporates:
           *  Constant: '<S525>/Constant'
           *  Product: '<S525>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_P_ap[0];
            rtb_MatrixConcatenate3[1] = rtb_Divide_lr_idx_3;
            rtb_MatrixConcatenate3[2] = rtb_Saturation_o4;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S525>/Switch' */

          /* Product: '<S524>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S527>/Sum of Elements' incorporates:
           *  Math: '<S527>/Math Function'
           *  SignalConversion: '<S527>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S527>/Math Function1' incorporates:
           *  Sum: '<S527>/Sum of Elements'
           *
           * About '<S527>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S527>/Math Function1' */

          /* Switch: '<S527>/Switch' incorporates:
           *  Constant: '<S527>/Constant'
           *  Product: '<S527>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_c14[1];
            rtb_Switch_c2[1] = rtb_Divide_c14[0];
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S527>/Switch' */

          /* Product: '<S525>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S528>/Sum of Elements' incorporates:
           *  Math: '<S528>/Math Function'
           *  SignalConversion: '<S528>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S528>/Math Function1' incorporates:
           *  Sum: '<S528>/Sum of Elements'
           *
           * About '<S528>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S528>/Math Function1' */

          /* Switch: '<S528>/Switch' incorporates:
           *  Constant: '<S528>/Constant'
           *  Product: '<S528>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Divide_c14[1];
            rtb_MatrixConcatenate3[1] = rtb_Divide_c14[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_o4;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S528>/Switch' */

          /* Product: '<S528>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S527>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S474>/Divide' */
          rtb_Square_ds[0] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S528>/Divide' */
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S527>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S474>/Divide' */
          rtb_Square_ds[1] = rtb_Saturation1_d / rtb_Integrator1_bx;

          /* Sum: '<S526>/Subtract' incorporates:
           *  Product: '<S526>/Multiply'
           *  Product: '<S526>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_c14[0] * rtb_P_ap[1] - rtb_Divide_c14[1]
            * rtb_P_ap[0];

          /* Signum: '<S521>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S521>/Sign1' */

          /* Switch: '<S521>/Switch2' incorporates:
           *  Constant: '<S521>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S521>/Switch2' */

          /* DotProduct: '<S521>/Dot Product' */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] * rtb_Divide_c14[0] + rtb_P_ap[1] *
            rtb_Divide_c14[1];

          /* Trigonometry: '<S521>/Acos' incorporates:
           *  DotProduct: '<S521>/Dot Product'
           */
          if (rtb_Divide_lr_idx_3 > 1.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 < -1.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            }
          }

          /* Product: '<S521>/Multiply' incorporates:
           *  Trigonometry: '<S521>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Divide_lr_idx_3);

          /* Saturate: '<S481>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S481>/Saturation' */

          /* Product: '<S481>/Divide' incorporates:
           *  Constant: '<S456>/L1'
           *  Constant: '<S481>/Constant'
           *  Gain: '<S481>/Gain'
           *  Math: '<S481>/Square'
           *  MinMax: '<S481>/Max'
           *  MinMax: '<S481>/Min'
           *  Product: '<S481>/Multiply1'
           *  Sqrt: '<S523>/Sqrt'
           *  Trigonometry: '<S481>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S472>/Subtract' incorporates:
           *  Product: '<S472>/Multiply'
           *  Product: '<S472>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S461>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S461>/Sign1' */

          /* Switch: '<S461>/Switch2' incorporates:
           *  Constant: '<S461>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S461>/Switch2' */

          /* DotProduct: '<S461>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide[0] * rtb_Square_ds[0] + FMS_ConstB.Divide
            [1] * rtb_Square_ds[1];

          /* Trigonometry: '<S461>/Acos' incorporates:
           *  DotProduct: '<S461>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S461>/Multiply' incorporates:
           *  Trigonometry: '<S461>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_u_b);

          /* Math: '<S464>/Rem' incorporates:
           *  Constant: '<S464>/Constant1'
           *  Delay: '<S460>/Delay'
           *  Sum: '<S460>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S464>/Switch' incorporates:
           *  Abs: '<S464>/Abs'
           *  Constant: '<S464>/Constant'
           *  Constant: '<S470>/Constant'
           *  Product: '<S464>/Multiply'
           *  RelationalOperator: '<S470>/Compare'
           *  Sum: '<S464>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S464>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S464>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S464>/Switch' */

          /* Sum: '<S460>/Sum' incorporates:
           *  Delay: '<S460>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S469>/Multiply1' incorporates:
           *  Constant: '<S469>/const1'
           *  DiscreteIntegrator: '<S463>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S469>/Add' incorporates:
           *  DiscreteIntegrator: '<S463>/Integrator1'
           *  Sum: '<S463>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S469>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S469>/Sign' */

          /* Sum: '<S469>/Add2' incorporates:
           *  Abs: '<S469>/Abs'
           *  Gain: '<S469>/Gain'
           *  Gain: '<S469>/Gain1'
           *  Product: '<S469>/Multiply2'
           *  Product: '<S469>/Multiply3'
           *  Sqrt: '<S469>/Sqrt'
           *  Sum: '<S469>/Add1'
           *  Sum: '<S469>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_m) *
                           FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S469>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S469>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_m;

          /* Sum: '<S469>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_m;

          /* Signum: '<S469>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S469>/Sign1' */

          /* Signum: '<S469>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S469>/Sign2' */

          /* Sum: '<S469>/Add5' incorporates:
           *  Gain: '<S469>/Gain2'
           *  Product: '<S469>/Multiply4'
           *  Sum: '<S469>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S469>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_m;

          /* Sum: '<S469>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_m;

          /* Product: '<S469>/Divide' */
          rtb_Integrator1_bx = rtb_u_b / FMS_ConstB.d_m;

          /* Signum: '<S469>/Sign5' incorporates:
           *  Signum: '<S469>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_a_bx = -1.0F;

            /* Signum: '<S469>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_a_bx = 1.0F;

            /* Signum: '<S469>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_a_bx = rtb_u_b;

            /* Signum: '<S469>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S469>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S460>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S465>/Rem' incorporates:
           *  Constant: '<S465>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S465>/Switch' incorporates:
           *  Abs: '<S465>/Abs'
           *  Constant: '<S465>/Constant'
           *  Constant: '<S471>/Constant'
           *  Product: '<S465>/Multiply'
           *  RelationalOperator: '<S471>/Compare'
           *  Sum: '<S465>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S465>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_u_b;
            }

            /* End of Signum: '<S465>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S465>/Switch' */

          /* Abs: '<S458>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S482>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S476>/Constant'
           *  RelationalOperator: '<S476>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(rtb_u_b <=
            0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S478>/Acceleration_Speed' incorporates:
           *  Constant: '<S478>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_o3;

          /* Product: '<S482>/Divide1' */
          rtb_u_b = rtb_Divide_lr_idx_2 / d;

          /* Saturate: '<S482>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S482>/Saturation' */

          /* Update for DiscreteIntegrator: '<S530>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_u_b;

          /* Update for Delay: '<S460>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S463>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S463>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S469>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S469>/Sign3' */

          /* Signum: '<S469>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S469>/Sign4' */

          /* Update for DiscreteIntegrator: '<S463>/Integrator' incorporates:
           *  Constant: '<S469>/const'
           *  Gain: '<S469>/Gain3'
           *  Product: '<S469>/Multiply5'
           *  Product: '<S469>/Multiply6'
           *  Sum: '<S469>/Subtract4'
           *  Sum: '<S469>/Subtract5'
           *  Sum: '<S469>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Integrator1_bx - rtb_a_bx) *
            FMS_ConstB.Gain4_cu * ((rtb_Saturation_ga - rtb_Saturation1_d) *
            0.5F) - rtb_Saturation_o4 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S463>/Integrator' */
          /* End of Outputs for SubSystem: '<S452>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S455>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S455>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S341>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S341>/Unknown' incorporates:
           *  ActionPort: '<S454>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S341>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
         *  ActionPort: '<S340>/Action Port'
         */
        /* SwitchCase: '<S340>/Switch Case' */
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
            /* Disable for SwitchCase: '<S439>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S355>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S373>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S389>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S414>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S401>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S340>/Acro' incorporates:
           *  ActionPort: '<S345>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S345>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S345>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S345>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Gain: '<S350>/Gain'
           *  Gain: '<S350>/Gain1'
           *  Gain: '<S350>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Outport: '<Root>/FMS_Out'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_c;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
          FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
          FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

          /* Saturate: '<S351>/Saturation' incorporates:
           *  Constant: '<S351>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  Sum: '<S351>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_u_b = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S351>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S345>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S351>/Constant5'
           *  Gain: '<S351>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S351>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_u_b), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S340>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S340>/Stabilize' incorporates:
             *  ActionPort: '<S348>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S340>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S435>/Integrator'
             *  DiscreteIntegrator: '<S435>/Integrator1'
             *  DiscreteIntegrator: '<S436>/Integrator'
             *  DiscreteIntegrator: '<S436>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S340>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S340>/Stabilize' incorporates:
             *  ActionPort: '<S348>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' incorporates:
             *  Chart: '<S440>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S340>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Stabilize' incorporates:
           *  ActionPort: '<S348>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S430>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_Compare_o3 = !FMS_B.Compare;

          /* Chart: '<S440>/Motion State' incorporates:
           *  Abs: '<S440>/Abs'
           *  Abs: '<S440>/Abs1'
           *  Constant: '<S450>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S450>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S439>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_e;
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S439>/Hold Control' incorporates:
               *  ActionPort: '<S442>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S439>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S439>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S439>/Hold Control' incorporates:
             *  ActionPort: '<S442>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S439>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S439>/Brake Control' incorporates:
             *  ActionPort: '<S441>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S439>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S439>/Move Control' incorporates:
               *  ActionPort: '<S443>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S439>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S439>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S439>/Move Control' incorporates:
             *  ActionPort: '<S443>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S439>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S439>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S432>/Switch' incorporates:
           *  Constant: '<S432>/Constant'
           *  Constant: '<S432>/Constant4'
           *  Constant: '<S432>/Constant5'
           *  Gain: '<S432>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S432>/Saturation'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S432>/Add'
           *  Sum: '<S432>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S432>/Saturation' */
              rtb_u_b = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S432>/Saturation' */
              rtb_u_b = 0.0F;
            } else {
              /* Saturate: '<S432>/Saturation' incorporates:
               *  Constant: '<S432>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S43>/Signal Copy2'
               *  Sum: '<S432>/Sum'
               */
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_u_b),
              65536.0F) + 1000U);
          }

          /* End of Switch: '<S432>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S348>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S348>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S348>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S430>/Data Type Conversion'
           *  DiscreteIntegrator: '<S435>/Integrator1'
           *  DiscreteIntegrator: '<S436>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S430>/Multiply'
           *  Product: '<S430>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S439>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S348>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S348>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S348>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S439>/Saturation' */

          /* BusAssignment: '<S348>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S438>/Multiply1' incorporates:
           *  Constant: '<S438>/const1'
           *  DiscreteIntegrator: '<S436>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S434>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S434>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S438>/Add' incorporates:
           *  DiscreteIntegrator: '<S436>/Integrator1'
           *  Gain: '<S430>/Gain1'
           *  Gain: '<S434>/Gain'
           *  Sum: '<S436>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S438>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S438>/Sign' */

          /* Sum: '<S438>/Add2' incorporates:
           *  Abs: '<S438>/Abs'
           *  Gain: '<S438>/Gain'
           *  Gain: '<S438>/Gain1'
           *  Product: '<S438>/Multiply2'
           *  Product: '<S438>/Multiply3'
           *  Sqrt: '<S438>/Sqrt'
           *  Sum: '<S438>/Add1'
           *  Sum: '<S438>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_g) * FMS_ConstB.d_g)
               - FMS_ConstB.d_g) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S438>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S438>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_g;

          /* Sum: '<S438>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_g;

          /* Signum: '<S438>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S438>/Sign1' */

          /* Signum: '<S438>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S438>/Sign2' */

          /* Sum: '<S438>/Add5' incorporates:
           *  Gain: '<S438>/Gain2'
           *  Product: '<S438>/Multiply4'
           *  Sum: '<S438>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S438>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_g;

          /* Sum: '<S438>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_g;

          /* Product: '<S438>/Divide' */
          rtb_Divide_lr_idx_3 = d / FMS_ConstB.d_g;

          /* Signum: '<S438>/Sign5' incorporates:
           *  Signum: '<S438>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S438>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S438>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = d;

            /* Signum: '<S438>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S438>/Sign5' */

          /* Product: '<S437>/Multiply1' incorporates:
           *  Constant: '<S437>/const1'
           *  DiscreteIntegrator: '<S435>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S433>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S433>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S437>/Add' incorporates:
           *  DiscreteIntegrator: '<S435>/Integrator1'
           *  Gain: '<S430>/Gain'
           *  Gain: '<S433>/Gain'
           *  Sum: '<S435>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S437>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S437>/Sign' */

          /* Sum: '<S437>/Add2' incorporates:
           *  Abs: '<S437>/Abs'
           *  Gain: '<S437>/Gain'
           *  Gain: '<S437>/Gain1'
           *  Product: '<S437>/Multiply2'
           *  Product: '<S437>/Multiply3'
           *  Sqrt: '<S437>/Sqrt'
           *  Sum: '<S437>/Add1'
           *  Sum: '<S437>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_a) * FMS_ConstB.d_a)
               - FMS_ConstB.d_a) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S437>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S437>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_a;

          /* Sum: '<S437>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_a;

          /* Signum: '<S437>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S437>/Sign1' */

          /* Signum: '<S437>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S437>/Sign2' */

          /* Sum: '<S437>/Add5' incorporates:
           *  Gain: '<S437>/Gain2'
           *  Product: '<S437>/Multiply4'
           *  Sum: '<S437>/Subtract2'
           */
          d += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S435>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S435>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S436>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S436>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S438>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S438>/Sign3' */

          /* Signum: '<S438>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S438>/Sign4' */

          /* Update for DiscreteIntegrator: '<S436>/Integrator' incorporates:
           *  Constant: '<S438>/const'
           *  Gain: '<S438>/Gain3'
           *  Product: '<S438>/Multiply5'
           *  Product: '<S438>/Multiply6'
           *  Sum: '<S438>/Subtract4'
           *  Sum: '<S438>/Subtract5'
           *  Sum: '<S438>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Divide_lr_idx_3 -
            rtb_Integrator1_bx) * FMS_ConstB.Gain4_o * ((rtb_Saturation_ga -
            rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4 * 12.566371F) *
            0.004F;

          /* Sum: '<S437>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_a;

          /* Sum: '<S437>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_a;

          /* Signum: '<S437>/Sign5' incorporates:
           *  Signum: '<S437>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S437>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S437>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S437>/Sign6' */
            rtb_Divide_lr_idx_3 = d;
          }

          /* End of Signum: '<S437>/Sign5' */

          /* Signum: '<S437>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S437>/Sign3' */

          /* Signum: '<S437>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S437>/Sign4' */

          /* Update for DiscreteIntegrator: '<S435>/Integrator' incorporates:
           *  Constant: '<S437>/const'
           *  Gain: '<S437>/Gain3'
           *  Product: '<S437>/Divide'
           *  Product: '<S437>/Multiply5'
           *  Product: '<S437>/Multiply6'
           *  Sum: '<S437>/Subtract4'
           *  Sum: '<S437>/Subtract5'
           *  Sum: '<S437>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((d / FMS_ConstB.d_a - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_k * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S340>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S340>/Altitude' incorporates:
             *  ActionPort: '<S346>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S340>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S369>/Integrator'
             *  DiscreteIntegrator: '<S369>/Integrator1'
             *  DiscreteIntegrator: '<S370>/Integrator'
             *  DiscreteIntegrator: '<S370>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S340>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S340>/Altitude' incorporates:
             *  ActionPort: '<S346>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' incorporates:
             *  Chart: '<S356>/Motion Status'
             *  Chart: '<S374>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S340>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Altitude' incorporates:
           *  ActionPort: '<S346>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S356>/Motion Status' incorporates:
           *  Abs: '<S356>/Abs'
           *  Abs: '<S356>/Abs1'
           *  Constant: '<S365>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S365>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S355>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_nh;
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S355>/Hold Control' incorporates:
               *  ActionPort: '<S358>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S355>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S355>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S355>/Hold Control' incorporates:
             *  ActionPort: '<S358>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S355>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S355>/Brake Control' incorporates:
             *  ActionPort: '<S357>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S355>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S355>/Move Control' incorporates:
             *  ActionPort: '<S359>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S355>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S355>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S352>/Switch' incorporates:
           *  Constant: '<S352>/Constant'
           *  Saturate: '<S355>/Saturation1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_ga = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S355>/Saturation1' */
            rtb_Saturation_ga = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S355>/Saturation1' */
            rtb_Saturation_ga = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S355>/Saturation1' */
            rtb_Saturation_ga = FMS_B.Merge_l;
          }

          /* End of Switch: '<S352>/Switch' */

          /* Logic: '<S353>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_Compare_o3 = !FMS_B.Compare;

          /* Chart: '<S374>/Motion State' incorporates:
           *  Abs: '<S374>/Abs'
           *  Abs: '<S374>/Abs1'
           *  Constant: '<S384>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S384>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S373>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S373>/Hold Control' incorporates:
               *  ActionPort: '<S376>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S373>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_pi);

              /* End of SystemReset for SubSystem: '<S373>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S373>/Hold Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_pi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S373>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S373>/Brake Control' incorporates:
             *  ActionPort: '<S375>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S373>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S373>/Move Control' incorporates:
               *  ActionPort: '<S377>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S373>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S373>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S373>/Move Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S373>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S373>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S346>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S346>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S346>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S353>/Data Type Conversion'
           *  DiscreteIntegrator: '<S369>/Integrator1'
           *  DiscreteIntegrator: '<S370>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S353>/Multiply'
           *  Product: '<S353>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S373>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S346>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S346>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S346>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S373>/Saturation' */

          /* BusAssignment: '<S346>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;

          /* Product: '<S372>/Multiply1' incorporates:
           *  Constant: '<S372>/const1'
           *  DiscreteIntegrator: '<S370>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S368>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S368>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S372>/Add' incorporates:
           *  DiscreteIntegrator: '<S370>/Integrator1'
           *  Gain: '<S353>/Gain1'
           *  Gain: '<S368>/Gain'
           *  Sum: '<S370>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S372>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S372>/Sign' */

          /* Sum: '<S372>/Add2' incorporates:
           *  Abs: '<S372>/Abs'
           *  Gain: '<S372>/Gain'
           *  Gain: '<S372>/Gain1'
           *  Product: '<S372>/Multiply2'
           *  Product: '<S372>/Multiply3'
           *  Sqrt: '<S372>/Sqrt'
           *  Sum: '<S372>/Add1'
           *  Sum: '<S372>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_o) * FMS_ConstB.d_o)
               - FMS_ConstB.d_o) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S372>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S372>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_o;

          /* Sum: '<S372>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_o;

          /* Signum: '<S372>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S372>/Sign1' */

          /* Signum: '<S372>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S372>/Sign2' */

          /* Sum: '<S372>/Add5' incorporates:
           *  Gain: '<S372>/Gain2'
           *  Product: '<S372>/Multiply4'
           *  Sum: '<S372>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S372>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_o;

          /* Sum: '<S372>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_o;

          /* Product: '<S372>/Divide' */
          rtb_Divide_lr_idx_3 = d / FMS_ConstB.d_o;

          /* Signum: '<S372>/Sign5' incorporates:
           *  Signum: '<S372>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S372>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S372>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = d;

            /* Signum: '<S372>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S372>/Sign5' */

          /* Product: '<S371>/Multiply1' incorporates:
           *  Constant: '<S371>/const1'
           *  DiscreteIntegrator: '<S369>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S367>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S367>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S371>/Add' incorporates:
           *  DiscreteIntegrator: '<S369>/Integrator1'
           *  Gain: '<S353>/Gain'
           *  Gain: '<S367>/Gain'
           *  Sum: '<S369>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S371>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S371>/Sign' */

          /* Sum: '<S371>/Add2' incorporates:
           *  Abs: '<S371>/Abs'
           *  Gain: '<S371>/Gain'
           *  Gain: '<S371>/Gain1'
           *  Product: '<S371>/Multiply2'
           *  Product: '<S371>/Multiply3'
           *  Sqrt: '<S371>/Sqrt'
           *  Sum: '<S371>/Add1'
           *  Sum: '<S371>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_c) * FMS_ConstB.d_c)
               - FMS_ConstB.d_c) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S371>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S371>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_c;

          /* Sum: '<S371>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_c;

          /* Signum: '<S371>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S371>/Sign1' */

          /* Signum: '<S371>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S371>/Sign2' */

          /* Sum: '<S371>/Add5' incorporates:
           *  Gain: '<S371>/Gain2'
           *  Product: '<S371>/Multiply4'
           *  Sum: '<S371>/Subtract2'
           */
          d += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S369>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S369>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S370>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S370>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S372>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S372>/Sign3' */

          /* Signum: '<S372>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S372>/Sign4' */

          /* Update for DiscreteIntegrator: '<S370>/Integrator' incorporates:
           *  Constant: '<S372>/const'
           *  Gain: '<S372>/Gain3'
           *  Product: '<S372>/Multiply5'
           *  Product: '<S372>/Multiply6'
           *  Sum: '<S372>/Subtract4'
           *  Sum: '<S372>/Subtract5'
           *  Sum: '<S372>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Divide_lr_idx_3 -
            rtb_Integrator1_bx) * FMS_ConstB.Gain4_c * ((rtb_Saturation_ga -
            rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4 * 12.566371F) *
            0.004F;

          /* Sum: '<S371>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_c;

          /* Sum: '<S371>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_c;

          /* Signum: '<S371>/Sign5' incorporates:
           *  Signum: '<S371>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S371>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S371>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S371>/Sign6' */
            rtb_Divide_lr_idx_3 = d;
          }

          /* End of Signum: '<S371>/Sign5' */

          /* Signum: '<S371>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S371>/Sign3' */

          /* Signum: '<S371>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S371>/Sign4' */

          /* Update for DiscreteIntegrator: '<S369>/Integrator' incorporates:
           *  Constant: '<S371>/const'
           *  Gain: '<S371>/Gain3'
           *  Product: '<S371>/Divide'
           *  Product: '<S371>/Multiply5'
           *  Product: '<S371>/Multiply6'
           *  Sum: '<S371>/Subtract4'
           *  Sum: '<S371>/Subtract5'
           *  Sum: '<S371>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((d / FMS_ConstB.d_c - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_h * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S340>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S340>/Position' incorporates:
             *  ActionPort: '<S347>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' incorporates:
             *  Chart: '<S390>/Motion Status'
             *  Chart: '<S402>/Motion State'
             *  Chart: '<S415>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S340>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Position' incorporates:
           *  ActionPort: '<S347>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S390>/Motion Status' incorporates:
           *  Abs: '<S390>/Abs'
           *  Abs: '<S390>/Abs1'
           *  Constant: '<S399>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S399>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S389>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_n;
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S389>/Hold Control' incorporates:
               *  ActionPort: '<S392>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S389>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S389>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S389>/Hold Control' incorporates:
             *  ActionPort: '<S392>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S389>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S389>/Brake Control' incorporates:
             *  ActionPort: '<S391>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S389>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S389>/Move Control' incorporates:
             *  ActionPort: '<S393>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S389>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S389>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S402>/Motion State' incorporates:
           *  Abs: '<S402>/Abs'
           *  Abs: '<S402>/Abs1'
           *  Constant: '<S412>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S412>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S415>/Logical Operator' incorporates:
           *  Abs: '<S415>/Abs1'
           *  Abs: '<S415>/Abs2'
           *  Constant: '<S427>/Constant'
           *  Constant: '<S428>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S427>/Compare'
           *  RelationalOperator: '<S428>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtb_Compare_o3 = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                             FMS_PARAM.PITCH_DZ) || (fabsf
            (FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S415>/Motion State' */
          if (FMS_DW.temporalCounter_i1_g < 2047U) {
            FMS_DW.temporalCounter_i1_g++;
          }

          if (FMS_DW.is_active_c16_FMS == 0U) {
            FMS_DW.is_active_c16_FMS = 1U;
            FMS_DW.is_c16_FMS = FMS_IN_Move_a;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c16_FMS) {
             case FMS_IN_Brake_m:
              rtb_state_fg = MotionState_Brake;
              if ((rtb_Divide_lr_idx_2 <= 0.2) || (FMS_DW.temporalCounter_i1_g >=
                   1250U)) {
                FMS_DW.is_c16_FMS = FMS_IN_Hold_ow;
                rtb_state_fg = MotionState_Hold;
              } else {
                if (rtb_Compare_o3) {
                  FMS_DW.is_c16_FMS = FMS_IN_Move_a;
                  rtb_state_fg = MotionState_Move;
                }
              }
              break;

             case FMS_IN_Hold_ow:
              rtb_state_fg = MotionState_Hold;
              if (rtb_Compare_o3) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_a;
                rtb_state_fg = MotionState_Move;
              }
              break;

             default:
              rtb_state_fg = MotionState_Move;
              if (!rtb_Compare_o3) {
                FMS_DW.is_c16_FMS = FMS_IN_Brake_m;
                FMS_DW.temporalCounter_i1_g = 0U;
                rtb_state_fg = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S415>/Motion State' */

          /* SwitchCase: '<S414>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S414>/Hold Control' incorporates:
               *  ActionPort: '<S416>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S414>/Switch Case' incorporates:
               *  Delay: '<S416>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S414>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S414>/Hold Control' incorporates:
             *  ActionPort: '<S416>/Action Port'
             */
            /* Delay: '<S416>/Delay' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            if (FMS_DW.icLoad != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Trigonometry: '<S420>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* Trigonometry: '<S420>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* SignalConversion: '<S420>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S420>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S420>/Gain' incorporates:
             *  Gain: '<S419>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S420>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S420>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* SignalConversion: '<S420>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S420>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* SignalConversion: '<S420>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S416>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S416>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S416>/Sum'
             */
            d = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Integrator1_bx = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S416>/Multiply' incorporates:
             *  SignalConversion: '<S416>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d;
            }

            /* End of Product: '<S416>/Multiply' */

            /* Gain: '<S416>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

            /* Update for Delay: '<S416>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S414>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S414>/Move Control' incorporates:
               *  ActionPort: '<S417>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S414>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S423>/Integrator'
               *  DiscreteIntegrator: '<S423>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S414>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S414>/Move Control' incorporates:
             *  ActionPort: '<S417>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S421>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S421>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S421>/Gain' */
            rtb_Saturation_o4 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S422>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S422>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S422>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

            /* Sum: '<S424>/Sum of Elements' incorporates:
             *  Math: '<S424>/Square'
             *  SignalConversion: '<S424>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S425>/Sum of Elements'
             *  Switch: '<S417>/Switch'
             */
            rtb_u_b = rtb_Saturation_o4 * rtb_Saturation_o4 +
              rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

            /* Switch: '<S417>/Switch' incorporates:
             *  Product: '<S425>/Divide'
             *  Sqrt: '<S424>/Sqrt'
             *  Sum: '<S424>/Sum of Elements'
             */
            if (sqrtf(rtb_u_b) > 1.0F) {
              /* Math: '<S425>/Math Function1'
               *
               * About '<S425>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_u_b < 0.0F) {
                rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
              } else {
                rtb_Saturation_ga = sqrtf(rtb_u_b);
              }

              /* End of Math: '<S425>/Math Function1' */

              /* Switch: '<S425>/Switch' incorporates:
               *  Constant: '<S425>/Constant'
               *  Product: '<S425>/Product'
               */
              if (rtb_Saturation_ga > 0.0F) {
                rtb_MatrixConcatenate3[0] = rtb_Saturation_o4;
                rtb_MatrixConcatenate3[1] = rtb_Divide_lr_idx_2;
                rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
              } else {
                rtb_MatrixConcatenate3[0] = 0.0F;
                rtb_MatrixConcatenate3[1] = 0.0F;
                rtb_MatrixConcatenate3[2] = 1.0F;
              }

              /* End of Switch: '<S425>/Switch' */
              rtb_Saturation_o4 = rtb_MatrixConcatenate3[0] /
                rtb_MatrixConcatenate3[2];
              rtb_Divide_lr_idx_2 = rtb_MatrixConcatenate3[1] /
                rtb_MatrixConcatenate3[2];
            }

            /* Product: '<S426>/Multiply1' incorporates:
             *  Constant: '<S426>/const1'
             *  DiscreteIntegrator: '<S423>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S426>/Add' incorporates:
             *  DiscreteIntegrator: '<S423>/Integrator1'
             *  Gain: '<S417>/Gain6'
             *  Sum: '<S423>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE[0] -
              FMS_PARAM.VEL_XY_LIM * rtb_Saturation_o4) + rtb_Saturation1_d;

            /* Signum: '<S426>/Sign' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Divide_lr_idx_3;
            }

            /* Sum: '<S426>/Add2' incorporates:
             *  Abs: '<S426>/Abs'
             *  Gain: '<S426>/Gain'
             *  Gain: '<S426>/Gain1'
             *  Product: '<S426>/Multiply2'
             *  Product: '<S426>/Multiply3'
             *  Sqrt: '<S426>/Sqrt'
             *  Sum: '<S426>/Add1'
             *  Sum: '<S426>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S426>/Add4' */
            rtb_Saturation1_d += rtb_Divide_lr_idx_3 - rtb_Saturation_o4;

            /* Sum: '<S426>/Add3' */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d;

            /* Sum: '<S426>/Subtract1' */
            rtb_Divide_lr_idx_3 -= FMS_ConstB.d;

            /* Signum: '<S426>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S426>/Sign2' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_3 > 0.0F) {
                rtb_Divide_lr_idx_3 = 1.0F;
              }
            }

            /* Sum: '<S426>/Add5' incorporates:
             *  Gain: '<S426>/Gain2'
             *  Product: '<S426>/Multiply4'
             *  Sum: '<S426>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Divide_lr_idx_3) *
              0.5F * rtb_Saturation1_d;

            /* SignalConversion: '<S423>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S423>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S423>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S423>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S426>/Sign4' incorporates:
             *  Sum: '<S426>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S426>/Sign3' incorporates:
             *  Sum: '<S426>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S426>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S426>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S426>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S426>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S423>/Integrator' incorporates:
             *  Constant: '<S426>/const'
             *  Gain: '<S426>/Gain3'
             *  Product: '<S426>/Divide'
             *  Product: '<S426>/Multiply5'
             *  Product: '<S426>/Multiply6'
             *  Sum: '<S426>/Subtract4'
             *  Sum: '<S426>/Subtract5'
             *  Sum: '<S426>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 39.224F) *
              0.004F;

            /* Product: '<S426>/Multiply1' incorporates:
             *  Constant: '<S426>/const1'
             *  DiscreteIntegrator: '<S423>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S426>/Add' incorporates:
             *  DiscreteIntegrator: '<S423>/Integrator1'
             *  Gain: '<S417>/Gain6'
             *  Sum: '<S423>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE[1] -
              FMS_PARAM.VEL_XY_LIM * rtb_Divide_lr_idx_2) + rtb_Saturation1_d;

            /* Signum: '<S426>/Sign' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Divide_lr_idx_3;
            }

            /* Sum: '<S426>/Add2' incorporates:
             *  Abs: '<S426>/Abs'
             *  Gain: '<S426>/Gain'
             *  Gain: '<S426>/Gain1'
             *  Product: '<S426>/Multiply2'
             *  Product: '<S426>/Multiply3'
             *  Sqrt: '<S426>/Sqrt'
             *  Sum: '<S426>/Add1'
             *  Sum: '<S426>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S426>/Add4' */
            rtb_Saturation1_d += rtb_Divide_lr_idx_3 - rtb_Saturation_o4;

            /* Sum: '<S426>/Add3' */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d;

            /* Sum: '<S426>/Subtract1' */
            rtb_Divide_lr_idx_3 -= FMS_ConstB.d;

            /* Signum: '<S426>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S426>/Sign2' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_3 > 0.0F) {
                rtb_Divide_lr_idx_3 = 1.0F;
              }
            }

            /* Sum: '<S426>/Add5' incorporates:
             *  Gain: '<S426>/Gain2'
             *  Product: '<S426>/Multiply4'
             *  Sum: '<S426>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Divide_lr_idx_3) *
              0.5F * rtb_Saturation1_d;

            /* SignalConversion: '<S423>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S423>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S423>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S423>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S426>/Sign4' incorporates:
             *  Sum: '<S426>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S426>/Sign3' incorporates:
             *  Sum: '<S426>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S426>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S426>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S426>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S426>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S423>/Integrator' incorporates:
             *  Constant: '<S426>/const'
             *  Gain: '<S426>/Gain3'
             *  Product: '<S426>/Divide'
             *  Product: '<S426>/Multiply5'
             *  Product: '<S426>/Multiply6'
             *  Sum: '<S426>/Subtract4'
             *  Sum: '<S426>/Subtract5'
             *  Sum: '<S426>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 39.224F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S414>/Move Control' */
            break;
          }

          /* SwitchCase: '<S401>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          switch (rtb_state_ej) {
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
              /* SystemReset for IfAction SubSystem: '<S401>/Hold Control' incorporates:
               *  ActionPort: '<S404>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S401>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S401>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S401>/Hold Control' incorporates:
             *  ActionPort: '<S404>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S401>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S401>/Brake Control' incorporates:
             *  ActionPort: '<S403>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S401>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S401>/Move Control' incorporates:
               *  ActionPort: '<S405>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S401>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S401>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S401>/Move Control' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S401>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S401>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S347>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S347>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S401>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S401>/Saturation' */

          /* Saturate: '<S414>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S414>/Saturation1' */

          /* Saturate: '<S389>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S347>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S389>/Saturation1' */
          /* End of Outputs for SubSystem: '<S340>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S340>/Unknown' incorporates:
           *  ActionPort: '<S349>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S340>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S50>/Manual' incorporates:
         *  ActionPort: '<S342>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S342>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S342>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S342>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S342>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S50>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S50>/Unknown' incorporates:
         *  ActionPort: '<S344>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S50>/Unknown' */
        break;
      }

      /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
      break;
    }

    /* End of Outputs for SubSystem: '<S42>/Arm' */
    break;
  }

  /* BusAssignment: '<S45>/Bus Assignment' incorporates:
   *  Constant: '<S45>/Constant'
   *  DataStoreRead: '<S45>/Data Store Read'
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   *  DataTypeConversion: '<S45>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S785>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy8Inport1'
   *  Sum: '<S45>/Sum'
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

  /* Update for DiscreteIntegrator: '<S785>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S785>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   */
  rtb_Compare_o3 = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S27>/SetHome' incorporates:
   *  TriggerPort: '<S34>/Trigger'
   */
  if (rtb_Compare_o3 && (FMS_PrevZCX.SetHome_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreWrite: '<S34>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_Compare_o3;

  /* End of Outputs for SubSystem: '<S27>/SetHome' */

  /* Update for DiscreteIntegrator: '<S817>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S817>/Gain'
   *  Sum: '<S817>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_kv[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_kv[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_kv[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for UnitDelay: '<S30>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S26>/Constant1'
   */
  rtb_u_b = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_u_b < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_u_b;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S37>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S37>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S11>/Gain'
   *  Sum: '<S11>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_o += (rtb_DiscreteTimeIntegrator_n -
    FMS_B.DiscreteTimeIntegrator5) * 62.831852F * 0.004F;

  /* Update for UnitDelay: '<S32>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S33>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S33>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S38>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S39>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S39>/Delay Input1':
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

  /* Update for DiscreteIntegrator: '<S819>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S819>/Gain'
   *  Sum: '<S819>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_L_af = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S818>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S818>/Gain'
   *  Sum: '<S818>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_lr_idx_0 -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_u_b = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_c + (real32_T)
    FMS_EXPORT.period;
  if (rtb_u_b < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_c = (uint32_T)rtb_u_b;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_c = MAX_uint32_T;
  }

  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_c >= 1000000U) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_c = 1000000U;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_c <= 0U) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_c = 0U;
    }
  }

  FMS_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    rtb_FixPtRelationalOperator_me;

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_u_b = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_u_b < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_u_b;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* Update for Delay: '<S24>/Delay' */
  FMS_DW.Delay_DSTATE_oi = rtb_Switch_ga;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S10>/Gain'
   *  Sum: '<S10>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_m = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_h += (rtb_Divide_lr_idx_1 -
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
  /* Start for SwitchCase: '<S42>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S42>/Arm' */
  /* Start for SwitchCase: '<S44>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S44>/FW_Mode' */
  /* Start for SwitchCase: '<S49>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;

  /* Start for IfAction SubSystem: '<S49>/SubMode' */
  /* Start for SwitchCase: '<S128>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S49>/SubMode' */

  /* Start for IfAction SubSystem: '<S49>/Auto' */
  /* Start for SwitchCase: '<S126>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;

  /* End of Start for SubSystem: '<S49>/Auto' */

  /* Start for IfAction SubSystem: '<S49>/Assist' */
  /* Start for SwitchCase: '<S125>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S125>/Altitude' */
  /* Start for SwitchCase: '<S138>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;

  /* End of Start for SubSystem: '<S125>/Altitude' */

  /* Start for IfAction SubSystem: '<S125>/Position' */
  /* Start for SwitchCase: '<S178>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S163>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S125>/Position' */
  /* End of Start for SubSystem: '<S49>/Assist' */
  /* End of Start for SubSystem: '<S44>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S44>/BackwardTrans_Mode' */
  /* Start for SwitchCase: '<S54>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;

  /* End of Start for SubSystem: '<S44>/BackwardTrans_Mode' */

  /* Start for IfAction SubSystem: '<S44>/MC_Mode' */
  /* Start for SwitchCase: '<S50>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S50>/SubMode' */
  /* Start for SwitchCase: '<S343>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S343>/Return' */
  /* Start for SwitchCase: '<S743>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S733>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S343>/Return' */

  /* Start for IfAction SubSystem: '<S343>/Hold' */
  /* Start for SwitchCase: '<S682>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S650>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S661>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S343>/Hold' */
  /* End of Start for SubSystem: '<S50>/SubMode' */

  /* Start for IfAction SubSystem: '<S50>/Auto' */
  /* Start for SwitchCase: '<S341>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S341>/Mission' */
  /* Start for Resettable SubSystem: '<S452>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S503>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S493>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S452>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S341>/Mission' */
  /* End of Start for SubSystem: '<S50>/Auto' */

  /* Start for IfAction SubSystem: '<S50>/Assist' */
  /* Start for SwitchCase: '<S340>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S340>/Stabilize' */
  /* Start for SwitchCase: '<S439>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S340>/Stabilize' */

  /* Start for IfAction SubSystem: '<S340>/Altitude' */
  /* Start for SwitchCase: '<S355>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S373>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S340>/Altitude' */

  /* Start for IfAction SubSystem: '<S340>/Position' */
  /* Start for SwitchCase: '<S389>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S414>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S401>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S340>/Position' */
  /* End of Start for SubSystem: '<S50>/Assist' */
  /* End of Start for SubSystem: '<S44>/MC_Mode' */
  /* End of Start for SubSystem: '<S42>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S817>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S819>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_L_af = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S818>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  FMS_DW.Delay_DSTATE_a = true;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_m = 1U;

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
  FMS_DW.is_VTOL_Mode = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_VTOL_State = 0U;
  FMS_DW.is_VTOL_State = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.temporalCounter_i2 = 0U;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Return_n = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_VTOL_Land_m = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
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
  /* SystemInitialize for IfAction SubSystem: '<S42>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S44>/FW_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S49>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S128>/Hold' */
  /* InitializeConditions for Delay: '<S283>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S278>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S128>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S49>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S126>/Mission' */
  /* InitializeConditions for UnitDelay: '<S242>/Delay Input1'
   *
   * Block description for '<S242>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S239>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S250>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_li = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S250>/Integrator' */
  FMS_DW.Integrator_DSTATE_fk = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S239>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S126>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S49>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S125>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S232>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S232>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S233>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_oo = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S237>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jv = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S237>/Integrator' */
  FMS_DW.Integrator_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S233>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S125>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S125>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
  FMS_DW.Integrator_DSTATE_hd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Integrator' */
  FMS_DW.Integrator_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
  FMS_DW.Integrator_DSTATE_er = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* SystemInitialize for Chart: '<S139>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S138>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S138>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S138>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S138>/Move Control' */

  /* SystemInitialize for Merge: '<S138>/Merge' */
  FMS_B.Merge_lj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S125>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S125>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator' */
  FMS_DW.Integrator_DSTATE_c5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S225>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S225>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S164>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S179>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S178>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_b, &FMS_DW.HoldControl_b);

  /* End of SystemInitialize for SubSystem: '<S178>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S163>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S163>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S163>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S163>/Move Control' */

  /* SystemInitialize for Merge: '<S163>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S178>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S125>/Position' */
  /* End of SystemInitialize for SubSystem: '<S49>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S44>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/BackwardTrans_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mb = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_hf = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  FMS_DW.Integrator_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  FMS_DW.Integrator_DSTATE_oy = 0.0F;

  /* SystemInitialize for Chart: '<S55>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for IfAction SubSystem: '<S54>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_p, &FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S54>/Hold Control' */

  /* SystemInitialize for Merge: '<S54>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S44>/BackwardTrans_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S50>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S343>/Takeoff' */
  /* InitializeConditions for Delay: '<S783>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S779>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S779>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S343>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S343>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S698>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S698>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S343>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S343>/Return' */
  /* InitializeConditions for Delay: '<S728>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S729>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S724>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S770>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S707>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S710>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S710>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S744>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S743>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S743>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S743>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S743>/Move Control' */

  /* SystemInitialize for Merge: '<S743>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S734>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S733>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S733>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S733>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_cg);

  /* End of SystemInitialize for SubSystem: '<S733>/Move Control' */

  /* SystemInitialize for Merge: '<S733>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S343>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S343>/Hold' */
  /* InitializeConditions for Delay: '<S663>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S675>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S675>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S651>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S662>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S683>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S682>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S682>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S682>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S682>/Move Control' */

  /* SystemInitialize for Merge: '<S682>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S650>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S650>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S650>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S650>/Move Control' */

  /* SystemInitialize for Merge: '<S650>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S661>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S661>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S661>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S661>/Move Control' */

  /* SystemInitialize for Merge: '<S661>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S343>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S50>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S341>/Mission' */
  /* InitializeConditions for UnitDelay: '<S455>/Delay Input1'
   *
   * Block description for '<S455>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S452>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S482>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S478>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S530>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S460>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S463>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S463>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S504>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S503>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S503>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S503>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S513>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S513>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S503>/Move Control' */

  /* SystemInitialize for Merge: '<S503>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S503>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S513>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S513>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S503>/Move Control' */

  /* SystemInitialize for Merge: '<S503>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S494>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S493>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S493>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S493>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S500>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S500>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S493>/Move Control' */

  /* SystemInitialize for Merge: '<S493>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S452>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S341>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S50>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S340>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S435>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S435>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S440>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S439>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S439>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S439>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S439>/Move Control' */

  /* SystemInitialize for Merge: '<S439>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S340>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S340>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S369>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S369>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S356>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S355>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S355>/Hold Control' */

  /* SystemInitialize for Merge: '<S355>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S374>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S373>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_pi);

  /* End of SystemInitialize for SubSystem: '<S373>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S373>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S373>/Move Control' */

  /* SystemInitialize for Merge: '<S373>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S340>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S340>/Position' */
  /* SystemInitialize for Chart: '<S390>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S389>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S389>/Hold Control' */

  /* SystemInitialize for Chart: '<S402>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S415>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S414>/Hold Control' */
  /* InitializeConditions for Delay: '<S416>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S414>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S414>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S423>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S423>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S414>/Move Control' */

  /* SystemInitialize for Merge: '<S414>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S414>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S423>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S423>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S414>/Move Control' */

  /* SystemInitialize for Merge: '<S414>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S389>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S401>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S401>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S401>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S401>/Move Control' */

  /* SystemInitialize for Merge: '<S401>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S340>/Position' */
  /* End of SystemInitialize for SubSystem: '<S50>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S44>/MC_Mode' */
  /* End of SystemInitialize for SubSystem: '<S42>/Arm' */
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
