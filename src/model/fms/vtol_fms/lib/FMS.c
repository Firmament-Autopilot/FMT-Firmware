/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2556
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 22 10:24:41 2025
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

/* Named constants for Chart: '<S176>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<S730>/Motion Status' */
#define FMS_IN_Brake_bq                ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S740>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_ol                 ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S436>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S658>/Motion State' */
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
                                        *   '<S40>/Constant'
                                        *   '<S782>/Constant1'
                                        *   '<S783>/Constant'
                                        *   '<S785>/Constant1'
                                        *   '<S786>/FW_ACCEPT_R'
                                        *   '<S786>/MC_ACCEPT_R'
                                        *   '<S789>/Constant'
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
                                        *   '<S265>/Dead Zone'
                                        *   '<S265>/Gain'
                                        *   '<S266>/Dead Zone'
                                        *   '<S266>/Gain'
                                        *   '<S267>/Dead Zone'
                                        *   '<S267>/Gain'
                                        *   '<S268>/Dead Zone'
                                        *   '<S268>/Gain'
                                        *   '<S271>/Constant4'
                                        *   '<S272>/Constant4'
                                        *   '<S640>/L1'
                                        *   '<S57>/L1'
                                        *   '<S58>/Gain6'
                                        *   '<S96>/Constant'
                                        *   '<S97>/Constant'
                                        *   '<S135>/Gain'
                                        *   '<S136>/Gain1'
                                        *   '<S137>/Gain'
                                        *   '<S158>/Gain1'
                                        *   '<S225>/Gain'
                                        *   '<S225>/Gain1'
                                        *   '<S226>/Gain1'
                                        *   '<S274>/Gain2'
                                        *   '<S274>/Saturation1'
                                        *   '<S275>/L1'
                                        *   '<S275>/R'
                                        *   '<S275>/Saturation1'
                                        *   '<S292>/Gain'
                                        *   '<S292>/Saturation1'
                                        *   '<S314>/Gain'
                                        *   '<S314>/Saturation1'
                                        *   '<S349>/Gain'
                                        *   '<S349>/Gain1'
                                        *   '<S426>/Gain'
                                        *   '<S426>/Gain1'
                                        *   '<S428>/Constant'
                                        *   '<S452>/L1'
                                        *   '<S533>/Saturation'
                                        *   '<S534>/Saturation1'
                                        *   '<S534>/Saturation2'
                                        *   '<S534>/Saturation3'
                                        *   '<S691>/Land_Speed'
                                        *   '<S692>/Saturation1'
                                        *   '<S771>/Takeoff_Speed'
                                        *   '<S772>/Gain2'
                                        *   '<S772>/Saturation1'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        *   '<S138>/Saturation1'
                                        *   '<S149>/Dead Zone'
                                        *   '<S149>/Gain'
                                        *   '<S152>/Dead Zone'
                                        *   '<S152>/Gain'
                                        *   '<S161>/Saturation1'
                                        *   '<S172>/Dead Zone'
                                        *   '<S172>/Gain'
                                        *   '<S175>/Saturation1'
                                        *   '<S222>/Constant'
                                        *   '<S222>/Constant1'
                                        *   '<S222>/Constant2'
                                        *   '<S228>/Dead Zone'
                                        *   '<S228>/Gain'
                                        *   '<S229>/Dead Zone'
                                        *   '<S229>/Gain'
                                        *   '<S234>/Dead Zone'
                                        *   '<S234>/Gain'
                                        *   '<S242>/Gain'
                                        *   '<S242>/Saturation1'
                                        *   '<S243>/Constant4'
                                        *   '<S297>/L1'
                                        *   '<S297>/Saturation1'
                                        *   '<S319>/L1'
                                        *   '<S319>/Saturation1'
                                        *   '<S351>/Saturation1'
                                        *   '<S363>/Dead Zone'
                                        *   '<S363>/Gain'
                                        *   '<S364>/Dead Zone'
                                        *   '<S364>/Gain'
                                        *   '<S369>/Saturation'
                                        *   '<S385>/Saturation1'
                                        *   '<S397>/Saturation'
                                        *   '<S410>/Saturation1'
                                        *   '<S429>/Dead Zone'
                                        *   '<S429>/Gain'
                                        *   '<S430>/Dead Zone'
                                        *   '<S430>/Gain'
                                        *   '<S435>/Saturation'
                                        *   '<S589>/Gain2'
                                        *   '<S596>/Gain1'
                                        *   '<S596>/Gain2'
                                        *   '<S646>/Saturation1'
                                        *   '<S657>/Saturation'
                                        *   '<S678>/Saturation1'
                                        *   '<S693>/Constant'
                                        *   '<S696>/Gain2'
                                        *   '<S720>/Constant'
                                        *   '<S720>/vel'
                                        *   '<S720>/Acceleration_Speed'
                                        *   '<S720>/Saturation'
                                        *   '<S720>/Switch'
                                        *   '<S724>/Constant'
                                        *   '<S141>/Gain2'
                                        *   '<S142>/Gain1'
                                        *   '<S147>/Constant'
                                        *   '<S164>/Gain2'
                                        *   '<S165>/Gain1'
                                        *   '<S170>/Constant'
                                        *   '<S178>/L1'
                                        *   '<S179>/Gain6'
                                        *   '<S217>/Constant'
                                        *   '<S218>/Constant'
                                        *   '<S248>/L1'
                                        *   '<S248>/Saturation1'
                                        *   '<S354>/Gain2'
                                        *   '<S355>/Gain1'
                                        *   '<S361>/Constant'
                                        *   '<S372>/Gain2'
                                        *   '<S373>/Gain1'
                                        *   '<S380>/Constant'
                                        *   '<S388>/Gain2'
                                        *   '<S389>/Gain1'
                                        *   '<S395>/Constant'
                                        *   '<S400>/Gain2'
                                        *   '<S401>/Gain1'
                                        *   '<S408>/Constant'
                                        *   '<S412>/Gain2'
                                        *   '<S413>/Gain6'
                                        *   '<S423>/Constant'
                                        *   '<S424>/Constant'
                                        *   '<S438>/Gain2'
                                        *   '<S439>/Gain1'
                                        *   '<S446>/Constant'
                                        *   '<S471>/Gain'
                                        *   '<S471>/Saturation1'
                                        *   '<S474>/Constant'
                                        *   '<S474>/vel'
                                        *   '<S474>/Switch'
                                        *   '<S649>/Gain2'
                                        *   '<S650>/Gain1'
                                        *   '<S661>/Gain2'
                                        *   '<S662>/Gain1'
                                        *   '<S670>/Gain2'
                                        *   '<S670>/Saturation'
                                        *   '<S671>/Integrator'
                                        *   '<S681>/Gain2'
                                        *   '<S682>/Gain6'
                                        *   '<S705>/Gain2'
                                        *   '<S705>/Saturation'
                                        *   '<S706>/Integrator'
                                        *   '<S144>/Dead Zone'
                                        *   '<S144>/Gain'
                                        *   '<S167>/Dead Zone'
                                        *   '<S167>/Gain'
                                        *   '<S214>/Dead Zone'
                                        *   '<S214>/Gain'
                                        *   '<S357>/Land_Speed'
                                        *   '<S358>/Constant'
                                        *   '<S360>/Dead Zone'
                                        *   '<S360>/Gain'
                                        *   '<S377>/Dead Zone'
                                        *   '<S377>/Gain'
                                        *   '<S391>/Land_Speed'
                                        *   '<S392>/Constant'
                                        *   '<S394>/Dead Zone'
                                        *   '<S394>/Gain'
                                        *   '<S405>/Dead Zone'
                                        *   '<S405>/Gain'
                                        *   '<S417>/Dead Zone'
                                        *   '<S417>/Gain'
                                        *   '<S418>/Dead Zone'
                                        *   '<S418>/Gain'
                                        *   '<S443>/Dead Zone'
                                        *   '<S443>/Gain'
                                        *   '<S458>/Gain2'
                                        *   '<S458>/Saturation'
                                        *   '<S459>/Integrator'
                                        *   '<S652>/Dead Zone'
                                        *   '<S652>/Gain'
                                        *   '<S666>/Dead Zone'
                                        *   '<S666>/Gain'
                                        *   '<S686>/Dead Zone'
                                        *   '<S686>/Gain'
                                        *   '<S687>/Dead Zone'
                                        *   '<S687>/Gain'
                                        *   '<S729>/Saturation1'
                                        *   '<S739>/Saturation1'
                                        *   '<S489>/Saturation1'
                                        *   '<S499>/Saturation1'
                                        *   '<S732>/Gain2'
                                        *   '<S733>/Gain1'
                                        *   '<S742>/Gain2'
                                        *   '<S743>/Gain6'
                                        *   '<S492>/Gain2'
                                        *   '<S493>/Gain1'
                                        *   '<S502>/Gain2'
                                        *   '<S503>/Gain6'
                                        *   '<S735>/Dead Zone'
                                        *   '<S735>/Gain'
                                        *   '<S747>/Dead Zone'
                                        *   '<S747>/Gain'
                                        *   '<S748>/Dead Zone'
                                        *   '<S748>/Gain'
                                        *   '<S495>/Dead Zone'
                                        *   '<S495>/Gain'
                                        *   '<S507>/Dead Zone'
                                        *   '<S507>/Gain'
                                        *   '<S508>/Dead Zone'
                                        *   '<S508>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S26>/Constant1'
                                        *   '<S781>/Constant'
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
 *    '<S321>/NearbyRefWP'
 *    '<S299>/NearbyRefWP'
 *    '<S250>/NearbyRefWP'
 *    '<S722>/NearbyRefWP'
 *    '<S476>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S325>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S321>/SearchL1RefWP'
 *    '<S299>/SearchL1RefWP'
 *    '<S250>/SearchL1RefWP'
 *    '<S722>/SearchL1RefWP'
 *    '<S476>/SearchL1RefWP'
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

  /* SignalConversion: '<S327>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S299>/OutRegionRegWP'
 *    '<S250>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S304>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S339>/Unknown'
 *    '<S337>/Unknown'
 *    '<S336>/Unknown'
 *    '<S50>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S273>/Bus Assignment' incorporates:
   *  Constant: '<S273>/Constant'
   *  Constant: '<S273>/Constant2'
   *  SignalConversion: '<S273>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S273>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S138>/Hold Control'
 *    '<S161>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S141>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S138>/Hold Control'
 *    '<S161>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S141>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S138>/Hold Control'
 *    '<S161>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S141>/Delay' incorporates:
   *  Gain: '<S143>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S141>/Gain2' incorporates:
   *  Delay: '<S141>/Delay'
   *  Gain: '<S143>/Gain'
   *  Sum: '<S141>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S141>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S138>/Brake Control'
 *    '<S161>/Brake Control'
 *    '<S729>/Brake Control'
 *    '<S646>/Brake Control'
 *    '<S657>/Brake Control'
 *    '<S489>/Brake Control'
 *    '<S435>/Brake Control'
 *    '<S351>/Brake Control'
 *    '<S369>/Brake Control'
 *    '<S385>/Brake Control'
 *    '<S397>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S140>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S140>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S138>/Move Control'
 *    '<S161>/Move Control'
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
 *    '<S161>/Move Control'
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
 *    '<S161>/Move Control'
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

  /* Product: '<S146>/Multiply1' incorporates:
   *  Constant: '<S146>/const1'
   *  DiscreteIntegrator: '<S145>/Integrator'
   */
  rtb_Add3_ci = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S144>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_bz = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_bz = 0.0F;
  } else {
    rtb_a_bz = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S144>/Dead Zone' */

  /* Sum: '<S146>/Add' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator1'
   *  Gain: '<S142>/Gain1'
   *  Gain: '<S144>/Gain'
   *  Sum: '<S145>/Subtract'
   */
  rtb_Subtract3_df = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_bz * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_ci;

  /* Signum: '<S146>/Sign' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_a_bz = -1.0F;
  } else if (rtb_Subtract3_df > 0.0F) {
    rtb_a_bz = 1.0F;
  } else {
    rtb_a_bz = rtb_Subtract3_df;
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
  rtb_a_bz = (sqrtf((8.0F * fabsf(rtb_Subtract3_df) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_bz + rtb_Add3_ci;

  /* Sum: '<S146>/Add4' */
  rtb_Add4_lp = (rtb_Subtract3_df - rtb_a_bz) + rtb_Add3_ci;

  /* Sum: '<S146>/Add3' */
  rtb_Add3_ci = rtb_Subtract3_df + localC->d;

  /* Sum: '<S146>/Subtract1' */
  rtb_Subtract3_df -= localC->d;

  /* Signum: '<S146>/Sign1' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign1' */

  /* Signum: '<S146>/Sign2' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_Subtract3_df = -1.0F;
  } else {
    if (rtb_Subtract3_df > 0.0F) {
      rtb_Subtract3_df = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign2' */

  /* Sum: '<S146>/Add5' incorporates:
   *  Gain: '<S146>/Gain2'
   *  Product: '<S146>/Multiply4'
   *  Sum: '<S146>/Subtract2'
   */
  rtb_a_bz += (rtb_Add3_ci - rtb_Subtract3_df) * 0.5F * rtb_Add4_lp;

  /* SignalConversion: '<S142>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S145>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S146>/Add6' */
  rtb_Add3_ci = rtb_a_bz + localC->d;

  /* Sum: '<S146>/Subtract3' */
  rtb_Subtract3_df = rtb_a_bz - localC->d;

  /* Signum: '<S146>/Sign5' */
  if (rtb_a_bz < 0.0F) {
    rtb_Add4_lp = -1.0F;
  } else if (rtb_a_bz > 0.0F) {
    rtb_Add4_lp = 1.0F;
  } else {
    rtb_Add4_lp = rtb_a_bz;
  }

  /* End of Signum: '<S146>/Sign5' */

  /* Signum: '<S146>/Sign3' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign3' */

  /* Signum: '<S146>/Sign4' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_Subtract3_df = -1.0F;
  } else {
    if (rtb_Subtract3_df > 0.0F) {
      rtb_Subtract3_df = 1.0F;
    }
  }

  /* End of Signum: '<S146>/Sign4' */

  /* Signum: '<S146>/Sign6' */
  if (rtb_a_bz < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_bz > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_bz;
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
  localDW->Integrator_DSTATE += ((rtb_a_bz / localC->d - rtb_Add4_lp) *
    localC->Gain4 * ((rtb_Add3_ci - rtb_Subtract3_df) * 0.5F) - rtb_a_f *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S139>/Motion Status'
 *    '<S162>/Motion Status'
 *    '<S352>/Motion Status'
 *    '<S386>/Motion Status'
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
 *    '<S162>/Motion Status'
 *    '<S352>/Motion Status'
 *    '<S386>/Motion Status'
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
 *    '<S162>/Motion Status'
 *    '<S352>/Motion Status'
 *    '<S386>/Motion Status'
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
 *    '<S175>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_l_Init(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S183>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S183>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S211>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System reset for action system:
 *    '<S175>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_g_Reset(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S183>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S183>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S211>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S175>/Hold Control'
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

  /* Sqrt: '<S190>/Sqrt' incorporates:
   *  Math: '<S190>/Square'
   *  Sum: '<S190>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_ex = sqrtf(((rtu_FMS_In[0] * rtu_FMS_In[0] +
    rtu_FMS_In[1] * rtu_FMS_In[1]) + rtu_FMS_In[2] * rtu_FMS_In[2]) +
    rtu_FMS_In[3] * rtu_FMS_In[3]);

  /* Product: '<S186>/Divide' */
  rtb_Square_kg_idx_0 = rtu_FMS_In[0] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_1 = rtu_FMS_In[1] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_2 = rtu_FMS_In[2] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_DiscreteTimeIntegrator1_ex = rtu_FMS_In[3] /
    rtb_DiscreteTimeIntegrator1_ex;

  /* Math: '<S187>/Square' incorporates:
   *  Math: '<S188>/Square'
   *  Math: '<S189>/Square'
   */
  rtb_Sign_hw = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_0;

  /* Math: '<S187>/Square2' incorporates:
   *  Math: '<S188>/Square2'
   *  Math: '<S189>/Square2'
   */
  rtb_Switch_fz_idx_1 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2;

  /* Math: '<S187>/Square1' incorporates:
   *  Math: '<S188>/Square1'
   *  Math: '<S189>/Square1'
   */
  D = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1;

  /* Math: '<S187>/Square3' incorporates:
   *  Math: '<S188>/Square3'
   *  Math: '<S189>/Square3'
   */
  absxk = rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex;

  /* Sum: '<S187>/Subtract' incorporates:
   *  Math: '<S187>/Square'
   *  Math: '<S187>/Square1'
   *  Math: '<S187>/Square2'
   *  Math: '<S187>/Square3'
   *  Sum: '<S187>/Add'
   *  Sum: '<S187>/Add1'
   */
  rtb_VectorConcatenate_l[0] = (rtb_Sign_hw + D) - (rtb_Switch_fz_idx_1 + absxk);

  /* Product: '<S187>/Multiply' incorporates:
   *  Product: '<S188>/Multiply'
   */
  b_t = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_2;

  /* Product: '<S187>/Multiply1' incorporates:
   *  Product: '<S188>/Multiply1'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_DiscreteTimeIntegrator1_ex;

  /* Gain: '<S187>/Gain' incorporates:
   *  Product: '<S187>/Multiply'
   *  Product: '<S187>/Multiply1'
   *  Sum: '<S187>/Subtract1'
   */
  rtb_VectorConcatenate_l[1] = (b_t - d1) * 2.0F;

  /* Product: '<S187>/Multiply2' incorporates:
   *  Product: '<S189>/Multiply'
   */
  rtb_VectorConcatenate_fy_tmp = rtb_Square_kg_idx_1 *
    rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S187>/Multiply3' incorporates:
   *  Product: '<S189>/Multiply1'
   */
  rtb_VectorConcatenate_fy_tmp_0 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_2;

  /* Gain: '<S187>/Gain1' incorporates:
   *  Product: '<S187>/Multiply2'
   *  Product: '<S187>/Multiply3'
   *  Sum: '<S187>/Add2'
   */
  rtb_VectorConcatenate_l[2] = (rtb_VectorConcatenate_fy_tmp +
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S188>/Gain' incorporates:
   *  Sum: '<S188>/Add3'
   */
  rtb_VectorConcatenate_l[3] = (b_t + d1) * 2.0F;

  /* Sum: '<S188>/Subtract' incorporates:
   *  Sum: '<S188>/Add'
   *  Sum: '<S188>/Add1'
   */
  rtb_VectorConcatenate_l[4] = (rtb_Sign_hw + rtb_Switch_fz_idx_1) - (D + absxk);

  /* Product: '<S188>/Multiply2' incorporates:
   *  Product: '<S189>/Multiply2'
   */
  b_t = rtb_Square_kg_idx_2 * rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S188>/Multiply3' incorporates:
   *  Product: '<S189>/Multiply3'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_1;

  /* Gain: '<S188>/Gain1' incorporates:
   *  Product: '<S188>/Multiply2'
   *  Product: '<S188>/Multiply3'
   *  Sum: '<S188>/Subtract1'
   */
  rtb_VectorConcatenate_l[5] = (b_t - d1) * 2.0F;

  /* Gain: '<S189>/Gain' incorporates:
   *  Sum: '<S189>/Subtract2'
   */
  rtb_VectorConcatenate_l[6] = (rtb_VectorConcatenate_fy_tmp -
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S189>/Gain1' incorporates:
   *  Sum: '<S189>/Add2'
   */
  rtb_VectorConcatenate_l[7] = (b_t + d1) * 2.0F;

  /* Sum: '<S189>/Subtract' incorporates:
   *  Sum: '<S189>/Add'
   *  Sum: '<S189>/Add1'
   */
  rtb_VectorConcatenate_l[8] = (rtb_Sign_hw + absxk) - (D + rtb_Switch_fz_idx_1);

  /* Product: '<S180>/Multiply' incorporates:
   *  SignalConversion: '<S180>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_ppg[i] = rtb_VectorConcatenate_l[i + 6] * rtu_FMS_In_g +
      (rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h + rtb_VectorConcatenate_l[i]
       * rtu_FMS_In_c);
  }

  /* End of Product: '<S180>/Multiply' */

  /* Trigonometry: '<S209>/Trigonometric Function1' incorporates:
   *  Gain: '<S208>/Gain'
   *  Trigonometry: '<S209>/Trigonometric Function3'
   */
  rtb_Sign_hw = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[0] = rtb_Sign_hw;

  /* Trigonometry: '<S209>/Trigonometric Function' incorporates:
   *  Gain: '<S208>/Gain'
   *  Trigonometry: '<S209>/Trigonometric Function2'
   */
  rtb_Switch_fz_idx_1 = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[1] = rtb_Switch_fz_idx_1;

  /* SignalConversion: '<S209>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S209>/Constant3'
   */
  rtb_VectorConcatenate_l[2] = 0.0F;

  /* Gain: '<S209>/Gain' */
  rtb_VectorConcatenate_l[3] = -rtb_Switch_fz_idx_1;

  /* Trigonometry: '<S209>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_Sign_hw;

  /* SignalConversion: '<S209>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S209>/Constant4'
   */
  rtb_VectorConcatenate_l[5] = 0.0F;

  /* SignalConversion: '<S209>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_l[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_l[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_l[8] = localC->VectorConcatenate3[2];

  /* Delay: '<S183>/start_vel' incorporates:
   *  SignalConversion: '<S196>/TmpSignal ConversionAtSquareInport1'
   */
  if (localDW->icLoad != 0) {
    localDW->start_vel_DSTATE[0] = rtu_FMS_In_c;
    localDW->start_vel_DSTATE[1] = rtu_FMS_In_h;
  }

  /* Sum: '<S204>/Sum of Elements' incorporates:
   *  Delay: '<S183>/start_vel'
   *  Math: '<S204>/Math Function'
   */
  rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[0] * localDW->
    start_vel_DSTATE[0] + localDW->start_vel_DSTATE[1] *
    localDW->start_vel_DSTATE[1];

  /* Math: '<S204>/Math Function1' incorporates:
   *  Sum: '<S204>/Sum of Elements'
   *
   * About '<S204>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_fz_idx_1 < 0.0F) {
    rtb_Sign_hw = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
  } else {
    rtb_Sign_hw = sqrtf(rtb_Switch_fz_idx_1);
  }

  /* End of Math: '<S204>/Math Function1' */

  /* Switch: '<S204>/Switch' incorporates:
   *  Constant: '<S204>/Constant'
   *  Delay: '<S183>/start_vel'
   *  Product: '<S204>/Product'
   */
  if (rtb_Sign_hw > 0.0F) {
    rtb_Square_kg_idx_2 = localDW->start_vel_DSTATE[0];
    rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[1];
  } else {
    rtb_Square_kg_idx_2 = 0.0F;
    rtb_Switch_fz_idx_1 = 0.0F;
    rtb_Sign_hw = 1.0F;
  }

  /* End of Switch: '<S204>/Switch' */

  /* Delay: '<S183>/start_wp' incorporates:
   *  SignalConversion: '<S183>/TmpSignal ConversionAtstart_wpInport2'
   */
  if (localDW->icLoad_e != 0) {
    localDW->start_wp_DSTATE[0] = rtu_FMS_In_l;
    localDW->start_wp_DSTATE[1] = rtu_FMS_In_m;
  }

  /* MATLAB Function: '<S181>/SearchL1RefWP' incorporates:
   *  Delay: '<S183>/start_wp'
   *  SignalConversion: '<S193>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_Square_kg_idx_0 = localDW->start_wp_DSTATE[0] - rtu_FMS_In_l;
  rtb_Square_kg_idx_1 = localDW->start_wp_DSTATE[1] - rtu_FMS_In_m;

  /* Product: '<S204>/Divide' */
  rtb_Square_kg_idx_2 /= rtb_Sign_hw;

  /* MATLAB Function: '<S181>/SearchL1RefWP' */
  D = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_0;

  /* Product: '<S204>/Divide' */
  rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_2;
  rtb_Square_kg_idx_2 = rtb_Switch_fz_idx_1 / rtb_Sign_hw;

  /* MATLAB Function: '<S181>/SearchL1RefWP' incorporates:
   *  Constant: '<S178>/L1'
   *  Delay: '<S183>/start_wp'
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

  /* MATLAB Function: '<S181>/OutRegionRefWP' incorporates:
   *  Delay: '<S183>/start_wp'
   *  SignalConversion: '<S183>/TmpSignal ConversionAtstart_wpInport2'
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

  /* Product: '<S207>/Multiply' incorporates:
   *  SignalConversion: '<S207>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_fy[i] = rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h
      + rtb_VectorConcatenate_l[i] * rtu_FMS_In_c;
  }

  /* End of Product: '<S207>/Multiply' */

  /* DiscreteIntegrator: '<S211>/Discrete-Time Integrator' */
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

  /* DiscreteIntegrator: '<S213>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S205>/Constant'
   *  Sum: '<S205>/Sum'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  if (localDW->DiscreteTimeIntegrator1_PrevRes != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  /* Signum: '<S180>/Sign' */
  if (rtb_Multiply_ppg[0] < 0.0F) {
    rtb_Switch_fz_idx_1 = -1.0F;
  } else if (rtb_Multiply_ppg[0] > 0.0F) {
    rtb_Switch_fz_idx_1 = 1.0F;
  } else {
    rtb_Switch_fz_idx_1 = rtb_Multiply_ppg[0];
  }

  /* End of Signum: '<S180>/Sign' */

  /* Switch: '<S178>/Switch' incorporates:
   *  Constant: '<S178>/L1'
   *  Constant: '<S194>/Constant'
   *  Constant: '<S205>/Constant'
   *  Constant: '<S212>/kp'
   *  DiscreteIntegrator: '<S211>/Discrete-Time Integrator'
   *  Gain: '<S194>/Gain'
   *  Math: '<S194>/Square'
   *  Math: '<S197>/Square'
   *  Math: '<S199>/Math Function'
   *  MinMax: '<S194>/Max'
   *  MinMax: '<S194>/Min'
   *  Product: '<S194>/Divide'
   *  Product: '<S194>/Multiply1'
   *  Product: '<S212>/Multiply'
   *  Sqrt: '<S197>/Sqrt'
   *  Sum: '<S182>/Subtract'
   *  Sum: '<S197>/Sum of Elements'
   *  Sum: '<S205>/Sum'
   *  Sum: '<S206>/Add'
   */
  if (rtb_Switch_fz_idx_1 > 0.0F) {
    /* Sum: '<S198>/Sum of Elements' incorporates:
     *  Math: '<S198>/Math Function'
     *  SignalConversion: '<S196>/TmpSignal ConversionAtSquareInport1'
     *  Sum: '<S196>/Sum of Elements'
     */
    rtb_Switch_fz_idx_1 = rtu_FMS_In_c * rtu_FMS_In_c + rtu_FMS_In_h *
      rtu_FMS_In_h;

    /* Math: '<S198>/Math Function1' incorporates:
     *  Sum: '<S198>/Sum of Elements'
     *
     * About '<S198>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Switch_fz_idx_1 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
    } else {
      d1 = sqrtf(rtb_Switch_fz_idx_1);
    }

    /* End of Math: '<S198>/Math Function1' */

    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S198>/Constant'
     *  Product: '<S198>/Product'
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

    /* End of Switch: '<S198>/Switch' */

    /* Product: '<S198>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* RelationalOperator: '<S191>/Compare' incorporates:
     *  Constant: '<S191>/Constant'
     *  MATLAB Function: '<S181>/SearchL1RefWP'
     */
    rtb_Compare_dd1 = (rtb_Sign_hw > 0.0F);

    /* Switch: '<S181>/Switch' incorporates:
     *  Delay: '<S183>/start_wp'
     *  MATLAB Function: '<S181>/OutRegionRefWP'
     */
    if (!rtb_Compare_dd1) {
      rtb_Square_kg_idx_0 = b_t * rtb_DiscreteTimeIntegrator1_ex +
        localDW->start_wp_DSTATE[0];
      rtb_Square_kg_idx_1 = b_t * rtb_Square_kg_idx_2 + localDW->
        start_wp_DSTATE[1];
    }

    /* End of Switch: '<S181>/Switch' */

    /* Sum: '<S182>/Subtract' incorporates:
     *  SignalConversion: '<S183>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_0 - rtu_FMS_In_l;
    rtb_Square_kg_idx_0 = rtb_DiscreteTimeIntegrator1_ex;
    rtb_Sign_hw = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex;

    /* Sum: '<S182>/Subtract' incorporates:
     *  Math: '<S199>/Math Function'
     *  SignalConversion: '<S183>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_1 - rtu_FMS_In_m;

    /* Sum: '<S199>/Sum of Elements' incorporates:
     *  Math: '<S199>/Math Function'
     */
    rtb_Square_kg_idx_2 = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex + rtb_Sign_hw;

    /* Math: '<S199>/Math Function1' incorporates:
     *  Sum: '<S199>/Sum of Elements'
     *
     * About '<S199>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S199>/Math Function1' */

    /* Switch: '<S199>/Switch' incorporates:
     *  Constant: '<S199>/Constant'
     *  Product: '<S199>/Product'
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

    /* End of Switch: '<S199>/Switch' */

    /* Product: '<S199>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_0 *= rtb_Square_kg_idx_0;

    /* Product: '<S199>/Divide' incorporates:
     *  Math: '<S197>/Square'
     */
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S201>/Sum of Elements' incorporates:
     *  Math: '<S201>/Math Function'
     *  SignalConversion: '<S201>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = absxk * absxk + D * D;

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
      rtb_Multiply_ppg[0] = absxk;
      rtb_Multiply_ppg[1] = D;
      rtb_Multiply_ppg[2] = d1;
    } else {
      rtb_Multiply_ppg[0] = 0.0F;
      rtb_Multiply_ppg[1] = 0.0F;
      rtb_Multiply_ppg[2] = 1.0F;
    }

    /* End of Switch: '<S201>/Switch' */

    /* Product: '<S201>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S202>/Sum of Elements' incorporates:
     *  Math: '<S202>/Math Function'
     *  SignalConversion: '<S202>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1 +
      rtb_Sign_hw * rtb_Sign_hw;

    /* Math: '<S202>/Math Function1' incorporates:
     *  Sum: '<S202>/Sum of Elements'
     *
     * About '<S202>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S202>/Math Function1' */

    /* Switch: '<S202>/Switch' incorporates:
     *  Constant: '<S202>/Constant'
     *  Product: '<S202>/Product'
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

    /* End of Switch: '<S202>/Switch' */

    /* Product: '<S202>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S200>/Subtract' incorporates:
     *  Product: '<S200>/Multiply'
     *  Product: '<S200>/Multiply1'
     */
    rtb_Square_kg_idx_2 = rtb_Sign_hw * absxk - rtb_Square_kg_idx_1 * D;

    /* Signum: '<S195>/Sign1' */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      rtb_Square_kg_idx_2 = -1.0F;
    } else {
      if (rtb_Square_kg_idx_2 > 0.0F) {
        rtb_Square_kg_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S195>/Sign1' */

    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S195>/Constant4'
     */
    if (rtb_Square_kg_idx_2 == 0.0F) {
      rtb_Square_kg_idx_2 = 1.0F;
    }

    /* End of Switch: '<S195>/Switch2' */

    /* DotProduct: '<S195>/Dot Product' */
    rtb_Square_kg_idx_1 = D * rtb_Sign_hw + absxk * rtb_Square_kg_idx_1;

    /* Trigonometry: '<S195>/Acos' incorporates:
     *  DotProduct: '<S195>/Dot Product'
     */
    if (rtb_Square_kg_idx_1 > 1.0F) {
      rtb_Square_kg_idx_1 = 1.0F;
    } else {
      if (rtb_Square_kg_idx_1 < -1.0F) {
        rtb_Square_kg_idx_1 = -1.0F;
      }
    }

    /* Product: '<S195>/Multiply' incorporates:
     *  Trigonometry: '<S195>/Acos'
     */
    rtb_Square_kg_idx_2 *= acosf(rtb_Square_kg_idx_1);

    /* Saturate: '<S194>/Saturation' */
    if (rtb_Square_kg_idx_2 > 1.57079637F) {
      rtb_Square_kg_idx_2 = 1.57079637F;
    } else {
      if (rtb_Square_kg_idx_2 < -1.57079637F) {
        rtb_Square_kg_idx_2 = -1.57079637F;
      }
    }

    /* End of Saturate: '<S194>/Saturation' */

    /* Trigonometry: '<S194>/Sin' */
    rtb_Square_kg_idx_1 = arm_sin_f32(rtb_Square_kg_idx_2);

    /* Sqrt: '<S196>/Sqrt' */
    rtb_Square_kg_idx_2 = sqrtf(rtb_Switch_fz_idx_1);
    *rty_ay_cmd_mPs2 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2 * 2.0F *
      rtb_Square_kg_idx_1 / fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf
      (rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex +
       rtb_Square_kg_idx_0), 0.5F));
  } else {
    *rty_ay_cmd_mPs2 = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
      localDW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Update for Delay: '<S183>/start_vel' */
  localDW->icLoad = 0U;

  /* Update for Delay: '<S183>/start_wp' */
  localDW->icLoad_e = 0U;

  /* Update for DiscreteIntegrator: '<S211>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S205>/Constant'
   *  Constant: '<S211>/ki'
   *  Product: '<S211>/Multiply'
   *  Sum: '<S205>/Sum'
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

  /* End of Update for DiscreteIntegrator: '<S211>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S205>/Constant'
   *  Gain: '<S213>/Gain'
   *  Sum: '<S205>/Sum'
   *  Sum: '<S213>/Sum5'
   */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE += ((0.0F - rtb_VectorConcatenate_fy[1])
    - localDW->DiscreteTimeIntegrator1_DSTATE) * 62.831852F * 0.004F;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S175>/Brake Control'
 *    '<S54>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T *rty_ay_cmd_mPs2)
{
  /* SignalConversion: '<S177>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
   *  Constant: '<S177>/Brake Speed'
   */
  *rty_ay_cmd_mPs2 = 0.0F;
}

/*
 * System initialize for atomic system:
 *    '<S176>/Motion State'
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
 *    '<S176>/Motion State'
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
 *    '<S176>/Motion State'
 *    '<S55>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S176>/Motion State' */
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

  /* End of Chart: '<S176>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S729>/Hold Control'
 *    '<S646>/Hold Control'
 *    '<S489>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S385>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S732>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S729>/Hold Control'
 *    '<S646>/Hold Control'
 *    '<S489>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S385>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S732>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S729>/Hold Control'
 *    '<S646>/Hold Control'
 *    '<S489>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S385>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S732>/Delay' incorporates:
   *  Gain: '<S734>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S732>/Gain2' incorporates:
   *  Delay: '<S732>/Delay'
   *  Gain: '<S734>/Gain'
   *  Sum: '<S732>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S732>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S729>/Move Control'
 *    '<S646>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S736>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S736>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S729>/Move Control'
 *    '<S646>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S736>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S736>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S729>/Move Control'
 *    '<S646>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S737>/Multiply1' incorporates:
   *  Constant: '<S737>/const1'
   *  DiscreteIntegrator: '<S736>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S735>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S735>/Dead Zone' */

  /* Sum: '<S737>/Add' incorporates:
   *  DiscreteIntegrator: '<S736>/Integrator1'
   *  Gain: '<S733>/Gain1'
   *  Gain: '<S735>/Gain'
   *  Sum: '<S736>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S737>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S737>/Sign' */

  /* Sum: '<S737>/Add2' incorporates:
   *  Abs: '<S737>/Abs'
   *  Gain: '<S737>/Gain'
   *  Gain: '<S737>/Gain1'
   *  Product: '<S737>/Multiply2'
   *  Product: '<S737>/Multiply3'
   *  Sqrt: '<S737>/Sqrt'
   *  Sum: '<S737>/Add1'
   *  Sum: '<S737>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_aw;

  /* Sum: '<S737>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_aw;

  /* Sum: '<S737>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_d + localC->d;

  /* Sum: '<S737>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S737>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S737>/Sign1' */

  /* Signum: '<S737>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S737>/Sign2' */

  /* Sum: '<S737>/Add5' incorporates:
   *  Gain: '<S737>/Gain2'
   *  Product: '<S737>/Multiply4'
   *  Sum: '<S737>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_aw - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S736>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S736>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S736>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S736>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S737>/Add6' */
  rtb_Add3_aw = rtb_a_o + localC->d;

  /* Sum: '<S737>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S737>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S737>/Sign5' */

  /* Signum: '<S737>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S737>/Sign3' */

  /* Signum: '<S737>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S737>/Sign4' */

  /* Signum: '<S737>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S737>/Sign6' */

  /* Update for DiscreteIntegrator: '<S736>/Integrator' incorporates:
   *  Constant: '<S737>/const'
   *  Gain: '<S737>/Gain3'
   *  Product: '<S737>/Divide'
   *  Product: '<S737>/Multiply5'
   *  Product: '<S737>/Multiply6'
   *  Sum: '<S737>/Subtract4'
   *  Sum: '<S737>/Subtract5'
   *  Sum: '<S737>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S730>/Motion Status'
 *    '<S647>/Motion Status'
 *    '<S490>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S730>/Motion Status'
 *    '<S647>/Motion Status'
 *    '<S490>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S730>/Motion Status'
 *    '<S647>/Motion Status'
 *    '<S490>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S730>/Motion Status' */
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

  /* End of Chart: '<S730>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S739>/Hold Control'
 *    '<S678>/Hold Control'
 *    '<S499>/Hold Control'
 */
void FMS_HoldControl_l0_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S742>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S739>/Hold Control'
 *    '<S678>/Hold Control'
 *    '<S499>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S742>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S739>/Hold Control'
 *    '<S678>/Hold Control'
 *    '<S499>/Hold Control'
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

  /* Delay: '<S742>/Delay' incorporates:
   *  SignalConversion: '<S742>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S746>/Trigonometric Function1' incorporates:
   *  Gain: '<S745>/Gain'
   *  Trigonometry: '<S746>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S746>/Trigonometric Function' incorporates:
   *  Gain: '<S745>/Gain'
   *  Trigonometry: '<S746>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S746>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S746>/Constant3'
   */
  rtb_VectorConcatenate_hl[2] = 0.0F;

  /* Gain: '<S746>/Gain' */
  rtb_VectorConcatenate_hl[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S746>/Trigonometric Function3' */
  rtb_VectorConcatenate_hl[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S746>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S746>/Constant4'
   */
  rtb_VectorConcatenate_hl[5] = 0.0F;

  /* SignalConversion: '<S746>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_hl[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_hl[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_hl[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S742>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S742>/Delay'
   *  SignalConversion: '<S742>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S742>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S742>/Multiply' incorporates:
   *  SignalConversion: '<S742>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_hl[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_hl[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S742>/Multiply' */

  /* Gain: '<S742>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S742>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S739>/Brake Control'
 *    '<S678>/Brake Control'
 *    '<S499>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S741>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S739>/Move Control'
 *    '<S678>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S739>/Move Control'
 *    '<S678>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S749>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S739>/Move Control'
 *    '<S678>/Move Control'
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

  /* DiscreteIntegrator: '<S749>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S750>/Multiply1' incorporates:
   *  Constant: '<S750>/const1'
   *  DiscreteIntegrator: '<S749>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S749>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S750>/Multiply1' incorporates:
   *  Constant: '<S750>/const1'
   *  DiscreteIntegrator: '<S749>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S747>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S747>/Dead Zone' */

  /* Sum: '<S750>/Add' incorporates:
   *  DiscreteIntegrator: '<S749>/Integrator1'
   *  Gain: '<S743>/Gain6'
   *  Gain: '<S747>/Gain'
   *  Sum: '<S749>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S748>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S748>/Dead Zone' */

  /* Sum: '<S750>/Add' incorporates:
   *  DiscreteIntegrator: '<S749>/Integrator1'
   *  Gain: '<S743>/Gain6'
   *  Gain: '<S748>/Gain'
   *  Sum: '<S749>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S750>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S750>/Add2' incorporates:
   *  Abs: '<S750>/Abs'
   *  Gain: '<S750>/Gain'
   *  Gain: '<S750>/Gain1'
   *  Product: '<S750>/Multiply2'
   *  Product: '<S750>/Multiply3'
   *  Signum: '<S750>/Sign'
   *  Sqrt: '<S750>/Sqrt'
   *  Sum: '<S750>/Add1'
   *  Sum: '<S750>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S750>/Add3' incorporates:
   *  Signum: '<S750>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S750>/Subtract1' incorporates:
   *  Signum: '<S750>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S750>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S750>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S750>/Add5' incorporates:
   *  Gain: '<S750>/Gain2'
   *  Product: '<S750>/Multiply4'
   *  Signum: '<S750>/Sign'
   *  Sum: '<S750>/Add2'
   *  Sum: '<S750>/Add4'
   *  Sum: '<S750>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S749>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S749>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S750>/Sign3' incorporates:
   *  Sum: '<S750>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S750>/Sign4' incorporates:
   *  Sum: '<S750>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S750>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S750>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S750>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S750>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S749>/Integrator' incorporates:
   *  Constant: '<S750>/const'
   *  Gain: '<S750>/Gain3'
   *  Product: '<S750>/Divide'
   *  Product: '<S750>/Multiply5'
   *  Product: '<S750>/Multiply6'
   *  Sum: '<S750>/Subtract4'
   *  Sum: '<S750>/Subtract5'
   *  Sum: '<S750>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S749>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S750>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S750>/Add2' incorporates:
   *  Abs: '<S750>/Abs'
   *  Gain: '<S750>/Gain'
   *  Gain: '<S750>/Gain1'
   *  Product: '<S750>/Multiply2'
   *  Product: '<S750>/Multiply3'
   *  Signum: '<S750>/Sign'
   *  Sqrt: '<S750>/Sqrt'
   *  Sum: '<S750>/Add1'
   *  Sum: '<S750>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S750>/Add3' incorporates:
   *  Signum: '<S750>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S750>/Subtract1' incorporates:
   *  Signum: '<S750>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S750>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S750>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S750>/Add5' incorporates:
   *  Gain: '<S750>/Gain2'
   *  Product: '<S750>/Multiply4'
   *  Signum: '<S750>/Sign'
   *  Sum: '<S750>/Add2'
   *  Sum: '<S750>/Add4'
   *  Sum: '<S750>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S749>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S749>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S750>/Sign3' incorporates:
   *  Sum: '<S750>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S750>/Sign4' incorporates:
   *  Sum: '<S750>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S750>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S750>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S750>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S750>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S749>/Integrator' incorporates:
   *  Constant: '<S750>/const'
   *  Gain: '<S750>/Gain3'
   *  Product: '<S750>/Divide'
   *  Product: '<S750>/Multiply5'
   *  Product: '<S750>/Multiply6'
   *  Sum: '<S750>/Subtract4'
   *  Sum: '<S750>/Subtract5'
   *  Sum: '<S750>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S749>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S740>/Motion State'
 *    '<S679>/Motion State'
 *    '<S500>/Motion State'
 */
void FMS_MotionState_c_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S740>/Motion State'
 *    '<S679>/Motion State'
 *    '<S500>/Motion State'
 */
void FMS_MotionState_f_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S740>/Motion State'
 *    '<S679>/Motion State'
 *    '<S500>/Motion State'
 */
void FMS_MotionState_p(real32_T rtu_motion_req, real32_T rtu_speed, MotionState *
  rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S740>/Motion State' */
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

  /* End of Chart: '<S740>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S722>/OutRegionRegWP'
 *    '<S476>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S755>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S657>/Hold Control'
 *    '<S435>/Hold Control'
 *    '<S369>/Hold Control'
 *    '<S397>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S661>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S657>/Hold Control'
 *    '<S435>/Hold Control'
 *    '<S369>/Hold Control'
 *    '<S397>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S661>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S657>/Hold Control'
 *    '<S435>/Hold Control'
 *    '<S369>/Hold Control'
 *    '<S397>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S661>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S661>/Sum' incorporates:
   *  Delay: '<S661>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S664>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S664>/Switch' incorporates:
   *  Constant: '<S664>/Constant'
   *  Constant: '<S665>/Constant'
   *  Product: '<S664>/Multiply'
   *  RelationalOperator: '<S665>/Compare'
   *  Sum: '<S664>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S664>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S664>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S664>/Switch' */

  /* Gain: '<S661>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S661>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S657>/Move Control'
 *    '<S435>/Move Control'
 *    '<S369>/Move Control'
 *    '<S397>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S667>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S667>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S657>/Move Control'
 *    '<S435>/Move Control'
 *    '<S369>/Move Control'
 *    '<S397>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S667>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S667>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S657>/Move Control'
 *    '<S435>/Move Control'
 *    '<S369>/Move Control'
 *    '<S397>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_mb;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S668>/Multiply1' incorporates:
   *  Constant: '<S668>/const1'
   *  DiscreteIntegrator: '<S667>/Integrator'
   */
  rtb_Add3_mb = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S666>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S666>/Dead Zone' */

  /* Sum: '<S668>/Add' incorporates:
   *  DiscreteIntegrator: '<S667>/Integrator1'
   *  Gain: '<S662>/Gain1'
   *  Gain: '<S666>/Gain'
   *  Sum: '<S667>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_mb;

  /* Signum: '<S668>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
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
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_mb;

  /* Sum: '<S668>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_mb;

  /* Sum: '<S668>/Add3' */
  rtb_Add3_mb = rtb_Subtract3_e + localC->d;

  /* Sum: '<S668>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S668>/Sign1' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S668>/Sign1' */

  /* Signum: '<S668>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S668>/Sign2' */

  /* Sum: '<S668>/Add5' incorporates:
   *  Gain: '<S668>/Gain2'
   *  Product: '<S668>/Multiply4'
   *  Sum: '<S668>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_mb - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S667>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S667>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S667>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S667>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S668>/Add6' */
  rtb_Add3_mb = rtb_a_h + localC->d;

  /* Sum: '<S668>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S668>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S668>/Sign5' */

  /* Signum: '<S668>/Sign3' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S668>/Sign3' */

  /* Signum: '<S668>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S668>/Sign4' */

  /* Signum: '<S668>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S668>/Sign6' */

  /* Update for DiscreteIntegrator: '<S667>/Integrator' incorporates:
   *  Constant: '<S668>/const'
   *  Gain: '<S668>/Gain3'
   *  Product: '<S668>/Divide'
   *  Product: '<S668>/Multiply5'
   *  Product: '<S668>/Multiply6'
   *  Sum: '<S668>/Subtract4'
   *  Sum: '<S668>/Subtract5'
   *  Sum: '<S668>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_mb - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S436>/Motion State'
 *    '<S370>/Motion State'
 *    '<S398>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S436>/Motion State'
 *    '<S370>/Motion State'
 *    '<S398>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S436>/Motion State'
 *    '<S370>/Motion State'
 *    '<S398>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S436>/Motion State' */
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

  /* End of Chart: '<S436>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S351>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S360>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S360>/Dead Zone' */

  /* Gain: '<S355>/Gain1' incorporates:
   *  Gain: '<S360>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S355>/Switch' incorporates:
   *  Constant: '<S357>/Land_Speed'
   *  Constant: '<S358>/Constant'
   *  Constant: '<S359>/Constant'
   *  Gain: '<S357>/Gain'
   *  Logic: '<S355>/Logical Operator'
   *  MinMax: '<S357>/Min'
   *  RelationalOperator: '<S358>/Compare'
   *  RelationalOperator: '<S359>/Compare'
   *  S-Function (sfix_bitop): '<S355>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S355>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S786>/Switch' incorporates:
   *  Constant: '<S786>/FW_ACCEPT_R'
   *  Constant: '<S786>/MC_ACCEPT_R'
   *  Constant: '<S793>/Constant'
   *  RelationalOperator: '<S793>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S786>/Switch' */
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

  /* Math: '<S804>/Rem' incorporates:
   *  Constant: '<S804>/Constant1'
   *  Sum: '<S788>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S804>/Switch' incorporates:
   *  Abs: '<S804>/Abs'
   *  Constant: '<S804>/Constant'
   *  Constant: '<S805>/Constant'
   *  Product: '<S804>/Multiply'
   *  RelationalOperator: '<S805>/Compare'
   *  Sum: '<S804>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S804>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S804>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S804>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S791>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S810>/Sum of Elements' incorporates:
   *  Math: '<S810>/Math Function'
   *  SignalConversion: '<S810>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S810>/Math Function1' incorporates:
   *  Sum: '<S810>/Sum of Elements'
   *
   * About '<S810>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S810>/Math Function1' */

  /* Switch: '<S810>/Switch' incorporates:
   *  Constant: '<S810>/Constant'
   *  Product: '<S810>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S810>/Switch' */

  /* Product: '<S810>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S808>/Subtract' incorporates:
   *  Product: '<S808>/Multiply'
   *  Product: '<S808>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S807>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S807>/Sign1' */

  /* Switch: '<S807>/Switch2' incorporates:
   *  Constant: '<S807>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S807>/Switch2' */

  /* DotProduct: '<S807>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S807>/Acos' incorporates:
   *  DotProduct: '<S807>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S807>/Multiply' incorporates:
   *  Trigonometry: '<S807>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S791>/Switch' incorporates:
   *  Bias: '<S791>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S791>/Switch' */
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

  /* Gain: '<S794>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S795>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S795>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S795>/Multiply1' incorporates:
   *  Product: '<S795>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S795>/Divide' incorporates:
   *  Constant: '<S795>/Constant'
   *  Constant: '<S795>/R'
   *  Sqrt: '<S795>/Sqrt'
   *  Sum: '<S795>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S795>/Product3' incorporates:
   *  Constant: '<S795>/Constant1'
   *  Product: '<S795>/Multiply1'
   *  Sum: '<S795>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S795>/Multiply2' incorporates:
   *  Trigonometry: '<S795>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S794>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S799>/Abs' incorporates:
   *  Abs: '<S802>/Abs1'
   *  Switch: '<S799>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S799>/Switch1' incorporates:
   *  Abs: '<S799>/Abs'
   *  Bias: '<S799>/Bias2'
   *  Bias: '<S799>/Bias3'
   *  Constant: '<S796>/Constant'
   *  Constant: '<S796>/Constant1'
   *  Constant: '<S801>/Constant'
   *  Gain: '<S799>/Gain1'
   *  Product: '<S799>/Multiply'
   *  RelationalOperator: '<S801>/Compare'
   *  Switch: '<S796>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S802>/Switch1' incorporates:
     *  Bias: '<S802>/Bias2'
     *  Bias: '<S802>/Bias3'
     *  Constant: '<S802>/Constant'
     *  Constant: '<S803>/Constant'
     *  Math: '<S802>/Math Function'
     *  RelationalOperator: '<S803>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S802>/Switch1' */

    /* Signum: '<S799>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S799>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S796>/Sum' incorporates:
   *  Sum: '<S794>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S794>/Multiply' incorporates:
   *  Gain: '<S794>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S798>/Switch1' incorporates:
   *  Abs: '<S798>/Abs1'
   *  Bias: '<S798>/Bias2'
   *  Bias: '<S798>/Bias3'
   *  Constant: '<S798>/Constant'
   *  Constant: '<S800>/Constant'
   *  Math: '<S798>/Math Function'
   *  RelationalOperator: '<S800>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S798>/Switch1' */

  /* Product: '<S794>/Multiply' incorporates:
   *  Gain: '<S794>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S794>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S797>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S797>/Sum2' incorporates:
   *  Product: '<S797>/Multiply1'
   *  Product: '<S797>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S797>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S797>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S797>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S787>/Data Type Conversion' incorporates:
   *  Gain: '<S794>/Gain'
   *  Sum: '<S794>/Sum1'
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

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Altitude(void)
{
  /* Inport: '<Root>/INS_Out' */
  if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
  {
    FMS_B.target_mode = PilotMode_Altitude;

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
    FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

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

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1 = false;
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
    if (FMS_DW.temporalCounter_i1 >= FMS_U.Mission_Data.param1[FMS_B.wp_index -
        1] * 250.0F) {
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
  FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
  /* RelationalOperator: '<S806>/Compare' incorporates:
   *  Abs: '<S790>/Abs'
   *  Constant: '<S806>/Constant'
   *  MinMax: '<S790>/Max'
   *  Sum: '<S790>/Sum'
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
        FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1_f = false;
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
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
    } else {
      FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
    }

    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_exit_internal_SubMode();
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
            FMS_enter_internal_Hold();
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
            FMS_enter_internal_Hold();
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
      /* Reshape: '<S789>/Reshape' incorporates:
       *  Constant: '<S789>/Constant'
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
          /* RelationalOperator: '<S792>/Compare' incorporates:
           *  Constant: '<S792>/Constant'
           *  S-Function (sfix_bitop): '<S784>/Bitwise AND'
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
          /* RelationalOperator: '<S785>/Relational Operator1' incorporates:
           *  Constant: '<S785>/Constant1'
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
        /* RelationalOperator: '<S783>/Relational Operator' incorporates:
         *  Constant: '<S783>/Constant'
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
          /* RelationalOperator: '<S782>/Relational Operator1' incorporates:
           *  Constant: '<S782>/Constant1'
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
  real32_T rtb_TmpSignalConversionAtMultip[3];
  real32_T rtb_VectorConcatenate[9];
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  real32_T rtb_Vg;
  int8_T rtPrevAction;
  real32_T rtb_Divide_bu[4];
  real32_T rtb_Square_gf;
  real32_T rtb_MatrixConcatenate1_a[9];
  real32_T rtb_Saturation_ga;
  real32_T rtb_Saturation1_d;
  real32_T rtb_Switch_c2[3];
  real32_T rtb_Divide_f0[2];
  real32_T rtb_Square_dv[2];
  real32_T rtb_Saturation1_p5;
  real32_T rtb_Saturation_o4;
  int32_T rtb_n;
  real32_T rtb_Switch_ov[3];
  real32_T rtb_a_bx;
  real32_T rtb_Integrator1_bx;
  real32_T rtb_Sign5_mn;
  real32_T rtb_Add4_a1;
  MotionState rtb_state_l4;
  real32_T rtb_Subtract3_g;
  real32_T rtb_Divide_jb;
  real32_T rtb_Sign5_dc;
  MotionState rtb_state_fg;
  MotionState rtb_state_og;
  real_T rtb_Switch1_n;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_aw;
  uint16_T rtb_y_cc;
  real32_T rtb_u_b;
  boolean_T rtb_Compare_at;
  real32_T rtb_P_ap[2];
  real32_T rtb_Subtract_hb[2];
  real32_T rtb_MatrixConcatenate1_a_0[3];
  boolean_T tmp[3];
  boolean_T tmp_0[3];
  boolean_T tmp_1[3];
  real32_T rtb_P_f_idx_0;
  real_T rtb_Multiply_g_idx_0;
  uint32_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_TmpSignalConversionAtMultip[0] = FMS_U.INS_Out.vn;
  rtb_TmpSignalConversionAtMultip[1] = FMS_U.INS_Out.ve;
  rtb_TmpSignalConversionAtMultip[2] = FMS_U.INS_Out.vd;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S42>/Arm' incorporates:
   *  ActionPort: '<S44>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S336>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S336>/Position' incorporates:
   *  ActionPort: '<S343>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S410>/Hold Control' incorporates:
   *  ActionPort: '<S412>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S337>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S337>/Offboard' incorporates:
   *  ActionPort: '<S449>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S339>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S339>/Land' incorporates:
   *  ActionPort: '<S639>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S339>/Takeoff' incorporates:
   *  ActionPort: '<S641>/Action Port'
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
   *  MultiPortSwitch: '<S531>/Index Vector'
   *  MultiPortSwitch: '<S596>/Index Vector'
   *  MultiPortSwitch: '<S597>/Index Vector'
   *  SwitchCase: '<S336>/Switch Case'
   *  SwitchCase: '<S337>/Switch Case'
   *  SwitchCase: '<S339>/Switch Case'
   *  SwitchCase: '<S410>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function1'
   *  Trigonometry: '<S100>/Trigonometric Function3'
   *  Trigonometry: '<S15>/Trigonometric Function1'
   *  Trigonometry: '<S15>/Trigonometric Function3'
   *  Trigonometry: '<S221>/Trigonometric Function1'
   *  Trigonometry: '<S221>/Trigonometric Function3'
   *  Trigonometry: '<S416>/Trigonometric Function1'
   *  Trigonometry: '<S416>/Trigonometric Function3'
   *  Trigonometry: '<S542>/Trigonometric Function1'
   *  Trigonometry: '<S542>/Trigonometric Function3'
   *  Trigonometry: '<S605>/Trigonometric Function1'
   *  Trigonometry: '<S605>/Trigonometric Function3'
   *  Trigonometry: '<S609>/Trigonometric Function1'
   *  Trigonometry: '<S609>/Trigonometric Function3'
   *  Trigonometry: '<S635>/Trigonometric Function1'
   *  Trigonometry: '<S635>/Trigonometric Function3'
   *  Trigonometry: '<S699>/Trigonometric Function1'
   *  Trigonometry: '<S699>/Trigonometric Function3'
   *  Trigonometry: '<S780>/Trigonometric Function1'
   *  Trigonometry: '<S780>/Trigonometric Function3'
   */
  rtb_Saturation_ga = arm_cos_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S125>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S339>/Takeoff' */
  /* End of Outputs for SubSystem: '<S339>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S337>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S410>/Hold Control' */
  /* End of Outputs for SubSystem: '<S336>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Trigonometry: '<S15>/Trigonometric Function1' */
  rtb_VectorConcatenate[0] = rtb_Saturation_ga;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S42>/Arm' incorporates:
   *  ActionPort: '<S44>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S336>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S336>/Position' incorporates:
   *  ActionPort: '<S343>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S410>/Hold Control' incorporates:
   *  ActionPort: '<S412>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S337>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S337>/Offboard' incorporates:
   *  ActionPort: '<S449>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S339>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S339>/Land' incorporates:
   *  ActionPort: '<S639>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S339>/Takeoff' incorporates:
   *  ActionPort: '<S641>/Action Port'
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
   *  MultiPortSwitch: '<S531>/Index Vector'
   *  MultiPortSwitch: '<S596>/Index Vector'
   *  MultiPortSwitch: '<S597>/Index Vector'
   *  SwitchCase: '<S336>/Switch Case'
   *  SwitchCase: '<S337>/Switch Case'
   *  SwitchCase: '<S339>/Switch Case'
   *  SwitchCase: '<S410>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function2'
   *  Trigonometry: '<S221>/Trigonometric Function'
   *  Trigonometry: '<S416>/Trigonometric Function'
   *  Trigonometry: '<S542>/Trigonometric Function'
   *  Trigonometry: '<S605>/Trigonometric Function'
   *  Trigonometry: '<S609>/Trigonometric Function'
   *  Trigonometry: '<S635>/Trigonometric Function'
   *  Trigonometry: '<S699>/Trigonometric Function'
   *  Trigonometry: '<S780>/Trigonometric Function'
   */
  rtb_Saturation1_d = arm_sin_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S125>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S339>/Takeoff' */
  /* End of Outputs for SubSystem: '<S339>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S337>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S410>/Hold Control' */
  /* End of Outputs for SubSystem: '<S336>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Trigonometry: '<S15>/Trigonometric Function' */
  rtb_VectorConcatenate[1] = rtb_Saturation1_d;

  /* SignalConversion: '<S15>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S15>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S15>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Saturation1_d;

  /* Trigonometry: '<S15>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_Saturation_ga;

  /* SignalConversion: '<S15>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S15>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

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
    rtb_Square_gf = FMS_U.INS_Out.airspeed;
  } else {
    /* Sqrt: '<S21>/Sqrt' incorporates:
     *  Math: '<S21>/Square'
     *  Sum: '<S21>/Sum of Elements'
     */
    rtb_Square_gf = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
      FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
      FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

    /* Product: '<S17>/Divide' */
    rtb_Divide_bu[0] = FMS_U.INS_Out.quat[0] / rtb_Square_gf;
    rtb_Divide_bu[1] = FMS_U.INS_Out.quat[1] / rtb_Square_gf;
    rtb_Divide_bu[2] = FMS_U.INS_Out.quat[2] / rtb_Square_gf;
    rtb_Divide_bu[3] = FMS_U.INS_Out.quat[3] / rtb_Square_gf;

    /* Math: '<S20>/Square' incorporates:
     *  Math: '<S18>/Square'
     *  Math: '<S19>/Square'
     */
    rtb_Saturation_o4 = rtb_Divide_bu[0] * rtb_Divide_bu[0];

    /* Math: '<S20>/Square2' incorporates:
     *  Math: '<S18>/Square2'
     *  Math: '<S19>/Square2'
     */
    rtb_u_b = rtb_Divide_bu[2] * rtb_Divide_bu[2];

    /* Math: '<S20>/Square1' incorporates:
     *  Math: '<S18>/Square1'
     *  Math: '<S19>/Square1'
     */
    rtb_Square_gf = rtb_Divide_bu[1] * rtb_Divide_bu[1];

    /* Math: '<S20>/Square3' incorporates:
     *  Math: '<S18>/Square3'
     *  Math: '<S19>/Square3'
     */
    rtb_Vg = rtb_Divide_bu[3] * rtb_Divide_bu[3];

    /* Sum: '<S20>/Subtract' incorporates:
     *  Math: '<S20>/Square'
     *  Math: '<S20>/Square1'
     *  Math: '<S20>/Square2'
     *  Math: '<S20>/Square3'
     *  Sum: '<S20>/Add'
     *  Sum: '<S20>/Add1'
     */
    rtb_MatrixConcatenate1_a[8] = (rtb_Saturation_o4 + rtb_Vg) - (rtb_Square_gf
      + rtb_u_b);

    /* Product: '<S20>/Multiply2' incorporates:
     *  Product: '<S19>/Multiply2'
     */
    rtb_Saturation1_p5 = rtb_Divide_bu[2] * rtb_Divide_bu[3];

    /* Product: '<S20>/Multiply3' incorporates:
     *  Product: '<S19>/Multiply3'
     */
    rtb_Add4_a1 = rtb_Divide_bu[0] * rtb_Divide_bu[1];

    /* Gain: '<S20>/Gain1' incorporates:
     *  Product: '<S20>/Multiply2'
     *  Product: '<S20>/Multiply3'
     *  Sum: '<S20>/Add2'
     */
    rtb_MatrixConcatenate1_a[7] = (rtb_Saturation1_p5 + rtb_Add4_a1) * 2.0F;

    /* Product: '<S20>/Multiply' incorporates:
     *  Product: '<S18>/Multiply2'
     */
    d = rtb_Divide_bu[1] * rtb_Divide_bu[3];

    /* Product: '<S20>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply3'
     */
    rtb_Integrator1_bx = rtb_Divide_bu[0] * rtb_Divide_bu[2];

    /* Gain: '<S20>/Gain' incorporates:
     *  Product: '<S20>/Multiply'
     *  Product: '<S20>/Multiply1'
     *  Sum: '<S20>/Subtract2'
     */
    rtb_MatrixConcatenate1_a[6] = (d - rtb_Integrator1_bx) * 2.0F;

    /* Gain: '<S19>/Gain1' incorporates:
     *  Sum: '<S19>/Subtract1'
     */
    rtb_MatrixConcatenate1_a[5] = (rtb_Saturation1_p5 - rtb_Add4_a1) * 2.0F;

    /* Sum: '<S19>/Subtract' incorporates:
     *  Sum: '<S19>/Add'
     *  Sum: '<S19>/Add1'
     */
    rtb_MatrixConcatenate1_a[4] = (rtb_Saturation_o4 + rtb_u_b) - (rtb_Square_gf
      + rtb_Vg);

    /* Product: '<S19>/Multiply' incorporates:
     *  Product: '<S18>/Multiply'
     */
    rtb_Saturation1_p5 = rtb_Divide_bu[1] * rtb_Divide_bu[2];

    /* Product: '<S19>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply1'
     */
    rtb_Add4_a1 = rtb_Divide_bu[0] * rtb_Divide_bu[3];

    /* Gain: '<S19>/Gain' incorporates:
     *  Product: '<S19>/Multiply'
     *  Product: '<S19>/Multiply1'
     *  Sum: '<S19>/Add3'
     */
    rtb_MatrixConcatenate1_a[3] = (rtb_Saturation1_p5 + rtb_Add4_a1) * 2.0F;

    /* Gain: '<S18>/Gain1' incorporates:
     *  Sum: '<S18>/Add2'
     */
    rtb_MatrixConcatenate1_a[2] = (d + rtb_Integrator1_bx) * 2.0F;

    /* Gain: '<S18>/Gain' incorporates:
     *  Sum: '<S18>/Subtract1'
     */
    rtb_MatrixConcatenate1_a[1] = (rtb_Saturation1_p5 - rtb_Add4_a1) * 2.0F;

    /* Sum: '<S18>/Subtract' incorporates:
     *  Sum: '<S18>/Add'
     *  Sum: '<S18>/Add1'
     */
    rtb_MatrixConcatenate1_a[0] = (rtb_Saturation_o4 + rtb_Square_gf) - (rtb_u_b
      + rtb_Vg);

    /* Product: '<S13>/Multiply' */
    for (rtb_n = 0; rtb_n < 3; rtb_n++) {
      rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_MatrixConcatenate1_a[rtb_n + 6] *
        rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1_a[rtb_n + 3]
        * rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1_a[rtb_n] *
        rtb_TmpSignalConversionAtMultip[0]);
    }

    /* End of Product: '<S13>/Multiply' */
    rtb_Square_gf = rtb_MatrixConcatenate1_a_0[0];
  }

  /* End of Switch: '<S1>/Switch' */

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Square_gf > 100.0F) {
    rtb_Square_gf = 100.0F;
  } else {
    if (rtb_Square_gf < 0.1F) {
      rtb_Square_gf = 0.1F;
    }
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Square_gf;
  }

  FMS_B.DiscreteTimeIntegrator5 = FMS_DW.DiscreteTimeIntegrator5_DSTATE;

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
    rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
      rtb_TmpSignalConversionAtMultip[2] + (rtb_VectorConcatenate[rtb_n + 3] *
      rtb_TmpSignalConversionAtMultip[1] + rtb_VectorConcatenate[rtb_n] *
      rtb_TmpSignalConversionAtMultip[0]);
  }

  /* End of Product: '<S12>/Multiply' */

  /* Signum: '<S12>/Sign' */
  if (rtb_MatrixConcatenate1_a_0[0] < 0.0F) {
    rtb_Vg = -1.0F;
  } else if (rtb_MatrixConcatenate1_a_0[0] > 0.0F) {
    rtb_Vg = 1.0F;
  } else {
    rtb_Vg = rtb_MatrixConcatenate1_a_0[0];
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
   *  ActionPort: '<S237>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S237>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S241>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
   *  ActionPort: '<S128>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
   *  ActionPort: '<S271>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Takeoff' incorporates:
   *  ActionPort: '<S272>/Action Port'
   */
  /* SwitchCase: '<S126>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S260>/Math Function'
   *  Math: '<S309>/Math Function'
   *  Math: '<S331>/Math Function'
   *  SwitchCase: '<S128>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   */
  rtb_Saturation_o4 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Add4_a1 = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S128>/Takeoff' */
  /* End of Outputs for SubSystem: '<S128>/Return' */
  /* End of Outputs for SubSystem: '<S237>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S126>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */

  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S337>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S337>/Mission' incorporates:
   *  ActionPort: '<S448>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S448>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S452>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S339>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S339>/Return' incorporates:
   *  ActionPort: '<S640>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Hold' incorporates:
   *  ActionPort: '<S269>/Action Port'
   */
  /* SwitchCase: '<S128>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S286>/Sum of Elements'
   *  Sum: '<S520>/Sum of Elements'
   *  Sum: '<S760>/Sum of Elements'
   *  SwitchCase: '<S337>/Switch Case'
   *  SwitchCase: '<S339>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Integrator1_bx = rtb_Saturation_o4 + rtb_Add4_a1;

  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S336>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S336>/Position' incorporates:
   *  ActionPort: '<S343>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S126>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
   *  ActionPort: '<S237>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S237>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S241>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
   *  ActionPort: '<S271>/Action Port'
   */
  /* SwitchCase: '<S126>/Switch Case' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S259>/Sqrt'
   *  Sqrt: '<S285>/Sqrt'
   *  Sqrt: '<S308>/Sqrt'
   *  Sqrt: '<S411>/Sqrt'
   *  Sqrt: '<S518>/Sqrt'
   *  Sqrt: '<S758>/Sqrt'
   *  Sum: '<S1>/Add'
   *  SwitchCase: '<S128>/Switch Case'
   *  SwitchCase: '<S336>/Switch Case'
   *  SwitchCase: '<S337>/Switch Case'
   *  SwitchCase: '<S339>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Saturation1_p5 = sqrtf(rtb_Integrator1_bx);

  /* End of Outputs for SubSystem: '<S128>/Return' */
  /* End of Outputs for SubSystem: '<S237>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S126>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */
  /* End of Outputs for SubSystem: '<S336>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S128>/Hold' */
  /* End of Outputs for SubSystem: '<S339>/Return' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S448>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S337>/Mission' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S49>/SubMode' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   */
  rtb_Vg *= rtb_Saturation1_p5;

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_m != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_h = rtb_Vg;
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
  /* SignalConversion: '<S43>/Signal Copy1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_bu[0] = FMS_U.INS_Out.quat[0];
  rtb_Divide_bu[1] = FMS_U.INS_Out.quat[1];
  rtb_Divide_bu[2] = FMS_U.INS_Out.quat[2];
  rtb_Divide_bu[3] = FMS_U.INS_Out.quat[3];

  /* SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_TmpSignalConversionAtMultip[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_ov[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_TmpSignalConversionAtMultip[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_ov[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_TmpSignalConversionAtMultip[2] = FMS_B.Cmd_In.sp_waypoint[2];
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
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S175>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S161>/Switch Case' */
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
        /* Disable for SwitchCase: '<S339>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S739>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S729>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S678>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S646>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S657>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S337>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S448>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S499>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S489>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S448>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S336>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S435>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S351>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S369>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S410>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S397>/Switch Case' */
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
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S175>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S161>/Switch Case' */
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
          /* Disable for SwitchCase: '<S339>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S739>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S729>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S678>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S646>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S657>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S337>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S448>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S499>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S489>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S448>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S336>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S435>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S351>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S369>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S410>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S397>/Switch Case' */
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
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S175>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S161>/Switch Case' */
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
           *  ActionPort: '<S272>/Action Port'
           */
          /* Sum: '<S331>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_a1;

          /* Math: '<S331>/Math Function1' incorporates:
           *  Sum: '<S331>/Sum of Elements'
           *
           * About '<S331>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S331>/Math Function1' */

          /* Switch: '<S331>/Switch' incorporates:
           *  Constant: '<S331>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S331>/Product'
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

          /* End of Switch: '<S331>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S321>/NearbyRefWP' incorporates:
           *  Constant: '<S319>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_f0,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S321>/SearchL1RefWP' incorporates:
           *  Constant: '<S319>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_ap, &rtb_u_b);

          /* MATLAB Function: '<S321>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S316>/Sum'
           *  Sum: '<S316>/Sum1'
           */
          rtb_Saturation1_p5 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Integrator1_bx = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Integrator1_bx * rtb_Integrator1_bx;
          rtb_Saturation_ga = (rtb_a_bx * rtb_Integrator1_bx + d *
                               rtb_Saturation1_p5) / (rtb_P_f_idx_0 +
            rtb_Saturation1_p5 * rtb_Saturation1_p5);
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
            rtb_Sign5_mn = (rtb_Saturation_ga * rtb_Saturation1_p5 +
                            FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Sign5_mn * rtb_Sign5_mn;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_mn = (rtb_Saturation_ga * rtb_Integrator1_bx +
                            FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_ga += sqrtf(rtb_Sign5_mn * rtb_Sign5_mn +
              rtb_Subtract_hb[0]) * 0.5774F / sqrtf(rtb_Saturation1_p5 *
              rtb_Saturation1_p5 + rtb_P_f_idx_0);
            if (rtb_Saturation_ga > 1.0F) {
              rtb_Saturation_ga = 1.0F;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = rtb_Saturation_ga * rtb_Saturation1_p5 +
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_ga = rtb_Saturation_ga * rtb_Integrator1_bx +
              FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S321>/OutRegionRegWP' */

          /* Switch: '<S321>/Switch1' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           */
          if (rtb_Saturation1_d <= 0.0F) {
            /* Switch: '<S321>/Switch' incorporates:
             *  Constant: '<S323>/Constant'
             *  RelationalOperator: '<S323>/Compare'
             */
            if (rtb_u_b >= 0.0F) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            } else {
              rtb_Divide_f0[0] = rtb_P_f_idx_0;
              rtb_Divide_f0[1] = rtb_Saturation_ga;
            }

            /* End of Switch: '<S321>/Switch' */
          }

          /* End of Switch: '<S321>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S322>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S332>/Sum of Elements' incorporates:
           *  Math: '<S332>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S332>/Math Function1' incorporates:
           *  Sum: '<S332>/Sum of Elements'
           *
           * About '<S332>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S332>/Math Function1' */

          /* Switch: '<S332>/Switch' incorporates:
           *  Constant: '<S332>/Constant'
           *  Product: '<S332>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Subtract_hb[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract_hb[1];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S332>/Switch' */

          /* Product: '<S331>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S334>/Sum of Elements' incorporates:
           *  Math: '<S334>/Math Function'
           *  SignalConversion: '<S334>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S334>/Math Function1' incorporates:
           *  Sum: '<S334>/Sum of Elements'
           *
           * About '<S334>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S334>/Math Function1' */

          /* Switch: '<S334>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  Product: '<S334>/Product'
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

          /* End of Switch: '<S334>/Switch' */

          /* Product: '<S332>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S335>/Sum of Elements' incorporates:
           *  Math: '<S335>/Math Function'
           *  SignalConversion: '<S335>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

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
           *  Product: '<S335>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Subtract_hb[1];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract_hb[0];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S335>/Switch' */

          /* Product: '<S335>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S334>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S335>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S334>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S316>/Divide' incorporates:
           *  Math: '<S317>/Square'
           *  Math: '<S318>/Square'
           *  Sqrt: '<S317>/Sqrt'
           *  Sqrt: '<S318>/Sqrt'
           *  Sum: '<S317>/Sum of Elements'
           *  Sum: '<S318>/Sum of Elements'
           */
          rtb_Saturation1_p5 = sqrtf(rtb_a_bx * rtb_a_bx + d * d) / sqrtf
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 + rtb_Integrator1_bx *
             rtb_Integrator1_bx);

          /* Saturate: '<S316>/Saturation' */
          if (rtb_Saturation1_p5 > 1.0F) {
            rtb_Saturation1_p5 = 1.0F;
          } else {
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation1_p5 = 0.0F;
            }
          }

          /* End of Saturate: '<S316>/Saturation' */

          /* Sum: '<S333>/Subtract' incorporates:
           *  Product: '<S333>/Multiply'
           *  Product: '<S333>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S329>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S329>/Sign1' */

          /* Switch: '<S329>/Switch2' incorporates:
           *  Constant: '<S329>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S329>/Switch2' */

          /* DotProduct: '<S329>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S329>/Acos' incorporates:
           *  DotProduct: '<S329>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S329>/Multiply' incorporates:
           *  Trigonometry: '<S329>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S328>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S328>/Saturation' */

          /* Sqrt: '<S330>/Sqrt' incorporates:
           *  Sum: '<S330>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(rtb_Saturation_o4 + rtb_Add4_a1);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S272>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S272>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S272>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S272>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S328>/Divide' incorporates:
           *  Constant: '<S319>/L1'
           *  Gain: '<S328>/Gain'
           *  Math: '<S328>/Square'
           *  Product: '<S328>/Multiply1'
           *  Trigonometry: '<S328>/Sin'
           */
          rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F * arm_sin_f32
            (rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S319>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S272>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S272>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S272>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S319>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S314>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S316>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S314>/Sum2'
           *  Sum: '<S316>/Add'
           *  Sum: '<S316>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_p5 +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S314>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S272>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S272>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S272>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S314>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S128>/Land' incorporates:
           *  ActionPort: '<S270>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S270>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S270>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S270>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S270>/Constant'
           *  Constant: '<S270>/Constant4'
           *  Constant: '<S270>/Constant5'
           *  Constant: '<S270>/Constant7'
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
           *  ActionPort: '<S271>/Action Port'
           */
          /* Math: '<S309>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Add4_a1;

          /* Sum: '<S309>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_a1;

          /* Math: '<S309>/Math Function1' incorporates:
           *  Sum: '<S309>/Sum of Elements'
           *
           * About '<S309>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S309>/Math Function1' */

          /* Switch: '<S309>/Switch' incorporates:
           *  Constant: '<S309>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S309>/Product'
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

          /* End of Switch: '<S309>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S299>/NearbyRefWP' incorporates:
           *  Constant: '<S297>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S299>/SearchL1RefWP' incorporates:
           *  Constant: '<S297>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_f0, &rtb_Saturation1_d);

          /* MATLAB Function: '<S299>/OutRegionRegWP' incorporates:
           *  Constant: '<S297>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0],
                             &rtb_TmpSignalConversionAtMultip[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S299>/Switch1' incorporates:
           *  Constant: '<S302>/Constant'
           *  RelationalOperator: '<S302>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_f0[0] = rtb_Subtract_hb[0];
            rtb_Divide_f0[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S301>/Compare' incorporates:
             *  Constant: '<S301>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S299>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S299>/Switch' */
          }

          /* End of Switch: '<S299>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S300>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S310>/Sum of Elements' incorporates:
           *  Math: '<S310>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S310>/Math Function1' incorporates:
           *  Sum: '<S310>/Sum of Elements'
           *
           * About '<S310>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S310>/Math Function1' */

          /* Switch: '<S310>/Switch' incorporates:
           *  Constant: '<S310>/Constant'
           *  Product: '<S310>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Subtract_hb[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract_hb[1];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S310>/Switch' */

          /* Product: '<S309>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S312>/Sum of Elements' incorporates:
           *  Math: '<S312>/Math Function'
           *  SignalConversion: '<S312>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S312>/Math Function1' incorporates:
           *  Sum: '<S312>/Sum of Elements'
           *
           * About '<S312>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S312>/Math Function1' */

          /* Switch: '<S312>/Switch' incorporates:
           *  Constant: '<S312>/Constant'
           *  Product: '<S312>/Product'
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

          /* End of Switch: '<S312>/Switch' */

          /* Product: '<S310>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S313>/Sum of Elements' incorporates:
           *  Math: '<S313>/Math Function'
           *  SignalConversion: '<S313>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

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
           *  Product: '<S313>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Subtract_hb[1];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract_hb[0];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S313>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S294>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S313>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S312>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S294>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_a1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S313>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S312>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S294>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S294>/Divide' incorporates:
           *  Math: '<S295>/Square'
           *  Math: '<S296>/Square'
           *  Sqrt: '<S295>/Sqrt'
           *  Sqrt: '<S296>/Sqrt'
           *  Sum: '<S294>/Sum'
           *  Sum: '<S294>/Sum1'
           *  Sum: '<S295>/Sum of Elements'
           *  Sum: '<S296>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_bx * rtb_a_bx + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Add4_a1 * rtb_Add4_a1 + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S294>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S294>/Saturation' */

          /* Sum: '<S311>/Subtract' incorporates:
           *  Product: '<S311>/Multiply'
           *  Product: '<S311>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S307>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S307>/Sign1' */

          /* Switch: '<S307>/Switch2' incorporates:
           *  Constant: '<S307>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S307>/Switch2' */

          /* DotProduct: '<S307>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S307>/Acos' incorporates:
           *  DotProduct: '<S307>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S307>/Multiply' incorporates:
           *  Trigonometry: '<S307>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S306>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S306>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S271>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S271>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S271>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S306>/Divide' incorporates:
           *  Constant: '<S297>/L1'
           *  Gain: '<S306>/Gain'
           *  Math: '<S306>/Square'
           *  Product: '<S306>/Multiply1'
           *  Trigonometry: '<S306>/Sin'
           */
          rtb_u_b = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F * arm_sin_f32
            (rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S297>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S297>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S292>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S294>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S292>/Sum2'
           *  Sum: '<S294>/Add'
           *  Sum: '<S294>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S292>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S271>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S292>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S128>/Hold' incorporates:
             *  ActionPort: '<S269>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S128>/Switch Case' incorporates:
             *  Delay: '<S274>/Delay'
             *  Delay: '<S279>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S128>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S128>/Hold' incorporates:
           *  ActionPort: '<S269>/Action Port'
           */
          /* Math: '<S286>/Math Function1'
           *
           * About '<S286>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S286>/Math Function1' */

          /* Switch: '<S286>/Switch' incorporates:
           *  Constant: '<S286>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S286>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Saturation_ga > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_TmpSignalConversionAtMultip[0] = FMS_U.INS_Out.vn;
            rtb_TmpSignalConversionAtMultip[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S286>/Switch' */

          /* Delay: '<S279>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S291>/Sum of Elements' incorporates:
           *  Delay: '<S279>/start_vel'
           *  Math: '<S291>/Math Function'
           */
          rtb_u_b = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

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
           *  Delay: '<S279>/start_vel'
           *  Product: '<S291>/Product'
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

          /* End of Switch: '<S291>/Switch' */

          /* Product: '<S286>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S289>/Sum of Elements' incorporates:
           *  Math: '<S289>/Math Function'
           *  SignalConversion: '<S289>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S289>/Math Function1' incorporates:
           *  Sum: '<S289>/Sum of Elements'
           *
           * About '<S289>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S289>/Math Function1' */

          /* Switch: '<S289>/Switch' incorporates:
           *  Constant: '<S289>/Constant'
           *  Product: '<S289>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Divide_f0[1];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Divide_f0[0];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S289>/Switch' */

          /* MinMax: '<S277>/Max' incorporates:
           *  Constant: '<S275>/L1'
           *  Constant: '<S275>/R'
           *  Gain: '<S277>/Gain'
           */
          rtb_Saturation_ga = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S277>/SearchL1RefWP' incorporates:
           *  Constant: '<S275>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S282>/TmpSignal ConversionAt SFunction Inport2'
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
            rtb_Add4_a1 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Add4_a1 * rtb_Add4_a1 + rtb_u_b * rtb_u_b);
            rtb_Saturation_o4 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Saturation1_d = ((d * d + rtb_Saturation_o4) - rtb_Saturation_ga
                                 * rtb_Saturation_ga) / (2.0F * d);
            rtb_Square_dv[0] = rtb_u_b / d;
            rtb_Add4_a1 /= d;
            rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d;
            if (rtb_u_b > rtb_Saturation_o4) {
              rtb_n = 0;
            } else if (rtb_u_b == rtb_Saturation_o4) {
              rtb_n = 1;
              rtb_P_ap[0] = rtb_Saturation1_d * rtb_Square_dv[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_ap[1] = rtb_Saturation1_d * rtb_Add4_a1 + FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation_o4 = sqrtf(rtb_Saturation_o4 - rtb_u_b);
              rtb_P_ap[0] = (rtb_Saturation1_d * rtb_Square_dv[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation_o4 *
                -rtb_Add4_a1;
              rtb_P_ap[1] = (rtb_Saturation1_d * rtb_Add4_a1 + FMS_U.INS_Out.y_R)
                + rtb_Saturation_o4 * rtb_Square_dv[0];
            }
          }

          /* End of MATLAB Function: '<S277>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S280>/Compare' incorporates:
           *  Constant: '<S280>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S277>/OutRegionRegWP' incorporates:
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

          /* Switch: '<S277>/Switch' incorporates:
           *  Constant: '<S275>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S277>/OutRegionRegWP'
           *  Product: '<S291>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_d = rtb_P_ap[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S277>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S278>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_dv[0] = rtb_Saturation1_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S277>/Switch' incorporates:
           *  Constant: '<S275>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S277>/OutRegionRegWP'
           *  Product: '<S291>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_d = rtb_P_ap[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S277>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S278>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_dv[1] = rtb_Saturation1_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S287>/Sum of Elements' incorporates:
           *  Math: '<S287>/Math Function'
           */
          rtb_u_b = rtb_Square_dv[0] * rtb_Square_dv[0] + rtb_Square_dv[1] *
            rtb_Square_dv[1];

          /* Math: '<S287>/Math Function1' incorporates:
           *  Sum: '<S287>/Sum of Elements'
           *
           * About '<S287>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S287>/Math Function1' */

          /* Switch: '<S287>/Switch' incorporates:
           *  Constant: '<S287>/Constant'
           *  Product: '<S287>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_ov[0] = rtb_Square_dv[0];
            rtb_Switch_ov[1] = rtb_Square_dv[1];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S287>/Switch' */

          /* Product: '<S287>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_f0[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S290>/Sum of Elements' incorporates:
           *  Math: '<S290>/Math Function'
           *  SignalConversion: '<S290>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S290>/Math Function1' incorporates:
           *  Sum: '<S290>/Sum of Elements'
           *
           * About '<S290>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S290>/Math Function1' */

          /* Switch: '<S290>/Switch' incorporates:
           *  Constant: '<S290>/Constant'
           *  Product: '<S290>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Switch_ov[0] = rtb_Divide_f0[1];
            rtb_Switch_ov[1] = rtb_Divide_f0[0];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S290>/Switch' */

          /* Product: '<S290>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S289>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S290>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S289>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S288>/Subtract' incorporates:
           *  Product: '<S288>/Multiply'
           *  Product: '<S288>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Divide_f0[0] * rtb_Subtract_hb[1] -
            rtb_Divide_f0[1] * rtb_Subtract_hb[0];

          /* Signum: '<S284>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S284>/Sign1' */

          /* Switch: '<S284>/Switch2' incorporates:
           *  Constant: '<S284>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S284>/Switch2' */

          /* DotProduct: '<S284>/Dot Product' */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[0] +
            rtb_Subtract_hb[1] * rtb_Divide_f0[1];

          /* Trigonometry: '<S284>/Acos' incorporates:
           *  DotProduct: '<S284>/Dot Product'
           */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < -1.0F) {
              rtb_Saturation_o4 = -1.0F;
            }
          }

          /* Product: '<S284>/Multiply' incorporates:
           *  Trigonometry: '<S284>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation_o4);

          /* Saturate: '<S283>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S283>/Saturation' */

          /* Delay: '<S274>/Delay' incorporates:
           *  Gain: '<S276>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S269>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S269>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S269>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S269>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S283>/Divide' incorporates:
           *  Constant: '<S275>/L1'
           *  Gain: '<S283>/Gain'
           *  Math: '<S283>/Square'
           *  Product: '<S283>/Multiply1'
           *  Trigonometry: '<S283>/Sin'
           */
          rtb_u_b = 2.0F * (rtb_Saturation1_p5 * rtb_Saturation1_p5) *
            arm_sin_f32(rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S275>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S269>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S269>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S269>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S275>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S274>/Gain2' incorporates:
           *  Delay: '<S274>/Delay'
           *  Gain: '<S276>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S274>/Sum'
           */
          rtb_u_b = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S274>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S269>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S269>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S269>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S274>/Saturation1' */

          /* Update for Delay: '<S279>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S274>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S128>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S128>/Unknown' incorporates:
           *  ActionPort: '<S273>/Action Port'
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
        /* SwitchCase: '<S126>/Switch Case' incorporates:
         *  RelationalOperator: '<S240>/FixPt Relational Operator'
         *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S240>/Delay Input1'
         *
         * Block description for '<S240>/Delay Input1':
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
          /* Outputs for IfAction SubSystem: '<S126>/Offboard' incorporates:
           *  ActionPort: '<S238>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S238>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S238>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S238>/Bus Assignment' incorporates:
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
             *  ActionPort: '<S237>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S126>/Switch Case' incorporates:
             *  UnitDelay: '<S240>/Delay Input1'
             *
             * Block description for '<S240>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S126>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
           *  ActionPort: '<S237>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S237>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S241>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S260>/Math Function' incorporates:
           *  RelationalOperator: '<S240>/FixPt Relational Operator'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S240>/Delay Input1'
           *
           * Block description for '<S240>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Add4_a1;

          /* Sum: '<S260>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_a1;

          /* Math: '<S260>/Math Function1' incorporates:
           *  Sum: '<S260>/Sum of Elements'
           *
           * About '<S260>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S260>/Math Function1' */

          /* Switch: '<S260>/Switch' incorporates:
           *  Constant: '<S260>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S260>/Product'
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

          /* End of Switch: '<S260>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S250>/NearbyRefWP' incorporates:
           *  Constant: '<S248>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S250>/SearchL1RefWP' incorporates:
           *  Constant: '<S248>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_f0, &rtb_Saturation1_d);

          /* MATLAB Function: '<S250>/OutRegionRegWP' incorporates:
           *  Constant: '<S248>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0],
                             &rtb_TmpSignalConversionAtMultip[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S250>/Switch1' incorporates:
           *  Constant: '<S253>/Constant'
           *  RelationalOperator: '<S253>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_f0[0] = rtb_Subtract_hb[0];
            rtb_Divide_f0[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S252>/Compare' incorporates:
             *  Constant: '<S252>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S250>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S250>/Switch' */
          }

          /* End of Switch: '<S250>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S251>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S261>/Sum of Elements' incorporates:
           *  Math: '<S261>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S261>/Math Function1' incorporates:
           *  Sum: '<S261>/Sum of Elements'
           *
           * About '<S261>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S261>/Math Function1' */

          /* Switch: '<S261>/Switch' incorporates:
           *  Constant: '<S261>/Constant'
           *  Product: '<S261>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Subtract_hb[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract_hb[1];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S261>/Switch' */

          /* Product: '<S260>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S263>/Sum of Elements' incorporates:
           *  Math: '<S263>/Math Function'
           *  SignalConversion: '<S263>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S263>/Math Function1' incorporates:
           *  Sum: '<S263>/Sum of Elements'
           *
           * About '<S263>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S263>/Math Function1' */

          /* Switch: '<S263>/Switch' incorporates:
           *  Constant: '<S263>/Constant'
           *  Product: '<S263>/Product'
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

          /* End of Switch: '<S263>/Switch' */

          /* Product: '<S261>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S264>/Sum of Elements' incorporates:
           *  Math: '<S264>/Math Function'
           *  SignalConversion: '<S264>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

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
           *  Product: '<S264>/Product'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Subtract_hb[1];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract_hb[0];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S264>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S245>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S264>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S263>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S245>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_a1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S264>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S263>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S245>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S245>/Divide' incorporates:
           *  Math: '<S246>/Square'
           *  Math: '<S247>/Square'
           *  Sqrt: '<S246>/Sqrt'
           *  Sqrt: '<S247>/Sqrt'
           *  Sum: '<S245>/Sum'
           *  Sum: '<S245>/Sum1'
           *  Sum: '<S246>/Sum of Elements'
           *  Sum: '<S247>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_bx * rtb_a_bx + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Add4_a1 * rtb_Add4_a1 + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S245>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S245>/Saturation' */

          /* Sum: '<S262>/Subtract' incorporates:
           *  Product: '<S262>/Multiply'
           *  Product: '<S262>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S258>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S258>/Sign1' */

          /* Switch: '<S258>/Switch2' incorporates:
           *  Constant: '<S258>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S258>/Switch2' */

          /* DotProduct: '<S258>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S258>/Acos' incorporates:
           *  DotProduct: '<S258>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S258>/Multiply' incorporates:
           *  Trigonometry: '<S258>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S257>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S257>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S241>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S241>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S241>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S243>/Switch' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
          } else {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Constant: '<S243>/Constant4'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S243>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S257>/Divide' incorporates:
           *  Constant: '<S248>/L1'
           *  Gain: '<S257>/Gain'
           *  Math: '<S257>/Square'
           *  Product: '<S257>/Multiply1'
           *  Trigonometry: '<S257>/Sin'
           */
          rtb_u_b = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F * arm_sin_f32
            (rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S248>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S248>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S242>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S245>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S242>/Sum2'
           *  Sum: '<S245>/Add'
           *  Sum: '<S245>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S242>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S241>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S242>/Saturation1' */
          /* End of Outputs for SubSystem: '<S237>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S240>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S240>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S126>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S126>/Unknown' incorporates:
           *  ActionPort: '<S239>/Action Port'
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
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S175>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S161>/Switch Case' */
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
             *  DiscreteIntegrator: '<S230>/Integrator'
             *  DiscreteIntegrator: '<S230>/Integrator1'
             *  DiscreteIntegrator: '<S231>/Integrator'
             *  DiscreteIntegrator: '<S231>/Integrator1'
             *  DiscreteIntegrator: '<S235>/Integrator'
             *  DiscreteIntegrator: '<S235>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_av = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Stabilize' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          /* Product: '<S232>/Multiply1' incorporates:
           *  Constant: '<S232>/const1'
           *  DiscreteIntegrator: '<S230>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S228>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S228>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S232>/Add' incorporates:
           *  DiscreteIntegrator: '<S230>/Integrator1'
           *  Gain: '<S225>/Gain'
           *  Gain: '<S228>/Gain'
           *  Sum: '<S230>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) + rtb_a_bx;

          /* Signum: '<S232>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S232>/Sign' */

          /* Sum: '<S232>/Add2' incorporates:
           *  Abs: '<S232>/Abs'
           *  Gain: '<S232>/Gain'
           *  Gain: '<S232>/Gain1'
           *  Product: '<S232>/Multiply2'
           *  Product: '<S232>/Multiply3'
           *  Sqrt: '<S232>/Sqrt'
           *  Sum: '<S232>/Add1'
           *  Sum: '<S232>/Subtract'
           */
          rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_ga + rtb_a_bx;

          /* Sum: '<S232>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Integrator1_bx) +
            rtb_a_bx;

          /* Sum: '<S232>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S232>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

          /* Signum: '<S232>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign1' */

          /* Signum: '<S232>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign2' */

          /* Sum: '<S232>/Add5' incorporates:
           *  Gain: '<S232>/Gain2'
           *  Product: '<S232>/Multiply4'
           *  Sum: '<S232>/Subtract2'
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
           *  DiscreteIntegrator: '<S230>/Integrator1'
           *  DiscreteIntegrator: '<S231>/Integrator1'
           *  DiscreteIntegrator: '<S235>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S227>/Saturation' incorporates:
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

          /* End of Saturate: '<S227>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S132>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S227>/Constant5'
           *  Gain: '<S227>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S227>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_u_b), 65536.0F) + 1000U);

          /* Product: '<S236>/Multiply1' incorporates:
           *  Constant: '<S236>/const1'
           *  DiscreteIntegrator: '<S235>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S234>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S234>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S236>/Add' incorporates:
           *  DiscreteIntegrator: '<S235>/Integrator1'
           *  Gain: '<S226>/Gain1'
           *  Gain: '<S234>/Gain'
           *  Sum: '<S235>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_bx;

          /* Signum: '<S236>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Add4_a1 = rtb_u_b;
          }

          /* End of Signum: '<S236>/Sign' */

          /* Sum: '<S236>/Add2' incorporates:
           *  Abs: '<S236>/Abs'
           *  Gain: '<S236>/Gain'
           *  Gain: '<S236>/Gain1'
           *  Product: '<S236>/Multiply2'
           *  Product: '<S236>/Multiply3'
           *  Sqrt: '<S236>/Sqrt'
           *  Sum: '<S236>/Add1'
           *  Sum: '<S236>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_h) *
            FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F * rtb_Add4_a1 + rtb_a_bx;

          /* Sum: '<S236>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Saturation1_p5) + rtb_a_bx;

          /* Sum: '<S236>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_h;

          /* Sum: '<S236>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_h;

          /* Signum: '<S236>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign1' */

          /* Signum: '<S236>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign2' */

          /* Sum: '<S236>/Add5' incorporates:
           *  Gain: '<S236>/Gain2'
           *  Product: '<S236>/Multiply4'
           *  Sum: '<S236>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S236>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_h;

          /* Sum: '<S236>/Subtract3' */
          rtb_Saturation1_d = rtb_Saturation1_p5 - FMS_ConstB.d_h;

          /* Product: '<S236>/Divide' */
          rtb_P_f_idx_0 = rtb_Saturation1_p5 / FMS_ConstB.d_h;

          /* Signum: '<S236>/Sign5' incorporates:
           *  Signum: '<S236>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S236>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S236>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Saturation1_p5;

            /* Signum: '<S236>/Sign6' */
            rtb_Saturation_o4 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S236>/Sign5' */

          /* Product: '<S233>/Multiply1' incorporates:
           *  Constant: '<S233>/const1'
           *  DiscreteIntegrator: '<S231>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S229>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S229>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S233>/Add' incorporates:
           *  DiscreteIntegrator: '<S231>/Integrator1'
           *  Gain: '<S225>/Gain1'
           *  Gain: '<S229>/Gain'
           *  Sum: '<S231>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S233>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Add4_a1 = rtb_u_b;
          }

          /* End of Signum: '<S233>/Sign' */

          /* Sum: '<S233>/Add2' incorporates:
           *  Abs: '<S233>/Abs'
           *  Gain: '<S233>/Gain'
           *  Gain: '<S233>/Gain1'
           *  Product: '<S233>/Multiply2'
           *  Product: '<S233>/Multiply3'
           *  Sqrt: '<S233>/Sqrt'
           *  Sum: '<S233>/Add1'
           *  Sum: '<S233>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_my) *
                            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Add4_a1 + rtb_Saturation1_p5;

          /* Sum: '<S233>/Add4' */
          rtb_Add4_a1 = (rtb_u_b - rtb_a_bx) + rtb_Saturation1_p5;

          /* Sum: '<S233>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_my;

          /* Sum: '<S233>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_my;

          /* Signum: '<S233>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S233>/Sign1' */

          /* Signum: '<S233>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S233>/Sign2' */

          /* Sum: '<S233>/Add5' incorporates:
           *  Gain: '<S233>/Gain2'
           *  Product: '<S233>/Multiply4'
           *  Sum: '<S233>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Add4_a1;

          /* Update for DiscreteIntegrator: '<S230>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S230>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S232>/Subtract3' */
          rtb_Saturation1_p5 = rtb_Integrator1_bx - FMS_ConstB.d_ny;

          /* Sum: '<S232>/Add6' */
          d = rtb_Integrator1_bx + FMS_ConstB.d_ny;

          /* Signum: '<S232>/Sign5' incorporates:
           *  Signum: '<S232>/Sign6'
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Add4_a1 = -1.0F;

            /* Signum: '<S232>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (rtb_Integrator1_bx > 0.0F) {
            rtb_Add4_a1 = 1.0F;

            /* Signum: '<S232>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Add4_a1 = rtb_Integrator1_bx;

            /* Signum: '<S232>/Sign6' */
            rtb_u_b = rtb_Integrator1_bx;
          }

          /* End of Signum: '<S232>/Sign5' */

          /* Signum: '<S232>/Sign3' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign3' */

          /* Signum: '<S232>/Sign4' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign4' */

          /* Update for DiscreteIntegrator: '<S230>/Integrator' incorporates:
           *  Constant: '<S232>/const'
           *  Gain: '<S232>/Gain3'
           *  Product: '<S232>/Divide'
           *  Product: '<S232>/Multiply5'
           *  Product: '<S232>/Multiply6'
           *  Sum: '<S232>/Subtract4'
           *  Sum: '<S232>/Subtract5'
           *  Sum: '<S232>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((rtb_Integrator1_bx / FMS_ConstB.d_ny
            - rtb_Add4_a1) * FMS_ConstB.Gain4_ko * ((d - rtb_Saturation1_p5) *
            0.5F) - rtb_u_b * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S231>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S231>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S235>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S235>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S236>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign3' */

          /* Signum: '<S236>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign4' */

          /* Update for DiscreteIntegrator: '<S235>/Integrator' incorporates:
           *  Constant: '<S236>/const'
           *  Gain: '<S236>/Gain3'
           *  Product: '<S236>/Multiply5'
           *  Product: '<S236>/Multiply6'
           *  Sum: '<S236>/Subtract4'
           *  Sum: '<S236>/Subtract5'
           *  Sum: '<S236>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_P_f_idx_0 - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 15.707963F) * 0.004F;

          /* Sum: '<S233>/Subtract3' */
          rtb_Saturation_ga = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S233>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S233>/Sign5' incorporates:
           *  Signum: '<S233>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S233>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S233>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_a_bx;

            /* Signum: '<S233>/Sign6' */
            rtb_Add4_a1 = rtb_a_bx;
          }

          /* End of Signum: '<S233>/Sign5' */

          /* Signum: '<S233>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S233>/Sign3' */

          /* Signum: '<S233>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S233>/Sign4' */

          /* Update for DiscreteIntegrator: '<S231>/Integrator' incorporates:
           *  Constant: '<S233>/const'
           *  Gain: '<S233>/Gain3'
           *  Product: '<S233>/Divide'
           *  Product: '<S233>/Multiply5'
           *  Product: '<S233>/Multiply6'
           *  Sum: '<S233>/Subtract4'
           *  Sum: '<S233>/Subtract5'
           *  Sum: '<S233>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_bx / FMS_ConstB.d_my -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_k2 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S125>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S125>/Altitude' incorporates:
             *  ActionPort: '<S130>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S125>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S150>/Integrator'
             *  DiscreteIntegrator: '<S150>/Integrator1'
             *  DiscreteIntegrator: '<S153>/Integrator'
             *  DiscreteIntegrator: '<S153>/Integrator1'
             *  DiscreteIntegrator: '<S155>/Integrator'
             *  DiscreteIntegrator: '<S155>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator1_DSTATE_mg = 0.0F;
            FMS_DW.Integrator_DSTATE_lc = 0.0F;
            FMS_DW.Integrator_DSTATE_ex = 0.0F;

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
           *  Constant: '<S147>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S147>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S138>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S138>/Hold Control' incorporates:
               *  ActionPort: '<S141>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S138>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S138>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S138>/Hold Control' incorporates:
             *  ActionPort: '<S141>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S138>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S138>/Brake Control' incorporates:
             *  ActionPort: '<S140>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S138>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S138>/Move Control' incorporates:
               *  ActionPort: '<S142>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S138>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S138>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S138>/Move Control' incorporates:
             *  ActionPort: '<S142>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S138>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S138>/Switch Case' */

          /* Product: '<S151>/Multiply1' incorporates:
           *  Constant: '<S151>/const1'
           *  DiscreteIntegrator: '<S150>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S149>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S149>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S151>/Add' incorporates:
           *  DiscreteIntegrator: '<S150>/Integrator1'
           *  Gain: '<S135>/Gain'
           *  Gain: '<S149>/Gain'
           *  Sum: '<S150>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Saturation_ga;

          /* Signum: '<S151>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
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
          rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_bi) * FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S151>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Integrator1_bx) +
            rtb_Saturation_ga;

          /* Sum: '<S151>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_bi;

          /* Sum: '<S151>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_bi;

          /* Signum: '<S151>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign1' */

          /* Signum: '<S151>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign2' */

          /* Sum: '<S151>/Add5' incorporates:
           *  Gain: '<S151>/Gain2'
           *  Product: '<S151>/Multiply4'
           *  Sum: '<S151>/Subtract2'
           */
          rtb_Integrator1_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S151>/Add6' */
          rtb_Saturation_ga = rtb_Integrator1_bx + FMS_ConstB.d_bi;

          /* Sum: '<S151>/Subtract3' */
          rtb_Saturation1_d = rtb_Integrator1_bx - FMS_ConstB.d_bi;

          /* Product: '<S151>/Divide' */
          rtb_a_bx = rtb_Integrator1_bx / FMS_ConstB.d_bi;

          /* Signum: '<S151>/Sign5' incorporates:
           *  Signum: '<S151>/Sign6'
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;

            /* Signum: '<S151>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Integrator1_bx > 0.0F) {
            rtb_P_f_idx_0 = 1.0F;

            /* Signum: '<S151>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_P_f_idx_0 = rtb_Integrator1_bx;

            /* Signum: '<S151>/Sign6' */
            rtb_Saturation_o4 = rtb_Integrator1_bx;
          }

          /* End of Signum: '<S151>/Sign5' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S130>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S130>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S130>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S150>/Integrator1'
           *  DiscreteIntegrator: '<S153>/Integrator1'
           *  DiscreteIntegrator: '<S155>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;
          FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_mg;

          /* Saturate: '<S138>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S138>/Saturation1' */

          /* Product: '<S156>/Multiply1' incorporates:
           *  Constant: '<S156>/const1'
           *  DiscreteIntegrator: '<S155>/Integrator'
           */
          rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_lc * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S137>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_u_b = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.3F) {
            rtb_u_b = 0.3F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S137>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S156>/Add' incorporates:
           *  DiscreteIntegrator: '<S155>/Integrator1'
           *  Gain: '<S137>/Gain'
           *  Sum: '<S155>/Subtract'
           */
          rtb_Sign5_mn = (FMS_DW.Integrator1_DSTATE_mg - FMS_PARAM.FW_SPEED_MAX *
                          rtb_u_b) + rtb_Integrator1_bx;

          /* Signum: '<S156>/Sign' */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_u_b = -1.0F;
          } else if (rtb_Sign5_mn > 0.0F) {
            rtb_u_b = 1.0F;
          } else {
            rtb_u_b = rtb_Sign5_mn;
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
          rtb_Subtract3_g = (sqrtf((8.0F * fabsf(rtb_Sign5_mn) + FMS_ConstB.d_d)
            * FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F * rtb_u_b +
            rtb_Integrator1_bx;

          /* Sum: '<S156>/Add4' */
          rtb_u_b = (rtb_Sign5_mn - rtb_Subtract3_g) + rtb_Integrator1_bx;

          /* Sum: '<S156>/Add3' */
          rtb_Saturation1_p5 = rtb_Sign5_mn + FMS_ConstB.d_d;

          /* Sum: '<S156>/Subtract1' */
          rtb_Sign5_mn -= FMS_ConstB.d_d;

          /* Signum: '<S156>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign1' */

          /* Signum: '<S156>/Sign2' */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_Sign5_mn = -1.0F;
          } else {
            if (rtb_Sign5_mn > 0.0F) {
              rtb_Sign5_mn = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign2' */

          /* Sum: '<S156>/Add5' incorporates:
           *  Gain: '<S156>/Gain2'
           *  Product: '<S156>/Multiply4'
           *  Sum: '<S156>/Subtract2'
           */
          rtb_Subtract3_g += (rtb_Saturation1_p5 - rtb_Sign5_mn) * 0.5F *
            rtb_u_b;

          /* Sum: '<S156>/Add6' */
          rtb_Saturation1_p5 = rtb_Subtract3_g + FMS_ConstB.d_d;

          /* Sum: '<S156>/Subtract3' */
          d = rtb_Subtract3_g - FMS_ConstB.d_d;

          /* Product: '<S156>/Divide' */
          rtb_Divide_jb = rtb_Subtract3_g / FMS_ConstB.d_d;

          /* Signum: '<S156>/Sign5' incorporates:
           *  Signum: '<S156>/Sign6'
           */
          if (rtb_Subtract3_g < 0.0F) {
            rtb_Sign5_dc = -1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_Subtract3_g > 0.0F) {
            rtb_Sign5_dc = 1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Sign5_dc = rtb_Subtract3_g;

            /* Signum: '<S156>/Sign6' */
            rtb_Add4_a1 = rtb_Subtract3_g;
          }

          /* End of Signum: '<S156>/Sign5' */

          /* Product: '<S154>/Multiply1' incorporates:
           *  Constant: '<S154>/const1'
           *  DiscreteIntegrator: '<S153>/Integrator'
           */
          rtb_Subtract3_g = FMS_DW.Integrator_DSTATE_ex * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S152>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S152>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S154>/Add' incorporates:
           *  DiscreteIntegrator: '<S153>/Integrator1'
           *  Gain: '<S136>/Gain1'
           *  Gain: '<S152>/Gain'
           *  Sum: '<S153>/Subtract'
           */
          rtb_Sign5_mn = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Subtract3_g;

          /* Signum: '<S154>/Sign' */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_u_b = -1.0F;
          } else if (rtb_Sign5_mn > 0.0F) {
            rtb_u_b = 1.0F;
          } else {
            rtb_u_b = rtb_Sign5_mn;
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
          rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Sign5_mn) +
            FMS_ConstB.d_nt) * FMS_ConstB.d_nt) - FMS_ConstB.d_nt) * 0.5F *
            rtb_u_b + rtb_Subtract3_g;

          /* Sum: '<S154>/Add4' */
          rtb_Subtract3_g += rtb_Sign5_mn - rtb_Integrator1_bx;

          /* Sum: '<S154>/Add3' */
          rtb_u_b = rtb_Sign5_mn + FMS_ConstB.d_nt;

          /* Sum: '<S154>/Subtract1' */
          rtb_Sign5_mn -= FMS_ConstB.d_nt;

          /* Signum: '<S154>/Sign1' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign1' */

          /* Signum: '<S154>/Sign2' */
          if (rtb_Sign5_mn < 0.0F) {
            rtb_Sign5_mn = -1.0F;
          } else {
            if (rtb_Sign5_mn > 0.0F) {
              rtb_Sign5_mn = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign2' */

          /* Sum: '<S154>/Add5' incorporates:
           *  Gain: '<S154>/Gain2'
           *  Product: '<S154>/Multiply4'
           *  Sum: '<S154>/Subtract2'
           */
          rtb_Integrator1_bx += (rtb_u_b - rtb_Sign5_mn) * 0.5F *
            rtb_Subtract3_g;

          /* Update for DiscreteIntegrator: '<S150>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S150>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Signum: '<S151>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign3' */

          /* Signum: '<S151>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S151>/Sign4' */

          /* Update for DiscreteIntegrator: '<S150>/Integrator' incorporates:
           *  Constant: '<S151>/const'
           *  Gain: '<S151>/Gain3'
           *  Product: '<S151>/Multiply5'
           *  Product: '<S151>/Multiply6'
           *  Sum: '<S151>/Subtract4'
           *  Sum: '<S151>/Subtract5'
           *  Sum: '<S151>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_a_bx - rtb_P_f_idx_0) *
            FMS_ConstB.Gain4_d1 * ((rtb_Saturation_ga - rtb_Saturation1_d) *
            0.5F) - rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S153>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S153>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_ex;

          /* Update for DiscreteIntegrator: '<S155>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S155>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mg += 0.004F * FMS_DW.Integrator_DSTATE_lc;

          /* Signum: '<S156>/Sign3' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign3' */

          /* Signum: '<S156>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
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
          FMS_DW.Integrator_DSTATE_lc += ((rtb_Divide_jb - rtb_Sign5_dc) *
            FMS_ConstB.Gain4_p2 * ((rtb_Saturation1_p5 - d) * 0.5F) -
            rtb_Add4_a1 * 78.448F) * 0.004F;

          /* Sum: '<S154>/Subtract3' */
          rtb_Saturation_ga = rtb_Integrator1_bx - FMS_ConstB.d_nt;

          /* Sum: '<S154>/Add6' */
          rtb_Saturation1_d = rtb_Integrator1_bx + FMS_ConstB.d_nt;

          /* Signum: '<S154>/Sign5' incorporates:
           *  Signum: '<S154>/Sign6'
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S154>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_Integrator1_bx > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S154>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Integrator1_bx;

            /* Signum: '<S154>/Sign6' */
            rtb_Add4_a1 = rtb_Integrator1_bx;
          }

          /* End of Signum: '<S154>/Sign5' */

          /* Signum: '<S154>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign3' */

          /* Signum: '<S154>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S154>/Sign4' */

          /* Update for DiscreteIntegrator: '<S153>/Integrator' incorporates:
           *  Constant: '<S154>/const'
           *  Gain: '<S154>/Gain3'
           *  Product: '<S154>/Divide'
           *  Product: '<S154>/Multiply5'
           *  Product: '<S154>/Multiply6'
           *  Sum: '<S154>/Subtract4'
           *  Sum: '<S154>/Subtract5'
           *  Sum: '<S154>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ex += ((rtb_Integrator1_bx / FMS_ConstB.d_nt
            - rtb_Saturation_o4) * FMS_ConstB.Gain4_kf * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S125>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S125>/Position' incorporates:
             *  ActionPort: '<S131>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S125>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S173>/Integrator'
             *  DiscreteIntegrator: '<S173>/Integrator1'
             *  DiscreteIntegrator: '<S223>/Integrator'
             *  DiscreteIntegrator: '<S223>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_nd = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Position' */

            /* SystemReset for IfAction SubSystem: '<S125>/Position' incorporates:
             *  ActionPort: '<S131>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S125>/Switch Case' incorporates:
             *  Chart: '<S162>/Motion Status'
             *  Chart: '<S176>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState);

            /* End of SystemReset for SubSystem: '<S125>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Position' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          /* Trigonometry: '<S221>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S221>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S221>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S221>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S221>/Gain' incorporates:
           *  Gain: '<S220>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S221>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S221>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S221>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S221>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S221>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S162>/Motion Status' incorporates:
           *  Abs: '<S162>/Abs'
           *  Abs: '<S162>/Abs1'
           *  Constant: '<S170>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S170>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S176>/Multiply' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 6]
              * FMS_U.INS_Out.vd + (rtb_VectorConcatenate[rtb_n + 3] *
              FMS_U.INS_Out.ve + rtb_VectorConcatenate[rtb_n] * FMS_U.INS_Out.vn);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of Product: '<S176>/Multiply' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S176>/Motion State' incorporates:
           *  Abs: '<S176>/Abs'
           *  Abs: '<S176>/Abs1'
           *  Abs: '<S176>/Abs2'
           *  Constant: '<S217>/Constant'
           *  Constant: '<S218>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Logic: '<S176>/Logical Operator'
           *  RelationalOperator: '<S217>/Compare'
           *  RelationalOperator: '<S218>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ)
                          || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
                              FMS_PARAM.YAW_DZ), fabsf
                          (rtb_MatrixConcatenate1_a_0[0]), &rtb_state_fg,
                          &FMS_DW.sf_MotionState);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S175>/Switch Case' incorporates:
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
            FMS_DW.SwitchCase_ActiveSubsystem_d = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_d = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_d) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S175>/Hold Control' incorporates:
               *  ActionPort: '<S178>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S175>/Switch Case' */
              FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_b,
                &FMS_DW.HoldControl_b);

              /* End of SystemReset for SubSystem: '<S175>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S175>/Hold Control' incorporates:
             *  ActionPort: '<S178>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_b(rtb_Divide_bu, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                              FMS_U.INS_Out.vd, FMS_U.INS_Out.psi,
                              FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              &FMS_B.Merge_be, &FMS_ConstB.HoldControl_b,
                              &FMS_DW.HoldControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S175>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S175>/Brake Control' incorporates:
             *  ActionPort: '<S177>/Action Port'
             */
            FMS_BrakeControl_h(&FMS_B.Merge_be);

            /* End of Outputs for SubSystem: '<S175>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S175>/Move Control' incorporates:
             *  ActionPort: '<S179>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S214>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S214>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S179>/Gain6' incorporates:
             *  Gain: '<S214>/Gain'
             */
            FMS_B.Merge_be = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
              FMS_PARAM.FW_ACC_Y_LIM;

            /* End of Outputs for SubSystem: '<S175>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S175>/Switch Case' */

          /* SwitchCase: '<S161>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S161>/Hold Control' incorporates:
               *  ActionPort: '<S164>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S161>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S161>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S161>/Hold Control' incorporates:
             *  ActionPort: '<S164>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S161>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S161>/Brake Control' incorporates:
             *  ActionPort: '<S163>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_fb);

            /* End of Outputs for SubSystem: '<S161>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S161>/Move Control' incorporates:
               *  ActionPort: '<S165>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S161>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S161>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S161>/Move Control' incorporates:
             *  ActionPort: '<S165>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S161>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S161>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S131>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S131>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S173>/Integrator1'
           *  DiscreteIntegrator: '<S223>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l5;
          FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_nd;

          /* Saturate: '<S175>/Saturation1' */
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

          /* End of Saturate: '<S175>/Saturation1' */

          /* Saturate: '<S161>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S161>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S160>/Saturation' incorporates:
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

          /* End of Saturate: '<S160>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S224>/Multiply1' incorporates:
           *  Constant: '<S224>/const1'
           *  DiscreteIntegrator: '<S223>/Integrator'
           */
          rtb_u_b = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Switch: '<S222>/Switch' incorporates:
           *  Constant: '<S222>/Constant'
           *  Constant: '<S222>/Constant1'
           *  Constant: '<S222>/Constant2'
           *  Product: '<S222>/Multiply'
           *  Product: '<S222>/Multiply1'
           *  Sum: '<S222>/Subtract'
           *  Sum: '<S222>/Subtract1'
           *  Sum: '<S222>/Sum'
           *  Sum: '<S222>/Sum1'
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

          /* End of Switch: '<S222>/Switch' */

          /* Sum: '<S224>/Add' incorporates:
           *  DiscreteIntegrator: '<S223>/Integrator1'
           *  Sum: '<S223>/Subtract'
           */
          d = (FMS_DW.Integrator1_DSTATE_nd - rtb_Saturation_ga) + rtb_u_b;

          /* Signum: '<S224>/Sign' */
          if (d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = d;
          }

          /* End of Signum: '<S224>/Sign' */

          /* Sum: '<S224>/Add2' incorporates:
           *  Abs: '<S224>/Abs'
           *  Gain: '<S224>/Gain'
           *  Gain: '<S224>/Gain1'
           *  Product: '<S224>/Multiply2'
           *  Product: '<S224>/Multiply3'
           *  Sqrt: '<S224>/Sqrt'
           *  Sum: '<S224>/Add1'
           *  Sum: '<S224>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(d) + FMS_ConstB.d_ad) *
            FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F * rtb_Saturation_ga +
            rtb_u_b;

          /* Sum: '<S224>/Add4' */
          rtb_Saturation1_d = (d - rtb_Saturation1_p5) + rtb_u_b;

          /* Sum: '<S224>/Add3' */
          rtb_Saturation_ga = d + FMS_ConstB.d_ad;

          /* Sum: '<S224>/Subtract1' */
          d -= FMS_ConstB.d_ad;

          /* Signum: '<S224>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S224>/Sign1' */

          /* Signum: '<S224>/Sign2' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S224>/Sign2' */

          /* Sum: '<S224>/Add5' incorporates:
           *  Gain: '<S224>/Gain2'
           *  Product: '<S224>/Multiply4'
           *  Sum: '<S224>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - d) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S224>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_ad;

          /* Sum: '<S224>/Subtract3' */
          rtb_Saturation1_d = rtb_Saturation1_p5 - FMS_ConstB.d_ad;

          /* Product: '<S224>/Divide' */
          rtb_Add4_a1 = rtb_Saturation1_p5 / FMS_ConstB.d_ad;

          /* Signum: '<S224>/Sign5' incorporates:
           *  Signum: '<S224>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S224>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S224>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = rtb_Saturation1_p5;

            /* Signum: '<S224>/Sign6' */
            rtb_Saturation_o4 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S224>/Sign5' */

          /* Product: '<S174>/Multiply1' incorporates:
           *  Constant: '<S174>/const1'
           *  DiscreteIntegrator: '<S173>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S172>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S172>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S174>/Add' incorporates:
           *  DiscreteIntegrator: '<S173>/Integrator1'
           *  Gain: '<S158>/Gain1'
           *  Gain: '<S172>/Gain'
           *  Sum: '<S173>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_l5 - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S174>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S174>/Sign' */

          /* Sum: '<S174>/Add2' incorporates:
           *  Abs: '<S174>/Abs'
           *  Gain: '<S174>/Gain'
           *  Gain: '<S174>/Gain1'
           *  Product: '<S174>/Multiply2'
           *  Product: '<S174>/Multiply3'
           *  Sqrt: '<S174>/Sqrt'
           *  Sum: '<S174>/Add1'
           *  Sum: '<S174>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_l) * FMS_ConstB.d_l)
               - FMS_ConstB.d_l) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S174>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S174>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_l;

          /* Sum: '<S174>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_l;

          /* Signum: '<S174>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S174>/Sign1' */

          /* Signum: '<S174>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S174>/Sign2' */

          /* Sum: '<S174>/Add5' incorporates:
           *  Gain: '<S174>/Gain2'
           *  Product: '<S174>/Multiply4'
           *  Sum: '<S174>/Subtract2'
           */
          d += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S173>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S173>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l5 += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S223>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S223>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S224>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S224>/Sign3' */

          /* Signum: '<S224>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S224>/Sign4' */

          /* Update for DiscreteIntegrator: '<S223>/Integrator' incorporates:
           *  Constant: '<S224>/const'
           *  Gain: '<S224>/Gain3'
           *  Product: '<S224>/Multiply5'
           *  Product: '<S224>/Multiply6'
           *  Sum: '<S224>/Subtract4'
           *  Sum: '<S224>/Subtract5'
           *  Sum: '<S224>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Add4_a1 - rtb_Integrator1_bx) *
            FMS_ConstB.Gain4_f * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 78.448F) * 0.004F;

          /* Sum: '<S174>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_l;

          /* Sum: '<S174>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_l;

          /* Signum: '<S174>/Sign5' incorporates:
           *  Signum: '<S174>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S174>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S174>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S174>/Sign6' */
            rtb_Add4_a1 = d;
          }

          /* End of Signum: '<S174>/Sign5' */

          /* Signum: '<S174>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S174>/Sign3' */

          /* Signum: '<S174>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S174>/Sign4' */

          /* Update for DiscreteIntegrator: '<S173>/Integrator' incorporates:
           *  Constant: '<S174>/const'
           *  Gain: '<S174>/Gain3'
           *  Product: '<S174>/Divide'
           *  Product: '<S174>/Multiply5'
           *  Product: '<S174>/Multiply6'
           *  Sum: '<S174>/Subtract4'
           *  Sum: '<S174>/Subtract5'
           *  Sum: '<S174>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((d / FMS_ConstB.d_l -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ak * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 15.707963F) * 0.004F;

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
        /* DeadZone: '<S265>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S265>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S265>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S266>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S266>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S127>/Gain'
         *  Gain: '<S266>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S267>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S267>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S267>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S268>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S268>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S268>/Gain'
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
      rtb_VectorConcatenate[0] = rtb_Saturation_ga;

      /* Trigonometry: '<S100>/Trigonometric Function' */
      rtb_VectorConcatenate[1] = rtb_Saturation1_d;

      /* SignalConversion: '<S100>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S100>/Constant3'
       */
      rtb_VectorConcatenate[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S100>/Gain' incorporates:
       *  Gain: '<S99>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       *  Trigonometry: '<S100>/Trigonometric Function2'
       */
      rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Trigonometry: '<S100>/Trigonometric Function3' */
      rtb_VectorConcatenate[4] = rtb_Saturation_ga;

      /* SignalConversion: '<S100>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S100>/Constant4'
       */
      rtb_VectorConcatenate[5] = 0.0F;

      /* SignalConversion: '<S100>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_du[0];
      rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_du[1];
      rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_du[2];

      /* Product: '<S55>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
          FMS_U.INS_Out.vd + (rtb_VectorConcatenate[rtb_n + 3] *
                              FMS_U.INS_Out.ve + rtb_VectorConcatenate[rtb_n] *
                              FMS_U.INS_Out.vn);

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
                      fabsf(rtb_MatrixConcatenate1_a_0[0]), &rtb_state_l4,
                      &FMS_DW.sf_MotionState_j);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SwitchCase: '<S54>/Switch Case' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ff;
      FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;
      switch (rtb_state_l4) {
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
        FMS_HoldControl_b(rtb_Divide_bu, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
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
        FMS_BrakeControl_h(&FMS_B.Merge_n);

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
      rtb_a_bx = (FMS_DW.Integrator1_DSTATE_hf - 1.0F / (1.0F - FMS_PARAM.YAW_DZ)
                  * rtb_u_b * (FMS_PARAM.YAW_RATE_LIM / 2.0F)) +
        rtb_Integrator1_bx;

      /* Signum: '<S123>/Sign' */
      if (rtb_a_bx < 0.0F) {
        rtb_u_b = -1.0F;
      } else if (rtb_a_bx > 0.0F) {
        rtb_u_b = 1.0F;
      } else {
        rtb_u_b = rtb_a_bx;
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
      rtb_Subtract3_g = (sqrtf((8.0F * fabsf(rtb_a_bx) + FMS_ConstB.d_j) *
        FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_u_b + rtb_Integrator1_bx;

      /* Sum: '<S123>/Add4' */
      rtb_Saturation1_d = (rtb_a_bx - rtb_Subtract3_g) + rtb_Integrator1_bx;

      /* Sum: '<S123>/Add3' */
      rtb_Saturation_ga = rtb_a_bx + FMS_ConstB.d_j;

      /* Sum: '<S123>/Subtract1' */
      rtb_a_bx -= FMS_ConstB.d_j;

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
      if (rtb_a_bx < 0.0F) {
        rtb_a_bx = -1.0F;
      } else {
        if (rtb_a_bx > 0.0F) {
          rtb_a_bx = 1.0F;
        }
      }

      /* End of Signum: '<S123>/Sign2' */

      /* Sum: '<S123>/Add5' incorporates:
       *  Gain: '<S123>/Gain2'
       *  Product: '<S123>/Multiply4'
       *  Sum: '<S123>/Subtract2'
       */
      rtb_Subtract3_g += (rtb_Saturation_ga - rtb_a_bx) * 0.5F *
        rtb_Saturation1_d;

      /* Sum: '<S123>/Add6' */
      rtb_Saturation_ga = rtb_Subtract3_g + FMS_ConstB.d_j;

      /* Sum: '<S123>/Subtract3' */
      rtb_Saturation1_d = rtb_Subtract3_g - FMS_ConstB.d_j;

      /* Product: '<S123>/Divide' */
      rtb_P_f_idx_0 = rtb_Subtract3_g / FMS_ConstB.d_j;

      /* Signum: '<S123>/Sign5' incorporates:
       *  Signum: '<S123>/Sign6'
       */
      if (rtb_Subtract3_g < 0.0F) {
        rtb_Sign5_mn = -1.0F;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = -1.0F;
      } else if (rtb_Subtract3_g > 0.0F) {
        rtb_Sign5_mn = 1.0F;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = 1.0F;
      } else {
        rtb_Sign5_mn = rtb_Subtract3_g;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = rtb_Subtract3_g;
      }

      /* End of Signum: '<S123>/Sign5' */

      /* Product: '<S124>/Multiply1' incorporates:
       *  Constant: '<S124>/const1'
       *  DiscreteIntegrator: '<S121>/Integrator'
       */
      rtb_Subtract3_g = FMS_DW.Integrator_DSTATE_l * 0.1F;

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
      rtb_a_bx = (FMS_DW.Integrator1_DSTATE_mb - 1.0F / (1.0F -
        FMS_PARAM.THROTTLE_DZ) * rtb_u_b * (-FMS_PARAM.VEL_Z_LIM / 2.0F)) +
        rtb_Subtract3_g;

      /* Signum: '<S124>/Sign' */
      if (rtb_a_bx < 0.0F) {
        rtb_u_b = -1.0F;
      } else if (rtb_a_bx > 0.0F) {
        rtb_u_b = 1.0F;
      } else {
        rtb_u_b = rtb_a_bx;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_a_bx) + FMS_ConstB.d_m2) *
        FMS_ConstB.d_m2) - FMS_ConstB.d_m2) * 0.5F * rtb_u_b + rtb_Subtract3_g;

      /* Sum: '<S124>/Add4' */
      rtb_u_b = (rtb_a_bx - rtb_Integrator1_bx) + rtb_Subtract3_g;

      /* Sum: '<S124>/Add3' */
      rtb_Saturation1_p5 = rtb_a_bx + FMS_ConstB.d_m2;

      /* Sum: '<S124>/Subtract1' */
      rtb_a_bx -= FMS_ConstB.d_m2;

      /* Signum: '<S124>/Sign1' */
      if (rtb_Saturation1_p5 < 0.0F) {
        rtb_Saturation1_p5 = -1.0F;
      } else {
        if (rtb_Saturation1_p5 > 0.0F) {
          rtb_Saturation1_p5 = 1.0F;
        }
      }

      /* End of Signum: '<S124>/Sign1' */

      /* Signum: '<S124>/Sign2' */
      if (rtb_a_bx < 0.0F) {
        rtb_a_bx = -1.0F;
      } else {
        if (rtb_a_bx > 0.0F) {
          rtb_a_bx = 1.0F;
        }
      }

      /* End of Signum: '<S124>/Sign2' */

      /* Sum: '<S124>/Add5' incorporates:
       *  Gain: '<S124>/Gain2'
       *  Product: '<S124>/Multiply4'
       *  Sum: '<S124>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_Saturation1_p5 - rtb_a_bx) * 0.5F * rtb_u_b;

      /* Sum: '<S124>/Add6' */
      rtb_Saturation1_p5 = rtb_Integrator1_bx + FMS_ConstB.d_m2;

      /* Sum: '<S124>/Subtract3' */
      d = rtb_Integrator1_bx - FMS_ConstB.d_m2;

      /* Product: '<S124>/Divide' */
      rtb_Divide_jb = rtb_Integrator1_bx / FMS_ConstB.d_m2;

      /* Signum: '<S124>/Sign5' incorporates:
       *  Signum: '<S124>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Sign5_dc = -1.0F;

        /* Signum: '<S124>/Sign6' */
        rtb_Add4_a1 = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Sign5_dc = 1.0F;

        /* Signum: '<S124>/Sign6' */
        rtb_Add4_a1 = 1.0F;
      } else {
        rtb_Sign5_dc = rtb_Integrator1_bx;

        /* Signum: '<S124>/Sign6' */
        rtb_Add4_a1 = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S124>/Sign5' */

      /* Product: '<S122>/Multiply1' incorporates:
       *  Constant: '<S122>/const1'
       *  DiscreteIntegrator: '<S119>/Integrator'
       */
      rtb_Subtract3_g = FMS_DW.Integrator_DSTATE_oy * 0.1F;

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
      rtb_a_bx = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F - FMS_PARAM.ROLL_DZ)
                  * rtb_u_b * (FMS_PARAM.VEL_XY_LIM / 2.0F)) + rtb_Subtract3_g;

      /* Signum: '<S122>/Sign' */
      if (rtb_a_bx < 0.0F) {
        rtb_u_b = -1.0F;
      } else if (rtb_a_bx > 0.0F) {
        rtb_u_b = 1.0F;
      } else {
        rtb_u_b = rtb_a_bx;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_a_bx) + FMS_ConstB.d_oj) *
        FMS_ConstB.d_oj) - FMS_ConstB.d_oj) * 0.5F * rtb_u_b + rtb_Subtract3_g;

      /* Sum: '<S122>/Add4' */
      rtb_Subtract3_g += rtb_a_bx - rtb_Integrator1_bx;

      /* Sum: '<S122>/Add3' */
      rtb_u_b = rtb_a_bx + FMS_ConstB.d_oj;

      /* Sum: '<S122>/Subtract1' */
      rtb_a_bx -= FMS_ConstB.d_oj;

      /* Signum: '<S122>/Sign1' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S122>/Sign1' */

      /* Signum: '<S122>/Sign2' */
      if (rtb_a_bx < 0.0F) {
        rtb_a_bx = -1.0F;
      } else {
        if (rtb_a_bx > 0.0F) {
          rtb_a_bx = 1.0F;
        }
      }

      /* End of Signum: '<S122>/Sign2' */

      /* Sum: '<S122>/Add5' incorporates:
       *  Gain: '<S122>/Gain2'
       *  Product: '<S122>/Multiply4'
       *  Sum: '<S122>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_u_b - rtb_a_bx) * 0.5F * rtb_Subtract3_g;

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
      FMS_DW.Integrator_DSTATE_e += ((rtb_P_f_idx_0 - rtb_Sign5_mn) *
        FMS_ConstB.Gain4_oc * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) -
        rtb_Saturation_o4 * 15.707963F) * 0.004F;

      /* Signum: '<S124>/Sign3' */
      if (rtb_Saturation1_p5 < 0.0F) {
        rtb_Saturation1_p5 = -1.0F;
      } else {
        if (rtb_Saturation1_p5 > 0.0F) {
          rtb_Saturation1_p5 = 1.0F;
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
      FMS_DW.Integrator_DSTATE_l += ((rtb_Divide_jb - rtb_Sign5_dc) *
        FMS_ConstB.Gain4_ht * ((rtb_Saturation1_p5 - d) * 0.5F) - rtb_Add4_a1 *
        39.224F) * 0.004F;

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
        rtb_Add4_a1 = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Saturation_o4 = 1.0F;

        /* Signum: '<S122>/Sign6' */
        rtb_Add4_a1 = 1.0F;
      } else {
        rtb_Saturation_o4 = rtb_Integrator1_bx;

        /* Signum: '<S122>/Sign6' */
        rtb_Add4_a1 = rtb_Integrator1_bx;
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
        rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 39.224F) * 0.004F;

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
          /* Disable for SwitchCase: '<S339>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S739>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S729>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S678>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S646>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S657>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S337>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S448>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S499>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S489>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S448>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S336>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S435>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S351>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S369>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S410>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S397>/Switch Case' */
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
         *  ActionPort: '<S339>/Action Port'
         */
        /* SwitchCase: '<S339>/Switch Case' incorporates:
         *  Math: '<S761>/Math Function'
         *  Sum: '<S723>/Subtract'
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
            /* Disable for SwitchCase: '<S739>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S729>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S678>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S646>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S657>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S339>/Takeoff' incorporates:
             *  ActionPort: '<S641>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S339>/Switch Case' incorporates:
             *  Delay: '<S779>/cur_waypoint'
             *  DiscreteIntegrator: '<S775>/Integrator'
             *  DiscreteIntegrator: '<S775>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S339>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S339>/Takeoff' incorporates:
           *  ActionPort: '<S641>/Action Port'
           */
          /* Delay: '<S779>/cur_waypoint' incorporates:
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
          /* Product: '<S779>/Divide' incorporates:
           *  Delay: '<S779>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S779>/Sum1'
           *  Sum: '<S779>/Sum2'
           */
          rtb_Saturation_o4 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S779>/Saturation' */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_o4 = 0.0F;
            }
          }

          /* End of Saturate: '<S779>/Saturation' */

          /* Trigonometry: '<S780>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S780>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S780>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S780>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S780>/Gain' incorporates:
           *  Gain: '<S778>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S780>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S780>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S780>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S780>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S780>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S772>/Saturation1' */
          rtb_Saturation_ga = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Saturation1_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S772>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S779>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S779>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S772>/Sum'
           *  Sum: '<S779>/Sum3'
           *  Sum: '<S779>/Sum4'
           */
          d = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0]) *
               rtb_Saturation_o4 + FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_o4 +
                                FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S772>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate[rtb_n] * d;
          }

          /* Saturate: '<S772>/Saturation1' incorporates:
           *  Gain: '<S772>/Gain2'
           *  Product: '<S772>/Multiply'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S641>/Bus Assignment1'
           *  Constant: '<S641>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S641>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S772>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_ga) {
            /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_ga;
          } else if (rtb_u_b < rtb_Saturation1_d) {
            /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Saturation1_p5 > rtb_Saturation_ga) {
            /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_ga;
          } else if (rtb_Saturation1_p5 < rtb_Saturation1_d) {
            /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_p5;
          }

          /* BusAssignment: '<S641>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S775>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S776>/Multiply1' incorporates:
           *  Constant: '<S776>/const1'
           *  DiscreteIntegrator: '<S775>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S771>/Switch' incorporates:
           *  Abs: '<S771>/Abs'
           *  Abs: '<S771>/Abs1'
           *  Constant: '<S771>/Takeoff_Speed'
           *  Constant: '<S773>/Constant'
           *  Constant: '<S774>/Constant'
           *  Gain: '<S771>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S771>/Logical Operator'
           *  RelationalOperator: '<S773>/Compare'
           *  RelationalOperator: '<S774>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S771>/Sum'
           *  Sum: '<S771>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_u_b = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_u_b = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S771>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S776>/Add' incorporates:
           *  DiscreteIntegrator: '<S775>/Integrator1'
           *  Sum: '<S775>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_f - rtb_u_b) +
            rtb_Saturation_o4;

          /* Signum: '<S776>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S776>/Sign' */

          /* Sum: '<S776>/Add2' incorporates:
           *  Abs: '<S776>/Abs'
           *  Gain: '<S776>/Gain'
           *  Gain: '<S776>/Gain1'
           *  Product: '<S776>/Multiply2'
           *  Product: '<S776>/Multiply3'
           *  Sqrt: '<S776>/Sqrt'
           *  Sum: '<S776>/Add1'
           *  Sum: '<S776>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_b) *
                           FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S776>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S776>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Sum: '<S776>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_b;

          /* Signum: '<S776>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S776>/Sign1' */

          /* Signum: '<S776>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S776>/Sign2' */

          /* Sum: '<S776>/Add5' incorporates:
           *  Gain: '<S776>/Gain2'
           *  Product: '<S776>/Multiply4'
           *  Sum: '<S776>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S779>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S775>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S775>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S776>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_b;

          /* Sum: '<S776>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_b;

          /* Signum: '<S776>/Sign5' incorporates:
           *  Signum: '<S776>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S776>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S776>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S776>/Sign6' */
            rtb_Add4_a1 = rtb_u_b;
          }

          /* End of Signum: '<S776>/Sign5' */

          /* Signum: '<S776>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S776>/Sign3' */

          /* Signum: '<S776>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S776>/Sign4' */

          /* Update for DiscreteIntegrator: '<S775>/Integrator' incorporates:
           *  Constant: '<S776>/const'
           *  Gain: '<S776>/Gain3'
           *  Product: '<S776>/Divide'
           *  Product: '<S776>/Multiply5'
           *  Product: '<S776>/Multiply6'
           *  Sum: '<S776>/Subtract4'
           *  Sum: '<S776>/Subtract5'
           *  Sum: '<S776>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_u_b / FMS_ConstB.d_b -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_i * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S339>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S339>/Land' incorporates:
             *  ActionPort: '<S639>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S339>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S694>/Integrator'
             *  DiscreteIntegrator: '<S694>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S339>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S339>/Land' incorporates:
           *  ActionPort: '<S639>/Action Port'
           */
          /* Trigonometry: '<S699>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S699>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S699>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S699>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S699>/Gain' incorporates:
           *  Gain: '<S698>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S699>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S699>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S699>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S699>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S699>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S692>/Saturation1' */
          rtb_Saturation_o4 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Add4_a1 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S696>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S696>/Sum'
           */
          d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S696>/Multiply' incorporates:
           *  SignalConversion: '<S696>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S696>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate[rtb_n] * d;
          }

          /* End of Product: '<S696>/Multiply' */

          /* Saturate: '<S692>/Saturation1' incorporates:
           *  Gain: '<S696>/Gain2'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S639>/Bus Assignment1'
           *  Constant: '<S639>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S639>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S692>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_o4) {
            /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_o4;
          } else if (rtb_u_b < rtb_Add4_a1) {
            /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Add4_a1;
          } else {
            /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Saturation1_p5 > rtb_Saturation_o4) {
            /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_o4;
          } else if (rtb_Saturation1_p5 < rtb_Add4_a1) {
            /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Add4_a1;
          } else {
            /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_p5;
          }

          /* BusAssignment: '<S639>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S694>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S695>/Multiply1' incorporates:
           *  Constant: '<S695>/const1'
           *  DiscreteIntegrator: '<S694>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S691>/Switch' incorporates:
           *  Constant: '<S691>/Land_Speed'
           *  Constant: '<S693>/Constant'
           *  Gain: '<S691>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S691>/Logical Operator'
           *  RelationalOperator: '<S693>/Compare'
           *  S-Function (sfix_bitop): '<S691>/cmd_p valid'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_u_b = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_u_b = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S691>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S695>/Add' incorporates:
           *  DiscreteIntegrator: '<S694>/Integrator1'
           *  Sum: '<S694>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_g - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S695>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S695>/Sign' */

          /* Sum: '<S695>/Add2' incorporates:
           *  Abs: '<S695>/Abs'
           *  Gain: '<S695>/Gain'
           *  Gain: '<S695>/Gain1'
           *  Product: '<S695>/Multiply2'
           *  Product: '<S695>/Multiply3'
           *  Sqrt: '<S695>/Sqrt'
           *  Sum: '<S695>/Add1'
           *  Sum: '<S695>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_om) *
                           FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S695>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S695>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Sum: '<S695>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_om;

          /* Signum: '<S695>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S695>/Sign1' */

          /* Signum: '<S695>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S695>/Sign2' */

          /* Sum: '<S695>/Add5' incorporates:
           *  Gain: '<S695>/Gain2'
           *  Product: '<S695>/Multiply4'
           *  Sum: '<S695>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for DiscreteIntegrator: '<S694>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S694>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S695>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_om;

          /* Sum: '<S695>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_om;

          /* Signum: '<S695>/Sign5' incorporates:
           *  Signum: '<S695>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S695>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S695>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S695>/Sign6' */
            rtb_Add4_a1 = rtb_u_b;
          }

          /* End of Signum: '<S695>/Sign5' */

          /* Signum: '<S695>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S695>/Sign3' */

          /* Signum: '<S695>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S695>/Sign4' */

          /* Update for DiscreteIntegrator: '<S694>/Integrator' incorporates:
           *  Constant: '<S695>/const'
           *  Gain: '<S695>/Gain3'
           *  Product: '<S695>/Divide'
           *  Product: '<S695>/Multiply5'
           *  Product: '<S695>/Multiply6'
           *  Sum: '<S695>/Subtract4'
           *  Sum: '<S695>/Subtract5'
           *  Sum: '<S695>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_u_b / FMS_ConstB.d_om -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_p * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S339>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S339>/Return' incorporates:
             *  ActionPort: '<S640>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S339>/Switch Case' incorporates:
             *  Delay: '<S703>/Delay'
             *  Delay: '<S724>/Delay'
             *  DiscreteIntegrator: '<S706>/Integrator'
             *  DiscreteIntegrator: '<S706>/Integrator1'
             *  DiscreteIntegrator: '<S720>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S725>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S766>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S339>/Return' */

            /* SystemReset for IfAction SubSystem: '<S339>/Return' incorporates:
             *  ActionPort: '<S640>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S339>/Switch Case' incorporates:
             *  Chart: '<S730>/Motion Status'
             *  Chart: '<S740>/Motion State'
             */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S339>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S339>/Return' incorporates:
           *  ActionPort: '<S640>/Action Port'
           */
          /* Delay: '<S724>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S719>/Compare' incorporates:
           *  Constant: '<S770>/Constant'
           *  DiscreteIntegrator: '<S725>/Discrete-Time Integrator'
           *  RelationalOperator: '<S770>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S720>/Acceleration_Speed' */
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
          /* Chart: '<S740>/Motion State' incorporates:
           *  Constant: '<S740>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S740>/Square'
           *  Math: '<S740>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S740>/Sqrt'
           *  Sum: '<S740>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S739>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S739>/Hold Control' incorporates:
               *  ActionPort: '<S742>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S739>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S739>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S739>/Hold Control' incorporates:
             *  ActionPort: '<S742>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S739>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S739>/Brake Control' incorporates:
             *  ActionPort: '<S741>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S739>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S739>/Move Control' incorporates:
               *  ActionPort: '<S743>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S739>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S739>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S739>/Move Control' incorporates:
             *  ActionPort: '<S743>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S739>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S739>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S730>/Motion Status' incorporates:
           *  Abs: '<S730>/Abs'
           *  Constant: '<S730>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S729>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S729>/Hold Control' incorporates:
               *  ActionPort: '<S732>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S729>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S729>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S729>/Hold Control' incorporates:
             *  ActionPort: '<S732>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S729>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S729>/Brake Control' incorporates:
             *  ActionPort: '<S731>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S729>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S729>/Move Control' incorporates:
               *  ActionPort: '<S733>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S729>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_cg);

              /* End of SystemReset for SubSystem: '<S729>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S729>/Move Control' incorporates:
             *  ActionPort: '<S733>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_cg, &FMS_DW.MoveControl_cg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S729>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S729>/Switch Case' */

          /* Switch: '<S701>/Switch' incorporates:
           *  Product: '<S724>/Multiply'
           *  Sum: '<S724>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S739>/Saturation1' */
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

            /* End of Saturate: '<S739>/Saturation1' */

            /* Saturate: '<S729>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S729>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S724>/Sum' incorporates:
             *  Delay: '<S724>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_a1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S767>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Add4_a1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S720>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_o4 = rtb_Add4_a1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S724>/Sum' incorporates:
             *  Delay: '<S724>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_a1 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S720>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S726>/Sqrt' incorporates:
             *  Math: '<S726>/Square'
             *  Sum: '<S720>/Sum'
             *  Sum: '<S726>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
                            rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S769>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S769>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S769>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S768>/Gain' incorporates:
             *  DiscreteIntegrator: '<S766>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S766>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S769>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S769>/Trigonometric Function1'
             */
            rtb_Saturation_ga = arm_cos_f32(rtb_Saturation1_d);
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Trigonometry: '<S769>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S769>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation1_d);

            /* Gain: '<S769>/Gain' incorporates:
             *  Trigonometry: '<S769>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S769>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S769>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S769>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S769>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* Switch: '<S720>/Switch' incorporates:
             *  Constant: '<S720>/vel'
             */
            if (rtb_u_b > FMS_PARAM.L1) {
              rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S720>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_u_b;

              /* Saturate: '<S720>/Saturation' */
              if (rtb_Saturation1_d > FMS_PARAM.CRUISE_SPEED) {
                rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Saturate: '<S720>/Saturation' */
            }

            /* End of Switch: '<S720>/Switch' */

            /* Switch: '<S720>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S720>/Acceleration_Speed'
             *  Sum: '<S720>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S720>/Switch1' */

            /* Sum: '<S767>/Sum of Elements' incorporates:
             *  Math: '<S767>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Add4_a1 *
              rtb_Add4_a1;

            /* Math: '<S767>/Math Function1' incorporates:
             *  Sum: '<S767>/Sum of Elements'
             *
             * About '<S767>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_Saturation_ga = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S767>/Math Function1' */

            /* Switch: '<S767>/Switch' incorporates:
             *  Constant: '<S767>/Constant'
             *  Product: '<S767>/Product'
             */
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Divide_bu[0] = rtb_Saturation_o4;
              rtb_Divide_bu[1] = rtb_Add4_a1;
              rtb_Divide_bu[3] = rtb_Saturation_ga;
            } else {
              rtb_Divide_bu[0] = 0.0F;
              rtb_Divide_bu[1] = 0.0F;
              rtb_Divide_bu[3] = 1.0F;
            }

            /* End of Switch: '<S767>/Switch' */

            /* Product: '<S765>/Multiply2' incorporates:
             *  Product: '<S767>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_bu[0] / rtb_Divide_bu[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_bu[1] / rtb_Divide_bu[3];
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_c2[rtb_n] = rtb_VectorConcatenate[rtb_n + 3] *
                rtb_Saturation1_d + rtb_VectorConcatenate[rtb_n] *
                rtb_Saturation_ga;
            }
          }

          /* End of Switch: '<S701>/Switch' */

          /* Delay: '<S703>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S706>/Integrator1' incorporates:
           *  Delay: '<S703>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S710>/Rem' incorporates:
           *  Constant: '<S710>/Constant1'
           *  DiscreteIntegrator: '<S706>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S705>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S710>/Switch' incorporates:
           *  Abs: '<S710>/Abs'
           *  Constant: '<S710>/Constant'
           *  Constant: '<S711>/Constant'
           *  Product: '<S710>/Multiply'
           *  RelationalOperator: '<S711>/Compare'
           *  Sum: '<S710>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S710>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S710>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S710>/Switch' */

          /* Gain: '<S705>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S705>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S705>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S640>/Bus Assignment1'
           *  Constant: '<S640>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S640>/Bus Assignment1' incorporates:
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

          /* Math: '<S760>/Math Function1'
           *
           * About '<S760>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S760>/Math Function1' */

          /* Switch: '<S760>/Switch' incorporates:
           *  Constant: '<S760>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S760>/Product'
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

          /* End of Switch: '<S760>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S640>/Sum' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_f0[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_f0[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S717>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S640>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S717>/Math Function' incorporates:
           *  Sum: '<S640>/Sum'
           */
          rtb_Square_dv[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_dv[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S717>/Sum of Elements' */
          rtb_u_b = rtb_Square_dv[0] + rtb_Square_dv[1];

          /* Math: '<S717>/Math Function1' incorporates:
           *  Sum: '<S717>/Sum of Elements'
           *
           * About '<S717>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S717>/Math Function1' */

          /* Switch: '<S717>/Switch' incorporates:
           *  Constant: '<S717>/Constant'
           *  Product: '<S717>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Integrator1_bx = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S717>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S722>/NearbyRefWP' incorporates:
           *  Constant: '<S640>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f0,
                          &rtb_u_b);

          /* MATLAB Function: '<S722>/SearchL1RefWP' incorporates:
           *  Constant: '<S640>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S722>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0],
                               &rtb_TmpSignalConversionAtMultip[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_dv);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S722>/Switch1' incorporates:
           *  Constant: '<S753>/Constant'
           *  RelationalOperator: '<S753>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_f0[0];
            rtb_P_ap[1] = rtb_Divide_f0[1];
          } else {
            /* RelationalOperator: '<S752>/Compare' incorporates:
             *  Constant: '<S752>/Constant'
             */
            rtb_Compare_at = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S722>/Switch' */
            if (!rtb_Compare_at) {
              rtb_P_ap[0] = rtb_Square_dv[0];
              rtb_P_ap[1] = rtb_Square_dv[1];
            }

            /* End of Switch: '<S722>/Switch' */
          }

          /* End of Switch: '<S722>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S723>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_a1 = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Add4_a1;
          rtb_Subtract_hb[0] = rtb_Add4_a1 * rtb_Add4_a1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S723>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S761>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_a1 = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S761>/Sum of Elements' incorporates:
           *  Math: '<S761>/Math Function'
           *  Sum: '<S759>/Sum of Elements'
           */
          rtb_u_b = rtb_Subtract_hb[0] + rtb_Add4_a1 * rtb_Add4_a1;

          /* Math: '<S761>/Math Function1' incorporates:
           *  Sum: '<S761>/Sum of Elements'
           *
           * About '<S761>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S761>/Math Function1' */

          /* Switch: '<S761>/Switch' incorporates:
           *  Constant: '<S761>/Constant'
           *  Product: '<S761>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_P_ap[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Add4_a1;
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S761>/Switch' */

          /* Product: '<S760>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S763>/Sum of Elements' incorporates:
           *  Math: '<S763>/Math Function'
           *  SignalConversion: '<S763>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S763>/Math Function1' incorporates:
           *  Sum: '<S763>/Sum of Elements'
           *
           * About '<S763>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S763>/Math Function1' */

          /* Switch: '<S763>/Switch' incorporates:
           *  Constant: '<S763>/Constant'
           *  Product: '<S763>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_f0[1];
            rtb_Switch_c2[1] = rtb_Divide_f0[0];
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S763>/Switch' */

          /* Product: '<S761>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S764>/Sum of Elements' incorporates:
           *  Math: '<S764>/Math Function'
           *  SignalConversion: '<S764>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S764>/Math Function1' incorporates:
           *  Sum: '<S764>/Sum of Elements'
           *
           * About '<S764>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S764>/Math Function1' */

          /* Switch: '<S764>/Switch' incorporates:
           *  Constant: '<S764>/Constant'
           *  Product: '<S764>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Divide_f0[1];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Divide_f0[0];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S764>/Switch' */

          /* Product: '<S764>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S763>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S717>/Divide' */
          rtb_Square_dv[0] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S764>/Divide' */
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S763>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S717>/Divide' */
          rtb_Square_dv[1] = rtb_Saturation1_d / rtb_Integrator1_bx;

          /* Sum: '<S762>/Subtract' incorporates:
           *  Product: '<S762>/Multiply'
           *  Product: '<S762>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_f0[0] * rtb_P_ap[1] - rtb_Divide_f0[1] *
            rtb_P_ap[0];

          /* Signum: '<S757>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S757>/Sign1' */

          /* Switch: '<S757>/Switch2' incorporates:
           *  Constant: '<S757>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S757>/Switch2' */

          /* DotProduct: '<S757>/Dot Product' */
          rtb_Add4_a1 = rtb_P_ap[0] * rtb_Divide_f0[0] + rtb_P_ap[1] *
            rtb_Divide_f0[1];

          /* Trigonometry: '<S757>/Acos' incorporates:
           *  DotProduct: '<S757>/Dot Product'
           */
          if (rtb_Add4_a1 > 1.0F) {
            rtb_Add4_a1 = 1.0F;
          } else {
            if (rtb_Add4_a1 < -1.0F) {
              rtb_Add4_a1 = -1.0F;
            }
          }

          /* Product: '<S757>/Multiply' incorporates:
           *  Trigonometry: '<S757>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Add4_a1);

          /* Saturate: '<S723>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S723>/Saturation' */

          /* Product: '<S723>/Divide' incorporates:
           *  Constant: '<S640>/L1'
           *  Constant: '<S723>/Constant'
           *  Gain: '<S723>/Gain'
           *  Math: '<S723>/Square'
           *  MinMax: '<S723>/Max'
           *  MinMax: '<S723>/Min'
           *  Product: '<S723>/Multiply1'
           *  Sqrt: '<S759>/Sqrt'
           *  Trigonometry: '<S723>/Sin'
           */
          rtb_Saturation1_p5 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S715>/Subtract' incorporates:
           *  Product: '<S715>/Multiply'
           *  Product: '<S715>/Multiply1'
           */
          rtb_Add4_a1 = rtb_Square_dv[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_dv[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S704>/Sign1' */
          if (rtb_Add4_a1 < 0.0F) {
            rtb_Add4_a1 = -1.0F;
          } else {
            if (rtb_Add4_a1 > 0.0F) {
              rtb_Add4_a1 = 1.0F;
            }
          }

          /* End of Signum: '<S704>/Sign1' */

          /* Switch: '<S704>/Switch2' incorporates:
           *  Constant: '<S704>/Constant4'
           */
          if (rtb_Add4_a1 == 0.0F) {
            rtb_Add4_a1 = 1.0F;
          }

          /* End of Switch: '<S704>/Switch2' */

          /* DotProduct: '<S704>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide_m[0] * rtb_Square_dv[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_dv[1];

          /* Trigonometry: '<S704>/Acos' incorporates:
           *  DotProduct: '<S704>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S704>/Multiply' incorporates:
           *  Trigonometry: '<S704>/Acos'
           */
          rtb_Add4_a1 *= acosf(rtb_u_b);

          /* Math: '<S707>/Rem' incorporates:
           *  Constant: '<S707>/Constant1'
           *  Delay: '<S703>/Delay'
           *  Sum: '<S703>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Add4_a1 - FMS_DW.Delay_DSTATE_nx,
            6.28318548F);

          /* Switch: '<S707>/Switch' incorporates:
           *  Abs: '<S707>/Abs'
           *  Constant: '<S707>/Constant'
           *  Constant: '<S713>/Constant'
           *  Product: '<S707>/Multiply'
           *  RelationalOperator: '<S713>/Compare'
           *  Sum: '<S707>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S707>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S707>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S707>/Switch' */

          /* Sum: '<S703>/Sum' incorporates:
           *  Delay: '<S703>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S712>/Multiply1' incorporates:
           *  Constant: '<S712>/const1'
           *  DiscreteIntegrator: '<S706>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S712>/Add' incorporates:
           *  DiscreteIntegrator: '<S706>/Integrator1'
           *  Sum: '<S706>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S712>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S712>/Sign' */

          /* Sum: '<S712>/Add2' incorporates:
           *  Abs: '<S712>/Abs'
           *  Gain: '<S712>/Gain'
           *  Gain: '<S712>/Gain1'
           *  Product: '<S712>/Multiply2'
           *  Product: '<S712>/Multiply3'
           *  Sqrt: '<S712>/Sqrt'
           *  Sum: '<S712>/Add1'
           *  Sum: '<S712>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_n) *
                           FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S712>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S712>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_n;

          /* Sum: '<S712>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_n;

          /* Signum: '<S712>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S712>/Sign1' */

          /* Signum: '<S712>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S712>/Sign2' */

          /* Sum: '<S712>/Add5' incorporates:
           *  Gain: '<S712>/Gain2'
           *  Product: '<S712>/Multiply4'
           *  Sum: '<S712>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S712>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_n;

          /* Sum: '<S712>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_n;

          /* Product: '<S712>/Divide' */
          d = rtb_u_b / FMS_ConstB.d_n;

          /* Signum: '<S712>/Sign5' incorporates:
           *  Signum: '<S712>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S712>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S712>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = rtb_u_b;

            /* Signum: '<S712>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S712>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S703>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_a1 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S708>/Rem' incorporates:
           *  Constant: '<S708>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Add4_a1, 6.28318548F);

          /* Switch: '<S708>/Switch' incorporates:
           *  Abs: '<S708>/Abs'
           *  Constant: '<S708>/Constant'
           *  Constant: '<S714>/Constant'
           *  Product: '<S708>/Multiply'
           *  RelationalOperator: '<S714>/Compare'
           *  Sum: '<S708>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S708>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Add4_a1 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Add4_a1 = 1.0F;
            } else {
              rtb_Add4_a1 = rtb_u_b;
            }

            /* End of Signum: '<S708>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Add4_a1;
          }

          /* End of Switch: '<S708>/Switch' */

          /* Abs: '<S701>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S724>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S725>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S718>/Constant'
           *  RelationalOperator: '<S718>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S725>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S720>/Acceleration_Speed' incorporates:
           *  Constant: '<S720>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S720>/Acceleration_Speed' */

          /* Product: '<S724>/Divide1' incorporates:
           *  Constant: '<S724>/Constant'
           */
          rtb_u_b = rtb_Saturation1_p5 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S724>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S724>/Saturation' */

          /* Update for DiscreteIntegrator: '<S766>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_u_b;

          /* Update for Delay: '<S703>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S706>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S706>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S712>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S712>/Sign3' */

          /* Signum: '<S712>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S712>/Sign4' */

          /* Update for DiscreteIntegrator: '<S706>/Integrator' incorporates:
           *  Constant: '<S712>/const'
           *  Gain: '<S712>/Gain3'
           *  Product: '<S712>/Multiply5'
           *  Product: '<S712>/Multiply6'
           *  Sum: '<S712>/Subtract4'
           *  Sum: '<S712>/Subtract5'
           *  Sum: '<S712>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S706>/Integrator' */
          /* End of Outputs for SubSystem: '<S339>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S339>/Hold' incorporates:
             *  ActionPort: '<S638>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S339>/Switch Case' incorporates:
             *  Delay: '<S659>/Delay'
             *  DiscreteIntegrator: '<S671>/Integrator'
             *  DiscreteIntegrator: '<S671>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S339>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S339>/Hold' incorporates:
             *  ActionPort: '<S638>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S339>/Switch Case' incorporates:
             *  Chart: '<S647>/Motion Status'
             *  Chart: '<S658>/Motion State'
             *  Chart: '<S679>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S339>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S339>/Hold' incorporates:
           *  ActionPort: '<S638>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S647>/Motion Status' incorporates:
           *  Abs: '<S647>/Abs'
           *  Constant: '<S647>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S658>/Motion State' incorporates:
           *  Abs: '<S658>/Abs'
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

          /* End of Chart: '<S658>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S679>/Motion State' incorporates:
           *  Constant: '<S679>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S679>/Square'
           *  Math: '<S679>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S679>/Sqrt'
           *  Sum: '<S679>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                            &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S678>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S678>/Hold Control' incorporates:
               *  ActionPort: '<S681>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S678>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S678>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S678>/Hold Control' incorporates:
             *  ActionPort: '<S681>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S678>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S678>/Brake Control' incorporates:
             *  ActionPort: '<S680>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S678>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S678>/Move Control' incorporates:
               *  ActionPort: '<S682>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S678>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S678>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S678>/Move Control' incorporates:
             *  ActionPort: '<S682>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S678>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S678>/Switch Case' */

          /* SwitchCase: '<S646>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S646>/Hold Control' incorporates:
               *  ActionPort: '<S649>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S646>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S646>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S646>/Hold Control' incorporates:
             *  ActionPort: '<S649>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S646>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S646>/Brake Control' incorporates:
             *  ActionPort: '<S648>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S646>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S646>/Move Control' incorporates:
               *  ActionPort: '<S650>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S646>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S646>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S646>/Move Control' incorporates:
             *  ActionPort: '<S650>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S646>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S646>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S656>/Compare' incorporates:
           *  Constant: '<S656>/Constant'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S659>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S671>/Integrator1' incorporates:
           *  Delay: '<S659>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S657>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S657>/Hold Control' incorporates:
               *  ActionPort: '<S661>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S657>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S657>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S657>/Hold Control' incorporates:
             *  ActionPort: '<S661>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S657>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S657>/Brake Control' incorporates:
             *  ActionPort: '<S660>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S657>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S657>/Move Control' incorporates:
               *  ActionPort: '<S662>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S657>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S657>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S657>/Move Control' incorporates:
             *  ActionPort: '<S662>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S657>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S657>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S644>/Switch' incorporates:
           *  Saturate: '<S657>/Saturation'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S674>/Rem' incorporates:
             *  Constant: '<S674>/Constant1'
             *  DiscreteIntegrator: '<S671>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S670>/Sum'
             */
            rtb_Saturation_ga = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S674>/Switch' incorporates:
             *  Abs: '<S674>/Abs'
             *  Constant: '<S674>/Constant'
             *  Constant: '<S675>/Constant'
             *  Product: '<S674>/Multiply'
             *  RelationalOperator: '<S675>/Compare'
             *  Sum: '<S674>/Add'
             */
            if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
              /* Signum: '<S674>/Sign' */
              if (rtb_Saturation_ga < 0.0F) {
                rtb_Saturation1_d = -1.0F;
              } else if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              } else {
                rtb_Saturation1_d = rtb_Saturation_ga;
              }

              /* End of Signum: '<S674>/Sign' */
              rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
            }

            /* End of Switch: '<S674>/Switch' */

            /* Gain: '<S670>/Gain2' */
            rtb_Saturation_ga *= FMS_PARAM.YAW_P;

            /* Saturate: '<S670>/Saturation' */
            if (rtb_Saturation_ga > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Saturation_ga < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S670>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S657>/Saturation' */
            rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S657>/Saturation' */
            rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S657>/Saturation' */
            rtb_Saturation_ga = FMS_B.Merge_h;
          }

          /* End of Switch: '<S644>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S638>/Bus Assignment'
           *  Constant: '<S638>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S638>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_ga;

          /* Saturate: '<S678>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S678>/Saturation1' */

          /* Saturate: '<S646>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S638>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S646>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S672>/Rem' incorporates:
           *  Constant: '<S672>/Constant1'
           *  Delay: '<S659>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S659>/Sum2'
           */
          rtb_Saturation_ga = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S672>/Switch' incorporates:
           *  Abs: '<S672>/Abs'
           *  Constant: '<S672>/Constant'
           *  Constant: '<S677>/Constant'
           *  Product: '<S672>/Multiply'
           *  RelationalOperator: '<S677>/Compare'
           *  Sum: '<S672>/Add'
           */
          if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
            /* Signum: '<S672>/Sign' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_ga;
            }

            /* End of Signum: '<S672>/Sign' */
            rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S672>/Switch' */

          /* Sum: '<S659>/Sum' incorporates:
           *  Delay: '<S659>/Delay'
           */
          rtb_Saturation1_d = rtb_Saturation_ga + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S671>/Integrator' */
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

          /* Product: '<S676>/Multiply1' incorporates:
           *  Constant: '<S676>/const1'
           *  DiscreteIntegrator: '<S671>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S676>/Add' incorporates:
           *  DiscreteIntegrator: '<S671>/Integrator1'
           *  Sum: '<S671>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jz - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S676>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S676>/Sign' */

          /* Sum: '<S676>/Add2' incorporates:
           *  Abs: '<S676>/Abs'
           *  Gain: '<S676>/Gain'
           *  Gain: '<S676>/Gain1'
           *  Product: '<S676>/Multiply2'
           *  Product: '<S676>/Multiply3'
           *  Sqrt: '<S676>/Sqrt'
           *  Sum: '<S676>/Add1'
           *  Sum: '<S676>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_k) *
                           FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S676>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S676>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_k;

          /* Sum: '<S676>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_k;

          /* Signum: '<S676>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S676>/Sign1' */

          /* Signum: '<S676>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S676>/Sign2' */

          /* Sum: '<S676>/Add5' incorporates:
           *  Gain: '<S676>/Gain2'
           *  Product: '<S676>/Multiply4'
           *  Sum: '<S676>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S659>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S671>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S671>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S676>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_k;

          /* Sum: '<S676>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_k;

          /* Signum: '<S676>/Sign5' incorporates:
           *  Signum: '<S676>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S676>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S676>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S676>/Sign6' */
            rtb_Add4_a1 = rtb_u_b;
          }

          /* End of Signum: '<S676>/Sign5' */

          /* Signum: '<S676>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S676>/Sign3' */

          /* Signum: '<S676>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S676>/Sign4' */

          /* Update for DiscreteIntegrator: '<S671>/Integrator' incorporates:
           *  Constant: '<S676>/const'
           *  Gain: '<S676>/Gain3'
           *  Product: '<S676>/Divide'
           *  Product: '<S676>/Multiply5'
           *  Product: '<S676>/Multiply6'
           *  Sum: '<S676>/Subtract4'
           *  Sum: '<S676>/Subtract5'
           *  Sum: '<S676>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hi += ((rtb_u_b / FMS_ConstB.d_k -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_a * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          FMS_DW.Integrator_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* End of Update for DiscreteIntegrator: '<S671>/Integrator' */
          /* End of Outputs for SubSystem: '<S339>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S339>/Unknown' incorporates:
           *  ActionPort: '<S642>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S339>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
         *  ActionPort: '<S337>/Action Port'
         */
        /* SwitchCase: '<S337>/Switch Case' incorporates:
         *  Math: '<S521>/Math Function'
         *  Sum: '<S477>/Subtract'
         *  Sum: '<S534>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S448>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S499>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S489>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S448>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S337>/Offboard' incorporates:
           *  ActionPort: '<S449>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S615>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S618>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S619>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S619>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S619>/Multiply1' incorporates:
           *  Product: '<S619>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S619>/Divide' incorporates:
           *  Constant: '<S619>/Constant'
           *  Constant: '<S619>/R'
           *  Sqrt: '<S619>/Sqrt'
           *  Sum: '<S619>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S619>/Product3' incorporates:
           *  Constant: '<S619>/Constant1'
           *  Product: '<S619>/Multiply1'
           *  Sum: '<S619>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S619>/Multiply2' incorporates:
           *  Trigonometry: '<S619>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S618>/Sum' incorporates:
           *  Gain: '<S615>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S623>/Abs' incorporates:
           *  Abs: '<S626>/Abs1'
           *  Switch: '<S623>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S623>/Switch1' incorporates:
           *  Abs: '<S623>/Abs'
           *  Bias: '<S623>/Bias2'
           *  Bias: '<S623>/Bias3'
           *  Constant: '<S620>/Constant'
           *  Constant: '<S620>/Constant1'
           *  Constant: '<S625>/Constant'
           *  Gain: '<S623>/Gain1'
           *  Product: '<S623>/Multiply'
           *  RelationalOperator: '<S625>/Compare'
           *  Switch: '<S620>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S626>/Switch1' incorporates:
             *  Bias: '<S626>/Bias2'
             *  Bias: '<S626>/Bias3'
             *  Constant: '<S626>/Constant'
             *  Constant: '<S627>/Constant'
             *  Math: '<S626>/Math Function'
             *  RelationalOperator: '<S627>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S626>/Switch1' */

            /* Signum: '<S623>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S623>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S620>/Sum' incorporates:
           *  Gain: '<S615>/Gain1'
           *  Gain: '<S615>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S618>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S618>/Multiply' incorporates:
           *  Gain: '<S618>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S622>/Switch1' incorporates:
           *  Abs: '<S622>/Abs1'
           *  Bias: '<S622>/Bias2'
           *  Bias: '<S622>/Bias3'
           *  Constant: '<S622>/Constant'
           *  Constant: '<S624>/Constant'
           *  Math: '<S622>/Math Function'
           *  RelationalOperator: '<S624>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S622>/Switch1' */

          /* Product: '<S618>/Multiply' incorporates:
           *  Gain: '<S618>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S596>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S600>/Multiply1'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S609>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S609>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S609>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S609>/Gain' incorporates:
             *  Gain: '<S608>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S609>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S609>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S609>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S609>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S609>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S609>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S602>/Switch' incorporates:
             *  Constant: '<S617>/Constant'
             *  DataTypeConversion: '<S615>/Data Type Conversion1'
             *  Product: '<S621>/Multiply1'
             *  Product: '<S621>/Multiply2'
             *  RelationalOperator: '<S617>/Compare'
             *  S-Function (sfix_bitop): '<S614>/lat_cmd valid'
             *  Sum: '<S621>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o2 +
                                   rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S600>/Multiply' incorporates:
             *  Constant: '<S606>/Constant'
             *  Constant: '<S607>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S599>/Logical Operator'
             *  RelationalOperator: '<S606>/Compare'
             *  RelationalOperator: '<S607>/Compare'
             *  S-Function (sfix_bitop): '<S599>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/x_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S600>/Sum1'
             */
            d = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S609>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S602>/Switch' incorporates:
             *  Constant: '<S617>/Constant'
             *  DataTypeConversion: '<S615>/Data Type Conversion1'
             *  Product: '<S621>/Multiply3'
             *  Product: '<S621>/Multiply4'
             *  RelationalOperator: '<S617>/Compare'
             *  S-Function (sfix_bitop): '<S614>/lon_cmd valid'
             *  Sum: '<S621>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                   rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S600>/Multiply' incorporates:
             *  Constant: '<S606>/Constant'
             *  Constant: '<S607>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S599>/Logical Operator'
             *  RelationalOperator: '<S606>/Compare'
             *  RelationalOperator: '<S607>/Compare'
             *  S-Function (sfix_bitop): '<S599>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/y_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S600>/Sum1'
             */
            rtb_Integrator1_bx = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S609>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S602>/Switch' incorporates:
             *  Constant: '<S617>/Constant'
             *  DataTypeConversion: '<S615>/Data Type Conversion'
             *  DataTypeConversion: '<S615>/Data Type Conversion1'
             *  Gain: '<S615>/Gain2'
             *  Gain: '<S618>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S617>/Compare'
             *  S-Function (sfix_bitop): '<S614>/alt_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S618>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_u_b = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                                    -FMS_U.INS_Out.alt_0);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S600>/Multiply' incorporates:
             *  Constant: '<S606>/Constant'
             *  Constant: '<S607>/Constant'
             *  Gain: '<S603>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S599>/Logical Operator'
             *  RelationalOperator: '<S606>/Compare'
             *  RelationalOperator: '<S607>/Compare'
             *  S-Function (sfix_bitop): '<S599>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/z_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S600>/Sum1'
             */
            rtb_Add4_a1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_u_b -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Add4_a1 +
                (rtb_VectorConcatenate[rtb_n + 3] * rtb_Integrator1_bx +
                 rtb_VectorConcatenate[rtb_n] * d);
            }

            /* SignalConversion: '<S542>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S542>/Constant4'
             *  MultiPortSwitch: '<S531>/Index Vector'
             *  Product: '<S600>/Multiply1'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S542>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S542>/Gain' incorporates:
             *  Gain: '<S541>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S531>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S542>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S542>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S542>/Constant3'
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S542>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S542>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S542>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S531>/Multiply' incorporates:
             *  Constant: '<S540>/Constant'
             *  RelationalOperator: '<S540>/Compare'
             *  S-Function (sfix_bitop): '<S537>/ax_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ? FMS_U.Auto_Cmd.ax_cmd :
              0.0F;

            /* SignalConversion: '<S542>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S531>/Multiply' incorporates:
             *  Constant: '<S540>/Constant'
             *  RelationalOperator: '<S540>/Compare'
             *  S-Function (sfix_bitop): '<S537>/ay_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S542>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S531>/Multiply' incorporates:
             *  Constant: '<S540>/Constant'
             *  RelationalOperator: '<S540>/Compare'
             *  S-Function (sfix_bitop): '<S537>/az_cmd valid'
             */
            rtb_Add4_a1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S531>/Index Vector' incorporates:
             *  Product: '<S538>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                rtb_Add4_a1 + (rtb_VectorConcatenate[rtb_n + 3] *
                               rtb_Integrator1_bx + rtb_VectorConcatenate[rtb_n]
                               * d);
            }
            break;

           case 1:
            /* SignalConversion: '<S612>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S612>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S612>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S601>/Data Store Read'
             *  Gain: '<S610>/Gain'
             *  Trigonometry: '<S612>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S612>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S601>/Data Store Read'
             *  Gain: '<S610>/Gain'
             *  Trigonometry: '<S612>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S612>/Gain' incorporates:
             *  Trigonometry: '<S612>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -rtb_u_b;

            /* SignalConversion: '<S612>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S612>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S612>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_u_b;

            /* Trigonometry: '<S612>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_o4;

            /* SignalConversion: '<S613>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S613>/Constant4'
             */
            rtb_MatrixConcatenate1_a[5] = 0.0F;

            /* Gain: '<S611>/Gain' incorporates:
             *  DataStoreRead: '<S601>/Data Store Read'
             *  Gain: '<S543>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S531>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S601>/Subtract'
             */
            rtb_Saturation1_p5 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S613>/Trigonometric Function3' incorporates:
             *  Gain: '<S611>/Gain'
             *  Trigonometry: '<S613>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(rtb_Saturation1_p5);
            rtb_MatrixConcatenate1_a[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S613>/Trigonometric Function2' incorporates:
             *  Gain: '<S611>/Gain'
             *  Trigonometry: '<S613>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(rtb_Saturation1_p5);

            /* Gain: '<S613>/Gain' incorporates:
             *  Trigonometry: '<S613>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_a[3] = -rtb_u_b;

            /* SignalConversion: '<S613>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S613>/Constant3'
             */
            rtb_MatrixConcatenate1_a[2] = 0.0F;

            /* Trigonometry: '<S613>/Trigonometric Function' */
            rtb_MatrixConcatenate1_a[1] = rtb_u_b;

            /* Trigonometry: '<S613>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_a[0] = rtb_Saturation_o4;

            /* RelationalOperator: '<S617>/Compare' incorporates:
             *  Constant: '<S617>/Constant'
             *  S-Function (sfix_bitop): '<S614>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S614>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S614>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S615>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S615>/Data Type Conversion'
             *  Gain: '<S615>/Gain2'
             *  Gain: '<S618>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S621>/Multiply1'
             *  Product: '<S621>/Multiply2'
             *  Product: '<S621>/Multiply3'
             *  Product: '<S621>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S618>/Sum1'
             *  Sum: '<S621>/Sum2'
             *  Sum: '<S621>/Sum3'
             */
            rtb_MatrixConcatenate1_a_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S602>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S612>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S613>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S601>/Sum' incorporates:
             *  DataStoreRead: '<S601>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            d = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S612>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S613>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S601>/Sum' incorporates:
             *  DataStoreRead: '<S601>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Integrator1_bx = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S612>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S613>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S601>/Sum' incorporates:
             *  DataStoreRead: '<S601>/Data Store Read'
             *  Gain: '<S603>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Add4_a1 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S606>/Compare' incorporates:
             *  Constant: '<S606>/Constant'
             *  S-Function (sfix_bitop): '<S599>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S607>/Compare' incorporates:
             *  Constant: '<S607>/Constant'
             *  S-Function (sfix_bitop): '<S599>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S601>/Sum2' incorporates:
               *  Product: '<S601>/Multiply2'
               *  Switch: '<S602>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_a_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              /* Product: '<S601>/Multiply' incorporates:
               *  Logic: '<S599>/Logical Operator'
               *  Product: '<S601>/Multiply2'
               *  Sum: '<S601>/Sum'
               *  Sum: '<S601>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? rtb_u_b -
                ((rtb_VectorConcatenate[rtb_n + 3] * rtb_Integrator1_bx +
                  rtb_VectorConcatenate[rtb_n] * d) +
                 rtb_VectorConcatenate[rtb_n + 6] * rtb_Add4_a1) : 0.0F;
            }

            /* SignalConversion: '<S544>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S544>/Constant4'
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S544>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_Saturation1_p5);

            /* Gain: '<S544>/Gain' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             *  Trigonometry: '<S544>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_Saturation1_p5);

            /* SignalConversion: '<S544>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S544>/Constant3'
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S544>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_Saturation1_p5);

            /* Trigonometry: '<S544>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S531>/Index Vector'
             */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_Saturation1_p5);

            /* Product: '<S531>/Multiply' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S540>/Compare' incorporates:
             *  Constant: '<S540>/Constant'
             *  S-Function (sfix_bitop): '<S537>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S537>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S537>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S544>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S531>/Index Vector'
               */
              rtb_VectorConcatenate[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S531>/Multiply' */
              rtb_MatrixConcatenate1_a_0[rtb_n] = tmp[rtb_n] ?
                rtb_Switch_c2[rtb_n] : 0.0F;
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_MatrixConcatenate1_a[rtb_n + 6] * rtb_Switch_ov[2] +
                (rtb_MatrixConcatenate1_a[rtb_n + 3] * rtb_Switch_ov[1] +
                 rtb_MatrixConcatenate1_a[rtb_n] * rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S531>/Index Vector' incorporates:
             *  Product: '<S539>/Multiply3'
             *  Product: '<S601>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                rtb_MatrixConcatenate1_a_0[2] + (rtb_VectorConcatenate[rtb_n + 3]
                * rtb_MatrixConcatenate1_a_0[1] + rtb_VectorConcatenate[rtb_n] *
                rtb_MatrixConcatenate1_a_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S605>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S605>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S605>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S605>/Gain' incorporates:
             *  Gain: '<S604>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S605>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S605>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S605>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S605>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S605>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* S-Function (sfix_bitop): '<S614>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S599>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S617>/Compare' incorporates:
             *  Constant: '<S617>/Constant'
             *  S-Function (sfix_bitop): '<S614>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S614>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S599>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S617>/Compare' incorporates:
             *  Constant: '<S617>/Constant'
             *  S-Function (sfix_bitop): '<S614>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S614>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S599>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S617>/Compare' incorporates:
             *  Constant: '<S617>/Constant'
             *  S-Function (sfix_bitop): '<S614>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S615>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S615>/Data Type Conversion'
             *  Gain: '<S615>/Gain2'
             *  Gain: '<S618>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S621>/Multiply1'
             *  Product: '<S621>/Multiply2'
             *  Product: '<S621>/Multiply3'
             *  Product: '<S621>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S618>/Sum1'
             *  Sum: '<S621>/Sum2'
             *  Sum: '<S621>/Sum3'
             */
            rtb_MatrixConcatenate1_a_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S602>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S605>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Sum: '<S598>/Sum' incorporates:
             *  DataStoreRead: '<S598>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation_o4 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S605>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Sum: '<S598>/Sum' incorporates:
             *  DataStoreRead: '<S598>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation1_p5 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S605>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Sum: '<S598>/Sum' incorporates:
             *  DataStoreRead: '<S598>/Data Store Read'
             *  Gain: '<S603>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Add4_a1 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S606>/Compare' incorporates:
             *  Constant: '<S606>/Constant'
             *  S-Function (sfix_bitop): '<S599>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S599>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S607>/Compare' incorporates:
             *  Constant: '<S607>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S598>/Sum2' incorporates:
             *  Logic: '<S599>/Logical Operator'
             *  Product: '<S598>/Multiply'
             *  Product: '<S598>/Multiply2'
             *  Sum: '<S598>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S602>/Switch' incorporates:
               *  Product: '<S598>/Multiply2'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_a_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              rtb_TmpSignalConversionAtMultip[rtb_n] = tmp_0[rtb_n] ||
                tmp_1[rtb_n] ? rtb_u_b - ((rtb_VectorConcatenate[rtb_n + 3] *
                rtb_Saturation1_p5 + rtb_VectorConcatenate[rtb_n] *
                rtb_Saturation_o4) + rtb_VectorConcatenate[rtb_n + 6] *
                rtb_Add4_a1) : 0.0F;
            }

            /* End of Sum: '<S598>/Sum2' */

            /* MultiPortSwitch: '<S531>/Index Vector' incorporates:
             *  Constant: '<S540>/Constant'
             *  Product: '<S531>/Multiply'
             *  RelationalOperator: '<S540>/Compare'
             *  S-Function (sfix_bitop): '<S537>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S537>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S537>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* Sum: '<S592>/Sum1' incorporates:
           *  Constant: '<S592>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S592>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S593>/Abs' */
          rtb_Saturation_o4 = fabsf(rtb_a_bx);

          /* Switch: '<S593>/Switch' incorporates:
           *  Constant: '<S593>/Constant'
           *  Constant: '<S594>/Constant'
           *  Product: '<S593>/Multiply'
           *  RelationalOperator: '<S594>/Compare'
           *  Sum: '<S593>/Subtract'
           */
          if (rtb_Saturation_o4 > 3.14159274F) {
            /* Signum: '<S593>/Sign' */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* End of Signum: '<S593>/Sign' */
            rtb_a_bx *= rtb_Saturation_o4 - 6.28318548F;
          }

          /* End of Switch: '<S593>/Switch' */

          /* Saturate: '<S592>/Saturation' */
          if (rtb_a_bx > 0.314159274F) {
            rtb_a_bx = 0.314159274F;
          } else {
            if (rtb_a_bx < -0.314159274F) {
              rtb_a_bx = -0.314159274F;
            }
          }

          /* End of Saturate: '<S592>/Saturation' */

          /* Gain: '<S589>/Gain2' */
          rtb_a_bx *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S533>/Sum' incorporates:
           *  Constant: '<S591>/Constant'
           *  Constant: '<S595>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S589>/Multiply2'
           *  Product: '<S590>/Multiply1'
           *  RelationalOperator: '<S591>/Compare'
           *  RelationalOperator: '<S595>/Compare'
           *  S-Function (sfix_bitop): '<S589>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S590>/psi_rate_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_u_b = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_a_bx : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S596>/Gain1' */
          rtb_Saturation_o4 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMultip[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMultip
            [1];

          /* Gain: '<S596>/Gain2' */
          rtb_a_bx = FMS_PARAM.Z_P * rtb_TmpSignalConversionAtMultip[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S597>/Index Vector' incorporates:
           *  Constant: '<S633>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S597>/Multiply'
           *  Product: '<S630>/Multiply'
           *  Product: '<S631>/Multiply3'
           *  RelationalOperator: '<S633>/Compare'
           *  S-Function (sfix_bitop): '<S629>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S629>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S629>/w_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S635>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S635>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S635>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S635>/Gain' incorporates:
             *  Gain: '<S634>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S635>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S635>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S635>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S635>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S635>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S635>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S597>/Multiply' incorporates:
             *  Constant: '<S633>/Constant'
             *  RelationalOperator: '<S633>/Compare'
             *  S-Function (sfix_bitop): '<S629>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S635>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S597>/Multiply' incorporates:
             *  Constant: '<S633>/Constant'
             *  RelationalOperator: '<S633>/Compare'
             *  S-Function (sfix_bitop): '<S629>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S635>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S597>/Multiply' incorporates:
             *  Constant: '<S633>/Constant'
             *  RelationalOperator: '<S633>/Compare'
             *  S-Function (sfix_bitop): '<S629>/w_cmd valid'
             */
            rtb_Add4_a1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Add4_a1 +
                (rtb_VectorConcatenate[rtb_n + 3] * rtb_Integrator1_bx +
                 rtb_VectorConcatenate[rtb_n] * d);
            }
            break;

           case 1:
            /* SignalConversion: '<S637>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S637>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Gain: '<S636>/Gain' incorporates:
             *  DataStoreRead: '<S631>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S631>/Subtract'
             */
            rtb_Saturation_ga = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S637>/Trigonometric Function3' incorporates:
             *  Gain: '<S636>/Gain'
             */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_Saturation_ga);

            /* Gain: '<S637>/Gain' incorporates:
             *  Gain: '<S636>/Gain'
             *  Trigonometry: '<S637>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S637>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S637>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S637>/Trigonometric Function' incorporates:
             *  Gain: '<S636>/Gain'
             */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_Saturation_ga);

            /* Trigonometry: '<S637>/Trigonometric Function1' incorporates:
             *  Gain: '<S636>/Gain'
             */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S637>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gjo[0];

            /* Product: '<S597>/Multiply' incorporates:
             *  Constant: '<S633>/Constant'
             *  RelationalOperator: '<S633>/Compare'
             *  S-Function (sfix_bitop): '<S629>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S637>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gjo[1];

            /* Product: '<S597>/Multiply' incorporates:
             *  Constant: '<S633>/Constant'
             *  RelationalOperator: '<S633>/Compare'
             *  S-Function (sfix_bitop): '<S629>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S637>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gjo[2];

            /* Product: '<S597>/Multiply' incorporates:
             *  Constant: '<S633>/Constant'
             *  RelationalOperator: '<S633>/Compare'
             *  S-Function (sfix_bitop): '<S629>/w_cmd valid'
             */
            rtb_Add4_a1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Add4_a1 +
                (rtb_VectorConcatenate[rtb_n + 3] * rtb_Integrator1_bx +
                 rtb_VectorConcatenate[rtb_n] * d);
            }
            break;

           default:
            rtb_TmpSignalConversionAtMultip[0] = (FMS_U.Auto_Cmd.cmd_mask &
              8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd : 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = (FMS_U.Auto_Cmd.cmd_mask &
              16384U) > 0U ? FMS_U.Auto_Cmd.v_cmd : 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = (FMS_U.Auto_Cmd.cmd_mask &
              32768U) > 0U ? FMS_U.Auto_Cmd.w_cmd : 0.0F;
            break;
          }

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMultip[0] += rtb_Saturation_o4;
          rtb_TmpSignalConversionAtMultip[1] += rtb_Saturation1_p5;

          /* Sum: '<S534>/Sum1' */
          rtb_Saturation_ga = rtb_a_bx + rtb_TmpSignalConversionAtMultip[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S552>/Switch' incorporates:
           *  Constant: '<S567>/Constant'
           *  Constant: '<S569>/Constant'
           *  Constant: '<S570>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S567>/Compare'
           *  RelationalOperator: '<S569>/Compare'
           *  RelationalOperator: '<S570>/Compare'
           *  S-Function (sfix_bitop): '<S552>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S552>/y_v_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S552>/Logical Operator' incorporates:
             *  Constant: '<S568>/Constant'
             *  Constant: '<S569>/Constant'
             *  Constant: '<S570>/Constant'
             *  RelationalOperator: '<S568>/Compare'
             *  RelationalOperator: '<S569>/Compare'
             *  RelationalOperator: '<S570>/Compare'
             *  S-Function (sfix_bitop): '<S552>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S552>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S552>/y_v_cmd'
             */
            rtb_Compare_at = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_at;
          } else {
            rtb_Compare_at = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U)
              > 0U);
          }

          /* End of Switch: '<S552>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S532>/u_cmd_valid' */
          /* MATLAB Function: '<S564>/bit_shift' incorporates:
           *  DataTypeConversion: '<S532>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_at << 6);

          /* End of Outputs for SubSystem: '<S532>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S532>/v_cmd_valid' */
          /* MATLAB Function: '<S565>/bit_shift' incorporates:
           *  DataTypeConversion: '<S532>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S532>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S553>/Switch' incorporates:
           *  Constant: '<S572>/Constant'
           *  Constant: '<S573>/Constant'
           *  Constant: '<S575>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S572>/Compare'
           *  RelationalOperator: '<S573>/Compare'
           *  RelationalOperator: '<S575>/Compare'
           *  S-Function (sfix_bitop): '<S553>/ax_cmd'
           *  S-Function (sfix_bitop): '<S553>/ay_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S553>/Logical Operator' incorporates:
             *  Constant: '<S573>/Constant'
             *  Constant: '<S575>/Constant'
             *  RelationalOperator: '<S573>/Compare'
             *  RelationalOperator: '<S575>/Compare'
             *  S-Function (sfix_bitop): '<S553>/ax_cmd'
             *  S-Function (sfix_bitop): '<S553>/ay_cmd'
             */
            rtb_Compare_at = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_at;
          } else {
            rtb_Compare_at = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S553>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S449>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S449>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S449>/Bus Assignment' incorporates:
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

          /* Saturate: '<S533>/Saturation' */
          if (rtb_u_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_u_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S533>/Saturation' */

          /* Saturate: '<S534>/Saturation2' */
          if (rtb_TmpSignalConversionAtMultip[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_TmpSignalConversionAtMultip[0] < -FMS_PARAM.VEL_XY_LIM)
          {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMultip[0];
          }

          /* End of Saturate: '<S534>/Saturation2' */

          /* Saturate: '<S534>/Saturation1' */
          if (rtb_TmpSignalConversionAtMultip[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_TmpSignalConversionAtMultip[1] < -FMS_PARAM.VEL_XY_LIM)
          {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMultip[1];
          }

          /* End of Saturate: '<S534>/Saturation1' */

          /* Saturate: '<S534>/Saturation3' */
          if (rtb_Saturation_ga > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_ga < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S449>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;
          }

          /* End of Saturate: '<S534>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S532>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S532>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S532>/throttle_cmd_valid' */
          /* BusAssignment: '<S449>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S545>/Constant'
           *  Constant: '<S546>/Constant'
           *  Constant: '<S547>/Constant'
           *  Constant: '<S548>/Constant'
           *  Constant: '<S549>/Constant'
           *  Constant: '<S550>/Constant'
           *  Constant: '<S551>/Constant'
           *  Constant: '<S571>/Constant'
           *  Constant: '<S574>/Constant'
           *  DataTypeConversion: '<S532>/Data Type Conversion10'
           *  DataTypeConversion: '<S532>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S554>/bit_shift'
           *  MATLAB Function: '<S555>/bit_shift'
           *  MATLAB Function: '<S556>/bit_shift'
           *  MATLAB Function: '<S558>/bit_shift'
           *  MATLAB Function: '<S559>/bit_shift'
           *  MATLAB Function: '<S560>/bit_shift'
           *  MATLAB Function: '<S561>/bit_shift'
           *  MATLAB Function: '<S562>/bit_shift'
           *  MATLAB Function: '<S563>/bit_shift'
           *  MATLAB Function: '<S566>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S545>/Compare'
           *  RelationalOperator: '<S546>/Compare'
           *  RelationalOperator: '<S547>/Compare'
           *  RelationalOperator: '<S548>/Compare'
           *  RelationalOperator: '<S549>/Compare'
           *  RelationalOperator: '<S550>/Compare'
           *  RelationalOperator: '<S551>/Compare'
           *  RelationalOperator: '<S571>/Compare'
           *  RelationalOperator: '<S574>/Compare'
           *  S-Function (sfix_bitop): '<S532>/p_cmd'
           *  S-Function (sfix_bitop): '<S532>/phi_cmd'
           *  S-Function (sfix_bitop): '<S532>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S532>/q_cmd'
           *  S-Function (sfix_bitop): '<S532>/r_cmd'
           *  S-Function (sfix_bitop): '<S532>/theta_cmd'
           *  S-Function (sfix_bitop): '<S532>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S552>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S553>/az_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           *  Sum: '<S532>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_aw) +
            rtb_y_cc) + (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
            (rtb_Compare_at << 9)) + (rtb_FixPtRelationalOperator_me << 10)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S532>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S532>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S532>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S337>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S337>/Mission' incorporates:
             *  ActionPort: '<S448>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S337>/Switch Case' incorporates:
             *  UnitDelay: '<S451>/Delay Input1'
             *
             * Block description for '<S451>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S337>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S337>/Mission' incorporates:
             *  ActionPort: '<S448>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S448>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S337>/Switch Case' incorporates:
             *  Chart: '<S490>/Motion Status'
             *  Chart: '<S500>/Motion State'
             *  Delay: '<S456>/Delay'
             *  Delay: '<S478>/Delay'
             *  DiscreteIntegrator: '<S459>/Integrator'
             *  DiscreteIntegrator: '<S459>/Integrator1'
             *  DiscreteIntegrator: '<S474>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S479>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S526>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S448>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S337>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S337>/Mission' incorporates:
           *  ActionPort: '<S448>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S451>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S451>/Delay Input1'
           *
           * Block description for '<S451>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S448>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S452>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S499>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S489>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S478>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S479>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S474>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S526>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S456>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S459>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S459>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S500>/Motion State' */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S490>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S478>/Delay' incorporates:
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
          /* Switch: '<S474>/Switch2' incorporates:
           *  Constant: '<S474>/vel'
           *  Constant: '<S483>/Constant'
           *  RelationalOperator: '<S483>/Compare'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S474>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S479>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S451>/Delay Input1'
           *
           * Block description for '<S451>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S473>/Compare' incorporates:
           *  Constant: '<S530>/Constant'
           *  RelationalOperator: '<S530>/Compare'
           *  UnitDelay: '<S451>/Delay Input1'
           *
           * Block description for '<S451>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S474>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S500>/Motion State' incorporates:
           *  Constant: '<S500>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S500>/Square'
           *  Math: '<S500>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S500>/Sqrt'
           *  Sum: '<S500>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S499>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S509>/Integrator1'
           *  Gain: '<S503>/Gain6'
           *  Gain: '<S507>/Gain'
           *  Gain: '<S508>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S509>/Subtract'
           *  Sum: '<S510>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S499>/Hold Control' incorporates:
               *  ActionPort: '<S502>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S499>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S499>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S499>/Hold Control' incorporates:
             *  ActionPort: '<S502>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S499>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S499>/Brake Control' incorporates:
             *  ActionPort: '<S501>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S499>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S499>/Move Control' incorporates:
               *  ActionPort: '<S503>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S499>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S509>/Integrator'
               *  DiscreteIntegrator: '<S509>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S499>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S499>/Move Control' incorporates:
             *  ActionPort: '<S503>/Action Port'
             */
            /* SignalConversion: '<S503>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S510>/Multiply1' incorporates:
             *  Constant: '<S510>/const1'
             *  DiscreteIntegrator: '<S509>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S503>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S510>/Multiply1' incorporates:
             *  Constant: '<S510>/const1'
             *  DiscreteIntegrator: '<S509>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S507>/Dead Zone' incorporates:
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

            /* Sum: '<S510>/Add' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator1'
             *  Gain: '<S503>/Gain6'
             *  Gain: '<S507>/Gain'
             *  Sum: '<S509>/Subtract'
             */
            rtb_Divide_f0[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S508>/Dead Zone' incorporates:
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

            /* Sum: '<S510>/Add' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator1'
             *  Gain: '<S503>/Gain6'
             *  Gain: '<S508>/Gain'
             *  Sum: '<S509>/Subtract'
             */
            rtb_Divide_f0[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S507>/Dead Zone' incorporates:
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

            /* Signum: '<S510>/Sign' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator1'
             *  Gain: '<S503>/Gain6'
             *  Gain: '<S507>/Gain'
             *  Sum: '<S509>/Subtract'
             *  Sum: '<S510>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S510>/Add2' incorporates:
             *  Abs: '<S510>/Abs'
             *  Gain: '<S510>/Gain'
             *  Gain: '<S510>/Gain1'
             *  Product: '<S510>/Multiply2'
             *  Product: '<S510>/Multiply3'
             *  Signum: '<S510>/Sign'
             *  Sqrt: '<S510>/Sqrt'
             *  Sum: '<S510>/Add1'
             *  Sum: '<S510>/Subtract'
             */
            rtb_Add4_a1 = (sqrtf((8.0F * fabsf(rtb_Divide_f0[0]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Saturation1_d +
              rtb_Subtract_hb[0];

            /* Sum: '<S510>/Add3' incorporates:
             *  Signum: '<S510>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_f0[0] + FMS_ConstB.d_oe;

            /* Sum: '<S510>/Subtract1' incorporates:
             *  Signum: '<S510>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_f0[0] - FMS_ConstB.d_oe;

            /* Signum: '<S510>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S510>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S510>/Add5' incorporates:
             *  Gain: '<S510>/Gain2'
             *  Product: '<S510>/Multiply4'
             *  Signum: '<S510>/Sign'
             *  Sum: '<S510>/Add2'
             *  Sum: '<S510>/Add4'
             *  Sum: '<S510>/Subtract2'
             */
            rtb_Add4_a1 += ((rtb_Divide_f0[0] - rtb_Add4_a1) + rtb_Subtract_hb[0])
              * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F);

            /* Update for DiscreteIntegrator: '<S509>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S510>/Sign4' incorporates:
             *  Sum: '<S510>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Add4_a1 - FMS_ConstB.d_oe;

            /* Signum: '<S510>/Sign3' incorporates:
             *  Sum: '<S510>/Add6'
             */
            rtb_Saturation1_d = rtb_Add4_a1 + FMS_ConstB.d_oe;

            /* Signum: '<S510>/Sign5' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Add4_a1 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Add4_a1;
            }

            /* Signum: '<S510>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S510>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S510>/Sign6' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Add4_a1 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Add4_a1;
            }

            /* Update for DiscreteIntegrator: '<S509>/Integrator' incorporates:
             *  Constant: '<S510>/const'
             *  Gain: '<S510>/Gain3'
             *  Product: '<S510>/Divide'
             *  Product: '<S510>/Multiply5'
             *  Product: '<S510>/Multiply6'
             *  Sum: '<S510>/Subtract4'
             *  Sum: '<S510>/Subtract5'
             *  Sum: '<S510>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Add4_a1 / FMS_ConstB.d_oe -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_g * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_u_b * 58.836F) * 0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S508>/Dead Zone' incorporates:
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

            /* Signum: '<S510>/Sign' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator1'
             *  Gain: '<S503>/Gain6'
             *  Gain: '<S508>/Gain'
             *  Sum: '<S509>/Subtract'
             *  Sum: '<S510>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S510>/Add2' incorporates:
             *  Abs: '<S510>/Abs'
             *  Gain: '<S510>/Gain'
             *  Gain: '<S510>/Gain1'
             *  Product: '<S510>/Multiply2'
             *  Product: '<S510>/Multiply3'
             *  Signum: '<S510>/Sign'
             *  Sqrt: '<S510>/Sqrt'
             *  Sum: '<S510>/Add1'
             *  Sum: '<S510>/Subtract'
             */
            rtb_Add4_a1 = (sqrtf((8.0F * fabsf(rtb_Divide_f0[1]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Saturation1_d +
              rtb_Subtract_hb[1];

            /* Sum: '<S510>/Add3' incorporates:
             *  Signum: '<S510>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_f0[1] + FMS_ConstB.d_oe;

            /* Sum: '<S510>/Subtract1' incorporates:
             *  Signum: '<S510>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_f0[1] - FMS_ConstB.d_oe;

            /* Signum: '<S510>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S510>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S510>/Add5' incorporates:
             *  Gain: '<S510>/Gain2'
             *  Product: '<S510>/Multiply4'
             *  Signum: '<S510>/Sign'
             *  Sum: '<S510>/Add2'
             *  Sum: '<S510>/Add4'
             *  Sum: '<S510>/Subtract2'
             */
            rtb_Add4_a1 += ((rtb_Divide_f0[1] - rtb_Add4_a1) + rtb_Subtract_hb[1])
              * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F);

            /* Update for DiscreteIntegrator: '<S509>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S509>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S510>/Sign4' incorporates:
             *  Sum: '<S510>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Add4_a1 - FMS_ConstB.d_oe;

            /* Signum: '<S510>/Sign3' incorporates:
             *  Sum: '<S510>/Add6'
             */
            rtb_Saturation1_d = rtb_Add4_a1 + FMS_ConstB.d_oe;

            /* Signum: '<S510>/Sign5' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Add4_a1 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Add4_a1;
            }

            /* Signum: '<S510>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S510>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S510>/Sign6' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Add4_a1 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Add4_a1;
            }

            /* Update for DiscreteIntegrator: '<S509>/Integrator' incorporates:
             *  Constant: '<S510>/const'
             *  Gain: '<S510>/Gain3'
             *  Product: '<S510>/Divide'
             *  Product: '<S510>/Multiply5'
             *  Product: '<S510>/Multiply6'
             *  Sum: '<S510>/Subtract4'
             *  Sum: '<S510>/Subtract5'
             *  Sum: '<S510>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Add4_a1 / FMS_ConstB.d_oe -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_g * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_u_b * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S499>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S499>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S490>/Motion Status' incorporates:
           *  Abs: '<S490>/Abs'
           *  Constant: '<S490>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S489>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
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
              /* SystemReset for IfAction SubSystem: '<S489>/Hold Control' incorporates:
               *  ActionPort: '<S492>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S489>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S489>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S489>/Hold Control' incorporates:
             *  ActionPort: '<S492>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S489>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S489>/Brake Control' incorporates:
             *  ActionPort: '<S491>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S489>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S489>/Move Control' incorporates:
               *  ActionPort: '<S493>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S489>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S496>/Integrator'
               *  DiscreteIntegrator: '<S496>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S489>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S489>/Move Control' incorporates:
             *  ActionPort: '<S493>/Action Port'
             */
            /* Product: '<S497>/Multiply1' incorporates:
             *  Constant: '<S497>/const1'
             *  DiscreteIntegrator: '<S496>/Integrator'
             */
            rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S495>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S495>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S497>/Add' incorporates:
             *  DiscreteIntegrator: '<S496>/Integrator1'
             *  Gain: '<S493>/Gain1'
             *  Gain: '<S495>/Gain'
             *  Sum: '<S496>/Subtract'
             */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_u_b * -FMS_PARAM.VEL_Z_LIM) +
              rtb_Saturation_ga;

            /* Signum: '<S497>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Saturation1_d;
            }

            /* End of Signum: '<S497>/Sign' */

            /* Sum: '<S497>/Add2' incorporates:
             *  Abs: '<S497>/Abs'
             *  Gain: '<S497>/Gain'
             *  Gain: '<S497>/Gain1'
             *  Product: '<S497>/Multiply2'
             *  Product: '<S497>/Multiply3'
             *  Sqrt: '<S497>/Sqrt'
             *  Sum: '<S497>/Add1'
             *  Sum: '<S497>/Subtract'
             */
            rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_oc)
                             * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_o4 + rtb_Saturation_ga;

            /* Sum: '<S497>/Add4' */
            rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) +
              rtb_Saturation_ga;

            /* Sum: '<S497>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_oc;

            /* Sum: '<S497>/Subtract1' */
            rtb_Saturation1_d -= FMS_ConstB.d_oc;

            /* Signum: '<S497>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S497>/Sign1' */

            /* Signum: '<S497>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S497>/Sign2' */

            /* Sum: '<S497>/Add5' incorporates:
             *  Gain: '<S497>/Gain2'
             *  Product: '<S497>/Multiply4'
             *  Sum: '<S497>/Subtract2'
             */
            rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
              rtb_Saturation_o4;

            /* SignalConversion: '<S493>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S496>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S496>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S496>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S497>/Subtract3' */
            rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_oc;

            /* Sum: '<S497>/Add6' */
            rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_oc;

            /* Signum: '<S497>/Sign5' incorporates:
             *  Signum: '<S497>/Sign6'
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_o4 = -1.0F;

              /* Signum: '<S497>/Sign6' */
              rtb_Add4_a1 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Saturation_o4 = 1.0F;

              /* Signum: '<S497>/Sign6' */
              rtb_Add4_a1 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_u_b;

              /* Signum: '<S497>/Sign6' */
              rtb_Add4_a1 = rtb_u_b;
            }

            /* End of Signum: '<S497>/Sign5' */

            /* Signum: '<S497>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S497>/Sign3' */

            /* Signum: '<S497>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S497>/Sign4' */

            /* Update for DiscreteIntegrator: '<S496>/Integrator' incorporates:
             *  Constant: '<S497>/const'
             *  Gain: '<S497>/Gain3'
             *  Product: '<S497>/Divide'
             *  Product: '<S497>/Multiply5'
             *  Product: '<S497>/Multiply6'
             *  Sum: '<S497>/Subtract4'
             *  Sum: '<S497>/Subtract5'
             *  Sum: '<S497>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_u_b / FMS_ConstB.d_oc -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_j * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S489>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S489>/Switch Case' */

          /* Switch: '<S454>/Switch' incorporates:
           *  Product: '<S478>/Multiply'
           *  Sum: '<S478>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S499>/Saturation1' */
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

            /* End of Saturate: '<S499>/Saturation1' */

            /* Saturate: '<S489>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S489>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S478>/Sum' incorporates:
             *  Delay: '<S478>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S527>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S474>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S478>/Sum' incorporates:
             *  Delay: '<S478>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S474>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S486>/Sqrt' incorporates:
             *  Math: '<S486>/Square'
             *  Sum: '<S474>/Sum'
             *  Sum: '<S486>/Sum of Elements'
             */
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S529>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S529>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S529>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S528>/Gain' incorporates:
             *  DiscreteIntegrator: '<S526>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S526>/Add'
             */
            rtb_u_b = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S529>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_u_b);

            /* Gain: '<S529>/Gain' incorporates:
             *  Trigonometry: '<S529>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_u_b);

            /* SignalConversion: '<S529>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S529>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S529>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_u_b);

            /* Trigonometry: '<S529>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_u_b);

            /* Switch: '<S485>/Switch2' incorporates:
             *  Constant: '<S474>/Constant2'
             *  DiscreteIntegrator: '<S474>/Acceleration_Speed'
             *  RelationalOperator: '<S485>/LowerRelop1'
             *  RelationalOperator: '<S485>/UpperRelop'
             *  Switch: '<S485>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_u_b = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S485>/Switch' incorporates:
               *  Constant: '<S474>/Constant2'
               */
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S485>/Switch2' */

            /* Switch: '<S474>/Switch' */
            if (rtb_Saturation_ga > FMS_PARAM.L1) {
              rtb_Saturation1_d = d;
            } else {
              /* Gain: '<S474>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_Saturation_ga;

              /* Switch: '<S484>/Switch2' incorporates:
               *  Constant: '<S474>/Constant1'
               *  RelationalOperator: '<S484>/LowerRelop1'
               *  RelationalOperator: '<S484>/UpperRelop'
               *  Switch: '<S484>/Switch'
               */
              if (rtb_Saturation1_d > d) {
                rtb_Saturation1_d = d;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  /* Switch: '<S484>/Switch' incorporates:
                   *  Constant: '<S474>/Constant1'
                   */
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Switch: '<S484>/Switch2' */
            }

            /* End of Switch: '<S474>/Switch' */

            /* Switch: '<S474>/Switch1' incorporates:
             *  Sum: '<S474>/Sum1'
             */
            if (rtb_u_b - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = rtb_u_b;
            }

            /* End of Switch: '<S474>/Switch1' */

            /* Sum: '<S527>/Sum of Elements' incorporates:
             *  Math: '<S527>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Saturation_o4 *
              rtb_Saturation_o4;

            /* Math: '<S527>/Math Function1' incorporates:
             *  Sum: '<S527>/Sum of Elements'
             *
             * About '<S527>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_u_b = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_u_b = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S527>/Math Function1' */

            /* Switch: '<S527>/Switch' incorporates:
             *  Constant: '<S527>/Constant'
             *  Product: '<S527>/Product'
             */
            if (rtb_u_b > 0.0F) {
              rtb_Divide_bu[0] = rtb_Subtract_hb[0];
              rtb_Divide_bu[1] = rtb_Saturation_o4;
              rtb_Divide_bu[3] = rtb_u_b;
            } else {
              rtb_Divide_bu[0] = 0.0F;
              rtb_Divide_bu[1] = 0.0F;
              rtb_Divide_bu[3] = 1.0F;
            }

            /* End of Switch: '<S527>/Switch' */

            /* Product: '<S525>/Multiply2' incorporates:
             *  Product: '<S527>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_bu[0] / rtb_Divide_bu[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_bu[1] / rtb_Divide_bu[3];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S480>/Sum1' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_u_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S480>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_a1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S480>/Divide' incorporates:
             *  Math: '<S481>/Square'
             *  Math: '<S482>/Square'
             *  Sqrt: '<S481>/Sqrt'
             *  Sqrt: '<S482>/Sqrt'
             *  Sum: '<S480>/Sum'
             *  Sum: '<S480>/Sum1'
             *  Sum: '<S481>/Sum of Elements'
             *  Sum: '<S482>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Add4_a1 * rtb_Add4_a1 + rtb_a_bx * rtb_a_bx) /
              sqrtf(rtb_Saturation_o4 * rtb_Saturation_o4 + rtb_u_b * rtb_u_b);

            /* Saturate: '<S480>/Saturation' */
            if (rtb_u_b > 1.0F) {
              rtb_u_b = 1.0F;
            } else {
              if (rtb_u_b < 0.0F) {
                rtb_u_b = 0.0F;
              }
            }

            /* End of Saturate: '<S480>/Saturation' */

            /* Product: '<S478>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n +
                3] * rtb_Saturation1_d + rtb_VectorConcatenate[rtb_n] *
                rtb_Saturation_ga;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S471>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S480>/Multiply'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S471>/Sum2'
             *  Sum: '<S480>/Add'
             *  Sum: '<S480>/Subtract'
             */
            rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_b +
                        FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_MatrixConcatenate1_a_0[0];
            rtb_Switch_c2[1] = rtb_MatrixConcatenate1_a_0[1];

            /* Saturate: '<S471>/Saturation1' incorporates:
             *  Product: '<S478>/Multiply'
             */
            if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_u_b;
            }

            /* End of Saturate: '<S471>/Saturation1' */
          }

          /* End of Switch: '<S454>/Switch' */

          /* Delay: '<S456>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S459>/Integrator1' incorporates:
           *  Delay: '<S456>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S463>/Rem' incorporates:
           *  Constant: '<S463>/Constant1'
           *  DiscreteIntegrator: '<S459>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S458>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S463>/Switch' incorporates:
           *  Abs: '<S463>/Abs'
           *  Constant: '<S463>/Constant'
           *  Constant: '<S464>/Constant'
           *  Product: '<S463>/Multiply'
           *  RelationalOperator: '<S464>/Compare'
           *  Sum: '<S463>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S463>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S463>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S463>/Switch' */

          /* Gain: '<S458>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S458>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S458>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S452>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S452>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S452>/Bus Assignment' incorporates:
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

          /* Math: '<S520>/Math Function1'
           *
           * About '<S520>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S520>/Math Function1' */

          /* Switch: '<S520>/Switch' incorporates:
           *  Constant: '<S520>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S520>/Product'
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

          /* End of Switch: '<S520>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S452>/Sum' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_f0[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_f0[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S470>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S452>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S470>/Math Function' incorporates:
           *  Sum: '<S452>/Sum'
           */
          rtb_Square_dv[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_dv[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S470>/Sum of Elements' */
          rtb_u_b = rtb_Square_dv[0] + rtb_Square_dv[1];

          /* Math: '<S470>/Math Function1' incorporates:
           *  Sum: '<S470>/Sum of Elements'
           *
           * About '<S470>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S470>/Math Function1' */

          /* Switch: '<S470>/Switch' incorporates:
           *  Constant: '<S470>/Constant'
           *  Product: '<S470>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Integrator1_bx = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S470>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S476>/NearbyRefWP' incorporates:
           *  Constant: '<S452>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f0,
                          &rtb_u_b);

          /* MATLAB Function: '<S476>/SearchL1RefWP' incorporates:
           *  Constant: '<S452>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S476>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0],
                               &rtb_TmpSignalConversionAtMultip[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_dv);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S476>/Switch1' incorporates:
           *  Constant: '<S513>/Constant'
           *  RelationalOperator: '<S513>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_f0[0];
            rtb_P_ap[1] = rtb_Divide_f0[1];
          } else {
            /* RelationalOperator: '<S512>/Compare' incorporates:
             *  Constant: '<S512>/Constant'
             */
            rtb_Compare_at = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S476>/Switch' */
            if (!rtb_Compare_at) {
              rtb_P_ap[0] = rtb_Square_dv[0];
              rtb_P_ap[1] = rtb_Square_dv[1];
            }

            /* End of Switch: '<S476>/Switch' */
          }

          /* End of Switch: '<S476>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S477>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_a1 = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Add4_a1;
          rtb_Saturation_o4 = rtb_Add4_a1 * rtb_Add4_a1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S477>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S521>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_a1 = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S521>/Sum of Elements' incorporates:
           *  Math: '<S521>/Math Function'
           *  Sum: '<S519>/Sum of Elements'
           */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_a1 * rtb_Add4_a1;

          /* Math: '<S521>/Math Function1' incorporates:
           *  Sum: '<S521>/Sum of Elements'
           *
           * About '<S521>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S521>/Math Function1' */

          /* Switch: '<S521>/Switch' incorporates:
           *  Constant: '<S521>/Constant'
           *  Product: '<S521>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_P_ap[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Add4_a1;
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S521>/Switch' */

          /* Product: '<S520>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S523>/Sum of Elements' incorporates:
           *  Math: '<S523>/Math Function'
           *  SignalConversion: '<S523>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S523>/Math Function1' incorporates:
           *  Sum: '<S523>/Sum of Elements'
           *
           * About '<S523>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S523>/Math Function1' */

          /* Switch: '<S523>/Switch' incorporates:
           *  Constant: '<S523>/Constant'
           *  Product: '<S523>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_f0[1];
            rtb_Switch_c2[1] = rtb_Divide_f0[0];
            rtb_Switch_c2[2] = rtb_Saturation_o4;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S523>/Switch' */

          /* Product: '<S521>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S524>/Sum of Elements' incorporates:
           *  Math: '<S524>/Math Function'
           *  SignalConversion: '<S524>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S524>/Math Function1' incorporates:
           *  Sum: '<S524>/Sum of Elements'
           *
           * About '<S524>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S524>/Math Function1' */

          /* Switch: '<S524>/Switch' incorporates:
           *  Constant: '<S524>/Constant'
           *  Product: '<S524>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_Divide_f0[1];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Divide_f0[0];
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S524>/Switch' */

          /* Product: '<S524>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S523>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S470>/Divide' */
          rtb_Square_dv[0] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S524>/Divide' */
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S523>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S470>/Divide' */
          rtb_Square_dv[1] = rtb_Saturation1_d / rtb_Integrator1_bx;

          /* Sum: '<S522>/Subtract' incorporates:
           *  Product: '<S522>/Multiply'
           *  Product: '<S522>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_f0[0] * rtb_P_ap[1] - rtb_Divide_f0[1] *
            rtb_P_ap[0];

          /* Signum: '<S517>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S517>/Sign1' */

          /* Switch: '<S517>/Switch2' incorporates:
           *  Constant: '<S517>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S517>/Switch2' */

          /* DotProduct: '<S517>/Dot Product' */
          rtb_Add4_a1 = rtb_P_ap[0] * rtb_Divide_f0[0] + rtb_P_ap[1] *
            rtb_Divide_f0[1];

          /* Trigonometry: '<S517>/Acos' incorporates:
           *  DotProduct: '<S517>/Dot Product'
           */
          if (rtb_Add4_a1 > 1.0F) {
            rtb_Add4_a1 = 1.0F;
          } else {
            if (rtb_Add4_a1 < -1.0F) {
              rtb_Add4_a1 = -1.0F;
            }
          }

          /* Product: '<S517>/Multiply' incorporates:
           *  Trigonometry: '<S517>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Add4_a1);

          /* Saturate: '<S477>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S477>/Saturation' */

          /* Product: '<S477>/Divide' incorporates:
           *  Constant: '<S452>/L1'
           *  Constant: '<S477>/Constant'
           *  Gain: '<S477>/Gain'
           *  Math: '<S477>/Square'
           *  MinMax: '<S477>/Max'
           *  MinMax: '<S477>/Min'
           *  Product: '<S477>/Multiply1'
           *  Sqrt: '<S519>/Sqrt'
           *  Trigonometry: '<S477>/Sin'
           */
          rtb_Saturation1_p5 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S468>/Subtract' incorporates:
           *  Product: '<S468>/Multiply'
           *  Product: '<S468>/Multiply1'
           */
          rtb_Add4_a1 = rtb_Square_dv[0] * FMS_ConstB.Divide[1] - rtb_Square_dv
            [1] * FMS_ConstB.Divide[0];

          /* Signum: '<S457>/Sign1' */
          if (rtb_Add4_a1 < 0.0F) {
            rtb_Add4_a1 = -1.0F;
          } else {
            if (rtb_Add4_a1 > 0.0F) {
              rtb_Add4_a1 = 1.0F;
            }
          }

          /* End of Signum: '<S457>/Sign1' */

          /* Switch: '<S457>/Switch2' incorporates:
           *  Constant: '<S457>/Constant4'
           */
          if (rtb_Add4_a1 == 0.0F) {
            rtb_Add4_a1 = 1.0F;
          }

          /* End of Switch: '<S457>/Switch2' */

          /* DotProduct: '<S457>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide[0] * rtb_Square_dv[0] + FMS_ConstB.Divide
            [1] * rtb_Square_dv[1];

          /* Trigonometry: '<S457>/Acos' incorporates:
           *  DotProduct: '<S457>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S457>/Multiply' incorporates:
           *  Trigonometry: '<S457>/Acos'
           */
          rtb_Add4_a1 *= acosf(rtb_u_b);

          /* Math: '<S460>/Rem' incorporates:
           *  Constant: '<S460>/Constant1'
           *  Delay: '<S456>/Delay'
           *  Sum: '<S456>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Add4_a1 - FMS_DW.Delay_DSTATE_n,
            6.28318548F);

          /* Switch: '<S460>/Switch' incorporates:
           *  Abs: '<S460>/Abs'
           *  Constant: '<S460>/Constant'
           *  Constant: '<S466>/Constant'
           *  Product: '<S460>/Multiply'
           *  RelationalOperator: '<S466>/Compare'
           *  Sum: '<S460>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S460>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S460>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S460>/Switch' */

          /* Sum: '<S456>/Sum' incorporates:
           *  Delay: '<S456>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S465>/Multiply1' incorporates:
           *  Constant: '<S465>/const1'
           *  DiscreteIntegrator: '<S459>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S465>/Add' incorporates:
           *  DiscreteIntegrator: '<S459>/Integrator1'
           *  Sum: '<S459>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S465>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S465>/Sign' */

          /* Sum: '<S465>/Add2' incorporates:
           *  Abs: '<S465>/Abs'
           *  Gain: '<S465>/Gain'
           *  Gain: '<S465>/Gain1'
           *  Product: '<S465>/Multiply2'
           *  Product: '<S465>/Multiply3'
           *  Sqrt: '<S465>/Sqrt'
           *  Sum: '<S465>/Add1'
           *  Sum: '<S465>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_m) *
                           FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S465>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S465>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_m;

          /* Sum: '<S465>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_m;

          /* Signum: '<S465>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S465>/Sign1' */

          /* Signum: '<S465>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S465>/Sign2' */

          /* Sum: '<S465>/Add5' incorporates:
           *  Gain: '<S465>/Gain2'
           *  Product: '<S465>/Multiply4'
           *  Sum: '<S465>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S465>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_m;

          /* Sum: '<S465>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_m;

          /* Product: '<S465>/Divide' */
          rtb_Integrator1_bx = rtb_u_b / FMS_ConstB.d_m;

          /* Signum: '<S465>/Sign5' incorporates:
           *  Signum: '<S465>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_a_bx = -1.0F;

            /* Signum: '<S465>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_a_bx = 1.0F;

            /* Signum: '<S465>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_a_bx = rtb_u_b;

            /* Signum: '<S465>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S465>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S456>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_a1 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S461>/Rem' incorporates:
           *  Constant: '<S461>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Add4_a1, 6.28318548F);

          /* Switch: '<S461>/Switch' incorporates:
           *  Abs: '<S461>/Abs'
           *  Constant: '<S461>/Constant'
           *  Constant: '<S467>/Constant'
           *  Product: '<S461>/Multiply'
           *  RelationalOperator: '<S467>/Compare'
           *  Sum: '<S461>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S461>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Add4_a1 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Add4_a1 = 1.0F;
            } else {
              rtb_Add4_a1 = rtb_u_b;
            }

            /* End of Signum: '<S461>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Add4_a1;
          }

          /* End of Switch: '<S461>/Switch' */

          /* Abs: '<S454>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S478>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S479>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S472>/Constant'
           *  RelationalOperator: '<S472>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S479>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S474>/Acceleration_Speed' incorporates:
           *  Constant: '<S474>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S478>/Divide1' */
          rtb_u_b = rtb_Saturation1_p5 / d;

          /* Saturate: '<S478>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S478>/Saturation' */

          /* Update for DiscreteIntegrator: '<S526>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_u_b;

          /* Update for Delay: '<S456>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S459>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S459>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S465>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S465>/Sign3' */

          /* Signum: '<S465>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S465>/Sign4' */

          /* Update for DiscreteIntegrator: '<S459>/Integrator' incorporates:
           *  Constant: '<S465>/const'
           *  Gain: '<S465>/Gain3'
           *  Product: '<S465>/Multiply5'
           *  Product: '<S465>/Multiply6'
           *  Sum: '<S465>/Subtract4'
           *  Sum: '<S465>/Subtract5'
           *  Sum: '<S465>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S459>/Integrator' */
          /* End of Outputs for SubSystem: '<S448>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S451>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S451>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S337>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S337>/Unknown' incorporates:
           *  ActionPort: '<S450>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S337>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
         *  ActionPort: '<S336>/Action Port'
         */
        /* SwitchCase: '<S336>/Switch Case' */
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
            /* Disable for SwitchCase: '<S435>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S351>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S369>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S410>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S397>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S336>/Acro' incorporates:
           *  ActionPort: '<S341>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S341>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S341>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Gain: '<S346>/Gain'
           *  Gain: '<S346>/Gain1'
           *  Gain: '<S346>/Gain2'
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

          /* Saturate: '<S347>/Saturation' incorporates:
           *  Constant: '<S347>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  Sum: '<S347>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_u_b = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S347>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S347>/Constant5'
           *  Gain: '<S347>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S347>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_u_b), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S336>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S336>/Stabilize' incorporates:
             *  ActionPort: '<S344>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S336>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S431>/Integrator'
             *  DiscreteIntegrator: '<S431>/Integrator1'
             *  DiscreteIntegrator: '<S432>/Integrator'
             *  DiscreteIntegrator: '<S432>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S336>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S336>/Stabilize' incorporates:
             *  ActionPort: '<S344>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S336>/Switch Case' incorporates:
             *  Chart: '<S436>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S336>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S336>/Stabilize' incorporates:
           *  ActionPort: '<S344>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S426>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S436>/Motion State' incorporates:
           *  Abs: '<S436>/Abs'
           *  Abs: '<S436>/Abs1'
           *  Constant: '<S446>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S446>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S435>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S435>/Hold Control' incorporates:
               *  ActionPort: '<S438>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S435>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S435>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S435>/Hold Control' incorporates:
             *  ActionPort: '<S438>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S435>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S435>/Brake Control' incorporates:
             *  ActionPort: '<S437>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S435>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S435>/Move Control' incorporates:
               *  ActionPort: '<S439>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S435>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S435>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S435>/Move Control' incorporates:
             *  ActionPort: '<S439>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S435>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S435>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S428>/Switch' incorporates:
           *  Constant: '<S428>/Constant'
           *  Constant: '<S428>/Constant4'
           *  Constant: '<S428>/Constant5'
           *  Gain: '<S428>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S428>/Saturation'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S428>/Add'
           *  Sum: '<S428>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S428>/Saturation' */
              rtb_u_b = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S428>/Saturation' */
              rtb_u_b = 0.0F;
            } else {
              /* Saturate: '<S428>/Saturation' incorporates:
               *  Constant: '<S428>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S43>/Signal Copy2'
               *  Sum: '<S428>/Sum'
               */
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_u_b),
              65536.0F) + 1000U);
          }

          /* End of Switch: '<S428>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S344>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S344>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S426>/Data Type Conversion'
           *  DiscreteIntegrator: '<S431>/Integrator1'
           *  DiscreteIntegrator: '<S432>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S426>/Multiply'
           *  Product: '<S426>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S435>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S344>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S344>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S344>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S435>/Saturation' */

          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S434>/Multiply1' incorporates:
           *  Constant: '<S434>/const1'
           *  DiscreteIntegrator: '<S432>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S430>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S430>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S434>/Add' incorporates:
           *  DiscreteIntegrator: '<S432>/Integrator1'
           *  Gain: '<S426>/Gain1'
           *  Gain: '<S430>/Gain'
           *  Sum: '<S432>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S434>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S434>/Sign' */

          /* Sum: '<S434>/Add2' incorporates:
           *  Abs: '<S434>/Abs'
           *  Gain: '<S434>/Gain'
           *  Gain: '<S434>/Gain1'
           *  Product: '<S434>/Multiply2'
           *  Product: '<S434>/Multiply3'
           *  Sqrt: '<S434>/Sqrt'
           *  Sum: '<S434>/Add1'
           *  Sum: '<S434>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_g) * FMS_ConstB.d_g)
               - FMS_ConstB.d_g) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S434>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S434>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_g;

          /* Sum: '<S434>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_g;

          /* Signum: '<S434>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S434>/Sign1' */

          /* Signum: '<S434>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S434>/Sign2' */

          /* Sum: '<S434>/Add5' incorporates:
           *  Gain: '<S434>/Gain2'
           *  Product: '<S434>/Multiply4'
           *  Sum: '<S434>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S434>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_g;

          /* Sum: '<S434>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_g;

          /* Product: '<S434>/Divide' */
          rtb_Add4_a1 = d / FMS_ConstB.d_g;

          /* Signum: '<S434>/Sign5' incorporates:
           *  Signum: '<S434>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S434>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S434>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = d;

            /* Signum: '<S434>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S434>/Sign5' */

          /* Product: '<S433>/Multiply1' incorporates:
           *  Constant: '<S433>/const1'
           *  DiscreteIntegrator: '<S431>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S429>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S429>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S433>/Add' incorporates:
           *  DiscreteIntegrator: '<S431>/Integrator1'
           *  Gain: '<S426>/Gain'
           *  Gain: '<S429>/Gain'
           *  Sum: '<S431>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S433>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S433>/Sign' */

          /* Sum: '<S433>/Add2' incorporates:
           *  Abs: '<S433>/Abs'
           *  Gain: '<S433>/Gain'
           *  Gain: '<S433>/Gain1'
           *  Product: '<S433>/Multiply2'
           *  Product: '<S433>/Multiply3'
           *  Sqrt: '<S433>/Sqrt'
           *  Sum: '<S433>/Add1'
           *  Sum: '<S433>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_a) * FMS_ConstB.d_a)
               - FMS_ConstB.d_a) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S433>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S433>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_a;

          /* Sum: '<S433>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_a;

          /* Signum: '<S433>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S433>/Sign1' */

          /* Signum: '<S433>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S433>/Sign2' */

          /* Sum: '<S433>/Add5' incorporates:
           *  Gain: '<S433>/Gain2'
           *  Product: '<S433>/Multiply4'
           *  Sum: '<S433>/Subtract2'
           */
          d += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S431>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S431>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S432>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S432>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S434>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S434>/Sign3' */

          /* Signum: '<S434>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S434>/Sign4' */

          /* Update for DiscreteIntegrator: '<S432>/Integrator' incorporates:
           *  Constant: '<S434>/const'
           *  Gain: '<S434>/Gain3'
           *  Product: '<S434>/Multiply5'
           *  Product: '<S434>/Multiply6'
           *  Sum: '<S434>/Subtract4'
           *  Sum: '<S434>/Subtract5'
           *  Sum: '<S434>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Add4_a1 - rtb_Integrator1_bx) *
            FMS_ConstB.Gain4_o * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Sum: '<S433>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_a;

          /* Sum: '<S433>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_a;

          /* Signum: '<S433>/Sign5' incorporates:
           *  Signum: '<S433>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S433>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S433>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S433>/Sign6' */
            rtb_Add4_a1 = d;
          }

          /* End of Signum: '<S433>/Sign5' */

          /* Signum: '<S433>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S433>/Sign3' */

          /* Signum: '<S433>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S433>/Sign4' */

          /* Update for DiscreteIntegrator: '<S431>/Integrator' incorporates:
           *  Constant: '<S433>/const'
           *  Gain: '<S433>/Gain3'
           *  Product: '<S433>/Divide'
           *  Product: '<S433>/Multiply5'
           *  Product: '<S433>/Multiply6'
           *  Sum: '<S433>/Subtract4'
           *  Sum: '<S433>/Subtract5'
           *  Sum: '<S433>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((d / FMS_ConstB.d_a - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_k * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Add4_a1 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S336>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S336>/Altitude' incorporates:
             *  ActionPort: '<S342>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S336>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S365>/Integrator'
             *  DiscreteIntegrator: '<S365>/Integrator1'
             *  DiscreteIntegrator: '<S366>/Integrator'
             *  DiscreteIntegrator: '<S366>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S336>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S336>/Altitude' incorporates:
             *  ActionPort: '<S342>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S336>/Switch Case' incorporates:
             *  Chart: '<S352>/Motion Status'
             *  Chart: '<S370>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S336>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S336>/Altitude' incorporates:
           *  ActionPort: '<S342>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S352>/Motion Status' incorporates:
           *  Abs: '<S352>/Abs'
           *  Abs: '<S352>/Abs1'
           *  Constant: '<S361>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S361>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S351>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S351>/Hold Control' incorporates:
               *  ActionPort: '<S354>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S351>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S351>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S351>/Hold Control' incorporates:
             *  ActionPort: '<S354>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S351>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S351>/Brake Control' incorporates:
             *  ActionPort: '<S353>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S351>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S351>/Move Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S351>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S351>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S348>/Switch' incorporates:
           *  Constant: '<S348>/Constant'
           *  Saturate: '<S351>/Saturation1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_ga = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S351>/Saturation1' */
            rtb_Saturation_ga = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S351>/Saturation1' */
            rtb_Saturation_ga = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S351>/Saturation1' */
            rtb_Saturation_ga = FMS_B.Merge_l;
          }

          /* End of Switch: '<S348>/Switch' */

          /* Logic: '<S349>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S370>/Motion State' incorporates:
           *  Abs: '<S370>/Abs'
           *  Abs: '<S370>/Abs1'
           *  Constant: '<S380>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S380>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S369>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S369>/Hold Control' incorporates:
               *  ActionPort: '<S372>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S369>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_pi);

              /* End of SystemReset for SubSystem: '<S369>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S369>/Hold Control' incorporates:
             *  ActionPort: '<S372>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_pi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S369>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S369>/Brake Control' incorporates:
             *  ActionPort: '<S371>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S369>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S369>/Move Control' incorporates:
               *  ActionPort: '<S373>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S369>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S369>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S369>/Move Control' incorporates:
             *  ActionPort: '<S373>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S369>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S369>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S342>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S342>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S342>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S349>/Data Type Conversion'
           *  DiscreteIntegrator: '<S365>/Integrator1'
           *  DiscreteIntegrator: '<S366>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S349>/Multiply'
           *  Product: '<S349>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S369>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S342>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S342>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S342>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S369>/Saturation' */

          /* BusAssignment: '<S342>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;

          /* Product: '<S368>/Multiply1' incorporates:
           *  Constant: '<S368>/const1'
           *  DiscreteIntegrator: '<S366>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S364>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S364>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S368>/Add' incorporates:
           *  DiscreteIntegrator: '<S366>/Integrator1'
           *  Gain: '<S349>/Gain1'
           *  Gain: '<S364>/Gain'
           *  Sum: '<S366>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S368>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S368>/Sign' */

          /* Sum: '<S368>/Add2' incorporates:
           *  Abs: '<S368>/Abs'
           *  Gain: '<S368>/Gain'
           *  Gain: '<S368>/Gain1'
           *  Product: '<S368>/Multiply2'
           *  Product: '<S368>/Multiply3'
           *  Sqrt: '<S368>/Sqrt'
           *  Sum: '<S368>/Add1'
           *  Sum: '<S368>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_o) * FMS_ConstB.d_o)
               - FMS_ConstB.d_o) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S368>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S368>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_o;

          /* Sum: '<S368>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_o;

          /* Signum: '<S368>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S368>/Sign1' */

          /* Signum: '<S368>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S368>/Sign2' */

          /* Sum: '<S368>/Add5' incorporates:
           *  Gain: '<S368>/Gain2'
           *  Product: '<S368>/Multiply4'
           *  Sum: '<S368>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S368>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_o;

          /* Sum: '<S368>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_o;

          /* Product: '<S368>/Divide' */
          rtb_Add4_a1 = d / FMS_ConstB.d_o;

          /* Signum: '<S368>/Sign5' incorporates:
           *  Signum: '<S368>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S368>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S368>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = d;

            /* Signum: '<S368>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S368>/Sign5' */

          /* Product: '<S367>/Multiply1' incorporates:
           *  Constant: '<S367>/const1'
           *  DiscreteIntegrator: '<S365>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S363>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S363>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S367>/Add' incorporates:
           *  DiscreteIntegrator: '<S365>/Integrator1'
           *  Gain: '<S349>/Gain'
           *  Gain: '<S363>/Gain'
           *  Sum: '<S365>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S367>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S367>/Sign' */

          /* Sum: '<S367>/Add2' incorporates:
           *  Abs: '<S367>/Abs'
           *  Gain: '<S367>/Gain'
           *  Gain: '<S367>/Gain1'
           *  Product: '<S367>/Multiply2'
           *  Product: '<S367>/Multiply3'
           *  Sqrt: '<S367>/Sqrt'
           *  Sum: '<S367>/Add1'
           *  Sum: '<S367>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_c) * FMS_ConstB.d_c)
               - FMS_ConstB.d_c) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S367>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S367>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_c;

          /* Sum: '<S367>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_c;

          /* Signum: '<S367>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S367>/Sign1' */

          /* Signum: '<S367>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S367>/Sign2' */

          /* Sum: '<S367>/Add5' incorporates:
           *  Gain: '<S367>/Gain2'
           *  Product: '<S367>/Multiply4'
           *  Sum: '<S367>/Subtract2'
           */
          d += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S365>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S365>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S366>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S366>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S368>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S368>/Sign3' */

          /* Signum: '<S368>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S368>/Sign4' */

          /* Update for DiscreteIntegrator: '<S366>/Integrator' incorporates:
           *  Constant: '<S368>/const'
           *  Gain: '<S368>/Gain3'
           *  Product: '<S368>/Multiply5'
           *  Product: '<S368>/Multiply6'
           *  Sum: '<S368>/Subtract4'
           *  Sum: '<S368>/Subtract5'
           *  Sum: '<S368>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Add4_a1 - rtb_Integrator1_bx) *
            FMS_ConstB.Gain4_c * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Sum: '<S367>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_c;

          /* Sum: '<S367>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_c;

          /* Signum: '<S367>/Sign5' incorporates:
           *  Signum: '<S367>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S367>/Sign6' */
            rtb_Add4_a1 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S367>/Sign6' */
            rtb_Add4_a1 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S367>/Sign6' */
            rtb_Add4_a1 = d;
          }

          /* End of Signum: '<S367>/Sign5' */

          /* Signum: '<S367>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S367>/Sign3' */

          /* Signum: '<S367>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S367>/Sign4' */

          /* Update for DiscreteIntegrator: '<S365>/Integrator' incorporates:
           *  Constant: '<S367>/const'
           *  Gain: '<S367>/Gain3'
           *  Product: '<S367>/Divide'
           *  Product: '<S367>/Multiply5'
           *  Product: '<S367>/Multiply6'
           *  Sum: '<S367>/Subtract4'
           *  Sum: '<S367>/Subtract5'
           *  Sum: '<S367>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((d / FMS_ConstB.d_c - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_h * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Add4_a1 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S336>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S336>/Position' incorporates:
             *  ActionPort: '<S343>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S336>/Switch Case' incorporates:
             *  Chart: '<S386>/Motion Status'
             *  Chart: '<S398>/Motion State'
             *  Chart: '<S411>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S336>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S336>/Position' incorporates:
           *  ActionPort: '<S343>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S386>/Motion Status' incorporates:
           *  Abs: '<S386>/Abs'
           *  Abs: '<S386>/Abs1'
           *  Constant: '<S395>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S395>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S385>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S385>/Hold Control' incorporates:
               *  ActionPort: '<S388>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S385>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S385>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S385>/Hold Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S385>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S385>/Brake Control' incorporates:
             *  ActionPort: '<S387>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S385>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S385>/Move Control' incorporates:
             *  ActionPort: '<S389>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S385>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S385>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S398>/Motion State' incorporates:
           *  Abs: '<S398>/Abs'
           *  Abs: '<S398>/Abs1'
           *  Constant: '<S408>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S408>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S411>/Logical Operator' incorporates:
           *  Abs: '<S411>/Abs1'
           *  Abs: '<S411>/Abs2'
           *  Constant: '<S423>/Constant'
           *  Constant: '<S424>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S423>/Compare'
           *  RelationalOperator: '<S424>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S411>/Motion State' */
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
              if ((rtb_Saturation1_p5 <= 0.2) || (FMS_DW.temporalCounter_i1_g >=
                   1250U)) {
                FMS_DW.is_c16_FMS = FMS_IN_Hold_ow;
                rtb_state_fg = MotionState_Hold;
              } else {
                if (rtb_FixPtRelationalOperator_me) {
                  FMS_DW.is_c16_FMS = FMS_IN_Move_a;
                  rtb_state_fg = MotionState_Move;
                }
              }
              break;

             case FMS_IN_Hold_ow:
              rtb_state_fg = MotionState_Hold;
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_a;
                rtb_state_fg = MotionState_Move;
              }
              break;

             default:
              rtb_state_fg = MotionState_Move;
              if (!rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Brake_m;
                FMS_DW.temporalCounter_i1_g = 0U;
                rtb_state_fg = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S411>/Motion State' */

          /* SwitchCase: '<S410>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S410>/Hold Control' incorporates:
               *  ActionPort: '<S412>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S410>/Switch Case' incorporates:
               *  Delay: '<S412>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S410>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S410>/Hold Control' incorporates:
             *  ActionPort: '<S412>/Action Port'
             */
            /* Delay: '<S412>/Delay' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            if (FMS_DW.icLoad != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Trigonometry: '<S416>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* Trigonometry: '<S416>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* SignalConversion: '<S416>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S416>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S416>/Gain' incorporates:
             *  Gain: '<S415>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S416>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S416>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* SignalConversion: '<S416>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S416>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* SignalConversion: '<S416>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S412>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S412>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S412>/Sum'
             */
            d = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Integrator1_bx = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S412>/Multiply' incorporates:
             *  SignalConversion: '<S412>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n +
                3] * rtb_Integrator1_bx + rtb_VectorConcatenate[rtb_n] * d;
            }

            /* End of Product: '<S412>/Multiply' */

            /* Gain: '<S412>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

            /* Update for Delay: '<S412>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S410>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S410>/Move Control' incorporates:
               *  ActionPort: '<S413>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S410>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S419>/Integrator'
               *  DiscreteIntegrator: '<S419>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S410>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S410>/Move Control' incorporates:
             *  ActionPort: '<S413>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S417>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S417>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S417>/Gain' */
            rtb_Saturation_o4 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S418>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S418>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S418>/Gain' */
            rtb_Saturation1_p5 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

            /* Sum: '<S420>/Sum of Elements' incorporates:
             *  Math: '<S420>/Square'
             *  SignalConversion: '<S420>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S421>/Sum of Elements'
             *  Switch: '<S413>/Switch'
             */
            rtb_u_b = rtb_Saturation_o4 * rtb_Saturation_o4 + rtb_Saturation1_p5
              * rtb_Saturation1_p5;

            /* Switch: '<S413>/Switch' incorporates:
             *  Product: '<S421>/Divide'
             *  Sqrt: '<S420>/Sqrt'
             *  Sum: '<S420>/Sum of Elements'
             */
            if (sqrtf(rtb_u_b) > 1.0F) {
              /* Math: '<S421>/Math Function1'
               *
               * About '<S421>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_u_b < 0.0F) {
                rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
              } else {
                rtb_Saturation_ga = sqrtf(rtb_u_b);
              }

              /* End of Math: '<S421>/Math Function1' */

              /* Switch: '<S421>/Switch' incorporates:
               *  Constant: '<S421>/Constant'
               *  Product: '<S421>/Product'
               */
              if (rtb_Saturation_ga > 0.0F) {
                rtb_TmpSignalConversionAtMultip[0] = rtb_Saturation_o4;
                rtb_TmpSignalConversionAtMultip[1] = rtb_Saturation1_p5;
                rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_ga;
              } else {
                rtb_TmpSignalConversionAtMultip[0] = 0.0F;
                rtb_TmpSignalConversionAtMultip[1] = 0.0F;
                rtb_TmpSignalConversionAtMultip[2] = 1.0F;
              }

              /* End of Switch: '<S421>/Switch' */
              rtb_Saturation_o4 = rtb_TmpSignalConversionAtMultip[0] /
                rtb_TmpSignalConversionAtMultip[2];
              rtb_Saturation1_p5 = rtb_TmpSignalConversionAtMultip[1] /
                rtb_TmpSignalConversionAtMultip[2];
            }

            /* Product: '<S422>/Multiply1' incorporates:
             *  Constant: '<S422>/const1'
             *  DiscreteIntegrator: '<S419>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S422>/Add' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator1'
             *  Gain: '<S413>/Gain6'
             *  Sum: '<S419>/Subtract'
             */
            rtb_Add4_a1 = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM *
                           rtb_Saturation_o4) + rtb_Saturation1_d;

            /* Signum: '<S422>/Sign' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Add4_a1 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Add4_a1;
            }

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
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Add4_a1) + FMS_ConstB.d)
              * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Saturation_ga +
              rtb_Saturation1_d;

            /* Sum: '<S422>/Add4' */
            rtb_Saturation1_d += rtb_Add4_a1 - rtb_Saturation_o4;

            /* Sum: '<S422>/Add3' */
            rtb_Saturation_ga = rtb_Add4_a1 + FMS_ConstB.d;

            /* Sum: '<S422>/Subtract1' */
            rtb_Add4_a1 -= FMS_ConstB.d;

            /* Signum: '<S422>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S422>/Sign2' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_Add4_a1 = -1.0F;
            } else {
              if (rtb_Add4_a1 > 0.0F) {
                rtb_Add4_a1 = 1.0F;
              }
            }

            /* Sum: '<S422>/Add5' incorporates:
             *  Gain: '<S422>/Gain2'
             *  Product: '<S422>/Multiply4'
             *  Sum: '<S422>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Add4_a1) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S419>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S419>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S422>/Sign4' incorporates:
             *  Sum: '<S422>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S422>/Sign3' incorporates:
             *  Sum: '<S422>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S422>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S422>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S422>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S422>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Add4_a1 = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Add4_a1 = 1.0F;
            } else {
              rtb_Add4_a1 = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S419>/Integrator' incorporates:
             *  Constant: '<S422>/const'
             *  Gain: '<S422>/Gain3'
             *  Product: '<S422>/Divide'
             *  Product: '<S422>/Multiply5'
             *  Product: '<S422>/Multiply6'
             *  Sum: '<S422>/Subtract4'
             *  Sum: '<S422>/Subtract5'
             *  Sum: '<S422>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 39.224F) * 0.004F;

            /* Product: '<S422>/Multiply1' incorporates:
             *  Constant: '<S422>/const1'
             *  DiscreteIntegrator: '<S419>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S422>/Add' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator1'
             *  Gain: '<S413>/Gain6'
             *  Sum: '<S419>/Subtract'
             */
            rtb_Add4_a1 = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                           rtb_Saturation1_p5) + rtb_Saturation1_d;

            /* Signum: '<S422>/Sign' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Add4_a1 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Add4_a1;
            }

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
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Add4_a1) + FMS_ConstB.d)
              * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Saturation_ga +
              rtb_Saturation1_d;

            /* Sum: '<S422>/Add4' */
            rtb_Saturation1_d += rtb_Add4_a1 - rtb_Saturation_o4;

            /* Sum: '<S422>/Add3' */
            rtb_Saturation_ga = rtb_Add4_a1 + FMS_ConstB.d;

            /* Sum: '<S422>/Subtract1' */
            rtb_Add4_a1 -= FMS_ConstB.d;

            /* Signum: '<S422>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S422>/Sign2' */
            if (rtb_Add4_a1 < 0.0F) {
              rtb_Add4_a1 = -1.0F;
            } else {
              if (rtb_Add4_a1 > 0.0F) {
                rtb_Add4_a1 = 1.0F;
              }
            }

            /* Sum: '<S422>/Add5' incorporates:
             *  Gain: '<S422>/Gain2'
             *  Product: '<S422>/Multiply4'
             *  Sum: '<S422>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Add4_a1) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S419>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S419>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S422>/Sign4' incorporates:
             *  Sum: '<S422>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S422>/Sign3' incorporates:
             *  Sum: '<S422>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S422>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S422>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S422>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S422>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Add4_a1 = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Add4_a1 = 1.0F;
            } else {
              rtb_Add4_a1 = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S419>/Integrator' incorporates:
             *  Constant: '<S422>/const'
             *  Gain: '<S422>/Gain3'
             *  Product: '<S422>/Divide'
             *  Product: '<S422>/Multiply5'
             *  Product: '<S422>/Multiply6'
             *  Sum: '<S422>/Subtract4'
             *  Sum: '<S422>/Subtract5'
             *  Sum: '<S422>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Add4_a1 * 39.224F) * 0.004F;

            /* End of Outputs for SubSystem: '<S410>/Move Control' */
            break;
          }

          /* SwitchCase: '<S397>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S397>/Hold Control' incorporates:
               *  ActionPort: '<S400>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S397>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S397>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S397>/Hold Control' incorporates:
             *  ActionPort: '<S400>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S397>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S397>/Brake Control' incorporates:
             *  ActionPort: '<S399>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S397>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S397>/Move Control' incorporates:
               *  ActionPort: '<S401>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S397>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S397>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S397>/Move Control' incorporates:
             *  ActionPort: '<S401>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S397>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S397>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S343>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S343>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S397>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S397>/Saturation' */

          /* Saturate: '<S410>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S410>/Saturation1' */

          /* Saturate: '<S385>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S343>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S385>/Saturation1' */
          /* End of Outputs for SubSystem: '<S336>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S336>/Unknown' incorporates:
           *  ActionPort: '<S345>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S336>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S50>/Manual' incorporates:
         *  ActionPort: '<S338>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S338>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S338>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S338>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S338>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S50>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S50>/Unknown' incorporates:
         *  ActionPort: '<S340>/Action Port'
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
   *  DiscreteIntegrator: '<S781>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S781>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S781>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S27>/SetHome' incorporates:
   *  TriggerPort: '<S34>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S34>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S27>/SetHome' */

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
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Square_gf -
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
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_h += (rtb_Vg -
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
  FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;

  /* End of Start for SubSystem: '<S125>/Altitude' */

  /* Start for IfAction SubSystem: '<S125>/Position' */
  /* Start for SwitchCase: '<S175>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S161>/Switch Case' */
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
  /* Start for SwitchCase: '<S339>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S339>/Return' */
  /* Start for SwitchCase: '<S739>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S729>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S339>/Return' */

  /* Start for IfAction SubSystem: '<S339>/Hold' */
  /* Start for SwitchCase: '<S678>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S646>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S657>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S339>/Hold' */
  /* End of Start for SubSystem: '<S50>/SubMode' */

  /* Start for IfAction SubSystem: '<S50>/Auto' */
  /* Start for SwitchCase: '<S337>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S337>/Mission' */
  /* Start for Resettable SubSystem: '<S448>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S499>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S489>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S448>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S337>/Mission' */
  /* End of Start for SubSystem: '<S50>/Auto' */

  /* Start for IfAction SubSystem: '<S50>/Assist' */
  /* Start for SwitchCase: '<S336>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S336>/Stabilize' */
  /* Start for SwitchCase: '<S435>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S336>/Stabilize' */

  /* Start for IfAction SubSystem: '<S336>/Altitude' */
  /* Start for SwitchCase: '<S351>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S369>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S336>/Altitude' */

  /* Start for IfAction SubSystem: '<S336>/Position' */
  /* Start for SwitchCase: '<S385>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S410>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S397>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S336>/Position' */
  /* End of Start for SubSystem: '<S50>/Assist' */
  /* End of Start for SubSystem: '<S44>/MC_Mode' */
  /* End of Start for SubSystem: '<S42>/Arm' */
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
  /* InitializeConditions for Delay: '<S279>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S274>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S128>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S49>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S126>/Mission' */
  /* InitializeConditions for UnitDelay: '<S240>/Delay Input1'
   *
   * Block description for '<S240>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S126>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S49>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S125>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S230>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S230>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S235>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S235>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S125>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S125>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S150>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S150>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S155>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mg = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S155>/Integrator' */
  FMS_DW.Integrator_DSTATE_lc = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
  FMS_DW.Integrator_DSTATE_ex = 0.0F;

  /* SystemInitialize for Chart: '<S139>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S138>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S138>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S138>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S138>/Move Control' */

  /* SystemInitialize for Merge: '<S138>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S125>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S125>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S162>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S176>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S175>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_b, &FMS_DW.HoldControl_b);

  /* End of SystemInitialize for SubSystem: '<S175>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S161>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S161>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S161>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S161>/Move Control' */

  /* SystemInitialize for Merge: '<S161>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S175>/Merge' */
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
  /* SystemInitialize for IfAction SubSystem: '<S339>/Takeoff' */
  /* InitializeConditions for Delay: '<S779>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S775>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S775>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S339>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S339>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S694>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S694>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S339>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S339>/Return' */
  /* InitializeConditions for Delay: '<S724>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S725>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S720>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S766>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S703>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S740>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S739>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S739>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S739>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S739>/Move Control' */

  /* SystemInitialize for Merge: '<S739>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S730>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S729>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S729>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S729>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_cg);

  /* End of SystemInitialize for SubSystem: '<S729>/Move Control' */

  /* SystemInitialize for Merge: '<S729>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S339>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S339>/Hold' */
  /* InitializeConditions for Delay: '<S659>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S671>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S671>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S647>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S658>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S679>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S678>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S678>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S678>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S678>/Move Control' */

  /* SystemInitialize for Merge: '<S678>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S646>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S646>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S646>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S646>/Move Control' */

  /* SystemInitialize for Merge: '<S646>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S657>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S657>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S657>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S657>/Move Control' */

  /* SystemInitialize for Merge: '<S657>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S339>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S50>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S337>/Mission' */
  /* InitializeConditions for UnitDelay: '<S451>/Delay Input1'
   *
   * Block description for '<S451>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S448>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S478>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S474>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S526>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S456>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S459>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S459>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S500>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S499>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S499>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S499>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S509>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S509>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S499>/Move Control' */

  /* SystemInitialize for Merge: '<S499>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S499>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S509>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S509>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S499>/Move Control' */

  /* SystemInitialize for Merge: '<S499>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S490>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S489>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S489>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S489>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S496>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S496>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S489>/Move Control' */

  /* SystemInitialize for Merge: '<S489>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S448>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S337>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S50>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S336>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S431>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S432>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S432>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S431>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S436>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S435>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S435>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S435>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S435>/Move Control' */

  /* SystemInitialize for Merge: '<S435>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S336>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S336>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S365>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S366>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S366>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S365>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S352>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S351>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S351>/Hold Control' */

  /* SystemInitialize for Merge: '<S351>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S370>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S369>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_pi);

  /* End of SystemInitialize for SubSystem: '<S369>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S369>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S369>/Move Control' */

  /* SystemInitialize for Merge: '<S369>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S336>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S336>/Position' */
  /* SystemInitialize for Chart: '<S386>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S385>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S385>/Hold Control' */

  /* SystemInitialize for Chart: '<S398>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S411>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S410>/Hold Control' */
  /* InitializeConditions for Delay: '<S412>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S410>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S410>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S410>/Move Control' */

  /* SystemInitialize for Merge: '<S410>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S410>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S410>/Move Control' */

  /* SystemInitialize for Merge: '<S410>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S385>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S397>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S397>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S397>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S397>/Move Control' */

  /* SystemInitialize for Merge: '<S397>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S336>/Position' */
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
