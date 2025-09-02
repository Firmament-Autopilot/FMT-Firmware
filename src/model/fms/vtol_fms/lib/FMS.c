/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2520
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep  2 10:30:08 2025
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

/* Named constants for Chart: '<S689>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S699>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S395>/Motion State' */
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
struct_dWs0XrqIAH5LuSHjOHxbwF FMS_PARAM = {
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
  22.0F,
  17.0F,
  14.0F,
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
                                        *   '<S741>/Constant1'
                                        *   '<S742>/Constant'
                                        *   '<S744>/Constant1'
                                        *   '<S745>/FW_ACCEPT_R'
                                        *   '<S745>/MC_ACCEPT_R'
                                        *   '<S748>/Constant'
                                        *   '<S48>/L1'
                                        *   '<S224>/Dead Zone'
                                        *   '<S224>/Gain'
                                        *   '<S225>/Dead Zone'
                                        *   '<S225>/Gain'
                                        *   '<S226>/Dead Zone'
                                        *   '<S226>/Gain'
                                        *   '<S227>/Dead Zone'
                                        *   '<S227>/Gain'
                                        *   '<S230>/Constant4'
                                        *   '<S231>/Constant4'
                                        *   '<S599>/L1'
                                        *   '<S95>/Gain'
                                        *   '<S96>/Gain1'
                                        *   '<S97>/Gain'
                                        *   '<S118>/Gain1'
                                        *   '<S120>/Gain'
                                        *   '<S184>/Gain'
                                        *   '<S184>/Gain1'
                                        *   '<S185>/Gain1'
                                        *   '<S233>/Gain2'
                                        *   '<S233>/Saturation1'
                                        *   '<S234>/L1'
                                        *   '<S234>/R'
                                        *   '<S234>/Saturation1'
                                        *   '<S251>/Gain'
                                        *   '<S251>/Saturation1'
                                        *   '<S273>/Gain'
                                        *   '<S273>/Saturation1'
                                        *   '<S308>/Gain'
                                        *   '<S308>/Gain1'
                                        *   '<S385>/Gain'
                                        *   '<S385>/Gain1'
                                        *   '<S387>/Constant'
                                        *   '<S411>/L1'
                                        *   '<S492>/Saturation'
                                        *   '<S493>/Saturation1'
                                        *   '<S493>/Saturation2'
                                        *   '<S493>/Saturation3'
                                        *   '<S650>/Land_Speed'
                                        *   '<S651>/Saturation1'
                                        *   '<S730>/Takeoff_Speed'
                                        *   '<S731>/Gain2'
                                        *   '<S731>/Saturation1'
                                        *   '<S98>/Saturation1'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S112>/Dead Zone'
                                        *   '<S112>/Gain'
                                        *   '<S121>/Saturation1'
                                        *   '<S132>/Dead Zone'
                                        *   '<S132>/Gain'
                                        *   '<S135>/Saturation1'
                                        *   '<S187>/Dead Zone'
                                        *   '<S187>/Gain'
                                        *   '<S188>/Dead Zone'
                                        *   '<S188>/Gain'
                                        *   '<S193>/Dead Zone'
                                        *   '<S193>/Gain'
                                        *   '<S201>/Gain'
                                        *   '<S201>/Saturation1'
                                        *   '<S202>/Constant4'
                                        *   '<S256>/L1'
                                        *   '<S256>/Saturation1'
                                        *   '<S278>/L1'
                                        *   '<S278>/Saturation1'
                                        *   '<S310>/Saturation1'
                                        *   '<S322>/Dead Zone'
                                        *   '<S322>/Gain'
                                        *   '<S323>/Dead Zone'
                                        *   '<S323>/Gain'
                                        *   '<S328>/Saturation'
                                        *   '<S344>/Saturation1'
                                        *   '<S356>/Saturation'
                                        *   '<S369>/Saturation1'
                                        *   '<S388>/Dead Zone'
                                        *   '<S388>/Gain'
                                        *   '<S389>/Dead Zone'
                                        *   '<S389>/Gain'
                                        *   '<S394>/Saturation'
                                        *   '<S548>/Gain2'
                                        *   '<S555>/Gain1'
                                        *   '<S555>/Gain2'
                                        *   '<S605>/Saturation1'
                                        *   '<S616>/Saturation'
                                        *   '<S637>/Saturation1'
                                        *   '<S652>/Constant'
                                        *   '<S655>/Gain2'
                                        *   '<S679>/Constant'
                                        *   '<S679>/vel'
                                        *   '<S679>/Acceleration_Speed'
                                        *   '<S679>/Saturation'
                                        *   '<S679>/Switch'
                                        *   '<S683>/Constant'
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
                                        *   '<S207>/L1'
                                        *   '<S207>/Saturation1'
                                        *   '<S313>/Gain2'
                                        *   '<S314>/Gain1'
                                        *   '<S320>/Constant'
                                        *   '<S331>/Gain2'
                                        *   '<S332>/Gain1'
                                        *   '<S339>/Constant'
                                        *   '<S347>/Gain2'
                                        *   '<S348>/Gain1'
                                        *   '<S354>/Constant'
                                        *   '<S359>/Gain2'
                                        *   '<S360>/Gain1'
                                        *   '<S367>/Constant'
                                        *   '<S371>/Gain2'
                                        *   '<S372>/Gain6'
                                        *   '<S382>/Constant'
                                        *   '<S383>/Constant'
                                        *   '<S397>/Gain2'
                                        *   '<S398>/Gain1'
                                        *   '<S405>/Constant'
                                        *   '<S430>/Gain'
                                        *   '<S430>/Saturation1'
                                        *   '<S433>/Constant'
                                        *   '<S433>/vel'
                                        *   '<S433>/Switch'
                                        *   '<S608>/Gain2'
                                        *   '<S609>/Gain1'
                                        *   '<S620>/Gain2'
                                        *   '<S621>/Gain1'
                                        *   '<S629>/Gain2'
                                        *   '<S629>/Saturation'
                                        *   '<S630>/Integrator'
                                        *   '<S640>/Gain2'
                                        *   '<S641>/Gain6'
                                        *   '<S664>/Gain2'
                                        *   '<S664>/Saturation'
                                        *   '<S665>/Integrator'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S127>/Dead Zone'
                                        *   '<S127>/Gain'
                                        *   '<S174>/Dead Zone'
                                        *   '<S174>/Gain'
                                        *   '<S316>/Land_Speed'
                                        *   '<S317>/Constant'
                                        *   '<S319>/Dead Zone'
                                        *   '<S319>/Gain'
                                        *   '<S336>/Dead Zone'
                                        *   '<S336>/Gain'
                                        *   '<S350>/Land_Speed'
                                        *   '<S351>/Constant'
                                        *   '<S353>/Dead Zone'
                                        *   '<S353>/Gain'
                                        *   '<S364>/Dead Zone'
                                        *   '<S364>/Gain'
                                        *   '<S376>/Dead Zone'
                                        *   '<S376>/Gain'
                                        *   '<S377>/Dead Zone'
                                        *   '<S377>/Gain'
                                        *   '<S402>/Dead Zone'
                                        *   '<S402>/Gain'
                                        *   '<S417>/Gain2'
                                        *   '<S417>/Saturation'
                                        *   '<S418>/Integrator'
                                        *   '<S611>/Dead Zone'
                                        *   '<S611>/Gain'
                                        *   '<S625>/Dead Zone'
                                        *   '<S625>/Gain'
                                        *   '<S645>/Dead Zone'
                                        *   '<S645>/Gain'
                                        *   '<S646>/Dead Zone'
                                        *   '<S646>/Gain'
                                        *   '<S688>/Saturation1'
                                        *   '<S698>/Saturation1'
                                        *   '<S448>/Saturation1'
                                        *   '<S458>/Saturation1'
                                        *   '<S691>/Gain2'
                                        *   '<S692>/Gain1'
                                        *   '<S701>/Gain2'
                                        *   '<S702>/Gain6'
                                        *   '<S451>/Gain2'
                                        *   '<S452>/Gain1'
                                        *   '<S461>/Gain2'
                                        *   '<S462>/Gain6'
                                        *   '<S694>/Dead Zone'
                                        *   '<S694>/Gain'
                                        *   '<S706>/Dead Zone'
                                        *   '<S706>/Gain'
                                        *   '<S707>/Dead Zone'
                                        *   '<S707>/Gain'
                                        *   '<S454>/Dead Zone'
                                        *   '<S454>/Gain'
                                        *   '<S466>/Dead Zone'
                                        *   '<S466>/Gain'
                                        *   '<S467>/Dead Zone'
                                        *   '<S467>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S23>/Constant1'
                                        *   '<S740>/Constant'
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
 *    '<S280>/NearbyRefWP'
 *    '<S258>/NearbyRefWP'
 *    '<S209>/NearbyRefWP'
 *    '<S681>/NearbyRefWP'
 *    '<S435>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S284>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S280>/SearchL1RefWP'
 *    '<S258>/SearchL1RefWP'
 *    '<S209>/SearchL1RefWP'
 *    '<S681>/SearchL1RefWP'
 *    '<S435>/SearchL1RefWP'
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

  /* SignalConversion: '<S286>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S258>/OutRegionRegWP'
 *    '<S209>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S263>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S298>/Unknown'
 *    '<S296>/Unknown'
 *    '<S295>/Unknown'
 *    '<S47>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S232>/Bus Assignment' incorporates:
   *  Constant: '<S232>/Constant'
   *  Constant: '<S232>/Constant2'
   *  SignalConversion: '<S232>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S232>/Bus Assignment' */
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
 *    '<S688>/Brake Control'
 *    '<S605>/Brake Control'
 *    '<S616>/Brake Control'
 *    '<S448>/Brake Control'
 *    '<S394>/Brake Control'
 *    '<S310>/Brake Control'
 *    '<S328>/Brake Control'
 *    '<S344>/Brake Control'
 *    '<S356>/Brake Control'
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
 *    '<S311>/Motion Status'
 *    '<S345>/Motion Status'
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
 *    '<S311>/Motion Status'
 *    '<S345>/Motion Status'
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
 *    '<S311>/Motion Status'
 *    '<S345>/Motion Status'
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
 *    '<S688>/Hold Control'
 *    '<S605>/Hold Control'
 *    '<S448>/Hold Control'
 *    '<S310>/Hold Control'
 *    '<S344>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S691>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S688>/Hold Control'
 *    '<S605>/Hold Control'
 *    '<S448>/Hold Control'
 *    '<S310>/Hold Control'
 *    '<S344>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S691>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S688>/Hold Control'
 *    '<S605>/Hold Control'
 *    '<S448>/Hold Control'
 *    '<S310>/Hold Control'
 *    '<S344>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S691>/Delay' incorporates:
   *  Gain: '<S693>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S691>/Gain2' incorporates:
   *  Delay: '<S691>/Delay'
   *  Gain: '<S693>/Gain'
   *  Sum: '<S691>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S691>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S688>/Move Control'
 *    '<S605>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S695>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S695>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S688>/Move Control'
 *    '<S605>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S695>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S695>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S688>/Move Control'
 *    '<S605>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S696>/Multiply1' incorporates:
   *  Constant: '<S696>/const1'
   *  DiscreteIntegrator: '<S695>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S694>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S694>/Dead Zone' */

  /* Sum: '<S696>/Add' incorporates:
   *  DiscreteIntegrator: '<S695>/Integrator1'
   *  Gain: '<S692>/Gain1'
   *  Gain: '<S694>/Gain'
   *  Sum: '<S695>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S696>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S696>/Sign' */

  /* Sum: '<S696>/Add2' incorporates:
   *  Abs: '<S696>/Abs'
   *  Gain: '<S696>/Gain'
   *  Gain: '<S696>/Gain1'
   *  Product: '<S696>/Multiply2'
   *  Product: '<S696>/Multiply3'
   *  Sqrt: '<S696>/Sqrt'
   *  Sum: '<S696>/Add1'
   *  Sum: '<S696>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_aw;

  /* Sum: '<S696>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_aw;

  /* Sum: '<S696>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_d + localC->d;

  /* Sum: '<S696>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S696>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S696>/Sign1' */

  /* Signum: '<S696>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S696>/Sign2' */

  /* Sum: '<S696>/Add5' incorporates:
   *  Gain: '<S696>/Gain2'
   *  Product: '<S696>/Multiply4'
   *  Sum: '<S696>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_aw - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S695>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S695>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S695>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S695>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S696>/Add6' */
  rtb_Add3_aw = rtb_a_o + localC->d;

  /* Sum: '<S696>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S696>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S696>/Sign5' */

  /* Signum: '<S696>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S696>/Sign3' */

  /* Signum: '<S696>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S696>/Sign4' */

  /* Signum: '<S696>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S696>/Sign6' */

  /* Update for DiscreteIntegrator: '<S695>/Integrator' incorporates:
   *  Constant: '<S696>/const'
   *  Gain: '<S696>/Gain3'
   *  Product: '<S696>/Divide'
   *  Product: '<S696>/Multiply5'
   *  Product: '<S696>/Multiply6'
   *  Sum: '<S696>/Subtract4'
   *  Sum: '<S696>/Subtract5'
   *  Sum: '<S696>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S689>/Motion Status'
 *    '<S606>/Motion Status'
 *    '<S449>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S689>/Motion Status'
 *    '<S606>/Motion Status'
 *    '<S449>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S689>/Motion Status'
 *    '<S606>/Motion Status'
 *    '<S449>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S689>/Motion Status' */
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

  /* End of Chart: '<S689>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S698>/Hold Control'
 *    '<S637>/Hold Control'
 *    '<S458>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S701>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S698>/Hold Control'
 *    '<S637>/Hold Control'
 *    '<S458>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S701>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S698>/Hold Control'
 *    '<S637>/Hold Control'
 *    '<S458>/Hold Control'
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

  /* Delay: '<S701>/Delay' incorporates:
   *  SignalConversion: '<S701>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S705>/Trigonometric Function1' incorporates:
   *  Gain: '<S704>/Gain'
   *  Trigonometry: '<S705>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S705>/Trigonometric Function' incorporates:
   *  Gain: '<S704>/Gain'
   *  Trigonometry: '<S705>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S705>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S705>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S705>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S705>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S705>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S705>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S705>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S701>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S701>/Delay'
   *  SignalConversion: '<S701>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S701>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S701>/Multiply' incorporates:
   *  SignalConversion: '<S701>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S701>/Multiply' */

  /* Gain: '<S701>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S701>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S698>/Brake Control'
 *    '<S637>/Brake Control'
 *    '<S458>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S700>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S698>/Move Control'
 *    '<S637>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S698>/Move Control'
 *    '<S637>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S698>/Move Control'
 *    '<S637>/Move Control'
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

  /* DiscreteIntegrator: '<S708>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S709>/Multiply1' incorporates:
   *  Constant: '<S709>/const1'
   *  DiscreteIntegrator: '<S708>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S708>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S709>/Multiply1' incorporates:
   *  Constant: '<S709>/const1'
   *  DiscreteIntegrator: '<S708>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S706>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S706>/Dead Zone' */

  /* Sum: '<S709>/Add' incorporates:
   *  DiscreteIntegrator: '<S708>/Integrator1'
   *  Gain: '<S702>/Gain6'
   *  Gain: '<S706>/Gain'
   *  Sum: '<S708>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S707>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S707>/Dead Zone' */

  /* Sum: '<S709>/Add' incorporates:
   *  DiscreteIntegrator: '<S708>/Integrator1'
   *  Gain: '<S702>/Gain6'
   *  Gain: '<S707>/Gain'
   *  Sum: '<S708>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S709>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S709>/Add2' incorporates:
   *  Abs: '<S709>/Abs'
   *  Gain: '<S709>/Gain'
   *  Gain: '<S709>/Gain1'
   *  Product: '<S709>/Multiply2'
   *  Product: '<S709>/Multiply3'
   *  Signum: '<S709>/Sign'
   *  Sqrt: '<S709>/Sqrt'
   *  Sum: '<S709>/Add1'
   *  Sum: '<S709>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S709>/Add3' incorporates:
   *  Signum: '<S709>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S709>/Subtract1' incorporates:
   *  Signum: '<S709>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S709>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S709>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S709>/Add5' incorporates:
   *  Gain: '<S709>/Gain2'
   *  Product: '<S709>/Multiply4'
   *  Signum: '<S709>/Sign'
   *  Sum: '<S709>/Add2'
   *  Sum: '<S709>/Add4'
   *  Sum: '<S709>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S708>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S708>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S709>/Sign3' incorporates:
   *  Sum: '<S709>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S709>/Sign4' incorporates:
   *  Sum: '<S709>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S709>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S709>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S709>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S709>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S708>/Integrator' incorporates:
   *  Constant: '<S709>/const'
   *  Gain: '<S709>/Gain3'
   *  Product: '<S709>/Divide'
   *  Product: '<S709>/Multiply5'
   *  Product: '<S709>/Multiply6'
   *  Sum: '<S709>/Subtract4'
   *  Sum: '<S709>/Subtract5'
   *  Sum: '<S709>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S708>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S709>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S709>/Add2' incorporates:
   *  Abs: '<S709>/Abs'
   *  Gain: '<S709>/Gain'
   *  Gain: '<S709>/Gain1'
   *  Product: '<S709>/Multiply2'
   *  Product: '<S709>/Multiply3'
   *  Signum: '<S709>/Sign'
   *  Sqrt: '<S709>/Sqrt'
   *  Sum: '<S709>/Add1'
   *  Sum: '<S709>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S709>/Add3' incorporates:
   *  Signum: '<S709>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S709>/Subtract1' incorporates:
   *  Signum: '<S709>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S709>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S709>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S709>/Add5' incorporates:
   *  Gain: '<S709>/Gain2'
   *  Product: '<S709>/Multiply4'
   *  Signum: '<S709>/Sign'
   *  Sum: '<S709>/Add2'
   *  Sum: '<S709>/Add4'
   *  Sum: '<S709>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S708>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S708>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S709>/Sign3' incorporates:
   *  Sum: '<S709>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S709>/Sign4' incorporates:
   *  Sum: '<S709>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S709>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S709>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S709>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S709>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S708>/Integrator' incorporates:
   *  Constant: '<S709>/const'
   *  Gain: '<S709>/Gain3'
   *  Product: '<S709>/Divide'
   *  Product: '<S709>/Multiply5'
   *  Product: '<S709>/Multiply6'
   *  Sum: '<S709>/Subtract4'
   *  Sum: '<S709>/Subtract5'
   *  Sum: '<S709>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S708>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S699>/Motion State'
 *    '<S638>/Motion State'
 *    '<S459>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S699>/Motion State'
 *    '<S638>/Motion State'
 *    '<S459>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S699>/Motion State'
 *    '<S638>/Motion State'
 *    '<S459>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S699>/Motion State' */
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

  /* End of Chart: '<S699>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S681>/OutRegionRegWP'
 *    '<S435>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S714>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S616>/Hold Control'
 *    '<S394>/Hold Control'
 *    '<S328>/Hold Control'
 *    '<S356>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S620>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S616>/Hold Control'
 *    '<S394>/Hold Control'
 *    '<S328>/Hold Control'
 *    '<S356>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S620>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S616>/Hold Control'
 *    '<S394>/Hold Control'
 *    '<S328>/Hold Control'
 *    '<S356>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S620>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S620>/Sum' incorporates:
   *  Delay: '<S620>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S623>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S623>/Switch' incorporates:
   *  Constant: '<S623>/Constant'
   *  Constant: '<S624>/Constant'
   *  Product: '<S623>/Multiply'
   *  RelationalOperator: '<S624>/Compare'
   *  Sum: '<S623>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S623>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S623>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S623>/Switch' */

  /* Gain: '<S620>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S620>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S616>/Move Control'
 *    '<S394>/Move Control'
 *    '<S328>/Move Control'
 *    '<S356>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S626>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S626>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S616>/Move Control'
 *    '<S394>/Move Control'
 *    '<S328>/Move Control'
 *    '<S356>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S626>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S626>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S616>/Move Control'
 *    '<S394>/Move Control'
 *    '<S328>/Move Control'
 *    '<S356>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_mb;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S627>/Multiply1' incorporates:
   *  Constant: '<S627>/const1'
   *  DiscreteIntegrator: '<S626>/Integrator'
   */
  rtb_Add3_mb = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S625>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S625>/Dead Zone' */

  /* Sum: '<S627>/Add' incorporates:
   *  DiscreteIntegrator: '<S626>/Integrator1'
   *  Gain: '<S621>/Gain1'
   *  Gain: '<S625>/Gain'
   *  Sum: '<S626>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_mb;

  /* Signum: '<S627>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
  }

  /* End of Signum: '<S627>/Sign' */

  /* Sum: '<S627>/Add2' incorporates:
   *  Abs: '<S627>/Abs'
   *  Gain: '<S627>/Gain'
   *  Gain: '<S627>/Gain1'
   *  Product: '<S627>/Multiply2'
   *  Product: '<S627>/Multiply3'
   *  Sqrt: '<S627>/Sqrt'
   *  Sum: '<S627>/Add1'
   *  Sum: '<S627>/Subtract'
   */
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_mb;

  /* Sum: '<S627>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_mb;

  /* Sum: '<S627>/Add3' */
  rtb_Add3_mb = rtb_Subtract3_e + localC->d;

  /* Sum: '<S627>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S627>/Sign1' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S627>/Sign1' */

  /* Signum: '<S627>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S627>/Sign2' */

  /* Sum: '<S627>/Add5' incorporates:
   *  Gain: '<S627>/Gain2'
   *  Product: '<S627>/Multiply4'
   *  Sum: '<S627>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_mb - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S626>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S626>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S626>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S626>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S627>/Add6' */
  rtb_Add3_mb = rtb_a_h + localC->d;

  /* Sum: '<S627>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S627>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S627>/Sign5' */

  /* Signum: '<S627>/Sign3' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S627>/Sign3' */

  /* Signum: '<S627>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S627>/Sign4' */

  /* Signum: '<S627>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S627>/Sign6' */

  /* Update for DiscreteIntegrator: '<S626>/Integrator' incorporates:
   *  Constant: '<S627>/const'
   *  Gain: '<S627>/Gain3'
   *  Product: '<S627>/Divide'
   *  Product: '<S627>/Multiply5'
   *  Product: '<S627>/Multiply6'
   *  Sum: '<S627>/Subtract4'
   *  Sum: '<S627>/Subtract5'
   *  Sum: '<S627>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_mb - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S395>/Motion State'
 *    '<S329>/Motion State'
 *    '<S357>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S395>/Motion State'
 *    '<S329>/Motion State'
 *    '<S357>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S395>/Motion State'
 *    '<S329>/Motion State'
 *    '<S357>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S395>/Motion State' */
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

  /* End of Chart: '<S395>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S310>/Move Control'
 *    '<S344>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S319>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S319>/Dead Zone' */

  /* Gain: '<S314>/Gain1' incorporates:
   *  Gain: '<S319>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S316>/Land_Speed'
   *  Constant: '<S317>/Constant'
   *  Constant: '<S318>/Constant'
   *  Gain: '<S316>/Gain'
   *  Logic: '<S314>/Logical Operator'
   *  MinMax: '<S316>/Min'
   *  RelationalOperator: '<S317>/Compare'
   *  RelationalOperator: '<S318>/Compare'
   *  S-Function (sfix_bitop): '<S314>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S314>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S745>/Switch' incorporates:
   *  Constant: '<S745>/FW_ACCEPT_R'
   *  Constant: '<S745>/MC_ACCEPT_R'
   *  Constant: '<S752>/Constant'
   *  RelationalOperator: '<S752>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S745>/Switch' */
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

  /* Math: '<S763>/Rem' incorporates:
   *  Constant: '<S763>/Constant1'
   *  Sum: '<S747>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S763>/Switch' incorporates:
   *  Abs: '<S763>/Abs'
   *  Constant: '<S763>/Constant'
   *  Constant: '<S764>/Constant'
   *  Product: '<S763>/Multiply'
   *  RelationalOperator: '<S764>/Compare'
   *  Sum: '<S763>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S763>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S763>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S763>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S750>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S769>/Sum of Elements' incorporates:
   *  Math: '<S769>/Math Function'
   *  SignalConversion: '<S769>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S769>/Math Function1' incorporates:
   *  Sum: '<S769>/Sum of Elements'
   *
   * About '<S769>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S769>/Math Function1' */

  /* Switch: '<S769>/Switch' incorporates:
   *  Constant: '<S769>/Constant'
   *  Product: '<S769>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S769>/Switch' */

  /* Product: '<S769>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S767>/Subtract' incorporates:
   *  Product: '<S767>/Multiply'
   *  Product: '<S767>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S766>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S766>/Sign1' */

  /* Switch: '<S766>/Switch2' incorporates:
   *  Constant: '<S766>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S766>/Switch2' */

  /* DotProduct: '<S766>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S766>/Acos' incorporates:
   *  DotProduct: '<S766>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S766>/Multiply' incorporates:
   *  Trigonometry: '<S766>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S750>/Switch' incorporates:
   *  Bias: '<S750>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S750>/Switch' */
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

  /* Gain: '<S753>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S754>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S754>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S754>/Multiply1' incorporates:
   *  Product: '<S754>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S754>/Divide' incorporates:
   *  Constant: '<S754>/Constant'
   *  Constant: '<S754>/R'
   *  Sqrt: '<S754>/Sqrt'
   *  Sum: '<S754>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S754>/Product3' incorporates:
   *  Constant: '<S754>/Constant1'
   *  Product: '<S754>/Multiply1'
   *  Sum: '<S754>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S754>/Multiply2' incorporates:
   *  Trigonometry: '<S754>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S753>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S758>/Abs' incorporates:
   *  Abs: '<S761>/Abs1'
   *  Switch: '<S758>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S758>/Switch1' incorporates:
   *  Abs: '<S758>/Abs'
   *  Bias: '<S758>/Bias2'
   *  Bias: '<S758>/Bias3'
   *  Constant: '<S755>/Constant'
   *  Constant: '<S755>/Constant1'
   *  Constant: '<S760>/Constant'
   *  Gain: '<S758>/Gain1'
   *  Product: '<S758>/Multiply'
   *  RelationalOperator: '<S760>/Compare'
   *  Switch: '<S755>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S761>/Switch1' incorporates:
     *  Bias: '<S761>/Bias2'
     *  Bias: '<S761>/Bias3'
     *  Constant: '<S761>/Constant'
     *  Constant: '<S762>/Constant'
     *  Math: '<S761>/Math Function'
     *  RelationalOperator: '<S762>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S761>/Switch1' */

    /* Signum: '<S758>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S758>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S755>/Sum' incorporates:
   *  Sum: '<S753>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S753>/Multiply' incorporates:
   *  Gain: '<S753>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S757>/Switch1' incorporates:
   *  Abs: '<S757>/Abs1'
   *  Bias: '<S757>/Bias2'
   *  Bias: '<S757>/Bias3'
   *  Constant: '<S757>/Constant'
   *  Constant: '<S759>/Constant'
   *  Math: '<S757>/Math Function'
   *  RelationalOperator: '<S759>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S757>/Switch1' */

  /* Product: '<S753>/Multiply' incorporates:
   *  Gain: '<S753>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S753>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S756>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S756>/Sum2' incorporates:
   *  Product: '<S756>/Multiply1'
   *  Product: '<S756>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S756>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S756>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S756>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S746>/Data Type Conversion' incorporates:
   *  Gain: '<S753>/Gain'
   *  Sum: '<S753>/Sum1'
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
  /* RelationalOperator: '<S765>/Compare' incorporates:
   *  Abs: '<S749>/Abs'
   *  Constant: '<S765>/Constant'
   *  MinMax: '<S749>/Max'
   *  Sum: '<S749>/Sum'
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
      /* Reshape: '<S748>/Reshape' incorporates:
       *  Constant: '<S748>/Constant'
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
        if (fabsf(FMS_B.DiscreteTimeIntegrator5_p) < 1.0F) {
          b_sf_internal_predicateOutput = true;
        } else if (FMS_DW.temporalCounter_i2 >= 5000U) {
          b_sf_internal_predicateOutput = true;
        } else {
          FMS_B.flag = FMS_B.BusConversion_InsertedFor_FMSSt.flag;

          /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.IsPosValid' */
          /* RelationalOperator: '<S751>/Compare' incorporates:
           *  Constant: '<S751>/Constant'
           *  S-Function (sfix_bitop): '<S743>/Bitwise AND'
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
          /* RelationalOperator: '<S744>/Relational Operator1' incorporates:
           *  Constant: '<S744>/Constant1'
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
        /* RelationalOperator: '<S742>/Relational Operator' incorporates:
         *  Constant: '<S742>/Constant'
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
          /* RelationalOperator: '<S741>/Relational Operator1' incorporates:
           *  Constant: '<S741>/Constant1'
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
   *  ActionPort: '<S196>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S196>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S200>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S46>/SubMode' incorporates:
   *  ActionPort: '<S88>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
   *  ActionPort: '<S230>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Takeoff' incorporates:
   *  ActionPort: '<S231>/Action Port'
   */
  /* SwitchCase: '<S86>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S219>/Math Function'
   *  Math: '<S268>/Math Function'
   *  Math: '<S290>/Math Function'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S88>/Switch Case'
   */
  rtb_Sign5_l = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_a_bx = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S88>/Takeoff' */
  /* End of Outputs for SubSystem: '<S88>/Return' */
  /* End of Outputs for SubSystem: '<S196>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S86>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */

  /* Outputs for IfAction SubSystem: '<S41>/MC_Mode' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
   *  ActionPort: '<S296>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S296>/Mission' incorporates:
   *  ActionPort: '<S407>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S407>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S411>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
   *  ActionPort: '<S298>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S298>/Return' incorporates:
   *  ActionPort: '<S599>/Action Port'
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
   *  ActionPort: '<S228>/Action Port'
   */
  /* SwitchCase: '<S135>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sqrt: '<S156>/Sqrt'
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S218>/Sqrt'
   *  Sqrt: '<S244>/Sqrt'
   *  Sqrt: '<S267>/Sqrt'
   *  Sqrt: '<S370>/Sqrt'
   *  Sqrt: '<S477>/Sqrt'
   *  Sqrt: '<S66>/Sqrt'
   *  Sqrt: '<S717>/Sqrt'
   *  Sum: '<S158>/Sum of Elements'
   *  Sum: '<S1>/Add'
   *  Sum: '<S245>/Sum of Elements'
   *  Sum: '<S479>/Sum of Elements'
   *  Sum: '<S68>/Sum of Elements'
   *  Sum: '<S719>/Sum of Elements'
   *  Switch: '<S138>/Switch'
   *  Switch: '<S48>/Switch'
   *  SwitchCase: '<S295>/Switch Case'
   *  SwitchCase: '<S296>/Switch Case'
   *  SwitchCase: '<S298>/Switch Case'
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
   *  ActionPort: '<S295>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S295>/Position' incorporates:
   *  ActionPort: '<S302>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
   *  ActionPort: '<S86>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
   *  ActionPort: '<S196>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S196>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S200>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
   *  ActionPort: '<S230>/Action Port'
   */
  rtb_Divide_lr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);

  /* End of Outputs for SubSystem: '<S88>/Return' */
  /* End of Outputs for SubSystem: '<S196>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S86>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */
  /* End of Outputs for SubSystem: '<S295>/Position' */
  /* End of Outputs for SubSystem: '<S47>/Assist' */
  /* End of Outputs for SubSystem: '<S88>/Hold' */
  /* End of Outputs for SubSystem: '<S135>/Hold Control' */
  /* End of Outputs for SubSystem: '<S85>/Position' */
  /* End of Outputs for SubSystem: '<S46>/Assist' */
  /* End of Outputs for SubSystem: '<S41>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S298>/Return' */
  /* End of Outputs for SubSystem: '<S47>/SubMode' */
  /* End of Outputs for SubSystem: '<S407>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S296>/Mission' */
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
        /* Disable for SwitchCase: '<S298>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S698>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S688>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S637>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S605>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S616>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S296>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S407>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S458>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S448>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S407>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S295>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S394>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S310>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S328>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S344>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S369>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S356>/Switch Case' */
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
          /* Disable for SwitchCase: '<S298>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S698>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S688>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S637>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S605>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S616>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S296>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S407>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S458>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S448>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S407>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S295>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S394>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S310>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S328>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S344>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S369>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S356>/Switch Case' */
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
           *  ActionPort: '<S231>/Action Port'
           */
          /* Sum: '<S290>/Sum of Elements' incorporates:
           *  Sum: '<S289>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Sign5_l + rtb_a_bx;

          /* Math: '<S290>/Math Function1' incorporates:
           *  Sum: '<S290>/Sum of Elements'
           *
           * About '<S290>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S290>/Math Function1' */

          /* Switch: '<S290>/Switch' incorporates:
           *  Constant: '<S290>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S290>/Product'
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

          /* End of Switch: '<S290>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S280>/NearbyRefWP' incorporates:
           *  Constant: '<S278>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_i5,
                          &rtb_Divide_lr_idx_2);

          /* MATLAB Function: '<S280>/SearchL1RefWP' incorporates:
           *  Constant: '<S278>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Divide_lr_idx_3);

          /* MATLAB Function: '<S280>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S275>/Sum'
           *  Sum: '<S275>/Sum1'
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

          /* End of MATLAB Function: '<S280>/OutRegionRegWP' */

          /* Switch: '<S280>/Switch1' incorporates:
           *  Constant: '<S283>/Constant'
           *  RelationalOperator: '<S283>/Compare'
           */
          if (rtb_Divide_lr_idx_2 <= 0.0F) {
            /* Switch: '<S280>/Switch' incorporates:
             *  Constant: '<S282>/Constant'
             *  RelationalOperator: '<S282>/Compare'
             */
            if (rtb_Divide_lr_idx_3 >= 0.0F) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            } else {
              rtb_Divide_i5[0] = rtb_P_dg[0];
              rtb_Divide_i5[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S280>/Switch' */
          }

          /* End of Switch: '<S280>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S281>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S291>/Sum of Elements' incorporates:
           *  Math: '<S291>/Math Function'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

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
            rtb_Switch_an[0] = rtb_Subtract_hb[0];
            rtb_Switch_an[1] = rtb_Subtract_hb[1];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S291>/Switch' */

          /* Product: '<S290>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S293>/Sum of Elements' incorporates:
           *  Math: '<S293>/Math Function'
           *  SignalConversion: '<S293>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S293>/Math Function1' incorporates:
           *  Sum: '<S293>/Sum of Elements'
           *
           * About '<S293>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S293>/Math Function1' */

          /* Switch: '<S293>/Switch' incorporates:
           *  Constant: '<S293>/Constant'
           *  Product: '<S293>/Product'
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

          /* End of Switch: '<S293>/Switch' */

          /* Product: '<S291>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Subtract_hb[1];
            rtb_Switch_an[1] = rtb_Subtract_hb[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S294>/Switch' */

          /* Product: '<S294>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S293>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S294>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S293>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S275>/Divide' incorporates:
           *  Math: '<S276>/Square'
           *  Math: '<S277>/Square'
           *  Sqrt: '<S276>/Sqrt'
           *  Sqrt: '<S277>/Sqrt'
           *  Sum: '<S276>/Sum of Elements'
           *  Sum: '<S277>/Sum of Elements'
           */
          rtb_Divide_pr_idx_2 = sqrtf(rtb_Sign5_l * rtb_Sign5_l +
            rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2) / sqrtf
            (rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0 + d * d);

          /* Saturate: '<S275>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S275>/Saturation' */

          /* Sum: '<S292>/Subtract' incorporates:
           *  Product: '<S292>/Multiply'
           *  Product: '<S292>/Multiply1'
           */
          rtb_Divide_pr_idx_1 = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S288>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S288>/Sign1' */

          /* Switch: '<S288>/Switch2' incorporates:
           *  Constant: '<S288>/Constant4'
           */
          if (rtb_Divide_pr_idx_1 == 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }

          /* End of Switch: '<S288>/Switch2' */

          /* DotProduct: '<S288>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S288>/Acos' incorporates:
           *  DotProduct: '<S288>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S288>/Multiply' incorporates:
           *  Trigonometry: '<S288>/Acos'
           */
          rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S287>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.57079637F) {
            rtb_Divide_pr_idx_1 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_1 < -1.57079637F) {
              rtb_Divide_pr_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S287>/Saturation' */

          /* Sqrt: '<S289>/Sqrt' */
          rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation_e);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S231>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S231>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S231>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S231>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S287>/Divide' incorporates:
           *  Constant: '<S278>/L1'
           *  Gain: '<S287>/Gain'
           *  Math: '<S287>/Square'
           *  Product: '<S287>/Multiply1'
           *  Trigonometry: '<S287>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Divide_pr_idx_1) / FMS_PARAM.FW_L1;

          /* Saturate: '<S278>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S278>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S273>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S275>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S273>/Sum2'
           *  Sum: '<S275>/Add'
           *  Sum: '<S275>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_2 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S273>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S273>/Saturation1' */
          /* End of Outputs for SubSystem: '<S88>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S88>/Land' incorporates:
           *  ActionPort: '<S229>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S229>/Bus Assignment1'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S229>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S229>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S229>/Constant'
           *  Constant: '<S229>/Constant4'
           *  Constant: '<S229>/Constant5'
           *  Constant: '<S229>/Constant7'
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
           *  ActionPort: '<S230>/Action Port'
           */
          /* Math: '<S268>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Sign5_l;
          rtb_Subtract_hb[1] = rtb_a_bx;

          /* Sum: '<S268>/Sum of Elements' */
          rtb_Saturation_e = rtb_Sign5_l + rtb_a_bx;

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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S268>/Product'
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

          /* End of Switch: '<S268>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S258>/NearbyRefWP' incorporates:
           *  Constant: '<S256>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Divide_pr_idx_1);

          /* MATLAB Function: '<S258>/SearchL1RefWP' incorporates:
           *  Constant: '<S256>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_i5, &rtb_Saturation_e);

          /* MATLAB Function: '<S258>/OutRegionRegWP' incorporates:
           *  Constant: '<S256>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_cg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S258>/Switch1' incorporates:
           *  Constant: '<S261>/Constant'
           *  RelationalOperator: '<S261>/Compare'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_i5[0] = rtb_Subtract_hb[0];
            rtb_Divide_i5[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S260>/Compare' incorporates:
             *  Constant: '<S260>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_e >= 0.0F);

            /* Switch: '<S258>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            }

            /* End of Switch: '<S258>/Switch' */
          }

          /* End of Switch: '<S258>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S259>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S269>/Sum of Elements' incorporates:
           *  Math: '<S269>/Math Function'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

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
            rtb_Switch_an[0] = rtb_Subtract_hb[0];
            rtb_Switch_an[1] = rtb_Subtract_hb[1];
            rtb_Switch_an[2] = rtb_Saturation_e;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S269>/Switch' */

          /* Product: '<S268>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S271>/Sum of Elements' incorporates:
           *  Math: '<S271>/Math Function'
           *  SignalConversion: '<S271>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S271>/Math Function1' incorporates:
           *  Sum: '<S271>/Sum of Elements'
           *
           * About '<S271>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S271>/Math Function1' */

          /* Switch: '<S271>/Switch' incorporates:
           *  Constant: '<S271>/Constant'
           *  Product: '<S271>/Product'
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

          /* End of Switch: '<S271>/Switch' */

          /* Product: '<S269>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Subtract_hb[1];
            rtb_Switch_an[1] = rtb_Subtract_hb[0];
            rtb_Switch_an[2] = rtb_Saturation_e;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S272>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S253>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S272>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S271>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S253>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S272>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S271>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S253>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S253>/Divide' incorporates:
           *  Math: '<S254>/Square'
           *  Math: '<S255>/Square'
           *  Sqrt: '<S254>/Sqrt'
           *  Sqrt: '<S255>/Sqrt'
           *  Sum: '<S253>/Sum'
           *  Sum: '<S253>/Sum1'
           *  Sum: '<S254>/Sum of Elements'
           *  Sum: '<S255>/Sum of Elements'
           */
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3
            + rtb_Saturation_e * rtb_Saturation_e) / sqrtf(rtb_Sign5_l *
            rtb_Sign5_l + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2);

          /* Saturate: '<S253>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S253>/Saturation' */

          /* Sum: '<S270>/Subtract' incorporates:
           *  Product: '<S270>/Multiply'
           *  Product: '<S270>/Multiply1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S266>/Sign1' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S266>/Sign1' */

          /* Switch: '<S266>/Switch2' incorporates:
           *  Constant: '<S266>/Constant4'
           */
          if (rtb_Saturation_e == 0.0F) {
            rtb_Saturation_e = 1.0F;
          }

          /* End of Switch: '<S266>/Switch2' */

          /* DotProduct: '<S266>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S266>/Acos' incorporates:
           *  DotProduct: '<S266>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S266>/Multiply' incorporates:
           *  Trigonometry: '<S266>/Acos'
           */
          rtb_Saturation_e *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S265>/Saturation' */
          if (rtb_Saturation_e > 1.57079637F) {
            rtb_Saturation_e = 1.57079637F;
          } else {
            if (rtb_Saturation_e < -1.57079637F) {
              rtb_Saturation_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S265>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S230>/Bus Assignment1'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S230>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S230>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S265>/Divide' incorporates:
           *  Constant: '<S256>/L1'
           *  Gain: '<S265>/Gain'
           *  Math: '<S265>/Square'
           *  Product: '<S265>/Multiply1'
           *  Trigonometry: '<S265>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_e) / FMS_PARAM.FW_L1;

          /* Saturate: '<S256>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S256>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S251>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S253>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S251>/Sum2'
           *  Sum: '<S253>/Add'
           *  Sum: '<S253>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S251>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S251>/Saturation1' */
          /* End of Outputs for SubSystem: '<S88>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S88>/Hold' incorporates:
             *  ActionPort: '<S228>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S88>/Switch Case' incorporates:
             *  Delay: '<S233>/Delay'
             *  Delay: '<S238>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S88>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Hold' incorporates:
           *  ActionPort: '<S228>/Action Port'
           */
          /* Math: '<S245>/Math Function1'
           *
           * About '<S245>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S245>/Math Function1' */

          /* Switch: '<S245>/Switch' incorporates:
           *  Constant: '<S245>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S245>/Product'
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

          /* End of Switch: '<S245>/Switch' */

          /* Delay: '<S238>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l3[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l3[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S250>/Sum of Elements' incorporates:
           *  Delay: '<S238>/start_vel'
           *  Math: '<S250>/Math Function'
           */
          rtb_Saturation_e = FMS_DW.start_vel_DSTATE_l3[0] *
            FMS_DW.start_vel_DSTATE_l3[0] + FMS_DW.start_vel_DSTATE_l3[1] *
            FMS_DW.start_vel_DSTATE_l3[1];

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
           *  Delay: '<S238>/start_vel'
           *  Product: '<S250>/Product'
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

          /* End of Switch: '<S250>/Switch' */

          /* Product: '<S245>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S248>/Sum of Elements' incorporates:
           *  Math: '<S248>/Math Function'
           *  SignalConversion: '<S248>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S248>/Math Function1' incorporates:
           *  Sum: '<S248>/Sum of Elements'
           *
           * About '<S248>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S248>/Math Function1' */

          /* Switch: '<S248>/Switch' incorporates:
           *  Constant: '<S248>/Constant'
           *  Product: '<S248>/Product'
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

          /* End of Switch: '<S248>/Switch' */

          /* MinMax: '<S236>/Max' incorporates:
           *  Constant: '<S234>/L1'
           *  Constant: '<S234>/R'
           *  Gain: '<S236>/Gain'
           */
          rtb_Divide_pr_idx_1 = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S236>/SearchL1RefWP' incorporates:
           *  Constant: '<S234>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S241>/TmpSignal ConversionAt SFunction Inport2'
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

          /* End of MATLAB Function: '<S236>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S239>/Compare' incorporates:
           *  Constant: '<S239>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S236>/OutRegionRegWP' incorporates:
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

          /* Switch: '<S236>/Switch' incorporates:
           *  Constant: '<S234>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S236>/OutRegionRegWP'
           *  Product: '<S250>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_e = rtb_P_cg[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] >
                     rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S236>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S237>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_ds[0] = rtb_Saturation_e - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S236>/Switch' incorporates:
           *  Constant: '<S234>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S236>/OutRegionRegWP'
           *  Product: '<S250>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_e = rtb_P_cg[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] >
                     rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S236>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S237>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_ds[1] = rtb_Saturation_e - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S246>/Sum of Elements' incorporates:
           *  Math: '<S246>/Math Function'
           */
          rtb_Saturation_e = rtb_Square_ds[0] * rtb_Square_ds[0] +
            rtb_Square_ds[1] * rtb_Square_ds[1];

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
            rtb_Switch_ee[0] = rtb_Square_ds[0];
            rtb_Switch_ee[1] = rtb_Square_ds[1];
            rtb_Switch_ee[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_ee[0] = 0.0F;
            rtb_Switch_ee[1] = 0.0F;
            rtb_Switch_ee[2] = 1.0F;
          }

          /* End of Switch: '<S246>/Switch' */

          /* Product: '<S246>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];
          rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

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
            rtb_Switch_ee[0] = rtb_Divide_i5[1];
            rtb_Switch_ee[1] = rtb_Divide_i5[0];
            rtb_Switch_ee[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_ee[0] = 0.0F;
            rtb_Switch_ee[1] = 0.0F;
            rtb_Switch_ee[2] = 1.0F;
          }

          /* End of Switch: '<S249>/Switch' */

          /* Product: '<S249>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];

          /* Product: '<S248>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S249>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

          /* Product: '<S248>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S247>/Subtract' incorporates:
           *  Product: '<S247>/Multiply'
           *  Product: '<S247>/Multiply1'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] * rtb_Subtract_hb[1] -
            rtb_Divide_i5[1] * rtb_Subtract_hb[0];

          /* Signum: '<S243>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S243>/Sign1' */

          /* Switch: '<S243>/Switch2' incorporates:
           *  Constant: '<S243>/Constant4'
           */
          if (rtb_Divide_pr_idx_1 == 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }

          /* End of Switch: '<S243>/Switch2' */

          /* DotProduct: '<S243>/Dot Product' */
          rtb_Divide_pr_idx_2 = rtb_Subtract_hb[0] * rtb_Divide_i5[0] +
            rtb_Subtract_hb[1] * rtb_Divide_i5[1];

          /* Trigonometry: '<S243>/Acos' incorporates:
           *  DotProduct: '<S243>/Dot Product'
           */
          if (rtb_Divide_pr_idx_2 > 1.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            }
          }

          /* Product: '<S243>/Multiply' incorporates:
           *  Trigonometry: '<S243>/Acos'
           */
          rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_2);

          /* Saturate: '<S242>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.57079637F) {
            rtb_Divide_pr_idx_1 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_1 < -1.57079637F) {
              rtb_Divide_pr_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S242>/Saturation' */

          /* Delay: '<S233>/Delay' incorporates:
           *  Gain: '<S235>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S228>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S228>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S228>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S228>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S242>/Divide' incorporates:
           *  Constant: '<S234>/L1'
           *  Gain: '<S242>/Gain'
           *  Math: '<S242>/Square'
           *  Product: '<S242>/Multiply1'
           *  Trigonometry: '<S242>/Sin'
           */
          rtb_Saturation_e = 2.0F * (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2) *
            arm_sin_f32(rtb_Divide_pr_idx_1) / FMS_PARAM.FW_L1;

          /* Saturate: '<S234>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S234>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S233>/Gain2' incorporates:
           *  Delay: '<S233>/Delay'
           *  Gain: '<S235>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S233>/Sum'
           */
          rtb_Saturation_e = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S233>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S233>/Saturation1' */

          /* Update for Delay: '<S238>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S233>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S88>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S88>/Unknown' incorporates:
           *  ActionPort: '<S232>/Action Port'
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
         *  RelationalOperator: '<S199>/FixPt Relational Operator'
         *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S199>/Delay Input1'
         *
         * Block description for '<S199>/Delay Input1':
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
           *  ActionPort: '<S197>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S197>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S197>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S197>/Bus Assignment' incorporates:
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
             *  ActionPort: '<S196>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S86>/Switch Case' incorporates:
             *  UnitDelay: '<S199>/Delay Input1'
             *
             * Block description for '<S199>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S86>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
           *  ActionPort: '<S196>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S196>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S200>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S219>/Math Function' incorporates:
           *  RelationalOperator: '<S199>/FixPt Relational Operator'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S199>/Delay Input1'
           *
           * Block description for '<S199>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Subtract_hb[0] = rtb_Sign5_l;
          rtb_Subtract_hb[1] = rtb_a_bx;

          /* Sum: '<S219>/Sum of Elements' */
          rtb_Saturation_e = rtb_Sign5_l + rtb_a_bx;

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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S219>/Product'
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

          /* End of Switch: '<S219>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S209>/NearbyRefWP' incorporates:
           *  Constant: '<S207>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Divide_pr_idx_1);

          /* MATLAB Function: '<S209>/SearchL1RefWP' incorporates:
           *  Constant: '<S207>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_i5, &rtb_Saturation_e);

          /* MATLAB Function: '<S209>/OutRegionRegWP' incorporates:
           *  Constant: '<S207>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_cg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S209>/Switch1' incorporates:
           *  Constant: '<S212>/Constant'
           *  RelationalOperator: '<S212>/Compare'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_i5[0] = rtb_Subtract_hb[0];
            rtb_Divide_i5[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S211>/Compare' incorporates:
             *  Constant: '<S211>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_e >= 0.0F);

            /* Switch: '<S209>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            }

            /* End of Switch: '<S209>/Switch' */
          }

          /* End of Switch: '<S209>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S210>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S220>/Sum of Elements' incorporates:
           *  Math: '<S220>/Math Function'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

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
            rtb_Switch_an[0] = rtb_Subtract_hb[0];
            rtb_Switch_an[1] = rtb_Subtract_hb[1];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S220>/Switch' */

          /* Product: '<S219>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S222>/Sum of Elements' incorporates:
           *  Math: '<S222>/Math Function'
           *  SignalConversion: '<S222>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S222>/Math Function1' incorporates:
           *  Sum: '<S222>/Sum of Elements'
           *
           * About '<S222>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S222>/Math Function1' */

          /* Switch: '<S222>/Switch' incorporates:
           *  Constant: '<S222>/Constant'
           *  Product: '<S222>/Product'
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

          /* End of Switch: '<S222>/Switch' */

          /* Product: '<S220>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Subtract_hb[1];
            rtb_Switch_an[1] = rtb_Subtract_hb[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S223>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S204>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S223>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S222>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S204>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S223>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S222>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S204>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S204>/Divide' incorporates:
           *  Math: '<S205>/Square'
           *  Math: '<S206>/Square'
           *  Sqrt: '<S205>/Sqrt'
           *  Sqrt: '<S206>/Sqrt'
           *  Sum: '<S204>/Sum'
           *  Sum: '<S204>/Sum1'
           *  Sum: '<S205>/Sum of Elements'
           *  Sum: '<S206>/Sum of Elements'
           */
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3
            + rtb_Saturation_e * rtb_Saturation_e) / sqrtf(rtb_Sign5_l *
            rtb_Sign5_l + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2);

          /* Saturate: '<S204>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S204>/Saturation' */

          /* Sum: '<S221>/Subtract' incorporates:
           *  Product: '<S221>/Multiply'
           *  Product: '<S221>/Multiply1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S217>/Sign1' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S217>/Sign1' */

          /* Switch: '<S217>/Switch2' incorporates:
           *  Constant: '<S217>/Constant4'
           */
          if (rtb_Saturation_e == 0.0F) {
            rtb_Saturation_e = 1.0F;
          }

          /* End of Switch: '<S217>/Switch2' */

          /* DotProduct: '<S217>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S217>/Acos' incorporates:
           *  DotProduct: '<S217>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S217>/Multiply' incorporates:
           *  Trigonometry: '<S217>/Acos'
           */
          rtb_Saturation_e *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S216>/Saturation' */
          if (rtb_Saturation_e > 1.57079637F) {
            rtb_Saturation_e = 1.57079637F;
          } else {
            if (rtb_Saturation_e < -1.57079637F) {
              rtb_Saturation_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S216>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S200>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S200>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S200>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S202>/Switch' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
          } else {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Constant: '<S202>/Constant4'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S202>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S216>/Divide' incorporates:
           *  Constant: '<S207>/L1'
           *  Gain: '<S216>/Gain'
           *  Math: '<S216>/Square'
           *  Product: '<S216>/Multiply1'
           *  Trigonometry: '<S216>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_e) / FMS_PARAM.FW_L1;

          /* Saturate: '<S207>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S207>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S201>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S204>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S201>/Sum2'
           *  Sum: '<S204>/Add'
           *  Sum: '<S204>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S201>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S200>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S201>/Saturation1' */
          /* End of Outputs for SubSystem: '<S196>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S199>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S199>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S86>/Unknown' incorporates:
           *  ActionPort: '<S198>/Action Port'
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
             *  DiscreteIntegrator: '<S189>/Integrator'
             *  DiscreteIntegrator: '<S189>/Integrator1'
             *  DiscreteIntegrator: '<S190>/Integrator'
             *  DiscreteIntegrator: '<S190>/Integrator1'
             *  DiscreteIntegrator: '<S194>/Integrator'
             *  DiscreteIntegrator: '<S194>/Integrator1'
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
          /* Product: '<S191>/Multiply1' incorporates:
           *  Constant: '<S191>/const1'
           *  DiscreteIntegrator: '<S189>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S187>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S187>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S191>/Add' incorporates:
           *  DiscreteIntegrator: '<S189>/Integrator1'
           *  Gain: '<S184>/Gain'
           *  Gain: '<S187>/Gain'
           *  Sum: '<S189>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ROLL_LIM) +
            rtb_a_bx;

          /* Signum: '<S191>/Sign' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S191>/Sign' */

          /* Sum: '<S191>/Add2' incorporates:
           *  Abs: '<S191>/Abs'
           *  Gain: '<S191>/Gain'
           *  Gain: '<S191>/Gain1'
           *  Product: '<S191>/Multiply2'
           *  Product: '<S191>/Multiply3'
           *  Sqrt: '<S191>/Sqrt'
           *  Sum: '<S191>/Add1'
           *  Sum: '<S191>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) + FMS_ConstB.d_ny) *
                     FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_a_bx;

          /* Sum: '<S191>/Add4' */
          rtb_Saturation_e = (rtb_Divide_lr_idx_2 - d) + rtb_a_bx;

          /* Sum: '<S191>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ny;

          /* Sum: '<S191>/Subtract1' */
          rtb_Divide_lr_idx_2 -= FMS_ConstB.d_ny;

          /* Signum: '<S191>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S191>/Sign1' */

          /* Signum: '<S191>/Sign2' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S191>/Sign2' */

          /* Sum: '<S191>/Add5' incorporates:
           *  Gain: '<S191>/Gain2'
           *  Product: '<S191>/Multiply4'
           *  Sum: '<S191>/Subtract2'
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
           *  DiscreteIntegrator: '<S189>/Integrator1'
           *  DiscreteIntegrator: '<S190>/Integrator1'
           *  DiscreteIntegrator: '<S194>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S186>/Saturation' incorporates:
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

          /* End of Saturate: '<S186>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S92>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S186>/Constant5'
           *  Gain: '<S186>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S186>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_Saturation_e), 65536.0F) + 1000U);

          /* Product: '<S195>/Multiply1' incorporates:
           *  Constant: '<S195>/const1'
           *  DiscreteIntegrator: '<S194>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S193>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S193>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S195>/Add' incorporates:
           *  DiscreteIntegrator: '<S194>/Integrator1'
           *  Gain: '<S185>/Gain1'
           *  Gain: '<S193>/Gain'
           *  Sum: '<S194>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_bx;

          /* Signum: '<S195>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S195>/Sign' */

          /* Sum: '<S195>/Add2' incorporates:
           *  Abs: '<S195>/Abs'
           *  Gain: '<S195>/Gain'
           *  Gain: '<S195>/Gain1'
           *  Product: '<S195>/Multiply2'
           *  Product: '<S195>/Multiply3'
           *  Sqrt: '<S195>/Sqrt'
           *  Sum: '<S195>/Add1'
           *  Sum: '<S195>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_hr) * FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_a_bx;

          /* Sum: '<S195>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_a_bx;

          /* Sum: '<S195>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_hr;

          /* Sum: '<S195>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_hr;

          /* Signum: '<S195>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S195>/Sign1' */

          /* Signum: '<S195>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S195>/Sign2' */

          /* Sum: '<S195>/Add5' incorporates:
           *  Gain: '<S195>/Gain2'
           *  Product: '<S195>/Multiply4'
           *  Sum: '<S195>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Sum: '<S195>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_hr;

          /* Sum: '<S195>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_hr;

          /* Product: '<S195>/Divide' */
          rtb_Divide_or = rtb_Divide_lr_idx_2 / FMS_ConstB.d_hr;

          /* Signum: '<S195>/Sign5' incorporates:
           *  Signum: '<S195>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S195>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S195>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Divide_lr_idx_2;

            /* Signum: '<S195>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S195>/Sign5' */

          /* Product: '<S192>/Multiply1' incorporates:
           *  Constant: '<S192>/const1'
           *  DiscreteIntegrator: '<S190>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S188>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S188>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S192>/Add' incorporates:
           *  DiscreteIntegrator: '<S190>/Integrator1'
           *  Gain: '<S184>/Gain1'
           *  Gain: '<S188>/Gain'
           *  Sum: '<S190>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S192>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
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
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation_e) + FMS_ConstB.d_my) *
                            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S192>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_Saturation_e - rtb_a_bx) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S192>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_my;

          /* Sum: '<S192>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_my;

          /* Signum: '<S192>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
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
          rtb_a_bx += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Update for DiscreteIntegrator: '<S189>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S189>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S191>/Subtract3' */
          rtb_Divide_lr_idx_2 = d - FMS_ConstB.d_ny;

          /* Sum: '<S191>/Add6' */
          rtb_Divide_lr_idx_3 = d + FMS_ConstB.d_ny;

          /* Signum: '<S191>/Sign5' incorporates:
           *  Signum: '<S191>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S191>/Sign6' */
            rtb_Saturation_e = -1.0F;
          } else if (d > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S191>/Sign6' */
            rtb_Saturation_e = 1.0F;
          } else {
            rtb_Sign5_l = d;

            /* Signum: '<S191>/Sign6' */
            rtb_Saturation_e = d;
          }

          /* End of Signum: '<S191>/Sign5' */

          /* Signum: '<S191>/Sign3' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S191>/Sign3' */

          /* Signum: '<S191>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S191>/Sign4' */

          /* Update for DiscreteIntegrator: '<S189>/Integrator' incorporates:
           *  Constant: '<S191>/const'
           *  Gain: '<S191>/Gain3'
           *  Product: '<S191>/Divide'
           *  Product: '<S191>/Multiply5'
           *  Product: '<S191>/Multiply6'
           *  Sum: '<S191>/Subtract4'
           *  Sum: '<S191>/Subtract5'
           *  Sum: '<S191>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((d / FMS_ConstB.d_ny - rtb_Sign5_l) *
            FMS_ConstB.Gain4_ko * ((rtb_Divide_lr_idx_3 - rtb_Divide_lr_idx_2) *
            0.5F) - rtb_Saturation_e * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S190>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S190>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S194>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S194>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S195>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S195>/Sign3' */

          /* Signum: '<S195>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S195>/Sign4' */

          /* Update for DiscreteIntegrator: '<S194>/Integrator' incorporates:
           *  Constant: '<S195>/const'
           *  Gain: '<S195>/Gain3'
           *  Product: '<S195>/Multiply5'
           *  Product: '<S195>/Multiply6'
           *  Sum: '<S195>/Subtract4'
           *  Sum: '<S195>/Subtract5'
           *  Sum: '<S195>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
            0.5F) - rtb_Divide_pr_idx_2 * 15.707963F) * 0.004F;

          /* Sum: '<S192>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S192>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S192>/Sign5' incorporates:
           *  Signum: '<S192>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S192>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S192>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_a_bx;

            /* Signum: '<S192>/Sign6' */
            rtb_Sign5_l = rtb_a_bx;
          }

          /* End of Signum: '<S192>/Sign5' */

          /* Signum: '<S192>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign3' */

          /* Signum: '<S192>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
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
             *  DiscreteIntegrator: '<S182>/Integrator'
             *  DiscreteIntegrator: '<S182>/Integrator1'
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
           *  DiscreteIntegrator: '<S182>/Integrator1'
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

          /* Product: '<S183>/Multiply1' incorporates:
           *  Constant: '<S183>/const1'
           *  DiscreteIntegrator: '<S182>/Integrator'
           */
          rtb_Divide_lr_idx_3 = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S120>/Saturation' incorporates:
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

          /* End of Saturate: '<S120>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S183>/Add' incorporates:
           *  DiscreteIntegrator: '<S182>/Integrator1'
           *  Gain: '<S120>/Gain'
           *  Sum: '<S182>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_nd -
                              FMS_PARAM.FW_SPEED_MAX * rtb_Saturation_e) +
            rtb_Divide_lr_idx_3;

          /* Signum: '<S183>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Saturation_e;
          }

          /* End of Signum: '<S183>/Sign' */

          /* Sum: '<S183>/Add2' incorporates:
           *  Abs: '<S183>/Abs'
           *  Gain: '<S183>/Gain'
           *  Gain: '<S183>/Gain1'
           *  Product: '<S183>/Multiply2'
           *  Product: '<S183>/Multiply3'
           *  Sqrt: '<S183>/Sqrt'
           *  Sum: '<S183>/Add1'
           *  Sum: '<S183>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_ad) * FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_lr_idx_3;

          /* Sum: '<S183>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_lr_idx_3;

          /* Sum: '<S183>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_ad;

          /* Sum: '<S183>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_ad;

          /* Signum: '<S183>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S183>/Sign1' */

          /* Signum: '<S183>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S183>/Sign2' */

          /* Sum: '<S183>/Add5' incorporates:
           *  Gain: '<S183>/Gain2'
           *  Product: '<S183>/Multiply4'
           *  Sum: '<S183>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Sum: '<S183>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ad;

          /* Sum: '<S183>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_ad;

          /* Product: '<S183>/Divide' */
          d = rtb_Divide_lr_idx_2 / FMS_ConstB.d_ad;

          /* Signum: '<S183>/Sign5' incorporates:
           *  Signum: '<S183>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S183>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S183>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Divide_lr_idx_2;

            /* Signum: '<S183>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S183>/Sign5' */

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
          rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S134>/Sign' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            rtb_Saturation_e = rtb_Divide_lr_idx_3;
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
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
            FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Saturation_e + rtb_Divide_lr_idx_2;

          /* Sum: '<S134>/Add4' */
          rtb_a_bx = (rtb_Divide_lr_idx_3 - rtb_Saturation_e) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S134>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_l;

          /* Sum: '<S134>/Subtract1' */
          rtb_Divide_lr_idx_3 -= FMS_ConstB.d_l;

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
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S134>/Sign2' */

          /* Sum: '<S134>/Add5' incorporates:
           *  Gain: '<S134>/Gain2'
           *  Product: '<S134>/Multiply4'
           *  Sum: '<S134>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_lr_idx_2 - rtb_Divide_lr_idx_3) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S133>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S182>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S182>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S183>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S183>/Sign3' */

          /* Signum: '<S183>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S183>/Sign4' */

          /* Update for DiscreteIntegrator: '<S182>/Integrator' incorporates:
           *  Constant: '<S183>/const'
           *  Gain: '<S183>/Gain3'
           *  Product: '<S183>/Multiply5'
           *  Product: '<S183>/Multiply6'
           *  Sum: '<S183>/Subtract4'
           *  Sum: '<S183>/Subtract5'
           *  Sum: '<S183>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_f *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 78.448F) * 0.004F;

          /* Sum: '<S134>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_l;

          /* Sum: '<S134>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_l;

          /* Signum: '<S134>/Sign5' incorporates:
           *  Signum: '<S134>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S134>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S134>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;

            /* Signum: '<S134>/Sign6' */
            rtb_Sign5_l = rtb_Saturation_e;
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
          FMS_DW.Integrator_DSTATE_ha += ((rtb_Saturation_e / FMS_ConstB.d_l -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_ak * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 15.707963F) * 0.004F;

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
        /* DeadZone: '<S224>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S224>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S224>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Saturation_e;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S225>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S225>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S225>/Gain'
         *  Gain: '<S87>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Saturation_e);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S226>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S226>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S226>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation_e;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S227>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S227>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S227>/Gain'
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
          /* Disable for SwitchCase: '<S298>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S698>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S688>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S637>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S605>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S616>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S296>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S407>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S458>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S448>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S407>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S295>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S394>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S310>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S328>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S344>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S369>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S356>/Switch Case' */
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
         *  ActionPort: '<S298>/Action Port'
         */
        /* SwitchCase: '<S298>/Switch Case' incorporates:
         *  Math: '<S720>/Math Function'
         *  Sum: '<S682>/Subtract'
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
            /* Disable for SwitchCase: '<S698>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S688>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S637>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S605>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S616>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S298>/Takeoff' incorporates:
             *  ActionPort: '<S600>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
             *  Delay: '<S738>/cur_waypoint'
             *  DiscreteIntegrator: '<S734>/Integrator'
             *  DiscreteIntegrator: '<S734>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S298>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S298>/Takeoff' incorporates:
           *  ActionPort: '<S600>/Action Port'
           */
          /* Delay: '<S738>/cur_waypoint' incorporates:
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
          /* Product: '<S738>/Divide' incorporates:
           *  Delay: '<S738>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S738>/Sum1'
           *  Sum: '<S738>/Sum2'
           */
          rtb_Divide_lr_idx_2 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S738>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S738>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S739>/Trigonometric Function1' incorporates:
           *  Gain: '<S737>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S739>/Trigonometric Function' incorporates:
           *  Gain: '<S737>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S739>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S739>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S739>/Gain' incorporates:
           *  Gain: '<S737>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S739>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S739>/Trigonometric Function3' incorporates:
           *  Gain: '<S737>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S739>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S739>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S739>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S731>/Saturation1' */
          rtb_Divide_pr_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Divide_pr_idx_2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S731>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S738>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S738>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S731>/Sum'
           *  Sum: '<S738>/Sum3'
           *  Sum: '<S738>/Sum4'
           */
          rtb_Divide_pr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S731>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* Saturate: '<S731>/Saturation1' incorporates:
           *  Gain: '<S731>/Gain2'
           *  Product: '<S731>/Multiply'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S600>/Bus Assignment1'
           *  Constant: '<S600>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S600>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S731>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Saturation_e < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Divide_pr_idx_1 < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S734>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S735>/Multiply1' incorporates:
           *  Constant: '<S735>/const1'
           *  DiscreteIntegrator: '<S734>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S730>/Switch' incorporates:
           *  Abs: '<S730>/Abs'
           *  Abs: '<S730>/Abs1'
           *  Constant: '<S730>/Takeoff_Speed'
           *  Constant: '<S732>/Constant'
           *  Constant: '<S733>/Constant'
           *  Gain: '<S730>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S730>/Logical Operator'
           *  RelationalOperator: '<S732>/Compare'
           *  RelationalOperator: '<S733>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S730>/Sum'
           *  Sum: '<S730>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_Saturation_e = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_Saturation_e = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S730>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S735>/Add' incorporates:
           *  DiscreteIntegrator: '<S734>/Integrator1'
           *  Sum: '<S734>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_f - rtb_Saturation_e)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S735>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S735>/Sign' */

          /* Sum: '<S735>/Add2' incorporates:
           *  Abs: '<S735>/Abs'
           *  Gain: '<S735>/Gain'
           *  Gain: '<S735>/Gain1'
           *  Product: '<S735>/Multiply2'
           *  Product: '<S735>/Multiply3'
           *  Sqrt: '<S735>/Sqrt'
           *  Sum: '<S735>/Add1'
           *  Sum: '<S735>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_lr_idx_2;

          /* Sum: '<S735>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S735>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_b;

          /* Sum: '<S735>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_b;

          /* Signum: '<S735>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S735>/Sign1' */

          /* Signum: '<S735>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S735>/Sign2' */

          /* Sum: '<S735>/Add5' incorporates:
           *  Gain: '<S735>/Gain2'
           *  Product: '<S735>/Multiply4'
           *  Sum: '<S735>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Update for Delay: '<S738>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S734>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S734>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S735>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_b;

          /* Sum: '<S735>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_b;

          /* Signum: '<S735>/Sign5' incorporates:
           *  Signum: '<S735>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S735>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S735>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;

            /* Signum: '<S735>/Sign6' */
            rtb_Sign5_l = rtb_Saturation_e;
          }

          /* End of Signum: '<S735>/Sign5' */

          /* Signum: '<S735>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S735>/Sign3' */

          /* Signum: '<S735>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S735>/Sign4' */

          /* Update for DiscreteIntegrator: '<S734>/Integrator' incorporates:
           *  Constant: '<S735>/const'
           *  Gain: '<S735>/Gain3'
           *  Product: '<S735>/Divide'
           *  Product: '<S735>/Multiply5'
           *  Product: '<S735>/Multiply6'
           *  Sum: '<S735>/Subtract4'
           *  Sum: '<S735>/Subtract5'
           *  Sum: '<S735>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation_e / FMS_ConstB.d_b -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_i * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S298>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S298>/Land' incorporates:
             *  ActionPort: '<S598>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S653>/Integrator'
             *  DiscreteIntegrator: '<S653>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S298>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S298>/Land' incorporates:
           *  ActionPort: '<S598>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S658>/Trigonometric Function1' incorporates:
           *  Gain: '<S657>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S658>/Trigonometric Function' incorporates:
           *  Gain: '<S657>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S658>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S658>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S658>/Gain' incorporates:
           *  Gain: '<S657>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S658>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S658>/Trigonometric Function3' incorporates:
           *  Gain: '<S657>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S658>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S658>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S658>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S651>/Saturation1' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Sign5_l = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S655>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S655>/Sum'
           */
          rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S655>/Multiply' incorporates:
           *  SignalConversion: '<S655>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S655>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* End of Product: '<S655>/Multiply' */

          /* Saturate: '<S651>/Saturation1' incorporates:
           *  Gain: '<S655>/Gain2'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S598>/Bus Assignment1'
           *  Constant: '<S598>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S598>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S651>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Saturation_e < rtb_Sign5_l) {
            /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Sign5_l;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Divide_pr_idx_1 < rtb_Sign5_l) {
            /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Sign5_l;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S653>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S654>/Multiply1' incorporates:
           *  Constant: '<S654>/const1'
           *  DiscreteIntegrator: '<S653>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S650>/Switch' incorporates:
           *  Constant: '<S650>/Land_Speed'
           *  Constant: '<S652>/Constant'
           *  Gain: '<S650>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S650>/Logical Operator'
           *  RelationalOperator: '<S652>/Compare'
           *  S-Function (sfix_bitop): '<S650>/cmd_p valid'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_Saturation_e = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_Saturation_e = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S650>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S654>/Add' incorporates:
           *  DiscreteIntegrator: '<S653>/Integrator1'
           *  Sum: '<S653>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_g - rtb_Saturation_e) +
            rtb_Divide_pr_idx_1;

          /* Signum: '<S654>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S654>/Sign' */

          /* Sum: '<S654>/Add2' incorporates:
           *  Abs: '<S654>/Abs'
           *  Gain: '<S654>/Gain'
           *  Gain: '<S654>/Gain1'
           *  Product: '<S654>/Multiply2'
           *  Product: '<S654>/Multiply3'
           *  Sqrt: '<S654>/Sqrt'
           *  Sum: '<S654>/Add1'
           *  Sum: '<S654>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S654>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S654>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_om;

          /* Sum: '<S654>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_om;

          /* Signum: '<S654>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S654>/Sign1' */

          /* Signum: '<S654>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S654>/Sign2' */

          /* Sum: '<S654>/Add5' incorporates:
           *  Gain: '<S654>/Gain2'
           *  Product: '<S654>/Multiply4'
           *  Sum: '<S654>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for DiscreteIntegrator: '<S653>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S653>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S654>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_om;

          /* Sum: '<S654>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_om;

          /* Signum: '<S654>/Sign5' incorporates:
           *  Signum: '<S654>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S654>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S654>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S654>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S654>/Sign5' */

          /* Signum: '<S654>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S654>/Sign3' */

          /* Signum: '<S654>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S654>/Sign4' */

          /* Update for DiscreteIntegrator: '<S653>/Integrator' incorporates:
           *  Constant: '<S654>/const'
           *  Gain: '<S654>/Gain3'
           *  Product: '<S654>/Divide'
           *  Product: '<S654>/Multiply5'
           *  Product: '<S654>/Multiply6'
           *  Sum: '<S654>/Subtract4'
           *  Sum: '<S654>/Subtract5'
           *  Sum: '<S654>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_om
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_p * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S298>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S298>/Return' incorporates:
             *  ActionPort: '<S599>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
             *  Delay: '<S662>/Delay'
             *  Delay: '<S683>/Delay'
             *  DiscreteIntegrator: '<S665>/Integrator'
             *  DiscreteIntegrator: '<S665>/Integrator1'
             *  DiscreteIntegrator: '<S679>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S684>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S725>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S298>/Return' */

            /* SystemReset for IfAction SubSystem: '<S298>/Return' incorporates:
             *  ActionPort: '<S599>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S298>/Switch Case' incorporates:
             *  Chart: '<S689>/Motion Status'
             *  Chart: '<S699>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S298>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S298>/Return' incorporates:
           *  ActionPort: '<S599>/Action Port'
           */
          /* Delay: '<S683>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S678>/Compare' incorporates:
           *  Constant: '<S729>/Constant'
           *  DiscreteIntegrator: '<S684>/Discrete-Time Integrator'
           *  RelationalOperator: '<S729>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S679>/Acceleration_Speed' */
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
          /* Chart: '<S699>/Motion State' incorporates:
           *  Constant: '<S699>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S699>/Square'
           *  Math: '<S699>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S699>/Sqrt'
           *  Sum: '<S699>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S698>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S698>/Hold Control' incorporates:
               *  ActionPort: '<S701>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S698>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S698>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S698>/Hold Control' incorporates:
             *  ActionPort: '<S701>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S698>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S698>/Brake Control' incorporates:
             *  ActionPort: '<S700>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S698>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S698>/Move Control' incorporates:
               *  ActionPort: '<S702>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S698>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S698>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S698>/Move Control' incorporates:
             *  ActionPort: '<S702>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S698>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S698>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S689>/Motion Status' incorporates:
           *  Abs: '<S689>/Abs'
           *  Constant: '<S689>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S688>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S688>/Hold Control' incorporates:
               *  ActionPort: '<S691>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S688>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S688>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S688>/Hold Control' incorporates:
             *  ActionPort: '<S691>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S688>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S688>/Brake Control' incorporates:
             *  ActionPort: '<S690>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S688>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S688>/Move Control' incorporates:
               *  ActionPort: '<S692>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S688>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S688>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S688>/Move Control' incorporates:
             *  ActionPort: '<S692>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S688>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S688>/Switch Case' */

          /* Switch: '<S660>/Switch' incorporates:
           *  Product: '<S683>/Multiply'
           *  Sum: '<S683>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S698>/Saturation1' */
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

            /* End of Saturate: '<S698>/Saturation1' */

            /* Saturate: '<S688>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S688>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S683>/Sum' incorporates:
             *  Delay: '<S683>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S726>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S679>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S683>/Sum' incorporates:
             *  Delay: '<S683>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S679>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S685>/Sqrt' incorporates:
             *  Math: '<S685>/Square'
             *  Sum: '<S679>/Sum'
             *  Sum: '<S685>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0 +
              rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S728>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S728>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S728>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S727>/Gain' incorporates:
             *  DiscreteIntegrator: '<S725>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S725>/Add'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S728>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S728>/Trigonometric Function1'
             */
            rtb_Sign5_l = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_VectorConcatenate_h[4] = rtb_Sign5_l;

            /* Trigonometry: '<S728>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S728>/Trigonometric Function'
             */
            rtb_a_bx = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S728>/Gain' incorporates:
             *  Trigonometry: '<S728>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -rtb_a_bx;

            /* SignalConversion: '<S728>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S728>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S728>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_a_bx;

            /* Trigonometry: '<S728>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Sign5_l;

            /* Switch: '<S679>/Switch' incorporates:
             *  Constant: '<S679>/vel'
             */
            if (rtb_Saturation_e > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S679>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Saturation_e;

              /* Saturate: '<S679>/Saturation' */
              if (rtb_Divide_pr_idx_2 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Saturate: '<S679>/Saturation' */
            }

            /* End of Switch: '<S679>/Switch' */

            /* Switch: '<S679>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S679>/Acceleration_Speed'
             *  Sum: '<S679>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Divide_pr_idx_2 < 0.0F)
            {
              rtb_Divide_pr_idx_2 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S679>/Switch1' */

            /* Sum: '<S726>/Sum of Elements' incorporates:
             *  Math: '<S726>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S726>/Math Function1' incorporates:
             *  Sum: '<S726>/Sum of Elements'
             *
             * About '<S726>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S726>/Math Function1' */

            /* Switch: '<S726>/Switch' incorporates:
             *  Constant: '<S726>/Constant'
             *  Product: '<S726>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Square_bg[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S726>/Switch' */

            /* Product: '<S724>/Multiply2' incorporates:
             *  Product: '<S726>/Divide'
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

          /* End of Switch: '<S660>/Switch' */

          /* Delay: '<S662>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S665>/Integrator1' incorporates:
           *  Delay: '<S662>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S669>/Rem' incorporates:
           *  Constant: '<S669>/Constant1'
           *  DiscreteIntegrator: '<S665>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S664>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S669>/Switch' incorporates:
           *  Abs: '<S669>/Abs'
           *  Constant: '<S669>/Constant'
           *  Constant: '<S670>/Constant'
           *  Product: '<S669>/Multiply'
           *  RelationalOperator: '<S670>/Compare'
           *  Sum: '<S669>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S669>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S669>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S669>/Switch' */

          /* Gain: '<S664>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S664>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S664>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S599>/Bus Assignment1'
           *  Constant: '<S599>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
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

          /* Math: '<S719>/Math Function1'
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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S719>/Product'
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

          /* End of Switch: '<S719>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S599>/Sum' incorporates:
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

          /* SignalConversion: '<S676>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S599>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S676>/Math Function' incorporates:
           *  Sum: '<S599>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S676>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S676>/Math Function1' incorporates:
           *  Sum: '<S676>/Sum of Elements'
           *
           * About '<S676>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S676>/Math Function1' */

          /* Switch: '<S676>/Switch' incorporates:
           *  Constant: '<S676>/Constant'
           *  Product: '<S676>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_a_bx = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_a_bx = 1.0F;
          }

          /* End of Switch: '<S676>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S681>/NearbyRefWP' incorporates:
           *  Constant: '<S599>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S681>/SearchL1RefWP' incorporates:
           *  Constant: '<S599>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S681>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S681>/Switch1' incorporates:
           *  Constant: '<S712>/Constant'
           *  RelationalOperator: '<S712>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S711>/Compare' incorporates:
             *  Constant: '<S711>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S681>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S681>/Switch' */
          }

          /* End of Switch: '<S681>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S682>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Sign5_l;
          rtb_Subtract_hb[0] = rtb_Sign5_l * rtb_Sign5_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S682>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S720>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S720>/Sum of Elements' incorporates:
           *  Math: '<S720>/Math Function'
           *  Sum: '<S718>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] + rtb_Sign5_l * rtb_Sign5_l;

          /* Math: '<S720>/Math Function1' incorporates:
           *  Sum: '<S720>/Sum of Elements'
           *
           * About '<S720>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S720>/Math Function1' */

          /* Switch: '<S720>/Switch' incorporates:
           *  Constant: '<S720>/Constant'
           *  Product: '<S720>/Product'
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

          /* End of Switch: '<S720>/Switch' */

          /* Product: '<S719>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S722>/Sum of Elements' incorporates:
           *  Math: '<S722>/Math Function'
           *  SignalConversion: '<S722>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S722>/Math Function1' incorporates:
           *  Sum: '<S722>/Sum of Elements'
           *
           * About '<S722>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S722>/Math Function1' */

          /* Switch: '<S722>/Switch' incorporates:
           *  Constant: '<S722>/Constant'
           *  Product: '<S722>/Product'
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

          /* End of Switch: '<S722>/Switch' */

          /* Product: '<S720>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S723>/Switch' */

          /* Product: '<S723>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S722>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S676>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_a_bx;

          /* Product: '<S723>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S722>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S676>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_a_bx;

          /* Sum: '<S721>/Subtract' incorporates:
           *  Product: '<S721>/Multiply'
           *  Product: '<S721>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S716>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S716>/Sign1' */

          /* Switch: '<S716>/Switch2' incorporates:
           *  Constant: '<S716>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S716>/Switch2' */

          /* DotProduct: '<S716>/Dot Product' */
          rtb_Sign5_l = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S716>/Acos' incorporates:
           *  DotProduct: '<S716>/Dot Product'
           */
          if (rtb_Sign5_l > 1.0F) {
            rtb_Sign5_l = 1.0F;
          } else {
            if (rtb_Sign5_l < -1.0F) {
              rtb_Sign5_l = -1.0F;
            }
          }

          /* Product: '<S716>/Multiply' incorporates:
           *  Trigonometry: '<S716>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Sign5_l);

          /* Saturate: '<S682>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S682>/Saturation' */

          /* Product: '<S682>/Divide' incorporates:
           *  Constant: '<S599>/L1'
           *  Constant: '<S682>/Constant'
           *  Gain: '<S682>/Gain'
           *  Math: '<S682>/Square'
           *  MinMax: '<S682>/Max'
           *  MinMax: '<S682>/Min'
           *  Product: '<S682>/Multiply1'
           *  Sqrt: '<S718>/Sqrt'
           *  Trigonometry: '<S682>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S674>/Subtract' incorporates:
           *  Product: '<S674>/Multiply'
           *  Product: '<S674>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S663>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S663>/Sign1' */

          /* Switch: '<S663>/Switch2' incorporates:
           *  Constant: '<S663>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S663>/Switch2' */

          /* DotProduct: '<S663>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide_m[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S663>/Acos' incorporates:
           *  DotProduct: '<S663>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S663>/Multiply' incorporates:
           *  Trigonometry: '<S663>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S666>/Rem' incorporates:
           *  Constant: '<S666>/Constant1'
           *  Delay: '<S662>/Delay'
           *  Sum: '<S662>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S666>/Switch' incorporates:
           *  Abs: '<S666>/Abs'
           *  Constant: '<S666>/Constant'
           *  Constant: '<S672>/Constant'
           *  Product: '<S666>/Multiply'
           *  RelationalOperator: '<S672>/Compare'
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

          /* Sum: '<S662>/Sum' incorporates:
           *  Delay: '<S662>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S671>/Multiply1' incorporates:
           *  Constant: '<S671>/const1'
           *  DiscreteIntegrator: '<S665>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S671>/Add' incorporates:
           *  DiscreteIntegrator: '<S665>/Integrator1'
           *  Sum: '<S665>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_b -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S671>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S671>/Sign' */

          /* Sum: '<S671>/Add2' incorporates:
           *  Abs: '<S671>/Abs'
           *  Gain: '<S671>/Gain'
           *  Gain: '<S671>/Gain1'
           *  Product: '<S671>/Multiply2'
           *  Product: '<S671>/Multiply3'
           *  Sqrt: '<S671>/Sqrt'
           *  Sum: '<S671>/Add1'
           *  Sum: '<S671>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_n) * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S671>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S671>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S671>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_n;

          /* Signum: '<S671>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S671>/Sign1' */

          /* Signum: '<S671>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S671>/Sign2' */

          /* Sum: '<S671>/Add5' incorporates:
           *  Gain: '<S671>/Gain2'
           *  Product: '<S671>/Multiply4'
           *  Sum: '<S671>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S671>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_n;

          /* Sum: '<S671>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_n;

          /* Product: '<S671>/Divide' */
          d = rtb_Saturation_e / FMS_ConstB.d_n;

          /* Signum: '<S671>/Sign5' incorporates:
           *  Signum: '<S671>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S671>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S671>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Saturation_e;

            /* Signum: '<S671>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S671>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S662>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S667>/Rem' incorporates:
           *  Constant: '<S667>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S667>/Switch' incorporates:
           *  Abs: '<S667>/Abs'
           *  Constant: '<S667>/Constant'
           *  Constant: '<S673>/Constant'
           *  Product: '<S667>/Multiply'
           *  RelationalOperator: '<S673>/Compare'
           *  Sum: '<S667>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S667>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S667>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S667>/Switch' */

          /* Abs: '<S660>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S683>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S684>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S677>/Constant'
           *  RelationalOperator: '<S677>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S684>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S679>/Acceleration_Speed' incorporates:
           *  Constant: '<S679>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S679>/Acceleration_Speed' */

          /* Product: '<S683>/Divide1' incorporates:
           *  Constant: '<S683>/Constant'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S683>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S683>/Saturation' */

          /* Update for DiscreteIntegrator: '<S725>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S662>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S665>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S665>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S671>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S671>/Sign3' */

          /* Signum: '<S671>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S671>/Sign4' */

          /* Update for DiscreteIntegrator: '<S665>/Integrator' incorporates:
           *  Constant: '<S671>/const'
           *  Gain: '<S671>/Gain3'
           *  Product: '<S671>/Multiply5'
           *  Product: '<S671>/Multiply6'
           *  Sum: '<S671>/Subtract4'
           *  Sum: '<S671>/Subtract5'
           *  Sum: '<S671>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S665>/Integrator' */
          /* End of Outputs for SubSystem: '<S298>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S298>/Hold' incorporates:
             *  ActionPort: '<S597>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
             *  Delay: '<S618>/Delay'
             *  DiscreteIntegrator: '<S630>/Integrator'
             *  DiscreteIntegrator: '<S630>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S298>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S298>/Hold' incorporates:
             *  ActionPort: '<S597>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S298>/Switch Case' incorporates:
             *  Chart: '<S606>/Motion Status'
             *  Chart: '<S617>/Motion State'
             *  Chart: '<S638>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_il = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S298>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S298>/Hold' incorporates:
           *  ActionPort: '<S597>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S606>/Motion Status' incorporates:
           *  Abs: '<S606>/Abs'
           *  Constant: '<S606>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S617>/Motion State' incorporates:
           *  Abs: '<S617>/Abs'
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

          /* End of Chart: '<S617>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S638>/Motion State' incorporates:
           *  Constant: '<S638>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S638>/Square'
           *  Math: '<S638>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S638>/Sqrt'
           *  Sum: '<S638>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S637>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S637>/Hold Control' incorporates:
               *  ActionPort: '<S640>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S637>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S637>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S637>/Hold Control' incorporates:
             *  ActionPort: '<S640>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S637>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S637>/Brake Control' incorporates:
             *  ActionPort: '<S639>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S637>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S637>/Move Control' incorporates:
               *  ActionPort: '<S641>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S637>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S637>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S637>/Move Control' incorporates:
             *  ActionPort: '<S641>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S637>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S637>/Switch Case' */

          /* SwitchCase: '<S605>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S605>/Hold Control' incorporates:
               *  ActionPort: '<S608>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S605>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S605>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S605>/Hold Control' incorporates:
             *  ActionPort: '<S608>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S605>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S605>/Brake Control' incorporates:
             *  ActionPort: '<S607>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S605>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S605>/Move Control' incorporates:
               *  ActionPort: '<S609>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S605>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S605>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S605>/Move Control' incorporates:
             *  ActionPort: '<S609>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S605>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S605>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S615>/Compare' incorporates:
           *  Constant: '<S615>/Constant'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S618>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S630>/Integrator1' incorporates:
           *  Delay: '<S618>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S616>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S616>/Hold Control' incorporates:
               *  ActionPort: '<S620>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S616>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S616>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S616>/Hold Control' incorporates:
             *  ActionPort: '<S620>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S616>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S616>/Brake Control' incorporates:
             *  ActionPort: '<S619>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S616>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S616>/Move Control' incorporates:
               *  ActionPort: '<S621>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S616>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S616>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S616>/Move Control' incorporates:
             *  ActionPort: '<S621>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S616>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S616>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S603>/Switch' incorporates:
           *  Saturate: '<S616>/Saturation'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S633>/Rem' incorporates:
             *  Constant: '<S633>/Constant1'
             *  DiscreteIntegrator: '<S630>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S629>/Sum'
             */
            rtb_Divide_pr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S633>/Switch' incorporates:
             *  Abs: '<S633>/Abs'
             *  Constant: '<S633>/Constant'
             *  Constant: '<S634>/Constant'
             *  Product: '<S633>/Multiply'
             *  RelationalOperator: '<S634>/Compare'
             *  Sum: '<S633>/Add'
             */
            if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
              /* Signum: '<S633>/Sign' */
              if (rtb_Divide_pr_idx_1 < 0.0F) {
                rtb_Divide_lr_idx_2 = -1.0F;
              } else if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              } else {
                rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
              }

              /* End of Signum: '<S633>/Sign' */
              rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
            }

            /* End of Switch: '<S633>/Switch' */

            /* Gain: '<S629>/Gain2' */
            rtb_Divide_pr_idx_1 *= FMS_PARAM.YAW_P;

            /* Saturate: '<S629>/Saturation' */
            if (rtb_Divide_pr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Divide_pr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S629>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S616>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S616>/Saturation' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S616>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_h;
          }

          /* End of Switch: '<S603>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S597>/Bus Assignment'
           *  Constant: '<S597>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S597>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_1;

          /* Saturate: '<S637>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S637>/Saturation1' */

          /* Saturate: '<S605>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S597>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S605>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S631>/Rem' incorporates:
           *  Constant: '<S631>/Constant1'
           *  Delay: '<S618>/Delay'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S618>/Sum2'
           */
          rtb_Divide_pr_idx_1 = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S631>/Switch' incorporates:
           *  Abs: '<S631>/Abs'
           *  Constant: '<S631>/Constant'
           *  Constant: '<S636>/Constant'
           *  Product: '<S631>/Multiply'
           *  RelationalOperator: '<S636>/Compare'
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

          /* Sum: '<S618>/Sum' incorporates:
           *  Delay: '<S618>/Delay'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1 + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S630>/Integrator' */
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

          /* Product: '<S635>/Multiply1' incorporates:
           *  Constant: '<S635>/const1'
           *  DiscreteIntegrator: '<S630>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S635>/Add' incorporates:
           *  DiscreteIntegrator: '<S630>/Integrator1'
           *  Sum: '<S630>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_jz - rtb_Divide_lr_idx_2)
            + rtb_Divide_pr_idx_1;

          /* Signum: '<S635>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S635>/Sign' */

          /* Sum: '<S635>/Add2' incorporates:
           *  Abs: '<S635>/Abs'
           *  Gain: '<S635>/Gain'
           *  Gain: '<S635>/Gain1'
           *  Product: '<S635>/Multiply2'
           *  Product: '<S635>/Multiply3'
           *  Sqrt: '<S635>/Sqrt'
           *  Sum: '<S635>/Add1'
           *  Sum: '<S635>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_k) * FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S635>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S635>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_k;

          /* Sum: '<S635>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_k;

          /* Signum: '<S635>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S635>/Sign1' */

          /* Signum: '<S635>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S635>/Sign2' */

          /* Sum: '<S635>/Add5' incorporates:
           *  Gain: '<S635>/Gain2'
           *  Product: '<S635>/Multiply4'
           *  Sum: '<S635>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for Delay: '<S618>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S630>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S630>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S635>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_k;

          /* Sum: '<S635>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_k;

          /* Signum: '<S635>/Sign5' incorporates:
           *  Signum: '<S635>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S635>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S635>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S635>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S635>/Sign5' */

          /* Signum: '<S635>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S635>/Sign3' */

          /* Signum: '<S635>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S635>/Sign4' */

          /* Update for DiscreteIntegrator: '<S630>/Integrator' incorporates:
           *  Constant: '<S635>/const'
           *  Gain: '<S635>/Gain3'
           *  Product: '<S635>/Divide'
           *  Product: '<S635>/Multiply5'
           *  Product: '<S635>/Multiply6'
           *  Sum: '<S635>/Subtract4'
           *  Sum: '<S635>/Subtract5'
           *  Sum: '<S635>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S630>/Integrator' */
          /* End of Outputs for SubSystem: '<S298>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S298>/Unknown' incorporates:
           *  ActionPort: '<S601>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S298>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
         *  ActionPort: '<S296>/Action Port'
         */
        /* SwitchCase: '<S296>/Switch Case' incorporates:
         *  Math: '<S480>/Math Function'
         *  Sum: '<S436>/Subtract'
         *  Sum: '<S493>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S407>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S458>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S448>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S407>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S296>/Offboard' incorporates:
           *  ActionPort: '<S408>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S574>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S577>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S578>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S578>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S578>/Multiply1' incorporates:
           *  Product: '<S578>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S578>/Divide' incorporates:
           *  Constant: '<S578>/Constant'
           *  Constant: '<S578>/R'
           *  Sqrt: '<S578>/Sqrt'
           *  Sum: '<S578>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S578>/Product3' incorporates:
           *  Constant: '<S578>/Constant1'
           *  Product: '<S578>/Multiply1'
           *  Sum: '<S578>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S578>/Multiply2' incorporates:
           *  Trigonometry: '<S578>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S577>/Sum' incorporates:
           *  Gain: '<S574>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S582>/Abs' incorporates:
           *  Abs: '<S585>/Abs1'
           *  Switch: '<S582>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S582>/Switch1' incorporates:
           *  Abs: '<S582>/Abs'
           *  Bias: '<S582>/Bias2'
           *  Bias: '<S582>/Bias3'
           *  Constant: '<S579>/Constant'
           *  Constant: '<S579>/Constant1'
           *  Constant: '<S584>/Constant'
           *  Gain: '<S582>/Gain1'
           *  Product: '<S582>/Multiply'
           *  RelationalOperator: '<S584>/Compare'
           *  Switch: '<S579>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S585>/Switch1' incorporates:
             *  Bias: '<S585>/Bias2'
             *  Bias: '<S585>/Bias3'
             *  Constant: '<S585>/Constant'
             *  Constant: '<S586>/Constant'
             *  Math: '<S585>/Math Function'
             *  RelationalOperator: '<S586>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S585>/Switch1' */

            /* Signum: '<S582>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S582>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S579>/Sum' incorporates:
           *  Gain: '<S574>/Gain1'
           *  Gain: '<S574>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S577>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S577>/Multiply' incorporates:
           *  Gain: '<S577>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S581>/Switch1' incorporates:
           *  Abs: '<S581>/Abs1'
           *  Bias: '<S581>/Bias2'
           *  Bias: '<S581>/Bias3'
           *  Constant: '<S581>/Constant'
           *  Constant: '<S583>/Constant'
           *  Math: '<S581>/Math Function'
           *  RelationalOperator: '<S583>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S581>/Switch1' */

          /* Product: '<S577>/Multiply' incorporates:
           *  Gain: '<S577>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S555>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S559>/Multiply1'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S568>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S568>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S568>/Trigonometric Function3' incorporates:
             *  Gain: '<S567>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S568>/Gain' incorporates:
             *  Gain: '<S567>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S568>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S568>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S568>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S568>/Trigonometric Function' incorporates:
             *  Gain: '<S567>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S568>/Trigonometric Function1' incorporates:
             *  Gain: '<S567>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S568>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S561>/Switch' incorporates:
             *  Constant: '<S576>/Constant'
             *  DataTypeConversion: '<S574>/Data Type Conversion1'
             *  Product: '<S580>/Multiply1'
             *  Product: '<S580>/Multiply2'
             *  RelationalOperator: '<S576>/Compare'
             *  S-Function (sfix_bitop): '<S573>/lat_cmd valid'
             *  Sum: '<S580>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Multiply_g_idx_0 *
                FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S559>/Multiply' incorporates:
             *  Constant: '<S565>/Constant'
             *  Constant: '<S566>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S558>/Logical Operator'
             *  RelationalOperator: '<S565>/Compare'
             *  RelationalOperator: '<S566>/Compare'
             *  S-Function (sfix_bitop): '<S558>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/x_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S559>/Sum1'
             */
            rtb_Divide_pr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S568>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S561>/Switch' incorporates:
             *  Constant: '<S576>/Constant'
             *  DataTypeConversion: '<S574>/Data Type Conversion1'
             *  Product: '<S580>/Multiply3'
             *  Product: '<S580>/Multiply4'
             *  RelationalOperator: '<S576>/Compare'
             *  S-Function (sfix_bitop): '<S573>/lon_cmd valid'
             *  Sum: '<S580>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S559>/Multiply' incorporates:
             *  Constant: '<S565>/Constant'
             *  Constant: '<S566>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S558>/Logical Operator'
             *  RelationalOperator: '<S565>/Compare'
             *  RelationalOperator: '<S566>/Compare'
             *  S-Function (sfix_bitop): '<S558>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/y_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S559>/Sum1'
             */
            rtb_Divide_lr_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S568>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S561>/Switch' incorporates:
             *  Constant: '<S576>/Constant'
             *  DataTypeConversion: '<S574>/Data Type Conversion'
             *  DataTypeConversion: '<S574>/Data Type Conversion1'
             *  Gain: '<S574>/Gain2'
             *  Gain: '<S577>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S576>/Compare'
             *  S-Function (sfix_bitop): '<S573>/alt_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S577>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_Saturation_e = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                -FMS_U.INS_Out.alt_0);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S559>/Multiply' incorporates:
             *  Constant: '<S565>/Constant'
             *  Constant: '<S566>/Constant'
             *  Gain: '<S562>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S558>/Logical Operator'
             *  RelationalOperator: '<S565>/Compare'
             *  RelationalOperator: '<S566>/Compare'
             *  S-Function (sfix_bitop): '<S558>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/z_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S559>/Sum1'
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

            /* SignalConversion: '<S501>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S501>/Constant4'
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  Product: '<S559>/Multiply1'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S501>/Trigonometric Function3' incorporates:
             *  Gain: '<S500>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S501>/Gain' incorporates:
             *  Gain: '<S500>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S501>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S501>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S501>/Constant3'
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S501>/Trigonometric Function' incorporates:
             *  Gain: '<S500>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S501>/Trigonometric Function1' incorporates:
             *  Gain: '<S500>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S501>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S490>/Multiply' incorporates:
             *  Constant: '<S499>/Constant'
             *  RelationalOperator: '<S499>/Compare'
             *  S-Function (sfix_bitop): '<S496>/ax_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S501>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S490>/Multiply' incorporates:
             *  Constant: '<S499>/Constant'
             *  RelationalOperator: '<S499>/Compare'
             *  S-Function (sfix_bitop): '<S496>/ay_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S501>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S490>/Multiply' incorporates:
             *  Constant: '<S499>/Constant'
             *  RelationalOperator: '<S499>/Compare'
             *  S-Function (sfix_bitop): '<S496>/az_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S490>/Index Vector' incorporates:
             *  Product: '<S497>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ee[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           case 1:
            /* SignalConversion: '<S571>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S571>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S571>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S560>/Data Store Read'
             *  Gain: '<S569>/Gain'
             *  Trigonometry: '<S571>/Trigonometric Function1'
             */
            rtb_Sign5_l = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_h[4] = rtb_Sign5_l;

            /* Trigonometry: '<S571>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S560>/Data Store Read'
             *  Gain: '<S569>/Gain'
             *  Trigonometry: '<S571>/Trigonometric Function'
             */
            rtb_a_bx = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S571>/Gain' incorporates:
             *  Trigonometry: '<S571>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -rtb_a_bx;

            /* SignalConversion: '<S571>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S571>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S571>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_a_bx;

            /* Trigonometry: '<S571>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Sign5_l;

            /* SignalConversion: '<S572>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S572>/Constant4'
             */
            rtb_MatrixConcatenate1_i[5] = 0.0F;

            /* Gain: '<S570>/Gain' incorporates:
             *  DataStoreRead: '<S560>/Data Store Read'
             *  Gain: '<S502>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S560>/Subtract'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S572>/Trigonometric Function3' incorporates:
             *  Gain: '<S570>/Gain'
             *  Trigonometry: '<S572>/Trigonometric Function1'
             */
            rtb_Sign5_l = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_MatrixConcatenate1_i[4] = rtb_Sign5_l;

            /* Trigonometry: '<S572>/Trigonometric Function2' incorporates:
             *  Gain: '<S570>/Gain'
             *  Trigonometry: '<S572>/Trigonometric Function'
             */
            rtb_a_bx = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S572>/Gain' incorporates:
             *  Trigonometry: '<S572>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_i[3] = -rtb_a_bx;

            /* SignalConversion: '<S572>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S572>/Constant3'
             */
            rtb_MatrixConcatenate1_i[2] = 0.0F;

            /* Trigonometry: '<S572>/Trigonometric Function' */
            rtb_MatrixConcatenate1_i[1] = rtb_a_bx;

            /* Trigonometry: '<S572>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_i[0] = rtb_Sign5_l;

            /* RelationalOperator: '<S576>/Compare' incorporates:
             *  Constant: '<S576>/Constant'
             *  S-Function (sfix_bitop): '<S573>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S573>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S573>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S574>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S574>/Data Type Conversion'
             *  Gain: '<S574>/Gain2'
             *  Gain: '<S577>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S580>/Multiply1'
             *  Product: '<S580>/Multiply2'
             *  Product: '<S580>/Multiply3'
             *  Product: '<S580>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S577>/Sum1'
             *  Sum: '<S580>/Sum2'
             *  Sum: '<S580>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S561>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S571>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S560>/Sum' incorporates:
             *  DataStoreRead: '<S560>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S571>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S560>/Sum' incorporates:
             *  DataStoreRead: '<S560>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S571>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S560>/Sum' incorporates:
             *  DataStoreRead: '<S560>/Data Store Read'
             *  Gain: '<S562>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S565>/Compare' incorporates:
             *  Constant: '<S565>/Constant'
             *  S-Function (sfix_bitop): '<S558>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S566>/Compare' incorporates:
             *  Constant: '<S566>/Constant'
             *  S-Function (sfix_bitop): '<S558>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S560>/Sum2' incorporates:
               *  Product: '<S560>/Multiply2'
               *  Switch: '<S561>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation_e = rtb_Switch_c2[rtb_n];
              } else {
                rtb_Saturation_e = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              /* Product: '<S560>/Multiply' incorporates:
               *  Logic: '<S558>/Logical Operator'
               *  Product: '<S560>/Multiply2'
               *  Sum: '<S560>/Sum'
               *  Sum: '<S560>/Sum2'
               */
              rtb_Switch_ee[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation_e - ((rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1) + rtb_VectorConcatenate_h[rtb_n + 6] *
                                    rtb_Divide_pr_idx_0) : 0.0F;
            }

            /* SignalConversion: '<S503>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S503>/Constant4'
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S503>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S503>/Gain' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             *  Trigonometry: '<S503>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Divide_pr_idx_2);

            /* SignalConversion: '<S503>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S503>/Constant3'
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S503>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Trigonometry: '<S503>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S490>/Index Vector'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Product: '<S490>/Multiply' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S499>/Compare' incorporates:
             *  Constant: '<S499>/Constant'
             *  S-Function (sfix_bitop): '<S496>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S496>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S496>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S503>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S490>/Index Vector'
               */
              rtb_VectorConcatenate_h[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S490>/Multiply' */
              rtb_Switch_c2[rtb_n] = tmp[rtb_n] ?
                rtb_MatrixConcatenate1_i_0[rtb_n] : 0.0F;
              rtb_Switch_an[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
                rtb_Switch_ee[2] + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                                    rtb_Switch_ee[1] +
                                    rtb_MatrixConcatenate1_i[rtb_n] *
                                    rtb_Switch_ee[0]);
            }

            /* MultiPortSwitch: '<S490>/Index Vector' incorporates:
             *  Product: '<S498>/Multiply3'
             *  Product: '<S560>/Multiply3'
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
            /* SignalConversion: '<S564>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S564>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S564>/Trigonometric Function3' incorporates:
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S564>/Gain' incorporates:
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S564>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S564>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S564>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S564>/Trigonometric Function' incorporates:
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S564>/Trigonometric Function1' incorporates:
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S573>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S558>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S576>/Compare' incorporates:
             *  Constant: '<S576>/Constant'
             *  S-Function (sfix_bitop): '<S573>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S573>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S558>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S576>/Compare' incorporates:
             *  Constant: '<S576>/Constant'
             *  S-Function (sfix_bitop): '<S573>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S573>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S558>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S576>/Compare' incorporates:
             *  Constant: '<S576>/Constant'
             *  S-Function (sfix_bitop): '<S573>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S574>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S574>/Data Type Conversion'
             *  Gain: '<S574>/Gain2'
             *  Gain: '<S577>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S580>/Multiply1'
             *  Product: '<S580>/Multiply2'
             *  Product: '<S580>/Multiply3'
             *  Product: '<S580>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S577>/Sum1'
             *  Sum: '<S580>/Sum2'
             *  Sum: '<S580>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S561>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S564>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_g[0];

            /* Sum: '<S557>/Sum' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S564>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_g[1];

            /* Sum: '<S557>/Sum' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S564>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Sum: '<S557>/Sum' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Gain: '<S562>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S565>/Compare' incorporates:
             *  Constant: '<S565>/Constant'
             *  S-Function (sfix_bitop): '<S558>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S558>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S566>/Compare' incorporates:
             *  Constant: '<S566>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S557>/Sum2' incorporates:
             *  Logic: '<S558>/Logical Operator'
             *  Product: '<S557>/Multiply'
             *  Product: '<S557>/Multiply2'
             *  Sum: '<S557>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S561>/Switch' incorporates:
               *  Product: '<S557>/Multiply2'
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

            /* End of Sum: '<S557>/Sum2' */

            /* MultiPortSwitch: '<S490>/Index Vector' incorporates:
             *  Constant: '<S499>/Constant'
             *  Product: '<S490>/Multiply'
             *  RelationalOperator: '<S499>/Compare'
             *  S-Function (sfix_bitop): '<S496>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S496>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S496>/az_cmd valid'
             */
            rtb_Switch_ee[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ee[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ee[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S555>/Index Vector' */

          /* Sum: '<S551>/Sum1' incorporates:
           *  Constant: '<S551>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S551>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S552>/Abs' */
          rtb_Divide_pr_idx_1 = fabsf(rtb_Divide_pr_idx_2);

          /* Switch: '<S552>/Switch' incorporates:
           *  Constant: '<S552>/Constant'
           *  Constant: '<S553>/Constant'
           *  Product: '<S552>/Multiply'
           *  RelationalOperator: '<S553>/Compare'
           *  Sum: '<S552>/Subtract'
           */
          if (rtb_Divide_pr_idx_1 > 3.14159274F) {
            /* Signum: '<S552>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_2 > 0.0F) {
                rtb_Divide_pr_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S552>/Sign' */
            rtb_Divide_pr_idx_2 *= rtb_Divide_pr_idx_1 - 6.28318548F;
          }

          /* End of Switch: '<S552>/Switch' */

          /* Saturate: '<S551>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 0.314159274F) {
            rtb_Divide_pr_idx_2 = 0.314159274F;
          } else {
            if (rtb_Divide_pr_idx_2 < -0.314159274F) {
              rtb_Divide_pr_idx_2 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S551>/Saturation' */

          /* Gain: '<S548>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S492>/Sum' incorporates:
           *  Constant: '<S550>/Constant'
           *  Constant: '<S554>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S548>/Multiply2'
           *  Product: '<S549>/Multiply1'
           *  RelationalOperator: '<S550>/Compare'
           *  RelationalOperator: '<S554>/Compare'
           *  S-Function (sfix_bitop): '<S548>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S549>/psi_rate_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Saturation_e = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Divide_pr_idx_2 : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S555>/Gain1' */
          rtb_Square_bg[0] = FMS_PARAM.XY_P * rtb_Switch_an[0];
          rtb_Square_bg[1] = FMS_PARAM.XY_P * rtb_Switch_an[1];

          /* Gain: '<S555>/Gain2' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.Z_P * rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S556>/Index Vector' incorporates:
           *  Constant: '<S592>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S556>/Multiply'
           *  Product: '<S589>/Multiply'
           *  Product: '<S590>/Multiply3'
           *  RelationalOperator: '<S592>/Compare'
           *  S-Function (sfix_bitop): '<S588>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S588>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S588>/w_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S594>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S594>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S594>/Trigonometric Function3' incorporates:
             *  Gain: '<S593>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S594>/Gain' incorporates:
             *  Gain: '<S593>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S594>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S594>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S594>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S594>/Trigonometric Function' incorporates:
             *  Gain: '<S593>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S594>/Trigonometric Function1' incorporates:
             *  Gain: '<S593>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S594>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S592>/Constant'
             *  RelationalOperator: '<S592>/Compare'
             *  S-Function (sfix_bitop): '<S588>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S594>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S592>/Constant'
             *  RelationalOperator: '<S592>/Compare'
             *  S-Function (sfix_bitop): '<S588>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S594>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S592>/Constant'
             *  RelationalOperator: '<S592>/Compare'
             *  S-Function (sfix_bitop): '<S588>/w_cmd valid'
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
            /* SignalConversion: '<S596>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S596>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Gain: '<S595>/Gain' incorporates:
             *  DataStoreRead: '<S590>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S590>/Subtract'
             */
            rtb_Divide_pr_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S596>/Trigonometric Function3' incorporates:
             *  Gain: '<S595>/Gain'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* Gain: '<S596>/Gain' incorporates:
             *  Gain: '<S595>/Gain'
             *  Trigonometry: '<S596>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S596>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S596>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S596>/Trigonometric Function' incorporates:
             *  Gain: '<S595>/Gain'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Divide_pr_idx_1);

            /* Trigonometry: '<S596>/Trigonometric Function1' incorporates:
             *  Gain: '<S595>/Gain'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S596>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S592>/Constant'
             *  RelationalOperator: '<S592>/Compare'
             *  S-Function (sfix_bitop): '<S588>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S596>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S592>/Constant'
             *  RelationalOperator: '<S592>/Compare'
             *  S-Function (sfix_bitop): '<S588>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S596>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S592>/Constant'
             *  RelationalOperator: '<S592>/Compare'
             *  S-Function (sfix_bitop): '<S588>/w_cmd valid'
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

          /* End of MultiPortSwitch: '<S556>/Index Vector' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_an[0] += rtb_Square_bg[0];
          rtb_Switch_an[1] += rtb_Square_bg[1];

          /* Sum: '<S493>/Sum1' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S511>/Switch' incorporates:
           *  Constant: '<S526>/Constant'
           *  Constant: '<S528>/Constant'
           *  Constant: '<S529>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S526>/Compare'
           *  RelationalOperator: '<S528>/Compare'
           *  RelationalOperator: '<S529>/Compare'
           *  S-Function (sfix_bitop): '<S511>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S511>/y_v_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S511>/Logical Operator' incorporates:
             *  Constant: '<S527>/Constant'
             *  Constant: '<S528>/Constant'
             *  Constant: '<S529>/Constant'
             *  RelationalOperator: '<S527>/Compare'
             *  RelationalOperator: '<S528>/Compare'
             *  RelationalOperator: '<S529>/Compare'
             *  S-Function (sfix_bitop): '<S511>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S511>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S511>/y_v_cmd'
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

          /* End of Switch: '<S511>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S491>/u_cmd_valid' */
          /* MATLAB Function: '<S523>/bit_shift' incorporates:
           *  DataTypeConversion: '<S491>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_kd << 6);

          /* End of Outputs for SubSystem: '<S491>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S491>/v_cmd_valid' */
          /* MATLAB Function: '<S524>/bit_shift' incorporates:
           *  DataTypeConversion: '<S491>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S491>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S512>/Switch' incorporates:
           *  Constant: '<S531>/Constant'
           *  Constant: '<S532>/Constant'
           *  Constant: '<S534>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S531>/Compare'
           *  RelationalOperator: '<S532>/Compare'
           *  RelationalOperator: '<S534>/Compare'
           *  S-Function (sfix_bitop): '<S512>/ax_cmd'
           *  S-Function (sfix_bitop): '<S512>/ay_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S512>/Logical Operator' incorporates:
             *  Constant: '<S532>/Constant'
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S532>/Compare'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S512>/ax_cmd'
             *  S-Function (sfix_bitop): '<S512>/ay_cmd'
             */
            rtb_Compare_kd = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_kd;
          } else {
            rtb_Compare_kd = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S512>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S408>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S408>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S408>/Bus Assignment' incorporates:
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

          /* Saturate: '<S492>/Saturation' */
          if (rtb_Saturation_e > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S492>/Saturation' */

          /* Saturate: '<S493>/Saturation2' */
          if (rtb_Switch_an[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_an[0];
          }

          /* End of Saturate: '<S493>/Saturation2' */

          /* Saturate: '<S493>/Saturation1' */
          if (rtb_Switch_an[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_an[1];
          }

          /* End of Saturate: '<S493>/Saturation1' */

          /* Saturate: '<S493>/Saturation3' */
          if (rtb_Divide_pr_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_pr_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S408>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;
          }

          /* End of Saturate: '<S493>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S491>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S491>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S491>/throttle_cmd_valid' */
          /* BusAssignment: '<S408>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S504>/Constant'
           *  Constant: '<S505>/Constant'
           *  Constant: '<S506>/Constant'
           *  Constant: '<S507>/Constant'
           *  Constant: '<S508>/Constant'
           *  Constant: '<S509>/Constant'
           *  Constant: '<S510>/Constant'
           *  Constant: '<S530>/Constant'
           *  Constant: '<S533>/Constant'
           *  DataTypeConversion: '<S491>/Data Type Conversion10'
           *  DataTypeConversion: '<S491>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S513>/bit_shift'
           *  MATLAB Function: '<S514>/bit_shift'
           *  MATLAB Function: '<S515>/bit_shift'
           *  MATLAB Function: '<S517>/bit_shift'
           *  MATLAB Function: '<S518>/bit_shift'
           *  MATLAB Function: '<S519>/bit_shift'
           *  MATLAB Function: '<S520>/bit_shift'
           *  MATLAB Function: '<S521>/bit_shift'
           *  MATLAB Function: '<S522>/bit_shift'
           *  MATLAB Function: '<S525>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S504>/Compare'
           *  RelationalOperator: '<S505>/Compare'
           *  RelationalOperator: '<S506>/Compare'
           *  RelationalOperator: '<S507>/Compare'
           *  RelationalOperator: '<S508>/Compare'
           *  RelationalOperator: '<S509>/Compare'
           *  RelationalOperator: '<S510>/Compare'
           *  RelationalOperator: '<S530>/Compare'
           *  RelationalOperator: '<S533>/Compare'
           *  S-Function (sfix_bitop): '<S491>/p_cmd'
           *  S-Function (sfix_bitop): '<S491>/phi_cmd'
           *  S-Function (sfix_bitop): '<S491>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S491>/q_cmd'
           *  S-Function (sfix_bitop): '<S491>/r_cmd'
           *  S-Function (sfix_bitop): '<S491>/theta_cmd'
           *  S-Function (sfix_bitop): '<S491>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S511>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S512>/az_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           *  Sum: '<S491>/Add'
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

          /* End of Outputs for SubSystem: '<S491>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S491>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S491>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S296>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S296>/Mission' incorporates:
             *  ActionPort: '<S407>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S296>/Switch Case' incorporates:
             *  UnitDelay: '<S410>/Delay Input1'
             *
             * Block description for '<S410>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S296>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S296>/Mission' incorporates:
             *  ActionPort: '<S407>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S407>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S296>/Switch Case' incorporates:
             *  Chart: '<S449>/Motion Status'
             *  Chart: '<S459>/Motion State'
             *  Delay: '<S415>/Delay'
             *  Delay: '<S437>/Delay'
             *  DiscreteIntegrator: '<S418>/Integrator'
             *  DiscreteIntegrator: '<S418>/Integrator1'
             *  DiscreteIntegrator: '<S433>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S438>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S485>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S407>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S296>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S296>/Mission' incorporates:
           *  ActionPort: '<S407>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S410>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S410>/Delay Input1'
           *
           * Block description for '<S410>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S407>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S411>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S458>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S448>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S437>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S433>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S485>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S415>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S418>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S418>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S459>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S449>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S437>/Delay' incorporates:
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
          /* Switch: '<S433>/Switch2' incorporates:
           *  Constant: '<S433>/vel'
           *  Constant: '<S442>/Constant'
           *  RelationalOperator: '<S442>/Compare'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S433>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S438>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S410>/Delay Input1'
           *
           * Block description for '<S410>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTAT_kf;

          /* RelationalOperator: '<S432>/Compare' incorporates:
           *  Constant: '<S489>/Constant'
           *  RelationalOperator: '<S489>/Compare'
           *  UnitDelay: '<S410>/Delay Input1'
           *
           * Block description for '<S410>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S433>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S459>/Motion State' incorporates:
           *  Constant: '<S459>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S459>/Square'
           *  Math: '<S459>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S459>/Sqrt'
           *  Sum: '<S459>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S458>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S468>/Integrator1'
           *  Gain: '<S462>/Gain6'
           *  Gain: '<S466>/Gain'
           *  Gain: '<S467>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S468>/Subtract'
           *  Sum: '<S469>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S458>/Hold Control' incorporates:
               *  ActionPort: '<S461>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S458>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S458>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S458>/Hold Control' incorporates:
             *  ActionPort: '<S461>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S458>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S458>/Brake Control' incorporates:
             *  ActionPort: '<S460>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S458>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S458>/Move Control' incorporates:
               *  ActionPort: '<S462>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S458>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S468>/Integrator'
               *  DiscreteIntegrator: '<S468>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S458>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S458>/Move Control' incorporates:
             *  ActionPort: '<S462>/Action Port'
             */
            /* SignalConversion: '<S462>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S469>/Multiply1' incorporates:
             *  Constant: '<S469>/const1'
             *  DiscreteIntegrator: '<S468>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S462>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S469>/Multiply1' incorporates:
             *  Constant: '<S469>/const1'
             *  DiscreteIntegrator: '<S468>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S466>/Dead Zone' incorporates:
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

            /* Sum: '<S469>/Add' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator1'
             *  Gain: '<S462>/Gain6'
             *  Gain: '<S466>/Gain'
             *  Sum: '<S468>/Subtract'
             */
            rtb_Divide_i5[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S467>/Dead Zone' incorporates:
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

            /* Sum: '<S469>/Add' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator1'
             *  Gain: '<S462>/Gain6'
             *  Gain: '<S467>/Gain'
             *  Sum: '<S468>/Subtract'
             */
            rtb_Divide_i5[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S466>/Dead Zone' incorporates:
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

            /* Signum: '<S469>/Sign' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator1'
             *  Gain: '<S462>/Gain6'
             *  Gain: '<S466>/Gain'
             *  Sum: '<S468>/Subtract'
             *  Sum: '<S469>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S469>/Add2' incorporates:
             *  Abs: '<S469>/Abs'
             *  Gain: '<S469>/Gain'
             *  Gain: '<S469>/Gain1'
             *  Product: '<S469>/Multiply2'
             *  Product: '<S469>/Multiply3'
             *  Signum: '<S469>/Sign'
             *  Sqrt: '<S469>/Sqrt'
             *  Sum: '<S469>/Add1'
             *  Sum: '<S469>/Subtract'
             */
            rtb_Sign5_l = (sqrtf((8.0F * fabsf(rtb_Divide_i5[0]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[0];

            /* Sum: '<S469>/Add3' incorporates:
             *  Signum: '<S469>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] + FMS_ConstB.d_oe;

            /* Sum: '<S469>/Subtract1' incorporates:
             *  Signum: '<S469>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] - FMS_ConstB.d_oe;

            /* Signum: '<S469>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S469>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S469>/Add5' incorporates:
             *  Gain: '<S469>/Gain2'
             *  Product: '<S469>/Multiply4'
             *  Signum: '<S469>/Sign'
             *  Sum: '<S469>/Add2'
             *  Sum: '<S469>/Add4'
             *  Sum: '<S469>/Subtract2'
             */
            rtb_Sign5_l += ((rtb_Divide_i5[0] - rtb_Sign5_l) + rtb_Subtract_hb[0])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S468>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S469>/Sign4' incorporates:
             *  Sum: '<S469>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Sign5_l - FMS_ConstB.d_oe;

            /* Signum: '<S469>/Sign3' incorporates:
             *  Sum: '<S469>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Sign5_l + FMS_ConstB.d_oe;

            /* Signum: '<S469>/Sign5' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Sign5_l;
            }

            /* Signum: '<S469>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S469>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S469>/Sign6' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Sign5_l;
            }

            /* Update for DiscreteIntegrator: '<S468>/Integrator' incorporates:
             *  Constant: '<S469>/const'
             *  Gain: '<S469>/Gain3'
             *  Product: '<S469>/Divide'
             *  Product: '<S469>/Multiply5'
             *  Product: '<S469>/Multiply6'
             *  Sum: '<S469>/Subtract4'
             *  Sum: '<S469>/Subtract5'
             *  Sum: '<S469>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Sign5_l / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S467>/Dead Zone' incorporates:
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

            /* Signum: '<S469>/Sign' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator1'
             *  Gain: '<S462>/Gain6'
             *  Gain: '<S467>/Gain'
             *  Sum: '<S468>/Subtract'
             *  Sum: '<S469>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S469>/Add2' incorporates:
             *  Abs: '<S469>/Abs'
             *  Gain: '<S469>/Gain'
             *  Gain: '<S469>/Gain1'
             *  Product: '<S469>/Multiply2'
             *  Product: '<S469>/Multiply3'
             *  Signum: '<S469>/Sign'
             *  Sqrt: '<S469>/Sqrt'
             *  Sum: '<S469>/Add1'
             *  Sum: '<S469>/Subtract'
             */
            rtb_Sign5_l = (sqrtf((8.0F * fabsf(rtb_Divide_i5[1]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[1];

            /* Sum: '<S469>/Add3' incorporates:
             *  Signum: '<S469>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[1] + FMS_ConstB.d_oe;

            /* Sum: '<S469>/Subtract1' incorporates:
             *  Signum: '<S469>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[1] - FMS_ConstB.d_oe;

            /* Signum: '<S469>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S469>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S469>/Add5' incorporates:
             *  Gain: '<S469>/Gain2'
             *  Product: '<S469>/Multiply4'
             *  Signum: '<S469>/Sign'
             *  Sum: '<S469>/Add2'
             *  Sum: '<S469>/Add4'
             *  Sum: '<S469>/Subtract2'
             */
            rtb_Sign5_l += ((rtb_Divide_i5[1] - rtb_Sign5_l) + rtb_Subtract_hb[1])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S468>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S468>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S469>/Sign4' incorporates:
             *  Sum: '<S469>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Sign5_l - FMS_ConstB.d_oe;

            /* Signum: '<S469>/Sign3' incorporates:
             *  Sum: '<S469>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Sign5_l + FMS_ConstB.d_oe;

            /* Signum: '<S469>/Sign5' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Sign5_l;
            }

            /* Signum: '<S469>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S469>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S469>/Sign6' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Sign5_l;
            }

            /* Update for DiscreteIntegrator: '<S468>/Integrator' incorporates:
             *  Constant: '<S469>/const'
             *  Gain: '<S469>/Gain3'
             *  Product: '<S469>/Divide'
             *  Product: '<S469>/Multiply5'
             *  Product: '<S469>/Multiply6'
             *  Sum: '<S469>/Subtract4'
             *  Sum: '<S469>/Subtract5'
             *  Sum: '<S469>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Sign5_l / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S458>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S458>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S449>/Motion Status' incorporates:
           *  Abs: '<S449>/Abs'
           *  Constant: '<S449>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S448>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S448>/Hold Control' incorporates:
               *  ActionPort: '<S451>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S448>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S448>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S448>/Hold Control' incorporates:
             *  ActionPort: '<S451>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S448>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S448>/Brake Control' incorporates:
             *  ActionPort: '<S450>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S448>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S448>/Move Control' incorporates:
               *  ActionPort: '<S452>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S448>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S455>/Integrator'
               *  DiscreteIntegrator: '<S455>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S448>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S448>/Move Control' incorporates:
             *  ActionPort: '<S452>/Action Port'
             */
            /* Product: '<S456>/Multiply1' incorporates:
             *  Constant: '<S456>/const1'
             *  DiscreteIntegrator: '<S455>/Integrator'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S454>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S454>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S456>/Add' incorporates:
             *  DiscreteIntegrator: '<S455>/Integrator1'
             *  Gain: '<S452>/Gain1'
             *  Gain: '<S454>/Gain'
             *  Sum: '<S455>/Subtract'
             */
            rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_Saturation_e * -FMS_PARAM.VEL_Z_LIM)
              + rtb_Divide_pr_idx_1;

            /* Signum: '<S456>/Sign' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_0;
            }

            /* End of Signum: '<S456>/Sign' */

            /* Sum: '<S456>/Add2' incorporates:
             *  Abs: '<S456>/Abs'
             *  Gain: '<S456>/Gain'
             *  Gain: '<S456>/Gain1'
             *  Product: '<S456>/Multiply2'
             *  Product: '<S456>/Multiply3'
             *  Sqrt: '<S456>/Sqrt'
             *  Sum: '<S456>/Add1'
             *  Sum: '<S456>/Subtract'
             */
            rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
              FMS_ConstB.d_oc) * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_e + rtb_Divide_pr_idx_1;

            /* Sum: '<S456>/Add4' */
            rtb_Divide_pr_idx_2 = (rtb_Divide_pr_idx_0 - rtb_Saturation_e) +
              rtb_Divide_pr_idx_1;

            /* Sum: '<S456>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_oc;

            /* Sum: '<S456>/Subtract1' */
            rtb_Divide_pr_idx_0 -= FMS_ConstB.d_oc;

            /* Signum: '<S456>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S456>/Sign1' */

            /* Signum: '<S456>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S456>/Sign2' */

            /* Sum: '<S456>/Add5' incorporates:
             *  Gain: '<S456>/Gain2'
             *  Product: '<S456>/Multiply4'
             *  Sum: '<S456>/Subtract2'
             */
            rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
              0.5F * rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S452>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S455>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S455>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S455>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S456>/Subtract3' */
            rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_oc;

            /* Sum: '<S456>/Add6' */
            rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_oc;

            /* Signum: '<S456>/Sign5' incorporates:
             *  Signum: '<S456>/Sign6'
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;

              /* Signum: '<S456>/Sign6' */
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;

              /* Signum: '<S456>/Sign6' */
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;

              /* Signum: '<S456>/Sign6' */
              rtb_Sign5_l = rtb_Saturation_e;
            }

            /* End of Signum: '<S456>/Sign5' */

            /* Signum: '<S456>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S456>/Sign3' */

            /* Signum: '<S456>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S456>/Sign4' */

            /* Update for DiscreteIntegrator: '<S455>/Integrator' incorporates:
             *  Constant: '<S456>/const'
             *  Gain: '<S456>/Gain3'
             *  Product: '<S456>/Divide'
             *  Product: '<S456>/Multiply5'
             *  Product: '<S456>/Multiply6'
             *  Sum: '<S456>/Subtract4'
             *  Sum: '<S456>/Subtract5'
             *  Sum: '<S456>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_Saturation_e / FMS_ConstB.d_oc
              - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_j *
              ((rtb_Divide_pr_idx_0 - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l
              * 78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S448>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S448>/Switch Case' */

          /* Switch: '<S413>/Switch' incorporates:
           *  Product: '<S437>/Multiply'
           *  Sum: '<S437>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S458>/Saturation1' */
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

            /* End of Saturate: '<S458>/Saturation1' */

            /* Saturate: '<S448>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S448>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S437>/Sum' incorporates:
             *  Delay: '<S437>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S486>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S433>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S437>/Sum' incorporates:
             *  Delay: '<S437>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S433>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S445>/Sqrt' incorporates:
             *  Math: '<S445>/Square'
             *  Sum: '<S433>/Sum'
             *  Sum: '<S445>/Sum of Elements'
             */
            rtb_Divide_pr_idx_0 = sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S488>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S488>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S488>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S487>/Gain' incorporates:
             *  DiscreteIntegrator: '<S485>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S485>/Add'
             */
            rtb_Saturation_e = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S488>/Trigonometric Function3' */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Saturation_e);

            /* Gain: '<S488>/Gain' incorporates:
             *  Trigonometry: '<S488>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Saturation_e);

            /* SignalConversion: '<S488>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S488>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S488>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Saturation_e);

            /* Trigonometry: '<S488>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Saturation_e);

            /* Switch: '<S444>/Switch2' incorporates:
             *  Constant: '<S433>/Constant2'
             *  DiscreteIntegrator: '<S433>/Acceleration_Speed'
             *  RelationalOperator: '<S444>/LowerRelop1'
             *  RelationalOperator: '<S444>/UpperRelop'
             *  Switch: '<S444>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_Saturation_e = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S444>/Switch' incorporates:
               *  Constant: '<S433>/Constant2'
               */
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S444>/Switch2' */

            /* Switch: '<S433>/Switch' */
            if (rtb_Divide_pr_idx_0 > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = d;
            } else {
              /* Gain: '<S433>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Divide_pr_idx_0;

              /* Switch: '<S443>/Switch2' incorporates:
               *  Constant: '<S433>/Constant1'
               *  RelationalOperator: '<S443>/LowerRelop1'
               *  RelationalOperator: '<S443>/UpperRelop'
               *  Switch: '<S443>/Switch'
               */
              if (rtb_Divide_pr_idx_2 > d) {
                rtb_Divide_pr_idx_2 = d;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  /* Switch: '<S443>/Switch' incorporates:
                   *  Constant: '<S433>/Constant1'
                   */
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Switch: '<S443>/Switch2' */
            }

            /* End of Switch: '<S433>/Switch' */

            /* Switch: '<S433>/Switch1' incorporates:
             *  Sum: '<S433>/Sum1'
             */
            if (rtb_Saturation_e - rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;
            }

            /* End of Switch: '<S433>/Switch1' */

            /* Sum: '<S486>/Sum of Elements' incorporates:
             *  Math: '<S486>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S486>/Math Function1' incorporates:
             *  Sum: '<S486>/Sum of Elements'
             *
             * About '<S486>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S486>/Math Function1' */

            /* Switch: '<S486>/Switch' incorporates:
             *  Constant: '<S486>/Constant'
             *  Product: '<S486>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Subtract_hb[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S486>/Switch' */

            /* Product: '<S484>/Multiply2' incorporates:
             *  Product: '<S486>/Divide'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_0 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_1 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S439>/Sum1' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S439>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Sign5_l = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S439>/Divide' incorporates:
             *  Math: '<S440>/Square'
             *  Math: '<S441>/Square'
             *  Sqrt: '<S440>/Sqrt'
             *  Sqrt: '<S441>/Sqrt'
             *  Sum: '<S439>/Sum'
             *  Sum: '<S439>/Sum1'
             *  Sum: '<S440>/Sum of Elements'
             *  Sum: '<S441>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Sign5_l * rtb_Sign5_l + rtb_a_bx *
              rtb_a_bx) / sqrtf(rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 +
                                rtb_Saturation_e * rtb_Saturation_e);

            /* Saturate: '<S439>/Saturation' */
            if (rtb_Saturation_e > 1.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = 0.0F;
              }
            }

            /* End of Saturate: '<S439>/Saturation' */

            /* Product: '<S437>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * rtb_Divide_pr_idx_1 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_0;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S430>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S439>/Multiply'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S430>/Sum2'
             *  Sum: '<S439>/Add'
             *  Sum: '<S439>/Subtract'
             */
            rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
              - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_e +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_VectorConcatenate_g0[0];
            rtb_Switch_c2[1] = rtb_VectorConcatenate_g0[1];

            /* Saturate: '<S430>/Saturation1' incorporates:
             *  Product: '<S437>/Multiply'
             */
            if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_Saturation_e;
            }

            /* End of Saturate: '<S430>/Saturation1' */
          }

          /* End of Switch: '<S413>/Switch' */

          /* Delay: '<S415>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S418>/Integrator1' incorporates:
           *  Delay: '<S415>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S422>/Rem' incorporates:
           *  Constant: '<S422>/Constant1'
           *  DiscreteIntegrator: '<S418>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S417>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S422>/Switch' incorporates:
           *  Abs: '<S422>/Abs'
           *  Constant: '<S422>/Constant'
           *  Constant: '<S423>/Constant'
           *  Product: '<S422>/Multiply'
           *  RelationalOperator: '<S423>/Compare'
           *  Sum: '<S422>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S422>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S422>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S422>/Switch' */

          /* Gain: '<S417>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S417>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S417>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S411>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S411>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S411>/Bus Assignment' incorporates:
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

          /* Math: '<S479>/Math Function1'
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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S479>/Product'
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

          /* End of Switch: '<S479>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S411>/Sum' incorporates:
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

          /* SignalConversion: '<S429>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S411>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S429>/Math Function' incorporates:
           *  Sum: '<S411>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S429>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S429>/Math Function1' incorporates:
           *  Sum: '<S429>/Sum of Elements'
           *
           * About '<S429>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S429>/Math Function1' */

          /* Switch: '<S429>/Switch' incorporates:
           *  Constant: '<S429>/Constant'
           *  Product: '<S429>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_a_bx = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_a_bx = 1.0F;
          }

          /* End of Switch: '<S429>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S435>/NearbyRefWP' incorporates:
           *  Constant: '<S411>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S435>/SearchL1RefWP' incorporates:
           *  Constant: '<S411>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S435>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S435>/Switch1' incorporates:
           *  Constant: '<S472>/Constant'
           *  RelationalOperator: '<S472>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S471>/Compare' incorporates:
             *  Constant: '<S471>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S435>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S435>/Switch' */
          }

          /* End of Switch: '<S435>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S436>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Sign5_l;
          rtb_Square_bg[0] = rtb_Sign5_l * rtb_Sign5_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S436>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S480>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S480>/Sum of Elements' incorporates:
           *  Math: '<S480>/Math Function'
           *  Sum: '<S478>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Square_bg[0] + rtb_Sign5_l * rtb_Sign5_l;

          /* Math: '<S480>/Math Function1' incorporates:
           *  Sum: '<S480>/Sum of Elements'
           *
           * About '<S480>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S480>/Math Function1' */

          /* Switch: '<S480>/Switch' incorporates:
           *  Constant: '<S480>/Constant'
           *  Product: '<S480>/Product'
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

          /* End of Switch: '<S480>/Switch' */

          /* Product: '<S479>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S482>/Sum of Elements' incorporates:
           *  Math: '<S482>/Math Function'
           *  SignalConversion: '<S482>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S482>/Math Function1' incorporates:
           *  Sum: '<S482>/Sum of Elements'
           *
           * About '<S482>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S482>/Math Function1' */

          /* Switch: '<S482>/Switch' incorporates:
           *  Constant: '<S482>/Constant'
           *  Product: '<S482>/Product'
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

          /* End of Switch: '<S482>/Switch' */

          /* Product: '<S480>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S483>/Switch' */

          /* Product: '<S483>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S482>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S429>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_a_bx;

          /* Product: '<S483>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S482>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S429>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_a_bx;

          /* Sum: '<S481>/Subtract' incorporates:
           *  Product: '<S481>/Multiply'
           *  Product: '<S481>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S476>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S476>/Sign1' */

          /* Switch: '<S476>/Switch2' incorporates:
           *  Constant: '<S476>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S476>/Switch2' */

          /* DotProduct: '<S476>/Dot Product' */
          rtb_Sign5_l = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S476>/Acos' incorporates:
           *  DotProduct: '<S476>/Dot Product'
           */
          if (rtb_Sign5_l > 1.0F) {
            rtb_Sign5_l = 1.0F;
          } else {
            if (rtb_Sign5_l < -1.0F) {
              rtb_Sign5_l = -1.0F;
            }
          }

          /* Product: '<S476>/Multiply' incorporates:
           *  Trigonometry: '<S476>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Sign5_l);

          /* Saturate: '<S436>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S436>/Saturation' */

          /* Product: '<S436>/Divide' incorporates:
           *  Constant: '<S411>/L1'
           *  Constant: '<S436>/Constant'
           *  Gain: '<S436>/Gain'
           *  Math: '<S436>/Square'
           *  MinMax: '<S436>/Max'
           *  MinMax: '<S436>/Min'
           *  Product: '<S436>/Multiply1'
           *  Sqrt: '<S478>/Sqrt'
           *  Trigonometry: '<S436>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S427>/Subtract' incorporates:
           *  Product: '<S427>/Multiply'
           *  Product: '<S427>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S416>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S416>/Sign1' */

          /* Switch: '<S416>/Switch2' incorporates:
           *  Constant: '<S416>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S416>/Switch2' */

          /* DotProduct: '<S416>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S416>/Acos' incorporates:
           *  DotProduct: '<S416>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S416>/Multiply' incorporates:
           *  Trigonometry: '<S416>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S419>/Rem' incorporates:
           *  Constant: '<S419>/Constant1'
           *  Delay: '<S415>/Delay'
           *  Sum: '<S415>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S419>/Switch' incorporates:
           *  Abs: '<S419>/Abs'
           *  Constant: '<S419>/Constant'
           *  Constant: '<S425>/Constant'
           *  Product: '<S419>/Multiply'
           *  RelationalOperator: '<S425>/Compare'
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

          /* Sum: '<S415>/Sum' incorporates:
           *  Delay: '<S415>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S424>/Multiply1' incorporates:
           *  Constant: '<S424>/const1'
           *  DiscreteIntegrator: '<S418>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S424>/Add' incorporates:
           *  DiscreteIntegrator: '<S418>/Integrator1'
           *  Sum: '<S418>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_mf -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S424>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S424>/Sign' */

          /* Sum: '<S424>/Add2' incorporates:
           *  Abs: '<S424>/Abs'
           *  Gain: '<S424>/Gain'
           *  Gain: '<S424>/Gain1'
           *  Product: '<S424>/Multiply2'
           *  Product: '<S424>/Multiply3'
           *  Sqrt: '<S424>/Sqrt'
           *  Sum: '<S424>/Add1'
           *  Sum: '<S424>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S424>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S424>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_m;

          /* Sum: '<S424>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_m;

          /* Signum: '<S424>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S424>/Sign1' */

          /* Signum: '<S424>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S424>/Sign2' */

          /* Sum: '<S424>/Add5' incorporates:
           *  Gain: '<S424>/Gain2'
           *  Product: '<S424>/Multiply4'
           *  Sum: '<S424>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S424>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_m;

          /* Sum: '<S424>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_m;

          /* Product: '<S424>/Divide' */
          rtb_Sign5_l = rtb_Saturation_e / FMS_ConstB.d_m;

          /* Signum: '<S424>/Sign5' incorporates:
           *  Signum: '<S424>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_a_bx = -1.0F;

            /* Signum: '<S424>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_a_bx = 1.0F;

            /* Signum: '<S424>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_a_bx = rtb_Saturation_e;

            /* Signum: '<S424>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S424>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S415>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S420>/Rem' incorporates:
           *  Constant: '<S420>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S420>/Switch' incorporates:
           *  Abs: '<S420>/Abs'
           *  Constant: '<S420>/Constant'
           *  Constant: '<S426>/Constant'
           *  Product: '<S420>/Multiply'
           *  RelationalOperator: '<S426>/Compare'
           *  Sum: '<S420>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S420>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S420>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S420>/Switch' */

          /* Abs: '<S413>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S437>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S431>/Constant'
           *  RelationalOperator: '<S431>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S433>/Acceleration_Speed' incorporates:
           *  Constant: '<S433>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S437>/Divide1' */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / d;

          /* Saturate: '<S437>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S437>/Saturation' */

          /* Update for DiscreteIntegrator: '<S485>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S415>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S418>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S418>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S424>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S424>/Sign3' */

          /* Signum: '<S424>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S424>/Sign4' */

          /* Update for DiscreteIntegrator: '<S418>/Integrator' incorporates:
           *  Constant: '<S424>/const'
           *  Gain: '<S424>/Gain3'
           *  Product: '<S424>/Multiply5'
           *  Product: '<S424>/Multiply6'
           *  Sum: '<S424>/Subtract4'
           *  Sum: '<S424>/Subtract5'
           *  Sum: '<S424>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S418>/Integrator' */
          /* End of Outputs for SubSystem: '<S407>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S410>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S410>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S296>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S296>/Unknown' incorporates:
           *  ActionPort: '<S409>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S296>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
         *  ActionPort: '<S295>/Action Port'
         */
        /* SwitchCase: '<S295>/Switch Case' */
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
            /* Disable for SwitchCase: '<S394>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S310>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S328>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S344>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S369>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S356>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S295>/Acro' incorporates:
           *  ActionPort: '<S300>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S300>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S300>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S300>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Gain: '<S305>/Gain'
           *  Gain: '<S305>/Gain1'
           *  Gain: '<S305>/Gain2'
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

          /* Saturate: '<S306>/Saturation' incorporates:
           *  Constant: '<S306>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  Sum: '<S306>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_Saturation_e = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S306>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S300>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S306>/Constant5'
           *  Gain: '<S306>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S306>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Saturation_e), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S295>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Stabilize' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S390>/Integrator'
             *  DiscreteIntegrator: '<S390>/Integrator1'
             *  DiscreteIntegrator: '<S391>/Integrator'
             *  DiscreteIntegrator: '<S391>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S295>/Stabilize' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S395>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S295>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Stabilize' incorporates:
           *  ActionPort: '<S303>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S385>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S395>/Motion State' incorporates:
           *  Abs: '<S395>/Abs'
           *  Abs: '<S395>/Abs1'
           *  Constant: '<S405>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S405>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S394>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S394>/Hold Control' incorporates:
               *  ActionPort: '<S397>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S394>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S394>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S394>/Hold Control' incorporates:
             *  ActionPort: '<S397>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S394>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S394>/Brake Control' incorporates:
             *  ActionPort: '<S396>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S394>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S394>/Move Control' incorporates:
               *  ActionPort: '<S398>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S394>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S394>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S394>/Move Control' incorporates:
             *  ActionPort: '<S398>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S394>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S394>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S387>/Switch' incorporates:
           *  Constant: '<S387>/Constant'
           *  Constant: '<S387>/Constant4'
           *  Constant: '<S387>/Constant5'
           *  Gain: '<S387>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S387>/Saturation'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S387>/Add'
           *  Sum: '<S387>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S387>/Saturation' */
              rtb_Saturation_e = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S387>/Saturation' */
              rtb_Saturation_e = 0.0F;
            } else {
              /* Saturate: '<S387>/Saturation' incorporates:
               *  Constant: '<S387>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S40>/Signal Copy2'
               *  Sum: '<S387>/Sum'
               */
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              rtb_Saturation_e), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S387>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S303>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S303>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S303>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DataTypeConversion: '<S385>/Data Type Conversion'
           *  DiscreteIntegrator: '<S390>/Integrator1'
           *  DiscreteIntegrator: '<S391>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S385>/Multiply'
           *  Product: '<S385>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S394>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
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
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S394>/Saturation' */

          /* BusAssignment: '<S303>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S393>/Multiply1' incorporates:
           *  Constant: '<S393>/const1'
           *  DiscreteIntegrator: '<S391>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S389>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S389>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S393>/Add' incorporates:
           *  DiscreteIntegrator: '<S391>/Integrator1'
           *  Gain: '<S385>/Gain1'
           *  Gain: '<S389>/Gain'
           *  Sum: '<S391>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

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
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S393>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S393>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_g;

          /* Sum: '<S393>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_g;

          /* Signum: '<S393>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
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
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S393>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_g;

          /* Sum: '<S393>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_g;

          /* Product: '<S393>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_g;

          /* Signum: '<S393>/Sign5' incorporates:
           *  Signum: '<S393>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S393>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S393>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Divide_lr_idx_3;

            /* Signum: '<S393>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S393>/Sign5' */

          /* Product: '<S392>/Multiply1' incorporates:
           *  Constant: '<S392>/const1'
           *  DiscreteIntegrator: '<S390>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S388>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S388>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S392>/Add' incorporates:
           *  DiscreteIntegrator: '<S390>/Integrator1'
           *  Gain: '<S385>/Gain'
           *  Gain: '<S388>/Gain'
           *  Sum: '<S390>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S392>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S392>/Sign' */

          /* Sum: '<S392>/Add2' incorporates:
           *  Abs: '<S392>/Abs'
           *  Gain: '<S392>/Gain'
           *  Gain: '<S392>/Gain1'
           *  Product: '<S392>/Multiply2'
           *  Product: '<S392>/Multiply3'
           *  Sqrt: '<S392>/Sqrt'
           *  Sum: '<S392>/Add1'
           *  Sum: '<S392>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S392>/Add4' */
          rtb_a_bx = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S392>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_a;

          /* Sum: '<S392>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_a;

          /* Signum: '<S392>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S392>/Sign1' */

          /* Signum: '<S392>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S392>/Sign2' */

          /* Sum: '<S392>/Add5' incorporates:
           *  Gain: '<S392>/Gain2'
           *  Product: '<S392>/Multiply4'
           *  Sum: '<S392>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S390>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S390>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S391>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S391>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S393>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S393>/Sign3' */

          /* Signum: '<S393>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S393>/Sign4' */

          /* Update for DiscreteIntegrator: '<S391>/Integrator' incorporates:
           *  Constant: '<S393>/const'
           *  Gain: '<S393>/Gain3'
           *  Product: '<S393>/Multiply5'
           *  Product: '<S393>/Multiply6'
           *  Sum: '<S393>/Subtract4'
           *  Sum: '<S393>/Subtract5'
           *  Sum: '<S393>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_o
            * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S392>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_a;

          /* Sum: '<S392>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_a;

          /* Signum: '<S392>/Sign5' incorporates:
           *  Signum: '<S392>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S392>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S392>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S392>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S392>/Sign5' */

          /* Signum: '<S392>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S392>/Sign3' */

          /* Signum: '<S392>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S392>/Sign4' */

          /* Update for DiscreteIntegrator: '<S390>/Integrator' incorporates:
           *  Constant: '<S392>/const'
           *  Gain: '<S392>/Gain3'
           *  Product: '<S392>/Divide'
           *  Product: '<S392>/Multiply5'
           *  Product: '<S392>/Multiply6'
           *  Sum: '<S392>/Subtract4'
           *  Sum: '<S392>/Subtract5'
           *  Sum: '<S392>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_a -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_k * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S295>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Altitude' incorporates:
             *  ActionPort: '<S301>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S324>/Integrator'
             *  DiscreteIntegrator: '<S324>/Integrator1'
             *  DiscreteIntegrator: '<S325>/Integrator'
             *  DiscreteIntegrator: '<S325>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S295>/Altitude' incorporates:
             *  ActionPort: '<S301>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S311>/Motion Status'
             *  Chart: '<S329>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S295>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Altitude' incorporates:
           *  ActionPort: '<S301>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S311>/Motion Status' incorporates:
           *  Abs: '<S311>/Abs'
           *  Abs: '<S311>/Abs1'
           *  Constant: '<S320>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S320>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S310>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S310>/Hold Control' incorporates:
               *  ActionPort: '<S313>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S310>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S310>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S310>/Hold Control' incorporates:
             *  ActionPort: '<S313>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S310>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S310>/Brake Control' incorporates:
             *  ActionPort: '<S312>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S310>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S310>/Move Control' incorporates:
             *  ActionPort: '<S314>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S310>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S310>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S307>/Constant'
           *  Saturate: '<S310>/Saturation1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Divide_pr_idx_1 = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S310>/Saturation1' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S310>/Saturation1' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S310>/Saturation1' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_l;
          }

          /* End of Switch: '<S307>/Switch' */

          /* Logic: '<S308>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S329>/Motion State' incorporates:
           *  Abs: '<S329>/Abs'
           *  Abs: '<S329>/Abs1'
           *  Constant: '<S339>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S339>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S328>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S328>/Hold Control' incorporates:
               *  ActionPort: '<S331>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S328>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S328>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S328>/Hold Control' incorporates:
             *  ActionPort: '<S331>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S328>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S328>/Brake Control' incorporates:
             *  ActionPort: '<S330>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S328>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S328>/Move Control' incorporates:
               *  ActionPort: '<S332>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S328>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S328>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S328>/Move Control' incorporates:
             *  ActionPort: '<S332>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S328>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S328>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S301>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S301>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DataTypeConversion: '<S308>/Data Type Conversion'
           *  DiscreteIntegrator: '<S324>/Integrator1'
           *  DiscreteIntegrator: '<S325>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S308>/Multiply'
           *  Product: '<S308>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S328>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S301>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S301>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S301>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S328>/Saturation' */

          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;

          /* Product: '<S327>/Multiply1' incorporates:
           *  Constant: '<S327>/const1'
           *  DiscreteIntegrator: '<S325>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S323>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S323>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S327>/Add' incorporates:
           *  DiscreteIntegrator: '<S325>/Integrator1'
           *  Gain: '<S308>/Gain1'
           *  Gain: '<S323>/Gain'
           *  Sum: '<S325>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

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
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S327>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S327>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_o;

          /* Sum: '<S327>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_o;

          /* Signum: '<S327>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
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
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S327>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_o;

          /* Sum: '<S327>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_o;

          /* Product: '<S327>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_o;

          /* Signum: '<S327>/Sign5' incorporates:
           *  Signum: '<S327>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S327>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S327>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Divide_lr_idx_3;

            /* Signum: '<S327>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S327>/Sign5' */

          /* Product: '<S326>/Multiply1' incorporates:
           *  Constant: '<S326>/const1'
           *  DiscreteIntegrator: '<S324>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S322>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S322>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S326>/Add' incorporates:
           *  DiscreteIntegrator: '<S324>/Integrator1'
           *  Gain: '<S308>/Gain'
           *  Gain: '<S322>/Gain'
           *  Sum: '<S324>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S326>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S326>/Sign' */

          /* Sum: '<S326>/Add2' incorporates:
           *  Abs: '<S326>/Abs'
           *  Gain: '<S326>/Gain'
           *  Gain: '<S326>/Gain1'
           *  Product: '<S326>/Multiply2'
           *  Product: '<S326>/Multiply3'
           *  Sqrt: '<S326>/Sqrt'
           *  Sum: '<S326>/Add1'
           *  Sum: '<S326>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S326>/Add4' */
          rtb_a_bx = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S326>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_c;

          /* Sum: '<S326>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_c;

          /* Signum: '<S326>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S326>/Sign1' */

          /* Signum: '<S326>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S326>/Sign2' */

          /* Sum: '<S326>/Add5' incorporates:
           *  Gain: '<S326>/Gain2'
           *  Product: '<S326>/Multiply4'
           *  Sum: '<S326>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S324>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S324>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S325>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S325>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S327>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S327>/Sign3' */

          /* Signum: '<S327>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S327>/Sign4' */

          /* Update for DiscreteIntegrator: '<S325>/Integrator' incorporates:
           *  Constant: '<S327>/const'
           *  Gain: '<S327>/Gain3'
           *  Product: '<S327>/Multiply5'
           *  Product: '<S327>/Multiply6'
           *  Sum: '<S327>/Subtract4'
           *  Sum: '<S327>/Subtract5'
           *  Sum: '<S327>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_c *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S326>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_c;

          /* Sum: '<S326>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_c;

          /* Signum: '<S326>/Sign5' incorporates:
           *  Signum: '<S326>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S326>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S326>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S326>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S326>/Sign5' */

          /* Signum: '<S326>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S326>/Sign3' */

          /* Signum: '<S326>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S326>/Sign4' */

          /* Update for DiscreteIntegrator: '<S324>/Integrator' incorporates:
           *  Constant: '<S326>/const'
           *  Gain: '<S326>/Gain3'
           *  Product: '<S326>/Divide'
           *  Product: '<S326>/Multiply5'
           *  Product: '<S326>/Multiply6'
           *  Sum: '<S326>/Subtract4'
           *  Sum: '<S326>/Subtract5'
           *  Sum: '<S326>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_c -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_h * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S295>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S295>/Position' incorporates:
             *  ActionPort: '<S302>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S345>/Motion Status'
             *  Chart: '<S357>/Motion State'
             *  Chart: '<S370>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S295>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Position' incorporates:
           *  ActionPort: '<S302>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S345>/Motion Status' incorporates:
           *  Abs: '<S345>/Abs'
           *  Abs: '<S345>/Abs1'
           *  Constant: '<S354>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S354>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S344>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S344>/Hold Control' incorporates:
               *  ActionPort: '<S347>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S344>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S344>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S344>/Hold Control' incorporates:
             *  ActionPort: '<S347>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S344>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S344>/Brake Control' incorporates:
             *  ActionPort: '<S346>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S344>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S344>/Move Control' incorporates:
             *  ActionPort: '<S348>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S344>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S344>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S357>/Motion State' incorporates:
           *  Abs: '<S357>/Abs'
           *  Abs: '<S357>/Abs1'
           *  Constant: '<S367>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S367>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S370>/Logical Operator' incorporates:
           *  Abs: '<S370>/Abs1'
           *  Abs: '<S370>/Abs2'
           *  Constant: '<S382>/Constant'
           *  Constant: '<S383>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S382>/Compare'
           *  RelationalOperator: '<S383>/Compare'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S370>/Motion State' */
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

          /* End of Chart: '<S370>/Motion State' */

          /* SwitchCase: '<S369>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S369>/Hold Control' incorporates:
               *  ActionPort: '<S371>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S369>/Switch Case' incorporates:
               *  Delay: '<S371>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S369>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S369>/Hold Control' incorporates:
             *  ActionPort: '<S371>/Action Port'
             */
            /* Delay: '<S371>/Delay' incorporates:
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
            /* Trigonometry: '<S375>/Trigonometric Function1' incorporates:
             *  Gain: '<S374>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S375>/Trigonometric Function' incorporates:
             *  Gain: '<S374>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S375>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S375>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S375>/Gain' incorporates:
             *  Gain: '<S374>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S375>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S375>/Trigonometric Function3' incorporates:
             *  Gain: '<S374>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S375>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S375>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* SignalConversion: '<S375>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S371>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S371>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S371>/Sum'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_lr_idx_2 = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S371>/Multiply' incorporates:
             *  SignalConversion: '<S371>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1;
            }

            /* End of Product: '<S371>/Multiply' */

            /* Gain: '<S371>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

            /* Update for Delay: '<S371>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S369>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S369>/Move Control' incorporates:
               *  ActionPort: '<S372>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S369>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S378>/Integrator'
               *  DiscreteIntegrator: '<S378>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S369>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S369>/Move Control' incorporates:
             *  ActionPort: '<S372>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S376>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S376>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S376>/Gain' */
            rtb_Divide_pr_idx_1 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
              rtb_Saturation_e;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S377>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S377>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S377>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation_e;

            /* SignalConversion: '<S379>/TmpSignal ConversionAtSquareInport1' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;
            rtb_Square_bg[1] = rtb_Divide_lr_idx_2;

            /* Sum: '<S379>/Sum of Elements' incorporates:
             *  Math: '<S379>/Square'
             *  SignalConversion: '<S379>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S380>/Sum of Elements'
             *  Switch: '<S372>/Switch'
             */
            rtb_Saturation_e = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 +
              rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

            /* Switch: '<S372>/Switch' incorporates:
             *  Product: '<S380>/Divide'
             *  Sqrt: '<S379>/Sqrt'
             *  Sum: '<S379>/Sum of Elements'
             */
            if (sqrtf(rtb_Saturation_e) > 1.0F) {
              /* Math: '<S380>/Math Function1'
               *
               * About '<S380>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
              } else {
                rtb_Saturation_e = sqrtf(rtb_Saturation_e);
              }

              /* End of Math: '<S380>/Math Function1' */

              /* Switch: '<S380>/Switch' incorporates:
               *  Constant: '<S380>/Constant'
               *  Product: '<S380>/Product'
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

              /* End of Switch: '<S380>/Switch' */
              rtb_Square_bg[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Square_bg[1] = rtb_Switch_an[1] / rtb_Switch_an[2];
            }

            /* Product: '<S381>/Multiply1' incorporates:
             *  Constant: '<S381>/const1'
             *  DiscreteIntegrator: '<S378>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S381>/Add' incorporates:
             *  DiscreteIntegrator: '<S378>/Integrator1'
             *  Gain: '<S372>/Gain6'
             *  Sum: '<S378>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[0] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[0]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S381>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

            /* Sum: '<S381>/Add2' incorporates:
             *  Abs: '<S381>/Abs'
             *  Gain: '<S381>/Gain'
             *  Gain: '<S381>/Gain1'
             *  Product: '<S381>/Multiply2'
             *  Product: '<S381>/Multiply3'
             *  Sqrt: '<S381>/Sqrt'
             *  Sum: '<S381>/Add1'
             *  Sum: '<S381>/Subtract'
             */
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S381>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S381>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S381>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S381>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S381>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S381>/Add5' incorporates:
             *  Gain: '<S381>/Gain2'
             *  Product: '<S381>/Multiply4'
             *  Sum: '<S381>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S378>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S378>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S378>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S378>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S381>/Sign4' incorporates:
             *  Sum: '<S381>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S381>/Sign3' incorporates:
             *  Sum: '<S381>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S381>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S381>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S381>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S381>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Sign5_l = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S378>/Integrator' incorporates:
             *  Constant: '<S381>/const'
             *  Gain: '<S381>/Gain3'
             *  Product: '<S381>/Divide'
             *  Product: '<S381>/Multiply5'
             *  Product: '<S381>/Multiply6'
             *  Sum: '<S381>/Subtract4'
             *  Sum: '<S381>/Subtract5'
             *  Sum: '<S381>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 39.224F) * 0.004F;

            /* Product: '<S381>/Multiply1' incorporates:
             *  Constant: '<S381>/const1'
             *  DiscreteIntegrator: '<S378>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S381>/Add' incorporates:
             *  DiscreteIntegrator: '<S378>/Integrator1'
             *  Gain: '<S372>/Gain6'
             *  Sum: '<S378>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[1] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[1]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S381>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

            /* Sum: '<S381>/Add2' incorporates:
             *  Abs: '<S381>/Abs'
             *  Gain: '<S381>/Gain'
             *  Gain: '<S381>/Gain1'
             *  Product: '<S381>/Multiply2'
             *  Product: '<S381>/Multiply3'
             *  Sqrt: '<S381>/Sqrt'
             *  Sum: '<S381>/Add1'
             *  Sum: '<S381>/Subtract'
             */
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S381>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S381>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S381>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S381>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S381>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S381>/Add5' incorporates:
             *  Gain: '<S381>/Gain2'
             *  Product: '<S381>/Multiply4'
             *  Sum: '<S381>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S378>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S378>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S378>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S378>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S381>/Sign4' incorporates:
             *  Sum: '<S381>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S381>/Sign3' incorporates:
             *  Sum: '<S381>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S381>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S381>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S381>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S381>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Sign5_l = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S378>/Integrator' incorporates:
             *  Constant: '<S381>/const'
             *  Gain: '<S381>/Gain3'
             *  Product: '<S381>/Divide'
             *  Product: '<S381>/Multiply5'
             *  Product: '<S381>/Multiply6'
             *  Sum: '<S381>/Subtract4'
             *  Sum: '<S381>/Subtract5'
             *  Sum: '<S381>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 39.224F) * 0.004F;

            /* End of Outputs for SubSystem: '<S369>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S369>/Switch Case' */

          /* SwitchCase: '<S356>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S356>/Hold Control' incorporates:
               *  ActionPort: '<S359>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S356>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S356>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S356>/Hold Control' incorporates:
             *  ActionPort: '<S359>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S356>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S356>/Brake Control' incorporates:
             *  ActionPort: '<S358>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S356>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S356>/Move Control' incorporates:
               *  ActionPort: '<S360>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S356>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S356>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S356>/Move Control' incorporates:
             *  ActionPort: '<S360>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S356>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S356>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S302>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S302>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S302>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S356>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
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
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S356>/Saturation' */

          /* Saturate: '<S369>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S369>/Saturation1' */

          /* Saturate: '<S344>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S344>/Saturation1' */
          /* End of Outputs for SubSystem: '<S295>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S295>/Unknown' incorporates:
           *  ActionPort: '<S304>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S295>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S47>/Manual' incorporates:
         *  ActionPort: '<S297>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S297>/Bus Assignment'
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S297>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S297>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S297>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S47>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S47>/Unknown' incorporates:
         *  ActionPort: '<S299>/Action Port'
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
   *  DiscreteIntegrator: '<S740>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S740>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S740>/Constant'
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
  /* Start for SwitchCase: '<S298>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S298>/Return' */
  /* Start for SwitchCase: '<S698>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S688>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S298>/Return' */

  /* Start for IfAction SubSystem: '<S298>/Hold' */
  /* Start for SwitchCase: '<S637>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S605>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S616>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S298>/Hold' */
  /* End of Start for SubSystem: '<S47>/SubMode' */

  /* Start for IfAction SubSystem: '<S47>/Auto' */
  /* Start for SwitchCase: '<S296>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S296>/Mission' */
  /* Start for Resettable SubSystem: '<S407>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S458>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S448>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S407>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S296>/Mission' */
  /* End of Start for SubSystem: '<S47>/Auto' */

  /* Start for IfAction SubSystem: '<S47>/Assist' */
  /* Start for SwitchCase: '<S295>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S295>/Stabilize' */
  /* Start for SwitchCase: '<S394>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S295>/Stabilize' */

  /* Start for IfAction SubSystem: '<S295>/Altitude' */
  /* Start for SwitchCase: '<S310>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S328>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S295>/Altitude' */

  /* Start for IfAction SubSystem: '<S295>/Position' */
  /* Start for SwitchCase: '<S344>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S369>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S356>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S295>/Position' */
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
  /* InitializeConditions for Delay: '<S238>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S233>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S88>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S46>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S86>/Mission' */
  /* InitializeConditions for UnitDelay: '<S199>/Delay Input1'
   *
   * Block description for '<S199>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S86>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S46>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S85>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S189>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S189>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S190>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S194>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S194>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S190>/Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S182>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S182>/Integrator' */
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
  /* SystemInitialize for IfAction SubSystem: '<S298>/Takeoff' */
  /* InitializeConditions for Delay: '<S738>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S734>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S734>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S298>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S653>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S653>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S298>/Return' */
  /* InitializeConditions for Delay: '<S683>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S684>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S679>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S725>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S662>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S665>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S665>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S699>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S698>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S698>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S698>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S698>/Move Control' */

  /* SystemInitialize for Merge: '<S698>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S689>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S688>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S688>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S688>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S688>/Move Control' */

  /* SystemInitialize for Merge: '<S688>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S298>/Hold' */
  /* InitializeConditions for Delay: '<S618>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S630>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S630>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S606>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S617>/Motion State' */
  FMS_DW.temporalCounter_i1_il = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S638>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S637>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S637>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S637>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S637>/Move Control' */

  /* SystemInitialize for Merge: '<S637>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S605>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S605>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S605>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S605>/Move Control' */

  /* SystemInitialize for Merge: '<S605>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S616>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S616>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S616>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S616>/Move Control' */

  /* SystemInitialize for Merge: '<S616>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S47>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S296>/Mission' */
  /* InitializeConditions for UnitDelay: '<S410>/Delay Input1'
   *
   * Block description for '<S410>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S407>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S437>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S433>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S485>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S415>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S418>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S418>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S459>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S458>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S458>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S458>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S468>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S468>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S458>/Move Control' */

  /* SystemInitialize for Merge: '<S458>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S458>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S468>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S468>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S458>/Move Control' */

  /* SystemInitialize for Merge: '<S458>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S449>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S448>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S448>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S448>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S455>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S455>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S448>/Move Control' */

  /* SystemInitialize for Merge: '<S448>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S407>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S296>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S47>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S295>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S390>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S391>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S391>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S390>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S395>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S394>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S394>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S394>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S394>/Move Control' */

  /* SystemInitialize for Merge: '<S394>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S324>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S325>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S325>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S324>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S311>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S310>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S310>/Hold Control' */

  /* SystemInitialize for Merge: '<S310>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S329>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S328>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S328>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S328>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S328>/Move Control' */

  /* SystemInitialize for Merge: '<S328>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Position' */
  /* SystemInitialize for Chart: '<S345>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S344>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S344>/Hold Control' */

  /* SystemInitialize for Chart: '<S357>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S370>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S369>/Hold Control' */
  /* InitializeConditions for Delay: '<S371>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S369>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S369>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S378>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S378>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S369>/Move Control' */

  /* SystemInitialize for Merge: '<S369>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S369>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S378>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S378>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S369>/Move Control' */

  /* SystemInitialize for Merge: '<S369>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S344>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S356>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S356>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S356>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S356>/Move Control' */

  /* SystemInitialize for Merge: '<S356>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Position' */
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
