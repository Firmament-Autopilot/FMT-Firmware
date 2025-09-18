/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2548
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep 17 08:37:35 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S133>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S170>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<S724>/Motion Status' */
#define FMS_IN_Brake_bq                ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S734>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_ol                 ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S430>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S652>/Motion State' */
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
                                        *   '<S776>/Constant1'
                                        *   '<S777>/Constant'
                                        *   '<S779>/Constant1'
                                        *   '<S780>/FW_ACCEPT_R'
                                        *   '<S780>/MC_ACCEPT_R'
                                        *   '<S783>/Constant'
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
                                        *   '<S259>/Dead Zone'
                                        *   '<S259>/Gain'
                                        *   '<S260>/Dead Zone'
                                        *   '<S260>/Gain'
                                        *   '<S261>/Dead Zone'
                                        *   '<S261>/Gain'
                                        *   '<S262>/Dead Zone'
                                        *   '<S262>/Gain'
                                        *   '<S265>/Constant4'
                                        *   '<S266>/Constant4'
                                        *   '<S634>/L1'
                                        *   '<S57>/L1'
                                        *   '<S58>/Gain6'
                                        *   '<S96>/Constant'
                                        *   '<S97>/Constant'
                                        *   '<S129>/Gain'
                                        *   '<S130>/Gain1'
                                        *   '<S131>/Gain'
                                        *   '<S152>/Gain1'
                                        *   '<S219>/Gain'
                                        *   '<S219>/Gain1'
                                        *   '<S220>/Gain1'
                                        *   '<S268>/Gain2'
                                        *   '<S268>/Saturation1'
                                        *   '<S269>/L1'
                                        *   '<S269>/R'
                                        *   '<S269>/Saturation1'
                                        *   '<S286>/Gain'
                                        *   '<S286>/Saturation1'
                                        *   '<S308>/Gain'
                                        *   '<S308>/Saturation1'
                                        *   '<S343>/Gain'
                                        *   '<S343>/Gain1'
                                        *   '<S420>/Gain'
                                        *   '<S420>/Gain1'
                                        *   '<S422>/Constant'
                                        *   '<S446>/L1'
                                        *   '<S527>/Saturation'
                                        *   '<S528>/Saturation1'
                                        *   '<S528>/Saturation2'
                                        *   '<S528>/Saturation3'
                                        *   '<S685>/Land_Speed'
                                        *   '<S686>/Saturation1'
                                        *   '<S765>/Takeoff_Speed'
                                        *   '<S766>/Gain2'
                                        *   '<S766>/Saturation1'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        *   '<S132>/Saturation1'
                                        *   '<S143>/Dead Zone'
                                        *   '<S143>/Gain'
                                        *   '<S146>/Dead Zone'
                                        *   '<S146>/Gain'
                                        *   '<S155>/Saturation1'
                                        *   '<S166>/Dead Zone'
                                        *   '<S166>/Gain'
                                        *   '<S169>/Saturation1'
                                        *   '<S216>/Constant'
                                        *   '<S216>/Constant1'
                                        *   '<S216>/Constant2'
                                        *   '<S222>/Dead Zone'
                                        *   '<S222>/Gain'
                                        *   '<S223>/Dead Zone'
                                        *   '<S223>/Gain'
                                        *   '<S228>/Dead Zone'
                                        *   '<S228>/Gain'
                                        *   '<S236>/Gain'
                                        *   '<S236>/Saturation1'
                                        *   '<S237>/Constant4'
                                        *   '<S291>/L1'
                                        *   '<S291>/Saturation1'
                                        *   '<S313>/L1'
                                        *   '<S313>/Saturation1'
                                        *   '<S345>/Saturation1'
                                        *   '<S357>/Dead Zone'
                                        *   '<S357>/Gain'
                                        *   '<S358>/Dead Zone'
                                        *   '<S358>/Gain'
                                        *   '<S363>/Saturation'
                                        *   '<S379>/Saturation1'
                                        *   '<S391>/Saturation'
                                        *   '<S404>/Saturation1'
                                        *   '<S423>/Dead Zone'
                                        *   '<S423>/Gain'
                                        *   '<S424>/Dead Zone'
                                        *   '<S424>/Gain'
                                        *   '<S429>/Saturation'
                                        *   '<S583>/Gain2'
                                        *   '<S590>/Gain1'
                                        *   '<S590>/Gain2'
                                        *   '<S640>/Saturation1'
                                        *   '<S651>/Saturation'
                                        *   '<S672>/Saturation1'
                                        *   '<S687>/Constant'
                                        *   '<S690>/Gain2'
                                        *   '<S714>/Constant'
                                        *   '<S714>/vel'
                                        *   '<S714>/Acceleration_Speed'
                                        *   '<S714>/Saturation'
                                        *   '<S714>/Switch'
                                        *   '<S718>/Constant'
                                        *   '<S135>/Gain2'
                                        *   '<S136>/Gain1'
                                        *   '<S141>/Constant'
                                        *   '<S158>/Gain2'
                                        *   '<S159>/Gain1'
                                        *   '<S164>/Constant'
                                        *   '<S172>/L1'
                                        *   '<S173>/Gain6'
                                        *   '<S211>/Constant'
                                        *   '<S212>/Constant'
                                        *   '<S242>/L1'
                                        *   '<S242>/Saturation1'
                                        *   '<S348>/Gain2'
                                        *   '<S349>/Gain1'
                                        *   '<S355>/Constant'
                                        *   '<S366>/Gain2'
                                        *   '<S367>/Gain1'
                                        *   '<S374>/Constant'
                                        *   '<S382>/Gain2'
                                        *   '<S383>/Gain1'
                                        *   '<S389>/Constant'
                                        *   '<S394>/Gain2'
                                        *   '<S395>/Gain1'
                                        *   '<S402>/Constant'
                                        *   '<S406>/Gain2'
                                        *   '<S407>/Gain6'
                                        *   '<S417>/Constant'
                                        *   '<S418>/Constant'
                                        *   '<S432>/Gain2'
                                        *   '<S433>/Gain1'
                                        *   '<S440>/Constant'
                                        *   '<S465>/Gain'
                                        *   '<S465>/Saturation1'
                                        *   '<S468>/Constant'
                                        *   '<S468>/vel'
                                        *   '<S468>/Switch'
                                        *   '<S643>/Gain2'
                                        *   '<S644>/Gain1'
                                        *   '<S655>/Gain2'
                                        *   '<S656>/Gain1'
                                        *   '<S664>/Gain2'
                                        *   '<S664>/Saturation'
                                        *   '<S665>/Integrator'
                                        *   '<S675>/Gain2'
                                        *   '<S676>/Gain6'
                                        *   '<S699>/Gain2'
                                        *   '<S699>/Saturation'
                                        *   '<S700>/Integrator'
                                        *   '<S138>/Dead Zone'
                                        *   '<S138>/Gain'
                                        *   '<S161>/Dead Zone'
                                        *   '<S161>/Gain'
                                        *   '<S208>/Dead Zone'
                                        *   '<S208>/Gain'
                                        *   '<S351>/Land_Speed'
                                        *   '<S352>/Constant'
                                        *   '<S354>/Dead Zone'
                                        *   '<S354>/Gain'
                                        *   '<S371>/Dead Zone'
                                        *   '<S371>/Gain'
                                        *   '<S385>/Land_Speed'
                                        *   '<S386>/Constant'
                                        *   '<S388>/Dead Zone'
                                        *   '<S388>/Gain'
                                        *   '<S399>/Dead Zone'
                                        *   '<S399>/Gain'
                                        *   '<S411>/Dead Zone'
                                        *   '<S411>/Gain'
                                        *   '<S412>/Dead Zone'
                                        *   '<S412>/Gain'
                                        *   '<S437>/Dead Zone'
                                        *   '<S437>/Gain'
                                        *   '<S452>/Gain2'
                                        *   '<S452>/Saturation'
                                        *   '<S453>/Integrator'
                                        *   '<S646>/Dead Zone'
                                        *   '<S646>/Gain'
                                        *   '<S660>/Dead Zone'
                                        *   '<S660>/Gain'
                                        *   '<S680>/Dead Zone'
                                        *   '<S680>/Gain'
                                        *   '<S681>/Dead Zone'
                                        *   '<S681>/Gain'
                                        *   '<S723>/Saturation1'
                                        *   '<S733>/Saturation1'
                                        *   '<S483>/Saturation1'
                                        *   '<S493>/Saturation1'
                                        *   '<S726>/Gain2'
                                        *   '<S727>/Gain1'
                                        *   '<S736>/Gain2'
                                        *   '<S737>/Gain6'
                                        *   '<S486>/Gain2'
                                        *   '<S487>/Gain1'
                                        *   '<S496>/Gain2'
                                        *   '<S497>/Gain6'
                                        *   '<S729>/Dead Zone'
                                        *   '<S729>/Gain'
                                        *   '<S741>/Dead Zone'
                                        *   '<S741>/Gain'
                                        *   '<S742>/Dead Zone'
                                        *   '<S742>/Gain'
                                        *   '<S489>/Dead Zone'
                                        *   '<S489>/Gain'
                                        *   '<S501>/Dead Zone'
                                        *   '<S501>/Gain'
                                        *   '<S502>/Dead Zone'
                                        *   '<S502>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S26>/Constant1'
                                        *   '<S775>/Constant'
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
 *    '<S315>/NearbyRefWP'
 *    '<S293>/NearbyRefWP'
 *    '<S244>/NearbyRefWP'
 *    '<S716>/NearbyRefWP'
 *    '<S470>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S319>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S315>/SearchL1RefWP'
 *    '<S293>/SearchL1RefWP'
 *    '<S244>/SearchL1RefWP'
 *    '<S716>/SearchL1RefWP'
 *    '<S470>/SearchL1RefWP'
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

  /* SignalConversion: '<S321>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S293>/OutRegionRegWP'
 *    '<S244>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S298>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S122>/Unknown'
 *    '<S120>/Unknown'
 *    '<S119>/Unknown'
 *    '<S49>/Unknown'
 *    '<S333>/Unknown'
 *    '<S331>/Unknown'
 *    '<S330>/Unknown'
 *    '<S50>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S267>/Bus Assignment' incorporates:
   *  Constant: '<S267>/Constant'
   *  Constant: '<S267>/Constant2'
   *  SignalConversion: '<S267>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S267>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S132>/Hold Control'
 *    '<S155>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S135>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S132>/Hold Control'
 *    '<S155>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S135>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S132>/Hold Control'
 *    '<S155>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S135>/Delay' incorporates:
   *  Gain: '<S137>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S135>/Gain2' incorporates:
   *  Delay: '<S135>/Delay'
   *  Gain: '<S137>/Gain'
   *  Sum: '<S135>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S135>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S132>/Brake Control'
 *    '<S155>/Brake Control'
 *    '<S723>/Brake Control'
 *    '<S640>/Brake Control'
 *    '<S651>/Brake Control'
 *    '<S483>/Brake Control'
 *    '<S429>/Brake Control'
 *    '<S345>/Brake Control'
 *    '<S363>/Brake Control'
 *    '<S379>/Brake Control'
 *    '<S391>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S134>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S134>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S132>/Move Control'
 *    '<S155>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S132>/Move Control'
 *    '<S155>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S132>/Move Control'
 *    '<S155>/Move Control'
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

  /* Product: '<S140>/Multiply1' incorporates:
   *  Constant: '<S140>/const1'
   *  DiscreteIntegrator: '<S139>/Integrator'
   */
  rtb_Add3_ci = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S138>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_bz = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_bz = 0.0F;
  } else {
    rtb_a_bz = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S138>/Dead Zone' */

  /* Sum: '<S140>/Add' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator1'
   *  Gain: '<S136>/Gain1'
   *  Gain: '<S138>/Gain'
   *  Sum: '<S139>/Subtract'
   */
  rtb_Subtract3_df = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_bz * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_ci;

  /* Signum: '<S140>/Sign' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_a_bz = -1.0F;
  } else if (rtb_Subtract3_df > 0.0F) {
    rtb_a_bz = 1.0F;
  } else {
    rtb_a_bz = rtb_Subtract3_df;
  }

  /* End of Signum: '<S140>/Sign' */

  /* Sum: '<S140>/Add2' incorporates:
   *  Abs: '<S140>/Abs'
   *  Gain: '<S140>/Gain'
   *  Gain: '<S140>/Gain1'
   *  Product: '<S140>/Multiply2'
   *  Product: '<S140>/Multiply3'
   *  Sqrt: '<S140>/Sqrt'
   *  Sum: '<S140>/Add1'
   *  Sum: '<S140>/Subtract'
   */
  rtb_a_bz = (sqrtf((8.0F * fabsf(rtb_Subtract3_df) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_bz + rtb_Add3_ci;

  /* Sum: '<S140>/Add4' */
  rtb_Add4_lp = (rtb_Subtract3_df - rtb_a_bz) + rtb_Add3_ci;

  /* Sum: '<S140>/Add3' */
  rtb_Add3_ci = rtb_Subtract3_df + localC->d;

  /* Sum: '<S140>/Subtract1' */
  rtb_Subtract3_df -= localC->d;

  /* Signum: '<S140>/Sign1' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S140>/Sign1' */

  /* Signum: '<S140>/Sign2' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_Subtract3_df = -1.0F;
  } else {
    if (rtb_Subtract3_df > 0.0F) {
      rtb_Subtract3_df = 1.0F;
    }
  }

  /* End of Signum: '<S140>/Sign2' */

  /* Sum: '<S140>/Add5' incorporates:
   *  Gain: '<S140>/Gain2'
   *  Product: '<S140>/Multiply4'
   *  Sum: '<S140>/Subtract2'
   */
  rtb_a_bz += (rtb_Add3_ci - rtb_Subtract3_df) * 0.5F * rtb_Add4_lp;

  /* SignalConversion: '<S136>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S139>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S140>/Add6' */
  rtb_Add3_ci = rtb_a_bz + localC->d;

  /* Sum: '<S140>/Subtract3' */
  rtb_Subtract3_df = rtb_a_bz - localC->d;

  /* Signum: '<S140>/Sign5' */
  if (rtb_a_bz < 0.0F) {
    rtb_Add4_lp = -1.0F;
  } else if (rtb_a_bz > 0.0F) {
    rtb_Add4_lp = 1.0F;
  } else {
    rtb_Add4_lp = rtb_a_bz;
  }

  /* End of Signum: '<S140>/Sign5' */

  /* Signum: '<S140>/Sign3' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S140>/Sign3' */

  /* Signum: '<S140>/Sign4' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_Subtract3_df = -1.0F;
  } else {
    if (rtb_Subtract3_df > 0.0F) {
      rtb_Subtract3_df = 1.0F;
    }
  }

  /* End of Signum: '<S140>/Sign4' */

  /* Signum: '<S140>/Sign6' */
  if (rtb_a_bz < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_bz > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_bz;
  }

  /* End of Signum: '<S140>/Sign6' */

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Constant: '<S140>/const'
   *  Gain: '<S140>/Gain3'
   *  Product: '<S140>/Divide'
   *  Product: '<S140>/Multiply5'
   *  Product: '<S140>/Multiply6'
   *  Sum: '<S140>/Subtract4'
   *  Sum: '<S140>/Subtract5'
   *  Sum: '<S140>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_bz / localC->d - rtb_Add4_lp) *
    localC->Gain4 * ((rtb_Add3_ci - rtb_Subtract3_df) * 0.5F) - rtb_a_f *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S133>/Motion Status'
 *    '<S156>/Motion Status'
 *    '<S346>/Motion Status'
 *    '<S380>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S133>/Motion Status'
 *    '<S156>/Motion Status'
 *    '<S346>/Motion Status'
 *    '<S380>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S133>/Motion Status'
 *    '<S156>/Motion Status'
 *    '<S346>/Motion Status'
 *    '<S380>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S133>/Motion Status' */
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

  /* End of Chart: '<S133>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S169>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_l_Init(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S177>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S177>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S205>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S205>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S207>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System reset for action system:
 *    '<S169>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_g_Reset(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S177>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S177>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S205>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S205>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S207>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S169>/Hold Control'
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

  /* Sqrt: '<S184>/Sqrt' incorporates:
   *  Math: '<S184>/Square'
   *  Sum: '<S184>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_ex = sqrtf(((rtu_FMS_In[0] * rtu_FMS_In[0] +
    rtu_FMS_In[1] * rtu_FMS_In[1]) + rtu_FMS_In[2] * rtu_FMS_In[2]) +
    rtu_FMS_In[3] * rtu_FMS_In[3]);

  /* Product: '<S180>/Divide' */
  rtb_Square_kg_idx_0 = rtu_FMS_In[0] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_1 = rtu_FMS_In[1] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_2 = rtu_FMS_In[2] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_DiscreteTimeIntegrator1_ex = rtu_FMS_In[3] /
    rtb_DiscreteTimeIntegrator1_ex;

  /* Math: '<S181>/Square' incorporates:
   *  Math: '<S182>/Square'
   *  Math: '<S183>/Square'
   */
  rtb_Sign_hw = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_0;

  /* Math: '<S181>/Square2' incorporates:
   *  Math: '<S182>/Square2'
   *  Math: '<S183>/Square2'
   */
  rtb_Switch_fz_idx_1 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2;

  /* Math: '<S181>/Square1' incorporates:
   *  Math: '<S182>/Square1'
   *  Math: '<S183>/Square1'
   */
  D = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1;

  /* Math: '<S181>/Square3' incorporates:
   *  Math: '<S182>/Square3'
   *  Math: '<S183>/Square3'
   */
  absxk = rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex;

  /* Sum: '<S181>/Subtract' incorporates:
   *  Math: '<S181>/Square'
   *  Math: '<S181>/Square1'
   *  Math: '<S181>/Square2'
   *  Math: '<S181>/Square3'
   *  Sum: '<S181>/Add'
   *  Sum: '<S181>/Add1'
   */
  rtb_VectorConcatenate_l[0] = (rtb_Sign_hw + D) - (rtb_Switch_fz_idx_1 + absxk);

  /* Product: '<S181>/Multiply' incorporates:
   *  Product: '<S182>/Multiply'
   */
  b_t = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_2;

  /* Product: '<S181>/Multiply1' incorporates:
   *  Product: '<S182>/Multiply1'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_DiscreteTimeIntegrator1_ex;

  /* Gain: '<S181>/Gain' incorporates:
   *  Product: '<S181>/Multiply'
   *  Product: '<S181>/Multiply1'
   *  Sum: '<S181>/Subtract1'
   */
  rtb_VectorConcatenate_l[1] = (b_t - d1) * 2.0F;

  /* Product: '<S181>/Multiply2' incorporates:
   *  Product: '<S183>/Multiply'
   */
  rtb_VectorConcatenate_fy_tmp = rtb_Square_kg_idx_1 *
    rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S181>/Multiply3' incorporates:
   *  Product: '<S183>/Multiply1'
   */
  rtb_VectorConcatenate_fy_tmp_0 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_2;

  /* Gain: '<S181>/Gain1' incorporates:
   *  Product: '<S181>/Multiply2'
   *  Product: '<S181>/Multiply3'
   *  Sum: '<S181>/Add2'
   */
  rtb_VectorConcatenate_l[2] = (rtb_VectorConcatenate_fy_tmp +
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S182>/Gain' incorporates:
   *  Sum: '<S182>/Add3'
   */
  rtb_VectorConcatenate_l[3] = (b_t + d1) * 2.0F;

  /* Sum: '<S182>/Subtract' incorporates:
   *  Sum: '<S182>/Add'
   *  Sum: '<S182>/Add1'
   */
  rtb_VectorConcatenate_l[4] = (rtb_Sign_hw + rtb_Switch_fz_idx_1) - (D + absxk);

  /* Product: '<S182>/Multiply2' incorporates:
   *  Product: '<S183>/Multiply2'
   */
  b_t = rtb_Square_kg_idx_2 * rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S182>/Multiply3' incorporates:
   *  Product: '<S183>/Multiply3'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_1;

  /* Gain: '<S182>/Gain1' incorporates:
   *  Product: '<S182>/Multiply2'
   *  Product: '<S182>/Multiply3'
   *  Sum: '<S182>/Subtract1'
   */
  rtb_VectorConcatenate_l[5] = (b_t - d1) * 2.0F;

  /* Gain: '<S183>/Gain' incorporates:
   *  Sum: '<S183>/Subtract2'
   */
  rtb_VectorConcatenate_l[6] = (rtb_VectorConcatenate_fy_tmp -
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S183>/Gain1' incorporates:
   *  Sum: '<S183>/Add2'
   */
  rtb_VectorConcatenate_l[7] = (b_t + d1) * 2.0F;

  /* Sum: '<S183>/Subtract' incorporates:
   *  Sum: '<S183>/Add'
   *  Sum: '<S183>/Add1'
   */
  rtb_VectorConcatenate_l[8] = (rtb_Sign_hw + absxk) - (D + rtb_Switch_fz_idx_1);

  /* Product: '<S174>/Multiply' incorporates:
   *  SignalConversion: '<S174>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_ppg[i] = rtb_VectorConcatenate_l[i + 6] * rtu_FMS_In_g +
      (rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h + rtb_VectorConcatenate_l[i]
       * rtu_FMS_In_c);
  }

  /* End of Product: '<S174>/Multiply' */

  /* Trigonometry: '<S203>/Trigonometric Function1' incorporates:
   *  Gain: '<S202>/Gain'
   *  Trigonometry: '<S203>/Trigonometric Function3'
   */
  rtb_Sign_hw = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[0] = rtb_Sign_hw;

  /* Trigonometry: '<S203>/Trigonometric Function' incorporates:
   *  Gain: '<S202>/Gain'
   *  Trigonometry: '<S203>/Trigonometric Function2'
   */
  rtb_Switch_fz_idx_1 = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[1] = rtb_Switch_fz_idx_1;

  /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S203>/Constant3'
   */
  rtb_VectorConcatenate_l[2] = 0.0F;

  /* Gain: '<S203>/Gain' */
  rtb_VectorConcatenate_l[3] = -rtb_Switch_fz_idx_1;

  /* Trigonometry: '<S203>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_Sign_hw;

  /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S203>/Constant4'
   */
  rtb_VectorConcatenate_l[5] = 0.0F;

  /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_l[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_l[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_l[8] = localC->VectorConcatenate3[2];

  /* Delay: '<S177>/start_vel' incorporates:
   *  SignalConversion: '<S190>/TmpSignal ConversionAtSquareInport1'
   */
  if (localDW->icLoad != 0) {
    localDW->start_vel_DSTATE[0] = rtu_FMS_In_c;
    localDW->start_vel_DSTATE[1] = rtu_FMS_In_h;
  }

  /* Sum: '<S198>/Sum of Elements' incorporates:
   *  Delay: '<S177>/start_vel'
   *  Math: '<S198>/Math Function'
   */
  rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[0] * localDW->
    start_vel_DSTATE[0] + localDW->start_vel_DSTATE[1] *
    localDW->start_vel_DSTATE[1];

  /* Math: '<S198>/Math Function1' incorporates:
   *  Sum: '<S198>/Sum of Elements'
   *
   * About '<S198>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_fz_idx_1 < 0.0F) {
    rtb_Sign_hw = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
  } else {
    rtb_Sign_hw = sqrtf(rtb_Switch_fz_idx_1);
  }

  /* End of Math: '<S198>/Math Function1' */

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S198>/Constant'
   *  Delay: '<S177>/start_vel'
   *  Product: '<S198>/Product'
   */
  if (rtb_Sign_hw > 0.0F) {
    rtb_Square_kg_idx_2 = localDW->start_vel_DSTATE[0];
    rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[1];
  } else {
    rtb_Square_kg_idx_2 = 0.0F;
    rtb_Switch_fz_idx_1 = 0.0F;
    rtb_Sign_hw = 1.0F;
  }

  /* End of Switch: '<S198>/Switch' */

  /* Delay: '<S177>/start_wp' incorporates:
   *  SignalConversion: '<S177>/TmpSignal ConversionAtstart_wpInport2'
   */
  if (localDW->icLoad_e != 0) {
    localDW->start_wp_DSTATE[0] = rtu_FMS_In_l;
    localDW->start_wp_DSTATE[1] = rtu_FMS_In_m;
  }

  /* MATLAB Function: '<S175>/SearchL1RefWP' incorporates:
   *  Delay: '<S177>/start_wp'
   *  SignalConversion: '<S187>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_Square_kg_idx_0 = localDW->start_wp_DSTATE[0] - rtu_FMS_In_l;
  rtb_Square_kg_idx_1 = localDW->start_wp_DSTATE[1] - rtu_FMS_In_m;

  /* Product: '<S198>/Divide' */
  rtb_Square_kg_idx_2 /= rtb_Sign_hw;

  /* MATLAB Function: '<S175>/SearchL1RefWP' */
  D = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_0;

  /* Product: '<S198>/Divide' */
  rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_2;
  rtb_Square_kg_idx_2 = rtb_Switch_fz_idx_1 / rtb_Sign_hw;

  /* MATLAB Function: '<S175>/SearchL1RefWP' incorporates:
   *  Constant: '<S172>/L1'
   *  Delay: '<S177>/start_wp'
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

  /* MATLAB Function: '<S175>/OutRegionRefWP' incorporates:
   *  Delay: '<S177>/start_wp'
   *  SignalConversion: '<S177>/TmpSignal ConversionAtstart_wpInport2'
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

  /* Product: '<S201>/Multiply' incorporates:
   *  SignalConversion: '<S201>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_fy[i] = rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h
      + rtb_VectorConcatenate_l[i] * rtu_FMS_In_c;
  }

  /* End of Product: '<S201>/Multiply' */

  /* DiscreteIntegrator: '<S205>/Discrete-Time Integrator' */
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

  /* DiscreteIntegrator: '<S207>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S199>/Constant'
   *  Sum: '<S199>/Sum'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  if (localDW->DiscreteTimeIntegrator1_PrevRes != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  /* Signum: '<S174>/Sign' */
  if (rtb_Multiply_ppg[0] < 0.0F) {
    rtb_Switch_fz_idx_1 = -1.0F;
  } else if (rtb_Multiply_ppg[0] > 0.0F) {
    rtb_Switch_fz_idx_1 = 1.0F;
  } else {
    rtb_Switch_fz_idx_1 = rtb_Multiply_ppg[0];
  }

  /* End of Signum: '<S174>/Sign' */

  /* Switch: '<S172>/Switch' incorporates:
   *  Constant: '<S172>/L1'
   *  Constant: '<S188>/Constant'
   *  Constant: '<S199>/Constant'
   *  Constant: '<S206>/kp'
   *  DiscreteIntegrator: '<S205>/Discrete-Time Integrator'
   *  Gain: '<S188>/Gain'
   *  Math: '<S188>/Square'
   *  Math: '<S191>/Square'
   *  Math: '<S193>/Math Function'
   *  MinMax: '<S188>/Max'
   *  MinMax: '<S188>/Min'
   *  Product: '<S188>/Divide'
   *  Product: '<S188>/Multiply1'
   *  Product: '<S206>/Multiply'
   *  Sqrt: '<S191>/Sqrt'
   *  Sum: '<S176>/Subtract'
   *  Sum: '<S191>/Sum of Elements'
   *  Sum: '<S199>/Sum'
   *  Sum: '<S200>/Add'
   */
  if (rtb_Switch_fz_idx_1 > 0.0F) {
    /* Sum: '<S192>/Sum of Elements' incorporates:
     *  Math: '<S192>/Math Function'
     *  SignalConversion: '<S190>/TmpSignal ConversionAtSquareInport1'
     *  Sum: '<S190>/Sum of Elements'
     */
    rtb_Switch_fz_idx_1 = rtu_FMS_In_c * rtu_FMS_In_c + rtu_FMS_In_h *
      rtu_FMS_In_h;

    /* Math: '<S192>/Math Function1' incorporates:
     *  Sum: '<S192>/Sum of Elements'
     *
     * About '<S192>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Switch_fz_idx_1 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
    } else {
      d1 = sqrtf(rtb_Switch_fz_idx_1);
    }

    /* End of Math: '<S192>/Math Function1' */

    /* Switch: '<S192>/Switch' incorporates:
     *  Constant: '<S192>/Constant'
     *  Product: '<S192>/Product'
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

    /* End of Switch: '<S192>/Switch' */

    /* Product: '<S192>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* RelationalOperator: '<S185>/Compare' incorporates:
     *  Constant: '<S185>/Constant'
     *  MATLAB Function: '<S175>/SearchL1RefWP'
     */
    rtb_Compare_dd1 = (rtb_Sign_hw > 0.0F);

    /* Switch: '<S175>/Switch' incorporates:
     *  Delay: '<S177>/start_wp'
     *  MATLAB Function: '<S175>/OutRegionRefWP'
     */
    if (!rtb_Compare_dd1) {
      rtb_Square_kg_idx_0 = b_t * rtb_DiscreteTimeIntegrator1_ex +
        localDW->start_wp_DSTATE[0];
      rtb_Square_kg_idx_1 = b_t * rtb_Square_kg_idx_2 + localDW->
        start_wp_DSTATE[1];
    }

    /* End of Switch: '<S175>/Switch' */

    /* Sum: '<S176>/Subtract' incorporates:
     *  SignalConversion: '<S177>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_0 - rtu_FMS_In_l;
    rtb_Square_kg_idx_0 = rtb_DiscreteTimeIntegrator1_ex;
    rtb_Sign_hw = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex;

    /* Sum: '<S176>/Subtract' incorporates:
     *  Math: '<S193>/Math Function'
     *  SignalConversion: '<S177>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_1 - rtu_FMS_In_m;

    /* Sum: '<S193>/Sum of Elements' incorporates:
     *  Math: '<S193>/Math Function'
     */
    rtb_Square_kg_idx_2 = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex + rtb_Sign_hw;

    /* Math: '<S193>/Math Function1' incorporates:
     *  Sum: '<S193>/Sum of Elements'
     *
     * About '<S193>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S193>/Math Function1' */

    /* Switch: '<S193>/Switch' incorporates:
     *  Constant: '<S193>/Constant'
     *  Product: '<S193>/Product'
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

    /* End of Switch: '<S193>/Switch' */

    /* Product: '<S193>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_0 *= rtb_Square_kg_idx_0;

    /* Product: '<S193>/Divide' incorporates:
     *  Math: '<S191>/Square'
     */
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S195>/Sum of Elements' incorporates:
     *  Math: '<S195>/Math Function'
     *  SignalConversion: '<S195>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = absxk * absxk + D * D;

    /* Math: '<S195>/Math Function1' incorporates:
     *  Sum: '<S195>/Sum of Elements'
     *
     * About '<S195>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S195>/Math Function1' */

    /* Switch: '<S195>/Switch' incorporates:
     *  Constant: '<S195>/Constant'
     *  Product: '<S195>/Product'
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

    /* End of Switch: '<S195>/Switch' */

    /* Product: '<S195>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S196>/Sum of Elements' incorporates:
     *  Math: '<S196>/Math Function'
     *  SignalConversion: '<S196>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1 +
      rtb_Sign_hw * rtb_Sign_hw;

    /* Math: '<S196>/Math Function1' incorporates:
     *  Sum: '<S196>/Sum of Elements'
     *
     * About '<S196>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S196>/Math Function1' */

    /* Switch: '<S196>/Switch' incorporates:
     *  Constant: '<S196>/Constant'
     *  Product: '<S196>/Product'
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

    /* End of Switch: '<S196>/Switch' */

    /* Product: '<S196>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S194>/Subtract' incorporates:
     *  Product: '<S194>/Multiply'
     *  Product: '<S194>/Multiply1'
     */
    rtb_Square_kg_idx_2 = rtb_Sign_hw * absxk - rtb_Square_kg_idx_1 * D;

    /* Signum: '<S189>/Sign1' */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      rtb_Square_kg_idx_2 = -1.0F;
    } else {
      if (rtb_Square_kg_idx_2 > 0.0F) {
        rtb_Square_kg_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S189>/Sign1' */

    /* Switch: '<S189>/Switch2' incorporates:
     *  Constant: '<S189>/Constant4'
     */
    if (rtb_Square_kg_idx_2 == 0.0F) {
      rtb_Square_kg_idx_2 = 1.0F;
    }

    /* End of Switch: '<S189>/Switch2' */

    /* DotProduct: '<S189>/Dot Product' */
    rtb_Square_kg_idx_1 = D * rtb_Sign_hw + absxk * rtb_Square_kg_idx_1;

    /* Trigonometry: '<S189>/Acos' incorporates:
     *  DotProduct: '<S189>/Dot Product'
     */
    if (rtb_Square_kg_idx_1 > 1.0F) {
      rtb_Square_kg_idx_1 = 1.0F;
    } else {
      if (rtb_Square_kg_idx_1 < -1.0F) {
        rtb_Square_kg_idx_1 = -1.0F;
      }
    }

    /* Product: '<S189>/Multiply' incorporates:
     *  Trigonometry: '<S189>/Acos'
     */
    rtb_Square_kg_idx_2 *= acosf(rtb_Square_kg_idx_1);

    /* Saturate: '<S188>/Saturation' */
    if (rtb_Square_kg_idx_2 > 1.57079637F) {
      rtb_Square_kg_idx_2 = 1.57079637F;
    } else {
      if (rtb_Square_kg_idx_2 < -1.57079637F) {
        rtb_Square_kg_idx_2 = -1.57079637F;
      }
    }

    /* End of Saturate: '<S188>/Saturation' */

    /* Trigonometry: '<S188>/Sin' */
    rtb_Square_kg_idx_1 = arm_sin_f32(rtb_Square_kg_idx_2);

    /* Sqrt: '<S190>/Sqrt' */
    rtb_Square_kg_idx_2 = sqrtf(rtb_Switch_fz_idx_1);
    *rty_ay_cmd_mPs2 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2 * 2.0F *
      rtb_Square_kg_idx_1 / fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf
      (rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex +
       rtb_Square_kg_idx_0), 0.5F));
  } else {
    *rty_ay_cmd_mPs2 = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
      localDW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Switch: '<S172>/Switch' */

  /* Update for Delay: '<S177>/start_vel' */
  localDW->icLoad = 0U;

  /* Update for Delay: '<S177>/start_wp' */
  localDW->icLoad_e = 0U;

  /* Update for DiscreteIntegrator: '<S205>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S199>/Constant'
   *  Constant: '<S205>/ki'
   *  Product: '<S205>/Multiply'
   *  Sum: '<S199>/Sum'
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

  /* End of Update for DiscreteIntegrator: '<S205>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S207>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S199>/Constant'
   *  Gain: '<S207>/Gain'
   *  Sum: '<S199>/Sum'
   *  Sum: '<S207>/Sum5'
   */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE += ((0.0F - rtb_VectorConcatenate_fy[1])
    - localDW->DiscreteTimeIntegrator1_DSTATE) * 62.831852F * 0.004F;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S169>/Brake Control'
 *    '<S54>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T *rty_ay_cmd_mPs2)
{
  /* SignalConversion: '<S171>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
   *  Constant: '<S171>/Brake Speed'
   */
  *rty_ay_cmd_mPs2 = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S169>/Move Control'
 *    '<S54>/Move Control'
 */
void FMS_MoveControl_d_Init(DW_MoveControl_FMS_p_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S169>/Move Control'
 *    '<S54>/Move Control'
 */
void FMS_MoveControl_a_Reset(DW_MoveControl_FMS_p_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S169>/Move Control'
 *    '<S54>/Move Control'
 */
void FMS_MoveControl_j(real32_T rtu_FMS_In, real32_T *rty_ay_cmd_mPs2, const
  ConstB_MoveControl_FMS_a_T *localC, DW_MoveControl_FMS_p_T *localDW)
{
  real32_T rtb_Add3_j;
  real32_T rtb_Subtract3_b;
  real32_T rtb_a_px;
  real32_T rtb_Add4_e;
  real32_T rtb_a_dw;

  /* Product: '<S210>/Multiply1' incorporates:
   *  Constant: '<S210>/const1'
   *  DiscreteIntegrator: '<S209>/Integrator'
   */
  rtb_Add3_j = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S208>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.ROLL_DZ) {
    rtb_a_px = rtu_FMS_In - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.ROLL_DZ) {
    rtb_a_px = 0.0F;
  } else {
    rtb_a_px = rtu_FMS_In - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S208>/Dead Zone' */

  /* Sum: '<S210>/Add' incorporates:
   *  DiscreteIntegrator: '<S209>/Integrator1'
   *  Gain: '<S173>/Gain6'
   *  Gain: '<S208>/Gain'
   *  Sum: '<S209>/Subtract'
   */
  rtb_Subtract3_b = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_a_px * FMS_PARAM.FW_ACC_Y_LIM) + rtb_Add3_j;

  /* Signum: '<S210>/Sign' */
  if (rtb_Subtract3_b < 0.0F) {
    rtb_a_px = -1.0F;
  } else if (rtb_Subtract3_b > 0.0F) {
    rtb_a_px = 1.0F;
  } else {
    rtb_a_px = rtb_Subtract3_b;
  }

  /* End of Signum: '<S210>/Sign' */

  /* Sum: '<S210>/Add2' incorporates:
   *  Abs: '<S210>/Abs'
   *  Gain: '<S210>/Gain'
   *  Gain: '<S210>/Gain1'
   *  Product: '<S210>/Multiply2'
   *  Product: '<S210>/Multiply3'
   *  Sqrt: '<S210>/Sqrt'
   *  Sum: '<S210>/Add1'
   *  Sum: '<S210>/Subtract'
   */
  rtb_a_px = (sqrtf((8.0F * fabsf(rtb_Subtract3_b) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_px + rtb_Add3_j;

  /* Sum: '<S210>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_b - rtb_a_px) + rtb_Add3_j;

  /* Sum: '<S210>/Add3' */
  rtb_Add3_j = rtb_Subtract3_b + localC->d;

  /* Sum: '<S210>/Subtract1' */
  rtb_Subtract3_b -= localC->d;

  /* Signum: '<S210>/Sign1' */
  if (rtb_Add3_j < 0.0F) {
    rtb_Add3_j = -1.0F;
  } else {
    if (rtb_Add3_j > 0.0F) {
      rtb_Add3_j = 1.0F;
    }
  }

  /* End of Signum: '<S210>/Sign1' */

  /* Signum: '<S210>/Sign2' */
  if (rtb_Subtract3_b < 0.0F) {
    rtb_Subtract3_b = -1.0F;
  } else {
    if (rtb_Subtract3_b > 0.0F) {
      rtb_Subtract3_b = 1.0F;
    }
  }

  /* End of Signum: '<S210>/Sign2' */

  /* Sum: '<S210>/Add5' incorporates:
   *  Gain: '<S210>/Gain2'
   *  Product: '<S210>/Multiply4'
   *  Sum: '<S210>/Subtract2'
   */
  rtb_a_px += (rtb_Add3_j - rtb_Subtract3_b) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S173>/OutportBufferForay_cmd_mPs2' incorporates:
   *  DiscreteIntegrator: '<S209>/Integrator1'
   */
  *rty_ay_cmd_mPs2 = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S209>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S209>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S210>/Add6' */
  rtb_Add3_j = rtb_a_px + localC->d;

  /* Sum: '<S210>/Subtract3' */
  rtb_Subtract3_b = rtb_a_px - localC->d;

  /* Signum: '<S210>/Sign5' */
  if (rtb_a_px < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_px > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_px;
  }

  /* End of Signum: '<S210>/Sign5' */

  /* Signum: '<S210>/Sign3' */
  if (rtb_Add3_j < 0.0F) {
    rtb_Add3_j = -1.0F;
  } else {
    if (rtb_Add3_j > 0.0F) {
      rtb_Add3_j = 1.0F;
    }
  }

  /* End of Signum: '<S210>/Sign3' */

  /* Signum: '<S210>/Sign4' */
  if (rtb_Subtract3_b < 0.0F) {
    rtb_Subtract3_b = -1.0F;
  } else {
    if (rtb_Subtract3_b > 0.0F) {
      rtb_Subtract3_b = 1.0F;
    }
  }

  /* End of Signum: '<S210>/Sign4' */

  /* Signum: '<S210>/Sign6' */
  if (rtb_a_px < 0.0F) {
    rtb_a_dw = -1.0F;
  } else if (rtb_a_px > 0.0F) {
    rtb_a_dw = 1.0F;
  } else {
    rtb_a_dw = rtb_a_px;
  }

  /* End of Signum: '<S210>/Sign6' */

  /* Update for DiscreteIntegrator: '<S209>/Integrator' incorporates:
   *  Constant: '<S210>/const'
   *  Gain: '<S210>/Gain3'
   *  Product: '<S210>/Divide'
   *  Product: '<S210>/Multiply5'
   *  Product: '<S210>/Multiply6'
   *  Sum: '<S210>/Subtract4'
   *  Sum: '<S210>/Subtract5'
   *  Sum: '<S210>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_px / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_j - rtb_Subtract3_b) * 0.5F) - rtb_a_dw * 58.836F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S170>/Motion State'
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
 *    '<S170>/Motion State'
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
 *    '<S170>/Motion State'
 *    '<S55>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S170>/Motion State' */
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

  /* End of Chart: '<S170>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S723>/Hold Control'
 *    '<S640>/Hold Control'
 *    '<S483>/Hold Control'
 *    '<S345>/Hold Control'
 *    '<S379>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S726>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S723>/Hold Control'
 *    '<S640>/Hold Control'
 *    '<S483>/Hold Control'
 *    '<S345>/Hold Control'
 *    '<S379>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S726>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S723>/Hold Control'
 *    '<S640>/Hold Control'
 *    '<S483>/Hold Control'
 *    '<S345>/Hold Control'
 *    '<S379>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S726>/Delay' incorporates:
   *  Gain: '<S728>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S726>/Gain2' incorporates:
   *  Delay: '<S726>/Delay'
   *  Gain: '<S728>/Gain'
   *  Sum: '<S726>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S726>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S723>/Move Control'
 *    '<S640>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S730>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S730>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S723>/Move Control'
 *    '<S640>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S730>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S730>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S723>/Move Control'
 *    '<S640>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_f;
  real32_T rtb_a_j2;
  real32_T rtb_Add4_gc;
  real32_T rtb_a_jg;

  /* Product: '<S731>/Multiply1' incorporates:
   *  Constant: '<S731>/const1'
   *  DiscreteIntegrator: '<S730>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S729>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_j2 = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_j2 = 0.0F;
  } else {
    rtb_a_j2 = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S729>/Dead Zone' */

  /* Sum: '<S731>/Add' incorporates:
   *  DiscreteIntegrator: '<S730>/Integrator1'
   *  Gain: '<S727>/Gain1'
   *  Gain: '<S729>/Gain'
   *  Sum: '<S730>/Subtract'
   */
  rtb_Subtract3_f = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_j2 * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_a;

  /* Signum: '<S731>/Sign' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_a_j2 = -1.0F;
  } else if (rtb_Subtract3_f > 0.0F) {
    rtb_a_j2 = 1.0F;
  } else {
    rtb_a_j2 = rtb_Subtract3_f;
  }

  /* End of Signum: '<S731>/Sign' */

  /* Sum: '<S731>/Add2' incorporates:
   *  Abs: '<S731>/Abs'
   *  Gain: '<S731>/Gain'
   *  Gain: '<S731>/Gain1'
   *  Product: '<S731>/Multiply2'
   *  Product: '<S731>/Multiply3'
   *  Sqrt: '<S731>/Sqrt'
   *  Sum: '<S731>/Add1'
   *  Sum: '<S731>/Subtract'
   */
  rtb_a_j2 = (sqrtf((8.0F * fabsf(rtb_Subtract3_f) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_j2 + rtb_Add3_a;

  /* Sum: '<S731>/Add4' */
  rtb_Add4_gc = (rtb_Subtract3_f - rtb_a_j2) + rtb_Add3_a;

  /* Sum: '<S731>/Add3' */
  rtb_Add3_a = rtb_Subtract3_f + localC->d;

  /* Sum: '<S731>/Subtract1' */
  rtb_Subtract3_f -= localC->d;

  /* Signum: '<S731>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign1' */

  /* Signum: '<S731>/Sign2' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign2' */

  /* Sum: '<S731>/Add5' incorporates:
   *  Gain: '<S731>/Gain2'
   *  Product: '<S731>/Multiply4'
   *  Sum: '<S731>/Subtract2'
   */
  rtb_a_j2 += (rtb_Add3_a - rtb_Subtract3_f) * 0.5F * rtb_Add4_gc;

  /* SignalConversion: '<S730>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S730>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S730>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S730>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S731>/Add6' */
  rtb_Add3_a = rtb_a_j2 + localC->d;

  /* Sum: '<S731>/Subtract3' */
  rtb_Subtract3_f = rtb_a_j2 - localC->d;

  /* Signum: '<S731>/Sign5' */
  if (rtb_a_j2 < 0.0F) {
    rtb_Add4_gc = -1.0F;
  } else if (rtb_a_j2 > 0.0F) {
    rtb_Add4_gc = 1.0F;
  } else {
    rtb_Add4_gc = rtb_a_j2;
  }

  /* End of Signum: '<S731>/Sign5' */

  /* Signum: '<S731>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign3' */

  /* Signum: '<S731>/Sign4' */
  if (rtb_Subtract3_f < 0.0F) {
    rtb_Subtract3_f = -1.0F;
  } else {
    if (rtb_Subtract3_f > 0.0F) {
      rtb_Subtract3_f = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign4' */

  /* Signum: '<S731>/Sign6' */
  if (rtb_a_j2 < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_j2 > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_j2;
  }

  /* End of Signum: '<S731>/Sign6' */

  /* Update for DiscreteIntegrator: '<S730>/Integrator' incorporates:
   *  Constant: '<S731>/const'
   *  Gain: '<S731>/Gain3'
   *  Product: '<S731>/Divide'
   *  Product: '<S731>/Multiply5'
   *  Product: '<S731>/Multiply6'
   *  Sum: '<S731>/Subtract4'
   *  Sum: '<S731>/Subtract5'
   *  Sum: '<S731>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_j2 / localC->d - rtb_Add4_gc) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_f) * 0.5F) - rtb_a_jg * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S724>/Motion Status'
 *    '<S641>/Motion Status'
 *    '<S484>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S724>/Motion Status'
 *    '<S641>/Motion Status'
 *    '<S484>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S724>/Motion Status'
 *    '<S641>/Motion Status'
 *    '<S484>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S724>/Motion Status' */
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

  /* End of Chart: '<S724>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S733>/Hold Control'
 *    '<S672>/Hold Control'
 *    '<S493>/Hold Control'
 */
void FMS_HoldControl_l0_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S736>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S733>/Hold Control'
 *    '<S672>/Hold Control'
 *    '<S493>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S736>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S733>/Hold Control'
 *    '<S672>/Hold Control'
 *    '<S493>/Hold Control'
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

  /* Delay: '<S736>/Delay' incorporates:
   *  SignalConversion: '<S736>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S740>/Trigonometric Function1' incorporates:
   *  Gain: '<S739>/Gain'
   *  Trigonometry: '<S740>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S740>/Trigonometric Function' incorporates:
   *  Gain: '<S739>/Gain'
   *  Trigonometry: '<S740>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S740>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S740>/Constant3'
   */
  rtb_VectorConcatenate_hl[2] = 0.0F;

  /* Gain: '<S740>/Gain' */
  rtb_VectorConcatenate_hl[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S740>/Trigonometric Function3' */
  rtb_VectorConcatenate_hl[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S740>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S740>/Constant4'
   */
  rtb_VectorConcatenate_hl[5] = 0.0F;

  /* SignalConversion: '<S740>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_hl[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_hl[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_hl[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S736>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S736>/Delay'
   *  SignalConversion: '<S736>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S736>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S736>/Multiply' incorporates:
   *  SignalConversion: '<S736>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_hl[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_hl[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S736>/Multiply' */

  /* Gain: '<S736>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S736>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S733>/Brake Control'
 *    '<S672>/Brake Control'
 *    '<S493>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S735>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S733>/Move Control'
 *    '<S672>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S733>/Move Control'
 *    '<S672>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S733>/Move Control'
 *    '<S672>/Move Control'
 */
void FMS_MoveControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_h, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_p_T *localC,
  DW_MoveControl_FMS_l_T *localDW)
{
  real32_T rtb_Subtract3_ne;
  real32_T rtb_Add3_l_idx_0;
  real32_T rtb_Subtract3_p_idx_0;
  real32_T rtb_Add3_l_idx_1;
  real32_T rtb_Subtract3_p_idx_1;
  real32_T rtb_v2_ew_idx_0;
  real32_T rtb_v2_ew_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_p_idx_0_0;

  /* DiscreteIntegrator: '<S743>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S744>/Multiply1' incorporates:
   *  Constant: '<S744>/const1'
   *  DiscreteIntegrator: '<S743>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S743>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S744>/Multiply1' incorporates:
   *  Constant: '<S744>/const1'
   *  DiscreteIntegrator: '<S743>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S741>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S741>/Dead Zone' */

  /* Sum: '<S744>/Add' incorporates:
   *  DiscreteIntegrator: '<S743>/Integrator1'
   *  Gain: '<S737>/Gain6'
   *  Gain: '<S741>/Gain'
   *  Sum: '<S743>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S742>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S742>/Dead Zone' */

  /* Sum: '<S744>/Add' incorporates:
   *  DiscreteIntegrator: '<S743>/Integrator1'
   *  Gain: '<S737>/Gain6'
   *  Gain: '<S742>/Gain'
   *  Sum: '<S743>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S744>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S744>/Add2' incorporates:
   *  Abs: '<S744>/Abs'
   *  Gain: '<S744>/Gain'
   *  Gain: '<S744>/Gain1'
   *  Product: '<S744>/Multiply2'
   *  Product: '<S744>/Multiply3'
   *  Signum: '<S744>/Sign'
   *  Sqrt: '<S744>/Sqrt'
   *  Sum: '<S744>/Add1'
   *  Sum: '<S744>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S744>/Add3' incorporates:
   *  Signum: '<S744>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S744>/Subtract1' incorporates:
   *  Signum: '<S744>/Sign'
   */
  rtb_Subtract3_ne = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S744>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign2' */
  if (rtb_Subtract3_ne < 0.0F) {
    rtb_Subtract3_ne = -1.0F;
  } else {
    if (rtb_Subtract3_ne > 0.0F) {
      rtb_Subtract3_ne = 1.0F;
    }
  }

  /* Sum: '<S744>/Add5' incorporates:
   *  Gain: '<S744>/Gain2'
   *  Product: '<S744>/Multiply4'
   *  Signum: '<S744>/Sign'
   *  Sum: '<S744>/Add2'
   *  Sum: '<S744>/Add4'
   *  Sum: '<S744>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_ne) * 0.5F);

  /* SignalConversion: '<S743>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S743>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S744>/Sign3' incorporates:
   *  Sum: '<S744>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S744>/Sign4' incorporates:
   *  Sum: '<S744>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S744>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S744>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_ne = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_ne = 1.0F;
  } else {
    rtb_Subtract3_ne = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S743>/Integrator' incorporates:
   *  Constant: '<S744>/const'
   *  Gain: '<S744>/Gain3'
   *  Product: '<S744>/Divide'
   *  Product: '<S744>/Multiply5'
   *  Product: '<S744>/Multiply6'
   *  Sum: '<S744>/Subtract4'
   *  Sum: '<S744>/Subtract5'
   *  Sum: '<S744>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_ne * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S744>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S744>/Add2' incorporates:
   *  Abs: '<S744>/Abs'
   *  Gain: '<S744>/Gain'
   *  Gain: '<S744>/Gain1'
   *  Product: '<S744>/Multiply2'
   *  Product: '<S744>/Multiply3'
   *  Signum: '<S744>/Sign'
   *  Sqrt: '<S744>/Sqrt'
   *  Sum: '<S744>/Add1'
   *  Sum: '<S744>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S744>/Add3' incorporates:
   *  Signum: '<S744>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S744>/Subtract1' incorporates:
   *  Signum: '<S744>/Sign'
   */
  rtb_Subtract3_ne = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S744>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign2' */
  if (rtb_Subtract3_ne < 0.0F) {
    rtb_Subtract3_ne = -1.0F;
  } else {
    if (rtb_Subtract3_ne > 0.0F) {
      rtb_Subtract3_ne = 1.0F;
    }
  }

  /* Sum: '<S744>/Add5' incorporates:
   *  Gain: '<S744>/Gain2'
   *  Product: '<S744>/Multiply4'
   *  Signum: '<S744>/Sign'
   *  Sum: '<S744>/Add2'
   *  Sum: '<S744>/Add4'
   *  Sum: '<S744>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_ne) * 0.5F);

  /* SignalConversion: '<S743>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S743>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S744>/Sign3' incorporates:
   *  Sum: '<S744>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S744>/Sign4' incorporates:
   *  Sum: '<S744>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S744>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S744>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_ne = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_ne = 1.0F;
  } else {
    rtb_Subtract3_ne = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S743>/Integrator' incorporates:
   *  Constant: '<S744>/const'
   *  Gain: '<S744>/Gain3'
   *  Product: '<S744>/Divide'
   *  Product: '<S744>/Multiply5'
   *  Product: '<S744>/Multiply6'
   *  Sum: '<S744>/Subtract4'
   *  Sum: '<S744>/Subtract5'
   *  Sum: '<S744>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_ne * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S734>/Motion State'
 *    '<S673>/Motion State'
 *    '<S494>/Motion State'
 */
void FMS_MotionState_c_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S734>/Motion State'
 *    '<S673>/Motion State'
 *    '<S494>/Motion State'
 */
void FMS_MotionState_f_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S734>/Motion State'
 *    '<S673>/Motion State'
 *    '<S494>/Motion State'
 */
void FMS_MotionState_p(real32_T rtu_motion_req, real32_T rtu_speed, MotionState *
  rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S734>/Motion State' */
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

  /* End of Chart: '<S734>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S716>/OutRegionRegWP'
 *    '<S470>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S749>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S651>/Hold Control'
 *    '<S429>/Hold Control'
 *    '<S363>/Hold Control'
 *    '<S391>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S655>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S651>/Hold Control'
 *    '<S429>/Hold Control'
 *    '<S363>/Hold Control'
 *    '<S391>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S655>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S651>/Hold Control'
 *    '<S429>/Hold Control'
 *    '<S363>/Hold Control'
 *    '<S391>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S655>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S655>/Sum' incorporates:
   *  Delay: '<S655>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S658>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S658>/Switch' incorporates:
   *  Constant: '<S658>/Constant'
   *  Constant: '<S659>/Constant'
   *  Product: '<S658>/Multiply'
   *  RelationalOperator: '<S659>/Compare'
   *  Sum: '<S658>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S658>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S658>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S658>/Switch' */

  /* Gain: '<S655>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S655>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S651>/Move Control'
 *    '<S429>/Move Control'
 *    '<S363>/Move Control'
 *    '<S391>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S661>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S661>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S651>/Move Control'
 *    '<S429>/Move Control'
 *    '<S363>/Move Control'
 *    '<S391>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S661>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S661>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S651>/Move Control'
 *    '<S429>/Move Control'
 *    '<S363>/Move Control'
 *    '<S391>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_mb;
  real32_T rtb_Subtract3_g5;
  real32_T rtb_a_ij;
  real32_T rtb_Add4_oa;
  real32_T rtb_a_g;

  /* Product: '<S662>/Multiply1' incorporates:
   *  Constant: '<S662>/const1'
   *  DiscreteIntegrator: '<S661>/Integrator'
   */
  rtb_Add3_mb = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S660>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_ij = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_ij = 0.0F;
  } else {
    rtb_a_ij = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S660>/Dead Zone' */

  /* Sum: '<S662>/Add' incorporates:
   *  DiscreteIntegrator: '<S661>/Integrator1'
   *  Gain: '<S656>/Gain1'
   *  Gain: '<S660>/Gain'
   *  Sum: '<S661>/Subtract'
   */
  rtb_Subtract3_g5 = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_ij * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_mb;

  /* Signum: '<S662>/Sign' */
  if (rtb_Subtract3_g5 < 0.0F) {
    rtb_a_ij = -1.0F;
  } else if (rtb_Subtract3_g5 > 0.0F) {
    rtb_a_ij = 1.0F;
  } else {
    rtb_a_ij = rtb_Subtract3_g5;
  }

  /* End of Signum: '<S662>/Sign' */

  /* Sum: '<S662>/Add2' incorporates:
   *  Abs: '<S662>/Abs'
   *  Gain: '<S662>/Gain'
   *  Gain: '<S662>/Gain1'
   *  Product: '<S662>/Multiply2'
   *  Product: '<S662>/Multiply3'
   *  Sqrt: '<S662>/Sqrt'
   *  Sum: '<S662>/Add1'
   *  Sum: '<S662>/Subtract'
   */
  rtb_a_ij = (sqrtf((8.0F * fabsf(rtb_Subtract3_g5) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_ij + rtb_Add3_mb;

  /* Sum: '<S662>/Add4' */
  rtb_Add4_oa = (rtb_Subtract3_g5 - rtb_a_ij) + rtb_Add3_mb;

  /* Sum: '<S662>/Add3' */
  rtb_Add3_mb = rtb_Subtract3_g5 + localC->d;

  /* Sum: '<S662>/Subtract1' */
  rtb_Subtract3_g5 -= localC->d;

  /* Signum: '<S662>/Sign1' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign1' */

  /* Signum: '<S662>/Sign2' */
  if (rtb_Subtract3_g5 < 0.0F) {
    rtb_Subtract3_g5 = -1.0F;
  } else {
    if (rtb_Subtract3_g5 > 0.0F) {
      rtb_Subtract3_g5 = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign2' */

  /* Sum: '<S662>/Add5' incorporates:
   *  Gain: '<S662>/Gain2'
   *  Product: '<S662>/Multiply4'
   *  Sum: '<S662>/Subtract2'
   */
  rtb_a_ij += (rtb_Add3_mb - rtb_Subtract3_g5) * 0.5F * rtb_Add4_oa;

  /* SignalConversion: '<S661>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S661>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S661>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S661>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S662>/Add6' */
  rtb_Add3_mb = rtb_a_ij + localC->d;

  /* Sum: '<S662>/Subtract3' */
  rtb_Subtract3_g5 = rtb_a_ij - localC->d;

  /* Signum: '<S662>/Sign5' */
  if (rtb_a_ij < 0.0F) {
    rtb_Add4_oa = -1.0F;
  } else if (rtb_a_ij > 0.0F) {
    rtb_Add4_oa = 1.0F;
  } else {
    rtb_Add4_oa = rtb_a_ij;
  }

  /* End of Signum: '<S662>/Sign5' */

  /* Signum: '<S662>/Sign3' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign3' */

  /* Signum: '<S662>/Sign4' */
  if (rtb_Subtract3_g5 < 0.0F) {
    rtb_Subtract3_g5 = -1.0F;
  } else {
    if (rtb_Subtract3_g5 > 0.0F) {
      rtb_Subtract3_g5 = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign4' */

  /* Signum: '<S662>/Sign6' */
  if (rtb_a_ij < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_ij > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_ij;
  }

  /* End of Signum: '<S662>/Sign6' */

  /* Update for DiscreteIntegrator: '<S661>/Integrator' incorporates:
   *  Constant: '<S662>/const'
   *  Gain: '<S662>/Gain3'
   *  Product: '<S662>/Divide'
   *  Product: '<S662>/Multiply5'
   *  Product: '<S662>/Multiply6'
   *  Sum: '<S662>/Subtract4'
   *  Sum: '<S662>/Subtract5'
   *  Sum: '<S662>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_ij / localC->d - rtb_Add4_oa) *
    localC->Gain4 * ((rtb_Add3_mb - rtb_Subtract3_g5) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S430>/Motion State'
 *    '<S364>/Motion State'
 *    '<S392>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S430>/Motion State'
 *    '<S364>/Motion State'
 *    '<S392>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S430>/Motion State'
 *    '<S364>/Motion State'
 *    '<S392>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S430>/Motion State' */
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

  /* End of Chart: '<S430>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S345>/Move Control'
 *    '<S379>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S354>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S354>/Dead Zone' */

  /* Gain: '<S349>/Gain1' incorporates:
   *  Gain: '<S354>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S349>/Switch' incorporates:
   *  Constant: '<S351>/Land_Speed'
   *  Constant: '<S352>/Constant'
   *  Constant: '<S353>/Constant'
   *  Gain: '<S351>/Gain'
   *  Logic: '<S349>/Logical Operator'
   *  MinMax: '<S351>/Min'
   *  RelationalOperator: '<S352>/Compare'
   *  RelationalOperator: '<S353>/Compare'
   *  S-Function (sfix_bitop): '<S349>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S349>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S780>/Switch' incorporates:
   *  Constant: '<S780>/FW_ACCEPT_R'
   *  Constant: '<S780>/MC_ACCEPT_R'
   *  Constant: '<S787>/Constant'
   *  RelationalOperator: '<S787>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S780>/Switch' */
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

  /* Math: '<S798>/Rem' incorporates:
   *  Constant: '<S798>/Constant1'
   *  Sum: '<S782>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S798>/Switch' incorporates:
   *  Abs: '<S798>/Abs'
   *  Constant: '<S798>/Constant'
   *  Constant: '<S799>/Constant'
   *  Product: '<S798>/Multiply'
   *  RelationalOperator: '<S799>/Compare'
   *  Sum: '<S798>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S798>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S798>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S798>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S785>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S804>/Sum of Elements' incorporates:
   *  Math: '<S804>/Math Function'
   *  SignalConversion: '<S804>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S804>/Math Function1' incorporates:
   *  Sum: '<S804>/Sum of Elements'
   *
   * About '<S804>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S804>/Math Function1' */

  /* Switch: '<S804>/Switch' incorporates:
   *  Constant: '<S804>/Constant'
   *  Product: '<S804>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S804>/Switch' */

  /* Product: '<S804>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S802>/Subtract' incorporates:
   *  Product: '<S802>/Multiply'
   *  Product: '<S802>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S801>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S801>/Sign1' */

  /* Switch: '<S801>/Switch2' incorporates:
   *  Constant: '<S801>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S801>/Switch2' */

  /* DotProduct: '<S801>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S801>/Acos' incorporates:
   *  DotProduct: '<S801>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S801>/Multiply' incorporates:
   *  Trigonometry: '<S801>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S785>/Switch' incorporates:
   *  Bias: '<S785>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S785>/Switch' */
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

  /* Gain: '<S788>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S789>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S789>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S789>/Multiply1' incorporates:
   *  Product: '<S789>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S789>/Divide' incorporates:
   *  Constant: '<S789>/Constant'
   *  Constant: '<S789>/R'
   *  Sqrt: '<S789>/Sqrt'
   *  Sum: '<S789>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S789>/Product3' incorporates:
   *  Constant: '<S789>/Constant1'
   *  Product: '<S789>/Multiply1'
   *  Sum: '<S789>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S789>/Multiply2' incorporates:
   *  Trigonometry: '<S789>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S788>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S793>/Abs' incorporates:
   *  Abs: '<S796>/Abs1'
   *  Switch: '<S793>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S793>/Switch1' incorporates:
   *  Abs: '<S793>/Abs'
   *  Bias: '<S793>/Bias2'
   *  Bias: '<S793>/Bias3'
   *  Constant: '<S790>/Constant'
   *  Constant: '<S790>/Constant1'
   *  Constant: '<S795>/Constant'
   *  Gain: '<S793>/Gain1'
   *  Product: '<S793>/Multiply'
   *  RelationalOperator: '<S795>/Compare'
   *  Switch: '<S790>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S796>/Switch1' incorporates:
     *  Bias: '<S796>/Bias2'
     *  Bias: '<S796>/Bias3'
     *  Constant: '<S796>/Constant'
     *  Constant: '<S797>/Constant'
     *  Math: '<S796>/Math Function'
     *  RelationalOperator: '<S797>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S796>/Switch1' */

    /* Signum: '<S793>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S793>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S790>/Sum' incorporates:
   *  Sum: '<S788>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S788>/Multiply' incorporates:
   *  Gain: '<S788>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S792>/Switch1' incorporates:
   *  Abs: '<S792>/Abs1'
   *  Bias: '<S792>/Bias2'
   *  Bias: '<S792>/Bias3'
   *  Constant: '<S792>/Constant'
   *  Constant: '<S794>/Constant'
   *  Math: '<S792>/Math Function'
   *  RelationalOperator: '<S794>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S792>/Switch1' */

  /* Product: '<S788>/Multiply' incorporates:
   *  Gain: '<S788>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S788>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S791>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S791>/Sum2' incorporates:
   *  Product: '<S791>/Multiply1'
   *  Product: '<S791>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S791>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S791>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S791>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S781>/Data Type Conversion' incorporates:
   *  Gain: '<S788>/Gain'
   *  Sum: '<S788>/Sum1'
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
  /* RelationalOperator: '<S800>/Compare' incorporates:
   *  Abs: '<S784>/Abs'
   *  Constant: '<S800>/Constant'
   *  MinMax: '<S784>/Max'
   *  Sum: '<S784>/Sum'
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
      /* Reshape: '<S783>/Reshape' incorporates:
       *  Constant: '<S783>/Constant'
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
          /* RelationalOperator: '<S786>/Compare' incorporates:
           *  Constant: '<S786>/Constant'
           *  S-Function (sfix_bitop): '<S778>/Bitwise AND'
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
          /* RelationalOperator: '<S779>/Relational Operator1' incorporates:
           *  Constant: '<S779>/Constant1'
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
        /* RelationalOperator: '<S777>/Relational Operator' incorporates:
         *  Constant: '<S777>/Constant'
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
          /* RelationalOperator: '<S776>/Relational Operator1' incorporates:
           *  Constant: '<S776>/Constant1'
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
  real32_T rtb_a_g;
  real32_T rtb_Sign5_mn;
  real32_T rtb_Add4_j4;
  MotionState rtb_state_l4;
  real32_T rtb_Subtract3_f;
  real32_T rtb_Sign5_dc;
  MotionState rtb_state_fg;
  real32_T rtb_Sign5_l;
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
  real32_T rtb_Subtract1_ky_0;
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
   *  ActionPort: '<S330>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S330>/Position' incorporates:
   *  ActionPort: '<S337>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S404>/Hold Control' incorporates:
   *  ActionPort: '<S406>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S331>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S331>/Offboard' incorporates:
   *  ActionPort: '<S443>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S333>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S333>/Land' incorporates:
   *  ActionPort: '<S633>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S333>/Takeoff' incorporates:
   *  ActionPort: '<S635>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
   *  ActionPort: '<S119>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S119>/Position' incorporates:
   *  ActionPort: '<S125>/Action Port'
   */
  /* SwitchCase: '<S119>/Switch Case' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  MultiPortSwitch: '<S525>/Index Vector'
   *  MultiPortSwitch: '<S590>/Index Vector'
   *  MultiPortSwitch: '<S591>/Index Vector'
   *  SwitchCase: '<S330>/Switch Case'
   *  SwitchCase: '<S331>/Switch Case'
   *  SwitchCase: '<S333>/Switch Case'
   *  SwitchCase: '<S404>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function1'
   *  Trigonometry: '<S100>/Trigonometric Function3'
   *  Trigonometry: '<S15>/Trigonometric Function1'
   *  Trigonometry: '<S15>/Trigonometric Function3'
   *  Trigonometry: '<S215>/Trigonometric Function1'
   *  Trigonometry: '<S215>/Trigonometric Function3'
   *  Trigonometry: '<S410>/Trigonometric Function1'
   *  Trigonometry: '<S410>/Trigonometric Function3'
   *  Trigonometry: '<S536>/Trigonometric Function1'
   *  Trigonometry: '<S536>/Trigonometric Function3'
   *  Trigonometry: '<S599>/Trigonometric Function1'
   *  Trigonometry: '<S599>/Trigonometric Function3'
   *  Trigonometry: '<S603>/Trigonometric Function1'
   *  Trigonometry: '<S603>/Trigonometric Function3'
   *  Trigonometry: '<S629>/Trigonometric Function1'
   *  Trigonometry: '<S629>/Trigonometric Function3'
   *  Trigonometry: '<S693>/Trigonometric Function1'
   *  Trigonometry: '<S693>/Trigonometric Function3'
   *  Trigonometry: '<S774>/Trigonometric Function1'
   *  Trigonometry: '<S774>/Trigonometric Function3'
   */
  rtb_Saturation_ga = arm_cos_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S119>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S333>/Takeoff' */
  /* End of Outputs for SubSystem: '<S333>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S331>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S404>/Hold Control' */
  /* End of Outputs for SubSystem: '<S330>/Position' */
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
   *  ActionPort: '<S330>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S330>/Position' incorporates:
   *  ActionPort: '<S337>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S404>/Hold Control' incorporates:
   *  ActionPort: '<S406>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S331>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S331>/Offboard' incorporates:
   *  ActionPort: '<S443>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S333>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S333>/Land' incorporates:
   *  ActionPort: '<S633>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S333>/Takeoff' incorporates:
   *  ActionPort: '<S635>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
   *  ActionPort: '<S119>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S119>/Position' incorporates:
   *  ActionPort: '<S125>/Action Port'
   */
  /* SwitchCase: '<S119>/Switch Case' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  MultiPortSwitch: '<S525>/Index Vector'
   *  MultiPortSwitch: '<S590>/Index Vector'
   *  MultiPortSwitch: '<S591>/Index Vector'
   *  SwitchCase: '<S330>/Switch Case'
   *  SwitchCase: '<S331>/Switch Case'
   *  SwitchCase: '<S333>/Switch Case'
   *  SwitchCase: '<S404>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function2'
   *  Trigonometry: '<S215>/Trigonometric Function'
   *  Trigonometry: '<S410>/Trigonometric Function'
   *  Trigonometry: '<S536>/Trigonometric Function'
   *  Trigonometry: '<S599>/Trigonometric Function'
   *  Trigonometry: '<S603>/Trigonometric Function'
   *  Trigonometry: '<S629>/Trigonometric Function'
   *  Trigonometry: '<S693>/Trigonometric Function'
   *  Trigonometry: '<S774>/Trigonometric Function'
   */
  rtb_Saturation1_d = arm_sin_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S119>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S333>/Takeoff' */
  /* End of Outputs for SubSystem: '<S333>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S331>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S404>/Hold Control' */
  /* End of Outputs for SubSystem: '<S330>/Position' */
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
    rtb_Saturation1_p5 = rtb_Divide_bu[2] * rtb_Divide_bu[2];

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
      + rtb_Saturation1_p5);

    /* Product: '<S20>/Multiply2' incorporates:
     *  Product: '<S19>/Multiply2'
     */
    rtb_u_b = rtb_Divide_bu[2] * rtb_Divide_bu[3];

    /* Product: '<S20>/Multiply3' incorporates:
     *  Product: '<S19>/Multiply3'
     */
    rtb_Add4_j4 = rtb_Divide_bu[0] * rtb_Divide_bu[1];

    /* Gain: '<S20>/Gain1' incorporates:
     *  Product: '<S20>/Multiply2'
     *  Product: '<S20>/Multiply3'
     *  Sum: '<S20>/Add2'
     */
    rtb_MatrixConcatenate1_a[7] = (rtb_u_b + rtb_Add4_j4) * 2.0F;

    /* Product: '<S20>/Multiply' incorporates:
     *  Product: '<S18>/Multiply2'
     */
    d = rtb_Divide_bu[1] * rtb_Divide_bu[3];

    /* Product: '<S20>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply3'
     */
    rtb_Sign5_l = rtb_Divide_bu[0] * rtb_Divide_bu[2];

    /* Gain: '<S20>/Gain' incorporates:
     *  Product: '<S20>/Multiply'
     *  Product: '<S20>/Multiply1'
     *  Sum: '<S20>/Subtract2'
     */
    rtb_MatrixConcatenate1_a[6] = (d - rtb_Sign5_l) * 2.0F;

    /* Gain: '<S19>/Gain1' incorporates:
     *  Sum: '<S19>/Subtract1'
     */
    rtb_MatrixConcatenate1_a[5] = (rtb_u_b - rtb_Add4_j4) * 2.0F;

    /* Sum: '<S19>/Subtract' incorporates:
     *  Sum: '<S19>/Add'
     *  Sum: '<S19>/Add1'
     */
    rtb_MatrixConcatenate1_a[4] = (rtb_Saturation_o4 + rtb_Saturation1_p5) -
      (rtb_Square_gf + rtb_Vg);

    /* Product: '<S19>/Multiply' incorporates:
     *  Product: '<S18>/Multiply'
     */
    rtb_u_b = rtb_Divide_bu[1] * rtb_Divide_bu[2];

    /* Product: '<S19>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply1'
     */
    rtb_Add4_j4 = rtb_Divide_bu[0] * rtb_Divide_bu[3];

    /* Gain: '<S19>/Gain' incorporates:
     *  Product: '<S19>/Multiply'
     *  Product: '<S19>/Multiply1'
     *  Sum: '<S19>/Add3'
     */
    rtb_MatrixConcatenate1_a[3] = (rtb_u_b + rtb_Add4_j4) * 2.0F;

    /* Gain: '<S18>/Gain1' incorporates:
     *  Sum: '<S18>/Add2'
     */
    rtb_MatrixConcatenate1_a[2] = (d + rtb_Sign5_l) * 2.0F;

    /* Gain: '<S18>/Gain' incorporates:
     *  Sum: '<S18>/Subtract1'
     */
    rtb_MatrixConcatenate1_a[1] = (rtb_u_b - rtb_Add4_j4) * 2.0F;

    /* Sum: '<S18>/Subtract' incorporates:
     *  Sum: '<S18>/Add'
     *  Sum: '<S18>/Add1'
     */
    rtb_MatrixConcatenate1_a[0] = (rtb_Saturation_o4 + rtb_Square_gf) -
      (rtb_Saturation1_p5 + rtb_Vg);

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
   *  ActionPort: '<S120>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S120>/Mission' incorporates:
   *  ActionPort: '<S231>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S231>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S235>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
   *  ActionPort: '<S122>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S122>/Return' incorporates:
   *  ActionPort: '<S265>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S122>/Takeoff' incorporates:
   *  ActionPort: '<S266>/Action Port'
   */
  /* SwitchCase: '<S120>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S254>/Math Function'
   *  Math: '<S303>/Math Function'
   *  Math: '<S325>/Math Function'
   *  SwitchCase: '<S122>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   */
  rtb_Saturation_o4 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Add4_j4 = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S122>/Takeoff' */
  /* End of Outputs for SubSystem: '<S122>/Return' */
  /* End of Outputs for SubSystem: '<S231>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S120>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */

  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S331>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S331>/Mission' incorporates:
   *  ActionPort: '<S442>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S442>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S446>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S333>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S333>/Return' incorporates:
   *  ActionPort: '<S634>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S122>/Hold' incorporates:
   *  ActionPort: '<S263>/Action Port'
   */
  /* SwitchCase: '<S122>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S280>/Sum of Elements'
   *  Sum: '<S514>/Sum of Elements'
   *  Sum: '<S754>/Sum of Elements'
   *  SwitchCase: '<S331>/Switch Case'
   *  SwitchCase: '<S333>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  d = rtb_Saturation_o4 + rtb_Add4_j4;

  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S330>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S330>/Position' incorporates:
   *  ActionPort: '<S337>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S120>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S120>/Mission' incorporates:
   *  ActionPort: '<S231>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S231>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S235>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S122>/Return' incorporates:
   *  ActionPort: '<S265>/Action Port'
   */
  /* SwitchCase: '<S120>/Switch Case' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S253>/Sqrt'
   *  Sqrt: '<S279>/Sqrt'
   *  Sqrt: '<S302>/Sqrt'
   *  Sqrt: '<S405>/Sqrt'
   *  Sqrt: '<S512>/Sqrt'
   *  Sqrt: '<S752>/Sqrt'
   *  Sum: '<S1>/Add'
   *  SwitchCase: '<S122>/Switch Case'
   *  SwitchCase: '<S330>/Switch Case'
   *  SwitchCase: '<S331>/Switch Case'
   *  SwitchCase: '<S333>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Saturation1_p5 = sqrtf(d);

  /* End of Outputs for SubSystem: '<S122>/Return' */
  /* End of Outputs for SubSystem: '<S231>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S120>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */
  /* End of Outputs for SubSystem: '<S330>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S122>/Hold' */
  /* End of Outputs for SubSystem: '<S333>/Return' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S442>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S331>/Mission' */
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
        /* Disable for SwitchCase: '<S122>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S120>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S119>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S132>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S169>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S155>/Switch Case' */
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
        /* Disable for SwitchCase: '<S333>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S733>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S723>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S672>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S640>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S651>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S331>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S442>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S493>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S483>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S442>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S330>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S429>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S345>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S363>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S379>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S404>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S391>/Switch Case' */
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
          /* Disable for SwitchCase: '<S122>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S120>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S119>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S132>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S169>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S155>/Switch Case' */
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
          /* Disable for SwitchCase: '<S333>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S733>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S723>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S672>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S640>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S651>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S331>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S442>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S493>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S483>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S442>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S330>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S429>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S345>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S363>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S379>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S404>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S391>/Switch Case' */
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
          /* Disable for SwitchCase: '<S122>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S120>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S119>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S132>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S169>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S155>/Switch Case' */
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
         *  ActionPort: '<S122>/Action Port'
         */
        /* SwitchCase: '<S122>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S122>/Takeoff' incorporates:
           *  ActionPort: '<S266>/Action Port'
           */
          /* Sum: '<S325>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_j4;

          /* Math: '<S325>/Math Function1' incorporates:
           *  Sum: '<S325>/Sum of Elements'
           *
           * About '<S325>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S325>/Math Function1' */

          /* Switch: '<S325>/Switch' incorporates:
           *  Constant: '<S325>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S325>/Product'
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

          /* End of Switch: '<S325>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S315>/NearbyRefWP' incorporates:
           *  Constant: '<S313>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_f0,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S315>/SearchL1RefWP' incorporates:
           *  Constant: '<S313>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_ap, &rtb_u_b);

          /* MATLAB Function: '<S315>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S310>/Sum'
           *  Sum: '<S310>/Sum1'
           */
          rtb_Saturation1_p5 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint
            [1];
          rtb_a_g = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Sign5_l * rtb_Sign5_l;
          rtb_Saturation_ga = (rtb_a_g * rtb_Sign5_l + d * rtb_Saturation1_p5) /
            (rtb_P_f_idx_0 + rtb_Saturation1_p5 * rtb_Saturation1_p5);
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
            rtb_Sign5_mn = (rtb_Saturation_ga * rtb_Sign5_l +
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
            rtb_Saturation_ga = rtb_Saturation_ga * rtb_Sign5_l +
              FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S315>/OutRegionRegWP' */

          /* Switch: '<S315>/Switch1' incorporates:
           *  Constant: '<S318>/Constant'
           *  RelationalOperator: '<S318>/Compare'
           */
          if (rtb_Saturation1_d <= 0.0F) {
            /* Switch: '<S315>/Switch' incorporates:
             *  Constant: '<S317>/Constant'
             *  RelationalOperator: '<S317>/Compare'
             */
            if (rtb_u_b >= 0.0F) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            } else {
              rtb_Divide_f0[0] = rtb_P_f_idx_0;
              rtb_Divide_f0[1] = rtb_Saturation_ga;
            }

            /* End of Switch: '<S315>/Switch' */
          }

          /* End of Switch: '<S315>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S316>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S326>/Sum of Elements' incorporates:
           *  Math: '<S326>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S326>/Math Function1' incorporates:
           *  Sum: '<S326>/Sum of Elements'
           *
           * About '<S326>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S326>/Math Function1' */

          /* Switch: '<S326>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  Product: '<S326>/Product'
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

          /* End of Switch: '<S326>/Switch' */

          /* Product: '<S325>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S328>/Sum of Elements' incorporates:
           *  Math: '<S328>/Math Function'
           *  SignalConversion: '<S328>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S328>/Math Function1' incorporates:
           *  Sum: '<S328>/Sum of Elements'
           *
           * About '<S328>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S328>/Math Function1' */

          /* Switch: '<S328>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  Product: '<S328>/Product'
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

          /* End of Switch: '<S328>/Switch' */

          /* Product: '<S326>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S329>/Sum of Elements' incorporates:
           *  Math: '<S329>/Math Function'
           *  SignalConversion: '<S329>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S329>/Math Function1' incorporates:
           *  Sum: '<S329>/Sum of Elements'
           *
           * About '<S329>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S329>/Math Function1' */

          /* Switch: '<S329>/Switch' incorporates:
           *  Constant: '<S329>/Constant'
           *  Product: '<S329>/Product'
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

          /* End of Switch: '<S329>/Switch' */

          /* Product: '<S329>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S328>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S329>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S328>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S310>/Divide' incorporates:
           *  Math: '<S311>/Square'
           *  Math: '<S312>/Square'
           *  Sqrt: '<S311>/Sqrt'
           *  Sqrt: '<S312>/Sqrt'
           *  Sum: '<S311>/Sum of Elements'
           *  Sum: '<S312>/Sum of Elements'
           */
          rtb_Saturation1_p5 = sqrtf(rtb_a_g * rtb_a_g + d * d) / sqrtf
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 + rtb_Sign5_l * rtb_Sign5_l);

          /* Saturate: '<S310>/Saturation' */
          if (rtb_Saturation1_p5 > 1.0F) {
            rtb_Saturation1_p5 = 1.0F;
          } else {
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation1_p5 = 0.0F;
            }
          }

          /* End of Saturate: '<S310>/Saturation' */

          /* Sum: '<S327>/Subtract' incorporates:
           *  Product: '<S327>/Multiply'
           *  Product: '<S327>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S323>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign1' */

          /* Switch: '<S323>/Switch2' incorporates:
           *  Constant: '<S323>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S323>/Switch2' */

          /* DotProduct: '<S323>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S323>/Acos' incorporates:
           *  DotProduct: '<S323>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S323>/Multiply' incorporates:
           *  Trigonometry: '<S323>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S322>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S322>/Saturation' */

          /* Sqrt: '<S324>/Sqrt' incorporates:
           *  Sum: '<S324>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(rtb_Saturation_o4 + rtb_Add4_j4);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S266>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S266>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S266>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S266>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S322>/Divide' incorporates:
           *  Constant: '<S313>/L1'
           *  Gain: '<S322>/Gain'
           *  Math: '<S322>/Square'
           *  Product: '<S322>/Multiply1'
           *  Trigonometry: '<S322>/Sin'
           */
          rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F * arm_sin_f32
            (rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S313>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S266>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S266>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S266>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S313>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S308>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S310>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S308>/Sum2'
           *  Sum: '<S310>/Add'
           *  Sum: '<S310>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_p5 +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S308>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S266>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S266>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S266>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S308>/Saturation1' */
          /* End of Outputs for SubSystem: '<S122>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S122>/Land' incorporates:
           *  ActionPort: '<S264>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S264>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S264>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S264>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S264>/Constant'
           *  Constant: '<S264>/Constant4'
           *  Constant: '<S264>/Constant5'
           *  Constant: '<S264>/Constant7'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S122>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S122>/Return' incorporates:
           *  ActionPort: '<S265>/Action Port'
           */
          /* Math: '<S303>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Add4_j4;

          /* Sum: '<S303>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_j4;

          /* Math: '<S303>/Math Function1' incorporates:
           *  Sum: '<S303>/Sum of Elements'
           *
           * About '<S303>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S303>/Math Function1' */

          /* Switch: '<S303>/Switch' incorporates:
           *  Constant: '<S303>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S303>/Product'
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

          /* End of Switch: '<S303>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S293>/NearbyRefWP' incorporates:
           *  Constant: '<S291>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S293>/SearchL1RefWP' incorporates:
           *  Constant: '<S291>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_f0, &rtb_Saturation1_d);

          /* MATLAB Function: '<S293>/OutRegionRegWP' incorporates:
           *  Constant: '<S291>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0],
                             &rtb_TmpSignalConversionAtMultip[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S293>/Switch1' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_f0[0] = rtb_Subtract_hb[0];
            rtb_Divide_f0[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S295>/Compare' incorporates:
             *  Constant: '<S295>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S293>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S293>/Switch' */
          }

          /* End of Switch: '<S293>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S294>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S304>/Sum of Elements' incorporates:
           *  Math: '<S304>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S304>/Math Function1' incorporates:
           *  Sum: '<S304>/Sum of Elements'
           *
           * About '<S304>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S304>/Math Function1' */

          /* Switch: '<S304>/Switch' incorporates:
           *  Constant: '<S304>/Constant'
           *  Product: '<S304>/Product'
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

          /* End of Switch: '<S304>/Switch' */

          /* Product: '<S303>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S306>/Sum of Elements' incorporates:
           *  Math: '<S306>/Math Function'
           *  SignalConversion: '<S306>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S306>/Math Function1' incorporates:
           *  Sum: '<S306>/Sum of Elements'
           *
           * About '<S306>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S306>/Math Function1' */

          /* Switch: '<S306>/Switch' incorporates:
           *  Constant: '<S306>/Constant'
           *  Product: '<S306>/Product'
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

          /* End of Switch: '<S306>/Switch' */

          /* Product: '<S304>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S307>/Sum of Elements' incorporates:
           *  Math: '<S307>/Math Function'
           *  SignalConversion: '<S307>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S307>/Math Function1' incorporates:
           *  Sum: '<S307>/Sum of Elements'
           *
           * About '<S307>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S307>/Math Function1' */

          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S307>/Constant'
           *  Product: '<S307>/Product'
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

          /* End of Switch: '<S307>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S288>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_g = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S307>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S306>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S288>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S307>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S306>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S288>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S288>/Divide' incorporates:
           *  Math: '<S289>/Square'
           *  Math: '<S290>/Square'
           *  Sqrt: '<S289>/Sqrt'
           *  Sqrt: '<S290>/Sqrt'
           *  Sum: '<S288>/Sum'
           *  Sum: '<S288>/Sum1'
           *  Sum: '<S289>/Sum of Elements'
           *  Sum: '<S290>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_g * rtb_a_g + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Sign5_l * rtb_Sign5_l + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S288>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S288>/Saturation' */

          /* Sum: '<S305>/Subtract' incorporates:
           *  Product: '<S305>/Multiply'
           *  Product: '<S305>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S301>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S301>/Sign1' */

          /* Switch: '<S301>/Switch2' incorporates:
           *  Constant: '<S301>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S301>/Switch2' */

          /* DotProduct: '<S301>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S301>/Acos' incorporates:
           *  DotProduct: '<S301>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S301>/Multiply' incorporates:
           *  Trigonometry: '<S301>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S300>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S300>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S265>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S265>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S265>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S300>/Divide' incorporates:
           *  Constant: '<S291>/L1'
           *  Gain: '<S300>/Gain'
           *  Math: '<S300>/Square'
           *  Product: '<S300>/Multiply1'
           *  Trigonometry: '<S300>/Sin'
           */
          rtb_u_b = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F * arm_sin_f32
            (rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S291>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S291>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S286>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S288>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S286>/Sum2'
           *  Sum: '<S288>/Add'
           *  Sum: '<S288>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S286>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S265>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S286>/Saturation1' */
          /* End of Outputs for SubSystem: '<S122>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S122>/Hold' incorporates:
             *  ActionPort: '<S263>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S122>/Switch Case' incorporates:
             *  Delay: '<S268>/Delay'
             *  Delay: '<S273>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S122>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S122>/Hold' incorporates:
           *  ActionPort: '<S263>/Action Port'
           */
          /* Math: '<S280>/Math Function1'
           *
           * About '<S280>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(d));
          } else {
            rtb_Saturation_ga = sqrtf(d);
          }

          /* End of Math: '<S280>/Math Function1' */

          /* Switch: '<S280>/Switch' incorporates:
           *  Constant: '<S280>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S280>/Product'
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

          /* End of Switch: '<S280>/Switch' */

          /* Delay: '<S273>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S285>/Sum of Elements' incorporates:
           *  Delay: '<S273>/start_vel'
           *  Math: '<S285>/Math Function'
           */
          rtb_u_b = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S285>/Math Function1' incorporates:
           *  Sum: '<S285>/Sum of Elements'
           *
           * About '<S285>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S285>/Math Function1' */

          /* Switch: '<S285>/Switch' incorporates:
           *  Constant: '<S285>/Constant'
           *  Delay: '<S273>/start_vel'
           *  Product: '<S285>/Product'
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

          /* End of Switch: '<S285>/Switch' */

          /* Product: '<S280>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S283>/Sum of Elements' incorporates:
           *  Math: '<S283>/Math Function'
           *  SignalConversion: '<S283>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S283>/Math Function1' incorporates:
           *  Sum: '<S283>/Sum of Elements'
           *
           * About '<S283>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S283>/Math Function1' */

          /* Switch: '<S283>/Switch' incorporates:
           *  Constant: '<S283>/Constant'
           *  Product: '<S283>/Product'
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

          /* End of Switch: '<S283>/Switch' */

          /* MinMax: '<S271>/Max' incorporates:
           *  Constant: '<S269>/L1'
           *  Constant: '<S269>/R'
           *  Gain: '<S271>/Gain'
           */
          rtb_Saturation_ga = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S271>/SearchL1RefWP' incorporates:
           *  Constant: '<S269>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S276>/TmpSignal ConversionAt SFunction Inport2'
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
            rtb_Add4_j4 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Add4_j4 * rtb_Add4_j4 + rtb_u_b * rtb_u_b);
            rtb_Saturation_o4 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Saturation1_d = ((d * d + rtb_Saturation_o4) - rtb_Saturation_ga
                                 * rtb_Saturation_ga) / (2.0F * d);
            rtb_Square_dv[0] = rtb_u_b / d;
            rtb_Add4_j4 /= d;
            rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d;
            if (rtb_u_b > rtb_Saturation_o4) {
              rtb_n = 0;
            } else if (rtb_u_b == rtb_Saturation_o4) {
              rtb_n = 1;
              rtb_P_ap[0] = rtb_Saturation1_d * rtb_Square_dv[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_ap[1] = rtb_Saturation1_d * rtb_Add4_j4 + FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation_o4 = sqrtf(rtb_Saturation_o4 - rtb_u_b);
              rtb_P_ap[0] = (rtb_Saturation1_d * rtb_Square_dv[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation_o4 *
                -rtb_Add4_j4;
              rtb_P_ap[1] = (rtb_Saturation1_d * rtb_Add4_j4 + FMS_U.INS_Out.y_R)
                + rtb_Saturation_o4 * rtb_Square_dv[0];
            }
          }

          /* End of MATLAB Function: '<S271>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S274>/Compare' incorporates:
           *  Constant: '<S274>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S271>/OutRegionRegWP' incorporates:
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

          /* Switch: '<S271>/Switch' incorporates:
           *  Constant: '<S269>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S271>/OutRegionRegWP'
           *  Product: '<S285>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_d = rtb_P_ap[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S271>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S272>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_dv[0] = rtb_Saturation1_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S271>/Switch' incorporates:
           *  Constant: '<S269>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S271>/OutRegionRegWP'
           *  Product: '<S285>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_d = rtb_P_ap[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S271>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S272>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_dv[1] = rtb_Saturation1_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S281>/Sum of Elements' incorporates:
           *  Math: '<S281>/Math Function'
           */
          rtb_u_b = rtb_Square_dv[0] * rtb_Square_dv[0] + rtb_Square_dv[1] *
            rtb_Square_dv[1];

          /* Math: '<S281>/Math Function1' incorporates:
           *  Sum: '<S281>/Sum of Elements'
           *
           * About '<S281>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S281>/Math Function1' */

          /* Switch: '<S281>/Switch' incorporates:
           *  Constant: '<S281>/Constant'
           *  Product: '<S281>/Product'
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

          /* End of Switch: '<S281>/Switch' */

          /* Product: '<S281>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_f0[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S284>/Sum of Elements' incorporates:
           *  Math: '<S284>/Math Function'
           *  SignalConversion: '<S284>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S284>/Math Function1' incorporates:
           *  Sum: '<S284>/Sum of Elements'
           *
           * About '<S284>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S284>/Math Function1' */

          /* Switch: '<S284>/Switch' incorporates:
           *  Constant: '<S284>/Constant'
           *  Product: '<S284>/Product'
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

          /* End of Switch: '<S284>/Switch' */

          /* Product: '<S284>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S283>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S284>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S283>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S282>/Subtract' incorporates:
           *  Product: '<S282>/Multiply'
           *  Product: '<S282>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Divide_f0[0] * rtb_Subtract_hb[1] -
            rtb_Divide_f0[1] * rtb_Subtract_hb[0];

          /* Signum: '<S278>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S278>/Sign1' */

          /* Switch: '<S278>/Switch2' incorporates:
           *  Constant: '<S278>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S278>/Switch2' */

          /* DotProduct: '<S278>/Dot Product' */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[0] +
            rtb_Subtract_hb[1] * rtb_Divide_f0[1];

          /* Trigonometry: '<S278>/Acos' incorporates:
           *  DotProduct: '<S278>/Dot Product'
           */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < -1.0F) {
              rtb_Saturation_o4 = -1.0F;
            }
          }

          /* Product: '<S278>/Multiply' incorporates:
           *  Trigonometry: '<S278>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation_o4);

          /* Saturate: '<S277>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S277>/Saturation' */

          /* Delay: '<S268>/Delay' incorporates:
           *  Gain: '<S270>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S263>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S263>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S263>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S263>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S277>/Divide' incorporates:
           *  Constant: '<S269>/L1'
           *  Gain: '<S277>/Gain'
           *  Math: '<S277>/Square'
           *  Product: '<S277>/Multiply1'
           *  Trigonometry: '<S277>/Sin'
           */
          rtb_u_b = 2.0F * (rtb_Saturation1_p5 * rtb_Saturation1_p5) *
            arm_sin_f32(rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S269>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S263>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S263>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S263>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S269>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S268>/Gain2' incorporates:
           *  Delay: '<S268>/Delay'
           *  Gain: '<S270>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S268>/Sum'
           */
          rtb_u_b = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S268>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S263>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S263>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S263>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S268>/Saturation1' */

          /* Update for Delay: '<S273>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S268>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S122>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S122>/Unknown' incorporates:
           *  ActionPort: '<S267>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S122>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
         *  ActionPort: '<S120>/Action Port'
         */
        /* SwitchCase: '<S120>/Switch Case' incorporates:
         *  RelationalOperator: '<S234>/FixPt Relational Operator'
         *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S234>/Delay Input1'
         *
         * Block description for '<S234>/Delay Input1':
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
          /* Outputs for IfAction SubSystem: '<S120>/Offboard' incorporates:
           *  ActionPort: '<S232>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S232>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S232>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S232>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S120>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_hd != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S120>/Mission' incorporates:
             *  ActionPort: '<S231>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S120>/Switch Case' incorporates:
             *  UnitDelay: '<S234>/Delay Input1'
             *
             * Block description for '<S234>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S120>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S120>/Mission' incorporates:
           *  ActionPort: '<S231>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S231>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S235>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S254>/Math Function' incorporates:
           *  RelationalOperator: '<S234>/FixPt Relational Operator'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S234>/Delay Input1'
           *
           * Block description for '<S234>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Add4_j4;

          /* Sum: '<S254>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Add4_j4;

          /* Math: '<S254>/Math Function1' incorporates:
           *  Sum: '<S254>/Sum of Elements'
           *
           * About '<S254>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S254>/Math Function1' */

          /* Switch: '<S254>/Switch' incorporates:
           *  Constant: '<S254>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S254>/Product'
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

          /* End of Switch: '<S254>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S244>/NearbyRefWP' incorporates:
           *  Constant: '<S242>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S244>/SearchL1RefWP' incorporates:
           *  Constant: '<S242>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_f0, &rtb_Saturation1_d);

          /* MATLAB Function: '<S244>/OutRegionRegWP' incorporates:
           *  Constant: '<S242>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0],
                             &rtb_TmpSignalConversionAtMultip[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S244>/Switch1' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_f0[0] = rtb_Subtract_hb[0];
            rtb_Divide_f0[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S246>/Compare' incorporates:
             *  Constant: '<S246>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S244>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S244>/Switch' */
          }

          /* End of Switch: '<S244>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S245>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S255>/Sum of Elements' incorporates:
           *  Math: '<S255>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S255>/Math Function1' incorporates:
           *  Sum: '<S255>/Sum of Elements'
           *
           * About '<S255>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S255>/Math Function1' */

          /* Switch: '<S255>/Switch' incorporates:
           *  Constant: '<S255>/Constant'
           *  Product: '<S255>/Product'
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

          /* End of Switch: '<S255>/Switch' */

          /* Product: '<S254>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S257>/Sum of Elements' incorporates:
           *  Math: '<S257>/Math Function'
           *  SignalConversion: '<S257>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S257>/Math Function1' incorporates:
           *  Sum: '<S257>/Sum of Elements'
           *
           * About '<S257>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S257>/Math Function1' */

          /* Switch: '<S257>/Switch' incorporates:
           *  Constant: '<S257>/Constant'
           *  Product: '<S257>/Product'
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

          /* End of Switch: '<S257>/Switch' */

          /* Product: '<S255>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S258>/Sum of Elements' incorporates:
           *  Math: '<S258>/Math Function'
           *  SignalConversion: '<S258>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S258>/Math Function1' incorporates:
           *  Sum: '<S258>/Sum of Elements'
           *
           * About '<S258>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S258>/Math Function1' */

          /* Switch: '<S258>/Switch' incorporates:
           *  Constant: '<S258>/Constant'
           *  Product: '<S258>/Product'
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

          /* End of Switch: '<S258>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S239>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_g = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S258>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S257>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S239>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S258>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S257>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S239>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S239>/Divide' incorporates:
           *  Math: '<S240>/Square'
           *  Math: '<S241>/Square'
           *  Sqrt: '<S240>/Sqrt'
           *  Sqrt: '<S241>/Sqrt'
           *  Sum: '<S239>/Sum'
           *  Sum: '<S239>/Sum1'
           *  Sum: '<S240>/Sum of Elements'
           *  Sum: '<S241>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_g * rtb_a_g + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Sign5_l * rtb_Sign5_l + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S239>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S239>/Saturation' */

          /* Sum: '<S256>/Subtract' incorporates:
           *  Product: '<S256>/Multiply'
           *  Product: '<S256>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S252>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S252>/Sign1' */

          /* Switch: '<S252>/Switch2' incorporates:
           *  Constant: '<S252>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S252>/Switch2' */

          /* DotProduct: '<S252>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S252>/Acos' incorporates:
           *  DotProduct: '<S252>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S252>/Multiply' incorporates:
           *  Trigonometry: '<S252>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S251>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S251>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S235>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S235>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S235>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S237>/Switch' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
          } else {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Constant: '<S237>/Constant4'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S237>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S251>/Divide' incorporates:
           *  Constant: '<S242>/L1'
           *  Gain: '<S251>/Gain'
           *  Math: '<S251>/Square'
           *  Product: '<S251>/Multiply1'
           *  Trigonometry: '<S251>/Sin'
           */
          rtb_u_b = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F * arm_sin_f32
            (rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S242>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S242>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S236>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S239>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S236>/Sum2'
           *  Sum: '<S239>/Add'
           *  Sum: '<S239>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S236>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S235>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S236>/Saturation1' */
          /* End of Outputs for SubSystem: '<S231>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S234>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S234>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S120>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S120>/Unknown' incorporates:
           *  ActionPort: '<S233>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S120>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
         *  ActionPort: '<S119>/Action Port'
         */
        /* SwitchCase: '<S119>/Switch Case' */
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
            /* Disable for SwitchCase: '<S132>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S169>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S155>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S119>/Stabilize' incorporates:
             *  ActionPort: '<S126>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S119>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S224>/Integrator'
             *  DiscreteIntegrator: '<S224>/Integrator1'
             *  DiscreteIntegrator: '<S225>/Integrator'
             *  DiscreteIntegrator: '<S225>/Integrator1'
             *  DiscreteIntegrator: '<S229>/Integrator'
             *  DiscreteIntegrator: '<S229>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_av = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S119>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S119>/Stabilize' incorporates:
           *  ActionPort: '<S126>/Action Port'
           */
          /* Product: '<S226>/Multiply1' incorporates:
           *  Constant: '<S226>/const1'
           *  DiscreteIntegrator: '<S224>/Integrator'
           */
          rtb_a_g = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S222>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S222>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S226>/Add' incorporates:
           *  DiscreteIntegrator: '<S224>/Integrator1'
           *  Gain: '<S219>/Gain'
           *  Gain: '<S222>/Gain'
           *  Sum: '<S224>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) + rtb_a_g;

          /* Signum: '<S226>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
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
          d = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_ny) *
                     FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_ga + rtb_a_g;

          /* Sum: '<S226>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - d) + rtb_a_g;

          /* Sum: '<S226>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S226>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

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
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign2' */

          /* Sum: '<S226>/Add5' incorporates:
           *  Gain: '<S226>/Gain2'
           *  Product: '<S226>/Multiply4'
           *  Sum: '<S226>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S126>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S126>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S126>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S224>/Integrator1'
           *  DiscreteIntegrator: '<S225>/Integrator1'
           *  DiscreteIntegrator: '<S229>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S221>/Saturation' incorporates:
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

          /* End of Saturate: '<S221>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S126>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S221>/Constant5'
           *  Gain: '<S221>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S221>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_u_b), 65536.0F) + 1000U);

          /* Product: '<S230>/Multiply1' incorporates:
           *  Constant: '<S230>/const1'
           *  DiscreteIntegrator: '<S229>/Integrator'
           */
          rtb_a_g = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S228>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S228>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S230>/Add' incorporates:
           *  DiscreteIntegrator: '<S229>/Integrator1'
           *  Gain: '<S220>/Gain1'
           *  Gain: '<S228>/Gain'
           *  Sum: '<S229>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_g;

          /* Signum: '<S230>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S230>/Sign' */

          /* Sum: '<S230>/Add2' incorporates:
           *  Abs: '<S230>/Abs'
           *  Gain: '<S230>/Gain'
           *  Gain: '<S230>/Gain1'
           *  Product: '<S230>/Multiply2'
           *  Product: '<S230>/Multiply3'
           *  Sqrt: '<S230>/Sqrt'
           *  Sum: '<S230>/Add1'
           *  Sum: '<S230>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_h) *
            FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F * rtb_Add4_j4 + rtb_a_g;

          /* Sum: '<S230>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Saturation1_p5) + rtb_a_g;

          /* Sum: '<S230>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_h;

          /* Sum: '<S230>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_h;

          /* Signum: '<S230>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S230>/Sign1' */

          /* Signum: '<S230>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S230>/Sign2' */

          /* Sum: '<S230>/Add5' incorporates:
           *  Gain: '<S230>/Gain2'
           *  Product: '<S230>/Multiply4'
           *  Sum: '<S230>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S230>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_h;

          /* Sum: '<S230>/Subtract3' */
          rtb_Saturation1_d = rtb_Saturation1_p5 - FMS_ConstB.d_h;

          /* Product: '<S230>/Divide' */
          rtb_P_f_idx_0 = rtb_Saturation1_p5 / FMS_ConstB.d_h;

          /* Signum: '<S230>/Sign5' incorporates:
           *  Signum: '<S230>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S230>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S230>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Saturation1_p5;

            /* Signum: '<S230>/Sign6' */
            rtb_Saturation_o4 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S230>/Sign5' */

          /* Product: '<S227>/Multiply1' incorporates:
           *  Constant: '<S227>/const1'
           *  DiscreteIntegrator: '<S225>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S223>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S223>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S227>/Add' incorporates:
           *  DiscreteIntegrator: '<S225>/Integrator1'
           *  Gain: '<S219>/Gain1'
           *  Gain: '<S223>/Gain'
           *  Sum: '<S225>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S227>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S227>/Sign' */

          /* Sum: '<S227>/Add2' incorporates:
           *  Abs: '<S227>/Abs'
           *  Gain: '<S227>/Gain'
           *  Gain: '<S227>/Gain1'
           *  Product: '<S227>/Multiply2'
           *  Product: '<S227>/Multiply3'
           *  Sqrt: '<S227>/Sqrt'
           *  Sum: '<S227>/Add1'
           *  Sum: '<S227>/Subtract'
           */
          rtb_a_g = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_my) *
                           FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Add4_j4 + rtb_Saturation1_p5;

          /* Sum: '<S227>/Add4' */
          rtb_Add4_j4 = (rtb_u_b - rtb_a_g) + rtb_Saturation1_p5;

          /* Sum: '<S227>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_my;

          /* Sum: '<S227>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_my;

          /* Signum: '<S227>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S227>/Sign1' */

          /* Signum: '<S227>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S227>/Sign2' */

          /* Sum: '<S227>/Add5' incorporates:
           *  Gain: '<S227>/Gain2'
           *  Product: '<S227>/Multiply4'
           *  Sum: '<S227>/Subtract2'
           */
          rtb_a_g += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Add4_j4;

          /* Update for DiscreteIntegrator: '<S224>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S224>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S226>/Subtract3' */
          rtb_Saturation1_p5 = d - FMS_ConstB.d_ny;

          /* Sum: '<S226>/Add6' */
          rtb_Add4_j4 = d + FMS_ConstB.d_ny;

          /* Signum: '<S226>/Sign5' incorporates:
           *  Signum: '<S226>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S226>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (d > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S226>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Sign5_l = d;

            /* Signum: '<S226>/Sign6' */
            rtb_u_b = d;
          }

          /* End of Signum: '<S226>/Sign5' */

          /* Signum: '<S226>/Sign3' */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else {
            if (rtb_Add4_j4 > 0.0F) {
              rtb_Add4_j4 = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign3' */

          /* Signum: '<S226>/Sign4' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S226>/Sign4' */

          /* Update for DiscreteIntegrator: '<S224>/Integrator' incorporates:
           *  Constant: '<S226>/const'
           *  Gain: '<S226>/Gain3'
           *  Product: '<S226>/Divide'
           *  Product: '<S226>/Multiply5'
           *  Product: '<S226>/Multiply6'
           *  Sum: '<S226>/Subtract4'
           *  Sum: '<S226>/Subtract5'
           *  Sum: '<S226>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((d / FMS_ConstB.d_ny - rtb_Sign5_l) *
            FMS_ConstB.Gain4_ko * ((rtb_Add4_j4 - rtb_Saturation1_p5) * 0.5F) -
            rtb_u_b * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S225>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S225>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S229>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S229>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S230>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S230>/Sign3' */

          /* Signum: '<S230>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S230>/Sign4' */

          /* Update for DiscreteIntegrator: '<S229>/Integrator' incorporates:
           *  Constant: '<S230>/const'
           *  Gain: '<S230>/Gain3'
           *  Product: '<S230>/Multiply5'
           *  Product: '<S230>/Multiply6'
           *  Sum: '<S230>/Subtract4'
           *  Sum: '<S230>/Subtract5'
           *  Sum: '<S230>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_P_f_idx_0 - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 15.707963F) * 0.004F;

          /* Sum: '<S227>/Subtract3' */
          rtb_Saturation_ga = rtb_a_g - FMS_ConstB.d_my;

          /* Sum: '<S227>/Add6' */
          rtb_Saturation1_d = rtb_a_g + FMS_ConstB.d_my;

          /* Signum: '<S227>/Sign5' incorporates:
           *  Signum: '<S227>/Sign6'
           */
          if (rtb_a_g < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S227>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_a_g > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S227>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_a_g;

            /* Signum: '<S227>/Sign6' */
            rtb_Sign5_l = rtb_a_g;
          }

          /* End of Signum: '<S227>/Sign5' */

          /* Signum: '<S227>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S227>/Sign3' */

          /* Signum: '<S227>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S227>/Sign4' */

          /* Update for DiscreteIntegrator: '<S225>/Integrator' incorporates:
           *  Constant: '<S227>/const'
           *  Gain: '<S227>/Gain3'
           *  Product: '<S227>/Divide'
           *  Product: '<S227>/Multiply5'
           *  Product: '<S227>/Multiply6'
           *  Sum: '<S227>/Subtract4'
           *  Sum: '<S227>/Subtract5'
           *  Sum: '<S227>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_g / FMS_ConstB.d_my -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_k2 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S119>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S119>/Altitude' incorporates:
             *  ActionPort: '<S124>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S119>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S144>/Integrator'
             *  DiscreteIntegrator: '<S144>/Integrator1'
             *  DiscreteIntegrator: '<S147>/Integrator'
             *  DiscreteIntegrator: '<S147>/Integrator1'
             *  DiscreteIntegrator: '<S149>/Integrator'
             *  DiscreteIntegrator: '<S149>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator1_DSTATE_mg = 0.0F;
            FMS_DW.Integrator_DSTATE_l = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S119>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S119>/Altitude' incorporates:
             *  ActionPort: '<S124>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S119>/Switch Case' incorporates:
             *  Chart: '<S133>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S119>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S119>/Altitude' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S133>/Motion Status' incorporates:
           *  Abs: '<S133>/Abs'
           *  Abs: '<S133>/Abs1'
           *  Constant: '<S141>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S141>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S132>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S132>/Hold Control' incorporates:
               *  ActionPort: '<S135>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S132>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S132>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S132>/Hold Control' incorporates:
             *  ActionPort: '<S135>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S132>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S132>/Brake Control' incorporates:
             *  ActionPort: '<S134>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S132>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S132>/Move Control' incorporates:
               *  ActionPort: '<S136>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S132>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S132>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S132>/Move Control' incorporates:
             *  ActionPort: '<S136>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S132>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S132>/Switch Case' */

          /* Product: '<S145>/Multiply1' incorporates:
           *  Constant: '<S145>/const1'
           *  DiscreteIntegrator: '<S144>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S143>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S143>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S145>/Add' incorporates:
           *  DiscreteIntegrator: '<S144>/Integrator1'
           *  Gain: '<S129>/Gain'
           *  Gain: '<S143>/Gain'
           *  Sum: '<S144>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Saturation_ga;

          /* Signum: '<S145>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S145>/Sign' */

          /* Sum: '<S145>/Add2' incorporates:
           *  Abs: '<S145>/Abs'
           *  Gain: '<S145>/Gain'
           *  Gain: '<S145>/Gain1'
           *  Product: '<S145>/Multiply2'
           *  Product: '<S145>/Multiply3'
           *  Sqrt: '<S145>/Sqrt'
           *  Sum: '<S145>/Add1'
           *  Sum: '<S145>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_bi) *
                     FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S145>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - d) + rtb_Saturation_ga;

          /* Sum: '<S145>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_bi;

          /* Sum: '<S145>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_bi;

          /* Signum: '<S145>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S145>/Sign1' */

          /* Signum: '<S145>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S145>/Sign2' */

          /* Sum: '<S145>/Add5' incorporates:
           *  Gain: '<S145>/Gain2'
           *  Product: '<S145>/Multiply4'
           *  Sum: '<S145>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S145>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_bi;

          /* Sum: '<S145>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_bi;

          /* Product: '<S145>/Divide' */
          rtb_a_g = d / FMS_ConstB.d_bi;

          /* Signum: '<S145>/Sign5' incorporates:
           *  Signum: '<S145>/Sign6'
           */
          if (d < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;

            /* Signum: '<S145>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_P_f_idx_0 = 1.0F;

            /* Signum: '<S145>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_P_f_idx_0 = d;

            /* Signum: '<S145>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S145>/Sign5' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S124>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S124>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S124>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S144>/Integrator1'
           *  DiscreteIntegrator: '<S147>/Integrator1'
           *  DiscreteIntegrator: '<S149>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;
          FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_mg;

          /* Saturate: '<S132>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S124>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S124>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S124>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S132>/Saturation1' */

          /* Product: '<S150>/Multiply1' incorporates:
           *  Constant: '<S150>/const1'
           *  DiscreteIntegrator: '<S149>/Integrator'
           */
          d = FMS_DW.Integrator_DSTATE_l * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S131>/Saturation' incorporates:
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

          /* End of Saturate: '<S131>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S150>/Add' incorporates:
           *  DiscreteIntegrator: '<S149>/Integrator1'
           *  Gain: '<S131>/Gain'
           *  Sum: '<S149>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_mg - FMS_PARAM.FW_SPEED_MAX *
                     rtb_u_b) + d;

          /* Signum: '<S150>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Subtract1_ky_0 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Subtract1_ky_0 = 1.0F;
          } else {
            rtb_Subtract1_ky_0 = rtb_u_b;
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
          rtb_Subtract3_f = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_d) *
            FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F * rtb_Subtract1_ky_0 + d;

          /* Sum: '<S150>/Add4' */
          rtb_Add4_j4 = (rtb_u_b - rtb_Subtract3_f) + d;

          /* Sum: '<S150>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_d;

          /* Sum: '<S150>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_d;

          /* Signum: '<S150>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign1' */

          /* Signum: '<S150>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign2' */

          /* Sum: '<S150>/Add5' incorporates:
           *  Gain: '<S150>/Gain2'
           *  Product: '<S150>/Multiply4'
           *  Sum: '<S150>/Subtract2'
           */
          rtb_Subtract3_f += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Add4_j4;

          /* Sum: '<S150>/Add6' */
          rtb_Saturation1_p5 = rtb_Subtract3_f + FMS_ConstB.d_d;

          /* Sum: '<S150>/Subtract3' */
          rtb_Add4_j4 = rtb_Subtract3_f - FMS_ConstB.d_d;

          /* Product: '<S150>/Divide' */
          rtb_Sign5_mn = rtb_Subtract3_f / FMS_ConstB.d_d;

          /* Signum: '<S150>/Sign5' incorporates:
           *  Signum: '<S150>/Sign6'
           */
          if (rtb_Subtract3_f < 0.0F) {
            rtb_Sign5_dc = -1.0F;

            /* Signum: '<S150>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Subtract3_f > 0.0F) {
            rtb_Sign5_dc = 1.0F;

            /* Signum: '<S150>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Sign5_dc = rtb_Subtract3_f;

            /* Signum: '<S150>/Sign6' */
            rtb_Sign5_l = rtb_Subtract3_f;
          }

          /* End of Signum: '<S150>/Sign5' */

          /* Product: '<S148>/Multiply1' incorporates:
           *  Constant: '<S148>/const1'
           *  DiscreteIntegrator: '<S147>/Integrator'
           */
          rtb_Subtract3_f = FMS_DW.Integrator_DSTATE_e * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S146>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S146>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S148>/Add' incorporates:
           *  DiscreteIntegrator: '<S147>/Integrator1'
           *  Gain: '<S130>/Gain1'
           *  Gain: '<S146>/Gain'
           *  Sum: '<S147>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Subtract3_f;

          /* Signum: '<S148>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Subtract1_ky_0 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Subtract1_ky_0 = 1.0F;
          } else {
            rtb_Subtract1_ky_0 = rtb_u_b;
          }

          /* End of Signum: '<S148>/Sign' */

          /* Sum: '<S148>/Add2' incorporates:
           *  Abs: '<S148>/Abs'
           *  Gain: '<S148>/Gain'
           *  Gain: '<S148>/Gain1'
           *  Product: '<S148>/Multiply2'
           *  Product: '<S148>/Multiply3'
           *  Sqrt: '<S148>/Sqrt'
           *  Sum: '<S148>/Add1'
           *  Sum: '<S148>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_nt) * FMS_ConstB.d_nt)
               - FMS_ConstB.d_nt) * 0.5F * rtb_Subtract1_ky_0 + rtb_Subtract3_f;

          /* Sum: '<S148>/Add4' */
          rtb_Subtract3_f += rtb_u_b - d;

          /* Sum: '<S148>/Add3' */
          rtb_Subtract1_ky_0 = rtb_u_b + FMS_ConstB.d_nt;

          /* Sum: '<S148>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_nt;

          /* Signum: '<S148>/Sign1' */
          if (rtb_Subtract1_ky_0 < 0.0F) {
            rtb_Subtract1_ky_0 = -1.0F;
          } else {
            if (rtb_Subtract1_ky_0 > 0.0F) {
              rtb_Subtract1_ky_0 = 1.0F;
            }
          }

          /* End of Signum: '<S148>/Sign1' */

          /* Signum: '<S148>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S148>/Sign2' */

          /* Sum: '<S148>/Add5' incorporates:
           *  Gain: '<S148>/Gain2'
           *  Product: '<S148>/Multiply4'
           *  Sum: '<S148>/Subtract2'
           */
          d += (rtb_Subtract1_ky_0 - rtb_u_b) * 0.5F * rtb_Subtract3_f;

          /* Update for DiscreteIntegrator: '<S144>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S144>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Signum: '<S145>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S145>/Sign3' */

          /* Signum: '<S145>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S145>/Sign4' */

          /* Update for DiscreteIntegrator: '<S144>/Integrator' incorporates:
           *  Constant: '<S145>/const'
           *  Gain: '<S145>/Gain3'
           *  Product: '<S145>/Multiply5'
           *  Product: '<S145>/Multiply6'
           *  Sum: '<S145>/Subtract4'
           *  Sum: '<S145>/Subtract5'
           *  Sum: '<S145>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_a_g - rtb_P_f_idx_0) *
            FMS_ConstB.Gain4_d1 * ((rtb_Saturation_ga - rtb_Saturation1_d) *
            0.5F) - rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S147>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S147>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Update for DiscreteIntegrator: '<S149>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S149>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mg += 0.004F * FMS_DW.Integrator_DSTATE_l;

          /* Signum: '<S150>/Sign3' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign3' */

          /* Signum: '<S150>/Sign4' */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else {
            if (rtb_Add4_j4 > 0.0F) {
              rtb_Add4_j4 = 1.0F;
            }
          }

          /* End of Signum: '<S150>/Sign4' */

          /* Update for DiscreteIntegrator: '<S149>/Integrator' incorporates:
           *  Constant: '<S150>/const'
           *  Gain: '<S150>/Gain3'
           *  Product: '<S150>/Multiply5'
           *  Product: '<S150>/Multiply6'
           *  Sum: '<S150>/Subtract4'
           *  Sum: '<S150>/Subtract5'
           *  Sum: '<S150>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_l += ((rtb_Sign5_mn - rtb_Sign5_dc) *
            FMS_ConstB.Gain4_p2 * ((rtb_Saturation1_p5 - rtb_Add4_j4) * 0.5F) -
            rtb_Sign5_l * 78.448F) * 0.004F;

          /* Sum: '<S148>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_nt;

          /* Sum: '<S148>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_nt;

          /* Signum: '<S148>/Sign5' incorporates:
           *  Signum: '<S148>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S148>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S148>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S148>/Sign6' */
            rtb_Sign5_l = d;
          }

          /* End of Signum: '<S148>/Sign5' */

          /* Signum: '<S148>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S148>/Sign3' */

          /* Signum: '<S148>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S148>/Sign4' */

          /* Update for DiscreteIntegrator: '<S147>/Integrator' incorporates:
           *  Constant: '<S148>/const'
           *  Gain: '<S148>/Gain3'
           *  Product: '<S148>/Divide'
           *  Product: '<S148>/Multiply5'
           *  Product: '<S148>/Multiply6'
           *  Sum: '<S148>/Subtract4'
           *  Sum: '<S148>/Subtract5'
           *  Sum: '<S148>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((d / FMS_ConstB.d_nt -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_kf * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S119>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S119>/Position' incorporates:
             *  ActionPort: '<S125>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S119>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S167>/Integrator'
             *  DiscreteIntegrator: '<S167>/Integrator1'
             *  DiscreteIntegrator: '<S217>/Integrator'
             *  DiscreteIntegrator: '<S217>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator1_DSTATE_nd = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S119>/Position' */

            /* SystemReset for IfAction SubSystem: '<S119>/Position' incorporates:
             *  ActionPort: '<S125>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S119>/Switch Case' incorporates:
             *  Chart: '<S156>/Motion Status'
             *  Chart: '<S170>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState);

            /* End of SystemReset for SubSystem: '<S119>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S119>/Position' incorporates:
           *  ActionPort: '<S125>/Action Port'
           */
          /* Trigonometry: '<S215>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S215>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S215>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S215>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S215>/Gain' incorporates:
           *  Gain: '<S214>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S215>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S215>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S215>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S215>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S215>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S156>/Motion Status' incorporates:
           *  Abs: '<S156>/Abs'
           *  Abs: '<S156>/Abs1'
           *  Constant: '<S164>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S164>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S170>/Multiply' incorporates:
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

          /* End of Product: '<S170>/Multiply' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S170>/Motion State' incorporates:
           *  Abs: '<S170>/Abs'
           *  Abs: '<S170>/Abs1'
           *  Abs: '<S170>/Abs2'
           *  Constant: '<S211>/Constant'
           *  Constant: '<S212>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Logic: '<S170>/Logical Operator'
           *  RelationalOperator: '<S211>/Compare'
           *  RelationalOperator: '<S212>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ)
                          || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
                              FMS_PARAM.YAW_DZ), fabsf
                          (rtb_MatrixConcatenate1_a_0[0]), &rtb_state_fg,
                          &FMS_DW.sf_MotionState);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S169>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
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
              /* SystemReset for IfAction SubSystem: '<S169>/Hold Control' incorporates:
               *  ActionPort: '<S172>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S169>/Switch Case' */
              FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_b,
                &FMS_DW.HoldControl_b);

              /* End of SystemReset for SubSystem: '<S169>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S169>/Hold Control' incorporates:
             *  ActionPort: '<S172>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_b(rtb_Divide_bu, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                              FMS_U.INS_Out.vd, FMS_U.INS_Out.psi,
                              FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              &FMS_B.Merge_be, &FMS_ConstB.HoldControl_b,
                              &FMS_DW.HoldControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S169>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S169>/Brake Control' incorporates:
             *  ActionPort: '<S171>/Action Port'
             */
            FMS_BrakeControl_h(&FMS_B.Merge_be);

            /* End of Outputs for SubSystem: '<S169>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S169>/Move Control' incorporates:
               *  ActionPort: '<S173>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S169>/Switch Case' */
              FMS_MoveControl_a_Reset(&FMS_DW.MoveControl_j);

              /* End of SystemReset for SubSystem: '<S169>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S169>/Move Control' incorporates:
             *  ActionPort: '<S173>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_roll, &FMS_B.Merge_be,
                              &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S169>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S169>/Switch Case' */

          /* SwitchCase: '<S155>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S155>/Hold Control' incorporates:
               *  ActionPort: '<S158>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S155>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S155>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S155>/Hold Control' incorporates:
             *  ActionPort: '<S158>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S155>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S155>/Brake Control' incorporates:
             *  ActionPort: '<S157>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_fb);

            /* End of Outputs for SubSystem: '<S155>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S155>/Move Control' incorporates:
               *  ActionPort: '<S159>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S155>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S155>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S155>/Move Control' incorporates:
             *  ActionPort: '<S159>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S155>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S155>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S125>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S125>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S125>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S167>/Integrator1'
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l;
          FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_nd;

          /* Saturate: '<S169>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S125>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S125>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S125>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S169>/Saturation1' */

          /* Saturate: '<S155>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S125>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S125>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S125>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S155>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S154>/Saturation' incorporates:
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

          /* End of Saturate: '<S154>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S218>/Multiply1' incorporates:
           *  Constant: '<S218>/const1'
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          rtb_u_b = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Switch: '<S216>/Switch' incorporates:
           *  Constant: '<S216>/Constant'
           *  Constant: '<S216>/Constant1'
           *  Constant: '<S216>/Constant2'
           *  Product: '<S216>/Multiply'
           *  Product: '<S216>/Multiply1'
           *  Sum: '<S216>/Subtract'
           *  Sum: '<S216>/Subtract1'
           *  Sum: '<S216>/Sum'
           *  Sum: '<S216>/Sum1'
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

          /* End of Switch: '<S216>/Switch' */

          /* Sum: '<S218>/Add' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  Sum: '<S217>/Subtract'
           */
          rtb_Add4_j4 = (FMS_DW.Integrator1_DSTATE_nd - rtb_Saturation_ga) +
            rtb_u_b;

          /* Signum: '<S218>/Sign' */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Add4_j4 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Add4_j4;
          }

          /* End of Signum: '<S218>/Sign' */

          /* Sum: '<S218>/Add2' incorporates:
           *  Abs: '<S218>/Abs'
           *  Gain: '<S218>/Gain'
           *  Gain: '<S218>/Gain1'
           *  Product: '<S218>/Multiply2'
           *  Product: '<S218>/Multiply3'
           *  Sqrt: '<S218>/Sqrt'
           *  Sum: '<S218>/Add1'
           *  Sum: '<S218>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_Add4_j4) +
            FMS_ConstB.d_ad) * FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F *
            rtb_Saturation_ga + rtb_u_b;

          /* Sum: '<S218>/Add4' */
          rtb_Saturation1_d = (rtb_Add4_j4 - rtb_Saturation1_p5) + rtb_u_b;

          /* Sum: '<S218>/Add3' */
          rtb_Saturation_ga = rtb_Add4_j4 + FMS_ConstB.d_ad;

          /* Sum: '<S218>/Subtract1' */
          rtb_Add4_j4 -= FMS_ConstB.d_ad;

          /* Signum: '<S218>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign1' */

          /* Signum: '<S218>/Sign2' */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else {
            if (rtb_Add4_j4 > 0.0F) {
              rtb_Add4_j4 = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign2' */

          /* Sum: '<S218>/Add5' incorporates:
           *  Gain: '<S218>/Gain2'
           *  Product: '<S218>/Multiply4'
           *  Sum: '<S218>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_Add4_j4) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S218>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_ad;

          /* Sum: '<S218>/Subtract3' */
          rtb_Saturation1_d = rtb_Saturation1_p5 - FMS_ConstB.d_ad;

          /* Product: '<S218>/Divide' */
          d = rtb_Saturation1_p5 / FMS_ConstB.d_ad;

          /* Signum: '<S218>/Sign5' incorporates:
           *  Signum: '<S218>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S218>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S218>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Saturation1_p5;

            /* Signum: '<S218>/Sign6' */
            rtb_Saturation_o4 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S218>/Sign5' */

          /* Product: '<S168>/Multiply1' incorporates:
           *  Constant: '<S168>/const1'
           *  DiscreteIntegrator: '<S167>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S166>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S166>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S168>/Add' incorporates:
           *  DiscreteIntegrator: '<S167>/Integrator1'
           *  Gain: '<S152>/Gain1'
           *  Gain: '<S166>/Gain'
           *  Sum: '<S167>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S168>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S168>/Sign' */

          /* Sum: '<S168>/Add2' incorporates:
           *  Abs: '<S168>/Abs'
           *  Gain: '<S168>/Gain'
           *  Gain: '<S168>/Gain1'
           *  Product: '<S168>/Multiply2'
           *  Product: '<S168>/Multiply3'
           *  Sqrt: '<S168>/Sqrt'
           *  Sum: '<S168>/Add1'
           *  Sum: '<S168>/Subtract'
           */
          rtb_Add4_j4 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_l) *
                               FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Add4_j4 + rtb_Saturation1_p5;

          /* Sum: '<S168>/Add4' */
          rtb_a_g = (rtb_u_b - rtb_Add4_j4) + rtb_Saturation1_p5;

          /* Sum: '<S168>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_l;

          /* Sum: '<S168>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_l;

          /* Signum: '<S168>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S168>/Sign1' */

          /* Signum: '<S168>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S168>/Sign2' */

          /* Sum: '<S168>/Add5' incorporates:
           *  Gain: '<S168>/Gain2'
           *  Product: '<S168>/Multiply4'
           *  Sum: '<S168>/Subtract2'
           */
          rtb_Add4_j4 += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_a_g;

          /* Update for DiscreteIntegrator: '<S167>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S167>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S217>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S218>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign3' */

          /* Signum: '<S218>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign4' */

          /* Update for DiscreteIntegrator: '<S217>/Integrator' incorporates:
           *  Constant: '<S218>/const'
           *  Gain: '<S218>/Gain3'
           *  Product: '<S218>/Multiply5'
           *  Product: '<S218>/Multiply6'
           *  Sum: '<S218>/Subtract4'
           *  Sum: '<S218>/Subtract5'
           *  Sum: '<S218>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_f *
            ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4
            * 78.448F) * 0.004F;

          /* Sum: '<S168>/Subtract3' */
          rtb_Saturation_ga = rtb_Add4_j4 - FMS_ConstB.d_l;

          /* Sum: '<S168>/Add6' */
          rtb_Saturation1_d = rtb_Add4_j4 + FMS_ConstB.d_l;

          /* Signum: '<S168>/Sign5' incorporates:
           *  Signum: '<S168>/Sign6'
           */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S168>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Add4_j4 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S168>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Add4_j4;

            /* Signum: '<S168>/Sign6' */
            rtb_Sign5_l = rtb_Add4_j4;
          }

          /* End of Signum: '<S168>/Sign5' */

          /* Signum: '<S168>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S168>/Sign3' */

          /* Signum: '<S168>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S168>/Sign4' */

          /* Update for DiscreteIntegrator: '<S167>/Integrator' incorporates:
           *  Constant: '<S168>/const'
           *  Gain: '<S168>/Gain3'
           *  Product: '<S168>/Divide'
           *  Product: '<S168>/Multiply5'
           *  Product: '<S168>/Multiply6'
           *  Sum: '<S168>/Subtract4'
           *  Sum: '<S168>/Subtract5'
           *  Sum: '<S168>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_Add4_j4 / FMS_ConstB.d_l -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ak * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S119>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S119>/Unknown' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S119>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S49>/Manual' incorporates:
         *  ActionPort: '<S121>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S121>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S121>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S121>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S121>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S259>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S259>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S121>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S259>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S260>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S260>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S121>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S121>/Gain'
         *  Gain: '<S260>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S261>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S261>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S121>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S261>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S262>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S262>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S121>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S262>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_u_b;

        /* End of Outputs for SubSystem: '<S49>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S49>/Unknown' incorporates:
         *  ActionPort: '<S123>/Action Port'
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
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S43>/Signal Copy1'
       *  SignalConversion: '<S43>/Signal Copy2'
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
        if (FMS_DW.SwitchCase_ActiveSubsystem_ff != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S54>/Move Control' incorporates:
           *  ActionPort: '<S58>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S54>/Switch Case' */
          FMS_MoveControl_a_Reset(&FMS_DW.MoveControl_c);

          /* End of SystemReset for SubSystem: '<S54>/Move Control' */
        }

        /* Outputs for IfAction SubSystem: '<S54>/Move Control' incorporates:
         *  ActionPort: '<S58>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_roll, &FMS_B.Merge_n,
                          &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
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
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_g;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_i;
      FMS_Y.FMS_Out.u_cmd = 0.0F;

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

      /* BusAssignment: '<S48>/Bus Assignment' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  Gain: '<S117>/Gain'
       *  Gain: '<S53>/Gain6'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.v_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
        FMS_PARAM.VEL_XY_LIM;

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

      /* BusAssignment: '<S48>/Bus Assignment' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  Gain: '<S116>/Gain'
       *  Gain: '<S53>/Gain1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.w_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_u_b *
        -FMS_PARAM.VEL_Z_LIM;

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

      /* BusAssignment: '<S48>/Bus Assignment' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  Gain: '<S118>/Gain'
       *  Gain: '<S53>/Gain2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_u_b *
        FMS_PARAM.YAW_RATE_LIM;

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
          /* Disable for SwitchCase: '<S333>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S733>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S723>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S672>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S640>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S651>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S331>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S442>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S493>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S483>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S442>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S330>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S429>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S345>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S363>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S379>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S404>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S391>/Switch Case' */
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
         *  ActionPort: '<S333>/Action Port'
         */
        /* SwitchCase: '<S333>/Switch Case' incorporates:
         *  Math: '<S755>/Math Function'
         *  Sum: '<S717>/Subtract'
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
            /* Disable for SwitchCase: '<S733>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S723>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S672>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S640>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S651>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S333>/Takeoff' incorporates:
             *  ActionPort: '<S635>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S333>/Switch Case' incorporates:
             *  Delay: '<S773>/cur_waypoint'
             *  DiscreteIntegrator: '<S769>/Integrator'
             *  DiscreteIntegrator: '<S769>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S333>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S333>/Takeoff' incorporates:
           *  ActionPort: '<S635>/Action Port'
           */
          /* Delay: '<S773>/cur_waypoint' incorporates:
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
          /* Product: '<S773>/Divide' incorporates:
           *  Delay: '<S773>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S773>/Sum1'
           *  Sum: '<S773>/Sum2'
           */
          rtb_Saturation_o4 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S773>/Saturation' */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_o4 = 0.0F;
            }
          }

          /* End of Saturate: '<S773>/Saturation' */

          /* Trigonometry: '<S774>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S774>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S774>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S774>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S774>/Gain' incorporates:
           *  Gain: '<S772>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S774>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S774>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S774>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S774>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S774>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S766>/Saturation1' */
          rtb_Saturation_ga = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Saturation1_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S766>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S773>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S773>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S766>/Sum'
           *  Sum: '<S773>/Sum3'
           *  Sum: '<S773>/Sum4'
           */
          rtb_Add4_j4 = ((FMS_B.Cmd_In.sp_waypoint[0] -
                          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Saturation_o4 +
                         FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
          d = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE[1]) *
               rtb_Saturation_o4 + FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S766>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 3]
              * d + rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4;
          }

          /* Saturate: '<S766>/Saturation1' incorporates:
           *  Gain: '<S766>/Gain2'
           *  Product: '<S766>/Multiply'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S635>/Bus Assignment1'
           *  Constant: '<S635>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S635>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S766>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_ga) {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_ga;
          } else if (rtb_u_b < rtb_Saturation1_d) {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Saturation1_p5 > rtb_Saturation_ga) {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_ga;
          } else if (rtb_Saturation1_p5 < rtb_Saturation1_d) {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_p5;
          }

          /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S769>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S770>/Multiply1' incorporates:
           *  Constant: '<S770>/const1'
           *  DiscreteIntegrator: '<S769>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S765>/Switch' incorporates:
           *  Abs: '<S765>/Abs'
           *  Abs: '<S765>/Abs1'
           *  Constant: '<S765>/Takeoff_Speed'
           *  Constant: '<S767>/Constant'
           *  Constant: '<S768>/Constant'
           *  Gain: '<S765>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S765>/Logical Operator'
           *  RelationalOperator: '<S767>/Compare'
           *  RelationalOperator: '<S768>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S765>/Sum'
           *  Sum: '<S765>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_u_b = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_u_b = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S765>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S770>/Add' incorporates:
           *  DiscreteIntegrator: '<S769>/Integrator1'
           *  Sum: '<S769>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_f - rtb_u_b) +
            rtb_Saturation_o4;

          /* Signum: '<S770>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S770>/Sign' */

          /* Sum: '<S770>/Add2' incorporates:
           *  Abs: '<S770>/Abs'
           *  Gain: '<S770>/Gain'
           *  Gain: '<S770>/Gain1'
           *  Product: '<S770>/Multiply2'
           *  Product: '<S770>/Multiply3'
           *  Sqrt: '<S770>/Sqrt'
           *  Sum: '<S770>/Add1'
           *  Sum: '<S770>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S770>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_Saturation1_p5;

          /* Sum: '<S770>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Sum: '<S770>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_b;

          /* Signum: '<S770>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S770>/Sign1' */

          /* Signum: '<S770>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S770>/Sign2' */

          /* Sum: '<S770>/Add5' incorporates:
           *  Gain: '<S770>/Gain2'
           *  Product: '<S770>/Multiply4'
           *  Sum: '<S770>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S773>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S769>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S769>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S770>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_p5 - FMS_ConstB.d_b;

          /* Sum: '<S770>/Add6' */
          rtb_Saturation1_d = rtb_Saturation1_p5 + FMS_ConstB.d_b;

          /* Signum: '<S770>/Sign5' incorporates:
           *  Signum: '<S770>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S770>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S770>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_p5;

            /* Signum: '<S770>/Sign6' */
            rtb_Sign5_l = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S770>/Sign5' */

          /* Signum: '<S770>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S770>/Sign3' */

          /* Signum: '<S770>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S770>/Sign4' */

          /* Update for DiscreteIntegrator: '<S769>/Integrator' incorporates:
           *  Constant: '<S770>/const'
           *  Gain: '<S770>/Gain3'
           *  Product: '<S770>/Divide'
           *  Product: '<S770>/Multiply5'
           *  Product: '<S770>/Multiply6'
           *  Sum: '<S770>/Subtract4'
           *  Sum: '<S770>/Subtract5'
           *  Sum: '<S770>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation1_p5 / FMS_ConstB.d_b -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_i * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S333>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S333>/Land' incorporates:
             *  ActionPort: '<S633>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S333>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S688>/Integrator'
             *  DiscreteIntegrator: '<S688>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S333>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S333>/Land' incorporates:
           *  ActionPort: '<S633>/Action Port'
           */
          /* Trigonometry: '<S693>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S693>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S693>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S693>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S693>/Gain' incorporates:
           *  Gain: '<S692>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S693>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S693>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S693>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S693>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S693>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S686>/Saturation1' */
          rtb_Saturation_o4 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Sign5_l = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S690>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S690>/Sum'
           */
          rtb_Add4_j4 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S690>/Multiply' incorporates:
           *  SignalConversion: '<S690>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S690>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 3]
              * d + rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4;
          }

          /* End of Product: '<S690>/Multiply' */

          /* Saturate: '<S686>/Saturation1' incorporates:
           *  Gain: '<S690>/Gain2'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S633>/Bus Assignment1'
           *  Constant: '<S633>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S633>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S686>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_o4) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_o4;
          } else if (rtb_u_b < rtb_Sign5_l) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Sign5_l;
          } else {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Saturation1_p5 > rtb_Saturation_o4) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_o4;
          } else if (rtb_Saturation1_p5 < rtb_Sign5_l) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Sign5_l;
          } else {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_p5;
          }

          /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S688>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S689>/Multiply1' incorporates:
           *  Constant: '<S689>/const1'
           *  DiscreteIntegrator: '<S688>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S685>/Switch' incorporates:
           *  Constant: '<S685>/Land_Speed'
           *  Constant: '<S687>/Constant'
           *  Gain: '<S685>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S685>/Logical Operator'
           *  RelationalOperator: '<S687>/Compare'
           *  S-Function (sfix_bitop): '<S685>/cmd_p valid'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_u_b = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_u_b = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S685>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S689>/Add' incorporates:
           *  DiscreteIntegrator: '<S688>/Integrator1'
           *  Sum: '<S688>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_g - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S689>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S689>/Sign' */

          /* Sum: '<S689>/Add2' incorporates:
           *  Abs: '<S689>/Abs'
           *  Gain: '<S689>/Gain'
           *  Gain: '<S689>/Gain1'
           *  Product: '<S689>/Multiply2'
           *  Product: '<S689>/Multiply3'
           *  Sqrt: '<S689>/Sqrt'
           *  Sum: '<S689>/Add1'
           *  Sum: '<S689>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S689>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Saturation1_p5) +
            rtb_Saturation_ga;

          /* Sum: '<S689>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Sum: '<S689>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_om;

          /* Signum: '<S689>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S689>/Sign1' */

          /* Signum: '<S689>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S689>/Sign2' */

          /* Sum: '<S689>/Add5' incorporates:
           *  Gain: '<S689>/Gain2'
           *  Product: '<S689>/Multiply4'
           *  Sum: '<S689>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for DiscreteIntegrator: '<S688>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S688>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S689>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_p5 - FMS_ConstB.d_om;

          /* Sum: '<S689>/Add6' */
          rtb_Saturation1_d = rtb_Saturation1_p5 + FMS_ConstB.d_om;

          /* Signum: '<S689>/Sign5' incorporates:
           *  Signum: '<S689>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S689>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S689>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_p5;

            /* Signum: '<S689>/Sign6' */
            rtb_Sign5_l = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S689>/Sign5' */

          /* Signum: '<S689>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S689>/Sign3' */

          /* Signum: '<S689>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S689>/Sign4' */

          /* Update for DiscreteIntegrator: '<S688>/Integrator' incorporates:
           *  Constant: '<S689>/const'
           *  Gain: '<S689>/Gain3'
           *  Product: '<S689>/Divide'
           *  Product: '<S689>/Multiply5'
           *  Product: '<S689>/Multiply6'
           *  Sum: '<S689>/Subtract4'
           *  Sum: '<S689>/Subtract5'
           *  Sum: '<S689>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Saturation1_p5 / FMS_ConstB.d_om
            - rtb_Saturation_o4) * FMS_ConstB.Gain4_p * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S333>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S333>/Return' incorporates:
             *  ActionPort: '<S634>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S333>/Switch Case' incorporates:
             *  Delay: '<S697>/Delay'
             *  Delay: '<S718>/Delay'
             *  DiscreteIntegrator: '<S700>/Integrator'
             *  DiscreteIntegrator: '<S700>/Integrator1'
             *  DiscreteIntegrator: '<S714>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S719>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S760>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S333>/Return' */

            /* SystemReset for IfAction SubSystem: '<S333>/Return' incorporates:
             *  ActionPort: '<S634>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S333>/Switch Case' incorporates:
             *  Chart: '<S724>/Motion Status'
             *  Chart: '<S734>/Motion State'
             */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S333>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S333>/Return' incorporates:
           *  ActionPort: '<S634>/Action Port'
           */
          /* Delay: '<S718>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S713>/Compare' incorporates:
           *  Constant: '<S764>/Constant'
           *  DiscreteIntegrator: '<S719>/Discrete-Time Integrator'
           *  RelationalOperator: '<S764>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S714>/Acceleration_Speed' */
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
          /* Chart: '<S734>/Motion State' incorporates:
           *  Constant: '<S734>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S734>/Square'
           *  Math: '<S734>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S734>/Sqrt'
           *  Sum: '<S734>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S733>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S733>/Hold Control' incorporates:
               *  ActionPort: '<S736>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S733>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S733>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S733>/Hold Control' incorporates:
             *  ActionPort: '<S736>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S733>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S733>/Brake Control' incorporates:
             *  ActionPort: '<S735>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S733>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S733>/Move Control' incorporates:
               *  ActionPort: '<S737>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S733>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S733>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S733>/Move Control' incorporates:
             *  ActionPort: '<S737>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S733>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S733>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S724>/Motion Status' incorporates:
           *  Abs: '<S724>/Abs'
           *  Constant: '<S724>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S723>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S723>/Hold Control' incorporates:
               *  ActionPort: '<S726>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S723>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S723>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S723>/Hold Control' incorporates:
             *  ActionPort: '<S726>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S723>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S723>/Brake Control' incorporates:
             *  ActionPort: '<S725>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S723>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S723>/Move Control' incorporates:
               *  ActionPort: '<S727>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S723>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_cg);

              /* End of SystemReset for SubSystem: '<S723>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S723>/Move Control' incorporates:
             *  ActionPort: '<S727>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_cg, &FMS_DW.MoveControl_cg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S723>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S723>/Switch Case' */

          /* Switch: '<S695>/Switch' incorporates:
           *  Product: '<S718>/Multiply'
           *  Sum: '<S718>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S733>/Saturation1' */
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

            /* End of Saturate: '<S733>/Saturation1' */

            /* Saturate: '<S723>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S723>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S718>/Sum' incorporates:
             *  Delay: '<S718>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_j4 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S761>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Add4_j4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S714>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_o4 = rtb_Add4_j4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S718>/Sum' incorporates:
             *  Delay: '<S718>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_j4 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S714>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S720>/Sqrt' incorporates:
             *  Math: '<S720>/Square'
             *  Sum: '<S714>/Sum'
             *  Sum: '<S720>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
                            rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S763>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S763>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S763>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S762>/Gain' incorporates:
             *  DiscreteIntegrator: '<S760>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S760>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S763>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S763>/Trigonometric Function1'
             */
            rtb_Saturation_ga = arm_cos_f32(rtb_Saturation1_d);
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Trigonometry: '<S763>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S763>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation1_d);

            /* Gain: '<S763>/Gain' incorporates:
             *  Trigonometry: '<S763>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S763>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S763>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S763>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S763>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* Switch: '<S714>/Switch' incorporates:
             *  Constant: '<S714>/vel'
             */
            if (rtb_u_b > FMS_PARAM.L1) {
              rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S714>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_u_b;

              /* Saturate: '<S714>/Saturation' */
              if (rtb_Saturation1_d > FMS_PARAM.CRUISE_SPEED) {
                rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Saturate: '<S714>/Saturation' */
            }

            /* End of Switch: '<S714>/Switch' */

            /* Switch: '<S714>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S714>/Acceleration_Speed'
             *  Sum: '<S714>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S714>/Switch1' */

            /* Sum: '<S761>/Sum of Elements' incorporates:
             *  Math: '<S761>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Add4_j4 *
              rtb_Add4_j4;

            /* Math: '<S761>/Math Function1' incorporates:
             *  Sum: '<S761>/Sum of Elements'
             *
             * About '<S761>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_Saturation_ga = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S761>/Math Function1' */

            /* Switch: '<S761>/Switch' incorporates:
             *  Constant: '<S761>/Constant'
             *  Product: '<S761>/Product'
             */
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Divide_bu[0] = rtb_Saturation_o4;
              rtb_Divide_bu[1] = rtb_Add4_j4;
              rtb_Divide_bu[3] = rtb_Saturation_ga;
            } else {
              rtb_Divide_bu[0] = 0.0F;
              rtb_Divide_bu[1] = 0.0F;
              rtb_Divide_bu[3] = 1.0F;
            }

            /* End of Switch: '<S761>/Switch' */

            /* Product: '<S759>/Multiply2' incorporates:
             *  Product: '<S761>/Divide'
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

          /* End of Switch: '<S695>/Switch' */

          /* Delay: '<S697>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S700>/Integrator1' incorporates:
           *  Delay: '<S697>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S704>/Rem' incorporates:
           *  Constant: '<S704>/Constant1'
           *  DiscreteIntegrator: '<S700>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S699>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S704>/Switch' incorporates:
           *  Abs: '<S704>/Abs'
           *  Constant: '<S704>/Constant'
           *  Constant: '<S705>/Constant'
           *  Product: '<S704>/Multiply'
           *  RelationalOperator: '<S705>/Compare'
           *  Sum: '<S704>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S704>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S704>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S704>/Switch' */

          /* Gain: '<S699>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S699>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S699>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S634>/Bus Assignment1'
           *  Constant: '<S634>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S634>/Bus Assignment1' incorporates:
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

          /* Math: '<S754>/Math Function1'
           *
           * About '<S754>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(d));
          } else {
            rtb_Saturation_o4 = sqrtf(d);
          }

          /* End of Math: '<S754>/Math Function1' */

          /* Switch: '<S754>/Switch' incorporates:
           *  Constant: '<S754>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S754>/Product'
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

          /* End of Switch: '<S754>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S634>/Sum' incorporates:
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

          /* SignalConversion: '<S711>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S634>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S711>/Math Function' incorporates:
           *  Sum: '<S634>/Sum'
           */
          rtb_Square_dv[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_dv[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S711>/Sum of Elements' */
          rtb_u_b = rtb_Square_dv[0] + rtb_Square_dv[1];

          /* Math: '<S711>/Math Function1' incorporates:
           *  Sum: '<S711>/Sum of Elements'
           *
           * About '<S711>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S711>/Math Function1' */

          /* Switch: '<S711>/Switch' incorporates:
           *  Constant: '<S711>/Constant'
           *  Product: '<S711>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            d = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            d = 1.0F;
          }

          /* End of Switch: '<S711>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S716>/NearbyRefWP' incorporates:
           *  Constant: '<S634>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f0,
                          &rtb_u_b);

          /* MATLAB Function: '<S716>/SearchL1RefWP' incorporates:
           *  Constant: '<S634>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S716>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0],
                               &rtb_TmpSignalConversionAtMultip[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_dv);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S716>/Switch1' incorporates:
           *  Constant: '<S747>/Constant'
           *  RelationalOperator: '<S747>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_f0[0];
            rtb_P_ap[1] = rtb_Divide_f0[1];
          } else {
            /* RelationalOperator: '<S746>/Compare' incorporates:
             *  Constant: '<S746>/Constant'
             */
            rtb_Compare_at = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S716>/Switch' */
            if (!rtb_Compare_at) {
              rtb_P_ap[0] = rtb_Square_dv[0];
              rtb_P_ap[1] = rtb_Square_dv[1];
            }

            /* End of Switch: '<S716>/Switch' */
          }

          /* End of Switch: '<S716>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S717>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Sign5_l;
          rtb_Subtract_hb[0] = rtb_Sign5_l * rtb_Sign5_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S717>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S755>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S755>/Sum of Elements' incorporates:
           *  Math: '<S755>/Math Function'
           *  Sum: '<S753>/Sum of Elements'
           */
          rtb_u_b = rtb_Subtract_hb[0] + rtb_Sign5_l * rtb_Sign5_l;

          /* Math: '<S755>/Math Function1' incorporates:
           *  Sum: '<S755>/Sum of Elements'
           *
           * About '<S755>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S755>/Math Function1' */

          /* Switch: '<S755>/Switch' incorporates:
           *  Constant: '<S755>/Constant'
           *  Product: '<S755>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_P_ap[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Sign5_l;
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S755>/Switch' */

          /* Product: '<S754>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S757>/Sum of Elements' incorporates:
           *  Math: '<S757>/Math Function'
           *  SignalConversion: '<S757>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_g = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S757>/Math Function1' incorporates:
           *  Sum: '<S757>/Sum of Elements'
           *
           * About '<S757>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_g < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_g));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_g);
          }

          /* End of Math: '<S757>/Math Function1' */

          /* Switch: '<S757>/Switch' incorporates:
           *  Constant: '<S757>/Constant'
           *  Product: '<S757>/Product'
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

          /* End of Switch: '<S757>/Switch' */

          /* Product: '<S755>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S758>/Sum of Elements' incorporates:
           *  Math: '<S758>/Math Function'
           *  SignalConversion: '<S758>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_g = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S758>/Math Function1' incorporates:
           *  Sum: '<S758>/Sum of Elements'
           *
           * About '<S758>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_g < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_g));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_g);
          }

          /* End of Math: '<S758>/Math Function1' */

          /* Switch: '<S758>/Switch' incorporates:
           *  Constant: '<S758>/Constant'
           *  Product: '<S758>/Product'
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

          /* End of Switch: '<S758>/Switch' */

          /* Product: '<S758>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S757>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S711>/Divide' */
          rtb_Square_dv[0] = rtb_Saturation_ga / d;

          /* Product: '<S758>/Divide' */
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S757>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S711>/Divide' */
          rtb_Square_dv[1] = rtb_Saturation1_d / d;

          /* Sum: '<S756>/Subtract' incorporates:
           *  Product: '<S756>/Multiply'
           *  Product: '<S756>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_f0[0] * rtb_P_ap[1] - rtb_Divide_f0[1] *
            rtb_P_ap[0];

          /* Signum: '<S751>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S751>/Sign1' */

          /* Switch: '<S751>/Switch2' incorporates:
           *  Constant: '<S751>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S751>/Switch2' */

          /* DotProduct: '<S751>/Dot Product' */
          rtb_Sign5_l = rtb_P_ap[0] * rtb_Divide_f0[0] + rtb_P_ap[1] *
            rtb_Divide_f0[1];

          /* Trigonometry: '<S751>/Acos' incorporates:
           *  DotProduct: '<S751>/Dot Product'
           */
          if (rtb_Sign5_l > 1.0F) {
            rtb_Sign5_l = 1.0F;
          } else {
            if (rtb_Sign5_l < -1.0F) {
              rtb_Sign5_l = -1.0F;
            }
          }

          /* Product: '<S751>/Multiply' incorporates:
           *  Trigonometry: '<S751>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Sign5_l);

          /* Saturate: '<S717>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S717>/Saturation' */

          /* Product: '<S717>/Divide' incorporates:
           *  Constant: '<S634>/L1'
           *  Constant: '<S717>/Constant'
           *  Gain: '<S717>/Gain'
           *  Math: '<S717>/Square'
           *  MinMax: '<S717>/Max'
           *  MinMax: '<S717>/Min'
           *  Product: '<S717>/Multiply1'
           *  Sqrt: '<S753>/Sqrt'
           *  Trigonometry: '<S717>/Sin'
           */
          rtb_Saturation1_p5 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S709>/Subtract' incorporates:
           *  Product: '<S709>/Multiply'
           *  Product: '<S709>/Multiply1'
           */
          rtb_Add4_j4 = rtb_Square_dv[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_dv[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S698>/Sign1' */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else {
            if (rtb_Add4_j4 > 0.0F) {
              rtb_Add4_j4 = 1.0F;
            }
          }

          /* End of Signum: '<S698>/Sign1' */

          /* Switch: '<S698>/Switch2' incorporates:
           *  Constant: '<S698>/Constant4'
           */
          if (rtb_Add4_j4 == 0.0F) {
            rtb_Add4_j4 = 1.0F;
          }

          /* End of Switch: '<S698>/Switch2' */

          /* DotProduct: '<S698>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide_m[0] * rtb_Square_dv[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_dv[1];

          /* Trigonometry: '<S698>/Acos' incorporates:
           *  DotProduct: '<S698>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S698>/Multiply' incorporates:
           *  Trigonometry: '<S698>/Acos'
           */
          rtb_Add4_j4 *= acosf(rtb_u_b);

          /* Math: '<S701>/Rem' incorporates:
           *  Constant: '<S701>/Constant1'
           *  Delay: '<S697>/Delay'
           *  Sum: '<S697>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Add4_j4 - FMS_DW.Delay_DSTATE_nx,
            6.28318548F);

          /* Switch: '<S701>/Switch' incorporates:
           *  Abs: '<S701>/Abs'
           *  Constant: '<S701>/Constant'
           *  Constant: '<S707>/Constant'
           *  Product: '<S701>/Multiply'
           *  RelationalOperator: '<S707>/Compare'
           *  Sum: '<S701>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S701>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S701>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S701>/Switch' */

          /* Sum: '<S697>/Sum' incorporates:
           *  Delay: '<S697>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S706>/Multiply1' incorporates:
           *  Constant: '<S706>/const1'
           *  DiscreteIntegrator: '<S700>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S706>/Add' incorporates:
           *  DiscreteIntegrator: '<S700>/Integrator1'
           *  Sum: '<S700>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S706>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S706>/Sign' */

          /* Sum: '<S706>/Add2' incorporates:
           *  Abs: '<S706>/Abs'
           *  Gain: '<S706>/Gain'
           *  Gain: '<S706>/Gain1'
           *  Product: '<S706>/Multiply2'
           *  Product: '<S706>/Multiply3'
           *  Sqrt: '<S706>/Sqrt'
           *  Sum: '<S706>/Add1'
           *  Sum: '<S706>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_n) *
                           FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S706>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S706>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_n;

          /* Sum: '<S706>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_n;

          /* Signum: '<S706>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S706>/Sign1' */

          /* Signum: '<S706>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S706>/Sign2' */

          /* Sum: '<S706>/Add5' incorporates:
           *  Gain: '<S706>/Gain2'
           *  Product: '<S706>/Multiply4'
           *  Sum: '<S706>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S706>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_n;

          /* Sum: '<S706>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_n;

          /* Product: '<S706>/Divide' */
          d = rtb_u_b / FMS_ConstB.d_n;

          /* Signum: '<S706>/Sign5' incorporates:
           *  Signum: '<S706>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S706>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S706>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_u_b;

            /* Signum: '<S706>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S706>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S697>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Add4_j4 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S702>/Rem' incorporates:
           *  Constant: '<S702>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Add4_j4, 6.28318548F);

          /* Switch: '<S702>/Switch' incorporates:
           *  Abs: '<S702>/Abs'
           *  Constant: '<S702>/Constant'
           *  Constant: '<S708>/Constant'
           *  Product: '<S702>/Multiply'
           *  RelationalOperator: '<S708>/Compare'
           *  Sum: '<S702>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S702>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Add4_j4 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Add4_j4 = 1.0F;
            } else {
              rtb_Add4_j4 = rtb_u_b;
            }

            /* End of Signum: '<S702>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Add4_j4;
          }

          /* End of Switch: '<S702>/Switch' */

          /* Abs: '<S695>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S718>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S719>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S712>/Constant'
           *  RelationalOperator: '<S712>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S719>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S714>/Acceleration_Speed' incorporates:
           *  Constant: '<S714>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S714>/Acceleration_Speed' */

          /* Product: '<S718>/Divide1' incorporates:
           *  Constant: '<S718>/Constant'
           */
          rtb_u_b = rtb_Saturation1_p5 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S718>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S718>/Saturation' */

          /* Update for DiscreteIntegrator: '<S760>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_u_b;

          /* Update for Delay: '<S697>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S700>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S700>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S706>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S706>/Sign3' */

          /* Signum: '<S706>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S706>/Sign4' */

          /* Update for DiscreteIntegrator: '<S700>/Integrator' incorporates:
           *  Constant: '<S706>/const'
           *  Gain: '<S706>/Gain3'
           *  Product: '<S706>/Multiply5'
           *  Product: '<S706>/Multiply6'
           *  Sum: '<S706>/Subtract4'
           *  Sum: '<S706>/Subtract5'
           *  Sum: '<S706>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_d *
            ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4
            * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S700>/Integrator' */
          /* End of Outputs for SubSystem: '<S333>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S333>/Hold' incorporates:
             *  ActionPort: '<S632>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S333>/Switch Case' incorporates:
             *  Delay: '<S653>/Delay'
             *  DiscreteIntegrator: '<S665>/Integrator'
             *  DiscreteIntegrator: '<S665>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S333>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S333>/Hold' incorporates:
             *  ActionPort: '<S632>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S333>/Switch Case' incorporates:
             *  Chart: '<S641>/Motion Status'
             *  Chart: '<S652>/Motion State'
             *  Chart: '<S673>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S333>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S333>/Hold' incorporates:
           *  ActionPort: '<S632>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S641>/Motion Status' incorporates:
           *  Abs: '<S641>/Abs'
           *  Constant: '<S641>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S652>/Motion State' incorporates:
           *  Abs: '<S652>/Abs'
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

          /* End of Chart: '<S652>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S673>/Motion State' incorporates:
           *  Constant: '<S673>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S673>/Square'
           *  Math: '<S673>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S673>/Sqrt'
           *  Sum: '<S673>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                            &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S672>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S672>/Hold Control' incorporates:
               *  ActionPort: '<S675>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S672>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S672>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S672>/Hold Control' incorporates:
             *  ActionPort: '<S675>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S672>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S672>/Brake Control' incorporates:
             *  ActionPort: '<S674>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S672>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S672>/Move Control' incorporates:
               *  ActionPort: '<S676>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S672>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S672>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S672>/Move Control' incorporates:
             *  ActionPort: '<S676>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S672>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S672>/Switch Case' */

          /* SwitchCase: '<S640>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S640>/Hold Control' incorporates:
               *  ActionPort: '<S643>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S640>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S640>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S640>/Hold Control' incorporates:
             *  ActionPort: '<S643>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S640>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S640>/Brake Control' incorporates:
             *  ActionPort: '<S642>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S640>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S640>/Move Control' incorporates:
               *  ActionPort: '<S644>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S640>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S640>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S640>/Move Control' incorporates:
             *  ActionPort: '<S644>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S640>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S640>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S650>/Compare' incorporates:
           *  Constant: '<S650>/Constant'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S653>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S665>/Integrator1' incorporates:
           *  Delay: '<S653>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S651>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S651>/Hold Control' incorporates:
               *  ActionPort: '<S655>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S651>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S651>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S651>/Hold Control' incorporates:
             *  ActionPort: '<S655>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S651>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S651>/Brake Control' incorporates:
             *  ActionPort: '<S654>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S651>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S651>/Move Control' incorporates:
               *  ActionPort: '<S656>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S651>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S651>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S651>/Move Control' incorporates:
             *  ActionPort: '<S656>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S651>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S651>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S638>/Switch' incorporates:
           *  Saturate: '<S651>/Saturation'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S668>/Rem' incorporates:
             *  Constant: '<S668>/Constant1'
             *  DiscreteIntegrator: '<S665>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S664>/Sum'
             */
            rtb_Saturation_ga = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S668>/Switch' incorporates:
             *  Abs: '<S668>/Abs'
             *  Constant: '<S668>/Constant'
             *  Constant: '<S669>/Constant'
             *  Product: '<S668>/Multiply'
             *  RelationalOperator: '<S669>/Compare'
             *  Sum: '<S668>/Add'
             */
            if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
              /* Signum: '<S668>/Sign' */
              if (rtb_Saturation_ga < 0.0F) {
                rtb_Saturation1_d = -1.0F;
              } else if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              } else {
                rtb_Saturation1_d = rtb_Saturation_ga;
              }

              /* End of Signum: '<S668>/Sign' */
              rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
            }

            /* End of Switch: '<S668>/Switch' */

            /* Gain: '<S664>/Gain2' */
            rtb_Saturation_ga *= FMS_PARAM.YAW_P;

            /* Saturate: '<S664>/Saturation' */
            if (rtb_Saturation_ga > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Saturation_ga < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S664>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S651>/Saturation' */
            rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S651>/Saturation' */
            rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S651>/Saturation' */
            rtb_Saturation_ga = FMS_B.Merge_h;
          }

          /* End of Switch: '<S638>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S632>/Bus Assignment'
           *  Constant: '<S632>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S632>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_ga;

          /* Saturate: '<S672>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S672>/Saturation1' */

          /* Saturate: '<S640>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S632>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S640>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S666>/Rem' incorporates:
           *  Constant: '<S666>/Constant1'
           *  Delay: '<S653>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S653>/Sum2'
           */
          rtb_Saturation_ga = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S666>/Switch' incorporates:
           *  Abs: '<S666>/Abs'
           *  Constant: '<S666>/Constant'
           *  Constant: '<S671>/Constant'
           *  Product: '<S666>/Multiply'
           *  RelationalOperator: '<S671>/Compare'
           *  Sum: '<S666>/Add'
           */
          if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
            /* Signum: '<S666>/Sign' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_ga;
            }

            /* End of Signum: '<S666>/Sign' */
            rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S666>/Switch' */

          /* Sum: '<S653>/Sum' incorporates:
           *  Delay: '<S653>/Delay'
           */
          rtb_Saturation1_d = rtb_Saturation_ga + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S665>/Integrator' */
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

          /* Product: '<S670>/Multiply1' incorporates:
           *  Constant: '<S670>/const1'
           *  DiscreteIntegrator: '<S665>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S670>/Add' incorporates:
           *  DiscreteIntegrator: '<S665>/Integrator1'
           *  Sum: '<S665>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jz - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S670>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S670>/Sign' */

          /* Sum: '<S670>/Add2' incorporates:
           *  Abs: '<S670>/Abs'
           *  Gain: '<S670>/Gain'
           *  Gain: '<S670>/Gain1'
           *  Product: '<S670>/Multiply2'
           *  Product: '<S670>/Multiply3'
           *  Sqrt: '<S670>/Sqrt'
           *  Sum: '<S670>/Add1'
           *  Sum: '<S670>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_k) * FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S670>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Saturation1_p5) +
            rtb_Saturation_ga;

          /* Sum: '<S670>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_k;

          /* Sum: '<S670>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_k;

          /* Signum: '<S670>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S670>/Sign1' */

          /* Signum: '<S670>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S670>/Sign2' */

          /* Sum: '<S670>/Add5' incorporates:
           *  Gain: '<S670>/Gain2'
           *  Product: '<S670>/Multiply4'
           *  Sum: '<S670>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S653>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S665>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S665>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S670>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_p5 - FMS_ConstB.d_k;

          /* Sum: '<S670>/Add6' */
          rtb_Saturation1_d = rtb_Saturation1_p5 + FMS_ConstB.d_k;

          /* Signum: '<S670>/Sign5' incorporates:
           *  Signum: '<S670>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S670>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S670>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_p5;

            /* Signum: '<S670>/Sign6' */
            rtb_Sign5_l = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S670>/Sign5' */

          /* Signum: '<S670>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S670>/Sign3' */

          /* Signum: '<S670>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S670>/Sign4' */

          /* Update for DiscreteIntegrator: '<S665>/Integrator' incorporates:
           *  Constant: '<S670>/const'
           *  Gain: '<S670>/Gain3'
           *  Product: '<S670>/Divide'
           *  Product: '<S670>/Multiply5'
           *  Product: '<S670>/Multiply6'
           *  Sum: '<S670>/Subtract4'
           *  Sum: '<S670>/Subtract5'
           *  Sum: '<S670>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hi += ((rtb_Saturation1_p5 / FMS_ConstB.d_k -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_a * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          FMS_DW.Integrator_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* End of Update for DiscreteIntegrator: '<S665>/Integrator' */
          /* End of Outputs for SubSystem: '<S333>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S333>/Unknown' incorporates:
           *  ActionPort: '<S636>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S333>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
         *  ActionPort: '<S331>/Action Port'
         */
        /* SwitchCase: '<S331>/Switch Case' incorporates:
         *  Math: '<S515>/Math Function'
         *  Sum: '<S471>/Subtract'
         *  Sum: '<S528>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S442>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S493>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S483>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S442>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S331>/Offboard' incorporates:
           *  ActionPort: '<S443>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S609>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S612>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S613>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S613>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S613>/Multiply1' incorporates:
           *  Product: '<S613>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S613>/Divide' incorporates:
           *  Constant: '<S613>/Constant'
           *  Constant: '<S613>/R'
           *  Sqrt: '<S613>/Sqrt'
           *  Sum: '<S613>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S613>/Product3' incorporates:
           *  Constant: '<S613>/Constant1'
           *  Product: '<S613>/Multiply1'
           *  Sum: '<S613>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S613>/Multiply2' incorporates:
           *  Trigonometry: '<S613>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S612>/Sum' incorporates:
           *  Gain: '<S609>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S617>/Abs' incorporates:
           *  Abs: '<S620>/Abs1'
           *  Switch: '<S617>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S617>/Switch1' incorporates:
           *  Abs: '<S617>/Abs'
           *  Bias: '<S617>/Bias2'
           *  Bias: '<S617>/Bias3'
           *  Constant: '<S614>/Constant'
           *  Constant: '<S614>/Constant1'
           *  Constant: '<S619>/Constant'
           *  Gain: '<S617>/Gain1'
           *  Product: '<S617>/Multiply'
           *  RelationalOperator: '<S619>/Compare'
           *  Switch: '<S614>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S620>/Switch1' incorporates:
             *  Bias: '<S620>/Bias2'
             *  Bias: '<S620>/Bias3'
             *  Constant: '<S620>/Constant'
             *  Constant: '<S621>/Constant'
             *  Math: '<S620>/Math Function'
             *  RelationalOperator: '<S621>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S620>/Switch1' */

            /* Signum: '<S617>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S617>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S614>/Sum' incorporates:
           *  Gain: '<S609>/Gain1'
           *  Gain: '<S609>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S612>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S612>/Multiply' incorporates:
           *  Gain: '<S612>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S616>/Switch1' incorporates:
           *  Abs: '<S616>/Abs1'
           *  Bias: '<S616>/Bias2'
           *  Bias: '<S616>/Bias3'
           *  Constant: '<S616>/Constant'
           *  Constant: '<S618>/Constant'
           *  Math: '<S616>/Math Function'
           *  RelationalOperator: '<S618>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S616>/Switch1' */

          /* Product: '<S612>/Multiply' incorporates:
           *  Gain: '<S612>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S590>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S594>/Multiply1'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S603>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S603>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S603>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S603>/Gain' incorporates:
             *  Gain: '<S602>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S603>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S603>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S603>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S603>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S603>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S603>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S596>/Switch' incorporates:
             *  Constant: '<S611>/Constant'
             *  DataTypeConversion: '<S609>/Data Type Conversion1'
             *  Product: '<S615>/Multiply1'
             *  Product: '<S615>/Multiply2'
             *  RelationalOperator: '<S611>/Compare'
             *  S-Function (sfix_bitop): '<S608>/lat_cmd valid'
             *  Sum: '<S615>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o2 +
                                   rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S594>/Multiply' incorporates:
             *  Constant: '<S600>/Constant'
             *  Constant: '<S601>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S593>/Logical Operator'
             *  RelationalOperator: '<S600>/Compare'
             *  RelationalOperator: '<S601>/Compare'
             *  S-Function (sfix_bitop): '<S593>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/x_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S594>/Sum1'
             */
            rtb_Add4_j4 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S603>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S596>/Switch' incorporates:
             *  Constant: '<S611>/Constant'
             *  DataTypeConversion: '<S609>/Data Type Conversion1'
             *  Product: '<S615>/Multiply3'
             *  Product: '<S615>/Multiply4'
             *  RelationalOperator: '<S611>/Compare'
             *  S-Function (sfix_bitop): '<S608>/lon_cmd valid'
             *  Sum: '<S615>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                   rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S594>/Multiply' incorporates:
             *  Constant: '<S600>/Constant'
             *  Constant: '<S601>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S593>/Logical Operator'
             *  RelationalOperator: '<S600>/Compare'
             *  RelationalOperator: '<S601>/Compare'
             *  S-Function (sfix_bitop): '<S593>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/y_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S594>/Sum1'
             */
            d = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S603>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S596>/Switch' incorporates:
             *  Constant: '<S611>/Constant'
             *  DataTypeConversion: '<S609>/Data Type Conversion'
             *  DataTypeConversion: '<S609>/Data Type Conversion1'
             *  Gain: '<S609>/Gain2'
             *  Gain: '<S612>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S611>/Compare'
             *  S-Function (sfix_bitop): '<S608>/alt_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S612>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_u_b = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                                    -FMS_U.INS_Out.alt_0);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S594>/Multiply' incorporates:
             *  Constant: '<S600>/Constant'
             *  Constant: '<S601>/Constant'
             *  Gain: '<S597>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S593>/Logical Operator'
             *  RelationalOperator: '<S600>/Compare'
             *  RelationalOperator: '<S601>/Compare'
             *  S-Function (sfix_bitop): '<S593>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/z_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S594>/Sum1'
             */
            rtb_Sign5_l = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_u_b -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Sign5_l +
                (rtb_VectorConcatenate[rtb_n + 3] * d +
                 rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4);
            }

            /* SignalConversion: '<S536>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S536>/Constant4'
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  Product: '<S594>/Multiply1'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S536>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S536>/Gain' incorporates:
             *  Gain: '<S535>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S536>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S536>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S536>/Constant3'
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S536>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S536>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S536>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S525>/Multiply' incorporates:
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/ax_cmd valid'
             */
            rtb_Add4_j4 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S536>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S525>/Multiply' incorporates:
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/ay_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd
              : 0.0F;

            /* SignalConversion: '<S536>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S525>/Multiply' incorporates:
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/az_cmd valid'
             */
            rtb_Sign5_l = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S525>/Index Vector' incorporates:
             *  Product: '<S532>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                rtb_Sign5_l + (rtb_VectorConcatenate[rtb_n + 3] * d +
                               rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4);
            }
            break;

           case 1:
            /* SignalConversion: '<S606>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S606>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S606>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S604>/Gain'
             *  Trigonometry: '<S606>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S606>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S604>/Gain'
             *  Trigonometry: '<S606>/Trigonometric Function'
             */
            rtb_Saturation1_p5 = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S606>/Gain' incorporates:
             *  Trigonometry: '<S606>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -rtb_Saturation1_p5;

            /* SignalConversion: '<S606>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S606>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S606>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_p5;

            /* Trigonometry: '<S606>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_o4;

            /* SignalConversion: '<S607>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S607>/Constant4'
             */
            rtb_MatrixConcatenate1_a[5] = 0.0F;

            /* Gain: '<S605>/Gain' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S537>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S595>/Subtract'
             */
            rtb_a_g = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S607>/Trigonometric Function3' incorporates:
             *  Gain: '<S605>/Gain'
             *  Trigonometry: '<S607>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(rtb_a_g);
            rtb_MatrixConcatenate1_a[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S607>/Trigonometric Function2' incorporates:
             *  Gain: '<S605>/Gain'
             *  Trigonometry: '<S607>/Trigonometric Function'
             */
            rtb_Saturation1_p5 = arm_sin_f32(rtb_a_g);

            /* Gain: '<S607>/Gain' incorporates:
             *  Trigonometry: '<S607>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_a[3] = -rtb_Saturation1_p5;

            /* SignalConversion: '<S607>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S607>/Constant3'
             */
            rtb_MatrixConcatenate1_a[2] = 0.0F;

            /* Trigonometry: '<S607>/Trigonometric Function' */
            rtb_MatrixConcatenate1_a[1] = rtb_Saturation1_p5;

            /* Trigonometry: '<S607>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_a[0] = rtb_Saturation_o4;

            /* RelationalOperator: '<S611>/Compare' incorporates:
             *  Constant: '<S611>/Constant'
             *  S-Function (sfix_bitop): '<S608>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S608>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S608>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S609>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S609>/Data Type Conversion'
             *  Gain: '<S609>/Gain2'
             *  Gain: '<S612>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S615>/Multiply1'
             *  Product: '<S615>/Multiply2'
             *  Product: '<S615>/Multiply3'
             *  Product: '<S615>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S612>/Sum1'
             *  Sum: '<S615>/Sum2'
             *  Sum: '<S615>/Sum3'
             */
            rtb_MatrixConcatenate1_a_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S596>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S606>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S607>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S595>/Sum' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Add4_j4 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S606>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S607>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S595>/Sum' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            d = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S606>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S607>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S595>/Sum' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S597>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Sign5_l = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S600>/Compare' incorporates:
             *  Constant: '<S600>/Constant'
             *  S-Function (sfix_bitop): '<S593>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S601>/Compare' incorporates:
             *  Constant: '<S601>/Constant'
             *  S-Function (sfix_bitop): '<S593>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S595>/Sum2' incorporates:
               *  Product: '<S595>/Multiply2'
               *  Switch: '<S596>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_a_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              /* Product: '<S595>/Multiply' incorporates:
               *  Logic: '<S593>/Logical Operator'
               *  Product: '<S595>/Multiply2'
               *  Sum: '<S595>/Sum'
               *  Sum: '<S595>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? rtb_u_b -
                ((rtb_VectorConcatenate[rtb_n + 3] * d +
                  rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4) +
                 rtb_VectorConcatenate[rtb_n + 6] * rtb_Sign5_l) : 0.0F;
            }

            /* SignalConversion: '<S538>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S538>/Constant4'
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S538>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_a_g);

            /* Gain: '<S538>/Gain' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  Trigonometry: '<S538>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_a_g);

            /* SignalConversion: '<S538>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S538>/Constant3'
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S538>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_a_g);

            /* Trigonometry: '<S538>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_a_g);

            /* Product: '<S525>/Multiply' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S534>/Compare' incorporates:
             *  Constant: '<S534>/Constant'
             *  S-Function (sfix_bitop): '<S531>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S531>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S531>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S538>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S525>/Index Vector'
               */
              rtb_VectorConcatenate[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S525>/Multiply' */
              rtb_MatrixConcatenate1_a_0[rtb_n] = tmp[rtb_n] ?
                rtb_Switch_c2[rtb_n] : 0.0F;
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_MatrixConcatenate1_a[rtb_n + 6] * rtb_Switch_ov[2] +
                (rtb_MatrixConcatenate1_a[rtb_n + 3] * rtb_Switch_ov[1] +
                 rtb_MatrixConcatenate1_a[rtb_n] * rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S525>/Index Vector' incorporates:
             *  Product: '<S533>/Multiply3'
             *  Product: '<S595>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                rtb_MatrixConcatenate1_a_0[2] + (rtb_VectorConcatenate[rtb_n + 3]
                * rtb_MatrixConcatenate1_a_0[1] + rtb_VectorConcatenate[rtb_n] *
                rtb_MatrixConcatenate1_a_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S599>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S599>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S599>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S599>/Gain' incorporates:
             *  Gain: '<S598>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S599>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S599>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S599>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S599>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S599>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* S-Function (sfix_bitop): '<S608>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S593>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S611>/Compare' incorporates:
             *  Constant: '<S611>/Constant'
             *  S-Function (sfix_bitop): '<S608>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S608>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S593>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S611>/Compare' incorporates:
             *  Constant: '<S611>/Constant'
             *  S-Function (sfix_bitop): '<S608>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S608>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S593>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S611>/Compare' incorporates:
             *  Constant: '<S611>/Constant'
             *  S-Function (sfix_bitop): '<S608>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S609>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S609>/Data Type Conversion'
             *  Gain: '<S609>/Gain2'
             *  Gain: '<S612>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S615>/Multiply1'
             *  Product: '<S615>/Multiply2'
             *  Product: '<S615>/Multiply3'
             *  Product: '<S615>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S612>/Sum1'
             *  Sum: '<S615>/Sum2'
             *  Sum: '<S615>/Sum3'
             */
            rtb_MatrixConcatenate1_a_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S596>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S599>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Sum: '<S592>/Sum' incorporates:
             *  DataStoreRead: '<S592>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation_o4 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S599>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Sum: '<S592>/Sum' incorporates:
             *  DataStoreRead: '<S592>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation1_p5 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S599>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Sum: '<S592>/Sum' incorporates:
             *  DataStoreRead: '<S592>/Data Store Read'
             *  Gain: '<S597>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Add4_j4 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S600>/Compare' incorporates:
             *  Constant: '<S600>/Constant'
             *  S-Function (sfix_bitop): '<S593>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S593>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S601>/Compare' incorporates:
             *  Constant: '<S601>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S592>/Sum2' incorporates:
             *  Logic: '<S593>/Logical Operator'
             *  Product: '<S592>/Multiply'
             *  Product: '<S592>/Multiply2'
             *  Sum: '<S592>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S596>/Switch' incorporates:
               *  Product: '<S592>/Multiply2'
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
                rtb_Add4_j4) : 0.0F;
            }

            /* End of Sum: '<S592>/Sum2' */

            /* MultiPortSwitch: '<S525>/Index Vector' incorporates:
             *  Constant: '<S534>/Constant'
             *  Product: '<S525>/Multiply'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S531>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S531>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* Sum: '<S586>/Sum1' incorporates:
           *  Constant: '<S586>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S586>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_g = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S587>/Abs' */
          rtb_Saturation_o4 = fabsf(rtb_a_g);

          /* Switch: '<S587>/Switch' incorporates:
           *  Constant: '<S587>/Constant'
           *  Constant: '<S588>/Constant'
           *  Product: '<S587>/Multiply'
           *  RelationalOperator: '<S588>/Compare'
           *  Sum: '<S587>/Subtract'
           */
          if (rtb_Saturation_o4 > 3.14159274F) {
            /* Signum: '<S587>/Sign' */
            if (rtb_a_g < 0.0F) {
              rtb_a_g = -1.0F;
            } else {
              if (rtb_a_g > 0.0F) {
                rtb_a_g = 1.0F;
              }
            }

            /* End of Signum: '<S587>/Sign' */
            rtb_a_g *= rtb_Saturation_o4 - 6.28318548F;
          }

          /* End of Switch: '<S587>/Switch' */

          /* Saturate: '<S586>/Saturation' */
          if (rtb_a_g > 0.314159274F) {
            rtb_a_g = 0.314159274F;
          } else {
            if (rtb_a_g < -0.314159274F) {
              rtb_a_g = -0.314159274F;
            }
          }

          /* End of Saturate: '<S586>/Saturation' */

          /* Gain: '<S583>/Gain2' */
          rtb_a_g *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S527>/Sum' incorporates:
           *  Constant: '<S585>/Constant'
           *  Constant: '<S589>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S583>/Multiply2'
           *  Product: '<S584>/Multiply1'
           *  RelationalOperator: '<S585>/Compare'
           *  RelationalOperator: '<S589>/Compare'
           *  S-Function (sfix_bitop): '<S583>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S584>/psi_rate_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_u_b = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_a_g : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S590>/Gain1' */
          rtb_Saturation_o4 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMultip[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMultip
            [1];

          /* Gain: '<S590>/Gain2' */
          rtb_a_g = FMS_PARAM.Z_P * rtb_TmpSignalConversionAtMultip[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S591>/Index Vector' incorporates:
           *  Constant: '<S627>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S591>/Multiply'
           *  Product: '<S624>/Multiply'
           *  Product: '<S625>/Multiply3'
           *  RelationalOperator: '<S627>/Compare'
           *  S-Function (sfix_bitop): '<S623>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S623>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S623>/w_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S629>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S629>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S629>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S629>/Gain' incorporates:
             *  Gain: '<S628>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S629>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S629>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S629>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S629>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S629>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S629>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/u_cmd valid'
             */
            rtb_Add4_j4 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S629>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/v_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ? FMS_U.Auto_Cmd.v_cmd :
              0.0F;

            /* SignalConversion: '<S629>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/w_cmd valid'
             */
            rtb_Sign5_l = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Sign5_l +
                (rtb_VectorConcatenate[rtb_n + 3] * d +
                 rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4);
            }
            break;

           case 1:
            /* SignalConversion: '<S631>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S631>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Gain: '<S630>/Gain' incorporates:
             *  DataStoreRead: '<S625>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S625>/Subtract'
             */
            rtb_Saturation_ga = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S631>/Trigonometric Function3' incorporates:
             *  Gain: '<S630>/Gain'
             */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_Saturation_ga);

            /* Gain: '<S631>/Gain' incorporates:
             *  Gain: '<S630>/Gain'
             *  Trigonometry: '<S631>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S631>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S631>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S631>/Trigonometric Function' incorporates:
             *  Gain: '<S630>/Gain'
             */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_Saturation_ga);

            /* Trigonometry: '<S631>/Trigonometric Function1' incorporates:
             *  Gain: '<S630>/Gain'
             */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S631>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gjo[0];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/u_cmd valid'
             */
            rtb_Add4_j4 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S631>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gjo[1];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/v_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ? FMS_U.Auto_Cmd.v_cmd :
              0.0F;

            /* SignalConversion: '<S631>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gjo[2];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/w_cmd valid'
             */
            rtb_Sign5_l = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Sign5_l +
                (rtb_VectorConcatenate[rtb_n + 3] * d +
                 rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4);
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

          /* Sum: '<S528>/Sum1' */
          rtb_Saturation_ga = rtb_a_g + rtb_TmpSignalConversionAtMultip[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S546>/Switch' incorporates:
           *  Constant: '<S561>/Constant'
           *  Constant: '<S563>/Constant'
           *  Constant: '<S564>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S561>/Compare'
           *  RelationalOperator: '<S563>/Compare'
           *  RelationalOperator: '<S564>/Compare'
           *  S-Function (sfix_bitop): '<S546>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S546>/y_v_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S546>/Logical Operator' incorporates:
             *  Constant: '<S562>/Constant'
             *  Constant: '<S563>/Constant'
             *  Constant: '<S564>/Constant'
             *  RelationalOperator: '<S562>/Compare'
             *  RelationalOperator: '<S563>/Compare'
             *  RelationalOperator: '<S564>/Compare'
             *  S-Function (sfix_bitop): '<S546>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S546>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S546>/y_v_cmd'
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

          /* End of Switch: '<S546>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S526>/u_cmd_valid' */
          /* MATLAB Function: '<S558>/bit_shift' incorporates:
           *  DataTypeConversion: '<S526>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_at << 6);

          /* End of Outputs for SubSystem: '<S526>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S526>/v_cmd_valid' */
          /* MATLAB Function: '<S559>/bit_shift' incorporates:
           *  DataTypeConversion: '<S526>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S526>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S547>/Switch' incorporates:
           *  Constant: '<S566>/Constant'
           *  Constant: '<S567>/Constant'
           *  Constant: '<S569>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S566>/Compare'
           *  RelationalOperator: '<S567>/Compare'
           *  RelationalOperator: '<S569>/Compare'
           *  S-Function (sfix_bitop): '<S547>/ax_cmd'
           *  S-Function (sfix_bitop): '<S547>/ay_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S547>/Logical Operator' incorporates:
             *  Constant: '<S567>/Constant'
             *  Constant: '<S569>/Constant'
             *  RelationalOperator: '<S567>/Compare'
             *  RelationalOperator: '<S569>/Compare'
             *  S-Function (sfix_bitop): '<S547>/ax_cmd'
             *  S-Function (sfix_bitop): '<S547>/ay_cmd'
             */
            rtb_Compare_at = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_at;
          } else {
            rtb_Compare_at = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S547>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S443>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S443>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S443>/Bus Assignment' incorporates:
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

          /* Saturate: '<S527>/Saturation' */
          if (rtb_u_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_u_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S527>/Saturation' */

          /* Saturate: '<S528>/Saturation2' */
          if (rtb_TmpSignalConversionAtMultip[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_TmpSignalConversionAtMultip[0] < -FMS_PARAM.VEL_XY_LIM)
          {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMultip[0];
          }

          /* End of Saturate: '<S528>/Saturation2' */

          /* Saturate: '<S528>/Saturation1' */
          if (rtb_TmpSignalConversionAtMultip[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_TmpSignalConversionAtMultip[1] < -FMS_PARAM.VEL_XY_LIM)
          {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMultip[1];
          }

          /* End of Saturate: '<S528>/Saturation1' */

          /* Saturate: '<S528>/Saturation3' */
          if (rtb_Saturation_ga > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_ga < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S443>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;
          }

          /* End of Saturate: '<S528>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S526>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S526>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S526>/throttle_cmd_valid' */
          /* BusAssignment: '<S443>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S539>/Constant'
           *  Constant: '<S540>/Constant'
           *  Constant: '<S541>/Constant'
           *  Constant: '<S542>/Constant'
           *  Constant: '<S543>/Constant'
           *  Constant: '<S544>/Constant'
           *  Constant: '<S545>/Constant'
           *  Constant: '<S565>/Constant'
           *  Constant: '<S568>/Constant'
           *  DataTypeConversion: '<S526>/Data Type Conversion10'
           *  DataTypeConversion: '<S526>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S548>/bit_shift'
           *  MATLAB Function: '<S549>/bit_shift'
           *  MATLAB Function: '<S550>/bit_shift'
           *  MATLAB Function: '<S552>/bit_shift'
           *  MATLAB Function: '<S553>/bit_shift'
           *  MATLAB Function: '<S554>/bit_shift'
           *  MATLAB Function: '<S555>/bit_shift'
           *  MATLAB Function: '<S556>/bit_shift'
           *  MATLAB Function: '<S557>/bit_shift'
           *  MATLAB Function: '<S560>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S539>/Compare'
           *  RelationalOperator: '<S540>/Compare'
           *  RelationalOperator: '<S541>/Compare'
           *  RelationalOperator: '<S542>/Compare'
           *  RelationalOperator: '<S543>/Compare'
           *  RelationalOperator: '<S544>/Compare'
           *  RelationalOperator: '<S545>/Compare'
           *  RelationalOperator: '<S565>/Compare'
           *  RelationalOperator: '<S568>/Compare'
           *  S-Function (sfix_bitop): '<S526>/p_cmd'
           *  S-Function (sfix_bitop): '<S526>/phi_cmd'
           *  S-Function (sfix_bitop): '<S526>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S526>/q_cmd'
           *  S-Function (sfix_bitop): '<S526>/r_cmd'
           *  S-Function (sfix_bitop): '<S526>/theta_cmd'
           *  S-Function (sfix_bitop): '<S526>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S546>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S547>/az_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           *  Sum: '<S526>/Add'
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

          /* End of Outputs for SubSystem: '<S526>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S526>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S526>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S331>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S331>/Mission' incorporates:
             *  ActionPort: '<S442>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S331>/Switch Case' incorporates:
             *  UnitDelay: '<S445>/Delay Input1'
             *
             * Block description for '<S445>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S331>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S331>/Mission' incorporates:
             *  ActionPort: '<S442>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S442>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S331>/Switch Case' incorporates:
             *  Chart: '<S484>/Motion Status'
             *  Chart: '<S494>/Motion State'
             *  Delay: '<S450>/Delay'
             *  Delay: '<S472>/Delay'
             *  DiscreteIntegrator: '<S453>/Integrator'
             *  DiscreteIntegrator: '<S453>/Integrator1'
             *  DiscreteIntegrator: '<S468>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S473>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S520>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S442>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S331>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S331>/Mission' incorporates:
           *  ActionPort: '<S442>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S445>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S445>/Delay Input1'
           *
           * Block description for '<S445>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S442>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S446>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S493>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S483>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S472>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S468>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S520>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S450>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S494>/Motion State' */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S484>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S472>/Delay' incorporates:
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
          /* Switch: '<S468>/Switch2' incorporates:
           *  Constant: '<S468>/vel'
           *  Constant: '<S477>/Constant'
           *  RelationalOperator: '<S477>/Compare'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            rtb_Add4_j4 = FMS_B.Cmd_In.set_speed;
          } else {
            rtb_Add4_j4 = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S468>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S473>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S445>/Delay Input1'
           *
           * Block description for '<S445>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S467>/Compare' incorporates:
           *  Constant: '<S524>/Constant'
           *  RelationalOperator: '<S524>/Compare'
           *  UnitDelay: '<S445>/Delay Input1'
           *
           * Block description for '<S445>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S468>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S494>/Motion State' incorporates:
           *  Constant: '<S494>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S494>/Square'
           *  Math: '<S494>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S494>/Sqrt'
           *  Sum: '<S494>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S493>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S503>/Integrator1'
           *  Gain: '<S497>/Gain6'
           *  Gain: '<S501>/Gain'
           *  Gain: '<S502>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S503>/Subtract'
           *  Sum: '<S504>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S493>/Hold Control' incorporates:
               *  ActionPort: '<S496>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S493>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S493>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S493>/Hold Control' incorporates:
             *  ActionPort: '<S496>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S493>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S493>/Brake Control' incorporates:
             *  ActionPort: '<S495>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S493>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S493>/Move Control' incorporates:
               *  ActionPort: '<S497>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S493>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S503>/Integrator'
               *  DiscreteIntegrator: '<S503>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S493>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S493>/Move Control' incorporates:
             *  ActionPort: '<S497>/Action Port'
             */
            /* SignalConversion: '<S497>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S504>/Multiply1' incorporates:
             *  Constant: '<S504>/const1'
             *  DiscreteIntegrator: '<S503>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S497>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S504>/Multiply1' incorporates:
             *  Constant: '<S504>/const1'
             *  DiscreteIntegrator: '<S503>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S501>/Dead Zone' incorporates:
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

            /* Sum: '<S504>/Add' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator1'
             *  Gain: '<S497>/Gain6'
             *  Gain: '<S501>/Gain'
             *  Sum: '<S503>/Subtract'
             */
            rtb_Divide_f0[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S502>/Dead Zone' incorporates:
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

            /* Sum: '<S504>/Add' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator1'
             *  Gain: '<S497>/Gain6'
             *  Gain: '<S502>/Gain'
             *  Sum: '<S503>/Subtract'
             */
            rtb_Divide_f0[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S501>/Dead Zone' incorporates:
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

            /* Signum: '<S504>/Sign' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator1'
             *  Gain: '<S497>/Gain6'
             *  Gain: '<S501>/Gain'
             *  Sum: '<S503>/Subtract'
             *  Sum: '<S504>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S504>/Add2' incorporates:
             *  Abs: '<S504>/Abs'
             *  Gain: '<S504>/Gain'
             *  Gain: '<S504>/Gain1'
             *  Product: '<S504>/Multiply2'
             *  Product: '<S504>/Multiply3'
             *  Signum: '<S504>/Sign'
             *  Sqrt: '<S504>/Sqrt'
             *  Sum: '<S504>/Add1'
             *  Sum: '<S504>/Subtract'
             */
            rtb_Sign5_l = (sqrtf((8.0F * fabsf(rtb_Divide_f0[0]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Saturation1_d +
              rtb_Subtract_hb[0];

            /* Sum: '<S504>/Add3' incorporates:
             *  Signum: '<S504>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_f0[0] + FMS_ConstB.d_oe;

            /* Sum: '<S504>/Subtract1' incorporates:
             *  Signum: '<S504>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_f0[0] - FMS_ConstB.d_oe;

            /* Signum: '<S504>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S504>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S504>/Add5' incorporates:
             *  Gain: '<S504>/Gain2'
             *  Product: '<S504>/Multiply4'
             *  Signum: '<S504>/Sign'
             *  Sum: '<S504>/Add2'
             *  Sum: '<S504>/Add4'
             *  Sum: '<S504>/Subtract2'
             */
            rtb_Sign5_l += ((rtb_Divide_f0[0] - rtb_Sign5_l) + rtb_Subtract_hb[0])
              * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F);

            /* Update for DiscreteIntegrator: '<S503>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S504>/Sign4' incorporates:
             *  Sum: '<S504>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Sign5_l - FMS_ConstB.d_oe;

            /* Signum: '<S504>/Sign3' incorporates:
             *  Sum: '<S504>/Add6'
             */
            rtb_Saturation1_d = rtb_Sign5_l + FMS_ConstB.d_oe;

            /* Signum: '<S504>/Sign5' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Sign5_l;
            }

            /* Signum: '<S504>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S504>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S504>/Sign6' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Sign5_l;
            }

            /* Update for DiscreteIntegrator: '<S503>/Integrator' incorporates:
             *  Constant: '<S504>/const'
             *  Gain: '<S504>/Gain3'
             *  Product: '<S504>/Divide'
             *  Product: '<S504>/Multiply5'
             *  Product: '<S504>/Multiply6'
             *  Sum: '<S504>/Subtract4'
             *  Sum: '<S504>/Subtract5'
             *  Sum: '<S504>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Sign5_l / FMS_ConstB.d_oe -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_g * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_u_b * 58.836F) * 0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S502>/Dead Zone' incorporates:
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

            /* Signum: '<S504>/Sign' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator1'
             *  Gain: '<S497>/Gain6'
             *  Gain: '<S502>/Gain'
             *  Sum: '<S503>/Subtract'
             *  Sum: '<S504>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S504>/Add2' incorporates:
             *  Abs: '<S504>/Abs'
             *  Gain: '<S504>/Gain'
             *  Gain: '<S504>/Gain1'
             *  Product: '<S504>/Multiply2'
             *  Product: '<S504>/Multiply3'
             *  Signum: '<S504>/Sign'
             *  Sqrt: '<S504>/Sqrt'
             *  Sum: '<S504>/Add1'
             *  Sum: '<S504>/Subtract'
             */
            rtb_Sign5_l = (sqrtf((8.0F * fabsf(rtb_Divide_f0[1]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Saturation1_d +
              rtb_Subtract_hb[1];

            /* Sum: '<S504>/Add3' incorporates:
             *  Signum: '<S504>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_f0[1] + FMS_ConstB.d_oe;

            /* Sum: '<S504>/Subtract1' incorporates:
             *  Signum: '<S504>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_f0[1] - FMS_ConstB.d_oe;

            /* Signum: '<S504>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S504>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S504>/Add5' incorporates:
             *  Gain: '<S504>/Gain2'
             *  Product: '<S504>/Multiply4'
             *  Signum: '<S504>/Sign'
             *  Sum: '<S504>/Add2'
             *  Sum: '<S504>/Add4'
             *  Sum: '<S504>/Subtract2'
             */
            rtb_Sign5_l += ((rtb_Divide_f0[1] - rtb_Sign5_l) + rtb_Subtract_hb[1])
              * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F);

            /* Update for DiscreteIntegrator: '<S503>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S503>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S504>/Sign4' incorporates:
             *  Sum: '<S504>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Sign5_l - FMS_ConstB.d_oe;

            /* Signum: '<S504>/Sign3' incorporates:
             *  Sum: '<S504>/Add6'
             */
            rtb_Saturation1_d = rtb_Sign5_l + FMS_ConstB.d_oe;

            /* Signum: '<S504>/Sign5' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Sign5_l;
            }

            /* Signum: '<S504>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S504>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S504>/Sign6' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Sign5_l;
            }

            /* Update for DiscreteIntegrator: '<S503>/Integrator' incorporates:
             *  Constant: '<S504>/const'
             *  Gain: '<S504>/Gain3'
             *  Product: '<S504>/Divide'
             *  Product: '<S504>/Multiply5'
             *  Product: '<S504>/Multiply6'
             *  Sum: '<S504>/Subtract4'
             *  Sum: '<S504>/Subtract5'
             *  Sum: '<S504>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Sign5_l / FMS_ConstB.d_oe -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_g * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_u_b * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S493>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S493>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S484>/Motion Status' incorporates:
           *  Abs: '<S484>/Abs'
           *  Constant: '<S484>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S483>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S483>/Hold Control' incorporates:
               *  ActionPort: '<S486>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S483>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S483>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S483>/Hold Control' incorporates:
             *  ActionPort: '<S486>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S483>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S483>/Brake Control' incorporates:
             *  ActionPort: '<S485>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S483>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S483>/Move Control' incorporates:
               *  ActionPort: '<S487>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S483>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S490>/Integrator'
               *  DiscreteIntegrator: '<S490>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S483>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S483>/Move Control' incorporates:
             *  ActionPort: '<S487>/Action Port'
             */
            /* Product: '<S491>/Multiply1' incorporates:
             *  Constant: '<S491>/const1'
             *  DiscreteIntegrator: '<S490>/Integrator'
             */
            rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S489>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S489>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S491>/Add' incorporates:
             *  DiscreteIntegrator: '<S490>/Integrator1'
             *  Gain: '<S487>/Gain1'
             *  Gain: '<S489>/Gain'
             *  Sum: '<S490>/Subtract'
             */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_u_b * -FMS_PARAM.VEL_Z_LIM) +
              rtb_Saturation_ga;

            /* Signum: '<S491>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Saturation1_d;
            }

            /* End of Signum: '<S491>/Sign' */

            /* Sum: '<S491>/Add2' incorporates:
             *  Abs: '<S491>/Abs'
             *  Gain: '<S491>/Gain'
             *  Gain: '<S491>/Gain1'
             *  Product: '<S491>/Multiply2'
             *  Product: '<S491>/Multiply3'
             *  Sqrt: '<S491>/Sqrt'
             *  Sum: '<S491>/Add1'
             *  Sum: '<S491>/Subtract'
             */
            rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_oc)
                             * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_o4 + rtb_Saturation_ga;

            /* Sum: '<S491>/Add4' */
            rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) +
              rtb_Saturation_ga;

            /* Sum: '<S491>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_oc;

            /* Sum: '<S491>/Subtract1' */
            rtb_Saturation1_d -= FMS_ConstB.d_oc;

            /* Signum: '<S491>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S491>/Sign1' */

            /* Signum: '<S491>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S491>/Sign2' */

            /* Sum: '<S491>/Add5' incorporates:
             *  Gain: '<S491>/Gain2'
             *  Product: '<S491>/Multiply4'
             *  Sum: '<S491>/Subtract2'
             */
            rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
              rtb_Saturation_o4;

            /* SignalConversion: '<S487>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S490>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S490>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S490>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S491>/Subtract3' */
            rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_oc;

            /* Sum: '<S491>/Add6' */
            rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_oc;

            /* Signum: '<S491>/Sign5' incorporates:
             *  Signum: '<S491>/Sign6'
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_o4 = -1.0F;

              /* Signum: '<S491>/Sign6' */
              rtb_Sign5_l = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Saturation_o4 = 1.0F;

              /* Signum: '<S491>/Sign6' */
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_u_b;

              /* Signum: '<S491>/Sign6' */
              rtb_Sign5_l = rtb_u_b;
            }

            /* End of Signum: '<S491>/Sign5' */

            /* Signum: '<S491>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S491>/Sign3' */

            /* Signum: '<S491>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S491>/Sign4' */

            /* Update for DiscreteIntegrator: '<S490>/Integrator' incorporates:
             *  Constant: '<S491>/const'
             *  Gain: '<S491>/Gain3'
             *  Product: '<S491>/Divide'
             *  Product: '<S491>/Multiply5'
             *  Product: '<S491>/Multiply6'
             *  Sum: '<S491>/Subtract4'
             *  Sum: '<S491>/Subtract5'
             *  Sum: '<S491>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_u_b / FMS_ConstB.d_oc -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_j * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S483>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S483>/Switch Case' */

          /* Switch: '<S448>/Switch' incorporates:
           *  Product: '<S472>/Multiply'
           *  Sum: '<S472>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S493>/Saturation1' */
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

            /* End of Saturate: '<S493>/Saturation1' */

            /* Saturate: '<S483>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S483>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S472>/Sum' incorporates:
             *  Delay: '<S472>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S521>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S468>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S472>/Sum' incorporates:
             *  Delay: '<S472>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S468>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S480>/Sqrt' incorporates:
             *  Math: '<S480>/Square'
             *  Sum: '<S468>/Sum'
             *  Sum: '<S480>/Sum of Elements'
             */
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S523>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S523>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S523>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S522>/Gain' incorporates:
             *  DiscreteIntegrator: '<S520>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S520>/Add'
             */
            rtb_u_b = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S523>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_u_b);

            /* Gain: '<S523>/Gain' incorporates:
             *  Trigonometry: '<S523>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_u_b);

            /* SignalConversion: '<S523>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S523>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S523>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_u_b);

            /* Trigonometry: '<S523>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_u_b);

            /* Switch: '<S479>/Switch2' incorporates:
             *  Constant: '<S468>/Constant2'
             *  DiscreteIntegrator: '<S468>/Acceleration_Speed'
             *  RelationalOperator: '<S479>/LowerRelop1'
             *  RelationalOperator: '<S479>/UpperRelop'
             *  Switch: '<S479>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Add4_j4) {
              rtb_u_b = rtb_Add4_j4;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S479>/Switch' incorporates:
               *  Constant: '<S468>/Constant2'
               */
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S479>/Switch2' */

            /* Switch: '<S468>/Switch' */
            if (rtb_Saturation_ga > FMS_PARAM.L1) {
              rtb_Saturation1_d = rtb_Add4_j4;
            } else {
              /* Gain: '<S468>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_Saturation_ga;

              /* Switch: '<S478>/Switch2' incorporates:
               *  Constant: '<S468>/Constant1'
               *  RelationalOperator: '<S478>/LowerRelop1'
               *  RelationalOperator: '<S478>/UpperRelop'
               *  Switch: '<S478>/Switch'
               */
              if (rtb_Saturation1_d > rtb_Add4_j4) {
                rtb_Saturation1_d = rtb_Add4_j4;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  /* Switch: '<S478>/Switch' incorporates:
                   *  Constant: '<S468>/Constant1'
                   */
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Switch: '<S478>/Switch2' */
            }

            /* End of Switch: '<S468>/Switch' */

            /* Switch: '<S468>/Switch1' incorporates:
             *  Sum: '<S468>/Sum1'
             */
            if (rtb_u_b - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = rtb_u_b;
            }

            /* End of Switch: '<S468>/Switch1' */

            /* Sum: '<S521>/Sum of Elements' incorporates:
             *  Math: '<S521>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Saturation_o4 *
              rtb_Saturation_o4;

            /* Math: '<S521>/Math Function1' incorporates:
             *  Sum: '<S521>/Sum of Elements'
             *
             * About '<S521>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_u_b = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_u_b = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S521>/Math Function1' */

            /* Switch: '<S521>/Switch' incorporates:
             *  Constant: '<S521>/Constant'
             *  Product: '<S521>/Product'
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

            /* End of Switch: '<S521>/Switch' */

            /* Product: '<S519>/Multiply2' incorporates:
             *  Product: '<S521>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_bu[0] / rtb_Divide_bu[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_bu[1] / rtb_Divide_bu[3];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S474>/Sum1' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_u_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S474>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Sign5_l = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_a_g = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S474>/Divide' incorporates:
             *  Math: '<S475>/Square'
             *  Math: '<S476>/Square'
             *  Sqrt: '<S475>/Sqrt'
             *  Sqrt: '<S476>/Sqrt'
             *  Sum: '<S474>/Sum'
             *  Sum: '<S474>/Sum1'
             *  Sum: '<S475>/Sum of Elements'
             *  Sum: '<S476>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Sign5_l * rtb_Sign5_l + rtb_a_g * rtb_a_g) /
              sqrtf(rtb_Saturation_o4 * rtb_Saturation_o4 + rtb_u_b * rtb_u_b);

            /* Saturate: '<S474>/Saturation' */
            if (rtb_u_b > 1.0F) {
              rtb_u_b = 1.0F;
            } else {
              if (rtb_u_b < 0.0F) {
                rtb_u_b = 0.0F;
              }
            }

            /* End of Saturate: '<S474>/Saturation' */

            /* Product: '<S472>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n +
                3] * rtb_Saturation1_d + rtb_VectorConcatenate[rtb_n] *
                rtb_Saturation_ga;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S465>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S474>/Multiply'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S465>/Sum2'
             *  Sum: '<S474>/Add'
             *  Sum: '<S474>/Subtract'
             */
            rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_b +
                        FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_MatrixConcatenate1_a_0[0];
            rtb_Switch_c2[1] = rtb_MatrixConcatenate1_a_0[1];

            /* Saturate: '<S465>/Saturation1' incorporates:
             *  Product: '<S472>/Multiply'
             */
            if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_u_b;
            }

            /* End of Saturate: '<S465>/Saturation1' */
          }

          /* End of Switch: '<S448>/Switch' */

          /* Delay: '<S450>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S453>/Integrator1' incorporates:
           *  Delay: '<S450>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S457>/Rem' incorporates:
           *  Constant: '<S457>/Constant1'
           *  DiscreteIntegrator: '<S453>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S452>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S457>/Switch' incorporates:
           *  Abs: '<S457>/Abs'
           *  Constant: '<S457>/Constant'
           *  Constant: '<S458>/Constant'
           *  Product: '<S457>/Multiply'
           *  RelationalOperator: '<S458>/Compare'
           *  Sum: '<S457>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S457>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S457>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S457>/Switch' */

          /* Gain: '<S452>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S452>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S452>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S446>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S446>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S446>/Bus Assignment' incorporates:
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

          /* Math: '<S514>/Math Function1'
           *
           * About '<S514>/Math Function1':
           *  Operator: sqrt
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(d));
          } else {
            rtb_Saturation_o4 = sqrtf(d);
          }

          /* End of Math: '<S514>/Math Function1' */

          /* Switch: '<S514>/Switch' incorporates:
           *  Constant: '<S514>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S514>/Product'
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

          /* End of Switch: '<S514>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S446>/Sum' incorporates:
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

          /* SignalConversion: '<S464>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S446>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S464>/Math Function' incorporates:
           *  Sum: '<S446>/Sum'
           */
          rtb_Square_dv[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_dv[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S464>/Sum of Elements' */
          rtb_u_b = rtb_Square_dv[0] + rtb_Square_dv[1];

          /* Math: '<S464>/Math Function1' incorporates:
           *  Sum: '<S464>/Sum of Elements'
           *
           * About '<S464>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S464>/Math Function1' */

          /* Switch: '<S464>/Switch' incorporates:
           *  Constant: '<S464>/Constant'
           *  Product: '<S464>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            d = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            d = 1.0F;
          }

          /* End of Switch: '<S464>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S470>/NearbyRefWP' incorporates:
           *  Constant: '<S446>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f0,
                          &rtb_u_b);

          /* MATLAB Function: '<S470>/SearchL1RefWP' incorporates:
           *  Constant: '<S446>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S470>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0],
                               &rtb_TmpSignalConversionAtMultip[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_dv);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S470>/Switch1' incorporates:
           *  Constant: '<S507>/Constant'
           *  RelationalOperator: '<S507>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_f0[0];
            rtb_P_ap[1] = rtb_Divide_f0[1];
          } else {
            /* RelationalOperator: '<S506>/Compare' incorporates:
             *  Constant: '<S506>/Constant'
             */
            rtb_Compare_at = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S470>/Switch' */
            if (!rtb_Compare_at) {
              rtb_P_ap[0] = rtb_Square_dv[0];
              rtb_P_ap[1] = rtb_Square_dv[1];
            }

            /* End of Switch: '<S470>/Switch' */
          }

          /* End of Switch: '<S470>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S471>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Sign5_l;
          rtb_Saturation_o4 = rtb_Sign5_l * rtb_Sign5_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S471>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S515>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S515>/Sum of Elements' incorporates:
           *  Math: '<S515>/Math Function'
           *  Sum: '<S513>/Sum of Elements'
           */
          rtb_u_b = rtb_Saturation_o4 + rtb_Sign5_l * rtb_Sign5_l;

          /* Math: '<S515>/Math Function1' incorporates:
           *  Sum: '<S515>/Sum of Elements'
           *
           * About '<S515>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S515>/Math Function1' */

          /* Switch: '<S515>/Switch' incorporates:
           *  Constant: '<S515>/Constant'
           *  Product: '<S515>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_P_ap[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Sign5_l;
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S515>/Switch' */

          /* Product: '<S514>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S517>/Sum of Elements' incorporates:
           *  Math: '<S517>/Math Function'
           *  SignalConversion: '<S517>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_g = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S517>/Math Function1' incorporates:
           *  Sum: '<S517>/Sum of Elements'
           *
           * About '<S517>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_g < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_g));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_g);
          }

          /* End of Math: '<S517>/Math Function1' */

          /* Switch: '<S517>/Switch' incorporates:
           *  Constant: '<S517>/Constant'
           *  Product: '<S517>/Product'
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

          /* End of Switch: '<S517>/Switch' */

          /* Product: '<S515>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S518>/Sum of Elements' incorporates:
           *  Math: '<S518>/Math Function'
           *  SignalConversion: '<S518>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_g = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S518>/Math Function1' incorporates:
           *  Sum: '<S518>/Sum of Elements'
           *
           * About '<S518>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_g < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_g));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_g);
          }

          /* End of Math: '<S518>/Math Function1' */

          /* Switch: '<S518>/Switch' incorporates:
           *  Constant: '<S518>/Constant'
           *  Product: '<S518>/Product'
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

          /* End of Switch: '<S518>/Switch' */

          /* Product: '<S518>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S517>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S464>/Divide' */
          rtb_Square_dv[0] = rtb_Saturation_ga / d;

          /* Product: '<S518>/Divide' */
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S517>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S464>/Divide' */
          rtb_Square_dv[1] = rtb_Saturation1_d / d;

          /* Sum: '<S516>/Subtract' incorporates:
           *  Product: '<S516>/Multiply'
           *  Product: '<S516>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_f0[0] * rtb_P_ap[1] - rtb_Divide_f0[1] *
            rtb_P_ap[0];

          /* Signum: '<S511>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S511>/Sign1' */

          /* Switch: '<S511>/Switch2' incorporates:
           *  Constant: '<S511>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S511>/Switch2' */

          /* DotProduct: '<S511>/Dot Product' */
          rtb_Sign5_l = rtb_P_ap[0] * rtb_Divide_f0[0] + rtb_P_ap[1] *
            rtb_Divide_f0[1];

          /* Trigonometry: '<S511>/Acos' incorporates:
           *  DotProduct: '<S511>/Dot Product'
           */
          if (rtb_Sign5_l > 1.0F) {
            rtb_Sign5_l = 1.0F;
          } else {
            if (rtb_Sign5_l < -1.0F) {
              rtb_Sign5_l = -1.0F;
            }
          }

          /* Product: '<S511>/Multiply' incorporates:
           *  Trigonometry: '<S511>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Sign5_l);

          /* Saturate: '<S471>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S471>/Saturation' */

          /* Product: '<S471>/Divide' incorporates:
           *  Constant: '<S446>/L1'
           *  Constant: '<S471>/Constant'
           *  Gain: '<S471>/Gain'
           *  Math: '<S471>/Square'
           *  MinMax: '<S471>/Max'
           *  MinMax: '<S471>/Min'
           *  Product: '<S471>/Multiply1'
           *  Sqrt: '<S513>/Sqrt'
           *  Trigonometry: '<S471>/Sin'
           */
          rtb_Saturation1_p5 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S462>/Subtract' incorporates:
           *  Product: '<S462>/Multiply'
           *  Product: '<S462>/Multiply1'
           */
          d = rtb_Square_dv[0] * FMS_ConstB.Divide[1] - rtb_Square_dv[1] *
            FMS_ConstB.Divide[0];

          /* Signum: '<S451>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S451>/Sign1' */

          /* Switch: '<S451>/Switch2' incorporates:
           *  Constant: '<S451>/Constant4'
           */
          if (d == 0.0F) {
            d = 1.0F;
          }

          /* End of Switch: '<S451>/Switch2' */

          /* DotProduct: '<S451>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide[0] * rtb_Square_dv[0] + FMS_ConstB.Divide
            [1] * rtb_Square_dv[1];

          /* Trigonometry: '<S451>/Acos' incorporates:
           *  DotProduct: '<S451>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S451>/Multiply' incorporates:
           *  Trigonometry: '<S451>/Acos'
           */
          d *= acosf(rtb_u_b);

          /* Math: '<S454>/Rem' incorporates:
           *  Constant: '<S454>/Constant1'
           *  Delay: '<S450>/Delay'
           *  Sum: '<S450>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(d - FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S454>/Switch' incorporates:
           *  Abs: '<S454>/Abs'
           *  Constant: '<S454>/Constant'
           *  Constant: '<S460>/Constant'
           *  Product: '<S454>/Multiply'
           *  RelationalOperator: '<S460>/Compare'
           *  Sum: '<S454>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S454>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S454>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S454>/Switch' */

          /* Sum: '<S450>/Sum' incorporates:
           *  Delay: '<S450>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S459>/Multiply1' incorporates:
           *  Constant: '<S459>/const1'
           *  DiscreteIntegrator: '<S453>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S459>/Add' incorporates:
           *  DiscreteIntegrator: '<S453>/Integrator1'
           *  Sum: '<S453>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S459>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S459>/Sign' */

          /* Sum: '<S459>/Add2' incorporates:
           *  Abs: '<S459>/Abs'
           *  Gain: '<S459>/Gain'
           *  Gain: '<S459>/Gain1'
           *  Product: '<S459>/Multiply2'
           *  Product: '<S459>/Multiply3'
           *  Sqrt: '<S459>/Sqrt'
           *  Sum: '<S459>/Add1'
           *  Sum: '<S459>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_m) *
                           FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S459>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S459>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_m;

          /* Sum: '<S459>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_m;

          /* Signum: '<S459>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S459>/Sign1' */

          /* Signum: '<S459>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S459>/Sign2' */

          /* Sum: '<S459>/Add5' incorporates:
           *  Gain: '<S459>/Gain2'
           *  Product: '<S459>/Multiply4'
           *  Sum: '<S459>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S459>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_m;

          /* Sum: '<S459>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_m;

          /* Product: '<S459>/Divide' */
          rtb_Sign5_l = rtb_u_b / FMS_ConstB.d_m;

          /* Signum: '<S459>/Sign5' incorporates:
           *  Signum: '<S459>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_a_g = -1.0F;

            /* Signum: '<S459>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_a_g = 1.0F;

            /* Signum: '<S459>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_a_g = rtb_u_b;

            /* Signum: '<S459>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S459>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S450>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          d -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S455>/Rem' incorporates:
           *  Constant: '<S455>/Constant1'
           */
          rtb_u_b = rt_remf(d, 6.28318548F);

          /* Switch: '<S455>/Switch' incorporates:
           *  Abs: '<S455>/Abs'
           *  Constant: '<S455>/Constant'
           *  Constant: '<S461>/Constant'
           *  Product: '<S455>/Multiply'
           *  RelationalOperator: '<S461>/Compare'
           *  Sum: '<S455>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S455>/Sign' */
            if (rtb_u_b < 0.0F) {
              d = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_u_b;
            }

            /* End of Signum: '<S455>/Sign' */
            rtb_u_b -= 6.28318548F * d;
          }

          /* End of Switch: '<S455>/Switch' */

          /* Abs: '<S448>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S472>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S466>/Constant'
           *  RelationalOperator: '<S466>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S468>/Acceleration_Speed' incorporates:
           *  Constant: '<S468>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S472>/Divide1' */
          rtb_u_b = rtb_Saturation1_p5 / rtb_Add4_j4;

          /* Saturate: '<S472>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S472>/Saturation' */

          /* Update for DiscreteIntegrator: '<S520>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_u_b;

          /* Update for Delay: '<S450>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S453>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S453>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S459>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S459>/Sign3' */

          /* Signum: '<S459>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S459>/Sign4' */

          /* Update for DiscreteIntegrator: '<S453>/Integrator' incorporates:
           *  Constant: '<S459>/const'
           *  Gain: '<S459>/Gain3'
           *  Product: '<S459>/Multiply5'
           *  Product: '<S459>/Multiply6'
           *  Sum: '<S459>/Subtract4'
           *  Sum: '<S459>/Subtract5'
           *  Sum: '<S459>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Sign5_l - rtb_a_g) *
            FMS_ConstB.Gain4_cu * ((rtb_Saturation_ga - rtb_Saturation1_d) *
            0.5F) - rtb_Saturation_o4 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S453>/Integrator' */
          /* End of Outputs for SubSystem: '<S442>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S445>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S445>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S331>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S331>/Unknown' incorporates:
           *  ActionPort: '<S444>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S331>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
         *  ActionPort: '<S330>/Action Port'
         */
        /* SwitchCase: '<S330>/Switch Case' */
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
            /* Disable for SwitchCase: '<S429>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S345>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S363>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S379>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S404>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S391>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S330>/Acro' incorporates:
           *  ActionPort: '<S335>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S335>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S335>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S335>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Gain: '<S340>/Gain'
           *  Gain: '<S340>/Gain1'
           *  Gain: '<S340>/Gain2'
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

          /* Saturate: '<S341>/Saturation' incorporates:
           *  Constant: '<S341>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  Sum: '<S341>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_u_b = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S341>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S335>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S341>/Constant5'
           *  Gain: '<S341>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S341>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_u_b), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S330>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S330>/Stabilize' incorporates:
             *  ActionPort: '<S338>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S330>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S425>/Integrator'
             *  DiscreteIntegrator: '<S425>/Integrator1'
             *  DiscreteIntegrator: '<S426>/Integrator'
             *  DiscreteIntegrator: '<S426>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S330>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S330>/Stabilize' incorporates:
             *  ActionPort: '<S338>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S330>/Switch Case' incorporates:
             *  Chart: '<S430>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S330>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S330>/Stabilize' incorporates:
           *  ActionPort: '<S338>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S420>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S430>/Motion State' incorporates:
           *  Abs: '<S430>/Abs'
           *  Abs: '<S430>/Abs1'
           *  Constant: '<S440>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S440>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S429>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S429>/Hold Control' incorporates:
               *  ActionPort: '<S432>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S429>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S429>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S429>/Hold Control' incorporates:
             *  ActionPort: '<S432>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S429>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S429>/Brake Control' incorporates:
             *  ActionPort: '<S431>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S429>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S429>/Move Control' incorporates:
               *  ActionPort: '<S433>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S429>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S429>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S429>/Move Control' incorporates:
             *  ActionPort: '<S433>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S429>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S429>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S422>/Switch' incorporates:
           *  Constant: '<S422>/Constant'
           *  Constant: '<S422>/Constant4'
           *  Constant: '<S422>/Constant5'
           *  Gain: '<S422>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S422>/Saturation'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S422>/Add'
           *  Sum: '<S422>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S422>/Saturation' */
              rtb_u_b = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S422>/Saturation' */
              rtb_u_b = 0.0F;
            } else {
              /* Saturate: '<S422>/Saturation' incorporates:
               *  Constant: '<S422>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S43>/Signal Copy2'
               *  Sum: '<S422>/Sum'
               */
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_u_b),
              65536.0F) + 1000U);
          }

          /* End of Switch: '<S422>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S338>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S338>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S338>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S420>/Data Type Conversion'
           *  DiscreteIntegrator: '<S425>/Integrator1'
           *  DiscreteIntegrator: '<S426>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S420>/Multiply'
           *  Product: '<S420>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S429>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S338>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S338>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S429>/Saturation' */

          /* BusAssignment: '<S338>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S428>/Multiply1' incorporates:
           *  Constant: '<S428>/const1'
           *  DiscreteIntegrator: '<S426>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S424>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S424>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S428>/Add' incorporates:
           *  DiscreteIntegrator: '<S426>/Integrator1'
           *  Gain: '<S420>/Gain1'
           *  Gain: '<S424>/Gain'
           *  Sum: '<S426>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S428>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S428>/Sign' */

          /* Sum: '<S428>/Add2' incorporates:
           *  Abs: '<S428>/Abs'
           *  Gain: '<S428>/Gain'
           *  Gain: '<S428>/Gain1'
           *  Product: '<S428>/Multiply2'
           *  Product: '<S428>/Multiply3'
           *  Sqrt: '<S428>/Sqrt'
           *  Sum: '<S428>/Add1'
           *  Sum: '<S428>/Subtract'
           */
          rtb_Add4_j4 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_g) *
                               FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Add4_j4 + rtb_Saturation1_p5;

          /* Sum: '<S428>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Add4_j4) + rtb_Saturation1_p5;

          /* Sum: '<S428>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_g;

          /* Sum: '<S428>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_g;

          /* Signum: '<S428>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S428>/Sign1' */

          /* Signum: '<S428>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S428>/Sign2' */

          /* Sum: '<S428>/Add5' incorporates:
           *  Gain: '<S428>/Gain2'
           *  Product: '<S428>/Multiply4'
           *  Sum: '<S428>/Subtract2'
           */
          rtb_Add4_j4 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S428>/Add6' */
          rtb_Saturation_ga = rtb_Add4_j4 + FMS_ConstB.d_g;

          /* Sum: '<S428>/Subtract3' */
          rtb_Saturation1_d = rtb_Add4_j4 - FMS_ConstB.d_g;

          /* Product: '<S428>/Divide' */
          d = rtb_Add4_j4 / FMS_ConstB.d_g;

          /* Signum: '<S428>/Sign5' incorporates:
           *  Signum: '<S428>/Sign6'
           */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S428>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Add4_j4 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S428>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Add4_j4;

            /* Signum: '<S428>/Sign6' */
            rtb_Saturation_o4 = rtb_Add4_j4;
          }

          /* End of Signum: '<S428>/Sign5' */

          /* Product: '<S427>/Multiply1' incorporates:
           *  Constant: '<S427>/const1'
           *  DiscreteIntegrator: '<S425>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S423>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S423>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S427>/Add' incorporates:
           *  DiscreteIntegrator: '<S425>/Integrator1'
           *  Gain: '<S420>/Gain'
           *  Gain: '<S423>/Gain'
           *  Sum: '<S425>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S427>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S427>/Sign' */

          /* Sum: '<S427>/Add2' incorporates:
           *  Abs: '<S427>/Abs'
           *  Gain: '<S427>/Gain'
           *  Gain: '<S427>/Gain1'
           *  Product: '<S427>/Multiply2'
           *  Product: '<S427>/Multiply3'
           *  Sqrt: '<S427>/Sqrt'
           *  Sum: '<S427>/Add1'
           *  Sum: '<S427>/Subtract'
           */
          rtb_Add4_j4 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_a) *
                               FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Add4_j4 + rtb_Saturation1_p5;

          /* Sum: '<S427>/Add4' */
          rtb_a_g = (rtb_u_b - rtb_Add4_j4) + rtb_Saturation1_p5;

          /* Sum: '<S427>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_a;

          /* Sum: '<S427>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_a;

          /* Signum: '<S427>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S427>/Sign1' */

          /* Signum: '<S427>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S427>/Sign2' */

          /* Sum: '<S427>/Add5' incorporates:
           *  Gain: '<S427>/Gain2'
           *  Product: '<S427>/Multiply4'
           *  Sum: '<S427>/Subtract2'
           */
          rtb_Add4_j4 += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_a_g;

          /* Update for DiscreteIntegrator: '<S425>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S425>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S426>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S426>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S428>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S428>/Sign3' */

          /* Signum: '<S428>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S428>/Sign4' */

          /* Update for DiscreteIntegrator: '<S426>/Integrator' incorporates:
           *  Constant: '<S428>/const'
           *  Gain: '<S428>/Gain3'
           *  Product: '<S428>/Multiply5'
           *  Product: '<S428>/Multiply6'
           *  Sum: '<S428>/Subtract4'
           *  Sum: '<S428>/Subtract5'
           *  Sum: '<S428>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_o
            * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) -
            rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Sum: '<S427>/Subtract3' */
          rtb_Saturation_ga = rtb_Add4_j4 - FMS_ConstB.d_a;

          /* Sum: '<S427>/Add6' */
          rtb_Saturation1_d = rtb_Add4_j4 + FMS_ConstB.d_a;

          /* Signum: '<S427>/Sign5' incorporates:
           *  Signum: '<S427>/Sign6'
           */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S427>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Add4_j4 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S427>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Add4_j4;

            /* Signum: '<S427>/Sign6' */
            rtb_Sign5_l = rtb_Add4_j4;
          }

          /* End of Signum: '<S427>/Sign5' */

          /* Signum: '<S427>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S427>/Sign3' */

          /* Signum: '<S427>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S427>/Sign4' */

          /* Update for DiscreteIntegrator: '<S425>/Integrator' incorporates:
           *  Constant: '<S427>/const'
           *  Gain: '<S427>/Gain3'
           *  Product: '<S427>/Divide'
           *  Product: '<S427>/Multiply5'
           *  Product: '<S427>/Multiply6'
           *  Sum: '<S427>/Subtract4'
           *  Sum: '<S427>/Subtract5'
           *  Sum: '<S427>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Add4_j4 / FMS_ConstB.d_a -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_k * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S330>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S330>/Altitude' incorporates:
             *  ActionPort: '<S336>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S330>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S359>/Integrator'
             *  DiscreteIntegrator: '<S359>/Integrator1'
             *  DiscreteIntegrator: '<S360>/Integrator'
             *  DiscreteIntegrator: '<S360>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S330>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S330>/Altitude' incorporates:
             *  ActionPort: '<S336>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S330>/Switch Case' incorporates:
             *  Chart: '<S346>/Motion Status'
             *  Chart: '<S364>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S330>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S330>/Altitude' incorporates:
           *  ActionPort: '<S336>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S346>/Motion Status' incorporates:
           *  Abs: '<S346>/Abs'
           *  Abs: '<S346>/Abs1'
           *  Constant: '<S355>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S355>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S345>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S345>/Hold Control' incorporates:
               *  ActionPort: '<S348>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S345>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S345>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S345>/Hold Control' incorporates:
             *  ActionPort: '<S348>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S345>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S345>/Brake Control' incorporates:
             *  ActionPort: '<S347>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S345>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S345>/Move Control' incorporates:
             *  ActionPort: '<S349>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S345>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S345>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S342>/Switch' incorporates:
           *  Constant: '<S342>/Constant'
           *  Saturate: '<S345>/Saturation1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_ga = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S345>/Saturation1' */
            rtb_Saturation_ga = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S345>/Saturation1' */
            rtb_Saturation_ga = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S345>/Saturation1' */
            rtb_Saturation_ga = FMS_B.Merge_l;
          }

          /* End of Switch: '<S342>/Switch' */

          /* Logic: '<S343>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S364>/Motion State' incorporates:
           *  Abs: '<S364>/Abs'
           *  Abs: '<S364>/Abs1'
           *  Constant: '<S374>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S374>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S363>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S363>/Hold Control' incorporates:
               *  ActionPort: '<S366>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S363>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_pi);

              /* End of SystemReset for SubSystem: '<S363>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S363>/Hold Control' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_pi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S363>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S363>/Brake Control' incorporates:
             *  ActionPort: '<S365>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S363>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S363>/Move Control' incorporates:
               *  ActionPort: '<S367>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S363>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S363>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S363>/Move Control' incorporates:
             *  ActionPort: '<S367>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S363>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S363>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S336>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S336>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S336>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S343>/Data Type Conversion'
           *  DiscreteIntegrator: '<S359>/Integrator1'
           *  DiscreteIntegrator: '<S360>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S343>/Multiply'
           *  Product: '<S343>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S363>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S336>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S336>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S336>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S363>/Saturation' */

          /* BusAssignment: '<S336>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;

          /* Product: '<S362>/Multiply1' incorporates:
           *  Constant: '<S362>/const1'
           *  DiscreteIntegrator: '<S360>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S358>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S358>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S362>/Add' incorporates:
           *  DiscreteIntegrator: '<S360>/Integrator1'
           *  Gain: '<S343>/Gain1'
           *  Gain: '<S358>/Gain'
           *  Sum: '<S360>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S362>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S362>/Sign' */

          /* Sum: '<S362>/Add2' incorporates:
           *  Abs: '<S362>/Abs'
           *  Gain: '<S362>/Gain'
           *  Gain: '<S362>/Gain1'
           *  Product: '<S362>/Multiply2'
           *  Product: '<S362>/Multiply3'
           *  Sqrt: '<S362>/Sqrt'
           *  Sum: '<S362>/Add1'
           *  Sum: '<S362>/Subtract'
           */
          rtb_Add4_j4 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_o) *
                               FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
            rtb_Add4_j4 + rtb_Saturation1_p5;

          /* Sum: '<S362>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Add4_j4) + rtb_Saturation1_p5;

          /* Sum: '<S362>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_o;

          /* Sum: '<S362>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_o;

          /* Signum: '<S362>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S362>/Sign1' */

          /* Signum: '<S362>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S362>/Sign2' */

          /* Sum: '<S362>/Add5' incorporates:
           *  Gain: '<S362>/Gain2'
           *  Product: '<S362>/Multiply4'
           *  Sum: '<S362>/Subtract2'
           */
          rtb_Add4_j4 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S362>/Add6' */
          rtb_Saturation_ga = rtb_Add4_j4 + FMS_ConstB.d_o;

          /* Sum: '<S362>/Subtract3' */
          rtb_Saturation1_d = rtb_Add4_j4 - FMS_ConstB.d_o;

          /* Product: '<S362>/Divide' */
          d = rtb_Add4_j4 / FMS_ConstB.d_o;

          /* Signum: '<S362>/Sign5' incorporates:
           *  Signum: '<S362>/Sign6'
           */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S362>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Add4_j4 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S362>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Add4_j4;

            /* Signum: '<S362>/Sign6' */
            rtb_Saturation_o4 = rtb_Add4_j4;
          }

          /* End of Signum: '<S362>/Sign5' */

          /* Product: '<S361>/Multiply1' incorporates:
           *  Constant: '<S361>/const1'
           *  DiscreteIntegrator: '<S359>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S357>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S357>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S361>/Add' incorporates:
           *  DiscreteIntegrator: '<S359>/Integrator1'
           *  Gain: '<S343>/Gain'
           *  Gain: '<S357>/Gain'
           *  Sum: '<S359>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S361>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_j4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_j4 = 1.0F;
          } else {
            rtb_Add4_j4 = rtb_u_b;
          }

          /* End of Signum: '<S361>/Sign' */

          /* Sum: '<S361>/Add2' incorporates:
           *  Abs: '<S361>/Abs'
           *  Gain: '<S361>/Gain'
           *  Gain: '<S361>/Gain1'
           *  Product: '<S361>/Multiply2'
           *  Product: '<S361>/Multiply3'
           *  Sqrt: '<S361>/Sqrt'
           *  Sum: '<S361>/Add1'
           *  Sum: '<S361>/Subtract'
           */
          rtb_Add4_j4 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_c) *
                               FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
            rtb_Add4_j4 + rtb_Saturation1_p5;

          /* Sum: '<S361>/Add4' */
          rtb_a_g = (rtb_u_b - rtb_Add4_j4) + rtb_Saturation1_p5;

          /* Sum: '<S361>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_c;

          /* Sum: '<S361>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_c;

          /* Signum: '<S361>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S361>/Sign1' */

          /* Signum: '<S361>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S361>/Sign2' */

          /* Sum: '<S361>/Add5' incorporates:
           *  Gain: '<S361>/Gain2'
           *  Product: '<S361>/Multiply4'
           *  Sum: '<S361>/Subtract2'
           */
          rtb_Add4_j4 += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_a_g;

          /* Update for DiscreteIntegrator: '<S359>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S359>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S360>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S360>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S362>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S362>/Sign3' */

          /* Signum: '<S362>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S362>/Sign4' */

          /* Update for DiscreteIntegrator: '<S360>/Integrator' incorporates:
           *  Constant: '<S362>/const'
           *  Gain: '<S362>/Gain3'
           *  Product: '<S362>/Multiply5'
           *  Product: '<S362>/Multiply6'
           *  Sum: '<S362>/Subtract4'
           *  Sum: '<S362>/Subtract5'
           *  Sum: '<S362>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_c *
            ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4
            * 12.566371F) * 0.004F;

          /* Sum: '<S361>/Subtract3' */
          rtb_Saturation_ga = rtb_Add4_j4 - FMS_ConstB.d_c;

          /* Sum: '<S361>/Add6' */
          rtb_Saturation1_d = rtb_Add4_j4 + FMS_ConstB.d_c;

          /* Signum: '<S361>/Sign5' incorporates:
           *  Signum: '<S361>/Sign6'
           */
          if (rtb_Add4_j4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S361>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Add4_j4 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S361>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Add4_j4;

            /* Signum: '<S361>/Sign6' */
            rtb_Sign5_l = rtb_Add4_j4;
          }

          /* End of Signum: '<S361>/Sign5' */

          /* Signum: '<S361>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S361>/Sign3' */

          /* Signum: '<S361>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S361>/Sign4' */

          /* Update for DiscreteIntegrator: '<S359>/Integrator' incorporates:
           *  Constant: '<S361>/const'
           *  Gain: '<S361>/Gain3'
           *  Product: '<S361>/Divide'
           *  Product: '<S361>/Multiply5'
           *  Product: '<S361>/Multiply6'
           *  Sum: '<S361>/Subtract4'
           *  Sum: '<S361>/Subtract5'
           *  Sum: '<S361>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Add4_j4 / FMS_ConstB.d_c -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_h * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S330>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S330>/Position' incorporates:
             *  ActionPort: '<S337>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S330>/Switch Case' incorporates:
             *  Chart: '<S380>/Motion Status'
             *  Chart: '<S392>/Motion State'
             *  Chart: '<S405>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S330>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S330>/Position' incorporates:
           *  ActionPort: '<S337>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S380>/Motion Status' incorporates:
           *  Abs: '<S380>/Abs'
           *  Abs: '<S380>/Abs1'
           *  Constant: '<S389>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S389>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S379>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S379>/Hold Control' incorporates:
               *  ActionPort: '<S382>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S379>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S379>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S379>/Hold Control' incorporates:
             *  ActionPort: '<S382>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S379>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S379>/Brake Control' incorporates:
             *  ActionPort: '<S381>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S379>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S379>/Move Control' incorporates:
             *  ActionPort: '<S383>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S379>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S379>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S392>/Motion State' incorporates:
           *  Abs: '<S392>/Abs'
           *  Abs: '<S392>/Abs1'
           *  Constant: '<S402>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S402>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S405>/Logical Operator' incorporates:
           *  Abs: '<S405>/Abs1'
           *  Abs: '<S405>/Abs2'
           *  Constant: '<S417>/Constant'
           *  Constant: '<S418>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S417>/Compare'
           *  RelationalOperator: '<S418>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S405>/Motion State' */
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

          /* End of Chart: '<S405>/Motion State' */

          /* SwitchCase: '<S404>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S404>/Hold Control' incorporates:
               *  ActionPort: '<S406>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S404>/Switch Case' incorporates:
               *  Delay: '<S406>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S404>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S404>/Hold Control' incorporates:
             *  ActionPort: '<S406>/Action Port'
             */
            /* Delay: '<S406>/Delay' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            if (FMS_DW.icLoad != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Trigonometry: '<S410>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* Trigonometry: '<S410>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* SignalConversion: '<S410>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S410>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S410>/Gain' incorporates:
             *  Gain: '<S409>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S410>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S410>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* SignalConversion: '<S410>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S410>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* SignalConversion: '<S410>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S406>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S406>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S406>/Sum'
             */
            rtb_Add4_j4 = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            d = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S406>/Multiply' incorporates:
             *  SignalConversion: '<S406>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n +
                3] * d + rtb_VectorConcatenate[rtb_n] * rtb_Add4_j4;
            }

            /* End of Product: '<S406>/Multiply' */

            /* Gain: '<S406>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

            /* Update for Delay: '<S406>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S404>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S404>/Move Control' incorporates:
               *  ActionPort: '<S407>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S404>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S413>/Integrator'
               *  DiscreteIntegrator: '<S413>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S404>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S404>/Move Control' incorporates:
             *  ActionPort: '<S407>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S411>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S411>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S411>/Gain' */
            rtb_Saturation_o4 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S412>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S412>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S412>/Gain' */
            rtb_Saturation1_p5 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

            /* Sum: '<S414>/Sum of Elements' incorporates:
             *  Math: '<S414>/Square'
             *  SignalConversion: '<S414>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S415>/Sum of Elements'
             *  Switch: '<S407>/Switch'
             */
            rtb_u_b = rtb_Saturation_o4 * rtb_Saturation_o4 + rtb_Saturation1_p5
              * rtb_Saturation1_p5;

            /* Switch: '<S407>/Switch' incorporates:
             *  Product: '<S415>/Divide'
             *  Sqrt: '<S414>/Sqrt'
             *  Sum: '<S414>/Sum of Elements'
             */
            if (sqrtf(rtb_u_b) > 1.0F) {
              /* Math: '<S415>/Math Function1'
               *
               * About '<S415>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_u_b < 0.0F) {
                rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
              } else {
                rtb_Saturation_ga = sqrtf(rtb_u_b);
              }

              /* End of Math: '<S415>/Math Function1' */

              /* Switch: '<S415>/Switch' incorporates:
               *  Constant: '<S415>/Constant'
               *  Product: '<S415>/Product'
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

              /* End of Switch: '<S415>/Switch' */
              rtb_Saturation_o4 = rtb_TmpSignalConversionAtMultip[0] /
                rtb_TmpSignalConversionAtMultip[2];
              rtb_Saturation1_p5 = rtb_TmpSignalConversionAtMultip[1] /
                rtb_TmpSignalConversionAtMultip[2];
            }

            /* Product: '<S416>/Multiply1' incorporates:
             *  Constant: '<S416>/const1'
             *  DiscreteIntegrator: '<S413>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S416>/Add' incorporates:
             *  DiscreteIntegrator: '<S413>/Integrator1'
             *  Gain: '<S407>/Gain6'
             *  Sum: '<S413>/Subtract'
             */
            rtb_Add4_j4 = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM *
                           rtb_Saturation_o4) + rtb_Saturation1_d;

            /* Signum: '<S416>/Sign' */
            if (rtb_Add4_j4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Add4_j4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Add4_j4;
            }

            /* Sum: '<S416>/Add2' incorporates:
             *  Abs: '<S416>/Abs'
             *  Gain: '<S416>/Gain'
             *  Gain: '<S416>/Gain1'
             *  Product: '<S416>/Multiply2'
             *  Product: '<S416>/Multiply3'
             *  Sqrt: '<S416>/Sqrt'
             *  Sum: '<S416>/Add1'
             *  Sum: '<S416>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Add4_j4) + FMS_ConstB.d)
              * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Saturation_ga +
              rtb_Saturation1_d;

            /* Sum: '<S416>/Add4' */
            rtb_Saturation1_d += rtb_Add4_j4 - rtb_Saturation_o4;

            /* Sum: '<S416>/Add3' */
            rtb_Saturation_ga = rtb_Add4_j4 + FMS_ConstB.d;

            /* Sum: '<S416>/Subtract1' */
            rtb_Add4_j4 -= FMS_ConstB.d;

            /* Signum: '<S416>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S416>/Sign2' */
            if (rtb_Add4_j4 < 0.0F) {
              rtb_Add4_j4 = -1.0F;
            } else {
              if (rtb_Add4_j4 > 0.0F) {
                rtb_Add4_j4 = 1.0F;
              }
            }

            /* Sum: '<S416>/Add5' incorporates:
             *  Gain: '<S416>/Gain2'
             *  Product: '<S416>/Multiply4'
             *  Sum: '<S416>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Add4_j4) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S413>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S413>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S413>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S413>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S416>/Sign4' incorporates:
             *  Sum: '<S416>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S416>/Sign3' incorporates:
             *  Sum: '<S416>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S416>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S416>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S416>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S416>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Sign5_l = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S413>/Integrator' incorporates:
             *  Constant: '<S416>/const'
             *  Gain: '<S416>/Gain3'
             *  Product: '<S416>/Divide'
             *  Product: '<S416>/Multiply5'
             *  Product: '<S416>/Multiply6'
             *  Sum: '<S416>/Subtract4'
             *  Sum: '<S416>/Subtract5'
             *  Sum: '<S416>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 39.224F) * 0.004F;

            /* Product: '<S416>/Multiply1' incorporates:
             *  Constant: '<S416>/const1'
             *  DiscreteIntegrator: '<S413>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S416>/Add' incorporates:
             *  DiscreteIntegrator: '<S413>/Integrator1'
             *  Gain: '<S407>/Gain6'
             *  Sum: '<S413>/Subtract'
             */
            rtb_Add4_j4 = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                           rtb_Saturation1_p5) + rtb_Saturation1_d;

            /* Signum: '<S416>/Sign' */
            if (rtb_Add4_j4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Add4_j4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Add4_j4;
            }

            /* Sum: '<S416>/Add2' incorporates:
             *  Abs: '<S416>/Abs'
             *  Gain: '<S416>/Gain'
             *  Gain: '<S416>/Gain1'
             *  Product: '<S416>/Multiply2'
             *  Product: '<S416>/Multiply3'
             *  Sqrt: '<S416>/Sqrt'
             *  Sum: '<S416>/Add1'
             *  Sum: '<S416>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Add4_j4) + FMS_ConstB.d)
              * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Saturation_ga +
              rtb_Saturation1_d;

            /* Sum: '<S416>/Add4' */
            rtb_Saturation1_d += rtb_Add4_j4 - rtb_Saturation_o4;

            /* Sum: '<S416>/Add3' */
            rtb_Saturation_ga = rtb_Add4_j4 + FMS_ConstB.d;

            /* Sum: '<S416>/Subtract1' */
            rtb_Add4_j4 -= FMS_ConstB.d;

            /* Signum: '<S416>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S416>/Sign2' */
            if (rtb_Add4_j4 < 0.0F) {
              rtb_Add4_j4 = -1.0F;
            } else {
              if (rtb_Add4_j4 > 0.0F) {
                rtb_Add4_j4 = 1.0F;
              }
            }

            /* Sum: '<S416>/Add5' incorporates:
             *  Gain: '<S416>/Gain2'
             *  Product: '<S416>/Multiply4'
             *  Sum: '<S416>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Add4_j4) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S413>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S413>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S413>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S413>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S416>/Sign4' incorporates:
             *  Sum: '<S416>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S416>/Sign3' incorporates:
             *  Sum: '<S416>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S416>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S416>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S416>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S416>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Sign5_l = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S413>/Integrator' incorporates:
             *  Constant: '<S416>/const'
             *  Gain: '<S416>/Gain3'
             *  Product: '<S416>/Divide'
             *  Product: '<S416>/Multiply5'
             *  Product: '<S416>/Multiply6'
             *  Sum: '<S416>/Subtract4'
             *  Sum: '<S416>/Subtract5'
             *  Sum: '<S416>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Sign5_l * 39.224F) * 0.004F;

            /* End of Outputs for SubSystem: '<S404>/Move Control' */
            break;
          }

          /* SwitchCase: '<S391>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S391>/Hold Control' incorporates:
               *  ActionPort: '<S394>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S391>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S391>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S391>/Hold Control' incorporates:
             *  ActionPort: '<S394>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S391>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S391>/Brake Control' incorporates:
             *  ActionPort: '<S393>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S391>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S391>/Move Control' incorporates:
               *  ActionPort: '<S395>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S391>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S391>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S391>/Move Control' incorporates:
             *  ActionPort: '<S395>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S391>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S391>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S337>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S337>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S337>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S391>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S391>/Saturation' */

          /* Saturate: '<S404>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S404>/Saturation1' */

          /* Saturate: '<S379>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S379>/Saturation1' */
          /* End of Outputs for SubSystem: '<S330>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S330>/Unknown' incorporates:
           *  ActionPort: '<S339>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S330>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S50>/Manual' incorporates:
         *  ActionPort: '<S332>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S332>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S332>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S332>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S332>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S50>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S50>/Unknown' incorporates:
         *  ActionPort: '<S334>/Action Port'
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
   *  DiscreteIntegrator: '<S775>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S775>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S775>/Constant'
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
  /* Start for SwitchCase: '<S122>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S49>/SubMode' */

  /* Start for IfAction SubSystem: '<S49>/Auto' */
  /* Start for SwitchCase: '<S120>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;

  /* End of Start for SubSystem: '<S49>/Auto' */

  /* Start for IfAction SubSystem: '<S49>/Assist' */
  /* Start for SwitchCase: '<S119>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S119>/Altitude' */
  /* Start for SwitchCase: '<S132>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;

  /* End of Start for SubSystem: '<S119>/Altitude' */

  /* Start for IfAction SubSystem: '<S119>/Position' */
  /* Start for SwitchCase: '<S169>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S155>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S119>/Position' */
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
  /* Start for SwitchCase: '<S333>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S333>/Return' */
  /* Start for SwitchCase: '<S733>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S723>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S333>/Return' */

  /* Start for IfAction SubSystem: '<S333>/Hold' */
  /* Start for SwitchCase: '<S672>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S640>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S651>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S333>/Hold' */
  /* End of Start for SubSystem: '<S50>/SubMode' */

  /* Start for IfAction SubSystem: '<S50>/Auto' */
  /* Start for SwitchCase: '<S331>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S331>/Mission' */
  /* Start for Resettable SubSystem: '<S442>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S493>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S483>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S442>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S331>/Mission' */
  /* End of Start for SubSystem: '<S50>/Auto' */

  /* Start for IfAction SubSystem: '<S50>/Assist' */
  /* Start for SwitchCase: '<S330>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S330>/Stabilize' */
  /* Start for SwitchCase: '<S429>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S330>/Stabilize' */

  /* Start for IfAction SubSystem: '<S330>/Altitude' */
  /* Start for SwitchCase: '<S345>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S363>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S330>/Altitude' */

  /* Start for IfAction SubSystem: '<S330>/Position' */
  /* Start for SwitchCase: '<S379>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S404>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S391>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S330>/Position' */
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
  /* SystemInitialize for IfAction SubSystem: '<S122>/Hold' */
  /* InitializeConditions for Delay: '<S273>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S268>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S122>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S49>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S120>/Mission' */
  /* InitializeConditions for UnitDelay: '<S234>/Delay Input1'
   *
   * Block description for '<S234>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S120>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S49>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S119>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S224>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S224>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S225>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S229>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S229>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S225>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S119>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S119>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S147>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mg = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
  FMS_DW.Integrator_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S147>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* SystemInitialize for Chart: '<S133>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S132>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S132>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S132>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S132>/Move Control' */

  /* SystemInitialize for Merge: '<S132>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S119>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S119>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S156>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S170>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S169>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_b, &FMS_DW.HoldControl_b);

  /* End of SystemInitialize for SubSystem: '<S169>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S169>/Move Control' */
  FMS_MoveControl_d_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S169>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S155>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S155>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S155>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S155>/Move Control' */

  /* SystemInitialize for Merge: '<S155>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S169>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S119>/Position' */
  /* End of SystemInitialize for SubSystem: '<S49>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S44>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/BackwardTrans_Mode' */
  /* SystemInitialize for Chart: '<S55>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for IfAction SubSystem: '<S54>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_p, &FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S54>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S54>/Move Control' */
  FMS_MoveControl_d_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S54>/Move Control' */

  /* SystemInitialize for Merge: '<S54>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S44>/BackwardTrans_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S50>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S333>/Takeoff' */
  /* InitializeConditions for Delay: '<S773>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S769>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S769>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S333>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S333>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S688>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S688>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S333>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S333>/Return' */
  /* InitializeConditions for Delay: '<S718>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S719>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S714>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S760>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S697>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S700>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S700>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S734>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S733>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S733>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S733>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S733>/Move Control' */

  /* SystemInitialize for Merge: '<S733>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S724>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S723>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S723>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S723>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_cg);

  /* End of SystemInitialize for SubSystem: '<S723>/Move Control' */

  /* SystemInitialize for Merge: '<S723>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S333>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S333>/Hold' */
  /* InitializeConditions for Delay: '<S653>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S665>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S665>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S641>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S652>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S673>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S672>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S672>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S672>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S672>/Move Control' */

  /* SystemInitialize for Merge: '<S672>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S640>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S640>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S640>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S640>/Move Control' */

  /* SystemInitialize for Merge: '<S640>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S651>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S651>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S651>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S651>/Move Control' */

  /* SystemInitialize for Merge: '<S651>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S333>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S50>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S331>/Mission' */
  /* InitializeConditions for UnitDelay: '<S445>/Delay Input1'
   *
   * Block description for '<S445>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S442>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S472>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S468>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S520>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S450>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S494>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S493>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S493>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S493>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S503>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S503>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S493>/Move Control' */

  /* SystemInitialize for Merge: '<S493>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S493>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S503>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S503>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S493>/Move Control' */

  /* SystemInitialize for Merge: '<S493>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S484>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S483>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S483>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S483>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S490>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S490>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S483>/Move Control' */

  /* SystemInitialize for Merge: '<S483>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S442>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S331>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S50>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S330>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S425>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S426>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S426>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S425>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S430>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S429>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S429>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S429>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S429>/Move Control' */

  /* SystemInitialize for Merge: '<S429>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S330>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S330>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S359>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S360>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S360>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S359>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S346>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S345>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S345>/Hold Control' */

  /* SystemInitialize for Merge: '<S345>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S364>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S363>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_pi);

  /* End of SystemInitialize for SubSystem: '<S363>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S363>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S363>/Move Control' */

  /* SystemInitialize for Merge: '<S363>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S330>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S330>/Position' */
  /* SystemInitialize for Chart: '<S380>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S379>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S379>/Hold Control' */

  /* SystemInitialize for Chart: '<S392>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S405>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S404>/Hold Control' */
  /* InitializeConditions for Delay: '<S406>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S404>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S404>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S413>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S413>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S404>/Move Control' */

  /* SystemInitialize for Merge: '<S404>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S404>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S413>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S413>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S404>/Move Control' */

  /* SystemInitialize for Merge: '<S404>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S379>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S391>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S391>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S391>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S391>/Move Control' */

  /* SystemInitialize for Merge: '<S391>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S330>/Position' */
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
