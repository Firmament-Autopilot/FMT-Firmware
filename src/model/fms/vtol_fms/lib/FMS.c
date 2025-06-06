/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2224
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:31:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S72>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S633>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S643>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S352>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S107>/Motion State' */
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
                                        *   '<S37>/Constant'
                                        *   '<S686>/Constant'
                                        *   '<S182>/Gain'
                                        *   '<S182>/Gain4'
                                        *   '<S182>/Gain5'
                                        *   '<S186>/Constant4'
                                        *   '<S187>/Constant4'
                                        *   '<S553>/L1'
                                        *   '<S67>/Gain'
                                        *   '<S69>/Gain'
                                        *   '<S70>/Gain1'
                                        *   '<S88>/Gain'
                                        *   '<S90>/Gain1'
                                        *   '<S143>/Gain'
                                        *   '<S143>/Gain1'
                                        *   '<S144>/Gain1'
                                        *   '<S159>/Constant4'
                                        *   '<S189>/Gain2'
                                        *   '<S189>/Saturation1'
                                        *   '<S190>/L1'
                                        *   '<S190>/R'
                                        *   '<S190>/Saturation1'
                                        *   '<S207>/Gain'
                                        *   '<S207>/Saturation1'
                                        *   '<S229>/Gain'
                                        *   '<S229>/Saturation1'
                                        *   '<S264>/Gain'
                                        *   '<S264>/Gain1'
                                        *   '<S342>/Gain'
                                        *   '<S342>/Gain1'
                                        *   '<S344>/Constant'
                                        *   '<S368>/L1'
                                        *   '<S446>/Saturation'
                                        *   '<S447>/Saturation1'
                                        *   '<S447>/Saturation2'
                                        *   '<S447>/Saturation3'
                                        *   '<S594>/Land_Speed'
                                        *   '<S595>/Saturation1'
                                        *   '<S674>/Takeoff_Speed'
                                        *   '<S675>/Gain2'
                                        *   '<S675>/Saturation1'
                                        *   '<S71>/Saturation1'
                                        *   '<S82>/Dead Zone'
                                        *   '<S82>/Gain'
                                        *   '<S85>/Dead Zone'
                                        *   '<S85>/Gain'
                                        *   '<S92>/Saturation1'
                                        *   '<S103>/Dead Zone'
                                        *   '<S103>/Gain'
                                        *   '<S106>/Saturation1'
                                        *   '<S146>/Dead Zone'
                                        *   '<S146>/Gain'
                                        *   '<S147>/Dead Zone'
                                        *   '<S147>/Gain'
                                        *   '<S152>/Dead Zone'
                                        *   '<S152>/Gain'
                                        *   '<S160>/Gain'
                                        *   '<S160>/Saturation1'
                                        *   '<S212>/L1'
                                        *   '<S212>/Saturation1'
                                        *   '<S234>/L1'
                                        *   '<S234>/Saturation1'
                                        *   '<S266>/Saturation1'
                                        *   '<S278>/Dead Zone'
                                        *   '<S278>/Gain'
                                        *   '<S279>/Dead Zone'
                                        *   '<S279>/Gain'
                                        *   '<S284>/Saturation'
                                        *   '<S300>/Saturation1'
                                        *   '<S312>/Saturation'
                                        *   '<S325>/Saturation1'
                                        *   '<S345>/Dead Zone'
                                        *   '<S345>/Gain'
                                        *   '<S346>/Dead Zone'
                                        *   '<S346>/Gain'
                                        *   '<S351>/Saturation'
                                        *   '<S502>/Gain2'
                                        *   '<S509>/Gain1'
                                        *   '<S509>/Gain2'
                                        *   '<S559>/Saturation1'
                                        *   '<S569>/Saturation'
                                        *   '<S581>/Saturation1'
                                        *   '<S596>/Constant'
                                        *   '<S599>/Gain2'
                                        *   '<S623>/Constant'
                                        *   '<S623>/vel'
                                        *   '<S623>/Acceleration_Speed'
                                        *   '<S623>/Saturation'
                                        *   '<S623>/Switch'
                                        *   '<S627>/Constant'
                                        *   '<S74>/Gain2'
                                        *   '<S75>/Gain1'
                                        *   '<S80>/Constant'
                                        *   '<S95>/Gain2'
                                        *   '<S96>/Gain1'
                                        *   '<S101>/Constant'
                                        *   '<S109>/L1'
                                        *   '<S110>/Gain6'
                                        *   '<S139>/Constant'
                                        *   '<S165>/L1'
                                        *   '<S165>/Saturation1'
                                        *   '<S269>/Gain2'
                                        *   '<S270>/Gain1'
                                        *   '<S276>/Constant'
                                        *   '<S287>/Gain2'
                                        *   '<S288>/Gain1'
                                        *   '<S295>/Constant'
                                        *   '<S303>/Gain2'
                                        *   '<S304>/Gain1'
                                        *   '<S310>/Constant'
                                        *   '<S315>/Gain2'
                                        *   '<S316>/Gain1'
                                        *   '<S323>/Constant'
                                        *   '<S328>/Gain2'
                                        *   '<S329>/Gain6'
                                        *   '<S339>/Constant'
                                        *   '<S340>/Constant'
                                        *   '<S354>/Gain2'
                                        *   '<S355>/Gain1'
                                        *   '<S362>/Constant'
                                        *   '<S387>/Gain'
                                        *   '<S387>/Saturation1'
                                        *   '<S390>/Constant'
                                        *   '<S390>/vel'
                                        *   '<S390>/Acceleration_Speed'
                                        *   '<S390>/Saturation'
                                        *   '<S390>/Switch'
                                        *   '<S394>/Constant'
                                        *   '<S562>/Gain2'
                                        *   '<S563>/Gain1'
                                        *   '<S572>/Gain2'
                                        *   '<S573>/Gain1'
                                        *   '<S584>/Gain2'
                                        *   '<S585>/Gain6'
                                        *   '<S608>/Gain2'
                                        *   '<S608>/Saturation'
                                        *   '<S609>/Integrator'
                                        *   '<S77>/Dead Zone'
                                        *   '<S77>/Gain'
                                        *   '<S98>/Dead Zone'
                                        *   '<S98>/Gain'
                                        *   '<S136>/Dead Zone'
                                        *   '<S136>/Gain'
                                        *   '<S272>/Land_Speed'
                                        *   '<S273>/Constant'
                                        *   '<S275>/Dead Zone'
                                        *   '<S275>/Gain'
                                        *   '<S292>/Dead Zone'
                                        *   '<S292>/Gain'
                                        *   '<S306>/Land_Speed'
                                        *   '<S307>/Constant'
                                        *   '<S309>/Dead Zone'
                                        *   '<S309>/Gain'
                                        *   '<S320>/Dead Zone'
                                        *   '<S320>/Gain'
                                        *   '<S333>/Dead Zone'
                                        *   '<S333>/Gain'
                                        *   '<S334>/Dead Zone'
                                        *   '<S334>/Gain'
                                        *   '<S359>/Dead Zone'
                                        *   '<S359>/Gain'
                                        *   '<S374>/Gain2'
                                        *   '<S374>/Saturation'
                                        *   '<S375>/Integrator'
                                        *   '<S565>/Dead Zone'
                                        *   '<S565>/Gain'
                                        *   '<S577>/Dead Zone'
                                        *   '<S577>/Gain'
                                        *   '<S589>/Dead Zone'
                                        *   '<S589>/Gain'
                                        *   '<S590>/Dead Zone'
                                        *   '<S590>/Gain'
                                        *   '<S632>/Saturation1'
                                        *   '<S642>/Saturation1'
                                        *   '<S402>/Saturation1'
                                        *   '<S412>/Saturation1'
                                        *   '<S635>/Gain2'
                                        *   '<S636>/Gain1'
                                        *   '<S645>/Gain2'
                                        *   '<S646>/Gain6'
                                        *   '<S405>/Gain2'
                                        *   '<S406>/Gain1'
                                        *   '<S415>/Gain2'
                                        *   '<S416>/Gain6'
                                        *   '<S638>/Dead Zone'
                                        *   '<S638>/Gain'
                                        *   '<S650>/Dead Zone'
                                        *   '<S650>/Gain'
                                        *   '<S651>/Dead Zone'
                                        *   '<S651>/Gain'
                                        *   '<S408>/Dead Zone'
                                        *   '<S408>/Gain'
                                        *   '<S420>/Dead Zone'
                                        *   '<S420>/Gain'
                                        *   '<S421>/Dead Zone'
                                        *   '<S421>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S23>/Constant1'
                                        *   '<S684>/Constant'
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
 *    '<S236>/NearbyRefWP'
 *    '<S214>/NearbyRefWP'
 *    '<S167>/NearbyRefWP'
 *    '<S625>/NearbyRefWP'
 *    '<S392>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S240>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S236>/OutRegionRegWP'
 *    '<S214>/OutRegionRegWP'
 *    '<S167>/OutRegionRegWP'
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

  /* SignalConversion: '<S241>/TmpSignal ConversionAt SFunction Inport3' */
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
    /* SignalConversion: '<S241>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S236>/SearchL1RefWP'
 *    '<S214>/SearchL1RefWP'
 *    '<S167>/SearchL1RefWP'
 *    '<S392>/SearchL1RefWP'
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

  /* SignalConversion: '<S242>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S61>/Unknown'
 *    '<S59>/Unknown'
 *    '<S58>/Unknown'
 *    '<S46>/Unknown'
 *    '<S254>/Unknown'
 *    '<S252>/Unknown'
 *    '<S251>/Unknown'
 *    '<S47>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S188>/Bus Assignment' incorporates:
   *  Constant: '<S188>/Constant'
   *  Constant: '<S188>/Constant2'
   *  SignalConversion: '<S188>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S188>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S71>/Hold Control'
 *    '<S92>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S74>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S71>/Hold Control'
 *    '<S92>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S74>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S71>/Hold Control'
 *    '<S92>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S74>/Delay' incorporates:
   *  Gain: '<S76>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S74>/Gain2' incorporates:
   *  Delay: '<S74>/Delay'
   *  Gain: '<S76>/Gain'
   *  Sum: '<S74>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S74>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S71>/Brake Control'
 *    '<S92>/Brake Control'
 *    '<S632>/Brake Control'
 *    '<S559>/Brake Control'
 *    '<S569>/Brake Control'
 *    '<S402>/Brake Control'
 *    '<S351>/Brake Control'
 *    '<S266>/Brake Control'
 *    '<S284>/Brake Control'
 *    '<S300>/Brake Control'
 *    '<S312>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S73>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S73>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S71>/Move Control'
 *    '<S92>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S71>/Move Control'
 *    '<S92>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S71>/Move Control'
 *    '<S92>/Move Control'
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

  /* Product: '<S79>/Multiply1' incorporates:
   *  Constant: '<S79>/const1'
   *  DiscreteIntegrator: '<S78>/Integrator'
   */
  rtb_Add3_ci = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S77>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S77>/Dead Zone' */

  /* Sum: '<S79>/Add' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator1'
   *  Gain: '<S75>/Gain1'
   *  Gain: '<S77>/Gain'
   *  Sum: '<S78>/Subtract'
   */
  rtb_Subtract3_m = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_b * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_ci;

  /* Signum: '<S79>/Sign' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_m > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_m;
  }

  /* End of Signum: '<S79>/Sign' */

  /* Sum: '<S79>/Add2' incorporates:
   *  Abs: '<S79>/Abs'
   *  Gain: '<S79>/Gain'
   *  Gain: '<S79>/Gain1'
   *  Product: '<S79>/Multiply2'
   *  Product: '<S79>/Multiply3'
   *  Sqrt: '<S79>/Sqrt'
   *  Sum: '<S79>/Add1'
   *  Sum: '<S79>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_m) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_ci;

  /* Sum: '<S79>/Add4' */
  rtb_Add4_lp = (rtb_Subtract3_m - rtb_a_b) + rtb_Add3_ci;

  /* Sum: '<S79>/Add3' */
  rtb_Add3_ci = rtb_Subtract3_m + localC->d;

  /* Sum: '<S79>/Subtract1' */
  rtb_Subtract3_m -= localC->d;

  /* Signum: '<S79>/Sign1' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign1' */

  /* Signum: '<S79>/Sign2' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign2' */

  /* Sum: '<S79>/Add5' incorporates:
   *  Gain: '<S79>/Gain2'
   *  Product: '<S79>/Multiply4'
   *  Sum: '<S79>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_ci - rtb_Subtract3_m) * 0.5F * rtb_Add4_lp;

  /* SignalConversion: '<S75>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S78>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S79>/Add6' */
  rtb_Add3_ci = rtb_a_b + localC->d;

  /* Sum: '<S79>/Subtract3' */
  rtb_Subtract3_m = rtb_a_b - localC->d;

  /* Signum: '<S79>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_lp = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_lp = 1.0F;
  } else {
    rtb_Add4_lp = rtb_a_b;
  }

  /* End of Signum: '<S79>/Sign5' */

  /* Signum: '<S79>/Sign3' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign3' */

  /* Signum: '<S79>/Sign4' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign4' */

  /* Signum: '<S79>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_b;
  }

  /* End of Signum: '<S79>/Sign6' */

  /* Update for DiscreteIntegrator: '<S78>/Integrator' incorporates:
   *  Constant: '<S79>/const'
   *  Gain: '<S79>/Gain3'
   *  Product: '<S79>/Divide'
   *  Product: '<S79>/Multiply5'
   *  Product: '<S79>/Multiply6'
   *  Sum: '<S79>/Subtract4'
   *  Sum: '<S79>/Subtract5'
   *  Sum: '<S79>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_lp) *
    localC->Gain4 * ((rtb_Add3_ci - rtb_Subtract3_m) * 0.5F) - rtb_a_f * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S72>/Motion Status'
 *    '<S93>/Motion Status'
 *    '<S267>/Motion Status'
 *    '<S301>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S72>/Motion Status'
 *    '<S93>/Motion Status'
 *    '<S267>/Motion Status'
 *    '<S301>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S72>/Motion Status'
 *    '<S93>/Motion Status'
 *    '<S267>/Motion Status'
 *    '<S301>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S72>/Motion Status' */
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

  /* End of Chart: '<S72>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S632>/Hold Control'
 *    '<S559>/Hold Control'
 *    '<S402>/Hold Control'
 *    '<S266>/Hold Control'
 *    '<S300>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S635>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S632>/Hold Control'
 *    '<S559>/Hold Control'
 *    '<S402>/Hold Control'
 *    '<S266>/Hold Control'
 *    '<S300>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S635>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S632>/Hold Control'
 *    '<S559>/Hold Control'
 *    '<S402>/Hold Control'
 *    '<S266>/Hold Control'
 *    '<S300>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S635>/Delay' incorporates:
   *  Gain: '<S637>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S635>/Gain2' incorporates:
   *  Delay: '<S635>/Delay'
   *  Gain: '<S637>/Gain'
   *  Sum: '<S635>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S635>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S632>/Move Control'
 *    '<S559>/Move Control'
 *    '<S402>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S639>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S639>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S632>/Move Control'
 *    '<S559>/Move Control'
 *    '<S402>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S639>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S639>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S632>/Move Control'
 *    '<S559>/Move Control'
 *    '<S402>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_f;
  real32_T rtb_a_f;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S640>/Multiply1' incorporates:
   *  Constant: '<S640>/const1'
   *  DiscreteIntegrator: '<S639>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S638>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_f = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_f = 0.0F;
  } else {
    rtb_a_f = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S638>/Dead Zone' */

  /* Sum: '<S640>/Add' incorporates:
   *  DiscreteIntegrator: '<S639>/Integrator1'
   *  Gain: '<S636>/Gain1'
   *  Gain: '<S638>/Gain'
   *  Sum: '<S639>/Subtract'
   */
  rtb_Subtract3_f = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_f * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S640>/Sign' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_Subtract3_f > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_Subtract3_f;
  }

  /* End of Signum: '<S640>/Sign' */

  /* Sum: '<S640>/Add2' incorporates:
   *  Abs: '<S640>/Abs'
   *  Gain: '<S640>/Gain'
   *  Gain: '<S640>/Gain1'
   *  Product: '<S640>/Multiply2'
   *  Product: '<S640>/Multiply3'
   *  Sqrt: '<S640>/Sqrt'
   *  Sum: '<S640>/Add1'
   *  Sum: '<S640>/Subtract'
   */
  rtb_a_f = (sqrtf((8.0F * fabsf(rtb_Subtract3_f) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_f + rtb_Add3_aw;

  /* Sum: '<S640>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_f - rtb_a_f) + rtb_Add3_aw;

  /* Sum: '<S640>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_f + localC->d;

  /* Sum: '<S640>/Subtract1' */
  rtb_Subtract3_f -= localC->d;

  /* Signum: '<S640>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S640>/Sign1' */

  /* Signum: '<S640>/Sign2' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S640>/Sign2' */

  /* Sum: '<S640>/Add5' incorporates:
   *  Gain: '<S640>/Gain2'
   *  Product: '<S640>/Multiply4'
   *  Sum: '<S640>/Subtract2'
   */
  rtb_a_f += (rtb_Add3_aw - rtb_Subtract3_f) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S639>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S639>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S639>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S639>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S640>/Add6' */
  rtb_Add3_aw = rtb_a_f + localC->d;

  /* Sum: '<S640>/Subtract3' */
  rtb_Subtract3_f = rtb_a_f - localC->d;

  /* Signum: '<S640>/Sign5' */
  if (rtb_a_f < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_f > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_f;
  }

  /* End of Signum: '<S640>/Sign5' */

  /* Signum: '<S640>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S640>/Sign3' */

  /* Signum: '<S640>/Sign4' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S640>/Sign4' */

  /* Signum: '<S640>/Sign6' */
  if (rtb_a_f < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_f > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_f;
  }

  /* End of Signum: '<S640>/Sign6' */

  /* Update for DiscreteIntegrator: '<S639>/Integrator' incorporates:
   *  Constant: '<S640>/const'
   *  Gain: '<S640>/Gain3'
   *  Product: '<S640>/Divide'
   *  Product: '<S640>/Multiply5'
   *  Product: '<S640>/Multiply6'
   *  Sum: '<S640>/Subtract4'
   *  Sum: '<S640>/Subtract5'
   *  Sum: '<S640>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_f / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_f) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S633>/Motion Status'
 *    '<S560>/Motion Status'
 *    '<S403>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S633>/Motion Status'
 *    '<S560>/Motion Status'
 *    '<S403>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S633>/Motion Status'
 *    '<S560>/Motion Status'
 *    '<S403>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S633>/Motion Status' */
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

  /* End of Chart: '<S633>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S642>/Hold Control'
 *    '<S581>/Hold Control'
 *    '<S412>/Hold Control'
 *    '<S325>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S645>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S642>/Hold Control'
 *    '<S581>/Hold Control'
 *    '<S412>/Hold Control'
 *    '<S325>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S645>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S642>/Hold Control'
 *    '<S581>/Hold Control'
 *    '<S412>/Hold Control'
 *    '<S325>/Hold Control'
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

  /* Delay: '<S645>/Delay' incorporates:
   *  SignalConversion: '<S645>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S649>/Trigonometric Function1' incorporates:
   *  Gain: '<S648>/Gain'
   *  Trigonometry: '<S649>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S649>/Trigonometric Function' incorporates:
   *  Gain: '<S648>/Gain'
   *  Trigonometry: '<S649>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S649>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S649>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S649>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S649>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S649>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S649>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S649>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S645>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S645>/Delay'
   *  SignalConversion: '<S645>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S645>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S645>/Multiply' incorporates:
   *  SignalConversion: '<S645>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S645>/Multiply' */

  /* Gain: '<S645>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S645>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S642>/Brake Control'
 *    '<S581>/Brake Control'
 *    '<S412>/Brake Control'
 *    '<S325>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S644>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S642>/Move Control'
 *    '<S581>/Move Control'
 *    '<S412>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S642>/Move Control'
 *    '<S581>/Move Control'
 *    '<S412>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S642>/Move Control'
 *    '<S581>/Move Control'
 *    '<S412>/Move Control'
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

  /* DiscreteIntegrator: '<S652>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S653>/Multiply1' incorporates:
   *  Constant: '<S653>/const1'
   *  DiscreteIntegrator: '<S652>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S652>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S653>/Multiply1' incorporates:
   *  Constant: '<S653>/const1'
   *  DiscreteIntegrator: '<S652>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S650>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S650>/Dead Zone' */

  /* Sum: '<S653>/Add' incorporates:
   *  DiscreteIntegrator: '<S652>/Integrator1'
   *  Gain: '<S646>/Gain6'
   *  Gain: '<S650>/Gain'
   *  Sum: '<S652>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S651>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S651>/Dead Zone' */

  /* Sum: '<S653>/Add' incorporates:
   *  DiscreteIntegrator: '<S652>/Integrator1'
   *  Gain: '<S646>/Gain6'
   *  Gain: '<S651>/Gain'
   *  Sum: '<S652>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S653>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S653>/Add2' incorporates:
   *  Abs: '<S653>/Abs'
   *  Gain: '<S653>/Gain'
   *  Gain: '<S653>/Gain1'
   *  Product: '<S653>/Multiply2'
   *  Product: '<S653>/Multiply3'
   *  Signum: '<S653>/Sign'
   *  Sqrt: '<S653>/Sqrt'
   *  Sum: '<S653>/Add1'
   *  Sum: '<S653>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S653>/Add3' incorporates:
   *  Signum: '<S653>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S653>/Subtract1' incorporates:
   *  Signum: '<S653>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S653>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S653>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S653>/Add5' incorporates:
   *  Gain: '<S653>/Gain2'
   *  Product: '<S653>/Multiply4'
   *  Signum: '<S653>/Sign'
   *  Sum: '<S653>/Add2'
   *  Sum: '<S653>/Add4'
   *  Sum: '<S653>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* SignalConversion: '<S652>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S652>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S653>/Sign3' incorporates:
   *  Sum: '<S653>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S653>/Sign4' incorporates:
   *  Sum: '<S653>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S653>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S653>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S653>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S653>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S652>/Integrator' incorporates:
   *  Constant: '<S653>/const'
   *  Gain: '<S653>/Gain3'
   *  Product: '<S653>/Divide'
   *  Product: '<S653>/Multiply5'
   *  Product: '<S653>/Multiply6'
   *  Sum: '<S653>/Subtract4'
   *  Sum: '<S653>/Subtract5'
   *  Sum: '<S653>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S652>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S653>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S653>/Add2' incorporates:
   *  Abs: '<S653>/Abs'
   *  Gain: '<S653>/Gain'
   *  Gain: '<S653>/Gain1'
   *  Product: '<S653>/Multiply2'
   *  Product: '<S653>/Multiply3'
   *  Signum: '<S653>/Sign'
   *  Sqrt: '<S653>/Sqrt'
   *  Sum: '<S653>/Add1'
   *  Sum: '<S653>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S653>/Add3' incorporates:
   *  Signum: '<S653>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S653>/Subtract1' incorporates:
   *  Signum: '<S653>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S653>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S653>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S653>/Add5' incorporates:
   *  Gain: '<S653>/Gain2'
   *  Product: '<S653>/Multiply4'
   *  Signum: '<S653>/Sign'
   *  Sum: '<S653>/Add2'
   *  Sum: '<S653>/Add4'
   *  Sum: '<S653>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* SignalConversion: '<S652>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S652>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S653>/Sign3' incorporates:
   *  Sum: '<S653>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S653>/Sign4' incorporates:
   *  Sum: '<S653>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S653>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S653>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S653>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S653>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S652>/Integrator' incorporates:
   *  Constant: '<S653>/const'
   *  Gain: '<S653>/Gain3'
   *  Product: '<S653>/Divide'
   *  Product: '<S653>/Multiply5'
   *  Product: '<S653>/Multiply6'
   *  Sum: '<S653>/Subtract4'
   *  Sum: '<S653>/Subtract5'
   *  Sum: '<S653>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S652>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S643>/Motion State'
 *    '<S582>/Motion State'
 *    '<S413>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S643>/Motion State'
 *    '<S582>/Motion State'
 *    '<S413>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S643>/Motion State'
 *    '<S582>/Motion State'
 *    '<S413>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S643>/Motion State' */
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

  /* End of Chart: '<S643>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S569>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S284>/Hold Control'
 *    '<S312>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S572>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S569>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S284>/Hold Control'
 *    '<S312>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S572>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S569>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S284>/Hold Control'
 *    '<S312>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S572>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S572>/Sum' incorporates:
   *  Delay: '<S572>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S575>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S575>/Switch' incorporates:
   *  Constant: '<S575>/Constant'
   *  Constant: '<S576>/Constant'
   *  Product: '<S575>/Multiply'
   *  RelationalOperator: '<S576>/Compare'
   *  Sum: '<S575>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S575>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S575>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S575>/Switch' */

  /* Gain: '<S572>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S572>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S569>/Move Control'
 *    '<S351>/Move Control'
 *    '<S284>/Move Control'
 *    '<S312>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S578>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S578>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S569>/Move Control'
 *    '<S351>/Move Control'
 *    '<S284>/Move Control'
 *    '<S312>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S578>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S578>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S569>/Move Control'
 *    '<S351>/Move Control'
 *    '<S284>/Move Control'
 *    '<S312>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_g;
  real32_T rtb_Subtract3_g;
  real32_T rtb_a_pq;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S579>/Multiply1' incorporates:
   *  Constant: '<S579>/const1'
   *  DiscreteIntegrator: '<S578>/Integrator'
   */
  rtb_Add3_g = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S577>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_pq = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_pq = 0.0F;
  } else {
    rtb_a_pq = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S577>/Dead Zone' */

  /* Sum: '<S579>/Add' incorporates:
   *  DiscreteIntegrator: '<S578>/Integrator1'
   *  Gain: '<S573>/Gain1'
   *  Gain: '<S577>/Gain'
   *  Sum: '<S578>/Subtract'
   */
  rtb_Subtract3_g = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_pq * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_g;

  /* Signum: '<S579>/Sign' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_a_pq = -1.0F;
  } else if (rtb_Subtract3_g > 0.0F) {
    rtb_a_pq = 1.0F;
  } else {
    rtb_a_pq = rtb_Subtract3_g;
  }

  /* End of Signum: '<S579>/Sign' */

  /* Sum: '<S579>/Add2' incorporates:
   *  Abs: '<S579>/Abs'
   *  Gain: '<S579>/Gain'
   *  Gain: '<S579>/Gain1'
   *  Product: '<S579>/Multiply2'
   *  Product: '<S579>/Multiply3'
   *  Sqrt: '<S579>/Sqrt'
   *  Sum: '<S579>/Add1'
   *  Sum: '<S579>/Subtract'
   */
  rtb_a_pq = (sqrtf((8.0F * fabsf(rtb_Subtract3_g) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_pq + rtb_Add3_g;

  /* Sum: '<S579>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_g - rtb_a_pq) + rtb_Add3_g;

  /* Sum: '<S579>/Add3' */
  rtb_Add3_g = rtb_Subtract3_g + localC->d;

  /* Sum: '<S579>/Subtract1' */
  rtb_Subtract3_g -= localC->d;

  /* Signum: '<S579>/Sign1' */
  if (rtb_Add3_g < 0.0F) {
    rtb_Add3_g = -1.0F;
  } else {
    if (rtb_Add3_g > 0.0F) {
      rtb_Add3_g = 1.0F;
    }
  }

  /* End of Signum: '<S579>/Sign1' */

  /* Signum: '<S579>/Sign2' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S579>/Sign2' */

  /* Sum: '<S579>/Add5' incorporates:
   *  Gain: '<S579>/Gain2'
   *  Product: '<S579>/Multiply4'
   *  Sum: '<S579>/Subtract2'
   */
  rtb_a_pq += (rtb_Add3_g - rtb_Subtract3_g) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S578>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S578>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S578>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S578>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S579>/Add6' */
  rtb_Add3_g = rtb_a_pq + localC->d;

  /* Sum: '<S579>/Subtract3' */
  rtb_Subtract3_g = rtb_a_pq - localC->d;

  /* Signum: '<S579>/Sign5' */
  if (rtb_a_pq < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_pq;
  }

  /* End of Signum: '<S579>/Sign5' */

  /* Signum: '<S579>/Sign3' */
  if (rtb_Add3_g < 0.0F) {
    rtb_Add3_g = -1.0F;
  } else {
    if (rtb_Add3_g > 0.0F) {
      rtb_Add3_g = 1.0F;
    }
  }

  /* End of Signum: '<S579>/Sign3' */

  /* Signum: '<S579>/Sign4' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S579>/Sign4' */

  /* Signum: '<S579>/Sign6' */
  if (rtb_a_pq < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_pq;
  }

  /* End of Signum: '<S579>/Sign6' */

  /* Update for DiscreteIntegrator: '<S578>/Integrator' incorporates:
   *  Constant: '<S579>/const'
   *  Gain: '<S579>/Gain3'
   *  Product: '<S579>/Divide'
   *  Product: '<S579>/Multiply5'
   *  Product: '<S579>/Multiply6'
   *  Sum: '<S579>/Subtract4'
   *  Sum: '<S579>/Subtract5'
   *  Sum: '<S579>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_pq / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_g - rtb_Subtract3_g) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S352>/Motion State'
 *    '<S285>/Motion State'
 *    '<S313>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S352>/Motion State'
 *    '<S285>/Motion State'
 *    '<S313>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S352>/Motion State'
 *    '<S285>/Motion State'
 *    '<S313>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S352>/Motion State' */
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

  /* End of Chart: '<S352>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S266>/Move Control'
 *    '<S300>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S275>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S275>/Dead Zone' */

  /* Gain: '<S270>/Gain1' incorporates:
   *  Gain: '<S275>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S270>/Switch' incorporates:
   *  Constant: '<S272>/Land_Speed'
   *  Constant: '<S273>/Constant'
   *  Constant: '<S274>/Constant'
   *  Gain: '<S272>/Gain'
   *  Logic: '<S270>/Logical Operator'
   *  MinMax: '<S272>/Min'
   *  RelationalOperator: '<S273>/Compare'
   *  RelationalOperator: '<S274>/Compare'
   *  S-Function (sfix_bitop): '<S270>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S270>/Switch' */
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
  int32_T rtb_Compare_d_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S688>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S689>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S689>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S689>/Multiply1' incorporates:
   *  Product: '<S689>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S689>/Divide' incorporates:
   *  Constant: '<S689>/Constant'
   *  Constant: '<S689>/R'
   *  Sqrt: '<S689>/Sqrt'
   *  Sum: '<S689>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S689>/Product3' incorporates:
   *  Constant: '<S689>/Constant1'
   *  Product: '<S689>/Multiply1'
   *  Sum: '<S689>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S689>/Multiply2' incorporates:
   *  Trigonometry: '<S689>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S688>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S693>/Abs' incorporates:
   *  Abs: '<S696>/Abs1'
   *  Switch: '<S693>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S693>/Switch1' incorporates:
   *  Abs: '<S693>/Abs'
   *  Bias: '<S693>/Bias2'
   *  Bias: '<S693>/Bias3'
   *  Constant: '<S690>/Constant'
   *  Constant: '<S690>/Constant1'
   *  Constant: '<S695>/Constant'
   *  Gain: '<S693>/Gain1'
   *  Product: '<S693>/Multiply'
   *  RelationalOperator: '<S695>/Compare'
   *  Switch: '<S690>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S696>/Switch1' incorporates:
     *  Bias: '<S696>/Bias2'
     *  Bias: '<S696>/Bias3'
     *  Constant: '<S696>/Constant'
     *  Constant: '<S697>/Constant'
     *  Math: '<S696>/Math Function'
     *  RelationalOperator: '<S697>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S696>/Switch1' */

    /* Signum: '<S693>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S693>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_d_0 = 180;
  } else {
    rtb_Compare_d_0 = 0;
  }

  /* Sum: '<S690>/Sum' incorporates:
   *  Sum: '<S688>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_d_0;

  /* Product: '<S688>/Multiply' incorporates:
   *  Gain: '<S688>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S692>/Switch1' incorporates:
   *  Abs: '<S692>/Abs1'
   *  Bias: '<S692>/Bias2'
   *  Bias: '<S692>/Bias3'
   *  Constant: '<S692>/Constant'
   *  Constant: '<S694>/Constant'
   *  Math: '<S692>/Math Function'
   *  RelationalOperator: '<S694>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S692>/Switch1' */

  /* Product: '<S688>/Multiply' incorporates:
   *  Gain: '<S688>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S688>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S691>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S691>/Sum2' incorporates:
   *  Product: '<S691>/Multiply1'
   *  Product: '<S691>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S691>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S691>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S691>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S685>/Data Type Conversion' incorporates:
   *  Gain: '<S688>/Gain'
   *  Sum: '<S688>/Sum1'
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
  /* RelationalOperator: '<S698>/Compare' incorporates:
   *  Abs: '<S687>/Abs'
   *  Constant: '<S698>/Constant'
   *  MinMax: '<S687>/Max'
   *  Sum: '<S687>/Sum'
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

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S686>/Reshape' incorporates:
       *  Constant: '<S686>/Constant'
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
  boolean_T c_sf_internal_predicateOutput;
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

    if (FMS_DW.is_active_VTOL_State != 0U) {
      guard1 = false;
      switch (FMS_DW.is_VTOL_State) {
       case FMS_IN_BackwardTrans:
        FMS_B.vtol_state = VTOLState_BackwardTrans;
        if ((fabsf(FMS_B.DiscreteTimeIntegrator5_p) < 1.0F) ||
            (FMS_DW.temporalCounter_i2 >= 5000U)) {
          guard1 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            c_sf_internal_predicateOutput = false;
          }

          if (c_sf_internal_predicateOutput) {
            guard1 = true;
          }
        }
        break;

       case FMS_IN_Fixwing:
        FMS_B.vtol_state = VTOLState_Fixwing;
        if (FMS_B.DataTypeConversion_n == VTOLMode_Multicopter) {
          FMS_DW.is_VTOL_State = FMS_IN_BackwardTrans;
          FMS_DW.temporalCounter_i2 = 0U;
          FMS_B.vtol_state = VTOLState_BackwardTrans;
        }
        break;

       case FMS_IN_ForwardTrans:
        FMS_B.vtol_state = VTOLState_ForwardTrans;
        if (FMS_B.DiscreteTimeIntegrator5 >= 17.0F) {
          FMS_DW.is_VTOL_State = FMS_IN_Fixwing;
          FMS_B.vtol_state = VTOLState_Fixwing;
        } else {
          if (FMS_B.DataTypeConversion_n == VTOLMode_Multicopter) {
            FMS_DW.is_VTOL_State = FMS_IN_BackwardTrans;
            FMS_DW.temporalCounter_i2 = 0U;
            FMS_B.vtol_state = VTOLState_BackwardTrans;
          }
        }
        break;

       case FMS_IN_Multicopter:
        FMS_B.vtol_state = VTOLState_Multicopter;
        if (FMS_B.DataTypeConversion_n == VTOLMode_Fixwing) {
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
  real32_T d;
  real32_T D;
  real32_T rtb_MatrixConcatenate1_i[9];
  FMS_Cmd rtb_DataTypeConversion1_fu;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion_o;
  uint16_T rtb_DataTypeConversion1_h;
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
  real_T rtb_Switch1_a;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  real32_T rtb_Transpose[9];
  real32_T rtb_u_mm;
  boolean_T rtb_LogicalOperator_op;
  real32_T rtb_P_dg[2];
  real32_T rtb_P_cg[2];
  real32_T rtb_MatrixConcatenate1_i_0[3];
  boolean_T tmp[3];
  real32_T rtb_Multiply_h_0[3];
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
  real_T rtb_Multiply_h_idx_0;
  uint32_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;
  boolean_T guard1 = false;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S39>/Arm' incorporates:
   *  ActionPort: '<S41>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S41>/FW_Mode' incorporates:
   *  ActionPort: '<S46>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Assist' incorporates:
   *  ActionPort: '<S58>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S58>/Position' incorporates:
   *  ActionPort: '<S64>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S106>/Hold Control' incorporates:
   *  ActionPort: '<S109>/Action Port'
   */
  /* SwitchCase: '<S106>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S18>/Square'
   *  Sqrt: '<S120>/Sqrt'
   *  Sqrt: '<S18>/Sqrt'
   *  Sum: '<S18>/Sum of Elements'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S58>/Switch Case'
   */
  d = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
              FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
             FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) +
            FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* End of Outputs for SubSystem: '<S106>/Hold Control' */
  /* End of Outputs for SubSystem: '<S58>/Position' */
  /* End of Outputs for SubSystem: '<S46>/Assist' */
  /* End of Outputs for SubSystem: '<S41>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S39>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S14>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Sqrt: '<S18>/Sqrt'
   */
  rtb_Divide_l_idx_0 = FMS_U.INS_Out.quat[0] / d;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / d;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / d;
  rtb_Divide_l_idx_3 = FMS_U.INS_Out.quat[3] / d;

  /* Math: '<S15>/Square' incorporates:
   *  Math: '<S16>/Square'
   *  Math: '<S17>/Square'
   */
  rtb_u_mm = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_0;

  /* Math: '<S15>/Square2' incorporates:
   *  Math: '<S16>/Square2'
   *  Math: '<S17>/Square2'
   */
  rtb_Switch_fz_idx_0 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S15>/Square1' incorporates:
   *  Math: '<S16>/Square1'
   *  Math: '<S17>/Square1'
   */
  rtb_Switch_fz_idx_1 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S15>/Square3' incorporates:
   *  Math: '<S16>/Square3'
   *  Math: '<S17>/Square3'
   */
  rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3;

  /* Sum: '<S15>/Subtract' incorporates:
   *  Math: '<S15>/Square'
   *  Math: '<S15>/Square1'
   *  Math: '<S15>/Square2'
   *  Math: '<S15>/Square3'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   */
  rtb_MatrixConcatenate1_i[0] = (rtb_u_mm + rtb_Switch_fz_idx_1) -
    (rtb_Switch_fz_idx_0 + rtb_Switch_fz_idx_2);

  /* Product: '<S15>/Multiply' incorporates:
   *  Product: '<S16>/Multiply'
   */
  rtb_Divide_or = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S15>/Multiply1' incorporates:
   *  Product: '<S16>/Multiply1'
   */
  rtb_Sign5_mn = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_3;

  /* Gain: '<S15>/Gain' incorporates:
   *  Product: '<S15>/Multiply'
   *  Product: '<S15>/Multiply1'
   *  Sum: '<S15>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[1] = (rtb_Divide_or - rtb_Sign5_mn) * 2.0F;

  /* Product: '<S15>/Multiply2' incorporates:
   *  Product: '<S17>/Multiply'
   */
  rtb_Subtract3_d = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_3;

  /* Product: '<S15>/Multiply3' incorporates:
   *  Product: '<S17>/Multiply1'
   */
  D = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_2;

  /* Gain: '<S15>/Gain1' incorporates:
   *  Product: '<S15>/Multiply2'
   *  Product: '<S15>/Multiply3'
   *  Sum: '<S15>/Add2'
   */
  rtb_MatrixConcatenate1_i[2] = (rtb_Subtract3_d + D) * 2.0F;

  /* Gain: '<S16>/Gain' incorporates:
   *  Sum: '<S16>/Add3'
   */
  rtb_MatrixConcatenate1_i[3] = (rtb_Divide_or + rtb_Sign5_mn) * 2.0F;

  /* Sum: '<S16>/Subtract' incorporates:
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Add1'
   */
  rtb_MatrixConcatenate1_i[4] = (rtb_u_mm + rtb_Switch_fz_idx_0) -
    (rtb_Switch_fz_idx_1 + rtb_Switch_fz_idx_2);

  /* Product: '<S16>/Multiply2' incorporates:
   *  Product: '<S17>/Multiply2'
   */
  rtb_Divide_or = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_3;

  /* Product: '<S16>/Multiply3' incorporates:
   *  Product: '<S17>/Multiply3'
   */
  rtb_Sign5_mn = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_1;

  /* Gain: '<S16>/Gain1' incorporates:
   *  Product: '<S16>/Multiply2'
   *  Product: '<S16>/Multiply3'
   *  Sum: '<S16>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[5] = (rtb_Divide_or - rtb_Sign5_mn) * 2.0F;

  /* Gain: '<S17>/Gain' incorporates:
   *  Sum: '<S17>/Subtract2'
   */
  rtb_MatrixConcatenate1_i[6] = (rtb_Subtract3_d - D) * 2.0F;

  /* Gain: '<S17>/Gain1' incorporates:
   *  Sum: '<S17>/Add2'
   */
  rtb_MatrixConcatenate1_i[7] = (rtb_Divide_or + rtb_Sign5_mn) * 2.0F;

  /* Sum: '<S17>/Subtract' incorporates:
   *  Sum: '<S17>/Add'
   *  Sum: '<S17>/Add1'
   */
  rtb_MatrixConcatenate1_i[8] = (rtb_u_mm + rtb_Switch_fz_idx_2) -
    (rtb_Switch_fz_idx_1 + rtb_Switch_fz_idx_0);

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
    rtb_Divide_l_idx_0 = -1.0F;
  } else if (rtb_MatrixConcatenate1_i_0[0] > 0.0F) {
    rtb_Divide_l_idx_0 = 1.0F;
  } else {
    rtb_Divide_l_idx_0 = rtb_MatrixConcatenate1_i_0[0];
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
   *  ActionPort: '<S59>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S59>/Mission' incorporates:
   *  ActionPort: '<S155>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S155>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S159>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S46>/SubMode' incorporates:
   *  ActionPort: '<S61>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S61>/Return' incorporates:
   *  ActionPort: '<S186>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S61>/Takeoff' incorporates:
   *  ActionPort: '<S187>/Action Port'
   */
  /* SwitchCase: '<S59>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S177>/Math Function'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S224>/Math Function'
   *  Math: '<S246>/Math Function'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S61>/Switch Case'
   */
  rtb_u_mm = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Divide_or = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S61>/Takeoff' */
  /* End of Outputs for SubSystem: '<S61>/Return' */
  /* End of Outputs for SubSystem: '<S155>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S59>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */

  /* Outputs for IfAction SubSystem: '<S41>/MC_Mode' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
   *  ActionPort: '<S252>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S252>/Mission' incorporates:
   *  ActionPort: '<S364>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S364>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S368>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
   *  ActionPort: '<S254>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S254>/Return' incorporates:
   *  ActionPort: '<S553>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Assist' incorporates:
   *  ActionPort: '<S58>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S58>/Position' incorporates:
   *  ActionPort: '<S64>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S106>/Hold Control' incorporates:
   *  ActionPort: '<S109>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S61>/Hold' incorporates:
   *  ActionPort: '<S184>/Action Port'
   */
  /* SwitchCase: '<S106>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sqrt: '<S126>/Sqrt'
   *  Sqrt: '<S176>/Sqrt'
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S200>/Sqrt'
   *  Sqrt: '<S223>/Sqrt'
   *  Sqrt: '<S326>/Sqrt'
   *  Sqrt: '<S431>/Sqrt'
   *  Sqrt: '<S661>/Sqrt'
   *  Sum: '<S128>/Sum of Elements'
   *  Sum: '<S1>/Add'
   *  Sum: '<S201>/Sum of Elements'
   *  Sum: '<S433>/Sum of Elements'
   *  Sum: '<S663>/Sum of Elements'
   *  Switch: '<S109>/Switch'
   *  SwitchCase: '<S251>/Switch Case'
   *  SwitchCase: '<S252>/Switch Case'
   *  SwitchCase: '<S254>/Switch Case'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S47>/Switch Case'
   *  SwitchCase: '<S58>/Switch Case'
   *  SwitchCase: '<S59>/Switch Case'
   *  SwitchCase: '<S61>/Switch Case'
   */
  rtb_Divide_l_idx_2 = rtb_u_mm + rtb_Divide_or;

  /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
   *  ActionPort: '<S251>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S251>/Position' incorporates:
   *  ActionPort: '<S258>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
   *  ActionPort: '<S59>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S59>/Mission' incorporates:
   *  ActionPort: '<S155>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S155>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S159>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S61>/Return' incorporates:
   *  ActionPort: '<S186>/Action Port'
   */
  rtb_Divide_l_idx_3 = sqrtf(rtb_Divide_l_idx_2);

  /* End of Outputs for SubSystem: '<S61>/Return' */
  /* End of Outputs for SubSystem: '<S155>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S59>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */
  /* End of Outputs for SubSystem: '<S251>/Position' */
  /* End of Outputs for SubSystem: '<S47>/Assist' */
  /* End of Outputs for SubSystem: '<S61>/Hold' */
  /* End of Outputs for SubSystem: '<S106>/Hold Control' */
  /* End of Outputs for SubSystem: '<S58>/Position' */
  /* End of Outputs for SubSystem: '<S46>/Assist' */
  /* End of Outputs for SubSystem: '<S254>/Return' */
  /* End of Outputs for SubSystem: '<S47>/SubMode' */
  /* End of Outputs for SubSystem: '<S364>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S252>/Mission' */
  /* End of Outputs for SubSystem: '<S47>/Auto' */
  /* End of Outputs for SubSystem: '<S41>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S46>/SubMode' */
  /* End of Outputs for SubSystem: '<S41>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S39>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   */
  rtb_Divide_l_idx_0 *= rtb_Divide_l_idx_3;

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
  if (rtb_Divide_l_idx_0 > 100.0F) {
    rtb_Divide_l_idx_1 = 100.0F;
  } else if (rtb_Divide_l_idx_0 < 0.1F) {
    rtb_Divide_l_idx_1 = 0.1F;
  } else {
    rtb_Divide_l_idx_1 = rtb_Divide_l_idx_0;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Divide_l_idx_1;
  }

  FMS_B.DiscreteTimeIntegrator5 = FMS_DW.DiscreteTimeIntegrator5_DSTATE;

  /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */

  /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_fu = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

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
    FMS_B.Switch1 = rtb_DataTypeConversion1_fu;
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

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion_n = (VTOLMode)FMS_U.Pilot_Cmd.cmd_2;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S709>/Constant'
   *  Constant: '<S9>/ACCEPT_R'
   *  Constant: '<S9>/MC_ACCEPT_R'
   *  RelationalOperator: '<S709>/Compare'
   */
  if (FMS_B.DataTypeConversion_n == VTOLMode_Multicopter) {
    FMS_B.Switch = FMS_PARAM.MC_ACCEPT_R;
  } else {
    FMS_B.Switch = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S9>/Switch' */

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_m != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_h = rtb_Divide_l_idx_0;
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
  FMS_DW.M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_d0[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_ov[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_d0[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_ov[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_d0[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_ov[2] = FMS_B.Cmd_In.cur_waypoint[2];

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
        /* Disable for SwitchCase: '<S61>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S59>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S58>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S71>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S106>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S92>/Switch Case' */
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
      /* Disable for SwitchCase: '<S47>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S254>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S642>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S632>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S581>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S559>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S569>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S252>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S364>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S412>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* End of Disable for SubSystem: '<S364>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S251>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S351>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S266>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S284>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S300>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S325>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S312>/Switch Case' */
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
          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S59>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S58>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S71>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S106>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S92>/Switch Case' */
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
        /* Disable for SwitchCase: '<S47>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S254>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S642>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S632>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S581>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S559>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S569>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S252>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S364>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S412>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S402>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* End of Disable for SubSystem: '<S364>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S251>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S351>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S266>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S284>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S300>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S325>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S312>/Switch Case' */
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
          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S59>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S58>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S71>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S106>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S92>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S46>/SubMode' incorporates:
         *  ActionPort: '<S61>/Action Port'
         */
        /* SwitchCase: '<S61>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S61>/Takeoff' incorporates:
           *  ActionPort: '<S187>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S245>/TmpSignal ConversionAtSquareInport1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_n4[0] = FMS_U.INS_Out.vn;
          rtb_Divide_n4[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S246>/Sum of Elements' */
          d = rtb_u_mm + rtb_Divide_or;

          /* Math: '<S246>/Math Function1' incorporates:
           *  Sum: '<S246>/Sum of Elements'
           *
           * About '<S246>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S246>/Math Function1' */

          /* Switch: '<S246>/Switch' incorporates:
           *  Constant: '<S246>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S246>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Switch: '<S246>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S236>/NearbyRefWP' incorporates:
           *  Constant: '<S234>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Divide_l_idx_3);

          /* MATLAB Function: '<S236>/SearchL1RefWP' incorporates:
           *  Constant: '<S234>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Divide_l_idx_2);

          /* MATLAB Function: '<S236>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S236>/Switch1' incorporates:
           *  Constant: '<S239>/Constant'
           *  RelationalOperator: '<S239>/Compare'
           */
          if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S238>/Compare' incorporates:
             *  Constant: '<S238>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_2 >= 0.0F);

            /* Switch: '<S236>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S236>/Switch' */
          }

          /* End of Switch: '<S236>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S237>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S247>/Sum of Elements' incorporates:
           *  Math: '<S247>/Math Function'
           */
          d = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S247>/Math Function1' incorporates:
           *  Sum: '<S247>/Sum of Elements'
           *
           * About '<S247>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S247>/Math Function1' */

          /* Switch: '<S247>/Switch' incorporates:
           *  Constant: '<S247>/Constant'
           *  Product: '<S247>/Product'
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

          /* End of Switch: '<S247>/Switch' */

          /* Product: '<S246>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S249>/Sum of Elements' incorporates:
           *  Math: '<S249>/Math Function'
           *  SignalConversion: '<S249>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

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
            rtb_Switch_fz_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_fz_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S249>/Switch' */

          /* Product: '<S247>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S250>/Sum of Elements' incorporates:
           *  Math: '<S250>/Math Function'
           *  SignalConversion: '<S250>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S250>/Math Function1' incorporates:
           *  Sum: '<S250>/Sum of Elements'
           *
           * About '<S250>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S250>/Math Function1' */

          /* Switch: '<S250>/Switch' incorporates:
           *  Constant: '<S250>/Constant'
           *  Product: '<S250>/Product'
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

          /* End of Switch: '<S250>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S231>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_2 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S250>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S249>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S231>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S250>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S249>/Divide' */
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S231>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Switch_fz_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S231>/Divide' incorporates:
           *  Math: '<S232>/Square'
           *  Math: '<S233>/Square'
           *  Sqrt: '<S232>/Sqrt'
           *  Sqrt: '<S233>/Sqrt'
           *  Sum: '<S231>/Sum'
           *  Sum: '<S231>/Sum1'
           *  Sum: '<S232>/Sum of Elements'
           *  Sum: '<S233>/Sum of Elements'
           */
          rtb_Switch_fz_idx_0 = sqrtf(rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 +
            rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2) / sqrtf(d * d +
            rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0);

          /* Saturate: '<S231>/Saturation' */
          if (rtb_Switch_fz_idx_0 > 1.0F) {
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 < 0.0F) {
              rtb_Switch_fz_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S231>/Saturation' */

          /* Sum: '<S248>/Subtract' incorporates:
           *  Product: '<S248>/Multiply'
           *  Product: '<S248>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S244>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S244>/Sign1' */

          /* Switch: '<S244>/Switch2' incorporates:
           *  Constant: '<S244>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S244>/Switch2' */

          /* DotProduct: '<S244>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S244>/Acos' incorporates:
           *  DotProduct: '<S244>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S244>/Multiply' incorporates:
           *  Trigonometry: '<S244>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S243>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S243>/Saturation' */

          /* Sqrt: '<S245>/Sqrt' incorporates:
           *  Sum: '<S245>/Sum of Elements'
           */
          rtb_Divide_l_idx_3 = sqrtf(rtb_u_mm + rtb_Divide_or);

          /* BusAssignment: '<S187>/Bus Assignment' incorporates:
           *  Constant: '<S187>/Constant'
           *  Constant: '<S187>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S243>/Divide' incorporates:
           *  Constant: '<S234>/L1'
           *  Gain: '<S243>/Gain'
           *  Math: '<S243>/Square'
           *  Product: '<S243>/Multiply1'
           *  Trigonometry: '<S243>/Sin'
           */
          d = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S234>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S187>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S187>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S187>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S234>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S229>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S231>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S229>/Sum2'
           *  Sum: '<S231>/Add'
           *  Sum: '<S231>/Subtract'
           */
          d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                 FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_fz_idx_0 +
                FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S229>/Saturation1' */
          if (d > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S187>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (d < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S187>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S187>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S229>/Saturation1' */
          /* End of Outputs for SubSystem: '<S61>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S61>/Land' incorporates:
           *  ActionPort: '<S185>/Action Port'
           */
          /* BusAssignment: '<S185>/Bus Assignment1' incorporates:
           *  Constant: '<S185>/Constant'
           *  Constant: '<S185>/Constant1'
           *  Constant: '<S185>/Constant4'
           *  Constant: '<S185>/Constant5'
           *  Constant: '<S185>/Constant7'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S61>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S61>/Return' incorporates:
           *  ActionPort: '<S186>/Action Port'
           */
          /* Math: '<S224>/Math Function' */
          rtb_Divide_n4[0] = rtb_u_mm;
          rtb_Divide_n4[1] = rtb_Divide_or;

          /* Sum: '<S224>/Sum of Elements' */
          d = rtb_u_mm + rtb_Divide_or;

          /* Math: '<S224>/Math Function1' incorporates:
           *  Sum: '<S224>/Sum of Elements'
           *
           * About '<S224>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S224>/Math Function1' */

          /* Switch: '<S224>/Switch' incorporates:
           *  Constant: '<S224>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S224>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Switch: '<S224>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S214>/NearbyRefWP' incorporates:
           *  Constant: '<S212>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Divide_l_idx_2);

          /* MATLAB Function: '<S214>/SearchL1RefWP' incorporates:
           *  Constant: '<S212>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_u_mm);

          /* MATLAB Function: '<S214>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S214>/Switch1' incorporates:
           *  Constant: '<S217>/Constant'
           *  RelationalOperator: '<S217>/Compare'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S216>/Compare' incorporates:
             *  Constant: '<S216>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_u_mm >= 0.0F);

            /* Switch: '<S214>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S214>/Switch' */
          }

          /* End of Switch: '<S214>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S215>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S225>/Sum of Elements' incorporates:
           *  Math: '<S225>/Math Function'
           */
          d = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S225>/Math Function1' incorporates:
           *  Sum: '<S225>/Sum of Elements'
           *
           * About '<S225>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S225>/Math Function1' */

          /* Switch: '<S225>/Switch' incorporates:
           *  Constant: '<S225>/Constant'
           *  Product: '<S225>/Product'
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

          /* End of Switch: '<S225>/Switch' */

          /* Product: '<S224>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S227>/Sum of Elements' incorporates:
           *  Math: '<S227>/Math Function'
           *  SignalConversion: '<S227>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

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
            rtb_Switch_fz_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_fz_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S227>/Switch' */

          /* Product: '<S225>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S228>/Sum of Elements' incorporates:
           *  Math: '<S228>/Math Function'
           *  SignalConversion: '<S228>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S228>/Math Function1' incorporates:
           *  Sum: '<S228>/Sum of Elements'
           *
           * About '<S228>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S228>/Math Function1' */

          /* Switch: '<S228>/Switch' incorporates:
           *  Constant: '<S228>/Constant'
           *  Product: '<S228>/Product'
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

          /* End of Switch: '<S228>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S209>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_2 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S228>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S227>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S209>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S228>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S227>/Divide' */
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S209>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_mm = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S209>/Divide' incorporates:
           *  Math: '<S210>/Square'
           *  Math: '<S211>/Square'
           *  Sqrt: '<S210>/Sqrt'
           *  Sqrt: '<S211>/Sqrt'
           *  Sum: '<S209>/Sum'
           *  Sum: '<S209>/Sum1'
           *  Sum: '<S210>/Sum of Elements'
           *  Sum: '<S211>/Sum of Elements'
           */
          rtb_u_mm = sqrtf(rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2 + d * d) /
            sqrtf(rtb_Divide_or * rtb_Divide_or + rtb_u_mm * rtb_u_mm);

          /* Saturate: '<S209>/Saturation' */
          if (rtb_u_mm > 1.0F) {
            rtb_u_mm = 1.0F;
          } else {
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = 0.0F;
            }
          }

          /* End of Saturate: '<S209>/Saturation' */

          /* Sum: '<S226>/Subtract' incorporates:
           *  Product: '<S226>/Multiply'
           *  Product: '<S226>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S222>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S222>/Sign1' */

          /* Switch: '<S222>/Switch2' incorporates:
           *  Constant: '<S222>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S222>/Switch2' */

          /* DotProduct: '<S222>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S222>/Acos' incorporates:
           *  DotProduct: '<S222>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S222>/Multiply' incorporates:
           *  Trigonometry: '<S222>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S221>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S221>/Saturation' */

          /* BusAssignment: '<S186>/Bus Assignment1' incorporates:
           *  Constant: '<S186>/Constant2'
           *  Constant: '<S186>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S221>/Divide' incorporates:
           *  Constant: '<S212>/L1'
           *  Gain: '<S221>/Gain'
           *  Math: '<S221>/Square'
           *  Product: '<S221>/Multiply1'
           *  Trigonometry: '<S221>/Sin'
           */
          d = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S212>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S186>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S212>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S207>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S209>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S207>/Sum2'
           *  Sum: '<S209>/Add'
           *  Sum: '<S209>/Subtract'
           */
          d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                 FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_mm +
                FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S207>/Saturation1' */
          if (d > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (d < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S186>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S186>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S207>/Saturation1' */
          /* End of Outputs for SubSystem: '<S61>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S61>/Hold' incorporates:
             *  ActionPort: '<S184>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S61>/Switch Case' incorporates:
             *  Delay: '<S189>/Delay'
             *  Delay: '<S194>/start_vel'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S61>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S61>/Hold' incorporates:
           *  ActionPort: '<S184>/Action Port'
           */
          /* Math: '<S201>/Math Function1'
           *
           * About '<S201>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S201>/Math Function1' */

          /* Switch: '<S201>/Switch' incorporates:
           *  Constant: '<S201>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S201>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Switch: '<S201>/Switch' */

          /* Delay: '<S194>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S206>/Sum of Elements' incorporates:
           *  Delay: '<S194>/start_vel'
           *  Math: '<S206>/Math Function'
           */
          d = FMS_DW.start_vel_DSTATE_l[0] * FMS_DW.start_vel_DSTATE_l[0] +
            FMS_DW.start_vel_DSTATE_l[1] * FMS_DW.start_vel_DSTATE_l[1];

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
           *  Delay: '<S194>/start_vel'
           *  Product: '<S206>/Product'
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

          /* End of Switch: '<S206>/Switch' */

          /* Product: '<S201>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S204>/Sum of Elements' incorporates:
           *  Math: '<S204>/Math Function'
           *  SignalConversion: '<S204>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

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
            rtb_Switch_d0[0] = rtb_Divide_n4[1];
            rtb_Switch_d0[1] = rtb_Divide_n4[0];
            rtb_Switch_d0[2] = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_d0[0] = 0.0F;
            rtb_Switch_d0[1] = 0.0F;
            rtb_Switch_d0[2] = 1.0F;
          }

          /* End of Switch: '<S204>/Switch' */

          /* MinMax: '<S192>/Max' incorporates:
           *  Constant: '<S190>/L1'
           *  Constant: '<S190>/R'
           *  Gain: '<S192>/Gain'
           */
          rtb_Divide_l_idx_2 = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S192>/SearchL1RefWP' incorporates:
           *  Constant: '<S190>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
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

          /* End of MATLAB Function: '<S192>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S195>/Compare' incorporates:
           *  Constant: '<S195>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S192>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_dg[0] = rtb_Divide_or * rtb_Divide_or;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Divide_or = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_dg[1] = rtb_Divide_or * rtb_Divide_or;

          /* Switch: '<S192>/Switch' incorporates:
           *  Constant: '<S190>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S192>/OutRegionRegWP'
           *  Product: '<S206>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_u_mm = rtb_P_cg[0];
          } else if (rtb_P_dg[0] + rtb_P_dg[1] > rtb_Divide_l_idx_2 *
                     rtb_Divide_l_idx_2) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S192>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
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
          /* Sum: '<S193>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_h[0] = rtb_u_mm - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S192>/Switch' incorporates:
           *  Constant: '<S190>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S192>/OutRegionRegWP'
           *  Product: '<S206>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_u_mm = rtb_P_cg[1];
          } else if (rtb_P_dg[0] + rtb_P_dg[1] > rtb_Divide_l_idx_2 *
                     rtb_Divide_l_idx_2) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S192>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
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
          /* Sum: '<S193>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_h[1] = rtb_u_mm - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S202>/Sum of Elements' incorporates:
           *  Math: '<S202>/Math Function'
           */
          d = rtb_Square_h[0] * rtb_Square_h[0] + rtb_Square_h[1] *
            rtb_Square_h[1];

          /* Math: '<S202>/Math Function1' incorporates:
           *  Sum: '<S202>/Sum of Elements'
           *
           * About '<S202>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S202>/Math Function1' */

          /* Switch: '<S202>/Switch' incorporates:
           *  Constant: '<S202>/Constant'
           *  Product: '<S202>/Product'
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

          /* End of Switch: '<S202>/Switch' */

          /* Product: '<S202>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S205>/Sum of Elements' incorporates:
           *  Math: '<S205>/Math Function'
           *  SignalConversion: '<S205>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S205>/Math Function1' incorporates:
           *  Sum: '<S205>/Sum of Elements'
           *
           * About '<S205>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S205>/Math Function1' */

          /* Switch: '<S205>/Switch' incorporates:
           *  Constant: '<S205>/Constant'
           *  Product: '<S205>/Product'
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

          /* End of Switch: '<S205>/Switch' */

          /* Product: '<S205>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S204>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S205>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S204>/Divide' */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S203>/Subtract' incorporates:
           *  Product: '<S203>/Multiply'
           *  Product: '<S203>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S199>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S199>/Sign1' */

          /* Switch: '<S199>/Switch2' incorporates:
           *  Constant: '<S199>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S199>/Switch2' */

          /* DotProduct: '<S199>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S199>/Acos' incorporates:
           *  DotProduct: '<S199>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S199>/Multiply' incorporates:
           *  Trigonometry: '<S199>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S198>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S198>/Saturation' */

          /* Delay: '<S189>/Delay' incorporates:
           *  Gain: '<S191>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_ncp = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* BusAssignment: '<S184>/Bus Assignment' incorporates:
           *  Constant: '<S184>/Constant'
           *  Constant: '<S184>/Constant3'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S198>/Divide' incorporates:
           *  Constant: '<S190>/L1'
           *  Gain: '<S198>/Gain'
           *  Math: '<S198>/Square'
           *  Product: '<S198>/Multiply1'
           *  Trigonometry: '<S198>/Sin'
           */
          d = 2.0F * (rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3) * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S190>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S184>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S184>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S184>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S190>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S189>/Gain2' incorporates:
           *  Delay: '<S189>/Delay'
           *  Gain: '<S191>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S189>/Sum'
           */
          d = (FMS_DW.Delay_DSTATE_ncp - (-FMS_U.INS_Out.h_R)) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S189>/Saturation1' */
          if (d > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S184>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (d < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S184>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S184>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S189>/Saturation1' */

          /* Update for Delay: '<S194>/start_vel' */
          FMS_DW.icLoad_l = 0U;

          /* Update for Delay: '<S189>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S61>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S61>/Unknown' incorporates:
           *  ActionPort: '<S188>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S61>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S46>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
         *  ActionPort: '<S59>/Action Port'
         */
        /* SwitchCase: '<S59>/Switch Case' incorporates:
         *  RelationalOperator: '<S158>/FixPt Relational Operator'
         *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S158>/Delay Input1'
         *
         * Block description for '<S158>/Delay Input1':
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
          /* Outputs for IfAction SubSystem: '<S59>/Offboard' incorporates:
           *  ActionPort: '<S156>/Action Port'
           */
          /* BusAssignment: '<S156>/Bus Assignment' incorporates:
           *  Constant: '<S156>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S59>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S59>/Mission' incorporates:
             *  ActionPort: '<S155>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S59>/Switch Case' incorporates:
             *  UnitDelay: '<S158>/Delay Input1'
             *
             * Block description for '<S158>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S59>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Mission' incorporates:
           *  ActionPort: '<S155>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S155>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S159>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S177>/Math Function' incorporates:
           *  RelationalOperator: '<S158>/FixPt Relational Operator'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S158>/Delay Input1'
           *
           * Block description for '<S158>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Divide_n4[0] = rtb_u_mm;
          rtb_Divide_n4[1] = rtb_Divide_or;

          /* Sum: '<S177>/Sum of Elements' */
          d = rtb_u_mm + rtb_Divide_or;

          /* Math: '<S177>/Math Function1' incorporates:
           *  Sum: '<S177>/Sum of Elements'
           *
           * About '<S177>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S177>/Math Function1' */

          /* Switch: '<S177>/Switch' incorporates:
           *  Constant: '<S177>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S177>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Switch: '<S177>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S167>/NearbyRefWP' incorporates:
           *  Constant: '<S165>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_n4,
                          &rtb_Divide_l_idx_2);

          /* MATLAB Function: '<S167>/SearchL1RefWP' incorporates:
           *  Constant: '<S165>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_u_mm);

          /* MATLAB Function: '<S167>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_dg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S167>/Switch1' incorporates:
           *  Constant: '<S170>/Constant'
           *  RelationalOperator: '<S170>/Compare'
           */
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_n4[0];
            rtb_P_cg[1] = rtb_Divide_n4[1];
          } else {
            /* RelationalOperator: '<S169>/Compare' incorporates:
             *  Constant: '<S169>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_u_mm >= 0.0F);

            /* Switch: '<S167>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_P_cg[0] = rtb_P_dg[0];
              rtb_P_cg[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S167>/Switch' */
          }

          /* End of Switch: '<S167>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S168>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_n4[0] = rtb_P_cg[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_n4[1] = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S178>/Sum of Elements' incorporates:
           *  Math: '<S178>/Math Function'
           */
          d = rtb_Divide_n4[0] * rtb_Divide_n4[0] + rtb_Divide_n4[1] *
            rtb_Divide_n4[1];

          /* Math: '<S178>/Math Function1' incorporates:
           *  Sum: '<S178>/Sum of Elements'
           *
           * About '<S178>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S178>/Math Function1' */

          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S178>/Constant'
           *  Product: '<S178>/Product'
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

          /* End of Switch: '<S178>/Switch' */

          /* Product: '<S177>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S180>/Sum of Elements' incorporates:
           *  Math: '<S180>/Math Function'
           *  SignalConversion: '<S180>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

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
            rtb_Switch_fz_idx_0 = rtb_Divide_n4[1];
            rtb_Switch_fz_idx_1 = rtb_Divide_n4[0];
            rtb_Switch_fz_idx_2 = rtb_Divide_l_idx_2;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S180>/Switch' */

          /* Product: '<S178>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S181>/Sum of Elements' incorporates:
           *  Math: '<S181>/Math Function'
           *  SignalConversion: '<S181>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S181>/Math Function1' incorporates:
           *  Sum: '<S181>/Sum of Elements'
           *
           * About '<S181>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
          } else {
            rtb_Divide_l_idx_2 = sqrtf(d);
          }

          /* End of Math: '<S181>/Math Function1' */

          /* Switch: '<S181>/Switch' incorporates:
           *  Constant: '<S181>/Constant'
           *  Product: '<S181>/Product'
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

          /* End of Switch: '<S181>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S162>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_2 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S181>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S180>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S162>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S181>/Divide' */
          rtb_Divide_n4[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S180>/Divide' */
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S162>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_mm = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S162>/Divide' incorporates:
           *  Math: '<S163>/Square'
           *  Math: '<S164>/Square'
           *  Sqrt: '<S163>/Sqrt'
           *  Sqrt: '<S164>/Sqrt'
           *  Sum: '<S162>/Sum'
           *  Sum: '<S162>/Sum1'
           *  Sum: '<S163>/Sum of Elements'
           *  Sum: '<S164>/Sum of Elements'
           */
          rtb_u_mm = sqrtf(rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2 + d * d) /
            sqrtf(rtb_Divide_or * rtb_Divide_or + rtb_u_mm * rtb_u_mm);

          /* Saturate: '<S162>/Saturation' */
          if (rtb_u_mm > 1.0F) {
            rtb_u_mm = 1.0F;
          } else {
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = 0.0F;
            }
          }

          /* End of Saturate: '<S162>/Saturation' */

          /* Sum: '<S179>/Subtract' incorporates:
           *  Product: '<S179>/Multiply'
           *  Product: '<S179>/Multiply1'
           */
          rtb_Divide_l_idx_2 = rtb_Divide_n4[0] * rtb_P_cg[1] - rtb_Divide_n4[1]
            * rtb_P_cg[0];

          /* Signum: '<S175>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S175>/Sign1' */

          /* Switch: '<S175>/Switch2' incorporates:
           *  Constant: '<S175>/Constant4'
           */
          if (rtb_Divide_l_idx_2 == 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }

          /* End of Switch: '<S175>/Switch2' */

          /* DotProduct: '<S175>/Dot Product' */
          rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_Divide_n4[0] + rtb_P_cg[1] *
            rtb_Divide_n4[1];

          /* Trigonometry: '<S175>/Acos' incorporates:
           *  DotProduct: '<S175>/Dot Product'
           */
          if (rtb_Switch_fz_idx_1 > 1.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 < -1.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            }
          }

          /* Product: '<S175>/Multiply' incorporates:
           *  Trigonometry: '<S175>/Acos'
           */
          rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

          /* Saturate: '<S174>/Saturation' */
          if (rtb_Divide_l_idx_2 > 1.57079637F) {
            rtb_Divide_l_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.57079637F) {
              rtb_Divide_l_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S174>/Saturation' */

          /* BusAssignment: '<S159>/Bus Assignment' incorporates:
           *  Constant: '<S159>/Constant'
           *  Constant: '<S159>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S174>/Divide' incorporates:
           *  Constant: '<S165>/L1'
           *  Gain: '<S174>/Gain'
           *  Math: '<S174>/Square'
           *  Product: '<S174>/Multiply1'
           *  Trigonometry: '<S174>/Sin'
           */
          d = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F * arm_sin_f32
            (rtb_Divide_l_idx_2) / FMS_PARAM.FW_L1;

          /* Saturate: '<S165>/Saturation1' */
          if (d > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (d < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = d;
          }

          /* End of Saturate: '<S165>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S160>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S162>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S160>/Sum2'
           *  Sum: '<S162>/Add'
           *  Sum: '<S162>/Subtract'
           */
          d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                 FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_mm +
                FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S160>/Saturation1' */
          if (d > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (d < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = d;
          }

          /* End of Saturate: '<S160>/Saturation1' */
          /* End of Outputs for SubSystem: '<S155>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S158>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S158>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S59>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S59>/Unknown' incorporates:
           *  ActionPort: '<S157>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S59>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S46>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S46>/Assist' incorporates:
         *  ActionPort: '<S58>/Action Port'
         */
        /* SwitchCase: '<S58>/Switch Case' */
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
            /* Disable for SwitchCase: '<S71>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S106>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S92>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_as) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S58>/Stabilize' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S58>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S148>/Integrator'
             *  DiscreteIntegrator: '<S148>/Integrator1'
             *  DiscreteIntegrator: '<S149>/Integrator'
             *  DiscreteIntegrator: '<S149>/Integrator1'
             *  DiscreteIntegrator: '<S153>/Integrator'
             *  DiscreteIntegrator: '<S153>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S58>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Stabilize' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* Product: '<S150>/Multiply1' incorporates:
           *  Constant: '<S150>/const1'
           *  DiscreteIntegrator: '<S148>/Integrator'
           */
          rtb_Switch_fz_idx_2 = FMS_DW.Integrator_DSTATE_a * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S146>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S146>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S150>/Add' incorporates:
           *  DiscreteIntegrator: '<S148>/Integrator1'
           *  Gain: '<S143>/Gain'
           *  Gain: '<S146>/Gain'
           *  Sum: '<S148>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Switch_fz_idx_2;

          /* Signum: '<S150>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3;
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
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_Switch_fz_idx_2;

          /* Sum: '<S150>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - rtb_Switch_fz_idx_1) +
            rtb_Switch_fz_idx_2;

          /* Sum: '<S150>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_ny;

          /* Sum: '<S150>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_ny;

          /* Signum: '<S150>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign1' */

          /* Signum: '<S150>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign2' */

          /* Sum: '<S150>/Add5' incorporates:
           *  Gain: '<S150>/Gain2'
           *  Product: '<S150>/Multiply4'
           *  Sum: '<S150>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) *
            0.5F * rtb_u_mm;

          /* BusAssignment: '<S65>/Bus Assignment' incorporates:
           *  Constant: '<S65>/Constant'
           *  DiscreteIntegrator: '<S148>/Integrator1'
           *  DiscreteIntegrator: '<S149>/Integrator1'
           *  DiscreteIntegrator: '<S153>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S145>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S145>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S65>/Bus Assignment' incorporates:
           *  Constant: '<S145>/Constant5'
           *  Gain: '<S145>/Gain2'
           *  Sum: '<S145>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * d), 65536.0F) + 1000U);

          /* Product: '<S154>/Multiply1' incorporates:
           *  Constant: '<S154>/const1'
           *  DiscreteIntegrator: '<S153>/Integrator'
           */
          rtb_Switch_fz_idx_2 = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S152>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S152>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S154>/Add' incorporates:
           *  DiscreteIntegrator: '<S153>/Integrator1'
           *  Gain: '<S144>/Gain1'
           *  Gain: '<S152>/Gain'
           *  Sum: '<S153>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Switch_fz_idx_2;

          /* Signum: '<S154>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S154>/Sign' */

          /* Sum: '<S154>/Add2' incorporates:
           *  Abs: '<S154>/Abs'
           *  Gain: '<S154>/Gain'
           *  Gain: '<S154>/Gain1'
           *  Product: '<S154>/Multiply2'
           *  Product: '<S154>/Multiply3'
           *  Sqrt: '<S154>/Sqrt'
           *  Sum: '<S154>/Add1'
           *  Sum: '<S154>/Subtract'
           */
          rtb_Subtract3_d = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_hr) * FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F * d +
            rtb_Switch_fz_idx_2;

          /* Sum: '<S154>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_0 - rtb_Subtract3_d) +
            rtb_Switch_fz_idx_2;

          /* Sum: '<S154>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_0 + FMS_ConstB.d_hr;

          /* Sum: '<S154>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_hr;

          /* Signum: '<S154>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign1' */

          /* Signum: '<S154>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign2' */

          /* Sum: '<S154>/Add5' incorporates:
           *  Gain: '<S154>/Gain2'
           *  Product: '<S154>/Multiply4'
           *  Sum: '<S154>/Subtract2'
           */
          rtb_Subtract3_d += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_0) * 0.5F *
            rtb_Divide_l_idx_3;

          /* Sum: '<S154>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Subtract3_d + FMS_ConstB.d_hr;

          /* Sum: '<S154>/Subtract3' */
          rtb_u_mm = rtb_Subtract3_d - FMS_ConstB.d_hr;

          /* Product: '<S154>/Divide' */
          rtb_Divide_or = rtb_Subtract3_d / FMS_ConstB.d_hr;

          /* Signum: '<S154>/Sign5' incorporates:
           *  Signum: '<S154>/Sign6'
           */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S154>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Subtract3_d > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S154>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Subtract3_d;

            /* Signum: '<S154>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Subtract3_d;
          }

          /* End of Signum: '<S154>/Sign5' */

          /* Product: '<S151>/Multiply1' incorporates:
           *  Constant: '<S151>/const1'
           *  DiscreteIntegrator: '<S149>/Integrator'
           */
          rtb_Subtract3_d = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S147>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S147>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S151>/Add' incorporates:
           *  DiscreteIntegrator: '<S149>/Integrator1'
           *  Gain: '<S143>/Gain1'
           *  Gain: '<S147>/Gain'
           *  Sum: '<S149>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * d * -FMS_PARAM.FW_PITCH_LIM) + rtb_Subtract3_d;

          /* Signum: '<S151>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S151>/Sign' */

          /* Sum: '<S151>/Add2' incorporates:
           *  Abs: '<S151>/Abs'
           *  Gain: '<S151>/Gain'
           *  Gain: '<S151>/Gain1'
           *  Product: '<S151>/Multiply2'
           *  Product: '<S151>/Multiply3'
           *  Sqrt: '<S151>/Sqrt'
           *  Sum: '<S151>/Add1'
           *  Sum: '<S151>/Subtract'
           */
          rtb_Switch_fz_idx_2 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_my) * FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F * d +
            rtb_Subtract3_d;

          /* Sum: '<S151>/Add4' */
          rtb_Subtract3_d += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_2;

          /* Sum: '<S151>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_my;

          /* Sum: '<S151>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_my;

          /* Signum: '<S151>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign1' */

          /* Signum: '<S151>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign2' */

          /* Sum: '<S151>/Add5' incorporates:
           *  Gain: '<S151>/Gain2'
           *  Product: '<S151>/Multiply4'
           *  Sum: '<S151>/Subtract2'
           */
          rtb_Switch_fz_idx_2 += (d - rtb_Switch_fz_idx_0) * 0.5F *
            rtb_Subtract3_d;

          /* Update for DiscreteIntegrator: '<S148>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S148>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Sum: '<S150>/Subtract3' */
          d = rtb_Switch_fz_idx_1 - FMS_ConstB.d_ny;

          /* Sum: '<S150>/Add6' */
          rtb_Subtract3_d = rtb_Switch_fz_idx_1 + FMS_ConstB.d_ny;

          /* Signum: '<S150>/Sign5' incorporates:
           *  Signum: '<S150>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;

            /* Signum: '<S150>/Sign6' */
            D = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Switch_fz_idx_0 = 1.0F;

            /* Signum: '<S150>/Sign6' */
            D = 1.0F;
          } else {
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;

            /* Signum: '<S150>/Sign6' */
            D = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S150>/Sign5' */

          /* Signum: '<S150>/Sign3' */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Subtract3_d = -1.0F;
          } else {
            if (rtb_Subtract3_d > 0.0F) {
              rtb_Subtract3_d = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign3' */

          /* Signum: '<S150>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign4' */

          /* Update for DiscreteIntegrator: '<S148>/Integrator' incorporates:
           *  Constant: '<S150>/const'
           *  Gain: '<S150>/Gain3'
           *  Product: '<S150>/Divide'
           *  Product: '<S150>/Multiply5'
           *  Product: '<S150>/Multiply6'
           *  Sum: '<S150>/Subtract4'
           *  Sum: '<S150>/Subtract5'
           *  Sum: '<S150>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_ny
            - rtb_Switch_fz_idx_0) * FMS_ConstB.Gain4_ko * ((rtb_Subtract3_d - d)
            * 0.5F) - D * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S149>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S149>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S153>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S153>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S154>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign3' */

          /* Signum: '<S154>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign4' */

          /* Update for DiscreteIntegrator: '<S153>/Integrator' incorporates:
           *  Constant: '<S154>/const'
           *  Gain: '<S154>/Gain3'
           *  Product: '<S154>/Multiply5'
           *  Product: '<S154>/Multiply6'
           *  Sum: '<S154>/Subtract4'
           *  Sum: '<S154>/Subtract5'
           *  Sum: '<S154>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 15.707963F) * 0.004F;

          /* Sum: '<S151>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_2 - FMS_ConstB.d_my;

          /* Sum: '<S151>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_2 + FMS_ConstB.d_my;

          /* Signum: '<S151>/Sign5' incorporates:
           *  Signum: '<S151>/Sign6'
           */
          if (rtb_Switch_fz_idx_2 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S151>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_2 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S151>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_2;

            /* Signum: '<S151>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_2;
          }

          /* End of Signum: '<S151>/Sign5' */

          /* Signum: '<S151>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign3' */

          /* Signum: '<S151>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign4' */

          /* Update for DiscreteIntegrator: '<S149>/Integrator' incorporates:
           *  Constant: '<S151>/const'
           *  Gain: '<S151>/Gain3'
           *  Product: '<S151>/Divide'
           *  Product: '<S151>/Multiply5'
           *  Product: '<S151>/Multiply6'
           *  Sum: '<S151>/Subtract4'
           *  Sum: '<S151>/Subtract5'
           *  Sum: '<S151>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_Switch_fz_idx_2 / FMS_ConstB.d_my
            - rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_k2 * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S58>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S58>/Altitude' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S58>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S83>/Integrator'
             *  DiscreteIntegrator: '<S83>/Integrator1'
             *  DiscreteIntegrator: '<S86>/Integrator'
             *  DiscreteIntegrator: '<S86>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S58>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S58>/Altitude' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S58>/Switch Case' incorporates:
             *  Chart: '<S72>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S58>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Altitude' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S72>/Motion Status' incorporates:
           *  Abs: '<S72>/Abs'
           *  Abs: '<S72>/Abs1'
           *  Constant: '<S80>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S80>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S71>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S71>/Hold Control' incorporates:
               *  ActionPort: '<S74>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S71>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S71>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S71>/Hold Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S71>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S71>/Brake Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S71>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S71>/Move Control' incorporates:
               *  ActionPort: '<S75>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S71>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S71>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S71>/Move Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S71>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S71>/Switch Case' */

          /* BusAssignment: '<S63>/Bus Assignment' incorporates:
           *  Constant: '<S63>/Constant'
           *  DiscreteIntegrator: '<S83>/Integrator1'
           *  DiscreteIntegrator: '<S86>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S67>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S67>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S63>/Bus Assignment' incorporates:
           *  Gain: '<S67>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * d;

          /* Saturate: '<S71>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S63>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S63>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S63>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S71>/Saturation1' */

          /* Product: '<S87>/Multiply1' incorporates:
           *  Constant: '<S87>/const1'
           *  DiscreteIntegrator: '<S86>/Integrator'
           */
          rtb_Switch_fz_idx_0 = FMS_DW.Integrator_DSTATE_e * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S85>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S85>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S87>/Add' incorporates:
           *  DiscreteIntegrator: '<S86>/Integrator1'
           *  Gain: '<S70>/Gain1'
           *  Gain: '<S85>/Gain'
           *  Sum: '<S86>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Switch_fz_idx_0;

          /* Signum: '<S87>/Sign' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S87>/Sign' */

          /* Sum: '<S87>/Add2' incorporates:
           *  Abs: '<S87>/Abs'
           *  Gain: '<S87>/Gain'
           *  Gain: '<S87>/Gain1'
           *  Product: '<S87>/Multiply2'
           *  Product: '<S87>/Multiply3'
           *  Sqrt: '<S87>/Sqrt'
           *  Sum: '<S87>/Add1'
           *  Sum: '<S87>/Subtract'
           */
          rtb_Sign5_mn = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_1) +
            FMS_ConstB.d_nt) * FMS_ConstB.d_nt) - FMS_ConstB.d_nt) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_Switch_fz_idx_0;

          /* Sum: '<S87>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_1 - rtb_Sign5_mn) +
            rtb_Switch_fz_idx_0;

          /* Sum: '<S87>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 + FMS_ConstB.d_nt;

          /* Sum: '<S87>/Subtract1' */
          rtb_Switch_fz_idx_1 -= FMS_ConstB.d_nt;

          /* Signum: '<S87>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S87>/Sign1' */

          /* Signum: '<S87>/Sign2' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S87>/Sign2' */

          /* Sum: '<S87>/Add5' incorporates:
           *  Gain: '<S87>/Gain2'
           *  Product: '<S87>/Multiply4'
           *  Sum: '<S87>/Subtract2'
           */
          rtb_Sign5_mn += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_1) * 0.5F *
            rtb_Divide_l_idx_3;

          /* Sum: '<S87>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Sign5_mn + FMS_ConstB.d_nt;

          /* Sum: '<S87>/Subtract3' */
          rtb_u_mm = rtb_Sign5_mn - FMS_ConstB.d_nt;

          /* Product: '<S87>/Divide' */
          rtb_Switch_fz_idx_2 = rtb_Sign5_mn / FMS_ConstB.d_nt;

          /* Signum: '<S87>/Sign5' incorporates:
           *  Signum: '<S87>/Sign6'
           */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S87>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Sign5_mn > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S87>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Sign5_mn;

            /* Signum: '<S87>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Sign5_mn;
          }

          /* End of Signum: '<S87>/Sign5' */

          /* Product: '<S84>/Multiply1' incorporates:
           *  Constant: '<S84>/const1'
           *  DiscreteIntegrator: '<S83>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S82>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S82>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S84>/Add' incorporates:
           *  DiscreteIntegrator: '<S83>/Integrator1'
           *  Gain: '<S69>/Gain'
           *  Gain: '<S82>/Gain'
           *  Sum: '<S83>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.FW_ROLL_LIM) + rtb_Sign5_mn;

          /* Signum: '<S84>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
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
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_bi) * FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S84>/Add4' */
          rtb_Sign5_mn += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1;

          /* Sum: '<S84>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_bi;

          /* Sum: '<S84>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_bi;

          /* Signum: '<S84>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign1' */

          /* Signum: '<S84>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign2' */

          /* Sum: '<S84>/Add5' incorporates:
           *  Gain: '<S84>/Gain2'
           *  Product: '<S84>/Multiply4'
           *  Sum: '<S84>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (d - rtb_Switch_fz_idx_0) * 0.5F * rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S83>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S83>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S86>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S86>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Signum: '<S87>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S87>/Sign3' */

          /* Signum: '<S87>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S87>/Sign4' */

          /* Update for DiscreteIntegrator: '<S86>/Integrator' incorporates:
           *  Constant: '<S87>/const'
           *  Gain: '<S87>/Gain3'
           *  Product: '<S87>/Multiply5'
           *  Product: '<S87>/Multiply6'
           *  Sum: '<S87>/Subtract4'
           *  Sum: '<S87>/Subtract5'
           *  Sum: '<S87>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_kf * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 15.707963F) * 0.004F;

          /* Sum: '<S84>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 - FMS_ConstB.d_bi;

          /* Sum: '<S84>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_1 + FMS_ConstB.d_bi;

          /* Signum: '<S84>/Sign5' incorporates:
           *  Signum: '<S84>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S84>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S84>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;

            /* Signum: '<S84>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S84>/Sign5' */

          /* Signum: '<S84>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign3' */

          /* Signum: '<S84>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_bi
            - rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_d1 * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S58>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_as != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S58>/Position' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S58>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S104>/Integrator'
             *  DiscreteIntegrator: '<S104>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S58>/Position' */

            /* SystemReset for IfAction SubSystem: '<S58>/Position' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S58>/Switch Case' incorporates:
             *  Chart: '<S107>/Motion State'
             *  Chart: '<S93>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_DW.temporalCounter_i1_ie = 0U;
            FMS_DW.is_active_c26_FMS = 0U;
            FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S58>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Position' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          /* Outputs for IfAction SubSystem: '<S106>/Hold Control' incorporates:
           *  ActionPort: '<S109>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S106>/Switch Case' incorporates:
           *  Gain: '<S141>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S135>/Trigonometric Function1'
           *  Trigonometry: '<S135>/Trigonometric Function3'
           *  Trigonometry: '<S142>/Trigonometric Function1'
           *  Trigonometry: '<S142>/Trigonometric Function3'
           */
          rtb_u_mm = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S106>/Hold Control' */

          /* Trigonometry: '<S142>/Trigonometric Function1' */
          rtb_MatrixConcatenate1_i[0] = rtb_u_mm;

          /* Outputs for IfAction SubSystem: '<S106>/Hold Control' incorporates:
           *  ActionPort: '<S109>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S106>/Switch Case' incorporates:
           *  Gain: '<S141>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S135>/Trigonometric Function'
           *  Trigonometry: '<S142>/Trigonometric Function'
           *  Trigonometry: '<S142>/Trigonometric Function2'
           */
          rtb_Switch_fz_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S106>/Hold Control' */

          /* Trigonometry: '<S142>/Trigonometric Function' */
          rtb_MatrixConcatenate1_i[1] = rtb_Switch_fz_idx_0;

          /* SignalConversion: '<S142>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S142>/Constant3'
           */
          rtb_MatrixConcatenate1_i[2] = 0.0F;

          /* Gain: '<S142>/Gain' */
          rtb_MatrixConcatenate1_i[3] = -rtb_Switch_fz_idx_0;

          /* Trigonometry: '<S142>/Trigonometric Function3' */
          rtb_MatrixConcatenate1_i[4] = rtb_u_mm;

          /* SignalConversion: '<S142>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S142>/Constant4'
           */
          rtb_MatrixConcatenate1_i[5] = 0.0F;

          /* SignalConversion: '<S142>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_g[0];
          rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_g[1];
          rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_g[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S93>/Motion Status' incorporates:
           *  Abs: '<S93>/Abs'
           *  Abs: '<S93>/Abs1'
           *  Constant: '<S101>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S101>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* RelationalOperator: '<S139>/Compare' incorporates:
           *  Abs: '<S107>/Abs1'
           *  Constant: '<S139>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S107>/Motion State' incorporates:
           *  Abs: '<S107>/Abs'
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

              /* Product: '<S107>/Multiply' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_MatrixConcatenate1_i_0[rtb_n] =
                  rtb_MatrixConcatenate1_i[rtb_n + 6] * FMS_U.INS_Out.vd +
                  (rtb_MatrixConcatenate1_i[rtb_n + 3] * FMS_U.INS_Out.ve +
                   rtb_MatrixConcatenate1_i[rtb_n] * FMS_U.INS_Out.vn);

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              }

              /* End of Product: '<S107>/Multiply' */
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

          /* End of Chart: '<S107>/Motion State' */

          /* SwitchCase: '<S106>/Switch Case' incorporates:
           *  MATLAB Function: '<S112>/SearchL1RefWP'
           *  Product: '<S134>/Divide'
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
              /* InitializeConditions for IfAction SubSystem: '<S106>/Hold Control' incorporates:
               *  ActionPort: '<S109>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S106>/Switch Case' incorporates:
               *  Delay: '<S114>/start_vel'
               *  Delay: '<S114>/start_wp'
               */
              FMS_DW.icLoad_g = 1U;
              FMS_DW.icLoad_e = 1U;

              /* End of InitializeConditions for SubSystem: '<S106>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S106>/Hold Control' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* Trigonometry: '<S135>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_u_mm;

            /* Trigonometry: '<S135>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S135>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S135>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S135>/Gain' incorporates:
             *  Gain: '<S133>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S135>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S135>/Trigonometric Function3' */
            rtb_Transpose[4] = rtb_u_mm;

            /* SignalConversion: '<S135>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S135>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* SignalConversion: '<S135>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_jn[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_jn[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_jn[2];

            /* Math: '<S114>/Transpose' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_i[3 * rtb_n] = rtb_Transpose[rtb_n];
              rtb_MatrixConcatenate1_i[1 + 3 * rtb_n] = rtb_Transpose[rtb_n + 3];
              rtb_MatrixConcatenate1_i[2 + 3 * rtb_n] = rtb_Transpose[rtb_n + 6];
            }

            for (rtb_n = 0; rtb_n < 9; rtb_n++) {
              rtb_Transpose[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n];
            }

            /* End of Math: '<S114>/Transpose' */

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Product: '<S116>/Divide' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_u_mm = FMS_U.INS_Out.quat[0] / d;
            rtb_Switch_fz_idx_2 = FMS_U.INS_Out.quat[1] / d;
            rtb_Switch_fz_idx_0 = FMS_U.INS_Out.quat[2] / d;
            d = FMS_U.INS_Out.quat[3] / d;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S117>/Subtract' incorporates:
             *  Math: '<S117>/Square'
             *  Math: '<S117>/Square1'
             *  Math: '<S117>/Square2'
             *  Math: '<S117>/Square3'
             *  Sum: '<S117>/Add'
             *  Sum: '<S117>/Add1'
             */
            rtb_MatrixConcatenate1_i[0] = (rtb_u_mm * rtb_u_mm +
              rtb_Switch_fz_idx_2 * rtb_Switch_fz_idx_2) - (rtb_Switch_fz_idx_0 *
              rtb_Switch_fz_idx_0 + d * d);

            /* Gain: '<S117>/Gain' incorporates:
             *  Product: '<S117>/Multiply'
             *  Product: '<S117>/Multiply1'
             *  Sum: '<S117>/Subtract1'
             */
            rtb_MatrixConcatenate1_i[1] = (rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_0 - rtb_u_mm * d) * 2.0F;

            /* Gain: '<S117>/Gain1' incorporates:
             *  Product: '<S117>/Multiply2'
             *  Product: '<S117>/Multiply3'
             *  Sum: '<S117>/Add2'
             */
            rtb_MatrixConcatenate1_i[2] = (rtb_Switch_fz_idx_2 * d + rtb_u_mm *
              rtb_Switch_fz_idx_0) * 2.0F;

            /* Gain: '<S118>/Gain' incorporates:
             *  Product: '<S118>/Multiply'
             *  Product: '<S118>/Multiply1'
             *  Sum: '<S118>/Add3'
             */
            rtb_MatrixConcatenate1_i[3] = (rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_0 + rtb_u_mm * d) * 2.0F;

            /* Sum: '<S118>/Subtract' incorporates:
             *  Math: '<S118>/Square'
             *  Math: '<S118>/Square1'
             *  Math: '<S118>/Square2'
             *  Math: '<S118>/Square3'
             *  Sum: '<S118>/Add'
             *  Sum: '<S118>/Add1'
             */
            rtb_MatrixConcatenate1_i[4] = (rtb_u_mm * rtb_u_mm +
              rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0) - (rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_2 + d * d);

            /* Gain: '<S118>/Gain1' incorporates:
             *  Product: '<S118>/Multiply2'
             *  Product: '<S118>/Multiply3'
             *  Sum: '<S118>/Subtract1'
             */
            rtb_MatrixConcatenate1_i[5] = (rtb_Switch_fz_idx_0 * d - rtb_u_mm *
              rtb_Switch_fz_idx_2) * 2.0F;

            /* Gain: '<S119>/Gain' incorporates:
             *  Product: '<S119>/Multiply'
             *  Product: '<S119>/Multiply1'
             *  Sum: '<S119>/Subtract2'
             */
            rtb_MatrixConcatenate1_i[6] = (rtb_Switch_fz_idx_2 * d - rtb_u_mm *
              rtb_Switch_fz_idx_0) * 2.0F;

            /* Gain: '<S119>/Gain1' incorporates:
             *  Product: '<S119>/Multiply2'
             *  Product: '<S119>/Multiply3'
             *  Sum: '<S119>/Add2'
             */
            rtb_MatrixConcatenate1_i[7] = (rtb_Switch_fz_idx_0 * d + rtb_u_mm *
              rtb_Switch_fz_idx_2) * 2.0F;

            /* Sum: '<S119>/Subtract' incorporates:
             *  Math: '<S119>/Square'
             *  Math: '<S119>/Square1'
             *  Math: '<S119>/Square2'
             *  Math: '<S119>/Square3'
             *  Sum: '<S119>/Add'
             *  Sum: '<S119>/Add1'
             */
            rtb_MatrixConcatenate1_i[8] = (rtb_u_mm * rtb_u_mm + d * d) -
              (rtb_Switch_fz_idx_2 * rtb_Switch_fz_idx_2 + rtb_Switch_fz_idx_0 *
               rtb_Switch_fz_idx_0);

            /* Delay: '<S114>/start_vel' incorporates:
             *  Product: '<S114>/Multiply'
             */
            if (FMS_DW.icLoad_g != 0) {
              /* Product: '<S114>/Multiply' */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n];
              }

              FMS_DW.start_vel_DSTATE[0] = rtb_MatrixConcatenate1_i_0[0];
              FMS_DW.start_vel_DSTATE[1] = rtb_MatrixConcatenate1_i_0[1];
            }

            /* Sum: '<S134>/Sum of Elements' incorporates:
             *  Delay: '<S114>/start_vel'
             *  Math: '<S134>/Math Function'
             */
            d = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
              FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

            /* Math: '<S134>/Math Function1' incorporates:
             *  Sum: '<S134>/Sum of Elements'
             *
             * About '<S134>/Math Function1':
             *  Operator: sqrt
             */
            if (d < 0.0F) {
              rtb_u_mm = -sqrtf(fabsf(d));
            } else {
              rtb_u_mm = sqrtf(d);
            }

            /* End of Math: '<S134>/Math Function1' */

            /* Switch: '<S134>/Switch' incorporates:
             *  Constant: '<S134>/Constant'
             *  Delay: '<S114>/start_vel'
             *  Product: '<S134>/Product'
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

            /* End of Switch: '<S134>/Switch' */

            /* Delay: '<S114>/start_wp' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            if (FMS_DW.icLoad_e != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S112>/SearchL1RefWP' incorporates:
             *  Delay: '<S114>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_u_mm = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Switch_fz_idx_0 = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S134>/Divide' */
            rtb_Divide_or = rtb_Switch_d0[0] / rtb_Switch_d0[2];

            /* MATLAB Function: '<S112>/SearchL1RefWP' */
            d = rtb_Divide_or * rtb_u_mm;
            rtb_Square_h[0] = rtb_Divide_or;

            /* Product: '<S134>/Divide' */
            rtb_Divide_or = rtb_Switch_d0[1] / rtb_Switch_d0[2];

            /* MATLAB Function: '<S112>/SearchL1RefWP' */
            d += rtb_Divide_or * rtb_Switch_fz_idx_0;
            rtb_Sign5_mn = 2.0F * d;
            d = rtb_u_mm * rtb_u_mm;
            rtb_u_mm = 0.0F;

            /* MATLAB Function: '<S112>/SearchL1RefWP' */
            d += rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0;
            rtb_Switch_fz_idx_0 = 0.0F;

            /* MATLAB Function: '<S112>/SearchL1RefWP' incorporates:
             *  Constant: '<S109>/L1'
             *  Delay: '<S114>/start_wp'
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
            /* MATLAB Function: '<S112>/OutRegionRefWP' incorporates:
             *  Delay: '<S114>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
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

            /* Product: '<S111>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n
                + 6] * FMS_U.INS_Out.vd + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                FMS_U.INS_Out.ve + rtb_MatrixConcatenate1_i[rtb_n] *
                FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Product: '<S111>/Multiply' */

            /* Signum: '<S111>/Sign' incorporates:
             *  Math: '<S127>/Square'
             *  Math: '<S128>/Math Function1'
             *  Math: '<S129>/Math Function'
             *  Sum: '<S113>/Subtract'
             *  Switch: '<S109>/Switch'
             *
             * About '<S128>/Math Function1':
             *  Operator: sqrt
             */
            if ((rtb_MatrixConcatenate1_i_0[0] < 0.0F) ||
                (rtb_MatrixConcatenate1_i_0[0] <= 0.0F)) {
              /* Switch: '<S109>/Switch' incorporates:
               *  Constant: '<S109>/Constant'
               */
              FMS_B.Merge_be = 0.0F;
            } else {
              if (rtb_Divide_l_idx_2 < 0.0F) {
                /* Math: '<S128>/Math Function1' incorporates:
                 *  Switch: '<S109>/Switch'
                 *
                 * About '<S128>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                /* Math: '<S128>/Math Function1' incorporates:
                 *  Switch: '<S109>/Switch'
                 *
                 * About '<S128>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* Switch: '<S128>/Switch' incorporates:
               *  Constant: '<S128>/Constant'
               *  Inport: '<Root>/INS_Out'
               *  Product: '<S128>/Product'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S109>/Switch'
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

              /* End of Switch: '<S128>/Switch' */

              /* Product: '<S128>/Divide' incorporates:
               *  Switch: '<S109>/Switch'
               */
              rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* RelationalOperator: '<S121>/Compare' incorporates:
               *  Constant: '<S121>/Constant'
               *  MATLAB Function: '<S112>/SearchL1RefWP'
               *  Switch: '<S109>/Switch'
               */
              rtb_FixPtRelationalOperator_me = (d > 0.0F);

              /* Switch: '<S112>/Switch' incorporates:
               *  Delay: '<S114>/start_wp'
               *  MATLAB Function: '<S112>/OutRegionRefWP'
               *  Switch: '<S109>/Switch'
               */
              if (!rtb_FixPtRelationalOperator_me) {
                rtb_u_mm = rtb_Switch_fz_idx_1 * rtb_Square_h[0] +
                  FMS_DW.start_wp_DSTATE[0];
                rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1 * rtb_Divide_or +
                  FMS_DW.start_wp_DSTATE[1];
              }

              /* End of Switch: '<S112>/Switch' */

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S113>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S109>/Switch'
               */
              D = rtb_u_mm - FMS_U.INS_Out.x_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              rtb_u_mm = D;
              rtb_P_dg[0] = D * D;

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S113>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  Math: '<S129>/Math Function'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S109>/Switch'
               */
              D = rtb_Switch_fz_idx_0 - FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

              /* Math: '<S129>/Math Function' incorporates:
               *  Math: '<S127>/Square'
               *  Switch: '<S109>/Switch'
               */
              d = D * D;

              /* Sum: '<S129>/Sum of Elements' incorporates:
               *  Math: '<S129>/Math Function'
               *  Switch: '<S109>/Switch'
               */
              rtb_Divide_l_idx_2 = d + rtb_P_dg[0];

              /* Math: '<S129>/Math Function1' incorporates:
               *  Sum: '<S129>/Sum of Elements'
               *  Switch: '<S109>/Switch'
               *
               * About '<S129>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* End of Math: '<S129>/Math Function1' */

              /* Switch: '<S129>/Switch' incorporates:
               *  Constant: '<S129>/Constant'
               *  Product: '<S129>/Product'
               *  Switch: '<S109>/Switch'
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

              /* End of Switch: '<S129>/Switch' */

              /* Product: '<S129>/Divide' incorporates:
               *  Switch: '<S109>/Switch'
               */
              rtb_P_dg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_u_mm *= rtb_u_mm;

              /* Product: '<S129>/Divide' incorporates:
               *  Math: '<S127>/Square'
               *  Switch: '<S109>/Switch'
               */
              rtb_P_dg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* Sum: '<S131>/Sum of Elements' incorporates:
               *  Math: '<S131>/Math Function'
               *  SignalConversion: '<S131>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S109>/Switch'
               */
              rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
                rtb_P_cg[0];

              /* Math: '<S131>/Math Function1' incorporates:
               *  Sum: '<S131>/Sum of Elements'
               *  Switch: '<S109>/Switch'
               *
               * About '<S131>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(rtb_Divide_l_idx_2));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(rtb_Divide_l_idx_2);
              }

              /* End of Math: '<S131>/Math Function1' */

              /* Switch: '<S131>/Switch' incorporates:
               *  Constant: '<S131>/Constant'
               *  Product: '<S131>/Product'
               *  Switch: '<S109>/Switch'
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

              /* End of Switch: '<S131>/Switch' */

              /* Product: '<S131>/Divide' incorporates:
               *  Switch: '<S109>/Switch'
               */
              rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* Sum: '<S132>/Sum of Elements' incorporates:
               *  Math: '<S132>/Math Function'
               *  SignalConversion: '<S132>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S109>/Switch'
               */
              rtb_Divide_l_idx_2 = rtb_P_dg[1] * rtb_P_dg[1] + rtb_P_dg[0] *
                rtb_P_dg[0];

              /* Math: '<S132>/Math Function1' incorporates:
               *  Sum: '<S132>/Sum of Elements'
               *  Switch: '<S109>/Switch'
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
               *  Switch: '<S109>/Switch'
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

              /* End of Switch: '<S132>/Switch' */

              /* Product: '<S132>/Divide' incorporates:
               *  Switch: '<S109>/Switch'
               */
              rtb_P_dg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_P_dg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

              /* Sum: '<S130>/Subtract' incorporates:
               *  Product: '<S130>/Multiply'
               *  Product: '<S130>/Multiply1'
               *  Switch: '<S109>/Switch'
               */
              rtb_Divide_l_idx_2 = rtb_P_dg[0] * rtb_P_cg[1] - rtb_P_dg[1] *
                rtb_P_cg[0];

              /* Signum: '<S125>/Sign1' incorporates:
               *  Switch: '<S109>/Switch'
               */
              if (rtb_Divide_l_idx_2 < 0.0F) {
                rtb_Divide_l_idx_2 = -1.0F;
              } else {
                if (rtb_Divide_l_idx_2 > 0.0F) {
                  rtb_Divide_l_idx_2 = 1.0F;
                }
              }

              /* End of Signum: '<S125>/Sign1' */

              /* Switch: '<S125>/Switch2' incorporates:
               *  Constant: '<S125>/Constant4'
               *  Switch: '<S109>/Switch'
               */
              if (rtb_Divide_l_idx_2 == 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }

              /* End of Switch: '<S125>/Switch2' */

              /* DotProduct: '<S125>/Dot Product' incorporates:
               *  Switch: '<S109>/Switch'
               */
              rtb_Switch_fz_idx_1 = rtb_P_cg[0] * rtb_P_dg[0] + rtb_P_cg[1] *
                rtb_P_dg[1];

              /* Trigonometry: '<S125>/Acos' incorporates:
               *  DotProduct: '<S125>/Dot Product'
               *  Switch: '<S109>/Switch'
               */
              if (rtb_Switch_fz_idx_1 > 1.0F) {
                rtb_Switch_fz_idx_1 = 1.0F;
              } else {
                if (rtb_Switch_fz_idx_1 < -1.0F) {
                  rtb_Switch_fz_idx_1 = -1.0F;
                }
              }

              /* Product: '<S125>/Multiply' incorporates:
               *  Switch: '<S109>/Switch'
               *  Trigonometry: '<S125>/Acos'
               */
              rtb_Divide_l_idx_2 *= acosf(rtb_Switch_fz_idx_1);

              /* Saturate: '<S124>/Saturation' incorporates:
               *  Switch: '<S109>/Switch'
               */
              if (rtb_Divide_l_idx_2 > 1.57079637F) {
                rtb_Divide_l_idx_2 = 1.57079637F;
              } else {
                if (rtb_Divide_l_idx_2 < -1.57079637F) {
                  rtb_Divide_l_idx_2 = -1.57079637F;
                }
              }

              /* End of Saturate: '<S124>/Saturation' */

              /* Switch: '<S109>/Switch' incorporates:
               *  Constant: '<S109>/L1'
               *  Constant: '<S124>/Constant'
               *  Gain: '<S124>/Gain'
               *  Math: '<S124>/Square'
               *  MinMax: '<S124>/Max'
               *  MinMax: '<S124>/Min'
               *  Product: '<S124>/Divide'
               *  Product: '<S124>/Multiply1'
               *  Sqrt: '<S127>/Sqrt'
               *  Sum: '<S127>/Sum of Elements'
               *  Trigonometry: '<S124>/Sin'
               */
              FMS_B.Merge_be = rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F *
                arm_sin_f32(rtb_Divide_l_idx_2) / fminf(FMS_PARAM.FW_L1, fmaxf
                (sqrtf(d + rtb_u_mm), 0.5F));
            }

            /* End of Signum: '<S111>/Sign' */

            /* Update for Delay: '<S114>/start_vel' */
            FMS_DW.icLoad_g = 0U;

            /* Update for Delay: '<S114>/start_wp' */
            FMS_DW.icLoad_e = 0U;

            /* End of Outputs for SubSystem: '<S106>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S106>/Brake Control' incorporates:
             *  ActionPort: '<S108>/Action Port'
             */
            /* SignalConversion: '<S108>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
             *  Constant: '<S108>/Brake Speed'
             */
            FMS_B.Merge_be = 0.0F;

            /* End of Outputs for SubSystem: '<S106>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S106>/Move Control' incorporates:
               *  ActionPort: '<S110>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S106>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S137>/Integrator'
               *  DiscreteIntegrator: '<S137>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_c = 0.0F;
              FMS_DW.Integrator_DSTATE_f1 = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S106>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S106>/Move Control' incorporates:
             *  ActionPort: '<S110>/Action Port'
             */
            /* Product: '<S138>/Multiply1' incorporates:
             *  Constant: '<S138>/const1'
             *  DiscreteIntegrator: '<S137>/Integrator'
             */
            rtb_Divide_l_idx_2 = FMS_DW.Integrator_DSTATE_f1 * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S136>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              d = 0.0F;
            } else {
              d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S136>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S138>/Add' incorporates:
             *  DiscreteIntegrator: '<S137>/Integrator1'
             *  Gain: '<S110>/Gain6'
             *  Gain: '<S136>/Gain'
             *  Sum: '<S137>/Subtract'
             */
            rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_c - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.FW_ACC_Y_LIM) +
              rtb_Divide_l_idx_2;

            /* Signum: '<S138>/Sign' */
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_u_mm = -1.0F;
            } else if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_u_mm = 1.0F;
            } else {
              rtb_u_mm = rtb_Divide_l_idx_3;
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
            d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_h) *
                       FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F * rtb_u_mm +
              rtb_Divide_l_idx_2;

            /* Sum: '<S138>/Add4' */
            rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Divide_l_idx_2;

            /* Sum: '<S138>/Add3' */
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_h;

            /* Sum: '<S138>/Subtract1' */
            rtb_Divide_l_idx_3 -= FMS_ConstB.d_h;

            /* Signum: '<S138>/Sign1' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S138>/Sign1' */

            /* Signum: '<S138>/Sign2' */
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_Divide_l_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_3 > 0.0F) {
                rtb_Divide_l_idx_3 = 1.0F;
              }
            }

            /* End of Signum: '<S138>/Sign2' */

            /* Sum: '<S138>/Add5' incorporates:
             *  Gain: '<S138>/Gain2'
             *  Product: '<S138>/Multiply4'
             *  Sum: '<S138>/Subtract2'
             */
            d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

            /* SignalConversion: '<S110>/OutportBufferForay_cmd_mPs2' incorporates:
             *  DiscreteIntegrator: '<S137>/Integrator1'
             */
            FMS_B.Merge_be = FMS_DW.Integrator1_DSTATE_c;

            /* Update for DiscreteIntegrator: '<S137>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S137>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_c += 0.004F * FMS_DW.Integrator_DSTATE_f1;

            /* Sum: '<S138>/Subtract3' */
            rtb_Divide_l_idx_2 = d - FMS_ConstB.d_h;

            /* Sum: '<S138>/Add6' */
            rtb_u_mm = d + FMS_ConstB.d_h;

            /* Signum: '<S138>/Sign5' incorporates:
             *  Signum: '<S138>/Sign6'
             */
            if (d < 0.0F) {
              rtb_Divide_l_idx_3 = -1.0F;

              /* Signum: '<S138>/Sign6' */
              rtb_Switch_fz_idx_0 = -1.0F;
            } else if (d > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;

              /* Signum: '<S138>/Sign6' */
              rtb_Switch_fz_idx_0 = 1.0F;
            } else {
              rtb_Divide_l_idx_3 = d;

              /* Signum: '<S138>/Sign6' */
              rtb_Switch_fz_idx_0 = d;
            }

            /* End of Signum: '<S138>/Sign5' */

            /* Signum: '<S138>/Sign3' */
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = -1.0F;
            } else {
              if (rtb_u_mm > 0.0F) {
                rtb_u_mm = 1.0F;
              }
            }

            /* End of Signum: '<S138>/Sign3' */

            /* Signum: '<S138>/Sign4' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S138>/Sign4' */

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
            FMS_DW.Integrator_DSTATE_f1 += ((d / FMS_ConstB.d_h -
              rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_b * ((rtb_u_mm -
              rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S106>/Move Control' */
            break;
          }

          /* SwitchCase: '<S92>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S92>/Hold Control' incorporates:
               *  ActionPort: '<S95>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S92>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S92>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S92>/Hold Control' incorporates:
             *  ActionPort: '<S95>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_f,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S92>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S92>/Brake Control' incorporates:
             *  ActionPort: '<S94>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S92>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S92>/Move Control' incorporates:
               *  ActionPort: '<S96>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S92>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S92>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S92>/Move Control' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_f,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S92>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S92>/Switch Case' */

          /* BusAssignment: '<S64>/Bus Assignment' incorporates:
           *  Constant: '<S64>/Constant'
           *  DiscreteIntegrator: '<S104>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S88>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < -0.2F) {
            d = -0.2F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S88>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S64>/Bus Assignment' incorporates:
           *  Gain: '<S88>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * d;

          /* Saturate: '<S106>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S106>/Saturation1' */

          /* Saturate: '<S92>/Saturation1' */
          if (FMS_B.Merge_f > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_f < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S64>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_f;
          }

          /* End of Saturate: '<S92>/Saturation1' */

          /* Product: '<S105>/Multiply1' incorporates:
           *  Constant: '<S105>/const1'
           *  DiscreteIntegrator: '<S104>/Integrator'
           */
          rtb_Divide_l_idx_2 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S103>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S103>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S105>/Add' incorporates:
           *  DiscreteIntegrator: '<S104>/Integrator1'
           *  Gain: '<S103>/Gain'
           *  Gain: '<S90>/Gain1'
           *  Sum: '<S104>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_l_idx_2;

          /* Signum: '<S105>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_u_mm = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_u_mm = 1.0F;
          } else {
            rtb_u_mm = rtb_Divide_l_idx_3;
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
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_l) *
                     FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_u_mm +
            rtb_Divide_l_idx_2;

          /* Sum: '<S105>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Divide_l_idx_2;

          /* Sum: '<S105>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_l;

          /* Sum: '<S105>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_l;

          /* Signum: '<S105>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S105>/Sign1' */

          /* Signum: '<S105>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S105>/Sign2' */

          /* Sum: '<S105>/Add5' incorporates:
           *  Gain: '<S105>/Gain2'
           *  Product: '<S105>/Multiply4'
           *  Sum: '<S105>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Update for DiscreteIntegrator: '<S104>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S104>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Sum: '<S105>/Subtract3' */
          rtb_Divide_l_idx_2 = d - FMS_ConstB.d_l;

          /* Sum: '<S105>/Add6' */
          rtb_u_mm = d + FMS_ConstB.d_l;

          /* Signum: '<S105>/Sign5' incorporates:
           *  Signum: '<S105>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S105>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S105>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = d;

            /* Signum: '<S105>/Sign6' */
            rtb_Switch_fz_idx_0 = d;
          }

          /* End of Signum: '<S105>/Sign5' */

          /* Signum: '<S105>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S105>/Sign3' */

          /* Signum: '<S105>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S105>/Sign4' */

          /* Update for DiscreteIntegrator: '<S104>/Integrator' incorporates:
           *  Constant: '<S105>/const'
           *  Gain: '<S105>/Gain3'
           *  Product: '<S105>/Divide'
           *  Product: '<S105>/Multiply5'
           *  Product: '<S105>/Multiply6'
           *  Sum: '<S105>/Subtract4'
           *  Sum: '<S105>/Subtract5'
           *  Sum: '<S105>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((d / FMS_ConstB.d_l -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_a * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 15.707963F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S58>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S58>/Unknown' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S58>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S46>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S46>/Manual' incorporates:
         *  ActionPort: '<S60>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Saturate: '<S183>/Saturation' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
          d = 1.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
          d = 0.0F;
        } else {
          d = FMS_U.Pilot_Cmd.stick_throttle;
        }

        /* End of Saturate: '<S183>/Saturation' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* DataTypeConversion: '<S182>/Data Type Conversion' incorporates:
         *  Constant: '<S183>/Constant5'
         *  Gain: '<S183>/Gain4'
         *  Sum: '<S183>/Add'
         */
        rtb_DataTypeConversion_o = (uint16_T)fmodf(floorf(1000.0F * d + 1000.0F),
          65536.0F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DataTypeConversion: '<S182>/Data Type Conversion1' incorporates:
         *  Bias: '<S182>/Bias1'
         *  Gain: '<S182>/Gain'
         *  Gain: '<S182>/Gain1'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        d = fmodf(floorf(FMS_PARAM.MANUAL_ROLL_REV * FMS_U.Pilot_Cmd.stick_roll *
                         500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_DataTypeConversion1_h = (uint16_T)(d < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-d : (int32_T)(uint16_T)d);

        /* BusAssignment: '<S60>/Bus Assignment' incorporates:
         *  Constant: '<S60>/Constant'
         *  Constant: '<S60>/Constant2'
         *  SignalConversion: '<S60>/TmpHiddenBufferAtBus AssignmentInport1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;
        FMS_Y.FMS_Out.actuator_cmd[0] = rtb_DataTypeConversion_o;
        FMS_Y.FMS_Out.actuator_cmd[1] = rtb_DataTypeConversion_o;
        FMS_Y.FMS_Out.actuator_cmd[2] = rtb_DataTypeConversion1_h;
        FMS_Y.FMS_Out.actuator_cmd[3] = rtb_DataTypeConversion1_h;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DataTypeConversion: '<S182>/Data Type Conversion2' incorporates:
         *  Bias: '<S182>/Bias2'
         *  Gain: '<S182>/Gain2'
         *  Gain: '<S182>/Gain4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        d = fmodf(floorf(FMS_PARAM.MANUAL_PITCH_REV *
                         FMS_U.Pilot_Cmd.stick_pitch * -500.0F + 1500.0F),
                  65536.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S60>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S182>/Data Type Conversion2'
         */
        FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(d < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-d : (int32_T)(uint16_T)d);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DataTypeConversion: '<S182>/Data Type Conversion3' incorporates:
         *  Bias: '<S182>/Bias3'
         *  Gain: '<S182>/Gain3'
         *  Gain: '<S182>/Gain5'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        d = fmodf(floorf(FMS_PARAM.MANUAL_YAW_REV * FMS_U.Pilot_Cmd.stick_yaw *
                         500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S60>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S182>/Data Type Conversion3'
         */
        FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(d < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-d : (int32_T)(uint16_T)d);
        for (rtb_n = 0; rtb_n < 10; rtb_n++) {
          FMS_Y.FMS_Out.actuator_cmd[rtb_n + 6] = 0U;
        }

        /* End of Outputs for SubSystem: '<S46>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S46>/Unknown' incorporates:
         *  ActionPort: '<S62>/Action Port'
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
         *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator'
         *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator1'
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

        /* End of InitializeConditions for SwitchCase: '<S41>/Switch Case' */
        /* End of InitializeConditions for SubSystem: '<S41>/BackwardTrans_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S41>/BackwardTrans_Mode' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Trigonometry: '<S53>/Trigonometric Function1' incorporates:
       *  Gain: '<S52>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S53>/Trigonometric Function' incorporates:
       *  Gain: '<S52>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S53>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S53>/Constant3'
       */
      rtb_Transpose[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S53>/Gain' incorporates:
       *  Gain: '<S52>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       *  Trigonometry: '<S53>/Trigonometric Function2'
       */
      rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S53>/Trigonometric Function3' incorporates:
       *  Gain: '<S52>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S53>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S53>/Constant4'
       */
      rtb_Transpose[5] = 0.0F;

      /* SignalConversion: '<S53>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_dz[0];
      rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_dz[1];
      rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_dz[2];

      /* Product: '<S51>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
          FMS_U.INS_Out.ve + rtb_Transpose[rtb_n] * FMS_U.INS_Out.vn;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      }

      /* End of Product: '<S51>/Multiply' */

      /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
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

      /* DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S49>/Constant'
       *  Sum: '<S49>/Sum'
       */
      if (FMS_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_n = 0.0F -
          rtb_MatrixConcatenate1_i_0[1];
      }

      if (FMS_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_n = 0.0F -
          rtb_MatrixConcatenate1_i_0[1];
      }

      /* BusAssignment: '<S45>/Bus Assignment' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S45>/Constant3'
       *  Constant: '<S45>/Constant4'
       *  Constant: '<S49>/Constant'
       *  Constant: '<S56>/kp'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator'
       *  Product: '<S56>/Multiply'
       *  Sum: '<S49>/Sum'
       *  Sum: '<S50>/Add'
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

      /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S49>/Constant'
       *  Constant: '<S55>/ki'
       *  Product: '<S55>/Multiply'
       *  Sum: '<S49>/Sum'
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

      /* End of Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S49>/Constant'
       *  Gain: '<S57>/Gain'
       *  Sum: '<S49>/Sum'
       *  Sum: '<S57>/Sum5'
       */
      FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
      FMS_DW.DiscreteTimeIntegrator1_DSTAT_n += ((0.0F -
        rtb_MatrixConcatenate1_i_0[1]) - FMS_DW.DiscreteTimeIntegrator1_DSTAT_n)
        * 62.831852F * 0.004F;
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
          /* Disable for SwitchCase: '<S254>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S642>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S632>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S581>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S559>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S569>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S252>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S364>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S412>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S402>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* End of Disable for SubSystem: '<S364>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S251>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S351>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S266>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S284>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S300>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S325>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S312>/Switch Case' */
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
         *  ActionPort: '<S254>/Action Port'
         */
        /* SwitchCase: '<S254>/Switch Case' incorporates:
         *  Product: '<S666>/Divide'
         *  Sum: '<S626>/Subtract'
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
            /* Disable for SwitchCase: '<S642>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S632>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S581>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S559>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S569>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S254>/Takeoff' incorporates:
             *  ActionPort: '<S554>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S254>/Switch Case' incorporates:
             *  Delay: '<S682>/cur_waypoint'
             *  DiscreteIntegrator: '<S678>/Integrator'
             *  DiscreteIntegrator: '<S678>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S254>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S254>/Takeoff' incorporates:
           *  ActionPort: '<S554>/Action Port'
           */
          /* Delay: '<S682>/cur_waypoint' incorporates:
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
          /* Product: '<S682>/Divide' incorporates:
           *  Delay: '<S682>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S682>/Sum1'
           *  Sum: '<S682>/Sum2'
           */
          rtb_Divide_l_idx_3 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S682>/Saturation' */
          if (rtb_Divide_l_idx_3 > 1.0F) {
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_Divide_l_idx_3 = 0.0F;
            }
          }

          /* End of Saturate: '<S682>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S683>/Trigonometric Function1' incorporates:
           *  Gain: '<S681>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S683>/Trigonometric Function' incorporates:
           *  Gain: '<S681>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S683>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S683>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S683>/Gain' incorporates:
           *  Gain: '<S681>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S683>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S683>/Trigonometric Function3' incorporates:
           *  Gain: '<S681>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S683>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S683>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* SignalConversion: '<S683>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Saturate: '<S675>/Saturation1' */
          rtb_u_mm = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Switch_fz_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S675>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S682>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S682>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S675>/Sum'
           *  Sum: '<S682>/Sum3'
           *  Sum: '<S682>/Sum4'
           */
          rtb_Divide_l_idx_2 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_l_idx_3 +
                                FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Switch_fz_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_l_idx_3 +
            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S675>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
              rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2;
          }

          /* Saturate: '<S675>/Saturation1' incorporates:
           *  Gain: '<S675>/Gain2'
           *  Product: '<S675>/Multiply'
           */
          d = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[0];
          rtb_Divide_l_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[1];

          /* BusAssignment: '<S554>/Bus Assignment1' incorporates:
           *  Constant: '<S554>/Constant'
           *  Constant: '<S554>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S675>/Saturation1' */
          if (d > rtb_u_mm) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_u_mm;
          } else if (d < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = d;
          }

          if (rtb_Divide_l_idx_2 > rtb_u_mm) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_u_mm;
          } else if (rtb_Divide_l_idx_2 < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S554>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_2;
          }

          /* BusAssignment: '<S554>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S678>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S679>/Multiply1' incorporates:
           *  Constant: '<S679>/const1'
           *  DiscreteIntegrator: '<S678>/Integrator'
           */
          rtb_Divide_l_idx_3 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S674>/Switch' incorporates:
           *  Abs: '<S674>/Abs'
           *  Abs: '<S674>/Abs1'
           *  Constant: '<S674>/Takeoff_Speed'
           *  Constant: '<S676>/Constant'
           *  Constant: '<S677>/Constant'
           *  Gain: '<S674>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S674>/Logical Operator'
           *  RelationalOperator: '<S676>/Compare'
           *  RelationalOperator: '<S677>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S674>/Sum'
           *  Sum: '<S674>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            d = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            d = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S674>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S679>/Add' incorporates:
           *  DiscreteIntegrator: '<S678>/Integrator1'
           *  Sum: '<S678>/Subtract'
           */
          rtb_u_mm = (FMS_DW.Integrator1_DSTATE_f - d) + rtb_Divide_l_idx_3;

          /* Signum: '<S679>/Sign' */
          if (rtb_u_mm < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_u_mm > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_u_mm;
          }

          /* End of Signum: '<S679>/Sign' */

          /* Sum: '<S679>/Add2' incorporates:
           *  Abs: '<S679>/Abs'
           *  Gain: '<S679>/Gain'
           *  Gain: '<S679>/Gain1'
           *  Product: '<S679>/Multiply2'
           *  Product: '<S679>/Multiply3'
           *  Sqrt: '<S679>/Sqrt'
           *  Sum: '<S679>/Add1'
           *  Sum: '<S679>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_mm) + FMS_ConstB.d_b) * FMS_ConstB.d_b)
               - FMS_ConstB.d_b) * 0.5F * rtb_Divide_l_idx_2 +
            rtb_Divide_l_idx_3;

          /* Sum: '<S679>/Add4' */
          rtb_Divide_l_idx_3 += rtb_u_mm - d;

          /* Sum: '<S679>/Add3' */
          rtb_Divide_l_idx_2 = rtb_u_mm + FMS_ConstB.d_b;

          /* Sum: '<S679>/Subtract1' */
          rtb_u_mm -= FMS_ConstB.d_b;

          /* Signum: '<S679>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S679>/Sign1' */

          /* Signum: '<S679>/Sign2' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S679>/Sign2' */

          /* Sum: '<S679>/Add5' incorporates:
           *  Gain: '<S679>/Gain2'
           *  Product: '<S679>/Multiply4'
           *  Sum: '<S679>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F * rtb_Divide_l_idx_3;

          /* Update for Delay: '<S682>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S678>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S678>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S679>/Subtract3' */
          rtb_Divide_l_idx_2 = d - FMS_ConstB.d_b;

          /* Sum: '<S679>/Add6' */
          rtb_u_mm = d + FMS_ConstB.d_b;

          /* Signum: '<S679>/Sign5' incorporates:
           *  Signum: '<S679>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S679>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S679>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = d;

            /* Signum: '<S679>/Sign6' */
            rtb_Switch_fz_idx_0 = d;
          }

          /* End of Signum: '<S679>/Sign5' */

          /* Signum: '<S679>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S679>/Sign3' */

          /* Signum: '<S679>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S679>/Sign4' */

          /* Update for DiscreteIntegrator: '<S678>/Integrator' incorporates:
           *  Constant: '<S679>/const'
           *  Gain: '<S679>/Gain3'
           *  Product: '<S679>/Divide'
           *  Product: '<S679>/Multiply5'
           *  Product: '<S679>/Multiply6'
           *  Sum: '<S679>/Subtract4'
           *  Sum: '<S679>/Subtract5'
           *  Sum: '<S679>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((d / FMS_ConstB.d_b -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_i * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S254>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S254>/Land' incorporates:
             *  ActionPort: '<S552>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S254>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S597>/Integrator'
             *  DiscreteIntegrator: '<S597>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S254>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S254>/Land' incorporates:
           *  ActionPort: '<S552>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S602>/Trigonometric Function1' incorporates:
           *  Gain: '<S601>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S602>/Trigonometric Function' incorporates:
           *  Gain: '<S601>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S602>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S602>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S602>/Gain' incorporates:
           *  Gain: '<S601>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S602>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S602>/Trigonometric Function3' incorporates:
           *  Gain: '<S601>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S602>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S602>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* SignalConversion: '<S602>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_j[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_j[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_j[2];

          /* Saturate: '<S595>/Saturation1' */
          rtb_Divide_l_idx_3 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Switch_fz_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S599>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S599>/Sum'
           */
          rtb_Divide_l_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Switch_fz_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S599>/Multiply' incorporates:
           *  SignalConversion: '<S599>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
              rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2;
          }

          /* End of Product: '<S599>/Multiply' */

          /* Saturate: '<S595>/Saturation1' incorporates:
           *  Gain: '<S599>/Gain2'
           */
          d = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[0];
          rtb_Divide_l_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_i_0[1];

          /* BusAssignment: '<S552>/Bus Assignment1' incorporates:
           *  Constant: '<S552>/Constant'
           *  Constant: '<S552>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S595>/Saturation1' */
          if (d > rtb_Divide_l_idx_3) {
            /* BusAssignment: '<S552>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_3;
          } else if (d < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S552>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S552>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = d;
          }

          if (rtb_Divide_l_idx_2 > rtb_Divide_l_idx_3) {
            /* BusAssignment: '<S552>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_3;
          } else if (rtb_Divide_l_idx_2 < rtb_Switch_fz_idx_0) {
            /* BusAssignment: '<S552>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_fz_idx_0;
          } else {
            /* BusAssignment: '<S552>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_2;
          }

          /* BusAssignment: '<S552>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S597>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S598>/Multiply1' incorporates:
           *  Constant: '<S598>/const1'
           *  DiscreteIntegrator: '<S597>/Integrator'
           */
          rtb_Divide_l_idx_2 = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S594>/Switch' incorporates:
           *  Constant: '<S594>/Land_Speed'
           *  Constant: '<S596>/Constant'
           *  Gain: '<S594>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S594>/Logical Operator'
           *  RelationalOperator: '<S596>/Compare'
           *  S-Function (sfix_bitop): '<S594>/cmd_p valid'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            d = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            d = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S594>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S598>/Add' incorporates:
           *  DiscreteIntegrator: '<S597>/Integrator1'
           *  Sum: '<S597>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_g - d) +
            rtb_Divide_l_idx_2;

          /* Signum: '<S598>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_u_mm = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_u_mm = 1.0F;
          } else {
            rtb_u_mm = rtb_Divide_l_idx_3;
          }

          /* End of Signum: '<S598>/Sign' */

          /* Sum: '<S598>/Add2' incorporates:
           *  Abs: '<S598>/Abs'
           *  Gain: '<S598>/Gain'
           *  Gain: '<S598>/Gain1'
           *  Product: '<S598>/Multiply2'
           *  Product: '<S598>/Multiply3'
           *  Sqrt: '<S598>/Sqrt'
           *  Sum: '<S598>/Add1'
           *  Sum: '<S598>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_om) *
                     FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F * rtb_u_mm +
            rtb_Divide_l_idx_2;

          /* Sum: '<S598>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Divide_l_idx_2;

          /* Sum: '<S598>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_om;

          /* Sum: '<S598>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_om;

          /* Signum: '<S598>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S598>/Sign1' */

          /* Signum: '<S598>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S598>/Sign2' */

          /* Sum: '<S598>/Add5' incorporates:
           *  Gain: '<S598>/Gain2'
           *  Product: '<S598>/Multiply4'
           *  Sum: '<S598>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Update for DiscreteIntegrator: '<S597>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S597>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S598>/Subtract3' */
          rtb_Divide_l_idx_2 = d - FMS_ConstB.d_om;

          /* Sum: '<S598>/Add6' */
          rtb_u_mm = d + FMS_ConstB.d_om;

          /* Signum: '<S598>/Sign5' incorporates:
           *  Signum: '<S598>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S598>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S598>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = d;

            /* Signum: '<S598>/Sign6' */
            rtb_Switch_fz_idx_0 = d;
          }

          /* End of Signum: '<S598>/Sign5' */

          /* Signum: '<S598>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S598>/Sign3' */

          /* Signum: '<S598>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S598>/Sign4' */

          /* Update for DiscreteIntegrator: '<S597>/Integrator' incorporates:
           *  Constant: '<S598>/const'
           *  Gain: '<S598>/Gain3'
           *  Product: '<S598>/Divide'
           *  Product: '<S598>/Multiply5'
           *  Product: '<S598>/Multiply6'
           *  Sum: '<S598>/Subtract4'
           *  Sum: '<S598>/Subtract5'
           *  Sum: '<S598>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((d / FMS_ConstB.d_om -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_p * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S254>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S254>/Return' incorporates:
             *  ActionPort: '<S553>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S254>/Switch Case' incorporates:
             *  Delay: '<S605>/Delay'
             *  Delay: '<S606>/Delay'
             *  Delay: '<S627>/Delay'
             *  DiscreteIntegrator: '<S609>/Integrator'
             *  DiscreteIntegrator: '<S609>/Integrator1'
             *  DiscreteIntegrator: '<S623>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S628>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S669>/Discrete-Time Integrator'
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

            /* End of InitializeConditions for SubSystem: '<S254>/Return' */

            /* SystemReset for IfAction SubSystem: '<S254>/Return' incorporates:
             *  ActionPort: '<S553>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S254>/Switch Case' incorporates:
             *  Chart: '<S633>/Motion Status'
             *  Chart: '<S643>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S254>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S254>/Return' incorporates:
           *  ActionPort: '<S553>/Action Port'
           */
          /* Delay: '<S627>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S622>/Compare' incorporates:
           *  Constant: '<S673>/Constant'
           *  DiscreteIntegrator: '<S628>/Discrete-Time Integrator'
           *  RelationalOperator: '<S673>/Compare'
           */
          rtb_Compare_ii = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S623>/Acceleration_Speed' */
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
          /* Chart: '<S643>/Motion State' incorporates:
           *  Constant: '<S643>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S643>/Square'
           *  Math: '<S643>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S643>/Sqrt'
           *  Sum: '<S643>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S642>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S642>/Hold Control' incorporates:
               *  ActionPort: '<S645>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S642>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S642>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S642>/Hold Control' incorporates:
             *  ActionPort: '<S645>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S642>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S642>/Brake Control' incorporates:
             *  ActionPort: '<S644>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S642>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S642>/Move Control' incorporates:
               *  ActionPort: '<S646>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S642>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S642>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S642>/Move Control' incorporates:
             *  ActionPort: '<S646>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S642>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S642>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S633>/Motion Status' incorporates:
           *  Abs: '<S633>/Abs'
           *  Constant: '<S633>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S632>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S632>/Hold Control' incorporates:
               *  ActionPort: '<S635>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S632>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S632>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S632>/Hold Control' incorporates:
             *  ActionPort: '<S635>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S632>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S632>/Brake Control' incorporates:
             *  ActionPort: '<S634>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S632>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S632>/Move Control' incorporates:
               *  ActionPort: '<S636>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S632>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S632>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S632>/Move Control' incorporates:
             *  ActionPort: '<S636>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S632>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S632>/Switch Case' */

          /* Switch: '<S604>/Switch' incorporates:
           *  Product: '<S627>/Multiply'
           *  Sum: '<S627>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S642>/Saturation1' */
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

            /* End of Saturate: '<S642>/Saturation1' */

            /* Saturate: '<S632>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_ov[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_ov[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_ov[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S632>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S627>/Sum' incorporates:
             *  Delay: '<S627>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S670>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_ov[0] = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S623>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract3_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_u_mm = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S627>/Sum' incorporates:
             *  Delay: '<S627>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S623>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_or = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S629>/Sqrt' incorporates:
             *  Math: '<S629>/Square'
             *  Sum: '<S623>/Sum'
             *  Sum: '<S629>/Sum of Elements'
             */
            d = sqrtf(rtb_Subtract3_d * rtb_Subtract3_d + rtb_Divide_or *
                      rtb_Divide_or);

            /* SignalConversion: '<S672>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S672>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S672>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S671>/Gain' incorporates:
             *  DiscreteIntegrator: '<S669>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S669>/Add'
             */
            rtb_Switch_fz_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S672>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S672>/Trigonometric Function1'
             */
            rtb_Switch_fz_idx_1 = arm_cos_f32(rtb_Switch_fz_idx_0);
            rtb_Transpose[4] = rtb_Switch_fz_idx_1;

            /* Trigonometry: '<S672>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S672>/Trigonometric Function'
             */
            rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_Switch_fz_idx_0);

            /* Gain: '<S672>/Gain' incorporates:
             *  Trigonometry: '<S672>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S672>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S672>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S672>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Switch_fz_idx_0;

            /* Trigonometry: '<S672>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_Switch_fz_idx_1;

            /* Switch: '<S623>/Switch' incorporates:
             *  Constant: '<S623>/vel'
             */
            if (d > FMS_PARAM.L1) {
              rtb_Switch_fz_idx_0 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S623>/Gain' */
              rtb_Switch_fz_idx_0 = 0.5F * d;

              /* Saturate: '<S623>/Saturation' */
              if (rtb_Switch_fz_idx_0 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Switch_fz_idx_0 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Switch_fz_idx_0 < 0.5F) {
                  rtb_Switch_fz_idx_0 = 0.5F;
                }
              }

              /* End of Saturate: '<S623>/Saturation' */
            }

            /* End of Switch: '<S623>/Switch' */

            /* Switch: '<S623>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S623>/Acceleration_Speed'
             *  Sum: '<S623>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Switch_fz_idx_0 < 0.0F)
            {
              rtb_Switch_fz_idx_0 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S623>/Switch1' */

            /* Sum: '<S670>/Sum of Elements' incorporates:
             *  Math: '<S670>/Math Function'
             */
            d = rtb_Switch_ov[0] * rtb_Switch_ov[0] + rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_2;

            /* Math: '<S670>/Math Function1' incorporates:
             *  Sum: '<S670>/Sum of Elements'
             *
             * About '<S670>/Math Function1':
             *  Operator: sqrt
             */
            if (d < 0.0F) {
              d = -sqrtf(fabsf(d));
            } else {
              d = sqrtf(d);
            }

            /* End of Math: '<S670>/Math Function1' */

            /* Switch: '<S670>/Switch' incorporates:
             *  Constant: '<S670>/Constant'
             *  Product: '<S670>/Product'
             */
            if (d <= 0.0F) {
              rtb_u_mm = 0.0F;
              rtb_Switch_fz_idx_2 = 0.0F;
              d = 1.0F;
            }

            /* End of Switch: '<S670>/Switch' */

            /* Product: '<S668>/Multiply2' incorporates:
             *  Product: '<S670>/Divide'
             */
            rtb_u_mm = rtb_u_mm / d * rtb_Switch_fz_idx_0;
            rtb_Switch_fz_idx_2 = rtb_Switch_fz_idx_2 / d * rtb_Switch_fz_idx_0;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_2 + rtb_Transpose[rtb_n] * rtb_u_mm;
            }
          }

          /* End of Switch: '<S604>/Switch' */

          /* Delay: '<S606>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S609>/Integrator1' incorporates:
           *  Delay: '<S606>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S613>/Rem' incorporates:
           *  Constant: '<S613>/Constant1'
           *  DiscreteIntegrator: '<S609>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S608>/Sum'
           */
          rtb_u_mm = rt_remf(FMS_DW.Integrator1_DSTATE_b - FMS_U.INS_Out.psi,
                             6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S613>/Switch' incorporates:
           *  Abs: '<S613>/Abs'
           *  Constant: '<S613>/Constant'
           *  Constant: '<S614>/Constant'
           *  Product: '<S613>/Multiply'
           *  RelationalOperator: '<S614>/Compare'
           *  Sum: '<S613>/Add'
           */
          if (fabsf(rtb_u_mm) > 3.14159274F) {
            /* Signum: '<S613>/Sign' */
            if (rtb_u_mm < 0.0F) {
              d = -1.0F;
            } else if (rtb_u_mm > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_u_mm;
            }

            /* End of Signum: '<S613>/Sign' */
            rtb_u_mm -= 6.28318548F * d;
          }

          /* End of Switch: '<S613>/Switch' */

          /* Gain: '<S608>/Gain2' */
          rtb_u_mm *= FMS_PARAM.YAW_P;

          /* Saturate: '<S608>/Saturation' */
          if (rtb_u_mm > FMS_PARAM.YAW_RATE_LIM) {
            rtb_u_mm = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_u_mm < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_u_mm = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S608>/Saturation' */

          /* BusAssignment: '<S553>/Bus Assignment1' incorporates:
           *  Constant: '<S553>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_ov[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_mm;

          /* Math: '<S663>/Math Function1'
           *
           * About '<S663>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_u_mm = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S663>/Math Function1' */

          /* Switch: '<S663>/Switch' incorporates:
           *  Constant: '<S663>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S663>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Switch: '<S663>/Switch' */

          /* Delay: '<S605>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_f != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_nc[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S553>/Sum' incorporates:
           *  Delay: '<S605>/Delay'
           *  MATLAB Function: '<S625>/OutRegionRegWP'
           *  MATLAB Function: '<S625>/SearchL1RefWP'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_nc[0];
          rtb_Divide_or = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_nc[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S620>/Sum of Elements' incorporates:
           *  Math: '<S620>/Math Function'
           *  Sum: '<S553>/Sum'
           */
          d = rtb_Divide_or * rtb_Divide_or + rtb_Subtract3_d * rtb_Subtract3_d;

          /* Math: '<S620>/Math Function1' incorporates:
           *  Sum: '<S620>/Sum of Elements'
           *
           * About '<S620>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(d));
          } else {
            rtb_u_mm = sqrtf(d);
          }

          /* End of Math: '<S620>/Math Function1' */

          /* Switch: '<S620>/Switch' incorporates:
           *  Constant: '<S620>/Constant'
           *  Product: '<S620>/Product'
           *  Sum: '<S553>/Sum'
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

          /* End of Switch: '<S620>/Switch' */

          /* Product: '<S663>/Divide' */
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_n4[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S666>/Sum of Elements' incorporates:
           *  Math: '<S666>/Math Function'
           *  SignalConversion: '<S666>/TmpSignal ConversionAtMath FunctionInport1'
           */
          d = rtb_Divide_n4[1] * rtb_Divide_n4[1] + rtb_Divide_n4[0] *
            rtb_Divide_n4[0];

          /* Math: '<S666>/Math Function1' incorporates:
           *  Sum: '<S666>/Sum of Elements'
           *
           * About '<S666>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(d));
          } else {
            rtb_u_mm = sqrtf(d);
          }

          /* End of Math: '<S666>/Math Function1' */

          /* Switch: '<S666>/Switch' incorporates:
           *  Constant: '<S666>/Constant'
           *  Product: '<S666>/Product'
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

          /* End of Switch: '<S666>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S625>/NearbyRefWP' incorporates:
           *  Constant: '<S553>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_n4, &d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* MATLAB Function: '<S625>/SearchL1RefWP' incorporates:
           *  Constant: '<S553>/L1'
           *  Delay: '<S605>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
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
          /* MATLAB Function: '<S625>/OutRegionRegWP' incorporates:
           *  Delay: '<S605>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_mm = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_nc[1]) *
                      rtb_Divide_or + (FMS_U.INS_Out.x_R -
            FMS_DW.Delay_DSTATE_nc[0]) * rtb_Subtract3_d) / (rtb_Subtract3_d *
            rtb_Subtract3_d + rtb_Divide_or * rtb_Divide_or);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_u_mm <= 0.0F);
          rtb_LogicalOperator_op = (rtb_u_mm >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Subtract3_d = FMS_DW.Delay_DSTATE_nc[0];
          } else if (rtb_LogicalOperator_op) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            rtb_Subtract3_d = rtb_u_mm * rtb_Subtract3_d +
              FMS_DW.Delay_DSTATE_nc[0];
          }

          /* Switch: '<S625>/Switch1' incorporates:
           *  Constant: '<S656>/Constant'
           *  RelationalOperator: '<S656>/Compare'
           */
          if (d <= 0.0F) {
            /* Switch: '<S625>/Switch' incorporates:
             *  Constant: '<S655>/Constant'
             *  MATLAB Function: '<S625>/SearchL1RefWP'
             *  RelationalOperator: '<S655>/Compare'
             */
            if (rtb_Divide_l_idx_2 >= 0.0F) {
              rtb_Divide_n4[0] = rtb_Square_h[0];
              rtb_Divide_n4[1] = rtb_Square_h[1];
            } else {
              rtb_Divide_n4[0] = rtb_Subtract3_d;

              /* MATLAB Function: '<S625>/OutRegionRegWP' incorporates:
               *  Delay: '<S605>/Delay'
               *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Divide_n4[1] = FMS_DW.Delay_DSTATE_nc[1];
              } else if (rtb_LogicalOperator_op) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_Divide_n4[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              } else {
                rtb_Divide_n4[1] = rtb_u_mm * rtb_Divide_or +
                  FMS_DW.Delay_DSTATE_nc[1];
              }
            }

            /* End of Switch: '<S625>/Switch' */
          }

          /* End of Switch: '<S625>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S626>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract3_d = rtb_Divide_n4[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S664>/Math Function' */
          rtb_P_cg[0] = rtb_Subtract3_d * rtb_Subtract3_d;
          rtb_Divide_n4[0] = rtb_Subtract3_d;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S626>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract3_d = rtb_Divide_n4[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S664>/Math Function' incorporates:
           *  Math: '<S662>/Square'
           */
          d = rtb_Subtract3_d * rtb_Subtract3_d;

          /* Sum: '<S664>/Sum of Elements' incorporates:
           *  Math: '<S664>/Math Function'
           */
          rtb_Divide_l_idx_2 = d + rtb_P_cg[0];

          /* Math: '<S664>/Math Function1' incorporates:
           *  Sum: '<S664>/Sum of Elements'
           *
           * About '<S664>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_u_mm = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S664>/Math Function1' */

          /* Switch: '<S664>/Switch' incorporates:
           *  Constant: '<S664>/Constant'
           *  Product: '<S664>/Product'
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

          /* End of Switch: '<S664>/Switch' */

          /* Product: '<S664>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S667>/Sum of Elements' incorporates:
           *  Math: '<S667>/Math Function'
           *  SignalConversion: '<S667>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

          /* Math: '<S667>/Math Function1' incorporates:
           *  Sum: '<S667>/Sum of Elements'
           *
           * About '<S667>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_u_mm = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_u_mm = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S667>/Math Function1' */

          /* Switch: '<S667>/Switch' incorporates:
           *  Constant: '<S667>/Constant'
           *  Product: '<S667>/Product'
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

          /* End of Switch: '<S667>/Switch' */

          /* Product: '<S667>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Math: '<S662>/Square' */
          rtb_P_dg[0] = rtb_Divide_n4[0] * rtb_Divide_n4[0];

          /* Product: '<S620>/Divide' */
          rtb_Square_h[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_Divide_n4[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S667>/Divide' incorporates:
           *  Product: '<S666>/Divide'
           */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S666>/Divide' */
          rtb_Subtract3_d = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S620>/Divide' */
          rtb_Square_h[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S665>/Subtract' incorporates:
           *  Product: '<S665>/Multiply'
           *  Product: '<S665>/Multiply1'
           */
          rtb_u_mm = rtb_P_cg[0] * rtb_Subtract3_d - rtb_P_cg[1] *
            rtb_Divide_n4[0];

          /* Signum: '<S660>/Sign1' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S660>/Sign1' */

          /* Switch: '<S660>/Switch2' incorporates:
           *  Constant: '<S660>/Constant4'
           */
          if (rtb_u_mm == 0.0F) {
            rtb_u_mm = 1.0F;
          }

          /* End of Switch: '<S660>/Switch2' */

          /* DotProduct: '<S660>/Dot Product' */
          rtb_Subtract3_d = rtb_Divide_n4[0] * rtb_P_cg[0] + rtb_Subtract3_d *
            rtb_P_cg[1];

          /* Trigonometry: '<S660>/Acos' incorporates:
           *  DotProduct: '<S660>/Dot Product'
           */
          if (rtb_Subtract3_d > 1.0F) {
            rtb_Subtract3_d = 1.0F;
          } else {
            if (rtb_Subtract3_d < -1.0F) {
              rtb_Subtract3_d = -1.0F;
            }
          }

          /* Product: '<S660>/Multiply' incorporates:
           *  Trigonometry: '<S660>/Acos'
           */
          rtb_u_mm *= acosf(rtb_Subtract3_d);

          /* Saturate: '<S626>/Saturation' */
          if (rtb_u_mm > 1.57079637F) {
            rtb_u_mm = 1.57079637F;
          } else {
            if (rtb_u_mm < -1.57079637F) {
              rtb_u_mm = -1.57079637F;
            }
          }

          /* End of Saturate: '<S626>/Saturation' */

          /* Product: '<S626>/Divide' incorporates:
           *  Constant: '<S553>/L1'
           *  Constant: '<S626>/Constant'
           *  Gain: '<S626>/Gain'
           *  Math: '<S626>/Square'
           *  MinMax: '<S626>/Max'
           *  MinMax: '<S626>/Min'
           *  Product: '<S626>/Multiply1'
           *  Sqrt: '<S662>/Sqrt'
           *  Sum: '<S662>/Sum of Elements'
           *  Trigonometry: '<S626>/Sin'
           */
          rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_u_mm) * (rtb_Divide_l_idx_3 *
            rtb_Divide_l_idx_3 * 2.0F) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(d +
            rtb_P_dg[0]), 0.5F));

          /* Sum: '<S618>/Subtract' incorporates:
           *  Product: '<S618>/Multiply'
           *  Product: '<S618>/Multiply1'
           */
          rtb_Switch_fz_idx_1 = rtb_Square_h[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_h[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S607>/Sign1' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S607>/Sign1' */

          /* Switch: '<S607>/Switch2' incorporates:
           *  Constant: '<S607>/Constant4'
           */
          if (rtb_Switch_fz_idx_1 == 0.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          }

          /* End of Switch: '<S607>/Switch2' */

          /* DotProduct: '<S607>/Dot Product' */
          d = FMS_ConstB.Divide_m[0] * rtb_Square_h[0] + FMS_ConstB.Divide_m[1] *
            rtb_Square_h[1];

          /* Trigonometry: '<S607>/Acos' incorporates:
           *  DotProduct: '<S607>/Dot Product'
           */
          if (d > 1.0F) {
            d = 1.0F;
          } else {
            if (d < -1.0F) {
              d = -1.0F;
            }
          }

          /* Product: '<S607>/Multiply' incorporates:
           *  Trigonometry: '<S607>/Acos'
           */
          rtb_Switch_fz_idx_1 *= acosf(d);

          /* Math: '<S610>/Rem' incorporates:
           *  Constant: '<S610>/Constant1'
           *  Delay: '<S606>/Delay'
           *  Sum: '<S606>/Sum2'
           */
          rtb_u_mm = rt_remf(rtb_Switch_fz_idx_1 - FMS_DW.Delay_DSTATE_nx,
                             6.28318548F);

          /* Switch: '<S610>/Switch' incorporates:
           *  Abs: '<S610>/Abs'
           *  Constant: '<S610>/Constant'
           *  Constant: '<S616>/Constant'
           *  Product: '<S610>/Multiply'
           *  RelationalOperator: '<S616>/Compare'
           *  Sum: '<S610>/Add'
           */
          if (fabsf(rtb_u_mm) > 3.14159274F) {
            /* Signum: '<S610>/Sign' */
            if (rtb_u_mm < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (rtb_u_mm > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = rtb_u_mm;
            }

            /* End of Signum: '<S610>/Sign' */
            rtb_u_mm -= 6.28318548F * rtb_Divide_l_idx_2;
          }

          /* End of Switch: '<S610>/Switch' */

          /* Sum: '<S606>/Sum' incorporates:
           *  Delay: '<S606>/Delay'
           */
          rtb_Divide_l_idx_2 = rtb_u_mm + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S615>/Multiply1' incorporates:
           *  Constant: '<S615>/const1'
           *  DiscreteIntegrator: '<S609>/Integrator'
           */
          rtb_u_mm = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S615>/Add' incorporates:
           *  DiscreteIntegrator: '<S609>/Integrator1'
           *  Sum: '<S609>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_b - rtb_Divide_l_idx_2)
            + rtb_u_mm;

          /* Signum: '<S615>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3;
          }

          /* End of Signum: '<S615>/Sign' */

          /* Sum: '<S615>/Add2' incorporates:
           *  Abs: '<S615>/Abs'
           *  Gain: '<S615>/Gain'
           *  Gain: '<S615>/Gain1'
           *  Product: '<S615>/Multiply2'
           *  Product: '<S615>/Multiply3'
           *  Sqrt: '<S615>/Sqrt'
           *  Sum: '<S615>/Add1'
           *  Sum: '<S615>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_n) *
                     FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_u_mm;

          /* Sum: '<S615>/Add4' */
          rtb_u_mm += rtb_Divide_l_idx_3 - d;

          /* Sum: '<S615>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_n;

          /* Sum: '<S615>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_n;

          /* Signum: '<S615>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S615>/Sign1' */

          /* Signum: '<S615>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S615>/Sign2' */

          /* Sum: '<S615>/Add5' incorporates:
           *  Gain: '<S615>/Gain2'
           *  Product: '<S615>/Multiply4'
           *  Sum: '<S615>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Sum: '<S615>/Add6' */
          rtb_Divide_l_idx_2 = d + FMS_ConstB.d_n;

          /* Sum: '<S615>/Subtract3' */
          rtb_u_mm = d - FMS_ConstB.d_n;

          /* Product: '<S615>/Divide' */
          rtb_Switch_fz_idx_2 = d / FMS_ConstB.d_n;

          /* Signum: '<S615>/Sign5' incorporates:
           *  Signum: '<S615>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S615>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S615>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = d;

            /* Signum: '<S615>/Sign6' */
            rtb_Divide_l_idx_3 = d;
          }

          /* End of Signum: '<S615>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S606>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Switch_fz_idx_1 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S611>/Rem' incorporates:
           *  Constant: '<S611>/Constant1'
           */
          d = rt_remf(rtb_Switch_fz_idx_1, 6.28318548F);

          /* Switch: '<S611>/Switch' incorporates:
           *  Abs: '<S611>/Abs'
           *  Constant: '<S611>/Constant'
           *  Constant: '<S617>/Constant'
           *  Product: '<S611>/Multiply'
           *  RelationalOperator: '<S617>/Compare'
           *  Sum: '<S611>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S611>/Sign' */
            if (d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = d;
            }

            /* End of Signum: '<S611>/Sign' */
            d -= 6.28318548F * rtb_Switch_fz_idx_1;
          }

          /* End of Switch: '<S611>/Switch' */

          /* Abs: '<S604>/Abs' */
          d = fabsf(d);

          /* Update for Delay: '<S627>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S628>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S621>/Constant'
           *  RelationalOperator: '<S621>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S628>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S623>/Acceleration_Speed' incorporates:
           *  Constant: '<S623>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S623>/Acceleration_Speed' */

          /* Product: '<S627>/Divide1' incorporates:
           *  Constant: '<S627>/Constant'
           */
          d = rtb_Switch_fz_idx_0 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S627>/Saturation' */
          if (d > 0.314159274F) {
            d = 0.314159274F;
          } else {
            if (d < -0.314159274F) {
              d = -0.314159274F;
            }
          }

          /* End of Saturate: '<S627>/Saturation' */

          /* Update for DiscreteIntegrator: '<S669>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * d;

          /* Update for Delay: '<S606>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S609>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S609>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Update for Delay: '<S605>/Delay' */
          FMS_DW.icLoad_f = 0U;

          /* Signum: '<S615>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S615>/Sign3' */

          /* Signum: '<S615>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S615>/Sign4' */

          /* Update for DiscreteIntegrator: '<S609>/Integrator' incorporates:
           *  Constant: '<S615>/const'
           *  Gain: '<S615>/Gain3'
           *  Product: '<S615>/Multiply5'
           *  Product: '<S615>/Multiply6'
           *  Sum: '<S615>/Subtract4'
           *  Sum: '<S615>/Subtract5'
           *  Sum: '<S615>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S609>/Integrator' */
          /* End of Outputs for SubSystem: '<S254>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S254>/Hold' incorporates:
             *  ActionPort: '<S551>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S254>/Switch Case' incorporates:
             *  Chart: '<S560>/Motion Status'
             *  Chart: '<S570>/Motion State'
             *  Chart: '<S582>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S254>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S254>/Hold' incorporates:
           *  ActionPort: '<S551>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S560>/Motion Status' incorporates:
           *  Abs: '<S560>/Abs'
           *  Constant: '<S560>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S570>/Motion State' incorporates:
           *  Abs: '<S570>/Abs'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Chart: '<S570>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S582>/Motion State' incorporates:
           *  Constant: '<S582>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S582>/Square'
           *  Math: '<S582>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S582>/Sqrt'
           *  Sum: '<S582>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S581>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S581>/Hold Control' incorporates:
               *  ActionPort: '<S584>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S581>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S581>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S581>/Hold Control' incorporates:
             *  ActionPort: '<S584>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S581>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S581>/Brake Control' incorporates:
             *  ActionPort: '<S583>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S581>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S581>/Move Control' incorporates:
               *  ActionPort: '<S585>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S581>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S581>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S581>/Move Control' incorporates:
             *  ActionPort: '<S585>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S581>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S581>/Switch Case' */

          /* SwitchCase: '<S559>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S559>/Hold Control' incorporates:
               *  ActionPort: '<S562>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S559>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S559>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S559>/Hold Control' incorporates:
             *  ActionPort: '<S562>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S559>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S559>/Brake Control' incorporates:
             *  ActionPort: '<S561>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S559>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S559>/Move Control' incorporates:
               *  ActionPort: '<S563>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S559>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S559>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S559>/Move Control' incorporates:
             *  ActionPort: '<S563>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S559>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S559>/Switch Case' */

          /* SwitchCase: '<S569>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S569>/Hold Control' incorporates:
               *  ActionPort: '<S572>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S569>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S569>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S569>/Hold Control' incorporates:
             *  ActionPort: '<S572>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S569>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S569>/Brake Control' incorporates:
             *  ActionPort: '<S571>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S569>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_cv != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S569>/Move Control' incorporates:
               *  ActionPort: '<S573>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S569>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S569>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S569>/Move Control' incorporates:
             *  ActionPort: '<S573>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S569>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S569>/Switch Case' */

          /* BusAssignment: '<S551>/Bus Assignment' incorporates:
           *  Constant: '<S551>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;

          /* Saturate: '<S569>/Saturation' */
          if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;
          }

          /* End of Saturate: '<S569>/Saturation' */

          /* Saturate: '<S581>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S581>/Saturation1' */

          /* Saturate: '<S559>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S551>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S559>/Saturation1' */
          /* End of Outputs for SubSystem: '<S254>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S254>/Unknown' incorporates:
           *  ActionPort: '<S555>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S254>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
         *  ActionPort: '<S252>/Action Port'
         */
        /* SwitchCase: '<S252>/Switch Case' incorporates:
         *  Math: '<S432>/Square'
         *  Sum: '<S393>/Subtract'
         *  Sum: '<S447>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S364>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S412>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* End of Disable for SubSystem: '<S364>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S252>/Offboard' incorporates:
           *  ActionPort: '<S365>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S528>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Multiply_h_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S531>/deg2rad' */
          rtb_Switch1_a = 0.017453292519943295 * rtb_Multiply_h_idx_0;

          /* Trigonometry: '<S532>/Sin' */
          rtb_Gain = sin(rtb_Switch1_a);

          /* Math: '<S532>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S532>/Multiply1' incorporates:
           *  Product: '<S532>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S532>/Divide' incorporates:
           *  Constant: '<S532>/Constant'
           *  Constant: '<S532>/R'
           *  Sqrt: '<S532>/Sqrt'
           *  Sum: '<S532>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S532>/Product3' incorporates:
           *  Constant: '<S532>/Constant1'
           *  Product: '<S532>/Multiply1'
           *  Sum: '<S532>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S532>/Multiply2' incorporates:
           *  Trigonometry: '<S532>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_a);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S531>/Sum' incorporates:
           *  Gain: '<S528>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Multiply_h_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_h_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S536>/Abs' incorporates:
           *  Abs: '<S539>/Abs1'
           *  Switch: '<S536>/Switch1'
           */
          rtb_Switch1_a = fabs(rtb_Multiply_h_idx_0);

          /* Switch: '<S536>/Switch1' incorporates:
           *  Abs: '<S536>/Abs'
           *  Bias: '<S536>/Bias2'
           *  Bias: '<S536>/Bias3'
           *  Constant: '<S533>/Constant'
           *  Constant: '<S533>/Constant1'
           *  Constant: '<S538>/Constant'
           *  Gain: '<S536>/Gain1'
           *  Product: '<S536>/Multiply'
           *  RelationalOperator: '<S538>/Compare'
           *  Switch: '<S533>/Switch'
           */
          if (rtb_Switch1_a > 90.0) {
            /* Switch: '<S539>/Switch1' incorporates:
             *  Bias: '<S539>/Bias2'
             *  Bias: '<S539>/Bias3'
             *  Constant: '<S539>/Constant'
             *  Constant: '<S540>/Constant'
             *  Math: '<S539>/Math Function'
             *  RelationalOperator: '<S540>/Compare'
             */
            if (rtb_Switch1_a > 180.0) {
              rtb_Multiply_h_idx_0 = rt_modd(rtb_Multiply_h_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S539>/Switch1' */

            /* Signum: '<S536>/Sign' */
            if (rtb_Multiply_h_idx_0 < 0.0) {
              rtb_Multiply_h_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_h_idx_0 > 0.0) {
                rtb_Multiply_h_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S536>/Sign' */
            rtb_Multiply_h_idx_0 *= -(rtb_Switch1_a + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S533>/Sum' incorporates:
           *  Gain: '<S528>/Gain1'
           *  Gain: '<S528>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S531>/Sum'
           */
          rtb_Switch1_a = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S531>/Multiply' incorporates:
           *  Gain: '<S531>/deg2rad1'
           */
          rtb_Multiply_h_idx_0 = 0.017453292519943295 * rtb_Multiply_h_idx_0 *
            rtb_Sum3;

          /* Switch: '<S535>/Switch1' incorporates:
           *  Abs: '<S535>/Abs1'
           *  Bias: '<S535>/Bias2'
           *  Bias: '<S535>/Bias3'
           *  Constant: '<S535>/Constant'
           *  Constant: '<S537>/Constant'
           *  Math: '<S535>/Math Function'
           *  RelationalOperator: '<S537>/Compare'
           */
          if (fabs(rtb_Switch1_a) > 180.0) {
            rtb_Switch1_a = rt_modd(rtb_Switch1_a + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S535>/Switch1' */

          /* Product: '<S531>/Multiply' incorporates:
           *  Gain: '<S531>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_a;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S509>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S513>/Multiply1'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S522>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S522>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S522>/Trigonometric Function3' incorporates:
             *  Gain: '<S521>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S522>/Gain' incorporates:
             *  Gain: '<S521>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S522>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S522>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S522>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S522>/Trigonometric Function' incorporates:
             *  Gain: '<S521>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S522>/Trigonometric Function1' incorporates:
             *  Gain: '<S521>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S522>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

            /* Switch: '<S515>/Switch' incorporates:
             *  Constant: '<S530>/Constant'
             *  DataTypeConversion: '<S528>/Data Type Conversion1'
             *  Product: '<S534>/Multiply1'
             *  Product: '<S534>/Multiply2'
             *  RelationalOperator: '<S530>/Compare'
             *  S-Function (sfix_bitop): '<S527>/lat_cmd valid'
             *  Sum: '<S534>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              d = (real32_T)(rtb_Multiply_h_idx_0 * FMS_ConstB.SinCos_o2 +
                             rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              d = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S513>/Multiply' incorporates:
             *  Constant: '<S519>/Constant'
             *  Constant: '<S520>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S512>/Logical Operator'
             *  RelationalOperator: '<S519>/Compare'
             *  RelationalOperator: '<S520>/Compare'
             *  S-Function (sfix_bitop): '<S512>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/x_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S513>/Sum1'
             */
            rtb_Divide_l_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? d - FMS_U.INS_Out.x_R :
              0.0F;

            /* SignalConversion: '<S522>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

            /* Switch: '<S515>/Switch' incorporates:
             *  Constant: '<S530>/Constant'
             *  DataTypeConversion: '<S528>/Data Type Conversion1'
             *  Product: '<S534>/Multiply3'
             *  Product: '<S534>/Multiply4'
             *  RelationalOperator: '<S530>/Compare'
             *  S-Function (sfix_bitop): '<S527>/lon_cmd valid'
             *  Sum: '<S534>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              d = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                             rtb_Multiply_h_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              d = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S513>/Multiply' incorporates:
             *  Constant: '<S519>/Constant'
             *  Constant: '<S520>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S512>/Logical Operator'
             *  RelationalOperator: '<S519>/Compare'
             *  RelationalOperator: '<S520>/Compare'
             *  S-Function (sfix_bitop): '<S512>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/y_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S513>/Sum1'
             */
            rtb_Switch_fz_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? d - FMS_U.INS_Out.y_R :
              0.0F;

            /* SignalConversion: '<S522>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

            /* Switch: '<S515>/Switch' incorporates:
             *  Constant: '<S530>/Constant'
             *  DataTypeConversion: '<S528>/Data Type Conversion'
             *  DataTypeConversion: '<S528>/Data Type Conversion1'
             *  Gain: '<S528>/Gain2'
             *  Gain: '<S531>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S530>/Compare'
             *  S-Function (sfix_bitop): '<S527>/alt_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S531>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              d = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd + -FMS_U.INS_Out.alt_0);
            } else {
              d = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S513>/Multiply' incorporates:
             *  Constant: '<S519>/Constant'
             *  Constant: '<S520>/Constant'
             *  Gain: '<S516>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S512>/Logical Operator'
             *  RelationalOperator: '<S519>/Compare'
             *  RelationalOperator: '<S520>/Compare'
             *  S-Function (sfix_bitop): '<S512>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/z_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S513>/Sum1'
             */
            rtb_Switch_fz_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? d - (-FMS_U.INS_Out.h_R)
              : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Switch_fz_idx_2 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
            }

            /* SignalConversion: '<S455>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S455>/Constant4'
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  Product: '<S513>/Multiply1'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S455>/Trigonometric Function3' incorporates:
             *  Gain: '<S454>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S455>/Gain' incorporates:
             *  Gain: '<S454>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S455>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S455>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S455>/Constant3'
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S455>/Trigonometric Function' incorporates:
             *  Gain: '<S454>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S455>/Trigonometric Function1' incorporates:
             *  Gain: '<S454>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S455>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_eu[0];

            /* Product: '<S444>/Multiply' incorporates:
             *  Constant: '<S453>/Constant'
             *  RelationalOperator: '<S453>/Compare'
             *  S-Function (sfix_bitop): '<S450>/ax_cmd valid'
             */
            rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S455>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_eu[1];

            /* Product: '<S444>/Multiply' incorporates:
             *  Constant: '<S453>/Constant'
             *  RelationalOperator: '<S453>/Compare'
             *  S-Function (sfix_bitop): '<S450>/ay_cmd valid'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S455>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_eu[2];

            /* Product: '<S444>/Multiply' incorporates:
             *  Constant: '<S453>/Constant'
             *  RelationalOperator: '<S453>/Compare'
             *  S-Function (sfix_bitop): '<S450>/az_cmd valid'
             */
            rtb_Switch_fz_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S444>/Index Vector' incorporates:
             *  Product: '<S451>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Switch_fz_idx_2 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
            }
            break;

           case 1:
            /* SignalConversion: '<S525>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S525>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S525>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S514>/Data Store Read'
             *  Gain: '<S523>/Gain'
             *  Trigonometry: '<S525>/Trigonometric Function1'
             */
            rtb_Switch_fz_idx_1 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_Transpose[4] = rtb_Switch_fz_idx_1;

            /* Trigonometry: '<S525>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S514>/Data Store Read'
             *  Gain: '<S523>/Gain'
             *  Trigonometry: '<S525>/Trigonometric Function'
             */
            rtb_Switch_fz_idx_0 = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S525>/Gain' incorporates:
             *  Trigonometry: '<S525>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S525>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S525>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S525>/Trigonometric Function' */
            rtb_Transpose[1] = rtb_Switch_fz_idx_0;

            /* Trigonometry: '<S525>/Trigonometric Function1' */
            rtb_Transpose[0] = rtb_Switch_fz_idx_1;

            /* SignalConversion: '<S525>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* SignalConversion: '<S526>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_di[0];

            /* SignalConversion: '<S525>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* SignalConversion: '<S526>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_di[1];

            /* SignalConversion: '<S525>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* SignalConversion: '<S526>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_di[2];

            /* SignalConversion: '<S526>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S526>/Constant4'
             */
            rtb_MatrixConcatenate1_i[5] = 0.0F;

            /* Gain: '<S524>/Gain' incorporates:
             *  DataStoreRead: '<S514>/Data Store Read'
             *  Gain: '<S456>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S514>/Subtract'
             */
            rtb_Divide_l_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S526>/Trigonometric Function3' incorporates:
             *  Gain: '<S524>/Gain'
             *  Trigonometry: '<S526>/Trigonometric Function1'
             */
            rtb_u_mm = arm_cos_f32(rtb_Divide_l_idx_2);
            rtb_MatrixConcatenate1_i[4] = rtb_u_mm;

            /* Trigonometry: '<S526>/Trigonometric Function2' incorporates:
             *  Gain: '<S524>/Gain'
             *  Trigonometry: '<S526>/Trigonometric Function'
             */
            rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_Divide_l_idx_2);

            /* Gain: '<S526>/Gain' incorporates:
             *  Trigonometry: '<S526>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_i[3] = -rtb_Switch_fz_idx_0;

            /* SignalConversion: '<S526>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S526>/Constant3'
             */
            rtb_MatrixConcatenate1_i[2] = 0.0F;

            /* Trigonometry: '<S526>/Trigonometric Function' */
            rtb_MatrixConcatenate1_i[1] = rtb_Switch_fz_idx_0;

            /* Trigonometry: '<S526>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_i[0] = rtb_u_mm;

            /* RelationalOperator: '<S530>/Compare' incorporates:
             *  Constant: '<S530>/Constant'
             *  S-Function (sfix_bitop): '<S527>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S527>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S527>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S528>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S528>/Data Type Conversion'
             *  Gain: '<S528>/Gain2'
             *  Gain: '<S531>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S534>/Multiply1'
             *  Product: '<S534>/Multiply2'
             *  Product: '<S534>/Multiply3'
             *  Product: '<S534>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S531>/Sum1'
             *  Sum: '<S534>/Sum2'
             *  Sum: '<S534>/Sum3'
             */
            rtb_Multiply_h_0[0] = (real32_T)(rtb_Multiply_h_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Multiply_h_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_h_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Multiply_h_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S515>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* RelationalOperator: '<S519>/Compare' incorporates:
             *  Constant: '<S519>/Constant'
             *  S-Function (sfix_bitop): '<S512>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S520>/Compare' incorporates:
             *  Constant: '<S520>/Constant'
             *  S-Function (sfix_bitop): '<S512>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S514>/Sum2' incorporates:
               *  Product: '<S514>/Multiply2'
               *  Switch: '<S515>/Switch'
               */
              if (tmp[rtb_n]) {
                d = rtb_Multiply_h_0[rtb_n];
              } else {
                d = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              /* Product: '<S514>/Multiply' incorporates:
               *  Gain: '<S516>/Gain'
               *  Inport: '<Root>/INS_Out'
               *  Logic: '<S512>/Logical Operator'
               *  Product: '<S514>/Multiply2'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Sum: '<S514>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? d -
                ((rtb_Transpose[rtb_n + 3] * FMS_U.INS_Out.y_R +
                  rtb_Transpose[rtb_n] * FMS_U.INS_Out.x_R) +
                 rtb_Transpose[rtb_n + 6] * -FMS_U.INS_Out.h_R) : 0.0F;
            }

            /* SignalConversion: '<S457>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S457>/Constant4'
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S457>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[4] = arm_cos_f32(rtb_Divide_l_idx_2);

            /* Gain: '<S457>/Gain' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             *  Trigonometry: '<S457>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_l_idx_2);

            /* SignalConversion: '<S457>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S457>/Constant3'
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S457>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[1] = arm_sin_f32(rtb_Divide_l_idx_2);

            /* Trigonometry: '<S457>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S444>/Index Vector'
             */
            rtb_Transpose[0] = arm_cos_f32(rtb_Divide_l_idx_2);

            /* Product: '<S444>/Multiply' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S453>/Compare' incorporates:
             *  Constant: '<S453>/Constant'
             *  S-Function (sfix_bitop): '<S450>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S450>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S450>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S457>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S444>/Index Vector'
               */
              rtb_Transpose[rtb_n + 6] = FMS_ConstB.VectorConcatenate3_o[rtb_n];

              /* Product: '<S444>/Multiply' */
              rtb_Multiply_h_0[rtb_n] = tmp[rtb_n] ?
                rtb_MatrixConcatenate1_i_0[rtb_n] : 0.0F;
              rtb_Switch_d0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
                rtb_Switch_ov[2] + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                                    rtb_Switch_ov[1] +
                                    rtb_MatrixConcatenate1_i[rtb_n] *
                                    rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S444>/Index Vector' incorporates:
             *  Product: '<S452>/Multiply3'
             *  Product: '<S514>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Multiply_h_0[2] + (rtb_Transpose[rtb_n + 3] *
                rtb_Multiply_h_0[1] + rtb_Transpose[rtb_n] * rtb_Multiply_h_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S518>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_d[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_d[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* SignalConversion: '<S518>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S518>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S518>/Trigonometric Function3' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S518>/Gain' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S518>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S518>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S518>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S518>/Trigonometric Function' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S518>/Trigonometric Function1' incorporates:
             *  Gain: '<S517>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S527>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S512>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S530>/Compare' incorporates:
             *  Constant: '<S530>/Constant'
             *  S-Function (sfix_bitop): '<S527>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S527>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S512>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S530>/Compare' incorporates:
             *  Constant: '<S530>/Constant'
             *  S-Function (sfix_bitop): '<S527>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S527>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S512>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S530>/Compare' incorporates:
             *  Constant: '<S530>/Constant'
             *  S-Function (sfix_bitop): '<S527>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S528>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S528>/Data Type Conversion'
             *  Gain: '<S528>/Gain2'
             *  Gain: '<S531>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S534>/Multiply1'
             *  Product: '<S534>/Multiply2'
             *  Product: '<S534>/Multiply3'
             *  Product: '<S534>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S531>/Sum1'
             *  Sum: '<S534>/Sum2'
             *  Sum: '<S534>/Sum3'
             */
            rtb_Multiply_h_0[0] = (real32_T)(rtb_Multiply_h_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Multiply_h_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_h_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Multiply_h_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S515>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* RelationalOperator: '<S519>/Compare' incorporates:
             *  Constant: '<S519>/Constant'
             *  S-Function (sfix_bitop): '<S512>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S520>/Compare' incorporates:
             *  Constant: '<S520>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S511>/Sum2' incorporates:
             *  Gain: '<S516>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S512>/Logical Operator'
             *  Product: '<S511>/Multiply'
             *  Product: '<S511>/Multiply2'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S515>/Switch' incorporates:
               *  Product: '<S511>/Multiply2'
               */
              if (tmp[rtb_n]) {
                d = rtb_Multiply_h_0[rtb_n];
              } else {
                d = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              rtb_Switch_d0[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? d -
                ((rtb_Transpose[rtb_n + 3] * FMS_U.INS_Out.y_R +
                  rtb_Transpose[rtb_n] * FMS_U.INS_Out.x_R) +
                 rtb_Transpose[rtb_n + 6] * -FMS_U.INS_Out.h_R) : 0.0F;
            }

            /* End of Sum: '<S511>/Sum2' */

            /* MultiPortSwitch: '<S444>/Index Vector' incorporates:
             *  Constant: '<S453>/Constant'
             *  Product: '<S444>/Multiply'
             *  RelationalOperator: '<S453>/Compare'
             *  S-Function (sfix_bitop): '<S450>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S450>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S450>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S509>/Index Vector' */

          /* Sum: '<S505>/Sum1' incorporates:
           *  Constant: '<S505>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S505>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_l_idx_3 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S506>/Abs' */
          rtb_Divide_l_idx_2 = fabsf(rtb_Divide_l_idx_3);

          /* Switch: '<S506>/Switch' incorporates:
           *  Constant: '<S506>/Constant'
           *  Constant: '<S507>/Constant'
           *  Product: '<S506>/Multiply'
           *  RelationalOperator: '<S507>/Compare'
           *  Sum: '<S506>/Subtract'
           */
          if (rtb_Divide_l_idx_2 > 3.14159274F) {
            /* Signum: '<S506>/Sign' */
            if (rtb_Divide_l_idx_3 < 0.0F) {
              rtb_Divide_l_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_3 > 0.0F) {
                rtb_Divide_l_idx_3 = 1.0F;
              }
            }

            /* End of Signum: '<S506>/Sign' */
            rtb_Divide_l_idx_3 *= rtb_Divide_l_idx_2 - 6.28318548F;
          }

          /* End of Switch: '<S506>/Switch' */

          /* Saturate: '<S505>/Saturation' */
          if (rtb_Divide_l_idx_3 > 0.314159274F) {
            rtb_Divide_l_idx_3 = 0.314159274F;
          } else {
            if (rtb_Divide_l_idx_3 < -0.314159274F) {
              rtb_Divide_l_idx_3 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S505>/Saturation' */

          /* Gain: '<S502>/Gain2' */
          rtb_Divide_l_idx_3 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S446>/Sum' incorporates:
           *  Constant: '<S504>/Constant'
           *  Constant: '<S508>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S502>/Multiply2'
           *  Product: '<S503>/Multiply1'
           *  RelationalOperator: '<S504>/Compare'
           *  RelationalOperator: '<S508>/Compare'
           *  S-Function (sfix_bitop): '<S502>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S503>/psi_rate_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          d = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Divide_l_idx_3 : 0.0F)
            + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
               FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S509>/Gain1' */
          rtb_u_mm = FMS_PARAM.XY_P * rtb_Switch_d0[0];
          rtb_Switch_fz_idx_0 = FMS_PARAM.XY_P * rtb_Switch_d0[1];

          /* Gain: '<S509>/Gain2' */
          rtb_Divide_l_idx_3 = FMS_PARAM.Z_P * rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S510>/Index Vector' incorporates:
           *  Constant: '<S546>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S510>/Multiply'
           *  Product: '<S543>/Multiply'
           *  Product: '<S544>/Multiply3'
           *  RelationalOperator: '<S546>/Compare'
           *  S-Function (sfix_bitop): '<S542>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S542>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S542>/w_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S548>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S548>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Trigonometry: '<S548>/Trigonometric Function3' incorporates:
             *  Gain: '<S547>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S548>/Gain' incorporates:
             *  Gain: '<S547>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S548>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S548>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S548>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S548>/Trigonometric Function' incorporates:
             *  Gain: '<S547>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S548>/Trigonometric Function1' incorporates:
             *  Gain: '<S547>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S548>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_n[0];

            /* Product: '<S510>/Multiply' incorporates:
             *  Constant: '<S546>/Constant'
             *  RelationalOperator: '<S546>/Compare'
             *  S-Function (sfix_bitop): '<S542>/u_cmd valid'
             */
            rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S548>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_n[1];

            /* Product: '<S510>/Multiply' incorporates:
             *  Constant: '<S546>/Constant'
             *  RelationalOperator: '<S546>/Compare'
             *  S-Function (sfix_bitop): '<S542>/v_cmd valid'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S548>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_n[2];

            /* Product: '<S510>/Multiply' incorporates:
             *  Constant: '<S546>/Constant'
             *  RelationalOperator: '<S546>/Compare'
             *  S-Function (sfix_bitop): '<S542>/w_cmd valid'
             */
            rtb_Switch_fz_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Switch_fz_idx_2 + (rtb_Transpose[rtb_n + 3] *
                rtb_Switch_fz_idx_1 + rtb_Transpose[rtb_n] * rtb_Divide_l_idx_2);
            }
            break;

           case 1:
            /* SignalConversion: '<S550>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S550>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Gain: '<S549>/Gain' incorporates:
             *  DataStoreRead: '<S544>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S544>/Subtract'
             */
            rtb_Divide_l_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S550>/Trigonometric Function3' incorporates:
             *  Gain: '<S549>/Gain'
             */
            rtb_Transpose[4] = arm_cos_f32(rtb_Divide_l_idx_2);

            /* Gain: '<S550>/Gain' incorporates:
             *  Gain: '<S549>/Gain'
             *  Trigonometry: '<S550>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_l_idx_2);

            /* SignalConversion: '<S550>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S550>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S550>/Trigonometric Function' incorporates:
             *  Gain: '<S549>/Gain'
             */
            rtb_Transpose[1] = arm_sin_f32(rtb_Divide_l_idx_2);

            /* Trigonometry: '<S550>/Trigonometric Function1' incorporates:
             *  Gain: '<S549>/Gain'
             */
            rtb_Transpose[0] = arm_cos_f32(rtb_Divide_l_idx_2);

            /* SignalConversion: '<S550>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_oh[0];

            /* Product: '<S510>/Multiply' incorporates:
             *  Constant: '<S546>/Constant'
             *  RelationalOperator: '<S546>/Compare'
             *  S-Function (sfix_bitop): '<S542>/u_cmd valid'
             */
            rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S550>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_oh[1];

            /* Product: '<S510>/Multiply' incorporates:
             *  Constant: '<S546>/Constant'
             *  RelationalOperator: '<S546>/Compare'
             *  S-Function (sfix_bitop): '<S542>/v_cmd valid'
             */
            rtb_Switch_fz_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S550>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_oh[2];

            /* Product: '<S510>/Multiply' incorporates:
             *  Constant: '<S546>/Constant'
             *  RelationalOperator: '<S546>/Compare'
             *  S-Function (sfix_bitop): '<S542>/w_cmd valid'
             */
            rtb_Switch_fz_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_d0[rtb_n] = rtb_Transpose[rtb_n + 6] *
                rtb_Switch_fz_idx_2 + (rtb_Transpose[rtb_n + 3] *
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

          /* End of MultiPortSwitch: '<S510>/Index Vector' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_d0[0] += rtb_u_mm;
          rtb_Switch_d0[1] += rtb_Switch_fz_idx_0;

          /* Sum: '<S447>/Sum1' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + rtb_Switch_d0[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S465>/Switch' incorporates:
           *  Constant: '<S480>/Constant'
           *  Constant: '<S482>/Constant'
           *  Constant: '<S483>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S480>/Compare'
           *  RelationalOperator: '<S482>/Compare'
           *  RelationalOperator: '<S483>/Compare'
           *  S-Function (sfix_bitop): '<S465>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S465>/y_v_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S465>/Logical Operator' incorporates:
             *  Constant: '<S481>/Constant'
             *  Constant: '<S482>/Constant'
             *  Constant: '<S483>/Constant'
             *  RelationalOperator: '<S481>/Compare'
             *  RelationalOperator: '<S482>/Compare'
             *  RelationalOperator: '<S483>/Compare'
             *  S-Function (sfix_bitop): '<S465>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S465>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S465>/y_v_cmd'
             */
            rtb_LogicalOperator_op = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_op;
          } else {
            rtb_LogicalOperator_op = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U)
              > 0U);
          }

          /* End of Switch: '<S465>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S445>/u_cmd_valid' */
          /* MATLAB Function: '<S477>/bit_shift' incorporates:
           *  DataTypeConversion: '<S445>/Data Type Conversion6'
           */
          rtb_DataTypeConversion_o = (uint16_T)(rtb_LogicalOperator_op << 6);

          /* End of Outputs for SubSystem: '<S445>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S445>/v_cmd_valid' */
          /* MATLAB Function: '<S478>/bit_shift' incorporates:
           *  DataTypeConversion: '<S445>/Data Type Conversion7'
           */
          rtb_DataTypeConversion1_h = (uint16_T)(rtb_FixPtRelationalOperator_me <<
            7);

          /* End of Outputs for SubSystem: '<S445>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S466>/Switch' incorporates:
           *  Constant: '<S485>/Constant'
           *  Constant: '<S486>/Constant'
           *  Constant: '<S488>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S485>/Compare'
           *  RelationalOperator: '<S486>/Compare'
           *  RelationalOperator: '<S488>/Compare'
           *  S-Function (sfix_bitop): '<S466>/ax_cmd'
           *  S-Function (sfix_bitop): '<S466>/ay_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S466>/Logical Operator' incorporates:
             *  Constant: '<S486>/Constant'
             *  Constant: '<S488>/Constant'
             *  RelationalOperator: '<S486>/Compare'
             *  RelationalOperator: '<S488>/Compare'
             *  S-Function (sfix_bitop): '<S466>/ax_cmd'
             *  S-Function (sfix_bitop): '<S466>/ay_cmd'
             */
            rtb_LogicalOperator_op = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_op;
          } else {
            rtb_LogicalOperator_op = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S466>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S365>/Bus Assignment' incorporates:
           *  Constant: '<S365>/Constant'
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
          FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ov[0];
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ov[1];
          FMS_Y.FMS_Out.az_cmd = rtb_Switch_ov[2];

          /* Saturate: '<S446>/Saturation' */
          if (d > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (d < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = d;
          }

          /* End of Saturate: '<S446>/Saturation' */

          /* Saturate: '<S447>/Saturation2' */
          if (rtb_Switch_d0[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_d0[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_d0[0];
          }

          /* End of Saturate: '<S447>/Saturation2' */

          /* Saturate: '<S447>/Saturation1' */
          if (rtb_Switch_d0[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_d0[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_d0[1];
          }

          /* End of Saturate: '<S447>/Saturation1' */

          /* Saturate: '<S447>/Saturation3' */
          if (rtb_Divide_l_idx_2 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_l_idx_2 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S365>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Divide_l_idx_2;
          }

          /* End of Saturate: '<S447>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S445>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S445>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S445>/throttle_cmd_valid' */
          /* BusAssignment: '<S365>/Bus Assignment' incorporates:
           *  Constant: '<S458>/Constant'
           *  Constant: '<S459>/Constant'
           *  Constant: '<S460>/Constant'
           *  Constant: '<S461>/Constant'
           *  Constant: '<S462>/Constant'
           *  Constant: '<S463>/Constant'
           *  Constant: '<S464>/Constant'
           *  Constant: '<S484>/Constant'
           *  Constant: '<S487>/Constant'
           *  DataTypeConversion: '<S445>/Data Type Conversion10'
           *  DataTypeConversion: '<S445>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S467>/bit_shift'
           *  MATLAB Function: '<S468>/bit_shift'
           *  MATLAB Function: '<S469>/bit_shift'
           *  MATLAB Function: '<S471>/bit_shift'
           *  MATLAB Function: '<S472>/bit_shift'
           *  MATLAB Function: '<S473>/bit_shift'
           *  MATLAB Function: '<S474>/bit_shift'
           *  MATLAB Function: '<S475>/bit_shift'
           *  MATLAB Function: '<S476>/bit_shift'
           *  MATLAB Function: '<S479>/bit_shift'
           *  RelationalOperator: '<S458>/Compare'
           *  RelationalOperator: '<S459>/Compare'
           *  RelationalOperator: '<S460>/Compare'
           *  RelationalOperator: '<S461>/Compare'
           *  RelationalOperator: '<S462>/Compare'
           *  RelationalOperator: '<S463>/Compare'
           *  RelationalOperator: '<S464>/Compare'
           *  RelationalOperator: '<S484>/Compare'
           *  RelationalOperator: '<S487>/Compare'
           *  S-Function (sfix_bitop): '<S445>/p_cmd'
           *  S-Function (sfix_bitop): '<S445>/phi_cmd'
           *  S-Function (sfix_bitop): '<S445>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S445>/q_cmd'
           *  S-Function (sfix_bitop): '<S445>/r_cmd'
           *  S-Function (sfix_bitop): '<S445>/theta_cmd'
           *  S-Function (sfix_bitop): '<S445>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S465>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S466>/az_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           *  Sum: '<S445>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) +
            rtb_DataTypeConversion_o) + rtb_DataTypeConversion1_h) +
            (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
            (rtb_LogicalOperator_op << 9)) + (rtb_FixPtRelationalOperator_me <<
            10)) + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S445>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S445>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S445>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S252>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S252>/Mission' incorporates:
             *  ActionPort: '<S364>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S252>/Switch Case' incorporates:
             *  UnitDelay: '<S367>/Delay Input1'
             *
             * Block description for '<S367>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S252>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S252>/Mission' incorporates:
             *  ActionPort: '<S364>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S364>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S252>/Switch Case' incorporates:
             *  Chart: '<S403>/Motion Status'
             *  Chart: '<S413>/Motion State'
             *  Delay: '<S372>/Delay'
             *  Delay: '<S394>/Delay'
             *  DiscreteIntegrator: '<S375>/Integrator'
             *  DiscreteIntegrator: '<S375>/Integrator1'
             *  DiscreteIntegrator: '<S390>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S395>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S439>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S364>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S252>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S252>/Mission' incorporates:
           *  ActionPort: '<S364>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S367>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S367>/Delay Input1'
           *
           * Block description for '<S367>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S364>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S368>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S412>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S402>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

            /* InitializeConditions for Delay: '<S394>/Delay' */
            FMS_DW.icLoad = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S395>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S390>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S372>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S413>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S403>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_h);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S394>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S395>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S367>/Delay Input1'
           *
           * Block description for '<S367>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTAT_kd;

          /* RelationalOperator: '<S389>/Compare' incorporates:
           *  Constant: '<S443>/Constant'
           *  RelationalOperator: '<S443>/Compare'
           *  UnitDelay: '<S367>/Delay Input1'
           *
           * Block description for '<S367>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_ii = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S390>/Acceleration_Speed' */
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
          /* Chart: '<S413>/Motion State' incorporates:
           *  Constant: '<S413>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S413>/Square'
           *  Math: '<S413>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S413>/Sqrt'
           *  Sum: '<S413>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S412>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S412>/Hold Control' incorporates:
               *  ActionPort: '<S415>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S412>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_fy);

              /* End of SystemReset for SubSystem: '<S412>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S412>/Hold Control' incorporates:
             *  ActionPort: '<S415>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_ls,
                              &FMS_ConstB.HoldControl_fy, &FMS_DW.HoldControl_fy);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S412>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S412>/Brake Control' incorporates:
             *  ActionPort: '<S414>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_ls);

            /* End of Outputs for SubSystem: '<S412>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S412>/Move Control' incorporates:
               *  ActionPort: '<S416>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S412>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_i);

              /* End of SystemReset for SubSystem: '<S412>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S412>/Move Control' incorporates:
             *  ActionPort: '<S416>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_ls,
                              &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S412>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S412>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S403>/Motion Status' incorporates:
           *  Abs: '<S403>/Abs'
           *  Constant: '<S403>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_h);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S402>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S402>/Hold Control' incorporates:
               *  ActionPort: '<S405>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S402>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bf);

              /* End of SystemReset for SubSystem: '<S402>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S402>/Hold Control' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_i,
                              &FMS_DW.HoldControl_bf);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S402>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S402>/Brake Control' incorporates:
             *  ActionPort: '<S404>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_i);

            /* End of Outputs for SubSystem: '<S402>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S402>/Move Control' incorporates:
               *  ActionPort: '<S406>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S402>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c0);

              /* End of SystemReset for SubSystem: '<S402>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S402>/Move Control' incorporates:
             *  ActionPort: '<S406>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_i,
                              &FMS_ConstB.MoveControl_c0, &FMS_DW.MoveControl_c0);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S402>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S402>/Switch Case' */

          /* Switch: '<S370>/Switch' incorporates:
           *  Product: '<S394>/Multiply'
           *  Sum: '<S394>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S412>/Saturation1' */
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

            /* End of Saturate: '<S412>/Saturation1' */

            /* Saturate: '<S402>/Saturation1' */
            if (FMS_B.Merge_i > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_fz_idx_2 = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_i < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_fz_idx_2 = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_fz_idx_2 = FMS_B.Merge_i;
            }

            /* End of Saturate: '<S402>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S394>/Sum' incorporates:
             *  Delay: '<S394>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S440>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S390>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_n4[0] = rtb_Switch_fz_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S394>/Sum' incorporates:
             *  Delay: '<S394>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE[1];

            /* Sum: '<S390>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_u_mm = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S399>/Sqrt' incorporates:
             *  Math: '<S399>/Square'
             *  Sum: '<S390>/Sum'
             *  Sum: '<S399>/Sum of Elements'
             */
            rtb_u_mm = sqrtf(rtb_Switch_fz_idx_1 * rtb_Switch_fz_idx_1 +
                             rtb_u_mm * rtb_u_mm);

            /* SignalConversion: '<S442>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

            /* SignalConversion: '<S442>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S442>/Constant4'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S441>/Gain' incorporates:
             *  DiscreteIntegrator: '<S439>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S439>/Add'
             */
            rtb_Switch_fz_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S442>/Trigonometric Function3' */
            rtb_Transpose[4] = arm_cos_f32(rtb_Switch_fz_idx_1);

            /* Gain: '<S442>/Gain' incorporates:
             *  Trigonometry: '<S442>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_Switch_fz_idx_1);

            /* SignalConversion: '<S442>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S442>/Constant3'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S442>/Trigonometric Function' */
            rtb_Transpose[1] = arm_sin_f32(rtb_Switch_fz_idx_1);

            /* Trigonometry: '<S442>/Trigonometric Function1' */
            rtb_Transpose[0] = arm_cos_f32(rtb_Switch_fz_idx_1);

            /* Switch: '<S390>/Switch' incorporates:
             *  Constant: '<S390>/vel'
             */
            if (rtb_u_mm > FMS_PARAM.L1) {
              rtb_Switch_fz_idx_1 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S390>/Gain' */
              rtb_Switch_fz_idx_1 = 0.5F * rtb_u_mm;

              /* Saturate: '<S390>/Saturation' */
              if (rtb_Switch_fz_idx_1 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Switch_fz_idx_1 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Switch_fz_idx_1 < 0.5F) {
                  rtb_Switch_fz_idx_1 = 0.5F;
                }
              }

              /* End of Saturate: '<S390>/Saturation' */
            }

            /* End of Switch: '<S390>/Switch' */

            /* Switch: '<S390>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S390>/Acceleration_Speed'
             *  Sum: '<S390>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE - rtb_Switch_fz_idx_1 < 0.0F) {
              rtb_Switch_fz_idx_1 = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S390>/Switch1' */

            /* Sum: '<S440>/Sum of Elements' incorporates:
             *  Math: '<S440>/Math Function'
             */
            d = rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0 + rtb_Switch_fz_idx_2 *
              rtb_Switch_fz_idx_2;

            /* Math: '<S440>/Math Function1' incorporates:
             *  Sum: '<S440>/Sum of Elements'
             *
             * About '<S440>/Math Function1':
             *  Operator: sqrt
             */
            if (d < 0.0F) {
              d = -sqrtf(fabsf(d));
            } else {
              d = sqrtf(d);
            }

            /* End of Math: '<S440>/Math Function1' */

            /* Switch: '<S440>/Switch' incorporates:
             *  Constant: '<S440>/Constant'
             *  Product: '<S440>/Product'
             */
            if (d > 0.0F) {
              rtb_u_mm = rtb_Divide_n4[0];
            } else {
              rtb_u_mm = 0.0F;
              rtb_Switch_fz_idx_2 = 0.0F;
              d = 1.0F;
            }

            /* End of Switch: '<S440>/Switch' */

            /* Product: '<S438>/Multiply2' incorporates:
             *  Product: '<S440>/Divide'
             */
            rtb_Divide_or = rtb_u_mm / d * rtb_Switch_fz_idx_1;
            rtb_Sign5_mn = rtb_Switch_fz_idx_2 / d * rtb_Switch_fz_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S396>/Sum1' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S396>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_fz_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
              [0];
            rtb_u_mm = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S396>/Divide' incorporates:
             *  Math: '<S397>/Square'
             *  Math: '<S398>/Square'
             *  Sqrt: '<S397>/Sqrt'
             *  Sqrt: '<S398>/Sqrt'
             *  Sum: '<S396>/Sum'
             *  Sum: '<S396>/Sum1'
             *  Sum: '<S397>/Sum of Elements'
             *  Sum: '<S398>/Sum of Elements'
             */
            rtb_Switch_fz_idx_1 = sqrtf(rtb_Switch_fz_idx_1 *
              rtb_Switch_fz_idx_1 + rtb_u_mm * rtb_u_mm) / sqrtf(rtb_Subtract3_d
              * rtb_Subtract3_d + d * d);

            /* Saturate: '<S396>/Saturation' */
            if (rtb_Switch_fz_idx_1 > 1.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              if (rtb_Switch_fz_idx_1 < 0.0F) {
                rtb_Switch_fz_idx_1 = 0.0F;
              }
            }

            /* End of Saturate: '<S396>/Saturation' */

            /* Product: '<S394>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_Transpose[rtb_n + 3] *
                rtb_Sign5_mn + rtb_Transpose[rtb_n] * rtb_Divide_or;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S387>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S396>/Multiply'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S387>/Sum2'
             *  Sum: '<S396>/Add'
             *  Sum: '<S396>/Subtract'
             */
            rtb_Switch_fz_idx_2 = (FMS_U.INS_Out.h_R -
              ((FMS_B.Cmd_In.sp_waypoint[2] - FMS_B.Cmd_In.cur_waypoint[2]) *
               rtb_Switch_fz_idx_1 + FMS_B.Cmd_In.cur_waypoint[2])) *
              FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_fz_idx_0 = rtb_MatrixConcatenate1_i_0[0];
            rtb_Switch_fz_idx_1 = rtb_MatrixConcatenate1_i_0[1];

            /* Saturate: '<S387>/Saturation1' incorporates:
             *  Product: '<S394>/Multiply'
             */
            if (rtb_Switch_fz_idx_2 > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_fz_idx_2 = FMS_PARAM.VEL_Z_LIM;
            } else {
              if (rtb_Switch_fz_idx_2 < -FMS_PARAM.VEL_Z_LIM) {
                rtb_Switch_fz_idx_2 = -FMS_PARAM.VEL_Z_LIM;
              }
            }

            /* End of Saturate: '<S387>/Saturation1' */
          }

          /* End of Switch: '<S370>/Switch' */

          /* Delay: '<S372>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S375>/Integrator1' incorporates:
           *  Delay: '<S372>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S379>/Rem' incorporates:
           *  Constant: '<S379>/Constant1'
           *  DiscreteIntegrator: '<S375>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S374>/Sum'
           */
          rtb_Subtract3_d = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S379>/Switch' incorporates:
           *  Abs: '<S379>/Abs'
           *  Constant: '<S379>/Constant'
           *  Constant: '<S380>/Constant'
           *  Product: '<S379>/Multiply'
           *  RelationalOperator: '<S380>/Compare'
           *  Sum: '<S379>/Add'
           */
          if (fabsf(rtb_Subtract3_d) > 3.14159274F) {
            /* Signum: '<S379>/Sign' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_u_mm = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_u_mm = 1.0F;
            } else {
              rtb_u_mm = rtb_Subtract3_d;
            }

            /* End of Signum: '<S379>/Sign' */
            rtb_Subtract3_d -= 6.28318548F * rtb_u_mm;
          }

          /* End of Switch: '<S379>/Switch' */

          /* Gain: '<S374>/Gain2' */
          rtb_Subtract3_d *= FMS_PARAM.YAW_P;

          /* Saturate: '<S374>/Saturation' */
          if (rtb_Subtract3_d > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Subtract3_d = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Subtract3_d < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Subtract3_d = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S374>/Saturation' */

          /* BusAssignment: '<S368>/Bus Assignment' incorporates:
           *  Constant: '<S368>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_fz_idx_0;
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_fz_idx_1;
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_fz_idx_2;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_d;

          /* Math: '<S433>/Math Function1'
           *
           * About '<S433>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S433>/Math Function1' */

          /* Switch: '<S433>/Switch' incorporates:
           *  Constant: '<S433>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S433>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
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

          /* End of Switch: '<S433>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S368>/Sum' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
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

          /* Math: '<S386>/Math Function' incorporates:
           *  Sum: '<S368>/Sum'
           */
          rtb_Square_h[0] = rtb_Divide_or * rtb_Divide_or;
          rtb_Square_h[1] = rtb_Sign5_mn * rtb_Sign5_mn;

          /* Sum: '<S386>/Sum of Elements' */
          d = rtb_Square_h[0] + rtb_Square_h[1];

          /* Math: '<S386>/Math Function1' incorporates:
           *  Sum: '<S386>/Sum of Elements'
           *
           * About '<S386>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(d));
          } else {
            rtb_Subtract3_d = sqrtf(d);
          }

          /* End of Math: '<S386>/Math Function1' */

          /* Switch: '<S386>/Switch' incorporates:
           *  Constant: '<S386>/Constant'
           *  Product: '<S386>/Product'
           */
          if (rtb_Subtract3_d > 0.0F) {
            rtb_MathFunction_n_idx_2 = rtb_Subtract3_d;
          } else {
            rtb_Divide_or = 0.0F;
            rtb_Sign5_mn = 0.0F;
            rtb_MathFunction_n_idx_2 = 1.0F;
          }

          /* End of Switch: '<S386>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S392>/NearbyRefWP' incorporates:
           *  Constant: '<S368>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_d0[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_dg, &d);

          /* MATLAB Function: '<S392>/SearchL1RefWP' incorporates:
           *  Constant: '<S368>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_Switch_d0[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_Square_h, &rtb_u_mm);

          /* MATLAB Function: '<S392>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
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
          rtb_LogicalOperator_op = (rtb_Divide_l_idx_2 >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else if (rtb_LogicalOperator_op) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract3_d = rtb_Divide_l_idx_2 * rtb_Subtract3_d +
              FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Switch: '<S392>/Switch1' incorporates:
           *  Constant: '<S426>/Constant'
           *  RelationalOperator: '<S426>/Compare'
           */
          if (d <= 0.0F) {
            /* Switch: '<S392>/Switch' incorporates:
             *  Constant: '<S425>/Constant'
             *  RelationalOperator: '<S425>/Compare'
             */
            if (rtb_u_mm >= 0.0F) {
              rtb_P_dg[0] = rtb_Square_h[0];
              rtb_P_dg[1] = rtb_Square_h[1];
            } else {
              rtb_P_dg[0] = rtb_Subtract3_d;

              /* MATLAB Function: '<S392>/OutRegionRegWP' incorporates:
               *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_P_dg[1] = FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              } else if (rtb_LogicalOperator_op) {
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

            /* End of Switch: '<S392>/Switch' */
          }

          /* End of Switch: '<S392>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S393>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          D = rtb_P_dg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S434>/Math Function' */
          rtb_P_cg[0] = D * D;
          rtb_u_mm = D;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S393>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          D = rtb_P_dg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S434>/Math Function' incorporates:
           *  Math: '<S432>/Square'
           */
          d = D * D;

          /* Sum: '<S434>/Sum of Elements' incorporates:
           *  Math: '<S434>/Math Function'
           */
          rtb_Divide_l_idx_2 = d + rtb_P_cg[0];

          /* Math: '<S434>/Math Function1' incorporates:
           *  Sum: '<S434>/Sum of Elements'
           *
           * About '<S434>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S434>/Math Function1' */

          /* Switch: '<S434>/Switch' incorporates:
           *  Constant: '<S434>/Constant'
           *  Product: '<S434>/Product'
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

          /* End of Switch: '<S434>/Switch' */

          /* Product: '<S433>/Divide' */
          rtb_P_cg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;
          rtb_P_cg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Sum: '<S436>/Sum of Elements' incorporates:
           *  Math: '<S436>/Math Function'
           *  SignalConversion: '<S436>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

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
            rtb_Switch_fz_idx_0 = rtb_P_cg[1];
            rtb_Switch_fz_idx_1 = rtb_P_cg[0];
            rtb_Switch_fz_idx_2 = rtb_Subtract3_d;
          } else {
            rtb_Switch_fz_idx_0 = 0.0F;
            rtb_Switch_fz_idx_1 = 0.0F;
            rtb_Switch_fz_idx_2 = 1.0F;
          }

          /* End of Switch: '<S436>/Switch' */

          /* Product: '<S434>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Sum: '<S437>/Sum of Elements' incorporates:
           *  Math: '<S437>/Math Function'
           *  SignalConversion: '<S437>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_2 = rtb_P_cg[1] * rtb_P_cg[1] + rtb_P_cg[0] *
            rtb_P_cg[0];

          /* Math: '<S437>/Math Function1' incorporates:
           *  Sum: '<S437>/Sum of Elements'
           *
           * About '<S437>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Subtract3_d = -sqrtf(fabsf(rtb_Divide_l_idx_2));
          } else {
            rtb_Subtract3_d = sqrtf(rtb_Divide_l_idx_2);
          }

          /* End of Math: '<S437>/Math Function1' */

          /* Switch: '<S437>/Switch' incorporates:
           *  Constant: '<S437>/Constant'
           *  Product: '<S437>/Product'
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

          /* End of Switch: '<S437>/Switch' */

          /* Product: '<S437>/Divide' */
          rtb_P_cg[0] = rtb_Switch_d0[0] / rtb_Switch_d0[2];

          /* Product: '<S436>/Divide' */
          rtb_P_dg[0] = rtb_Switch_fz_idx_0 / rtb_Switch_fz_idx_2;

          /* Product: '<S386>/Divide' */
          rtb_Square_h[0] = rtb_Divide_or / rtb_MathFunction_n_idx_2;
          rtb_u_mm *= rtb_u_mm;

          /* Product: '<S437>/Divide' incorporates:
           *  Math: '<S432>/Square'
           */
          rtb_P_cg[1] = rtb_Switch_d0[1] / rtb_Switch_d0[2];

          /* Product: '<S436>/Divide' */
          rtb_P_dg[1] = rtb_Switch_fz_idx_1 / rtb_Switch_fz_idx_2;

          /* Product: '<S386>/Divide' */
          rtb_Square_h[1] = rtb_Sign5_mn / rtb_MathFunction_n_idx_2;

          /* Sum: '<S435>/Subtract' incorporates:
           *  Product: '<S435>/Multiply'
           *  Product: '<S435>/Multiply1'
           */
          rtb_Subtract3_d = rtb_P_cg[0] * rtb_P_dg[1] - rtb_P_cg[1] * rtb_P_dg[0];

          /* Signum: '<S430>/Sign1' */
          if (rtb_Subtract3_d < 0.0F) {
            rtb_Subtract3_d = -1.0F;
          } else {
            if (rtb_Subtract3_d > 0.0F) {
              rtb_Subtract3_d = 1.0F;
            }
          }

          /* End of Signum: '<S430>/Sign1' */

          /* Switch: '<S430>/Switch2' incorporates:
           *  Constant: '<S430>/Constant4'
           */
          if (rtb_Subtract3_d == 0.0F) {
            rtb_Subtract3_d = 1.0F;
          }

          /* End of Switch: '<S430>/Switch2' */

          /* DotProduct: '<S430>/Dot Product' */
          rtb_Divide_l_idx_2 = rtb_P_dg[0] * rtb_P_cg[0] + rtb_P_dg[1] *
            rtb_P_cg[1];

          /* Trigonometry: '<S430>/Acos' incorporates:
           *  DotProduct: '<S430>/Dot Product'
           */
          if (rtb_Divide_l_idx_2 > 1.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_l_idx_2 < -1.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            }
          }

          /* Product: '<S430>/Multiply' incorporates:
           *  Trigonometry: '<S430>/Acos'
           */
          rtb_Subtract3_d *= acosf(rtb_Divide_l_idx_2);

          /* Saturate: '<S393>/Saturation' */
          if (rtb_Subtract3_d > 1.57079637F) {
            rtb_Subtract3_d = 1.57079637F;
          } else {
            if (rtb_Subtract3_d < -1.57079637F) {
              rtb_Subtract3_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S393>/Saturation' */

          /* Product: '<S393>/Divide' incorporates:
           *  Constant: '<S368>/L1'
           *  Constant: '<S393>/Constant'
           *  Gain: '<S393>/Gain'
           *  Math: '<S393>/Square'
           *  MinMax: '<S393>/Max'
           *  MinMax: '<S393>/Min'
           *  Product: '<S393>/Multiply1'
           *  Sqrt: '<S432>/Sqrt'
           *  Sum: '<S432>/Sum of Elements'
           *  Trigonometry: '<S393>/Sin'
           */
          rtb_Switch_fz_idx_0 = arm_sin_f32(rtb_Subtract3_d) *
            (rtb_Divide_l_idx_3 * rtb_Divide_l_idx_3 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(d + rtb_u_mm), 0.5F));

          /* Sum: '<S384>/Subtract' incorporates:
           *  Product: '<S384>/Multiply'
           *  Product: '<S384>/Multiply1'
           */
          rtb_Switch_fz_idx_1 = rtb_Square_h[0] * FMS_ConstB.Divide[1] -
            rtb_Square_h[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S373>/Sign1' */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Switch_fz_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_1 > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S373>/Sign1' */

          /* Switch: '<S373>/Switch2' incorporates:
           *  Constant: '<S373>/Constant4'
           */
          if (rtb_Switch_fz_idx_1 == 0.0F) {
            rtb_Switch_fz_idx_1 = 1.0F;
          }

          /* End of Switch: '<S373>/Switch2' */

          /* DotProduct: '<S373>/Dot Product' */
          d = FMS_ConstB.Divide[0] * rtb_Square_h[0] + FMS_ConstB.Divide[1] *
            rtb_Square_h[1];

          /* Trigonometry: '<S373>/Acos' incorporates:
           *  DotProduct: '<S373>/Dot Product'
           */
          if (d > 1.0F) {
            d = 1.0F;
          } else {
            if (d < -1.0F) {
              d = -1.0F;
            }
          }

          /* Product: '<S373>/Multiply' incorporates:
           *  Trigonometry: '<S373>/Acos'
           */
          rtb_Switch_fz_idx_1 *= acosf(d);

          /* Math: '<S376>/Rem' incorporates:
           *  Constant: '<S376>/Constant1'
           *  Delay: '<S372>/Delay'
           *  Sum: '<S372>/Sum2'
           */
          rtb_Subtract3_d = rt_remf(rtb_Switch_fz_idx_1 - FMS_DW.Delay_DSTATE_n,
            6.28318548F);

          /* Switch: '<S376>/Switch' incorporates:
           *  Abs: '<S376>/Abs'
           *  Constant: '<S376>/Constant'
           *  Constant: '<S382>/Constant'
           *  Product: '<S376>/Multiply'
           *  RelationalOperator: '<S382>/Compare'
           *  Sum: '<S376>/Add'
           */
          if (fabsf(rtb_Subtract3_d) > 3.14159274F) {
            /* Signum: '<S376>/Sign' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = rtb_Subtract3_d;
            }

            /* End of Signum: '<S376>/Sign' */
            rtb_Subtract3_d -= 6.28318548F * rtb_Divide_l_idx_2;
          }

          /* End of Switch: '<S376>/Switch' */

          /* Sum: '<S372>/Sum' incorporates:
           *  Delay: '<S372>/Delay'
           */
          rtb_Divide_l_idx_2 = rtb_Subtract3_d + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S381>/Multiply1' incorporates:
           *  Constant: '<S381>/const1'
           *  DiscreteIntegrator: '<S375>/Integrator'
           */
          rtb_Subtract3_d = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S381>/Add' incorporates:
           *  DiscreteIntegrator: '<S375>/Integrator1'
           *  Sum: '<S375>/Subtract'
           */
          rtb_Divide_l_idx_3 = (FMS_DW.Integrator1_DSTATE_mf -
                                rtb_Divide_l_idx_2) + rtb_Subtract3_d;

          /* Signum: '<S381>/Sign' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else if (rtb_Divide_l_idx_3 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          } else {
            rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3;
          }

          /* End of Signum: '<S381>/Sign' */

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
          d = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_3) + FMS_ConstB.d_m) *
                     FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Divide_l_idx_2 + rtb_Subtract3_d;

          /* Sum: '<S381>/Add4' */
          rtb_u_mm = (rtb_Divide_l_idx_3 - d) + rtb_Subtract3_d;

          /* Sum: '<S381>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Divide_l_idx_3 + FMS_ConstB.d_m;

          /* Sum: '<S381>/Subtract1' */
          rtb_Divide_l_idx_3 -= FMS_ConstB.d_m;

          /* Signum: '<S381>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign1' */

          /* Signum: '<S381>/Sign2' */
          if (rtb_Divide_l_idx_3 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_3 > 0.0F) {
              rtb_Divide_l_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign2' */

          /* Sum: '<S381>/Add5' incorporates:
           *  Gain: '<S381>/Gain2'
           *  Product: '<S381>/Multiply4'
           *  Sum: '<S381>/Subtract2'
           */
          d += (rtb_Divide_l_idx_2 - rtb_Divide_l_idx_3) * 0.5F * rtb_u_mm;

          /* Sum: '<S381>/Add6' */
          rtb_Divide_l_idx_2 = d + FMS_ConstB.d_m;

          /* Sum: '<S381>/Subtract3' */
          rtb_u_mm = d - FMS_ConstB.d_m;

          /* Product: '<S381>/Divide' */
          rtb_Switch_fz_idx_2 = d / FMS_ConstB.d_m;

          /* Signum: '<S381>/Sign5' incorporates:
           *  Signum: '<S381>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S381>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S381>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = d;

            /* Signum: '<S381>/Sign6' */
            rtb_Divide_l_idx_3 = d;
          }

          /* End of Signum: '<S381>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S372>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Switch_fz_idx_1 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S377>/Rem' incorporates:
           *  Constant: '<S377>/Constant1'
           */
          d = rt_remf(rtb_Switch_fz_idx_1, 6.28318548F);

          /* Switch: '<S377>/Switch' incorporates:
           *  Abs: '<S377>/Abs'
           *  Constant: '<S377>/Constant'
           *  Constant: '<S383>/Constant'
           *  Product: '<S377>/Multiply'
           *  RelationalOperator: '<S383>/Compare'
           *  Sum: '<S377>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S377>/Sign' */
            if (d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = d;
            }

            /* End of Signum: '<S377>/Sign' */
            d -= 6.28318548F * rtb_Switch_fz_idx_1;
          }

          /* End of Switch: '<S377>/Switch' */

          /* Abs: '<S370>/Abs' */
          d = fabsf(d);

          /* Update for Delay: '<S394>/Delay' */
          FMS_DW.icLoad = 0U;

          /* Update for DiscreteIntegrator: '<S395>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S388>/Constant'
           *  RelationalOperator: '<S388>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S395>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S390>/Acceleration_Speed' incorporates:
           *  Constant: '<S390>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S390>/Acceleration_Speed' */

          /* Product: '<S394>/Divide1' incorporates:
           *  Constant: '<S394>/Constant'
           */
          d = rtb_Switch_fz_idx_0 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S394>/Saturation' */
          if (d > 0.314159274F) {
            d = 0.314159274F;
          } else {
            if (d < -0.314159274F) {
              d = -0.314159274F;
            }
          }

          /* End of Saturate: '<S394>/Saturation' */

          /* Update for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * d;

          /* Update for Delay: '<S372>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S375>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S375>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S381>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign3' */

          /* Signum: '<S381>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign4' */

          /* Update for DiscreteIntegrator: '<S375>/Integrator' incorporates:
           *  Constant: '<S381>/const'
           *  Gain: '<S381>/Gain3'
           *  Product: '<S381>/Multiply5'
           *  Product: '<S381>/Multiply6'
           *  Sum: '<S381>/Subtract4'
           *  Sum: '<S381>/Subtract5'
           *  Sum: '<S381>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S375>/Integrator' */
          /* End of Outputs for SubSystem: '<S364>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S367>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S367>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S252>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S252>/Unknown' incorporates:
           *  ActionPort: '<S366>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S252>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
         *  ActionPort: '<S251>/Action Port'
         */
        /* SwitchCase: '<S251>/Switch Case' */
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
            /* Disable for SwitchCase: '<S351>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S266>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S284>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S300>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S325>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S312>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S251>/Acro' incorporates:
           *  ActionPort: '<S256>/Action Port'
           */
          /* BusAssignment: '<S256>/Bus Assignment' incorporates:
           *  Constant: '<S256>/Constant'
           *  Gain: '<S261>/Gain'
           *  Gain: '<S261>/Gain1'
           *  Gain: '<S261>/Gain2'
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

          /* Saturate: '<S262>/Saturation' incorporates:
           *  Constant: '<S262>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  Sum: '<S262>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            d = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S262>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S256>/Bus Assignment' incorporates:
           *  Constant: '<S262>/Constant5'
           *  Gain: '<S262>/Gain2'
           *  Sum: '<S262>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            d), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S251>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S251>/Stabilize' incorporates:
             *  ActionPort: '<S259>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S251>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S347>/Integrator'
             *  DiscreteIntegrator: '<S347>/Integrator1'
             *  DiscreteIntegrator: '<S348>/Integrator'
             *  DiscreteIntegrator: '<S348>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S251>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S251>/Stabilize' incorporates:
             *  ActionPort: '<S259>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S251>/Switch Case' incorporates:
             *  Chart: '<S352>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S251>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S251>/Stabilize' incorporates:
           *  ActionPort: '<S259>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S342>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S352>/Motion State' incorporates:
           *  Abs: '<S352>/Abs'
           *  Abs: '<S352>/Abs1'
           *  Constant: '<S362>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S362>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S351>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S351>/Hold Control' incorporates:
               *  ActionPort: '<S354>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S351>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S351>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S351>/Hold Control' incorporates:
             *  ActionPort: '<S354>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S351>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S351>/Brake Control' incorporates:
             *  ActionPort: '<S353>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S351>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S351>/Move Control' incorporates:
               *  ActionPort: '<S355>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S351>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S351>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S351>/Move Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S351>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S351>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S344>/Switch' incorporates:
           *  Constant: '<S344>/Constant'
           *  Constant: '<S344>/Constant4'
           *  Constant: '<S344>/Constant5'
           *  Gain: '<S344>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S344>/Saturation'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S344>/Add'
           *  Sum: '<S344>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_DataTypeConversion_o = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S344>/Saturation' */
              d = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S344>/Saturation' */
              d = 0.0F;
            } else {
              /* Saturate: '<S344>/Saturation' incorporates:
               *  Constant: '<S344>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S40>/Signal Copy2'
               *  Sum: '<S344>/Sum'
               */
              d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_DataTypeConversion_o = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              d), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S344>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S259>/Bus Assignment' incorporates:
           *  Constant: '<S259>/Constant'
           *  DataTypeConversion: '<S342>/Data Type Conversion'
           *  DiscreteIntegrator: '<S347>/Integrator1'
           *  DiscreteIntegrator: '<S348>/Integrator1'
           *  Product: '<S342>/Multiply'
           *  Product: '<S342>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S351>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S259>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S351>/Saturation' */

          /* BusAssignment: '<S259>/Bus Assignment' */
          FMS_Y.FMS_Out.throttle_cmd = rtb_DataTypeConversion_o;

          /* Product: '<S350>/Multiply1' incorporates:
           *  Constant: '<S350>/const1'
           *  DiscreteIntegrator: '<S348>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S346>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S346>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S350>/Add' incorporates:
           *  DiscreteIntegrator: '<S348>/Integrator1'
           *  Gain: '<S342>/Gain1'
           *  Gain: '<S346>/Gain'
           *  Sum: '<S348>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * d * -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S350>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S350>/Sign' */

          /* Sum: '<S350>/Add2' incorporates:
           *  Abs: '<S350>/Abs'
           *  Gain: '<S350>/Gain'
           *  Gain: '<S350>/Gain1'
           *  Product: '<S350>/Multiply2'
           *  Product: '<S350>/Multiply3'
           *  Sqrt: '<S350>/Sqrt'
           *  Sum: '<S350>/Add1'
           *  Sum: '<S350>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S350>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1) +
            rtb_Sign5_mn;

          /* Sum: '<S350>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_0 + FMS_ConstB.d_g;

          /* Sum: '<S350>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_g;

          /* Signum: '<S350>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S350>/Sign1' */

          /* Signum: '<S350>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S350>/Sign2' */

          /* Sum: '<S350>/Add5' incorporates:
           *  Gain: '<S350>/Gain2'
           *  Product: '<S350>/Multiply4'
           *  Sum: '<S350>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_0) *
            0.5F * rtb_Divide_l_idx_3;

          /* Sum: '<S350>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 + FMS_ConstB.d_g;

          /* Sum: '<S350>/Subtract3' */
          rtb_u_mm = rtb_Switch_fz_idx_1 - FMS_ConstB.d_g;

          /* Product: '<S350>/Divide' */
          rtb_Switch_fz_idx_2 = rtb_Switch_fz_idx_1 / FMS_ConstB.d_g;

          /* Signum: '<S350>/Sign5' incorporates:
           *  Signum: '<S350>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S350>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S350>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Switch_fz_idx_1;

            /* Signum: '<S350>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S350>/Sign5' */

          /* Product: '<S349>/Multiply1' incorporates:
           *  Constant: '<S349>/const1'
           *  DiscreteIntegrator: '<S347>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S345>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S345>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S349>/Add' incorporates:
           *  DiscreteIntegrator: '<S347>/Integrator1'
           *  Gain: '<S342>/Gain'
           *  Gain: '<S345>/Gain'
           *  Sum: '<S347>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S349>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S349>/Sign' */

          /* Sum: '<S349>/Add2' incorporates:
           *  Abs: '<S349>/Abs'
           *  Gain: '<S349>/Gain'
           *  Gain: '<S349>/Gain1'
           *  Product: '<S349>/Multiply2'
           *  Product: '<S349>/Multiply3'
           *  Sqrt: '<S349>/Sqrt'
           *  Sum: '<S349>/Add1'
           *  Sum: '<S349>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S349>/Add4' */
          rtb_Sign5_mn += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1;

          /* Sum: '<S349>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_a;

          /* Sum: '<S349>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_a;

          /* Signum: '<S349>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S349>/Sign1' */

          /* Signum: '<S349>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S349>/Sign2' */

          /* Sum: '<S349>/Add5' incorporates:
           *  Gain: '<S349>/Gain2'
           *  Product: '<S349>/Multiply4'
           *  Sum: '<S349>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (d - rtb_Switch_fz_idx_0) * 0.5F * rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S347>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S347>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S348>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S348>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S350>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S350>/Sign3' */

          /* Signum: '<S350>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S350>/Sign4' */

          /* Update for DiscreteIntegrator: '<S348>/Integrator' incorporates:
           *  Constant: '<S350>/const'
           *  Gain: '<S350>/Gain3'
           *  Product: '<S350>/Multiply5'
           *  Product: '<S350>/Multiply6'
           *  Sum: '<S350>/Subtract4'
           *  Sum: '<S350>/Subtract5'
           *  Sum: '<S350>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_o * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 12.566371F) * 0.004F;

          /* Sum: '<S349>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 - FMS_ConstB.d_a;

          /* Sum: '<S349>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_1 + FMS_ConstB.d_a;

          /* Signum: '<S349>/Sign5' incorporates:
           *  Signum: '<S349>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S349>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S349>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;

            /* Signum: '<S349>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S349>/Sign5' */

          /* Signum: '<S349>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S349>/Sign3' */

          /* Signum: '<S349>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S349>/Sign4' */

          /* Update for DiscreteIntegrator: '<S347>/Integrator' incorporates:
           *  Constant: '<S349>/const'
           *  Gain: '<S349>/Gain3'
           *  Product: '<S349>/Divide'
           *  Product: '<S349>/Multiply5'
           *  Product: '<S349>/Multiply6'
           *  Sum: '<S349>/Subtract4'
           *  Sum: '<S349>/Subtract5'
           *  Sum: '<S349>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_a -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_k * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S251>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S251>/Altitude' incorporates:
             *  ActionPort: '<S257>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S251>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S280>/Integrator'
             *  DiscreteIntegrator: '<S280>/Integrator1'
             *  DiscreteIntegrator: '<S281>/Integrator'
             *  DiscreteIntegrator: '<S281>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S251>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S251>/Altitude' incorporates:
             *  ActionPort: '<S257>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S251>/Switch Case' incorporates:
             *  Chart: '<S267>/Motion Status'
             *  Chart: '<S285>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S251>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S251>/Altitude' incorporates:
           *  ActionPort: '<S257>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S267>/Motion Status' incorporates:
           *  Abs: '<S267>/Abs'
           *  Abs: '<S267>/Abs1'
           *  Constant: '<S276>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S276>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S266>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S266>/Hold Control' incorporates:
               *  ActionPort: '<S269>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S266>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S266>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S266>/Hold Control' incorporates:
             *  ActionPort: '<S269>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S266>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S266>/Brake Control' incorporates:
             *  ActionPort: '<S268>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S266>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S266>/Move Control' incorporates:
             *  ActionPort: '<S270>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S266>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S266>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S263>/Switch' incorporates:
           *  Constant: '<S263>/Constant'
           *  Saturate: '<S266>/Saturation1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Divide_l_idx_2 = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S266>/Saturation1' */
            rtb_Divide_l_idx_2 = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S266>/Saturation1' */
            rtb_Divide_l_idx_2 = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S266>/Saturation1' */
            rtb_Divide_l_idx_2 = FMS_B.Merge_l;
          }

          /* End of Switch: '<S263>/Switch' */

          /* Logic: '<S264>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S285>/Motion State' incorporates:
           *  Abs: '<S285>/Abs'
           *  Abs: '<S285>/Abs1'
           *  Constant: '<S295>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S295>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S284>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S284>/Hold Control' incorporates:
               *  ActionPort: '<S287>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S284>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S284>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S284>/Hold Control' incorporates:
             *  ActionPort: '<S287>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S284>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S284>/Brake Control' incorporates:
             *  ActionPort: '<S286>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S284>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S284>/Move Control' incorporates:
               *  ActionPort: '<S288>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S284>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S284>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S284>/Move Control' incorporates:
             *  ActionPort: '<S288>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S284>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S284>/Switch Case' */

          /* BusAssignment: '<S257>/Bus Assignment' incorporates:
           *  Constant: '<S257>/Constant'
           *  DataTypeConversion: '<S264>/Data Type Conversion'
           *  DiscreteIntegrator: '<S280>/Integrator1'
           *  DiscreteIntegrator: '<S281>/Integrator1'
           *  Product: '<S264>/Multiply'
           *  Product: '<S264>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S284>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S257>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S257>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S257>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S284>/Saturation' */

          /* BusAssignment: '<S257>/Bus Assignment' */
          FMS_Y.FMS_Out.w_cmd = rtb_Divide_l_idx_2;

          /* Product: '<S283>/Multiply1' incorporates:
           *  Constant: '<S283>/const1'
           *  DiscreteIntegrator: '<S281>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S279>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S279>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S283>/Add' incorporates:
           *  DiscreteIntegrator: '<S281>/Integrator1'
           *  Gain: '<S264>/Gain1'
           *  Gain: '<S279>/Gain'
           *  Sum: '<S281>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * d * -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S283>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S283>/Sign' */

          /* Sum: '<S283>/Add2' incorporates:
           *  Abs: '<S283>/Abs'
           *  Gain: '<S283>/Gain'
           *  Gain: '<S283>/Gain1'
           *  Product: '<S283>/Multiply2'
           *  Product: '<S283>/Multiply3'
           *  Sqrt: '<S283>/Sqrt'
           *  Sum: '<S283>/Add1'
           *  Sum: '<S283>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S283>/Add4' */
          rtb_Divide_l_idx_3 = (rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1) +
            rtb_Sign5_mn;

          /* Sum: '<S283>/Add3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_0 + FMS_ConstB.d_o;

          /* Sum: '<S283>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_o;

          /* Signum: '<S283>/Sign1' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S283>/Sign1' */

          /* Signum: '<S283>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S283>/Sign2' */

          /* Sum: '<S283>/Add5' incorporates:
           *  Gain: '<S283>/Gain2'
           *  Product: '<S283>/Multiply4'
           *  Sum: '<S283>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (rtb_Divide_l_idx_2 - rtb_Switch_fz_idx_0) *
            0.5F * rtb_Divide_l_idx_3;

          /* Sum: '<S283>/Add6' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 + FMS_ConstB.d_o;

          /* Sum: '<S283>/Subtract3' */
          rtb_u_mm = rtb_Switch_fz_idx_1 - FMS_ConstB.d_o;

          /* Product: '<S283>/Divide' */
          rtb_Switch_fz_idx_2 = rtb_Switch_fz_idx_1 / FMS_ConstB.d_o;

          /* Signum: '<S283>/Sign5' incorporates:
           *  Signum: '<S283>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S283>/Sign6' */
            rtb_Divide_l_idx_3 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S283>/Sign6' */
            rtb_Divide_l_idx_3 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Switch_fz_idx_1;

            /* Signum: '<S283>/Sign6' */
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S283>/Sign5' */

          /* Product: '<S282>/Multiply1' incorporates:
           *  Constant: '<S282>/const1'
           *  DiscreteIntegrator: '<S280>/Integrator'
           */
          rtb_Sign5_mn = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S278>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            d = 0.0F;
          } else {
            d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S278>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S282>/Add' incorporates:
           *  DiscreteIntegrator: '<S280>/Integrator1'
           *  Gain: '<S264>/Gain'
           *  Gain: '<S278>/Gain'
           *  Sum: '<S280>/Subtract'
           */
          rtb_Switch_fz_idx_0 = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * d * FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign5_mn;

          /* Signum: '<S282>/Sign' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            d = -1.0F;
          } else if (rtb_Switch_fz_idx_0 > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_Switch_fz_idx_0;
          }

          /* End of Signum: '<S282>/Sign' */

          /* Sum: '<S282>/Add2' incorporates:
           *  Abs: '<S282>/Abs'
           *  Gain: '<S282>/Gain'
           *  Gain: '<S282>/Gain1'
           *  Product: '<S282>/Multiply2'
           *  Product: '<S282>/Multiply3'
           *  Sqrt: '<S282>/Sqrt'
           *  Sum: '<S282>/Add1'
           *  Sum: '<S282>/Subtract'
           */
          rtb_Switch_fz_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch_fz_idx_0) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * d +
            rtb_Sign5_mn;

          /* Sum: '<S282>/Add4' */
          rtb_Sign5_mn += rtb_Switch_fz_idx_0 - rtb_Switch_fz_idx_1;

          /* Sum: '<S282>/Add3' */
          d = rtb_Switch_fz_idx_0 + FMS_ConstB.d_c;

          /* Sum: '<S282>/Subtract1' */
          rtb_Switch_fz_idx_0 -= FMS_ConstB.d_c;

          /* Signum: '<S282>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S282>/Sign1' */

          /* Signum: '<S282>/Sign2' */
          if (rtb_Switch_fz_idx_0 < 0.0F) {
            rtb_Switch_fz_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_fz_idx_0 > 0.0F) {
              rtb_Switch_fz_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S282>/Sign2' */

          /* Sum: '<S282>/Add5' incorporates:
           *  Gain: '<S282>/Gain2'
           *  Product: '<S282>/Multiply4'
           *  Sum: '<S282>/Subtract2'
           */
          rtb_Switch_fz_idx_1 += (d - rtb_Switch_fz_idx_0) * 0.5F * rtb_Sign5_mn;

          /* Update for DiscreteIntegrator: '<S280>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S280>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S281>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S281>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S283>/Sign3' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S283>/Sign3' */

          /* Signum: '<S283>/Sign4' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S283>/Sign4' */

          /* Update for DiscreteIntegrator: '<S281>/Integrator' incorporates:
           *  Constant: '<S283>/const'
           *  Gain: '<S283>/Gain3'
           *  Product: '<S283>/Multiply5'
           *  Product: '<S283>/Multiply6'
           *  Sum: '<S283>/Subtract4'
           *  Sum: '<S283>/Subtract5'
           *  Sum: '<S283>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_fz_idx_2 - rtb_Divide_or) *
            FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_2 - rtb_u_mm) * 0.5F) -
            rtb_Divide_l_idx_3 * 12.566371F) * 0.004F;

          /* Sum: '<S282>/Subtract3' */
          rtb_Divide_l_idx_2 = rtb_Switch_fz_idx_1 - FMS_ConstB.d_c;

          /* Sum: '<S282>/Add6' */
          rtb_u_mm = rtb_Switch_fz_idx_1 + FMS_ConstB.d_c;

          /* Signum: '<S282>/Sign5' incorporates:
           *  Signum: '<S282>/Sign6'
           */
          if (rtb_Switch_fz_idx_1 < 0.0F) {
            rtb_Divide_l_idx_3 = -1.0F;

            /* Signum: '<S282>/Sign6' */
            rtb_Switch_fz_idx_0 = -1.0F;
          } else if (rtb_Switch_fz_idx_1 > 0.0F) {
            rtb_Divide_l_idx_3 = 1.0F;

            /* Signum: '<S282>/Sign6' */
            rtb_Switch_fz_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_3 = rtb_Switch_fz_idx_1;

            /* Signum: '<S282>/Sign6' */
            rtb_Switch_fz_idx_0 = rtb_Switch_fz_idx_1;
          }

          /* End of Signum: '<S282>/Sign5' */

          /* Signum: '<S282>/Sign3' */
          if (rtb_u_mm < 0.0F) {
            rtb_u_mm = -1.0F;
          } else {
            if (rtb_u_mm > 0.0F) {
              rtb_u_mm = 1.0F;
            }
          }

          /* End of Signum: '<S282>/Sign3' */

          /* Signum: '<S282>/Sign4' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S282>/Sign4' */

          /* Update for DiscreteIntegrator: '<S280>/Integrator' incorporates:
           *  Constant: '<S282>/const'
           *  Gain: '<S282>/Gain3'
           *  Product: '<S282>/Divide'
           *  Product: '<S282>/Multiply5'
           *  Product: '<S282>/Multiply6'
           *  Sum: '<S282>/Subtract4'
           *  Sum: '<S282>/Subtract5'
           *  Sum: '<S282>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Switch_fz_idx_1 / FMS_ConstB.d_c -
            rtb_Divide_l_idx_3) * FMS_ConstB.Gain4_h * ((rtb_u_mm -
            rtb_Divide_l_idx_2) * 0.5F) - rtb_Switch_fz_idx_0 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S251>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S251>/Position' incorporates:
             *  ActionPort: '<S258>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S251>/Switch Case' incorporates:
             *  Chart: '<S301>/Motion Status'
             *  Chart: '<S313>/Motion State'
             *  Chart: '<S326>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S251>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S251>/Position' incorporates:
           *  ActionPort: '<S258>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S301>/Motion Status' incorporates:
           *  Abs: '<S301>/Abs'
           *  Abs: '<S301>/Abs1'
           *  Constant: '<S310>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S310>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S300>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S300>/Hold Control' incorporates:
               *  ActionPort: '<S303>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S300>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S300>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S300>/Hold Control' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S300>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S300>/Brake Control' incorporates:
             *  ActionPort: '<S302>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S300>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S300>/Move Control' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S300>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S300>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S313>/Motion State' incorporates:
           *  Abs: '<S313>/Abs'
           *  Abs: '<S313>/Abs1'
           *  Constant: '<S323>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S323>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S326>/Logical Operator' incorporates:
           *  Abs: '<S326>/Abs1'
           *  Abs: '<S326>/Abs2'
           *  Constant: '<S339>/Constant'
           *  Constant: '<S340>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S339>/Compare'
           *  RelationalOperator: '<S340>/Compare'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S326>/Motion State' */
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

          /* End of Chart: '<S326>/Motion State' */

          /* SwitchCase: '<S325>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S325>/Hold Control' incorporates:
               *  ActionPort: '<S328>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S325>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_jz);

              /* End of SystemReset for SubSystem: '<S325>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S325>/Hold Control' incorporates:
             *  ActionPort: '<S328>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge,
                              &FMS_ConstB.HoldControl_jz, &FMS_DW.HoldControl_jz);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S325>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S325>/Brake Control' incorporates:
             *  ActionPort: '<S327>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge);

            /* End of Outputs for SubSystem: '<S325>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S325>/Move Control' incorporates:
               *  ActionPort: '<S329>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S325>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S335>/Integrator'
               *  DiscreteIntegrator: '<S335>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S325>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S325>/Move Control' incorporates:
             *  ActionPort: '<S329>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S333>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              d = 0.0F;
            } else {
              d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S333>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S333>/Gain' */
            rtb_u_mm = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * d;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S334>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              d = 0.0F;
            } else {
              d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S334>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S334>/Gain' */
            rtb_Switch_fz_idx_0 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * d;

            /* Sum: '<S336>/Sum of Elements' incorporates:
             *  Math: '<S336>/Square'
             *  SignalConversion: '<S336>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S337>/Sum of Elements'
             *  Switch: '<S329>/Switch'
             */
            d = rtb_u_mm * rtb_u_mm + rtb_Switch_fz_idx_0 * rtb_Switch_fz_idx_0;

            /* Switch: '<S329>/Switch' incorporates:
             *  Product: '<S337>/Divide'
             *  Sqrt: '<S336>/Sqrt'
             *  Sum: '<S336>/Sum of Elements'
             */
            if (sqrtf(d) > 1.0F) {
              /* Math: '<S337>/Math Function1'
               *
               * About '<S337>/Math Function1':
               *  Operator: sqrt
               */
              if (d < 0.0F) {
                rtb_Divide_l_idx_2 = -sqrtf(fabsf(d));
              } else {
                rtb_Divide_l_idx_2 = sqrtf(d);
              }

              /* End of Math: '<S337>/Math Function1' */

              /* Switch: '<S337>/Switch' incorporates:
               *  Constant: '<S337>/Constant'
               *  Product: '<S337>/Product'
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

              /* End of Switch: '<S337>/Switch' */
              rtb_u_mm = rtb_Switch_d0[0] / rtb_Switch_d0[2];
              rtb_Switch_fz_idx_0 = rtb_Switch_d0[1] / rtb_Switch_d0[2];
            }

            /* Product: '<S338>/Multiply1' incorporates:
             *  Constant: '<S338>/const1'
             *  DiscreteIntegrator: '<S335>/Integrator'
             */
            rtb_Switch_fz_idx_1 = FMS_DW.Integrator_DSTATE[0] * 0.05F;

            /* Sum: '<S338>/Add' incorporates:
             *  DiscreteIntegrator: '<S335>/Integrator1'
             *  Gain: '<S329>/Gain6'
             *  Sum: '<S335>/Subtract'
             */
            D = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM * rtb_u_mm)
              + rtb_Switch_fz_idx_1;

            /* Signum: '<S338>/Sign' */
            if (D < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (D > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = D;
            }

            /* Sum: '<S338>/Add2' incorporates:
             *  Abs: '<S338>/Abs'
             *  Gain: '<S338>/Gain'
             *  Gain: '<S338>/Gain1'
             *  Product: '<S338>/Multiply2'
             *  Product: '<S338>/Multiply3'
             *  Sqrt: '<S338>/Sqrt'
             *  Sum: '<S338>/Add1'
             *  Sum: '<S338>/Subtract'
             */
            rtb_Subtract3_d = (sqrtf((8.0F * fabsf(D) + FMS_ConstB.d) *
              FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Divide_l_idx_2 +
              rtb_Switch_fz_idx_1;

            /* Sum: '<S338>/Add4' */
            rtb_Switch_fz_idx_1 += D - rtb_Subtract3_d;

            /* Sum: '<S338>/Add3' */
            rtb_Divide_l_idx_2 = D + FMS_ConstB.d;

            /* Sum: '<S338>/Subtract1' */
            D -= FMS_ConstB.d;

            /* Signum: '<S338>/Sign1' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S338>/Sign2' */
            if (D < 0.0F) {
              D = -1.0F;
            } else {
              if (D > 0.0F) {
                D = 1.0F;
              }
            }

            /* Sum: '<S338>/Add5' incorporates:
             *  Gain: '<S338>/Gain2'
             *  Product: '<S338>/Multiply4'
             *  Sum: '<S338>/Subtract2'
             */
            rtb_Subtract3_d += (rtb_Divide_l_idx_2 - D) * 0.5F *
              rtb_Switch_fz_idx_1;

            /* SignalConversion: '<S335>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S335>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S335>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S335>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S338>/Sign4' incorporates:
             *  Sum: '<S338>/Subtract3'
             */
            rtb_Divide_l_idx_2 = rtb_Subtract3_d - FMS_ConstB.d;

            /* Signum: '<S338>/Sign3' incorporates:
             *  Sum: '<S338>/Add6'
             */
            rtb_u_mm = rtb_Subtract3_d + FMS_ConstB.d;

            /* Signum: '<S338>/Sign5' */
            if (rtb_Subtract3_d < 0.0F) {
              d = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_Subtract3_d;
            }

            /* Signum: '<S338>/Sign3' */
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = -1.0F;
            } else {
              if (rtb_u_mm > 0.0F) {
                rtb_u_mm = 1.0F;
              }
            }

            /* Signum: '<S338>/Sign4' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S338>/Sign6' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = rtb_Subtract3_d;
            }

            /* Update for DiscreteIntegrator: '<S335>/Integrator' incorporates:
             *  Constant: '<S338>/const'
             *  Gain: '<S338>/Gain3'
             *  Product: '<S338>/Divide'
             *  Product: '<S338>/Multiply5'
             *  Product: '<S338>/Multiply6'
             *  Sum: '<S338>/Subtract4'
             *  Sum: '<S338>/Subtract5'
             *  Sum: '<S338>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Subtract3_d / FMS_ConstB.d - d)
              * FMS_ConstB.Gain4 * ((rtb_u_mm - rtb_Divide_l_idx_2) * 0.5F) -
              rtb_Switch_fz_idx_1 * 58.836F) * 0.004F;

            /* Product: '<S338>/Multiply1' incorporates:
             *  Constant: '<S338>/const1'
             *  DiscreteIntegrator: '<S335>/Integrator'
             */
            rtb_Switch_fz_idx_1 = FMS_DW.Integrator_DSTATE[1] * 0.05F;

            /* Sum: '<S338>/Add' incorporates:
             *  DiscreteIntegrator: '<S335>/Integrator1'
             *  Gain: '<S329>/Gain6'
             *  Sum: '<S335>/Subtract'
             */
            D = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                 rtb_Switch_fz_idx_0) + rtb_Switch_fz_idx_1;

            /* Signum: '<S338>/Sign' */
            if (D < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else if (D > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            } else {
              rtb_Divide_l_idx_2 = D;
            }

            /* Sum: '<S338>/Add2' incorporates:
             *  Abs: '<S338>/Abs'
             *  Gain: '<S338>/Gain'
             *  Gain: '<S338>/Gain1'
             *  Product: '<S338>/Multiply2'
             *  Product: '<S338>/Multiply3'
             *  Sqrt: '<S338>/Sqrt'
             *  Sum: '<S338>/Add1'
             *  Sum: '<S338>/Subtract'
             */
            rtb_Subtract3_d = (sqrtf((8.0F * fabsf(D) + FMS_ConstB.d) *
              FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Divide_l_idx_2 +
              rtb_Switch_fz_idx_1;

            /* Sum: '<S338>/Add4' */
            rtb_Switch_fz_idx_1 += D - rtb_Subtract3_d;

            /* Sum: '<S338>/Add3' */
            rtb_Divide_l_idx_2 = D + FMS_ConstB.d;

            /* Sum: '<S338>/Subtract1' */
            D -= FMS_ConstB.d;

            /* Signum: '<S338>/Sign1' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S338>/Sign2' */
            if (D < 0.0F) {
              D = -1.0F;
            } else {
              if (D > 0.0F) {
                D = 1.0F;
              }
            }

            /* Sum: '<S338>/Add5' incorporates:
             *  Gain: '<S338>/Gain2'
             *  Product: '<S338>/Multiply4'
             *  Sum: '<S338>/Subtract2'
             */
            rtb_Subtract3_d += (rtb_Divide_l_idx_2 - D) * 0.5F *
              rtb_Switch_fz_idx_1;

            /* SignalConversion: '<S335>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S335>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S335>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S335>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S338>/Sign4' incorporates:
             *  Sum: '<S338>/Subtract3'
             */
            rtb_Divide_l_idx_2 = rtb_Subtract3_d - FMS_ConstB.d;

            /* Signum: '<S338>/Sign3' incorporates:
             *  Sum: '<S338>/Add6'
             */
            rtb_u_mm = rtb_Subtract3_d + FMS_ConstB.d;

            /* Signum: '<S338>/Sign5' */
            if (rtb_Subtract3_d < 0.0F) {
              d = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_Subtract3_d;
            }

            /* Signum: '<S338>/Sign3' */
            if (rtb_u_mm < 0.0F) {
              rtb_u_mm = -1.0F;
            } else {
              if (rtb_u_mm > 0.0F) {
                rtb_u_mm = 1.0F;
              }
            }

            /* Signum: '<S338>/Sign4' */
            if (rtb_Divide_l_idx_2 < 0.0F) {
              rtb_Divide_l_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_l_idx_2 > 0.0F) {
                rtb_Divide_l_idx_2 = 1.0F;
              }
            }

            /* Signum: '<S338>/Sign6' */
            if (rtb_Subtract3_d < 0.0F) {
              rtb_Switch_fz_idx_1 = -1.0F;
            } else if (rtb_Subtract3_d > 0.0F) {
              rtb_Switch_fz_idx_1 = 1.0F;
            } else {
              rtb_Switch_fz_idx_1 = rtb_Subtract3_d;
            }

            /* Update for DiscreteIntegrator: '<S335>/Integrator' incorporates:
             *  Constant: '<S338>/const'
             *  Gain: '<S338>/Gain3'
             *  Product: '<S338>/Divide'
             *  Product: '<S338>/Multiply5'
             *  Product: '<S338>/Multiply6'
             *  Sum: '<S338>/Subtract4'
             *  Sum: '<S338>/Subtract5'
             *  Sum: '<S338>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Subtract3_d / FMS_ConstB.d - d)
              * FMS_ConstB.Gain4 * ((rtb_u_mm - rtb_Divide_l_idx_2) * 0.5F) -
              rtb_Switch_fz_idx_1 * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S325>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S325>/Switch Case' */

          /* SwitchCase: '<S312>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S312>/Hold Control' incorporates:
               *  ActionPort: '<S315>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S312>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S312>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S312>/Hold Control' incorporates:
             *  ActionPort: '<S315>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S312>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S312>/Brake Control' incorporates:
             *  ActionPort: '<S314>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S312>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S312>/Move Control' incorporates:
               *  ActionPort: '<S316>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S312>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S312>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S312>/Move Control' incorporates:
             *  ActionPort: '<S316>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S312>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S312>/Switch Case' */

          /* BusAssignment: '<S258>/Bus Assignment' incorporates:
           *  Constant: '<S258>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S312>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S312>/Saturation' */

          /* Saturate: '<S325>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S325>/Saturation1' */

          /* Saturate: '<S300>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S258>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S300>/Saturation1' */
          /* End of Outputs for SubSystem: '<S251>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S251>/Unknown' incorporates:
           *  ActionPort: '<S260>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S251>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S47>/Manual' incorporates:
         *  ActionPort: '<S253>/Action Port'
         */
        /* BusAssignment: '<S253>/Bus Assignment' incorporates:
         *  Constant: '<S253>/Constant'
         *  Constant: '<S253>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S47>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S47>/Unknown' incorporates:
         *  ActionPort: '<S255>/Action Port'
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
   *  DiscreteIntegrator: '<S684>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S684>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S684>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_fu ==
    FMS_Cmd_SetHome);

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
  d = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)d;
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
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Divide_l_idx_1 -
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
  d = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)d;
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
  /* Start for SwitchCase: '<S39>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S39>/Arm' */
  /* Start for SwitchCase: '<S41>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S41>/FW_Mode' */
  /* Start for SwitchCase: '<S46>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;

  /* Start for IfAction SubSystem: '<S46>/SubMode' */
  /* Start for SwitchCase: '<S61>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S46>/SubMode' */

  /* Start for IfAction SubSystem: '<S46>/Auto' */
  /* Start for SwitchCase: '<S59>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S46>/Auto' */

  /* Start for IfAction SubSystem: '<S46>/Assist' */
  /* Start for SwitchCase: '<S58>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_as = -1;

  /* Start for IfAction SubSystem: '<S58>/Altitude' */
  /* Start for SwitchCase: '<S71>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;

  /* End of Start for SubSystem: '<S58>/Altitude' */

  /* Start for IfAction SubSystem: '<S58>/Position' */
  /* Start for SwitchCase: '<S106>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S92>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S58>/Position' */
  /* End of Start for SubSystem: '<S46>/Assist' */
  /* End of Start for SubSystem: '<S41>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S41>/MC_Mode' */
  /* Start for SwitchCase: '<S47>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S47>/SubMode' */
  /* Start for SwitchCase: '<S254>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S254>/Return' */
  /* Start for SwitchCase: '<S642>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S632>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S254>/Return' */

  /* Start for IfAction SubSystem: '<S254>/Hold' */
  /* Start for SwitchCase: '<S581>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S559>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S569>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;

  /* End of Start for SubSystem: '<S254>/Hold' */
  /* End of Start for SubSystem: '<S47>/SubMode' */

  /* Start for IfAction SubSystem: '<S47>/Auto' */
  /* Start for SwitchCase: '<S252>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S252>/Mission' */
  /* Start for Resettable SubSystem: '<S364>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S412>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* Start for SwitchCase: '<S402>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S364>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S252>/Mission' */
  /* End of Start for SubSystem: '<S47>/Auto' */

  /* Start for IfAction SubSystem: '<S47>/Assist' */
  /* Start for SwitchCase: '<S251>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S251>/Stabilize' */
  /* Start for SwitchCase: '<S351>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S251>/Stabilize' */

  /* Start for IfAction SubSystem: '<S251>/Altitude' */
  /* Start for SwitchCase: '<S266>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S284>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S251>/Altitude' */

  /* Start for IfAction SubSystem: '<S251>/Position' */
  /* Start for SwitchCase: '<S300>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S325>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S312>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S251>/Position' */
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
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S39>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S41>/FW_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S46>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S61>/Hold' */
  /* InitializeConditions for Delay: '<S194>/start_vel' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S189>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S61>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S46>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S59>/Mission' */
  /* InitializeConditions for UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S59>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S46>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S58>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S148>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S148>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S58>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S58>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S83>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S86>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S86>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* SystemInitialize for Chart: '<S72>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S71>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S71>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S71>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S71>/Move Control' */

  /* SystemInitialize for Merge: '<S71>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S58>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S58>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S93>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S107>/Motion State' */
  FMS_DW.temporalCounter_i1_ie = 0U;
  FMS_DW.is_active_c26_FMS = 0U;
  FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S106>/Hold Control' */
  /* InitializeConditions for Delay: '<S114>/start_vel' */
  FMS_DW.icLoad_g = 1U;

  /* InitializeConditions for Delay: '<S114>/start_wp' */
  FMS_DW.icLoad_e = 1U;

  /* End of SystemInitialize for SubSystem: '<S106>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S106>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  FMS_DW.Integrator_DSTATE_f1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S106>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S92>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S92>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S92>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S92>/Move Control' */

  /* SystemInitialize for Merge: '<S92>/Merge' */
  FMS_B.Merge_f = 0.0F;

  /* SystemInitialize for Merge: '<S106>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S58>/Position' */
  /* End of SystemInitialize for SubSystem: '<S46>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S41>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S41>/BackwardTrans_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
    }
  }

  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' */
  FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of SystemInitialize for SubSystem: '<S41>/BackwardTrans_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S41>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S47>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S254>/Takeoff' */
  /* InitializeConditions for Delay: '<S682>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S678>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S678>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S254>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S254>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S597>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S597>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S254>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S254>/Return' */
  /* InitializeConditions for Delay: '<S627>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S628>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S623>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S669>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S606>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;

  /* InitializeConditions for Delay: '<S605>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S609>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S643>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S642>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S642>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S642>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S642>/Move Control' */

  /* SystemInitialize for Merge: '<S642>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S633>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S632>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S632>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S632>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S632>/Move Control' */

  /* SystemInitialize for Merge: '<S632>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S254>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S254>/Hold' */
  /* SystemInitialize for Chart: '<S560>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S570>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S582>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S581>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S581>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S581>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S581>/Move Control' */

  /* SystemInitialize for Merge: '<S581>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S559>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S559>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S559>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S559>/Move Control' */

  /* SystemInitialize for Merge: '<S559>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S569>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S569>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S569>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S569>/Move Control' */

  /* SystemInitialize for Merge: '<S569>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S254>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S47>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S252>/Mission' */
  /* InitializeConditions for UnitDelay: '<S367>/Delay Input1'
   *
   * Block description for '<S367>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S364>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S394>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_kd = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S390>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S372>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S413>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S412>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_fy);

  /* End of SystemInitialize for SubSystem: '<S412>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S412>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S412>/Move Control' */

  /* SystemInitialize for Merge: '<S412>/Merge' */
  FMS_B.Merge_ls[0] = 0.0F;
  FMS_B.Merge_ls[1] = 0.0F;

  /* SystemInitialize for Chart: '<S403>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for IfAction SubSystem: '<S402>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bf);

  /* End of SystemInitialize for SubSystem: '<S402>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S402>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c0);

  /* End of SystemInitialize for SubSystem: '<S402>/Move Control' */

  /* SystemInitialize for Merge: '<S402>/Merge' */
  FMS_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S364>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S252>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S47>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S251>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S347>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S348>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S348>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S347>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S352>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S351>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S351>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S351>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S351>/Move Control' */

  /* SystemInitialize for Merge: '<S351>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S251>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S251>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S280>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S281>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S281>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S280>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S267>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S266>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S266>/Hold Control' */

  /* SystemInitialize for Merge: '<S266>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S285>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S284>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S284>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S284>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S284>/Move Control' */

  /* SystemInitialize for Merge: '<S284>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S251>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S251>/Position' */
  /* SystemInitialize for Chart: '<S301>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S300>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S300>/Hold Control' */

  /* SystemInitialize for Chart: '<S313>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S326>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S325>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_jz);

  /* End of SystemInitialize for SubSystem: '<S325>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S325>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S335>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S335>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S325>/Move Control' */

  /* SystemInitialize for Merge: '<S325>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S325>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S335>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S335>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S325>/Move Control' */

  /* SystemInitialize for Merge: '<S325>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S300>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S312>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S312>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S312>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S312>/Move Control' */

  /* SystemInitialize for Merge: '<S312>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S251>/Position' */
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
