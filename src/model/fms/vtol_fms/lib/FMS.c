/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2244
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul 11 10:13:10 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S73>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S635>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S645>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S354>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S108>/Motion State' */
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
#define FMS_IN_BackwardTrans           ((uint8_T)1U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Fixwing                 ((uint8_T)2U)
#define FMS_IN_ForwardTrans            ((uint8_T)3U)
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
#define FMS_IN_Multicopter             ((uint8_T)4U)
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
  ,                                    /* home */
  0U                                   /* error */
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
                                        *   '<S4>/Constant1'
                                        *   '<S9>/ACCEPT_R'
                                        *   '<S9>/MC_ACCEPT_R'
                                        *   '<S38>/Constant'
                                        *   '<S688>/Constant'
                                        *   '<S184>/Gain'
                                        *   '<S184>/Gain4'
                                        *   '<S184>/Gain5'
                                        *   '<S188>/Constant4'
                                        *   '<S189>/Constant4'
                                        *   '<S555>/L1'
                                        *   '<S68>/Gain'
                                        *   '<S70>/Gain'
                                        *   '<S71>/Gain1'
                                        *   '<S89>/Gain'
                                        *   '<S91>/Gain1'
                                        *   '<S145>/Gain'
                                        *   '<S145>/Gain1'
                                        *   '<S146>/Gain1'
                                        *   '<S161>/Constant4'
                                        *   '<S191>/Gain2'
                                        *   '<S191>/Saturation1'
                                        *   '<S192>/L1'
                                        *   '<S192>/R'
                                        *   '<S192>/Saturation1'
                                        *   '<S209>/Gain'
                                        *   '<S209>/Saturation1'
                                        *   '<S231>/Gain'
                                        *   '<S231>/Saturation1'
                                        *   '<S266>/Gain'
                                        *   '<S266>/Gain1'
                                        *   '<S344>/Gain'
                                        *   '<S344>/Gain1'
                                        *   '<S346>/Constant'
                                        *   '<S370>/L1'
                                        *   '<S448>/Saturation'
                                        *   '<S449>/Saturation1'
                                        *   '<S449>/Saturation2'
                                        *   '<S449>/Saturation3'
                                        *   '<S596>/Land_Speed'
                                        *   '<S597>/Saturation1'
                                        *   '<S676>/Takeoff_Speed'
                                        *   '<S677>/Gain2'
                                        *   '<S677>/Saturation1'
                                        *   '<S72>/Saturation1'
                                        *   '<S83>/Dead Zone'
                                        *   '<S83>/Gain'
                                        *   '<S86>/Dead Zone'
                                        *   '<S86>/Gain'
                                        *   '<S93>/Saturation1'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S107>/Saturation1'
                                        *   '<S148>/Dead Zone'
                                        *   '<S148>/Gain'
                                        *   '<S149>/Dead Zone'
                                        *   '<S149>/Gain'
                                        *   '<S154>/Dead Zone'
                                        *   '<S154>/Gain'
                                        *   '<S162>/Gain'
                                        *   '<S162>/Saturation1'
                                        *   '<S214>/L1'
                                        *   '<S214>/Saturation1'
                                        *   '<S236>/L1'
                                        *   '<S236>/Saturation1'
                                        *   '<S268>/Saturation1'
                                        *   '<S280>/Dead Zone'
                                        *   '<S280>/Gain'
                                        *   '<S281>/Dead Zone'
                                        *   '<S281>/Gain'
                                        *   '<S286>/Saturation'
                                        *   '<S302>/Saturation1'
                                        *   '<S314>/Saturation'
                                        *   '<S327>/Saturation1'
                                        *   '<S347>/Dead Zone'
                                        *   '<S347>/Gain'
                                        *   '<S348>/Dead Zone'
                                        *   '<S348>/Gain'
                                        *   '<S353>/Saturation'
                                        *   '<S504>/Gain2'
                                        *   '<S511>/Gain1'
                                        *   '<S511>/Gain2'
                                        *   '<S561>/Saturation1'
                                        *   '<S571>/Saturation'
                                        *   '<S583>/Saturation1'
                                        *   '<S598>/Constant'
                                        *   '<S601>/Gain2'
                                        *   '<S625>/Constant'
                                        *   '<S625>/vel'
                                        *   '<S625>/Acceleration_Speed'
                                        *   '<S625>/Saturation'
                                        *   '<S625>/Switch'
                                        *   '<S629>/Constant'
                                        *   '<S75>/Gain2'
                                        *   '<S76>/Gain1'
                                        *   '<S81>/Constant'
                                        *   '<S96>/Gain2'
                                        *   '<S97>/Gain1'
                                        *   '<S102>/Constant'
                                        *   '<S110>/L1'
                                        *   '<S111>/Gain6'
                                        *   '<S140>/Constant'
                                        *   '<S141>/Constant'
                                        *   '<S167>/L1'
                                        *   '<S167>/Saturation1'
                                        *   '<S271>/Gain2'
                                        *   '<S272>/Gain1'
                                        *   '<S278>/Constant'
                                        *   '<S289>/Gain2'
                                        *   '<S290>/Gain1'
                                        *   '<S297>/Constant'
                                        *   '<S305>/Gain2'
                                        *   '<S306>/Gain1'
                                        *   '<S312>/Constant'
                                        *   '<S317>/Gain2'
                                        *   '<S318>/Gain1'
                                        *   '<S325>/Constant'
                                        *   '<S330>/Gain2'
                                        *   '<S331>/Gain6'
                                        *   '<S341>/Constant'
                                        *   '<S342>/Constant'
                                        *   '<S356>/Gain2'
                                        *   '<S357>/Gain1'
                                        *   '<S364>/Constant'
                                        *   '<S389>/Gain'
                                        *   '<S389>/Saturation1'
                                        *   '<S392>/Constant'
                                        *   '<S392>/vel'
                                        *   '<S392>/Acceleration_Speed'
                                        *   '<S392>/Saturation'
                                        *   '<S392>/Switch'
                                        *   '<S396>/Constant'
                                        *   '<S564>/Gain2'
                                        *   '<S565>/Gain1'
                                        *   '<S574>/Gain2'
                                        *   '<S575>/Gain1'
                                        *   '<S586>/Gain2'
                                        *   '<S587>/Gain6'
                                        *   '<S610>/Gain2'
                                        *   '<S610>/Saturation'
                                        *   '<S611>/Integrator'
                                        *   '<S78>/Dead Zone'
                                        *   '<S78>/Gain'
                                        *   '<S99>/Dead Zone'
                                        *   '<S99>/Gain'
                                        *   '<S137>/Dead Zone'
                                        *   '<S137>/Gain'
                                        *   '<S274>/Land_Speed'
                                        *   '<S275>/Constant'
                                        *   '<S277>/Dead Zone'
                                        *   '<S277>/Gain'
                                        *   '<S294>/Dead Zone'
                                        *   '<S294>/Gain'
                                        *   '<S308>/Land_Speed'
                                        *   '<S309>/Constant'
                                        *   '<S311>/Dead Zone'
                                        *   '<S311>/Gain'
                                        *   '<S322>/Dead Zone'
                                        *   '<S322>/Gain'
                                        *   '<S335>/Dead Zone'
                                        *   '<S335>/Gain'
                                        *   '<S336>/Dead Zone'
                                        *   '<S336>/Gain'
                                        *   '<S361>/Dead Zone'
                                        *   '<S361>/Gain'
                                        *   '<S376>/Gain2'
                                        *   '<S376>/Saturation'
                                        *   '<S377>/Integrator'
                                        *   '<S567>/Dead Zone'
                                        *   '<S567>/Gain'
                                        *   '<S579>/Dead Zone'
                                        *   '<S579>/Gain'
                                        *   '<S591>/Dead Zone'
                                        *   '<S591>/Gain'
                                        *   '<S592>/Dead Zone'
                                        *   '<S592>/Gain'
                                        *   '<S634>/Saturation1'
                                        *   '<S644>/Saturation1'
                                        *   '<S404>/Saturation1'
                                        *   '<S414>/Saturation1'
                                        *   '<S637>/Gain2'
                                        *   '<S638>/Gain1'
                                        *   '<S647>/Gain2'
                                        *   '<S648>/Gain6'
                                        *   '<S407>/Gain2'
                                        *   '<S408>/Gain1'
                                        *   '<S417>/Gain2'
                                        *   '<S418>/Gain6'
                                        *   '<S640>/Dead Zone'
                                        *   '<S640>/Gain'
                                        *   '<S652>/Dead Zone'
                                        *   '<S652>/Gain'
                                        *   '<S653>/Dead Zone'
                                        *   '<S653>/Gain'
                                        *   '<S410>/Dead Zone'
                                        *   '<S410>/Gain'
                                        *   '<S422>/Dead Zone'
                                        *   '<S422>/Gain'
                                        *   '<S423>/Dead Zone'
                                        *   '<S423>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S24>/Constant1'
                                        *   '<S686>/Constant'
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
static void FMS_sf_msg_send_VTOL_M(void);
static boolean_T FMS_CheckModeValid(VTOLMode vtol_mode_in, VTOLState
  vtol_state_in);
static boolean_T FMS_sf_msg_pop_VTOL_M(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void FMS_sf_msg_discard_VTOL_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for atomic system:
 *    '<S238>/NearbyRefWP'
 *    '<S216>/NearbyRefWP'
 *    '<S169>/NearbyRefWP'
 *    '<S627>/NearbyRefWP'
 *    '<S394>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S242>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S238>/OutRegionRegWP'
 *    '<S216>/OutRegionRegWP'
 *    '<S169>/OutRegionRegWP'
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

  /* SignalConversion: '<S243>/TmpSignal ConversionAt SFunction Inport3' */
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
    /* SignalConversion: '<S243>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S238>/SearchL1RefWP'
 *    '<S216>/SearchL1RefWP'
 *    '<S169>/SearchL1RefWP'
 *    '<S394>/SearchL1RefWP'
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

  /* SignalConversion: '<S244>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S62>/Unknown'
 *    '<S60>/Unknown'
 *    '<S59>/Unknown'
 *    '<S47>/Unknown'
 *    '<S256>/Unknown'
 *    '<S254>/Unknown'
 *    '<S253>/Unknown'
 *    '<S48>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S190>/Bus Assignment' incorporates:
   *  Constant: '<S190>/Constant'
   *  Constant: '<S190>/Constant2'
   *  SignalConversion: '<S190>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S190>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S72>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S75>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S72>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S75>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S72>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S75>/Delay' incorporates:
   *  Gain: '<S77>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S75>/Gain2' incorporates:
   *  Delay: '<S75>/Delay'
   *  Gain: '<S77>/Gain'
   *  Sum: '<S75>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S75>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S72>/Brake Control'
 *    '<S93>/Brake Control'
 *    '<S634>/Brake Control'
 *    '<S561>/Brake Control'
 *    '<S571>/Brake Control'
 *    '<S404>/Brake Control'
 *    '<S353>/Brake Control'
 *    '<S268>/Brake Control'
 *    '<S286>/Brake Control'
 *    '<S302>/Brake Control'
 *    '<S314>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S74>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S74>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S72>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S79>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S79>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S72>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S79>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S79>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S72>/Move Control'
 *    '<S93>/Move Control'
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

  /* Product: '<S80>/Multiply1' incorporates:
   *  Constant: '<S80>/const1'
   *  DiscreteIntegrator: '<S79>/Integrator'
   */
  rtb_Add3_ci = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S78>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S78>/Dead Zone' */

  /* Sum: '<S80>/Add' incorporates:
   *  DiscreteIntegrator: '<S79>/Integrator1'
   *  Gain: '<S76>/Gain1'
   *  Gain: '<S78>/Gain'
   *  Sum: '<S79>/Subtract'
   */
  rtb_Subtract3_m = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_b * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_ci;

  /* Signum: '<S80>/Sign' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_m > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_m;
  }

  /* End of Signum: '<S80>/Sign' */

  /* Sum: '<S80>/Add2' incorporates:
   *  Abs: '<S80>/Abs'
   *  Gain: '<S80>/Gain'
   *  Gain: '<S80>/Gain1'
   *  Product: '<S80>/Multiply2'
   *  Product: '<S80>/Multiply3'
   *  Sqrt: '<S80>/Sqrt'
   *  Sum: '<S80>/Add1'
   *  Sum: '<S80>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_m) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_ci;

  /* Sum: '<S80>/Add4' */
  rtb_Add4_lp = (rtb_Subtract3_m - rtb_a_b) + rtb_Add3_ci;

  /* Sum: '<S80>/Add3' */
  rtb_Add3_ci = rtb_Subtract3_m + localC->d;

  /* Sum: '<S80>/Subtract1' */
  rtb_Subtract3_m -= localC->d;

  /* Signum: '<S80>/Sign1' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S80>/Sign1' */

  /* Signum: '<S80>/Sign2' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S80>/Sign2' */

  /* Sum: '<S80>/Add5' incorporates:
   *  Gain: '<S80>/Gain2'
   *  Product: '<S80>/Multiply4'
   *  Sum: '<S80>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_ci - rtb_Subtract3_m) * 0.5F * rtb_Add4_lp;

  /* SignalConversion: '<S76>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S79>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S79>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S79>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S80>/Add6' */
  rtb_Add3_ci = rtb_a_b + localC->d;

  /* Sum: '<S80>/Subtract3' */
  rtb_Subtract3_m = rtb_a_b - localC->d;

  /* Signum: '<S80>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_lp = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_lp = 1.0F;
  } else {
    rtb_Add4_lp = rtb_a_b;
  }

  /* End of Signum: '<S80>/Sign5' */

  /* Signum: '<S80>/Sign3' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S80>/Sign3' */

  /* Signum: '<S80>/Sign4' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S80>/Sign4' */

  /* Signum: '<S80>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_b;
  }

  /* End of Signum: '<S80>/Sign6' */

  /* Update for DiscreteIntegrator: '<S79>/Integrator' incorporates:
   *  Constant: '<S80>/const'
   *  Gain: '<S80>/Gain3'
   *  Product: '<S80>/Divide'
   *  Product: '<S80>/Multiply5'
   *  Product: '<S80>/Multiply6'
   *  Sum: '<S80>/Subtract4'
   *  Sum: '<S80>/Subtract5'
   *  Sum: '<S80>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_lp) *
    localC->Gain4 * ((rtb_Add3_ci - rtb_Subtract3_m) * 0.5F) - rtb_a_f * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S73>/Motion Status'
 *    '<S94>/Motion Status'
 *    '<S269>/Motion Status'
 *    '<S303>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S73>/Motion Status'
 *    '<S94>/Motion Status'
 *    '<S269>/Motion Status'
 *    '<S303>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S73>/Motion Status'
 *    '<S94>/Motion Status'
 *    '<S269>/Motion Status'
 *    '<S303>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S73>/Motion Status' */
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

  /* End of Chart: '<S73>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S634>/Hold Control'
 *    '<S561>/Hold Control'
 *    '<S404>/Hold Control'
 *    '<S268>/Hold Control'
 *    '<S302>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S637>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S634>/Hold Control'
 *    '<S561>/Hold Control'
 *    '<S404>/Hold Control'
 *    '<S268>/Hold Control'
 *    '<S302>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S637>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S634>/Hold Control'
 *    '<S561>/Hold Control'
 *    '<S404>/Hold Control'
 *    '<S268>/Hold Control'
 *    '<S302>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S637>/Delay' incorporates:
   *  Gain: '<S639>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S637>/Gain2' incorporates:
   *  Delay: '<S637>/Delay'
   *  Gain: '<S639>/Gain'
   *  Sum: '<S637>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S637>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S634>/Move Control'
 *    '<S561>/Move Control'
 *    '<S404>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S641>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S641>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S634>/Move Control'
 *    '<S561>/Move Control'
 *    '<S404>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S641>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S641>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S634>/Move Control'
 *    '<S561>/Move Control'
 *    '<S404>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_f;
  real32_T rtb_a_f;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S642>/Multiply1' incorporates:
   *  Constant: '<S642>/const1'
   *  DiscreteIntegrator: '<S641>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S640>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_f = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_f = 0.0F;
  } else {
    rtb_a_f = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S640>/Dead Zone' */

  /* Sum: '<S642>/Add' incorporates:
   *  DiscreteIntegrator: '<S641>/Integrator1'
   *  Gain: '<S638>/Gain1'
   *  Gain: '<S640>/Gain'
   *  Sum: '<S641>/Subtract'
   */
  rtb_Subtract3_f = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_f * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S642>/Sign' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_Subtract3_f > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_Subtract3_f;
  }

  /* End of Signum: '<S642>/Sign' */

  /* Sum: '<S642>/Add2' incorporates:
   *  Abs: '<S642>/Abs'
   *  Gain: '<S642>/Gain'
   *  Gain: '<S642>/Gain1'
   *  Product: '<S642>/Multiply2'
   *  Product: '<S642>/Multiply3'
   *  Sqrt: '<S642>/Sqrt'
   *  Sum: '<S642>/Add1'
   *  Sum: '<S642>/Subtract'
   */
  rtb_a_f = (sqrtf((8.0F * fabsf(rtb_Subtract3_f) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_f + rtb_Add3_aw;

  /* Sum: '<S642>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_f - rtb_a_f) + rtb_Add3_aw;

  /* Sum: '<S642>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_f + localC->d;

  /* Sum: '<S642>/Subtract1' */
  rtb_Subtract3_f -= localC->d;

  /* Signum: '<S642>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S642>/Sign1' */

  /* Signum: '<S642>/Sign2' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S642>/Sign2' */

  /* Sum: '<S642>/Add5' incorporates:
   *  Gain: '<S642>/Gain2'
   *  Product: '<S642>/Multiply4'
   *  Sum: '<S642>/Subtract2'
   */
  rtb_a_f += (rtb_Add3_aw - rtb_Subtract3_f) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S641>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S641>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S641>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S641>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S642>/Add6' */
  rtb_Add3_aw = rtb_a_f + localC->d;

  /* Sum: '<S642>/Subtract3' */
  rtb_Subtract3_f = rtb_a_f - localC->d;

  /* Signum: '<S642>/Sign5' */
  if (rtb_a_f < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_f > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_f;
  }

  /* End of Signum: '<S642>/Sign5' */

  /* Signum: '<S642>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S642>/Sign3' */

  /* Signum: '<S642>/Sign4' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S642>/Sign4' */

  /* Signum: '<S642>/Sign6' */
  if (rtb_a_f < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_f > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_f;
  }

  /* End of Signum: '<S642>/Sign6' */

  /* Update for DiscreteIntegrator: '<S641>/Integrator' incorporates:
   *  Constant: '<S642>/const'
   *  Gain: '<S642>/Gain3'
   *  Product: '<S642>/Divide'
   *  Product: '<S642>/Multiply5'
   *  Product: '<S642>/Multiply6'
   *  Sum: '<S642>/Subtract4'
   *  Sum: '<S642>/Subtract5'
   *  Sum: '<S642>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_f / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_f) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S635>/Motion Status'
 *    '<S562>/Motion Status'
 *    '<S405>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S635>/Motion Status'
 *    '<S562>/Motion Status'
 *    '<S405>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S635>/Motion Status'
 *    '<S562>/Motion Status'
 *    '<S405>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S635>/Motion Status' */
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

  /* End of Chart: '<S635>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S644>/Hold Control'
 *    '<S583>/Hold Control'
 *    '<S414>/Hold Control'
 *    '<S327>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S647>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S644>/Hold Control'
 *    '<S583>/Hold Control'
 *    '<S414>/Hold Control'
 *    '<S327>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S647>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S644>/Hold Control'
 *    '<S583>/Hold Control'
 *    '<S414>/Hold Control'
 *    '<S327>/Hold Control'
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

  /* Delay: '<S647>/Delay' incorporates:
   *  SignalConversion: '<S647>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S651>/Trigonometric Function1' incorporates:
   *  Gain: '<S650>/Gain'
   *  Trigonometry: '<S651>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S651>/Trigonometric Function' incorporates:
   *  Gain: '<S650>/Gain'
   *  Trigonometry: '<S651>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S651>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S651>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S651>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S651>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S651>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S651>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S651>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S647>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S647>/Delay'
   *  SignalConversion: '<S647>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S647>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S647>/Multiply' incorporates:
   *  SignalConversion: '<S647>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S647>/Multiply' */

  /* Gain: '<S647>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S647>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S644>/Brake Control'
 *    '<S583>/Brake Control'
 *    '<S414>/Brake Control'
 *    '<S327>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S646>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S644>/Move Control'
 *    '<S583>/Move Control'
 *    '<S414>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S644>/Move Control'
 *    '<S583>/Move Control'
 *    '<S414>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S644>/Move Control'
 *    '<S583>/Move Control'
 *    '<S414>/Move Control'
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

  /* DiscreteIntegrator: '<S654>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S655>/Multiply1' incorporates:
   *  Constant: '<S655>/const1'
   *  DiscreteIntegrator: '<S654>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S654>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S655>/Multiply1' incorporates:
   *  Constant: '<S655>/const1'
   *  DiscreteIntegrator: '<S654>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S652>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S652>/Dead Zone' */

  /* Sum: '<S655>/Add' incorporates:
   *  DiscreteIntegrator: '<S654>/Integrator1'
   *  Gain: '<S648>/Gain6'
   *  Gain: '<S652>/Gain'
   *  Sum: '<S654>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S653>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S653>/Dead Zone' */

  /* Sum: '<S655>/Add' incorporates:
   *  DiscreteIntegrator: '<S654>/Integrator1'
   *  Gain: '<S648>/Gain6'
   *  Gain: '<S653>/Gain'
   *  Sum: '<S654>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S655>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S655>/Add2' incorporates:
   *  Abs: '<S655>/Abs'
   *  Gain: '<S655>/Gain'
   *  Gain: '<S655>/Gain1'
   *  Product: '<S655>/Multiply2'
   *  Product: '<S655>/Multiply3'
   *  Signum: '<S655>/Sign'
   *  Sqrt: '<S655>/Sqrt'
   *  Sum: '<S655>/Add1'
   *  Sum: '<S655>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S655>/Add3' incorporates:
   *  Signum: '<S655>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S655>/Subtract1' incorporates:
   *  Signum: '<S655>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S655>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S655>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S655>/Add5' incorporates:
   *  Gain: '<S655>/Gain2'
   *  Product: '<S655>/Multiply4'
   *  Signum: '<S655>/Sign'
   *  Sum: '<S655>/Add2'
   *  Sum: '<S655>/Add4'
   *  Sum: '<S655>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* SignalConversion: '<S654>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S654>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S655>/Sign3' incorporates:
   *  Sum: '<S655>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S655>/Sign4' incorporates:
   *  Sum: '<S655>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S655>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S655>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S655>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S655>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_p_idx_0_0;
  }

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
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S654>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S655>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S655>/Add2' incorporates:
   *  Abs: '<S655>/Abs'
   *  Gain: '<S655>/Gain'
   *  Gain: '<S655>/Gain1'
   *  Product: '<S655>/Multiply2'
   *  Product: '<S655>/Multiply3'
   *  Signum: '<S655>/Sign'
   *  Sqrt: '<S655>/Sqrt'
   *  Sum: '<S655>/Add1'
   *  Sum: '<S655>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S655>/Add3' incorporates:
   *  Signum: '<S655>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S655>/Subtract1' incorporates:
   *  Signum: '<S655>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S655>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S655>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S655>/Add5' incorporates:
   *  Gain: '<S655>/Gain2'
   *  Product: '<S655>/Multiply4'
   *  Signum: '<S655>/Sign'
   *  Sum: '<S655>/Add2'
   *  Sum: '<S655>/Add4'
   *  Sum: '<S655>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* SignalConversion: '<S654>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S654>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S655>/Sign3' incorporates:
   *  Sum: '<S655>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S655>/Sign4' incorporates:
   *  Sum: '<S655>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S655>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S655>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S655>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S655>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_p_idx_0_0;
  }

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
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S654>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S645>/Motion State'
 *    '<S584>/Motion State'
 *    '<S415>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S645>/Motion State'
 *    '<S584>/Motion State'
 *    '<S415>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S645>/Motion State'
 *    '<S584>/Motion State'
 *    '<S415>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S645>/Motion State' */
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

  /* End of Chart: '<S645>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S571>/Hold Control'
 *    '<S353>/Hold Control'
 *    '<S286>/Hold Control'
 *    '<S314>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S574>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S571>/Hold Control'
 *    '<S353>/Hold Control'
 *    '<S286>/Hold Control'
 *    '<S314>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S574>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S571>/Hold Control'
 *    '<S353>/Hold Control'
 *    '<S286>/Hold Control'
 *    '<S314>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S574>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S574>/Sum' incorporates:
   *  Delay: '<S574>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S577>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S577>/Switch' incorporates:
   *  Constant: '<S577>/Constant'
   *  Constant: '<S578>/Constant'
   *  Product: '<S577>/Multiply'
   *  RelationalOperator: '<S578>/Compare'
   *  Sum: '<S577>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S577>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S577>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S577>/Switch' */

  /* Gain: '<S574>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S574>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S571>/Move Control'
 *    '<S353>/Move Control'
 *    '<S286>/Move Control'
 *    '<S314>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S580>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S580>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S571>/Move Control'
 *    '<S353>/Move Control'
 *    '<S286>/Move Control'
 *    '<S314>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S580>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S580>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S571>/Move Control'
 *    '<S353>/Move Control'
 *    '<S286>/Move Control'
 *    '<S314>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_g;
  real32_T rtb_Subtract3_g;
  real32_T rtb_a_pq;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S581>/Multiply1' incorporates:
   *  Constant: '<S581>/const1'
   *  DiscreteIntegrator: '<S580>/Integrator'
   */
  rtb_Add3_g = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S579>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_pq = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_pq = 0.0F;
  } else {
    rtb_a_pq = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S579>/Dead Zone' */

  /* Sum: '<S581>/Add' incorporates:
   *  DiscreteIntegrator: '<S580>/Integrator1'
   *  Gain: '<S575>/Gain1'
   *  Gain: '<S579>/Gain'
   *  Sum: '<S580>/Subtract'
   */
  rtb_Subtract3_g = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_pq * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_g;

  /* Signum: '<S581>/Sign' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_a_pq = -1.0F;
  } else if (rtb_Subtract3_g > 0.0F) {
    rtb_a_pq = 1.0F;
  } else {
    rtb_a_pq = rtb_Subtract3_g;
  }

  /* End of Signum: '<S581>/Sign' */

  /* Sum: '<S581>/Add2' incorporates:
   *  Abs: '<S581>/Abs'
   *  Gain: '<S581>/Gain'
   *  Gain: '<S581>/Gain1'
   *  Product: '<S581>/Multiply2'
   *  Product: '<S581>/Multiply3'
   *  Sqrt: '<S581>/Sqrt'
   *  Sum: '<S581>/Add1'
   *  Sum: '<S581>/Subtract'
   */
  rtb_a_pq = (sqrtf((8.0F * fabsf(rtb_Subtract3_g) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_pq + rtb_Add3_g;

  /* Sum: '<S581>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_g - rtb_a_pq) + rtb_Add3_g;

  /* Sum: '<S581>/Add3' */
  rtb_Add3_g = rtb_Subtract3_g + localC->d;

  /* Sum: '<S581>/Subtract1' */
  rtb_Subtract3_g -= localC->d;

  /* Signum: '<S581>/Sign1' */
  if (rtb_Add3_g < 0.0F) {
    rtb_Add3_g = -1.0F;
  } else {
    if (rtb_Add3_g > 0.0F) {
      rtb_Add3_g = 1.0F;
    }
  }

  /* End of Signum: '<S581>/Sign1' */

  /* Signum: '<S581>/Sign2' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S581>/Sign2' */

  /* Sum: '<S581>/Add5' incorporates:
   *  Gain: '<S581>/Gain2'
   *  Product: '<S581>/Multiply4'
   *  Sum: '<S581>/Subtract2'
   */
  rtb_a_pq += (rtb_Add3_g - rtb_Subtract3_g) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S580>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S580>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S580>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S580>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S581>/Add6' */
  rtb_Add3_g = rtb_a_pq + localC->d;

  /* Sum: '<S581>/Subtract3' */
  rtb_Subtract3_g = rtb_a_pq - localC->d;

  /* Signum: '<S581>/Sign5' */
  if (rtb_a_pq < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_pq;
  }

  /* End of Signum: '<S581>/Sign5' */

  /* Signum: '<S581>/Sign3' */
  if (rtb_Add3_g < 0.0F) {
    rtb_Add3_g = -1.0F;
  } else {
    if (rtb_Add3_g > 0.0F) {
      rtb_Add3_g = 1.0F;
    }
  }

  /* End of Signum: '<S581>/Sign3' */

  /* Signum: '<S581>/Sign4' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S581>/Sign4' */

  /* Signum: '<S581>/Sign6' */
  if (rtb_a_pq < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_pq;
  }

  /* End of Signum: '<S581>/Sign6' */

  /* Update for DiscreteIntegrator: '<S580>/Integrator' incorporates:
   *  Constant: '<S581>/const'
   *  Gain: '<S581>/Gain3'
   *  Product: '<S581>/Divide'
   *  Product: '<S581>/Multiply5'
   *  Product: '<S581>/Multiply6'
   *  Sum: '<S581>/Subtract4'
   *  Sum: '<S581>/Subtract5'
   *  Sum: '<S581>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_pq / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_g - rtb_Subtract3_g) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S354>/Motion State'
 *    '<S287>/Motion State'
 *    '<S315>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S354>/Motion State'
 *    '<S287>/Motion State'
 *    '<S315>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S354>/Motion State'
 *    '<S287>/Motion State'
 *    '<S315>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S354>/Motion State' */
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

  /* End of Chart: '<S354>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S268>/Move Control'
 *    '<S302>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S277>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S277>/Dead Zone' */

  /* Gain: '<S272>/Gain1' incorporates:
   *  Gain: '<S277>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S272>/Switch' incorporates:
   *  Constant: '<S274>/Land_Speed'
   *  Constant: '<S275>/Constant'
   *  Constant: '<S276>/Constant'
   *  Gain: '<S274>/Gain'
   *  Logic: '<S272>/Logical Operator'
   *  MinMax: '<S274>/Min'
   *  RelationalOperator: '<S275>/Compare'
   *  RelationalOperator: '<S276>/Compare'
   *  S-Function (sfix_bitop): '<S272>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S272>/Switch' */
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

  /* Gain: '<S690>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S691>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S691>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S691>/Multiply1' incorporates:
   *  Product: '<S691>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S691>/Divide' incorporates:
   *  Constant: '<S691>/Constant'
   *  Constant: '<S691>/R'
   *  Sqrt: '<S691>/Sqrt'
   *  Sum: '<S691>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S691>/Product3' incorporates:
   *  Constant: '<S691>/Constant1'
   *  Product: '<S691>/Multiply1'
   *  Sum: '<S691>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S691>/Multiply2' incorporates:
   *  Trigonometry: '<S691>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S690>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S695>/Abs' incorporates:
   *  Abs: '<S698>/Abs1'
   *  Switch: '<S695>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S695>/Switch1' incorporates:
   *  Abs: '<S695>/Abs'
   *  Bias: '<S695>/Bias2'
   *  Bias: '<S695>/Bias3'
   *  Constant: '<S692>/Constant'
   *  Constant: '<S692>/Constant1'
   *  Constant: '<S697>/Constant'
   *  Gain: '<S695>/Gain1'
   *  Product: '<S695>/Multiply'
   *  RelationalOperator: '<S697>/Compare'
   *  Switch: '<S692>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S698>/Switch1' incorporates:
     *  Bias: '<S698>/Bias2'
     *  Bias: '<S698>/Bias3'
     *  Constant: '<S698>/Constant'
     *  Constant: '<S699>/Constant'
     *  Math: '<S698>/Math Function'
     *  RelationalOperator: '<S699>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S698>/Switch1' */

    /* Signum: '<S695>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S695>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S692>/Sum' incorporates:
   *  Sum: '<S690>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S690>/Multiply' incorporates:
   *  Gain: '<S690>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S694>/Switch1' incorporates:
   *  Abs: '<S694>/Abs1'
   *  Bias: '<S694>/Bias2'
   *  Bias: '<S694>/Bias3'
   *  Constant: '<S694>/Constant'
   *  Constant: '<S696>/Constant'
   *  Math: '<S694>/Math Function'
   *  RelationalOperator: '<S696>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S694>/Switch1' */

  /* Product: '<S690>/Multiply' incorporates:
   *  Gain: '<S690>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S690>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S693>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S693>/Sum2' incorporates:
   *  Product: '<S693>/Multiply1'
   *  Product: '<S693>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S693>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S693>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S693>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S687>/Data Type Conversion' incorporates:
   *  Gain: '<S690>/Gain'
   *  Sum: '<S690>/Sum1'
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

    /* Delay: '<S26>/Delay' */
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

    /* End of Delay: '<S26>/Delay' */
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

    /* Delay: '<S26>/Delay' */
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

    /* End of Delay: '<S26>/Delay' */
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

    /* Delay: '<S26>/Delay' */
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

    /* End of Delay: '<S26>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

  /* Delay: '<S26>/Delay' */
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

  /* End of Delay: '<S26>/Delay' */
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_i, &FMS_DW.Msg_FMS_Cmd_a
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_a[0] : NULL;
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
            lla_tmp = FMS_B.wp_index - 1;

            /* Inport: '<Root>/Mission_Data' */
            FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] * 1.0E-7;
            FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] * 1.0E-7;
            FMS_B.lla[2] = -(FMS_U.Mission_Data.z[lla_tmp] + FMS_DW.home[2]);
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

  /* Outputs for Function Call SubSystem: '<S6>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S700>/Compare' incorporates:
   *  Abs: '<S689>/Abs'
   *  Constant: '<S700>/Constant'
   *  MinMax: '<S689>/Max'
   *  Sum: '<S689>/Sum'
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
  FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_h >=
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
        FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
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
            FMS_DW.durationLastReferenceTick_1_g =
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
          FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_g >= 500) {
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
              FMS_DW.durationLastReferenceTick_1_g =
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
      /* Reshape: '<S688>/Reshape' incorporates:
       *  Constant: '<S688>/Constant'
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
        FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
        FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_o = false;
      FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
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
          FMS_DW.condWasTrueAtLastTimeStep_1_o = (FMS_DW.prep_takeoff == 1.0);
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
          FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
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
  FMS_emplace_n(&FMS_DW.Queue_VTOLMode_k, &FMS_DW.VTOL_M_msgReservedData);
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
    FMS_DW.VTOL_M_msgHandle = FMS_pop_c(&FMS_DW.Queue_VTOLMode_k,
      &FMS_DW.Msg_VTOLMode_n[0]) != 0 ? (void *)&FMS_DW.Msg_VTOLMode_n[0] : NULL;
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
    FMS_DW.durationLastReferenceTick_2_d = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
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
          FMS_DW.durationLastReferenceTick_2_d = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_d = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_g)) {
          FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_m > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_b)) {
            FMS_DW.durationLastReferenceTick_2_d =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2_d > 375) {
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
              FMS_DW.durationLastReferenceTick_2_d =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_g)) {
              FMS_DW.durationLastReferenceTick_1_m =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_DW.br;
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
        if (FMS_B.DiscreteTimeIntegrator5 >= 17.0F) {
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_i, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_a[1]);
  FMS_initQueue_k((Queue_VTOLMode *)&FMS_DW.Queue_VTOLMode_k, MSG_FIFO_QUEUE, 10,
                  (Msg_VTOLMode *)&FMS_DW.Msg_VTOLMode_n[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T d;
  real32_T D;
  real32_T rtb_MatrixConcatenate1_i[9];
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion_o;
  uint16_T rtb_DataTypeConversion1_b;
  real32_T rtb_Divide_n4[2];
  real32_T rtb_Switch_d0[3];
  real32_T rtb_Square_h[2];
  int32_T rtb_n;
  real32_T rtb_Switch_ov[3];
  real32_T rtb_Subtract3_d;
  real32_T rtb_Divide_or;
  real32_T rtb_Sign5_mn;
  MotionState rtb_state_l4;
  MotionState rtb_state_fg;
  boolean_T rtb_Compare_ii;
  MotionState rtb_state_og;
  real_T rtb_Switch1_n;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  real32_T rtb_Transpose[9];
  real32_T rtb_u_mm;
  boolean_T rtb_LogicalOperator_oy;
  real32_T rtb_P_dg[2];
  real32_T rtb_P_cg[2];
  real32_T rtb_MatrixConcatenate1_i_0[3];
  boolean_T tmp[3];
  real32_T rtb_Multiply_g_0[3];
  boolean_T tmp_0[3];
  boolean_T tmp_1[3];
  real32_T rtb_Switch_fz_idx_2;
  real32_T rtb_Switch_fz_idx_1;
  real32_T rtb_Switch_fz_idx_0;
  real32_T rtb_MathFunction_n_idx_2;
  real32_T rtb_Divide_l_idx_3;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real32_T rtb_Divide_l_idx_0;
  real_T rtb_Multiply_g_idx_0;
  uint32_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;
  boolean_T guard1 = false;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S40>/Arm' incorporates:
   *  ActionPort: '<S42>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S42>/FW_Mode' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
   *  ActionPort: '<S59>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S59>/Position' incorporates:
   *  ActionPort: '<S65>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S107>/Hold Control' incorporates:
   *  ActionPort: '<S110>/Action Port'
   */
  /* SwitchCase: '<S107>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S19>/Square'
   *  Sqrt: '<S121>/Sqrt'
   *  Sqrt: '<S19>/Sqrt'
   *  Sum: '<S19>/Sum of Elements'
   *  SwitchCase: '<S40>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S47>/Switch Case'
   *  SwitchCase: '<S59>/Switch Case'
   */
  d = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
              FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
             FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) +
            FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* End of Outputs for SubSystem: '<S107>/Hold Control' */
  /* End of Outputs for SubSystem: '<S59>/Position' */
  /* End of Outputs for SubSystem: '<S47>/Assist' */
  /* End of Outputs for SubSystem: '<S42>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S40>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S15>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Sqrt: '<S19>/Sqrt'
   */
  rtb_Divide_l_idx_0 = FMS_U.INS_Out.quat[0] / d;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / d;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / d;
  rtb_Divide_l_idx_3 = FMS_U.INS_Out.quat[3] / d;

  /* Math: '<S16>/Square' incorporates:
   *  Math: '<S17>/Square'
   *  Math: '<S18>/Square'
   */
  rtb_u_mm = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_0;

  /* Math: '<S16>/Square2' incorporates:
   *  Math: '<S17>/Square2'
   *  Math: '<S18>/Square2'
   */
  rtb_Switch_fz_idx_0 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S16>/Square1' incorporates:
   *  Math: '<S17>/Square1'
   *  Math: '<S18>/Square1'
   */
  rtb_Switch_fz_idx_1 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S16>/Square3' incorporates:
   *  Math: '<S17>/Square3'
   *  Math: '<S18>/Square3'
   */
  rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3;

  /* Sum: '<S16>/Subtract' incorporates:
   *  Math: '<S16>/Square'
   *  Math: '<S16>/Square1'
   *  Math: '<S16>/Square2'
   *  Math: '<S16>/Square3'
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Add1'
   */
  rtb_MatrixConcatenate1_i[0] = (rtb_u_mm + rtb_Switch_fz_idx_1) -
    (rtb_Switch_fz_idx_0 + rtb_Switch_fz_idx_2);

  /* Product: '<S16>/Multiply' incorporates:
   *  Product: '<S17>/Multiply'
   */
  rtb_Divide_or = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S16>/Multiply1' incorporates:
   *  Product: '<S17>/Multiply1'
   */
  rtb_Sign5_mn = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_3;

  /* Gain: '<S16>/Gain' incorporates:
   *  Product: '<S16>/Multiply'
   *  Product: '<S16>/Multiply1'
   *  Sum: '<S16>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[1] = (rtb_Divide_or - rtb_Sign5_mn) * 2.0F;

  /* Product: '<S16>/Multiply2' incorporates:
   *  Product: '<S18>/Multiply'
   */
  rtb_Subtract3_d = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_3;

  /* Product: '<S16>/Multiply3' incorporates:
   *  Product: '<S18>/Multiply1'
   */
  D = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_2;

  /* Gain: '<S16>/Gain1' incorporates:
   *  Product: '<S16>/Multiply2'
   *  Product: '<S16>/Multiply3'
   *  Sum: '<S16>/Add2'
   */
  rtb_MatrixConcatenate1_i[2] = (rtb_Subtract3_d + D) * 2.0F;

  /* Gain: '<S17>/Gain' incorporates:
   *  Sum: '<S17>/Add3'
   */
  rtb_MatrixConcatenate1_i[3] = (rtb_Divide_or + rtb_Sign5_mn) * 2.0F;

  /* Sum: '<S17>/Subtract' incorporates:
   *  Sum: '<S17>/Add'
   *  Sum: '<S17>/Add1'
   */
  rtb_MatrixConcatenate1_i[4] = (rtb_u_mm + rtb_Switch_fz_idx_0) -
    (rtb_Switch_fz_idx_1 + rtb_Switch_fz_idx_2);

  /* Product: '<S17>/Multiply2' incorporates:
   *  Product: '<S18>/Multiply2'
   */
  rtb_Divide_or = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_3;

  /* Product: '<S17>/Multiply3' incorporates:
   *  Product: '<S18>/Multiply3'
   */
  rtb_Sign5_mn = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_1;

  /* Gain: '<S17>/Gain1' incorporates:
   *  Product: '<S17>/Multiply2'
   *  Product: '<S17>/Multiply3'
   *  Sum: '<S17>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[5] = (rtb_Divide_or - rtb_Sign5_mn) * 2.0F;

  /* Gain: '<S18>/Gain' incorporates:
   *  Sum: '<S18>/Subtract2'
   */
  rtb_MatrixConcatenate1_i[6] = (rtb_Subtract3_d - D) * 2.0F;

  /* Gain: '<S18>/Gain1' incorporates:
   *  Sum: '<S18>/Add2'
   */
  rtb_MatrixConcatenate1_i[7] = (rtb_Divide_or + rtb_Sign5_mn) * 2.0F;

  /* Sum: '<S18>/Subtract' incorporates:
   *  Sum: '<S18>/Add'
   *  Sum: '<S18>/Add1'
   */
  rtb_MatrixConcatenate1_i[8] = (rtb_u_mm + rtb_Switch_fz_idx_2) -
    (rtb_Switch_fz_idx_1 + rtb_Switch_fz_idx_0);

  /* Product: '<S13>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (rtb_n = 0; rtb_n < 3; rtb_n++) {
    rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
      FMS_U.INS_Out.vd + (rtb_MatrixConcatenate1_i[rtb_n + 3] * FMS_U.INS_Out.ve
                          + rtb_MatrixConcatenate1_i[rtb_n] * FMS_U.INS_Out.vn);
  }

  /* End of Product: '<S13>/Multiply' */

  /* Signum: '<S13>/Sign' */
  if (rtb_MatrixConcatenate1_i_0[0] < 0.0F) {
    rtb_Divide_l_idx_0 = -1.0F;
  } else if (rtb_MatrixConcatenate1_i_0[0] > 0.0F) {
    rtb_Divide_l_idx_0 = 1.0F;
  } else {
    rtb_Divide_l_idx_0 = rtb_MatrixConcatenate1_i_0[0];
  }

  /* End of Signum: '<S13>/Sign' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S40>/Arm' incorporates:
   *  ActionPort: '<S42>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S42>/FW_Mode' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
   *  ActionPort: '<S60>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S60>/Mission' incorporates:
   *  ActionPort: '<S157>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S157>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S161>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
   *  ActionPort: '<S62>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S62>/Return' incorporates:
   *  ActionPort: '<S188>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S62>/Takeoff' incorporates:
   *  ActionPort: '<S189>/Action Port'
   */
  /* SwitchCase: '<S60>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S179>/Math Function'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S226>/Math Function'
   *  Math: '<S248>/Math Function'
   *  SwitchCase: '<S40>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S47>/Switch Case'
   *  SwitchCase: '<S62>/Switch Case'
   */
  rtb_u_mm = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Divide_or = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S62>/Takeoff' */
  /* End of Outputs for SubSystem: '<S62>/Return' */
  /* End of Outputs for SubSystem: '<S157>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S60>/Mission' */
  /* End of Outputs for SubSystem: '<S47>/Auto' */

  /* Outputs for IfAction SubSystem: '<S42>/MC_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S48>/Auto' incorporates:
   *  ActionPort: '<S254>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S254>/Mission' incorporates:
   *  ActionPort: '<S366>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S366>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S370>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S48>/SubMode' incorporates:
   *  ActionPort: '<S256>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S256>/Return' incorporates:
   *  ActionPort: '<S555>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
   *  ActionPort: '<S59>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S59>/Position' incorporates:
   *  ActionPort: '<S65>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S107>/Hold Control' incorporates:
   *  ActionPort: '<S110>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S62>/Hold' incorporates:
   *  ActionPort: '<S186>/Action Port'
   */
  /* SwitchCase: '<S107>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sqrt: '<S127>/Sqrt'
   *  Sqrt: '<S178>/Sqrt'
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S202>/Sqrt'
   *  Sqrt: '<S225>/Sqrt'
   *  Sqrt: '<S328>/Sqrt'
   *  Sqrt: '<S433>/Sqrt'
   *  Sqrt: '<S663>/Sqrt'
   *  Sum: '<S129>/Sum of Elements'
   *  Sum: '<S1>/Add'
   *  Sum: '<S203>/Sum of Elements'
   *  Sum: '<S435>/Sum of Elements'
   *  Sum: '<S665>/Sum of Elements'
   *  Switch: '<S110>/Switch'
   *  SwitchCase: '<S253>/Switch Case'
   *  SwitchCase: '<S254>/Switch Case'
   *  SwitchCase: '<S256>/Switch Case'
   *  SwitchCase: '<S40>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S47>/Switch Case'
   *  SwitchCase: '<S48>/Switch Case'
   *  SwitchCase: '<S59>/Switch Case'
   *  SwitchCase: '<S60>/Switch Case'
   *  SwitchCase: '<S62>/Switch Case'
   */
  rtb_Divide_l_idx_2 = rtb_u_mm + rtb_Divide_or;

  /* Outputs for IfAction SubSystem: '<S48>/Assist' incorporates:
   *  ActionPort: '<S253>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S253>/Position' incorporates:
   *  ActionPort: '<S260>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
   *  ActionPort: '<S60>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S60>/Mission' incorporates:
   *  ActionPort: '<S157>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S157>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S161>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S62>/Return' incorporates:
   *  ActionPort: '<S188>/Action Port'
   */
  rtb_Divide_l_idx_3 = sqrtf(rtb_Divide_l_idx_2);

  /* End of Outputs for SubSystem: '<S62>/Return' */
  /* End of Outputs for SubSystem: '<S157>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S60>/Mission' */
  /* End of Outputs for SubSystem: '<S47>/Auto' */
  /* End of Outputs for SubSystem: '<S253>/Position' */
  /* End of Outputs for SubSystem: '<S48>/Assist' */
  /* End of Outputs for SubSystem: '<S62>/Hold' */
  /* End of Outputs for SubSystem: '<S107>/Hold Control' */
  /* End of Outputs for SubSystem: '<S59>/Position' */
  /* End of Outputs for SubSystem: '<S47>/Assist' */
  /* End of Outputs for SubSystem: '<S256>/Return' */
  /* End of Outputs for SubSystem: '<S48>/SubMode' */
  /* End of Outputs for SubSystem: '<S366>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S254>/Mission' */
  /* End of Outputs for SubSystem: '<S48>/Auto' */
  /* End of Outputs for SubSystem: '<S42>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S47>/SubMode' */
  /* End of Outputs for SubSystem: '<S42>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S40>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   */
  rtb_Divide_l_idx_0 *= rtb_Divide_l_idx_3;

  /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S28>/FixPt Relational Operator'
   *  UnitDelay: '<S28>/Delay Input1'
   *
   * Block description for '<S28>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  DataTypeConversion: '<S26>/Data Type Conversion2'
   *  Delay: '<S26>/Delay'
   *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S26>/Logical Operator'
   *  Logic: '<S26>/Logical Operator1'
   *  RelationalOperator: '<S27>/Compare'
   *  RelationalOperator: '<S33>/Compare'
   *  RelationalOperator: '<S34>/Compare'
   *  RelationalOperator: '<S35>/FixPt Relational Operator'
   *  Switch: '<S26>/Switch1'
   *  UnitDelay: '<S35>/Delay Input1'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S26>/Switch1' incorporates:
       *  DataTypeConversion: '<S26>/Data Type Conversion1'
       *  Delay: '<S26>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S26>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S26>/Delay'
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
  if (rtb_Divide_l_idx_0 > 100.0F) {
    rtb_Divide_l_idx_1 = 100.0F;
  } else if (rtb_Divide_l_idx_0 < 0.1F) {
    rtb_Divide_l_idx_1 = 0.1F;
  } else {
    rtb_Divide_l_idx_1 = rtb_Divide_l_idx_0;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Divide_l_idx_1;
  }

  FMS_B.DiscreteTimeIntegrator5 = FMS_DW.DiscreteTimeIntegrator5_DSTATE;

  /* End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator5' */

  /* DataTypeConversion: '<S25>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant1'
   *  DataTypeConversion: '<S25>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S30>/FixPt Relational Operator'
   *  RelationalOperator: '<S31>/FixPt Relational Operator'
   *  Switch: '<S25>/Switch2'
   *  UnitDelay: '<S30>/Delay Input1'
   *  UnitDelay: '<S31>/Delay Input1'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S25>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S37>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S37>/Delay Input1'
   *
   * Block description for '<S37>/Delay Input1':
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
   *  RelationalOperator: '<S36>/FixPt Relational Operator'
   *  UnitDelay: '<S36>/Delay Input1'
   *
   * Block description for '<S36>/Delay Input1':
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
   *  Constant: '<S38>/Constant'
   *  Constant: '<S4>/Constant1'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  RelationalOperator: '<S38>/Compare'
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

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Delay: '<S22>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S21>/FixPt Relational Operator'
   *  Switch: '<S22>/Switch'
   *  UnitDelay: '<S21>/Delay Input1'
   *
   * Block description for '<S21>/Delay Input1':
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
   *  Constant: '<S20>/Constant'
   *  Constant: '<S23>/Upper Limit'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S23>/Upper Test'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion_n = (VTOLMode)FMS_U.Pilot_Cmd.cmd_2;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S711>/Constant'
   *  Constant: '<S9>/ACCEPT_R'
   *  Constant: '<S9>/MC_ACCEPT_R'
   *  RelationalOperator: '<S711>/Compare'
   */
  if (FMS_B.DataTypeConversion_n == VTOLMode_Multicopter) {
    FMS_B.Switch = FMS_PARAM.MC_ACCEPT_R;
  } else {
    FMS_B.Switch = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S9>/Switch' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_m != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_h = rtb_Divide_l_idx_0;
  }

  FMS_B.DiscreteTimeIntegrator5_p = FMS_DW.DiscreteTimeIntegrator5_DSTAT_h;

  /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) ||
      (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
    FMS_DW.durationLastReferenceTick_1_g = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_o = rtb_FixPtRelationalOperator_me;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
  {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator_me;
  FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_i = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_g)) {
    FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_b)) {
    FMS_DW.durationLastReferenceTick_2_d = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 4095U) {
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
  /* SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_d0[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_ov[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_d0[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_ov[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_d0[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_ov[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* SwitchCase: '<S40>/Switch Case' incorporates:
   *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S42>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
     case 0:
      /* Disable for SwitchCase: '<S47>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
       case 0:
        /* Disable for SwitchCase: '<S62>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S60>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S59>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S107>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S93>/Switch Case' */
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
      /* Disable for SwitchCase: '<S48>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S256>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S644>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S634>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S583>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S561>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S571>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S254>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S366>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S414>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S404>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* End of Disable for SubSystem: '<S366>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S253>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S353>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S268>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S286>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S302>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S327>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S314>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S42>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S40>/Disarm' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* BusAssignment: '<S44>/Bus Assignment' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant2'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_mv;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ap;

    /* End of Outputs for SubSystem: '<S40>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S40>/Standby' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    /* BusAssignment: '<S45>/Bus Assignment' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant2'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_hd;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ft;

    /* End of Outputs for SubSystem: '<S40>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S40>/Arm' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* SwitchCase: '<S42>/Switch Case' incorporates:
     *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy8Inport1'
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
        /* Disable for SwitchCase: '<S47>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
         case 0:
          /* Disable for SwitchCase: '<S62>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S60>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S59>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S72>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S107>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S93>/Switch Case' */
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
        /* Disable for SwitchCase: '<S48>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S256>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S644>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S583>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S561>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S571>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S254>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S366>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S414>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S404>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* End of Disable for SubSystem: '<S366>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S253>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S353>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S268>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S286>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S302>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S327>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S314>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S42>/FW_Mode' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      /* SwitchCase: '<S47>/Switch Case' */
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
          /* Disable for SwitchCase: '<S62>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S60>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S59>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S72>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S107>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S93>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
         *  ActionPort: '<S62>/Action Port'
         */
        /* SwitchCase: '<S62>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S62>/Takeoff' incorporates:
           *  ActionPort: '<S189>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S247>/TmpSignal ConversionAtSquareInport1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Divide_n4[0] = FMS_U.INS_Out.vn;
          rtb_Divide_n4[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S248>/Sum of Elements' */
          d = rtb_u_mm + rtb_Divide_or;

          /* Math: '<S248>/Math Function1' incorporates:
           *  Sum: '<S248>/Sum of Elements'
           *
           * About '<S248>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S248>/Math Function1' */

          /* Switch: '<S248>/Switch' incorporates:
           *  Constant: '<S248>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S248>/Product'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S248>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S238>/NearbyRefWP' incorporates:
           *  Constant: '<S236>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Divide_l_idx_3);

          /* MATLAB Function: '<S238>/SearchL1RefWP' incorporates:
           *  Constant: '<S236>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Divide_l_idx_2);

          /* MATLAB Function: '<S238>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S238>/Switch1' incorporates:
           *  Constant: '<S241>/Constant'
           *  RelationalOperator: '<S241>/Compare'
           */
          if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S240>/Compare' incorporates:
             *  Constant: '<S240>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_2 >= 0.0F);

            /* Switch: '<S238>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S238>/Switch' */
          }

          /* End of Switch: '<S238>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S239>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S249>/Sum of Elements' incorporates:
           *  Math: '<S249>/Math Function'
           */
          d = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S249>/Math Function1' incorporates:
           *  Sum: '<S249>/Sum of Elements'
           *
           * About '<S249>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S249>/Math Function1' */

          /* Switch: '<S249>/Switch' incorporates:
           *  Constant: '<S249>/Constant'
           *  Product: '<S249>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Divide_n4[1];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S249>/Switch' */

          /* Product: '<S248>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S251>/Sum of Elements' incorporates:
           *  Math: '<S251>/Math Function'
           *  SignalConversion: '<S251>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S251>/Math Function1' incorporates:
           *  Sum: '<S251>/Sum of Elements'
           *
           * About '<S251>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S251>/Math Function1' */

          /* Switch: '<S251>/Switch' incorporates:
           *  Constant: '<S251>/Constant'
           *  Product: '<S251>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_fz_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_fz_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S251>/Switch' */

          /* Product: '<S249>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S252>/Sum of Elements' incorporates:
           *  Math: '<S252>/Math Function'
           *  SignalConversion: '<S252>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S252>/Math Function1' incorporates:
           *  Sum: '<S252>/Sum of Elements'
           *
           * About '<S252>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S252>/Math Function1' */

          /* Switch: '<S252>/Switch' incorporates:
           *  Constant: '<S252>/Constant'
           *  Product: '<S252>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S252>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S233>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_2 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S252>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S251>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S233>/Sum1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S252>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S251>/Divide' */
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S233>/Sum1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Switch_fz_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S233>/Divide' incorporates:
           *  Math: '<S234>/Square'
           *  Math: '<S235>/Square'
           *  Sqrt: '<S234>/Sqrt'
           *  Sqrt: '<S235>/Sqrt'
           *  Sum: '<S233>/Sum'
           *  Sum: '<S233>/Sum1'
           *  Sum: '<S234>/Sum of Elements'
           *  Sum: '<S235>/Sum of Elements'
           */
          rtb_Switch_fz_idx_0 = sqrtf(rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 +
            rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2) / sqrtf(d * d +
            rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0);

          /* Saturate: '<S233>/Saturation' */
          if (rtb_Switch_fz_idx_0 > 1.0F) {
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 < 0.0F) {
              rtb_Switch_fz_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S233>/Saturation' */

          /* Sum: '<S250>/Subtract' incorporates:
           *  Product: '<S250>/Multiply'
           *  Product: '<S250>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S246>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S246>/Sign1' */

          /* Switch: '<S246>/Switch2' incorporates:
           *  Constant: '<S246>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S246>/Switch2' */

          /* DotProduct: '<S246>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S246>/Acos' incorporates:
           *  DotProduct: '<S246>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S246>/Multiply' incorporates:
           *  Trigonometry: '<S246>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S245>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S245>/Saturation' */

          /* Sqrt: '<S247>/Sqrt' incorporates:
           *  Sum: '<S247>/Sum of Elements'
           */
          rtb_Divide_l_idx_3 = sqrtf(rtb_u_mm + rtb_Divide_or);

          /* BusAssignment: '<S189>/Bus Assignment' incorporates:
           *  Constant: '<S189>/Constant'
           *  Constant: '<S189>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S245>/Divide' incorporates:
           *  Constant: '<S236>/L1'
           *  Gain: '<S245>/Gain'
           *  Math: '<S245>/Square'
           *  Product: '<S245>/Multiply1'
           *  Trigonometry: '<S245>/Sin'
           */
          d = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S236>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S189>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S189>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S189>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S236>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S231>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S233>/Multiply'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S231>/Sum2'
           *  Sum: '<S233>/Add'
           *  Sum: '<S233>/Subtract'
           */
          d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                 FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_fz_idx_0 +
                FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S231>/Saturation1' */
          if (d > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S189>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (d < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S189>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S189>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S231>/Saturation1' */
          /* End of Outputs for SubSystem: '<S62>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S62>/Land' incorporates:
           *  ActionPort: '<S187>/Action Port'
           */
          /* BusAssignment: '<S187>/Bus Assignment1' incorporates:
           *  Constant: '<S187>/Constant'
           *  Constant: '<S187>/Constant1'
           *  Constant: '<S187>/Constant4'
           *  Constant: '<S187>/Constant5'
           *  Constant: '<S187>/Constant7'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S62>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S62>/Return' incorporates:
           *  ActionPort: '<S188>/Action Port'
           */
          /* Math: '<S226>/Math Function' */
          rtb_Divide_n4[0] = rtb_u_mm;
          rtb_Divide_n4[1] = rtb_Divide_or;

          /* Sum: '<S226>/Sum of Elements' */
          d = rtb_u_mm + rtb_Divide_or;

          /* Math: '<S226>/Math Function1' incorporates:
           *  Sum: '<S226>/Sum of Elements'
           *
           * About '<S226>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S226>/Math Function1' */

          /* Switch: '<S226>/Switch' incorporates:
           *  Constant: '<S226>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S226>/Product'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S226>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S216>/NearbyRefWP' incorporates:
           *  Constant: '<S214>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Divide_l_idx_2);

          /* MATLAB Function: '<S216>/SearchL1RefWP' incorporates:
           *  Constant: '<S214>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_u_mm);

          /* MATLAB Function: '<S216>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S216>/Switch1' incorporates:
           *  Constant: '<S219>/Constant'
           *  RelationalOperator: '<S219>/Compare'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S218>/Compare' incorporates:
             *  Constant: '<S218>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_u_mm >= 0.0F);

            /* Switch: '<S216>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S216>/Switch' */
          }

          /* End of Switch: '<S216>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S217>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S227>/Sum of Elements' incorporates:
           *  Math: '<S227>/Math Function'
           */
          d = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S227>/Math Function1' incorporates:
           *  Sum: '<S227>/Sum of Elements'
           *
           * About '<S227>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S227>/Math Function1' */

          /* Switch: '<S227>/Switch' incorporates:
           *  Constant: '<S227>/Constant'
           *  Product: '<S227>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Divide_n4[1];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S227>/Switch' */

          /* Product: '<S226>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S229>/Sum of Elements' incorporates:
           *  Math: '<S229>/Math Function'
           *  SignalConversion: '<S229>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S229>/Math Function1' incorporates:
           *  Sum: '<S229>/Sum of Elements'
           *
           * About '<S229>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S229>/Math Function1' */

          /* Switch: '<S229>/Switch' incorporates:
           *  Constant: '<S229>/Constant'
           *  Product: '<S229>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_fz_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_fz_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S229>/Switch' */

          /* Product: '<S227>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S230>/Sum of Elements' incorporates:
           *  Math: '<S230>/Math Function'
           *  SignalConversion: '<S230>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S230>/Math Function1' incorporates:
           *  Sum: '<S230>/Sum of Elements'
           *
           * About '<S230>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S230>/Math Function1' */

          /* Switch: '<S230>/Switch' incorporates:
           *  Constant: '<S230>/Constant'
           *  Product: '<S230>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S230>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S211>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_2 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S230>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S229>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S211>/Sum1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S230>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S229>/Divide' */
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S211>/Sum1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_mm = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S211>/Divide' incorporates:
           *  Math: '<S212>/Square'
           *  Math: '<S213>/Square'
           *  Sqrt: '<S212>/Sqrt'
           *  Sqrt: '<S213>/Sqrt'
           *  Sum: '<S211>/Sum'
           *  Sum: '<S211>/Sum1'
           *  Sum: '<S212>/Sum of Elements'
           *  Sum: '<S213>/Sum of Elements'
           */
          rtb_u_mm = sqrtf(rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2 + d * d) /
            sqrtf(rtb_Divide_or * rtb_Divide_or + rtb_u_mm * rtb_u_mm);

          /* Saturate: '<S211>/Saturation' */
          if (rtb_u_mm > 1.0F) {
            rtb_u_mm = 1.0F;
          } else {
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = 0.0F;
            }
          }

          /* End of Saturate: '<S211>/Saturation' */

          /* Sum: '<S228>/Subtract' incorporates:
           *  Product: '<S228>/Multiply'
           *  Product: '<S228>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S224>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S224>/Sign1' */

          /* Switch: '<S224>/Switch2' incorporates:
           *  Constant: '<S224>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S224>/Switch2' */

          /* DotProduct: '<S224>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S224>/Acos' incorporates:
           *  DotProduct: '<S224>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S224>/Multiply' incorporates:
           *  Trigonometry: '<S224>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S223>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S223>/Saturation' */

          /* BusAssignment: '<S188>/Bus Assignment1' incorporates:
           *  Constant: '<S188>/Constant2'
           *  Constant: '<S188>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S223>/Divide' incorporates:
           *  Constant: '<S214>/L1'
           *  Gain: '<S223>/Gain'
           *  Math: '<S223>/Square'
           *  Product: '<S223>/Multiply1'
           *  Trigonometry: '<S223>/Sin'
           */
          d = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S214>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S188>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S188>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S188>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S214>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S209>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S211>/Multiply'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S209>/Sum2'
           *  Sum: '<S211>/Add'
           *  Sum: '<S211>/Subtract'
           */
          d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                 FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_mm +
                FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S209>/Saturation1' */
          if (d > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S188>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (d < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S188>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S188>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S209>/Saturation1' */
          /* End of Outputs for SubSystem: '<S62>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S62>/Hold' incorporates:
             *  ActionPort: '<S186>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S62>/Switch Case' incorporates:
             *  Delay: '<S191>/Delay'
             *  Delay: '<S196>/start_vel'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S62>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S62>/Hold' incorporates:
           *  ActionPort: '<S186>/Action Port'
           */
          /* Math: '<S203>/Math Function1'
           *
           * About '<S203>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S203>/Math Function1' */

          /* Switch: '<S203>/Switch' incorporates:
           *  Constant: '<S203>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S203>/Product'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_d0[0] = FMS_U.INS_Out.vn;
            rtb_Switch_d0[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S203>/Switch' */

          /* Delay: '<S196>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S208>/Sum of Elements' incorporates:
           *  Delay: '<S196>/start_vel'
           *  Math: '<S208>/Math Function'
           */
          d = FMS_DW.start_vel_DSTATE_l[0] * FMS_DW.start_vel_DSTATE_l[0] +
            FMS_DW.start_vel_DSTATE_l[1] * FMS_DW.start_vel_DSTATE_l[1];

          /* Math: '<S208>/Math Function1' incorporates:
           *  Sum: '<S208>/Sum of Elements'
           *
           * About '<S208>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S208>/Math Function1' */

          /* Switch: '<S208>/Switch' incorporates:
           *  Constant: '<S208>/Constant'
           *  Delay: '<S196>/start_vel'
           *  Product: '<S208>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_ov[0] = FMS_DW.start_vel_DSTATE_l[0];
            rtb_Switch_ov[1] = FMS_DW.start_vel_DSTATE_l[1];
            rtb_Switch_ov[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S208>/Switch' */

          /* Product: '<S203>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S206>/Sum of Elements' incorporates:
           *  Math: '<S206>/Math Function'
           *  SignalConversion: '<S206>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S206>/Math Function1' incorporates:
           *  Sum: '<S206>/Sum of Elements'
           *
           * About '<S206>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S206>/Math Function1' */

          /* Switch: '<S206>/Switch' incorporates:
           *  Constant: '<S206>/Constant'
           *  Product: '<S206>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S206>/Switch' */

          /* MinMax: '<S194>/Max' incorporates:
           *  Constant: '<S192>/L1'
           *  Constant: '<S192>/R'
           *  Gain: '<S194>/Gain'
           */
          rtb_Divide_l_idx_2 = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S194>/SearchL1RefWP' incorporates:
           *  Constant: '<S192>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_cg[0] = 0.0F;
          rtb_P_cg[1] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.cur_waypoint[0]) &&
              (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.cur_waypoint[1]) &&
              (rtb_Divide_l_idx_2 == FMS_PARAM.FW_L1)) {
            rtb_n = 0;
          } else {
            rtb_Divide_or = FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R;
            rtb_P_dg[0] = rtb_Divide_or * rtb_Divide_or;
            rtb_Square_h[0] = rtb_Divide_or;
            rtb_Divide_or = FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Divide_or * rtb_Divide_or + rtb_P_dg[0]);
            rtb_u_mm = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Switch_fz_idx_1 = ((d * d + rtb_u_mm) - rtb_Divide_l_idx_2 *
              rtb_Divide_l_idx_2) / (2.0F * d);
            rtb_Square_h[0] /= d;
            rtb_Divide_or /= d;
            d = rtb_Switch_fz_idx_1 * rtb_Switch_fz_idx_1;
            if (d > rtb_u_mm) {
              rtb_n = 0;
            } else if (d == rtb_u_mm) {
              rtb_n = 1;
              rtb_P_cg[0] = rtb_Switch_fz_idx_1 * rtb_Square_h[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_cg[1] = rtb_Switch_fz_idx_1 * rtb_Divide_or +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_u_mm = sqrtf(rtb_u_mm - d);
              rtb_P_cg[0] = (rtb_Switch_fz_idx_1 * rtb_Square_h[0] +
                             FMS_U.INS_Out.x_R) + rtb_u_mm * -rtb_Divide_or;
              rtb_P_cg[1] = (rtb_Switch_fz_idx_1 * rtb_Divide_or +
                             FMS_U.INS_Out.y_R) + rtb_u_mm * rtb_Square_h[0];
            }
          }

          /* End of MATLAB Function: '<S194>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S197>/Compare' incorporates:
           *  Constant: '<S197>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S194>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_dg[0] = rtb_Divide_or * rtb_Divide_or;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Divide_or = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_dg[1] = rtb_Divide_or * rtb_Divide_or;

          /* Switch: '<S194>/Switch' incorporates:
           *  Constant: '<S192>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S194>/OutRegionRegWP'
           *  Product: '<S208>/Divide'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_u_mm = rtb_P_cg[0];
          } else if (rtb_P_dg[0] + rtb_P_dg[1] > rtb_Divide_l_idx_2 *
                     rtb_Divide_l_idx_2) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S194>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_u_mm = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_u_mm = rtb_Switch_ov[0] / rtb_Switch_ov[2] * FMS_PARAM.FW_L1 +
              FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S195>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Square_h[0] = rtb_u_mm - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S194>/Switch' incorporates:
           *  Constant: '<S192>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S194>/OutRegionRegWP'
           *  Product: '<S208>/Divide'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_u_mm = rtb_P_cg[1];
          } else if (rtb_P_dg[0] + rtb_P_dg[1] > rtb_Divide_l_idx_2 *
                     rtb_Divide_l_idx_2) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S194>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_u_mm = FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_u_mm = rtb_Switch_ov[1] / rtb_Switch_ov[2] * FMS_PARAM.FW_L1 +
              FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S195>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Square_h[1] = rtb_u_mm - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S204>/Sum of Elements' incorporates:
           *  Math: '<S204>/Math Function'
           */
          d = rtb_Square_h[0] * rtb_Square_h[0] + rtb_Square_h[1] *
            rtb_Square_h[1];

          /* Math: '<S204>/Math Function1' incorporates:
           *  Sum: '<S204>/Sum of Elements'
           *
           * About '<S204>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S204>/Math Function1' */

          /* Switch: '<S204>/Switch' incorporates:
           *  Constant: '<S204>/Constant'
           *  Product: '<S204>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_ov[0] = rtb_Square_h[0];
            rtb_Switch_ov[1] = rtb_Square_h[1];
            rtb_Switch_ov[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S204>/Switch' */

          /* Product: '<S204>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S207>/Sum of Elements' incorporates:
           *  Math: '<S207>/Math Function'
           *  SignalConversion: '<S207>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S207>/Math Function1' incorporates:
           *  Sum: '<S207>/Sum of Elements'
           *
           * About '<S207>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S207>/Math Function1' */

          /* Switch: '<S207>/Switch' incorporates:
           *  Constant: '<S207>/Constant'
           *  Product: '<S207>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_ov[0] = rtb_Divide_n4[1];
            rtb_Switch_ov[1] = rtb_Divide_n4[0];
            rtb_Switch_ov[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S207>/Switch' */

          /* Product: '<S207>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S206>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S207>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S206>/Divide' */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S205>/Subtract' incorporates:
           *  Product: '<S205>/Multiply'
           *  Product: '<S205>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S201>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S201>/Sign1' */

          /* Switch: '<S201>/Switch2' incorporates:
           *  Constant: '<S201>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S201>/Switch2' */

          /* DotProduct: '<S201>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S201>/Acos' incorporates:
           *  DotProduct: '<S201>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S201>/Multiply' incorporates:
           *  Trigonometry: '<S201>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S200>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S200>/Saturation' */

          /* Delay: '<S191>/Delay' incorporates:
           *  Gain: '<S193>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_ncp = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* BusAssignment: '<S186>/Bus Assignment' incorporates:
           *  Constant: '<S186>/Constant'
           *  Constant: '<S186>/Constant3'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S200>/Divide' incorporates:
           *  Constant: '<S192>/L1'
           *  Gain: '<S200>/Gain'
           *  Math: '<S200>/Square'
           *  Product: '<S200>/Multiply1'
           *  Trigonometry: '<S200>/Sin'
           */
          d = 2.0F * (rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3) * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S192>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S186>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S192>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S191>/Gain2' incorporates:
           *  Delay: '<S191>/Delay'
           *  Gain: '<S193>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sum: '<S191>/Sum'
           */
          d = (FMS_DW.Delay_DSTATE_ncp - (-FMS_U.INS_Out.h_R)) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S191>/Saturation1' */
          if (d > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (d < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S186>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S191>/Saturation1' */

          /* Update for Delay: '<S196>/start_vel' */
          FMS_DW.icLoad_l = 0U;

          /* Update for Delay: '<S191>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S62>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S62>/Unknown' incorporates:
           *  ActionPort: '<S190>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S62>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
         *  ActionPort: '<S60>/Action Port'
         */
        /* SwitchCase: '<S60>/Switch Case' incorporates:
         *  RelationalOperator: '<S160>/FixPt Relational Operator'
         *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S160>/Delay Input1'
         *
         * Block description for '<S160>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_h) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S60>/Offboard' incorporates:
           *  ActionPort: '<S158>/Action Port'
           */
          /* BusAssignment: '<S158>/Bus Assignment' incorporates:
           *  Constant: '<S158>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S60>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S60>/Mission' incorporates:
             *  ActionPort: '<S157>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S60>/Switch Case' incorporates:
             *  UnitDelay: '<S160>/Delay Input1'
             *
             * Block description for '<S160>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S60>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S60>/Mission' incorporates:
           *  ActionPort: '<S157>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S157>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S161>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S179>/Math Function' incorporates:
           *  RelationalOperator: '<S160>/FixPt Relational Operator'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S160>/Delay Input1'
           *
           * Block description for '<S160>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Divide_n4[0] = rtb_u_mm;
          rtb_Divide_n4[1] = rtb_Divide_or;

          /* Sum: '<S179>/Sum of Elements' */
          d = rtb_u_mm + rtb_Divide_or;

          /* Math: '<S179>/Math Function1' incorporates:
           *  Sum: '<S179>/Sum of Elements'
           *
           * About '<S179>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S179>/Math Function1' */

          /* Switch: '<S179>/Switch' incorporates:
           *  Constant: '<S179>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S179>/Product'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S179>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S169>/NearbyRefWP' incorporates:
           *  Constant: '<S167>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Divide_l_idx_2);

          /* MATLAB Function: '<S169>/SearchL1RefWP' incorporates:
           *  Constant: '<S167>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_u_mm);

          /* MATLAB Function: '<S169>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S169>/Switch1' incorporates:
           *  Constant: '<S172>/Constant'
           *  RelationalOperator: '<S172>/Compare'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S171>/Compare' incorporates:
             *  Constant: '<S171>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_u_mm >= 0.0F);

            /* Switch: '<S169>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S169>/Switch' */
          }

          /* End of Switch: '<S169>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S170>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S180>/Sum of Elements' incorporates:
           *  Math: '<S180>/Math Function'
           */
          d = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S180>/Math Function1' incorporates:
           *  Sum: '<S180>/Sum of Elements'
           *
           * About '<S180>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S180>/Math Function1' */

          /* Switch: '<S180>/Switch' incorporates:
           *  Constant: '<S180>/Constant'
           *  Product: '<S180>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Divide_n4[1];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S180>/Switch' */

          /* Product: '<S179>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S182>/Sum of Elements' incorporates:
           *  Math: '<S182>/Math Function'
           *  SignalConversion: '<S182>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S182>/Math Function1' incorporates:
           *  Sum: '<S182>/Sum of Elements'
           *
           * About '<S182>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S182>/Math Function1' */

          /* Switch: '<S182>/Switch' incorporates:
           *  Constant: '<S182>/Constant'
           *  Product: '<S182>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_fz_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_fz_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S182>/Switch' */

          /* Product: '<S180>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S183>/Sum of Elements' incorporates:
           *  Math: '<S183>/Math Function'
           *  SignalConversion: '<S183>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S183>/Math Function1' incorporates:
           *  Sum: '<S183>/Sum of Elements'
           *
           * About '<S183>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S183>/Math Function1' */

          /* Switch: '<S183>/Switch' incorporates:
           *  Constant: '<S183>/Constant'
           *  Product: '<S183>/Product'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S183>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S164>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_2 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S183>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S182>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S164>/Sum1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S183>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S182>/Divide' */
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S164>/Sum1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_mm = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S164>/Divide' incorporates:
           *  Math: '<S165>/Square'
           *  Math: '<S166>/Square'
           *  Sqrt: '<S165>/Sqrt'
           *  Sqrt: '<S166>/Sqrt'
           *  Sum: '<S164>/Sum'
           *  Sum: '<S164>/Sum1'
           *  Sum: '<S165>/Sum of Elements'
           *  Sum: '<S166>/Sum of Elements'
           */
          rtb_u_mm = sqrtf(rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2 + d * d) /
            sqrtf(rtb_Divide_or * rtb_Divide_or + rtb_u_mm * rtb_u_mm);

          /* Saturate: '<S164>/Saturation' */
          if (rtb_u_mm > 1.0F) {
            rtb_u_mm = 1.0F;
          } else {
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = 0.0F;
            }
          }

          /* End of Saturate: '<S164>/Saturation' */

          /* Sum: '<S181>/Subtract' incorporates:
           *  Product: '<S181>/Multiply'
           *  Product: '<S181>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S177>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S177>/Sign1' */

          /* Switch: '<S177>/Switch2' incorporates:
           *  Constant: '<S177>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S177>/Switch2' */

          /* DotProduct: '<S177>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S177>/Acos' incorporates:
           *  DotProduct: '<S177>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S177>/Multiply' incorporates:
           *  Trigonometry: '<S177>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S176>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S176>/Saturation' */

          /* BusAssignment: '<S161>/Bus Assignment' incorporates:
           *  Constant: '<S161>/Constant'
           *  Constant: '<S161>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S176>/Divide' incorporates:
           *  Constant: '<S167>/L1'
           *  Gain: '<S176>/Gain'
           *  Math: '<S176>/Square'
           *  Product: '<S176>/Multiply1'
           *  Trigonometry: '<S176>/Sin'
           */
          d = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S167>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S161>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S161>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S161>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S167>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S162>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S164>/Multiply'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S162>/Sum2'
           *  Sum: '<S164>/Add'
           *  Sum: '<S164>/Subtract'
           */
          d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                 FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_mm +
                FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S162>/Saturation1' */
          if (d > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S161>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (d < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S161>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S161>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S162>/Saturation1' */
          /* End of Outputs for SubSystem: '<S157>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S160>/Delay Input1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S160>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S60>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S60>/Unknown' incorporates:
           *  ActionPort: '<S159>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S60>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
         *  ActionPort: '<S59>/Action Port'
         */
        /* SwitchCase: '<S59>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_as;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_as) {
          switch (rtPrevAction) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S72>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S107>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S93>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S59>/Stabilize' incorporates:
             *  ActionPort: '<S66>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S59>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S150>/Integrator'
             *  DiscreteIntegrator: '<S150>/Integrator1'
             *  DiscreteIntegrator: '<S151>/Integrator'
             *  DiscreteIntegrator: '<S151>/Integrator1'
             *  DiscreteIntegrator: '<S155>/Integrator'
             *  DiscreteIntegrator: '<S155>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S59>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Stabilize' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          /* Product: '<S152>/Multiply1' incorporates:
           *  Constant: '<S152>/const1'
           *  DiscreteIntegrator: '<S150>/Integrator'
           */
          rtb_Switch_fz_idx_2 = FMS_DW.Integrator_DSTATE_a * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S148>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S148>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S152>/Add' incorporates:
           *  DiscreteIntegrator: '<S150>/Integrator1'
           *  Gain: '<S145>/Gain'
           *  Gain: '<S148>/Gain'
           *  Sum: '<S150>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Switch_fz_idx_2;

          /* Signum: '<S152>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3;
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
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_Switch_fz_idx_2;

          /* Sum: '<S152>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - rtb_Switch_fz_idx_1) +
            rtb_Switch_fz_idx_2;

          /* Sum: '<S152>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_ny;

          /* Sum: '<S152>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_ny;

          /* Signum: '<S152>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign1' */

          /* Signum: '<S152>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign2' */

          /* Sum: '<S152>/Add5' incorporates:
           *  Gain: '<S152>/Gain2'
           *  Product: '<S152>/Multiply4'
           *  Sum: '<S152>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) *
            0.5F * rtb_u_mm;

          /* BusAssignment: '<S66>/Bus Assignment' incorporates:
           *  Constant: '<S66>/Constant'
           *  DiscreteIntegrator: '<S150>/Integrator1'
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  DiscreteIntegrator: '<S155>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S147>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S147>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S66>/Bus Assignment' incorporates:
           *  Constant: '<S147>/Constant5'
           *  Gain: '<S147>/Gain2'
           *  Sum: '<S147>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * d), 65536.0F) + 1000U);

          /* Product: '<S156>/Multiply1' incorporates:
           *  Constant: '<S156>/const1'
           *  DiscreteIntegrator: '<S155>/Integrator'
           */
          rtb_Switch_fz_idx_2 = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S154>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S154>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S156>/Add' incorporates:
           *  DiscreteIntegrator: '<S155>/Integrator1'
           *  Gain: '<S146>/Gain1'
           *  Gain: '<S154>/Gain'
           *  Sum: '<S155>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Switch_fz_idx_2;

          /* Signum: '<S156>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S156>/Sign' */

          /* Sum: '<S156>/Add2' incorporates:
           *  Abs: '<S156>/Abs'
           *  Gain: '<S156>/Gain'
           *  Gain: '<S156>/Gain1'
           *  Product: '<S156>/Multiply2'
           *  Product: '<S156>/Multiply3'
           *  Sqrt: '<S156>/Sqrt'
           *  Sum: '<S156>/Add1'
           *  Sum: '<S156>/Subtract'
           */
          rtb_Subtract3_d = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_hr) * FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F * d +
            rtb_Switch_fz_idx_2;

          /* Sum: '<S156>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_0 - rtb_Subtract3_d) +
            rtb_Switch_fz_idx_2;

          /* Sum: '<S156>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_0 + FMS_ConstB.d_hr;

          /* Sum: '<S156>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_hr;

          /* Signum: '<S156>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign1' */

          /* Signum: '<S156>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign2' */

          /* Sum: '<S156>/Add5' incorporates:
           *  Gain: '<S156>/Gain2'
           *  Product: '<S156>/Multiply4'
           *  Sum: '<S156>/Subtract2'
           */
          rtb_Subtract3_d += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_0) * 0.5F *
            rtb_Divide_l_idx_3;

          /* Sum: '<S156>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Subtract3_d + FMS_ConstB.d_hr;

          /* Sum: '<S156>/Subtract3' */
          rtb_u_mm = rtb_Subtract3_d - FMS_ConstB.d_hr;

          /* Product: '<S156>/Divide' */
          rtb_Divide_or = rtb_Subtract3_d / FMS_ConstB.d_hr;

          /* Signum: '<S156>/Sign5' incorporates:
           *  Signum: '<S156>/Sign6'
           */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Subtract3_d > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Subtract3_d;

            /* Signum: '<S156>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Subtract3_d;
          }

          /* End of Signum: '<S156>/Sign5' */

          /* Product: '<S153>/Multiply1' incorporates:
           *  Constant: '<S153>/const1'
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          rtb_Subtract3_d = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S149>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S149>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S153>/Add' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  Gain: '<S145>/Gain1'
           *  Gain: '<S149>/Gain'
           *  Sum: '<S151>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * d * -FMS_PARAM.FW_PITCH_LIM) + rtb_Subtract3_d;

          /* Signum: '<S153>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S153>/Sign' */

          /* Sum: '<S153>/Add2' incorporates:
           *  Abs: '<S153>/Abs'
           *  Gain: '<S153>/Gain'
           *  Gain: '<S153>/Gain1'
           *  Product: '<S153>/Multiply2'
           *  Product: '<S153>/Multiply3'
           *  Sqrt: '<S153>/Sqrt'
           *  Sum: '<S153>/Add1'
           *  Sum: '<S153>/Subtract'
           */
          rtb_Switch_fz_idx_2 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_my) * FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F * d +
            rtb_Subtract3_d;

          /* Sum: '<S153>/Add4' */
          rtb_Subtract3_d += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_2;

          /* Sum: '<S153>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_my;

          /* Sum: '<S153>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_my;

          /* Signum: '<S153>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S153>/Sign1' */

          /* Signum: '<S153>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S153>/Sign2' */

          /* Sum: '<S153>/Add5' incorporates:
           *  Gain: '<S153>/Gain2'
           *  Product: '<S153>/Multiply4'
           *  Sum: '<S153>/Subtract2'
           */
          rtb_Switch_fz_idx_2 += (d - rtb_Switch_fz_idx_0) * 0.5F *
            rtb_Subtract3_d;

          /* Update for DiscreteIntegrator: '<S150>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S150>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Sum: '<S152>/Subtract3' */
          d = rtb_Switch_fz_idx_1 - FMS_ConstB.d_ny;

          /* Sum: '<S152>/Add6' */
          rtb_Subtract3_d = rtb_Switch_fz_idx_1 + FMS_ConstB.d_ny;

          /* Signum: '<S152>/Sign5' incorporates:
           *  Signum: '<S152>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;

            /* Signum: '<S152>/Sign6' */
            D = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Switch_fz_idx_0 = 1.0F;

            /* Signum: '<S152>/Sign6' */
            D = 1.0F;
          } else {
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;

            /* Signum: '<S152>/Sign6' */
            D = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S152>/Sign5' */

          /* Signum: '<S152>/Sign3' */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Subtract3_d = -1.0F;
          } else {
            if (rtb_Subtract3_d > 0.0F) {
              rtb_Subtract3_d = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign3' */

          /* Signum: '<S152>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S152>/Sign4' */

          /* Update for DiscreteIntegrator: '<S150>/Integrator' incorporates:
           *  Constant: '<S152>/const'
           *  Gain: '<S152>/Gain3'
           *  Product: '<S152>/Divide'
           *  Product: '<S152>/Multiply5'
           *  Product: '<S152>/Multiply6'
           *  Sum: '<S152>/Subtract4'
           *  Sum: '<S152>/Subtract5'
           *  Sum: '<S152>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_ny
            - rtb_Switch_fz_idx_0) * FMS_ConstB.Gain4_ko * ((rtb_Subtract3_d - d)
            * 0.5F) - D * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S151>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S155>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S155>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S156>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign3' */

          /* Signum: '<S156>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign4' */

          /* Update for DiscreteIntegrator: '<S155>/Integrator' incorporates:
           *  Constant: '<S156>/const'
           *  Gain: '<S156>/Gain3'
           *  Product: '<S156>/Multiply5'
           *  Product: '<S156>/Multiply6'
           *  Sum: '<S156>/Subtract4'
           *  Sum: '<S156>/Subtract5'
           *  Sum: '<S156>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 15.707963F) * 0.004F;

          /* Sum: '<S153>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_2 - FMS_ConstB.d_my;

          /* Sum: '<S153>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_2 + FMS_ConstB.d_my;

          /* Signum: '<S153>/Sign5' incorporates:
           *  Signum: '<S153>/Sign6'
           */
          if (rtb_Switch_fz_idx_2 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S153>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_2 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S153>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_2;

            /* Signum: '<S153>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_2;
          }

          /* End of Signum: '<S153>/Sign5' */

          /* Signum: '<S153>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S153>/Sign3' */

          /* Signum: '<S153>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S153>/Sign4' */

          /* Update for DiscreteIntegrator: '<S151>/Integrator' incorporates:
           *  Constant: '<S153>/const'
           *  Gain: '<S153>/Gain3'
           *  Product: '<S153>/Divide'
           *  Product: '<S153>/Multiply5'
           *  Product: '<S153>/Multiply6'
           *  Sum: '<S153>/Subtract4'
           *  Sum: '<S153>/Subtract5'
           *  Sum: '<S153>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_Switch_fz_idx_2 / FMS_ConstB.d_my
            - rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_k2 * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S59>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S59>/Altitude' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S59>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S84>/Integrator'
             *  DiscreteIntegrator: '<S84>/Integrator1'
             *  DiscreteIntegrator: '<S87>/Integrator'
             *  DiscreteIntegrator: '<S87>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S59>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S59>/Altitude' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S59>/Switch Case' incorporates:
             *  Chart: '<S73>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S59>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Altitude' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S73>/Motion Status' incorporates:
           *  Abs: '<S73>/Abs'
           *  Abs: '<S73>/Abs1'
           *  Constant: '<S81>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S81>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S72>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S72>/Hold Control' incorporates:
               *  ActionPort: '<S75>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S72>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S72>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S72>/Hold Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S72>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S72>/Brake Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S72>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S72>/Move Control' incorporates:
               *  ActionPort: '<S76>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S72>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S72>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S72>/Move Control' incorporates:
             *  ActionPort: '<S76>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S72>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S72>/Switch Case' */

          /* BusAssignment: '<S64>/Bus Assignment' incorporates:
           *  Constant: '<S64>/Constant'
           *  DiscreteIntegrator: '<S84>/Integrator1'
           *  DiscreteIntegrator: '<S87>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S68>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S68>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S64>/Bus Assignment' incorporates:
           *  Gain: '<S68>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * d;

          /* Saturate: '<S72>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S72>/Saturation1' */

          /* Product: '<S88>/Multiply1' incorporates:
           *  Constant: '<S88>/const1'
           *  DiscreteIntegrator: '<S87>/Integrator'
           */
          rtb_Switch_fz_idx_0 = FMS_DW.Integrator_DSTATE_e * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S86>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S86>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S88>/Add' incorporates:
           *  DiscreteIntegrator: '<S87>/Integrator1'
           *  Gain: '<S71>/Gain1'
           *  Gain: '<S86>/Gain'
           *  Sum: '<S87>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Switch_fz_idx_0;

          /* Signum: '<S88>/Sign' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S88>/Sign' */

          /* Sum: '<S88>/Add2' incorporates:
           *  Abs: '<S88>/Abs'
           *  Gain: '<S88>/Gain'
           *  Gain: '<S88>/Gain1'
           *  Product: '<S88>/Multiply2'
           *  Product: '<S88>/Multiply3'
           *  Sqrt: '<S88>/Sqrt'
           *  Sum: '<S88>/Add1'
           *  Sum: '<S88>/Subtract'
           */
          rtb_Sign5_mn = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_1) +
            FMS_ConstB.d_nt) * FMS_ConstB.d_nt) - FMS_ConstB.d_nt) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_Switch_fz_idx_0;

          /* Sum: '<S88>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_1 - rtb_Sign5_mn) +
            rtb_Switch_fz_idx_0;

          /* Sum: '<S88>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 + FMS_ConstB.d_nt;

          /* Sum: '<S88>/Subtract1' */
          rtb_Switch_fz_idx_1 -= FMS_ConstB.d_nt;

          /* Signum: '<S88>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S88>/Sign1' */

          /* Signum: '<S88>/Sign2' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S88>/Sign2' */

          /* Sum: '<S88>/Add5' incorporates:
           *  Gain: '<S88>/Gain2'
           *  Product: '<S88>/Multiply4'
           *  Sum: '<S88>/Subtract2'
           */
          rtb_Sign5_mn += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_1) * 0.5F *
            rtb_Divide_l_idx_3;

          /* Sum: '<S88>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Sign5_mn + FMS_ConstB.d_nt;

          /* Sum: '<S88>/Subtract3' */
          rtb_u_mm = rtb_Sign5_mn - FMS_ConstB.d_nt;

          /* Product: '<S88>/Divide' */
          rtb_Switch_fz_idx_2 = rtb_Sign5_mn / FMS_ConstB.d_nt;

          /* Signum: '<S88>/Sign5' incorporates:
           *  Signum: '<S88>/Sign6'
           */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S88>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Sign5_mn > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S88>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Sign5_mn;

            /* Signum: '<S88>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Sign5_mn;
          }

          /* End of Signum: '<S88>/Sign5' */

          /* Product: '<S85>/Multiply1' incorporates:
           *  Constant: '<S85>/const1'
           *  DiscreteIntegrator: '<S84>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S83>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S83>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S85>/Add' incorporates:
           *  DiscreteIntegrator: '<S84>/Integrator1'
           *  Gain: '<S70>/Gain'
           *  Gain: '<S83>/Gain'
           *  Sum: '<S84>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.FW_ROLL_LIM) + rtb_Sign5_mn;

          /* Signum: '<S85>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
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
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_bi) * FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S85>/Add4' */
          rtb_Sign5_mn += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1;

          /* Sum: '<S85>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_bi;

          /* Sum: '<S85>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_bi;

          /* Signum: '<S85>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign1' */

          /* Signum: '<S85>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign2' */

          /* Sum: '<S85>/Add5' incorporates:
           *  Gain: '<S85>/Gain2'
           *  Product: '<S85>/Multiply4'
           *  Sum: '<S85>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (d - rtb_Switch_fz_idx_0) * 0.5F * rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S84>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S84>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S87>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S87>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Signum: '<S88>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S88>/Sign3' */

          /* Signum: '<S88>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S88>/Sign4' */

          /* Update for DiscreteIntegrator: '<S87>/Integrator' incorporates:
           *  Constant: '<S88>/const'
           *  Gain: '<S88>/Gain3'
           *  Product: '<S88>/Multiply5'
           *  Product: '<S88>/Multiply6'
           *  Sum: '<S88>/Subtract4'
           *  Sum: '<S88>/Subtract5'
           *  Sum: '<S88>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_kf * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 15.707963F) * 0.004F;

          /* Sum: '<S85>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 - FMS_ConstB.d_bi;

          /* Sum: '<S85>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_1 + FMS_ConstB.d_bi;

          /* Signum: '<S85>/Sign5' incorporates:
           *  Signum: '<S85>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S85>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S85>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;

            /* Signum: '<S85>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S85>/Sign5' */

          /* Signum: '<S85>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S85>/Sign3' */

          /* Signum: '<S85>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_bi
            - rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_d1 * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S59>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S59>/Position' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S59>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S105>/Integrator'
             *  DiscreteIntegrator: '<S105>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S59>/Position' */

            /* SystemReset for IfAction SubSystem: '<S59>/Position' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S59>/Switch Case' incorporates:
             *  Chart: '<S108>/Motion State'
             *  Chart: '<S94>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_DW.temporalCounter_i1_ie = 0U;
            FMS_DW.is_active_c26_FMS = 0U;
            FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S59>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Position' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* Outputs for IfAction SubSystem: '<S107>/Hold Control' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S107>/Switch Case' incorporates:
           *  Gain: '<S143>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Trigonometry: '<S136>/Trigonometric Function1'
           *  Trigonometry: '<S136>/Trigonometric Function3'
           *  Trigonometry: '<S144>/Trigonometric Function1'
           *  Trigonometry: '<S144>/Trigonometric Function3'
           */
          rtb_u_mm = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S107>/Hold Control' */

          /* Trigonometry: '<S144>/Trigonometric Function1' */
          rtb_MatrixConcatenate1_i[0] = rtb_u_mm;

          /* Outputs for IfAction SubSystem: '<S107>/Hold Control' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S107>/Switch Case' incorporates:
           *  Gain: '<S143>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Trigonometry: '<S136>/Trigonometric Function'
           *  Trigonometry: '<S144>/Trigonometric Function'
           *  Trigonometry: '<S144>/Trigonometric Function2'
           */
          rtb_Switch_fz_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S107>/Hold Control' */

          /* Trigonometry: '<S144>/Trigonometric Function' */
          rtb_MatrixConcatenate1_i[1] = rtb_Switch_fz_idx_0;

          /* SignalConversion: '<S144>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S144>/Constant3'
           */
          rtb_MatrixConcatenate1_i[2] = 0.0F;

          /* Gain: '<S144>/Gain' */
          rtb_MatrixConcatenate1_i[3] = -rtb_Switch_fz_idx_0;

          /* Trigonometry: '<S144>/Trigonometric Function3' */
          rtb_MatrixConcatenate1_i[4] = rtb_u_mm;

          /* SignalConversion: '<S144>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S144>/Constant4'
           */
          rtb_MatrixConcatenate1_i[5] = 0.0F;

          /* SignalConversion: '<S144>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S94>/Motion Status' incorporates:
           *  Abs: '<S94>/Abs'
           *  Abs: '<S94>/Abs1'
           *  Constant: '<S102>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S102>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* Logic: '<S108>/Logical Operator' incorporates:
           *  Abs: '<S108>/Abs1'
           *  Abs: '<S108>/Abs2'
           *  Constant: '<S140>/Constant'
           *  Constant: '<S141>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S140>/Compare'
           *  RelationalOperator: '<S141>/Compare'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
            FMS_PARAM.YAW_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S108>/Motion State' incorporates:
           *  Abs: '<S108>/Abs'
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

              /* Product: '<S108>/Multiply' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S41>/Signal Copy1'
               */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_MatrixConcatenate1_i_0[rtb_n] =
                  rtb_MatrixConcatenate1_i[rtb_n + 6] * FMS_U.INS_Out.vd +
                  (rtb_MatrixConcatenate1_i[rtb_n + 3] * FMS_U.INS_Out.ve +
                   rtb_MatrixConcatenate1_i[rtb_n] * FMS_U.INS_Out.vn);

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              }

              /* End of Product: '<S108>/Multiply' */
              if ((fabsf(rtb_MatrixConcatenate1_i_0[1]) <= 0.2) ||
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

          /* End of Chart: '<S108>/Motion State' */

          /* SwitchCase: '<S107>/Switch Case' incorporates:
           *  MATLAB Function: '<S113>/SearchL1RefWP'
           *  Product: '<S135>/Divide'
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
              /* InitializeConditions for IfAction SubSystem: '<S107>/Hold Control' incorporates:
               *  ActionPort: '<S110>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S107>/Switch Case' incorporates:
               *  Delay: '<S115>/start_vel'
               *  Delay: '<S115>/start_wp'
               */
              FMS_DW.icLoad_g = 1U;
              FMS_DW.icLoad_e = 1U;

              /* End of InitializeConditions for SubSystem: '<S107>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S107>/Hold Control' incorporates:
             *  ActionPort: '<S110>/Action Port'
             */
            /* Trigonometry: '<S136>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_u_mm;

            /* Trigonometry: '<S136>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S136>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S136>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S136>/Gain' incorporates:
             *  Gain: '<S134>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Trigonometry: '<S136>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S136>/Trigonometric Function3' */
            rtb_Transpose[4] = rtb_u_mm;

            /* SignalConversion: '<S136>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S136>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_jn[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_jn[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_jn[2];

            /* Math: '<S115>/Transpose' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_i[3 * rtb_n] = rtb_Transpose[rtb_n];
              rtb_MatrixConcatenate1_i[1 + 3 * rtb_n] = rtb_Transpose[rtb_n + 3];
              rtb_MatrixConcatenate1_i[2 + 3 * rtb_n] = rtb_Transpose[rtb_n + 6];
            }

            for (rtb_n = 0; rtb_n < 9; rtb_n++) {
              rtb_Transpose[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n];
            }

            /* End of Math: '<S115>/Transpose' */

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Product: '<S117>/Divide' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_u_mm = FMS_U.INS_Out.quat[0] / d;
            rtb_Switch_fz_idx_2 = FMS_U.INS_Out.quat[1] / d;
            rtb_Switch_fz_idx_0 = FMS_U.INS_Out.quat[2] / d;
            d = FMS_U.INS_Out.quat[3] / d;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S118>/Subtract' incorporates:
             *  Math: '<S118>/Square'
             *  Math: '<S118>/Square1'
             *  Math: '<S118>/Square2'
             *  Math: '<S118>/Square3'
             *  Sum: '<S118>/Add'
             *  Sum: '<S118>/Add1'
             */
            rtb_MatrixConcatenate1_i[0] = (rtb_u_mm * rtb_u_mm +
              rtb_Switch_fz_idx_2 * rtb_Switch_fz_idx_2) - (rtb_Switch_fz_idx_0 *
              rtb_Switch_fz_idx_0 + d * d);

            /* Gain: '<S118>/Gain' incorporates:
             *  Product: '<S118>/Multiply'
             *  Product: '<S118>/Multiply1'
             *  Sum: '<S118>/Subtract1'
             */
            rtb_MatrixConcatenate1_i[1] = (rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_0 - rtb_u_mm * d) * 2.0F;

            /* Gain: '<S118>/Gain1' incorporates:
             *  Product: '<S118>/Multiply2'
             *  Product: '<S118>/Multiply3'
             *  Sum: '<S118>/Add2'
             */
            rtb_MatrixConcatenate1_i[2] = (rtb_Switch_fz_idx_2 * d + rtb_u_mm *
              rtb_Switch_fz_idx_0) * 2.0F;

            /* Gain: '<S119>/Gain' incorporates:
             *  Product: '<S119>/Multiply'
             *  Product: '<S119>/Multiply1'
             *  Sum: '<S119>/Add3'
             */
            rtb_MatrixConcatenate1_i[3] = (rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_0 + rtb_u_mm * d) * 2.0F;

            /* Sum: '<S119>/Subtract' incorporates:
             *  Math: '<S119>/Square'
             *  Math: '<S119>/Square1'
             *  Math: '<S119>/Square2'
             *  Math: '<S119>/Square3'
             *  Sum: '<S119>/Add'
             *  Sum: '<S119>/Add1'
             */
            rtb_MatrixConcatenate1_i[4] = (rtb_u_mm * rtb_u_mm +
              rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0) - (rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_2 + d * d);

            /* Gain: '<S119>/Gain1' incorporates:
             *  Product: '<S119>/Multiply2'
             *  Product: '<S119>/Multiply3'
             *  Sum: '<S119>/Subtract1'
             */
            rtb_MatrixConcatenate1_i[5] = (rtb_Switch_fz_idx_0 * d - rtb_u_mm *
              rtb_Switch_fz_idx_2) * 2.0F;

            /* Gain: '<S120>/Gain' incorporates:
             *  Product: '<S120>/Multiply'
             *  Product: '<S120>/Multiply1'
             *  Sum: '<S120>/Subtract2'
             */
            rtb_MatrixConcatenate1_i[6] = (rtb_Switch_fz_idx_2 * d - rtb_u_mm *
              rtb_Switch_fz_idx_0) * 2.0F;

            /* Gain: '<S120>/Gain1' incorporates:
             *  Product: '<S120>/Multiply2'
             *  Product: '<S120>/Multiply3'
             *  Sum: '<S120>/Add2'
             */
            rtb_MatrixConcatenate1_i[7] = (rtb_Switch_fz_idx_0 * d + rtb_u_mm *
              rtb_Switch_fz_idx_2) * 2.0F;

            /* Sum: '<S120>/Subtract' incorporates:
             *  Math: '<S120>/Square'
             *  Math: '<S120>/Square1'
             *  Math: '<S120>/Square2'
             *  Math: '<S120>/Square3'
             *  Sum: '<S120>/Add'
             *  Sum: '<S120>/Add1'
             */
            rtb_MatrixConcatenate1_i[8] = (rtb_u_mm * rtb_u_mm + d * d) -
              (rtb_Switch_fz_idx_2 * rtb_Switch_fz_idx_2 + rtb_Switch_fz_idx_0 *
               rtb_Switch_fz_idx_0);

            /* Delay: '<S115>/start_vel' incorporates:
             *  Product: '<S115>/Multiply'
             */
            if (FMS_DW.icLoad_g != 0) {
              /* Product: '<S115>/Multiply' */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n];
              }

              FMS_DW.start_vel_DSTATE[0] = rtb_MatrixConcatenate1_i_0[0];
              FMS_DW.start_vel_DSTATE[1] = rtb_MatrixConcatenate1_i_0[1];
            }

            /* Sum: '<S135>/Sum of Elements' incorporates:
             *  Delay: '<S115>/start_vel'
             *  Math: '<S135>/Math Function'
             */
            d = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
              FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

            /* Math: '<S135>/Math Function1' incorporates:
             *  Sum: '<S135>/Sum of Elements'
             *
             * About '<S135>/Math Function1':
             *  Operator: sqrt
             */
            if (d < 0.0F) {
              rtb_u_mm = -sqrtf(fabsf(d));
            } else {
              rtb_u_mm = sqrtf(d);
            }

            /* End of Math: '<S135>/Math Function1' */

            /* Switch: '<S135>/Switch' incorporates:
             *  Constant: '<S135>/Constant'
             *  Delay: '<S115>/start_vel'
             *  Product: '<S135>/Product'
             */
            if (rtb_u_mm > 0.0F) {
              rtb_Switch_d0[0] = FMS_DW.start_vel_DSTATE[0];
              rtb_Switch_d0[1] = FMS_DW.start_vel_DSTATE[1];
              rtb_Switch_d0[2] = rtb_u_mm;
            } else {
              rtb_Switch_d0[0] = 0.0F;
              rtb_Switch_d0[1] = 0.0F;
              rtb_Switch_d0[2] = 1.0F;
            }

            /* End of Switch: '<S135>/Switch' */

            /* Delay: '<S115>/start_wp' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            if (FMS_DW.icLoad_e != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S113>/SearchL1RefWP' incorporates:
             *  Delay: '<S115>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_u_mm = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Switch_fz_idx_0 = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S135>/Divide' */
            rtb_Divide_or = rtb_Switch_d0[0] / rtb_Switch_d0[2];

            /* MATLAB Function: '<S113>/SearchL1RefWP' */
            d = rtb_Divide_or * rtb_u_mm;
            rtb_Square_h[0] = rtb_Divide_or;

            /* Product: '<S135>/Divide' */
            rtb_Divide_or = rtb_Switch_d0[1] / rtb_Switch_d0[2];

            /* MATLAB Function: '<S113>/SearchL1RefWP' */
            d += rtb_Divide_or * rtb_Switch_fz_idx_0;
            rtb_Sign5_mn = 2.0F * d;
            d = rtb_u_mm * rtb_u_mm;
            rtb_u_mm = 0.0F;

            /* MATLAB Function: '<S113>/SearchL1RefWP' */
            d += rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0;
            rtb_Switch_fz_idx_0 = 0.0F;

            /* MATLAB Function: '<S113>/SearchL1RefWP' incorporates:
             *  Constant: '<S110>/L1'
             *  Delay: '<S115>/start_wp'
             */
            D = rtb_Sign5_mn * rtb_Sign5_mn - (d - FMS_PARAM.FW_L1 *
              FMS_PARAM.FW_L1) * 4.0F;
            d = -1.0F;
            if (D > 0.0F) {
              rtb_u_mm = sqrtf(D);
              d = fmaxf((-rtb_Sign5_mn + rtb_u_mm) / 2.0F, (-rtb_Sign5_mn -
                         rtb_u_mm) / 2.0F);
              rtb_u_mm = d * rtb_Square_h[0] + FMS_DW.start_wp_DSTATE[0];
              rtb_Switch_fz_idx_0 = d * rtb_Divide_or + FMS_DW.start_wp_DSTATE[1];
            } else {
              if (D == 0.0F) {
                d = -rtb_Sign5_mn / 2.0F;
                rtb_u_mm = d * rtb_Square_h[0] + FMS_DW.start_wp_DSTATE[0];
                rtb_Switch_fz_idx_0 = d * rtb_Divide_or +
                  FMS_DW.start_wp_DSTATE[1];
              }
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S113>/OutRegionRefWP' incorporates:
             *  Delay: '<S115>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0])
              * rtb_Square_h[0] + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1])
              * rtb_Divide_or;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_2 = 1.29246971E-26F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_mn = fabsf((rtb_Switch_fz_idx_1 * rtb_Square_h[0] +
                                  FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            if (rtb_Sign5_mn > 1.29246971E-26F) {
              D = 1.0F;
              rtb_Switch_fz_idx_2 = rtb_Sign5_mn;
            } else {
              rtb_Subtract3_d = rtb_Sign5_mn / 1.29246971E-26F;
              D = rtb_Subtract3_d * rtb_Subtract3_d;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_mn = fabsf((rtb_Switch_fz_idx_1 * rtb_Divide_or +
                                  FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            if (rtb_Sign5_mn > rtb_Switch_fz_idx_2) {
              rtb_Subtract3_d = rtb_Switch_fz_idx_2 / rtb_Sign5_mn;
              D = D * rtb_Subtract3_d * rtb_Subtract3_d + 1.0F;
              rtb_Switch_fz_idx_2 = rtb_Sign5_mn;
            } else {
              rtb_Subtract3_d = rtb_Sign5_mn / rtb_Switch_fz_idx_2;
              D += rtb_Subtract3_d * rtb_Subtract3_d;
            }

            D = rtb_Switch_fz_idx_2 * sqrtf(D);
            rtb_Switch_fz_idx_1 += D * 0.577350259F;

            /* Product: '<S112>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n
                + 6] * FMS_U.INS_Out.vd + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                FMS_U.INS_Out.ve + rtb_MatrixConcatenate1_i[rtb_n] *
                FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Product: '<S112>/Multiply' */

            /* Signum: '<S112>/Sign' incorporates:
             *  Math: '<S128>/Square'
             *  Math: '<S129>/Math Function1'
             *  Math: '<S130>/Math Function'
             *  Sum: '<S114>/Subtract'
             *  Switch: '<S110>/Switch'
             *
             * About '<S129>/Math Function1':
             *  Operator: sqrt
             */
            if ((rtb_MatrixConcatenate1_i_0[0] < 0.0F) ||
                (rtb_MatrixConcatenate1_i_0[0] <= 0.0F)) {
              /* Switch: '<S110>/Switch' incorporates:
               *  Constant: '<S110>/Constant'
               */
              FMS_B.Merge_be = 0.0F;
            } else {
              if (rtb_Divide_l_idx_2 < 0.0F) {
                /* Math: '<S129>/Math Function1' incorporates:
                 *  Switch: '<S110>/Switch'
                 *
                 * About '<S129>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                /* Math: '<S129>/Math Function1' incorporates:
                 *  Switch: '<S110>/Switch'
                 *
                 * About '<S129>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* Switch: '<S129>/Switch' incorporates:
               *  Constant: '<S129>/Constant'
               *  Inport: '<Root>/INS_Out'
               *  Product: '<S129>/Product'
               *  SignalConversion: '<S41>/Signal Copy1'
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 > 0.0F) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_Switch_d0[0] = FMS_U.INS_Out.vn;
                rtb_Switch_d0[1] = FMS_U.INS_Out.ve;

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
                rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
              } else {
                rtb_Switch_d0[0] = 0.0F;
                rtb_Switch_d0[1] = 0.0F;
                rtb_Switch_d0[2] = 1.0F;
              }

              /* End of Switch: '<S129>/Switch' */

              /* Product: '<S129>/Divide' incorporates:
               *  Switch: '<S110>/Switch'
               */
              rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* RelationalOperator: '<S122>/Compare' incorporates:
               *  Constant: '<S122>/Constant'
               *  MATLAB Function: '<S113>/SearchL1RefWP'
               *  Switch: '<S110>/Switch'
               */
              rtb_FixPtRelationalOperator_me = (d > 0.0F);

              /* Switch: '<S113>/Switch' incorporates:
               *  Delay: '<S115>/start_wp'
               *  MATLAB Function: '<S113>/OutRegionRefWP'
               *  Switch: '<S110>/Switch'
               */
              if (!rtb_FixPtRelationalOperator_me) {
                rtb_u_mm = rtb_Switch_fz_idx_1 * rtb_Square_h[0] +
                  FMS_DW.start_wp_DSTATE[0];
                rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1 * rtb_Divide_or +
                  FMS_DW.start_wp_DSTATE[1];
              }

              /* End of Switch: '<S113>/Switch' */

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S114>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S41>/Signal Copy1'
               *  Switch: '<S110>/Switch'
               */
              D = rtb_u_mm - FMS_U.INS_Out.x_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              rtb_u_mm = D;
              rtb_P_dg[0] = D * D;

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S114>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  Math: '<S130>/Math Function'
               *  SignalConversion: '<S41>/Signal Copy1'
               *  Switch: '<S110>/Switch'
               */
              D = rtb_Switch_fz_idx_0 - FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

              /* Math: '<S130>/Math Function' incorporates:
               *  Math: '<S128>/Square'
               *  Switch: '<S110>/Switch'
               */
              d = D * D;

              /* Sum: '<S130>/Sum of Elements' incorporates:
               *  Math: '<S130>/Math Function'
               *  Switch: '<S110>/Switch'
               */
              rtb_Divide_l_idx_2 = d + rtb_P_dg[0];

              /* Math: '<S130>/Math Function1' incorporates:
               *  Sum: '<S130>/Sum of Elements'
               *  Switch: '<S110>/Switch'
               *
               * About '<S130>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* End of Math: '<S130>/Math Function1' */

              /* Switch: '<S130>/Switch' incorporates:
               *  Constant: '<S130>/Constant'
               *  Product: '<S130>/Product'
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Switch_d0[0] = rtb_u_mm;
                rtb_Switch_d0[1] = D;
                rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
              } else {
                rtb_Switch_d0[0] = 0.0F;
                rtb_Switch_d0[1] = 0.0F;
                rtb_Switch_d0[2] = 1.0F;
              }

              /* End of Switch: '<S130>/Switch' */

              /* Product: '<S130>/Divide' incorporates:
               *  Switch: '<S110>/Switch'
               */
              rtb_P_dg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_u_mm *= rtb_u_mm;

              /* Product: '<S130>/Divide' incorporates:
               *  Math: '<S128>/Square'
               *  Switch: '<S110>/Switch'
               */
              rtb_P_dg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* Sum: '<S132>/Sum of Elements' incorporates:
               *  Math: '<S132>/Math Function'
               *  SignalConversion: '<S132>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S110>/Switch'
               */
              rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
                rtb_P_cg[0];

              /* Math: '<S132>/Math Function1' incorporates:
               *  Sum: '<S132>/Sum of Elements'
               *  Switch: '<S110>/Switch'
               *
               * About '<S132>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* End of Math: '<S132>/Math Function1' */

              /* Switch: '<S132>/Switch' incorporates:
               *  Constant: '<S132>/Constant'
               *  Product: '<S132>/Product'
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Switch_d0[0] = rtb_P_cg[1];
                rtb_Switch_d0[1] = rtb_P_cg[0];
                rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
              } else {
                rtb_Switch_d0[0] = 0.0F;
                rtb_Switch_d0[1] = 0.0F;
                rtb_Switch_d0[2] = 1.0F;
              }

              /* End of Switch: '<S132>/Switch' */

              /* Product: '<S132>/Divide' incorporates:
               *  Switch: '<S110>/Switch'
               */
              rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* Sum: '<S133>/Sum of Elements' incorporates:
               *  Math: '<S133>/Math Function'
               *  SignalConversion: '<S133>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S110>/Switch'
               */
              rtb_Divide_l_idx_2 = rtb_P_dg[1] * rtb_P_dg[1] + rtb_P_dg[0] *
                rtb_P_dg[0];

              /* Math: '<S133>/Math Function1' incorporates:
               *  Sum: '<S133>/Sum of Elements'
               *  Switch: '<S110>/Switch'
               *
               * About '<S133>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* End of Math: '<S133>/Math Function1' */

              /* Switch: '<S133>/Switch' incorporates:
               *  Constant: '<S133>/Constant'
               *  Product: '<S133>/Product'
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Switch_d0[0] = rtb_P_dg[1];
                rtb_Switch_d0[1] = rtb_P_dg[0];
                rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
              } else {
                rtb_Switch_d0[0] = 0.0F;
                rtb_Switch_d0[1] = 0.0F;
                rtb_Switch_d0[2] = 1.0F;
              }

              /* End of Switch: '<S133>/Switch' */

              /* Product: '<S133>/Divide' incorporates:
               *  Switch: '<S110>/Switch'
               */
              rtb_P_dg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_P_dg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* Sum: '<S131>/Subtract' incorporates:
               *  Product: '<S131>/Multiply'
               *  Product: '<S131>/Multiply1'
               *  Switch: '<S110>/Switch'
               */
              rtb_Divide_l_idx_2 = rtb_P_dg[0] * rtb_P_cg[1] - rtb_P_dg[1] *
                rtb_P_cg[0];

              /* Signum: '<S126>/Sign1' incorporates:
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -1.0F;
              } else {
                if (rtb_Divide_l_idx_2 > 0.0F) {
                  rtb_Divide_l_idx_2 = 1.0F;
                }
              }

              /* End of Signum: '<S126>/Sign1' */

              /* Switch: '<S126>/Switch2' incorporates:
               *  Constant: '<S126>/Constant4'
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 == 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }

              /* End of Switch: '<S126>/Switch2' */

              /* DotProduct: '<S126>/Dot Product' incorporates:
               *  Switch: '<S110>/Switch'
               */
              rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_P_dg[0] + rtb_P_cg[1] *
                rtb_P_dg[1];

              /* Trigonometry: '<S126>/Acos' incorporates:
               *  DotProduct: '<S126>/Dot Product'
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Switch_fz_idx_1 > 1.0F) {
                rtb_Switch_fz_idx_1 = 1.0F;
              } else {
                if (rtb_Switch_fz_idx_1 < -1.0F) {
                  rtb_Switch_fz_idx_1 = -1.0F;
                }
              }

              /* Product: '<S126>/Multiply' incorporates:
               *  Switch: '<S110>/Switch'
               *  Trigonometry: '<S126>/Acos'
               */
              rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

              /* Saturate: '<S125>/Saturation' incorporates:
               *  Switch: '<S110>/Switch'
               */
              if (rtb_Divide_l_idx_2 > 1.57079637F) {
                rtb_Divide_l_idx_2 = 1.57079637F;
              } else {
                if (rtb_Divide_l_idx_2 < -1.57079637F) {
                  rtb_Divide_l_idx_2 = -1.57079637F;
                }
              }

              /* End of Saturate: '<S125>/Saturation' */

              /* Switch: '<S110>/Switch' incorporates:
               *  Constant: '<S110>/L1'
               *  Constant: '<S125>/Constant'
               *  Gain: '<S125>/Gain'
               *  Math: '<S125>/Square'
               *  MinMax: '<S125>/Max'
               *  MinMax: '<S125>/Min'
               *  Product: '<S125>/Divide'
               *  Product: '<S125>/Multiply1'
               *  Sqrt: '<S128>/Sqrt'
               *  Sum: '<S128>/Sum of Elements'
               *  Trigonometry: '<S125>/Sin'
               */
              FMS_B.Merge_be = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F *
                arm_sin_f32(rtb_Divide_l_idx_2) / fminf(FMS_PARAM.FW_L1, fmaxf
                (sqrtf(d + rtb_u_mm), 0.5F));
            }

            /* End of Signum: '<S112>/Sign' */

            /* Update for Delay: '<S115>/start_vel' */
            FMS_DW.icLoad_g = 0U;

            /* Update for Delay: '<S115>/start_wp' */
            FMS_DW.icLoad_e = 0U;

            /* End of Outputs for SubSystem: '<S107>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S107>/Brake Control' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* SignalConversion: '<S109>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
             *  Constant: '<S109>/Brake Speed'
             */
            FMS_B.Merge_be = 0.0F;

            /* End of Outputs for SubSystem: '<S107>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S107>/Move Control' incorporates:
               *  ActionPort: '<S111>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S107>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S138>/Integrator'
               *  DiscreteIntegrator: '<S138>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_c = 0.0F;
              FMS_DW.Integrator_DSTATE_f1 = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S107>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S107>/Move Control' incorporates:
             *  ActionPort: '<S111>/Action Port'
             */
            /* Product: '<S139>/Multiply1' incorporates:
             *  Constant: '<S139>/const1'
             *  DiscreteIntegrator: '<S138>/Integrator'
             */
            rtb_Divide_l_idx_2 = FMS_DW.Integrator_DSTATE_f1 * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S137>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S41>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              d = 0.0F;
            } else {
              d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S137>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S139>/Add' incorporates:
             *  DiscreteIntegrator: '<S138>/Integrator1'
             *  Gain: '<S111>/Gain6'
             *  Gain: '<S137>/Gain'
             *  Sum: '<S138>/Subtract'
             */
            rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_c - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.FW_ACC_Y_LIM) +
              rtb_Divide_l_idx_2;

            /* Signum: '<S139>/Sign' */
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_u_mm = -1.0F;
            } else if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_u_mm = 1.0F;
            } else {
              rtb_u_mm = rtb_Divide_l_idx_3;
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
            d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_h) *
                       FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F * rtb_u_mm +
              rtb_Divide_l_idx_2;

            /* Sum: '<S139>/Add4' */
            rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Divide_l_idx_2;

            /* Sum: '<S139>/Add3' */
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_h;

            /* Sum: '<S139>/Subtract1' */
            rtb_Divide_l_idx_3 -= FMS_ConstB.d_h;

            /* Signum: '<S139>/Sign1' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S139>/Sign1' */

            /* Signum: '<S139>/Sign2' */
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_Divide_l_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_3 > 0.0F) {
                rtb_Divide_l_idx_3 = 1.0F;
              }
            }

            /* End of Signum: '<S139>/Sign2' */

            /* Sum: '<S139>/Add5' incorporates:
             *  Gain: '<S139>/Gain2'
             *  Product: '<S139>/Multiply4'
             *  Sum: '<S139>/Subtract2'
             */
            d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

            /* SignalConversion: '<S111>/OutportBufferForay_cmd_mPs2' incorporates:
             *  DiscreteIntegrator: '<S138>/Integrator1'
             */
            FMS_B.Merge_be = FMS_DW.Integrator1_DSTATE_c;

            /* Update for DiscreteIntegrator: '<S138>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S138>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_c += 0.004F * FMS_DW.Integrator_DSTATE_f1;

            /* Sum: '<S139>/Subtract3' */
            rtb_Divide_l_idx_2 = d - FMS_ConstB.d_h;

            /* Sum: '<S139>/Add6' */
            rtb_u_mm = d + FMS_ConstB.d_h;

            /* Signum: '<S139>/Sign5' incorporates:
             *  Signum: '<S139>/Sign6'
             */
            if (d < 0.0F) {
              rtb_Divide_l_idx_3 = -1.0F;

              /* Signum: '<S139>/Sign6' */
              rtb_Switch_fz_idx_0 = -1.0F;
            } else if (d > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;

              /* Signum: '<S139>/Sign6' */
              rtb_Switch_fz_idx_0 = 1.0F;
            } else {
              rtb_Divide_l_idx_3 = d;

              /* Signum: '<S139>/Sign6' */
              rtb_Switch_fz_idx_0 = d;
            }

            /* End of Signum: '<S139>/Sign5' */

            /* Signum: '<S139>/Sign3' */
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = -1.0F;
            } else {
              if (rtb_u_mm > 0.0F) {
                rtb_u_mm = 1.0F;
              }
            }

            /* End of Signum: '<S139>/Sign3' */

            /* Signum: '<S139>/Sign4' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S139>/Sign4' */

            /* Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
             *  Constant: '<S139>/const'
             *  Gain: '<S139>/Gain3'
             *  Product: '<S139>/Divide'
             *  Product: '<S139>/Multiply5'
             *  Product: '<S139>/Multiply6'
             *  Sum: '<S139>/Subtract4'
             *  Sum: '<S139>/Subtract5'
             *  Sum: '<S139>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_f1 += ((d / FMS_ConstB.d_h -
              rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_b * ((rtb_u_mm -
              rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S107>/Move Control' */
            break;
          }

          /* SwitchCase: '<S93>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S93>/Hold Control' incorporates:
               *  ActionPort: '<S96>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S93>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S93>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S93>/Hold Control' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_f,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S93>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S93>/Brake Control' incorporates:
             *  ActionPort: '<S95>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S93>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S93>/Move Control' incorporates:
               *  ActionPort: '<S97>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S93>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S93>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S93>/Move Control' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_f,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S93>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S93>/Switch Case' */

          /* BusAssignment: '<S65>/Bus Assignment' incorporates:
           *  Constant: '<S65>/Constant'
           *  DiscreteIntegrator: '<S105>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S89>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < -0.2F) {
            d = -0.2F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S89>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S65>/Bus Assignment' incorporates:
           *  Gain: '<S89>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * d;

          /* Saturate: '<S107>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S65>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S65>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S65>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S107>/Saturation1' */

          /* Saturate: '<S93>/Saturation1' */
          if (FMS_B.Merge_f > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S65>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_f < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S65>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S65>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_f;
          }

          /* End of Saturate: '<S93>/Saturation1' */

          /* Product: '<S106>/Multiply1' incorporates:
           *  Constant: '<S106>/const1'
           *  DiscreteIntegrator: '<S105>/Integrator'
           */
          rtb_Divide_l_idx_2 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S104>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S104>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S106>/Add' incorporates:
           *  DiscreteIntegrator: '<S105>/Integrator1'
           *  Gain: '<S104>/Gain'
           *  Gain: '<S91>/Gain1'
           *  Sum: '<S105>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_l_idx_2;

          /* Signum: '<S106>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_u_mm = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_u_mm = 1.0F;
          } else {
            rtb_u_mm = rtb_Divide_l_idx_3;
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
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_l) *
                     FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_u_mm +
            rtb_Divide_l_idx_2;

          /* Sum: '<S106>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Divide_l_idx_2;

          /* Sum: '<S106>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_l;

          /* Sum: '<S106>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_l;

          /* Signum: '<S106>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S106>/Sign1' */

          /* Signum: '<S106>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S106>/Sign2' */

          /* Sum: '<S106>/Add5' incorporates:
           *  Gain: '<S106>/Gain2'
           *  Product: '<S106>/Multiply4'
           *  Sum: '<S106>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Update for DiscreteIntegrator: '<S105>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S105>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Sum: '<S106>/Subtract3' */
          rtb_Divide_l_idx_2 = d - FMS_ConstB.d_l;

          /* Sum: '<S106>/Add6' */
          rtb_u_mm = d + FMS_ConstB.d_l;

          /* Signum: '<S106>/Sign5' incorporates:
           *  Signum: '<S106>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S106>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S106>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = d;

            /* Signum: '<S106>/Sign6' */
            rtb_Switch_fz_idx_0 = d;
          }

          /* End of Signum: '<S106>/Sign5' */

          /* Signum: '<S106>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S106>/Sign3' */

          /* Signum: '<S106>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S106>/Sign4' */

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
          FMS_DW.Integrator_DSTATE_ha += ((d / FMS_ConstB.d_l -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_a * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 15.707963F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S59>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S59>/Unknown' incorporates:
           *  ActionPort: '<S67>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S59>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S47>/Manual' incorporates:
         *  ActionPort: '<S61>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Saturate: '<S185>/Saturation' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S41>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
          d = 1.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
          d = 0.0F;
        } else {
          d = FMS_U.Pilot_Cmd.stick_throttle;
        }

        /* End of Saturate: '<S185>/Saturation' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* DataTypeConversion: '<S184>/Data Type Conversion' incorporates:
         *  Constant: '<S185>/Constant5'
         *  Gain: '<S185>/Gain4'
         *  Sum: '<S185>/Add'
         */
        rtb_DataTypeConversion_o = (uint16_T)fmodf(floorf(1000.0F * d + 1000.0F),
          65536.0F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DataTypeConversion: '<S184>/Data Type Conversion1' incorporates:
         *  Bias: '<S184>/Bias1'
         *  Gain: '<S184>/Gain'
         *  Gain: '<S184>/Gain1'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S41>/Signal Copy2'
         */
        d = fmodf(floorf(FMS_PARAM.MANUAL_ROLL_REV * FMS_U.Pilot_Cmd.stick_roll *
                         500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_DataTypeConversion1_b = (uint16_T)(d < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-d : (int32_T)(uint16_T)d);

        /* BusAssignment: '<S61>/Bus Assignment' incorporates:
         *  Constant: '<S61>/Constant'
         *  Constant: '<S61>/Constant2'
         *  SignalConversion: '<S61>/TmpHiddenBufferAtBus AssignmentInport1'
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

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DataTypeConversion: '<S184>/Data Type Conversion2' incorporates:
         *  Bias: '<S184>/Bias2'
         *  Gain: '<S184>/Gain2'
         *  Gain: '<S184>/Gain4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S41>/Signal Copy2'
         */
        d = fmodf(floorf(FMS_PARAM.MANUAL_PITCH_REV *
                         FMS_U.Pilot_Cmd.stick_pitch * -500.0F + 1500.0F),
                  65536.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S61>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S184>/Data Type Conversion2'
         */
        FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(d < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-d : (int32_T)(uint16_T)d);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DataTypeConversion: '<S184>/Data Type Conversion3' incorporates:
         *  Bias: '<S184>/Bias3'
         *  Gain: '<S184>/Gain3'
         *  Gain: '<S184>/Gain5'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S41>/Signal Copy2'
         */
        d = fmodf(floorf(FMS_PARAM.MANUAL_YAW_REV * FMS_U.Pilot_Cmd.stick_yaw *
                         500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S61>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S184>/Data Type Conversion3'
         */
        FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(d < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-d : (int32_T)(uint16_T)d);
        for (rtb_n = 0; rtb_n < 10; rtb_n++) {
          FMS_Y.FMS_Out.actuator_cmd[rtb_n + 6] = 0U;
        }

        /* End of Outputs for SubSystem: '<S47>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S47>/Unknown' incorporates:
         *  ActionPort: '<S63>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

        /* End of Outputs for SubSystem: '<S47>/Unknown' */
        break;
      }

      /* End of Outputs for SubSystem: '<S42>/FW_Mode' */
      break;

     case 1:
      if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S42>/BackwardTrans_Mode' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        /* InitializeConditions for SwitchCase: '<S42>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
         *  DiscreteIntegrator: '<S58>/Discrete-Time Integrator1'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant;
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
          }
        }

        FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;
        FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
        FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

        /* End of InitializeConditions for SwitchCase: '<S42>/Switch Case' */
        /* End of InitializeConditions for SubSystem: '<S42>/BackwardTrans_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S42>/BackwardTrans_Mode' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Trigonometry: '<S54>/Trigonometric Function1' incorporates:
       *  Gain: '<S53>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S41>/Signal Copy1'
       */
      rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S54>/Trigonometric Function' incorporates:
       *  Gain: '<S53>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S41>/Signal Copy1'
       */
      rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S54>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S54>/Constant3'
       */
      rtb_Transpose[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S54>/Gain' incorporates:
       *  Gain: '<S53>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S41>/Signal Copy1'
       *  Trigonometry: '<S54>/Trigonometric Function2'
       */
      rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S54>/Trigonometric Function3' incorporates:
       *  Gain: '<S53>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S41>/Signal Copy1'
       */
      rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S54>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S54>/Constant4'
       */
      rtb_Transpose[5] = 0.0F;

      /* SignalConversion: '<S54>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_dz[0];
      rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_dz[1];
      rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_dz[2];

      /* Product: '<S52>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S41>/Signal Copy1'
       */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
          FMS_U.INS_Out.ve + rtb_Transpose[rtb_n] * FMS_U.INS_Out.vn;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      }

      /* End of Product: '<S52>/Multiply' */

      /* DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
      if (FMS_DW.DiscreteTimeIntegrator_PrevRese != 0) {
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant;
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

      /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S50>/Constant'
       *  Sum: '<S50>/Sum'
       */
      if (FMS_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_n = 0.0F -
          rtb_MatrixConcatenate1_i_0[1];
      }

      if (FMS_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_n = 0.0F -
          rtb_MatrixConcatenate1_i_0[1];
      }

      /* BusAssignment: '<S46>/Bus Assignment' incorporates:
       *  Constant: '<S46>/Constant'
       *  Constant: '<S46>/Constant3'
       *  Constant: '<S46>/Constant4'
       *  Constant: '<S50>/Constant'
       *  Constant: '<S57>/kp'
       *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
       *  Product: '<S57>/Multiply'
       *  Sum: '<S50>/Sum'
       *  Sum: '<S51>/Add'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_g;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_i;
      FMS_Y.FMS_Out.u_cmd = 0.0F;
      FMS_Y.FMS_Out.w_cmd = 0.0F;
      FMS_Y.FMS_Out.ay_cmd = (0.0F - rtb_MatrixConcatenate1_i_0[1]) * 1.2F +
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k;
      FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

      /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S50>/Constant'
       *  Constant: '<S56>/ki'
       *  Product: '<S56>/Multiply'
       *  Sum: '<S50>/Sum'
       */
      FMS_DW.DiscreteTimeIntegrator_DSTATE_k += (0.0F -
        rtb_MatrixConcatenate1_i_0[1]) * 0.5F * 0.004F;
      if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
      } else {
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
        }
      }

      FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

      /* End of Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S50>/Constant'
       *  Gain: '<S58>/Gain'
       *  Sum: '<S50>/Sum'
       *  Sum: '<S58>/Sum5'
       */
      FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
      FMS_DW.DiscreteTimeIntegrator1_DSTAT_n += ((0.0F -
        rtb_MatrixConcatenate1_i_0[1]) - FMS_DW.DiscreteTimeIntegrator1_DSTAT_n)
        * 62.831852F * 0.004F;
      FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* End of Outputs for SubSystem: '<S42>/BackwardTrans_Mode' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S42>/MC_Mode' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* SwitchCase: '<S48>/Switch Case' */
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
          /* Disable for SwitchCase: '<S256>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S644>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S583>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S561>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S571>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S254>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S366>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S414>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S404>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* End of Disable for SubSystem: '<S366>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S253>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S353>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S268>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S286>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S302>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S327>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S314>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S48>/SubMode' incorporates:
         *  ActionPort: '<S256>/Action Port'
         */
        /* SwitchCase: '<S256>/Switch Case' incorporates:
         *  Product: '<S668>/Divide'
         *  Sum: '<S628>/Subtract'
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
            /* Disable for SwitchCase: '<S644>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S583>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S561>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S571>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S256>/Takeoff' incorporates:
             *  ActionPort: '<S556>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S256>/Switch Case' incorporates:
             *  Delay: '<S684>/cur_waypoint'
             *  DiscreteIntegrator: '<S680>/Integrator'
             *  DiscreteIntegrator: '<S680>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S256>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S256>/Takeoff' incorporates:
           *  ActionPort: '<S556>/Action Port'
           */
          /* Delay: '<S684>/cur_waypoint' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_hz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
            FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Product: '<S684>/Divide' incorporates:
           *  Delay: '<S684>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S684>/Sum1'
           *  Sum: '<S684>/Sum2'
           */
          rtb_Divide_l_idx_3 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S684>/Saturation' */
          if (rtb_Divide_l_idx_3 > 1.0F) {
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_Divide_l_idx_3 = 0.0F;
            }
          }

          /* End of Saturate: '<S684>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S685>/Trigonometric Function1' incorporates:
           *  Gain: '<S683>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S685>/Trigonometric Function' incorporates:
           *  Gain: '<S683>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S685>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S685>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S685>/Gain' incorporates:
           *  Gain: '<S683>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Trigonometry: '<S685>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S685>/Trigonometric Function3' incorporates:
           *  Gain: '<S683>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S685>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S685>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* SignalConversion: '<S685>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Saturate: '<S677>/Saturation1' */
          rtb_u_mm = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Switch_fz_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S677>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S684>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S684>/Multiply'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S677>/Sum'
           *  Sum: '<S684>/Sum3'
           *  Sum: '<S684>/Sum4'
           */
          rtb_Divide_l_idx_2 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_l_idx_3 +
                                FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Switch_fz_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_l_idx_3 +
            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S677>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
              rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2;
          }

          /* Saturate: '<S677>/Saturation1' incorporates:
           *  Gain: '<S677>/Gain2'
           *  Product: '<S677>/Multiply'
           */
          d = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[0];
          rtb_Divide_l_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[1];

          /* BusAssignment: '<S556>/Bus Assignment1' incorporates:
           *  Constant: '<S556>/Constant'
           *  Constant: '<S556>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S677>/Saturation1' */
          if (d > rtb_u_mm) {
            /* BusAssignment: '<S556>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_u_mm;
          } else if (d < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S556>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S556>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = d;
          }

          if (rtb_Divide_l_idx_2 > rtb_u_mm) {
            /* BusAssignment: '<S556>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_u_mm;
          } else if (rtb_Divide_l_idx_2 < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S556>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S556>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_2;
          }

          /* BusAssignment: '<S556>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S680>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S681>/Multiply1' incorporates:
           *  Constant: '<S681>/const1'
           *  DiscreteIntegrator: '<S680>/Integrator'
           */
          rtb_Divide_l_idx_3 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S676>/Switch' incorporates:
           *  Abs: '<S676>/Abs'
           *  Abs: '<S676>/Abs1'
           *  Constant: '<S676>/Takeoff_Speed'
           *  Constant: '<S678>/Constant'
           *  Constant: '<S679>/Constant'
           *  Gain: '<S676>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S676>/Logical Operator'
           *  RelationalOperator: '<S678>/Compare'
           *  RelationalOperator: '<S679>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S676>/Sum'
           *  Sum: '<S676>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            d = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            d = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S676>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S681>/Add' incorporates:
           *  DiscreteIntegrator: '<S680>/Integrator1'
           *  Sum: '<S680>/Subtract'
           */
          rtb_u_mm = (FMS_DW.Integrator1_DSTATE_f - d) + rtb_Divide_l_idx_3;

          /* Signum: '<S681>/Sign' */
          if (rtb_u_mm < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_u_mm > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_u_mm;
          }

          /* End of Signum: '<S681>/Sign' */

          /* Sum: '<S681>/Add2' incorporates:
           *  Abs: '<S681>/Abs'
           *  Gain: '<S681>/Gain'
           *  Gain: '<S681>/Gain1'
           *  Product: '<S681>/Multiply2'
           *  Product: '<S681>/Multiply3'
           *  Sqrt: '<S681>/Sqrt'
           *  Sum: '<S681>/Add1'
           *  Sum: '<S681>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_mm) + FMS_ConstB.d_b) * FMS_ConstB.d_b)
               - FMS_ConstB.d_b) * 0.5F * rtb_Divide_l_idx_2 +
            rtb_Divide_l_idx_3;

          /* Sum: '<S681>/Add4' */
          rtb_Divide_l_idx_3 += rtb_u_mm - d;

          /* Sum: '<S681>/Add3' */
          rtb_Divide_l_idx_2 = rtb_u_mm + FMS_ConstB.d_b;

          /* Sum: '<S681>/Subtract1' */
          rtb_u_mm -= FMS_ConstB.d_b;

          /* Signum: '<S681>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S681>/Sign1' */

          /* Signum: '<S681>/Sign2' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S681>/Sign2' */

          /* Sum: '<S681>/Add5' incorporates:
           *  Gain: '<S681>/Gain2'
           *  Product: '<S681>/Multiply4'
           *  Sum: '<S681>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F * rtb_Divide_l_idx_3;

          /* Update for Delay: '<S684>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S680>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S680>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S681>/Subtract3' */
          rtb_Divide_l_idx_2 = d - FMS_ConstB.d_b;

          /* Sum: '<S681>/Add6' */
          rtb_u_mm = d + FMS_ConstB.d_b;

          /* Signum: '<S681>/Sign5' incorporates:
           *  Signum: '<S681>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S681>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S681>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = d;

            /* Signum: '<S681>/Sign6' */
            rtb_Switch_fz_idx_0 = d;
          }

          /* End of Signum: '<S681>/Sign5' */

          /* Signum: '<S681>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S681>/Sign3' */

          /* Signum: '<S681>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S681>/Sign4' */

          /* Update for DiscreteIntegrator: '<S680>/Integrator' incorporates:
           *  Constant: '<S681>/const'
           *  Gain: '<S681>/Gain3'
           *  Product: '<S681>/Divide'
           *  Product: '<S681>/Multiply5'
           *  Product: '<S681>/Multiply6'
           *  Sum: '<S681>/Subtract4'
           *  Sum: '<S681>/Subtract5'
           *  Sum: '<S681>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((d / FMS_ConstB.d_b -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_i * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S256>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S256>/Land' incorporates:
             *  ActionPort: '<S554>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S256>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S599>/Integrator'
             *  DiscreteIntegrator: '<S599>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S256>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S256>/Land' incorporates:
           *  ActionPort: '<S554>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S604>/Trigonometric Function1' incorporates:
           *  Gain: '<S603>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S604>/Trigonometric Function' incorporates:
           *  Gain: '<S603>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S604>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S604>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S604>/Gain' incorporates:
           *  Gain: '<S603>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Trigonometry: '<S604>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S604>/Trigonometric Function3' incorporates:
           *  Gain: '<S603>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S604>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S604>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* SignalConversion: '<S604>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S597>/Saturation1' */
          rtb_Divide_l_idx_3 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Switch_fz_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S601>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S601>/Sum'
           */
          rtb_Divide_l_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Switch_fz_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S601>/Multiply' incorporates:
           *  SignalConversion: '<S601>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
              rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2;
          }

          /* End of Product: '<S601>/Multiply' */

          /* Saturate: '<S597>/Saturation1' incorporates:
           *  Gain: '<S601>/Gain2'
           */
          d = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[0];
          rtb_Divide_l_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[1];

          /* BusAssignment: '<S554>/Bus Assignment1' incorporates:
           *  Constant: '<S554>/Constant'
           *  Constant: '<S554>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S597>/Saturation1' */
          if (d > rtb_Divide_l_idx_3) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_3;
          } else if (d < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = d;
          }

          if (rtb_Divide_l_idx_2 > rtb_Divide_l_idx_3) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_3;
          } else if (rtb_Divide_l_idx_2 < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_2;
          }

          /* BusAssignment: '<S554>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S599>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S600>/Multiply1' incorporates:
           *  Constant: '<S600>/const1'
           *  DiscreteIntegrator: '<S599>/Integrator'
           */
          rtb_Divide_l_idx_2 = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S596>/Switch' incorporates:
           *  Constant: '<S596>/Land_Speed'
           *  Constant: '<S598>/Constant'
           *  Gain: '<S596>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S596>/Logical Operator'
           *  RelationalOperator: '<S598>/Compare'
           *  S-Function (sfix_bitop): '<S596>/cmd_p valid'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            d = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            d = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S596>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S600>/Add' incorporates:
           *  DiscreteIntegrator: '<S599>/Integrator1'
           *  Sum: '<S599>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_g - d) +
            rtb_Divide_l_idx_2;

          /* Signum: '<S600>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_u_mm = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_u_mm = 1.0F;
          } else {
            rtb_u_mm = rtb_Divide_l_idx_3;
          }

          /* End of Signum: '<S600>/Sign' */

          /* Sum: '<S600>/Add2' incorporates:
           *  Abs: '<S600>/Abs'
           *  Gain: '<S600>/Gain'
           *  Gain: '<S600>/Gain1'
           *  Product: '<S600>/Multiply2'
           *  Product: '<S600>/Multiply3'
           *  Sqrt: '<S600>/Sqrt'
           *  Sum: '<S600>/Add1'
           *  Sum: '<S600>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_om) *
                     FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F * rtb_u_mm +
            rtb_Divide_l_idx_2;

          /* Sum: '<S600>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Divide_l_idx_2;

          /* Sum: '<S600>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_om;

          /* Sum: '<S600>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_om;

          /* Signum: '<S600>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S600>/Sign1' */

          /* Signum: '<S600>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S600>/Sign2' */

          /* Sum: '<S600>/Add5' incorporates:
           *  Gain: '<S600>/Gain2'
           *  Product: '<S600>/Multiply4'
           *  Sum: '<S600>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Update for DiscreteIntegrator: '<S599>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S599>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S600>/Subtract3' */
          rtb_Divide_l_idx_2 = d - FMS_ConstB.d_om;

          /* Sum: '<S600>/Add6' */
          rtb_u_mm = d + FMS_ConstB.d_om;

          /* Signum: '<S600>/Sign5' incorporates:
           *  Signum: '<S600>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S600>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S600>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = d;

            /* Signum: '<S600>/Sign6' */
            rtb_Switch_fz_idx_0 = d;
          }

          /* End of Signum: '<S600>/Sign5' */

          /* Signum: '<S600>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S600>/Sign3' */

          /* Signum: '<S600>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S600>/Sign4' */

          /* Update for DiscreteIntegrator: '<S599>/Integrator' incorporates:
           *  Constant: '<S600>/const'
           *  Gain: '<S600>/Gain3'
           *  Product: '<S600>/Divide'
           *  Product: '<S600>/Multiply5'
           *  Product: '<S600>/Multiply6'
           *  Sum: '<S600>/Subtract4'
           *  Sum: '<S600>/Subtract5'
           *  Sum: '<S600>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((d / FMS_ConstB.d_om -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_p * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S256>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S256>/Return' incorporates:
             *  ActionPort: '<S555>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S256>/Switch Case' incorporates:
             *  Delay: '<S607>/Delay'
             *  Delay: '<S608>/Delay'
             *  Delay: '<S629>/Delay'
             *  DiscreteIntegrator: '<S611>/Integrator'
             *  DiscreteIntegrator: '<S611>/Integrator1'
             *  DiscreteIntegrator: '<S625>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S630>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S671>/Discrete-Time Integrator'
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

            /* End of InitializeConditions for SubSystem: '<S256>/Return' */

            /* SystemReset for IfAction SubSystem: '<S256>/Return' incorporates:
             *  ActionPort: '<S555>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S256>/Switch Case' incorporates:
             *  Chart: '<S635>/Motion Status'
             *  Chart: '<S645>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S256>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S256>/Return' incorporates:
           *  ActionPort: '<S555>/Action Port'
           */
          /* Delay: '<S629>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S624>/Compare' incorporates:
           *  Constant: '<S675>/Constant'
           *  DiscreteIntegrator: '<S630>/Discrete-Time Integrator'
           *  RelationalOperator: '<S675>/Compare'
           */
          rtb_Compare_ii = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S625>/Acceleration_Speed' */
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

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S645>/Motion State' incorporates:
           *  Constant: '<S645>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S645>/Square'
           *  Math: '<S645>/Square1'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sqrt: '<S645>/Sqrt'
           *  Sum: '<S645>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S644>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S644>/Hold Control' incorporates:
               *  ActionPort: '<S647>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S644>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S644>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S644>/Hold Control' incorporates:
             *  ActionPort: '<S647>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S644>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S644>/Brake Control' incorporates:
             *  ActionPort: '<S646>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S644>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S644>/Move Control' incorporates:
               *  ActionPort: '<S648>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S644>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S644>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S644>/Move Control' incorporates:
             *  ActionPort: '<S648>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S644>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S644>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S635>/Motion Status' incorporates:
           *  Abs: '<S635>/Abs'
           *  Constant: '<S635>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S634>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S634>/Hold Control' incorporates:
               *  ActionPort: '<S637>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S634>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S634>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S634>/Hold Control' incorporates:
             *  ActionPort: '<S637>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S634>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S634>/Brake Control' incorporates:
             *  ActionPort: '<S636>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S634>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S634>/Move Control' incorporates:
               *  ActionPort: '<S638>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S634>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S634>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S634>/Move Control' incorporates:
             *  ActionPort: '<S638>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S634>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S634>/Switch Case' */

          /* Switch: '<S606>/Switch' incorporates:
           *  Product: '<S629>/Multiply'
           *  Sum: '<S629>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S644>/Saturation1' */
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

            /* End of Saturate: '<S644>/Saturation1' */

            /* Saturate: '<S634>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_ov[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_ov[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_ov[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S634>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S629>/Sum' incorporates:
             *  Delay: '<S629>/Delay'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S672>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_ov[0] = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S625>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract3_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_u_mm = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S629>/Sum' incorporates:
             *  Delay: '<S629>/Delay'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S625>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_or = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S631>/Sqrt' incorporates:
             *  Math: '<S631>/Square'
             *  Sum: '<S625>/Sum'
             *  Sum: '<S631>/Sum of Elements'
             */
            d = sqrtf(rtb_Subtract3_d * rtb_Subtract3_d + rtb_Divide_or *
                      rtb_Divide_or);

            /* SignalConversion: '<S674>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S674>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S674>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S673>/Gain' incorporates:
             *  DiscreteIntegrator: '<S671>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S671>/Add'
             */
            rtb_Switch_fz_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S674>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S674>/Trigonometric Function1'
             */
            rtb_Switch_fz_idx_1 = arm_cos_f32(rtb_Switch_fz_idx_0);
            rtb_Transpose[4] = rtb_Switch_fz_idx_1;

            /* Trigonometry: '<S674>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S674>/Trigonometric Function'
             */
            rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_Switch_fz_idx_0);

            /* Gain: '<S674>/Gain' incorporates:
             *  Trigonometry: '<S674>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S674>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S674>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S674>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Switch_fz_idx_0;

            /* Trigonometry: '<S674>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_Switch_fz_idx_1;

            /* Switch: '<S625>/Switch' incorporates:
             *  Constant: '<S625>/vel'
             */
            if (d > FMS_PARAM.L1) {
              rtb_Switch_fz_idx_0 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S625>/Gain' */
              rtb_Switch_fz_idx_0 = 0.5F * d;

              /* Saturate: '<S625>/Saturation' */
              if (rtb_Switch_fz_idx_0 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Switch_fz_idx_0 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Switch_fz_idx_0 < 0.5F) {
                  rtb_Switch_fz_idx_0 = 0.5F;
                }
              }

              /* End of Saturate: '<S625>/Saturation' */
            }

            /* End of Switch: '<S625>/Switch' */

            /* Switch: '<S625>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S625>/Acceleration_Speed'
             *  Sum: '<S625>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Switch_fz_idx_0 < 0.0F)
            {
              rtb_Switch_fz_idx_0 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S625>/Switch1' */

            /* Sum: '<S672>/Sum of Elements' incorporates:
             *  Math: '<S672>/Math Function'
             */
            d = rtb_Switch_ov[0] * rtb_Switch_ov[0] + rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_2;

            /* Math: '<S672>/Math Function1' incorporates:
             *  Sum: '<S672>/Sum of Elements'
             *
             * About '<S672>/Math Function1':
             *  Operator: sqrt
             */
            if (d < 0.0F) {
              d = -sqrtf(fabsf(d));
            } else {
              d = sqrtf(d);
            }

            /* End of Math: '<S672>/Math Function1' */

            /* Switch: '<S672>/Switch' incorporates:
             *  Constant: '<S672>/Constant'
             *  Product: '<S672>/Product'
             */
            if (d <= 0.0F) {
              rtb_u_mm = 0.0F;
              rtb_Switch_fz_idx_2 = 0.0F;
              d = 1.0F;
            }

            /* End of Switch: '<S672>/Switch' */

            /* Product: '<S670>/Multiply2' incorporates:
             *  Product: '<S672>/Divide'
             */
            rtb_u_mm = rtb_u_mm / d * rtb_Switch_fz_idx_0;
            rtb_Switch_fz_idx_2 = rtb_Switch_fz_idx_2 / d * rtb_Switch_fz_idx_0;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_2 + rtb_Transpose[rtb_n] * rtb_u_mm;
            }
          }

          /* End of Switch: '<S606>/Switch' */

          /* Delay: '<S608>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S611>/Integrator1' incorporates:
           *  Delay: '<S608>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S615>/Rem' incorporates:
           *  Constant: '<S615>/Constant1'
           *  DiscreteIntegrator: '<S611>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sum: '<S610>/Sum'
           */
          rtb_u_mm = rt_remf(FMS_DW.Integrator1_DSTATE_b - FMS_U.INS_Out.psi,
                             6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S615>/Switch' incorporates:
           *  Abs: '<S615>/Abs'
           *  Constant: '<S615>/Constant'
           *  Constant: '<S616>/Constant'
           *  Product: '<S615>/Multiply'
           *  RelationalOperator: '<S616>/Compare'
           *  Sum: '<S615>/Add'
           */
          if (fabsf(rtb_u_mm) > 3.14159274F) {
            /* Signum: '<S615>/Sign' */
            if (rtb_u_mm < 0.0F) {
              d = -1.0F;
            } else if (rtb_u_mm > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_u_mm;
            }

            /* End of Signum: '<S615>/Sign' */
            rtb_u_mm -= 6.28318548F * d;
          }

          /* End of Switch: '<S615>/Switch' */

          /* Gain: '<S610>/Gain2' */
          rtb_u_mm *= FMS_PARAM.YAW_P;

          /* Saturate: '<S610>/Saturation' */
          if (rtb_u_mm > FMS_PARAM.YAW_RATE_LIM) {
            rtb_u_mm = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_u_mm < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_u_mm = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S610>/Saturation' */

          /* BusAssignment: '<S555>/Bus Assignment1' incorporates:
           *  Constant: '<S555>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_ov[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_mm;

          /* Math: '<S665>/Math Function1'
           *
           * About '<S665>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_u_mm = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S665>/Math Function1' */

          /* Switch: '<S665>/Switch' incorporates:
           *  Constant: '<S665>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S665>/Product'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_u_mm > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_ov[0] = FMS_U.INS_Out.vn;
            rtb_Switch_ov[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_ov[2] = rtb_u_mm;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S665>/Switch' */

          /* Delay: '<S607>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_f != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_nc[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S555>/Sum' incorporates:
           *  Delay: '<S607>/Delay'
           *  MATLAB Function: '<S627>/OutRegionRegWP'
           *  MATLAB Function: '<S627>/SearchL1RefWP'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_nc[0];
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_nc[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S622>/Sum of Elements' incorporates:
           *  Math: '<S622>/Math Function'
           *  Sum: '<S555>/Sum'
           */
          d = rtb_Divide_or * rtb_Divide_or + rtb_Subtract3_d * rtb_Subtract3_d;

          /* Math: '<S622>/Math Function1' incorporates:
           *  Sum: '<S622>/Sum of Elements'
           *
           * About '<S622>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(d));
          } else {
            rtb_u_mm = sqrtf(d);
          }

          /* End of Math: '<S622>/Math Function1' */

          /* Switch: '<S622>/Switch' incorporates:
           *  Constant: '<S622>/Constant'
           *  Product: '<S622>/Product'
           *  Sum: '<S555>/Sum'
           */
          if (rtb_u_mm > 0.0F) {
            rtb_Switch_fz_idx_0 = rtb_Divide_or;
            rtb_Switch_fz_idx_1 = rtb_Subtract3_d;
            rtb_Switch_fz_idx_2 = rtb_u_mm;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S622>/Switch' */

          /* Product: '<S665>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S668>/Sum of Elements' incorporates:
           *  Math: '<S668>/Math Function'
           *  SignalConversion: '<S668>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S668>/Math Function1' incorporates:
           *  Sum: '<S668>/Sum of Elements'
           *
           * About '<S668>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(d));
          } else {
            rtb_u_mm = sqrtf(d);
          }

          /* End of Math: '<S668>/Math Function1' */

          /* Switch: '<S668>/Switch' incorporates:
           *  Constant: '<S668>/Constant'
           *  Product: '<S668>/Product'
           */
          if (rtb_u_mm > 0.0F) {
            rtb_Switch_ov[0] = rtb_Divide_n4[1];
            rtb_Switch_ov[1] = rtb_Divide_n4[0];
            rtb_Switch_ov[2] = rtb_u_mm;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S668>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S627>/NearbyRefWP' incorporates:
           *  Constant: '<S555>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_n4, &d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* MATLAB Function: '<S627>/SearchL1RefWP' incorporates:
           *  Constant: '<S555>/L1'
           *  Delay: '<S607>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_u_mm = rtb_Subtract3_d * rtb_Subtract3_d + rtb_Divide_or *
            rtb_Divide_or;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Sign5_mn = (rtb_Subtract3_d * (FMS_DW.Delay_DSTATE_nc[0] -
            FMS_U.INS_Out.x_R) + rtb_Divide_or * (FMS_DW.Delay_DSTATE_nc[1] -
            FMS_U.INS_Out.y_R)) * 2.0F;
          D = rtb_Sign5_mn * rtb_Sign5_mn - (((((FMS_U.INS_Out.x_R *
            FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
            FMS_DW.Delay_DSTATE_nc[0] * FMS_DW.Delay_DSTATE_nc[0]) +
            FMS_DW.Delay_DSTATE_nc[1] * FMS_DW.Delay_DSTATE_nc[1]) -
            (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_nc[0] + FMS_U.INS_Out.y_R *
             FMS_DW.Delay_DSTATE_nc[1]) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) *
            (4.0F * rtb_u_mm);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Divide_l_idx_2 = -1.0F;
          rtb_Square_h[0] = 0.0F;
          rtb_Square_h[1] = 0.0F;
          guard1 = false;
          if (D > 0.0F) {
            rtb_MathFunction_n_idx_2 = sqrtf(D);
            D = (-rtb_Sign5_mn + rtb_MathFunction_n_idx_2) / (2.0F * rtb_u_mm);
            rtb_u_mm = (-rtb_Sign5_mn - rtb_MathFunction_n_idx_2) / (2.0F *
              rtb_u_mm);
            if ((D >= 0.0F) && (D <= 1.0F) && (rtb_u_mm >= 0.0F) && (rtb_u_mm <=
                 1.0F)) {
              rtb_Divide_l_idx_2 = fmaxf(D, rtb_u_mm);
              guard1 = true;
            } else if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Divide_l_idx_2 = D;
              guard1 = true;
            } else {
              if ((rtb_u_mm >= 0.0F) && (rtb_u_mm <= 1.0F)) {
                rtb_Divide_l_idx_2 = rtb_u_mm;
                guard1 = true;
              }
            }
          } else {
            if (D == 0.0F) {
              D = -rtb_Sign5_mn / (2.0F * rtb_u_mm);
              if ((D >= 0.0F) && (D <= 1.0F)) {
                rtb_Divide_l_idx_2 = D;
                guard1 = true;
              }
            }
          }

          if (guard1) {
            rtb_Square_h[0] = rtb_Subtract3_d * rtb_Divide_l_idx_2 +
              FMS_DW.Delay_DSTATE_nc[0];
            rtb_Square_h[1] = rtb_Divide_or * rtb_Divide_l_idx_2 +
              FMS_DW.Delay_DSTATE_nc[1];
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S627>/OutRegionRegWP' incorporates:
           *  Delay: '<S607>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_mm = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_nc[1]) *
                      rtb_Divide_or + (FMS_U.INS_Out.x_R -
            FMS_DW.Delay_DSTATE_nc[0]) * rtb_Subtract3_d) / (rtb_Subtract3_d *
            rtb_Subtract3_d + rtb_Divide_or * rtb_Divide_or);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_u_mm <= 0.0F);
          rtb_LogicalOperator_oy = (rtb_u_mm >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Subtract3_d = FMS_DW.Delay_DSTATE_nc[0];
          } else if (rtb_LogicalOperator_oy) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            rtb_Subtract3_d = rtb_u_mm * rtb_Subtract3_d +
              FMS_DW.Delay_DSTATE_nc[0];
          }

          /* Switch: '<S627>/Switch1' incorporates:
           *  Constant: '<S658>/Constant'
           *  RelationalOperator: '<S658>/Compare'
           */
          if (d <= 0.0F) {
            /* Switch: '<S627>/Switch' incorporates:
             *  Constant: '<S657>/Constant'
             *  MATLAB Function: '<S627>/SearchL1RefWP'
             *  RelationalOperator: '<S657>/Compare'
             */
            if (rtb_Divide_l_idx_2 >= 0.0F) {
              rtb_Divide_n4[0] = rtb_Square_h[0];
              rtb_Divide_n4[1] = rtb_Square_h[1];
            } else {
              rtb_Divide_n4[0] = rtb_Subtract3_d;

              /* MATLAB Function: '<S627>/OutRegionRegWP' incorporates:
               *  Delay: '<S607>/Delay'
               *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Divide_n4[1] = FMS_DW.Delay_DSTATE_nc[1];
              } else if (rtb_LogicalOperator_oy) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_Divide_n4[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              } else {
                rtb_Divide_n4[1] = rtb_u_mm * rtb_Divide_or +
                  FMS_DW.Delay_DSTATE_nc[1];
              }
            }

            /* End of Switch: '<S627>/Switch' */
          }

          /* End of Switch: '<S627>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S628>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Subtract3_d = rtb_Divide_n4[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S666>/Math Function' */
          rtb_P_cg[0] = rtb_Subtract3_d * rtb_Subtract3_d;
          rtb_Divide_n4[0] = rtb_Subtract3_d;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S628>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Subtract3_d = rtb_Divide_n4[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S666>/Math Function' incorporates:
           *  Math: '<S664>/Square'
           */
          d = rtb_Subtract3_d * rtb_Subtract3_d;

          /* Sum: '<S666>/Sum of Elements' incorporates:
           *  Math: '<S666>/Math Function'
           */
          rtb_Divide_l_idx_2 = d + rtb_P_cg[0];

          /* Math: '<S666>/Math Function1' incorporates:
           *  Sum: '<S666>/Sum of Elements'
           *
           * About '<S666>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_u_mm = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S666>/Math Function1' */

          /* Switch: '<S666>/Switch' incorporates:
           *  Constant: '<S666>/Constant'
           *  Product: '<S666>/Product'
           */
          if (rtb_u_mm > 0.0F) {
            rtb_Switch_d0[0] = rtb_Divide_n4[0];
            rtb_Switch_d0[1] = rtb_Subtract3_d;
            rtb_Switch_d0[2] = rtb_u_mm;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S666>/Switch' */

          /* Product: '<S666>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S669>/Sum of Elements' incorporates:
           *  Math: '<S669>/Math Function'
           *  SignalConversion: '<S669>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

          /* Math: '<S669>/Math Function1' incorporates:
           *  Sum: '<S669>/Sum of Elements'
           *
           * About '<S669>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_u_mm = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S669>/Math Function1' */

          /* Switch: '<S669>/Switch' incorporates:
           *  Constant: '<S669>/Constant'
           *  Product: '<S669>/Product'
           */
          if (rtb_u_mm > 0.0F) {
            rtb_Switch_d0[0] = rtb_P_cg[1];
            rtb_Switch_d0[1] = rtb_P_cg[0];
            rtb_Switch_d0[2] = rtb_u_mm;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S669>/Switch' */

          /* Product: '<S669>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Math: '<S664>/Square' */
          rtb_P_dg[0] = rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Product: '<S622>/Divide' */
          rtb_Square_h[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S669>/Divide' incorporates:
           *  Product: '<S668>/Divide'
           */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S668>/Divide' */
          rtb_Subtract3_d = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S622>/Divide' */
          rtb_Square_h[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S667>/Subtract' incorporates:
           *  Product: '<S667>/Multiply'
           *  Product: '<S667>/Multiply1'
           */
          rtb_u_mm = rtb_P_cg[0] * rtb_Subtract3_d - rtb_P_cg[1] *
            rtb_Divide_n4[0];

          /* Signum: '<S662>/Sign1' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S662>/Sign1' */

          /* Switch: '<S662>/Switch2' incorporates:
           *  Constant: '<S662>/Constant4'
           */
          if (rtb_u_mm == 0.0F) {
            rtb_u_mm = 1.0F;
          }

          /* End of Switch: '<S662>/Switch2' */

          /* DotProduct: '<S662>/Dot Product' */
          rtb_Subtract3_d = rtb_Divide_n4[0] * rtb_P_cg[0] + rtb_Subtract3_d *
            rtb_P_cg[1];

          /* Trigonometry: '<S662>/Acos' incorporates:
           *  DotProduct: '<S662>/Dot Product'
           */
          if (rtb_Subtract3_d > 1.0F) {
            rtb_Subtract3_d = 1.0F;
          } else {
            if (rtb_Subtract3_d < -1.0F) {
              rtb_Subtract3_d = -1.0F;
            }
          }

          /* Product: '<S662>/Multiply' incorporates:
           *  Trigonometry: '<S662>/Acos'
           */
          rtb_u_mm *= acosf(rtb_Subtract3_d);

          /* Saturate: '<S628>/Saturation' */
          if (rtb_u_mm > 1.57079637F) {
            rtb_u_mm = 1.57079637F;
          } else {
            if (rtb_u_mm < -1.57079637F) {
              rtb_u_mm = -1.57079637F;
            }
          }

          /* End of Saturate: '<S628>/Saturation' */

          /* Product: '<S628>/Divide' incorporates:
           *  Constant: '<S555>/L1'
           *  Constant: '<S628>/Constant'
           *  Gain: '<S628>/Gain'
           *  Math: '<S628>/Square'
           *  MinMax: '<S628>/Max'
           *  MinMax: '<S628>/Min'
           *  Product: '<S628>/Multiply1'
           *  Sqrt: '<S664>/Sqrt'
           *  Sum: '<S664>/Sum of Elements'
           *  Trigonometry: '<S628>/Sin'
           */
          rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_u_mm) * (rtb_Divide_l_idx_3 *
            rtb_Divide_l_idx_3 * 2.0F) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(d +
            rtb_P_dg[0]), 0.5F));

          /* Sum: '<S620>/Subtract' incorporates:
           *  Product: '<S620>/Multiply'
           *  Product: '<S620>/Multiply1'
           */
          rtb_Switch_fz_idx_1 = rtb_Square_h[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_h[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S609>/Sign1' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S609>/Sign1' */

          /* Switch: '<S609>/Switch2' incorporates:
           *  Constant: '<S609>/Constant4'
           */
          if (rtb_Switch_fz_idx_1 == 0.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          }

          /* End of Switch: '<S609>/Switch2' */

          /* DotProduct: '<S609>/Dot Product' */
          d = FMS_ConstB.Divide_m[0] * rtb_Square_h[0] + FMS_ConstB.Divide_m[1] *
            rtb_Square_h[1];

          /* Trigonometry: '<S609>/Acos' incorporates:
           *  DotProduct: '<S609>/Dot Product'
           */
          if (d > 1.0F) {
            d = 1.0F;
          } else {
            if (d < -1.0F) {
              d = -1.0F;
            }
          }

          /* Product: '<S609>/Multiply' incorporates:
           *  Trigonometry: '<S609>/Acos'
           */
          rtb_Switch_fz_idx_1 *= acosf(d);

          /* Math: '<S612>/Rem' incorporates:
           *  Constant: '<S612>/Constant1'
           *  Delay: '<S608>/Delay'
           *  Sum: '<S608>/Sum2'
           */
          rtb_u_mm = rt_remf(rtb_Switch_fz_idx_1 - FMS_DW.Delay_DSTATE_nx,
                             6.28318548F);

          /* Switch: '<S612>/Switch' incorporates:
           *  Abs: '<S612>/Abs'
           *  Constant: '<S612>/Constant'
           *  Constant: '<S618>/Constant'
           *  Product: '<S612>/Multiply'
           *  RelationalOperator: '<S618>/Compare'
           *  Sum: '<S612>/Add'
           */
          if (fabsf(rtb_u_mm) > 3.14159274F) {
            /* Signum: '<S612>/Sign' */
            if (rtb_u_mm < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (rtb_u_mm > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = rtb_u_mm;
            }

            /* End of Signum: '<S612>/Sign' */
            rtb_u_mm -= 6.28318548F * rtb_Divide_l_idx_2;
          }

          /* End of Switch: '<S612>/Switch' */

          /* Sum: '<S608>/Sum' incorporates:
           *  Delay: '<S608>/Delay'
           */
          rtb_Divide_l_idx_2 = rtb_u_mm + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S617>/Multiply1' incorporates:
           *  Constant: '<S617>/const1'
           *  DiscreteIntegrator: '<S611>/Integrator'
           */
          rtb_u_mm = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S617>/Add' incorporates:
           *  DiscreteIntegrator: '<S611>/Integrator1'
           *  Sum: '<S611>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_b - rtb_Divide_l_idx_2)
            + rtb_u_mm;

          /* Signum: '<S617>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3;
          }

          /* End of Signum: '<S617>/Sign' */

          /* Sum: '<S617>/Add2' incorporates:
           *  Abs: '<S617>/Abs'
           *  Gain: '<S617>/Gain'
           *  Gain: '<S617>/Gain1'
           *  Product: '<S617>/Multiply2'
           *  Product: '<S617>/Multiply3'
           *  Sqrt: '<S617>/Sqrt'
           *  Sum: '<S617>/Add1'
           *  Sum: '<S617>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_n) *
                     FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_u_mm;

          /* Sum: '<S617>/Add4' */
          rtb_u_mm += rtb_Divide_l_idx_3 - d;

          /* Sum: '<S617>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_n;

          /* Sum: '<S617>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_n;

          /* Signum: '<S617>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S617>/Sign1' */

          /* Signum: '<S617>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S617>/Sign2' */

          /* Sum: '<S617>/Add5' incorporates:
           *  Gain: '<S617>/Gain2'
           *  Product: '<S617>/Multiply4'
           *  Sum: '<S617>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Sum: '<S617>/Add6' */
          rtb_Divide_l_idx_2 = d + FMS_ConstB.d_n;

          /* Sum: '<S617>/Subtract3' */
          rtb_u_mm = d - FMS_ConstB.d_n;

          /* Product: '<S617>/Divide' */
          rtb_Switch_fz_idx_2 = d / FMS_ConstB.d_n;

          /* Signum: '<S617>/Sign5' incorporates:
           *  Signum: '<S617>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S617>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S617>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = d;

            /* Signum: '<S617>/Sign6' */
            rtb_Divide_l_idx_3 = d;
          }

          /* End of Signum: '<S617>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S608>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Switch_fz_idx_1 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S613>/Rem' incorporates:
           *  Constant: '<S613>/Constant1'
           */
          d = rt_remf(rtb_Switch_fz_idx_1, 6.28318548F);

          /* Switch: '<S613>/Switch' incorporates:
           *  Abs: '<S613>/Abs'
           *  Constant: '<S613>/Constant'
           *  Constant: '<S619>/Constant'
           *  Product: '<S613>/Multiply'
           *  RelationalOperator: '<S619>/Compare'
           *  Sum: '<S613>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S613>/Sign' */
            if (d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = d;
            }

            /* End of Signum: '<S613>/Sign' */
            d -= 6.28318548F * rtb_Switch_fz_idx_1;
          }

          /* End of Switch: '<S613>/Switch' */

          /* Abs: '<S606>/Abs' */
          d = fabsf(d);

          /* Update for Delay: '<S629>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S630>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S623>/Constant'
           *  RelationalOperator: '<S623>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_a = (uint8_T)((uint32_T)(d <=
            0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_a);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S630>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S625>/Acceleration_Speed' incorporates:
           *  Constant: '<S625>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S625>/Acceleration_Speed' */

          /* Product: '<S629>/Divide1' incorporates:
           *  Constant: '<S629>/Constant'
           */
          d = rtb_Switch_fz_idx_0 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S629>/Saturation' */
          if (d > 0.314159274F) {
            d = 0.314159274F;
          } else {
            if (d < -0.314159274F) {
              d = -0.314159274F;
            }
          }

          /* End of Saturate: '<S629>/Saturation' */

          /* Update for DiscreteIntegrator: '<S671>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * d;

          /* Update for Delay: '<S608>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S611>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S611>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Update for Delay: '<S607>/Delay' */
          FMS_DW.icLoad_f = 0U;

          /* Signum: '<S617>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S617>/Sign3' */

          /* Signum: '<S617>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S617>/Sign4' */

          /* Update for DiscreteIntegrator: '<S611>/Integrator' incorporates:
           *  Constant: '<S617>/const'
           *  Gain: '<S617>/Gain3'
           *  Product: '<S617>/Multiply5'
           *  Product: '<S617>/Multiply6'
           *  Sum: '<S617>/Subtract4'
           *  Sum: '<S617>/Subtract5'
           *  Sum: '<S617>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_d * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S611>/Integrator' */
          /* End of Outputs for SubSystem: '<S256>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S256>/Hold' incorporates:
             *  ActionPort: '<S553>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S256>/Switch Case' incorporates:
             *  Chart: '<S562>/Motion Status'
             *  Chart: '<S572>/Motion State'
             *  Chart: '<S584>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S256>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S256>/Hold' incorporates:
           *  ActionPort: '<S553>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S562>/Motion Status' incorporates:
           *  Abs: '<S562>/Abs'
           *  Constant: '<S562>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S572>/Motion State' incorporates:
           *  Abs: '<S572>/Abs'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
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

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              if ((fabsf(FMS_U.INS_Out.r) <= 0.1) ||
                  (FMS_DW.temporalCounter_i1_i >= 250U)) {
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
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_fg = MotionState_Brake;
              break;
            }
          }

          /* End of Chart: '<S572>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S584>/Motion State' incorporates:
           *  Constant: '<S584>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S584>/Square'
           *  Math: '<S584>/Square1'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sqrt: '<S584>/Sqrt'
           *  Sum: '<S584>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S583>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S583>/Hold Control' incorporates:
               *  ActionPort: '<S586>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S583>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S583>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S583>/Hold Control' incorporates:
             *  ActionPort: '<S586>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S583>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S583>/Brake Control' incorporates:
             *  ActionPort: '<S585>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S583>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S583>/Move Control' incorporates:
               *  ActionPort: '<S587>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S583>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S583>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S583>/Move Control' incorporates:
             *  ActionPort: '<S587>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S583>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S583>/Switch Case' */

          /* SwitchCase: '<S561>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S561>/Hold Control' incorporates:
               *  ActionPort: '<S564>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S561>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S561>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S561>/Hold Control' incorporates:
             *  ActionPort: '<S564>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S561>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S561>/Brake Control' incorporates:
             *  ActionPort: '<S563>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S561>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S561>/Move Control' incorporates:
               *  ActionPort: '<S565>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S561>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S561>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S561>/Move Control' incorporates:
             *  ActionPort: '<S565>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S561>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S561>/Switch Case' */

          /* SwitchCase: '<S571>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S571>/Hold Control' incorporates:
               *  ActionPort: '<S574>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S571>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S571>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S571>/Hold Control' incorporates:
             *  ActionPort: '<S574>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S571>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S571>/Brake Control' incorporates:
             *  ActionPort: '<S573>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S571>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_cv != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S571>/Move Control' incorporates:
               *  ActionPort: '<S575>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S571>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S571>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S571>/Move Control' incorporates:
             *  ActionPort: '<S575>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S571>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S571>/Switch Case' */

          /* BusAssignment: '<S553>/Bus Assignment' incorporates:
           *  Constant: '<S553>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;

          /* Saturate: '<S571>/Saturation' */
          if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;
          }

          /* End of Saturate: '<S571>/Saturation' */

          /* Saturate: '<S583>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S583>/Saturation1' */

          /* Saturate: '<S561>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S553>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S561>/Saturation1' */
          /* End of Outputs for SubSystem: '<S256>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S256>/Unknown' incorporates:
           *  ActionPort: '<S557>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S256>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S48>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S48>/Auto' incorporates:
         *  ActionPort: '<S254>/Action Port'
         */
        /* SwitchCase: '<S254>/Switch Case' incorporates:
         *  Math: '<S434>/Square'
         *  Sum: '<S395>/Subtract'
         *  Sum: '<S449>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S366>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S414>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S404>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* End of Disable for SubSystem: '<S366>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S254>/Offboard' incorporates:
           *  ActionPort: '<S367>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S530>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S533>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S534>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S534>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S534>/Multiply1' incorporates:
           *  Product: '<S534>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S534>/Divide' incorporates:
           *  Constant: '<S534>/Constant'
           *  Constant: '<S534>/R'
           *  Sqrt: '<S534>/Sqrt'
           *  Sum: '<S534>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S534>/Product3' incorporates:
           *  Constant: '<S534>/Constant1'
           *  Product: '<S534>/Multiply1'
           *  Sum: '<S534>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S534>/Multiply2' incorporates:
           *  Trigonometry: '<S534>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S533>/Sum' incorporates:
           *  Gain: '<S530>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S41>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S538>/Abs' incorporates:
           *  Abs: '<S541>/Abs1'
           *  Switch: '<S538>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S538>/Switch1' incorporates:
           *  Abs: '<S538>/Abs'
           *  Bias: '<S538>/Bias2'
           *  Bias: '<S538>/Bias3'
           *  Constant: '<S535>/Constant'
           *  Constant: '<S535>/Constant1'
           *  Constant: '<S540>/Constant'
           *  Gain: '<S538>/Gain1'
           *  Product: '<S538>/Multiply'
           *  RelationalOperator: '<S540>/Compare'
           *  Switch: '<S535>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S541>/Switch1' incorporates:
             *  Bias: '<S541>/Bias2'
             *  Bias: '<S541>/Bias3'
             *  Constant: '<S541>/Constant'
             *  Constant: '<S542>/Constant'
             *  Math: '<S541>/Math Function'
             *  RelationalOperator: '<S542>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S541>/Switch1' */

            /* Signum: '<S538>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S538>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S535>/Sum' incorporates:
           *  Gain: '<S530>/Gain1'
           *  Gain: '<S530>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sum: '<S533>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S533>/Multiply' incorporates:
           *  Gain: '<S533>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S537>/Switch1' incorporates:
           *  Abs: '<S537>/Abs1'
           *  Bias: '<S537>/Bias2'
           *  Bias: '<S537>/Bias3'
           *  Constant: '<S537>/Constant'
           *  Constant: '<S539>/Constant'
           *  Math: '<S537>/Math Function'
           *  RelationalOperator: '<S539>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S537>/Switch1' */

          /* Product: '<S533>/Multiply' incorporates:
           *  Gain: '<S533>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S511>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S515>/Multiply1'
           *  SignalConversion: '<S41>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S524>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S524>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S524>/Trigonometric Function3' incorporates:
             *  Gain: '<S523>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S524>/Gain' incorporates:
             *  Gain: '<S523>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Trigonometry: '<S524>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S524>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S524>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S524>/Trigonometric Function' incorporates:
             *  Gain: '<S523>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S524>/Trigonometric Function1' incorporates:
             *  Gain: '<S523>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S524>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S517>/Switch' incorporates:
             *  Constant: '<S532>/Constant'
             *  DataTypeConversion: '<S530>/Data Type Conversion1'
             *  Product: '<S536>/Multiply1'
             *  Product: '<S536>/Multiply2'
             *  RelationalOperator: '<S532>/Compare'
             *  S-Function (sfix_bitop): '<S529>/lat_cmd valid'
             *  Sum: '<S536>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              d = (real32_T)(rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o2 +
                             rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              d = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S515>/Multiply' incorporates:
             *  Constant: '<S521>/Constant'
             *  Constant: '<S522>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S514>/Logical Operator'
             *  RelationalOperator: '<S521>/Compare'
             *  RelationalOperator: '<S522>/Compare'
             *  S-Function (sfix_bitop): '<S514>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/x_cmd valid'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S515>/Sum1'
             */
            rtb_Divide_l_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? d - FMS_U.INS_Out.x_R :
              0.0F;

            /* SignalConversion: '<S524>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S517>/Switch' incorporates:
             *  Constant: '<S532>/Constant'
             *  DataTypeConversion: '<S530>/Data Type Conversion1'
             *  Product: '<S536>/Multiply3'
             *  Product: '<S536>/Multiply4'
             *  RelationalOperator: '<S532>/Compare'
             *  S-Function (sfix_bitop): '<S529>/lon_cmd valid'
             *  Sum: '<S536>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              d = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                             rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              d = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S515>/Multiply' incorporates:
             *  Constant: '<S521>/Constant'
             *  Constant: '<S522>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S514>/Logical Operator'
             *  RelationalOperator: '<S521>/Compare'
             *  RelationalOperator: '<S522>/Compare'
             *  S-Function (sfix_bitop): '<S514>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/y_cmd valid'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S515>/Sum1'
             */
            rtb_Switch_fz_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? d - FMS_U.INS_Out.y_R :
              0.0F;

            /* SignalConversion: '<S524>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S517>/Switch' incorporates:
             *  Constant: '<S532>/Constant'
             *  DataTypeConversion: '<S530>/Data Type Conversion'
             *  DataTypeConversion: '<S530>/Data Type Conversion1'
             *  Gain: '<S530>/Gain2'
             *  Gain: '<S533>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S532>/Compare'
             *  S-Function (sfix_bitop): '<S529>/alt_cmd valid'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S533>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              d = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd + -FMS_U.INS_Out.alt_0);
            } else {
              d = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S515>/Multiply' incorporates:
             *  Constant: '<S521>/Constant'
             *  Constant: '<S522>/Constant'
             *  Gain: '<S518>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S514>/Logical Operator'
             *  RelationalOperator: '<S521>/Compare'
             *  RelationalOperator: '<S522>/Compare'
             *  S-Function (sfix_bitop): '<S514>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/z_cmd valid'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S515>/Sum1'
             */
            rtb_Divide_l_idx_3 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? d - (-FMS_U.INS_Out.h_R)
              : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Divide_l_idx_3 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
            }

            /* SignalConversion: '<S457>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S457>/Constant4'
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  Product: '<S515>/Multiply1'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S457>/Trigonometric Function3' incorporates:
             *  Gain: '<S456>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S457>/Gain' incorporates:
             *  Gain: '<S456>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Trigonometry: '<S457>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S457>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S457>/Constant3'
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S457>/Trigonometric Function' incorporates:
             *  Gain: '<S456>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S457>/Trigonometric Function1' incorporates:
             *  Gain: '<S456>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S457>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S446>/Multiply' incorporates:
             *  Constant: '<S455>/Constant'
             *  RelationalOperator: '<S455>/Compare'
             *  S-Function (sfix_bitop): '<S452>/ax_cmd valid'
             */
            rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S457>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S446>/Multiply' incorporates:
             *  Constant: '<S455>/Constant'
             *  RelationalOperator: '<S455>/Compare'
             *  S-Function (sfix_bitop): '<S452>/ay_cmd valid'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S457>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S446>/Multiply' incorporates:
             *  Constant: '<S455>/Constant'
             *  RelationalOperator: '<S455>/Compare'
             *  S-Function (sfix_bitop): '<S452>/az_cmd valid'
             */
            rtb_Divide_l_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S446>/Index Vector' incorporates:
             *  Product: '<S453>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Divide_l_idx_3 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
            }
            break;

           case 1:
            /* SignalConversion: '<S527>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S527>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S527>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S516>/Data Store Read'
             *  Gain: '<S525>/Gain'
             *  Trigonometry: '<S527>/Trigonometric Function1'
             */
            rtb_Switch_fz_idx_1 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_Transpose[4] = rtb_Switch_fz_idx_1;

            /* Trigonometry: '<S527>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S516>/Data Store Read'
             *  Gain: '<S525>/Gain'
             *  Trigonometry: '<S527>/Trigonometric Function'
             */
            rtb_Switch_fz_idx_0 = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S527>/Gain' incorporates:
             *  Trigonometry: '<S527>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S527>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S527>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S527>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Switch_fz_idx_0;

            /* Trigonometry: '<S527>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_Switch_fz_idx_1;

            /* SignalConversion: '<S528>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S528>/Constant4'
             */
            rtb_MatrixConcatenate1_i[5] = 0.0F;

            /* Gain: '<S526>/Gain' incorporates:
             *  DataStoreRead: '<S516>/Data Store Read'
             *  Gain: '<S458>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S516>/Subtract'
             */
            rtb_Switch_fz_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S528>/Trigonometric Function3' incorporates:
             *  Gain: '<S526>/Gain'
             *  Trigonometry: '<S528>/Trigonometric Function1'
             */
            rtb_u_mm = arm_cos_f32(rtb_Switch_fz_idx_2);
            rtb_MatrixConcatenate1_i[4] = rtb_u_mm;

            /* Trigonometry: '<S528>/Trigonometric Function2' incorporates:
             *  Gain: '<S526>/Gain'
             *  Trigonometry: '<S528>/Trigonometric Function'
             */
            rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_Switch_fz_idx_2);

            /* Gain: '<S528>/Gain' incorporates:
             *  Trigonometry: '<S528>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_i[3] = -rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S528>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S528>/Constant3'
             */
            rtb_MatrixConcatenate1_i[2] = 0.0F;

            /* Trigonometry: '<S528>/Trigonometric Function' */
            rtb_MatrixConcatenate1_i[1] = rtb_Switch_fz_idx_0;

            /* Trigonometry: '<S528>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_i[0] = rtb_u_mm;

            /* RelationalOperator: '<S532>/Compare' incorporates:
             *  Constant: '<S532>/Constant'
             *  S-Function (sfix_bitop): '<S529>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S529>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S529>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S530>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S530>/Data Type Conversion'
             *  Gain: '<S530>/Gain2'
             *  Gain: '<S533>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S536>/Multiply1'
             *  Product: '<S536>/Multiply2'
             *  Product: '<S536>/Multiply3'
             *  Product: '<S536>/Multiply4'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S533>/Sum1'
             *  Sum: '<S536>/Sum2'
             *  Sum: '<S536>/Sum3'
             */
            rtb_Multiply_g_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Multiply_g_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Multiply_g_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S517>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S527>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S528>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S516>/Sum' incorporates:
             *  DataStoreRead: '<S516>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Divide_l_idx_2 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S527>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S528>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S516>/Sum' incorporates:
             *  DataStoreRead: '<S516>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S527>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S528>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S516>/Sum' incorporates:
             *  DataStoreRead: '<S516>/Data Store Read'
             *  Gain: '<S518>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Divide_l_idx_3 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S521>/Compare' incorporates:
             *  Constant: '<S521>/Constant'
             *  S-Function (sfix_bitop): '<S514>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S522>/Compare' incorporates:
             *  Constant: '<S522>/Constant'
             *  S-Function (sfix_bitop): '<S514>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S516>/Sum2' incorporates:
               *  Product: '<S516>/Multiply2'
               *  Switch: '<S517>/Switch'
               */
              if (tmp[rtb_n]) {
                d = rtb_Multiply_g_0[rtb_n];
              } else {
                d = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              /* Product: '<S516>/Multiply' incorporates:
               *  Logic: '<S514>/Logical Operator'
               *  Product: '<S516>/Multiply2'
               *  Sum: '<S516>/Sum'
               *  Sum: '<S516>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? d -
                ((rtb_Transpose[rtb_n + 3] * rtb_Switch_fz_idx_1 +
                  rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2) +
                 rtb_Transpose[rtb_n + 6] * rtb_Divide_l_idx_3) : 0.0F;
            }

            /* SignalConversion: '<S459>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S459>/Constant4'
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S459>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[4] = arm_cos_f32(rtb_Switch_fz_idx_2);

            /* Gain: '<S459>/Gain' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             *  Trigonometry: '<S459>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_Switch_fz_idx_2);

            /* SignalConversion: '<S459>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S459>/Constant3'
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S459>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[1] = arm_sin_f32(rtb_Switch_fz_idx_2);

            /* Trigonometry: '<S459>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S446>/Index Vector'
             */
            rtb_Transpose[0] = arm_cos_f32(rtb_Switch_fz_idx_2);

            /* Product: '<S446>/Multiply' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S455>/Compare' incorporates:
             *  Constant: '<S455>/Constant'
             *  S-Function (sfix_bitop): '<S452>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S452>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S452>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S459>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S446>/Index Vector'
               */
              rtb_Transpose[rtb_n + 6] = FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S446>/Multiply' */
              rtb_Multiply_g_0[rtb_n] = tmp[rtb_n] ?
                rtb_MatrixConcatenate1_i_0[rtb_n] : 0.0F;
              rtb_Switch_d0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
                rtb_Switch_ov[2] + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                                    rtb_Switch_ov[1] +
                                    rtb_MatrixConcatenate1_i[rtb_n] *
                                    rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S446>/Index Vector' incorporates:
             *  Product: '<S454>/Multiply3'
             *  Product: '<S516>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Multiply_g_0[2] + (rtb_Transpose[rtb_n + 3] *
                rtb_Multiply_g_0[1] + rtb_Transpose[rtb_n] * rtb_Multiply_g_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S520>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S520>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S520>/Trigonometric Function3' incorporates:
             *  Gain: '<S519>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S520>/Gain' incorporates:
             *  Gain: '<S519>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Trigonometry: '<S520>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S520>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S520>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S520>/Trigonometric Function' incorporates:
             *  Gain: '<S519>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S520>/Trigonometric Function1' incorporates:
             *  Gain: '<S519>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S529>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S514>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S532>/Compare' incorporates:
             *  Constant: '<S532>/Constant'
             *  S-Function (sfix_bitop): '<S529>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S529>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S514>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S532>/Compare' incorporates:
             *  Constant: '<S532>/Constant'
             *  S-Function (sfix_bitop): '<S529>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S529>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S514>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S532>/Compare' incorporates:
             *  Constant: '<S532>/Constant'
             *  S-Function (sfix_bitop): '<S529>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S530>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S530>/Data Type Conversion'
             *  Gain: '<S530>/Gain2'
             *  Gain: '<S533>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S536>/Multiply1'
             *  Product: '<S536>/Multiply2'
             *  Product: '<S536>/Multiply3'
             *  Product: '<S536>/Multiply4'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S533>/Sum1'
             *  Sum: '<S536>/Sum2'
             *  Sum: '<S536>/Sum3'
             */
            rtb_Multiply_g_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Multiply_g_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Multiply_g_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S517>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S520>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_g[0];

            /* Sum: '<S513>/Sum' incorporates:
             *  DataStoreRead: '<S513>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Divide_l_idx_2 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S520>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_g[1];

            /* Sum: '<S513>/Sum' incorporates:
             *  DataStoreRead: '<S513>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Divide_l_idx_3 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S520>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Sum: '<S513>/Sum' incorporates:
             *  DataStoreRead: '<S513>/Data Store Read'
             *  Gain: '<S518>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_u_mm = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S521>/Compare' incorporates:
             *  Constant: '<S521>/Constant'
             *  S-Function (sfix_bitop): '<S514>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S514>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S522>/Compare' incorporates:
             *  Constant: '<S522>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S513>/Sum2' incorporates:
             *  Logic: '<S514>/Logical Operator'
             *  Product: '<S513>/Multiply'
             *  Product: '<S513>/Multiply2'
             *  Sum: '<S513>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S517>/Switch' incorporates:
               *  Product: '<S513>/Multiply2'
               */
              if (tmp[rtb_n]) {
                d = rtb_Multiply_g_0[rtb_n];
              } else {
                d = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              rtb_Switch_d0[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? d -
                ((rtb_Transpose[rtb_n + 3] * rtb_Divide_l_idx_3 +
                  rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2) +
                 rtb_Transpose[rtb_n + 6] * rtb_u_mm) : 0.0F;
            }

            /* End of Sum: '<S513>/Sum2' */

            /* MultiPortSwitch: '<S446>/Index Vector' incorporates:
             *  Constant: '<S455>/Constant'
             *  Product: '<S446>/Multiply'
             *  RelationalOperator: '<S455>/Compare'
             *  S-Function (sfix_bitop): '<S452>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S452>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S452>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S511>/Index Vector' */

          /* Sum: '<S507>/Sum1' incorporates:
           *  Constant: '<S507>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S507>/Math Function'
           *  SignalConversion: '<S41>/Signal Copy'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Switch_fz_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S508>/Abs' */
          rtb_Divide_l_idx_2 = fabsf(rtb_Switch_fz_idx_2);

          /* Switch: '<S508>/Switch' incorporates:
           *  Constant: '<S508>/Constant'
           *  Constant: '<S509>/Constant'
           *  Product: '<S508>/Multiply'
           *  RelationalOperator: '<S509>/Compare'
           *  Sum: '<S508>/Subtract'
           */
          if (rtb_Divide_l_idx_2 > 3.14159274F) {
            /* Signum: '<S508>/Sign' */
            if (rtb_Switch_fz_idx_2 < 0.0F) {
              rtb_Switch_fz_idx_2 = -1.0F;
            } else {
              if (rtb_Switch_fz_idx_2 > 0.0F) {
                rtb_Switch_fz_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S508>/Sign' */
            rtb_Switch_fz_idx_2 *= rtb_Divide_l_idx_2 - 6.28318548F;
          }

          /* End of Switch: '<S508>/Switch' */

          /* Saturate: '<S507>/Saturation' */
          if (rtb_Switch_fz_idx_2 > 0.314159274F) {
            rtb_Switch_fz_idx_2 = 0.314159274F;
          } else {
            if (rtb_Switch_fz_idx_2 < -0.314159274F) {
              rtb_Switch_fz_idx_2 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S507>/Saturation' */

          /* Gain: '<S504>/Gain2' */
          rtb_Switch_fz_idx_2 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S448>/Sum' incorporates:
           *  Constant: '<S506>/Constant'
           *  Constant: '<S510>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S504>/Multiply2'
           *  Product: '<S505>/Multiply1'
           *  RelationalOperator: '<S506>/Compare'
           *  RelationalOperator: '<S510>/Compare'
           *  S-Function (sfix_bitop): '<S504>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S505>/psi_rate_cmd valid'
           *  SignalConversion: '<S41>/Signal Copy'
           */
          d = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Switch_fz_idx_2 : 0.0F)
            + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
               FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S511>/Gain1' */
          rtb_u_mm = FMS_PARAM.XY_P * rtb_Switch_d0[0];
          rtb_Switch_fz_idx_0 = FMS_PARAM.XY_P * rtb_Switch_d0[1];

          /* Gain: '<S511>/Gain2' */
          rtb_Switch_fz_idx_2 = FMS_PARAM.Z_P * rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S512>/Index Vector' incorporates:
           *  Constant: '<S548>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S512>/Multiply'
           *  Product: '<S545>/Multiply'
           *  Product: '<S546>/Multiply3'
           *  RelationalOperator: '<S548>/Compare'
           *  S-Function (sfix_bitop): '<S544>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S544>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S544>/w_cmd valid'
           *  SignalConversion: '<S41>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S550>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S550>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S550>/Trigonometric Function3' incorporates:
             *  Gain: '<S549>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S550>/Gain' incorporates:
             *  Gain: '<S549>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Trigonometry: '<S550>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S550>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S550>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S550>/Trigonometric Function' incorporates:
             *  Gain: '<S549>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S550>/Trigonometric Function1' incorporates:
             *  Gain: '<S549>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S550>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S512>/Multiply' incorporates:
             *  Constant: '<S548>/Constant'
             *  RelationalOperator: '<S548>/Compare'
             *  S-Function (sfix_bitop): '<S544>/u_cmd valid'
             */
            rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S550>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S512>/Multiply' incorporates:
             *  Constant: '<S548>/Constant'
             *  RelationalOperator: '<S548>/Compare'
             *  S-Function (sfix_bitop): '<S544>/v_cmd valid'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S550>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S512>/Multiply' incorporates:
             *  Constant: '<S548>/Constant'
             *  RelationalOperator: '<S548>/Compare'
             *  S-Function (sfix_bitop): '<S544>/w_cmd valid'
             */
            rtb_Divide_l_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Divide_l_idx_3 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
            }
            break;

           case 1:
            /* SignalConversion: '<S552>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S552>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Gain: '<S551>/Gain' incorporates:
             *  DataStoreRead: '<S546>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S546>/Subtract'
             */
            rtb_Divide_l_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S552>/Trigonometric Function3' incorporates:
             *  Gain: '<S551>/Gain'
             */
            rtb_Transpose[4] = arm_cos_f32(rtb_Divide_l_idx_2);

            /* Gain: '<S552>/Gain' incorporates:
             *  Gain: '<S551>/Gain'
             *  Trigonometry: '<S552>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_l_idx_2);

            /* SignalConversion: '<S552>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S552>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S552>/Trigonometric Function' incorporates:
             *  Gain: '<S551>/Gain'
             */
            rtb_Transpose[1] = arm_sin_f32(rtb_Divide_l_idx_2);

            /* Trigonometry: '<S552>/Trigonometric Function1' incorporates:
             *  Gain: '<S551>/Gain'
             */
            rtb_Transpose[0] = arm_cos_f32(rtb_Divide_l_idx_2);

            /* SignalConversion: '<S552>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Product: '<S512>/Multiply' incorporates:
             *  Constant: '<S548>/Constant'
             *  RelationalOperator: '<S548>/Compare'
             *  S-Function (sfix_bitop): '<S544>/u_cmd valid'
             */
            rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S552>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Product: '<S512>/Multiply' incorporates:
             *  Constant: '<S548>/Constant'
             *  RelationalOperator: '<S548>/Compare'
             *  S-Function (sfix_bitop): '<S544>/v_cmd valid'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S552>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Product: '<S512>/Multiply' incorporates:
             *  Constant: '<S548>/Constant'
             *  RelationalOperator: '<S548>/Compare'
             *  S-Function (sfix_bitop): '<S544>/w_cmd valid'
             */
            rtb_Divide_l_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Divide_l_idx_3 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
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

          /* End of MultiPortSwitch: '<S512>/Index Vector' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_d0[0] += rtb_u_mm;
          rtb_Switch_d0[1] += rtb_Switch_fz_idx_0;

          /* Sum: '<S449>/Sum1' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_2 + rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S467>/Switch' incorporates:
           *  Constant: '<S482>/Constant'
           *  Constant: '<S484>/Constant'
           *  Constant: '<S485>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S482>/Compare'
           *  RelationalOperator: '<S484>/Compare'
           *  RelationalOperator: '<S485>/Compare'
           *  S-Function (sfix_bitop): '<S467>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S467>/y_v_cmd'
           *  SignalConversion: '<S41>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S467>/Logical Operator' incorporates:
             *  Constant: '<S483>/Constant'
             *  Constant: '<S484>/Constant'
             *  Constant: '<S485>/Constant'
             *  RelationalOperator: '<S483>/Compare'
             *  RelationalOperator: '<S484>/Compare'
             *  RelationalOperator: '<S485>/Compare'
             *  S-Function (sfix_bitop): '<S467>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S467>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S467>/y_v_cmd'
             */
            rtb_LogicalOperator_oy = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_oy;
          } else {
            rtb_LogicalOperator_oy = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U)
              > 0U);
          }

          /* End of Switch: '<S467>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S447>/u_cmd_valid' */
          /* MATLAB Function: '<S479>/bit_shift' incorporates:
           *  DataTypeConversion: '<S447>/Data Type Conversion6'
           */
          rtb_DataTypeConversion_o = (uint16_T)(rtb_LogicalOperator_oy << 6);

          /* End of Outputs for SubSystem: '<S447>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S447>/v_cmd_valid' */
          /* MATLAB Function: '<S480>/bit_shift' incorporates:
           *  DataTypeConversion: '<S447>/Data Type Conversion7'
           */
          rtb_DataTypeConversion1_b = (uint16_T)(rtb_FixPtRelationalOperator_me <<
            7);

          /* End of Outputs for SubSystem: '<S447>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S468>/Switch' incorporates:
           *  Constant: '<S487>/Constant'
           *  Constant: '<S488>/Constant'
           *  Constant: '<S490>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S487>/Compare'
           *  RelationalOperator: '<S488>/Compare'
           *  RelationalOperator: '<S490>/Compare'
           *  S-Function (sfix_bitop): '<S468>/ax_cmd'
           *  S-Function (sfix_bitop): '<S468>/ay_cmd'
           *  SignalConversion: '<S41>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S468>/Logical Operator' incorporates:
             *  Constant: '<S488>/Constant'
             *  Constant: '<S490>/Constant'
             *  RelationalOperator: '<S488>/Compare'
             *  RelationalOperator: '<S490>/Compare'
             *  S-Function (sfix_bitop): '<S468>/ax_cmd'
             *  S-Function (sfix_bitop): '<S468>/ay_cmd'
             */
            rtb_LogicalOperator_oy = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_oy;
          } else {
            rtb_LogicalOperator_oy = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S468>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S367>/Bus Assignment' incorporates:
           *  Constant: '<S367>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S41>/Signal Copy'
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
          FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.az_cmd = rtb_Switch_ov[2];

          /* Saturate: '<S448>/Saturation' */
          if (d > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (d < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = d;
          }

          /* End of Saturate: '<S448>/Saturation' */

          /* Saturate: '<S449>/Saturation2' */
          if (rtb_Switch_d0[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_d0[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_d0[0];
          }

          /* End of Saturate: '<S449>/Saturation2' */

          /* Saturate: '<S449>/Saturation1' */
          if (rtb_Switch_d0[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_d0[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_d0[1];
          }

          /* End of Saturate: '<S449>/Saturation1' */

          /* Saturate: '<S449>/Saturation3' */
          if (rtb_Divide_l_idx_2 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_l_idx_2 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S367>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Divide_l_idx_2;
          }

          /* End of Saturate: '<S449>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S447>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S447>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S447>/throttle_cmd_valid' */
          /* BusAssignment: '<S367>/Bus Assignment' incorporates:
           *  Constant: '<S460>/Constant'
           *  Constant: '<S461>/Constant'
           *  Constant: '<S462>/Constant'
           *  Constant: '<S463>/Constant'
           *  Constant: '<S464>/Constant'
           *  Constant: '<S465>/Constant'
           *  Constant: '<S466>/Constant'
           *  Constant: '<S486>/Constant'
           *  Constant: '<S489>/Constant'
           *  DataTypeConversion: '<S447>/Data Type Conversion10'
           *  DataTypeConversion: '<S447>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S469>/bit_shift'
           *  MATLAB Function: '<S470>/bit_shift'
           *  MATLAB Function: '<S471>/bit_shift'
           *  MATLAB Function: '<S473>/bit_shift'
           *  MATLAB Function: '<S474>/bit_shift'
           *  MATLAB Function: '<S475>/bit_shift'
           *  MATLAB Function: '<S476>/bit_shift'
           *  MATLAB Function: '<S477>/bit_shift'
           *  MATLAB Function: '<S478>/bit_shift'
           *  MATLAB Function: '<S481>/bit_shift'
           *  RelationalOperator: '<S460>/Compare'
           *  RelationalOperator: '<S461>/Compare'
           *  RelationalOperator: '<S462>/Compare'
           *  RelationalOperator: '<S463>/Compare'
           *  RelationalOperator: '<S464>/Compare'
           *  RelationalOperator: '<S465>/Compare'
           *  RelationalOperator: '<S466>/Compare'
           *  RelationalOperator: '<S486>/Compare'
           *  RelationalOperator: '<S489>/Compare'
           *  S-Function (sfix_bitop): '<S447>/p_cmd'
           *  S-Function (sfix_bitop): '<S447>/phi_cmd'
           *  S-Function (sfix_bitop): '<S447>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S447>/q_cmd'
           *  S-Function (sfix_bitop): '<S447>/r_cmd'
           *  S-Function (sfix_bitop): '<S447>/theta_cmd'
           *  S-Function (sfix_bitop): '<S447>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S467>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S468>/az_cmd'
           *  SignalConversion: '<S41>/Signal Copy'
           *  Sum: '<S447>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) +
            rtb_DataTypeConversion_o) + rtb_DataTypeConversion1_b) +
            (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
            (rtb_LogicalOperator_oy << 9)) + (rtb_FixPtRelationalOperator_me <<
            10)) + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S447>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S447>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S447>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S254>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S254>/Mission' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S254>/Switch Case' incorporates:
             *  UnitDelay: '<S369>/Delay Input1'
             *
             * Block description for '<S369>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S254>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S254>/Mission' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S366>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S254>/Switch Case' incorporates:
             *  Chart: '<S405>/Motion Status'
             *  Chart: '<S415>/Motion State'
             *  Delay: '<S374>/Delay'
             *  Delay: '<S396>/Delay'
             *  DiscreteIntegrator: '<S377>/Integrator'
             *  DiscreteIntegrator: '<S377>/Integrator1'
             *  DiscreteIntegrator: '<S392>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S397>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S441>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 0U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.icLoad_m = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_h);

            /* End of SystemReset for SubSystem: '<S366>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S254>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S254>/Mission' incorporates:
           *  ActionPort: '<S366>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S369>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S369>/Delay Input1'
           *
           * Block description for '<S369>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S366>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S370>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S414>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S404>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* InitializeConditions for Delay: '<S396>/Delay' */
            FMS_DW.icLoad = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S397>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S392>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S441>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S374>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S415>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S405>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_h);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S396>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S397>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S369>/Delay Input1'
           *
           * Block description for '<S369>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTAT_kd;

          /* RelationalOperator: '<S391>/Compare' incorporates:
           *  Constant: '<S445>/Constant'
           *  RelationalOperator: '<S445>/Compare'
           *  UnitDelay: '<S369>/Delay Input1'
           *
           * Block description for '<S369>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_ii = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S392>/Acceleration_Speed' */
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

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S415>/Motion State' incorporates:
           *  Constant: '<S415>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S415>/Square'
           *  Math: '<S415>/Square1'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sqrt: '<S415>/Sqrt'
           *  Sum: '<S415>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S414>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S414>/Hold Control' incorporates:
               *  ActionPort: '<S417>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S414>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_fy);

              /* End of SystemReset for SubSystem: '<S414>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S414>/Hold Control' incorporates:
             *  ActionPort: '<S417>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_ls,
                              &FMS_ConstB.HoldControl_fy, &FMS_DW.HoldControl_fy);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S414>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S414>/Brake Control' incorporates:
             *  ActionPort: '<S416>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_ls);

            /* End of Outputs for SubSystem: '<S414>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S414>/Move Control' incorporates:
               *  ActionPort: '<S418>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S414>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_i);

              /* End of SystemReset for SubSystem: '<S414>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S414>/Move Control' incorporates:
             *  ActionPort: '<S418>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_ls,
                              &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S414>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S414>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S405>/Motion Status' incorporates:
           *  Abs: '<S405>/Abs'
           *  Constant: '<S405>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_h);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S404>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S404>/Hold Control' incorporates:
               *  ActionPort: '<S407>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S404>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bf);

              /* End of SystemReset for SubSystem: '<S404>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S404>/Hold Control' incorporates:
             *  ActionPort: '<S407>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_i,
                              &FMS_DW.HoldControl_bf);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S404>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S404>/Brake Control' incorporates:
             *  ActionPort: '<S406>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_i);

            /* End of Outputs for SubSystem: '<S404>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S404>/Move Control' incorporates:
               *  ActionPort: '<S408>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S404>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c0);

              /* End of SystemReset for SubSystem: '<S404>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S404>/Move Control' incorporates:
             *  ActionPort: '<S408>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_i,
                              &FMS_ConstB.MoveControl_c0, &FMS_DW.MoveControl_c0);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S404>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S404>/Switch Case' */

          /* Switch: '<S372>/Switch' incorporates:
           *  Product: '<S396>/Multiply'
           *  Sum: '<S396>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S414>/Saturation1' */
            if (FMS_B.Merge_ls[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_fz_idx_0 = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_ls[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_fz_idx_0 = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_fz_idx_0 = FMS_B.Merge_ls[0];
            }

            if (FMS_B.Merge_ls[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_fz_idx_1 = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_ls[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_fz_idx_1 = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_fz_idx_1 = FMS_B.Merge_ls[1];
            }

            /* End of Saturate: '<S414>/Saturation1' */

            /* Saturate: '<S404>/Saturation1' */
            if (FMS_B.Merge_i > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_fz_idx_2 = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_i < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_fz_idx_2 = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_fz_idx_2 = FMS_B.Merge_i;
            }

            /* End of Saturate: '<S404>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S396>/Sum' incorporates:
             *  Delay: '<S396>/Delay'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S442>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S392>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_n4[0] = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S396>/Sum' incorporates:
             *  Delay: '<S396>/Delay'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE[1];

            /* Sum: '<S392>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_u_mm = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S401>/Sqrt' incorporates:
             *  Math: '<S401>/Square'
             *  Sum: '<S392>/Sum'
             *  Sum: '<S401>/Sum of Elements'
             */
            rtb_u_mm = sqrtf(rtb_Switch_fz_idx_1 * rtb_Switch_fz_idx_1 +
                             rtb_u_mm * rtb_u_mm);

            /* SignalConversion: '<S444>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

            /* SignalConversion: '<S444>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S444>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S443>/Gain' incorporates:
             *  DiscreteIntegrator: '<S441>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  Sum: '<S441>/Add'
             */
            rtb_Switch_fz_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S444>/Trigonometric Function3' */
            rtb_Transpose[4] = arm_cos_f32(rtb_Switch_fz_idx_1);

            /* Gain: '<S444>/Gain' incorporates:
             *  Trigonometry: '<S444>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_Switch_fz_idx_1);

            /* SignalConversion: '<S444>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S444>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S444>/Trigonometric Function' */
            rtb_Transpose[1] = arm_sin_f32(rtb_Switch_fz_idx_1);

            /* Trigonometry: '<S444>/Trigonometric Function1' */
            rtb_Transpose[0] = arm_cos_f32(rtb_Switch_fz_idx_1);

            /* Switch: '<S392>/Switch' incorporates:
             *  Constant: '<S392>/vel'
             */
            if (rtb_u_mm > FMS_PARAM.L1) {
              rtb_Switch_fz_idx_1 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S392>/Gain' */
              rtb_Switch_fz_idx_1 = 0.5F * rtb_u_mm;

              /* Saturate: '<S392>/Saturation' */
              if (rtb_Switch_fz_idx_1 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Switch_fz_idx_1 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Switch_fz_idx_1 < 0.5F) {
                  rtb_Switch_fz_idx_1 = 0.5F;
                }
              }

              /* End of Saturate: '<S392>/Saturation' */
            }

            /* End of Switch: '<S392>/Switch' */

            /* Switch: '<S392>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S392>/Acceleration_Speed'
             *  Sum: '<S392>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE - rtb_Switch_fz_idx_1 < 0.0F) {
              rtb_Switch_fz_idx_1 = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S392>/Switch1' */

            /* Sum: '<S442>/Sum of Elements' incorporates:
             *  Math: '<S442>/Math Function'
             */
            d = rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0 + rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_2;

            /* Math: '<S442>/Math Function1' incorporates:
             *  Sum: '<S442>/Sum of Elements'
             *
             * About '<S442>/Math Function1':
             *  Operator: sqrt
             */
            if (d < 0.0F) {
              d = -sqrtf(fabsf(d));
            } else {
              d = sqrtf(d);
            }

            /* End of Math: '<S442>/Math Function1' */

            /* Switch: '<S442>/Switch' incorporates:
             *  Constant: '<S442>/Constant'
             *  Product: '<S442>/Product'
             */
            if (d > 0.0F) {
              rtb_u_mm = rtb_Divide_n4[0];
            } else {
              rtb_u_mm = 0.0F;
              rtb_Switch_fz_idx_2 = 0.0F;
              d = 1.0F;
            }

            /* End of Switch: '<S442>/Switch' */

            /* Product: '<S440>/Multiply2' incorporates:
             *  Product: '<S442>/Divide'
             */
            rtb_Divide_or = rtb_u_mm / d * rtb_Switch_fz_idx_1;
            rtb_Sign5_mn = rtb_Switch_fz_idx_2 / d * rtb_Switch_fz_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S398>/Sum1' incorporates:
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S398>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
              [0];
            rtb_u_mm = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S398>/Divide' incorporates:
             *  Math: '<S399>/Square'
             *  Math: '<S400>/Square'
             *  Sqrt: '<S399>/Sqrt'
             *  Sqrt: '<S400>/Sqrt'
             *  Sum: '<S398>/Sum'
             *  Sum: '<S398>/Sum1'
             *  Sum: '<S399>/Sum of Elements'
             *  Sum: '<S400>/Sum of Elements'
             */
            rtb_Switch_fz_idx_1 = sqrtf(rtb_Switch_fz_idx_1 *
              rtb_Switch_fz_idx_1 + rtb_u_mm * rtb_u_mm) / sqrtf(rtb_Subtract3_d
              * rtb_Subtract3_d + d * d);

            /* Saturate: '<S398>/Saturation' */
            if (rtb_Switch_fz_idx_1 > 1.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              if (rtb_Switch_fz_idx_1 < 0.0F) {
                rtb_Switch_fz_idx_1 = 0.0F;
              }
            }

            /* End of Saturate: '<S398>/Saturation' */

            /* Product: '<S396>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
                rtb_Sign5_mn + rtb_Transpose[rtb_n] * rtb_Divide_or;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S389>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S398>/Multiply'
             *  SignalConversion: '<S41>/Signal Copy1'
             *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S389>/Sum2'
             *  Sum: '<S398>/Add'
             *  Sum: '<S398>/Subtract'
             */
            rtb_Switch_fz_idx_2 = (FMS_U.INS_Out.h_R -
              ((FMS_B.Cmd_In.sp_waypoint[2] - FMS_B.Cmd_In.cur_waypoint[2]) *
               rtb_Switch_fz_idx_1 + FMS_B.Cmd_In.cur_waypoint[2])) *
              FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_0 = rtb_MatrixConcatenate1_i_0[0];
            rtb_Switch_fz_idx_1 = rtb_MatrixConcatenate1_i_0[1];

            /* Saturate: '<S389>/Saturation1' incorporates:
             *  Product: '<S396>/Multiply'
             */
            if (rtb_Switch_fz_idx_2 > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_fz_idx_2 = FMS_PARAM.VEL_Z_LIM;
            } else {
              if (rtb_Switch_fz_idx_2 < -FMS_PARAM.VEL_Z_LIM) {
                rtb_Switch_fz_idx_2 = -FMS_PARAM.VEL_Z_LIM;
              }
            }

            /* End of Saturate: '<S389>/Saturation1' */
          }

          /* End of Switch: '<S372>/Switch' */

          /* Delay: '<S374>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S377>/Integrator1' incorporates:
           *  Delay: '<S374>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S381>/Rem' incorporates:
           *  Constant: '<S381>/Constant1'
           *  DiscreteIntegrator: '<S377>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  Sum: '<S376>/Sum'
           */
          rtb_Subtract3_d = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S381>/Switch' incorporates:
           *  Abs: '<S381>/Abs'
           *  Constant: '<S381>/Constant'
           *  Constant: '<S382>/Constant'
           *  Product: '<S381>/Multiply'
           *  RelationalOperator: '<S382>/Compare'
           *  Sum: '<S381>/Add'
           */
          if (fabsf(rtb_Subtract3_d) > 3.14159274F) {
            /* Signum: '<S381>/Sign' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_u_mm = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_u_mm = 1.0F;
            } else {
              rtb_u_mm = rtb_Subtract3_d;
            }

            /* End of Signum: '<S381>/Sign' */
            rtb_Subtract3_d -= 6.28318548F * rtb_u_mm;
          }

          /* End of Switch: '<S381>/Switch' */

          /* Gain: '<S376>/Gain2' */
          rtb_Subtract3_d *= FMS_PARAM.YAW_P;

          /* Saturate: '<S376>/Saturation' */
          if (rtb_Subtract3_d > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Subtract3_d = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Subtract3_d < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Subtract3_d = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S376>/Saturation' */

          /* BusAssignment: '<S370>/Bus Assignment' incorporates:
           *  Constant: '<S370>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_fz_idx_0;
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_fz_idx_1;
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_fz_idx_2;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_d;

          /* Math: '<S435>/Math Function1'
           *
           * About '<S435>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S435>/Math Function1' */

          /* Switch: '<S435>/Switch' incorporates:
           *  Constant: '<S435>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S435>/Product'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          if (rtb_Subtract3_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_0 = FMS_U.INS_Out.vn;
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_2 = rtb_Subtract3_d;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S435>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S370>/Sum' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_mn = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_P_dg[0] = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_P_dg[1] = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint
            [1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S388>/Math Function' incorporates:
           *  Sum: '<S370>/Sum'
           */
          rtb_Square_h[0] = rtb_Divide_or * rtb_Divide_or;
          rtb_Square_h[1] = rtb_Sign5_mn * rtb_Sign5_mn;

          /* Sum: '<S388>/Sum of Elements' */
          d = rtb_Square_h[0] + rtb_Square_h[1];

          /* Math: '<S388>/Math Function1' incorporates:
           *  Sum: '<S388>/Sum of Elements'
           *
           * About '<S388>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(d));
          } else {
            rtb_Subtract3_d = sqrtf(d);
          }

          /* End of Math: '<S388>/Math Function1' */

          /* Switch: '<S388>/Switch' incorporates:
           *  Constant: '<S388>/Constant'
           *  Product: '<S388>/Product'
           */
          if (rtb_Subtract3_d > 0.0F) {
            rtb_MathFunction_n_idx_2 = rtb_Subtract3_d;
          } else {
            rtb_Divide_or = 0.0F;
            rtb_Sign5_mn = 0.0F;
            rtb_MathFunction_n_idx_2 = 1.0F;
          }

          /* End of Switch: '<S388>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S394>/NearbyRefWP' incorporates:
           *  Constant: '<S370>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_dg, &d);

          /* MATLAB Function: '<S394>/SearchL1RefWP' incorporates:
           *  Constant: '<S370>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_Square_h, &rtb_u_mm);

          /* MATLAB Function: '<S394>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          D = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_l_idx_2 = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
                                * D + (FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Subtract3_d) / (rtb_Subtract3_d *
            rtb_Subtract3_d + D * D);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_2 <= 0.0F);
          rtb_LogicalOperator_oy = (rtb_Divide_l_idx_2 >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else if (rtb_LogicalOperator_oy) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = rtb_Divide_l_idx_2 * rtb_Subtract3_d +
              FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Switch: '<S394>/Switch1' incorporates:
           *  Constant: '<S428>/Constant'
           *  RelationalOperator: '<S428>/Compare'
           */
          if (d <= 0.0F) {
            /* Switch: '<S394>/Switch' incorporates:
             *  Constant: '<S427>/Constant'
             *  RelationalOperator: '<S427>/Compare'
             */
            if (rtb_u_mm >= 0.0F) {
              rtb_P_dg[0] = rtb_Square_h[0];
              rtb_P_dg[1] = rtb_Square_h[1];
            } else {
              rtb_P_dg[0] = rtb_Subtract3_d;

              /* MATLAB Function: '<S394>/OutRegionRegWP' incorporates:
               *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_P_dg[1] = FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              } else if (rtb_LogicalOperator_oy) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_P_dg[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              } else {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_P_dg[1] = rtb_Divide_l_idx_2 * D +
                  FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              }
            }

            /* End of Switch: '<S394>/Switch' */
          }

          /* End of Switch: '<S394>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S395>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          D = rtb_P_dg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S436>/Math Function' */
          rtb_P_cg[0] = D * D;
          rtb_u_mm = D;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S395>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          D = rtb_P_dg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S436>/Math Function' incorporates:
           *  Math: '<S434>/Square'
           */
          d = D * D;

          /* Sum: '<S436>/Sum of Elements' incorporates:
           *  Math: '<S436>/Math Function'
           */
          rtb_Divide_l_idx_2 = d + rtb_P_cg[0];

          /* Math: '<S436>/Math Function1' incorporates:
           *  Sum: '<S436>/Sum of Elements'
           *
           * About '<S436>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S436>/Math Function1' */

          /* Switch: '<S436>/Switch' incorporates:
           *  Constant: '<S436>/Constant'
           *  Product: '<S436>/Product'
           */
          if (rtb_Subtract3_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_u_mm;
            rtb_Switch_d0[1] = D;
            rtb_Switch_d0[2] = rtb_Subtract3_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S436>/Switch' */

          /* Product: '<S435>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S438>/Sum of Elements' incorporates:
           *  Math: '<S438>/Math Function'
           *  SignalConversion: '<S438>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

          /* Math: '<S438>/Math Function1' incorporates:
           *  Sum: '<S438>/Sum of Elements'
           *
           * About '<S438>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S438>/Math Function1' */

          /* Switch: '<S438>/Switch' incorporates:
           *  Constant: '<S438>/Constant'
           *  Product: '<S438>/Product'
           */
          if (rtb_Subtract3_d > 0.0F) {
            rtb_Switch_fz_idx_0 = rtb_P_cg[1];
            rtb_Switch_fz_idx_1 = rtb_P_cg[0];
            rtb_Switch_fz_idx_2 = rtb_Subtract3_d;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S438>/Switch' */

          /* Product: '<S436>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S439>/Sum of Elements' incorporates:
           *  Math: '<S439>/Math Function'
           *  SignalConversion: '<S439>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

          /* Math: '<S439>/Math Function1' incorporates:
           *  Sum: '<S439>/Sum of Elements'
           *
           * About '<S439>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S439>/Math Function1' */

          /* Switch: '<S439>/Switch' incorporates:
           *  Constant: '<S439>/Constant'
           *  Product: '<S439>/Product'
           */
          if (rtb_Subtract3_d > 0.0F) {
            rtb_Switch_d0[0] = rtb_P_cg[1];
            rtb_Switch_d0[1] = rtb_P_cg[0];
            rtb_Switch_d0[2] = rtb_Subtract3_d;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S439>/Switch' */

          /* Product: '<S439>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S438>/Divide' */
          rtb_P_dg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Product: '<S388>/Divide' */
          rtb_Square_h[0] = rtb_Divide_or / rtb_MathFunction_n_idx_2;
          rtb_u_mm *= rtb_u_mm;

          /* Product: '<S439>/Divide' incorporates:
           *  Math: '<S434>/Square'
           */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S438>/Divide' */
          rtb_P_dg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Product: '<S388>/Divide' */
          rtb_Square_h[1] = rtb_Sign5_mn / rtb_MathFunction_n_idx_2;

          /* Sum: '<S437>/Subtract' incorporates:
           *  Product: '<S437>/Multiply'
           *  Product: '<S437>/Multiply1'
           */
          rtb_Subtract3_d = rtb_P_cg[0] * rtb_P_dg[1] - rtb_P_cg[1] * rtb_P_dg[0];

          /* Signum: '<S432>/Sign1' */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Subtract3_d = -1.0F;
          } else {
            if (rtb_Subtract3_d > 0.0F) {
              rtb_Subtract3_d = 1.0F;
            }
          }

          /* End of Signum: '<S432>/Sign1' */

          /* Switch: '<S432>/Switch2' incorporates:
           *  Constant: '<S432>/Constant4'
           */
          if (rtb_Subtract3_d == 0.0F) {
            rtb_Subtract3_d = 1.0F;
          }

          /* End of Switch: '<S432>/Switch2' */

          /* DotProduct: '<S432>/Dot Product' */
          rtb_Divide_l_idx_2 = rtb_P_dg[0] * rtb_P_cg[0] + rtb_P_dg[1] *
            rtb_P_cg[1];

          /* Trigonometry: '<S432>/Acos' incorporates:
           *  DotProduct: '<S432>/Dot Product'
           */
          if (rtb_Divide_l_idx_2 > 1.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            }
          }

          /* Product: '<S432>/Multiply' incorporates:
           *  Trigonometry: '<S432>/Acos'
           */
          rtb_Subtract3_d *= acosf(rtb_Divide_l_idx_2);

          /* Saturate: '<S395>/Saturation' */
          if (rtb_Subtract3_d > 1.57079637F) {
            rtb_Subtract3_d = 1.57079637F;
          } else {
            if (rtb_Subtract3_d < -1.57079637F) {
              rtb_Subtract3_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S395>/Saturation' */

          /* Product: '<S395>/Divide' incorporates:
           *  Constant: '<S370>/L1'
           *  Constant: '<S395>/Constant'
           *  Gain: '<S395>/Gain'
           *  Math: '<S395>/Square'
           *  MinMax: '<S395>/Max'
           *  MinMax: '<S395>/Min'
           *  Product: '<S395>/Multiply1'
           *  Sqrt: '<S434>/Sqrt'
           *  Sum: '<S434>/Sum of Elements'
           *  Trigonometry: '<S395>/Sin'
           */
          rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_Subtract3_d) *
            (rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(d + rtb_u_mm), 0.5F));

          /* Sum: '<S386>/Subtract' incorporates:
           *  Product: '<S386>/Multiply'
           *  Product: '<S386>/Multiply1'
           */
          rtb_Switch_fz_idx_1 = rtb_Square_h[0] * FMS_ConstB.Divide[1] -
            rtb_Square_h[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S375>/Sign1' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S375>/Sign1' */

          /* Switch: '<S375>/Switch2' incorporates:
           *  Constant: '<S375>/Constant4'
           */
          if (rtb_Switch_fz_idx_1 == 0.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          }

          /* End of Switch: '<S375>/Switch2' */

          /* DotProduct: '<S375>/Dot Product' */
          d = FMS_ConstB.Divide[0] * rtb_Square_h[0] + FMS_ConstB.Divide[1] *
            rtb_Square_h[1];

          /* Trigonometry: '<S375>/Acos' incorporates:
           *  DotProduct: '<S375>/Dot Product'
           */
          if (d > 1.0F) {
            d = 1.0F;
          } else {
            if (d < -1.0F) {
              d = -1.0F;
            }
          }

          /* Product: '<S375>/Multiply' incorporates:
           *  Trigonometry: '<S375>/Acos'
           */
          rtb_Switch_fz_idx_1 *= acosf(d);

          /* Math: '<S378>/Rem' incorporates:
           *  Constant: '<S378>/Constant1'
           *  Delay: '<S374>/Delay'
           *  Sum: '<S374>/Sum2'
           */
          rtb_Subtract3_d = rt_remf(rtb_Switch_fz_idx_1 - FMS_DW.Delay_DSTATE_n,
            6.28318548F);

          /* Switch: '<S378>/Switch' incorporates:
           *  Abs: '<S378>/Abs'
           *  Constant: '<S378>/Constant'
           *  Constant: '<S384>/Constant'
           *  Product: '<S378>/Multiply'
           *  RelationalOperator: '<S384>/Compare'
           *  Sum: '<S378>/Add'
           */
          if (fabsf(rtb_Subtract3_d) > 3.14159274F) {
            /* Signum: '<S378>/Sign' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = rtb_Subtract3_d;
            }

            /* End of Signum: '<S378>/Sign' */
            rtb_Subtract3_d -= 6.28318548F * rtb_Divide_l_idx_2;
          }

          /* End of Switch: '<S378>/Switch' */

          /* Sum: '<S374>/Sum' incorporates:
           *  Delay: '<S374>/Delay'
           */
          rtb_Divide_l_idx_2 = rtb_Subtract3_d + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S383>/Multiply1' incorporates:
           *  Constant: '<S383>/const1'
           *  DiscreteIntegrator: '<S377>/Integrator'
           */
          rtb_Subtract3_d = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S383>/Add' incorporates:
           *  DiscreteIntegrator: '<S377>/Integrator1'
           *  Sum: '<S377>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_mf -
                                rtb_Divide_l_idx_2) + rtb_Subtract3_d;

          /* Signum: '<S383>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3;
          }

          /* End of Signum: '<S383>/Sign' */

          /* Sum: '<S383>/Add2' incorporates:
           *  Abs: '<S383>/Abs'
           *  Gain: '<S383>/Gain'
           *  Gain: '<S383>/Gain1'
           *  Product: '<S383>/Multiply2'
           *  Product: '<S383>/Multiply3'
           *  Sqrt: '<S383>/Sqrt'
           *  Sum: '<S383>/Add1'
           *  Sum: '<S383>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_m) *
                     FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_Subtract3_d;

          /* Sum: '<S383>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Subtract3_d;

          /* Sum: '<S383>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_m;

          /* Sum: '<S383>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_m;

          /* Signum: '<S383>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S383>/Sign1' */

          /* Signum: '<S383>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S383>/Sign2' */

          /* Sum: '<S383>/Add5' incorporates:
           *  Gain: '<S383>/Gain2'
           *  Product: '<S383>/Multiply4'
           *  Sum: '<S383>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Sum: '<S383>/Add6' */
          rtb_Divide_l_idx_2 = d + FMS_ConstB.d_m;

          /* Sum: '<S383>/Subtract3' */
          rtb_u_mm = d - FMS_ConstB.d_m;

          /* Product: '<S383>/Divide' */
          rtb_Switch_fz_idx_2 = d / FMS_ConstB.d_m;

          /* Signum: '<S383>/Sign5' incorporates:
           *  Signum: '<S383>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S383>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S383>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = d;

            /* Signum: '<S383>/Sign6' */
            rtb_Divide_l_idx_3 = d;
          }

          /* End of Signum: '<S383>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S374>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
           */
          rtb_Switch_fz_idx_1 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S379>/Rem' incorporates:
           *  Constant: '<S379>/Constant1'
           */
          d = rt_remf(rtb_Switch_fz_idx_1, 6.28318548F);

          /* Switch: '<S379>/Switch' incorporates:
           *  Abs: '<S379>/Abs'
           *  Constant: '<S379>/Constant'
           *  Constant: '<S385>/Constant'
           *  Product: '<S379>/Multiply'
           *  RelationalOperator: '<S385>/Compare'
           *  Sum: '<S379>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S379>/Sign' */
            if (d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = d;
            }

            /* End of Signum: '<S379>/Sign' */
            d -= 6.28318548F * rtb_Switch_fz_idx_1;
          }

          /* End of Switch: '<S379>/Switch' */

          /* Abs: '<S372>/Abs' */
          d = fabsf(d);

          /* Update for Delay: '<S396>/Delay' */
          FMS_DW.icLoad = 0U;

          /* Update for DiscreteIntegrator: '<S397>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S390>/Constant'
           *  RelationalOperator: '<S390>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = (uint8_T)((uint32_T)(d <=
            0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTAT_kd);
          if (FMS_DW.DiscreteTimeIntegrator_DSTAT_kd >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTAT_kd <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S397>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S392>/Acceleration_Speed' incorporates:
           *  Constant: '<S392>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S392>/Acceleration_Speed' */

          /* Product: '<S396>/Divide1' incorporates:
           *  Constant: '<S396>/Constant'
           */
          d = rtb_Switch_fz_idx_0 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S396>/Saturation' */
          if (d > 0.314159274F) {
            d = 0.314159274F;
          } else {
            if (d < -0.314159274F) {
              d = -0.314159274F;
            }
          }

          /* End of Saturate: '<S396>/Saturation' */

          /* Update for DiscreteIntegrator: '<S441>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * d;

          /* Update for Delay: '<S374>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S377>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S377>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S383>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S383>/Sign3' */

          /* Signum: '<S383>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S383>/Sign4' */

          /* Update for DiscreteIntegrator: '<S377>/Integrator' incorporates:
           *  Constant: '<S383>/const'
           *  Gain: '<S383>/Gain3'
           *  Product: '<S383>/Multiply5'
           *  Product: '<S383>/Multiply6'
           *  Sum: '<S383>/Subtract4'
           *  Sum: '<S383>/Subtract5'
           *  Sum: '<S383>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_cu * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S377>/Integrator' */
          /* End of Outputs for SubSystem: '<S366>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S369>/Delay Input1' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S369>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S254>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S254>/Unknown' incorporates:
           *  ActionPort: '<S368>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S254>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S48>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S48>/Assist' incorporates:
         *  ActionPort: '<S253>/Action Port'
         */
        /* SwitchCase: '<S253>/Switch Case' */
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
            /* Disable for SwitchCase: '<S353>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S268>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S286>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S302>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S327>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S314>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S253>/Acro' incorporates:
           *  ActionPort: '<S258>/Action Port'
           */
          /* BusAssignment: '<S258>/Bus Assignment' incorporates:
           *  Constant: '<S258>/Constant'
           *  Gain: '<S263>/Gain'
           *  Gain: '<S263>/Gain1'
           *  Gain: '<S263>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_c;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
          FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
          FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

          /* Saturate: '<S264>/Saturation' incorporates:
           *  Constant: '<S264>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           *  Sum: '<S264>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            d = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S264>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S258>/Bus Assignment' incorporates:
           *  Constant: '<S264>/Constant5'
           *  Gain: '<S264>/Gain2'
           *  Sum: '<S264>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            d), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S253>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S253>/Stabilize' incorporates:
             *  ActionPort: '<S261>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S253>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S349>/Integrator'
             *  DiscreteIntegrator: '<S349>/Integrator1'
             *  DiscreteIntegrator: '<S350>/Integrator'
             *  DiscreteIntegrator: '<S350>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S253>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S253>/Stabilize' incorporates:
             *  ActionPort: '<S261>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S253>/Switch Case' incorporates:
             *  Chart: '<S354>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S253>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S253>/Stabilize' incorporates:
           *  ActionPort: '<S261>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S344>/Logical Operator' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S354>/Motion State' incorporates:
           *  Abs: '<S354>/Abs'
           *  Abs: '<S354>/Abs1'
           *  Constant: '<S364>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S364>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S353>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S353>/Hold Control' incorporates:
               *  ActionPort: '<S356>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S353>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S353>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S353>/Hold Control' incorporates:
             *  ActionPort: '<S356>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S353>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S353>/Brake Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S353>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S353>/Move Control' incorporates:
               *  ActionPort: '<S357>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S353>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S353>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S353>/Move Control' incorporates:
             *  ActionPort: '<S357>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S353>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S353>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S346>/Switch' incorporates:
           *  Constant: '<S346>/Constant'
           *  Constant: '<S346>/Constant4'
           *  Constant: '<S346>/Constant5'
           *  Gain: '<S346>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S346>/Saturation'
           *  SignalConversion: '<S41>/Signal Copy2'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S346>/Add'
           *  Sum: '<S346>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_DataTypeConversion_o = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S346>/Saturation' */
              d = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S346>/Saturation' */
              d = 0.0F;
            } else {
              /* Saturate: '<S346>/Saturation' incorporates:
               *  Constant: '<S346>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S41>/Signal Copy2'
               *  Sum: '<S346>/Sum'
               */
              d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_DataTypeConversion_o = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              d), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S346>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S261>/Bus Assignment' incorporates:
           *  Constant: '<S261>/Constant'
           *  DataTypeConversion: '<S344>/Data Type Conversion'
           *  DiscreteIntegrator: '<S349>/Integrator1'
           *  DiscreteIntegrator: '<S350>/Integrator1'
           *  Product: '<S344>/Multiply'
           *  Product: '<S344>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S353>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S261>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S261>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S261>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S353>/Saturation' */

          /* BusAssignment: '<S261>/Bus Assignment' */
          FMS_Y.FMS_Out.throttle_cmd = rtb_DataTypeConversion_o;

          /* Product: '<S352>/Multiply1' incorporates:
           *  Constant: '<S352>/const1'
           *  DiscreteIntegrator: '<S350>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S348>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S348>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S352>/Add' incorporates:
           *  DiscreteIntegrator: '<S350>/Integrator1'
           *  Gain: '<S344>/Gain1'
           *  Gain: '<S348>/Gain'
           *  Sum: '<S350>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * d * -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S352>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S352>/Sign' */

          /* Sum: '<S352>/Add2' incorporates:
           *  Abs: '<S352>/Abs'
           *  Gain: '<S352>/Gain'
           *  Gain: '<S352>/Gain1'
           *  Product: '<S352>/Multiply2'
           *  Product: '<S352>/Multiply3'
           *  Sqrt: '<S352>/Sqrt'
           *  Sum: '<S352>/Add1'
           *  Sum: '<S352>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S352>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1) +
            rtb_Sign5_mn;

          /* Sum: '<S352>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_0 + FMS_ConstB.d_g;

          /* Sum: '<S352>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_g;

          /* Signum: '<S352>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S352>/Sign1' */

          /* Signum: '<S352>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S352>/Sign2' */

          /* Sum: '<S352>/Add5' incorporates:
           *  Gain: '<S352>/Gain2'
           *  Product: '<S352>/Multiply4'
           *  Sum: '<S352>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_0) *
            0.5F * rtb_Divide_l_idx_3;

          /* Sum: '<S352>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 + FMS_ConstB.d_g;

          /* Sum: '<S352>/Subtract3' */
          rtb_u_mm = rtb_Switch_fz_idx_1 - FMS_ConstB.d_g;

          /* Product: '<S352>/Divide' */
          rtb_Switch_fz_idx_2 = rtb_Switch_fz_idx_1 / FMS_ConstB.d_g;

          /* Signum: '<S352>/Sign5' incorporates:
           *  Signum: '<S352>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S352>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S352>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Switch_fz_idx_1;

            /* Signum: '<S352>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S352>/Sign5' */

          /* Product: '<S351>/Multiply1' incorporates:
           *  Constant: '<S351>/const1'
           *  DiscreteIntegrator: '<S349>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S347>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S347>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S351>/Add' incorporates:
           *  DiscreteIntegrator: '<S349>/Integrator1'
           *  Gain: '<S344>/Gain'
           *  Gain: '<S347>/Gain'
           *  Sum: '<S349>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S351>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S351>/Sign' */

          /* Sum: '<S351>/Add2' incorporates:
           *  Abs: '<S351>/Abs'
           *  Gain: '<S351>/Gain'
           *  Gain: '<S351>/Gain1'
           *  Product: '<S351>/Multiply2'
           *  Product: '<S351>/Multiply3'
           *  Sqrt: '<S351>/Sqrt'
           *  Sum: '<S351>/Add1'
           *  Sum: '<S351>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S351>/Add4' */
          rtb_Sign5_mn += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1;

          /* Sum: '<S351>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_a;

          /* Sum: '<S351>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_a;

          /* Signum: '<S351>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S351>/Sign1' */

          /* Signum: '<S351>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S351>/Sign2' */

          /* Sum: '<S351>/Add5' incorporates:
           *  Gain: '<S351>/Gain2'
           *  Product: '<S351>/Multiply4'
           *  Sum: '<S351>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (d - rtb_Switch_fz_idx_0) * 0.5F * rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S349>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S349>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S350>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S350>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S352>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S352>/Sign3' */

          /* Signum: '<S352>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S352>/Sign4' */

          /* Update for DiscreteIntegrator: '<S350>/Integrator' incorporates:
           *  Constant: '<S352>/const'
           *  Gain: '<S352>/Gain3'
           *  Product: '<S352>/Multiply5'
           *  Product: '<S352>/Multiply6'
           *  Sum: '<S352>/Subtract4'
           *  Sum: '<S352>/Subtract5'
           *  Sum: '<S352>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_o * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 12.566371F) * 0.004F;

          /* Sum: '<S351>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 - FMS_ConstB.d_a;

          /* Sum: '<S351>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_1 + FMS_ConstB.d_a;

          /* Signum: '<S351>/Sign5' incorporates:
           *  Signum: '<S351>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S351>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S351>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;

            /* Signum: '<S351>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S351>/Sign5' */

          /* Signum: '<S351>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S351>/Sign3' */

          /* Signum: '<S351>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S351>/Sign4' */

          /* Update for DiscreteIntegrator: '<S349>/Integrator' incorporates:
           *  Constant: '<S351>/const'
           *  Gain: '<S351>/Gain3'
           *  Product: '<S351>/Divide'
           *  Product: '<S351>/Multiply5'
           *  Product: '<S351>/Multiply6'
           *  Sum: '<S351>/Subtract4'
           *  Sum: '<S351>/Subtract5'
           *  Sum: '<S351>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_a -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_k * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S253>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S253>/Altitude' incorporates:
             *  ActionPort: '<S259>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S253>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S282>/Integrator'
             *  DiscreteIntegrator: '<S282>/Integrator1'
             *  DiscreteIntegrator: '<S283>/Integrator'
             *  DiscreteIntegrator: '<S283>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S253>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S253>/Altitude' incorporates:
             *  ActionPort: '<S259>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S253>/Switch Case' incorporates:
             *  Chart: '<S269>/Motion Status'
             *  Chart: '<S287>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S253>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S253>/Altitude' incorporates:
           *  ActionPort: '<S259>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S269>/Motion Status' incorporates:
           *  Abs: '<S269>/Abs'
           *  Abs: '<S269>/Abs1'
           *  Constant: '<S278>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S278>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S268>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S268>/Hold Control' incorporates:
               *  ActionPort: '<S271>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S268>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S268>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S268>/Hold Control' incorporates:
             *  ActionPort: '<S271>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S268>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S268>/Brake Control' incorporates:
             *  ActionPort: '<S270>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S268>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S268>/Move Control' incorporates:
             *  ActionPort: '<S272>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S268>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S268>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S265>/Switch' incorporates:
           *  Constant: '<S265>/Constant'
           *  Saturate: '<S268>/Saturation1'
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Divide_l_idx_2 = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S268>/Saturation1' */
            rtb_Divide_l_idx_2 = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S268>/Saturation1' */
            rtb_Divide_l_idx_2 = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S268>/Saturation1' */
            rtb_Divide_l_idx_2 = FMS_B.Merge_l;
          }

          /* End of Switch: '<S265>/Switch' */

          /* Logic: '<S266>/Logical Operator' incorporates:
           *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S287>/Motion State' incorporates:
           *  Abs: '<S287>/Abs'
           *  Abs: '<S287>/Abs1'
           *  Constant: '<S297>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S297>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S286>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S286>/Hold Control' incorporates:
               *  ActionPort: '<S289>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S286>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S286>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S286>/Hold Control' incorporates:
             *  ActionPort: '<S289>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S286>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S286>/Brake Control' incorporates:
             *  ActionPort: '<S288>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S286>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S286>/Move Control' incorporates:
               *  ActionPort: '<S290>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S286>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S286>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S286>/Move Control' incorporates:
             *  ActionPort: '<S290>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S286>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S286>/Switch Case' */

          /* BusAssignment: '<S259>/Bus Assignment' incorporates:
           *  Constant: '<S259>/Constant'
           *  DataTypeConversion: '<S266>/Data Type Conversion'
           *  DiscreteIntegrator: '<S282>/Integrator1'
           *  DiscreteIntegrator: '<S283>/Integrator1'
           *  Product: '<S266>/Multiply'
           *  Product: '<S266>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S286>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S259>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S286>/Saturation' */

          /* BusAssignment: '<S259>/Bus Assignment' */
          FMS_Y.FMS_Out.w_cmd = rtb_Divide_l_idx_2;

          /* Product: '<S285>/Multiply1' incorporates:
           *  Constant: '<S285>/const1'
           *  DiscreteIntegrator: '<S283>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S281>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S281>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S285>/Add' incorporates:
           *  DiscreteIntegrator: '<S283>/Integrator1'
           *  Gain: '<S266>/Gain1'
           *  Gain: '<S281>/Gain'
           *  Sum: '<S283>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * d * -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S285>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S285>/Sign' */

          /* Sum: '<S285>/Add2' incorporates:
           *  Abs: '<S285>/Abs'
           *  Gain: '<S285>/Gain'
           *  Gain: '<S285>/Gain1'
           *  Product: '<S285>/Multiply2'
           *  Product: '<S285>/Multiply3'
           *  Sqrt: '<S285>/Sqrt'
           *  Sum: '<S285>/Add1'
           *  Sum: '<S285>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S285>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1) +
            rtb_Sign5_mn;

          /* Sum: '<S285>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_0 + FMS_ConstB.d_o;

          /* Sum: '<S285>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_o;

          /* Signum: '<S285>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S285>/Sign1' */

          /* Signum: '<S285>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S285>/Sign2' */

          /* Sum: '<S285>/Add5' incorporates:
           *  Gain: '<S285>/Gain2'
           *  Product: '<S285>/Multiply4'
           *  Sum: '<S285>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_0) *
            0.5F * rtb_Divide_l_idx_3;

          /* Sum: '<S285>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 + FMS_ConstB.d_o;

          /* Sum: '<S285>/Subtract3' */
          rtb_u_mm = rtb_Switch_fz_idx_1 - FMS_ConstB.d_o;

          /* Product: '<S285>/Divide' */
          rtb_Switch_fz_idx_2 = rtb_Switch_fz_idx_1 / FMS_ConstB.d_o;

          /* Signum: '<S285>/Sign5' incorporates:
           *  Signum: '<S285>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S285>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S285>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Switch_fz_idx_1;

            /* Signum: '<S285>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S285>/Sign5' */

          /* Product: '<S284>/Multiply1' incorporates:
           *  Constant: '<S284>/const1'
           *  DiscreteIntegrator: '<S282>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S280>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S280>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S284>/Add' incorporates:
           *  DiscreteIntegrator: '<S282>/Integrator1'
           *  Gain: '<S266>/Gain'
           *  Gain: '<S280>/Gain'
           *  Sum: '<S282>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S284>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S284>/Sign' */

          /* Sum: '<S284>/Add2' incorporates:
           *  Abs: '<S284>/Abs'
           *  Gain: '<S284>/Gain'
           *  Gain: '<S284>/Gain1'
           *  Product: '<S284>/Multiply2'
           *  Product: '<S284>/Multiply3'
           *  Sqrt: '<S284>/Sqrt'
           *  Sum: '<S284>/Add1'
           *  Sum: '<S284>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S284>/Add4' */
          rtb_Sign5_mn += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1;

          /* Sum: '<S284>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_c;

          /* Sum: '<S284>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_c;

          /* Signum: '<S284>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S284>/Sign1' */

          /* Signum: '<S284>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S284>/Sign2' */

          /* Sum: '<S284>/Add5' incorporates:
           *  Gain: '<S284>/Gain2'
           *  Product: '<S284>/Multiply4'
           *  Sum: '<S284>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (d - rtb_Switch_fz_idx_0) * 0.5F * rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S282>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S282>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S283>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S283>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S285>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S285>/Sign3' */

          /* Signum: '<S285>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S285>/Sign4' */

          /* Update for DiscreteIntegrator: '<S283>/Integrator' incorporates:
           *  Constant: '<S285>/const'
           *  Gain: '<S285>/Gain3'
           *  Product: '<S285>/Multiply5'
           *  Product: '<S285>/Multiply6'
           *  Sum: '<S285>/Subtract4'
           *  Sum: '<S285>/Subtract5'
           *  Sum: '<S285>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 12.566371F) * 0.004F;

          /* Sum: '<S284>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 - FMS_ConstB.d_c;

          /* Sum: '<S284>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_1 + FMS_ConstB.d_c;

          /* Signum: '<S284>/Sign5' incorporates:
           *  Signum: '<S284>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S284>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S284>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;

            /* Signum: '<S284>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S284>/Sign5' */

          /* Signum: '<S284>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S284>/Sign3' */

          /* Signum: '<S284>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S284>/Sign4' */

          /* Update for DiscreteIntegrator: '<S282>/Integrator' incorporates:
           *  Constant: '<S284>/const'
           *  Gain: '<S284>/Gain3'
           *  Product: '<S284>/Divide'
           *  Product: '<S284>/Multiply5'
           *  Product: '<S284>/Multiply6'
           *  Sum: '<S284>/Subtract4'
           *  Sum: '<S284>/Subtract5'
           *  Sum: '<S284>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_c -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_h * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S253>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S253>/Position' incorporates:
             *  ActionPort: '<S260>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S253>/Switch Case' incorporates:
             *  Chart: '<S303>/Motion Status'
             *  Chart: '<S315>/Motion State'
             *  Chart: '<S328>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S253>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S253>/Position' incorporates:
           *  ActionPort: '<S260>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S303>/Motion Status' incorporates:
           *  Abs: '<S303>/Abs'
           *  Abs: '<S303>/Abs1'
           *  Constant: '<S312>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S312>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S302>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S302>/Hold Control' incorporates:
               *  ActionPort: '<S305>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S302>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S302>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S302>/Hold Control' incorporates:
             *  ActionPort: '<S305>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S302>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S302>/Brake Control' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S302>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S302>/Move Control' incorporates:
             *  ActionPort: '<S306>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S302>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S302>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S315>/Motion State' incorporates:
           *  Abs: '<S315>/Abs'
           *  Abs: '<S315>/Abs1'
           *  Constant: '<S325>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S325>/Compare'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S328>/Logical Operator' incorporates:
           *  Abs: '<S328>/Abs1'
           *  Abs: '<S328>/Abs2'
           *  Constant: '<S341>/Constant'
           *  Constant: '<S342>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S341>/Compare'
           *  RelationalOperator: '<S342>/Compare'
           *  SignalConversion: '<S41>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S328>/Motion State' */
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
              if ((rtb_Divide_l_idx_3 <= 0.2) || (FMS_DW.temporalCounter_i1_g >=
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

          /* End of Chart: '<S328>/Motion State' */

          /* SwitchCase: '<S327>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S41>/Signal Copy1'
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
              /* SystemReset for IfAction SubSystem: '<S327>/Hold Control' incorporates:
               *  ActionPort: '<S330>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S327>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_jz);

              /* End of SystemReset for SubSystem: '<S327>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S327>/Hold Control' incorporates:
             *  ActionPort: '<S330>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge,
                              &FMS_ConstB.HoldControl_jz, &FMS_DW.HoldControl_jz);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S327>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S327>/Brake Control' incorporates:
             *  ActionPort: '<S329>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge);

            /* End of Outputs for SubSystem: '<S327>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S327>/Move Control' incorporates:
               *  ActionPort: '<S331>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S327>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S337>/Integrator'
               *  DiscreteIntegrator: '<S337>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S327>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S327>/Move Control' incorporates:
             *  ActionPort: '<S331>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S335>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S41>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              d = 0.0F;
            } else {
              d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S335>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S335>/Gain' */
            rtb_u_mm = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * d;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S336>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S41>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              d = 0.0F;
            } else {
              d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S336>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S336>/Gain' */
            rtb_Switch_fz_idx_0 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * d;

            /* Sum: '<S338>/Sum of Elements' incorporates:
             *  Math: '<S338>/Square'
             *  SignalConversion: '<S338>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S339>/Sum of Elements'
             *  Switch: '<S331>/Switch'
             */
            d = rtb_u_mm * rtb_u_mm + rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0;

            /* Switch: '<S331>/Switch' incorporates:
             *  Product: '<S339>/Divide'
             *  Sqrt: '<S338>/Sqrt'
             *  Sum: '<S338>/Sum of Elements'
             */
            if (sqrtf(d) > 1.0F) {
              /* Math: '<S339>/Math Function1'
               *
               * About '<S339>/Math Function1':
               *  Operator: sqrt
               */
              if (d < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(d);
              }

              /* End of Math: '<S339>/Math Function1' */

              /* Switch: '<S339>/Switch' incorporates:
               *  Constant: '<S339>/Constant'
               *  Product: '<S339>/Product'
               */
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Switch_d0[0] = rtb_u_mm;
                rtb_Switch_d0[1] = rtb_Switch_fz_idx_0;
                rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
              } else {
                rtb_Switch_d0[0] = 0.0F;
                rtb_Switch_d0[1] = 0.0F;
                rtb_Switch_d0[2] = 1.0F;
              }

              /* End of Switch: '<S339>/Switch' */
              rtb_u_mm = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_Switch_fz_idx_0 = rtb_Switch_d0[1] / rtb_Switch_d0[2];
            }

            /* Product: '<S340>/Multiply1' incorporates:
             *  Constant: '<S340>/const1'
             *  DiscreteIntegrator: '<S337>/Integrator'
             */
            rtb_Switch_fz_idx_1 = FMS_DW.Integrator_DSTATE[0] * 0.05F;

            /* Sum: '<S340>/Add' incorporates:
             *  DiscreteIntegrator: '<S337>/Integrator1'
             *  Gain: '<S331>/Gain6'
             *  Sum: '<S337>/Subtract'
             */
            D = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM * rtb_u_mm)
              + rtb_Switch_fz_idx_1;

            /* Signum: '<S340>/Sign' */
            if (D < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (D > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = D;
            }

            /* Sum: '<S340>/Add2' incorporates:
             *  Abs: '<S340>/Abs'
             *  Gain: '<S340>/Gain'
             *  Gain: '<S340>/Gain1'
             *  Product: '<S340>/Multiply2'
             *  Product: '<S340>/Multiply3'
             *  Sqrt: '<S340>/Sqrt'
             *  Sum: '<S340>/Add1'
             *  Sum: '<S340>/Subtract'
             */
            rtb_Subtract3_d = (sqrtf((8.0F * fabsf(D) + FMS_ConstB.d) *
              FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Divide_l_idx_2 +
              rtb_Switch_fz_idx_1;

            /* Sum: '<S340>/Add4' */
            rtb_Switch_fz_idx_1 += D - rtb_Subtract3_d;

            /* Sum: '<S340>/Add3' */
            rtb_Divide_l_idx_2 = D + FMS_ConstB.d;

            /* Sum: '<S340>/Subtract1' */
            D -= FMS_ConstB.d;

            /* Signum: '<S340>/Sign1' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S340>/Sign2' */
            if (D < 0.0F) {
              D = -1.0F;
            } else {
              if (D > 0.0F) {
                D = 1.0F;
              }
            }

            /* Sum: '<S340>/Add5' incorporates:
             *  Gain: '<S340>/Gain2'
             *  Product: '<S340>/Multiply4'
             *  Sum: '<S340>/Subtract2'
             */
            rtb_Subtract3_d += (rtb_Divide_l_idx_2 - D) * 0.5F *
              rtb_Switch_fz_idx_1;

            /* SignalConversion: '<S337>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S337>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S337>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S337>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S340>/Sign4' incorporates:
             *  Sum: '<S340>/Subtract3'
             */
            rtb_Divide_l_idx_2 = rtb_Subtract3_d - FMS_ConstB.d;

            /* Signum: '<S340>/Sign3' incorporates:
             *  Sum: '<S340>/Add6'
             */
            rtb_u_mm = rtb_Subtract3_d + FMS_ConstB.d;

            /* Signum: '<S340>/Sign5' */
            if (rtb_Subtract3_d < 0.0F) {
              d = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_Subtract3_d;
            }

            /* Signum: '<S340>/Sign3' */
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = -1.0F;
            } else {
              if (rtb_u_mm > 0.0F) {
                rtb_u_mm = 1.0F;
              }
            }

            /* Signum: '<S340>/Sign4' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S340>/Sign6' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = rtb_Subtract3_d;
            }

            /* Update for DiscreteIntegrator: '<S337>/Integrator' incorporates:
             *  Constant: '<S340>/const'
             *  Gain: '<S340>/Gain3'
             *  Product: '<S340>/Divide'
             *  Product: '<S340>/Multiply5'
             *  Product: '<S340>/Multiply6'
             *  Sum: '<S340>/Subtract4'
             *  Sum: '<S340>/Subtract5'
             *  Sum: '<S340>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Subtract3_d / FMS_ConstB.d - d)
              * FMS_ConstB.Gain4 * ((rtb_u_mm - rtb_Divide_l_idx_2) * 0.5F) -
              rtb_Switch_fz_idx_1 * 58.836F) * 0.004F;

            /* Product: '<S340>/Multiply1' incorporates:
             *  Constant: '<S340>/const1'
             *  DiscreteIntegrator: '<S337>/Integrator'
             */
            rtb_Switch_fz_idx_1 = FMS_DW.Integrator_DSTATE[1] * 0.05F;

            /* Sum: '<S340>/Add' incorporates:
             *  DiscreteIntegrator: '<S337>/Integrator1'
             *  Gain: '<S331>/Gain6'
             *  Sum: '<S337>/Subtract'
             */
            D = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                 rtb_Switch_fz_idx_0) + rtb_Switch_fz_idx_1;

            /* Signum: '<S340>/Sign' */
            if (D < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (D > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = D;
            }

            /* Sum: '<S340>/Add2' incorporates:
             *  Abs: '<S340>/Abs'
             *  Gain: '<S340>/Gain'
             *  Gain: '<S340>/Gain1'
             *  Product: '<S340>/Multiply2'
             *  Product: '<S340>/Multiply3'
             *  Sqrt: '<S340>/Sqrt'
             *  Sum: '<S340>/Add1'
             *  Sum: '<S340>/Subtract'
             */
            rtb_Subtract3_d = (sqrtf((8.0F * fabsf(D) + FMS_ConstB.d) *
              FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Divide_l_idx_2 +
              rtb_Switch_fz_idx_1;

            /* Sum: '<S340>/Add4' */
            rtb_Switch_fz_idx_1 += D - rtb_Subtract3_d;

            /* Sum: '<S340>/Add3' */
            rtb_Divide_l_idx_2 = D + FMS_ConstB.d;

            /* Sum: '<S340>/Subtract1' */
            D -= FMS_ConstB.d;

            /* Signum: '<S340>/Sign1' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S340>/Sign2' */
            if (D < 0.0F) {
              D = -1.0F;
            } else {
              if (D > 0.0F) {
                D = 1.0F;
              }
            }

            /* Sum: '<S340>/Add5' incorporates:
             *  Gain: '<S340>/Gain2'
             *  Product: '<S340>/Multiply4'
             *  Sum: '<S340>/Subtract2'
             */
            rtb_Subtract3_d += (rtb_Divide_l_idx_2 - D) * 0.5F *
              rtb_Switch_fz_idx_1;

            /* SignalConversion: '<S337>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S337>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S337>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S337>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S340>/Sign4' incorporates:
             *  Sum: '<S340>/Subtract3'
             */
            rtb_Divide_l_idx_2 = rtb_Subtract3_d - FMS_ConstB.d;

            /* Signum: '<S340>/Sign3' incorporates:
             *  Sum: '<S340>/Add6'
             */
            rtb_u_mm = rtb_Subtract3_d + FMS_ConstB.d;

            /* Signum: '<S340>/Sign5' */
            if (rtb_Subtract3_d < 0.0F) {
              d = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_Subtract3_d;
            }

            /* Signum: '<S340>/Sign3' */
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = -1.0F;
            } else {
              if (rtb_u_mm > 0.0F) {
                rtb_u_mm = 1.0F;
              }
            }

            /* Signum: '<S340>/Sign4' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S340>/Sign6' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = rtb_Subtract3_d;
            }

            /* Update for DiscreteIntegrator: '<S337>/Integrator' incorporates:
             *  Constant: '<S340>/const'
             *  Gain: '<S340>/Gain3'
             *  Product: '<S340>/Divide'
             *  Product: '<S340>/Multiply5'
             *  Product: '<S340>/Multiply6'
             *  Sum: '<S340>/Subtract4'
             *  Sum: '<S340>/Subtract5'
             *  Sum: '<S340>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Subtract3_d / FMS_ConstB.d - d)
              * FMS_ConstB.Gain4 * ((rtb_u_mm - rtb_Divide_l_idx_2) * 0.5F) -
              rtb_Switch_fz_idx_1 * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S327>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S327>/Switch Case' */

          /* SwitchCase: '<S314>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S41>/Signal Copy1'
           *  SignalConversion: '<S41>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S314>/Hold Control' incorporates:
               *  ActionPort: '<S317>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S314>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S314>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S314>/Hold Control' incorporates:
             *  ActionPort: '<S317>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S314>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S314>/Brake Control' incorporates:
             *  ActionPort: '<S316>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S314>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S314>/Move Control' incorporates:
               *  ActionPort: '<S318>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S314>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S314>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S314>/Move Control' incorporates:
             *  ActionPort: '<S318>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S314>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S314>/Switch Case' */

          /* BusAssignment: '<S260>/Bus Assignment' incorporates:
           *  Constant: '<S260>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S314>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S314>/Saturation' */

          /* Saturate: '<S327>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S327>/Saturation1' */

          /* Saturate: '<S302>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S302>/Saturation1' */
          /* End of Outputs for SubSystem: '<S253>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S253>/Unknown' incorporates:
           *  ActionPort: '<S262>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S253>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S48>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S48>/Manual' incorporates:
         *  ActionPort: '<S255>/Action Port'
         */
        /* BusAssignment: '<S255>/Bus Assignment' incorporates:
         *  Constant: '<S255>/Constant'
         *  Constant: '<S255>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S48>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S48>/Unknown' incorporates:
         *  ActionPort: '<S257>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S48>/Unknown' */
        break;
      }

      /* End of Outputs for SubSystem: '<S42>/MC_Mode' */
      break;
    }

    /* End of Outputs for SubSystem: '<S40>/Arm' */
    break;
  }

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* BusAssignment: '<S43>/Bus Assignment' incorporates:
   *  Constant: '<S43>/Constant'
   *  DataStoreRead: '<S43>/Data Store Read'
   *  DataTypeConversion: '<S43>/Data Type Conversion'
   *  DataTypeConversion: '<S43>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S686>/Discrete-Time Integrator'
   *  Gain: '<S43>/Gain'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  SignalConversion: '<S41>/TmpSignal ConversionAtSignal Copy8Inport1'
   *  Sum: '<S43>/Sum'
   *  Sum: '<S43>/Sum1'
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

  /* Update for DiscreteIntegrator: '<S686>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S686>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S25>/SetHome' incorporates:
   *  TriggerPort: '<S32>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S32>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S25>/SetHome' */

  /* Update for UnitDelay: '<S28>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S28>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  d = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)d;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S35>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S12>/Gain'
   *  Sum: '<S12>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Divide_l_idx_1 -
    FMS_B.DiscreteTimeIntegrator5) * 125.663704F * 0.004F;

  /* Update for UnitDelay: '<S30>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S31>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S36>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S37>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S37>/Delay Input1':
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

  /* Update for UnitDelay: '<S21>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  d = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)d;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* Update for Delay: '<S22>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S11>/Gain'
   *  Sum: '<S11>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_m = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_h += (rtb_Divide_l_idx_0 -
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
  /* Start for SwitchCase: '<S40>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S40>/Arm' */
  /* Start for SwitchCase: '<S42>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S42>/FW_Mode' */
  /* Start for SwitchCase: '<S47>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;

  /* Start for IfAction SubSystem: '<S47>/SubMode' */
  /* Start for SwitchCase: '<S62>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S47>/SubMode' */

  /* Start for IfAction SubSystem: '<S47>/Auto' */
  /* Start for SwitchCase: '<S60>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S47>/Auto' */

  /* Start for IfAction SubSystem: '<S47>/Assist' */
  /* Start for SwitchCase: '<S59>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_as = -1;

  /* Start for IfAction SubSystem: '<S59>/Altitude' */
  /* Start for SwitchCase: '<S72>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;

  /* End of Start for SubSystem: '<S59>/Altitude' */

  /* Start for IfAction SubSystem: '<S59>/Position' */
  /* Start for SwitchCase: '<S107>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S93>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S59>/Position' */
  /* End of Start for SubSystem: '<S47>/Assist' */
  /* End of Start for SubSystem: '<S42>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S42>/MC_Mode' */
  /* Start for SwitchCase: '<S48>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S48>/SubMode' */
  /* Start for SwitchCase: '<S256>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S256>/Return' */
  /* Start for SwitchCase: '<S644>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S634>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S256>/Return' */

  /* Start for IfAction SubSystem: '<S256>/Hold' */
  /* Start for SwitchCase: '<S583>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S561>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S571>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;

  /* End of Start for SubSystem: '<S256>/Hold' */
  /* End of Start for SubSystem: '<S48>/SubMode' */

  /* Start for IfAction SubSystem: '<S48>/Auto' */
  /* Start for SwitchCase: '<S254>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S254>/Mission' */
  /* Start for Resettable SubSystem: '<S366>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S414>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* Start for SwitchCase: '<S404>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S366>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S254>/Mission' */
  /* End of Start for SubSystem: '<S48>/Auto' */

  /* Start for IfAction SubSystem: '<S48>/Assist' */
  /* Start for SwitchCase: '<S253>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S253>/Stabilize' */
  /* Start for SwitchCase: '<S353>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S253>/Stabilize' */

  /* Start for IfAction SubSystem: '<S253>/Altitude' */
  /* Start for SwitchCase: '<S268>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S286>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S253>/Altitude' */

  /* Start for IfAction SubSystem: '<S253>/Position' */
  /* Start for SwitchCase: '<S302>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S327>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S314>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S253>/Position' */
  /* End of Start for SubSystem: '<S48>/Assist' */
  /* End of Start for SubSystem: '<S42>/MC_Mode' */
  /* End of Start for SubSystem: '<S40>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
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
  FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S40>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S42>/FW_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S47>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S62>/Hold' */
  /* InitializeConditions for Delay: '<S196>/start_vel' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S191>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S62>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S47>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S60>/Mission' */
  /* InitializeConditions for UnitDelay: '<S160>/Delay Input1'
   *
   * Block description for '<S160>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S60>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S47>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S59>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S150>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S150>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S155>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S155>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S59>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S84>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S84>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* SystemInitialize for Chart: '<S73>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S72>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S72>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S72>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S72>/Move Control' */

  /* SystemInitialize for Merge: '<S72>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S59>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S94>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S108>/Motion State' */
  FMS_DW.temporalCounter_i1_ie = 0U;
  FMS_DW.is_active_c26_FMS = 0U;
  FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S107>/Hold Control' */
  /* InitializeConditions for Delay: '<S115>/start_vel' */
  FMS_DW.icLoad_g = 1U;

  /* InitializeConditions for Delay: '<S115>/start_wp' */
  FMS_DW.icLoad_e = 1U;

  /* End of SystemInitialize for SubSystem: '<S107>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S107>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
  FMS_DW.Integrator_DSTATE_f1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S107>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S93>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S93>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S93>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S93>/Move Control' */

  /* SystemInitialize for Merge: '<S93>/Merge' */
  FMS_B.Merge_f = 0.0F;

  /* SystemInitialize for Merge: '<S107>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S59>/Position' */
  /* End of SystemInitialize for SubSystem: '<S47>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S42>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/BackwardTrans_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
    }
  }

  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' */
  FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of SystemInitialize for SubSystem: '<S42>/BackwardTrans_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S48>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S256>/Takeoff' */
  /* InitializeConditions for Delay: '<S684>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S680>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S680>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S256>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S256>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S599>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S599>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S256>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S256>/Return' */
  /* InitializeConditions for Delay: '<S629>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S630>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S625>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S671>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S608>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S611>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;

  /* InitializeConditions for Delay: '<S607>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S611>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S645>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S644>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S644>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S644>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S644>/Move Control' */

  /* SystemInitialize for Merge: '<S644>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S635>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S634>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S634>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S634>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S634>/Move Control' */

  /* SystemInitialize for Merge: '<S634>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S256>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S256>/Hold' */
  /* SystemInitialize for Chart: '<S562>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S572>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S584>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S583>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S583>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S583>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S583>/Move Control' */

  /* SystemInitialize for Merge: '<S583>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S561>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S561>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S561>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S561>/Move Control' */

  /* SystemInitialize for Merge: '<S561>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S571>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S571>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S571>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S571>/Move Control' */

  /* SystemInitialize for Merge: '<S571>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S256>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S48>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S48>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S254>/Mission' */
  /* InitializeConditions for UnitDelay: '<S369>/Delay Input1'
   *
   * Block description for '<S369>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S366>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S396>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S397>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S392>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S441>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S374>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S415>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S414>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_fy);

  /* End of SystemInitialize for SubSystem: '<S414>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S414>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S414>/Move Control' */

  /* SystemInitialize for Merge: '<S414>/Merge' */
  FMS_B.Merge_ls[0] = 0.0F;
  FMS_B.Merge_ls[1] = 0.0F;

  /* SystemInitialize for Chart: '<S405>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for IfAction SubSystem: '<S404>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bf);

  /* End of SystemInitialize for SubSystem: '<S404>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S404>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c0);

  /* End of SystemInitialize for SubSystem: '<S404>/Move Control' */

  /* SystemInitialize for Merge: '<S404>/Merge' */
  FMS_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S366>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S254>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S48>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S48>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S253>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S349>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S350>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S350>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S349>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S354>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S353>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S353>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S353>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S353>/Move Control' */

  /* SystemInitialize for Merge: '<S353>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S253>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S253>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S282>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S283>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S283>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S282>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S269>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S268>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S268>/Hold Control' */

  /* SystemInitialize for Merge: '<S268>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S287>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S286>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S286>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S286>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S286>/Move Control' */

  /* SystemInitialize for Merge: '<S286>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S253>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S253>/Position' */
  /* SystemInitialize for Chart: '<S303>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S302>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S302>/Hold Control' */

  /* SystemInitialize for Chart: '<S315>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S328>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S327>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_jz);

  /* End of SystemInitialize for SubSystem: '<S327>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S327>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S337>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S337>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S327>/Move Control' */

  /* SystemInitialize for Merge: '<S327>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S327>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S337>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S337>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S327>/Move Control' */

  /* SystemInitialize for Merge: '<S327>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S302>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S314>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S314>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S314>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S314>/Move Control' */

  /* SystemInitialize for Merge: '<S314>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S253>/Position' */
  /* End of SystemInitialize for SubSystem: '<S48>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S42>/MC_Mode' */
  /* End of SystemInitialize for SubSystem: '<S40>/Arm' */
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
