/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2161
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug  6 13:42:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S52>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S603>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S613>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S325>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S87>/Motion State' */
#define FMS_IN_Brake_bw                ((uint8_T)1U)
#define FMS_IN_Hold_od                 ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_BackTrans               ((uint8_T)1U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Fixwing                 ((uint8_T)2U)
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
#define FMS_IN_Multicopter             ((uint8_T)3U)
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
  30.0F,
  17.0F,
  1.0F,
  10.0F,
  8.0F,
  0.785398185F,
  0.785398185F,
  1.04719758F,
  22.0F,
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
                                        *   '<S656>/Constant'
                                        *   '<S155>/Gain'
                                        *   '<S155>/Gain4'
                                        *   '<S155>/Gain5'
                                        *   '<S159>/Constant4'
                                        *   '<S160>/Constant4'
                                        *   '<S523>/L1'
                                        *   '<S47>/Gain'
                                        *   '<S49>/Gain'
                                        *   '<S50>/Gain1'
                                        *   '<S68>/Gain'
                                        *   '<S70>/Gain1'
                                        *   '<S116>/Gain'
                                        *   '<S116>/Gain1'
                                        *   '<S117>/Gain1'
                                        *   '<S132>/Constant4'
                                        *   '<S162>/Gain2'
                                        *   '<S162>/Saturation1'
                                        *   '<S163>/L1'
                                        *   '<S163>/R'
                                        *   '<S163>/Saturation1'
                                        *   '<S180>/Gain'
                                        *   '<S180>/Saturation1'
                                        *   '<S202>/Gain'
                                        *   '<S202>/Saturation1'
                                        *   '<S237>/Gain'
                                        *   '<S237>/Gain1'
                                        *   '<S315>/Gain'
                                        *   '<S315>/Gain1'
                                        *   '<S317>/Constant'
                                        *   '<S341>/L1'
                                        *   '<S419>/Saturation'
                                        *   '<S420>/Saturation1'
                                        *   '<S420>/Saturation2'
                                        *   '<S420>/Saturation3'
                                        *   '<S564>/Land_Speed'
                                        *   '<S565>/Saturation1'
                                        *   '<S644>/Takeoff_Speed'
                                        *   '<S645>/Gain2'
                                        *   '<S645>/Saturation1'
                                        *   '<S51>/Saturation1'
                                        *   '<S62>/Dead Zone'
                                        *   '<S62>/Gain'
                                        *   '<S65>/Dead Zone'
                                        *   '<S65>/Gain'
                                        *   '<S72>/Saturation1'
                                        *   '<S83>/Dead Zone'
                                        *   '<S83>/Gain'
                                        *   '<S86>/Saturation1'
                                        *   '<S119>/Dead Zone'
                                        *   '<S119>/Gain'
                                        *   '<S120>/Dead Zone'
                                        *   '<S120>/Gain'
                                        *   '<S125>/Dead Zone'
                                        *   '<S125>/Gain'
                                        *   '<S133>/Gain'
                                        *   '<S133>/Saturation1'
                                        *   '<S185>/L1'
                                        *   '<S185>/Saturation1'
                                        *   '<S207>/L1'
                                        *   '<S207>/Saturation1'
                                        *   '<S239>/Saturation1'
                                        *   '<S251>/Dead Zone'
                                        *   '<S251>/Gain'
                                        *   '<S252>/Dead Zone'
                                        *   '<S252>/Gain'
                                        *   '<S257>/Saturation'
                                        *   '<S273>/Saturation1'
                                        *   '<S285>/Saturation'
                                        *   '<S298>/Saturation1'
                                        *   '<S318>/Dead Zone'
                                        *   '<S318>/Gain'
                                        *   '<S319>/Dead Zone'
                                        *   '<S319>/Gain'
                                        *   '<S324>/Saturation'
                                        *   '<S473>/Gain2'
                                        *   '<S480>/Gain1'
                                        *   '<S480>/Gain2'
                                        *   '<S529>/Saturation1'
                                        *   '<S539>/Saturation'
                                        *   '<S551>/Saturation1'
                                        *   '<S566>/Constant'
                                        *   '<S569>/Gain2'
                                        *   '<S593>/Constant'
                                        *   '<S593>/vel'
                                        *   '<S593>/Acceleration_Speed'
                                        *   '<S593>/Saturation'
                                        *   '<S593>/Switch'
                                        *   '<S597>/Constant'
                                        *   '<S54>/Gain2'
                                        *   '<S55>/Gain1'
                                        *   '<S60>/Constant'
                                        *   '<S75>/Gain2'
                                        *   '<S76>/Gain1'
                                        *   '<S81>/Constant'
                                        *   '<S89>/L1'
                                        *   '<S90>/Gain6'
                                        *   '<S112>/Constant'
                                        *   '<S138>/L1'
                                        *   '<S138>/Saturation1'
                                        *   '<S242>/Gain2'
                                        *   '<S243>/Gain1'
                                        *   '<S249>/Constant'
                                        *   '<S260>/Gain2'
                                        *   '<S261>/Gain1'
                                        *   '<S268>/Constant'
                                        *   '<S276>/Gain2'
                                        *   '<S277>/Gain1'
                                        *   '<S283>/Constant'
                                        *   '<S288>/Gain2'
                                        *   '<S289>/Gain1'
                                        *   '<S296>/Constant'
                                        *   '<S301>/Gain2'
                                        *   '<S302>/Gain6'
                                        *   '<S312>/Constant'
                                        *   '<S313>/Constant'
                                        *   '<S327>/Gain2'
                                        *   '<S328>/Gain1'
                                        *   '<S335>/Constant'
                                        *   '<S360>/Gain'
                                        *   '<S360>/Saturation1'
                                        *   '<S363>/Constant'
                                        *   '<S363>/vel'
                                        *   '<S363>/Acceleration_Speed'
                                        *   '<S363>/Saturation'
                                        *   '<S363>/Switch'
                                        *   '<S367>/Constant'
                                        *   '<S532>/Gain2'
                                        *   '<S533>/Gain1'
                                        *   '<S542>/Gain2'
                                        *   '<S543>/Gain1'
                                        *   '<S554>/Gain2'
                                        *   '<S555>/Gain6'
                                        *   '<S578>/Gain2'
                                        *   '<S578>/Saturation'
                                        *   '<S579>/Integrator'
                                        *   '<S57>/Dead Zone'
                                        *   '<S57>/Gain'
                                        *   '<S78>/Dead Zone'
                                        *   '<S78>/Gain'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S245>/Land_Speed'
                                        *   '<S246>/Constant'
                                        *   '<S248>/Dead Zone'
                                        *   '<S248>/Gain'
                                        *   '<S265>/Dead Zone'
                                        *   '<S265>/Gain'
                                        *   '<S279>/Land_Speed'
                                        *   '<S280>/Constant'
                                        *   '<S282>/Dead Zone'
                                        *   '<S282>/Gain'
                                        *   '<S293>/Dead Zone'
                                        *   '<S293>/Gain'
                                        *   '<S306>/Dead Zone'
                                        *   '<S306>/Gain'
                                        *   '<S307>/Dead Zone'
                                        *   '<S307>/Gain'
                                        *   '<S332>/Dead Zone'
                                        *   '<S332>/Gain'
                                        *   '<S347>/Gain2'
                                        *   '<S347>/Saturation'
                                        *   '<S348>/Integrator'
                                        *   '<S535>/Dead Zone'
                                        *   '<S535>/Gain'
                                        *   '<S547>/Dead Zone'
                                        *   '<S547>/Gain'
                                        *   '<S559>/Dead Zone'
                                        *   '<S559>/Gain'
                                        *   '<S560>/Dead Zone'
                                        *   '<S560>/Gain'
                                        *   '<S602>/Saturation1'
                                        *   '<S612>/Saturation1'
                                        *   '<S375>/Saturation1'
                                        *   '<S385>/Saturation1'
                                        *   '<S605>/Gain2'
                                        *   '<S606>/Gain1'
                                        *   '<S615>/Gain2'
                                        *   '<S616>/Gain6'
                                        *   '<S378>/Gain2'
                                        *   '<S379>/Gain1'
                                        *   '<S388>/Gain2'
                                        *   '<S389>/Gain6'
                                        *   '<S608>/Dead Zone'
                                        *   '<S608>/Gain'
                                        *   '<S620>/Dead Zone'
                                        *   '<S620>/Gain'
                                        *   '<S621>/Dead Zone'
                                        *   '<S621>/Gain'
                                        *   '<S381>/Dead Zone'
                                        *   '<S381>/Gain'
                                        *   '<S393>/Dead Zone'
                                        *   '<S393>/Gain'
                                        *   '<S394>/Dead Zone'
                                        *   '<S394>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S13>/Constant1'
                                        *   '<S654>/Constant'
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
 * Output and update for atomic system:
 *    '<S209>/NearbyRefWP'
 *    '<S187>/NearbyRefWP'
 *    '<S140>/NearbyRefWP'
 *    '<S595>/NearbyRefWP'
 *    '<S365>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S213>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S209>/OutRegionRegWP'
 *    '<S187>/OutRegionRegWP'
 *    '<S140>/OutRegionRegWP'
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

  /* SignalConversion: '<S214>/TmpSignal ConversionAt SFunction Inport3' */
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
    /* SignalConversion: '<S214>/TmpSignal ConversionAt SFunction Inport3' */
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
 * Output and update for atomic system:
 *    '<S209>/SearchL1RefWP'
 *    '<S187>/SearchL1RefWP'
 *    '<S140>/SearchL1RefWP'
 *    '<S365>/SearchL1RefWP'
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

  /* SignalConversion: '<S215>/TmpSignal ConversionAt SFunction Inport3' */
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
 * Output and update for action system:
 *    '<S41>/Unknown'
 *    '<S39>/Unknown'
 *    '<S38>/Unknown'
 *    '<S36>/Unknown'
 *    '<S227>/Unknown'
 *    '<S225>/Unknown'
 *    '<S224>/Unknown'
 *    '<S37>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S161>/Bus Assignment' incorporates:
   *  Constant: '<S161>/Constant'
   *  Constant: '<S161>/Constant2'
   *  SignalConversion: '<S161>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S161>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S51>/Hold Control'
 *    '<S72>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S54>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S51>/Hold Control'
 *    '<S72>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S54>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S51>/Hold Control'
 *    '<S72>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S54>/Delay' incorporates:
   *  Gain: '<S56>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S54>/Gain2' incorporates:
   *  Delay: '<S54>/Delay'
   *  Gain: '<S56>/Gain'
   *  Sum: '<S54>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S54>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S51>/Brake Control'
 *    '<S72>/Brake Control'
 *    '<S602>/Brake Control'
 *    '<S529>/Brake Control'
 *    '<S539>/Brake Control'
 *    '<S375>/Brake Control'
 *    '<S324>/Brake Control'
 *    '<S239>/Brake Control'
 *    '<S257>/Brake Control'
 *    '<S273>/Brake Control'
 *    '<S285>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S53>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S51>/Move Control'
 *    '<S72>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S51>/Move Control'
 *    '<S72>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S51>/Move Control'
 *    '<S72>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_ci;
  real32_T rtb_Subtract3_m;
  real32_T rtb_a_b;
  real32_T rtb_Add4_lp;
  real32_T rtb_a_f;

  /* Product: '<S59>/Multiply1' incorporates:
   *  Constant: '<S59>/const1'
   *  DiscreteIntegrator: '<S58>/Integrator'
   */
  rtb_Add3_ci = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S57>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S57>/Dead Zone' */

  /* Sum: '<S59>/Add' incorporates:
   *  DiscreteIntegrator: '<S58>/Integrator1'
   *  Gain: '<S55>/Gain1'
   *  Gain: '<S57>/Gain'
   *  Sum: '<S58>/Subtract'
   */
  rtb_Subtract3_m = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_b * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_ci;

  /* Signum: '<S59>/Sign' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_m > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_m;
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
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_m) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_ci;

  /* Sum: '<S59>/Add4' */
  rtb_Add4_lp = (rtb_Subtract3_m - rtb_a_b) + rtb_Add3_ci;

  /* Sum: '<S59>/Add3' */
  rtb_Add3_ci = rtb_Subtract3_m + localC->d;

  /* Sum: '<S59>/Subtract1' */
  rtb_Subtract3_m -= localC->d;

  /* Signum: '<S59>/Sign1' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S59>/Sign1' */

  /* Signum: '<S59>/Sign2' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S59>/Sign2' */

  /* Sum: '<S59>/Add5' incorporates:
   *  Gain: '<S59>/Gain2'
   *  Product: '<S59>/Multiply4'
   *  Sum: '<S59>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_ci - rtb_Subtract3_m) * 0.5F * rtb_Add4_lp;

  /* SignalConversion: '<S55>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S58>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S58>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S58>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S59>/Add6' */
  rtb_Add3_ci = rtb_a_b + localC->d;

  /* Sum: '<S59>/Subtract3' */
  rtb_Subtract3_m = rtb_a_b - localC->d;

  /* Signum: '<S59>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_lp = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_lp = 1.0F;
  } else {
    rtb_Add4_lp = rtb_a_b;
  }

  /* End of Signum: '<S59>/Sign5' */

  /* Signum: '<S59>/Sign3' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S59>/Sign3' */

  /* Signum: '<S59>/Sign4' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S59>/Sign4' */

  /* Signum: '<S59>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_b;
  }

  /* End of Signum: '<S59>/Sign6' */

  /* Update for DiscreteIntegrator: '<S58>/Integrator' incorporates:
   *  Constant: '<S59>/const'
   *  Gain: '<S59>/Gain3'
   *  Product: '<S59>/Divide'
   *  Product: '<S59>/Multiply5'
   *  Product: '<S59>/Multiply6'
   *  Sum: '<S59>/Subtract4'
   *  Sum: '<S59>/Subtract5'
   *  Sum: '<S59>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_lp) *
    localC->Gain4 * ((rtb_Add3_ci - rtb_Subtract3_m) * 0.5F) - rtb_a_f * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S52>/Motion Status'
 *    '<S73>/Motion Status'
 *    '<S240>/Motion Status'
 *    '<S274>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S52>/Motion Status'
 *    '<S73>/Motion Status'
 *    '<S240>/Motion Status'
 *    '<S274>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S52>/Motion Status'
 *    '<S73>/Motion Status'
 *    '<S240>/Motion Status'
 *    '<S274>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S52>/Motion Status' */
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

  /* End of Chart: '<S52>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S602>/Hold Control'
 *    '<S529>/Hold Control'
 *    '<S375>/Hold Control'
 *    '<S239>/Hold Control'
 *    '<S273>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S605>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S602>/Hold Control'
 *    '<S529>/Hold Control'
 *    '<S375>/Hold Control'
 *    '<S239>/Hold Control'
 *    '<S273>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S605>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S602>/Hold Control'
 *    '<S529>/Hold Control'
 *    '<S375>/Hold Control'
 *    '<S239>/Hold Control'
 *    '<S273>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S605>/Delay' incorporates:
   *  Gain: '<S607>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S605>/Gain2' incorporates:
   *  Delay: '<S605>/Delay'
   *  Gain: '<S607>/Gain'
   *  Sum: '<S605>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S605>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S602>/Move Control'
 *    '<S529>/Move Control'
 *    '<S375>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S602>/Move Control'
 *    '<S529>/Move Control'
 *    '<S375>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S602>/Move Control'
 *    '<S529>/Move Control'
 *    '<S375>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_f;
  real32_T rtb_a_f;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S610>/Multiply1' incorporates:
   *  Constant: '<S610>/const1'
   *  DiscreteIntegrator: '<S609>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S608>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_f = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_f = 0.0F;
  } else {
    rtb_a_f = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S608>/Dead Zone' */

  /* Sum: '<S610>/Add' incorporates:
   *  DiscreteIntegrator: '<S609>/Integrator1'
   *  Gain: '<S606>/Gain1'
   *  Gain: '<S608>/Gain'
   *  Sum: '<S609>/Subtract'
   */
  rtb_Subtract3_f = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_f * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S610>/Sign' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_Subtract3_f > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_Subtract3_f;
  }

  /* End of Signum: '<S610>/Sign' */

  /* Sum: '<S610>/Add2' incorporates:
   *  Abs: '<S610>/Abs'
   *  Gain: '<S610>/Gain'
   *  Gain: '<S610>/Gain1'
   *  Product: '<S610>/Multiply2'
   *  Product: '<S610>/Multiply3'
   *  Sqrt: '<S610>/Sqrt'
   *  Sum: '<S610>/Add1'
   *  Sum: '<S610>/Subtract'
   */
  rtb_a_f = (sqrtf((8.0F * fabsf(rtb_Subtract3_f) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_f + rtb_Add3_aw;

  /* Sum: '<S610>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_f - rtb_a_f) + rtb_Add3_aw;

  /* Sum: '<S610>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_f + localC->d;

  /* Sum: '<S610>/Subtract1' */
  rtb_Subtract3_f -= localC->d;

  /* Signum: '<S610>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S610>/Sign1' */

  /* Signum: '<S610>/Sign2' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S610>/Sign2' */

  /* Sum: '<S610>/Add5' incorporates:
   *  Gain: '<S610>/Gain2'
   *  Product: '<S610>/Multiply4'
   *  Sum: '<S610>/Subtract2'
   */
  rtb_a_f += (rtb_Add3_aw - rtb_Subtract3_f) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S609>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S609>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S609>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S609>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S610>/Add6' */
  rtb_Add3_aw = rtb_a_f + localC->d;

  /* Sum: '<S610>/Subtract3' */
  rtb_Subtract3_f = rtb_a_f - localC->d;

  /* Signum: '<S610>/Sign5' */
  if (rtb_a_f < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_f > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_f;
  }

  /* End of Signum: '<S610>/Sign5' */

  /* Signum: '<S610>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S610>/Sign3' */

  /* Signum: '<S610>/Sign4' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S610>/Sign4' */

  /* Signum: '<S610>/Sign6' */
  if (rtb_a_f < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_f > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_f;
  }

  /* End of Signum: '<S610>/Sign6' */

  /* Update for DiscreteIntegrator: '<S609>/Integrator' incorporates:
   *  Constant: '<S610>/const'
   *  Gain: '<S610>/Gain3'
   *  Product: '<S610>/Divide'
   *  Product: '<S610>/Multiply5'
   *  Product: '<S610>/Multiply6'
   *  Sum: '<S610>/Subtract4'
   *  Sum: '<S610>/Subtract5'
   *  Sum: '<S610>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_f / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_f) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S603>/Motion Status'
 *    '<S530>/Motion Status'
 *    '<S376>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S603>/Motion Status'
 *    '<S530>/Motion Status'
 *    '<S376>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S603>/Motion Status'
 *    '<S530>/Motion Status'
 *    '<S376>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S603>/Motion Status' */
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

  /* End of Chart: '<S603>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S612>/Hold Control'
 *    '<S551>/Hold Control'
 *    '<S385>/Hold Control'
 *    '<S298>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S615>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S612>/Hold Control'
 *    '<S551>/Hold Control'
 *    '<S385>/Hold Control'
 *    '<S298>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S615>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S612>/Hold Control'
 *    '<S551>/Hold Control'
 *    '<S385>/Hold Control'
 *    '<S298>/Hold Control'
 */
void FMS_HoldControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rtu_FMS_In_d, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_m_T *localDW)
{
  real32_T rtb_VectorConcatenate_m[9];
  real32_T rtb_VectorConcatenate_d[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_d_tmp;
  real32_T rtb_VectorConcatenate_d_tmp_0;

  /* Delay: '<S615>/Delay' incorporates:
   *  SignalConversion: '<S615>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S619>/Trigonometric Function1' incorporates:
   *  Gain: '<S618>/Gain'
   *  Trigonometry: '<S619>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_m[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S619>/Trigonometric Function' incorporates:
   *  Gain: '<S618>/Gain'
   *  Trigonometry: '<S619>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_m[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S619>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S619>/Constant3'
   */
  rtb_VectorConcatenate_m[2] = 0.0F;

  /* Gain: '<S619>/Gain' */
  rtb_VectorConcatenate_m[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S619>/Trigonometric Function3' */
  rtb_VectorConcatenate_m[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S619>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S619>/Constant4'
   */
  rtb_VectorConcatenate_m[5] = 0.0F;

  /* SignalConversion: '<S619>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_m[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_m[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_m[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S615>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S615>/Delay'
   *  SignalConversion: '<S615>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S615>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S615>/Multiply' incorporates:
   *  SignalConversion: '<S615>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_m[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_m[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S615>/Multiply' */

  /* Gain: '<S615>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S615>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S612>/Brake Control'
 *    '<S551>/Brake Control'
 *    '<S385>/Brake Control'
 *    '<S298>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S614>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S612>/Move Control'
 *    '<S551>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S612>/Move Control'
 *    '<S551>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S612>/Move Control'
 *    '<S551>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_h, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_p_T *localC,
  DW_MoveControl_FMS_l_T *localDW)
{
  real32_T rtb_Subtract3_p;
  real32_T rtb_Add3_l_idx_0;
  real32_T rtb_Subtract3_p_idx_0;
  real32_T rtb_Add3_l_idx_1;
  real32_T rtb_Subtract3_p_idx_1;
  real32_T rtb_v2_ew_idx_0;
  real32_T rtb_v2_ew_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_p_idx_0_0;

  /* DiscreteIntegrator: '<S622>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S623>/Multiply1' incorporates:
   *  Constant: '<S623>/const1'
   *  DiscreteIntegrator: '<S622>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S622>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S623>/Multiply1' incorporates:
   *  Constant: '<S623>/const1'
   *  DiscreteIntegrator: '<S622>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S620>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S620>/Dead Zone' */

  /* Sum: '<S623>/Add' incorporates:
   *  DiscreteIntegrator: '<S622>/Integrator1'
   *  Gain: '<S616>/Gain6'
   *  Gain: '<S620>/Gain'
   *  Sum: '<S622>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S621>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S621>/Dead Zone' */

  /* Sum: '<S623>/Add' incorporates:
   *  DiscreteIntegrator: '<S622>/Integrator1'
   *  Gain: '<S616>/Gain6'
   *  Gain: '<S621>/Gain'
   *  Sum: '<S622>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S623>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S623>/Add2' incorporates:
   *  Abs: '<S623>/Abs'
   *  Gain: '<S623>/Gain'
   *  Gain: '<S623>/Gain1'
   *  Product: '<S623>/Multiply2'
   *  Product: '<S623>/Multiply3'
   *  Signum: '<S623>/Sign'
   *  Sqrt: '<S623>/Sqrt'
   *  Sum: '<S623>/Add1'
   *  Sum: '<S623>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S623>/Add3' incorporates:
   *  Signum: '<S623>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S623>/Subtract1' incorporates:
   *  Signum: '<S623>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S623>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S623>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S623>/Add5' incorporates:
   *  Gain: '<S623>/Gain2'
   *  Product: '<S623>/Multiply4'
   *  Signum: '<S623>/Sign'
   *  Sum: '<S623>/Add2'
   *  Sum: '<S623>/Add4'
   *  Sum: '<S623>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* SignalConversion: '<S622>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S622>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S623>/Sign3' incorporates:
   *  Sum: '<S623>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S623>/Sign4' incorporates:
   *  Sum: '<S623>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S623>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S623>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S623>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S623>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S622>/Integrator' incorporates:
   *  Constant: '<S623>/const'
   *  Gain: '<S623>/Gain3'
   *  Product: '<S623>/Divide'
   *  Product: '<S623>/Multiply5'
   *  Product: '<S623>/Multiply6'
   *  Sum: '<S623>/Subtract4'
   *  Sum: '<S623>/Subtract5'
   *  Sum: '<S623>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S622>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S623>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S623>/Add2' incorporates:
   *  Abs: '<S623>/Abs'
   *  Gain: '<S623>/Gain'
   *  Gain: '<S623>/Gain1'
   *  Product: '<S623>/Multiply2'
   *  Product: '<S623>/Multiply3'
   *  Signum: '<S623>/Sign'
   *  Sqrt: '<S623>/Sqrt'
   *  Sum: '<S623>/Add1'
   *  Sum: '<S623>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S623>/Add3' incorporates:
   *  Signum: '<S623>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S623>/Subtract1' incorporates:
   *  Signum: '<S623>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S623>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S623>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S623>/Add5' incorporates:
   *  Gain: '<S623>/Gain2'
   *  Product: '<S623>/Multiply4'
   *  Signum: '<S623>/Sign'
   *  Sum: '<S623>/Add2'
   *  Sum: '<S623>/Add4'
   *  Sum: '<S623>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* SignalConversion: '<S622>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S622>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S623>/Sign3' incorporates:
   *  Sum: '<S623>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S623>/Sign4' incorporates:
   *  Sum: '<S623>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S623>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S623>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S623>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S623>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S622>/Integrator' incorporates:
   *  Constant: '<S623>/const'
   *  Gain: '<S623>/Gain3'
   *  Product: '<S623>/Divide'
   *  Product: '<S623>/Multiply5'
   *  Product: '<S623>/Multiply6'
   *  Sum: '<S623>/Subtract4'
   *  Sum: '<S623>/Subtract5'
   *  Sum: '<S623>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S622>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S613>/Motion State'
 *    '<S552>/Motion State'
 *    '<S386>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S613>/Motion State'
 *    '<S552>/Motion State'
 *    '<S386>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S613>/Motion State'
 *    '<S552>/Motion State'
 *    '<S386>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S613>/Motion State' */
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

  /* End of Chart: '<S613>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S539>/Hold Control'
 *    '<S324>/Hold Control'
 *    '<S257>/Hold Control'
 *    '<S285>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S542>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S539>/Hold Control'
 *    '<S324>/Hold Control'
 *    '<S257>/Hold Control'
 *    '<S285>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S542>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S539>/Hold Control'
 *    '<S324>/Hold Control'
 *    '<S257>/Hold Control'
 *    '<S285>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S542>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S542>/Sum' incorporates:
   *  Delay: '<S542>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S545>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S545>/Switch' incorporates:
   *  Constant: '<S545>/Constant'
   *  Constant: '<S546>/Constant'
   *  Product: '<S545>/Multiply'
   *  RelationalOperator: '<S546>/Compare'
   *  Sum: '<S545>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S545>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S545>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S545>/Switch' */

  /* Gain: '<S542>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S542>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S539>/Move Control'
 *    '<S324>/Move Control'
 *    '<S257>/Move Control'
 *    '<S285>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S548>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S548>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S539>/Move Control'
 *    '<S324>/Move Control'
 *    '<S257>/Move Control'
 *    '<S285>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S548>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S548>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S539>/Move Control'
 *    '<S324>/Move Control'
 *    '<S257>/Move Control'
 *    '<S285>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_g;
  real32_T rtb_Subtract3_g;
  real32_T rtb_a_pq;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S549>/Multiply1' incorporates:
   *  Constant: '<S549>/const1'
   *  DiscreteIntegrator: '<S548>/Integrator'
   */
  rtb_Add3_g = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S547>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_pq = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_pq = 0.0F;
  } else {
    rtb_a_pq = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S547>/Dead Zone' */

  /* Sum: '<S549>/Add' incorporates:
   *  DiscreteIntegrator: '<S548>/Integrator1'
   *  Gain: '<S543>/Gain1'
   *  Gain: '<S547>/Gain'
   *  Sum: '<S548>/Subtract'
   */
  rtb_Subtract3_g = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_pq * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_g;

  /* Signum: '<S549>/Sign' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_a_pq = -1.0F;
  } else if (rtb_Subtract3_g > 0.0F) {
    rtb_a_pq = 1.0F;
  } else {
    rtb_a_pq = rtb_Subtract3_g;
  }

  /* End of Signum: '<S549>/Sign' */

  /* Sum: '<S549>/Add2' incorporates:
   *  Abs: '<S549>/Abs'
   *  Gain: '<S549>/Gain'
   *  Gain: '<S549>/Gain1'
   *  Product: '<S549>/Multiply2'
   *  Product: '<S549>/Multiply3'
   *  Sqrt: '<S549>/Sqrt'
   *  Sum: '<S549>/Add1'
   *  Sum: '<S549>/Subtract'
   */
  rtb_a_pq = (sqrtf((8.0F * fabsf(rtb_Subtract3_g) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_pq + rtb_Add3_g;

  /* Sum: '<S549>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_g - rtb_a_pq) + rtb_Add3_g;

  /* Sum: '<S549>/Add3' */
  rtb_Add3_g = rtb_Subtract3_g + localC->d;

  /* Sum: '<S549>/Subtract1' */
  rtb_Subtract3_g -= localC->d;

  /* Signum: '<S549>/Sign1' */
  if (rtb_Add3_g < 0.0F) {
    rtb_Add3_g = -1.0F;
  } else {
    if (rtb_Add3_g > 0.0F) {
      rtb_Add3_g = 1.0F;
    }
  }

  /* End of Signum: '<S549>/Sign1' */

  /* Signum: '<S549>/Sign2' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S549>/Sign2' */

  /* Sum: '<S549>/Add5' incorporates:
   *  Gain: '<S549>/Gain2'
   *  Product: '<S549>/Multiply4'
   *  Sum: '<S549>/Subtract2'
   */
  rtb_a_pq += (rtb_Add3_g - rtb_Subtract3_g) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S548>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S548>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S548>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S548>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S549>/Add6' */
  rtb_Add3_g = rtb_a_pq + localC->d;

  /* Sum: '<S549>/Subtract3' */
  rtb_Subtract3_g = rtb_a_pq - localC->d;

  /* Signum: '<S549>/Sign5' */
  if (rtb_a_pq < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_pq;
  }

  /* End of Signum: '<S549>/Sign5' */

  /* Signum: '<S549>/Sign3' */
  if (rtb_Add3_g < 0.0F) {
    rtb_Add3_g = -1.0F;
  } else {
    if (rtb_Add3_g > 0.0F) {
      rtb_Add3_g = 1.0F;
    }
  }

  /* End of Signum: '<S549>/Sign3' */

  /* Signum: '<S549>/Sign4' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S549>/Sign4' */

  /* Signum: '<S549>/Sign6' */
  if (rtb_a_pq < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_pq;
  }

  /* End of Signum: '<S549>/Sign6' */

  /* Update for DiscreteIntegrator: '<S548>/Integrator' incorporates:
   *  Constant: '<S549>/const'
   *  Gain: '<S549>/Gain3'
   *  Product: '<S549>/Divide'
   *  Product: '<S549>/Multiply5'
   *  Product: '<S549>/Multiply6'
   *  Sum: '<S549>/Subtract4'
   *  Sum: '<S549>/Subtract5'
   *  Sum: '<S549>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_pq / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_g - rtb_Subtract3_g) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S325>/Motion State'
 *    '<S258>/Motion State'
 *    '<S286>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S325>/Motion State'
 *    '<S258>/Motion State'
 *    '<S286>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S325>/Motion State'
 *    '<S258>/Motion State'
 *    '<S286>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S325>/Motion State' */
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

  /* End of Chart: '<S325>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S239>/Move Control'
 *    '<S273>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S248>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S248>/Dead Zone' */

  /* Gain: '<S243>/Gain1' incorporates:
   *  Gain: '<S248>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S243>/Switch' incorporates:
   *  Constant: '<S245>/Land_Speed'
   *  Constant: '<S246>/Constant'
   *  Constant: '<S247>/Constant'
   *  Gain: '<S245>/Gain'
   *  Logic: '<S243>/Logical Operator'
   *  MinMax: '<S245>/Min'
   *  RelationalOperator: '<S246>/Compare'
   *  RelationalOperator: '<S247>/Compare'
   *  S-Function (sfix_bitop): '<S243>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S243>/Switch' */
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

  /* Gain: '<S658>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S659>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S659>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S659>/Multiply1' incorporates:
   *  Product: '<S659>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S659>/Divide' incorporates:
   *  Constant: '<S659>/Constant'
   *  Constant: '<S659>/R'
   *  Sqrt: '<S659>/Sqrt'
   *  Sum: '<S659>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S659>/Product3' incorporates:
   *  Constant: '<S659>/Constant1'
   *  Product: '<S659>/Multiply1'
   *  Sum: '<S659>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S659>/Multiply2' incorporates:
   *  Trigonometry: '<S659>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S658>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S663>/Abs' incorporates:
   *  Abs: '<S666>/Abs1'
   *  Switch: '<S663>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S663>/Switch1' incorporates:
   *  Abs: '<S663>/Abs'
   *  Bias: '<S663>/Bias2'
   *  Bias: '<S663>/Bias3'
   *  Constant: '<S660>/Constant'
   *  Constant: '<S660>/Constant1'
   *  Constant: '<S665>/Constant'
   *  Gain: '<S663>/Gain1'
   *  Product: '<S663>/Multiply'
   *  RelationalOperator: '<S665>/Compare'
   *  Switch: '<S660>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S666>/Switch1' incorporates:
     *  Bias: '<S666>/Bias2'
     *  Bias: '<S666>/Bias3'
     *  Constant: '<S666>/Constant'
     *  Constant: '<S667>/Constant'
     *  Math: '<S666>/Math Function'
     *  RelationalOperator: '<S667>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S666>/Switch1' */

    /* Signum: '<S663>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S663>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_d_0 = 180;
  } else {
    rtb_Compare_d_0 = 0;
  }

  /* Sum: '<S660>/Sum' incorporates:
   *  Sum: '<S658>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_d_0;

  /* Product: '<S658>/Multiply' incorporates:
   *  Gain: '<S658>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S662>/Switch1' incorporates:
   *  Abs: '<S662>/Abs1'
   *  Bias: '<S662>/Bias2'
   *  Bias: '<S662>/Bias3'
   *  Constant: '<S662>/Constant'
   *  Constant: '<S664>/Constant'
   *  Math: '<S662>/Math Function'
   *  RelationalOperator: '<S664>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S662>/Switch1' */

  /* Product: '<S658>/Multiply' incorporates:
   *  Gain: '<S658>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_ee;

  /* Gain: '<S658>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S661>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S661>/Sum2' incorporates:
   *  Product: '<S661>/Multiply1'
   *  Product: '<S661>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S661>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S661>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S661>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S655>/Data Type Conversion' incorporates:
   *  Gain: '<S658>/Gain'
   *  Sum: '<S658>/Sum1'
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_m, &FMS_DW.M_msgReservedData);
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_m, &FMS_DW.Msg_FMS_Cmd_h
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_h[0] : NULL;
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
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
  } else {
    FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
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
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
          FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
  /* RelationalOperator: '<S668>/Compare' incorporates:
   *  Abs: '<S657>/Abs'
   *  Constant: '<S668>/Constant'
   *  MinMax: '<S657>/Max'
   *  Sum: '<S657>/Sum'
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
                FMS_DW.is_Manual = FMS_IN_Manual_g;
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
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real_T tmp;
  FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_f >=
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
            FMS_B.state = VehicleState_Hold;
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
          FMS_Auto();
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
        FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
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
              (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
            FMS_DW.durationLastReferenceTick_1_c =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
          FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_c >= 500) {
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
                (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
              FMS_DW.durationLastReferenceTick_1_c =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
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
      /* Reshape: '<S656>/Reshape' incorporates:
       *  Constant: '<S656>/Constant'
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
        FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
        FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_l = false;
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
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
          FMS_DW.condWasTrueAtLastTimeStep_1_l = (FMS_DW.prep_takeoff == 1.0);
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
          FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_l = sf_internal_predicateOutput;
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
    FMS_DW.durationLastReferenceTick_2_j = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_o = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_j = FMS_DW.bl;
    FMS_DW.is_active_Lost_Return = 1U;
    FMS_DW.is_Lost_Return = FMS_IN_Connect;
    FMS_DW.is_active_VTOL_Mode = 1U;
    FMS_DW.is_VTOL_Mode = FMS_IN_Multicopter;
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
          FMS_DW.durationLastReferenceTick_2_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_o = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_j = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_o = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_j = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
          FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_o = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_g > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_j)) {
            FMS_DW.durationLastReferenceTick_2_j =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_j = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2_j > 375) {
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_j)) {
              FMS_DW.durationLastReferenceTick_2_j =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_j = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
              FMS_DW.durationLastReferenceTick_1_g =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_o = FMS_DW.br;
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
       case FMS_IN_BackTrans:
        FMS_B.vtol_state = VTOLState_BackTrans;
        if ((sqrtf(FMS_B.BusConversion_InsertedFor_FMSSt.vn *
                   FMS_B.BusConversion_InsertedFor_FMSSt.vn +
                   FMS_B.BusConversion_InsertedFor_FMSSt.ve *
                   FMS_B.BusConversion_InsertedFor_FMSSt.ve) < 2.5F) ||
            (FMS_DW.temporalCounter_i2 >= 1250U)) {
          FMS_DW.is_VTOL_Mode = FMS_IN_Multicopter;
          FMS_B.vtol_state = VTOLState_Multicopter;
        }
        break;

       case FMS_IN_Fixwing:
        FMS_B.vtol_state = VTOLState_Fixwing;
        if (FMS_B.dd1 == VTOLMode_Multicopter) {
          FMS_DW.is_VTOL_Mode = FMS_IN_BackTrans;
          FMS_DW.temporalCounter_i2 = 0U;
          FMS_B.vtol_state = VTOLState_BackTrans;
        }
        break;

       case FMS_IN_Multicopter:
        FMS_B.vtol_state = VTOLState_Multicopter;
        if (FMS_B.dd1 == VTOLMode_Fixwing) {
          FMS_DW.is_VTOL_Mode = FMS_IN_Fixwing;
          FMS_B.vtol_state = VTOLState_Fixwing;
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_m, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_h[1]);
}

/* Model step function */
void FMS_step(void)
{
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion_o;
  uint16_T rtb_DataTypeConversion1_b;
  real32_T rtb_Saturation_d;
  real32_T rtb_Saturation1_d;
  real32_T rtb_Divide_n4[2];
  real32_T rtb_Switch_d0[3];
  real32_T rtb_Square_h[2];
  real32_T rtb_Saturation1_hc;
  int32_T rtb_n;
  real32_T rtb_Switch_ov[3];
  real32_T rtb_a_bx;
  real32_T rtb_Subtract3_d;
  real32_T rtb_Divide_or;
  real32_T rtb_Sign5_mn;
  MotionState rtb_state_l4;
  real32_T rtb_VectorConcatenate_pc[9];
  MotionState rtb_state_fg;
  boolean_T rtb_Compare_ii;
  MotionState rtb_state_og;
  real_T rtb_Switch1_l4;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  real32_T rtb_Transpose[9];
  boolean_T rtb_LogicalOperator_fl;
  real32_T rtb_P_dg[2];
  real32_T rtb_u;
  real32_T rtb_P_cg[2];
  real32_T rtb_VectorConcatenate_g0[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  real32_T rtb_Switch_f_idx_2;
  real32_T rtb_Switch_f_idx_1;
  real32_T rtb_Switch_f_idx_0;
  real_T rtb_Multiply_l_idx_0;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  real32_T rtb_Divide_d_0;
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

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.dd1 = (VTOLMode)FMS_U.Pilot_Cmd.cmd_2;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S679>/Constant'
   *  Constant: '<S8>/ACCEPT_R'
   *  Constant: '<S8>/MC_ACCEPT_R'
   *  RelationalOperator: '<S679>/Compare'
   */
  if (FMS_B.dd1 == VTOLMode_Multicopter) {
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
      (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_l = rtb_FixPtRelationalOperator_me;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
  {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator_me;
  FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
    FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_o = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_j)) {
    FMS_DW.durationLastReferenceTick_2_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_j = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 4095U) {
    FMS_DW.temporalCounter_i1++;
  }

  if (FMS_DW.temporalCounter_i2 < 2047U) {
    FMS_DW.temporalCounter_i2++;
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
  rtb_Switch_d0[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_ov[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_d0[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_ov[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_d0[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_ov[2] = FMS_B.Cmd_In.cur_waypoint[2];

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
      switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
       case 0:
        /* Disable for SwitchCase: '<S41>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S39>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S38>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_as = -1;
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
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S227>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S612>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S602>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S551>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S529>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S539>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S225>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S337>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S375>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* End of Disable for SubSystem: '<S337>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S224>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S324>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S239>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S257>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S273>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S298>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S285>/Switch Case' */
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
    switch (FMS_B.vtol_state) {
     case VTOLState_Fixwing:
      FMS_DW.SwitchCase_ActiveSubsystem_k = 0;
      break;

     case VTOLState_BackTrans:
      FMS_DW.SwitchCase_ActiveSubsystem_k = 1;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_k = 2;
      break;
    }

    /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_k) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
         case 0:
          /* Disable for SwitchCase: '<S41>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S39>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S38>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S51>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S86>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S72>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_as = -1;
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
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S227>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S612>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S602>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S551>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S529>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S539>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S225>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S337>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S375>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* End of Disable for SubSystem: '<S337>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S224>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S324>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S239>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S257>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S273>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S298>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S285>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S31>/FW_Mode' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* SwitchCase: '<S36>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pn;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_pn) {
        switch (rtPrevAction) {
         case 0:
          /* Disable for SwitchCase: '<S41>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S39>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S38>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S51>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S86>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S72>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_as = -1;
          break;

         case 3:
         case 4:
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S36>/SubMode' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* SwitchCase: '<S41>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S41>/Takeoff' incorporates:
           *  ActionPort: '<S160>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SignalConversion: '<S218>/TmpSignal ConversionAtSquareInport1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Divide_n4[0] = FMS_U.INS_Out.vn;
          rtb_Divide_n4[1] = FMS_U.INS_Out.ve;

          /* Sum: '<S219>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S219>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S218>/Sum of Elements'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S219>/Math Function1' incorporates:
           *  Sum: '<S219>/Sum of Elements'
           *
           * About '<S219>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S219>/Math Function1' */

          /* Switch: '<S219>/Switch' incorporates:
           *  Constant: '<S219>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S219>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Saturation_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S219>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S209>/NearbyRefWP' incorporates:
           *  Constant: '<S207>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S209>/SearchL1RefWP' incorporates:
           *  Constant: '<S207>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Saturation_d);

          /* MATLAB Function: '<S209>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S209>/Switch1' incorporates:
           *  Constant: '<S212>/Constant'
           *  RelationalOperator: '<S212>/Compare'
           */
          if (rtb_Saturation1_d > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S211>/Compare' incorporates:
             *  Constant: '<S211>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_d >= 0.0F);

            /* Switch: '<S209>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S209>/Switch' */
          }

          /* End of Switch: '<S209>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S210>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S220>/Sum of Elements' incorporates:
           *  Math: '<S220>/Math Function'
           */
          rtb_a_bx = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S220>/Math Function1' incorporates:
           *  Sum: '<S220>/Sum of Elements'
           *
           * About '<S220>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_d = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S220>/Math Function1' */

          /* Switch: '<S220>/Switch' incorporates:
           *  Constant: '<S220>/Constant'
           *  Product: '<S220>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Divide_n4[1];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S220>/Switch' */

          /* Product: '<S219>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S222>/Sum of Elements' incorporates:
           *  Math: '<S222>/Math Function'
           *  SignalConversion: '<S222>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S222>/Math Function1' incorporates:
           *  Sum: '<S222>/Sum of Elements'
           *
           * About '<S222>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_d = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S222>/Math Function1' */

          /* Switch: '<S222>/Switch' incorporates:
           *  Constant: '<S222>/Constant'
           *  Product: '<S222>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_f_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S222>/Switch' */

          /* Product: '<S220>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S223>/Sum of Elements' incorporates:
           *  Math: '<S223>/Math Function'
           *  SignalConversion: '<S223>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S223>/Math Function1' incorporates:
           *  Sum: '<S223>/Sum of Elements'
           *
           * About '<S223>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_d = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S223>/Math Function1' */

          /* Switch: '<S223>/Switch' incorporates:
           *  Constant: '<S223>/Constant'
           *  Product: '<S223>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S223>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S204>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation1_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S223>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S222>/Divide' */
          rtb_P_cg[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S204>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Switch_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S223>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S222>/Divide' */
          rtb_P_cg[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S204>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Switch_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

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
          rtb_Switch_f_idx_0 = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
            rtb_Saturation_d * rtb_Saturation_d) / sqrtf(rtb_Switch_f_idx_0 *
            rtb_Switch_f_idx_0 + rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1);

          /* Saturate: '<S204>/Saturation' */
          if (rtb_Switch_f_idx_0 > 1.0F) {
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_0 < 0.0F) {
              rtb_Switch_f_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S204>/Saturation' */

          /* Sum: '<S221>/Subtract' incorporates:
           *  Product: '<S221>/Multiply'
           *  Product: '<S221>/Multiply1'
           */
          rtb_Saturation_d = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1] *
            rtb_P_cg[0];

          /* Signum: '<S217>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S217>/Sign1' */

          /* Switch: '<S217>/Switch2' incorporates:
           *  Constant: '<S217>/Constant4'
           */
          if (rtb_Saturation_d == 0.0F) {
            rtb_Saturation_d = 1.0F;
          }

          /* End of Switch: '<S217>/Switch2' */

          /* DotProduct: '<S217>/Dot Product' */
          rtb_Saturation1_d = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S217>/Acos' incorporates:
           *  DotProduct: '<S217>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S217>/Multiply' incorporates:
           *  Trigonometry: '<S217>/Acos'
           */
          rtb_Saturation_d *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S216>/Saturation' */
          if (rtb_Saturation_d > 1.57079637F) {
            rtb_Saturation_d = 1.57079637F;
          } else {
            if (rtb_Saturation_d < -1.57079637F) {
              rtb_Saturation_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S216>/Saturation' */

          /* Sqrt: '<S218>/Sqrt' */
          rtb_Saturation1_d = sqrtf(rtb_Saturation1_hc);

          /* BusAssignment: '<S160>/Bus Assignment' incorporates:
           *  Constant: '<S160>/Constant'
           *  Constant: '<S160>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S216>/Divide' incorporates:
           *  Constant: '<S207>/L1'
           *  Gain: '<S216>/Gain'
           *  Math: '<S216>/Square'
           *  Product: '<S216>/Multiply1'
           *  Trigonometry: '<S216>/Sin'
           */
          rtb_Switch_f_idx_1 = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F *
            arm_sin_f32(rtb_Saturation_d) / FMS_PARAM.FW_L1;

          /* Saturate: '<S207>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S160>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S160>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S160>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S207>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S202>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S204>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S202>/Sum2'
           *  Sum: '<S204>/Add'
           *  Sum: '<S204>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_f_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S202>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S160>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S160>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S160>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S202>/Saturation1' */
          /* End of Outputs for SubSystem: '<S41>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S41>/Land' incorporates:
           *  ActionPort: '<S158>/Action Port'
           */
          /* BusAssignment: '<S158>/Bus Assignment1' incorporates:
           *  Constant: '<S158>/Constant'
           *  Constant: '<S158>/Constant1'
           *  Constant: '<S158>/Constant4'
           *  Constant: '<S158>/Constant5'
           *  Constant: '<S158>/Constant7'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S41>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S41>/Return' incorporates:
           *  ActionPort: '<S159>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S197>/Math Function' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Divide_n4[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
          rtb_Divide_n4[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* Sum: '<S197>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S197>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S197>/Math Function1' incorporates:
           *  Sum: '<S197>/Sum of Elements'
           *
           * About '<S197>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S197>/Math Function1' */

          /* Switch: '<S197>/Switch' incorporates:
           *  Constant: '<S197>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S197>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Saturation_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S197>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S187>/NearbyRefWP' incorporates:
           *  Constant: '<S185>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S187>/SearchL1RefWP' incorporates:
           *  Constant: '<S185>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Saturation_d);

          /* MATLAB Function: '<S187>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S187>/Switch1' incorporates:
           *  Constant: '<S190>/Constant'
           *  RelationalOperator: '<S190>/Compare'
           */
          if (rtb_Saturation1_d > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S189>/Compare' incorporates:
             *  Constant: '<S189>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_d >= 0.0F);

            /* Switch: '<S187>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S187>/Switch' */
          }

          /* End of Switch: '<S187>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S188>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S198>/Sum of Elements' incorporates:
           *  Math: '<S198>/Math Function'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[0] * rtb_Divide_n4[0] +
            rtb_Divide_n4[1] * rtb_Divide_n4[1];

          /* Math: '<S198>/Math Function1' incorporates:
           *  Sum: '<S198>/Sum of Elements'
           *
           * About '<S198>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S198>/Math Function1' */

          /* Switch: '<S198>/Switch' incorporates:
           *  Constant: '<S198>/Constant'
           *  Product: '<S198>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Divide_n4[1];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S198>/Switch' */

          /* Product: '<S197>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S200>/Sum of Elements' incorporates:
           *  Math: '<S200>/Math Function'
           *  SignalConversion: '<S200>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
            rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Math: '<S200>/Math Function1' incorporates:
           *  Sum: '<S200>/Sum of Elements'
           *
           * About '<S200>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S200>/Math Function1' */

          /* Switch: '<S200>/Switch' incorporates:
           *  Constant: '<S200>/Constant'
           *  Product: '<S200>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_f_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S200>/Switch' */

          /* Product: '<S198>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S201>/Sum of Elements' incorporates:
           *  Math: '<S201>/Math Function'
           *  SignalConversion: '<S201>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
            rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Math: '<S201>/Math Function1' incorporates:
           *  Sum: '<S201>/Sum of Elements'
           *
           * About '<S201>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S201>/Math Function1' */

          /* Switch: '<S201>/Switch' incorporates:
           *  Constant: '<S201>/Constant'
           *  Product: '<S201>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S201>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S182>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S201>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S200>/Divide' */
          rtb_P_cg[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S182>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S201>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S200>/Divide' */
          rtb_P_cg[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S182>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S182>/Divide' incorporates:
           *  Math: '<S183>/Square'
           *  Math: '<S184>/Square'
           *  Sqrt: '<S183>/Sqrt'
           *  Sqrt: '<S184>/Sqrt'
           *  Sum: '<S182>/Sum'
           *  Sum: '<S182>/Sum1'
           *  Sum: '<S183>/Sum of Elements'
           *  Sum: '<S184>/Sum of Elements'
           */
          rtb_Saturation1_hc = sqrtf(rtb_a_bx * rtb_a_bx + rtb_Saturation1_hc *
            rtb_Saturation1_hc) / sqrtf(rtb_Saturation_d * rtb_Saturation_d +
            rtb_Saturation1_d * rtb_Saturation1_d);

          /* Saturate: '<S182>/Saturation' */
          if (rtb_Saturation1_hc > 1.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation1_hc = 0.0F;
            }
          }

          /* End of Saturate: '<S182>/Saturation' */

          /* Sum: '<S199>/Subtract' incorporates:
           *  Product: '<S199>/Multiply'
           *  Product: '<S199>/Multiply1'
           */
          rtb_Saturation_d = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1] *
            rtb_P_cg[0];

          /* Signum: '<S195>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S195>/Sign1' */

          /* Switch: '<S195>/Switch2' incorporates:
           *  Constant: '<S195>/Constant4'
           */
          if (rtb_Saturation_d == 0.0F) {
            rtb_Saturation_d = 1.0F;
          }

          /* End of Switch: '<S195>/Switch2' */

          /* DotProduct: '<S195>/Dot Product' */
          rtb_Saturation1_d = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S195>/Acos' incorporates:
           *  DotProduct: '<S195>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S195>/Multiply' incorporates:
           *  Trigonometry: '<S195>/Acos'
           */
          rtb_Saturation_d *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S194>/Saturation' */
          if (rtb_Saturation_d > 1.57079637F) {
            rtb_Saturation_d = 1.57079637F;
          } else {
            if (rtb_Saturation_d < -1.57079637F) {
              rtb_Saturation_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S194>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S196>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S196>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S196>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S159>/Bus Assignment1' incorporates:
           *  Constant: '<S159>/Constant2'
           *  Constant: '<S159>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S194>/Divide' incorporates:
           *  Constant: '<S185>/L1'
           *  Gain: '<S194>/Gain'
           *  Math: '<S194>/Square'
           *  Product: '<S194>/Multiply1'
           *  Trigonometry: '<S194>/Sin'
           */
          rtb_Switch_f_idx_1 = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F *
            arm_sin_f32(rtb_Saturation_d) / FMS_PARAM.FW_L1;

          /* Saturate: '<S185>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S159>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S185>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S180>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S182>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S180>/Sum2'
           *  Sum: '<S182>/Add'
           *  Sum: '<S182>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_hc +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S180>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S159>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S180>/Saturation1' */
          /* End of Outputs for SubSystem: '<S41>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S41>/Hold' incorporates:
             *  ActionPort: '<S157>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S41>/Switch Case' incorporates:
             *  Delay: '<S162>/Delay'
             *  Delay: '<S167>/start_vel'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S41>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S41>/Hold' incorporates:
           *  ActionPort: '<S157>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S174>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S174>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S174>/Math Function1' incorporates:
           *  Sum: '<S174>/Sum of Elements'
           *
           * About '<S174>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S174>/Math Function1' */

          /* Switch: '<S174>/Switch' incorporates:
           *  Constant: '<S174>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S174>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Saturation_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_d0[0] = FMS_U.INS_Out.vn;
            rtb_Switch_d0[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S174>/Switch' */

          /* Delay: '<S167>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Sum: '<S179>/Sum of Elements' incorporates:
           *  Delay: '<S167>/start_vel'
           *  Math: '<S179>/Math Function'
           */
          rtb_Saturation1_hc = FMS_DW.start_vel_DSTATE_l[0] *
            FMS_DW.start_vel_DSTATE_l[0] + FMS_DW.start_vel_DSTATE_l[1] *
            FMS_DW.start_vel_DSTATE_l[1];

          /* Math: '<S179>/Math Function1' incorporates:
           *  Sum: '<S179>/Sum of Elements'
           *
           * About '<S179>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S179>/Math Function1' */

          /* Switch: '<S179>/Switch' incorporates:
           *  Constant: '<S179>/Constant'
           *  Delay: '<S167>/start_vel'
           *  Product: '<S179>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_ov[0] = FMS_DW.start_vel_DSTATE_l[0];
            rtb_Switch_ov[1] = FMS_DW.start_vel_DSTATE_l[1];
            rtb_Switch_ov[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S179>/Switch' */

          /* Product: '<S174>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S177>/Sum of Elements' incorporates:
           *  Math: '<S177>/Math Function'
           *  SignalConversion: '<S177>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
            rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Math: '<S177>/Math Function1' incorporates:
           *  Sum: '<S177>/Sum of Elements'
           *
           * About '<S177>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S177>/Math Function1' */

          /* Switch: '<S177>/Switch' incorporates:
           *  Constant: '<S177>/Constant'
           *  Product: '<S177>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S177>/Switch' */

          /* MinMax: '<S165>/Max' incorporates:
           *  Constant: '<S163>/L1'
           *  Constant: '<S163>/R'
           *  Gain: '<S165>/Gain'
           */
          rtb_Saturation1_d = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S165>/SearchL1RefWP' incorporates:
           *  Constant: '<S163>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_cg[0] = 0.0F;
          rtb_P_cg[1] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.cur_waypoint[0]) &&
              (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.cur_waypoint[1]) &&
              (rtb_Saturation1_d == FMS_PARAM.FW_L1)) {
            rtb_n = 0;
          } else {
            rtb_Saturation_d = FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R;
            rtb_P_dg[0] = rtb_Saturation_d * rtb_Saturation_d;
            rtb_Square_h[0] = rtb_Saturation_d;
            rtb_Saturation_d = FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R;
            rtb_Saturation1_hc = sqrtf(rtb_Saturation_d * rtb_Saturation_d +
              rtb_P_dg[0]);
            rtb_Switch_f_idx_1 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Switch_f_idx_0 = ((rtb_Saturation1_hc * rtb_Saturation1_hc +
              rtb_Switch_f_idx_1) - rtb_Saturation1_d * rtb_Saturation1_d) /
              (2.0F * rtb_Saturation1_hc);
            rtb_Square_h[0] /= rtb_Saturation1_hc;
            rtb_Saturation_d /= rtb_Saturation1_hc;
            rtb_Saturation1_hc = rtb_Switch_f_idx_0 * rtb_Switch_f_idx_0;
            if (rtb_Saturation1_hc > rtb_Switch_f_idx_1) {
              rtb_n = 0;
            } else if (rtb_Saturation1_hc == rtb_Switch_f_idx_1) {
              rtb_n = 1;
              rtb_P_cg[0] = rtb_Switch_f_idx_0 * rtb_Square_h[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_cg[1] = rtb_Switch_f_idx_0 * rtb_Saturation_d +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation1_hc = sqrtf(rtb_Switch_f_idx_1 - rtb_Saturation1_hc);
              rtb_P_cg[0] = (rtb_Switch_f_idx_0 * rtb_Square_h[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation1_hc *
                -rtb_Saturation_d;
              rtb_P_cg[1] = (rtb_Switch_f_idx_0 * rtb_Saturation_d +
                             FMS_U.INS_Out.y_R) + rtb_Saturation1_hc *
                rtb_Square_h[0];
            }
          }

          /* End of MATLAB Function: '<S165>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* RelationalOperator: '<S168>/Compare' incorporates:
           *  Constant: '<S168>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S165>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_P_dg[0] = rtb_Saturation_d * rtb_Saturation_d;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Saturation_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_P_dg[1] = rtb_Saturation_d * rtb_Saturation_d;

          /* Switch: '<S165>/Switch' incorporates:
           *  Constant: '<S163>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S165>/OutRegionRegWP'
           *  Product: '<S179>/Divide'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_d = rtb_P_cg[0];
          } else if (rtb_P_dg[0] + rtb_P_dg[1] > rtb_Saturation1_d *
                     rtb_Saturation1_d) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S165>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_d = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation_d = rtb_Switch_ov[0] / rtb_Switch_ov[2] *
              FMS_PARAM.FW_L1 + FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S166>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Square_h[0] = rtb_Saturation_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S165>/Switch' incorporates:
           *  Constant: '<S163>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S165>/OutRegionRegWP'
           *  Product: '<S179>/Divide'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_d = rtb_P_cg[1];
          } else if (rtb_P_dg[0] + rtb_P_dg[1] > rtb_Saturation1_d *
                     rtb_Saturation1_d) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S165>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_d = FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation_d = rtb_Switch_ov[1] / rtb_Switch_ov[2] *
              FMS_PARAM.FW_L1 + FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S166>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Square_h[1] = rtb_Saturation_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S175>/Sum of Elements' incorporates:
           *  Math: '<S175>/Math Function'
           */
          rtb_Saturation1_hc = rtb_Square_h[0] * rtb_Square_h[0] + rtb_Square_h
            [1] * rtb_Square_h[1];

          /* Math: '<S175>/Math Function1' incorporates:
           *  Sum: '<S175>/Sum of Elements'
           *
           * About '<S175>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S175>/Math Function1' */

          /* Switch: '<S175>/Switch' incorporates:
           *  Constant: '<S175>/Constant'
           *  Product: '<S175>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_ov[0] = rtb_Square_h[0];
            rtb_Switch_ov[1] = rtb_Square_h[1];
            rtb_Switch_ov[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S175>/Switch' */

          /* Product: '<S175>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S178>/Sum of Elements' incorporates:
           *  Math: '<S178>/Math Function'
           *  SignalConversion: '<S178>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
            rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Math: '<S178>/Math Function1' incorporates:
           *  Sum: '<S178>/Sum of Elements'
           *
           * About '<S178>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S178>/Math Function1' */

          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S178>/Constant'
           *  Product: '<S178>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_ov[0] = rtb_Divide_n4[1];
            rtb_Switch_ov[1] = rtb_Divide_n4[0];
            rtb_Switch_ov[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S178>/Switch' */

          /* Product: '<S178>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S177>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S178>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S177>/Divide' */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S173>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S173>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S173>/Sum of Elements'
           */
          rtb_Saturation_d = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S171>/Square' */
          rtb_Saturation1_hc = rtb_Saturation_d * rtb_Saturation_d;

          /* Sum: '<S176>/Subtract' incorporates:
           *  Product: '<S176>/Multiply'
           *  Product: '<S176>/Multiply1'
           */
          rtb_Saturation_d = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1] *
            rtb_P_cg[0];

          /* Signum: '<S172>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S172>/Sign1' */

          /* Switch: '<S172>/Switch2' incorporates:
           *  Constant: '<S172>/Constant4'
           */
          if (rtb_Saturation_d == 0.0F) {
            rtb_Saturation_d = 1.0F;
          }

          /* End of Switch: '<S172>/Switch2' */

          /* DotProduct: '<S172>/Dot Product' */
          rtb_Saturation1_d = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S172>/Acos' incorporates:
           *  DotProduct: '<S172>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S172>/Multiply' incorporates:
           *  Trigonometry: '<S172>/Acos'
           */
          rtb_Saturation_d *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S171>/Saturation' */
          if (rtb_Saturation_d > 1.57079637F) {
            rtb_Saturation_d = 1.57079637F;
          } else {
            if (rtb_Saturation_d < -1.57079637F) {
              rtb_Saturation_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S171>/Saturation' */

          /* Delay: '<S162>/Delay' incorporates:
           *  Gain: '<S164>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_ncp = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Constant: '<S157>/Constant'
           *  Constant: '<S157>/Constant3'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S171>/Divide' incorporates:
           *  Constant: '<S163>/L1'
           *  Gain: '<S171>/Gain'
           *  Product: '<S171>/Multiply1'
           *  Trigonometry: '<S171>/Sin'
           */
          rtb_Switch_f_idx_1 = 2.0F * rtb_Saturation1_hc * arm_sin_f32
            (rtb_Saturation_d) / FMS_PARAM.FW_L1;

          /* Saturate: '<S163>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S157>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S157>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S157>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S163>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S162>/Gain2' incorporates:
           *  Delay: '<S162>/Delay'
           *  Gain: '<S164>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S162>/Sum'
           */
          rtb_Switch_f_idx_1 = (FMS_DW.Delay_DSTATE_ncp - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S162>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S157>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S157>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S157>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S162>/Saturation1' */

          /* Update for Delay: '<S167>/start_vel' */
          FMS_DW.icLoad_l = 0U;

          /* Update for Delay: '<S162>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S41>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S41>/Unknown' incorporates:
           *  ActionPort: '<S161>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S41>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S41>/Switch Case' */
        /* End of Outputs for SubSystem: '<S36>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S36>/Auto' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */
        /* SwitchCase: '<S39>/Switch Case' incorporates:
         *  RelationalOperator: '<S131>/FixPt Relational Operator'
         *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S131>/Delay Input1'
         *
         * Block description for '<S131>/Delay Input1':
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
          /* Outputs for IfAction SubSystem: '<S39>/Offboard' incorporates:
           *  ActionPort: '<S129>/Action Port'
           */
          /* BusAssignment: '<S129>/Bus Assignment' incorporates:
           *  Constant: '<S129>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S39>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S39>/Mission' incorporates:
             *  ActionPort: '<S128>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
             *  UnitDelay: '<S131>/Delay Input1'
             *
             * Block description for '<S131>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S39>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S39>/Mission' incorporates:
           *  ActionPort: '<S128>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S128>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S132>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* Math: '<S150>/Math Function' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S131>/FixPt Relational Operator'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S131>/Delay Input1'
           *
           * Block description for '<S131>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Divide_n4[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
          rtb_Divide_n4[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* Sum: '<S150>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S150>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S150>/Math Function1' incorporates:
           *  Sum: '<S150>/Sum of Elements'
           *
           * About '<S150>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S150>/Math Function1' */

          /* Switch: '<S150>/Switch' incorporates:
           *  Constant: '<S150>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S150>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Saturation_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S150>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S140>/NearbyRefWP' incorporates:
           *  Constant: '<S138>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S140>/SearchL1RefWP' incorporates:
           *  Constant: '<S138>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Saturation_d);

          /* MATLAB Function: '<S140>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S140>/Switch1' incorporates:
           *  Constant: '<S143>/Constant'
           *  RelationalOperator: '<S143>/Compare'
           */
          if (rtb_Saturation1_d > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S142>/Compare' incorporates:
             *  Constant: '<S142>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_d >= 0.0F);

            /* Switch: '<S140>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S140>/Switch' */
          }

          /* End of Switch: '<S140>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S141>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S151>/Sum of Elements' incorporates:
           *  Math: '<S151>/Math Function'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[0] * rtb_Divide_n4[0] +
            rtb_Divide_n4[1] * rtb_Divide_n4[1];

          /* Math: '<S151>/Math Function1' incorporates:
           *  Sum: '<S151>/Sum of Elements'
           *
           * About '<S151>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S151>/Math Function1' */

          /* Switch: '<S151>/Switch' incorporates:
           *  Constant: '<S151>/Constant'
           *  Product: '<S151>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Divide_n4[1];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S151>/Switch' */

          /* Product: '<S150>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S153>/Sum of Elements' incorporates:
           *  Math: '<S153>/Math Function'
           *  SignalConversion: '<S153>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
            rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Math: '<S153>/Math Function1' incorporates:
           *  Sum: '<S153>/Sum of Elements'
           *
           * About '<S153>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S153>/Math Function1' */

          /* Switch: '<S153>/Switch' incorporates:
           *  Constant: '<S153>/Constant'
           *  Product: '<S153>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_f_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S153>/Switch' */

          /* Product: '<S151>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S154>/Sum of Elements' incorporates:
           *  Math: '<S154>/Math Function'
           *  SignalConversion: '<S154>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
            rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Math: '<S154>/Math Function1' incorporates:
           *  Sum: '<S154>/Sum of Elements'
           *
           * About '<S154>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S154>/Math Function1' */

          /* Switch: '<S154>/Switch' incorporates:
           *  Constant: '<S154>/Constant'
           *  Product: '<S154>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S154>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S135>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S154>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S153>/Divide' */
          rtb_P_cg[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S135>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S154>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S153>/Divide' */
          rtb_P_cg[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S135>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S135>/Divide' incorporates:
           *  Math: '<S136>/Square'
           *  Math: '<S137>/Square'
           *  Sqrt: '<S136>/Sqrt'
           *  Sqrt: '<S137>/Sqrt'
           *  Sum: '<S135>/Sum'
           *  Sum: '<S135>/Sum1'
           *  Sum: '<S136>/Sum of Elements'
           *  Sum: '<S137>/Sum of Elements'
           */
          rtb_Saturation1_hc = sqrtf(rtb_a_bx * rtb_a_bx + rtb_Saturation1_hc *
            rtb_Saturation1_hc) / sqrtf(rtb_Saturation_d * rtb_Saturation_d +
            rtb_Saturation1_d * rtb_Saturation1_d);

          /* Saturate: '<S135>/Saturation' */
          if (rtb_Saturation1_hc > 1.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation1_hc = 0.0F;
            }
          }

          /* End of Saturate: '<S135>/Saturation' */

          /* Sum: '<S152>/Subtract' incorporates:
           *  Product: '<S152>/Multiply'
           *  Product: '<S152>/Multiply1'
           */
          rtb_Saturation_d = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1] *
            rtb_P_cg[0];

          /* Signum: '<S148>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S148>/Sign1' */

          /* Switch: '<S148>/Switch2' incorporates:
           *  Constant: '<S148>/Constant4'
           */
          if (rtb_Saturation_d == 0.0F) {
            rtb_Saturation_d = 1.0F;
          }

          /* End of Switch: '<S148>/Switch2' */

          /* DotProduct: '<S148>/Dot Product' */
          rtb_Saturation1_d = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S148>/Acos' incorporates:
           *  DotProduct: '<S148>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S148>/Multiply' incorporates:
           *  Trigonometry: '<S148>/Acos'
           */
          rtb_Saturation_d *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S147>/Saturation' */
          if (rtb_Saturation_d > 1.57079637F) {
            rtb_Saturation_d = 1.57079637F;
          } else {
            if (rtb_Saturation_d < -1.57079637F) {
              rtb_Saturation_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S147>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S149>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S149>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S149>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S132>/Bus Assignment' incorporates:
           *  Constant: '<S132>/Constant'
           *  Constant: '<S132>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S147>/Divide' incorporates:
           *  Constant: '<S138>/L1'
           *  Gain: '<S147>/Gain'
           *  Math: '<S147>/Square'
           *  Product: '<S147>/Multiply1'
           *  Trigonometry: '<S147>/Sin'
           */
          rtb_Switch_f_idx_1 = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F *
            arm_sin_f32(rtb_Saturation_d) / FMS_PARAM.FW_L1;

          /* Saturate: '<S138>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S132>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S132>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S132>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S138>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S133>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S135>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S133>/Sum2'
           *  Sum: '<S135>/Add'
           *  Sum: '<S135>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_hc +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S133>/Saturation1' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S132>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S132>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S132>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S133>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Update for UnitDelay: '<S131>/Delay Input1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S131>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S39>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
           *  ActionPort: '<S130>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S39>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S39>/Switch Case' */
        /* End of Outputs for SubSystem: '<S36>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S36>/Assist' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */
        /* SwitchCase: '<S38>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_as;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Stabilize:
          FMS_DW.SwitchCase_ActiveSubsystem_as = 0;
          break;

         case VehicleState_Altitude:
          FMS_DW.SwitchCase_ActiveSubsystem_as = 1;
          break;

         case VehicleState_Position:
          FMS_DW.SwitchCase_ActiveSubsystem_as = 2;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_as = 3;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_as) {
          switch (rtPrevAction) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S51>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S86>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S72>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S38>/Stabilize' incorporates:
             *  ActionPort: '<S45>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S38>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S121>/Integrator'
             *  DiscreteIntegrator: '<S121>/Integrator1'
             *  DiscreteIntegrator: '<S122>/Integrator'
             *  DiscreteIntegrator: '<S122>/Integrator1'
             *  DiscreteIntegrator: '<S126>/Integrator'
             *  DiscreteIntegrator: '<S126>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S38>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S38>/Stabilize' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* Product: '<S123>/Multiply1' incorporates:
           *  Constant: '<S123>/const1'
           *  DiscreteIntegrator: '<S121>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_a * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S119>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S119>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S123>/Add' incorporates:
           *  DiscreteIntegrator: '<S121>/Integrator1'
           *  Gain: '<S116>/Gain'
           *  Gain: '<S119>/Gain'
           *  Sum: '<S121>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_hc * FMS_PARAM.FW_ROLL_LIM) +
            rtb_a_bx;

          /* Signum: '<S123>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_d = 1.0F;
          } else {
            rtb_Saturation_d = rtb_Saturation1_d;
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
          rtb_Switch_f_idx_1 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_d + rtb_a_bx;

          /* Sum: '<S123>/Add4' */
          rtb_Saturation1_hc = (rtb_Saturation1_d - rtb_Switch_f_idx_1) +
            rtb_a_bx;

          /* Sum: '<S123>/Add3' */
          rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S123>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

          /* Signum: '<S123>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign1' */

          /* Signum: '<S123>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign2' */

          /* Sum: '<S123>/Add5' incorporates:
           *  Gain: '<S123>/Gain2'
           *  Product: '<S123>/Multiply4'
           *  Sum: '<S123>/Subtract2'
           */
          rtb_Switch_f_idx_1 += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation1_hc;

          /* BusAssignment: '<S45>/Bus Assignment' incorporates:
           *  Constant: '<S45>/Constant'
           *  DiscreteIntegrator: '<S121>/Integrator1'
           *  DiscreteIntegrator: '<S122>/Integrator1'
           *  DiscreteIntegrator: '<S126>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Saturate: '<S118>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S118>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S45>/Bus Assignment' incorporates:
           *  Constant: '<S118>/Constant5'
           *  Gain: '<S118>/Gain2'
           *  Sum: '<S118>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_Saturation1_hc), 65536.0F) + 1000U);

          /* Product: '<S127>/Multiply1' incorporates:
           *  Constant: '<S127>/const1'
           *  DiscreteIntegrator: '<S126>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S125>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S125>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S127>/Add' incorporates:
           *  DiscreteIntegrator: '<S126>/Integrator1'
           *  Gain: '<S117>/Gain1'
           *  Gain: '<S125>/Gain'
           *  Sum: '<S126>/Subtract'
           */
          rtb_Switch_f_idx_2 = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation1_hc * FMS_PARAM.FW_YAW_RATE_LIM)
            + rtb_a_bx;

          /* Signum: '<S127>/Sign' */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_2 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_2;
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
          rtb_Subtract3_d = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_2) +
            FMS_ConstB.d_hr) * FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F *
            rtb_Saturation1_hc + rtb_a_bx;

          /* Sum: '<S127>/Add4' */
          rtb_Saturation1_d = (rtb_Switch_f_idx_2 - rtb_Subtract3_d) + rtb_a_bx;

          /* Sum: '<S127>/Add3' */
          rtb_Saturation_d = rtb_Switch_f_idx_2 + FMS_ConstB.d_hr;

          /* Sum: '<S127>/Subtract1' */
          rtb_Switch_f_idx_2 -= FMS_ConstB.d_hr;

          /* Signum: '<S127>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S127>/Sign1' */

          /* Signum: '<S127>/Sign2' */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_2 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S127>/Sign2' */

          /* Sum: '<S127>/Add5' incorporates:
           *  Gain: '<S127>/Gain2'
           *  Product: '<S127>/Multiply4'
           *  Sum: '<S127>/Subtract2'
           */
          rtb_Subtract3_d += (rtb_Saturation_d - rtb_Switch_f_idx_2) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S127>/Add6' */
          rtb_Saturation_d = rtb_Subtract3_d + FMS_ConstB.d_hr;

          /* Sum: '<S127>/Subtract3' */
          rtb_Saturation1_d = rtb_Subtract3_d - FMS_ConstB.d_hr;

          /* Product: '<S127>/Divide' */
          rtb_Divide_or = rtb_Subtract3_d / FMS_ConstB.d_hr;

          /* Signum: '<S127>/Sign5' incorporates:
           *  Signum: '<S127>/Sign6'
           */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S127>/Sign6' */
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_Subtract3_d > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S127>/Sign6' */
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Subtract3_d;

            /* Signum: '<S127>/Sign6' */
            rtb_Switch_f_idx_0 = rtb_Subtract3_d;
          }

          /* End of Signum: '<S127>/Sign5' */

          /* Product: '<S124>/Multiply1' incorporates:
           *  Constant: '<S124>/const1'
           *  DiscreteIntegrator: '<S122>/Integrator'
           */
          rtb_Subtract3_d = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S120>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S120>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S124>/Add' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator1'
           *  Gain: '<S116>/Gain1'
           *  Gain: '<S120>/Gain'
           *  Sum: '<S122>/Subtract'
           */
          rtb_Switch_f_idx_2 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation1_hc * -FMS_PARAM.FW_PITCH_LIM)
            + rtb_Subtract3_d;

          /* Signum: '<S124>/Sign' */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_2 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_2;
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
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_2) + FMS_ConstB.d_my)
                            * FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Saturation1_hc + rtb_Subtract3_d;

          /* Sum: '<S124>/Add4' */
          rtb_Subtract3_d += rtb_Switch_f_idx_2 - rtb_a_bx;

          /* Sum: '<S124>/Add3' */
          rtb_Saturation1_hc = rtb_Switch_f_idx_2 + FMS_ConstB.d_my;

          /* Sum: '<S124>/Subtract1' */
          rtb_Switch_f_idx_2 -= FMS_ConstB.d_my;

          /* Signum: '<S124>/Sign1' */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else {
            if (rtb_Saturation1_hc > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            }
          }

          /* End of Signum: '<S124>/Sign1' */

          /* Signum: '<S124>/Sign2' */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_2 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S124>/Sign2' */

          /* Sum: '<S124>/Add5' incorporates:
           *  Gain: '<S124>/Gain2'
           *  Product: '<S124>/Multiply4'
           *  Sum: '<S124>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation1_hc - rtb_Switch_f_idx_2) * 0.5F *
            rtb_Subtract3_d;

          /* Update for DiscreteIntegrator: '<S121>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S121>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Sum: '<S123>/Subtract3' */
          rtb_Saturation1_hc = rtb_Switch_f_idx_1 - FMS_ConstB.d_ny;

          /* Sum: '<S123>/Add6' */
          rtb_Subtract3_d = rtb_Switch_f_idx_1 + FMS_ConstB.d_ny;

          /* Signum: '<S123>/Sign5' incorporates:
           *  Signum: '<S123>/Sign6'
           */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Switch_f_idx_2 = -1.0F;

            /* Signum: '<S123>/Sign6' */
            rtb_u = -1.0F;
          } else if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Switch_f_idx_2 = 1.0F;

            /* Signum: '<S123>/Sign6' */
            rtb_u = 1.0F;
          } else {
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_1;

            /* Signum: '<S123>/Sign6' */
            rtb_u = rtb_Switch_f_idx_1;
          }

          /* End of Signum: '<S123>/Sign5' */

          /* Signum: '<S123>/Sign3' */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Subtract3_d = -1.0F;
          } else {
            if (rtb_Subtract3_d > 0.0F) {
              rtb_Subtract3_d = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign3' */

          /* Signum: '<S123>/Sign4' */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else {
            if (rtb_Saturation1_hc > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
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
          FMS_DW.Integrator_DSTATE_a += ((rtb_Switch_f_idx_1 / FMS_ConstB.d_ny -
            rtb_Switch_f_idx_2) * FMS_ConstB.Gain4_ko * ((rtb_Subtract3_d -
            rtb_Saturation1_hc) * 0.5F) - rtb_u * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S122>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S126>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S126>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S127>/Sign3' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S127>/Sign3' */

          /* Signum: '<S127>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S127>/Sign4' */

          /* Update for DiscreteIntegrator: '<S126>/Integrator' incorporates:
           *  Constant: '<S127>/const'
           *  Gain: '<S127>/Gain3'
           *  Product: '<S127>/Multiply5'
           *  Product: '<S127>/Multiply6'
           *  Sum: '<S127>/Subtract4'
           *  Sum: '<S127>/Subtract5'
           *  Sum: '<S127>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Saturation_d - rtb_Saturation1_d) * 0.5F)
            - rtb_Switch_f_idx_0 * 15.707963F) * 0.004F;

          /* Sum: '<S124>/Subtract3' */
          rtb_Saturation_d = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S124>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S124>/Sign5' incorporates:
           *  Signum: '<S124>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S124>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S124>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_a_bx;

            /* Signum: '<S124>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_a_bx;
          }

          /* End of Signum: '<S124>/Sign5' */

          /* Signum: '<S124>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S124>/Sign3' */

          /* Signum: '<S124>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S124>/Sign4' */

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
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_bx / FMS_ConstB.d_my -
            rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_k2 * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S38>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S38>/Altitude' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S38>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S63>/Integrator'
             *  DiscreteIntegrator: '<S63>/Integrator1'
             *  DiscreteIntegrator: '<S66>/Integrator'
             *  DiscreteIntegrator: '<S66>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S38>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S38>/Altitude' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S38>/Switch Case' incorporates:
             *  Chart: '<S52>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S38>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S38>/Altitude' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S52>/Motion Status' incorporates:
           *  Abs: '<S52>/Abs'
           *  Abs: '<S52>/Abs1'
           *  Constant: '<S60>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S60>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S51>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S51>/Hold Control' incorporates:
               *  ActionPort: '<S54>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S51>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S51>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S51>/Hold Control' incorporates:
             *  ActionPort: '<S54>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S51>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S51>/Brake Control' incorporates:
             *  ActionPort: '<S53>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S51>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S51>/Move Control' incorporates:
               *  ActionPort: '<S55>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S51>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S51>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S51>/Move Control' incorporates:
             *  ActionPort: '<S55>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S51>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S51>/Switch Case' */

          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Constant: '<S43>/Constant'
           *  DiscreteIntegrator: '<S63>/Integrator1'
           *  DiscreteIntegrator: '<S66>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Saturate: '<S47>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S47>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Gain: '<S47>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation1_hc;

          /* Saturate: '<S51>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S51>/Saturation1' */

          /* Product: '<S67>/Multiply1' incorporates:
           *  Constant: '<S67>/const1'
           *  DiscreteIntegrator: '<S66>/Integrator'
           */
          rtb_Switch_f_idx_1 = FMS_DW.Integrator_DSTATE_e * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S65>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S65>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S67>/Add' incorporates:
           *  DiscreteIntegrator: '<S66>/Integrator1'
           *  Gain: '<S50>/Gain1'
           *  Gain: '<S65>/Gain'
           *  Sum: '<S66>/Subtract'
           */
          rtb_a_bx = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation1_hc * FMS_PARAM.FW_YAW_RATE_LIM)
            + rtb_Switch_f_idx_1;

          /* Signum: '<S67>/Sign' */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Saturation_d = 1.0F;
          } else {
            rtb_Saturation_d = rtb_a_bx;
          }

          /* End of Signum: '<S67>/Sign' */

          /* Sum: '<S67>/Add2' incorporates:
           *  Abs: '<S67>/Abs'
           *  Gain: '<S67>/Gain'
           *  Gain: '<S67>/Gain1'
           *  Product: '<S67>/Multiply2'
           *  Product: '<S67>/Multiply3'
           *  Sqrt: '<S67>/Sqrt'
           *  Sum: '<S67>/Add1'
           *  Sum: '<S67>/Subtract'
           */
          rtb_Sign5_mn = (sqrtf((8.0F * fabsf(rtb_a_bx) + FMS_ConstB.d_nt) *
                                FMS_ConstB.d_nt) - FMS_ConstB.d_nt) * 0.5F *
            rtb_Saturation_d + rtb_Switch_f_idx_1;

          /* Sum: '<S67>/Add4' */
          rtb_Saturation1_d = (rtb_a_bx - rtb_Sign5_mn) + rtb_Switch_f_idx_1;

          /* Sum: '<S67>/Add3' */
          rtb_Saturation_d = rtb_a_bx + FMS_ConstB.d_nt;

          /* Sum: '<S67>/Subtract1' */
          rtb_a_bx -= FMS_ConstB.d_nt;

          /* Signum: '<S67>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S67>/Sign1' */

          /* Signum: '<S67>/Sign2' */
          if (rtb_a_bx < 0.0F) {
            rtb_a_bx = -1.0F;
          } else {
            if (rtb_a_bx > 0.0F) {
              rtb_a_bx = 1.0F;
            }
          }

          /* End of Signum: '<S67>/Sign2' */

          /* Sum: '<S67>/Add5' incorporates:
           *  Gain: '<S67>/Gain2'
           *  Product: '<S67>/Multiply4'
           *  Sum: '<S67>/Subtract2'
           */
          rtb_Sign5_mn += (rtb_Saturation_d - rtb_a_bx) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S67>/Add6' */
          rtb_Saturation_d = rtb_Sign5_mn + FMS_ConstB.d_nt;

          /* Sum: '<S67>/Subtract3' */
          rtb_Saturation1_d = rtb_Sign5_mn - FMS_ConstB.d_nt;

          /* Product: '<S67>/Divide' */
          rtb_Switch_f_idx_2 = rtb_Sign5_mn / FMS_ConstB.d_nt;

          /* Signum: '<S67>/Sign5' incorporates:
           *  Signum: '<S67>/Sign6'
           */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S67>/Sign6' */
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_Sign5_mn > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S67>/Sign6' */
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Sign5_mn;

            /* Signum: '<S67>/Sign6' */
            rtb_Switch_f_idx_0 = rtb_Sign5_mn;
          }

          /* End of Signum: '<S67>/Sign5' */

          /* Product: '<S64>/Multiply1' incorporates:
           *  Constant: '<S64>/const1'
           *  DiscreteIntegrator: '<S63>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S62>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S62>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S64>/Add' incorporates:
           *  DiscreteIntegrator: '<S63>/Integrator1'
           *  Gain: '<S49>/Gain'
           *  Gain: '<S62>/Gain'
           *  Sum: '<S63>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_hc * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Sign5_mn;

          /* Signum: '<S64>/Sign' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_1;
          }

          /* End of Signum: '<S64>/Sign' */

          /* Sum: '<S64>/Add2' incorporates:
           *  Abs: '<S64>/Abs'
           *  Gain: '<S64>/Gain'
           *  Gain: '<S64>/Gain1'
           *  Product: '<S64>/Multiply2'
           *  Product: '<S64>/Multiply3'
           *  Sqrt: '<S64>/Sqrt'
           *  Sum: '<S64>/Add1'
           *  Sum: '<S64>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d_bi)
                            * FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Saturation1_hc + rtb_Sign5_mn;

          /* Sum: '<S64>/Add4' */
          rtb_Sign5_mn += rtb_Switch_f_idx_1 - rtb_a_bx;

          /* Sum: '<S64>/Add3' */
          rtb_Saturation1_hc = rtb_Switch_f_idx_1 + FMS_ConstB.d_bi;

          /* Sum: '<S64>/Subtract1' */
          rtb_Switch_f_idx_1 -= FMS_ConstB.d_bi;

          /* Signum: '<S64>/Sign1' */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else {
            if (rtb_Saturation1_hc > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            }
          }

          /* End of Signum: '<S64>/Sign1' */

          /* Signum: '<S64>/Sign2' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Switch_f_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S64>/Sign2' */

          /* Sum: '<S64>/Add5' incorporates:
           *  Gain: '<S64>/Gain2'
           *  Product: '<S64>/Multiply4'
           *  Sum: '<S64>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation1_hc - rtb_Switch_f_idx_1) * 0.5F *
            rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S63>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S66>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Signum: '<S67>/Sign3' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S67>/Sign3' */

          /* Signum: '<S67>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S67>/Sign4' */

          /* Update for DiscreteIntegrator: '<S66>/Integrator' incorporates:
           *  Constant: '<S67>/const'
           *  Gain: '<S67>/Gain3'
           *  Product: '<S67>/Multiply5'
           *  Product: '<S67>/Multiply6'
           *  Sum: '<S67>/Subtract4'
           *  Sum: '<S67>/Subtract5'
           *  Sum: '<S67>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((rtb_Switch_f_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_kf * ((rtb_Saturation_d - rtb_Saturation1_d) * 0.5F)
            - rtb_Switch_f_idx_0 * 15.707963F) * 0.004F;

          /* Sum: '<S64>/Subtract3' */
          rtb_Saturation_d = rtb_a_bx - FMS_ConstB.d_bi;

          /* Sum: '<S64>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_bi;

          /* Signum: '<S64>/Sign5' incorporates:
           *  Signum: '<S64>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S64>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S64>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_a_bx;

            /* Signum: '<S64>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_a_bx;
          }

          /* End of Signum: '<S64>/Sign5' */

          /* Signum: '<S64>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S64>/Sign3' */

          /* Signum: '<S64>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S64>/Sign4' */

          /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
           *  Constant: '<S64>/const'
           *  Gain: '<S64>/Gain3'
           *  Product: '<S64>/Divide'
           *  Product: '<S64>/Multiply5'
           *  Product: '<S64>/Multiply6'
           *  Sum: '<S64>/Subtract4'
           *  Sum: '<S64>/Subtract5'
           *  Sum: '<S64>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_a_bx / FMS_ConstB.d_bi -
            rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_d1 * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S38>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S38>/Position' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S38>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S84>/Integrator'
             *  DiscreteIntegrator: '<S84>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S38>/Position' */

            /* SystemReset for IfAction SubSystem: '<S38>/Position' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S38>/Switch Case' incorporates:
             *  Chart: '<S73>/Motion Status'
             *  Chart: '<S87>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_DW.temporalCounter_i1_ie = 0U;
            FMS_DW.is_active_c26_FMS = 0U;
            FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S38>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S38>/Position' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* Outputs for IfAction SubSystem: '<S86>/Hold Control' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SwitchCase: '<S86>/Switch Case' incorporates:
           *  Gain: '<S114>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S108>/Trigonometric Function1'
           *  Trigonometry: '<S108>/Trigonometric Function3'
           *  Trigonometry: '<S115>/Trigonometric Function1'
           *  Trigonometry: '<S115>/Trigonometric Function3'
           */
          rtb_Saturation1_hc = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Hold Control' */

          /* Trigonometry: '<S115>/Trigonometric Function1' */
          rtb_VectorConcatenate_pc[0] = rtb_Saturation1_hc;

          /* Outputs for IfAction SubSystem: '<S86>/Hold Control' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SwitchCase: '<S86>/Switch Case' incorporates:
           *  Gain: '<S114>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S108>/Trigonometric Function'
           *  Trigonometry: '<S115>/Trigonometric Function'
           *  Trigonometry: '<S115>/Trigonometric Function2'
           */
          rtb_Saturation1_d = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Hold Control' */

          /* Trigonometry: '<S115>/Trigonometric Function' */
          rtb_VectorConcatenate_pc[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S115>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S115>/Constant3'
           */
          rtb_VectorConcatenate_pc[2] = 0.0F;

          /* Gain: '<S115>/Gain' */
          rtb_VectorConcatenate_pc[3] = -rtb_Saturation1_d;

          /* Trigonometry: '<S115>/Trigonometric Function3' */
          rtb_VectorConcatenate_pc[4] = rtb_Saturation1_hc;

          /* SignalConversion: '<S115>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S115>/Constant4'
           */
          rtb_VectorConcatenate_pc[5] = 0.0F;

          /* SignalConversion: '<S115>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S73>/Motion Status' incorporates:
           *  Abs: '<S73>/Abs'
           *  Abs: '<S73>/Abs1'
           *  Constant: '<S81>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S81>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* RelationalOperator: '<S112>/Compare' incorporates:
           *  Abs: '<S87>/Abs1'
           *  Constant: '<S112>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Chart: '<S87>/Motion State' incorporates:
           *  Abs: '<S87>/Abs'
           */
          if (FMS_DW.temporalCounter_i1_ie < 255U) {
            FMS_DW.temporalCounter_i1_ie++;
          }

          if (FMS_DW.is_active_c26_FMS == 0U) {
            FMS_DW.is_active_c26_FMS = 1U;
            FMS_DW.is_c26_FMS = FMS_IN_Move_p;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c26_FMS) {
             case FMS_IN_Brake_bw:
              rtb_state_fg = MotionState_Brake;

              /* Product: '<S87>/Multiply' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S30>/Signal Copy1'
               */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n
                  + 6] * FMS_U.INS_Out.vd + (rtb_VectorConcatenate_pc[rtb_n + 3]
                  * FMS_U.INS_Out.ve + rtb_VectorConcatenate_pc[rtb_n] *
                  FMS_U.INS_Out.vn);

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              }

              /* End of Product: '<S87>/Multiply' */
              if ((fabsf(rtb_VectorConcatenate_g0[1]) <= 0.2) ||
                  (FMS_DW.temporalCounter_i1_ie >= 250U)) {
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
                FMS_DW.temporalCounter_i1_ie = 0U;
                rtb_state_fg = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S87>/Motion State' */

          /* SwitchCase: '<S86>/Switch Case' incorporates:
           *  Math: '<S100>/Square'
           *  Product: '<S107>/Divide'
           *  Sum: '<S92>/Subtract'
           *  Switch: '<S91>/Switch'
           */
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
              /* InitializeConditions for IfAction SubSystem: '<S86>/Hold Control' incorporates:
               *  ActionPort: '<S89>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S86>/Switch Case' incorporates:
               *  Delay: '<S93>/start_vel'
               *  Delay: '<S93>/start_wp'
               */
              FMS_DW.icLoad_g = 1U;
              FMS_DW.icLoad_e = 1U;

              /* End of InitializeConditions for SubSystem: '<S86>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S86>/Hold Control' incorporates:
             *  ActionPort: '<S89>/Action Port'
             */
            /* Trigonometry: '<S108>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_Saturation1_hc;

            /* Trigonometry: '<S108>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Saturation1_d;

            /* SignalConversion: '<S108>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S108>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S108>/Gain' incorporates:
             *  Gain: '<S106>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S108>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Trigonometry: '<S108>/Trigonometric Function3' */
            rtb_Transpose[4] = rtb_Saturation1_hc;

            /* SignalConversion: '<S108>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S108>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* SignalConversion: '<S108>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_jn[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_jn[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_jn[2];

            /* Math: '<S93>/Transpose' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_pc[3 * rtb_n] = rtb_Transpose[rtb_n];
              rtb_VectorConcatenate_pc[1 + 3 * rtb_n] = rtb_Transpose[rtb_n + 3];
              rtb_VectorConcatenate_pc[2 + 3 * rtb_n] = rtb_Transpose[rtb_n + 6];
            }

            for (rtb_n = 0; rtb_n < 9; rtb_n++) {
              rtb_Transpose[rtb_n] = rtb_VectorConcatenate_pc[rtb_n];
            }

            /* End of Math: '<S93>/Transpose' */

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S101>/Sum of Elements' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Math: '<S101>/Math Function'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Math: '<S101>/Math Function1' incorporates:
             *  Sum: '<S101>/Sum of Elements'
             *
             * About '<S101>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
            } else {
              rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
            }

            /* End of Math: '<S101>/Math Function1' */

            /* Switch: '<S101>/Switch' incorporates:
             *  Constant: '<S101>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S101>/Product'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            if (rtb_Saturation_d > 0.0F) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Switch_d0[0] = FMS_U.INS_Out.vn;
              rtb_Switch_d0[1] = FMS_U.INS_Out.ve;

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              rtb_Switch_d0[2] = rtb_Saturation_d;
            } else {
              rtb_Switch_d0[0] = 0.0F;
              rtb_Switch_d0[1] = 0.0F;
              rtb_Switch_d0[2] = 1.0F;
            }

            /* End of Switch: '<S101>/Switch' */

            /* Product: '<S101>/Divide' */
            rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
            rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

            /* Sum: '<S104>/Sum of Elements' incorporates:
             *  Math: '<S104>/Math Function'
             *  SignalConversion: '<S104>/TmpSignal ConversionAtMath FunctionInport1'
             */
            rtb_Saturation1_hc = rtb_Divide_n4[1] * rtb_Divide_n4[1] +
              rtb_Divide_n4[0] * rtb_Divide_n4[0];

            /* Math: '<S104>/Math Function1' incorporates:
             *  Sum: '<S104>/Sum of Elements'
             *
             * About '<S104>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
            } else {
              rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
            }

            /* End of Math: '<S104>/Math Function1' */

            /* Switch: '<S104>/Switch' incorporates:
             *  Constant: '<S104>/Constant'
             *  Product: '<S104>/Product'
             */
            if (rtb_Saturation_d > 0.0F) {
              rtb_Switch_d0[0] = rtb_Divide_n4[1];
              rtb_Switch_d0[1] = rtb_Divide_n4[0];
              rtb_Switch_d0[2] = rtb_Saturation_d;
            } else {
              rtb_Switch_d0[0] = 0.0F;
              rtb_Switch_d0[1] = 0.0F;
              rtb_Switch_d0[2] = 1.0F;
            }

            /* End of Switch: '<S104>/Switch' */

            /* Delay: '<S93>/start_vel' incorporates:
             *  Product: '<S93>/Multiply'
             */
            if (FMS_DW.icLoad_g != 0) {
              /* Product: '<S93>/Multiply' */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                rtb_VectorConcatenate_g0[rtb_n] = rtb_Transpose[rtb_n];
              }

              FMS_DW.start_vel_DSTATE[0] = rtb_VectorConcatenate_g0[0];
              FMS_DW.start_vel_DSTATE[1] = rtb_VectorConcatenate_g0[1];
            }

            /* Sum: '<S107>/Sum of Elements' incorporates:
             *  Delay: '<S93>/start_vel'
             *  Math: '<S107>/Math Function'
             */
            rtb_Saturation1_hc = FMS_DW.start_vel_DSTATE[0] *
              FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
              FMS_DW.start_vel_DSTATE[1];

            /* Math: '<S107>/Math Function1' incorporates:
             *  Sum: '<S107>/Sum of Elements'
             *
             * About '<S107>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
            } else {
              rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
            }

            /* End of Math: '<S107>/Math Function1' */

            /* Switch: '<S107>/Switch' incorporates:
             *  Constant: '<S107>/Constant'
             *  Delay: '<S93>/start_vel'
             *  Product: '<S107>/Product'
             */
            if (rtb_Saturation_d > 0.0F) {
              rtb_Switch_ov[0] = FMS_DW.start_vel_DSTATE[0];
              rtb_Switch_ov[1] = FMS_DW.start_vel_DSTATE[1];
              rtb_Switch_ov[2] = rtb_Saturation_d;
            } else {
              rtb_Switch_ov[0] = 0.0F;
              rtb_Switch_ov[1] = 0.0F;
              rtb_Switch_ov[2] = 1.0F;
            }

            /* End of Switch: '<S107>/Switch' */

            /* Delay: '<S93>/start_wp' incorporates:
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
            /* MATLAB Function: '<S91>/SearchL1RefWP' incorporates:
             *  Delay: '<S93>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Divide_n4[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_n4[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Product: '<S107>/Divide' */
            rtb_a_bx = rtb_Switch_ov[0] / rtb_Switch_ov[2];

            /* MATLAB Function: '<S91>/SearchL1RefWP' */
            rtb_Saturation_d = rtb_a_bx * rtb_Divide_n4[0];
            rtb_Saturation1_hc = rtb_a_bx;

            /* Product: '<S107>/Divide' */
            rtb_a_bx = rtb_Switch_ov[1] / rtb_Switch_ov[2];

            /* MATLAB Function: '<S91>/SearchL1RefWP' incorporates:
             *  Constant: '<S89>/L1'
             *  Delay: '<S93>/start_wp'
             */
            rtb_Saturation_d += rtb_a_bx * rtb_Divide_n4[1];
            rtb_Saturation1_d = 2.0F * rtb_Saturation_d;
            rtb_P_cg[0] = 0.0F;
            rtb_P_cg[1] = 0.0F;
            rtb_Subtract3_d = rtb_Saturation1_d * rtb_Saturation1_d -
              ((rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
                rtb_Divide_n4[1]) - FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1) * 4.0F;
            rtb_Saturation_d = -1.0F;
            if (rtb_Subtract3_d > 0.0F) {
              rtb_Saturation_d = sqrtf(rtb_Subtract3_d);
              rtb_Saturation_d = fmaxf((-rtb_Saturation1_d + rtb_Saturation_d) /
                2.0F, (-rtb_Saturation1_d - rtb_Saturation_d) / 2.0F);
              rtb_P_cg[0] = rtb_Saturation_d * rtb_Saturation1_hc +
                FMS_DW.start_wp_DSTATE[0];
              rtb_P_cg[1] = rtb_Saturation_d * rtb_a_bx +
                FMS_DW.start_wp_DSTATE[1];
            } else {
              if (rtb_Subtract3_d == 0.0F) {
                rtb_Saturation_d = -rtb_Saturation1_d / 2.0F;
                rtb_P_cg[0] = rtb_Saturation_d * rtb_Saturation1_hc +
                  FMS_DW.start_wp_DSTATE[0];
                rtb_P_cg[1] = rtb_Saturation_d * rtb_a_bx +
                  FMS_DW.start_wp_DSTATE[1];
              }
            }

            /* RelationalOperator: '<S94>/Compare' incorporates:
             *  Constant: '<S94>/Constant'
             *  MATLAB Function: '<S91>/SearchL1RefWP'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_d > 0.0F);

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S91>/OutRegionRefWP' incorporates:
             *  Delay: '<S93>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Saturation_d = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
              rtb_Saturation1_hc + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1])
              * rtb_a_bx;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation1_d = 1.29246971E-26F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = fabsf((rtb_Saturation_d * rtb_Saturation1_hc +
              FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            if (rtb_Switch_f_idx_0 > 1.29246971E-26F) {
              rtb_Switch_f_idx_2 = 1.0F;
              rtb_Saturation1_d = rtb_Switch_f_idx_0;
            } else {
              rtb_Switch_f_idx_1 = rtb_Switch_f_idx_0 / 1.29246971E-26F;
              rtb_Switch_f_idx_2 = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = fabsf((rtb_Saturation_d * rtb_a_bx +
              FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            if (rtb_Switch_f_idx_0 > rtb_Saturation1_d) {
              rtb_Switch_f_idx_1 = rtb_Saturation1_d / rtb_Switch_f_idx_0;
              rtb_Switch_f_idx_2 = rtb_Switch_f_idx_2 * rtb_Switch_f_idx_1 *
                rtb_Switch_f_idx_1 + 1.0F;
              rtb_Saturation1_d = rtb_Switch_f_idx_0;
            } else {
              rtb_Switch_f_idx_1 = rtb_Switch_f_idx_0 / rtb_Saturation1_d;
              rtb_Switch_f_idx_2 += rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;
            }

            rtb_Switch_f_idx_2 = rtb_Saturation1_d * sqrtf(rtb_Switch_f_idx_2);
            rtb_Switch_f_idx_0 = rtb_Switch_f_idx_2 * 0.577350259F +
              rtb_Saturation_d;

            /* Switch: '<S91>/Switch' incorporates:
             *  Delay: '<S93>/start_wp'
             *  MATLAB Function: '<S91>/OutRegionRefWP'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Saturation_d = rtb_P_cg[0];
            } else {
              rtb_Saturation_d = rtb_Switch_f_idx_0 * rtb_Saturation1_hc +
                FMS_DW.start_wp_DSTATE[0];
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S92>/Subtract' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Saturation1_d = rtb_Saturation_d - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Math: '<S102>/Math Function' */
            rtb_Divide_n4[0] = rtb_Saturation1_d * rtb_Saturation1_d;
            rtb_P_cg[0] = rtb_Saturation1_d;

            /* Switch: '<S91>/Switch' incorporates:
             *  Delay: '<S93>/start_wp'
             *  MATLAB Function: '<S91>/OutRegionRefWP'
             *  Sum: '<S92>/Subtract'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Saturation_d = rtb_P_cg[1];
            } else {
              rtb_Saturation_d = rtb_Switch_f_idx_0 * rtb_a_bx +
                FMS_DW.start_wp_DSTATE[1];
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S92>/Subtract' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Saturation1_d = rtb_Saturation_d - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Math: '<S102>/Math Function' incorporates:
             *  Math: '<S100>/Square'
             */
            rtb_Saturation1_hc = rtb_Saturation1_d * rtb_Saturation1_d;

            /* Sum: '<S102>/Sum of Elements' incorporates:
             *  Math: '<S102>/Math Function'
             */
            rtb_a_bx = rtb_Saturation1_hc + rtb_Divide_n4[0];

            /* Math: '<S102>/Math Function1' incorporates:
             *  Sum: '<S102>/Sum of Elements'
             *
             * About '<S102>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_bx < 0.0F) {
              rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
            } else {
              rtb_Saturation_d = sqrtf(rtb_a_bx);
            }

            /* End of Math: '<S102>/Math Function1' */

            /* Switch: '<S102>/Switch' incorporates:
             *  Constant: '<S102>/Constant'
             *  Product: '<S102>/Product'
             */
            if (rtb_Saturation_d > 0.0F) {
              rtb_Switch_ov[0] = rtb_P_cg[0];
              rtb_Switch_ov[1] = rtb_Saturation1_d;
              rtb_Switch_ov[2] = rtb_Saturation_d;
            } else {
              rtb_Switch_ov[0] = 0.0F;
              rtb_Switch_ov[1] = 0.0F;
              rtb_Switch_ov[2] = 1.0F;
            }

            /* End of Switch: '<S102>/Switch' */

            /* Product: '<S102>/Divide' */
            rtb_P_dg[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
            rtb_P_dg[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

            /* Sum: '<S105>/Sum of Elements' incorporates:
             *  Math: '<S105>/Math Function'
             *  SignalConversion: '<S105>/TmpSignal ConversionAtMath FunctionInport1'
             */
            rtb_a_bx = rtb_P_dg[1] * rtb_P_dg[1] + rtb_P_dg[0] * rtb_P_dg[0];

            /* Math: '<S105>/Math Function1' incorporates:
             *  Sum: '<S105>/Sum of Elements'
             *
             * About '<S105>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_bx < 0.0F) {
              rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
            } else {
              rtb_Saturation_d = sqrtf(rtb_a_bx);
            }

            /* End of Math: '<S105>/Math Function1' */

            /* Switch: '<S105>/Switch' incorporates:
             *  Constant: '<S105>/Constant'
             *  Product: '<S105>/Product'
             */
            if (rtb_Saturation_d > 0.0F) {
              rtb_Switch_ov[0] = rtb_P_dg[1];
              rtb_Switch_ov[1] = rtb_P_dg[0];
              rtb_Switch_ov[2] = rtb_Saturation_d;
            } else {
              rtb_Switch_ov[0] = 0.0F;
              rtb_Switch_ov[1] = 0.0F;
              rtb_Switch_ov[2] = 1.0F;
            }

            /* End of Switch: '<S105>/Switch' */

            /* Product: '<S105>/Divide' */
            rtb_P_dg[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

            /* Product: '<S104>/Divide' */
            rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
            rtb_P_cg[0] *= rtb_P_cg[0];

            /* Product: '<S105>/Divide' incorporates:
             *  Math: '<S100>/Square'
             */
            rtb_P_dg[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

            /* Product: '<S104>/Divide' */
            rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sqrt: '<S99>/Sqrt' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Math: '<S99>/Square'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S99>/Sum of Elements'
             */
            rtb_Saturation_d = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Gain: '<S97>/Gain' incorporates:
             *  Math: '<S97>/Square'
             */
            rtb_Saturation1_d = rtb_Saturation_d * rtb_Saturation_d * 2.0F;

            /* Sum: '<S103>/Subtract' incorporates:
             *  Product: '<S103>/Multiply'
             *  Product: '<S103>/Multiply1'
             */
            rtb_Saturation_d = rtb_P_dg[0] * rtb_Divide_n4[1] - rtb_P_dg[1] *
              rtb_Divide_n4[0];

            /* Signum: '<S98>/Sign1' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
              }
            }

            /* End of Signum: '<S98>/Sign1' */

            /* Switch: '<S98>/Switch2' incorporates:
             *  Constant: '<S98>/Constant4'
             */
            if (rtb_Saturation_d == 0.0F) {
              rtb_Saturation_d = 1.0F;
            }

            /* End of Switch: '<S98>/Switch2' */

            /* DotProduct: '<S98>/Dot Product' */
            rtb_Switch_f_idx_1 = rtb_Divide_n4[0] * rtb_P_dg[0] + rtb_Divide_n4
              [1] * rtb_P_dg[1];

            /* Trigonometry: '<S98>/Acos' incorporates:
             *  DotProduct: '<S98>/Dot Product'
             */
            if (rtb_Switch_f_idx_1 > 1.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            } else {
              if (rtb_Switch_f_idx_1 < -1.0F) {
                rtb_Switch_f_idx_1 = -1.0F;
              }
            }

            /* Product: '<S98>/Multiply' incorporates:
             *  Trigonometry: '<S98>/Acos'
             */
            rtb_Saturation_d *= acosf(rtb_Switch_f_idx_1);

            /* Saturate: '<S97>/Saturation' */
            if (rtb_Saturation_d > 1.57079637F) {
              rtb_Saturation_d = 1.57079637F;
            } else {
              if (rtb_Saturation_d < -1.57079637F) {
                rtb_Saturation_d = -1.57079637F;
              }
            }

            /* End of Saturate: '<S97>/Saturation' */

            /* Product: '<S97>/Divide' incorporates:
             *  Constant: '<S89>/L1'
             *  Constant: '<S97>/Constant'
             *  MinMax: '<S97>/Max'
             *  MinMax: '<S97>/Min'
             *  Product: '<S97>/Multiply1'
             *  Sqrt: '<S100>/Sqrt'
             *  Sum: '<S100>/Sum of Elements'
             *  Trigonometry: '<S97>/Sin'
             */
            FMS_B.Merge_be = arm_sin_f32(rtb_Saturation_d) * rtb_Saturation1_d /
              fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf(rtb_Saturation1_hc + rtb_P_cg[0]),
                     0.5F));

            /* Update for Delay: '<S93>/start_vel' */
            FMS_DW.icLoad_g = 0U;

            /* Update for Delay: '<S93>/start_wp' */
            FMS_DW.icLoad_e = 0U;

            /* End of Outputs for SubSystem: '<S86>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S86>/Brake Control' incorporates:
             *  ActionPort: '<S88>/Action Port'
             */
            /* SignalConversion: '<S88>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
             *  Constant: '<S88>/Brake Speed'
             */
            FMS_B.Merge_be = 0.0F;

            /* End of Outputs for SubSystem: '<S86>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S86>/Move Control' incorporates:
               *  ActionPort: '<S90>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S86>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S110>/Integrator'
               *  DiscreteIntegrator: '<S110>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_c = 0.0F;
              FMS_DW.Integrator_DSTATE_f1 = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S86>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S86>/Move Control' incorporates:
             *  ActionPort: '<S90>/Action Port'
             */
            /* Product: '<S111>/Multiply1' incorporates:
             *  Constant: '<S111>/const1'
             *  DiscreteIntegrator: '<S110>/Integrator'
             */
            rtb_Saturation_d = FMS_DW.Integrator_DSTATE_f1 * 0.05F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* DeadZone: '<S109>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S30>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
                FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_hc = 0.0F;
            } else {
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S109>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Sum: '<S111>/Add' incorporates:
             *  DiscreteIntegrator: '<S110>/Integrator1'
             *  Gain: '<S109>/Gain'
             *  Gain: '<S90>/Gain6'
             *  Sum: '<S110>/Subtract'
             */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_c - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation1_hc * FMS_PARAM.FW_ACC_Y_LIM)
              + rtb_Saturation_d;

            /* Signum: '<S111>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_hc = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            } else {
              rtb_Saturation1_hc = rtb_Saturation1_d;
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
            rtb_Saturation1_hc = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
              FMS_ConstB.d_h) * FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F *
              rtb_Saturation1_hc + rtb_Saturation_d;

            /* Sum: '<S111>/Add4' */
            rtb_Switch_f_idx_0 = (rtb_Saturation1_d - rtb_Saturation1_hc) +
              rtb_Saturation_d;

            /* Sum: '<S111>/Add3' */
            rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_h;

            /* Sum: '<S111>/Subtract1' */
            rtb_Saturation1_d -= FMS_ConstB.d_h;

            /* Signum: '<S111>/Sign1' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
              }
            }

            /* End of Signum: '<S111>/Sign1' */

            /* Signum: '<S111>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S111>/Sign2' */

            /* Sum: '<S111>/Add5' incorporates:
             *  Gain: '<S111>/Gain2'
             *  Product: '<S111>/Multiply4'
             *  Sum: '<S111>/Subtract2'
             */
            rtb_Saturation1_hc += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
              rtb_Switch_f_idx_0;

            /* SignalConversion: '<S90>/OutportBufferForay_cmd_mPs2' incorporates:
             *  DiscreteIntegrator: '<S110>/Integrator1'
             */
            FMS_B.Merge_be = FMS_DW.Integrator1_DSTATE_c;

            /* Update for DiscreteIntegrator: '<S110>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S110>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_c += 0.004F * FMS_DW.Integrator_DSTATE_f1;

            /* Sum: '<S111>/Subtract3' */
            rtb_Saturation_d = rtb_Saturation1_hc - FMS_ConstB.d_h;

            /* Sum: '<S111>/Add6' */
            rtb_Saturation1_d = rtb_Saturation1_hc + FMS_ConstB.d_h;

            /* Signum: '<S111>/Sign5' incorporates:
             *  Signum: '<S111>/Sign6'
             */
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Switch_f_idx_0 = -1.0F;

              /* Signum: '<S111>/Sign6' */
              rtb_Switch_f_idx_2 = -1.0F;
            } else if (rtb_Saturation1_hc > 0.0F) {
              rtb_Switch_f_idx_0 = 1.0F;

              /* Signum: '<S111>/Sign6' */
              rtb_Switch_f_idx_2 = 1.0F;
            } else {
              rtb_Switch_f_idx_0 = rtb_Saturation1_hc;

              /* Signum: '<S111>/Sign6' */
              rtb_Switch_f_idx_2 = rtb_Saturation1_hc;
            }

            /* End of Signum: '<S111>/Sign5' */

            /* Signum: '<S111>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S111>/Sign3' */

            /* Signum: '<S111>/Sign4' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
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
            FMS_DW.Integrator_DSTATE_f1 += ((rtb_Saturation1_hc / FMS_ConstB.d_h
              - rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_b * ((rtb_Saturation1_d -
              rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S86>/Move Control' */
            break;
          }

          /* SwitchCase: '<S72>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S72>/Hold Control' incorporates:
               *  ActionPort: '<S75>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S72>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S72>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S72>/Hold Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_f,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S72>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S72>/Brake Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S72>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S72>/Move Control' incorporates:
               *  ActionPort: '<S76>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S72>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S72>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S72>/Move Control' incorporates:
             *  ActionPort: '<S76>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_f,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S72>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S72>/Switch Case' */

          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Constant: '<S44>/Constant'
           *  DiscreteIntegrator: '<S84>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Saturate: '<S68>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S68>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Gain: '<S68>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation1_hc;

          /* Saturate: '<S86>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S44>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S44>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S44>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S86>/Saturation1' */

          /* Saturate: '<S72>/Saturation1' */
          if (FMS_B.Merge_f > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S44>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_f < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S44>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S44>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_f;
          }

          /* End of Saturate: '<S72>/Saturation1' */

          /* Product: '<S85>/Multiply1' incorporates:
           *  Constant: '<S85>/const1'
           *  DiscreteIntegrator: '<S84>/Integrator'
           */
          rtb_Saturation_d = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S83>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S83>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S85>/Add' incorporates:
           *  DiscreteIntegrator: '<S84>/Integrator1'
           *  Gain: '<S70>/Gain1'
           *  Gain: '<S83>/Gain'
           *  Sum: '<S84>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation1_hc * FMS_PARAM.FW_YAW_RATE_LIM)
            + rtb_Saturation_d;

          /* Signum: '<S85>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Saturation1_d;
          }

          /* End of Signum: '<S85>/Sign' */

          /* Sum: '<S85>/Add2' incorporates:
           *  Abs: '<S85>/Abs'
           *  Gain: '<S85>/Gain'
           *  Gain: '<S85>/Gain1'
           *  Product: '<S85>/Multiply2'
           *  Product: '<S85>/Multiply3'
           *  Sqrt: '<S85>/Sqrt'
           *  Sum: '<S85>/Add1'
           *  Sum: '<S85>/Subtract'
           */
          rtb_Saturation1_hc = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Saturation1_hc + rtb_Saturation_d;

          /* Sum: '<S85>/Add4' */
          rtb_Switch_f_idx_0 = (rtb_Saturation1_d - rtb_Saturation1_hc) +
            rtb_Saturation_d;

          /* Sum: '<S85>/Add3' */
          rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_l;

          /* Sum: '<S85>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_l;

          /* Signum: '<S85>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign1' */

          /* Signum: '<S85>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign2' */

          /* Sum: '<S85>/Add5' incorporates:
           *  Gain: '<S85>/Gain2'
           *  Product: '<S85>/Multiply4'
           *  Sum: '<S85>/Subtract2'
           */
          rtb_Saturation1_hc += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
            rtb_Switch_f_idx_0;

          /* Update for DiscreteIntegrator: '<S84>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S84>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Sum: '<S85>/Subtract3' */
          rtb_Saturation_d = rtb_Saturation1_hc - FMS_ConstB.d_l;

          /* Sum: '<S85>/Add6' */
          rtb_Saturation1_d = rtb_Saturation1_hc + FMS_ConstB.d_l;

          /* Signum: '<S85>/Sign5' incorporates:
           *  Signum: '<S85>/Sign6'
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S85>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_Saturation1_hc > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S85>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_Saturation1_hc;

            /* Signum: '<S85>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_Saturation1_hc;
          }

          /* End of Signum: '<S85>/Sign5' */

          /* Signum: '<S85>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign3' */

          /* Signum: '<S85>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign4' */

          /* Update for DiscreteIntegrator: '<S84>/Integrator' incorporates:
           *  Constant: '<S85>/const'
           *  Gain: '<S85>/Gain3'
           *  Product: '<S85>/Divide'
           *  Product: '<S85>/Multiply5'
           *  Product: '<S85>/Multiply6'
           *  Sum: '<S85>/Subtract4'
           *  Sum: '<S85>/Subtract5'
           *  Sum: '<S85>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_Saturation1_hc / FMS_ConstB.d_l -
            rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_a * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 15.707963F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S38>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S38>/Unknown' incorporates:
           *  ActionPort: '<S46>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S38>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S38>/Switch Case' */
        /* End of Outputs for SubSystem: '<S36>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S36>/Manual' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Saturate: '<S156>/Saturation' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
          rtb_Saturation1_hc = 1.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
          rtb_Saturation1_hc = 0.0F;
        } else {
          rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_throttle;
        }

        /* End of Saturate: '<S156>/Saturation' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* DataTypeConversion: '<S155>/Data Type Conversion' incorporates:
         *  Constant: '<S156>/Constant5'
         *  Gain: '<S156>/Gain4'
         *  Sum: '<S156>/Add'
         */
        rtb_DataTypeConversion_o = (uint16_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_hc + 1000.0F), 65536.0F);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DataTypeConversion: '<S155>/Data Type Conversion1' incorporates:
         *  Bias: '<S155>/Bias1'
         *  Gain: '<S155>/Gain'
         *  Gain: '<S155>/Gain1'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        rtb_Saturation1_hc = fmodf(floorf(FMS_PARAM.MANUAL_ROLL_REV *
          FMS_U.Pilot_Cmd.stick_roll * 500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_DataTypeConversion1_b = (uint16_T)(rtb_Saturation1_hc < 0.0F ?
          (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation1_hc : (int32_T)
          (uint16_T)rtb_Saturation1_hc);

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  Constant: '<S40>/Constant'
         *  Constant: '<S40>/Constant2'
         *  SignalConversion: '<S40>/TmpHiddenBufferAtBus AssignmentInport1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;
        FMS_Y.FMS_Out.actuator_cmd[0] = rtb_DataTypeConversion_o;
        FMS_Y.FMS_Out.actuator_cmd[1] = rtb_DataTypeConversion_o;
        FMS_Y.FMS_Out.actuator_cmd[2] = rtb_DataTypeConversion1_b;
        FMS_Y.FMS_Out.actuator_cmd[3] = rtb_DataTypeConversion1_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DataTypeConversion: '<S155>/Data Type Conversion2' incorporates:
         *  Bias: '<S155>/Bias2'
         *  Gain: '<S155>/Gain2'
         *  Gain: '<S155>/Gain4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        rtb_Saturation1_hc = fmodf(floorf(FMS_PARAM.MANUAL_PITCH_REV *
          FMS_U.Pilot_Cmd.stick_pitch * -500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S155>/Data Type Conversion2'
         */
        FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_Saturation1_hc < 0.0F ?
          (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation1_hc : (int32_T)
          (uint16_T)rtb_Saturation1_hc);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DataTypeConversion: '<S155>/Data Type Conversion3' incorporates:
         *  Bias: '<S155>/Bias3'
         *  Gain: '<S155>/Gain3'
         *  Gain: '<S155>/Gain5'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        rtb_Saturation1_hc = fmodf(floorf(FMS_PARAM.MANUAL_YAW_REV *
          FMS_U.Pilot_Cmd.stick_yaw * 500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S155>/Data Type Conversion3'
         */
        FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_Saturation1_hc < 0.0F ?
          (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation1_hc : (int32_T)
          (uint16_T)rtb_Saturation1_hc);
        for (rtb_n = 0; rtb_n < 10; rtb_n++) {
          FMS_Y.FMS_Out.actuator_cmd[rtb_n + 6] = 0U;
        }

        /* End of Outputs for SubSystem: '<S36>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S36>/Unknown' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

        /* End of Outputs for SubSystem: '<S36>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S36>/Switch Case' */
      /* End of Outputs for SubSystem: '<S31>/FW_Mode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S31>/BackTrans_Mode' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* BusAssignment: '<S35>/Bus Assignment' incorporates:
       *  Constant: '<S35>/Constant'
       *  Constant: '<S35>/Constant3'
       *  Constant: '<S35>/Constant4'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_g;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_i;
      FMS_Y.FMS_Out.phi_cmd = 0.0F;
      FMS_Y.FMS_Out.theta_cmd = 0.261799395F;
      FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
      FMS_Y.FMS_Out.w_cmd = 0.0F;

      /* End of Outputs for SubSystem: '<S31>/BackTrans_Mode' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S31>/MC_Mode' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* SwitchCase: '<S37>/Switch Case' */
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
          /* Disable for SwitchCase: '<S227>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S612>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S602>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S551>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S529>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S539>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S225>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S337>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S375>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* End of Disable for SubSystem: '<S337>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S224>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S324>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S239>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S257>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S273>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S298>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S285>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S37>/SubMode' incorporates:
         *  ActionPort: '<S227>/Action Port'
         */
        /* SwitchCase: '<S227>/Switch Case' incorporates:
         *  Product: '<S636>/Divide'
         *  Sum: '<S596>/Subtract'
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
            /* Disable for SwitchCase: '<S612>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S602>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S551>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S529>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S539>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S227>/Takeoff' incorporates:
             *  ActionPort: '<S524>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S227>/Switch Case' incorporates:
             *  Delay: '<S652>/cur_waypoint'
             *  DiscreteIntegrator: '<S648>/Integrator'
             *  DiscreteIntegrator: '<S648>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S227>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S227>/Takeoff' incorporates:
           *  ActionPort: '<S524>/Action Port'
           */
          /* Delay: '<S652>/cur_waypoint' incorporates:
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
          /* Product: '<S652>/Divide' incorporates:
           *  Delay: '<S652>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S652>/Sum1'
           *  Sum: '<S652>/Sum2'
           */
          rtb_Saturation_d = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S652>/Saturation' */
          if (rtb_Saturation_d > 1.0F) {
            rtb_Saturation_d = 1.0F;
          } else {
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = 0.0F;
            }
          }

          /* End of Saturate: '<S652>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S653>/Trigonometric Function1' incorporates:
           *  Gain: '<S651>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_pc[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S653>/Trigonometric Function' incorporates:
           *  Gain: '<S651>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_pc[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S653>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S653>/Constant3'
           */
          rtb_VectorConcatenate_pc[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S653>/Gain' incorporates:
           *  Gain: '<S651>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S653>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_pc[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S653>/Trigonometric Function3' incorporates:
           *  Gain: '<S651>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_pc[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S653>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S653>/Constant4'
           */
          rtb_VectorConcatenate_pc[5] = 0.0F;

          /* SignalConversion: '<S653>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Saturate: '<S645>/Saturation1' */
          rtb_Switch_f_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Switch_f_idx_2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SignalConversion: '<S645>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S652>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S652>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S645>/Sum'
           *  Sum: '<S652>/Sum3'
           *  Sum: '<S652>/Sum4'
           */
          rtb_Saturation1_d = ((FMS_B.Cmd_In.sp_waypoint[0] -
                                FMS_DW.cur_waypoint_DSTATE[0]) *
                               rtb_Saturation_d + FMS_DW.cur_waypoint_DSTATE[0])
            - FMS_U.INS_Out.x_R;
          rtb_Saturation1_hc = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_d +
                                FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S645>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 3]
              * rtb_Saturation1_hc + rtb_VectorConcatenate_pc[rtb_n] *
              rtb_Saturation1_d;
          }

          /* Saturate: '<S645>/Saturation1' incorporates:
           *  Gain: '<S645>/Gain2'
           *  Product: '<S645>/Multiply'
           */
          rtb_Switch_f_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Saturation_d = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* BusAssignment: '<S524>/Bus Assignment1' incorporates:
           *  Constant: '<S524>/Constant'
           *  Constant: '<S524>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S645>/Saturation1' */
          if (rtb_Switch_f_idx_1 > rtb_Switch_f_idx_0) {
            /* BusAssignment: '<S524>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_0;
          } else if (rtb_Switch_f_idx_1 < rtb_Switch_f_idx_2) {
            /* BusAssignment: '<S524>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_2;
          } else {
            /* BusAssignment: '<S524>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_1;
          }

          if (rtb_Saturation_d > rtb_Switch_f_idx_0) {
            /* BusAssignment: '<S524>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_f_idx_0;
          } else if (rtb_Saturation_d < rtb_Switch_f_idx_2) {
            /* BusAssignment: '<S524>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_f_idx_2;
          } else {
            /* BusAssignment: '<S524>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_d;
          }

          /* BusAssignment: '<S524>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S648>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S649>/Multiply1' incorporates:
           *  Constant: '<S649>/const1'
           *  DiscreteIntegrator: '<S648>/Integrator'
           */
          rtb_Saturation_d = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S644>/Switch' incorporates:
           *  Abs: '<S644>/Abs'
           *  Abs: '<S644>/Abs1'
           *  Constant: '<S644>/Takeoff_Speed'
           *  Constant: '<S646>/Constant'
           *  Constant: '<S647>/Constant'
           *  Gain: '<S644>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S644>/Logical Operator'
           *  RelationalOperator: '<S646>/Compare'
           *  RelationalOperator: '<S647>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S644>/Sum'
           *  Sum: '<S644>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_Saturation1_hc = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_Saturation1_hc = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S644>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S649>/Add' incorporates:
           *  DiscreteIntegrator: '<S648>/Integrator1'
           *  Sum: '<S648>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_f - rtb_Saturation1_hc)
            + rtb_Saturation_d;

          /* Signum: '<S649>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Saturation1_d;
          }

          /* End of Signum: '<S649>/Sign' */

          /* Sum: '<S649>/Add2' incorporates:
           *  Abs: '<S649>/Abs'
           *  Gain: '<S649>/Gain'
           *  Gain: '<S649>/Gain1'
           *  Product: '<S649>/Multiply2'
           *  Product: '<S649>/Multiply3'
           *  Sqrt: '<S649>/Sqrt'
           *  Sum: '<S649>/Add1'
           *  Sum: '<S649>/Subtract'
           */
          rtb_Saturation1_hc = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation1_hc + rtb_Saturation_d;

          /* Sum: '<S649>/Add4' */
          rtb_Switch_f_idx_0 = (rtb_Saturation1_d - rtb_Saturation1_hc) +
            rtb_Saturation_d;

          /* Sum: '<S649>/Add3' */
          rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Sum: '<S649>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_b;

          /* Signum: '<S649>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S649>/Sign1' */

          /* Signum: '<S649>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S649>/Sign2' */

          /* Sum: '<S649>/Add5' incorporates:
           *  Gain: '<S649>/Gain2'
           *  Product: '<S649>/Multiply4'
           *  Sum: '<S649>/Subtract2'
           */
          rtb_Saturation1_hc += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
            rtb_Switch_f_idx_0;

          /* Update for Delay: '<S652>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S648>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S648>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S649>/Subtract3' */
          rtb_Saturation_d = rtb_Saturation1_hc - FMS_ConstB.d_b;

          /* Sum: '<S649>/Add6' */
          rtb_Saturation1_d = rtb_Saturation1_hc + FMS_ConstB.d_b;

          /* Signum: '<S649>/Sign5' incorporates:
           *  Signum: '<S649>/Sign6'
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S649>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_Saturation1_hc > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S649>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_Saturation1_hc;

            /* Signum: '<S649>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_Saturation1_hc;
          }

          /* End of Signum: '<S649>/Sign5' */

          /* Signum: '<S649>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S649>/Sign3' */

          /* Signum: '<S649>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S649>/Sign4' */

          /* Update for DiscreteIntegrator: '<S648>/Integrator' incorporates:
           *  Constant: '<S649>/const'
           *  Gain: '<S649>/Gain3'
           *  Product: '<S649>/Divide'
           *  Product: '<S649>/Multiply5'
           *  Product: '<S649>/Multiply6'
           *  Sum: '<S649>/Subtract4'
           *  Sum: '<S649>/Subtract5'
           *  Sum: '<S649>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation1_hc / FMS_ConstB.d_b -
            rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_i * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S227>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S227>/Land' incorporates:
             *  ActionPort: '<S522>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S227>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S567>/Integrator'
             *  DiscreteIntegrator: '<S567>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S227>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S227>/Land' incorporates:
           *  ActionPort: '<S522>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S572>/Trigonometric Function1' incorporates:
           *  Gain: '<S571>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_pc[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S572>/Trigonometric Function' incorporates:
           *  Gain: '<S571>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_pc[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S572>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S572>/Constant3'
           */
          rtb_VectorConcatenate_pc[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S572>/Gain' incorporates:
           *  Gain: '<S571>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S572>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_pc[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S572>/Trigonometric Function3' incorporates:
           *  Gain: '<S571>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_pc[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S572>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S572>/Constant4'
           */
          rtb_VectorConcatenate_pc[5] = 0.0F;

          /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_j[0];
          rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_j[1];
          rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_j[2];

          /* Saturate: '<S565>/Saturation1' */
          rtb_Switch_f_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Switch_f_idx_2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SignalConversion: '<S569>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S569>/Sum'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Saturation1_hc = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S569>/Multiply' incorporates:
           *  SignalConversion: '<S569>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 3]
              * rtb_Saturation1_hc + rtb_VectorConcatenate_pc[rtb_n] *
              rtb_Saturation1_d;
          }

          /* End of Product: '<S569>/Multiply' */

          /* Saturate: '<S565>/Saturation1' incorporates:
           *  Gain: '<S569>/Gain2'
           */
          rtb_Switch_f_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Saturation_d = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* BusAssignment: '<S522>/Bus Assignment1' incorporates:
           *  Constant: '<S522>/Constant'
           *  Constant: '<S522>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S565>/Saturation1' */
          if (rtb_Switch_f_idx_1 > rtb_Switch_f_idx_0) {
            /* BusAssignment: '<S522>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_0;
          } else if (rtb_Switch_f_idx_1 < rtb_Switch_f_idx_2) {
            /* BusAssignment: '<S522>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_2;
          } else {
            /* BusAssignment: '<S522>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_1;
          }

          if (rtb_Saturation_d > rtb_Switch_f_idx_0) {
            /* BusAssignment: '<S522>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_f_idx_0;
          } else if (rtb_Saturation_d < rtb_Switch_f_idx_2) {
            /* BusAssignment: '<S522>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_f_idx_2;
          } else {
            /* BusAssignment: '<S522>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_d;
          }

          /* BusAssignment: '<S522>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S567>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S568>/Multiply1' incorporates:
           *  Constant: '<S568>/const1'
           *  DiscreteIntegrator: '<S567>/Integrator'
           */
          rtb_Saturation_d = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S564>/Switch' incorporates:
           *  Constant: '<S564>/Land_Speed'
           *  Constant: '<S566>/Constant'
           *  Gain: '<S564>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S564>/Logical Operator'
           *  RelationalOperator: '<S566>/Compare'
           *  S-Function (sfix_bitop): '<S564>/cmd_p valid'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_Saturation1_hc = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_Saturation1_hc = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S564>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S568>/Add' incorporates:
           *  DiscreteIntegrator: '<S567>/Integrator1'
           *  Sum: '<S567>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_g - rtb_Saturation1_hc)
            + rtb_Saturation_d;

          /* Signum: '<S568>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Saturation1_d;
          }

          /* End of Signum: '<S568>/Sign' */

          /* Sum: '<S568>/Add2' incorporates:
           *  Abs: '<S568>/Abs'
           *  Gain: '<S568>/Gain'
           *  Gain: '<S568>/Gain1'
           *  Product: '<S568>/Multiply2'
           *  Product: '<S568>/Multiply3'
           *  Sqrt: '<S568>/Sqrt'
           *  Sum: '<S568>/Add1'
           *  Sum: '<S568>/Subtract'
           */
          rtb_Saturation1_hc = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation1_hc + rtb_Saturation_d;

          /* Sum: '<S568>/Add4' */
          rtb_Switch_f_idx_0 = (rtb_Saturation1_d - rtb_Saturation1_hc) +
            rtb_Saturation_d;

          /* Sum: '<S568>/Add3' */
          rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Sum: '<S568>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_om;

          /* Signum: '<S568>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S568>/Sign1' */

          /* Signum: '<S568>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S568>/Sign2' */

          /* Sum: '<S568>/Add5' incorporates:
           *  Gain: '<S568>/Gain2'
           *  Product: '<S568>/Multiply4'
           *  Sum: '<S568>/Subtract2'
           */
          rtb_Saturation1_hc += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
            rtb_Switch_f_idx_0;

          /* Update for DiscreteIntegrator: '<S567>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S567>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S568>/Subtract3' */
          rtb_Saturation_d = rtb_Saturation1_hc - FMS_ConstB.d_om;

          /* Sum: '<S568>/Add6' */
          rtb_Saturation1_d = rtb_Saturation1_hc + FMS_ConstB.d_om;

          /* Signum: '<S568>/Sign5' incorporates:
           *  Signum: '<S568>/Sign6'
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S568>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_Saturation1_hc > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S568>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_Saturation1_hc;

            /* Signum: '<S568>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_Saturation1_hc;
          }

          /* End of Signum: '<S568>/Sign5' */

          /* Signum: '<S568>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S568>/Sign3' */

          /* Signum: '<S568>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S568>/Sign4' */

          /* Update for DiscreteIntegrator: '<S567>/Integrator' incorporates:
           *  Constant: '<S568>/const'
           *  Gain: '<S568>/Gain3'
           *  Product: '<S568>/Divide'
           *  Product: '<S568>/Multiply5'
           *  Product: '<S568>/Multiply6'
           *  Sum: '<S568>/Subtract4'
           *  Sum: '<S568>/Subtract5'
           *  Sum: '<S568>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Saturation1_hc / FMS_ConstB.d_om
            - rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_p * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S227>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S227>/Return' incorporates:
             *  ActionPort: '<S523>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S227>/Switch Case' incorporates:
             *  Delay: '<S575>/Delay'
             *  Delay: '<S576>/Delay'
             *  Delay: '<S597>/Delay'
             *  DiscreteIntegrator: '<S579>/Integrator'
             *  DiscreteIntegrator: '<S579>/Integrator1'
             *  DiscreteIntegrator: '<S593>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S598>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S639>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.icLoad_f = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S227>/Return' */

            /* SystemReset for IfAction SubSystem: '<S227>/Return' incorporates:
             *  ActionPort: '<S523>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S227>/Switch Case' incorporates:
             *  Chart: '<S603>/Motion Status'
             *  Chart: '<S613>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S227>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S227>/Return' incorporates:
           *  ActionPort: '<S523>/Action Port'
           */
          /* Delay: '<S597>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* RelationalOperator: '<S592>/Compare' incorporates:
           *  Constant: '<S643>/Constant'
           *  DiscreteIntegrator: '<S598>/Discrete-Time Integrator'
           *  RelationalOperator: '<S643>/Compare'
           */
          rtb_Compare_ii = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S593>/Acceleration_Speed' */
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
          /* Chart: '<S613>/Motion State' incorporates:
           *  Constant: '<S613>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S613>/Square'
           *  Math: '<S613>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S613>/Sqrt'
           *  Sum: '<S613>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S612>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S612>/Hold Control' incorporates:
               *  ActionPort: '<S615>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S612>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S612>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S612>/Hold Control' incorporates:
             *  ActionPort: '<S615>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S612>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S612>/Brake Control' incorporates:
             *  ActionPort: '<S614>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S612>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S612>/Move Control' incorporates:
               *  ActionPort: '<S616>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S612>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S612>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S612>/Move Control' incorporates:
             *  ActionPort: '<S616>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S612>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S612>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S603>/Motion Status' incorporates:
           *  Abs: '<S603>/Abs'
           *  Constant: '<S603>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S602>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S602>/Hold Control' incorporates:
               *  ActionPort: '<S605>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S602>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S602>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S602>/Hold Control' incorporates:
             *  ActionPort: '<S605>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S602>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S602>/Brake Control' incorporates:
             *  ActionPort: '<S604>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S602>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S602>/Move Control' incorporates:
               *  ActionPort: '<S606>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S602>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S602>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S602>/Move Control' incorporates:
             *  ActionPort: '<S606>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S602>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S602>/Switch Case' */

          /* Switch: '<S574>/Switch' incorporates:
           *  Product: '<S597>/Multiply'
           *  Sum: '<S597>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S612>/Saturation1' */
            if (FMS_B.Merge_m[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_ov[0] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_m[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_ov[0] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_ov[0] = FMS_B.Merge_m[0];
            }

            if (FMS_B.Merge_m[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_ov[1] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_m[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_ov[1] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_ov[1] = FMS_B.Merge_m[1];
            }

            /* End of Saturate: '<S612>/Saturation1' */

            /* Saturate: '<S602>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_ov[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_ov[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_ov[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S602>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S597>/Sum' incorporates:
             *  Delay: '<S597>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* SignalConversion: '<S640>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_ov[0] = rtb_Switch_f_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S593>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation_d = rtb_Switch_f_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S597>/Sum' incorporates:
             *  Delay: '<S597>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S593>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_hc = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Sqrt: '<S599>/Sqrt' incorporates:
             *  Math: '<S599>/Square'
             *  Sum: '<S593>/Sum'
             *  Sum: '<S599>/Sum of Elements'
             */
            rtb_Switch_f_idx_0 = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation1_hc * rtb_Saturation1_hc);

            /* SignalConversion: '<S642>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_d[0];
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_d[1];
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* SignalConversion: '<S642>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S642>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S641>/Gain' incorporates:
             *  DiscreteIntegrator: '<S639>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S639>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Trigonometry: '<S642>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S642>/Trigonometric Function1'
             */
            rtb_Saturation1_hc = arm_cos_f32(rtb_Saturation1_d);
            rtb_VectorConcatenate_pc[4] = rtb_Saturation1_hc;

            /* Trigonometry: '<S642>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S642>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation1_d);

            /* Gain: '<S642>/Gain' incorporates:
             *  Trigonometry: '<S642>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S642>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S642>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S642>/Trigonometric Function' */
            rtb_VectorConcatenate_pc[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S642>/Trigonometric Function1' */
            rtb_VectorConcatenate_pc[0] = rtb_Saturation1_hc;

            /* Switch: '<S593>/Switch' incorporates:
             *  Constant: '<S593>/vel'
             */
            if (rtb_Switch_f_idx_0 > FMS_PARAM.L1) {
              rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S593>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_Switch_f_idx_0;

              /* Saturate: '<S593>/Saturation' */
              if (rtb_Saturation1_d > FMS_PARAM.CRUISE_SPEED) {
                rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Saturate: '<S593>/Saturation' */
            }

            /* End of Switch: '<S593>/Switch' */

            /* Switch: '<S593>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S593>/Acceleration_Speed'
             *  Sum: '<S593>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S593>/Switch1' */

            /* Sum: '<S640>/Sum of Elements' incorporates:
             *  Math: '<S640>/Math Function'
             */
            rtb_Saturation1_hc = rtb_Switch_ov[0] * rtb_Switch_ov[0] +
              rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

            /* Math: '<S640>/Math Function1' incorporates:
             *  Sum: '<S640>/Sum of Elements'
             *
             * About '<S640>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation1_hc = -sqrtf(fabsf(rtb_Saturation1_hc));
            } else {
              rtb_Saturation1_hc = sqrtf(rtb_Saturation1_hc);
            }

            /* End of Math: '<S640>/Math Function1' */

            /* Switch: '<S640>/Switch' incorporates:
             *  Constant: '<S640>/Constant'
             *  Product: '<S640>/Product'
             */
            if (rtb_Saturation1_hc <= 0.0F) {
              rtb_Saturation_d = 0.0F;
              rtb_Switch_f_idx_1 = 0.0F;
              rtb_Saturation1_hc = 1.0F;
            }

            /* End of Switch: '<S640>/Switch' */

            /* Product: '<S638>/Multiply2' incorporates:
             *  Product: '<S640>/Divide'
             */
            rtb_Saturation_d = rtb_Saturation_d / rtb_Saturation1_hc *
              rtb_Saturation1_d;
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_1 / rtb_Saturation1_hc *
              rtb_Saturation1_d;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 3] *
                rtb_Switch_f_idx_1 + rtb_VectorConcatenate_pc[rtb_n] *
                rtb_Saturation_d;
            }
          }

          /* End of Switch: '<S574>/Switch' */

          /* Delay: '<S576>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S579>/Integrator1' incorporates:
           *  Delay: '<S576>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S583>/Rem' incorporates:
           *  Constant: '<S583>/Constant1'
           *  DiscreteIntegrator: '<S579>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S578>/Sum'
           */
          rtb_Saturation_d = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S583>/Switch' incorporates:
           *  Abs: '<S583>/Abs'
           *  Constant: '<S583>/Constant'
           *  Constant: '<S584>/Constant'
           *  Product: '<S583>/Multiply'
           *  RelationalOperator: '<S584>/Compare'
           *  Sum: '<S583>/Add'
           */
          if (fabsf(rtb_Saturation_d) > 3.14159274F) {
            /* Signum: '<S583>/Sign' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_d;
            }

            /* End of Signum: '<S583>/Sign' */
            rtb_Saturation_d -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S583>/Switch' */

          /* Gain: '<S578>/Gain2' */
          rtb_Saturation_d *= FMS_PARAM.YAW_P;

          /* Saturate: '<S578>/Saturation' */
          if (rtb_Saturation_d > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_d = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_d < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_d = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S578>/Saturation' */

          /* BusAssignment: '<S523>/Bus Assignment1' incorporates:
           *  Constant: '<S523>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_ov[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_d;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S633>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S633>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S633>/Math Function1' incorporates:
           *  Sum: '<S633>/Sum of Elements'
           *
           * About '<S633>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S633>/Math Function1' */

          /* Switch: '<S633>/Switch' incorporates:
           *  Constant: '<S633>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S633>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Saturation_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_ov[0] = FMS_U.INS_Out.vn;
            rtb_Switch_ov[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_ov[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S633>/Switch' */

          /* Delay: '<S575>/Delay' incorporates:
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
          /* Sum: '<S523>/Sum' incorporates:
           *  Delay: '<S575>/Delay'
           *  MATLAB Function: '<S595>/OutRegionRegWP'
           *  MATLAB Function: '<S595>/SearchL1RefWP'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_mn = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_nc[0];
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_nc[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S590>/Sum of Elements' incorporates:
           *  Math: '<S590>/Math Function'
           *  Sum: '<S523>/Sum'
           */
          rtb_Saturation1_hc = rtb_Divide_or * rtb_Divide_or + rtb_Sign5_mn *
            rtb_Sign5_mn;

          /* Math: '<S590>/Math Function1' incorporates:
           *  Sum: '<S590>/Sum of Elements'
           *
           * About '<S590>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S590>/Math Function1' */

          /* Switch: '<S590>/Switch' incorporates:
           *  Constant: '<S590>/Constant'
           *  Product: '<S590>/Product'
           *  Sum: '<S523>/Sum'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_or;
            rtb_Switch_f_idx_1 = rtb_Sign5_mn;
            rtb_Switch_f_idx_2 = rtb_Saturation_d;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S590>/Switch' */

          /* Product: '<S633>/Divide' */
          rtb_P_cg[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_P_cg[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S636>/Sum of Elements' incorporates:
           *  Math: '<S636>/Math Function'
           *  SignalConversion: '<S636>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_hc = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

          /* Math: '<S636>/Math Function1' incorporates:
           *  Sum: '<S636>/Sum of Elements'
           *
           * About '<S636>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_Saturation_d = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S636>/Math Function1' */

          /* Switch: '<S636>/Switch' incorporates:
           *  Constant: '<S636>/Constant'
           *  Product: '<S636>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_ov[0] = rtb_P_cg[1];
            rtb_Switch_ov[1] = rtb_P_cg[0];
            rtb_Switch_ov[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S636>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S595>/NearbyRefWP' incorporates:
           *  Constant: '<S523>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_cg, &rtb_a_bx);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* MATLAB Function: '<S595>/SearchL1RefWP' incorporates:
           *  Constant: '<S523>/L1'
           *  Delay: '<S575>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_hc = rtb_Sign5_mn * rtb_Sign5_mn + rtb_Divide_or *
            rtb_Divide_or;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Saturation1_d = (rtb_Sign5_mn * (FMS_DW.Delay_DSTATE_nc[0] -
            FMS_U.INS_Out.x_R) + rtb_Divide_or * (FMS_DW.Delay_DSTATE_nc[1] -
            FMS_U.INS_Out.y_R)) * 2.0F;
          rtb_Subtract3_d = rtb_Saturation1_d * rtb_Saturation1_d -
            (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R *
                 FMS_U.INS_Out.y_R) + FMS_DW.Delay_DSTATE_nc[0] *
                FMS_DW.Delay_DSTATE_nc[0]) + FMS_DW.Delay_DSTATE_nc[1] *
               FMS_DW.Delay_DSTATE_nc[1]) - (FMS_U.INS_Out.x_R *
               FMS_DW.Delay_DSTATE_nc[0] + FMS_U.INS_Out.y_R *
               FMS_DW.Delay_DSTATE_nc[1]) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1)
            * (4.0F * rtb_Saturation1_hc);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Saturation_d = -1.0F;
          rtb_Square_h[0] = 0.0F;
          rtb_Square_h[1] = 0.0F;
          guard1 = false;
          if (rtb_Subtract3_d > 0.0F) {
            rtb_u = sqrtf(rtb_Subtract3_d);
            rtb_Subtract3_d = (-rtb_Saturation1_d + rtb_u) / (2.0F *
              rtb_Saturation1_hc);
            rtb_Saturation1_d = (-rtb_Saturation1_d - rtb_u) / (2.0F *
              rtb_Saturation1_hc);
            if ((rtb_Subtract3_d >= 0.0F) && (rtb_Subtract3_d <= 1.0F) &&
                (rtb_Saturation1_d >= 0.0F) && (rtb_Saturation1_d <= 1.0F)) {
              rtb_Saturation_d = fmaxf(rtb_Subtract3_d, rtb_Saturation1_d);
              guard1 = true;
            } else if ((rtb_Subtract3_d >= 0.0F) && (rtb_Subtract3_d <= 1.0F)) {
              rtb_Saturation_d = rtb_Subtract3_d;
              guard1 = true;
            } else {
              if ((rtb_Saturation1_d >= 0.0F) && (rtb_Saturation1_d <= 1.0F)) {
                rtb_Saturation_d = rtb_Saturation1_d;
                guard1 = true;
              }
            }
          } else {
            if (rtb_Subtract3_d == 0.0F) {
              rtb_Subtract3_d = -rtb_Saturation1_d / (2.0F * rtb_Saturation1_hc);
              if ((rtb_Subtract3_d >= 0.0F) && (rtb_Subtract3_d <= 1.0F)) {
                rtb_Saturation_d = rtb_Subtract3_d;
                guard1 = true;
              }
            }
          }

          if (guard1) {
            rtb_Square_h[0] = rtb_Sign5_mn * rtb_Saturation_d +
              FMS_DW.Delay_DSTATE_nc[0];
            rtb_Square_h[1] = rtb_Divide_or * rtb_Saturation_d +
              FMS_DW.Delay_DSTATE_nc[1];
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S595>/OutRegionRegWP' incorporates:
           *  Delay: '<S575>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_nc[1]) *
                               rtb_Divide_or + (FMS_U.INS_Out.x_R -
            FMS_DW.Delay_DSTATE_nc[0]) * rtb_Sign5_mn) / (rtb_Sign5_mn *
            rtb_Sign5_mn + rtb_Divide_or * rtb_Divide_or);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_Saturation1_d <= 0.0F);
          rtb_LogicalOperator_fl = (rtb_Saturation1_d >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_hc = FMS_DW.Delay_DSTATE_nc[0];
          } else if (rtb_LogicalOperator_fl) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation1_hc = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            rtb_Saturation1_hc = rtb_Saturation1_d * rtb_Sign5_mn +
              FMS_DW.Delay_DSTATE_nc[0];
          }

          /* Switch: '<S595>/Switch1' incorporates:
           *  Constant: '<S626>/Constant'
           *  RelationalOperator: '<S626>/Compare'
           */
          if (rtb_a_bx <= 0.0F) {
            /* Switch: '<S595>/Switch' incorporates:
             *  Constant: '<S625>/Constant'
             *  MATLAB Function: '<S595>/SearchL1RefWP'
             *  RelationalOperator: '<S625>/Compare'
             */
            if (rtb_Saturation_d >= 0.0F) {
              rtb_P_cg[0] = rtb_Square_h[0];
              rtb_P_cg[1] = rtb_Square_h[1];
            } else {
              rtb_P_cg[0] = rtb_Saturation1_hc;

              /* MATLAB Function: '<S595>/OutRegionRegWP' incorporates:
               *  Delay: '<S575>/Delay'
               *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_P_cg[1] = FMS_DW.Delay_DSTATE_nc[1];
              } else if (rtb_LogicalOperator_fl) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_P_cg[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              } else {
                rtb_P_cg[1] = rtb_Saturation1_d * rtb_Divide_or +
                  FMS_DW.Delay_DSTATE_nc[1];
              }
            }

            /* End of Switch: '<S595>/Switch' */
          }

          /* End of Switch: '<S595>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S596>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_d = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S634>/Math Function' */
          rtb_Divide_n4[0] = rtb_Saturation1_d * rtb_Saturation1_d;
          rtb_P_cg[0] = rtb_Saturation1_d;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S596>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_d = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S634>/Math Function' incorporates:
           *  Math: '<S632>/Square'
           */
          rtb_Saturation1_hc = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S634>/Sum of Elements' incorporates:
           *  Math: '<S634>/Math Function'
           */
          rtb_a_bx = rtb_Saturation1_hc + rtb_Divide_n4[0];

          /* Math: '<S634>/Math Function1' incorporates:
           *  Sum: '<S634>/Sum of Elements'
           *
           * About '<S634>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_d = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S634>/Math Function1' */

          /* Switch: '<S634>/Switch' incorporates:
           *  Constant: '<S634>/Constant'
           *  Product: '<S634>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_P_cg[0];
            rtb_Switch_d0[1] = rtb_Saturation1_d;
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S634>/Switch' */

          /* Product: '<S634>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S637>/Sum of Elements' incorporates:
           *  Math: '<S637>/Math Function'
           *  SignalConversion: '<S637>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S637>/Math Function1' incorporates:
           *  Sum: '<S637>/Sum of Elements'
           *
           * About '<S637>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_d = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_d = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S637>/Math Function1' */

          /* Switch: '<S637>/Switch' incorporates:
           *  Constant: '<S637>/Constant'
           *  Product: '<S637>/Product'
           */
          if (rtb_Saturation_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Saturation_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S637>/Switch' */

          /* Product: '<S637>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Math: '<S632>/Square' */
          rtb_P_dg[0] = rtb_P_cg[0] * rtb_P_cg[0];

          /* Product: '<S590>/Divide' */
          rtb_Square_h[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_P_cg[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S637>/Divide' incorporates:
           *  Product: '<S636>/Divide'
           */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S636>/Divide' */
          rtb_Saturation1_d = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S590>/Divide' */
          rtb_Square_h[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S631>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S631>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S631>/Sum of Elements'
           */
          rtb_Saturation_d = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S596>/Gain' incorporates:
           *  Math: '<S596>/Square'
           */
          rtb_Switch_f_idx_0 = rtb_Saturation_d * rtb_Saturation_d * 2.0F;

          /* Sum: '<S635>/Subtract' incorporates:
           *  Product: '<S635>/Multiply'
           *  Product: '<S635>/Multiply1'
           */
          rtb_Saturation_d = rtb_Divide_n4[0] * rtb_Saturation1_d -
            rtb_Divide_n4[1] * rtb_P_cg[0];

          /* Signum: '<S630>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S630>/Sign1' */

          /* Switch: '<S630>/Switch2' incorporates:
           *  Constant: '<S630>/Constant4'
           */
          if (rtb_Saturation_d == 0.0F) {
            rtb_Saturation_d = 1.0F;
          }

          /* End of Switch: '<S630>/Switch2' */

          /* DotProduct: '<S630>/Dot Product' */
          rtb_Saturation1_d = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_Saturation1_d
            * rtb_Divide_n4[1];

          /* Trigonometry: '<S630>/Acos' incorporates:
           *  DotProduct: '<S630>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S630>/Multiply' incorporates:
           *  Trigonometry: '<S630>/Acos'
           */
          rtb_Saturation_d *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S596>/Saturation' */
          if (rtb_Saturation_d > 1.57079637F) {
            rtb_Saturation_d = 1.57079637F;
          } else {
            if (rtb_Saturation_d < -1.57079637F) {
              rtb_Saturation_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S596>/Saturation' */

          /* Product: '<S596>/Divide' incorporates:
           *  Constant: '<S523>/L1'
           *  Constant: '<S596>/Constant'
           *  MinMax: '<S596>/Max'
           *  MinMax: '<S596>/Min'
           *  Product: '<S596>/Multiply1'
           *  Sqrt: '<S632>/Sqrt'
           *  Sum: '<S632>/Sum of Elements'
           *  Trigonometry: '<S596>/Sin'
           */
          rtb_Saturation1_hc = arm_sin_f32(rtb_Saturation_d) *
            rtb_Switch_f_idx_0 / fminf(FMS_PARAM.L1, fmaxf(sqrtf
            (rtb_Saturation1_hc + rtb_P_dg[0]), 0.5F));

          /* Sum: '<S588>/Subtract' incorporates:
           *  Product: '<S588>/Multiply'
           *  Product: '<S588>/Multiply1'
           */
          rtb_Switch_f_idx_2 = rtb_Square_h[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_h[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S577>/Sign1' */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_2 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S577>/Sign1' */

          /* Switch: '<S577>/Switch2' incorporates:
           *  Constant: '<S577>/Constant4'
           */
          if (rtb_Switch_f_idx_2 == 0.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S577>/Switch2' */

          /* DotProduct: '<S577>/Dot Product' */
          rtb_Switch_f_idx_1 = FMS_ConstB.Divide_m[0] * rtb_Square_h[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_h[1];

          /* Trigonometry: '<S577>/Acos' incorporates:
           *  DotProduct: '<S577>/Dot Product'
           */
          if (rtb_Switch_f_idx_1 > 1.0F) {
            rtb_Switch_f_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_1 < -1.0F) {
              rtb_Switch_f_idx_1 = -1.0F;
            }
          }

          /* Product: '<S577>/Multiply' incorporates:
           *  Trigonometry: '<S577>/Acos'
           */
          rtb_Switch_f_idx_2 *= acosf(rtb_Switch_f_idx_1);

          /* Math: '<S580>/Rem' incorporates:
           *  Constant: '<S580>/Constant1'
           *  Delay: '<S576>/Delay'
           *  Sum: '<S576>/Sum2'
           */
          rtb_Saturation_d = rt_remf(rtb_Switch_f_idx_2 - FMS_DW.Delay_DSTATE_nx,
            6.28318548F);

          /* Switch: '<S580>/Switch' incorporates:
           *  Abs: '<S580>/Abs'
           *  Constant: '<S580>/Constant'
           *  Constant: '<S586>/Constant'
           *  Product: '<S580>/Multiply'
           *  RelationalOperator: '<S586>/Compare'
           *  Sum: '<S580>/Add'
           */
          if (fabsf(rtb_Saturation_d) > 3.14159274F) {
            /* Signum: '<S580>/Sign' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_d;
            }

            /* End of Signum: '<S580>/Sign' */
            rtb_Saturation_d -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S580>/Switch' */

          /* Sum: '<S576>/Sum' incorporates:
           *  Delay: '<S576>/Delay'
           */
          rtb_Saturation1_d = rtb_Saturation_d + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S585>/Multiply1' incorporates:
           *  Constant: '<S585>/const1'
           *  DiscreteIntegrator: '<S579>/Integrator'
           */
          rtb_Saturation_d = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S585>/Add' incorporates:
           *  DiscreteIntegrator: '<S579>/Integrator1'
           *  Sum: '<S579>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation1_d)
            + rtb_Saturation_d;

          /* Signum: '<S585>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S585>/Sign' */

          /* Sum: '<S585>/Add2' incorporates:
           *  Abs: '<S585>/Abs'
           *  Gain: '<S585>/Gain'
           *  Gain: '<S585>/Gain1'
           *  Product: '<S585>/Multiply2'
           *  Product: '<S585>/Multiply3'
           *  Sqrt: '<S585>/Sqrt'
           *  Sum: '<S585>/Add1'
           *  Sum: '<S585>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_n) *
                            FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Switch_f_idx_0 + rtb_Saturation_d;

          /* Sum: '<S585>/Add4' */
          rtb_Switch_f_idx_0 = (rtb_Saturation1_d - rtb_a_bx) + rtb_Saturation_d;

          /* Sum: '<S585>/Add3' */
          rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_n;

          /* Sum: '<S585>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_n;

          /* Signum: '<S585>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S585>/Sign1' */

          /* Signum: '<S585>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S585>/Sign2' */

          /* Sum: '<S585>/Add5' incorporates:
           *  Gain: '<S585>/Gain2'
           *  Product: '<S585>/Multiply4'
           *  Sum: '<S585>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
            rtb_Switch_f_idx_0;

          /* Sum: '<S585>/Add6' */
          rtb_Saturation_d = rtb_a_bx + FMS_ConstB.d_n;

          /* Sum: '<S585>/Subtract3' */
          rtb_Saturation1_d = rtb_a_bx - FMS_ConstB.d_n;

          /* Product: '<S585>/Divide' */
          rtb_Divide_or = rtb_a_bx / FMS_ConstB.d_n;

          /* Signum: '<S585>/Sign5' incorporates:
           *  Signum: '<S585>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S585>/Sign6' */
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S585>/Sign6' */
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_a_bx;

            /* Signum: '<S585>/Sign6' */
            rtb_Switch_f_idx_0 = rtb_a_bx;
          }

          /* End of Signum: '<S585>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S576>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Switch_f_idx_2 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S581>/Rem' incorporates:
           *  Constant: '<S581>/Constant1'
           */
          rtb_a_bx = rt_remf(rtb_Switch_f_idx_2, 6.28318548F);

          /* Switch: '<S581>/Switch' incorporates:
           *  Abs: '<S581>/Abs'
           *  Constant: '<S581>/Constant'
           *  Constant: '<S587>/Constant'
           *  Product: '<S581>/Multiply'
           *  RelationalOperator: '<S587>/Compare'
           *  Sum: '<S581>/Add'
           */
          if (fabsf(rtb_a_bx) > 3.14159274F) {
            /* Signum: '<S581>/Sign' */
            if (rtb_a_bx < 0.0F) {
              rtb_Switch_f_idx_1 = -1.0F;
            } else if (rtb_a_bx > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            } else {
              rtb_Switch_f_idx_1 = rtb_a_bx;
            }

            /* End of Signum: '<S581>/Sign' */
            rtb_a_bx -= 6.28318548F * rtb_Switch_f_idx_1;
          }

          /* End of Switch: '<S581>/Switch' */

          /* Abs: '<S574>/Abs' */
          rtb_a_bx = fabsf(rtb_a_bx);

          /* Update for Delay: '<S597>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S598>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S591>/Constant'
           *  RelationalOperator: '<S591>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_a = (uint8_T)((uint32_T)(rtb_a_bx
            <= 0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_a);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S598>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S593>/Acceleration_Speed' incorporates:
           *  Constant: '<S593>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S593>/Acceleration_Speed' */

          /* Product: '<S597>/Divide1' incorporates:
           *  Constant: '<S597>/Constant'
           */
          rtb_Switch_f_idx_1 = rtb_Saturation1_hc / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S597>/Saturation' */
          if (rtb_Switch_f_idx_1 > 0.314159274F) {
            rtb_Switch_f_idx_1 = 0.314159274F;
          } else {
            if (rtb_Switch_f_idx_1 < -0.314159274F) {
              rtb_Switch_f_idx_1 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S597>/Saturation' */

          /* Update for DiscreteIntegrator: '<S639>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_Switch_f_idx_1;

          /* Update for Delay: '<S576>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S579>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S579>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Update for Delay: '<S575>/Delay' */
          FMS_DW.icLoad_f = 0U;

          /* Signum: '<S585>/Sign3' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S585>/Sign3' */

          /* Signum: '<S585>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S585>/Sign4' */

          /* Update for DiscreteIntegrator: '<S579>/Integrator' incorporates:
           *  Constant: '<S585>/const'
           *  Gain: '<S585>/Gain3'
           *  Product: '<S585>/Multiply5'
           *  Product: '<S585>/Multiply6'
           *  Sum: '<S585>/Subtract4'
           *  Sum: '<S585>/Subtract5'
           *  Sum: '<S585>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_d * ((rtb_Saturation_d - rtb_Saturation1_d) * 0.5F)
            - rtb_Switch_f_idx_0 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S579>/Integrator' */
          /* End of Outputs for SubSystem: '<S227>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S227>/Hold' incorporates:
             *  ActionPort: '<S521>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S227>/Switch Case' incorporates:
             *  Chart: '<S530>/Motion Status'
             *  Chart: '<S540>/Motion State'
             *  Chart: '<S552>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S227>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S227>/Hold' incorporates:
           *  ActionPort: '<S521>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S530>/Motion Status' incorporates:
           *  Abs: '<S530>/Abs'
           *  Constant: '<S530>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Chart: '<S540>/Motion State' incorporates:
           *  Abs: '<S540>/Abs'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.temporalCounter_i1_i < 255U) {
            FMS_DW.temporalCounter_i1_i++;
          }

          if (FMS_DW.is_active_c15_FMS == 0U) {
            FMS_DW.is_active_c15_FMS = 1U;
            FMS_DW.is_c15_FMS = FMS_IN_Move_p;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c15_FMS) {
             case FMS_IN_Brake_bw:
              rtb_state_fg = MotionState_Brake;

              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              if ((fabsf(FMS_U.INS_Out.r) <= 0.1) ||
                  (FMS_DW.temporalCounter_i1_i >= 250U)) {
                FMS_DW.is_c15_FMS = FMS_IN_Hold_od;
                rtb_state_fg = MotionState_Hold;
              }

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              break;

             case FMS_IN_Hold_od:
              rtb_state_fg = MotionState_Hold;
              break;

             default:
              FMS_DW.is_c15_FMS = FMS_IN_Brake_bw;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_fg = MotionState_Brake;
              break;
            }
          }

          /* End of Chart: '<S540>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S552>/Motion State' incorporates:
           *  Constant: '<S552>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S552>/Square'
           *  Math: '<S552>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S552>/Sqrt'
           *  Sum: '<S552>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S551>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S551>/Hold Control' incorporates:
               *  ActionPort: '<S554>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S551>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S551>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S551>/Hold Control' incorporates:
             *  ActionPort: '<S554>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S551>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S551>/Brake Control' incorporates:
             *  ActionPort: '<S553>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S551>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S551>/Move Control' incorporates:
               *  ActionPort: '<S555>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S551>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S551>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S551>/Move Control' incorporates:
             *  ActionPort: '<S555>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S551>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S551>/Switch Case' */

          /* SwitchCase: '<S529>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S529>/Hold Control' incorporates:
               *  ActionPort: '<S532>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S529>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S529>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S529>/Hold Control' incorporates:
             *  ActionPort: '<S532>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S529>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S529>/Brake Control' incorporates:
             *  ActionPort: '<S531>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S529>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S529>/Move Control' incorporates:
               *  ActionPort: '<S533>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S529>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S529>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S529>/Move Control' incorporates:
             *  ActionPort: '<S533>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S529>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S529>/Switch Case' */

          /* SwitchCase: '<S539>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_cv;
          FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
          switch (rtb_state_fg) {
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
              /* SystemReset for IfAction SubSystem: '<S539>/Hold Control' incorporates:
               *  ActionPort: '<S542>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S539>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S539>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S539>/Hold Control' incorporates:
             *  ActionPort: '<S542>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S539>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S539>/Brake Control' incorporates:
             *  ActionPort: '<S541>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S539>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_cv != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S539>/Move Control' incorporates:
               *  ActionPort: '<S543>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S539>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S539>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S539>/Move Control' incorporates:
             *  ActionPort: '<S543>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S539>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S539>/Switch Case' */

          /* BusAssignment: '<S521>/Bus Assignment' incorporates:
           *  Constant: '<S521>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;

          /* Saturate: '<S539>/Saturation' */
          if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;
          }

          /* End of Saturate: '<S539>/Saturation' */

          /* Saturate: '<S551>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S551>/Saturation1' */

          /* Saturate: '<S529>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S521>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S529>/Saturation1' */
          /* End of Outputs for SubSystem: '<S227>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S227>/Unknown' incorporates:
           *  ActionPort: '<S525>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S227>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S227>/Switch Case' */
        /* End of Outputs for SubSystem: '<S37>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S37>/Auto' incorporates:
         *  ActionPort: '<S225>/Action Port'
         */
        /* SwitchCase: '<S225>/Switch Case' incorporates:
         *  Math: '<S405>/Square'
         *  Sum: '<S366>/Subtract'
         *  Sum: '<S420>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S337>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S375>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* End of Disable for SubSystem: '<S337>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S225>/Offboard' incorporates:
           *  ActionPort: '<S338>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S499>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Multiply_l_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S502>/deg2rad' */
          rtb_Switch1_l4 = 0.017453292519943295 * rtb_Multiply_l_idx_0;

          /* Trigonometry: '<S503>/Sin' */
          rtb_Gain = sin(rtb_Switch1_l4);

          /* Math: '<S503>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S503>/Multiply1' incorporates:
           *  Product: '<S503>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S503>/Divide' incorporates:
           *  Constant: '<S503>/Constant'
           *  Constant: '<S503>/R'
           *  Sqrt: '<S503>/Sqrt'
           *  Sum: '<S503>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S503>/Product3' incorporates:
           *  Constant: '<S503>/Constant1'
           *  Product: '<S503>/Multiply1'
           *  Sum: '<S503>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S503>/Multiply2' incorporates:
           *  Trigonometry: '<S503>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_l4);

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S502>/Sum' incorporates:
           *  Gain: '<S499>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          rtb_Multiply_l_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l_idx_0;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Abs: '<S507>/Abs' incorporates:
           *  Abs: '<S510>/Abs1'
           *  Switch: '<S507>/Switch1'
           */
          rtb_Switch1_l4 = fabs(rtb_Multiply_l_idx_0);

          /* Switch: '<S507>/Switch1' incorporates:
           *  Abs: '<S507>/Abs'
           *  Bias: '<S507>/Bias2'
           *  Bias: '<S507>/Bias3'
           *  Constant: '<S504>/Constant'
           *  Constant: '<S504>/Constant1'
           *  Constant: '<S509>/Constant'
           *  Gain: '<S507>/Gain1'
           *  Product: '<S507>/Multiply'
           *  RelationalOperator: '<S509>/Compare'
           *  Switch: '<S504>/Switch'
           */
          if (rtb_Switch1_l4 > 90.0) {
            /* Switch: '<S510>/Switch1' incorporates:
             *  Bias: '<S510>/Bias2'
             *  Bias: '<S510>/Bias3'
             *  Constant: '<S510>/Constant'
             *  Constant: '<S511>/Constant'
             *  Math: '<S510>/Math Function'
             *  RelationalOperator: '<S511>/Compare'
             */
            if (rtb_Switch1_l4 > 180.0) {
              rtb_Multiply_l_idx_0 = rt_modd(rtb_Multiply_l_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S510>/Switch1' */

            /* Signum: '<S507>/Sign' */
            if (rtb_Multiply_l_idx_0 < 0.0) {
              rtb_Multiply_l_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_l_idx_0 > 0.0) {
                rtb_Multiply_l_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S507>/Sign' */
            rtb_Multiply_l_idx_0 *= -(rtb_Switch1_l4 + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S504>/Sum' incorporates:
           *  Gain: '<S499>/Gain1'
           *  Gain: '<S499>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S502>/Sum'
           */
          rtb_Switch1_l4 = (1.0000000000287557E-7 * (real_T)
                            FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                            FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S502>/Multiply' incorporates:
           *  Gain: '<S502>/deg2rad1'
           */
          rtb_Multiply_l_idx_0 = 0.017453292519943295 * rtb_Multiply_l_idx_0 *
            rtb_Sum3;

          /* Switch: '<S506>/Switch1' incorporates:
           *  Abs: '<S506>/Abs1'
           *  Bias: '<S506>/Bias2'
           *  Bias: '<S506>/Bias3'
           *  Constant: '<S506>/Constant'
           *  Constant: '<S508>/Constant'
           *  Math: '<S506>/Math Function'
           *  RelationalOperator: '<S508>/Compare'
           */
          if (fabs(rtb_Switch1_l4) > 180.0) {
            rtb_Switch1_l4 = rt_modd(rtb_Switch1_l4 + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S506>/Switch1' */

          /* Product: '<S502>/Multiply' incorporates:
           *  Gain: '<S502>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_l4;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MultiPortSwitch: '<S480>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S484>/Multiply1'
           *  Product: '<S485>/Multiply3'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S493>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S493>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Trigonometry: '<S493>/Trigonometric Function3' incorporates:
             *  Gain: '<S492>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S493>/Gain' incorporates:
             *  Gain: '<S492>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S493>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S493>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S493>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S493>/Trigonometric Function' incorporates:
             *  Gain: '<S492>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S493>/Trigonometric Function1' incorporates:
             *  Gain: '<S492>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S493>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_e[0];

            /* Saturate: '<S484>/Saturation' incorporates:
             *  Constant: '<S490>/Constant'
             *  Constant: '<S491>/Constant'
             *  Constant: '<S501>/Constant'
             *  DataTypeConversion: '<S499>/Data Type Conversion1'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S483>/Logical Operator'
             *  Product: '<S484>/Multiply'
             *  Product: '<S505>/Multiply1'
             *  Product: '<S505>/Multiply2'
             *  RelationalOperator: '<S490>/Compare'
             *  RelationalOperator: '<S491>/Compare'
             *  RelationalOperator: '<S501>/Compare'
             *  S-Function (sfix_bitop): '<S483>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S498>/lat_cmd valid'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S484>/Sum1'
             *  Sum: '<S505>/Sum2'
             *  Switch: '<S486>/Switch'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_Saturation1_hc = (real32_T)(rtb_Multiply_l_idx_0 *
                FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation1_hc = FMS_U.Auto_Cmd.x_cmd;
            }

            rtb_Switch_f_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation1_hc -
              FMS_U.INS_Out.x_R : 0.0F;
            if (rtb_Switch_f_idx_1 > 4.0F) {
              rtb_Switch_f_idx_1 = 4.0F;
            } else {
              if (rtb_Switch_f_idx_1 < -4.0F) {
                rtb_Switch_f_idx_1 = -4.0F;
              }
            }

            /* SignalConversion: '<S493>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_e[1];

            /* Saturate: '<S484>/Saturation' incorporates:
             *  Constant: '<S490>/Constant'
             *  Constant: '<S491>/Constant'
             *  Constant: '<S501>/Constant'
             *  DataTypeConversion: '<S499>/Data Type Conversion1'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S483>/Logical Operator'
             *  Product: '<S484>/Multiply'
             *  Product: '<S505>/Multiply3'
             *  Product: '<S505>/Multiply4'
             *  RelationalOperator: '<S490>/Compare'
             *  RelationalOperator: '<S491>/Compare'
             *  RelationalOperator: '<S501>/Compare'
             *  S-Function (sfix_bitop): '<S483>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S498>/lon_cmd valid'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S484>/Sum1'
             *  Sum: '<S505>/Sum3'
             *  Switch: '<S486>/Switch'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_Saturation1_hc = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation1_hc = FMS_U.Auto_Cmd.y_cmd;
            }

            rtb_Saturation_d = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation1_hc -
              FMS_U.INS_Out.y_R : 0.0F;
            if (rtb_Saturation_d > 4.0F) {
              rtb_Saturation_d = 4.0F;
            } else {
              if (rtb_Saturation_d < -4.0F) {
                rtb_Saturation_d = -4.0F;
              }
            }

            /* SignalConversion: '<S493>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_e[2];

            /* Saturate: '<S484>/Saturation' incorporates:
             *  Constant: '<S490>/Constant'
             *  Constant: '<S491>/Constant'
             *  Constant: '<S501>/Constant'
             *  DataTypeConversion: '<S499>/Data Type Conversion'
             *  DataTypeConversion: '<S499>/Data Type Conversion1'
             *  Gain: '<S487>/Gain'
             *  Gain: '<S499>/Gain2'
             *  Gain: '<S502>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S483>/Logical Operator'
             *  Product: '<S484>/Multiply'
             *  RelationalOperator: '<S490>/Compare'
             *  RelationalOperator: '<S491>/Compare'
             *  RelationalOperator: '<S501>/Compare'
             *  S-Function (sfix_bitop): '<S483>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/z_cmd valid'
             *  S-Function (sfix_bitop): '<S498>/alt_cmd valid'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S484>/Sum1'
             *  Sum: '<S502>/Sum1'
             *  Switch: '<S486>/Switch'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_Saturation1_hc = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                -FMS_U.INS_Out.alt_0);
            } else {
              rtb_Saturation1_hc = FMS_U.Auto_Cmd.z_cmd;
            }

            rtb_Saturation1_d = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation1_hc -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Saturation1_d > 2.0F) {
              rtb_Saturation1_d = 2.0F;
            } else {
              if (rtb_Saturation1_d < -2.0F) {
                rtb_Saturation1_d = -2.0F;
              }
            }

            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 6] *
                rtb_Saturation1_d + (rtb_VectorConcatenate_pc[rtb_n + 3] *
                rtb_Saturation_d + rtb_VectorConcatenate_pc[rtb_n] *
                rtb_Switch_f_idx_1);
            }

            /* SignalConversion: '<S427>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S427>/Constant4'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  Product: '<S484>/Multiply1'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Trigonometry: '<S427>/Trigonometric Function3' incorporates:
             *  Gain: '<S426>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S427>/Gain' incorporates:
             *  Gain: '<S426>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S427>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S427>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S427>/Constant3'
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S427>/Trigonometric Function' incorporates:
             *  Gain: '<S426>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S427>/Trigonometric Function1' incorporates:
             *  Gain: '<S426>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S427>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_l[0];

            /* Product: '<S417>/Multiply' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/ax_cmd valid'
             */
            rtb_Saturation1_d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S427>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_l[1];

            /* Product: '<S417>/Multiply' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/ay_cmd valid'
             */
            rtb_Saturation1_hc = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S427>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_l[2];

            /* Product: '<S417>/Multiply' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/az_cmd valid'
             */
            rtb_a_bx = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S417>/Index Vector' incorporates:
             *  Product: '<S423>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 6] *
                rtb_a_bx + (rtb_VectorConcatenate_pc[rtb_n + 3] *
                            rtb_Saturation1_hc + rtb_VectorConcatenate_pc[rtb_n]
                            * rtb_Saturation1_d);
            }
            break;

           case 1:
            /* SignalConversion: '<S497>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S497>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Gain: '<S495>/Gain' incorporates:
             *  Gain: '<S428>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S485>/Subtract'
             */
            rtb_Saturation_d = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

            /* Trigonometry: '<S497>/Trigonometric Function3' incorporates:
             *  Gain: '<S495>/Gain'
             *  Trigonometry: '<S497>/Trigonometric Function1'
             */
            rtb_Saturation1_hc = arm_cos_f32(rtb_Saturation_d);
            rtb_VectorConcatenate_pc[4] = rtb_Saturation1_hc;

            /* Trigonometry: '<S497>/Trigonometric Function2' incorporates:
             *  Gain: '<S495>/Gain'
             *  Trigonometry: '<S497>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation_d);

            /* Gain: '<S497>/Gain' incorporates:
             *  Trigonometry: '<S497>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S497>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S497>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S497>/Trigonometric Function' */
            rtb_VectorConcatenate_pc[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S497>/Trigonometric Function1' */
            rtb_VectorConcatenate_pc[0] = rtb_Saturation1_hc;

            /* SignalConversion: '<S497>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_n[0];

            /* SignalConversion: '<S496>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_p[0];

            /* SignalConversion: '<S497>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_n[1];

            /* SignalConversion: '<S496>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_p[1];

            /* SignalConversion: '<S497>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_n[2];

            /* SignalConversion: '<S496>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_p[2];

            /* SignalConversion: '<S496>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S496>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S496>/Trigonometric Function3' incorporates:
             *  Gain: '<S494>/Gain'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Trigonometry: '<S496>/Trigonometric Function1'
             */
            rtb_Saturation1_d = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
            rtb_Transpose[4] = rtb_Saturation1_d;

            /* Trigonometry: '<S496>/Trigonometric Function2' incorporates:
             *  Gain: '<S494>/Gain'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Trigonometry: '<S496>/Trigonometric Function'
             */
            rtb_Saturation1_hc = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

            /* Gain: '<S496>/Gain' incorporates:
             *  Trigonometry: '<S496>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -rtb_Saturation1_hc;

            /* SignalConversion: '<S496>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S496>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S496>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Saturation1_hc;

            /* Trigonometry: '<S496>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_Saturation1_d;

            /* RelationalOperator: '<S501>/Compare' incorporates:
             *  Constant: '<S501>/Constant'
             *  S-Function (sfix_bitop): '<S498>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S498>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S498>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S499>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S499>/Data Type Conversion'
             *  Gain: '<S499>/Gain2'
             *  Gain: '<S502>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S505>/Multiply1'
             *  Product: '<S505>/Multiply2'
             *  Product: '<S505>/Multiply3'
             *  Product: '<S505>/Multiply4'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S502>/Sum1'
             *  Sum: '<S505>/Sum2'
             *  Sum: '<S505>/Sum3'
             */
            rtb_VectorConcatenate_g0[0] = (real32_T)(rtb_Multiply_l_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_g0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_g0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S486>/Switch' */
            tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
            tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
            tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* RelationalOperator: '<S490>/Compare' incorporates:
             *  Constant: '<S490>/Constant'
             *  S-Function (sfix_bitop): '<S483>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/z_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S491>/Compare' incorporates:
             *  Constant: '<S491>/Constant'
             *  S-Function (sfix_bitop): '<S483>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/lon_cmd valid'
             */
            tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S485>/Sum2' incorporates:
               *  Product: '<S485>/Multiply2'
               *  Switch: '<S486>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation1_hc = rtb_VectorConcatenate_g0[rtb_n];
              } else {
                rtb_Saturation1_hc = tmp_0[rtb_n];
              }

              /* Saturate: '<S485>/Saturation1' incorporates:
               *  Gain: '<S487>/Gain'
               *  Inport: '<Root>/INS_Out'
               *  Logic: '<S483>/Logical Operator'
               *  Product: '<S485>/Multiply'
               *  Product: '<S485>/Multiply2'
               *  SignalConversion: '<S30>/Signal Copy1'
               *  Sum: '<S485>/Sum2'
               */
              rtb_Switch_f_idx_1 = tmp_1[rtb_n] || tmp_2[rtb_n] ?
                rtb_Saturation1_hc - ((rtb_Transpose[rtb_n + 3] *
                FMS_U.INS_Out.y_R + rtb_Transpose[rtb_n] * FMS_U.INS_Out.x_R) +
                rtb_Transpose[rtb_n + 6] * -FMS_U.INS_Out.h_R) : 0.0F;
              if (rtb_Switch_f_idx_1 > FMS_ConstP.pooled53[rtb_n]) {
                rtb_Switch_ov[rtb_n] = FMS_ConstP.pooled53[rtb_n];
              } else if (rtb_Switch_f_idx_1 < FMS_ConstP.pooled54[rtb_n]) {
                rtb_Switch_ov[rtb_n] = FMS_ConstP.pooled54[rtb_n];
              } else {
                rtb_Switch_ov[rtb_n] = rtb_Switch_f_idx_1;
              }

              /* End of Saturate: '<S485>/Saturation1' */
            }

            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 6] *
                rtb_Switch_ov[2] + (rtb_VectorConcatenate_pc[rtb_n + 3] *
                                    rtb_Switch_ov[1] +
                                    rtb_VectorConcatenate_pc[rtb_n] *
                                    rtb_Switch_ov[0]);
            }

            /* SignalConversion: '<S429>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S429>/Constant4'
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  Product: '<S485>/Multiply3'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Trigonometry: '<S429>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(rtb_Saturation_d);

            /* Gain: '<S429>/Gain' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             *  Trigonometry: '<S429>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(rtb_Saturation_d);

            /* SignalConversion: '<S429>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S429>/Constant3'
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S429>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(rtb_Saturation_d);

            /* Trigonometry: '<S429>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(rtb_Saturation_d);

            /* SignalConversion: '<S429>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Product: '<S417>/Multiply' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/ax_cmd valid'
             */
            rtb_Saturation1_d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S429>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Product: '<S417>/Multiply' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/ay_cmd valid'
             */
            rtb_Saturation1_hc = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S429>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S417>/Index Vector'
             */
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Product: '<S417>/Multiply' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/az_cmd valid'
             */
            rtb_a_bx = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S417>/Index Vector' incorporates:
             *  Product: '<S424>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 6] *
                rtb_a_bx + (rtb_VectorConcatenate_pc[rtb_n + 3] *
                            rtb_Saturation1_hc + rtb_VectorConcatenate_pc[rtb_n]
                            * rtb_Saturation1_d);
            }
            break;

           default:
            /* SignalConversion: '<S489>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_a[0];
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_a[1];
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_a[2];

            /* SignalConversion: '<S489>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S489>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Trigonometry: '<S489>/Trigonometric Function3' incorporates:
             *  Gain: '<S488>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S489>/Gain' incorporates:
             *  Gain: '<S488>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S489>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S489>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S489>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S489>/Trigonometric Function' incorporates:
             *  Gain: '<S488>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S489>/Trigonometric Function1' incorporates:
             *  Gain: '<S488>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S498>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S483>/lat_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S501>/Compare' incorporates:
             *  Constant: '<S501>/Constant'
             *  S-Function (sfix_bitop): '<S498>/lat_cmd valid'
             */
            tmp[0] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S498>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S483>/lon_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S501>/Compare' incorporates:
             *  Constant: '<S501>/Constant'
             *  S-Function (sfix_bitop): '<S498>/lon_cmd valid'
             */
            tmp[1] = (tmp_4 > 0U);

            /* S-Function (sfix_bitop): '<S498>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S483>/alt_cmd valid'
             */
            tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S501>/Compare' incorporates:
             *  Constant: '<S501>/Constant'
             *  S-Function (sfix_bitop): '<S498>/alt_cmd valid'
             */
            tmp[2] = (tmp_5 > 0U);

            /* DataTypeConversion: '<S499>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S499>/Data Type Conversion'
             *  Gain: '<S499>/Gain2'
             *  Gain: '<S502>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S505>/Multiply1'
             *  Product: '<S505>/Multiply2'
             *  Product: '<S505>/Multiply3'
             *  Product: '<S505>/Multiply4'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S502>/Sum1'
             *  Sum: '<S505>/Sum2'
             *  Sum: '<S505>/Sum3'
             */
            rtb_VectorConcatenate_g0[0] = (real32_T)(rtb_Multiply_l_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_g0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_g0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S486>/Switch' */
            tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
            tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
            tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* RelationalOperator: '<S490>/Compare' incorporates:
             *  Constant: '<S490>/Constant'
             *  S-Function (sfix_bitop): '<S483>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S483>/z_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S491>/Compare' incorporates:
             *  Constant: '<S491>/Constant'
             */
            tmp_2[0] = (tmp_3 > 0U);
            tmp_2[1] = (tmp_4 > 0U);
            tmp_2[2] = (tmp_5 > 0U);

            /* Sum: '<S482>/Sum2' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S486>/Switch' incorporates:
               *  Product: '<S482>/Multiply2'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation1_hc = rtb_VectorConcatenate_g0[rtb_n];
              } else {
                rtb_Saturation1_hc = tmp_0[rtb_n];
              }

              /* Saturate: '<S482>/Saturation1' incorporates:
               *  Gain: '<S487>/Gain'
               *  Inport: '<Root>/INS_Out'
               *  Logic: '<S483>/Logical Operator'
               *  Product: '<S482>/Multiply'
               *  Product: '<S482>/Multiply2'
               *  SignalConversion: '<S30>/Signal Copy1'
               */
              rtb_Switch_f_idx_1 = tmp_1[rtb_n] || tmp_2[rtb_n] ?
                rtb_Saturation1_hc - ((rtb_VectorConcatenate_pc[rtb_n + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_pc[rtb_n] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_pc[rtb_n + 6] *
                -FMS_U.INS_Out.h_R) : 0.0F;
              if (rtb_Switch_f_idx_1 > FMS_ConstP.pooled53[rtb_n]) {
                rtb_Switch_d0[rtb_n] = FMS_ConstP.pooled53[rtb_n];
              } else if (rtb_Switch_f_idx_1 < FMS_ConstP.pooled54[rtb_n]) {
                rtb_Switch_d0[rtb_n] = FMS_ConstP.pooled54[rtb_n];
              } else {
                rtb_Switch_d0[rtb_n] = rtb_Switch_f_idx_1;
              }

              /* End of Saturate: '<S482>/Saturation1' */
            }

            /* End of Sum: '<S482>/Sum2' */

            /* MultiPortSwitch: '<S417>/Index Vector' incorporates:
             *  Constant: '<S425>/Constant'
             *  Product: '<S417>/Multiply'
             *  RelationalOperator: '<S425>/Compare'
             *  S-Function (sfix_bitop): '<S422>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S422>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S422>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S480>/Index Vector' */

          /* Sum: '<S476>/Sum1' incorporates:
           *  Constant: '<S476>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S476>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Switch_f_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Abs: '<S477>/Abs' */
          rtb_Saturation_d = fabsf(rtb_Switch_f_idx_2);

          /* Switch: '<S477>/Switch' incorporates:
           *  Constant: '<S477>/Constant'
           *  Constant: '<S478>/Constant'
           *  Product: '<S477>/Multiply'
           *  RelationalOperator: '<S478>/Compare'
           *  Sum: '<S477>/Subtract'
           */
          if (rtb_Saturation_d > 3.14159274F) {
            /* Signum: '<S477>/Sign' */
            if (rtb_Switch_f_idx_2 < 0.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            } else {
              if (rtb_Switch_f_idx_2 > 0.0F) {
                rtb_Switch_f_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S477>/Sign' */
            rtb_Switch_f_idx_2 *= rtb_Saturation_d - 6.28318548F;
          }

          /* End of Switch: '<S477>/Switch' */

          /* Saturate: '<S476>/Saturation' */
          if (rtb_Switch_f_idx_2 > 0.314159274F) {
            rtb_Switch_f_idx_2 = 0.314159274F;
          } else {
            if (rtb_Switch_f_idx_2 < -0.314159274F) {
              rtb_Switch_f_idx_2 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S476>/Saturation' */

          /* Gain: '<S473>/Gain2' */
          rtb_Switch_f_idx_2 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S419>/Sum' incorporates:
           *  Constant: '<S475>/Constant'
           *  Constant: '<S479>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S473>/Multiply2'
           *  Product: '<S474>/Multiply1'
           *  RelationalOperator: '<S475>/Compare'
           *  RelationalOperator: '<S479>/Compare'
           *  S-Function (sfix_bitop): '<S473>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S474>/psi_rate_cmd valid'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          rtb_Switch_f_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                                rtb_Switch_f_idx_2 : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S480>/Gain1' */
          rtb_Saturation_d = FMS_PARAM.XY_P * rtb_Switch_d0[0];
          rtb_Switch_f_idx_0 = FMS_PARAM.XY_P * rtb_Switch_d0[1];

          /* Gain: '<S480>/Gain2' */
          rtb_Switch_f_idx_2 = FMS_PARAM.Z_P * rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MultiPortSwitch: '<S481>/Index Vector' incorporates:
           *  Constant: '<S516>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S481>/Multiply'
           *  Product: '<S514>/Multiply'
           *  Product: '<S515>/Multiply3'
           *  RelationalOperator: '<S516>/Compare'
           *  S-Function (sfix_bitop): '<S513>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S513>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S513>/w_cmd valid'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S518>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S518>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Trigonometry: '<S518>/Trigonometric Function3' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S518>/Gain' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S518>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S518>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S518>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S518>/Trigonometric Function' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S518>/Trigonometric Function1' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S518>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_h[0];

            /* Product: '<S481>/Multiply' incorporates:
             *  Constant: '<S516>/Constant'
             *  RelationalOperator: '<S516>/Compare'
             *  S-Function (sfix_bitop): '<S513>/u_cmd valid'
             */
            rtb_Saturation1_d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S518>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_h[1];

            /* Product: '<S481>/Multiply' incorporates:
             *  Constant: '<S516>/Constant'
             *  RelationalOperator: '<S516>/Compare'
             *  S-Function (sfix_bitop): '<S513>/v_cmd valid'
             */
            rtb_Saturation1_hc = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S518>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_h[2];

            /* Product: '<S481>/Multiply' incorporates:
             *  Constant: '<S516>/Constant'
             *  RelationalOperator: '<S516>/Compare'
             *  S-Function (sfix_bitop): '<S513>/w_cmd valid'
             */
            rtb_a_bx = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 6] *
                rtb_a_bx + (rtb_VectorConcatenate_pc[rtb_n + 3] *
                            rtb_Saturation1_hc + rtb_VectorConcatenate_pc[rtb_n]
                            * rtb_Saturation1_d);
            }
            break;

           case 1:
            /* SignalConversion: '<S520>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S520>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Gain: '<S519>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S515>/Subtract'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi -
                                  FMS_B.Cmd_In.offboard_psi_0);

            /* Trigonometry: '<S520>/Trigonometric Function3' incorporates:
             *  Gain: '<S519>/Gain'
             */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(rtb_Saturation1_d);

            /* Gain: '<S520>/Gain' incorporates:
             *  Gain: '<S519>/Gain'
             *  Trigonometry: '<S520>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(rtb_Saturation1_d);

            /* SignalConversion: '<S520>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S520>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S520>/Trigonometric Function' incorporates:
             *  Gain: '<S519>/Gain'
             */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(rtb_Saturation1_d);

            /* Trigonometry: '<S520>/Trigonometric Function1' incorporates:
             *  Gain: '<S519>/Gain'
             */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(rtb_Saturation1_d);

            /* SignalConversion: '<S520>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3_g[0];

            /* Product: '<S481>/Multiply' incorporates:
             *  Constant: '<S516>/Constant'
             *  RelationalOperator: '<S516>/Compare'
             *  S-Function (sfix_bitop): '<S513>/u_cmd valid'
             */
            rtb_Saturation1_d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S520>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3_g[1];

            /* Product: '<S481>/Multiply' incorporates:
             *  Constant: '<S516>/Constant'
             *  RelationalOperator: '<S516>/Compare'
             *  S-Function (sfix_bitop): '<S513>/v_cmd valid'
             */
            rtb_Saturation1_hc = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S520>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Product: '<S481>/Multiply' incorporates:
             *  Constant: '<S516>/Constant'
             *  RelationalOperator: '<S516>/Compare'
             *  S-Function (sfix_bitop): '<S513>/w_cmd valid'
             */
            rtb_a_bx = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n + 6] *
                rtb_a_bx + (rtb_VectorConcatenate_pc[rtb_n + 3] *
                            rtb_Saturation1_hc + rtb_VectorConcatenate_pc[rtb_n]
                            * rtb_Saturation1_d);
            }
            break;

           default:
            rtb_Switch_d0[0] = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;
            rtb_Switch_d0[1] = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;
            rtb_Switch_d0[2] = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S481>/Index Vector' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_d0[0] += rtb_Saturation_d;
          rtb_Switch_d0[1] += rtb_Switch_f_idx_0;

          /* Sum: '<S420>/Sum1' */
          rtb_Saturation_d = rtb_Switch_f_idx_2 + rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S437>/Switch' incorporates:
           *  Constant: '<S452>/Constant'
           *  Constant: '<S453>/Constant'
           *  Constant: '<S454>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S452>/Compare'
           *  RelationalOperator: '<S453>/Compare'
           *  RelationalOperator: '<S454>/Compare'
           *  S-Function (sfix_bitop): '<S437>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S437>/y_v_cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S437>/Logical Operator' incorporates:
             *  Constant: '<S453>/Constant'
             *  Constant: '<S454>/Constant'
             *  RelationalOperator: '<S453>/Compare'
             *  RelationalOperator: '<S454>/Compare'
             *  S-Function (sfix_bitop): '<S437>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S437>/y_v_cmd'
             */
            rtb_LogicalOperator_fl = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_fl;
          } else {
            rtb_LogicalOperator_fl = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U)
              > 0U);
          }

          /* End of Switch: '<S437>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S418>/u_cmd_valid' */
          /* MATLAB Function: '<S449>/bit_shift' incorporates:
           *  DataTypeConversion: '<S418>/Data Type Conversion6'
           */
          rtb_DataTypeConversion_o = (uint16_T)(rtb_LogicalOperator_fl << 6);

          /* End of Outputs for SubSystem: '<S418>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S418>/v_cmd_valid' */
          /* MATLAB Function: '<S450>/bit_shift' incorporates:
           *  DataTypeConversion: '<S418>/Data Type Conversion7'
           */
          rtb_DataTypeConversion1_b = (uint16_T)(rtb_FixPtRelationalOperator_me <<
            7);

          /* End of Outputs for SubSystem: '<S418>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S438>/Switch' incorporates:
           *  Constant: '<S456>/Constant'
           *  Constant: '<S457>/Constant'
           *  Constant: '<S459>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S456>/Compare'
           *  RelationalOperator: '<S457>/Compare'
           *  RelationalOperator: '<S459>/Compare'
           *  S-Function (sfix_bitop): '<S438>/ax_cmd'
           *  S-Function (sfix_bitop): '<S438>/ay_cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S438>/Logical Operator' incorporates:
             *  Constant: '<S457>/Constant'
             *  Constant: '<S459>/Constant'
             *  RelationalOperator: '<S457>/Compare'
             *  RelationalOperator: '<S459>/Compare'
             *  S-Function (sfix_bitop): '<S438>/ax_cmd'
             *  S-Function (sfix_bitop): '<S438>/ay_cmd'
             */
            rtb_LogicalOperator_fl = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_fl;
          } else {
            rtb_LogicalOperator_fl = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S438>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S338>/Bus Assignment' incorporates:
           *  Constant: '<S338>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
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
          FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.az_cmd = rtb_Switch_ov[2];

          /* Saturate: '<S419>/Saturation' */
          if (rtb_Switch_f_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_Switch_f_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_Switch_f_idx_1;
          }

          /* End of Saturate: '<S419>/Saturation' */

          /* Saturate: '<S420>/Saturation2' */
          if (rtb_Switch_d0[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_d0[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_d0[0];
          }

          /* End of Saturate: '<S420>/Saturation2' */

          /* Saturate: '<S420>/Saturation1' */
          if (rtb_Switch_d0[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_d0[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_d0[1];
          }

          /* End of Saturate: '<S420>/Saturation1' */

          /* Saturate: '<S420>/Saturation3' */
          if (rtb_Saturation_d > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_d < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S338>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_d;
          }

          /* End of Saturate: '<S420>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S418>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S418>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S418>/throttle_cmd_valid' */
          /* BusAssignment: '<S338>/Bus Assignment' incorporates:
           *  Constant: '<S430>/Constant'
           *  Constant: '<S431>/Constant'
           *  Constant: '<S432>/Constant'
           *  Constant: '<S433>/Constant'
           *  Constant: '<S434>/Constant'
           *  Constant: '<S435>/Constant'
           *  Constant: '<S436>/Constant'
           *  Constant: '<S455>/Constant'
           *  Constant: '<S458>/Constant'
           *  DataTypeConversion: '<S418>/Data Type Conversion10'
           *  DataTypeConversion: '<S418>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S439>/bit_shift'
           *  MATLAB Function: '<S440>/bit_shift'
           *  MATLAB Function: '<S441>/bit_shift'
           *  MATLAB Function: '<S443>/bit_shift'
           *  MATLAB Function: '<S444>/bit_shift'
           *  MATLAB Function: '<S445>/bit_shift'
           *  MATLAB Function: '<S446>/bit_shift'
           *  MATLAB Function: '<S447>/bit_shift'
           *  MATLAB Function: '<S448>/bit_shift'
           *  MATLAB Function: '<S451>/bit_shift'
           *  RelationalOperator: '<S430>/Compare'
           *  RelationalOperator: '<S431>/Compare'
           *  RelationalOperator: '<S432>/Compare'
           *  RelationalOperator: '<S433>/Compare'
           *  RelationalOperator: '<S434>/Compare'
           *  RelationalOperator: '<S435>/Compare'
           *  RelationalOperator: '<S436>/Compare'
           *  RelationalOperator: '<S455>/Compare'
           *  RelationalOperator: '<S458>/Compare'
           *  S-Function (sfix_bitop): '<S418>/p_cmd'
           *  S-Function (sfix_bitop): '<S418>/phi_cmd'
           *  S-Function (sfix_bitop): '<S418>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S418>/q_cmd'
           *  S-Function (sfix_bitop): '<S418>/r_cmd'
           *  S-Function (sfix_bitop): '<S418>/theta_cmd'
           *  S-Function (sfix_bitop): '<S418>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S437>/z_w_cmd'
           *  S-Function (sfix_bitop): '<S438>/az_cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           *  Sum: '<S418>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) +
            rtb_DataTypeConversion_o) + rtb_DataTypeConversion1_b) +
            (((FMS_U.Auto_Cmd.cmd_mask & 33280U) > 0U) << 8)) +
            (rtb_LogicalOperator_fl << 9)) + (rtb_FixPtRelationalOperator_me <<
            10)) + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S418>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S418>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S418>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S225>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S225>/Mission' incorporates:
             *  ActionPort: '<S337>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S225>/Switch Case' incorporates:
             *  UnitDelay: '<S340>/Delay Input1'
             *
             * Block description for '<S340>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S225>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S225>/Mission' incorporates:
             *  ActionPort: '<S337>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S337>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S225>/Switch Case' incorporates:
             *  Chart: '<S376>/Motion Status'
             *  Chart: '<S386>/Motion State'
             *  Delay: '<S345>/Delay'
             *  Delay: '<S367>/Delay'
             *  DiscreteIntegrator: '<S348>/Integrator'
             *  DiscreteIntegrator: '<S348>/Integrator1'
             *  DiscreteIntegrator: '<S363>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S368>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S412>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.icLoad_m = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_h);

            /* End of SystemReset for SubSystem: '<S337>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S225>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S225>/Mission' incorporates:
           *  ActionPort: '<S337>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* RelationalOperator: '<S340>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S340>/Delay Input1'
           *
           * Block description for '<S340>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S337>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S341>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S375>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* InitializeConditions for Delay: '<S367>/Delay' */
            FMS_DW.icLoad = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S368>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S363>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S345>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S348>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S348>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S386>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S376>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_h);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S367>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S368>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S340>/Delay Input1'
           *
           * Block description for '<S340>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S362>/Compare' incorporates:
           *  Constant: '<S416>/Constant'
           *  RelationalOperator: '<S416>/Compare'
           *  UnitDelay: '<S340>/Delay Input1'
           *
           * Block description for '<S340>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_ii = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S363>/Acceleration_Speed' */
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
          /* Chart: '<S386>/Motion State' incorporates:
           *  Constant: '<S386>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S386>/Square'
           *  Math: '<S386>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S386>/Sqrt'
           *  Sum: '<S386>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S385>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_c;
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S385>/Hold Control' incorporates:
               *  ActionPort: '<S388>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S385>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_fy);

              /* End of SystemReset for SubSystem: '<S385>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S385>/Hold Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_ls,
                              &FMS_ConstB.HoldControl_fy, &FMS_DW.HoldControl_fy);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S385>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S385>/Brake Control' incorporates:
             *  ActionPort: '<S387>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_ls);

            /* End of Outputs for SubSystem: '<S385>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S385>/Move Control' incorporates:
               *  ActionPort: '<S389>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S385>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_i);

              /* End of SystemReset for SubSystem: '<S385>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S385>/Move Control' incorporates:
             *  ActionPort: '<S389>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_ls,
                              &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S385>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S385>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S376>/Motion Status' incorporates:
           *  Abs: '<S376>/Abs'
           *  Constant: '<S376>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_h);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S375>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S375>/Hold Control' incorporates:
               *  ActionPort: '<S378>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S375>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bf);

              /* End of SystemReset for SubSystem: '<S375>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S375>/Hold Control' incorporates:
             *  ActionPort: '<S378>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_i,
                              &FMS_DW.HoldControl_bf);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S375>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S375>/Brake Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_i);

            /* End of Outputs for SubSystem: '<S375>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S375>/Move Control' incorporates:
               *  ActionPort: '<S379>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S375>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c0);

              /* End of SystemReset for SubSystem: '<S375>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S375>/Move Control' incorporates:
             *  ActionPort: '<S379>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_i,
                              &FMS_ConstB.MoveControl_c0, &FMS_DW.MoveControl_c0);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S375>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S375>/Switch Case' */

          /* Switch: '<S343>/Switch' incorporates:
           *  Product: '<S367>/Multiply'
           *  Sum: '<S367>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S385>/Saturation1' */
            if (FMS_B.Merge_ls[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_f_idx_0 = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_ls[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_f_idx_0 = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_f_idx_0 = FMS_B.Merge_ls[0];
            }

            if (FMS_B.Merge_ls[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_f_idx_1 = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_ls[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_f_idx_1 = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_f_idx_1 = FMS_B.Merge_ls[1];
            }

            /* End of Saturate: '<S385>/Saturation1' */

            /* Saturate: '<S375>/Saturation1' */
            if (FMS_B.Merge_i > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_f_idx_2 = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_i < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_f_idx_2 = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_f_idx_2 = FMS_B.Merge_i;
            }

            /* End of Saturate: '<S375>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S367>/Sum' incorporates:
             *  Delay: '<S367>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* SignalConversion: '<S413>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_f_idx_0 = rtb_Switch_f_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S363>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Divide_n4[0] = rtb_Switch_f_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S367>/Sum' incorporates:
             *  Delay: '<S367>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE[1];

            /* Sum: '<S363>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Sqrt: '<S372>/Sqrt' incorporates:
             *  Math: '<S372>/Square'
             *  Sum: '<S363>/Sum'
             *  Sum: '<S372>/Sum of Elements'
             */
            rtb_Saturation_d = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation_d * rtb_Saturation_d);

            /* SignalConversion: '<S415>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_pc[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_VectorConcatenate_pc[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_VectorConcatenate_pc[8] = FMS_ConstB.VectorConcatenate3[2];

            /* SignalConversion: '<S415>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S415>/Constant4'
             */
            rtb_VectorConcatenate_pc[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S414>/Gain' incorporates:
             *  DiscreteIntegrator: '<S412>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S412>/Add'
             */
            rtb_Switch_f_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Trigonometry: '<S415>/Trigonometric Function3' */
            rtb_VectorConcatenate_pc[4] = arm_cos_f32(rtb_Switch_f_idx_2);

            /* Gain: '<S415>/Gain' incorporates:
             *  Trigonometry: '<S415>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_pc[3] = -arm_sin_f32(rtb_Switch_f_idx_2);

            /* SignalConversion: '<S415>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S415>/Constant3'
             */
            rtb_VectorConcatenate_pc[2] = 0.0F;

            /* Trigonometry: '<S415>/Trigonometric Function' */
            rtb_VectorConcatenate_pc[1] = arm_sin_f32(rtb_Switch_f_idx_2);

            /* Trigonometry: '<S415>/Trigonometric Function1' */
            rtb_VectorConcatenate_pc[0] = arm_cos_f32(rtb_Switch_f_idx_2);

            /* Switch: '<S363>/Switch' incorporates:
             *  Constant: '<S363>/vel'
             */
            if (rtb_Saturation_d > FMS_PARAM.L1) {
              rtb_Switch_f_idx_2 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S363>/Gain' */
              rtb_Switch_f_idx_2 = 0.5F * rtb_Saturation_d;

              /* Saturate: '<S363>/Saturation' */
              if (rtb_Switch_f_idx_2 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Switch_f_idx_2 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Switch_f_idx_2 < 0.5F) {
                  rtb_Switch_f_idx_2 = 0.5F;
                }
              }

              /* End of Saturate: '<S363>/Saturation' */
            }

            /* End of Switch: '<S363>/Switch' */

            /* Switch: '<S363>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S363>/Acceleration_Speed'
             *  Sum: '<S363>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE - rtb_Switch_f_idx_2 < 0.0F) {
              rtb_Switch_f_idx_2 = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S363>/Switch1' */

            /* Sum: '<S413>/Sum of Elements' incorporates:
             *  Math: '<S413>/Math Function'
             */
            rtb_Saturation1_hc = rtb_Switch_f_idx_0 * rtb_Switch_f_idx_0 +
              rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

            /* Math: '<S413>/Math Function1' incorporates:
             *  Sum: '<S413>/Sum of Elements'
             *
             * About '<S413>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_hc < 0.0F) {
              rtb_Saturation1_hc = -sqrtf(fabsf(rtb_Saturation1_hc));
            } else {
              rtb_Saturation1_hc = sqrtf(rtb_Saturation1_hc);
            }

            /* End of Math: '<S413>/Math Function1' */

            /* Switch: '<S413>/Switch' incorporates:
             *  Constant: '<S413>/Constant'
             *  Product: '<S413>/Product'
             */
            if (rtb_Saturation1_hc > 0.0F) {
              rtb_Saturation_d = rtb_Divide_n4[0];
            } else {
              rtb_Saturation_d = 0.0F;
              rtb_Switch_f_idx_1 = 0.0F;
              rtb_Saturation1_hc = 1.0F;
            }

            /* End of Switch: '<S413>/Switch' */

            /* Product: '<S411>/Multiply2' incorporates:
             *  Product: '<S413>/Divide'
             */
            rtb_Saturation1_d = rtb_Saturation_d / rtb_Saturation1_hc *
              rtb_Switch_f_idx_2;
            rtb_Divide_or = rtb_Switch_f_idx_1 / rtb_Saturation1_hc *
              rtb_Switch_f_idx_2;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S369>/Sum1' incorporates:
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation1_hc = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S369>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_f_idx_2 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Product: '<S369>/Divide' incorporates:
             *  Math: '<S370>/Square'
             *  Math: '<S371>/Square'
             *  Sqrt: '<S370>/Sqrt'
             *  Sqrt: '<S371>/Sqrt'
             *  Sum: '<S369>/Sum'
             *  Sum: '<S369>/Sum1'
             *  Sum: '<S370>/Sum of Elements'
             *  Sum: '<S371>/Sum of Elements'
             */
            rtb_Switch_f_idx_2 = sqrtf(rtb_Switch_f_idx_2 * rtb_Switch_f_idx_2 +
              rtb_Saturation_d * rtb_Saturation_d) / sqrtf(rtb_Switch_f_idx_1 *
              rtb_Switch_f_idx_1 + rtb_Saturation1_hc * rtb_Saturation1_hc);

            /* Saturate: '<S369>/Saturation' */
            if (rtb_Switch_f_idx_2 > 1.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            } else {
              if (rtb_Switch_f_idx_2 < 0.0F) {
                rtb_Switch_f_idx_2 = 0.0F;
              }
            }

            /* End of Saturate: '<S369>/Saturation' */

            /* Product: '<S367>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_pc[rtb_n +
                3] * rtb_Divide_or + rtb_VectorConcatenate_pc[rtb_n] *
                rtb_Saturation1_d;
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S360>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S369>/Multiply'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S360>/Sum2'
             *  Sum: '<S369>/Add'
             *  Sum: '<S369>/Subtract'
             */
            rtb_Switch_f_idx_2 = (FMS_U.INS_Out.h_R -
                                  ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_f_idx_2 +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = rtb_VectorConcatenate_g0[0];
            rtb_Switch_f_idx_1 = rtb_VectorConcatenate_g0[1];

            /* Saturate: '<S360>/Saturation1' incorporates:
             *  Product: '<S367>/Multiply'
             */
            if (rtb_Switch_f_idx_2 > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_f_idx_2 = FMS_PARAM.VEL_Z_LIM;
            } else {
              if (rtb_Switch_f_idx_2 < -FMS_PARAM.VEL_Z_LIM) {
                rtb_Switch_f_idx_2 = -FMS_PARAM.VEL_Z_LIM;
              }
            }

            /* End of Saturate: '<S360>/Saturation1' */
          }

          /* End of Switch: '<S343>/Switch' */

          /* Delay: '<S345>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S348>/Integrator1' incorporates:
           *  Delay: '<S345>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S352>/Rem' incorporates:
           *  Constant: '<S352>/Constant1'
           *  DiscreteIntegrator: '<S348>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S347>/Sum'
           */
          rtb_a_bx = rt_remf(FMS_DW.Integrator1_DSTATE_mf - FMS_U.INS_Out.psi,
                             6.28318548F);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S352>/Switch' incorporates:
           *  Abs: '<S352>/Abs'
           *  Constant: '<S352>/Constant'
           *  Constant: '<S353>/Constant'
           *  Product: '<S352>/Multiply'
           *  RelationalOperator: '<S353>/Compare'
           *  Sum: '<S352>/Add'
           */
          if (fabsf(rtb_a_bx) > 3.14159274F) {
            /* Signum: '<S352>/Sign' */
            if (rtb_a_bx < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else if (rtb_a_bx > 0.0F) {
              rtb_Saturation_d = 1.0F;
            } else {
              rtb_Saturation_d = rtb_a_bx;
            }

            /* End of Signum: '<S352>/Sign' */
            rtb_a_bx -= 6.28318548F * rtb_Saturation_d;
          }

          /* End of Switch: '<S352>/Switch' */

          /* Gain: '<S347>/Gain2' */
          rtb_a_bx *= FMS_PARAM.YAW_P;

          /* Saturate: '<S347>/Saturation' */
          if (rtb_a_bx > FMS_PARAM.YAW_RATE_LIM) {
            rtb_a_bx = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_a_bx < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_a_bx = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S347>/Saturation' */

          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  Constant: '<S341>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_f_idx_0;
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_f_idx_1;
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_f_idx_2;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_a_bx;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S406>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S406>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Saturation1_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S406>/Math Function1' incorporates:
           *  Sum: '<S406>/Sum of Elements'
           *
           * About '<S406>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_a_bx = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_a_bx = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S406>/Math Function1' */

          /* Switch: '<S406>/Switch' incorporates:
           *  Constant: '<S406>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S406>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_a_bx > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_f_idx_2 = rtb_a_bx;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S406>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S341>/Sum' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_P_dg[0] = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_P_dg[1] = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint
            [1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S359>/Math Function' incorporates:
           *  Sum: '<S341>/Sum'
           */
          rtb_Square_h[0] = rtb_Saturation1_d * rtb_Saturation1_d;
          rtb_Square_h[1] = rtb_Divide_or * rtb_Divide_or;

          /* Sum: '<S359>/Sum of Elements' */
          rtb_Saturation1_hc = rtb_Square_h[0] + rtb_Square_h[1];

          /* Math: '<S359>/Math Function1' incorporates:
           *  Sum: '<S359>/Sum of Elements'
           *
           * About '<S359>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_a_bx = -sqrtf(fabsf(rtb_Saturation1_hc));
          } else {
            rtb_a_bx = sqrtf(rtb_Saturation1_hc);
          }

          /* End of Math: '<S359>/Math Function1' */

          /* Switch: '<S359>/Switch' incorporates:
           *  Constant: '<S359>/Constant'
           *  Product: '<S359>/Product'
           */
          if (rtb_a_bx > 0.0F) {
            rtb_Subtract3_d = rtb_a_bx;
          } else {
            rtb_Saturation1_d = 0.0F;
            rtb_Divide_or = 0.0F;
            rtb_Subtract3_d = 1.0F;
          }

          /* End of Switch: '<S359>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S365>/NearbyRefWP' incorporates:
           *  Constant: '<S341>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_dg,
                          &rtb_Sign5_mn);

          /* MATLAB Function: '<S365>/SearchL1RefWP' incorporates:
           *  Constant: '<S341>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_Square_h, &rtb_u);

          /* MATLAB Function: '<S365>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_bx = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_d_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Saturation_d = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
                              * rtb_Divide_d_0 + (FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_a_bx) / (rtb_a_bx * rtb_a_bx +
            rtb_Divide_d_0 * rtb_Divide_d_0);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_Saturation_d <= 0.0F);
          rtb_LogicalOperator_fl = (rtb_Saturation_d >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation1_hc = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else if (rtb_LogicalOperator_fl) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation1_hc = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Saturation1_hc = rtb_Saturation_d * rtb_a_bx +
              FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Switch: '<S365>/Switch1' incorporates:
           *  Constant: '<S399>/Constant'
           *  RelationalOperator: '<S399>/Compare'
           */
          if (rtb_Sign5_mn <= 0.0F) {
            /* Switch: '<S365>/Switch' incorporates:
             *  Constant: '<S398>/Constant'
             *  RelationalOperator: '<S398>/Compare'
             */
            if (rtb_u >= 0.0F) {
              rtb_P_dg[0] = rtb_Square_h[0];
              rtb_P_dg[1] = rtb_Square_h[1];
            } else {
              rtb_P_dg[0] = rtb_Saturation1_hc;

              /* MATLAB Function: '<S365>/OutRegionRegWP' incorporates:
               *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_P_dg[1] = FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              } else if (rtb_LogicalOperator_fl) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_P_dg[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              } else {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_P_dg[1] = rtb_Saturation_d * rtb_Divide_d_0 +
                  FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              }
            }

            /* End of Switch: '<S365>/Switch' */
          }

          /* End of Switch: '<S365>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S366>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sign5_mn = rtb_P_dg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S407>/Math Function' */
          rtb_Divide_n4[0] = rtb_Sign5_mn * rtb_Sign5_mn;
          rtb_Saturation_d = rtb_Sign5_mn;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S366>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sign5_mn = rtb_P_dg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S407>/Math Function' incorporates:
           *  Math: '<S405>/Square'
           */
          rtb_Saturation1_hc = rtb_Sign5_mn * rtb_Sign5_mn;

          /* Sum: '<S407>/Sum of Elements' incorporates:
           *  Math: '<S407>/Math Function'
           */
          rtb_a_bx = rtb_Saturation1_hc + rtb_Divide_n4[0];

          /* Math: '<S407>/Math Function1' incorporates:
           *  Sum: '<S407>/Sum of Elements'
           *
           * About '<S407>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_a_bx = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_a_bx = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S407>/Math Function1' */

          /* Switch: '<S407>/Switch' incorporates:
           *  Constant: '<S407>/Constant'
           *  Product: '<S407>/Product'
           */
          if (rtb_a_bx > 0.0F) {
            rtb_Switch_d0[0] = rtb_Saturation_d;
            rtb_Switch_d0[1] = rtb_Sign5_mn;
            rtb_Switch_d0[2] = rtb_a_bx;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S407>/Switch' */

          /* Product: '<S406>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S409>/Sum of Elements' incorporates:
           *  Math: '<S409>/Math Function'
           *  SignalConversion: '<S409>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S409>/Math Function1' incorporates:
           *  Sum: '<S409>/Sum of Elements'
           *
           * About '<S409>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_a_bx = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_a_bx = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S409>/Math Function1' */

          /* Switch: '<S409>/Switch' incorporates:
           *  Constant: '<S409>/Constant'
           *  Product: '<S409>/Product'
           */
          if (rtb_a_bx > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_f_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_f_idx_2 = rtb_a_bx;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S409>/Switch' */

          /* Product: '<S407>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S410>/Sum of Elements' incorporates:
           *  Math: '<S410>/Math Function'
           *  SignalConversion: '<S410>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S410>/Math Function1' incorporates:
           *  Sum: '<S410>/Sum of Elements'
           *
           * About '<S410>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_a_bx = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_a_bx = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S410>/Math Function1' */

          /* Switch: '<S410>/Switch' incorporates:
           *  Constant: '<S410>/Constant'
           *  Product: '<S410>/Product'
           */
          if (rtb_a_bx > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_a_bx;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S410>/Switch' */

          /* Product: '<S410>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S409>/Divide' */
          rtb_P_dg[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Product: '<S359>/Divide' */
          rtb_Square_h[0] = rtb_Saturation1_d / rtb_Subtract3_d;
          rtb_Saturation_d *= rtb_Saturation_d;

          /* Product: '<S410>/Divide' incorporates:
           *  Math: '<S405>/Square'
           */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S409>/Divide' */
          rtb_P_dg[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Product: '<S359>/Divide' */
          rtb_Square_h[1] = rtb_Divide_or / rtb_Subtract3_d;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S404>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S404>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S404>/Sum of Elements'
           */
          rtb_a_bx = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S366>/Gain' incorporates:
           *  Math: '<S366>/Square'
           */
          rtb_Saturation1_d = rtb_a_bx * rtb_a_bx * 2.0F;

          /* Sum: '<S408>/Subtract' incorporates:
           *  Product: '<S408>/Multiply'
           *  Product: '<S408>/Multiply1'
           */
          rtb_a_bx = rtb_Divide_n4[0] * rtb_P_dg[1] - rtb_Divide_n4[1] *
            rtb_P_dg[0];

          /* Signum: '<S403>/Sign1' */
          if (rtb_a_bx < 0.0F) {
            rtb_a_bx = -1.0F;
          } else {
            if (rtb_a_bx > 0.0F) {
              rtb_a_bx = 1.0F;
            }
          }

          /* End of Signum: '<S403>/Sign1' */

          /* Switch: '<S403>/Switch2' incorporates:
           *  Constant: '<S403>/Constant4'
           */
          if (rtb_a_bx == 0.0F) {
            rtb_a_bx = 1.0F;
          }

          /* End of Switch: '<S403>/Switch2' */

          /* DotProduct: '<S403>/Dot Product' */
          rtb_Switch_f_idx_0 = rtb_P_dg[0] * rtb_Divide_n4[0] + rtb_P_dg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S403>/Acos' incorporates:
           *  DotProduct: '<S403>/Dot Product'
           */
          if (rtb_Switch_f_idx_0 > 1.0F) {
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_0 < -1.0F) {
              rtb_Switch_f_idx_0 = -1.0F;
            }
          }

          /* Product: '<S403>/Multiply' incorporates:
           *  Trigonometry: '<S403>/Acos'
           */
          rtb_a_bx *= acosf(rtb_Switch_f_idx_0);

          /* Saturate: '<S366>/Saturation' */
          if (rtb_a_bx > 1.57079637F) {
            rtb_a_bx = 1.57079637F;
          } else {
            if (rtb_a_bx < -1.57079637F) {
              rtb_a_bx = -1.57079637F;
            }
          }

          /* End of Saturate: '<S366>/Saturation' */

          /* Product: '<S366>/Divide' incorporates:
           *  Constant: '<S341>/L1'
           *  Constant: '<S366>/Constant'
           *  MinMax: '<S366>/Max'
           *  MinMax: '<S366>/Min'
           *  Product: '<S366>/Multiply1'
           *  Sqrt: '<S405>/Sqrt'
           *  Sum: '<S405>/Sum of Elements'
           *  Trigonometry: '<S366>/Sin'
           */
          rtb_Saturation1_hc = arm_sin_f32(rtb_a_bx) * rtb_Saturation1_d / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation1_hc + rtb_Saturation_d),
              0.5F));

          /* Sum: '<S357>/Subtract' incorporates:
           *  Product: '<S357>/Multiply'
           *  Product: '<S357>/Multiply1'
           */
          rtb_Switch_f_idx_2 = rtb_Square_h[0] * FMS_ConstB.Divide[1] -
            rtb_Square_h[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S346>/Sign1' */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_2 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S346>/Sign1' */

          /* Switch: '<S346>/Switch2' incorporates:
           *  Constant: '<S346>/Constant4'
           */
          if (rtb_Switch_f_idx_2 == 0.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S346>/Switch2' */

          /* DotProduct: '<S346>/Dot Product' */
          rtb_Switch_f_idx_1 = FMS_ConstB.Divide[0] * rtb_Square_h[0] +
            FMS_ConstB.Divide[1] * rtb_Square_h[1];

          /* Trigonometry: '<S346>/Acos' incorporates:
           *  DotProduct: '<S346>/Dot Product'
           */
          if (rtb_Switch_f_idx_1 > 1.0F) {
            rtb_Switch_f_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_1 < -1.0F) {
              rtb_Switch_f_idx_1 = -1.0F;
            }
          }

          /* Product: '<S346>/Multiply' incorporates:
           *  Trigonometry: '<S346>/Acos'
           */
          rtb_Switch_f_idx_2 *= acosf(rtb_Switch_f_idx_1);

          /* Math: '<S349>/Rem' incorporates:
           *  Constant: '<S349>/Constant1'
           *  Delay: '<S345>/Delay'
           *  Sum: '<S345>/Sum2'
           */
          rtb_a_bx = rt_remf(rtb_Switch_f_idx_2 - FMS_DW.Delay_DSTATE_n,
                             6.28318548F);

          /* Switch: '<S349>/Switch' incorporates:
           *  Abs: '<S349>/Abs'
           *  Constant: '<S349>/Constant'
           *  Constant: '<S355>/Constant'
           *  Product: '<S349>/Multiply'
           *  RelationalOperator: '<S355>/Compare'
           *  Sum: '<S349>/Add'
           */
          if (fabsf(rtb_a_bx) > 3.14159274F) {
            /* Signum: '<S349>/Sign' */
            if (rtb_a_bx < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else if (rtb_a_bx > 0.0F) {
              rtb_Saturation_d = 1.0F;
            } else {
              rtb_Saturation_d = rtb_a_bx;
            }

            /* End of Signum: '<S349>/Sign' */
            rtb_a_bx -= 6.28318548F * rtb_Saturation_d;
          }

          /* End of Switch: '<S349>/Switch' */

          /* Sum: '<S345>/Sum' incorporates:
           *  Delay: '<S345>/Delay'
           */
          rtb_Saturation_d = rtb_a_bx + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S354>/Multiply1' incorporates:
           *  Constant: '<S354>/const1'
           *  DiscreteIntegrator: '<S348>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S354>/Add' incorporates:
           *  DiscreteIntegrator: '<S348>/Integrator1'
           *  Sum: '<S348>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_d)
            + rtb_a_bx;

          /* Signum: '<S354>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_d = 1.0F;
          } else {
            rtb_Saturation_d = rtb_Saturation1_d;
          }

          /* End of Signum: '<S354>/Sign' */

          /* Sum: '<S354>/Add2' incorporates:
           *  Abs: '<S354>/Abs'
           *  Gain: '<S354>/Gain'
           *  Gain: '<S354>/Gain1'
           *  Product: '<S354>/Multiply2'
           *  Product: '<S354>/Multiply3'
           *  Sqrt: '<S354>/Sqrt'
           *  Sum: '<S354>/Add1'
           *  Sum: '<S354>/Subtract'
           */
          rtb_Sign5_mn = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_d + rtb_a_bx;

          /* Sum: '<S354>/Add4' */
          rtb_Switch_f_idx_0 = (rtb_Saturation1_d - rtb_Sign5_mn) + rtb_a_bx;

          /* Sum: '<S354>/Add3' */
          rtb_Saturation_d = rtb_Saturation1_d + FMS_ConstB.d_m;

          /* Sum: '<S354>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_m;

          /* Signum: '<S354>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S354>/Sign1' */

          /* Signum: '<S354>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S354>/Sign2' */

          /* Sum: '<S354>/Add5' incorporates:
           *  Gain: '<S354>/Gain2'
           *  Product: '<S354>/Multiply4'
           *  Sum: '<S354>/Subtract2'
           */
          rtb_Sign5_mn += (rtb_Saturation_d - rtb_Saturation1_d) * 0.5F *
            rtb_Switch_f_idx_0;

          /* Sum: '<S354>/Add6' */
          rtb_Saturation_d = rtb_Sign5_mn + FMS_ConstB.d_m;

          /* Sum: '<S354>/Subtract3' */
          rtb_Saturation1_d = rtb_Sign5_mn - FMS_ConstB.d_m;

          /* Product: '<S354>/Divide' */
          rtb_a_bx = rtb_Sign5_mn / FMS_ConstB.d_m;

          /* Signum: '<S354>/Sign5' incorporates:
           *  Signum: '<S354>/Sign6'
           */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S354>/Sign6' */
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_Sign5_mn > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S354>/Sign6' */
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Sign5_mn;

            /* Signum: '<S354>/Sign6' */
            rtb_Switch_f_idx_0 = rtb_Sign5_mn;
          }

          /* End of Signum: '<S354>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S345>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Switch_f_idx_2 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S350>/Rem' incorporates:
           *  Constant: '<S350>/Constant1'
           */
          rtb_Sign5_mn = rt_remf(rtb_Switch_f_idx_2, 6.28318548F);

          /* Switch: '<S350>/Switch' incorporates:
           *  Abs: '<S350>/Abs'
           *  Constant: '<S350>/Constant'
           *  Constant: '<S356>/Constant'
           *  Product: '<S350>/Multiply'
           *  RelationalOperator: '<S356>/Compare'
           *  Sum: '<S350>/Add'
           */
          if (fabsf(rtb_Sign5_mn) > 3.14159274F) {
            /* Signum: '<S350>/Sign' */
            if (rtb_Sign5_mn < 0.0F) {
              rtb_Switch_f_idx_1 = -1.0F;
            } else if (rtb_Sign5_mn > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            } else {
              rtb_Switch_f_idx_1 = rtb_Sign5_mn;
            }

            /* End of Signum: '<S350>/Sign' */
            rtb_Sign5_mn -= 6.28318548F * rtb_Switch_f_idx_1;
          }

          /* End of Switch: '<S350>/Switch' */

          /* Abs: '<S343>/Abs' */
          rtb_Sign5_mn = fabsf(rtb_Sign5_mn);

          /* Update for Delay: '<S367>/Delay' */
          FMS_DW.icLoad = 0U;

          /* Update for DiscreteIntegrator: '<S368>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S361>/Constant'
           *  RelationalOperator: '<S361>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
            (rtb_Sign5_mn <= 0.17453292F) +
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S368>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S363>/Acceleration_Speed' incorporates:
           *  Constant: '<S363>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S363>/Acceleration_Speed' */

          /* Product: '<S367>/Divide1' incorporates:
           *  Constant: '<S367>/Constant'
           */
          rtb_Switch_f_idx_1 = rtb_Saturation1_hc / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S367>/Saturation' */
          if (rtb_Switch_f_idx_1 > 0.314159274F) {
            rtb_Switch_f_idx_1 = 0.314159274F;
          } else {
            if (rtb_Switch_f_idx_1 < -0.314159274F) {
              rtb_Switch_f_idx_1 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S367>/Saturation' */

          /* Update for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_Switch_f_idx_1;

          /* Update for Delay: '<S345>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S348>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S348>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S354>/Sign3' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S354>/Sign3' */

          /* Signum: '<S354>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S354>/Sign4' */

          /* Update for DiscreteIntegrator: '<S348>/Integrator' incorporates:
           *  Constant: '<S354>/const'
           *  Gain: '<S354>/Gain3'
           *  Product: '<S354>/Multiply5'
           *  Product: '<S354>/Multiply6'
           *  Sum: '<S354>/Subtract4'
           *  Sum: '<S354>/Subtract5'
           *  Sum: '<S354>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_a_bx - rtb_Divide_or) *
            FMS_ConstB.Gain4_cu * ((rtb_Saturation_d - rtb_Saturation1_d) * 0.5F)
            - rtb_Switch_f_idx_0 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S348>/Integrator' */
          /* End of Outputs for SubSystem: '<S337>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Update for UnitDelay: '<S340>/Delay Input1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S340>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S225>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S225>/Unknown' incorporates:
           *  ActionPort: '<S339>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S225>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S225>/Switch Case' */
        /* End of Outputs for SubSystem: '<S37>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S37>/Assist' incorporates:
         *  ActionPort: '<S224>/Action Port'
         */
        /* SwitchCase: '<S224>/Switch Case' */
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
            /* Disable for SwitchCase: '<S324>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S239>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S257>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S273>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S298>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S285>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S224>/Acro' incorporates:
           *  ActionPort: '<S229>/Action Port'
           */
          /* BusAssignment: '<S229>/Bus Assignment' incorporates:
           *  Constant: '<S229>/Constant'
           *  Gain: '<S234>/Gain'
           *  Gain: '<S234>/Gain1'
           *  Gain: '<S234>/Gain2'
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

          /* Saturate: '<S235>/Saturation' incorporates:
           *  Constant: '<S235>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           *  Sum: '<S235>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_Saturation1_hc = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S235>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S229>/Bus Assignment' incorporates:
           *  Constant: '<S235>/Constant5'
           *  Gain: '<S235>/Gain2'
           *  Sum: '<S235>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Saturation1_hc), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S224>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S224>/Stabilize' incorporates:
             *  ActionPort: '<S232>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S224>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S320>/Integrator'
             *  DiscreteIntegrator: '<S320>/Integrator1'
             *  DiscreteIntegrator: '<S321>/Integrator'
             *  DiscreteIntegrator: '<S321>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S224>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S224>/Stabilize' incorporates:
             *  ActionPort: '<S232>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S224>/Switch Case' incorporates:
             *  Chart: '<S325>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S224>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S224>/Stabilize' incorporates:
           *  ActionPort: '<S232>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Logic: '<S315>/Logical Operator' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S325>/Motion State' incorporates:
           *  Abs: '<S325>/Abs'
           *  Abs: '<S325>/Abs1'
           *  Constant: '<S335>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S335>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S324>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S324>/Hold Control' incorporates:
               *  ActionPort: '<S327>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S324>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S324>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S324>/Hold Control' incorporates:
             *  ActionPort: '<S327>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S324>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S324>/Brake Control' incorporates:
             *  ActionPort: '<S326>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S324>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S324>/Move Control' incorporates:
               *  ActionPort: '<S328>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S324>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S324>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S324>/Move Control' incorporates:
             *  ActionPort: '<S328>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S324>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S324>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S317>/Switch' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S317>/Constant4'
           *  Constant: '<S317>/Constant5'
           *  Gain: '<S317>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S317>/Saturation'
           *  SignalConversion: '<S30>/Signal Copy2'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S317>/Add'
           *  Sum: '<S317>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_DataTypeConversion_o = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S317>/Saturation' */
              rtb_Saturation1_hc = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S317>/Saturation' */
              rtb_Saturation1_hc = 0.0F;
            } else {
              /* Saturate: '<S317>/Saturation' incorporates:
               *  Constant: '<S317>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S30>/Signal Copy2'
               *  Sum: '<S317>/Sum'
               */
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_DataTypeConversion_o = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              rtb_Saturation1_hc), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S317>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S232>/Bus Assignment' incorporates:
           *  Constant: '<S232>/Constant'
           *  DataTypeConversion: '<S315>/Data Type Conversion'
           *  DiscreteIntegrator: '<S320>/Integrator1'
           *  DiscreteIntegrator: '<S321>/Integrator1'
           *  Product: '<S315>/Multiply'
           *  Product: '<S315>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S324>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S232>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S232>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S232>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S324>/Saturation' */

          /* BusAssignment: '<S232>/Bus Assignment' */
          FMS_Y.FMS_Out.throttle_cmd = rtb_DataTypeConversion_o;

          /* Product: '<S323>/Multiply1' incorporates:
           *  Constant: '<S323>/const1'
           *  DiscreteIntegrator: '<S321>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S319>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S319>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S323>/Add' incorporates:
           *  DiscreteIntegrator: '<S321>/Integrator1'
           *  Gain: '<S315>/Gain1'
           *  Gain: '<S319>/Gain'
           *  Sum: '<S321>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation1_hc * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Sign5_mn;

          /* Signum: '<S323>/Sign' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_1;
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
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d_g) *
                            FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Saturation1_hc + rtb_Sign5_mn;

          /* Sum: '<S323>/Add4' */
          rtb_Saturation1_d = (rtb_Switch_f_idx_1 - rtb_a_bx) + rtb_Sign5_mn;

          /* Sum: '<S323>/Add3' */
          rtb_Saturation_d = rtb_Switch_f_idx_1 + FMS_ConstB.d_g;

          /* Sum: '<S323>/Subtract1' */
          rtb_Switch_f_idx_1 -= FMS_ConstB.d_g;

          /* Signum: '<S323>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign1' */

          /* Signum: '<S323>/Sign2' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Switch_f_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign2' */

          /* Sum: '<S323>/Add5' incorporates:
           *  Gain: '<S323>/Gain2'
           *  Product: '<S323>/Multiply4'
           *  Sum: '<S323>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_d - rtb_Switch_f_idx_1) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S323>/Add6' */
          rtb_Saturation_d = rtb_a_bx + FMS_ConstB.d_g;

          /* Sum: '<S323>/Subtract3' */
          rtb_Saturation1_d = rtb_a_bx - FMS_ConstB.d_g;

          /* Product: '<S323>/Divide' */
          rtb_Switch_f_idx_2 = rtb_a_bx / FMS_ConstB.d_g;

          /* Signum: '<S323>/Sign5' incorporates:
           *  Signum: '<S323>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S323>/Sign6' */
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S323>/Sign6' */
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Divide_or = rtb_a_bx;

            /* Signum: '<S323>/Sign6' */
            rtb_Switch_f_idx_0 = rtb_a_bx;
          }

          /* End of Signum: '<S323>/Sign5' */

          /* Product: '<S322>/Multiply1' incorporates:
           *  Constant: '<S322>/const1'
           *  DiscreteIntegrator: '<S320>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S318>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S318>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S322>/Add' incorporates:
           *  DiscreteIntegrator: '<S320>/Integrator1'
           *  Gain: '<S315>/Gain'
           *  Gain: '<S318>/Gain'
           *  Sum: '<S320>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_hc * FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Sign5_mn;

          /* Signum: '<S322>/Sign' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_1;
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
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d_a) *
                            FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Saturation1_hc + rtb_Sign5_mn;

          /* Sum: '<S322>/Add4' */
          rtb_Sign5_mn += rtb_Switch_f_idx_1 - rtb_a_bx;

          /* Sum: '<S322>/Add3' */
          rtb_Saturation1_hc = rtb_Switch_f_idx_1 + FMS_ConstB.d_a;

          /* Sum: '<S322>/Subtract1' */
          rtb_Switch_f_idx_1 -= FMS_ConstB.d_a;

          /* Signum: '<S322>/Sign1' */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else {
            if (rtb_Saturation1_hc > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign1' */

          /* Signum: '<S322>/Sign2' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Switch_f_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign2' */

          /* Sum: '<S322>/Add5' incorporates:
           *  Gain: '<S322>/Gain2'
           *  Product: '<S322>/Multiply4'
           *  Sum: '<S322>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation1_hc - rtb_Switch_f_idx_1) * 0.5F *
            rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S320>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S320>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S321>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S321>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S323>/Sign3' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign3' */

          /* Signum: '<S323>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign4' */

          /* Update for DiscreteIntegrator: '<S321>/Integrator' incorporates:
           *  Constant: '<S323>/const'
           *  Gain: '<S323>/Gain3'
           *  Product: '<S323>/Multiply5'
           *  Product: '<S323>/Multiply6'
           *  Sum: '<S323>/Subtract4'
           *  Sum: '<S323>/Subtract5'
           *  Sum: '<S323>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Switch_f_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_o * ((rtb_Saturation_d - rtb_Saturation1_d) * 0.5F)
            - rtb_Switch_f_idx_0 * 12.566371F) * 0.004F;

          /* Sum: '<S322>/Subtract3' */
          rtb_Saturation_d = rtb_a_bx - FMS_ConstB.d_a;

          /* Sum: '<S322>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_a;

          /* Signum: '<S322>/Sign5' incorporates:
           *  Signum: '<S322>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S322>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S322>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_a_bx;

            /* Signum: '<S322>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_a_bx;
          }

          /* End of Signum: '<S322>/Sign5' */

          /* Signum: '<S322>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign3' */

          /* Signum: '<S322>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign4' */

          /* Update for DiscreteIntegrator: '<S320>/Integrator' incorporates:
           *  Constant: '<S322>/const'
           *  Gain: '<S322>/Gain3'
           *  Product: '<S322>/Divide'
           *  Product: '<S322>/Multiply5'
           *  Product: '<S322>/Multiply6'
           *  Sum: '<S322>/Subtract4'
           *  Sum: '<S322>/Subtract5'
           *  Sum: '<S322>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_a_bx / FMS_ConstB.d_a -
            rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_k * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S224>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S224>/Altitude' incorporates:
             *  ActionPort: '<S230>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S224>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S253>/Integrator'
             *  DiscreteIntegrator: '<S253>/Integrator1'
             *  DiscreteIntegrator: '<S254>/Integrator'
             *  DiscreteIntegrator: '<S254>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S224>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S224>/Altitude' incorporates:
             *  ActionPort: '<S230>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S224>/Switch Case' incorporates:
             *  Chart: '<S240>/Motion Status'
             *  Chart: '<S258>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S224>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S224>/Altitude' incorporates:
           *  ActionPort: '<S230>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S240>/Motion Status' incorporates:
           *  Abs: '<S240>/Abs'
           *  Abs: '<S240>/Abs1'
           *  Constant: '<S249>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S249>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S239>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S239>/Hold Control' incorporates:
               *  ActionPort: '<S242>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S239>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S239>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S239>/Hold Control' incorporates:
             *  ActionPort: '<S242>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S239>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S239>/Brake Control' incorporates:
             *  ActionPort: '<S241>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S239>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S239>/Move Control' incorporates:
             *  ActionPort: '<S243>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S239>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S239>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S236>/Switch' incorporates:
           *  Constant: '<S236>/Constant'
           *  Saturate: '<S239>/Saturation1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_d = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S239>/Saturation1' */
            rtb_Saturation_d = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S239>/Saturation1' */
            rtb_Saturation_d = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S239>/Saturation1' */
            rtb_Saturation_d = FMS_B.Merge_l;
          }

          /* End of Switch: '<S236>/Switch' */

          /* Logic: '<S237>/Logical Operator' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S258>/Motion State' incorporates:
           *  Abs: '<S258>/Abs'
           *  Abs: '<S258>/Abs1'
           *  Constant: '<S268>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S268>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S257>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S257>/Hold Control' incorporates:
               *  ActionPort: '<S260>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S257>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S257>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S257>/Hold Control' incorporates:
             *  ActionPort: '<S260>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S257>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S257>/Brake Control' incorporates:
             *  ActionPort: '<S259>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S257>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S257>/Move Control' incorporates:
               *  ActionPort: '<S261>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S257>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S257>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S257>/Move Control' incorporates:
             *  ActionPort: '<S261>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S257>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S257>/Switch Case' */

          /* BusAssignment: '<S230>/Bus Assignment' incorporates:
           *  Constant: '<S230>/Constant'
           *  DataTypeConversion: '<S237>/Data Type Conversion'
           *  DiscreteIntegrator: '<S253>/Integrator1'
           *  DiscreteIntegrator: '<S254>/Integrator1'
           *  Product: '<S237>/Multiply'
           *  Product: '<S237>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S257>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S257>/Saturation' */

          /* BusAssignment: '<S230>/Bus Assignment' */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_d;

          /* Product: '<S256>/Multiply1' incorporates:
           *  Constant: '<S256>/const1'
           *  DiscreteIntegrator: '<S254>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S252>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S252>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S256>/Add' incorporates:
           *  DiscreteIntegrator: '<S254>/Integrator1'
           *  Gain: '<S237>/Gain1'
           *  Gain: '<S252>/Gain'
           *  Sum: '<S254>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation1_hc * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Sign5_mn;

          /* Signum: '<S256>/Sign' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_1;
          }

          /* End of Signum: '<S256>/Sign' */

          /* Sum: '<S256>/Add2' incorporates:
           *  Abs: '<S256>/Abs'
           *  Gain: '<S256>/Gain'
           *  Gain: '<S256>/Gain1'
           *  Product: '<S256>/Multiply2'
           *  Product: '<S256>/Multiply3'
           *  Sqrt: '<S256>/Sqrt'
           *  Sum: '<S256>/Add1'
           *  Sum: '<S256>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d_o) *
                            FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
            rtb_Saturation1_hc + rtb_Sign5_mn;

          /* Sum: '<S256>/Add4' */
          rtb_Saturation1_d = (rtb_Switch_f_idx_1 - rtb_a_bx) + rtb_Sign5_mn;

          /* Sum: '<S256>/Add3' */
          rtb_Saturation_d = rtb_Switch_f_idx_1 + FMS_ConstB.d_o;

          /* Sum: '<S256>/Subtract1' */
          rtb_Switch_f_idx_1 -= FMS_ConstB.d_o;

          /* Signum: '<S256>/Sign1' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S256>/Sign1' */

          /* Signum: '<S256>/Sign2' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Switch_f_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S256>/Sign2' */

          /* Sum: '<S256>/Add5' incorporates:
           *  Gain: '<S256>/Gain2'
           *  Product: '<S256>/Multiply4'
           *  Sum: '<S256>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_d - rtb_Switch_f_idx_1) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S256>/Add6' */
          rtb_Saturation_d = rtb_a_bx + FMS_ConstB.d_o;

          /* Sum: '<S256>/Subtract3' */
          rtb_Saturation1_d = rtb_a_bx - FMS_ConstB.d_o;

          /* Product: '<S256>/Divide' */
          rtb_Switch_f_idx_2 = rtb_a_bx / FMS_ConstB.d_o;

          /* Signum: '<S256>/Sign5' incorporates:
           *  Signum: '<S256>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S256>/Sign6' */
            rtb_Switch_f_idx_0 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S256>/Sign6' */
            rtb_Switch_f_idx_0 = 1.0F;
          } else {
            rtb_Divide_or = rtb_a_bx;

            /* Signum: '<S256>/Sign6' */
            rtb_Switch_f_idx_0 = rtb_a_bx;
          }

          /* End of Signum: '<S256>/Sign5' */

          /* Product: '<S255>/Multiply1' incorporates:
           *  Constant: '<S255>/const1'
           *  DiscreteIntegrator: '<S253>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S251>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_hc = 0.0F;
          } else {
            rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S251>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S255>/Add' incorporates:
           *  DiscreteIntegrator: '<S253>/Integrator1'
           *  Gain: '<S237>/Gain'
           *  Gain: '<S251>/Gain'
           *  Sum: '<S253>/Subtract'
           */
          rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_hc * FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Sign5_mn;

          /* Signum: '<S255>/Sign' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Saturation1_hc = 1.0F;
          } else {
            rtb_Saturation1_hc = rtb_Switch_f_idx_1;
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
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d_c) *
                            FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
            rtb_Saturation1_hc + rtb_Sign5_mn;

          /* Sum: '<S255>/Add4' */
          rtb_Sign5_mn += rtb_Switch_f_idx_1 - rtb_a_bx;

          /* Sum: '<S255>/Add3' */
          rtb_Saturation1_hc = rtb_Switch_f_idx_1 + FMS_ConstB.d_c;

          /* Sum: '<S255>/Subtract1' */
          rtb_Switch_f_idx_1 -= FMS_ConstB.d_c;

          /* Signum: '<S255>/Sign1' */
          if (rtb_Saturation1_hc < 0.0F) {
            rtb_Saturation1_hc = -1.0F;
          } else {
            if (rtb_Saturation1_hc > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign1' */

          /* Signum: '<S255>/Sign2' */
          if (rtb_Switch_f_idx_1 < 0.0F) {
            rtb_Switch_f_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign2' */

          /* Sum: '<S255>/Add5' incorporates:
           *  Gain: '<S255>/Gain2'
           *  Product: '<S255>/Multiply4'
           *  Sum: '<S255>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation1_hc - rtb_Switch_f_idx_1) * 0.5F *
            rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S253>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S253>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S254>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S254>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S256>/Sign3' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S256>/Sign3' */

          /* Signum: '<S256>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S256>/Sign4' */

          /* Update for DiscreteIntegrator: '<S254>/Integrator' incorporates:
           *  Constant: '<S256>/const'
           *  Gain: '<S256>/Gain3'
           *  Product: '<S256>/Multiply5'
           *  Product: '<S256>/Multiply6'
           *  Sum: '<S256>/Subtract4'
           *  Sum: '<S256>/Subtract5'
           *  Sum: '<S256>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_f_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_c * ((rtb_Saturation_d - rtb_Saturation1_d) * 0.5F)
            - rtb_Switch_f_idx_0 * 12.566371F) * 0.004F;

          /* Sum: '<S255>/Subtract3' */
          rtb_Saturation_d = rtb_a_bx - FMS_ConstB.d_c;

          /* Sum: '<S255>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_c;

          /* Signum: '<S255>/Sign5' incorporates:
           *  Signum: '<S255>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Switch_f_idx_0 = -1.0F;

            /* Signum: '<S255>/Sign6' */
            rtb_Switch_f_idx_2 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Switch_f_idx_0 = 1.0F;

            /* Signum: '<S255>/Sign6' */
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            rtb_Switch_f_idx_0 = rtb_a_bx;

            /* Signum: '<S255>/Sign6' */
            rtb_Switch_f_idx_2 = rtb_a_bx;
          }

          /* End of Signum: '<S255>/Sign5' */

          /* Signum: '<S255>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign3' */

          /* Signum: '<S255>/Sign4' */
          if (rtb_Saturation_d < 0.0F) {
            rtb_Saturation_d = -1.0F;
          } else {
            if (rtb_Saturation_d > 0.0F) {
              rtb_Saturation_d = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign4' */

          /* Update for DiscreteIntegrator: '<S253>/Integrator' incorporates:
           *  Constant: '<S255>/const'
           *  Gain: '<S255>/Gain3'
           *  Product: '<S255>/Divide'
           *  Product: '<S255>/Multiply5'
           *  Product: '<S255>/Multiply6'
           *  Sum: '<S255>/Subtract4'
           *  Sum: '<S255>/Subtract5'
           *  Sum: '<S255>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_a_bx / FMS_ConstB.d_c -
            rtb_Switch_f_idx_0) * FMS_ConstB.Gain4_h * ((rtb_Saturation1_d -
            rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S224>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S224>/Position' incorporates:
             *  ActionPort: '<S231>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S224>/Switch Case' incorporates:
             *  Chart: '<S274>/Motion Status'
             *  Chart: '<S286>/Motion State'
             *  Chart: '<S299>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S224>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S224>/Position' incorporates:
           *  ActionPort: '<S231>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S274>/Motion Status' incorporates:
           *  Abs: '<S274>/Abs'
           *  Abs: '<S274>/Abs1'
           *  Constant: '<S283>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S283>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S273>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S273>/Hold Control' incorporates:
               *  ActionPort: '<S276>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S273>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S273>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S273>/Hold Control' incorporates:
             *  ActionPort: '<S276>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S273>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S273>/Brake Control' incorporates:
             *  ActionPort: '<S275>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S273>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S273>/Move Control' incorporates:
             *  ActionPort: '<S277>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S273>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S273>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S286>/Motion State' incorporates:
           *  Abs: '<S286>/Abs'
           *  Abs: '<S286>/Abs1'
           *  Constant: '<S296>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S296>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S299>/Logical Operator' incorporates:
           *  Abs: '<S299>/Abs1'
           *  Abs: '<S299>/Abs2'
           *  Constant: '<S312>/Constant'
           *  Constant: '<S313>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S312>/Compare'
           *  RelationalOperator: '<S313>/Compare'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Chart: '<S299>/Motion State' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S299>/Square'
           *  Math: '<S299>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S299>/Sqrt'
           *  Sum: '<S299>/Add'
           */
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

              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                         FMS_U.INS_Out.ve) <= 0.2) ||
                  (FMS_DW.temporalCounter_i1_g >= 2000U)) {
                FMS_DW.is_c16_FMS = FMS_IN_Hold_od;
                rtb_state_fg = MotionState_Hold;
              } else {
                if (rtb_FixPtRelationalOperator_me) {
                  FMS_DW.is_c16_FMS = FMS_IN_Move_p;
                  rtb_state_fg = MotionState_Move;
                }
              }

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
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

          /* End of Chart: '<S299>/Motion State' */

          /* SwitchCase: '<S298>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
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
              /* SystemReset for IfAction SubSystem: '<S298>/Hold Control' incorporates:
               *  ActionPort: '<S301>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S298>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_jz);

              /* End of SystemReset for SubSystem: '<S298>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S298>/Hold Control' incorporates:
             *  ActionPort: '<S301>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge,
                              &FMS_ConstB.HoldControl_jz, &FMS_DW.HoldControl_jz);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S298>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S298>/Brake Control' incorporates:
             *  ActionPort: '<S300>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge);

            /* End of Outputs for SubSystem: '<S298>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S298>/Move Control' incorporates:
               *  ActionPort: '<S302>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S308>/Integrator'
               *  DiscreteIntegrator: '<S308>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S298>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S298>/Move Control' incorporates:
             *  ActionPort: '<S302>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* DeadZone: '<S306>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S30>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_hc = 0.0F;
            } else {
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S306>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Gain: '<S306>/Gain' */
            rtb_Saturation_d = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
              rtb_Saturation1_hc;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* DeadZone: '<S307>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S30>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
                FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_hc = 0.0F;
            } else {
              rtb_Saturation1_hc = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S307>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Gain: '<S307>/Gain' */
            rtb_Switch_f_idx_0 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation1_hc;

            /* Sum: '<S309>/Sum of Elements' incorporates:
             *  Math: '<S309>/Square'
             *  SignalConversion: '<S309>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S310>/Sum of Elements'
             *  Switch: '<S302>/Switch'
             */
            rtb_Saturation1_hc = rtb_Saturation_d * rtb_Saturation_d +
              rtb_Switch_f_idx_0 * rtb_Switch_f_idx_0;

            /* Switch: '<S302>/Switch' incorporates:
             *  Product: '<S310>/Divide'
             *  Sqrt: '<S309>/Sqrt'
             *  Sum: '<S309>/Sum of Elements'
             */
            if (sqrtf(rtb_Saturation1_hc) > 1.0F) {
              /* Math: '<S310>/Math Function1'
               *
               * About '<S310>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Saturation1_hc < 0.0F) {
                rtb_Saturation1_d = -sqrtf(fabsf(rtb_Saturation1_hc));
              } else {
                rtb_Saturation1_d = sqrtf(rtb_Saturation1_hc);
              }

              /* End of Math: '<S310>/Math Function1' */

              /* Switch: '<S310>/Switch' incorporates:
               *  Constant: '<S310>/Constant'
               *  Product: '<S310>/Product'
               */
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Switch_d0[0] = rtb_Saturation_d;
                rtb_Switch_d0[1] = rtb_Switch_f_idx_0;
                rtb_Switch_d0[2] = rtb_Saturation1_d;
              } else {
                rtb_Switch_d0[0] = 0.0F;
                rtb_Switch_d0[1] = 0.0F;
                rtb_Switch_d0[2] = 1.0F;
              }

              /* End of Switch: '<S310>/Switch' */
              rtb_Saturation_d = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_Switch_f_idx_0 = rtb_Switch_d0[1] / rtb_Switch_d0[2];
            }

            /* Product: '<S311>/Multiply1' incorporates:
             *  Constant: '<S311>/const1'
             *  DiscreteIntegrator: '<S308>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.05F;

            /* Sum: '<S311>/Add' incorporates:
             *  DiscreteIntegrator: '<S308>/Integrator1'
             *  Gain: '<S302>/Gain6'
             *  Sum: '<S308>/Subtract'
             */
            rtb_Sign5_mn = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM *
                            rtb_Saturation_d) + rtb_Saturation1_d;

            /* Signum: '<S311>/Sign' */
            if (rtb_Sign5_mn < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else if (rtb_Sign5_mn > 0.0F) {
              rtb_Saturation_d = 1.0F;
            } else {
              rtb_Saturation_d = rtb_Sign5_mn;
            }

            /* Sum: '<S311>/Add2' incorporates:
             *  Abs: '<S311>/Abs'
             *  Gain: '<S311>/Gain'
             *  Gain: '<S311>/Gain1'
             *  Product: '<S311>/Multiply2'
             *  Product: '<S311>/Multiply3'
             *  Sqrt: '<S311>/Sqrt'
             *  Sum: '<S311>/Add1'
             *  Sum: '<S311>/Subtract'
             */
            rtb_Switch_f_idx_1 = (sqrtf((8.0F * fabsf(rtb_Sign5_mn) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_d + rtb_Saturation1_d;

            /* Sum: '<S311>/Add4' */
            rtb_Saturation1_d += rtb_Sign5_mn - rtb_Switch_f_idx_1;

            /* Sum: '<S311>/Add3' */
            rtb_Saturation_d = rtb_Sign5_mn + FMS_ConstB.d;

            /* Sum: '<S311>/Subtract1' */
            rtb_Sign5_mn -= FMS_ConstB.d;

            /* Signum: '<S311>/Sign1' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
              }
            }

            /* Signum: '<S311>/Sign2' */
            if (rtb_Sign5_mn < 0.0F) {
              rtb_Sign5_mn = -1.0F;
            } else {
              if (rtb_Sign5_mn > 0.0F) {
                rtb_Sign5_mn = 1.0F;
              }
            }

            /* Sum: '<S311>/Add5' incorporates:
             *  Gain: '<S311>/Gain2'
             *  Product: '<S311>/Multiply4'
             *  Sum: '<S311>/Subtract2'
             */
            rtb_Switch_f_idx_1 += (rtb_Saturation_d - rtb_Sign5_mn) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S308>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S308>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S308>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S308>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S311>/Sign4' incorporates:
             *  Sum: '<S311>/Subtract3'
             */
            rtb_Saturation_d = rtb_Switch_f_idx_1 - FMS_ConstB.d;

            /* Signum: '<S311>/Sign3' incorporates:
             *  Sum: '<S311>/Add6'
             */
            rtb_Saturation1_d = rtb_Switch_f_idx_1 + FMS_ConstB.d;

            /* Signum: '<S311>/Sign5' */
            if (rtb_Switch_f_idx_1 < 0.0F) {
              rtb_Saturation1_hc = -1.0F;
            } else if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            } else {
              rtb_Saturation1_hc = rtb_Switch_f_idx_1;
            }

            /* Signum: '<S311>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S311>/Sign4' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
              }
            }

            /* Signum: '<S311>/Sign6' */
            if (rtb_Switch_f_idx_1 < 0.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            } else if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            } else {
              rtb_Switch_f_idx_2 = rtb_Switch_f_idx_1;
            }

            /* Update for DiscreteIntegrator: '<S308>/Integrator' incorporates:
             *  Constant: '<S311>/const'
             *  Gain: '<S311>/Gain3'
             *  Product: '<S311>/Divide'
             *  Product: '<S311>/Multiply5'
             *  Product: '<S311>/Multiply6'
             *  Sum: '<S311>/Subtract4'
             *  Sum: '<S311>/Subtract5'
             *  Sum: '<S311>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Switch_f_idx_1 / FMS_ConstB.d -
              rtb_Saturation1_hc) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 58.836F) * 0.004F;

            /* Product: '<S311>/Multiply1' incorporates:
             *  Constant: '<S311>/const1'
             *  DiscreteIntegrator: '<S308>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.05F;

            /* Sum: '<S311>/Add' incorporates:
             *  DiscreteIntegrator: '<S308>/Integrator1'
             *  Gain: '<S302>/Gain6'
             *  Sum: '<S308>/Subtract'
             */
            rtb_Sign5_mn = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                            rtb_Switch_f_idx_0) + rtb_Saturation1_d;

            /* Signum: '<S311>/Sign' */
            if (rtb_Sign5_mn < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else if (rtb_Sign5_mn > 0.0F) {
              rtb_Saturation_d = 1.0F;
            } else {
              rtb_Saturation_d = rtb_Sign5_mn;
            }

            /* Sum: '<S311>/Add2' incorporates:
             *  Abs: '<S311>/Abs'
             *  Gain: '<S311>/Gain'
             *  Gain: '<S311>/Gain1'
             *  Product: '<S311>/Multiply2'
             *  Product: '<S311>/Multiply3'
             *  Sqrt: '<S311>/Sqrt'
             *  Sum: '<S311>/Add1'
             *  Sum: '<S311>/Subtract'
             */
            rtb_Switch_f_idx_1 = (sqrtf((8.0F * fabsf(rtb_Sign5_mn) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_d + rtb_Saturation1_d;

            /* Sum: '<S311>/Add4' */
            rtb_Saturation1_d += rtb_Sign5_mn - rtb_Switch_f_idx_1;

            /* Sum: '<S311>/Add3' */
            rtb_Saturation_d = rtb_Sign5_mn + FMS_ConstB.d;

            /* Sum: '<S311>/Subtract1' */
            rtb_Sign5_mn -= FMS_ConstB.d;

            /* Signum: '<S311>/Sign1' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
              }
            }

            /* Signum: '<S311>/Sign2' */
            if (rtb_Sign5_mn < 0.0F) {
              rtb_Sign5_mn = -1.0F;
            } else {
              if (rtb_Sign5_mn > 0.0F) {
                rtb_Sign5_mn = 1.0F;
              }
            }

            /* Sum: '<S311>/Add5' incorporates:
             *  Gain: '<S311>/Gain2'
             *  Product: '<S311>/Multiply4'
             *  Sum: '<S311>/Subtract2'
             */
            rtb_Switch_f_idx_1 += (rtb_Saturation_d - rtb_Sign5_mn) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S308>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S308>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S308>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S308>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S311>/Sign4' incorporates:
             *  Sum: '<S311>/Subtract3'
             */
            rtb_Saturation_d = rtb_Switch_f_idx_1 - FMS_ConstB.d;

            /* Signum: '<S311>/Sign3' incorporates:
             *  Sum: '<S311>/Add6'
             */
            rtb_Saturation1_d = rtb_Switch_f_idx_1 + FMS_ConstB.d;

            /* Signum: '<S311>/Sign5' */
            if (rtb_Switch_f_idx_1 < 0.0F) {
              rtb_Saturation1_hc = -1.0F;
            } else if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Saturation1_hc = 1.0F;
            } else {
              rtb_Saturation1_hc = rtb_Switch_f_idx_1;
            }

            /* Signum: '<S311>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S311>/Sign4' */
            if (rtb_Saturation_d < 0.0F) {
              rtb_Saturation_d = -1.0F;
            } else {
              if (rtb_Saturation_d > 0.0F) {
                rtb_Saturation_d = 1.0F;
              }
            }

            /* Signum: '<S311>/Sign6' */
            if (rtb_Switch_f_idx_1 < 0.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            } else if (rtb_Switch_f_idx_1 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            } else {
              rtb_Switch_f_idx_2 = rtb_Switch_f_idx_1;
            }

            /* Update for DiscreteIntegrator: '<S308>/Integrator' incorporates:
             *  Constant: '<S311>/const'
             *  Gain: '<S311>/Gain3'
             *  Product: '<S311>/Divide'
             *  Product: '<S311>/Multiply5'
             *  Product: '<S311>/Multiply6'
             *  Sum: '<S311>/Subtract4'
             *  Sum: '<S311>/Subtract5'
             *  Sum: '<S311>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Switch_f_idx_1 / FMS_ConstB.d -
              rtb_Saturation1_hc) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_d) * 0.5F) - rtb_Switch_f_idx_2 * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S298>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S298>/Switch Case' */

          /* SwitchCase: '<S285>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S285>/Hold Control' incorporates:
               *  ActionPort: '<S288>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S285>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S285>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S285>/Hold Control' incorporates:
             *  ActionPort: '<S288>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S285>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S285>/Brake Control' incorporates:
             *  ActionPort: '<S287>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S285>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S285>/Move Control' incorporates:
               *  ActionPort: '<S289>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S285>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S285>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S285>/Move Control' incorporates:
             *  ActionPort: '<S289>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S285>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S285>/Switch Case' */

          /* BusAssignment: '<S231>/Bus Assignment' incorporates:
           *  Constant: '<S231>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S285>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S285>/Saturation' */

          /* Saturate: '<S298>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S298>/Saturation1' */

          /* Saturate: '<S273>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S273>/Saturation1' */
          /* End of Outputs for SubSystem: '<S224>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S224>/Unknown' incorporates:
           *  ActionPort: '<S233>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S224>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S224>/Switch Case' */
        /* End of Outputs for SubSystem: '<S37>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S37>/Manual' incorporates:
         *  ActionPort: '<S226>/Action Port'
         */
        /* BusAssignment: '<S226>/Bus Assignment' incorporates:
         *  Constant: '<S226>/Constant'
         *  Constant: '<S226>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S37>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S228>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S37>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S37>/Switch Case' */
      /* End of Outputs for SubSystem: '<S31>/MC_Mode' */
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
   *  DiscreteIntegrator: '<S654>/Discrete-Time Integrator'
   *  Gain: '<S32>/Gain'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy8Inport1'
   *  Sum: '<S32>/Sum'
   *  Sum: '<S32>/Sum1'
   */
  FMS_Y.FMS_Out.ctrl_mode = (uint8_T)((uint32_T)(uint8_T)((uint8_T)
    FMS_B.vtol_state << 6) + FMS_Y.FMS_Out.ctrl_mode);

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

  /* Update for DiscreteIntegrator: '<S654>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S654>/Constant'
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
  rtb_Saturation1_hc = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation1_hc < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Saturation1_hc;
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
  rtb_Saturation1_hc = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation1_hc < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Saturation1_hc;
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
    FMS_B.vtol_state = VTOLState_Multicopter;
    FMS_B.dd1 = VTOLMode_Multicopter;
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

  /* Start for IfAction SubSystem: '<S31>/FW_Mode' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;

  /* Start for IfAction SubSystem: '<S36>/SubMode' */
  /* Start for SwitchCase: '<S41>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S36>/SubMode' */

  /* Start for IfAction SubSystem: '<S36>/Auto' */
  /* Start for SwitchCase: '<S39>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S36>/Auto' */

  /* Start for IfAction SubSystem: '<S36>/Assist' */
  /* Start for SwitchCase: '<S38>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_as = -1;

  /* Start for IfAction SubSystem: '<S38>/Altitude' */
  /* Start for SwitchCase: '<S51>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;

  /* End of Start for SubSystem: '<S38>/Altitude' */

  /* Start for IfAction SubSystem: '<S38>/Position' */
  /* Start for SwitchCase: '<S86>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S72>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S38>/Position' */
  /* End of Start for SubSystem: '<S36>/Assist' */
  /* End of Start for SubSystem: '<S31>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S31>/MC_Mode' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S37>/SubMode' */
  /* Start for SwitchCase: '<S227>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S227>/Return' */
  /* Start for SwitchCase: '<S612>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S602>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S227>/Return' */

  /* Start for IfAction SubSystem: '<S227>/Hold' */
  /* Start for SwitchCase: '<S551>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S529>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S539>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;

  /* End of Start for SubSystem: '<S227>/Hold' */
  /* End of Start for SubSystem: '<S37>/SubMode' */

  /* Start for IfAction SubSystem: '<S37>/Auto' */
  /* Start for SwitchCase: '<S225>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S225>/Mission' */
  /* Start for Resettable SubSystem: '<S337>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S385>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* Start for SwitchCase: '<S375>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S337>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S225>/Mission' */
  /* End of Start for SubSystem: '<S37>/Auto' */

  /* Start for IfAction SubSystem: '<S37>/Assist' */
  /* Start for SwitchCase: '<S224>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S224>/Stabilize' */
  /* Start for SwitchCase: '<S324>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S224>/Stabilize' */

  /* Start for IfAction SubSystem: '<S224>/Altitude' */
  /* Start for SwitchCase: '<S239>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S257>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S224>/Altitude' */

  /* Start for IfAction SubSystem: '<S224>/Position' */
  /* Start for SwitchCase: '<S273>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S298>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S285>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S224>/Position' */
  /* End of Start for SubSystem: '<S37>/Assist' */
  /* End of Start for SubSystem: '<S31>/MC_Mode' */
  /* End of Start for SubSystem: '<S29>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

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
  FMS_DW.temporalCounter_i2 = 0U;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
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
  /* SystemInitialize for IfAction SubSystem: '<S31>/FW_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S36>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S41>/Hold' */
  /* InitializeConditions for Delay: '<S167>/start_vel' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S162>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S41>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S36>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S39>/Mission' */
  /* InitializeConditions for UnitDelay: '<S131>/Delay Input1'
   *
   * Block description for '<S131>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S39>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S36>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S38>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S38>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S38>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* SystemInitialize for Chart: '<S52>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S51>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S51>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S51>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S51>/Move Control' */

  /* SystemInitialize for Merge: '<S51>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S38>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S38>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S84>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S84>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S73>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S87>/Motion State' */
  FMS_DW.temporalCounter_i1_ie = 0U;
  FMS_DW.is_active_c26_FMS = 0U;
  FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S86>/Hold Control' */
  /* InitializeConditions for Delay: '<S93>/start_vel' */
  FMS_DW.icLoad_g = 1U;

  /* InitializeConditions for Delay: '<S93>/start_wp' */
  FMS_DW.icLoad_e = 1U;

  /* End of SystemInitialize for SubSystem: '<S86>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S86>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S110>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Integrator' */
  FMS_DW.Integrator_DSTATE_f1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S86>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S72>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S72>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S72>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S72>/Move Control' */

  /* SystemInitialize for Merge: '<S72>/Merge' */
  FMS_B.Merge_f = 0.0F;

  /* SystemInitialize for Merge: '<S86>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S38>/Position' */
  /* End of SystemInitialize for SubSystem: '<S36>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S31>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S31>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S37>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S227>/Takeoff' */
  /* InitializeConditions for Delay: '<S652>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S648>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S648>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S227>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S227>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S567>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S567>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S227>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S227>/Return' */
  /* InitializeConditions for Delay: '<S597>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S598>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S593>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S639>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S576>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S579>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;

  /* InitializeConditions for Delay: '<S575>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S579>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S613>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S612>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S612>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S612>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S612>/Move Control' */

  /* SystemInitialize for Merge: '<S612>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S603>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S602>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S602>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S602>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S602>/Move Control' */

  /* SystemInitialize for Merge: '<S602>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S227>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S227>/Hold' */
  /* SystemInitialize for Chart: '<S530>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S540>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S552>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S551>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S551>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S551>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S551>/Move Control' */

  /* SystemInitialize for Merge: '<S551>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S529>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S529>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S529>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S529>/Move Control' */

  /* SystemInitialize for Merge: '<S529>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S539>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S539>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S539>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S539>/Move Control' */

  /* SystemInitialize for Merge: '<S539>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S227>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S37>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S225>/Mission' */
  /* InitializeConditions for UnitDelay: '<S340>/Delay Input1'
   *
   * Block description for '<S340>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S337>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S367>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S368>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S363>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S345>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S348>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S348>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S386>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S385>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_fy);

  /* End of SystemInitialize for SubSystem: '<S385>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S385>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S385>/Move Control' */

  /* SystemInitialize for Merge: '<S385>/Merge' */
  FMS_B.Merge_ls[0] = 0.0F;
  FMS_B.Merge_ls[1] = 0.0F;

  /* SystemInitialize for Chart: '<S376>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for IfAction SubSystem: '<S375>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bf);

  /* End of SystemInitialize for SubSystem: '<S375>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S375>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c0);

  /* End of SystemInitialize for SubSystem: '<S375>/Move Control' */

  /* SystemInitialize for Merge: '<S375>/Merge' */
  FMS_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S337>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S225>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S37>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S224>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S325>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S324>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S324>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S324>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S324>/Move Control' */

  /* SystemInitialize for Merge: '<S324>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S224>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S224>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S253>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S254>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S254>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S253>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S240>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S239>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S239>/Hold Control' */

  /* SystemInitialize for Merge: '<S239>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S258>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S257>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S257>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S257>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S257>/Move Control' */

  /* SystemInitialize for Merge: '<S257>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S224>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S224>/Position' */
  /* SystemInitialize for Chart: '<S274>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S273>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S273>/Hold Control' */

  /* SystemInitialize for Chart: '<S286>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S299>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S298>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_jz);

  /* End of SystemInitialize for SubSystem: '<S298>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S298>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S308>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S308>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Move Control' */

  /* SystemInitialize for Merge: '<S298>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S298>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S308>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S308>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Move Control' */

  /* SystemInitialize for Merge: '<S298>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S273>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S285>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S285>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S285>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S285>/Move Control' */

  /* SystemInitialize for Merge: '<S285>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S224>/Position' */
  /* End of SystemInitialize for SubSystem: '<S37>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S31>/MC_Mode' */
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
