/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2570
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 23 16:28:48 2025
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

/* Named constants for Chart: '<S182>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<S744>/Motion Status' */
#define FMS_IN_Brake_bq                ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S754>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_ol                 ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S450>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S672>/Motion State' */
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
                                        *   '<S796>/Constant1'
                                        *   '<S797>/Constant'
                                        *   '<S799>/Constant1'
                                        *   '<S800>/FW_ACCEPT_R'
                                        *   '<S800>/MC_ACCEPT_R'
                                        *   '<S803>/Constant'
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
                                        *   '<S279>/Dead Zone'
                                        *   '<S279>/Gain'
                                        *   '<S280>/Dead Zone'
                                        *   '<S280>/Gain'
                                        *   '<S281>/Dead Zone'
                                        *   '<S281>/Gain'
                                        *   '<S282>/Dead Zone'
                                        *   '<S282>/Gain'
                                        *   '<S285>/Constant4'
                                        *   '<S286>/Constant4'
                                        *   '<S654>/L1'
                                        *   '<S57>/L1'
                                        *   '<S58>/Gain6'
                                        *   '<S96>/Constant'
                                        *   '<S97>/Constant'
                                        *   '<S135>/Gain'
                                        *   '<S136>/Gain1'
                                        *   '<S137>/Saturation1'
                                        *   '<S163>/Gain1'
                                        *   '<S165>/Saturation1'
                                        *   '<S234>/Gain'
                                        *   '<S234>/Gain1'
                                        *   '<S235>/Gain1'
                                        *   '<S288>/Gain2'
                                        *   '<S288>/Saturation1'
                                        *   '<S289>/L1'
                                        *   '<S289>/R'
                                        *   '<S289>/Saturation1'
                                        *   '<S306>/Gain'
                                        *   '<S306>/Saturation1'
                                        *   '<S328>/Gain'
                                        *   '<S328>/Saturation1'
                                        *   '<S363>/Gain'
                                        *   '<S363>/Gain1'
                                        *   '<S440>/Gain'
                                        *   '<S440>/Gain1'
                                        *   '<S442>/Constant'
                                        *   '<S466>/L1'
                                        *   '<S547>/Saturation'
                                        *   '<S548>/Saturation1'
                                        *   '<S548>/Saturation2'
                                        *   '<S548>/Saturation3'
                                        *   '<S705>/Land_Speed'
                                        *   '<S706>/Saturation1'
                                        *   '<S785>/Takeoff_Speed'
                                        *   '<S786>/Gain2'
                                        *   '<S786>/Saturation1'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        *   '<S138>/Saturation1'
                                        *   '<S150>/Dead Zone'
                                        *   '<S150>/Gain'
                                        *   '<S153>/Dead Zone'
                                        *   '<S153>/Gain'
                                        *   '<S157>/Constant'
                                        *   '<S157>/Constant1'
                                        *   '<S157>/Constant2'
                                        *   '<S166>/Saturation1'
                                        *   '<S178>/Dead Zone'
                                        *   '<S178>/Gain'
                                        *   '<S181>/Saturation1'
                                        *   '<S230>/Constant'
                                        *   '<S230>/Constant1'
                                        *   '<S230>/Constant2'
                                        *   '<S237>/Dead Zone'
                                        *   '<S237>/Gain'
                                        *   '<S238>/Dead Zone'
                                        *   '<S238>/Gain'
                                        *   '<S243>/Dead Zone'
                                        *   '<S243>/Gain'
                                        *   '<S251>/Gain'
                                        *   '<S251>/Saturation1'
                                        *   '<S252>/Constant4'
                                        *   '<S252>/Saturation'
                                        *   '<S311>/L1'
                                        *   '<S311>/Saturation1'
                                        *   '<S333>/L1'
                                        *   '<S333>/Saturation1'
                                        *   '<S365>/Saturation1'
                                        *   '<S377>/Dead Zone'
                                        *   '<S377>/Gain'
                                        *   '<S378>/Dead Zone'
                                        *   '<S378>/Gain'
                                        *   '<S383>/Saturation'
                                        *   '<S399>/Saturation1'
                                        *   '<S411>/Saturation'
                                        *   '<S424>/Saturation1'
                                        *   '<S443>/Dead Zone'
                                        *   '<S443>/Gain'
                                        *   '<S444>/Dead Zone'
                                        *   '<S444>/Gain'
                                        *   '<S449>/Saturation'
                                        *   '<S603>/Gain2'
                                        *   '<S610>/Gain1'
                                        *   '<S610>/Gain2'
                                        *   '<S660>/Saturation1'
                                        *   '<S671>/Saturation'
                                        *   '<S692>/Saturation1'
                                        *   '<S707>/Constant'
                                        *   '<S710>/Gain2'
                                        *   '<S734>/Constant'
                                        *   '<S734>/vel'
                                        *   '<S734>/Acceleration_Speed'
                                        *   '<S734>/Saturation'
                                        *   '<S734>/Switch'
                                        *   '<S738>/Constant'
                                        *   '<S140>/Gain2'
                                        *   '<S141>/Gain1'
                                        *   '<S148>/Constant'
                                        *   '<S168>/Gain2'
                                        *   '<S169>/Gain1'
                                        *   '<S176>/Constant'
                                        *   '<S184>/L1'
                                        *   '<S185>/Gain6'
                                        *   '<S223>/Constant'
                                        *   '<S224>/Constant'
                                        *   '<S262>/L1'
                                        *   '<S262>/Saturation1'
                                        *   '<S368>/Gain2'
                                        *   '<S369>/Gain1'
                                        *   '<S375>/Constant'
                                        *   '<S386>/Gain2'
                                        *   '<S387>/Gain1'
                                        *   '<S394>/Constant'
                                        *   '<S402>/Gain2'
                                        *   '<S403>/Gain1'
                                        *   '<S409>/Constant'
                                        *   '<S414>/Gain2'
                                        *   '<S415>/Gain1'
                                        *   '<S422>/Constant'
                                        *   '<S426>/Gain2'
                                        *   '<S427>/Gain6'
                                        *   '<S437>/Constant'
                                        *   '<S438>/Constant'
                                        *   '<S452>/Gain2'
                                        *   '<S453>/Gain1'
                                        *   '<S460>/Constant'
                                        *   '<S485>/Gain'
                                        *   '<S485>/Saturation1'
                                        *   '<S488>/Constant'
                                        *   '<S488>/vel'
                                        *   '<S488>/Switch'
                                        *   '<S663>/Gain2'
                                        *   '<S664>/Gain1'
                                        *   '<S675>/Gain2'
                                        *   '<S676>/Gain1'
                                        *   '<S684>/Gain2'
                                        *   '<S684>/Saturation'
                                        *   '<S685>/Integrator'
                                        *   '<S695>/Gain2'
                                        *   '<S696>/Gain6'
                                        *   '<S719>/Gain2'
                                        *   '<S719>/Saturation'
                                        *   '<S720>/Integrator'
                                        *   '<S144>/Dead Zone'
                                        *   '<S144>/Gain'
                                        *   '<S172>/Dead Zone'
                                        *   '<S172>/Gain'
                                        *   '<S220>/Dead Zone'
                                        *   '<S220>/Gain'
                                        *   '<S371>/Land_Speed'
                                        *   '<S372>/Constant'
                                        *   '<S374>/Dead Zone'
                                        *   '<S374>/Gain'
                                        *   '<S391>/Dead Zone'
                                        *   '<S391>/Gain'
                                        *   '<S405>/Land_Speed'
                                        *   '<S406>/Constant'
                                        *   '<S408>/Dead Zone'
                                        *   '<S408>/Gain'
                                        *   '<S419>/Dead Zone'
                                        *   '<S419>/Gain'
                                        *   '<S431>/Dead Zone'
                                        *   '<S431>/Gain'
                                        *   '<S432>/Dead Zone'
                                        *   '<S432>/Gain'
                                        *   '<S457>/Dead Zone'
                                        *   '<S457>/Gain'
                                        *   '<S472>/Gain2'
                                        *   '<S472>/Saturation'
                                        *   '<S473>/Integrator'
                                        *   '<S666>/Dead Zone'
                                        *   '<S666>/Gain'
                                        *   '<S680>/Dead Zone'
                                        *   '<S680>/Gain'
                                        *   '<S700>/Dead Zone'
                                        *   '<S700>/Gain'
                                        *   '<S701>/Dead Zone'
                                        *   '<S701>/Gain'
                                        *   '<S743>/Saturation1'
                                        *   '<S753>/Saturation1'
                                        *   '<S503>/Saturation1'
                                        *   '<S513>/Saturation1'
                                        *   '<S746>/Gain2'
                                        *   '<S747>/Gain1'
                                        *   '<S756>/Gain2'
                                        *   '<S757>/Gain6'
                                        *   '<S506>/Gain2'
                                        *   '<S507>/Gain1'
                                        *   '<S516>/Gain2'
                                        *   '<S517>/Gain6'
                                        *   '<S749>/Dead Zone'
                                        *   '<S749>/Gain'
                                        *   '<S761>/Dead Zone'
                                        *   '<S761>/Gain'
                                        *   '<S762>/Dead Zone'
                                        *   '<S762>/Gain'
                                        *   '<S509>/Dead Zone'
                                        *   '<S509>/Gain'
                                        *   '<S521>/Dead Zone'
                                        *   '<S521>/Gain'
                                        *   '<S522>/Dead Zone'
                                        *   '<S522>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S26>/Constant1'
                                        *   '<S795>/Constant'
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
 *    '<S335>/NearbyRefWP'
 *    '<S313>/NearbyRefWP'
 *    '<S264>/NearbyRefWP'
 *    '<S736>/NearbyRefWP'
 *    '<S490>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S339>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S335>/SearchL1RefWP'
 *    '<S313>/SearchL1RefWP'
 *    '<S264>/SearchL1RefWP'
 *    '<S736>/SearchL1RefWP'
 *    '<S490>/SearchL1RefWP'
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

  /* SignalConversion: '<S341>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S313>/OutRegionRegWP'
 *    '<S264>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S318>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S353>/Unknown'
 *    '<S351>/Unknown'
 *    '<S350>/Unknown'
 *    '<S50>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S287>/Bus Assignment' incorporates:
   *  Constant: '<S287>/Constant'
   *  Constant: '<S287>/Constant2'
   *  SignalConversion: '<S287>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S287>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S138>/Hold Control'
 *    '<S166>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S140>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S138>/Hold Control'
 *    '<S166>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S140>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S138>/Hold Control'
 *    '<S166>/Hold Control'
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
 *    '<S166>/Move Control'
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
 *    '<S166>/Move Control'
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
 *    '<S166>/Move Control'
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
 *    '<S167>/Motion Status'
 *    '<S366>/Motion Status'
 *    '<S400>/Motion Status'
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
 *    '<S167>/Motion Status'
 *    '<S366>/Motion Status'
 *    '<S400>/Motion Status'
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
 *    '<S167>/Motion Status'
 *    '<S366>/Motion Status'
 *    '<S400>/Motion Status'
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
 *    '<S181>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_l_Init(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S189>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S189>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S219>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System reset for action system:
 *    '<S181>/Hold Control'
 *    '<S54>/Hold Control'
 */
void FMS_HoldControl_g_Reset(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S189>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S189>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S219>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S181>/Hold Control'
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

  /* Sqrt: '<S196>/Sqrt' incorporates:
   *  Math: '<S196>/Square'
   *  Sum: '<S196>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_ex = sqrtf(((rtu_FMS_In[0] * rtu_FMS_In[0] +
    rtu_FMS_In[1] * rtu_FMS_In[1]) + rtu_FMS_In[2] * rtu_FMS_In[2]) +
    rtu_FMS_In[3] * rtu_FMS_In[3]);

  /* Product: '<S192>/Divide' */
  rtb_Square_kg_idx_0 = rtu_FMS_In[0] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_1 = rtu_FMS_In[1] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_2 = rtu_FMS_In[2] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_DiscreteTimeIntegrator1_ex = rtu_FMS_In[3] /
    rtb_DiscreteTimeIntegrator1_ex;

  /* Math: '<S193>/Square' incorporates:
   *  Math: '<S194>/Square'
   *  Math: '<S195>/Square'
   */
  rtb_Sign_hw = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_0;

  /* Math: '<S193>/Square2' incorporates:
   *  Math: '<S194>/Square2'
   *  Math: '<S195>/Square2'
   */
  rtb_Switch_fz_idx_1 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2;

  /* Math: '<S193>/Square1' incorporates:
   *  Math: '<S194>/Square1'
   *  Math: '<S195>/Square1'
   */
  D = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1;

  /* Math: '<S193>/Square3' incorporates:
   *  Math: '<S194>/Square3'
   *  Math: '<S195>/Square3'
   */
  absxk = rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex;

  /* Sum: '<S193>/Subtract' incorporates:
   *  Math: '<S193>/Square'
   *  Math: '<S193>/Square1'
   *  Math: '<S193>/Square2'
   *  Math: '<S193>/Square3'
   *  Sum: '<S193>/Add'
   *  Sum: '<S193>/Add1'
   */
  rtb_VectorConcatenate_l[0] = (rtb_Sign_hw + D) - (rtb_Switch_fz_idx_1 + absxk);

  /* Product: '<S193>/Multiply' incorporates:
   *  Product: '<S194>/Multiply'
   */
  b_t = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_2;

  /* Product: '<S193>/Multiply1' incorporates:
   *  Product: '<S194>/Multiply1'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_DiscreteTimeIntegrator1_ex;

  /* Gain: '<S193>/Gain' incorporates:
   *  Product: '<S193>/Multiply'
   *  Product: '<S193>/Multiply1'
   *  Sum: '<S193>/Subtract1'
   */
  rtb_VectorConcatenate_l[1] = (b_t - d1) * 2.0F;

  /* Product: '<S193>/Multiply2' incorporates:
   *  Product: '<S195>/Multiply'
   */
  rtb_VectorConcatenate_fy_tmp = rtb_Square_kg_idx_1 *
    rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S193>/Multiply3' incorporates:
   *  Product: '<S195>/Multiply1'
   */
  rtb_VectorConcatenate_fy_tmp_0 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_2;

  /* Gain: '<S193>/Gain1' incorporates:
   *  Product: '<S193>/Multiply2'
   *  Product: '<S193>/Multiply3'
   *  Sum: '<S193>/Add2'
   */
  rtb_VectorConcatenate_l[2] = (rtb_VectorConcatenate_fy_tmp +
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S194>/Gain' incorporates:
   *  Sum: '<S194>/Add3'
   */
  rtb_VectorConcatenate_l[3] = (b_t + d1) * 2.0F;

  /* Sum: '<S194>/Subtract' incorporates:
   *  Sum: '<S194>/Add'
   *  Sum: '<S194>/Add1'
   */
  rtb_VectorConcatenate_l[4] = (rtb_Sign_hw + rtb_Switch_fz_idx_1) - (D + absxk);

  /* Product: '<S194>/Multiply2' incorporates:
   *  Product: '<S195>/Multiply2'
   */
  b_t = rtb_Square_kg_idx_2 * rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S194>/Multiply3' incorporates:
   *  Product: '<S195>/Multiply3'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_1;

  /* Gain: '<S194>/Gain1' incorporates:
   *  Product: '<S194>/Multiply2'
   *  Product: '<S194>/Multiply3'
   *  Sum: '<S194>/Subtract1'
   */
  rtb_VectorConcatenate_l[5] = (b_t - d1) * 2.0F;

  /* Gain: '<S195>/Gain' incorporates:
   *  Sum: '<S195>/Subtract2'
   */
  rtb_VectorConcatenate_l[6] = (rtb_VectorConcatenate_fy_tmp -
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S195>/Gain1' incorporates:
   *  Sum: '<S195>/Add2'
   */
  rtb_VectorConcatenate_l[7] = (b_t + d1) * 2.0F;

  /* Sum: '<S195>/Subtract' incorporates:
   *  Sum: '<S195>/Add'
   *  Sum: '<S195>/Add1'
   */
  rtb_VectorConcatenate_l[8] = (rtb_Sign_hw + absxk) - (D + rtb_Switch_fz_idx_1);

  /* Product: '<S186>/Multiply' incorporates:
   *  SignalConversion: '<S186>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_ppg[i] = rtb_VectorConcatenate_l[i + 6] * rtu_FMS_In_g +
      (rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h + rtb_VectorConcatenate_l[i]
       * rtu_FMS_In_c);
  }

  /* End of Product: '<S186>/Multiply' */

  /* Trigonometry: '<S215>/Trigonometric Function1' incorporates:
   *  Gain: '<S214>/Gain'
   *  Trigonometry: '<S215>/Trigonometric Function3'
   */
  rtb_Sign_hw = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[0] = rtb_Sign_hw;

  /* Trigonometry: '<S215>/Trigonometric Function' incorporates:
   *  Gain: '<S214>/Gain'
   *  Trigonometry: '<S215>/Trigonometric Function2'
   */
  rtb_Switch_fz_idx_1 = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[1] = rtb_Switch_fz_idx_1;

  /* SignalConversion: '<S215>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S215>/Constant3'
   */
  rtb_VectorConcatenate_l[2] = 0.0F;

  /* Gain: '<S215>/Gain' */
  rtb_VectorConcatenate_l[3] = -rtb_Switch_fz_idx_1;

  /* Trigonometry: '<S215>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_Sign_hw;

  /* SignalConversion: '<S215>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S215>/Constant4'
   */
  rtb_VectorConcatenate_l[5] = 0.0F;

  /* SignalConversion: '<S215>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_l[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_l[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_l[8] = localC->VectorConcatenate3[2];

  /* Delay: '<S189>/start_vel' incorporates:
   *  SignalConversion: '<S202>/TmpSignal ConversionAtSquareInport1'
   */
  if (localDW->icLoad != 0) {
    localDW->start_vel_DSTATE[0] = rtu_FMS_In_c;
    localDW->start_vel_DSTATE[1] = rtu_FMS_In_h;
  }

  /* Sum: '<S210>/Sum of Elements' incorporates:
   *  Delay: '<S189>/start_vel'
   *  Math: '<S210>/Math Function'
   */
  rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[0] * localDW->
    start_vel_DSTATE[0] + localDW->start_vel_DSTATE[1] *
    localDW->start_vel_DSTATE[1];

  /* Math: '<S210>/Math Function1' incorporates:
   *  Sum: '<S210>/Sum of Elements'
   *
   * About '<S210>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_fz_idx_1 < 0.0F) {
    rtb_Sign_hw = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
  } else {
    rtb_Sign_hw = sqrtf(rtb_Switch_fz_idx_1);
  }

  /* End of Math: '<S210>/Math Function1' */

  /* Switch: '<S210>/Switch' incorporates:
   *  Constant: '<S210>/Constant'
   *  Delay: '<S189>/start_vel'
   *  Product: '<S210>/Product'
   */
  if (rtb_Sign_hw > 0.0F) {
    rtb_Square_kg_idx_2 = localDW->start_vel_DSTATE[0];
    rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[1];
  } else {
    rtb_Square_kg_idx_2 = 0.0F;
    rtb_Switch_fz_idx_1 = 0.0F;
    rtb_Sign_hw = 1.0F;
  }

  /* End of Switch: '<S210>/Switch' */

  /* Delay: '<S189>/start_wp' incorporates:
   *  SignalConversion: '<S189>/TmpSignal ConversionAtstart_wpInport2'
   */
  if (localDW->icLoad_e != 0) {
    localDW->start_wp_DSTATE[0] = rtu_FMS_In_l;
    localDW->start_wp_DSTATE[1] = rtu_FMS_In_m;
  }

  /* MATLAB Function: '<S187>/SearchL1RefWP' incorporates:
   *  Delay: '<S189>/start_wp'
   *  SignalConversion: '<S199>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_Square_kg_idx_0 = localDW->start_wp_DSTATE[0] - rtu_FMS_In_l;
  rtb_Square_kg_idx_1 = localDW->start_wp_DSTATE[1] - rtu_FMS_In_m;

  /* Product: '<S210>/Divide' */
  rtb_Square_kg_idx_2 /= rtb_Sign_hw;

  /* MATLAB Function: '<S187>/SearchL1RefWP' */
  D = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_0;

  /* Product: '<S210>/Divide' */
  rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_2;
  rtb_Square_kg_idx_2 = rtb_Switch_fz_idx_1 / rtb_Sign_hw;

  /* MATLAB Function: '<S187>/SearchL1RefWP' incorporates:
   *  Constant: '<S184>/L1'
   *  Delay: '<S189>/start_wp'
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

  /* MATLAB Function: '<S187>/OutRegionRefWP' incorporates:
   *  Delay: '<S189>/start_wp'
   *  SignalConversion: '<S189>/TmpSignal ConversionAtstart_wpInport2'
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

  /* Product: '<S213>/Multiply' incorporates:
   *  SignalConversion: '<S213>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_fy[i] = rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h
      + rtb_VectorConcatenate_l[i] * rtu_FMS_In_c;
  }

  /* End of Product: '<S213>/Multiply' */

  /* DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
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

  /* DiscreteIntegrator: '<S219>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S211>/Constant'
   *  Sum: '<S211>/Sum'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  if (localDW->DiscreteTimeIntegrator1_PrevRes != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  /* Signum: '<S186>/Sign' */
  if (rtb_Multiply_ppg[0] < 0.0F) {
    rtb_Switch_fz_idx_1 = -1.0F;
  } else if (rtb_Multiply_ppg[0] > 0.0F) {
    rtb_Switch_fz_idx_1 = 1.0F;
  } else {
    rtb_Switch_fz_idx_1 = rtb_Multiply_ppg[0];
  }

  /* End of Signum: '<S186>/Sign' */

  /* Switch: '<S184>/Switch' incorporates:
   *  Constant: '<S184>/L1'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S211>/Constant'
   *  Constant: '<S218>/kp'
   *  DiscreteIntegrator: '<S217>/Discrete-Time Integrator'
   *  Gain: '<S200>/Gain'
   *  Math: '<S200>/Square'
   *  Math: '<S203>/Square'
   *  Math: '<S205>/Math Function'
   *  MinMax: '<S200>/Max'
   *  MinMax: '<S200>/Min'
   *  Product: '<S200>/Divide'
   *  Product: '<S200>/Multiply1'
   *  Product: '<S218>/Multiply'
   *  Sqrt: '<S203>/Sqrt'
   *  Sum: '<S188>/Subtract'
   *  Sum: '<S203>/Sum of Elements'
   *  Sum: '<S211>/Sum'
   *  Sum: '<S212>/Add'
   */
  if (rtb_Switch_fz_idx_1 > 0.0F) {
    /* Sum: '<S204>/Sum of Elements' incorporates:
     *  Math: '<S204>/Math Function'
     *  SignalConversion: '<S202>/TmpSignal ConversionAtSquareInport1'
     *  Sum: '<S202>/Sum of Elements'
     */
    rtb_Switch_fz_idx_1 = rtu_FMS_In_c * rtu_FMS_In_c + rtu_FMS_In_h *
      rtu_FMS_In_h;

    /* Math: '<S204>/Math Function1' incorporates:
     *  Sum: '<S204>/Sum of Elements'
     *
     * About '<S204>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Switch_fz_idx_1 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
    } else {
      d1 = sqrtf(rtb_Switch_fz_idx_1);
    }

    /* End of Math: '<S204>/Math Function1' */

    /* Switch: '<S204>/Switch' incorporates:
     *  Constant: '<S204>/Constant'
     *  Product: '<S204>/Product'
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

    /* End of Switch: '<S204>/Switch' */

    /* Product: '<S204>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* RelationalOperator: '<S197>/Compare' incorporates:
     *  Constant: '<S197>/Constant'
     *  MATLAB Function: '<S187>/SearchL1RefWP'
     */
    rtb_Compare_dd1 = (rtb_Sign_hw > 0.0F);

    /* Switch: '<S187>/Switch' incorporates:
     *  Delay: '<S189>/start_wp'
     *  MATLAB Function: '<S187>/OutRegionRefWP'
     */
    if (!rtb_Compare_dd1) {
      rtb_Square_kg_idx_0 = b_t * rtb_DiscreteTimeIntegrator1_ex +
        localDW->start_wp_DSTATE[0];
      rtb_Square_kg_idx_1 = b_t * rtb_Square_kg_idx_2 + localDW->
        start_wp_DSTATE[1];
    }

    /* End of Switch: '<S187>/Switch' */

    /* Sum: '<S188>/Subtract' incorporates:
     *  SignalConversion: '<S189>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_0 - rtu_FMS_In_l;
    rtb_Square_kg_idx_0 = rtb_DiscreteTimeIntegrator1_ex;
    rtb_Sign_hw = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex;

    /* Sum: '<S188>/Subtract' incorporates:
     *  Math: '<S205>/Math Function'
     *  SignalConversion: '<S189>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_1 - rtu_FMS_In_m;

    /* Sum: '<S205>/Sum of Elements' incorporates:
     *  Math: '<S205>/Math Function'
     */
    rtb_Square_kg_idx_2 = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex + rtb_Sign_hw;

    /* Math: '<S205>/Math Function1' incorporates:
     *  Sum: '<S205>/Sum of Elements'
     *
     * About '<S205>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S205>/Math Function1' */

    /* Switch: '<S205>/Switch' incorporates:
     *  Constant: '<S205>/Constant'
     *  Product: '<S205>/Product'
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

    /* End of Switch: '<S205>/Switch' */

    /* Product: '<S205>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_0 *= rtb_Square_kg_idx_0;

    /* Product: '<S205>/Divide' incorporates:
     *  Math: '<S203>/Square'
     */
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S207>/Sum of Elements' incorporates:
     *  Math: '<S207>/Math Function'
     *  SignalConversion: '<S207>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = absxk * absxk + D * D;

    /* Math: '<S207>/Math Function1' incorporates:
     *  Sum: '<S207>/Sum of Elements'
     *
     * About '<S207>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S207>/Math Function1' */

    /* Switch: '<S207>/Switch' incorporates:
     *  Constant: '<S207>/Constant'
     *  Product: '<S207>/Product'
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

    /* End of Switch: '<S207>/Switch' */

    /* Product: '<S207>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S208>/Sum of Elements' incorporates:
     *  Math: '<S208>/Math Function'
     *  SignalConversion: '<S208>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1 +
      rtb_Sign_hw * rtb_Sign_hw;

    /* Math: '<S208>/Math Function1' incorporates:
     *  Sum: '<S208>/Sum of Elements'
     *
     * About '<S208>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S208>/Math Function1' */

    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S208>/Constant'
     *  Product: '<S208>/Product'
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

    /* End of Switch: '<S208>/Switch' */

    /* Product: '<S208>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S206>/Subtract' incorporates:
     *  Product: '<S206>/Multiply'
     *  Product: '<S206>/Multiply1'
     */
    rtb_Square_kg_idx_2 = rtb_Sign_hw * absxk - rtb_Square_kg_idx_1 * D;

    /* Signum: '<S201>/Sign1' */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      rtb_Square_kg_idx_2 = -1.0F;
    } else {
      if (rtb_Square_kg_idx_2 > 0.0F) {
        rtb_Square_kg_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S201>/Sign1' */

    /* Switch: '<S201>/Switch2' incorporates:
     *  Constant: '<S201>/Constant4'
     */
    if (rtb_Square_kg_idx_2 == 0.0F) {
      rtb_Square_kg_idx_2 = 1.0F;
    }

    /* End of Switch: '<S201>/Switch2' */

    /* DotProduct: '<S201>/Dot Product' */
    rtb_Square_kg_idx_1 = D * rtb_Sign_hw + absxk * rtb_Square_kg_idx_1;

    /* Trigonometry: '<S201>/Acos' incorporates:
     *  DotProduct: '<S201>/Dot Product'
     */
    if (rtb_Square_kg_idx_1 > 1.0F) {
      rtb_Square_kg_idx_1 = 1.0F;
    } else {
      if (rtb_Square_kg_idx_1 < -1.0F) {
        rtb_Square_kg_idx_1 = -1.0F;
      }
    }

    /* Product: '<S201>/Multiply' incorporates:
     *  Trigonometry: '<S201>/Acos'
     */
    rtb_Square_kg_idx_2 *= acosf(rtb_Square_kg_idx_1);

    /* Saturate: '<S200>/Saturation' */
    if (rtb_Square_kg_idx_2 > 1.57079637F) {
      rtb_Square_kg_idx_2 = 1.57079637F;
    } else {
      if (rtb_Square_kg_idx_2 < -1.57079637F) {
        rtb_Square_kg_idx_2 = -1.57079637F;
      }
    }

    /* End of Saturate: '<S200>/Saturation' */

    /* Trigonometry: '<S200>/Sin' */
    rtb_Square_kg_idx_1 = arm_sin_f32(rtb_Square_kg_idx_2);

    /* Sqrt: '<S202>/Sqrt' */
    rtb_Square_kg_idx_2 = sqrtf(rtb_Switch_fz_idx_1);
    *rty_ay_cmd_mPs2 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2 * 2.0F *
      rtb_Square_kg_idx_1 / fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf
      (rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex +
       rtb_Square_kg_idx_0), 0.5F));
  } else {
    *rty_ay_cmd_mPs2 = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
      localDW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Switch: '<S184>/Switch' */

  /* Update for Delay: '<S189>/start_vel' */
  localDW->icLoad = 0U;

  /* Update for Delay: '<S189>/start_wp' */
  localDW->icLoad_e = 0U;

  /* Update for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S211>/Constant'
   *  Constant: '<S217>/ki'
   *  Product: '<S217>/Multiply'
   *  Sum: '<S211>/Sum'
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

  /* End of Update for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S219>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S211>/Constant'
   *  Gain: '<S219>/Gain'
   *  Sum: '<S211>/Sum'
   *  Sum: '<S219>/Sum5'
   */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE += ((0.0F - rtb_VectorConcatenate_fy[1])
    - localDW->DiscreteTimeIntegrator1_DSTATE) * 62.831852F * 0.004F;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S181>/Brake Control'
 *    '<S54>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_ay_cmd_mPs2)
{
  /* SignalConversion: '<S183>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
   *  Constant: '<S183>/Brake Speed'
   */
  *rty_ay_cmd_mPs2 = 0.0F;
}

/*
 * System initialize for atomic system:
 *    '<S182>/Motion State'
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
 *    '<S182>/Motion State'
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
 *    '<S182>/Motion State'
 *    '<S55>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S182>/Motion State' */
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

  /* End of Chart: '<S182>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S743>/Hold Control'
 *    '<S660>/Hold Control'
 *    '<S503>/Hold Control'
 *    '<S365>/Hold Control'
 *    '<S399>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S746>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S743>/Hold Control'
 *    '<S660>/Hold Control'
 *    '<S503>/Hold Control'
 *    '<S365>/Hold Control'
 *    '<S399>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S746>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S743>/Hold Control'
 *    '<S660>/Hold Control'
 *    '<S503>/Hold Control'
 *    '<S365>/Hold Control'
 *    '<S399>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S746>/Delay' incorporates:
   *  Gain: '<S748>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S746>/Gain2' incorporates:
   *  Delay: '<S746>/Delay'
   *  Gain: '<S748>/Gain'
   *  Sum: '<S746>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S746>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S743>/Brake Control'
 *    '<S660>/Brake Control'
 *    '<S671>/Brake Control'
 *    '<S503>/Brake Control'
 *    '<S449>/Brake Control'
 *    '<S365>/Brake Control'
 *    '<S383>/Brake Control'
 *    '<S399>/Brake Control'
 *    '<S411>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S745>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S745>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S743>/Move Control'
 *    '<S660>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S750>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S750>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S743>/Move Control'
 *    '<S660>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S750>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S750>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S743>/Move Control'
 *    '<S660>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_ho;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S751>/Multiply1' incorporates:
   *  Constant: '<S751>/const1'
   *  DiscreteIntegrator: '<S750>/Integrator'
   */
  rtb_Add3_ho = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S749>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S749>/Dead Zone' */

  /* Sum: '<S751>/Add' incorporates:
   *  DiscreteIntegrator: '<S750>/Integrator1'
   *  Gain: '<S747>/Gain1'
   *  Gain: '<S749>/Gain'
   *  Sum: '<S750>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_ho;

  /* Signum: '<S751>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S751>/Sign' */

  /* Sum: '<S751>/Add2' incorporates:
   *  Abs: '<S751>/Abs'
   *  Gain: '<S751>/Gain'
   *  Gain: '<S751>/Gain1'
   *  Product: '<S751>/Multiply2'
   *  Product: '<S751>/Multiply3'
   *  Sqrt: '<S751>/Sqrt'
   *  Sum: '<S751>/Add1'
   *  Sum: '<S751>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_ho;

  /* Sum: '<S751>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_ho;

  /* Sum: '<S751>/Add3' */
  rtb_Add3_ho = rtb_Subtract3_d + localC->d;

  /* Sum: '<S751>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S751>/Sign1' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S751>/Sign1' */

  /* Signum: '<S751>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S751>/Sign2' */

  /* Sum: '<S751>/Add5' incorporates:
   *  Gain: '<S751>/Gain2'
   *  Product: '<S751>/Multiply4'
   *  Sum: '<S751>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_ho - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S750>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S750>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S750>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S750>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S751>/Add6' */
  rtb_Add3_ho = rtb_a_o + localC->d;

  /* Sum: '<S751>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S751>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S751>/Sign5' */

  /* Signum: '<S751>/Sign3' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S751>/Sign3' */

  /* Signum: '<S751>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S751>/Sign4' */

  /* Signum: '<S751>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S751>/Sign6' */

  /* Update for DiscreteIntegrator: '<S750>/Integrator' incorporates:
   *  Constant: '<S751>/const'
   *  Gain: '<S751>/Gain3'
   *  Product: '<S751>/Divide'
   *  Product: '<S751>/Multiply5'
   *  Product: '<S751>/Multiply6'
   *  Sum: '<S751>/Subtract4'
   *  Sum: '<S751>/Subtract5'
   *  Sum: '<S751>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_ho - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S744>/Motion Status'
 *    '<S661>/Motion Status'
 *    '<S504>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S744>/Motion Status'
 *    '<S661>/Motion Status'
 *    '<S504>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S744>/Motion Status'
 *    '<S661>/Motion Status'
 *    '<S504>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S744>/Motion Status' */
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

  /* End of Chart: '<S744>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S753>/Hold Control'
 *    '<S692>/Hold Control'
 *    '<S513>/Hold Control'
 */
void FMS_HoldControl_l0_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S756>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S753>/Hold Control'
 *    '<S692>/Hold Control'
 *    '<S513>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S756>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S753>/Hold Control'
 *    '<S692>/Hold Control'
 *    '<S513>/Hold Control'
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

  /* Delay: '<S756>/Delay' incorporates:
   *  SignalConversion: '<S756>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S760>/Trigonometric Function1' incorporates:
   *  Gain: '<S759>/Gain'
   *  Trigonometry: '<S760>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S760>/Trigonometric Function' incorporates:
   *  Gain: '<S759>/Gain'
   *  Trigonometry: '<S760>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S760>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S760>/Constant3'
   */
  rtb_VectorConcatenate_hl[2] = 0.0F;

  /* Gain: '<S760>/Gain' */
  rtb_VectorConcatenate_hl[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S760>/Trigonometric Function3' */
  rtb_VectorConcatenate_hl[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S760>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S760>/Constant4'
   */
  rtb_VectorConcatenate_hl[5] = 0.0F;

  /* SignalConversion: '<S760>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_hl[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_hl[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_hl[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S756>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S756>/Delay'
   *  SignalConversion: '<S756>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S756>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S756>/Multiply' incorporates:
   *  SignalConversion: '<S756>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_hl[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_hl[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S756>/Multiply' */

  /* Gain: '<S756>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S756>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S753>/Brake Control'
 *    '<S692>/Brake Control'
 *    '<S513>/Brake Control'
 */
void FMS_BrakeControl_e1(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S755>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S753>/Move Control'
 *    '<S692>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S753>/Move Control'
 *    '<S692>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S753>/Move Control'
 *    '<S692>/Move Control'
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

  /* DiscreteIntegrator: '<S763>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S764>/Multiply1' incorporates:
   *  Constant: '<S764>/const1'
   *  DiscreteIntegrator: '<S763>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S763>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S764>/Multiply1' incorporates:
   *  Constant: '<S764>/const1'
   *  DiscreteIntegrator: '<S763>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S761>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S761>/Dead Zone' */

  /* Sum: '<S764>/Add' incorporates:
   *  DiscreteIntegrator: '<S763>/Integrator1'
   *  Gain: '<S757>/Gain6'
   *  Gain: '<S761>/Gain'
   *  Sum: '<S763>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S762>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S762>/Dead Zone' */

  /* Sum: '<S764>/Add' incorporates:
   *  DiscreteIntegrator: '<S763>/Integrator1'
   *  Gain: '<S757>/Gain6'
   *  Gain: '<S762>/Gain'
   *  Sum: '<S763>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S764>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S764>/Add2' incorporates:
   *  Abs: '<S764>/Abs'
   *  Gain: '<S764>/Gain'
   *  Gain: '<S764>/Gain1'
   *  Product: '<S764>/Multiply2'
   *  Product: '<S764>/Multiply3'
   *  Signum: '<S764>/Sign'
   *  Sqrt: '<S764>/Sqrt'
   *  Sum: '<S764>/Add1'
   *  Sum: '<S764>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S764>/Add3' incorporates:
   *  Signum: '<S764>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S764>/Subtract1' incorporates:
   *  Signum: '<S764>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S764>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S764>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S764>/Add5' incorporates:
   *  Gain: '<S764>/Gain2'
   *  Product: '<S764>/Multiply4'
   *  Signum: '<S764>/Sign'
   *  Sum: '<S764>/Add2'
   *  Sum: '<S764>/Add4'
   *  Sum: '<S764>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S763>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S763>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S764>/Sign3' incorporates:
   *  Sum: '<S764>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S764>/Sign4' incorporates:
   *  Sum: '<S764>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S764>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S764>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S764>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S764>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S763>/Integrator' incorporates:
   *  Constant: '<S764>/const'
   *  Gain: '<S764>/Gain3'
   *  Product: '<S764>/Divide'
   *  Product: '<S764>/Multiply5'
   *  Product: '<S764>/Multiply6'
   *  Sum: '<S764>/Subtract4'
   *  Sum: '<S764>/Subtract5'
   *  Sum: '<S764>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S763>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S764>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S764>/Add2' incorporates:
   *  Abs: '<S764>/Abs'
   *  Gain: '<S764>/Gain'
   *  Gain: '<S764>/Gain1'
   *  Product: '<S764>/Multiply2'
   *  Product: '<S764>/Multiply3'
   *  Signum: '<S764>/Sign'
   *  Sqrt: '<S764>/Sqrt'
   *  Sum: '<S764>/Add1'
   *  Sum: '<S764>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S764>/Add3' incorporates:
   *  Signum: '<S764>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S764>/Subtract1' incorporates:
   *  Signum: '<S764>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S764>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S764>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S764>/Add5' incorporates:
   *  Gain: '<S764>/Gain2'
   *  Product: '<S764>/Multiply4'
   *  Signum: '<S764>/Sign'
   *  Sum: '<S764>/Add2'
   *  Sum: '<S764>/Add4'
   *  Sum: '<S764>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S763>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S763>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S764>/Sign3' incorporates:
   *  Sum: '<S764>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S764>/Sign4' incorporates:
   *  Sum: '<S764>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S764>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S764>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S764>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S764>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S763>/Integrator' incorporates:
   *  Constant: '<S764>/const'
   *  Gain: '<S764>/Gain3'
   *  Product: '<S764>/Divide'
   *  Product: '<S764>/Multiply5'
   *  Product: '<S764>/Multiply6'
   *  Sum: '<S764>/Subtract4'
   *  Sum: '<S764>/Subtract5'
   *  Sum: '<S764>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S763>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S754>/Motion State'
 *    '<S693>/Motion State'
 *    '<S514>/Motion State'
 */
void FMS_MotionState_c_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S754>/Motion State'
 *    '<S693>/Motion State'
 *    '<S514>/Motion State'
 */
void FMS_MotionState_f_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S754>/Motion State'
 *    '<S693>/Motion State'
 *    '<S514>/Motion State'
 */
void FMS_MotionState_p(real32_T rtu_motion_req, real32_T rtu_speed, MotionState *
  rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S754>/Motion State' */
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

  /* End of Chart: '<S754>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S736>/OutRegionRegWP'
 *    '<S490>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S769>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S671>/Hold Control'
 *    '<S449>/Hold Control'
 *    '<S383>/Hold Control'
 *    '<S411>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S675>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S671>/Hold Control'
 *    '<S449>/Hold Control'
 *    '<S383>/Hold Control'
 *    '<S411>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S675>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S671>/Hold Control'
 *    '<S449>/Hold Control'
 *    '<S383>/Hold Control'
 *    '<S411>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S675>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S675>/Sum' incorporates:
   *  Delay: '<S675>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S678>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S678>/Switch' incorporates:
   *  Constant: '<S678>/Constant'
   *  Constant: '<S679>/Constant'
   *  Product: '<S678>/Multiply'
   *  RelationalOperator: '<S679>/Compare'
   *  Sum: '<S678>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S678>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S678>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S678>/Switch' */

  /* Gain: '<S675>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S675>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S671>/Move Control'
 *    '<S449>/Move Control'
 *    '<S383>/Move Control'
 *    '<S411>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S681>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S681>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S671>/Move Control'
 *    '<S449>/Move Control'
 *    '<S383>/Move Control'
 *    '<S411>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S681>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S681>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S671>/Move Control'
 *    '<S449>/Move Control'
 *    '<S383>/Move Control'
 *    '<S411>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_px;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S682>/Multiply1' incorporates:
   *  Constant: '<S682>/const1'
   *  DiscreteIntegrator: '<S681>/Integrator'
   */
  rtb_Add3_px = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S680>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S680>/Dead Zone' */

  /* Sum: '<S682>/Add' incorporates:
   *  DiscreteIntegrator: '<S681>/Integrator1'
   *  Gain: '<S676>/Gain1'
   *  Gain: '<S680>/Gain'
   *  Sum: '<S681>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_px;

  /* Signum: '<S682>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
  }

  /* End of Signum: '<S682>/Sign' */

  /* Sum: '<S682>/Add2' incorporates:
   *  Abs: '<S682>/Abs'
   *  Gain: '<S682>/Gain'
   *  Gain: '<S682>/Gain1'
   *  Product: '<S682>/Multiply2'
   *  Product: '<S682>/Multiply3'
   *  Sqrt: '<S682>/Sqrt'
   *  Sum: '<S682>/Add1'
   *  Sum: '<S682>/Subtract'
   */
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_px;

  /* Sum: '<S682>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_px;

  /* Sum: '<S682>/Add3' */
  rtb_Add3_px = rtb_Subtract3_e + localC->d;

  /* Sum: '<S682>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S682>/Sign1' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S682>/Sign1' */

  /* Signum: '<S682>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S682>/Sign2' */

  /* Sum: '<S682>/Add5' incorporates:
   *  Gain: '<S682>/Gain2'
   *  Product: '<S682>/Multiply4'
   *  Sum: '<S682>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_px - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S681>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S681>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S681>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S681>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S682>/Add6' */
  rtb_Add3_px = rtb_a_h + localC->d;

  /* Sum: '<S682>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S682>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S682>/Sign5' */

  /* Signum: '<S682>/Sign3' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S682>/Sign3' */

  /* Signum: '<S682>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S682>/Sign4' */

  /* Signum: '<S682>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S682>/Sign6' */

  /* Update for DiscreteIntegrator: '<S681>/Integrator' incorporates:
   *  Constant: '<S682>/const'
   *  Gain: '<S682>/Gain3'
   *  Product: '<S682>/Divide'
   *  Product: '<S682>/Multiply5'
   *  Product: '<S682>/Multiply6'
   *  Sum: '<S682>/Subtract4'
   *  Sum: '<S682>/Subtract5'
   *  Sum: '<S682>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_px - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S450>/Motion State'
 *    '<S384>/Motion State'
 *    '<S412>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S450>/Motion State'
 *    '<S384>/Motion State'
 *    '<S412>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S450>/Motion State'
 *    '<S384>/Motion State'
 *    '<S412>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S450>/Motion State' */
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

  /* End of Chart: '<S450>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S365>/Move Control'
 *    '<S399>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S374>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S374>/Dead Zone' */

  /* Gain: '<S369>/Gain1' incorporates:
   *  Gain: '<S374>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S369>/Switch' incorporates:
   *  Constant: '<S371>/Land_Speed'
   *  Constant: '<S372>/Constant'
   *  Constant: '<S373>/Constant'
   *  Gain: '<S371>/Gain'
   *  Logic: '<S369>/Logical Operator'
   *  MinMax: '<S371>/Min'
   *  RelationalOperator: '<S372>/Compare'
   *  RelationalOperator: '<S373>/Compare'
   *  S-Function (sfix_bitop): '<S369>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S369>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S800>/Switch' incorporates:
   *  Constant: '<S800>/FW_ACCEPT_R'
   *  Constant: '<S800>/MC_ACCEPT_R'
   *  Constant: '<S807>/Constant'
   *  RelationalOperator: '<S807>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S800>/Switch' */
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

  /* Math: '<S818>/Rem' incorporates:
   *  Constant: '<S818>/Constant1'
   *  Sum: '<S802>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S818>/Switch' incorporates:
   *  Abs: '<S818>/Abs'
   *  Constant: '<S818>/Constant'
   *  Constant: '<S819>/Constant'
   *  Product: '<S818>/Multiply'
   *  RelationalOperator: '<S819>/Compare'
   *  Sum: '<S818>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S818>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S818>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S818>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S805>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S824>/Sum of Elements' incorporates:
   *  Math: '<S824>/Math Function'
   *  SignalConversion: '<S824>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S824>/Math Function1' incorporates:
   *  Sum: '<S824>/Sum of Elements'
   *
   * About '<S824>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S824>/Math Function1' */

  /* Switch: '<S824>/Switch' incorporates:
   *  Constant: '<S824>/Constant'
   *  Product: '<S824>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S824>/Switch' */

  /* Product: '<S824>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S822>/Subtract' incorporates:
   *  Product: '<S822>/Multiply'
   *  Product: '<S822>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S821>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S821>/Sign1' */

  /* Switch: '<S821>/Switch2' incorporates:
   *  Constant: '<S821>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S821>/Switch2' */

  /* DotProduct: '<S821>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S821>/Acos' incorporates:
   *  DotProduct: '<S821>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S821>/Multiply' incorporates:
   *  Trigonometry: '<S821>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S805>/Switch' incorporates:
   *  Bias: '<S805>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S805>/Switch' */
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

  /* Gain: '<S808>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S809>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S809>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S809>/Multiply1' incorporates:
   *  Product: '<S809>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S809>/Divide' incorporates:
   *  Constant: '<S809>/Constant'
   *  Constant: '<S809>/R'
   *  Sqrt: '<S809>/Sqrt'
   *  Sum: '<S809>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S809>/Product3' incorporates:
   *  Constant: '<S809>/Constant1'
   *  Product: '<S809>/Multiply1'
   *  Sum: '<S809>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S809>/Multiply2' incorporates:
   *  Trigonometry: '<S809>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S808>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S813>/Abs' incorporates:
   *  Abs: '<S816>/Abs1'
   *  Switch: '<S813>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S813>/Switch1' incorporates:
   *  Abs: '<S813>/Abs'
   *  Bias: '<S813>/Bias2'
   *  Bias: '<S813>/Bias3'
   *  Constant: '<S810>/Constant'
   *  Constant: '<S810>/Constant1'
   *  Constant: '<S815>/Constant'
   *  Gain: '<S813>/Gain1'
   *  Product: '<S813>/Multiply'
   *  RelationalOperator: '<S815>/Compare'
   *  Switch: '<S810>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S816>/Switch1' incorporates:
     *  Bias: '<S816>/Bias2'
     *  Bias: '<S816>/Bias3'
     *  Constant: '<S816>/Constant'
     *  Constant: '<S817>/Constant'
     *  Math: '<S816>/Math Function'
     *  RelationalOperator: '<S817>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S816>/Switch1' */

    /* Signum: '<S813>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S813>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S810>/Sum' incorporates:
   *  Sum: '<S808>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S808>/Multiply' incorporates:
   *  Gain: '<S808>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S812>/Switch1' incorporates:
   *  Abs: '<S812>/Abs1'
   *  Bias: '<S812>/Bias2'
   *  Bias: '<S812>/Bias3'
   *  Constant: '<S812>/Constant'
   *  Constant: '<S814>/Constant'
   *  Math: '<S812>/Math Function'
   *  RelationalOperator: '<S814>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S812>/Switch1' */

  /* Product: '<S808>/Multiply' incorporates:
   *  Gain: '<S808>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S808>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S811>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S811>/Sum2' incorporates:
   *  Product: '<S811>/Multiply1'
   *  Product: '<S811>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S811>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S811>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S811>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S801>/Data Type Conversion' incorporates:
   *  Gain: '<S808>/Gain'
   *  Sum: '<S808>/Sum1'
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
  /* RelationalOperator: '<S820>/Compare' incorporates:
   *  Abs: '<S804>/Abs'
   *  Constant: '<S820>/Constant'
   *  MinMax: '<S804>/Max'
   *  Sum: '<S804>/Sum'
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
      /* Reshape: '<S803>/Reshape' incorporates:
       *  Constant: '<S803>/Constant'
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
          /* RelationalOperator: '<S806>/Compare' incorporates:
           *  Constant: '<S806>/Constant'
           *  S-Function (sfix_bitop): '<S798>/Bitwise AND'
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
          /* RelationalOperator: '<S799>/Relational Operator1' incorporates:
           *  Constant: '<S799>/Constant1'
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
        /* RelationalOperator: '<S797>/Relational Operator' incorporates:
         *  Constant: '<S797>/Constant'
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
          /* RelationalOperator: '<S796>/Relational Operator1' incorporates:
           *  Constant: '<S796>/Constant1'
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
  real32_T rtb_Divide_m1i;
  real32_T rtb_Sign5_p2;
  real32_T rtb_a_m;
  real32_T rtb_Subtract3_p;
  real32_T rtb_Divide_p5;
  real32_T rtb_Sign5_g42;
  real32_T rtb_Divide_i;
  real32_T rtb_Sign5_ij;
  real32_T rtb_Divide_pq;
  real32_T rtb_Sign5_a1;
  real32_T rtb_Add4_pb;
  MotionState rtb_state_ej;
  MotionState rtb_state_fg;
  MotionState rtb_state_og;
  real_T rtb_Switch1_n;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_aw;
  uint16_T rtb_y_cc;
  real32_T rtb_Subtract1_o;
  real32_T rtb_Divide_jq;
  real32_T rtb_Sign5_ke;
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
  real32_T y;
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
   *  ActionPort: '<S350>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S350>/Position' incorporates:
   *  ActionPort: '<S357>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S424>/Hold Control' incorporates:
   *  ActionPort: '<S426>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S351>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S351>/Offboard' incorporates:
   *  ActionPort: '<S463>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S353>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S353>/Land' incorporates:
   *  ActionPort: '<S653>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S353>/Takeoff' incorporates:
   *  ActionPort: '<S655>/Action Port'
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
   *  MultiPortSwitch: '<S545>/Index Vector'
   *  MultiPortSwitch: '<S610>/Index Vector'
   *  MultiPortSwitch: '<S611>/Index Vector'
   *  SwitchCase: '<S350>/Switch Case'
   *  SwitchCase: '<S351>/Switch Case'
   *  SwitchCase: '<S353>/Switch Case'
   *  SwitchCase: '<S424>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function1'
   *  Trigonometry: '<S100>/Trigonometric Function3'
   *  Trigonometry: '<S15>/Trigonometric Function1'
   *  Trigonometry: '<S15>/Trigonometric Function3'
   *  Trigonometry: '<S227>/Trigonometric Function1'
   *  Trigonometry: '<S227>/Trigonometric Function3'
   *  Trigonometry: '<S430>/Trigonometric Function1'
   *  Trigonometry: '<S430>/Trigonometric Function3'
   *  Trigonometry: '<S556>/Trigonometric Function1'
   *  Trigonometry: '<S556>/Trigonometric Function3'
   *  Trigonometry: '<S619>/Trigonometric Function1'
   *  Trigonometry: '<S619>/Trigonometric Function3'
   *  Trigonometry: '<S623>/Trigonometric Function1'
   *  Trigonometry: '<S623>/Trigonometric Function3'
   *  Trigonometry: '<S649>/Trigonometric Function1'
   *  Trigonometry: '<S649>/Trigonometric Function3'
   *  Trigonometry: '<S713>/Trigonometric Function1'
   *  Trigonometry: '<S713>/Trigonometric Function3'
   *  Trigonometry: '<S794>/Trigonometric Function1'
   *  Trigonometry: '<S794>/Trigonometric Function3'
   */
  rtb_Saturation_ga = arm_cos_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S125>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S353>/Takeoff' */
  /* End of Outputs for SubSystem: '<S353>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S351>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S424>/Hold Control' */
  /* End of Outputs for SubSystem: '<S350>/Position' */
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
   *  ActionPort: '<S350>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S350>/Position' incorporates:
   *  ActionPort: '<S357>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S424>/Hold Control' incorporates:
   *  ActionPort: '<S426>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S351>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S351>/Offboard' incorporates:
   *  ActionPort: '<S463>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S353>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S353>/Land' incorporates:
   *  ActionPort: '<S653>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S353>/Takeoff' incorporates:
   *  ActionPort: '<S655>/Action Port'
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
   *  MultiPortSwitch: '<S545>/Index Vector'
   *  MultiPortSwitch: '<S610>/Index Vector'
   *  MultiPortSwitch: '<S611>/Index Vector'
   *  SwitchCase: '<S350>/Switch Case'
   *  SwitchCase: '<S351>/Switch Case'
   *  SwitchCase: '<S353>/Switch Case'
   *  SwitchCase: '<S424>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S100>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function2'
   *  Trigonometry: '<S227>/Trigonometric Function'
   *  Trigonometry: '<S430>/Trigonometric Function'
   *  Trigonometry: '<S556>/Trigonometric Function'
   *  Trigonometry: '<S619>/Trigonometric Function'
   *  Trigonometry: '<S623>/Trigonometric Function'
   *  Trigonometry: '<S649>/Trigonometric Function'
   *  Trigonometry: '<S713>/Trigonometric Function'
   *  Trigonometry: '<S794>/Trigonometric Function'
   */
  rtb_Saturation1_d = arm_sin_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S125>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S353>/Takeoff' */
  /* End of Outputs for SubSystem: '<S353>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S351>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S424>/Hold Control' */
  /* End of Outputs for SubSystem: '<S350>/Position' */
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
    rtb_Subtract1_o = rtb_Divide_bu[0] * rtb_Divide_bu[1];

    /* Gain: '<S20>/Gain1' incorporates:
     *  Product: '<S20>/Multiply2'
     *  Product: '<S20>/Multiply3'
     *  Sum: '<S20>/Add2'
     */
    rtb_MatrixConcatenate1_a[7] = (rtb_Saturation1_p5 + rtb_Subtract1_o) * 2.0F;

    /* Product: '<S20>/Multiply' incorporates:
     *  Product: '<S18>/Multiply2'
     */
    d = rtb_Divide_bu[1] * rtb_Divide_bu[3];

    /* Product: '<S20>/Multiply1' incorporates:
     *  Product: '<S18>/Multiply3'
     */
    rtb_Divide_jq = rtb_Divide_bu[0] * rtb_Divide_bu[2];

    /* Gain: '<S20>/Gain' incorporates:
     *  Product: '<S20>/Multiply'
     *  Product: '<S20>/Multiply1'
     *  Sum: '<S20>/Subtract2'
     */
    rtb_MatrixConcatenate1_a[6] = (d - rtb_Divide_jq) * 2.0F;

    /* Gain: '<S19>/Gain1' incorporates:
     *  Sum: '<S19>/Subtract1'
     */
    rtb_MatrixConcatenate1_a[5] = (rtb_Saturation1_p5 - rtb_Subtract1_o) * 2.0F;

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
    rtb_Subtract1_o = rtb_Divide_bu[0] * rtb_Divide_bu[3];

    /* Gain: '<S19>/Gain' incorporates:
     *  Product: '<S19>/Multiply'
     *  Product: '<S19>/Multiply1'
     *  Sum: '<S19>/Add3'
     */
    rtb_MatrixConcatenate1_a[3] = (rtb_Saturation1_p5 + rtb_Subtract1_o) * 2.0F;

    /* Gain: '<S18>/Gain1' incorporates:
     *  Sum: '<S18>/Add2'
     */
    rtb_MatrixConcatenate1_a[2] = (d + rtb_Divide_jq) * 2.0F;

    /* Gain: '<S18>/Gain' incorporates:
     *  Sum: '<S18>/Subtract1'
     */
    rtb_MatrixConcatenate1_a[1] = (rtb_Saturation1_p5 - rtb_Subtract1_o) * 2.0F;

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
   *  ActionPort: '<S246>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S246>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S250>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
   *  ActionPort: '<S128>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
   *  ActionPort: '<S285>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Takeoff' incorporates:
   *  ActionPort: '<S286>/Action Port'
   */
  /* SwitchCase: '<S126>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S274>/Math Function'
   *  Math: '<S323>/Math Function'
   *  Math: '<S345>/Math Function'
   *  SwitchCase: '<S128>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   */
  rtb_Saturation_o4 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Subtract1_o = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S128>/Takeoff' */
  /* End of Outputs for SubSystem: '<S128>/Return' */
  /* End of Outputs for SubSystem: '<S246>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S126>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */

  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S351>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S351>/Mission' incorporates:
   *  ActionPort: '<S462>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S462>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S466>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S353>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S353>/Return' incorporates:
   *  ActionPort: '<S654>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Hold' incorporates:
   *  ActionPort: '<S283>/Action Port'
   */
  /* SwitchCase: '<S128>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S300>/Sum of Elements'
   *  Sum: '<S534>/Sum of Elements'
   *  Sum: '<S774>/Sum of Elements'
   *  SwitchCase: '<S351>/Switch Case'
   *  SwitchCase: '<S353>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Divide_jq = rtb_Saturation_o4 + rtb_Subtract1_o;

  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S350>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S350>/Position' incorporates:
   *  ActionPort: '<S357>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S126>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
   *  ActionPort: '<S246>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S246>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S250>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S128>/Return' incorporates:
   *  ActionPort: '<S285>/Action Port'
   */
  /* SwitchCase: '<S126>/Switch Case' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S273>/Sqrt'
   *  Sqrt: '<S299>/Sqrt'
   *  Sqrt: '<S322>/Sqrt'
   *  Sqrt: '<S425>/Sqrt'
   *  Sqrt: '<S532>/Sqrt'
   *  Sqrt: '<S772>/Sqrt'
   *  Sum: '<S1>/Add'
   *  SwitchCase: '<S128>/Switch Case'
   *  SwitchCase: '<S350>/Switch Case'
   *  SwitchCase: '<S351>/Switch Case'
   *  SwitchCase: '<S353>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Saturation1_p5 = sqrtf(rtb_Divide_jq);

  /* End of Outputs for SubSystem: '<S128>/Return' */
  /* End of Outputs for SubSystem: '<S246>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S126>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */
  /* End of Outputs for SubSystem: '<S350>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S128>/Hold' */
  /* End of Outputs for SubSystem: '<S353>/Return' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S462>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S351>/Mission' */
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
          FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S181>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S166>/Switch Case' */
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
        /* Disable for SwitchCase: '<S353>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S753>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S743>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S692>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S660>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S671>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S351>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S462>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S513>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S503>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S462>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S350>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S449>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S365>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S383>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S399>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S424>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S411>/Switch Case' */
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
            /* Disable for SwitchCase: '<S181>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S166>/Switch Case' */
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
          /* Disable for SwitchCase: '<S353>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S753>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S743>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S692>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S660>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S671>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S351>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S462>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S513>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S503>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S462>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S350>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S449>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S365>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S383>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S399>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S424>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S411>/Switch Case' */
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
            /* Disable for SwitchCase: '<S181>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S166>/Switch Case' */
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
           *  ActionPort: '<S286>/Action Port'
           */
          /* Sum: '<S345>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Subtract1_o;

          /* Math: '<S345>/Math Function1' incorporates:
           *  Sum: '<S345>/Sum of Elements'
           *
           * About '<S345>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S345>/Math Function1' */

          /* Switch: '<S345>/Switch' incorporates:
           *  Constant: '<S345>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S345>/Product'
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

          /* End of Switch: '<S345>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S335>/NearbyRefWP' incorporates:
           *  Constant: '<S333>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_f0,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S335>/SearchL1RefWP' incorporates:
           *  Constant: '<S333>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_ap, &rtb_u_b);

          /* MATLAB Function: '<S335>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S330>/Sum'
           *  Sum: '<S330>/Sum1'
           */
          rtb_Saturation1_p5 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_jq = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Sign5_ke = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Divide_jq * rtb_Divide_jq;
          rtb_Saturation_ga = (rtb_Sign5_ke * rtb_Divide_jq + d *
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
            rtb_Divide_m1i = (rtb_Saturation_ga * rtb_Saturation1_p5 +
                              FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Divide_m1i * rtb_Divide_m1i;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_m1i = (rtb_Saturation_ga * rtb_Divide_jq +
                              FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_ga += sqrtf(rtb_Divide_m1i * rtb_Divide_m1i +
              rtb_Subtract_hb[0]) * 0.5774F / sqrtf(rtb_Saturation1_p5 *
              rtb_Saturation1_p5 + rtb_P_f_idx_0);
            if (rtb_Saturation_ga > 1.0F) {
              rtb_Saturation_ga = 1.0F;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = rtb_Saturation_ga * rtb_Saturation1_p5 +
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_ga = rtb_Saturation_ga * rtb_Divide_jq +
              FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S335>/OutRegionRegWP' */

          /* Switch: '<S335>/Switch1' incorporates:
           *  Constant: '<S338>/Constant'
           *  RelationalOperator: '<S338>/Compare'
           */
          if (rtb_Saturation1_d <= 0.0F) {
            /* Switch: '<S335>/Switch' incorporates:
             *  Constant: '<S337>/Constant'
             *  RelationalOperator: '<S337>/Compare'
             */
            if (rtb_u_b >= 0.0F) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            } else {
              rtb_Divide_f0[0] = rtb_P_f_idx_0;
              rtb_Divide_f0[1] = rtb_Saturation_ga;
            }

            /* End of Switch: '<S335>/Switch' */
          }

          /* End of Switch: '<S335>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S336>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S346>/Sum of Elements' incorporates:
           *  Math: '<S346>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S346>/Math Function1' incorporates:
           *  Sum: '<S346>/Sum of Elements'
           *
           * About '<S346>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S346>/Math Function1' */

          /* Switch: '<S346>/Switch' incorporates:
           *  Constant: '<S346>/Constant'
           *  Product: '<S346>/Product'
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

          /* End of Switch: '<S346>/Switch' */

          /* Product: '<S345>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S348>/Sum of Elements' incorporates:
           *  Math: '<S348>/Math Function'
           *  SignalConversion: '<S348>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S348>/Math Function1' incorporates:
           *  Sum: '<S348>/Sum of Elements'
           *
           * About '<S348>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S348>/Math Function1' */

          /* Switch: '<S348>/Switch' incorporates:
           *  Constant: '<S348>/Constant'
           *  Product: '<S348>/Product'
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

          /* End of Switch: '<S348>/Switch' */

          /* Product: '<S346>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S349>/Sum of Elements' incorporates:
           *  Math: '<S349>/Math Function'
           *  SignalConversion: '<S349>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S349>/Math Function1' incorporates:
           *  Sum: '<S349>/Sum of Elements'
           *
           * About '<S349>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S349>/Math Function1' */

          /* Switch: '<S349>/Switch' incorporates:
           *  Constant: '<S349>/Constant'
           *  Product: '<S349>/Product'
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

          /* End of Switch: '<S349>/Switch' */

          /* Product: '<S349>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S348>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S349>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S348>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S330>/Divide' incorporates:
           *  Math: '<S331>/Square'
           *  Math: '<S332>/Square'
           *  Sqrt: '<S331>/Sqrt'
           *  Sqrt: '<S332>/Sqrt'
           *  Sum: '<S331>/Sum of Elements'
           *  Sum: '<S332>/Sum of Elements'
           */
          rtb_Saturation1_p5 = sqrtf(rtb_Sign5_ke * rtb_Sign5_ke + d * d) /
            sqrtf(rtb_Saturation1_p5 * rtb_Saturation1_p5 + rtb_Divide_jq *
                  rtb_Divide_jq);

          /* Saturate: '<S330>/Saturation' */
          if (rtb_Saturation1_p5 > 1.0F) {
            rtb_Saturation1_p5 = 1.0F;
          } else {
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation1_p5 = 0.0F;
            }
          }

          /* End of Saturate: '<S330>/Saturation' */

          /* Sum: '<S347>/Subtract' incorporates:
           *  Product: '<S347>/Multiply'
           *  Product: '<S347>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S343>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S343>/Sign1' */

          /* Switch: '<S343>/Switch2' incorporates:
           *  Constant: '<S343>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S343>/Switch2' */

          /* DotProduct: '<S343>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S343>/Acos' incorporates:
           *  DotProduct: '<S343>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S343>/Multiply' incorporates:
           *  Trigonometry: '<S343>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S342>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S342>/Saturation' */

          /* Sqrt: '<S344>/Sqrt' incorporates:
           *  Sum: '<S344>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(rtb_Saturation_o4 + rtb_Subtract1_o);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S286>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S286>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S286>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S286>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S342>/Divide' incorporates:
           *  Constant: '<S333>/L1'
           *  Gain: '<S342>/Gain'
           *  Math: '<S342>/Square'
           *  Product: '<S342>/Multiply1'
           *  Trigonometry: '<S342>/Sin'
           */
          rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F * arm_sin_f32
            (rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S333>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S286>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S286>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S286>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S333>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S328>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S330>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S328>/Sum2'
           *  Sum: '<S330>/Add'
           *  Sum: '<S330>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_p5 +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S328>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S286>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S286>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S286>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S328>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S128>/Land' incorporates:
           *  ActionPort: '<S284>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S284>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S284>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S284>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S284>/Constant'
           *  Constant: '<S284>/Constant4'
           *  Constant: '<S284>/Constant5'
           *  Constant: '<S284>/Constant7'
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
           *  ActionPort: '<S285>/Action Port'
           */
          /* Math: '<S323>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Subtract1_o;

          /* Sum: '<S323>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Subtract1_o;

          /* Math: '<S323>/Math Function1' incorporates:
           *  Sum: '<S323>/Sum of Elements'
           *
           * About '<S323>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S323>/Math Function1' */

          /* Switch: '<S323>/Switch' incorporates:
           *  Constant: '<S323>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S323>/Product'
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

          /* End of Switch: '<S323>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S313>/NearbyRefWP' incorporates:
           *  Constant: '<S311>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S313>/SearchL1RefWP' incorporates:
           *  Constant: '<S311>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_f0, &rtb_Saturation1_d);

          /* MATLAB Function: '<S313>/OutRegionRegWP' incorporates:
           *  Constant: '<S311>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0],
                             &rtb_TmpSignalConversionAtMultip[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S313>/Switch1' incorporates:
           *  Constant: '<S316>/Constant'
           *  RelationalOperator: '<S316>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_f0[0] = rtb_Subtract_hb[0];
            rtb_Divide_f0[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S315>/Compare' incorporates:
             *  Constant: '<S315>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S313>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S313>/Switch' */
          }

          /* End of Switch: '<S313>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S314>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S324>/Sum of Elements' incorporates:
           *  Math: '<S324>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S324>/Math Function1' incorporates:
           *  Sum: '<S324>/Sum of Elements'
           *
           * About '<S324>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S324>/Math Function1' */

          /* Switch: '<S324>/Switch' incorporates:
           *  Constant: '<S324>/Constant'
           *  Product: '<S324>/Product'
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

          /* End of Switch: '<S324>/Switch' */

          /* Product: '<S323>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S326>/Sum of Elements' incorporates:
           *  Math: '<S326>/Math Function'
           *  SignalConversion: '<S326>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S326>/Math Function1' incorporates:
           *  Sum: '<S326>/Sum of Elements'
           *
           * About '<S326>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S326>/Math Function1' */

          /* Switch: '<S326>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  Product: '<S326>/Product'
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

          /* End of Switch: '<S326>/Switch' */

          /* Product: '<S324>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S327>/Sum of Elements' incorporates:
           *  Math: '<S327>/Math Function'
           *  SignalConversion: '<S327>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S327>/Math Function1' incorporates:
           *  Sum: '<S327>/Sum of Elements'
           *
           * About '<S327>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S327>/Math Function1' */

          /* Switch: '<S327>/Switch' incorporates:
           *  Constant: '<S327>/Constant'
           *  Product: '<S327>/Product'
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

          /* End of Switch: '<S327>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S308>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign5_ke = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S327>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S326>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S308>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract1_o = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S327>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S326>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S308>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S308>/Divide' incorporates:
           *  Math: '<S309>/Square'
           *  Math: '<S310>/Square'
           *  Sqrt: '<S309>/Sqrt'
           *  Sqrt: '<S310>/Sqrt'
           *  Sum: '<S308>/Sum'
           *  Sum: '<S308>/Sum1'
           *  Sum: '<S309>/Sum of Elements'
           *  Sum: '<S310>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_Sign5_ke * rtb_Sign5_ke + rtb_u_b *
            rtb_u_b) / sqrtf(rtb_Subtract1_o * rtb_Subtract1_o +
                             rtb_Saturation_o4 * rtb_Saturation_o4);

          /* Saturate: '<S308>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S308>/Saturation' */

          /* Sum: '<S325>/Subtract' incorporates:
           *  Product: '<S325>/Multiply'
           *  Product: '<S325>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S321>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S321>/Sign1' */

          /* Switch: '<S321>/Switch2' incorporates:
           *  Constant: '<S321>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S321>/Switch2' */

          /* DotProduct: '<S321>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S321>/Acos' incorporates:
           *  DotProduct: '<S321>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S321>/Multiply' incorporates:
           *  Trigonometry: '<S321>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S320>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S320>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S285>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S285>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S285>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S320>/Divide' incorporates:
           *  Constant: '<S311>/L1'
           *  Gain: '<S320>/Gain'
           *  Math: '<S320>/Square'
           *  Product: '<S320>/Multiply1'
           *  Trigonometry: '<S320>/Sin'
           */
          rtb_u_b = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F * arm_sin_f32
            (rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S311>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S311>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S306>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S308>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S306>/Sum2'
           *  Sum: '<S308>/Add'
           *  Sum: '<S308>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S306>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S285>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S306>/Saturation1' */
          /* End of Outputs for SubSystem: '<S128>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S128>/Hold' incorporates:
             *  ActionPort: '<S283>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S128>/Switch Case' incorporates:
             *  Delay: '<S288>/Delay'
             *  Delay: '<S293>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S128>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S128>/Hold' incorporates:
           *  ActionPort: '<S283>/Action Port'
           */
          /* Math: '<S300>/Math Function1'
           *
           * About '<S300>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Divide_jq));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Divide_jq);
          }

          /* End of Math: '<S300>/Math Function1' */

          /* Switch: '<S300>/Switch' incorporates:
           *  Constant: '<S300>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S300>/Product'
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

          /* End of Switch: '<S300>/Switch' */

          /* Delay: '<S293>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S305>/Sum of Elements' incorporates:
           *  Delay: '<S293>/start_vel'
           *  Math: '<S305>/Math Function'
           */
          rtb_u_b = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S305>/Math Function1' incorporates:
           *  Sum: '<S305>/Sum of Elements'
           *
           * About '<S305>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S305>/Math Function1' */

          /* Switch: '<S305>/Switch' incorporates:
           *  Constant: '<S305>/Constant'
           *  Delay: '<S293>/start_vel'
           *  Product: '<S305>/Product'
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

          /* End of Switch: '<S305>/Switch' */

          /* Product: '<S300>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S303>/Sum of Elements' incorporates:
           *  Math: '<S303>/Math Function'
           *  SignalConversion: '<S303>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S303>/Math Function1' incorporates:
           *  Sum: '<S303>/Sum of Elements'
           *
           * About '<S303>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S303>/Math Function1' */

          /* Switch: '<S303>/Switch' incorporates:
           *  Constant: '<S303>/Constant'
           *  Product: '<S303>/Product'
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

          /* End of Switch: '<S303>/Switch' */

          /* MinMax: '<S291>/Max' incorporates:
           *  Constant: '<S289>/L1'
           *  Constant: '<S289>/R'
           *  Gain: '<S291>/Gain'
           */
          rtb_Saturation_ga = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S291>/SearchL1RefWP' incorporates:
           *  Constant: '<S289>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S296>/TmpSignal ConversionAt SFunction Inport2'
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
            rtb_Subtract1_o = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Subtract1_o * rtb_Subtract1_o + rtb_u_b * rtb_u_b);
            rtb_Saturation_o4 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Saturation1_d = ((d * d + rtb_Saturation_o4) - rtb_Saturation_ga
                                 * rtb_Saturation_ga) / (2.0F * d);
            rtb_Square_dv[0] = rtb_u_b / d;
            rtb_Subtract1_o /= d;
            rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d;
            if (rtb_u_b > rtb_Saturation_o4) {
              rtb_n = 0;
            } else if (rtb_u_b == rtb_Saturation_o4) {
              rtb_n = 1;
              rtb_P_ap[0] = rtb_Saturation1_d * rtb_Square_dv[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_ap[1] = rtb_Saturation1_d * rtb_Subtract1_o +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation_o4 = sqrtf(rtb_Saturation_o4 - rtb_u_b);
              rtb_P_ap[0] = (rtb_Saturation1_d * rtb_Square_dv[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation_o4 *
                -rtb_Subtract1_o;
              rtb_P_ap[1] = (rtb_Saturation1_d * rtb_Subtract1_o +
                             FMS_U.INS_Out.y_R) + rtb_Saturation_o4 *
                rtb_Square_dv[0];
            }
          }

          /* End of MATLAB Function: '<S291>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S294>/Compare' incorporates:
           *  Constant: '<S294>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S291>/OutRegionRegWP' incorporates:
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

          /* Switch: '<S291>/Switch' incorporates:
           *  Constant: '<S289>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S291>/OutRegionRegWP'
           *  Product: '<S305>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_d = rtb_P_ap[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S291>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S292>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_dv[0] = rtb_Saturation1_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S291>/Switch' incorporates:
           *  Constant: '<S289>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S291>/OutRegionRegWP'
           *  Product: '<S305>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation1_d = rtb_P_ap[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S291>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S292>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_dv[1] = rtb_Saturation1_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S301>/Sum of Elements' incorporates:
           *  Math: '<S301>/Math Function'
           */
          rtb_u_b = rtb_Square_dv[0] * rtb_Square_dv[0] + rtb_Square_dv[1] *
            rtb_Square_dv[1];

          /* Math: '<S301>/Math Function1' incorporates:
           *  Sum: '<S301>/Sum of Elements'
           *
           * About '<S301>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S301>/Math Function1' */

          /* Switch: '<S301>/Switch' incorporates:
           *  Constant: '<S301>/Constant'
           *  Product: '<S301>/Product'
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

          /* End of Switch: '<S301>/Switch' */

          /* Product: '<S301>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_f0[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S304>/Sum of Elements' incorporates:
           *  Math: '<S304>/Math Function'
           *  SignalConversion: '<S304>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S304>/Math Function1' incorporates:
           *  Sum: '<S304>/Sum of Elements'
           *
           * About '<S304>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S304>/Math Function1' */

          /* Switch: '<S304>/Switch' incorporates:
           *  Constant: '<S304>/Constant'
           *  Product: '<S304>/Product'
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

          /* End of Switch: '<S304>/Switch' */

          /* Product: '<S304>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S303>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S304>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S303>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S302>/Subtract' incorporates:
           *  Product: '<S302>/Multiply'
           *  Product: '<S302>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Divide_f0[0] * rtb_Subtract_hb[1] -
            rtb_Divide_f0[1] * rtb_Subtract_hb[0];

          /* Signum: '<S298>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S298>/Sign1' */

          /* Switch: '<S298>/Switch2' incorporates:
           *  Constant: '<S298>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S298>/Switch2' */

          /* DotProduct: '<S298>/Dot Product' */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_f0[0] +
            rtb_Subtract_hb[1] * rtb_Divide_f0[1];

          /* Trigonometry: '<S298>/Acos' incorporates:
           *  DotProduct: '<S298>/Dot Product'
           */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < -1.0F) {
              rtb_Saturation_o4 = -1.0F;
            }
          }

          /* Product: '<S298>/Multiply' incorporates:
           *  Trigonometry: '<S298>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation_o4);

          /* Saturate: '<S297>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S297>/Saturation' */

          /* Delay: '<S288>/Delay' incorporates:
           *  Gain: '<S290>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S283>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S283>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S283>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S283>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S297>/Divide' incorporates:
           *  Constant: '<S289>/L1'
           *  Gain: '<S297>/Gain'
           *  Math: '<S297>/Square'
           *  Product: '<S297>/Multiply1'
           *  Trigonometry: '<S297>/Sin'
           */
          rtb_u_b = 2.0F * (rtb_Saturation1_p5 * rtb_Saturation1_p5) *
            arm_sin_f32(rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S289>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S283>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S283>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S283>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S289>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S288>/Gain2' incorporates:
           *  Delay: '<S288>/Delay'
           *  Gain: '<S290>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S288>/Sum'
           */
          rtb_u_b = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S288>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S283>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S283>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S283>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S288>/Saturation1' */

          /* Update for Delay: '<S293>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S288>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S128>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S128>/Unknown' incorporates:
           *  ActionPort: '<S287>/Action Port'
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
           *  ActionPort: '<S247>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S247>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S247>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S247>/Bus Assignment' incorporates:
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
             *  ActionPort: '<S246>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S126>/Switch Case' incorporates:
             *  UnitDelay: '<S249>/Delay Input1'
             *
             * Block description for '<S249>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S126>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S126>/Mission' incorporates:
             *  ActionPort: '<S246>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S246>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S126>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S258>/Integrator'
             *  DiscreteIntegrator: '<S258>/Integrator1'
             *  DiscreteIntegrator: '<S259>/Integrator'
             *  DiscreteIntegrator: '<S259>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;
            FMS_DW.Integrator1_DSTATE_ew = 0.0F;
            FMS_DW.Integrator_DSTATE_fk = 0.0F;
            FMS_DW.Integrator_DSTATE_oc = 0.0F;

            /* End of SystemReset for SubSystem: '<S246>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S126>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S126>/Mission' incorporates:
           *  ActionPort: '<S246>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S249>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S249>/Delay Input1'
           *
           * Block description for '<S249>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S246>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S250>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k != POS_ZCSIG)) {
            /* InitializeConditions for DiscreteIntegrator: '<S259>/Integrator1' */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;

            /* InitializeConditions for DiscreteIntegrator: '<S258>/Integrator1' */
            FMS_DW.Integrator1_DSTATE_ew = 0.0F;

            /* InitializeConditions for DiscreteIntegrator: '<S259>/Integrator' */
            FMS_DW.Integrator_DSTATE_fk = 0.0F;

            /* InitializeConditions for DiscreteIntegrator: '<S258>/Integrator' */
            FMS_DW.Integrator_DSTATE_oc = 0.0F;
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k =
            rtb_FixPtRelationalOperator_me;

          /* Math: '<S274>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Subtract1_o;

          /* Sum: '<S274>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Subtract1_o;

          /* Math: '<S274>/Math Function1' incorporates:
           *  Sum: '<S274>/Sum of Elements'
           *
           * About '<S274>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S274>/Math Function1' */

          /* Switch: '<S274>/Switch' incorporates:
           *  Constant: '<S274>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S274>/Product'
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

          /* End of Switch: '<S274>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S264>/NearbyRefWP' incorporates:
           *  Constant: '<S262>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_u_b);

          /* MATLAB Function: '<S264>/SearchL1RefWP' incorporates:
           *  Constant: '<S262>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_f0, &rtb_Saturation_ga);

          /* MATLAB Function: '<S264>/OutRegionRegWP' incorporates:
           *  Constant: '<S262>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0],
                             &rtb_TmpSignalConversionAtMultip[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S264>/Switch1' incorporates:
           *  Constant: '<S267>/Constant'
           *  RelationalOperator: '<S267>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_Divide_f0[0] = rtb_Subtract_hb[0];
            rtb_Divide_f0[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S266>/Compare' incorporates:
             *  Constant: '<S266>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_ga >= 0.0F);

            /* Switch: '<S264>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_f0[0] = rtb_P_ap[0];
              rtb_Divide_f0[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S264>/Switch' */
          }

          /* End of Switch: '<S264>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S265>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_f0[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_f0[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S275>/Sum of Elements' incorporates:
           *  Math: '<S275>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S275>/Math Function1' incorporates:
           *  Sum: '<S275>/Sum of Elements'
           *
           * About '<S275>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S275>/Math Function1' */

          /* Switch: '<S275>/Switch' incorporates:
           *  Constant: '<S275>/Constant'
           *  Product: '<S275>/Product'
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

          /* End of Switch: '<S275>/Switch' */

          /* Product: '<S274>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S277>/Sum of Elements' incorporates:
           *  Math: '<S277>/Math Function'
           *  SignalConversion: '<S277>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S277>/Math Function1' incorporates:
           *  Sum: '<S277>/Sum of Elements'
           *
           * About '<S277>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S277>/Math Function1' */

          /* Switch: '<S277>/Switch' incorporates:
           *  Constant: '<S277>/Constant'
           *  Product: '<S277>/Product'
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

          /* End of Switch: '<S277>/Switch' */

          /* Product: '<S275>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S278>/Sum of Elements' incorporates:
           *  Math: '<S278>/Math Function'
           *  SignalConversion: '<S278>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S278>/Math Function1' incorporates:
           *  Sum: '<S278>/Sum of Elements'
           *
           * About '<S278>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S278>/Math Function1' */

          /* Switch: '<S278>/Switch' incorporates:
           *  Constant: '<S278>/Constant'
           *  Product: '<S278>/Product'
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

          /* End of Switch: '<S278>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S254>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign5_ke = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S278>/Divide' */
          rtb_Subtract_hb[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S277>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S254>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract1_o = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S278>/Divide' */
          rtb_Subtract_hb[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S277>/Divide' */
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S254>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
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
          rtb_Saturation_o4 = sqrtf(rtb_Sign5_ke * rtb_Sign5_ke + rtb_u_b *
            rtb_u_b) / sqrtf(rtb_Subtract1_o * rtb_Subtract1_o +
                             rtb_Saturation_o4 * rtb_Saturation_o4);

          /* Saturate: '<S254>/Saturation' */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_o4 = 0.0F;
            }
          }

          /* End of Saturate: '<S254>/Saturation' */

          /* Sum: '<S276>/Subtract' incorporates:
           *  Product: '<S276>/Multiply'
           *  Product: '<S276>/Multiply1'
           */
          rtb_Subtract1_o = rtb_Subtract_hb[0] * rtb_Divide_f0[1] -
            rtb_Subtract_hb[1] * rtb_Divide_f0[0];

          /* Signum: '<S272>/Sign1' */
          if (rtb_Subtract1_o < 0.0F) {
            rtb_Subtract1_o = -1.0F;
          } else {
            if (rtb_Subtract1_o > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            }
          }

          /* End of Signum: '<S272>/Sign1' */

          /* Switch: '<S272>/Switch2' incorporates:
           *  Constant: '<S272>/Constant4'
           */
          if (rtb_Subtract1_o == 0.0F) {
            rtb_Subtract1_o = 1.0F;
          }

          /* End of Switch: '<S272>/Switch2' */

          /* DotProduct: '<S272>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_f0[0] * rtb_Subtract_hb[0] +
            rtb_Divide_f0[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S272>/Acos' incorporates:
           *  DotProduct: '<S272>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S272>/Multiply' incorporates:
           *  Trigonometry: '<S272>/Acos'
           */
          rtb_Subtract1_o *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S271>/Saturation' */
          if (rtb_Subtract1_o > 1.57079637F) {
            rtb_Subtract1_o = 1.57079637F;
          } else {
            if (rtb_Subtract1_o < -1.57079637F) {
              rtb_Subtract1_o = -1.57079637F;
            }
          }

          /* End of Saturate: '<S271>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S250>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S250>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S250>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Saturate: '<S252>/Saturation' */
          if (FMS_DW.Integrator1_DSTATE_li > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_li < 2.5F) {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = 2.5F;
          } else {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_li;
          }

          /* End of Saturate: '<S252>/Saturation' */

          /* Product: '<S271>/Divide' incorporates:
           *  Constant: '<S262>/L1'
           *  Gain: '<S271>/Gain'
           *  Math: '<S271>/Square'
           *  Product: '<S271>/Multiply1'
           *  Trigonometry: '<S271>/Sin'
           */
          rtb_u_b = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F * arm_sin_f32
            (rtb_Subtract1_o) / FMS_PARAM.FW_L1;

          /* Saturate: '<S262>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S262>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S251>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S254>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S251>/Sum2'
           *  Sum: '<S254>/Add'
           *  Sum: '<S254>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_o4 +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S251>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S250>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S251>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S252>/Switch' incorporates:
           *  Constant: '<S252>/Constant4'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            rtb_Subtract1_o = FMS_B.Cmd_In.set_speed;
          } else {
            rtb_Subtract1_o = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S252>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S261>/Multiply1' incorporates:
           *  Constant: '<S261>/const1'
           *  DiscreteIntegrator: '<S259>/Integrator'
           */
          d = FMS_DW.Integrator_DSTATE_fk * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S252>/Switch1' incorporates:
           *  Constant: '<S257>/Constant'
           *  DiscreteIntegrator: '<S258>/Integrator1'
           *  RelationalOperator: '<S257>/Compare'
           */
          if (FMS_B.vtol_state == VTOLState_ForwardTrans) {
            rtb_u_b = FMS_DW.Integrator1_DSTATE_ew;
          } else {
            rtb_u_b = rtb_Subtract1_o;
          }

          /* End of Switch: '<S252>/Switch1' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S261>/Add' incorporates:
           *  DiscreteIntegrator: '<S259>/Integrator1'
           *  Sum: '<S259>/Subtract'
           */
          rtb_Saturation_o4 = (FMS_DW.Integrator1_DSTATE_li - rtb_u_b) + d;

          /* Signum: '<S261>/Sign' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation_o4 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation_o4;
          }

          /* End of Signum: '<S261>/Sign' */

          /* Sum: '<S261>/Add2' incorporates:
           *  Abs: '<S261>/Abs'
           *  Gain: '<S261>/Gain'
           *  Gain: '<S261>/Gain1'
           *  Product: '<S261>/Multiply2'
           *  Product: '<S261>/Multiply3'
           *  Sqrt: '<S261>/Sqrt'
           *  Sum: '<S261>/Add1'
           *  Sum: '<S261>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation_o4) + FMS_ConstB.d_cy) *
                           FMS_ConstB.d_cy) - FMS_ConstB.d_cy) * 0.5F *
            rtb_Saturation_ga + d;

          /* Sum: '<S261>/Add4' */
          rtb_Saturation1_d = (rtb_Saturation_o4 - rtb_u_b) + d;

          /* Sum: '<S261>/Add3' */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_ConstB.d_cy;

          /* Sum: '<S261>/Subtract1' */
          rtb_Saturation_o4 -= FMS_ConstB.d_cy;

          /* Signum: '<S261>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S261>/Sign1' */

          /* Signum: '<S261>/Sign2' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S261>/Sign2' */

          /* Sum: '<S261>/Add5' incorporates:
           *  Gain: '<S261>/Gain2'
           *  Product: '<S261>/Multiply4'
           *  Sum: '<S261>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation_o4) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S261>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_cy;

          /* Sum: '<S261>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_cy;

          /* Product: '<S261>/Divide' */
          rtb_Divide_jq = rtb_u_b / FMS_ConstB.d_cy;

          /* Signum: '<S261>/Sign5' incorporates:
           *  Signum: '<S261>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_ke = -1.0F;

            /* Signum: '<S261>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_ke = 1.0F;

            /* Signum: '<S261>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_ke = rtb_u_b;

            /* Signum: '<S261>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S261>/Sign5' */

          /* Product: '<S260>/Multiply1' incorporates:
           *  Constant: '<S260>/const1'
           *  DiscreteIntegrator: '<S258>/Integrator'
           */
          rtb_u_b = FMS_DW.Integrator_DSTATE_oc * 0.05F;

          /* Sum: '<S260>/Add' incorporates:
           *  DiscreteIntegrator: '<S258>/Integrator1'
           *  Sum: '<S258>/Subtract'
           */
          rtb_Subtract1_o = (FMS_DW.Integrator1_DSTATE_ew - rtb_Subtract1_o) +
            rtb_u_b;

          /* Signum: '<S260>/Sign' */
          if (rtb_Subtract1_o < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else if (rtb_Subtract1_o > 0.0F) {
            rtb_Saturation1_p5 = 1.0F;
          } else {
            rtb_Saturation1_p5 = rtb_Subtract1_o;
          }

          /* End of Signum: '<S260>/Sign' */

          /* Sum: '<S260>/Add2' incorporates:
           *  Abs: '<S260>/Abs'
           *  Gain: '<S260>/Gain'
           *  Gain: '<S260>/Gain1'
           *  Product: '<S260>/Multiply2'
           *  Product: '<S260>/Multiply3'
           *  Sqrt: '<S260>/Sqrt'
           *  Sum: '<S260>/Add1'
           *  Sum: '<S260>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Subtract1_o) + FMS_ConstB.d_omy) *
                     FMS_ConstB.d_omy) - FMS_ConstB.d_omy) * 0.5F *
            rtb_Saturation1_p5 + rtb_u_b;

          /* Sum: '<S260>/Add4' */
          rtb_u_b += rtb_Subtract1_o - d;

          /* Sum: '<S260>/Add3' */
          rtb_Saturation1_p5 = rtb_Subtract1_o + FMS_ConstB.d_omy;

          /* Sum: '<S260>/Subtract1' */
          rtb_Subtract1_o -= FMS_ConstB.d_omy;

          /* Signum: '<S260>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S260>/Sign1' */

          /* Signum: '<S260>/Sign2' */
          if (rtb_Subtract1_o < 0.0F) {
            rtb_Subtract1_o = -1.0F;
          } else {
            if (rtb_Subtract1_o > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            }
          }

          /* End of Signum: '<S260>/Sign2' */

          /* Sum: '<S260>/Add5' incorporates:
           *  Gain: '<S260>/Gain2'
           *  Product: '<S260>/Multiply4'
           *  Sum: '<S260>/Subtract2'
           */
          d += (rtb_Saturation1_p5 - rtb_Subtract1_o) * 0.5F * rtb_u_b;

          /* Update for DiscreteIntegrator: '<S259>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S259>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_li += 0.004F * FMS_DW.Integrator_DSTATE_fk;

          /* Update for DiscreteIntegrator: '<S258>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S258>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_ew += 0.004F * FMS_DW.Integrator_DSTATE_oc;

          /* Signum: '<S261>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S261>/Sign3' */

          /* Signum: '<S261>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S261>/Sign4' */

          /* Update for DiscreteIntegrator: '<S259>/Integrator' incorporates:
           *  Constant: '<S261>/const'
           *  Gain: '<S261>/Gain3'
           *  Product: '<S261>/Multiply5'
           *  Product: '<S261>/Multiply6'
           *  Sum: '<S261>/Subtract4'
           *  Sum: '<S261>/Subtract5'
           *  Sum: '<S261>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_fk += ((rtb_Divide_jq - rtb_Sign5_ke) *
            FMS_ConstB.Gain4_ka * ((rtb_Saturation_ga - rtb_Saturation1_d) *
            0.5F) - rtb_Saturation_o4 * 39.224F) * 0.004F;

          /* Sum: '<S260>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_omy;

          /* Sum: '<S260>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_omy;

          /* Signum: '<S260>/Sign5' incorporates:
           *  Signum: '<S260>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S260>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S260>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S260>/Sign6' */
            rtb_Subtract1_o = d;
          }

          /* End of Signum: '<S260>/Sign5' */

          /* Signum: '<S260>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S260>/Sign3' */

          /* Signum: '<S260>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S260>/Sign4' */

          /* Update for DiscreteIntegrator: '<S258>/Integrator' incorporates:
           *  Constant: '<S260>/const'
           *  Gain: '<S260>/Gain3'
           *  Product: '<S260>/Divide'
           *  Product: '<S260>/Multiply5'
           *  Product: '<S260>/Multiply6'
           *  Sum: '<S260>/Subtract4'
           *  Sum: '<S260>/Subtract5'
           *  Sum: '<S260>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_oc += ((d / FMS_ConstB.d_omy -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_d5 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 2.9418F) * 0.004F;

          /* End of Outputs for SubSystem: '<S246>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S249>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S249>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S126>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S126>/Unknown' incorporates:
           *  ActionPort: '<S248>/Action Port'
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
            /* Disable for SwitchCase: '<S181>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S166>/Switch Case' */
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
             *  DiscreteIntegrator: '<S239>/Integrator'
             *  DiscreteIntegrator: '<S239>/Integrator1'
             *  DiscreteIntegrator: '<S240>/Integrator'
             *  DiscreteIntegrator: '<S240>/Integrator1'
             *  DiscreteIntegrator: '<S244>/Integrator'
             *  DiscreteIntegrator: '<S244>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_av = 0.0F;
            FMS_DW.Integrator1_DSTATE_oo = 0.0F;
            FMS_DW.Integrator1_DSTATE_jv = 0.0F;
            FMS_DW.Integrator_DSTATE_jp = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Stabilize' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          /* Product: '<S241>/Multiply1' incorporates:
           *  Constant: '<S241>/const1'
           *  DiscreteIntegrator: '<S239>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S237>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S237>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S241>/Add' incorporates:
           *  DiscreteIntegrator: '<S239>/Integrator1'
           *  Gain: '<S234>/Gain'
           *  Gain: '<S237>/Gain'
           *  Sum: '<S239>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) +
            rtb_P_f_idx_0;

          /* Signum: '<S241>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S241>/Sign' */

          /* Sum: '<S241>/Add2' incorporates:
           *  Abs: '<S241>/Abs'
           *  Gain: '<S241>/Gain'
           *  Gain: '<S241>/Gain1'
           *  Product: '<S241>/Multiply2'
           *  Product: '<S241>/Multiply3'
           *  Sqrt: '<S241>/Sqrt'
           *  Sum: '<S241>/Add1'
           *  Sum: '<S241>/Subtract'
           */
          rtb_Divide_jq = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_ga + rtb_P_f_idx_0;

          /* Sum: '<S241>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Divide_jq) +
            rtb_P_f_idx_0;

          /* Sum: '<S241>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S241>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

          /* Signum: '<S241>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S241>/Sign1' */

          /* Signum: '<S241>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S241>/Sign2' */

          /* Sum: '<S241>/Add5' incorporates:
           *  Gain: '<S241>/Gain2'
           *  Product: '<S241>/Multiply4'
           *  Sum: '<S241>/Subtract2'
           */
          rtb_Divide_jq += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S132>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S132>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S132>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S239>/Integrator1'
           *  DiscreteIntegrator: '<S240>/Integrator1'
           *  DiscreteIntegrator: '<S244>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_oo;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_jv;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S236>/Saturation' incorporates:
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

          /* End of Saturate: '<S236>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S132>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S236>/Constant5'
           *  Gain: '<S236>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S236>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_u_b), 65536.0F) + 1000U);

          /* Product: '<S245>/Multiply1' incorporates:
           *  Constant: '<S245>/const1'
           *  DiscreteIntegrator: '<S244>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_jp * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S243>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S243>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S245>/Add' incorporates:
           *  DiscreteIntegrator: '<S244>/Integrator1'
           *  Gain: '<S235>/Gain1'
           *  Gain: '<S243>/Gain'
           *  Sum: '<S244>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_jv - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_P_f_idx_0;

          /* Signum: '<S245>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Subtract1_o = rtb_u_b;
          }

          /* End of Signum: '<S245>/Sign' */

          /* Sum: '<S245>/Add2' incorporates:
           *  Abs: '<S245>/Abs'
           *  Gain: '<S245>/Gain'
           *  Gain: '<S245>/Gain1'
           *  Product: '<S245>/Multiply2'
           *  Product: '<S245>/Multiply3'
           *  Sqrt: '<S245>/Sqrt'
           *  Sum: '<S245>/Add1'
           *  Sum: '<S245>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_mq) *
            FMS_ConstB.d_mq) - FMS_ConstB.d_mq) * 0.5F * rtb_Subtract1_o +
            rtb_P_f_idx_0;

          /* Sum: '<S245>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Saturation1_p5) + rtb_P_f_idx_0;

          /* Sum: '<S245>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_mq;

          /* Sum: '<S245>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_mq;

          /* Signum: '<S245>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S245>/Sign1' */

          /* Signum: '<S245>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S245>/Sign2' */

          /* Sum: '<S245>/Add5' incorporates:
           *  Gain: '<S245>/Gain2'
           *  Product: '<S245>/Multiply4'
           *  Sum: '<S245>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S245>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_mq;

          /* Sum: '<S245>/Subtract3' */
          rtb_Saturation1_d = rtb_Saturation1_p5 - FMS_ConstB.d_mq;

          /* Product: '<S245>/Divide' */
          rtb_Divide_m1i = rtb_Saturation1_p5 / FMS_ConstB.d_mq;

          /* Signum: '<S245>/Sign5' incorporates:
           *  Signum: '<S245>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Sign5_p2 = -1.0F;

            /* Signum: '<S245>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Sign5_p2 = 1.0F;

            /* Signum: '<S245>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_p2 = rtb_Saturation1_p5;

            /* Signum: '<S245>/Sign6' */
            rtb_Saturation_o4 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S245>/Sign5' */

          /* Product: '<S242>/Multiply1' incorporates:
           *  Constant: '<S242>/const1'
           *  DiscreteIntegrator: '<S240>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S238>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S238>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S242>/Add' incorporates:
           *  DiscreteIntegrator: '<S240>/Integrator1'
           *  Gain: '<S234>/Gain1'
           *  Gain: '<S238>/Gain'
           *  Sum: '<S240>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_oo - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S242>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Subtract1_o = rtb_u_b;
          }

          /* End of Signum: '<S242>/Sign' */

          /* Sum: '<S242>/Add2' incorporates:
           *  Abs: '<S242>/Abs'
           *  Gain: '<S242>/Gain'
           *  Gain: '<S242>/Gain1'
           *  Product: '<S242>/Multiply2'
           *  Product: '<S242>/Multiply3'
           *  Sqrt: '<S242>/Sqrt'
           *  Sum: '<S242>/Add1'
           *  Sum: '<S242>/Subtract'
           */
          rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_my) *
            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F * rtb_Subtract1_o +
            rtb_Saturation1_p5;

          /* Sum: '<S242>/Add4' */
          rtb_Subtract1_o = (rtb_u_b - rtb_P_f_idx_0) + rtb_Saturation1_p5;

          /* Sum: '<S242>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_my;

          /* Sum: '<S242>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_my;

          /* Signum: '<S242>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S242>/Sign1' */

          /* Signum: '<S242>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S242>/Sign2' */

          /* Sum: '<S242>/Add5' incorporates:
           *  Gain: '<S242>/Gain2'
           *  Product: '<S242>/Multiply4'
           *  Sum: '<S242>/Subtract2'
           */
          rtb_P_f_idx_0 += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F *
            rtb_Subtract1_o;

          /* Update for DiscreteIntegrator: '<S239>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S239>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S241>/Subtract3' */
          rtb_Saturation1_p5 = rtb_Divide_jq - FMS_ConstB.d_ny;

          /* Sum: '<S241>/Add6' */
          d = rtb_Divide_jq + FMS_ConstB.d_ny;

          /* Signum: '<S241>/Sign5' incorporates:
           *  Signum: '<S241>/Sign6'
           */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Subtract1_o = -1.0F;

            /* Signum: '<S241>/Sign6' */
            rtb_Sign5_ke = -1.0F;
          } else if (rtb_Divide_jq > 0.0F) {
            rtb_Subtract1_o = 1.0F;

            /* Signum: '<S241>/Sign6' */
            rtb_Sign5_ke = 1.0F;
          } else {
            rtb_Subtract1_o = rtb_Divide_jq;

            /* Signum: '<S241>/Sign6' */
            rtb_Sign5_ke = rtb_Divide_jq;
          }

          /* End of Signum: '<S241>/Sign5' */

          /* Signum: '<S241>/Sign3' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S241>/Sign3' */

          /* Signum: '<S241>/Sign4' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S241>/Sign4' */

          /* Update for DiscreteIntegrator: '<S239>/Integrator' incorporates:
           *  Constant: '<S241>/const'
           *  Gain: '<S241>/Gain3'
           *  Product: '<S241>/Divide'
           *  Product: '<S241>/Multiply5'
           *  Product: '<S241>/Multiply6'
           *  Sum: '<S241>/Subtract4'
           *  Sum: '<S241>/Subtract5'
           *  Sum: '<S241>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((rtb_Divide_jq / FMS_ConstB.d_ny -
            rtb_Subtract1_o) * FMS_ConstB.Gain4_ko * ((d - rtb_Saturation1_p5) *
            0.5F) - rtb_Sign5_ke * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S240>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S240>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_oo += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S244>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S244>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jv += 0.004F * FMS_DW.Integrator_DSTATE_jp;

          /* Signum: '<S245>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S245>/Sign3' */

          /* Signum: '<S245>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S245>/Sign4' */

          /* Update for DiscreteIntegrator: '<S244>/Integrator' incorporates:
           *  Constant: '<S245>/const'
           *  Gain: '<S245>/Gain3'
           *  Product: '<S245>/Multiply5'
           *  Product: '<S245>/Multiply6'
           *  Sum: '<S245>/Subtract4'
           *  Sum: '<S245>/Subtract5'
           *  Sum: '<S245>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_jp += ((rtb_Divide_m1i - rtb_Sign5_p2) *
            FMS_ConstB.Gain4_b * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 15.707963F) * 0.004F;

          /* Sum: '<S242>/Subtract3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 - FMS_ConstB.d_my;

          /* Sum: '<S242>/Add6' */
          rtb_Saturation1_d = rtb_P_f_idx_0 + FMS_ConstB.d_my;

          /* Signum: '<S242>/Sign5' incorporates:
           *  Signum: '<S242>/Sign6'
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S242>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S242>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_P_f_idx_0;

            /* Signum: '<S242>/Sign6' */
            rtb_Subtract1_o = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S242>/Sign5' */

          /* Signum: '<S242>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S242>/Sign3' */

          /* Signum: '<S242>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S242>/Sign4' */

          /* Update for DiscreteIntegrator: '<S240>/Integrator' incorporates:
           *  Constant: '<S242>/const'
           *  Gain: '<S242>/Gain3'
           *  Product: '<S242>/Divide'
           *  Product: '<S242>/Multiply5'
           *  Product: '<S242>/Multiply6'
           *  Sum: '<S242>/Subtract4'
           *  Sum: '<S242>/Subtract5'
           *  Sum: '<S242>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_P_f_idx_0 / FMS_ConstB.d_my -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_k2 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 12.566371F) * 0.004F;

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
             *  DiscreteIntegrator: '<S158>/Integrator'
             *  DiscreteIntegrator: '<S158>/Integrator1'
             *  DiscreteIntegrator: '<S159>/Integrator'
             *  DiscreteIntegrator: '<S159>/Integrator1'
             */
            FMS_DW.Integrator_DSTATE_hd = 0.0F;
            FMS_DW.Integrator1_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_jl = 0.0F;
            FMS_DW.Integrator1_DSTATE_hv = 0.0F;
            FMS_DW.Integrator1_DSTATE_ml = 0.0F;
            FMS_DW.Integrator_DSTATE_kn = 0.0F;
            FMS_DW.Integrator_DSTATE_k1 = 0.0F;
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
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_hd;

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
          rtb_Divide_m1i = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ar) * FMS_ConstB.d_ar) - FMS_ConstB.d_ar) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S147>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Divide_m1i) +
            rtb_Saturation_ga;

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
          rtb_Divide_m1i += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
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
          if (FMS_DW.Integrator1_DSTATE_hv > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_hv < 2.5F) {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = 2.5F;
          } else {
            /* BusAssignment: '<S130>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_hv;
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

          /* Switch: '<S157>/Switch' incorporates:
           *  Constant: '<S157>/Constant'
           *  Constant: '<S157>/Constant1'
           *  Constant: '<S157>/Constant2'
           *  Product: '<S157>/Multiply'
           *  Product: '<S157>/Multiply1'
           *  Sum: '<S157>/Subtract'
           *  Sum: '<S157>/Subtract1'
           *  Sum: '<S157>/Sum'
           *  Sum: '<S157>/Sum1'
           */
          if (rtb_Saturation_ga >= 0.0F) {
            rtb_Saturation1_p5 = (FMS_PARAM.FW_SPEED_MAX -
                                  FMS_PARAM.FW_CRUISE_SPEED) * rtb_Saturation_ga
              + FMS_PARAM.FW_CRUISE_SPEED;
          } else {
            rtb_Saturation1_p5 = (FMS_PARAM.FW_CRUISE_SPEED -
                                  FMS_PARAM.FW_SPEED_MIN) * rtb_Saturation_ga +
              FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S157>/Switch' */

          /* Product: '<S160>/Multiply1' incorporates:
           *  Constant: '<S160>/const1'
           *  DiscreteIntegrator: '<S158>/Integrator'
           */
          rtb_a_m = FMS_DW.Integrator_DSTATE_kn * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S137>/Switch' incorporates:
           *  Constant: '<S156>/Constant'
           *  DiscreteIntegrator: '<S159>/Integrator1'
           *  RelationalOperator: '<S156>/Compare'
           */
          if (FMS_B.vtol_state == VTOLState_ForwardTrans) {
            rtb_u_b = FMS_DW.Integrator1_DSTATE_ml;
          } else {
            rtb_u_b = rtb_Saturation1_p5;
          }

          /* End of Switch: '<S137>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S160>/Add' incorporates:
           *  DiscreteIntegrator: '<S158>/Integrator1'
           *  Sum: '<S158>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_hv - rtb_u_b) + rtb_a_m;

          /* Signum: '<S160>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
          }

          /* End of Signum: '<S160>/Sign' */

          /* Sum: '<S160>/Add2' incorporates:
           *  Abs: '<S160>/Abs'
           *  Gain: '<S160>/Gain'
           *  Gain: '<S160>/Gain1'
           *  Product: '<S160>/Multiply2'
           *  Product: '<S160>/Multiply3'
           *  Sqrt: '<S160>/Sqrt'
           *  Sum: '<S160>/Add1'
           *  Sum: '<S160>/Subtract'
           */
          rtb_Subtract3_p = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_nd) *
            FMS_ConstB.d_nd) - FMS_ConstB.d_nd) * 0.5F * rtb_Add4_pb + rtb_a_m;

          /* Sum: '<S160>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Subtract3_p) + rtb_a_m;

          /* Sum: '<S160>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_nd;

          /* Sum: '<S160>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_nd;

          /* Signum: '<S160>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S160>/Sign1' */

          /* Signum: '<S160>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S160>/Sign2' */

          /* Sum: '<S160>/Add5' incorporates:
           *  Gain: '<S160>/Gain2'
           *  Product: '<S160>/Multiply4'
           *  Sum: '<S160>/Subtract2'
           */
          rtb_Subtract3_p += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S160>/Add6' */
          rtb_Saturation_ga = rtb_Subtract3_p + FMS_ConstB.d_nd;

          /* Sum: '<S160>/Subtract3' */
          rtb_Saturation1_d = rtb_Subtract3_p - FMS_ConstB.d_nd;

          /* Product: '<S160>/Divide' */
          rtb_Divide_p5 = rtb_Subtract3_p / FMS_ConstB.d_nd;

          /* Signum: '<S160>/Sign5' incorporates:
           *  Signum: '<S160>/Sign6'
           */
          if (rtb_Subtract3_p < 0.0F) {
            rtb_Sign5_g42 = -1.0F;

            /* Signum: '<S160>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Subtract3_p > 0.0F) {
            rtb_Sign5_g42 = 1.0F;

            /* Signum: '<S160>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_g42 = rtb_Subtract3_p;

            /* Signum: '<S160>/Sign6' */
            rtb_Saturation_o4 = rtb_Subtract3_p;
          }

          /* End of Signum: '<S160>/Sign5' */

          /* Product: '<S161>/Multiply1' incorporates:
           *  Constant: '<S161>/const1'
           *  DiscreteIntegrator: '<S159>/Integrator'
           */
          rtb_Subtract3_p = FMS_DW.Integrator_DSTATE_k1 * 0.05F;

          /* Sum: '<S161>/Add' incorporates:
           *  DiscreteIntegrator: '<S159>/Integrator1'
           *  Sum: '<S159>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_ml - rtb_Saturation1_p5) +
            rtb_Subtract3_p;

          /* Signum: '<S161>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
          }

          /* End of Signum: '<S161>/Sign' */

          /* Sum: '<S161>/Add2' incorporates:
           *  Abs: '<S161>/Abs'
           *  Gain: '<S161>/Gain'
           *  Gain: '<S161>/Gain1'
           *  Product: '<S161>/Multiply2'
           *  Product: '<S161>/Multiply3'
           *  Sqrt: '<S161>/Sqrt'
           *  Sum: '<S161>/Add1'
           *  Sum: '<S161>/Subtract'
           */
          rtb_a_m = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_ndm) *
                           FMS_ConstB.d_ndm) - FMS_ConstB.d_ndm) * 0.5F *
            rtb_Add4_pb + rtb_Subtract3_p;

          /* Sum: '<S161>/Add4' */
          rtb_Subtract1_o = (rtb_u_b - rtb_a_m) + rtb_Subtract3_p;

          /* Sum: '<S161>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_ndm;

          /* Sum: '<S161>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_ndm;

          /* Signum: '<S161>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign1' */

          /* Signum: '<S161>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign2' */

          /* Sum: '<S161>/Add5' incorporates:
           *  Gain: '<S161>/Gain2'
           *  Product: '<S161>/Multiply4'
           *  Sum: '<S161>/Subtract2'
           */
          rtb_a_m += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Subtract1_o;

          /* Sum: '<S161>/Add6' */
          rtb_Saturation1_p5 = rtb_a_m + FMS_ConstB.d_ndm;

          /* Sum: '<S161>/Subtract3' */
          d = rtb_a_m - FMS_ConstB.d_ndm;

          /* Product: '<S161>/Divide' */
          rtb_Divide_i = rtb_a_m / FMS_ConstB.d_ndm;

          /* Signum: '<S161>/Sign5' incorporates:
           *  Signum: '<S161>/Sign6'
           */
          if (rtb_a_m < 0.0F) {
            rtb_Sign5_ij = -1.0F;

            /* Signum: '<S161>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_a_m > 0.0F) {
            rtb_Sign5_ij = 1.0F;

            /* Signum: '<S161>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Sign5_ij = rtb_a_m;

            /* Signum: '<S161>/Sign6' */
            rtb_Subtract1_o = rtb_a_m;
          }

          /* End of Signum: '<S161>/Sign5' */

          /* Product: '<S155>/Multiply1' incorporates:
           *  Constant: '<S155>/const1'
           *  DiscreteIntegrator: '<S154>/Integrator'
           */
          rtb_Subtract3_p = FMS_DW.Integrator_DSTATE_er * 0.02F;

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
            rtb_Subtract3_p;

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
          rtb_a_m = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_cb) *
                           FMS_ConstB.d_cb) - FMS_ConstB.d_cb) * 0.5F *
            rtb_Add4_pb + rtb_Subtract3_p;

          /* Sum: '<S155>/Add4' */
          rtb_Sign5_ke = (rtb_u_b - rtb_a_m) + rtb_Subtract3_p;

          /* Sum: '<S155>/Add3' */
          rtb_Divide_jq = rtb_u_b + FMS_ConstB.d_cb;

          /* Sum: '<S155>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_cb;

          /* Signum: '<S155>/Sign1' */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Divide_jq = -1.0F;
          } else {
            if (rtb_Divide_jq > 0.0F) {
              rtb_Divide_jq = 1.0F;
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
          rtb_a_m += (rtb_Divide_jq - rtb_u_b) * 0.5F * rtb_Sign5_ke;

          /* Sum: '<S155>/Add6' */
          rtb_Divide_jq = rtb_a_m + FMS_ConstB.d_cb;

          /* Sum: '<S155>/Subtract3' */
          rtb_Sign5_p2 = rtb_a_m - FMS_ConstB.d_cb;

          /* Product: '<S155>/Divide' */
          rtb_Divide_pq = rtb_a_m / FMS_ConstB.d_cb;

          /* Signum: '<S155>/Sign5' incorporates:
           *  Signum: '<S155>/Sign6'
           */
          if (rtb_a_m < 0.0F) {
            rtb_Sign5_a1 = -1.0F;

            /* Signum: '<S155>/Sign6' */
            rtb_Sign5_ke = -1.0F;
          } else if (rtb_a_m > 0.0F) {
            rtb_Sign5_a1 = 1.0F;

            /* Signum: '<S155>/Sign6' */
            rtb_Sign5_ke = 1.0F;
          } else {
            rtb_Sign5_a1 = rtb_a_m;

            /* Signum: '<S155>/Sign6' */
            rtb_Sign5_ke = rtb_a_m;
          }

          /* End of Signum: '<S155>/Sign5' */

          /* Product: '<S152>/Multiply1' incorporates:
           *  Constant: '<S152>/const1'
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          rtb_Subtract3_p = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

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
            rtb_Subtract3_p;

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
          rtb_a_m = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_bi) *
                           FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Add4_pb + rtb_Subtract3_p;

          /* Sum: '<S152>/Add4' */
          rtb_Add4_pb = (rtb_u_b - rtb_a_m) + rtb_Subtract3_p;

          /* Sum: '<S152>/Add3' */
          rtb_Subtract3_p = rtb_u_b + FMS_ConstB.d_bi;

          /* Sum: '<S152>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_bi;

          /* Signum: '<S152>/Sign1' */
          if (rtb_Subtract3_p < 0.0F) {
            rtb_Subtract3_p = -1.0F;
          } else {
            if (rtb_Subtract3_p > 0.0F) {
              rtb_Subtract3_p = 1.0F;
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
          rtb_a_m += (rtb_Subtract3_p - rtb_u_b) * 0.5F * rtb_Add4_pb;

          /* Sum: '<S147>/Subtract3' */
          rtb_Subtract3_p = rtb_Divide_m1i - FMS_ConstB.d_ar;

          /* Sum: '<S147>/Add6' */
          rtb_Add4_pb = rtb_Divide_m1i + FMS_ConstB.d_ar;

          /* Signum: '<S147>/Sign5' incorporates:
           *  Signum: '<S147>/Sign6'
           */
          if (rtb_Divide_m1i < 0.0F) {
            rtb_u_b = -1.0F;

            /* Signum: '<S147>/Sign6' */
            y = -1.0F;
          } else if (rtb_Divide_m1i > 0.0F) {
            rtb_u_b = 1.0F;

            /* Signum: '<S147>/Sign6' */
            y = 1.0F;
          } else {
            rtb_u_b = rtb_Divide_m1i;

            /* Signum: '<S147>/Sign6' */
            y = rtb_Divide_m1i;
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
          if (rtb_Subtract3_p < 0.0F) {
            rtb_Subtract3_p = -1.0F;
          } else {
            if (rtb_Subtract3_p > 0.0F) {
              rtb_Subtract3_p = 1.0F;
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
          FMS_DW.Integrator_DSTATE_hd += ((rtb_Divide_m1i / FMS_ConstB.d_ar -
            rtb_u_b) * FMS_ConstB.Gain4_am * ((rtb_Add4_pb - rtb_Subtract3_p) *
            0.5F) - y * 78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S142>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_a += 0.004F * rtb_P_f_idx_0;

          /* Update for DiscreteIntegrator: '<S151>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S154>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S154>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jl += 0.004F * FMS_DW.Integrator_DSTATE_er;

          /* Update for DiscreteIntegrator: '<S158>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S158>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_hv += 0.004F * FMS_DW.Integrator_DSTATE_kn;

          /* Update for DiscreteIntegrator: '<S159>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S159>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_ml += 0.004F * FMS_DW.Integrator_DSTATE_k1;

          /* Signum: '<S160>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S160>/Sign3' */

          /* Signum: '<S160>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S160>/Sign4' */

          /* Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
           *  Constant: '<S160>/const'
           *  Gain: '<S160>/Gain3'
           *  Product: '<S160>/Multiply5'
           *  Product: '<S160>/Multiply6'
           *  Sum: '<S160>/Subtract4'
           *  Sum: '<S160>/Subtract5'
           *  Sum: '<S160>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_kn += ((rtb_Divide_p5 - rtb_Sign5_g42) *
            FMS_ConstB.Gain4_m * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 39.224F) * 0.004F;

          /* Signum: '<S161>/Sign3' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign3' */

          /* Signum: '<S161>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign4' */

          /* Update for DiscreteIntegrator: '<S159>/Integrator' incorporates:
           *  Constant: '<S161>/const'
           *  Gain: '<S161>/Gain3'
           *  Product: '<S161>/Multiply5'
           *  Product: '<S161>/Multiply6'
           *  Sum: '<S161>/Subtract4'
           *  Sum: '<S161>/Subtract5'
           *  Sum: '<S161>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k1 += ((rtb_Divide_i - rtb_Sign5_ij) *
            FMS_ConstB.Gain4_co * ((rtb_Saturation1_p5 - d) * 0.5F) -
            rtb_Subtract1_o * 2.9418F) * 0.004F;

          /* Signum: '<S155>/Sign3' */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Divide_jq = -1.0F;
          } else {
            if (rtb_Divide_jq > 0.0F) {
              rtb_Divide_jq = 1.0F;
            }
          }

          /* End of Signum: '<S155>/Sign3' */

          /* Signum: '<S155>/Sign4' */
          if (rtb_Sign5_p2 < 0.0F) {
            rtb_Sign5_p2 = -1.0F;
          } else {
            if (rtb_Sign5_p2 > 0.0F) {
              rtb_Sign5_p2 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_er += ((rtb_Divide_pq - rtb_Sign5_a1) *
            FMS_ConstB.Gain4_ci * ((rtb_Divide_jq - rtb_Sign5_p2) * 0.5F) -
            rtb_Sign5_ke * 15.707963F) * 0.004F;

          /* Sum: '<S152>/Subtract3' */
          rtb_Saturation_ga = rtb_a_m - FMS_ConstB.d_bi;

          /* Sum: '<S152>/Add6' */
          rtb_Saturation1_d = rtb_a_m + FMS_ConstB.d_bi;

          /* Signum: '<S152>/Sign5' incorporates:
           *  Signum: '<S152>/Sign6'
           */
          if (rtb_a_m < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S152>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_a_m > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S152>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_a_m;

            /* Signum: '<S152>/Sign6' */
            rtb_Subtract1_o = rtb_a_m;
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
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_a_m / FMS_ConstB.d_bi -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_d1 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S125>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S125>/Position' incorporates:
             *  ActionPort: '<S131>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S125>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S170>/Integrator'
             *  DiscreteIntegrator: '<S170>/Integrator1'
             *  DiscreteIntegrator: '<S179>/Integrator'
             *  DiscreteIntegrator: '<S179>/Integrator1'
             *  DiscreteIntegrator: '<S229>/Integrator'
             *  DiscreteIntegrator: '<S229>/Integrator1'
             *  DiscreteIntegrator: '<S231>/Integrator'
             *  DiscreteIntegrator: '<S231>/Integrator1'
             */
            FMS_DW.Integrator_DSTATE_c5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_i = 0.0F;
            FMS_DW.Integrator1_DSTATE_l5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_nd = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S125>/Position' */

            /* SystemReset for IfAction SubSystem: '<S125>/Position' incorporates:
             *  ActionPort: '<S131>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S125>/Switch Case' incorporates:
             *  Chart: '<S167>/Motion Status'
             *  Chart: '<S182>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState);

            /* End of SystemReset for SubSystem: '<S125>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Position' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          /* Trigonometry: '<S227>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S227>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S227>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S227>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S227>/Gain' incorporates:
           *  Gain: '<S226>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S227>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S227>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S227>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S227>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S227>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S167>/Motion Status' incorporates:
           *  Abs: '<S167>/Abs'
           *  Abs: '<S167>/Abs1'
           *  Constant: '<S176>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S176>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S182>/Multiply' incorporates:
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

          /* End of Product: '<S182>/Multiply' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S182>/Motion State' incorporates:
           *  Abs: '<S182>/Abs'
           *  Abs: '<S182>/Abs1'
           *  Abs: '<S182>/Abs2'
           *  Constant: '<S223>/Constant'
           *  Constant: '<S224>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Logic: '<S182>/Logical Operator'
           *  RelationalOperator: '<S223>/Compare'
           *  RelationalOperator: '<S224>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ)
                          || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
                              FMS_PARAM.YAW_DZ), fabsf
                          (rtb_MatrixConcatenate1_a_0[0]), &rtb_state_fg,
                          &FMS_DW.sf_MotionState);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S181>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S181>/Hold Control' incorporates:
               *  ActionPort: '<S184>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S181>/Switch Case' */
              FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_b,
                &FMS_DW.HoldControl_b);

              /* End of SystemReset for SubSystem: '<S181>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S181>/Hold Control' incorporates:
             *  ActionPort: '<S184>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_b(rtb_Divide_bu, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                              FMS_U.INS_Out.vd, FMS_U.INS_Out.psi,
                              FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              &FMS_B.Merge_be, &FMS_ConstB.HoldControl_b,
                              &FMS_DW.HoldControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S181>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S181>/Brake Control' incorporates:
             *  ActionPort: '<S183>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_be);

            /* End of Outputs for SubSystem: '<S181>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S181>/Move Control' incorporates:
             *  ActionPort: '<S185>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S220>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S220>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S185>/Gain6' incorporates:
             *  Gain: '<S220>/Gain'
             */
            FMS_B.Merge_be = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
              FMS_PARAM.FW_ACC_Y_LIM;

            /* End of Outputs for SubSystem: '<S181>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S181>/Switch Case' */

          /* SwitchCase: '<S166>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S166>/Hold Control' incorporates:
               *  ActionPort: '<S168>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S166>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S166>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S166>/Hold Control' incorporates:
             *  ActionPort: '<S168>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S166>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S166>/Move Control' incorporates:
               *  ActionPort: '<S169>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S166>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S166>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S166>/Move Control' incorporates:
             *  ActionPort: '<S169>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S166>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S166>/Switch Case' */

          /* DiscreteIntegrator: '<S170>/Integrator' */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_c5;

          /* Product: '<S175>/Multiply1' incorporates:
           *  Constant: '<S175>/const1'
           *  DiscreteIntegrator: '<S170>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_c5 * 0.05F;

          /* Saturate: '<S166>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_u_b = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S166>/Saturation1' */

          /* Sum: '<S175>/Add' incorporates:
           *  DiscreteIntegrator: '<S170>/Integrator1'
           *  Sum: '<S170>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_i - rtb_u_b) +
            rtb_Saturation1_p5;

          /* Signum: '<S175>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
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
          rtb_Divide_m1i = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_av) * FMS_ConstB.d_av) - FMS_ConstB.d_av) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation1_p5;

          /* Sum: '<S175>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Divide_m1i) +
            rtb_Saturation1_p5;

          /* Sum: '<S175>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_av;

          /* Sum: '<S175>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_av;

          /* Signum: '<S175>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S175>/Sign1' */

          /* Signum: '<S175>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S175>/Sign2' */

          /* Sum: '<S175>/Add5' incorporates:
           *  Gain: '<S175>/Gain2'
           *  Product: '<S175>/Multiply4'
           *  Sum: '<S175>/Subtract2'
           */
          rtb_Divide_m1i += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S131>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S131>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S179>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l5;

          /* Saturate: '<S165>/Saturation1' */
          if (FMS_DW.Integrator1_DSTATE_nd > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_nd < 2.5F) {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = 2.5F;
          } else {
            /* BusAssignment: '<S131>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_nd;
          }

          /* End of Saturate: '<S165>/Saturation1' */

          /* Saturate: '<S181>/Saturation1' */
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

          /* End of Saturate: '<S181>/Saturation1' */

          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S170>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_i;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S165>/Saturation' incorporates:
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

          /* End of Saturate: '<S165>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S230>/Switch' incorporates:
           *  Constant: '<S230>/Constant'
           *  Constant: '<S230>/Constant1'
           *  Constant: '<S230>/Constant2'
           *  Product: '<S230>/Multiply'
           *  Product: '<S230>/Multiply1'
           *  Sum: '<S230>/Subtract'
           *  Sum: '<S230>/Subtract1'
           *  Sum: '<S230>/Sum'
           *  Sum: '<S230>/Sum1'
           */
          if (rtb_Saturation_ga >= 0.0F) {
            rtb_Saturation1_p5 = (FMS_PARAM.FW_SPEED_MAX -
                                  FMS_PARAM.FW_CRUISE_SPEED) * rtb_Saturation_ga
              + FMS_PARAM.FW_CRUISE_SPEED;
          } else {
            rtb_Saturation1_p5 = (FMS_PARAM.FW_CRUISE_SPEED -
                                  FMS_PARAM.FW_SPEED_MIN) * rtb_Saturation_ga +
              FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S230>/Switch' */

          /* Product: '<S233>/Multiply1' incorporates:
           *  Constant: '<S233>/const1'
           *  DiscreteIntegrator: '<S231>/Integrator'
           */
          rtb_a_m = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S165>/Switch' incorporates:
           *  Constant: '<S228>/Constant'
           *  DiscreteIntegrator: '<S229>/Integrator1'
           *  RelationalOperator: '<S228>/Compare'
           */
          if (FMS_B.vtol_state == VTOLState_ForwardTrans) {
            rtb_u_b = FMS_DW.Integrator1_DSTATE_o;
          } else {
            rtb_u_b = rtb_Saturation1_p5;
          }

          /* End of Switch: '<S165>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S233>/Add' incorporates:
           *  DiscreteIntegrator: '<S231>/Integrator1'
           *  Sum: '<S231>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_nd - rtb_u_b) + rtb_a_m;

          /* Signum: '<S233>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_ke = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_ke = 1.0F;
          } else {
            rtb_Sign5_ke = rtb_u_b;
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
          rtb_Divide_jq = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_ad) *
            FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F * rtb_Sign5_ke + rtb_a_m;

          /* Sum: '<S233>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Divide_jq) + rtb_a_m;

          /* Sum: '<S233>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_ad;

          /* Sum: '<S233>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_ad;

          /* Signum: '<S233>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
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
          rtb_Divide_jq += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S233>/Add6' */
          rtb_Saturation_ga = rtb_Divide_jq + FMS_ConstB.d_ad;

          /* Sum: '<S233>/Subtract3' */
          rtb_Saturation1_d = rtb_Divide_jq - FMS_ConstB.d_ad;

          /* Product: '<S233>/Divide' */
          rtb_Divide_p5 = rtb_Divide_jq / FMS_ConstB.d_ad;

          /* Signum: '<S233>/Sign5' incorporates:
           *  Signum: '<S233>/Sign6'
           */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Sign5_g42 = -1.0F;

            /* Signum: '<S233>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Divide_jq > 0.0F) {
            rtb_Sign5_g42 = 1.0F;

            /* Signum: '<S233>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_g42 = rtb_Divide_jq;

            /* Signum: '<S233>/Sign6' */
            rtb_Saturation_o4 = rtb_Divide_jq;
          }

          /* End of Signum: '<S233>/Sign5' */

          /* Product: '<S232>/Multiply1' incorporates:
           *  Constant: '<S232>/const1'
           *  DiscreteIntegrator: '<S229>/Integrator'
           */
          rtb_Divide_jq = FMS_DW.Integrator_DSTATE_j * 0.05F;

          /* Sum: '<S232>/Add' incorporates:
           *  DiscreteIntegrator: '<S229>/Integrator1'
           *  Sum: '<S229>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_o - rtb_Saturation1_p5) +
            rtb_Divide_jq;

          /* Signum: '<S232>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_ke = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_ke = 1.0F;
          } else {
            rtb_Sign5_ke = rtb_u_b;
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
          rtb_a_m = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_e) *
                           FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F *
            rtb_Sign5_ke + rtb_Divide_jq;

          /* Sum: '<S232>/Add4' */
          rtb_Subtract1_o = (rtb_u_b - rtb_a_m) + rtb_Divide_jq;

          /* Sum: '<S232>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_e;

          /* Sum: '<S232>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_e;

          /* Signum: '<S232>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign1' */

          /* Signum: '<S232>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign2' */

          /* Sum: '<S232>/Add5' incorporates:
           *  Gain: '<S232>/Gain2'
           *  Product: '<S232>/Multiply4'
           *  Sum: '<S232>/Subtract2'
           */
          rtb_a_m += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Subtract1_o;

          /* Sum: '<S232>/Add6' */
          rtb_Saturation1_p5 = rtb_a_m + FMS_ConstB.d_e;

          /* Sum: '<S232>/Subtract3' */
          d = rtb_a_m - FMS_ConstB.d_e;

          /* Product: '<S232>/Divide' */
          rtb_Divide_i = rtb_a_m / FMS_ConstB.d_e;

          /* Signum: '<S232>/Sign5' incorporates:
           *  Signum: '<S232>/Sign6'
           */
          if (rtb_a_m < 0.0F) {
            rtb_Sign5_ij = -1.0F;

            /* Signum: '<S232>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_a_m > 0.0F) {
            rtb_Sign5_ij = 1.0F;

            /* Signum: '<S232>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Sign5_ij = rtb_a_m;

            /* Signum: '<S232>/Sign6' */
            rtb_Subtract1_o = rtb_a_m;
          }

          /* End of Signum: '<S232>/Sign5' */

          /* Product: '<S180>/Multiply1' incorporates:
           *  Constant: '<S180>/const1'
           *  DiscreteIntegrator: '<S179>/Integrator'
           */
          rtb_Divide_jq = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S178>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S178>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S180>/Add' incorporates:
           *  DiscreteIntegrator: '<S179>/Integrator1'
           *  Gain: '<S163>/Gain1'
           *  Gain: '<S178>/Gain'
           *  Sum: '<S179>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_l5 - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_jq;

          /* Signum: '<S180>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_ke = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_ke = 1.0F;
          } else {
            rtb_Sign5_ke = rtb_u_b;
          }

          /* End of Signum: '<S180>/Sign' */

          /* Sum: '<S180>/Add2' incorporates:
           *  Abs: '<S180>/Abs'
           *  Gain: '<S180>/Gain'
           *  Gain: '<S180>/Gain1'
           *  Product: '<S180>/Multiply2'
           *  Product: '<S180>/Multiply3'
           *  Sqrt: '<S180>/Sqrt'
           *  Sum: '<S180>/Add1'
           *  Sum: '<S180>/Subtract'
           */
          rtb_a_m = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Sign5_ke + rtb_Divide_jq;

          /* Sum: '<S180>/Add4' */
          rtb_Sign5_ke = (rtb_u_b - rtb_a_m) + rtb_Divide_jq;

          /* Sum: '<S180>/Add3' */
          rtb_Divide_jq = rtb_u_b + FMS_ConstB.d_l;

          /* Sum: '<S180>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_l;

          /* Signum: '<S180>/Sign1' */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Divide_jq = -1.0F;
          } else {
            if (rtb_Divide_jq > 0.0F) {
              rtb_Divide_jq = 1.0F;
            }
          }

          /* End of Signum: '<S180>/Sign1' */

          /* Signum: '<S180>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S180>/Sign2' */

          /* Sum: '<S180>/Add5' incorporates:
           *  Gain: '<S180>/Gain2'
           *  Product: '<S180>/Multiply4'
           *  Sum: '<S180>/Subtract2'
           */
          rtb_a_m += (rtb_Divide_jq - rtb_u_b) * 0.5F * rtb_Sign5_ke;

          /* Sum: '<S175>/Subtract3' */
          rtb_Divide_jq = rtb_Divide_m1i - FMS_ConstB.d_av;

          /* Sum: '<S175>/Add6' */
          rtb_Sign5_p2 = rtb_Divide_m1i + FMS_ConstB.d_av;

          /* Signum: '<S175>/Sign5' incorporates:
           *  Signum: '<S175>/Sign6'
           */
          if (rtb_Divide_m1i < 0.0F) {
            rtb_Sign5_ke = -1.0F;

            /* Signum: '<S175>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (rtb_Divide_m1i > 0.0F) {
            rtb_Sign5_ke = 1.0F;

            /* Signum: '<S175>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Sign5_ke = rtb_Divide_m1i;

            /* Signum: '<S175>/Sign6' */
            rtb_u_b = rtb_Divide_m1i;
          }

          /* End of Signum: '<S175>/Sign5' */

          /* Signum: '<S175>/Sign3' */
          if (rtb_Sign5_p2 < 0.0F) {
            rtb_Sign5_p2 = -1.0F;
          } else {
            if (rtb_Sign5_p2 > 0.0F) {
              rtb_Sign5_p2 = 1.0F;
            }
          }

          /* End of Signum: '<S175>/Sign3' */

          /* Signum: '<S175>/Sign4' */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Divide_jq = -1.0F;
          } else {
            if (rtb_Divide_jq > 0.0F) {
              rtb_Divide_jq = 1.0F;
            }
          }

          /* End of Signum: '<S175>/Sign4' */

          /* Update for DiscreteIntegrator: '<S170>/Integrator' incorporates:
           *  Constant: '<S175>/const'
           *  Gain: '<S175>/Gain3'
           *  Product: '<S175>/Divide'
           *  Product: '<S175>/Multiply5'
           *  Product: '<S175>/Multiply6'
           *  Sum: '<S175>/Subtract4'
           *  Sum: '<S175>/Subtract5'
           *  Sum: '<S175>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c5 += ((rtb_Divide_m1i / FMS_ConstB.d_av -
            rtb_Sign5_ke) * FMS_ConstB.Gain4_p5 * ((rtb_Sign5_p2 - rtb_Divide_jq)
            * 0.5F) - rtb_u_b * 78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S170>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_i += 0.004F * rtb_P_f_idx_0;

          /* Update for DiscreteIntegrator: '<S179>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S179>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l5 += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S231>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S231>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Update for DiscreteIntegrator: '<S229>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S229>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_j;

          /* Signum: '<S233>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S233>/Sign3' */

          /* Signum: '<S233>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S233>/Sign4' */

          /* Update for DiscreteIntegrator: '<S231>/Integrator' incorporates:
           *  Constant: '<S233>/const'
           *  Gain: '<S233>/Gain3'
           *  Product: '<S233>/Multiply5'
           *  Product: '<S233>/Multiply6'
           *  Sum: '<S233>/Subtract4'
           *  Sum: '<S233>/Subtract5'
           *  Sum: '<S233>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Divide_p5 - rtb_Sign5_g42) *
            FMS_ConstB.Gain4_f * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 39.224F) * 0.004F;

          /* Signum: '<S232>/Sign3' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign3' */

          /* Signum: '<S232>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S232>/Sign4' */

          /* Update for DiscreteIntegrator: '<S229>/Integrator' incorporates:
           *  Constant: '<S232>/const'
           *  Gain: '<S232>/Gain3'
           *  Product: '<S232>/Multiply5'
           *  Product: '<S232>/Multiply6'
           *  Sum: '<S232>/Subtract4'
           *  Sum: '<S232>/Subtract5'
           *  Sum: '<S232>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_j += ((rtb_Divide_i - rtb_Sign5_ij) *
            FMS_ConstB.Gain4_o4 * ((rtb_Saturation1_p5 - d) * 0.5F) -
            rtb_Subtract1_o * 2.9418F) * 0.004F;

          /* Sum: '<S180>/Subtract3' */
          rtb_Saturation_ga = rtb_a_m - FMS_ConstB.d_l;

          /* Sum: '<S180>/Add6' */
          rtb_Saturation1_d = rtb_a_m + FMS_ConstB.d_l;

          /* Signum: '<S180>/Sign5' incorporates:
           *  Signum: '<S180>/Sign6'
           */
          if (rtb_a_m < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S180>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_a_m > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S180>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_a_m;

            /* Signum: '<S180>/Sign6' */
            rtb_Subtract1_o = rtb_a_m;
          }

          /* End of Signum: '<S180>/Sign5' */

          /* Signum: '<S180>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S180>/Sign3' */

          /* Signum: '<S180>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S180>/Sign4' */

          /* Update for DiscreteIntegrator: '<S179>/Integrator' incorporates:
           *  Constant: '<S180>/const'
           *  Gain: '<S180>/Gain3'
           *  Product: '<S180>/Divide'
           *  Product: '<S180>/Multiply5'
           *  Product: '<S180>/Multiply6'
           *  Sum: '<S180>/Subtract4'
           *  Sum: '<S180>/Subtract5'
           *  Sum: '<S180>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_a_m / FMS_ConstB.d_l -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ak * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 15.707963F) * 0.004F;

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
        /* DeadZone: '<S279>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S279>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S279>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S280>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S280>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S127>/Gain'
         *  Gain: '<S280>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S281>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S281>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S281>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S282>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S282>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S127>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S282>/Gain'
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
                      fabsf(rtb_MatrixConcatenate1_a_0[0]), &rtb_state_ej,
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
        FMS_BrakeControl(&FMS_B.Merge_n);

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
      rtb_Sign5_ke = FMS_DW.Integrator_DSTATE_e * 0.02F;

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
                 * rtb_u_b * (FMS_PARAM.YAW_RATE_LIM / 2.0F)) + rtb_Sign5_ke;

      /* Signum: '<S123>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_p5 = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_p5 = 1.0F;
      } else {
        rtb_Divide_p5 = rtb_u_b;
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
      rtb_Divide_jq = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_j) *
        FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Divide_p5 + rtb_Sign5_ke;

      /* Sum: '<S123>/Add4' */
      rtb_Saturation1_d = (rtb_u_b - rtb_Divide_jq) + rtb_Sign5_ke;

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
      rtb_Divide_jq += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

      /* Sum: '<S123>/Add6' */
      rtb_Saturation_ga = rtb_Divide_jq + FMS_ConstB.d_j;

      /* Sum: '<S123>/Subtract3' */
      rtb_Saturation1_d = rtb_Divide_jq - FMS_ConstB.d_j;

      /* Product: '<S123>/Divide' */
      rtb_P_f_idx_0 = rtb_Divide_jq / FMS_ConstB.d_j;

      /* Signum: '<S123>/Sign5' incorporates:
       *  Signum: '<S123>/Sign6'
       */
      if (rtb_Divide_jq < 0.0F) {
        rtb_Divide_m1i = -1.0F;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = -1.0F;
      } else if (rtb_Divide_jq > 0.0F) {
        rtb_Divide_m1i = 1.0F;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = 1.0F;
      } else {
        rtb_Divide_m1i = rtb_Divide_jq;

        /* Signum: '<S123>/Sign6' */
        rtb_Saturation_o4 = rtb_Divide_jq;
      }

      /* End of Signum: '<S123>/Sign5' */

      /* Product: '<S124>/Multiply1' incorporates:
       *  Constant: '<S124>/const1'
       *  DiscreteIntegrator: '<S121>/Integrator'
       */
      rtb_Divide_jq = FMS_DW.Integrator_DSTATE_l * 0.1F;

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
                  2.0F)) + rtb_Divide_jq;

      /* Signum: '<S124>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_p5 = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_p5 = 1.0F;
      } else {
        rtb_Divide_p5 = rtb_u_b;
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
      rtb_Sign5_ke = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_m2) *
                            FMS_ConstB.d_m2) - FMS_ConstB.d_m2) * 0.5F *
        rtb_Divide_p5 + rtb_Divide_jq;

      /* Sum: '<S124>/Add4' */
      rtb_Subtract1_o = (rtb_u_b - rtb_Sign5_ke) + rtb_Divide_jq;

      /* Sum: '<S124>/Add3' */
      rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_m2;

      /* Sum: '<S124>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_m2;

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
      rtb_Sign5_ke += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Subtract1_o;

      /* Sum: '<S124>/Add6' */
      rtb_Saturation1_p5 = rtb_Sign5_ke + FMS_ConstB.d_m2;

      /* Sum: '<S124>/Subtract3' */
      d = rtb_Sign5_ke - FMS_ConstB.d_m2;

      /* Product: '<S124>/Divide' */
      rtb_Sign5_p2 = rtb_Sign5_ke / FMS_ConstB.d_m2;

      /* Signum: '<S124>/Sign5' incorporates:
       *  Signum: '<S124>/Sign6'
       */
      if (rtb_Sign5_ke < 0.0F) {
        rtb_a_m = -1.0F;

        /* Signum: '<S124>/Sign6' */
        rtb_Subtract1_o = -1.0F;
      } else if (rtb_Sign5_ke > 0.0F) {
        rtb_a_m = 1.0F;

        /* Signum: '<S124>/Sign6' */
        rtb_Subtract1_o = 1.0F;
      } else {
        rtb_a_m = rtb_Sign5_ke;

        /* Signum: '<S124>/Sign6' */
        rtb_Subtract1_o = rtb_Sign5_ke;
      }

      /* End of Signum: '<S124>/Sign5' */

      /* Product: '<S122>/Multiply1' incorporates:
       *  Constant: '<S122>/const1'
       *  DiscreteIntegrator: '<S119>/Integrator'
       */
      rtb_Divide_jq = FMS_DW.Integrator_DSTATE_oy * 0.1F;

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
                 * rtb_u_b * (FMS_PARAM.VEL_XY_LIM / 2.0F)) + rtb_Divide_jq;

      /* Signum: '<S122>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_p5 = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_p5 = 1.0F;
      } else {
        rtb_Divide_p5 = rtb_u_b;
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
      rtb_Sign5_ke = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_oj) *
                            FMS_ConstB.d_oj) - FMS_ConstB.d_oj) * 0.5F *
        rtb_Divide_p5 + rtb_Divide_jq;

      /* Sum: '<S122>/Add4' */
      rtb_Divide_p5 = (rtb_u_b - rtb_Sign5_ke) + rtb_Divide_jq;

      /* Sum: '<S122>/Add3' */
      rtb_Divide_jq = rtb_u_b + FMS_ConstB.d_oj;

      /* Sum: '<S122>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_oj;

      /* Signum: '<S122>/Sign1' */
      if (rtb_Divide_jq < 0.0F) {
        rtb_Divide_jq = -1.0F;
      } else {
        if (rtb_Divide_jq > 0.0F) {
          rtb_Divide_jq = 1.0F;
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
      rtb_Sign5_ke += (rtb_Divide_jq - rtb_u_b) * 0.5F * rtb_Divide_p5;

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
      FMS_DW.Integrator_DSTATE_e += ((rtb_P_f_idx_0 - rtb_Divide_m1i) *
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
      FMS_DW.Integrator_DSTATE_l += ((rtb_Sign5_p2 - rtb_a_m) *
        FMS_ConstB.Gain4_ht * ((rtb_Saturation1_p5 - d) * 0.5F) -
        rtb_Subtract1_o * 39.224F) * 0.004F;

      /* Sum: '<S122>/Subtract3' */
      rtb_Saturation_ga = rtb_Sign5_ke - FMS_ConstB.d_oj;

      /* Sum: '<S122>/Add6' */
      rtb_Saturation1_d = rtb_Sign5_ke + FMS_ConstB.d_oj;

      /* Signum: '<S122>/Sign5' incorporates:
       *  Signum: '<S122>/Sign6'
       */
      if (rtb_Sign5_ke < 0.0F) {
        rtb_Saturation_o4 = -1.0F;

        /* Signum: '<S122>/Sign6' */
        rtb_Subtract1_o = -1.0F;
      } else if (rtb_Sign5_ke > 0.0F) {
        rtb_Saturation_o4 = 1.0F;

        /* Signum: '<S122>/Sign6' */
        rtb_Subtract1_o = 1.0F;
      } else {
        rtb_Saturation_o4 = rtb_Sign5_ke;

        /* Signum: '<S122>/Sign6' */
        rtb_Subtract1_o = rtb_Sign5_ke;
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
      FMS_DW.Integrator_DSTATE_oy += ((rtb_Sign5_ke / FMS_ConstB.d_oj -
        rtb_Saturation_o4) * FMS_ConstB.Gain4_i3 * ((rtb_Saturation1_d -
        rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 39.224F) * 0.004F;

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
          /* Disable for SwitchCase: '<S353>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S753>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S743>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S692>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S660>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S671>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S351>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S462>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S513>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S503>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S462>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S350>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S449>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S365>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S383>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S399>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S424>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S411>/Switch Case' */
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
         *  ActionPort: '<S353>/Action Port'
         */
        /* SwitchCase: '<S353>/Switch Case' incorporates:
         *  Math: '<S775>/Math Function'
         *  Sum: '<S737>/Subtract'
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
            /* Disable for SwitchCase: '<S753>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S743>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S692>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S660>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S671>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S353>/Takeoff' incorporates:
             *  ActionPort: '<S655>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S353>/Switch Case' incorporates:
             *  Delay: '<S793>/cur_waypoint'
             *  DiscreteIntegrator: '<S789>/Integrator'
             *  DiscreteIntegrator: '<S789>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S353>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S353>/Takeoff' incorporates:
           *  ActionPort: '<S655>/Action Port'
           */
          /* Delay: '<S793>/cur_waypoint' incorporates:
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
          /* Product: '<S793>/Divide' incorporates:
           *  Delay: '<S793>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S793>/Sum1'
           *  Sum: '<S793>/Sum2'
           */
          rtb_Saturation_o4 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S793>/Saturation' */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_o4 = 0.0F;
            }
          }

          /* End of Saturate: '<S793>/Saturation' */

          /* Trigonometry: '<S794>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S794>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S794>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S794>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S794>/Gain' incorporates:
           *  Gain: '<S792>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S794>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S794>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S794>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S794>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S794>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S786>/Saturation1' */
          rtb_Saturation_ga = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Saturation1_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S786>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S793>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S793>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S786>/Sum'
           *  Sum: '<S793>/Sum3'
           *  Sum: '<S793>/Sum4'
           */
          d = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0]) *
               rtb_Saturation_o4 + FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Divide_jq = ((FMS_B.Cmd_In.sp_waypoint[1] -
                            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_o4 +
                           FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S786>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 3]
              * rtb_Divide_jq + rtb_VectorConcatenate[rtb_n] * d;
          }

          /* Saturate: '<S786>/Saturation1' incorporates:
           *  Gain: '<S786>/Gain2'
           *  Product: '<S786>/Multiply'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S655>/Bus Assignment1'
           *  Constant: '<S655>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S655>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S786>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_ga) {
            /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_ga;
          } else if (rtb_u_b < rtb_Saturation1_d) {
            /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Saturation1_p5 > rtb_Saturation_ga) {
            /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_ga;
          } else if (rtb_Saturation1_p5 < rtb_Saturation1_d) {
            /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_p5;
          }

          /* BusAssignment: '<S655>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S789>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S790>/Multiply1' incorporates:
           *  Constant: '<S790>/const1'
           *  DiscreteIntegrator: '<S789>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S785>/Switch' incorporates:
           *  Abs: '<S785>/Abs'
           *  Abs: '<S785>/Abs1'
           *  Constant: '<S785>/Takeoff_Speed'
           *  Constant: '<S787>/Constant'
           *  Constant: '<S788>/Constant'
           *  Gain: '<S785>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S785>/Logical Operator'
           *  RelationalOperator: '<S787>/Compare'
           *  RelationalOperator: '<S788>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S785>/Sum'
           *  Sum: '<S785>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_u_b = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_u_b = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S785>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S790>/Add' incorporates:
           *  DiscreteIntegrator: '<S789>/Integrator1'
           *  Sum: '<S789>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_f - rtb_u_b) +
            rtb_Saturation_o4;

          /* Signum: '<S790>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S790>/Sign' */

          /* Sum: '<S790>/Add2' incorporates:
           *  Abs: '<S790>/Abs'
           *  Gain: '<S790>/Gain'
           *  Gain: '<S790>/Gain1'
           *  Product: '<S790>/Multiply2'
           *  Product: '<S790>/Multiply3'
           *  Sqrt: '<S790>/Sqrt'
           *  Sum: '<S790>/Add1'
           *  Sum: '<S790>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_b) *
                           FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S790>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S790>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Sum: '<S790>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_b;

          /* Signum: '<S790>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S790>/Sign1' */

          /* Signum: '<S790>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S790>/Sign2' */

          /* Sum: '<S790>/Add5' incorporates:
           *  Gain: '<S790>/Gain2'
           *  Product: '<S790>/Multiply4'
           *  Sum: '<S790>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S793>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S789>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S789>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S790>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_b;

          /* Sum: '<S790>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_b;

          /* Signum: '<S790>/Sign5' incorporates:
           *  Signum: '<S790>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S790>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S790>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S790>/Sign6' */
            rtb_Subtract1_o = rtb_u_b;
          }

          /* End of Signum: '<S790>/Sign5' */

          /* Signum: '<S790>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S790>/Sign3' */

          /* Signum: '<S790>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S790>/Sign4' */

          /* Update for DiscreteIntegrator: '<S789>/Integrator' incorporates:
           *  Constant: '<S790>/const'
           *  Gain: '<S790>/Gain3'
           *  Product: '<S790>/Divide'
           *  Product: '<S790>/Multiply5'
           *  Product: '<S790>/Multiply6'
           *  Sum: '<S790>/Subtract4'
           *  Sum: '<S790>/Subtract5'
           *  Sum: '<S790>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_u_b / FMS_ConstB.d_b -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_i * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S353>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S353>/Land' incorporates:
             *  ActionPort: '<S653>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S353>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S708>/Integrator'
             *  DiscreteIntegrator: '<S708>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S353>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S353>/Land' incorporates:
           *  ActionPort: '<S653>/Action Port'
           */
          /* Trigonometry: '<S713>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S713>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S713>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S713>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S713>/Gain' incorporates:
           *  Gain: '<S712>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S713>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S713>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S713>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S713>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S713>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S706>/Saturation1' */
          rtb_Saturation_o4 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Subtract1_o = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S710>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S710>/Sum'
           */
          d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_jq = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S710>/Multiply' incorporates:
           *  SignalConversion: '<S710>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S710>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 3]
              * rtb_Divide_jq + rtb_VectorConcatenate[rtb_n] * d;
          }

          /* End of Product: '<S710>/Multiply' */

          /* Saturate: '<S706>/Saturation1' incorporates:
           *  Gain: '<S710>/Gain2'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S653>/Bus Assignment1'
           *  Constant: '<S653>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S653>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S706>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_o4) {
            /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_o4;
          } else if (rtb_u_b < rtb_Subtract1_o) {
            /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Subtract1_o;
          } else {
            /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Saturation1_p5 > rtb_Saturation_o4) {
            /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_o4;
          } else if (rtb_Saturation1_p5 < rtb_Subtract1_o) {
            /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Subtract1_o;
          } else {
            /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_p5;
          }

          /* BusAssignment: '<S653>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S708>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S709>/Multiply1' incorporates:
           *  Constant: '<S709>/const1'
           *  DiscreteIntegrator: '<S708>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S705>/Switch' incorporates:
           *  Constant: '<S705>/Land_Speed'
           *  Constant: '<S707>/Constant'
           *  Gain: '<S705>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S705>/Logical Operator'
           *  RelationalOperator: '<S707>/Compare'
           *  S-Function (sfix_bitop): '<S705>/cmd_p valid'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_u_b = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_u_b = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S705>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S709>/Add' incorporates:
           *  DiscreteIntegrator: '<S708>/Integrator1'
           *  Sum: '<S708>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_g - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S709>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S709>/Sign' */

          /* Sum: '<S709>/Add2' incorporates:
           *  Abs: '<S709>/Abs'
           *  Gain: '<S709>/Gain'
           *  Gain: '<S709>/Gain1'
           *  Product: '<S709>/Multiply2'
           *  Product: '<S709>/Multiply3'
           *  Sqrt: '<S709>/Sqrt'
           *  Sum: '<S709>/Add1'
           *  Sum: '<S709>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_om) *
                           FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S709>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S709>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Sum: '<S709>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_om;

          /* Signum: '<S709>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S709>/Sign1' */

          /* Signum: '<S709>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S709>/Sign2' */

          /* Sum: '<S709>/Add5' incorporates:
           *  Gain: '<S709>/Gain2'
           *  Product: '<S709>/Multiply4'
           *  Sum: '<S709>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for DiscreteIntegrator: '<S708>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S708>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S709>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_om;

          /* Sum: '<S709>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_om;

          /* Signum: '<S709>/Sign5' incorporates:
           *  Signum: '<S709>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S709>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S709>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S709>/Sign6' */
            rtb_Subtract1_o = rtb_u_b;
          }

          /* End of Signum: '<S709>/Sign5' */

          /* Signum: '<S709>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S709>/Sign3' */

          /* Signum: '<S709>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S709>/Sign4' */

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
          FMS_DW.Integrator_DSTATE_cy += ((rtb_u_b / FMS_ConstB.d_om -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_p * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S353>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S353>/Return' incorporates:
             *  ActionPort: '<S654>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S353>/Switch Case' incorporates:
             *  Delay: '<S717>/Delay'
             *  Delay: '<S738>/Delay'
             *  DiscreteIntegrator: '<S720>/Integrator'
             *  DiscreteIntegrator: '<S720>/Integrator1'
             *  DiscreteIntegrator: '<S734>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S739>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S780>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S353>/Return' */

            /* SystemReset for IfAction SubSystem: '<S353>/Return' incorporates:
             *  ActionPort: '<S654>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S353>/Switch Case' incorporates:
             *  Chart: '<S744>/Motion Status'
             *  Chart: '<S754>/Motion State'
             */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S353>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S353>/Return' incorporates:
           *  ActionPort: '<S654>/Action Port'
           */
          /* Delay: '<S738>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S733>/Compare' incorporates:
           *  Constant: '<S784>/Constant'
           *  DiscreteIntegrator: '<S739>/Discrete-Time Integrator'
           *  RelationalOperator: '<S784>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S734>/Acceleration_Speed' */
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
          /* Chart: '<S754>/Motion State' incorporates:
           *  Constant: '<S754>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S754>/Square'
           *  Math: '<S754>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S754>/Sqrt'
           *  Sum: '<S754>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S753>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S753>/Hold Control' incorporates:
               *  ActionPort: '<S756>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S753>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S753>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S753>/Hold Control' incorporates:
             *  ActionPort: '<S756>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S753>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S753>/Brake Control' incorporates:
             *  ActionPort: '<S755>/Action Port'
             */
            FMS_BrakeControl_e1(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S753>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S753>/Move Control' incorporates:
               *  ActionPort: '<S757>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S753>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S753>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S753>/Move Control' incorporates:
             *  ActionPort: '<S757>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S753>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S753>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S744>/Motion Status' incorporates:
           *  Abs: '<S744>/Abs'
           *  Constant: '<S744>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S743>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S743>/Hold Control' incorporates:
               *  ActionPort: '<S746>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S743>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S743>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S743>/Hold Control' incorporates:
             *  ActionPort: '<S746>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S743>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S743>/Brake Control' incorporates:
             *  ActionPort: '<S745>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S743>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S743>/Move Control' incorporates:
               *  ActionPort: '<S747>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S743>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_cg);

              /* End of SystemReset for SubSystem: '<S743>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S743>/Move Control' incorporates:
             *  ActionPort: '<S747>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_cg, &FMS_DW.MoveControl_cg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S743>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S743>/Switch Case' */

          /* Switch: '<S715>/Switch' incorporates:
           *  Product: '<S738>/Multiply'
           *  Sum: '<S738>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S753>/Saturation1' */
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

            /* End of Saturate: '<S753>/Saturation1' */

            /* Saturate: '<S743>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S743>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S738>/Sum' incorporates:
             *  Delay: '<S738>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract1_o = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S781>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Subtract1_o;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S734>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_o4 = rtb_Subtract1_o;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S738>/Sum' incorporates:
             *  Delay: '<S738>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract1_o = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S734>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S740>/Sqrt' incorporates:
             *  Math: '<S740>/Square'
             *  Sum: '<S734>/Sum'
             *  Sum: '<S740>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
                            rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S783>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S783>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S783>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S782>/Gain' incorporates:
             *  DiscreteIntegrator: '<S780>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S780>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S783>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S783>/Trigonometric Function1'
             */
            rtb_Saturation_ga = arm_cos_f32(rtb_Saturation1_d);
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Trigonometry: '<S783>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S783>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation1_d);

            /* Gain: '<S783>/Gain' incorporates:
             *  Trigonometry: '<S783>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S783>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S783>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S783>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S783>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* Switch: '<S734>/Switch' incorporates:
             *  Constant: '<S734>/vel'
             */
            if (rtb_u_b > FMS_PARAM.L1) {
              rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S734>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_u_b;

              /* Saturate: '<S734>/Saturation' */
              if (rtb_Saturation1_d > FMS_PARAM.CRUISE_SPEED) {
                rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Saturate: '<S734>/Saturation' */
            }

            /* End of Switch: '<S734>/Switch' */

            /* Switch: '<S734>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S734>/Acceleration_Speed'
             *  Sum: '<S734>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S734>/Switch1' */

            /* Sum: '<S781>/Sum of Elements' incorporates:
             *  Math: '<S781>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Subtract1_o *
              rtb_Subtract1_o;

            /* Math: '<S781>/Math Function1' incorporates:
             *  Sum: '<S781>/Sum of Elements'
             *
             * About '<S781>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_Saturation_ga = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S781>/Math Function1' */

            /* Switch: '<S781>/Switch' incorporates:
             *  Constant: '<S781>/Constant'
             *  Product: '<S781>/Product'
             */
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Divide_bu[0] = rtb_Saturation_o4;
              rtb_Divide_bu[1] = rtb_Subtract1_o;
              rtb_Divide_bu[3] = rtb_Saturation_ga;
            } else {
              rtb_Divide_bu[0] = 0.0F;
              rtb_Divide_bu[1] = 0.0F;
              rtb_Divide_bu[3] = 1.0F;
            }

            /* End of Switch: '<S781>/Switch' */

            /* Product: '<S779>/Multiply2' incorporates:
             *  Product: '<S781>/Divide'
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

          /* End of Switch: '<S715>/Switch' */

          /* Delay: '<S717>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S720>/Integrator1' incorporates:
           *  Delay: '<S717>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S724>/Rem' incorporates:
           *  Constant: '<S724>/Constant1'
           *  DiscreteIntegrator: '<S720>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S719>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S724>/Switch' incorporates:
           *  Abs: '<S724>/Abs'
           *  Constant: '<S724>/Constant'
           *  Constant: '<S725>/Constant'
           *  Product: '<S724>/Multiply'
           *  RelationalOperator: '<S725>/Compare'
           *  Sum: '<S724>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S724>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S724>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S724>/Switch' */

          /* Gain: '<S719>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S719>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S719>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S654>/Bus Assignment1'
           *  Constant: '<S654>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S654>/Bus Assignment1' incorporates:
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

          /* Math: '<S774>/Math Function1'
           *
           * About '<S774>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Divide_jq));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Divide_jq);
          }

          /* End of Math: '<S774>/Math Function1' */

          /* Switch: '<S774>/Switch' incorporates:
           *  Constant: '<S774>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S774>/Product'
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

          /* End of Switch: '<S774>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S654>/Sum' incorporates:
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

          /* SignalConversion: '<S731>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S654>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S731>/Math Function' incorporates:
           *  Sum: '<S654>/Sum'
           */
          rtb_Square_dv[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_dv[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S731>/Sum of Elements' */
          rtb_u_b = rtb_Square_dv[0] + rtb_Square_dv[1];

          /* Math: '<S731>/Math Function1' incorporates:
           *  Sum: '<S731>/Sum of Elements'
           *
           * About '<S731>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S731>/Math Function1' */

          /* Switch: '<S731>/Switch' incorporates:
           *  Constant: '<S731>/Constant'
           *  Product: '<S731>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Divide_jq = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Divide_jq = 1.0F;
          }

          /* End of Switch: '<S731>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S736>/NearbyRefWP' incorporates:
           *  Constant: '<S654>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f0,
                          &rtb_u_b);

          /* MATLAB Function: '<S736>/SearchL1RefWP' incorporates:
           *  Constant: '<S654>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S736>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0],
                               &rtb_TmpSignalConversionAtMultip[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_dv);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S736>/Switch1' incorporates:
           *  Constant: '<S767>/Constant'
           *  RelationalOperator: '<S767>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_f0[0];
            rtb_P_ap[1] = rtb_Divide_f0[1];
          } else {
            /* RelationalOperator: '<S766>/Compare' incorporates:
             *  Constant: '<S766>/Constant'
             */
            rtb_Compare_at = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S736>/Switch' */
            if (!rtb_Compare_at) {
              rtb_P_ap[0] = rtb_Square_dv[0];
              rtb_P_ap[1] = rtb_Square_dv[1];
            }

            /* End of Switch: '<S736>/Switch' */
          }

          /* End of Switch: '<S736>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S737>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract1_o = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Subtract1_o;
          rtb_Subtract_hb[0] = rtb_Subtract1_o * rtb_Subtract1_o;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S737>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S775>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract1_o = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S775>/Sum of Elements' incorporates:
           *  Math: '<S775>/Math Function'
           *  Sum: '<S773>/Sum of Elements'
           */
          rtb_u_b = rtb_Subtract_hb[0] + rtb_Subtract1_o * rtb_Subtract1_o;

          /* Math: '<S775>/Math Function1' incorporates:
           *  Sum: '<S775>/Sum of Elements'
           *
           * About '<S775>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S775>/Math Function1' */

          /* Switch: '<S775>/Switch' incorporates:
           *  Constant: '<S775>/Constant'
           *  Product: '<S775>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_P_ap[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract1_o;
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S775>/Switch' */

          /* Product: '<S774>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S777>/Sum of Elements' incorporates:
           *  Math: '<S777>/Math Function'
           *  SignalConversion: '<S777>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Sign5_ke = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S777>/Math Function1' incorporates:
           *  Sum: '<S777>/Sum of Elements'
           *
           * About '<S777>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Sign5_ke < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Sign5_ke));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Sign5_ke);
          }

          /* End of Math: '<S777>/Math Function1' */

          /* Switch: '<S777>/Switch' incorporates:
           *  Constant: '<S777>/Constant'
           *  Product: '<S777>/Product'
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

          /* End of Switch: '<S777>/Switch' */

          /* Product: '<S775>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S778>/Sum of Elements' incorporates:
           *  Math: '<S778>/Math Function'
           *  SignalConversion: '<S778>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Sign5_ke = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S778>/Math Function1' incorporates:
           *  Sum: '<S778>/Sum of Elements'
           *
           * About '<S778>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Sign5_ke < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Sign5_ke));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Sign5_ke);
          }

          /* End of Math: '<S778>/Math Function1' */

          /* Switch: '<S778>/Switch' incorporates:
           *  Constant: '<S778>/Constant'
           *  Product: '<S778>/Product'
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

          /* End of Switch: '<S778>/Switch' */

          /* Product: '<S778>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S777>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S731>/Divide' */
          rtb_Square_dv[0] = rtb_Saturation_ga / rtb_Divide_jq;

          /* Product: '<S778>/Divide' */
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S777>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S731>/Divide' */
          rtb_Square_dv[1] = rtb_Saturation1_d / rtb_Divide_jq;

          /* Sum: '<S776>/Subtract' incorporates:
           *  Product: '<S776>/Multiply'
           *  Product: '<S776>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_f0[0] * rtb_P_ap[1] - rtb_Divide_f0[1] *
            rtb_P_ap[0];

          /* Signum: '<S771>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S771>/Sign1' */

          /* Switch: '<S771>/Switch2' incorporates:
           *  Constant: '<S771>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S771>/Switch2' */

          /* DotProduct: '<S771>/Dot Product' */
          rtb_Subtract1_o = rtb_P_ap[0] * rtb_Divide_f0[0] + rtb_P_ap[1] *
            rtb_Divide_f0[1];

          /* Trigonometry: '<S771>/Acos' incorporates:
           *  DotProduct: '<S771>/Dot Product'
           */
          if (rtb_Subtract1_o > 1.0F) {
            rtb_Subtract1_o = 1.0F;
          } else {
            if (rtb_Subtract1_o < -1.0F) {
              rtb_Subtract1_o = -1.0F;
            }
          }

          /* Product: '<S771>/Multiply' incorporates:
           *  Trigonometry: '<S771>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Subtract1_o);

          /* Saturate: '<S737>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S737>/Saturation' */

          /* Product: '<S737>/Divide' incorporates:
           *  Constant: '<S654>/L1'
           *  Constant: '<S737>/Constant'
           *  Gain: '<S737>/Gain'
           *  Math: '<S737>/Square'
           *  MinMax: '<S737>/Max'
           *  MinMax: '<S737>/Min'
           *  Product: '<S737>/Multiply1'
           *  Sqrt: '<S773>/Sqrt'
           *  Trigonometry: '<S737>/Sin'
           */
          rtb_Saturation1_p5 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S729>/Subtract' incorporates:
           *  Product: '<S729>/Multiply'
           *  Product: '<S729>/Multiply1'
           */
          rtb_Subtract1_o = rtb_Square_dv[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_dv[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S718>/Sign1' */
          if (rtb_Subtract1_o < 0.0F) {
            rtb_Subtract1_o = -1.0F;
          } else {
            if (rtb_Subtract1_o > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            }
          }

          /* End of Signum: '<S718>/Sign1' */

          /* Switch: '<S718>/Switch2' incorporates:
           *  Constant: '<S718>/Constant4'
           */
          if (rtb_Subtract1_o == 0.0F) {
            rtb_Subtract1_o = 1.0F;
          }

          /* End of Switch: '<S718>/Switch2' */

          /* DotProduct: '<S718>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide_m[0] * rtb_Square_dv[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_dv[1];

          /* Trigonometry: '<S718>/Acos' incorporates:
           *  DotProduct: '<S718>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S718>/Multiply' incorporates:
           *  Trigonometry: '<S718>/Acos'
           */
          rtb_Subtract1_o *= acosf(rtb_u_b);

          /* Math: '<S721>/Rem' incorporates:
           *  Constant: '<S721>/Constant1'
           *  Delay: '<S717>/Delay'
           *  Sum: '<S717>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Subtract1_o - FMS_DW.Delay_DSTATE_nx,
            6.28318548F);

          /* Switch: '<S721>/Switch' incorporates:
           *  Abs: '<S721>/Abs'
           *  Constant: '<S721>/Constant'
           *  Constant: '<S727>/Constant'
           *  Product: '<S721>/Multiply'
           *  RelationalOperator: '<S727>/Compare'
           *  Sum: '<S721>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S721>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S721>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S721>/Switch' */

          /* Sum: '<S717>/Sum' incorporates:
           *  Delay: '<S717>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S726>/Multiply1' incorporates:
           *  Constant: '<S726>/const1'
           *  DiscreteIntegrator: '<S720>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S726>/Add' incorporates:
           *  DiscreteIntegrator: '<S720>/Integrator1'
           *  Sum: '<S720>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S726>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S726>/Sign' */

          /* Sum: '<S726>/Add2' incorporates:
           *  Abs: '<S726>/Abs'
           *  Gain: '<S726>/Gain'
           *  Gain: '<S726>/Gain1'
           *  Product: '<S726>/Multiply2'
           *  Product: '<S726>/Multiply3'
           *  Sqrt: '<S726>/Sqrt'
           *  Sum: '<S726>/Add1'
           *  Sum: '<S726>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_n) *
                           FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S726>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S726>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_n;

          /* Sum: '<S726>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_n;

          /* Signum: '<S726>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S726>/Sign1' */

          /* Signum: '<S726>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S726>/Sign2' */

          /* Sum: '<S726>/Add5' incorporates:
           *  Gain: '<S726>/Gain2'
           *  Product: '<S726>/Multiply4'
           *  Sum: '<S726>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S726>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_n;

          /* Sum: '<S726>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_n;

          /* Product: '<S726>/Divide' */
          d = rtb_u_b / FMS_ConstB.d_n;

          /* Signum: '<S726>/Sign5' incorporates:
           *  Signum: '<S726>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_jq = -1.0F;

            /* Signum: '<S726>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_jq = 1.0F;

            /* Signum: '<S726>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Divide_jq = rtb_u_b;

            /* Signum: '<S726>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S726>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S717>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract1_o -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S722>/Rem' incorporates:
           *  Constant: '<S722>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Subtract1_o, 6.28318548F);

          /* Switch: '<S722>/Switch' incorporates:
           *  Abs: '<S722>/Abs'
           *  Constant: '<S722>/Constant'
           *  Constant: '<S728>/Constant'
           *  Product: '<S722>/Multiply'
           *  RelationalOperator: '<S728>/Compare'
           *  Sum: '<S722>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S722>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Subtract1_o = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            } else {
              rtb_Subtract1_o = rtb_u_b;
            }

            /* End of Signum: '<S722>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Subtract1_o;
          }

          /* End of Switch: '<S722>/Switch' */

          /* Abs: '<S715>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S738>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S739>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S732>/Constant'
           *  RelationalOperator: '<S732>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S739>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S734>/Acceleration_Speed' incorporates:
           *  Constant: '<S734>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S734>/Acceleration_Speed' */

          /* Product: '<S738>/Divide1' incorporates:
           *  Constant: '<S738>/Constant'
           */
          rtb_u_b = rtb_Saturation1_p5 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S738>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S738>/Saturation' */

          /* Update for DiscreteIntegrator: '<S780>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_u_b;

          /* Update for Delay: '<S717>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S720>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S720>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S726>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S726>/Sign3' */

          /* Signum: '<S726>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S726>/Sign4' */

          /* Update for DiscreteIntegrator: '<S720>/Integrator' incorporates:
           *  Constant: '<S726>/const'
           *  Gain: '<S726>/Gain3'
           *  Product: '<S726>/Multiply5'
           *  Product: '<S726>/Multiply6'
           *  Sum: '<S726>/Subtract4'
           *  Sum: '<S726>/Subtract5'
           *  Sum: '<S726>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((d - rtb_Divide_jq) *
            FMS_ConstB.Gain4_d * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S720>/Integrator' */
          /* End of Outputs for SubSystem: '<S353>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S353>/Hold' incorporates:
             *  ActionPort: '<S652>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S353>/Switch Case' incorporates:
             *  Delay: '<S673>/Delay'
             *  DiscreteIntegrator: '<S685>/Integrator'
             *  DiscreteIntegrator: '<S685>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S353>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S353>/Hold' incorporates:
             *  ActionPort: '<S652>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S353>/Switch Case' incorporates:
             *  Chart: '<S661>/Motion Status'
             *  Chart: '<S672>/Motion State'
             *  Chart: '<S693>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S353>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S353>/Hold' incorporates:
           *  ActionPort: '<S652>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S661>/Motion Status' incorporates:
           *  Abs: '<S661>/Abs'
           *  Constant: '<S661>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S672>/Motion State' incorporates:
           *  Abs: '<S672>/Abs'
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

          /* End of Chart: '<S672>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S693>/Motion State' incorporates:
           *  Constant: '<S693>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S693>/Square'
           *  Math: '<S693>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S693>/Sqrt'
           *  Sum: '<S693>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                            &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S692>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S692>/Hold Control' incorporates:
               *  ActionPort: '<S695>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S692>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S692>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S692>/Hold Control' incorporates:
             *  ActionPort: '<S695>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S692>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S692>/Brake Control' incorporates:
             *  ActionPort: '<S694>/Action Port'
             */
            FMS_BrakeControl_e1(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S692>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S692>/Move Control' incorporates:
               *  ActionPort: '<S696>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S692>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S692>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S692>/Move Control' incorporates:
             *  ActionPort: '<S696>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S692>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S692>/Switch Case' */

          /* SwitchCase: '<S660>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S660>/Hold Control' incorporates:
               *  ActionPort: '<S663>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S660>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S660>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S660>/Hold Control' incorporates:
             *  ActionPort: '<S663>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S660>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S660>/Brake Control' incorporates:
             *  ActionPort: '<S662>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S660>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S660>/Move Control' incorporates:
               *  ActionPort: '<S664>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S660>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S660>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S660>/Move Control' incorporates:
             *  ActionPort: '<S664>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S660>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S660>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S670>/Compare' incorporates:
           *  Constant: '<S670>/Constant'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S673>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S685>/Integrator1' incorporates:
           *  Delay: '<S673>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S671>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S671>/Hold Control' incorporates:
               *  ActionPort: '<S675>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S671>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S671>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S671>/Hold Control' incorporates:
             *  ActionPort: '<S675>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S671>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S671>/Brake Control' incorporates:
             *  ActionPort: '<S674>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S671>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S671>/Move Control' incorporates:
               *  ActionPort: '<S676>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S671>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S671>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S671>/Move Control' incorporates:
             *  ActionPort: '<S676>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S671>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S671>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S658>/Switch' incorporates:
           *  Saturate: '<S671>/Saturation'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S688>/Rem' incorporates:
             *  Constant: '<S688>/Constant1'
             *  DiscreteIntegrator: '<S685>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S684>/Sum'
             */
            rtb_Saturation_ga = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S688>/Switch' incorporates:
             *  Abs: '<S688>/Abs'
             *  Constant: '<S688>/Constant'
             *  Constant: '<S689>/Constant'
             *  Product: '<S688>/Multiply'
             *  RelationalOperator: '<S689>/Compare'
             *  Sum: '<S688>/Add'
             */
            if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
              /* Signum: '<S688>/Sign' */
              if (rtb_Saturation_ga < 0.0F) {
                rtb_Saturation1_d = -1.0F;
              } else if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              } else {
                rtb_Saturation1_d = rtb_Saturation_ga;
              }

              /* End of Signum: '<S688>/Sign' */
              rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
            }

            /* End of Switch: '<S688>/Switch' */

            /* Gain: '<S684>/Gain2' */
            rtb_Saturation_ga *= FMS_PARAM.YAW_P;

            /* Saturate: '<S684>/Saturation' */
            if (rtb_Saturation_ga > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Saturation_ga < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S684>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S671>/Saturation' */
            rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S671>/Saturation' */
            rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S671>/Saturation' */
            rtb_Saturation_ga = FMS_B.Merge_h;
          }

          /* End of Switch: '<S658>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S652>/Bus Assignment'
           *  Constant: '<S652>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S652>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_ga;

          /* Saturate: '<S692>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S692>/Saturation1' */

          /* Saturate: '<S660>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S652>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S660>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S686>/Rem' incorporates:
           *  Constant: '<S686>/Constant1'
           *  Delay: '<S673>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S673>/Sum2'
           */
          rtb_Saturation_ga = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S686>/Switch' incorporates:
           *  Abs: '<S686>/Abs'
           *  Constant: '<S686>/Constant'
           *  Constant: '<S691>/Constant'
           *  Product: '<S686>/Multiply'
           *  RelationalOperator: '<S691>/Compare'
           *  Sum: '<S686>/Add'
           */
          if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
            /* Signum: '<S686>/Sign' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_ga;
            }

            /* End of Signum: '<S686>/Sign' */
            rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S686>/Switch' */

          /* Sum: '<S673>/Sum' incorporates:
           *  Delay: '<S673>/Delay'
           */
          rtb_Saturation1_d = rtb_Saturation_ga + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S685>/Integrator' */
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

          /* Product: '<S690>/Multiply1' incorporates:
           *  Constant: '<S690>/const1'
           *  DiscreteIntegrator: '<S685>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S690>/Add' incorporates:
           *  DiscreteIntegrator: '<S685>/Integrator1'
           *  Sum: '<S685>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jz - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S690>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S690>/Sign' */

          /* Sum: '<S690>/Add2' incorporates:
           *  Abs: '<S690>/Abs'
           *  Gain: '<S690>/Gain'
           *  Gain: '<S690>/Gain1'
           *  Product: '<S690>/Multiply2'
           *  Product: '<S690>/Multiply3'
           *  Sqrt: '<S690>/Sqrt'
           *  Sum: '<S690>/Add1'
           *  Sum: '<S690>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_k) *
                           FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S690>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S690>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_k;

          /* Sum: '<S690>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_k;

          /* Signum: '<S690>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S690>/Sign1' */

          /* Signum: '<S690>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S690>/Sign2' */

          /* Sum: '<S690>/Add5' incorporates:
           *  Gain: '<S690>/Gain2'
           *  Product: '<S690>/Multiply4'
           *  Sum: '<S690>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S673>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S685>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S685>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S690>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_k;

          /* Sum: '<S690>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_k;

          /* Signum: '<S690>/Sign5' incorporates:
           *  Signum: '<S690>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S690>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S690>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S690>/Sign6' */
            rtb_Subtract1_o = rtb_u_b;
          }

          /* End of Signum: '<S690>/Sign5' */

          /* Signum: '<S690>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S690>/Sign3' */

          /* Signum: '<S690>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S690>/Sign4' */

          /* Update for DiscreteIntegrator: '<S685>/Integrator' incorporates:
           *  Constant: '<S690>/const'
           *  Gain: '<S690>/Gain3'
           *  Product: '<S690>/Divide'
           *  Product: '<S690>/Multiply5'
           *  Product: '<S690>/Multiply6'
           *  Sum: '<S690>/Subtract4'
           *  Sum: '<S690>/Subtract5'
           *  Sum: '<S690>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hi += ((rtb_u_b / FMS_ConstB.d_k -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_a * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 0.785398185F) *
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

          /* End of Update for DiscreteIntegrator: '<S685>/Integrator' */
          /* End of Outputs for SubSystem: '<S353>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S353>/Unknown' incorporates:
           *  ActionPort: '<S656>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S353>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
         *  ActionPort: '<S351>/Action Port'
         */
        /* SwitchCase: '<S351>/Switch Case' incorporates:
         *  Math: '<S535>/Math Function'
         *  Sum: '<S491>/Subtract'
         *  Sum: '<S548>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S462>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S513>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S503>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S462>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S351>/Offboard' incorporates:
           *  ActionPort: '<S463>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S629>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S632>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S633>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S633>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S633>/Multiply1' incorporates:
           *  Product: '<S633>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S633>/Divide' incorporates:
           *  Constant: '<S633>/Constant'
           *  Constant: '<S633>/R'
           *  Sqrt: '<S633>/Sqrt'
           *  Sum: '<S633>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S633>/Product3' incorporates:
           *  Constant: '<S633>/Constant1'
           *  Product: '<S633>/Multiply1'
           *  Sum: '<S633>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S633>/Multiply2' incorporates:
           *  Trigonometry: '<S633>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S632>/Sum' incorporates:
           *  Gain: '<S629>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S637>/Abs' incorporates:
           *  Abs: '<S640>/Abs1'
           *  Switch: '<S637>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S637>/Switch1' incorporates:
           *  Abs: '<S637>/Abs'
           *  Bias: '<S637>/Bias2'
           *  Bias: '<S637>/Bias3'
           *  Constant: '<S634>/Constant'
           *  Constant: '<S634>/Constant1'
           *  Constant: '<S639>/Constant'
           *  Gain: '<S637>/Gain1'
           *  Product: '<S637>/Multiply'
           *  RelationalOperator: '<S639>/Compare'
           *  Switch: '<S634>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S640>/Switch1' incorporates:
             *  Bias: '<S640>/Bias2'
             *  Bias: '<S640>/Bias3'
             *  Constant: '<S640>/Constant'
             *  Constant: '<S641>/Constant'
             *  Math: '<S640>/Math Function'
             *  RelationalOperator: '<S641>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S640>/Switch1' */

            /* Signum: '<S637>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S637>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S634>/Sum' incorporates:
           *  Gain: '<S629>/Gain1'
           *  Gain: '<S629>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S632>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S632>/Multiply' incorporates:
           *  Gain: '<S632>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S636>/Switch1' incorporates:
           *  Abs: '<S636>/Abs1'
           *  Bias: '<S636>/Bias2'
           *  Bias: '<S636>/Bias3'
           *  Constant: '<S636>/Constant'
           *  Constant: '<S638>/Constant'
           *  Math: '<S636>/Math Function'
           *  RelationalOperator: '<S638>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S636>/Switch1' */

          /* Product: '<S632>/Multiply' incorporates:
           *  Gain: '<S632>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S610>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S614>/Multiply1'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S623>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S623>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S623>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S623>/Gain' incorporates:
             *  Gain: '<S622>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S623>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S623>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S623>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S623>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S623>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S623>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S616>/Switch' incorporates:
             *  Constant: '<S631>/Constant'
             *  DataTypeConversion: '<S629>/Data Type Conversion1'
             *  Product: '<S635>/Multiply1'
             *  Product: '<S635>/Multiply2'
             *  RelationalOperator: '<S631>/Compare'
             *  S-Function (sfix_bitop): '<S628>/lat_cmd valid'
             *  Sum: '<S635>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o2 +
                                   rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S614>/Multiply' incorporates:
             *  Constant: '<S620>/Constant'
             *  Constant: '<S621>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S613>/Logical Operator'
             *  RelationalOperator: '<S620>/Compare'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S613>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/x_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S614>/Sum1'
             */
            d = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S623>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S616>/Switch' incorporates:
             *  Constant: '<S631>/Constant'
             *  DataTypeConversion: '<S629>/Data Type Conversion1'
             *  Product: '<S635>/Multiply3'
             *  Product: '<S635>/Multiply4'
             *  RelationalOperator: '<S631>/Compare'
             *  S-Function (sfix_bitop): '<S628>/lon_cmd valid'
             *  Sum: '<S635>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                   rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S614>/Multiply' incorporates:
             *  Constant: '<S620>/Constant'
             *  Constant: '<S621>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S613>/Logical Operator'
             *  RelationalOperator: '<S620>/Compare'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S613>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/y_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S614>/Sum1'
             */
            rtb_Divide_jq = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S623>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S616>/Switch' incorporates:
             *  Constant: '<S631>/Constant'
             *  DataTypeConversion: '<S629>/Data Type Conversion'
             *  DataTypeConversion: '<S629>/Data Type Conversion1'
             *  Gain: '<S629>/Gain2'
             *  Gain: '<S632>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S631>/Compare'
             *  S-Function (sfix_bitop): '<S628>/alt_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S632>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_u_b = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                                    -FMS_U.INS_Out.alt_0);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S614>/Multiply' incorporates:
             *  Constant: '<S620>/Constant'
             *  Constant: '<S621>/Constant'
             *  Gain: '<S617>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S613>/Logical Operator'
             *  RelationalOperator: '<S620>/Compare'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S613>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/z_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S614>/Sum1'
             */
            rtb_Subtract1_o = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_u_b -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Subtract1_o +
                (rtb_VectorConcatenate[rtb_n + 3] * rtb_Divide_jq +
                 rtb_VectorConcatenate[rtb_n] * d);
            }

            /* SignalConversion: '<S556>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S556>/Constant4'
             *  MultiPortSwitch: '<S545>/Index Vector'
             *  Product: '<S614>/Multiply1'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S556>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S556>/Gain' incorporates:
             *  Gain: '<S555>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S545>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S556>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S556>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S556>/Constant3'
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S556>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S556>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S556>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S545>/Multiply' incorporates:
             *  Constant: '<S554>/Constant'
             *  RelationalOperator: '<S554>/Compare'
             *  S-Function (sfix_bitop): '<S551>/ax_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ? FMS_U.Auto_Cmd.ax_cmd :
              0.0F;

            /* SignalConversion: '<S556>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S545>/Multiply' incorporates:
             *  Constant: '<S554>/Constant'
             *  RelationalOperator: '<S554>/Compare'
             *  S-Function (sfix_bitop): '<S551>/ay_cmd valid'
             */
            rtb_Divide_jq = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S556>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S545>/Multiply' incorporates:
             *  Constant: '<S554>/Constant'
             *  RelationalOperator: '<S554>/Compare'
             *  S-Function (sfix_bitop): '<S551>/az_cmd valid'
             */
            rtb_Subtract1_o = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S545>/Index Vector' incorporates:
             *  Product: '<S552>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                rtb_Subtract1_o + (rtb_VectorConcatenate[rtb_n + 3] *
                                   rtb_Divide_jq + rtb_VectorConcatenate[rtb_n] *
                                   d);
            }
            break;

           case 1:
            /* SignalConversion: '<S626>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S626>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S626>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S615>/Data Store Read'
             *  Gain: '<S624>/Gain'
             *  Trigonometry: '<S626>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S626>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S615>/Data Store Read'
             *  Gain: '<S624>/Gain'
             *  Trigonometry: '<S626>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S626>/Gain' incorporates:
             *  Trigonometry: '<S626>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -rtb_u_b;

            /* SignalConversion: '<S626>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S626>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S626>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_u_b;

            /* Trigonometry: '<S626>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_o4;

            /* SignalConversion: '<S627>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S627>/Constant4'
             */
            rtb_MatrixConcatenate1_a[5] = 0.0F;

            /* Gain: '<S625>/Gain' incorporates:
             *  DataStoreRead: '<S615>/Data Store Read'
             *  Gain: '<S557>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S545>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S615>/Subtract'
             */
            rtb_Saturation1_p5 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S627>/Trigonometric Function3' incorporates:
             *  Gain: '<S625>/Gain'
             *  Trigonometry: '<S627>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(rtb_Saturation1_p5);
            rtb_MatrixConcatenate1_a[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S627>/Trigonometric Function2' incorporates:
             *  Gain: '<S625>/Gain'
             *  Trigonometry: '<S627>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(rtb_Saturation1_p5);

            /* Gain: '<S627>/Gain' incorporates:
             *  Trigonometry: '<S627>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_a[3] = -rtb_u_b;

            /* SignalConversion: '<S627>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S627>/Constant3'
             */
            rtb_MatrixConcatenate1_a[2] = 0.0F;

            /* Trigonometry: '<S627>/Trigonometric Function' */
            rtb_MatrixConcatenate1_a[1] = rtb_u_b;

            /* Trigonometry: '<S627>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_a[0] = rtb_Saturation_o4;

            /* RelationalOperator: '<S631>/Compare' incorporates:
             *  Constant: '<S631>/Constant'
             *  S-Function (sfix_bitop): '<S628>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S628>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S628>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S629>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S629>/Data Type Conversion'
             *  Gain: '<S629>/Gain2'
             *  Gain: '<S632>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S635>/Multiply1'
             *  Product: '<S635>/Multiply2'
             *  Product: '<S635>/Multiply3'
             *  Product: '<S635>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S632>/Sum1'
             *  Sum: '<S635>/Sum2'
             *  Sum: '<S635>/Sum3'
             */
            rtb_MatrixConcatenate1_a_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S616>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S626>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S627>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S615>/Sum' incorporates:
             *  DataStoreRead: '<S615>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            d = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S626>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S627>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S615>/Sum' incorporates:
             *  DataStoreRead: '<S615>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_jq = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S626>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S627>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_a[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S615>/Sum' incorporates:
             *  DataStoreRead: '<S615>/Data Store Read'
             *  Gain: '<S617>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Subtract1_o = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S620>/Compare' incorporates:
             *  Constant: '<S620>/Constant'
             *  S-Function (sfix_bitop): '<S613>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S621>/Compare' incorporates:
             *  Constant: '<S621>/Constant'
             *  S-Function (sfix_bitop): '<S613>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S615>/Sum2' incorporates:
               *  Product: '<S615>/Multiply2'
               *  Switch: '<S616>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_a_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              /* Product: '<S615>/Multiply' incorporates:
               *  Logic: '<S613>/Logical Operator'
               *  Product: '<S615>/Multiply2'
               *  Sum: '<S615>/Sum'
               *  Sum: '<S615>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? rtb_u_b -
                ((rtb_VectorConcatenate[rtb_n + 3] * rtb_Divide_jq +
                  rtb_VectorConcatenate[rtb_n] * d) +
                 rtb_VectorConcatenate[rtb_n + 6] * rtb_Subtract1_o) : 0.0F;
            }

            /* SignalConversion: '<S558>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S558>/Constant4'
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S558>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_Saturation1_p5);

            /* Gain: '<S558>/Gain' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             *  Trigonometry: '<S558>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_Saturation1_p5);

            /* SignalConversion: '<S558>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S558>/Constant3'
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S558>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_Saturation1_p5);

            /* Trigonometry: '<S558>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S545>/Index Vector'
             */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_Saturation1_p5);

            /* Product: '<S545>/Multiply' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S554>/Compare' incorporates:
             *  Constant: '<S554>/Constant'
             *  S-Function (sfix_bitop): '<S551>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S551>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S551>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S558>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S545>/Index Vector'
               */
              rtb_VectorConcatenate[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S545>/Multiply' */
              rtb_MatrixConcatenate1_a_0[rtb_n] = tmp[rtb_n] ?
                rtb_Switch_c2[rtb_n] : 0.0F;
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_MatrixConcatenate1_a[rtb_n + 6] * rtb_Switch_ov[2] +
                (rtb_MatrixConcatenate1_a[rtb_n + 3] * rtb_Switch_ov[1] +
                 rtb_MatrixConcatenate1_a[rtb_n] * rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S545>/Index Vector' incorporates:
             *  Product: '<S553>/Multiply3'
             *  Product: '<S615>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                rtb_MatrixConcatenate1_a_0[2] + (rtb_VectorConcatenate[rtb_n + 3]
                * rtb_MatrixConcatenate1_a_0[1] + rtb_VectorConcatenate[rtb_n] *
                rtb_MatrixConcatenate1_a_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S619>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S619>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S619>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S619>/Gain' incorporates:
             *  Gain: '<S618>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S619>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S619>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S619>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S619>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S619>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* S-Function (sfix_bitop): '<S628>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S613>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S631>/Compare' incorporates:
             *  Constant: '<S631>/Constant'
             *  S-Function (sfix_bitop): '<S628>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S628>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S613>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S631>/Compare' incorporates:
             *  Constant: '<S631>/Constant'
             *  S-Function (sfix_bitop): '<S628>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S628>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S613>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S631>/Compare' incorporates:
             *  Constant: '<S631>/Constant'
             *  S-Function (sfix_bitop): '<S628>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S629>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S629>/Data Type Conversion'
             *  Gain: '<S629>/Gain2'
             *  Gain: '<S632>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S635>/Multiply1'
             *  Product: '<S635>/Multiply2'
             *  Product: '<S635>/Multiply3'
             *  Product: '<S635>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S632>/Sum1'
             *  Sum: '<S635>/Sum2'
             *  Sum: '<S635>/Sum3'
             */
            rtb_MatrixConcatenate1_a_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_a_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S616>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S619>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Sum: '<S612>/Sum' incorporates:
             *  DataStoreRead: '<S612>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation_o4 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S619>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Sum: '<S612>/Sum' incorporates:
             *  DataStoreRead: '<S612>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation1_p5 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S619>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Sum: '<S612>/Sum' incorporates:
             *  DataStoreRead: '<S612>/Data Store Read'
             *  Gain: '<S617>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Subtract1_o = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S620>/Compare' incorporates:
             *  Constant: '<S620>/Constant'
             *  S-Function (sfix_bitop): '<S613>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S613>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S621>/Compare' incorporates:
             *  Constant: '<S621>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S612>/Sum2' incorporates:
             *  Logic: '<S613>/Logical Operator'
             *  Product: '<S612>/Multiply'
             *  Product: '<S612>/Multiply2'
             *  Sum: '<S612>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S616>/Switch' incorporates:
               *  Product: '<S612>/Multiply2'
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
                rtb_Subtract1_o) : 0.0F;
            }

            /* End of Sum: '<S612>/Sum2' */

            /* MultiPortSwitch: '<S545>/Index Vector' incorporates:
             *  Constant: '<S554>/Constant'
             *  Product: '<S545>/Multiply'
             *  RelationalOperator: '<S554>/Compare'
             *  S-Function (sfix_bitop): '<S551>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S551>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S551>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* Sum: '<S606>/Sum1' incorporates:
           *  Constant: '<S606>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S606>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Sign5_ke = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S607>/Abs' */
          rtb_Saturation_o4 = fabsf(rtb_Sign5_ke);

          /* Switch: '<S607>/Switch' incorporates:
           *  Constant: '<S607>/Constant'
           *  Constant: '<S608>/Constant'
           *  Product: '<S607>/Multiply'
           *  RelationalOperator: '<S608>/Compare'
           *  Sum: '<S607>/Subtract'
           */
          if (rtb_Saturation_o4 > 3.14159274F) {
            /* Signum: '<S607>/Sign' */
            if (rtb_Sign5_ke < 0.0F) {
              rtb_Sign5_ke = -1.0F;
            } else {
              if (rtb_Sign5_ke > 0.0F) {
                rtb_Sign5_ke = 1.0F;
              }
            }

            /* End of Signum: '<S607>/Sign' */
            rtb_Sign5_ke *= rtb_Saturation_o4 - 6.28318548F;
          }

          /* End of Switch: '<S607>/Switch' */

          /* Saturate: '<S606>/Saturation' */
          if (rtb_Sign5_ke > 0.314159274F) {
            rtb_Sign5_ke = 0.314159274F;
          } else {
            if (rtb_Sign5_ke < -0.314159274F) {
              rtb_Sign5_ke = -0.314159274F;
            }
          }

          /* End of Saturate: '<S606>/Saturation' */

          /* Gain: '<S603>/Gain2' */
          rtb_Sign5_ke *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S547>/Sum' incorporates:
           *  Constant: '<S605>/Constant'
           *  Constant: '<S609>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S603>/Multiply2'
           *  Product: '<S604>/Multiply1'
           *  RelationalOperator: '<S605>/Compare'
           *  RelationalOperator: '<S609>/Compare'
           *  S-Function (sfix_bitop): '<S603>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S604>/psi_rate_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_u_b = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Sign5_ke : 0.0F)
            + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
               FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S610>/Gain1' */
          rtb_Saturation_o4 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMultip[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMultip
            [1];

          /* Gain: '<S610>/Gain2' */
          rtb_Sign5_ke = FMS_PARAM.Z_P * rtb_TmpSignalConversionAtMultip[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S611>/Index Vector' incorporates:
           *  Constant: '<S647>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S611>/Multiply'
           *  Product: '<S644>/Multiply'
           *  Product: '<S645>/Multiply3'
           *  RelationalOperator: '<S647>/Compare'
           *  S-Function (sfix_bitop): '<S643>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S643>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S643>/w_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S649>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S649>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Trigonometry: '<S649>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* Gain: '<S649>/Gain' incorporates:
             *  Gain: '<S648>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S649>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S649>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S649>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S649>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S649>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S649>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S611>/Multiply' incorporates:
             *  Constant: '<S647>/Constant'
             *  RelationalOperator: '<S647>/Compare'
             *  S-Function (sfix_bitop): '<S643>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S649>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S611>/Multiply' incorporates:
             *  Constant: '<S647>/Constant'
             *  RelationalOperator: '<S647>/Compare'
             *  S-Function (sfix_bitop): '<S643>/v_cmd valid'
             */
            rtb_Divide_jq = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S649>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S611>/Multiply' incorporates:
             *  Constant: '<S647>/Constant'
             *  RelationalOperator: '<S647>/Compare'
             *  S-Function (sfix_bitop): '<S643>/w_cmd valid'
             */
            rtb_Subtract1_o = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Subtract1_o +
                (rtb_VectorConcatenate[rtb_n + 3] * rtb_Divide_jq +
                 rtb_VectorConcatenate[rtb_n] * d);
            }
            break;

           case 1:
            /* SignalConversion: '<S651>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S651>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Gain: '<S650>/Gain' incorporates:
             *  DataStoreRead: '<S645>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S645>/Subtract'
             */
            rtb_Saturation_ga = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S651>/Trigonometric Function3' incorporates:
             *  Gain: '<S650>/Gain'
             */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_Saturation_ga);

            /* Gain: '<S651>/Gain' incorporates:
             *  Gain: '<S650>/Gain'
             *  Trigonometry: '<S651>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S651>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S651>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S651>/Trigonometric Function' incorporates:
             *  Gain: '<S650>/Gain'
             */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_Saturation_ga);

            /* Trigonometry: '<S651>/Trigonometric Function1' incorporates:
             *  Gain: '<S650>/Gain'
             */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S651>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_gjo[0];

            /* Product: '<S611>/Multiply' incorporates:
             *  Constant: '<S647>/Constant'
             *  RelationalOperator: '<S647>/Compare'
             *  S-Function (sfix_bitop): '<S643>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S651>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_gjo[1];

            /* Product: '<S611>/Multiply' incorporates:
             *  Constant: '<S647>/Constant'
             *  RelationalOperator: '<S647>/Compare'
             *  S-Function (sfix_bitop): '<S643>/v_cmd valid'
             */
            rtb_Divide_jq = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S651>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_gjo[2];

            /* Product: '<S611>/Multiply' incorporates:
             *  Constant: '<S647>/Constant'
             *  RelationalOperator: '<S647>/Compare'
             *  S-Function (sfix_bitop): '<S643>/w_cmd valid'
             */
            rtb_Subtract1_o = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMultip[rtb_n] =
                rtb_VectorConcatenate[rtb_n + 6] * rtb_Subtract1_o +
                (rtb_VectorConcatenate[rtb_n + 3] * rtb_Divide_jq +
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

          /* Sum: '<S548>/Sum1' */
          rtb_Saturation_ga = rtb_Sign5_ke + rtb_TmpSignalConversionAtMultip[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S566>/Switch' incorporates:
           *  Constant: '<S581>/Constant'
           *  Constant: '<S583>/Constant'
           *  Constant: '<S584>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S581>/Compare'
           *  RelationalOperator: '<S583>/Compare'
           *  RelationalOperator: '<S584>/Compare'
           *  S-Function (sfix_bitop): '<S566>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S566>/y_v_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S566>/Logical Operator' incorporates:
             *  Constant: '<S582>/Constant'
             *  Constant: '<S583>/Constant'
             *  Constant: '<S584>/Constant'
             *  RelationalOperator: '<S582>/Compare'
             *  RelationalOperator: '<S583>/Compare'
             *  RelationalOperator: '<S584>/Compare'
             *  S-Function (sfix_bitop): '<S566>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S566>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S566>/y_v_cmd'
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

          /* End of Switch: '<S566>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S546>/u_cmd_valid' */
          /* MATLAB Function: '<S578>/bit_shift' incorporates:
           *  DataTypeConversion: '<S546>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_at << 6);

          /* End of Outputs for SubSystem: '<S546>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S546>/v_cmd_valid' */
          /* MATLAB Function: '<S579>/bit_shift' incorporates:
           *  DataTypeConversion: '<S546>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S546>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S567>/Switch' incorporates:
           *  Constant: '<S586>/Constant'
           *  Constant: '<S587>/Constant'
           *  Constant: '<S589>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S586>/Compare'
           *  RelationalOperator: '<S587>/Compare'
           *  RelationalOperator: '<S589>/Compare'
           *  S-Function (sfix_bitop): '<S567>/ax_cmd'
           *  S-Function (sfix_bitop): '<S567>/ay_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S567>/Logical Operator' incorporates:
             *  Constant: '<S587>/Constant'
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S587>/Compare'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S567>/ax_cmd'
             *  S-Function (sfix_bitop): '<S567>/ay_cmd'
             */
            rtb_Compare_at = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_at;
          } else {
            rtb_Compare_at = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S567>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S463>/Bus Assignment'
           *  Constant: '<S463>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S463>/Bus Assignment' incorporates:
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

          /* Saturate: '<S547>/Saturation' */
          if (rtb_u_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_u_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S547>/Saturation' */

          /* Saturate: '<S548>/Saturation2' */
          if (rtb_TmpSignalConversionAtMultip[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_TmpSignalConversionAtMultip[0] < -FMS_PARAM.VEL_XY_LIM)
          {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMultip[0];
          }

          /* End of Saturate: '<S548>/Saturation2' */

          /* Saturate: '<S548>/Saturation1' */
          if (rtb_TmpSignalConversionAtMultip[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_TmpSignalConversionAtMultip[1] < -FMS_PARAM.VEL_XY_LIM)
          {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMultip[1];
          }

          /* End of Saturate: '<S548>/Saturation1' */

          /* Saturate: '<S548>/Saturation3' */
          if (rtb_Saturation_ga > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_ga < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S463>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;
          }

          /* End of Saturate: '<S548>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S546>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S546>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S546>/throttle_cmd_valid' */
          /* BusAssignment: '<S463>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S559>/Constant'
           *  Constant: '<S560>/Constant'
           *  Constant: '<S561>/Constant'
           *  Constant: '<S562>/Constant'
           *  Constant: '<S563>/Constant'
           *  Constant: '<S564>/Constant'
           *  Constant: '<S565>/Constant'
           *  Constant: '<S585>/Constant'
           *  Constant: '<S588>/Constant'
           *  DataTypeConversion: '<S546>/Data Type Conversion10'
           *  DataTypeConversion: '<S546>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S568>/bit_shift'
           *  MATLAB Function: '<S569>/bit_shift'
           *  MATLAB Function: '<S570>/bit_shift'
           *  MATLAB Function: '<S572>/bit_shift'
           *  MATLAB Function: '<S573>/bit_shift'
           *  MATLAB Function: '<S574>/bit_shift'
           *  MATLAB Function: '<S575>/bit_shift'
           *  MATLAB Function: '<S576>/bit_shift'
           *  MATLAB Function: '<S577>/bit_shift'
           *  MATLAB Function: '<S580>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S559>/Compare'
           *  RelationalOperator: '<S560>/Compare'
           *  RelationalOperator: '<S561>/Compare'
           *  RelationalOperator: '<S562>/Compare'
           *  RelationalOperator: '<S563>/Compare'
           *  RelationalOperator: '<S564>/Compare'
           *  RelationalOperator: '<S565>/Compare'
           *  RelationalOperator: '<S585>/Compare'
           *  RelationalOperator: '<S588>/Compare'
           *  S-Function (sfix_bitop): '<S546>/p_cmd'
           *  S-Function (sfix_bitop): '<S546>/phi_cmd'
           *  S-Function (sfix_bitop): '<S546>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S546>/q_cmd'
           *  S-Function (sfix_bitop): '<S546>/r_cmd'
           *  S-Function (sfix_bitop): '<S546>/theta_cmd'
           *  S-Function (sfix_bitop): '<S546>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S566>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S567>/az_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           *  Sum: '<S546>/Add'
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

          /* End of Outputs for SubSystem: '<S546>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S546>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S546>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S351>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S351>/Mission' incorporates:
             *  ActionPort: '<S462>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S351>/Switch Case' incorporates:
             *  UnitDelay: '<S465>/Delay Input1'
             *
             * Block description for '<S465>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S351>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S351>/Mission' incorporates:
             *  ActionPort: '<S462>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S462>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S351>/Switch Case' incorporates:
             *  Chart: '<S504>/Motion Status'
             *  Chart: '<S514>/Motion State'
             *  Delay: '<S470>/Delay'
             *  Delay: '<S492>/Delay'
             *  DiscreteIntegrator: '<S473>/Integrator'
             *  DiscreteIntegrator: '<S473>/Integrator1'
             *  DiscreteIntegrator: '<S488>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S493>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S540>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S462>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S351>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S351>/Mission' incorporates:
           *  ActionPort: '<S462>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S465>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S465>/Delay Input1'
           *
           * Block description for '<S465>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S462>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S466>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S513>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S503>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S492>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S493>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S488>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S540>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S470>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S473>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S473>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S514>/Motion State' */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S504>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S492>/Delay' incorporates:
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
          /* Switch: '<S488>/Switch2' incorporates:
           *  Constant: '<S488>/vel'
           *  Constant: '<S497>/Constant'
           *  RelationalOperator: '<S497>/Compare'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S488>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S493>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S465>/Delay Input1'
           *
           * Block description for '<S465>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S487>/Compare' incorporates:
           *  Constant: '<S544>/Constant'
           *  RelationalOperator: '<S544>/Compare'
           *  UnitDelay: '<S465>/Delay Input1'
           *
           * Block description for '<S465>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S488>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S514>/Motion State' incorporates:
           *  Constant: '<S514>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S514>/Square'
           *  Math: '<S514>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S514>/Sqrt'
           *  Sum: '<S514>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S513>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S523>/Integrator1'
           *  Gain: '<S517>/Gain6'
           *  Gain: '<S521>/Gain'
           *  Gain: '<S522>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S523>/Subtract'
           *  Sum: '<S524>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S513>/Hold Control' incorporates:
               *  ActionPort: '<S516>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S513>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S513>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S513>/Hold Control' incorporates:
             *  ActionPort: '<S516>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S513>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S513>/Brake Control' incorporates:
             *  ActionPort: '<S515>/Action Port'
             */
            FMS_BrakeControl_e1(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S513>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S513>/Move Control' incorporates:
               *  ActionPort: '<S517>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S513>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S523>/Integrator'
               *  DiscreteIntegrator: '<S523>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S513>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S513>/Move Control' incorporates:
             *  ActionPort: '<S517>/Action Port'
             */
            /* SignalConversion: '<S517>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S524>/Multiply1' incorporates:
             *  Constant: '<S524>/const1'
             *  DiscreteIntegrator: '<S523>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S517>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S524>/Multiply1' incorporates:
             *  Constant: '<S524>/const1'
             *  DiscreteIntegrator: '<S523>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S521>/Dead Zone' incorporates:
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

            /* Sum: '<S524>/Add' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator1'
             *  Gain: '<S517>/Gain6'
             *  Gain: '<S521>/Gain'
             *  Sum: '<S523>/Subtract'
             */
            rtb_Divide_f0[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S522>/Dead Zone' incorporates:
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

            /* Sum: '<S524>/Add' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator1'
             *  Gain: '<S517>/Gain6'
             *  Gain: '<S522>/Gain'
             *  Sum: '<S523>/Subtract'
             */
            rtb_Divide_f0[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S521>/Dead Zone' incorporates:
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

            /* Signum: '<S524>/Sign' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator1'
             *  Gain: '<S517>/Gain6'
             *  Gain: '<S521>/Gain'
             *  Sum: '<S523>/Subtract'
             *  Sum: '<S524>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S524>/Add2' incorporates:
             *  Abs: '<S524>/Abs'
             *  Gain: '<S524>/Gain'
             *  Gain: '<S524>/Gain1'
             *  Product: '<S524>/Multiply2'
             *  Product: '<S524>/Multiply3'
             *  Signum: '<S524>/Sign'
             *  Sqrt: '<S524>/Sqrt'
             *  Sum: '<S524>/Add1'
             *  Sum: '<S524>/Subtract'
             */
            rtb_Subtract1_o = (sqrtf((8.0F * fabsf(rtb_Divide_f0[0]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_Saturation1_d + rtb_Subtract_hb[0];

            /* Sum: '<S524>/Add3' incorporates:
             *  Signum: '<S524>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_f0[0] + FMS_ConstB.d_oe;

            /* Sum: '<S524>/Subtract1' incorporates:
             *  Signum: '<S524>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_f0[0] - FMS_ConstB.d_oe;

            /* Signum: '<S524>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S524>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S524>/Add5' incorporates:
             *  Gain: '<S524>/Gain2'
             *  Product: '<S524>/Multiply4'
             *  Signum: '<S524>/Sign'
             *  Sum: '<S524>/Add2'
             *  Sum: '<S524>/Add4'
             *  Sum: '<S524>/Subtract2'
             */
            rtb_Subtract1_o += ((rtb_Divide_f0[0] - rtb_Subtract1_o) +
                                rtb_Subtract_hb[0]) * ((rtb_Saturation_ga -
              rtb_Saturation1_d) * 0.5F);

            /* Update for DiscreteIntegrator: '<S523>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S524>/Sign4' incorporates:
             *  Sum: '<S524>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Subtract1_o - FMS_ConstB.d_oe;

            /* Signum: '<S524>/Sign3' incorporates:
             *  Sum: '<S524>/Add6'
             */
            rtb_Saturation1_d = rtb_Subtract1_o + FMS_ConstB.d_oe;

            /* Signum: '<S524>/Sign5' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Subtract1_o > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Subtract1_o;
            }

            /* Signum: '<S524>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S524>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S524>/Sign6' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Subtract1_o > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Subtract1_o;
            }

            /* Update for DiscreteIntegrator: '<S523>/Integrator' incorporates:
             *  Constant: '<S524>/const'
             *  Gain: '<S524>/Gain3'
             *  Product: '<S524>/Divide'
             *  Product: '<S524>/Multiply5'
             *  Product: '<S524>/Multiply6'
             *  Sum: '<S524>/Subtract4'
             *  Sum: '<S524>/Subtract5'
             *  Sum: '<S524>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Subtract1_o / FMS_ConstB.d_oe
              - rtb_Saturation_o4) * FMS_ConstB.Gain4_g * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_u_b * 58.836F) * 0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S522>/Dead Zone' incorporates:
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

            /* Signum: '<S524>/Sign' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator1'
             *  Gain: '<S517>/Gain6'
             *  Gain: '<S522>/Gain'
             *  Sum: '<S523>/Subtract'
             *  Sum: '<S524>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S524>/Add2' incorporates:
             *  Abs: '<S524>/Abs'
             *  Gain: '<S524>/Gain'
             *  Gain: '<S524>/Gain1'
             *  Product: '<S524>/Multiply2'
             *  Product: '<S524>/Multiply3'
             *  Signum: '<S524>/Sign'
             *  Sqrt: '<S524>/Sqrt'
             *  Sum: '<S524>/Add1'
             *  Sum: '<S524>/Subtract'
             */
            rtb_Subtract1_o = (sqrtf((8.0F * fabsf(rtb_Divide_f0[1]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_Saturation1_d + rtb_Subtract_hb[1];

            /* Sum: '<S524>/Add3' incorporates:
             *  Signum: '<S524>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_f0[1] + FMS_ConstB.d_oe;

            /* Sum: '<S524>/Subtract1' incorporates:
             *  Signum: '<S524>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_f0[1] - FMS_ConstB.d_oe;

            /* Signum: '<S524>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S524>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S524>/Add5' incorporates:
             *  Gain: '<S524>/Gain2'
             *  Product: '<S524>/Multiply4'
             *  Signum: '<S524>/Sign'
             *  Sum: '<S524>/Add2'
             *  Sum: '<S524>/Add4'
             *  Sum: '<S524>/Subtract2'
             */
            rtb_Subtract1_o += ((rtb_Divide_f0[1] - rtb_Subtract1_o) +
                                rtb_Subtract_hb[1]) * ((rtb_Saturation_ga -
              rtb_Saturation1_d) * 0.5F);

            /* Update for DiscreteIntegrator: '<S523>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S523>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S524>/Sign4' incorporates:
             *  Sum: '<S524>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Subtract1_o - FMS_ConstB.d_oe;

            /* Signum: '<S524>/Sign3' incorporates:
             *  Sum: '<S524>/Add6'
             */
            rtb_Saturation1_d = rtb_Subtract1_o + FMS_ConstB.d_oe;

            /* Signum: '<S524>/Sign5' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Subtract1_o > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Subtract1_o;
            }

            /* Signum: '<S524>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S524>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S524>/Sign6' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Subtract1_o > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Subtract1_o;
            }

            /* Update for DiscreteIntegrator: '<S523>/Integrator' incorporates:
             *  Constant: '<S524>/const'
             *  Gain: '<S524>/Gain3'
             *  Product: '<S524>/Divide'
             *  Product: '<S524>/Multiply5'
             *  Product: '<S524>/Multiply6'
             *  Sum: '<S524>/Subtract4'
             *  Sum: '<S524>/Subtract5'
             *  Sum: '<S524>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Subtract1_o / FMS_ConstB.d_oe
              - rtb_Saturation_o4) * FMS_ConstB.Gain4_g * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_u_b * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S513>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S513>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S504>/Motion Status' incorporates:
           *  Abs: '<S504>/Abs'
           *  Constant: '<S504>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S503>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S503>/Hold Control' incorporates:
               *  ActionPort: '<S506>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S503>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S503>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S503>/Hold Control' incorporates:
             *  ActionPort: '<S506>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S503>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S503>/Brake Control' incorporates:
             *  ActionPort: '<S505>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S503>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S503>/Move Control' incorporates:
               *  ActionPort: '<S507>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S503>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S510>/Integrator'
               *  DiscreteIntegrator: '<S510>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S503>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S503>/Move Control' incorporates:
             *  ActionPort: '<S507>/Action Port'
             */
            /* Product: '<S511>/Multiply1' incorporates:
             *  Constant: '<S511>/const1'
             *  DiscreteIntegrator: '<S510>/Integrator'
             */
            rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S509>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S509>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S511>/Add' incorporates:
             *  DiscreteIntegrator: '<S510>/Integrator1'
             *  Gain: '<S507>/Gain1'
             *  Gain: '<S509>/Gain'
             *  Sum: '<S510>/Subtract'
             */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_u_b * -FMS_PARAM.VEL_Z_LIM) +
              rtb_Saturation_ga;

            /* Signum: '<S511>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Saturation1_d;
            }

            /* End of Signum: '<S511>/Sign' */

            /* Sum: '<S511>/Add2' incorporates:
             *  Abs: '<S511>/Abs'
             *  Gain: '<S511>/Gain'
             *  Gain: '<S511>/Gain1'
             *  Product: '<S511>/Multiply2'
             *  Product: '<S511>/Multiply3'
             *  Sqrt: '<S511>/Sqrt'
             *  Sum: '<S511>/Add1'
             *  Sum: '<S511>/Subtract'
             */
            rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_oc)
                             * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_o4 + rtb_Saturation_ga;

            /* Sum: '<S511>/Add4' */
            rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) +
              rtb_Saturation_ga;

            /* Sum: '<S511>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_oc;

            /* Sum: '<S511>/Subtract1' */
            rtb_Saturation1_d -= FMS_ConstB.d_oc;

            /* Signum: '<S511>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S511>/Sign1' */

            /* Signum: '<S511>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S511>/Sign2' */

            /* Sum: '<S511>/Add5' incorporates:
             *  Gain: '<S511>/Gain2'
             *  Product: '<S511>/Multiply4'
             *  Sum: '<S511>/Subtract2'
             */
            rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
              rtb_Saturation_o4;

            /* SignalConversion: '<S507>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S510>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S510>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S510>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S511>/Subtract3' */
            rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_oc;

            /* Sum: '<S511>/Add6' */
            rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_oc;

            /* Signum: '<S511>/Sign5' incorporates:
             *  Signum: '<S511>/Sign6'
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_o4 = -1.0F;

              /* Signum: '<S511>/Sign6' */
              rtb_Subtract1_o = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Saturation_o4 = 1.0F;

              /* Signum: '<S511>/Sign6' */
              rtb_Subtract1_o = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_u_b;

              /* Signum: '<S511>/Sign6' */
              rtb_Subtract1_o = rtb_u_b;
            }

            /* End of Signum: '<S511>/Sign5' */

            /* Signum: '<S511>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S511>/Sign3' */

            /* Signum: '<S511>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S511>/Sign4' */

            /* Update for DiscreteIntegrator: '<S510>/Integrator' incorporates:
             *  Constant: '<S511>/const'
             *  Gain: '<S511>/Gain3'
             *  Product: '<S511>/Divide'
             *  Product: '<S511>/Multiply5'
             *  Product: '<S511>/Multiply6'
             *  Sum: '<S511>/Subtract4'
             *  Sum: '<S511>/Subtract5'
             *  Sum: '<S511>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_u_b / FMS_ConstB.d_oc -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_j * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S503>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S503>/Switch Case' */

          /* Switch: '<S468>/Switch' incorporates:
           *  Product: '<S492>/Multiply'
           *  Sum: '<S492>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S513>/Saturation1' */
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

            /* End of Saturate: '<S513>/Saturation1' */

            /* Saturate: '<S503>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S503>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S492>/Sum' incorporates:
             *  Delay: '<S492>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S541>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S488>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S492>/Sum' incorporates:
             *  Delay: '<S492>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S488>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S500>/Sqrt' incorporates:
             *  Math: '<S500>/Square'
             *  Sum: '<S488>/Sum'
             *  Sum: '<S500>/Sum of Elements'
             */
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S543>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S543>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S543>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S542>/Gain' incorporates:
             *  DiscreteIntegrator: '<S540>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S540>/Add'
             */
            rtb_u_b = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S543>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = arm_cos_f32(rtb_u_b);

            /* Gain: '<S543>/Gain' incorporates:
             *  Trigonometry: '<S543>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(rtb_u_b);

            /* SignalConversion: '<S543>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S543>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Trigonometry: '<S543>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = arm_sin_f32(rtb_u_b);

            /* Trigonometry: '<S543>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = arm_cos_f32(rtb_u_b);

            /* Switch: '<S499>/Switch2' incorporates:
             *  Constant: '<S488>/Constant2'
             *  DiscreteIntegrator: '<S488>/Acceleration_Speed'
             *  RelationalOperator: '<S499>/LowerRelop1'
             *  RelationalOperator: '<S499>/UpperRelop'
             *  Switch: '<S499>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_u_b = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S499>/Switch' incorporates:
               *  Constant: '<S488>/Constant2'
               */
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S499>/Switch2' */

            /* Switch: '<S488>/Switch' */
            if (rtb_Saturation_ga > FMS_PARAM.L1) {
              rtb_Saturation1_d = d;
            } else {
              /* Gain: '<S488>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_Saturation_ga;

              /* Switch: '<S498>/Switch2' incorporates:
               *  Constant: '<S488>/Constant1'
               *  RelationalOperator: '<S498>/LowerRelop1'
               *  RelationalOperator: '<S498>/UpperRelop'
               *  Switch: '<S498>/Switch'
               */
              if (rtb_Saturation1_d > d) {
                rtb_Saturation1_d = d;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  /* Switch: '<S498>/Switch' incorporates:
                   *  Constant: '<S488>/Constant1'
                   */
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Switch: '<S498>/Switch2' */
            }

            /* End of Switch: '<S488>/Switch' */

            /* Switch: '<S488>/Switch1' incorporates:
             *  Sum: '<S488>/Sum1'
             */
            if (rtb_u_b - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = rtb_u_b;
            }

            /* End of Switch: '<S488>/Switch1' */

            /* Sum: '<S541>/Sum of Elements' incorporates:
             *  Math: '<S541>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Saturation_o4 *
              rtb_Saturation_o4;

            /* Math: '<S541>/Math Function1' incorporates:
             *  Sum: '<S541>/Sum of Elements'
             *
             * About '<S541>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_u_b = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_u_b = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S541>/Math Function1' */

            /* Switch: '<S541>/Switch' incorporates:
             *  Constant: '<S541>/Constant'
             *  Product: '<S541>/Product'
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

            /* End of Switch: '<S541>/Switch' */

            /* Product: '<S539>/Multiply2' incorporates:
             *  Product: '<S541>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_bu[0] / rtb_Divide_bu[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_bu[1] / rtb_Divide_bu[3];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S494>/Sum1' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_u_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S494>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract1_o = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Sign5_ke = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S494>/Divide' incorporates:
             *  Math: '<S495>/Square'
             *  Math: '<S496>/Square'
             *  Sqrt: '<S495>/Sqrt'
             *  Sqrt: '<S496>/Sqrt'
             *  Sum: '<S494>/Sum'
             *  Sum: '<S494>/Sum1'
             *  Sum: '<S495>/Sum of Elements'
             *  Sum: '<S496>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Subtract1_o * rtb_Subtract1_o + rtb_Sign5_ke *
                            rtb_Sign5_ke) / sqrtf(rtb_Saturation_o4 *
              rtb_Saturation_o4 + rtb_u_b * rtb_u_b);

            /* Saturate: '<S494>/Saturation' */
            if (rtb_u_b > 1.0F) {
              rtb_u_b = 1.0F;
            } else {
              if (rtb_u_b < 0.0F) {
                rtb_u_b = 0.0F;
              }
            }

            /* End of Saturate: '<S494>/Saturation' */

            /* Product: '<S492>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n +
                3] * rtb_Saturation1_d + rtb_VectorConcatenate[rtb_n] *
                rtb_Saturation_ga;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S485>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S494>/Multiply'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S485>/Sum2'
             *  Sum: '<S494>/Add'
             *  Sum: '<S494>/Subtract'
             */
            rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_b +
                        FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_MatrixConcatenate1_a_0[0];
            rtb_Switch_c2[1] = rtb_MatrixConcatenate1_a_0[1];

            /* Saturate: '<S485>/Saturation1' incorporates:
             *  Product: '<S492>/Multiply'
             */
            if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_u_b;
            }

            /* End of Saturate: '<S485>/Saturation1' */
          }

          /* End of Switch: '<S468>/Switch' */

          /* Delay: '<S470>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S473>/Integrator1' incorporates:
           *  Delay: '<S470>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S477>/Rem' incorporates:
           *  Constant: '<S477>/Constant1'
           *  DiscreteIntegrator: '<S473>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S472>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S477>/Switch' incorporates:
           *  Abs: '<S477>/Abs'
           *  Constant: '<S477>/Constant'
           *  Constant: '<S478>/Constant'
           *  Product: '<S477>/Multiply'
           *  RelationalOperator: '<S478>/Compare'
           *  Sum: '<S477>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S477>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S477>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S477>/Switch' */

          /* Gain: '<S472>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S472>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S472>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S466>/Bus Assignment'
           *  Constant: '<S466>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S466>/Bus Assignment' incorporates:
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

          /* Math: '<S534>/Math Function1'
           *
           * About '<S534>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_jq < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Divide_jq));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Divide_jq);
          }

          /* End of Math: '<S534>/Math Function1' */

          /* Switch: '<S534>/Switch' incorporates:
           *  Constant: '<S534>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S534>/Product'
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

          /* End of Switch: '<S534>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S466>/Sum' incorporates:
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

          /* SignalConversion: '<S484>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S466>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S484>/Math Function' incorporates:
           *  Sum: '<S466>/Sum'
           */
          rtb_Square_dv[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_dv[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S484>/Sum of Elements' */
          rtb_u_b = rtb_Square_dv[0] + rtb_Square_dv[1];

          /* Math: '<S484>/Math Function1' incorporates:
           *  Sum: '<S484>/Sum of Elements'
           *
           * About '<S484>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S484>/Math Function1' */

          /* Switch: '<S484>/Switch' incorporates:
           *  Constant: '<S484>/Constant'
           *  Product: '<S484>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Divide_jq = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Divide_jq = 1.0F;
          }

          /* End of Switch: '<S484>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S490>/NearbyRefWP' incorporates:
           *  Constant: '<S466>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_TmpSignalConversionAtMultip[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f0,
                          &rtb_u_b);

          /* MATLAB Function: '<S490>/SearchL1RefWP' incorporates:
           *  Constant: '<S466>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_TmpSignalConversionAtMultip
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S490>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0],
                               &rtb_TmpSignalConversionAtMultip[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_dv);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S490>/Switch1' incorporates:
           *  Constant: '<S527>/Constant'
           *  RelationalOperator: '<S527>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_f0[0];
            rtb_P_ap[1] = rtb_Divide_f0[1];
          } else {
            /* RelationalOperator: '<S526>/Compare' incorporates:
             *  Constant: '<S526>/Constant'
             */
            rtb_Compare_at = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S490>/Switch' */
            if (!rtb_Compare_at) {
              rtb_P_ap[0] = rtb_Square_dv[0];
              rtb_P_ap[1] = rtb_Square_dv[1];
            }

            /* End of Switch: '<S490>/Switch' */
          }

          /* End of Switch: '<S490>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S491>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract1_o = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Subtract1_o;
          rtb_Saturation_o4 = rtb_Subtract1_o * rtb_Subtract1_o;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S491>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S535>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract1_o = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S535>/Sum of Elements' incorporates:
           *  Math: '<S535>/Math Function'
           *  Sum: '<S533>/Sum of Elements'
           */
          rtb_u_b = rtb_Saturation_o4 + rtb_Subtract1_o * rtb_Subtract1_o;

          /* Math: '<S535>/Math Function1' incorporates:
           *  Sum: '<S535>/Sum of Elements'
           *
           * About '<S535>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S535>/Math Function1' */

          /* Switch: '<S535>/Switch' incorporates:
           *  Constant: '<S535>/Constant'
           *  Product: '<S535>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_TmpSignalConversionAtMultip[0] = rtb_P_ap[0];
            rtb_TmpSignalConversionAtMultip[1] = rtb_Subtract1_o;
            rtb_TmpSignalConversionAtMultip[2] = rtb_Saturation_o4;
          } else {
            rtb_TmpSignalConversionAtMultip[0] = 0.0F;
            rtb_TmpSignalConversionAtMultip[1] = 0.0F;
            rtb_TmpSignalConversionAtMultip[2] = 1.0F;
          }

          /* End of Switch: '<S535>/Switch' */

          /* Product: '<S534>/Divide' */
          rtb_Divide_f0[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_f0[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S537>/Sum of Elements' incorporates:
           *  Math: '<S537>/Math Function'
           *  SignalConversion: '<S537>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Sign5_ke = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S537>/Math Function1' incorporates:
           *  Sum: '<S537>/Sum of Elements'
           *
           * About '<S537>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Sign5_ke < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Sign5_ke));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Sign5_ke);
          }

          /* End of Math: '<S537>/Math Function1' */

          /* Switch: '<S537>/Switch' incorporates:
           *  Constant: '<S537>/Constant'
           *  Product: '<S537>/Product'
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

          /* End of Switch: '<S537>/Switch' */

          /* Product: '<S535>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Sum: '<S538>/Sum of Elements' incorporates:
           *  Math: '<S538>/Math Function'
           *  SignalConversion: '<S538>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Sign5_ke = rtb_Divide_f0[1] * rtb_Divide_f0[1] + rtb_Divide_f0[0] *
            rtb_Divide_f0[0];

          /* Math: '<S538>/Math Function1' incorporates:
           *  Sum: '<S538>/Sum of Elements'
           *
           * About '<S538>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Sign5_ke < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Sign5_ke));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Sign5_ke);
          }

          /* End of Math: '<S538>/Math Function1' */

          /* Switch: '<S538>/Switch' incorporates:
           *  Constant: '<S538>/Constant'
           *  Product: '<S538>/Product'
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

          /* End of Switch: '<S538>/Switch' */

          /* Product: '<S538>/Divide' */
          rtb_Divide_f0[0] = rtb_TmpSignalConversionAtMultip[0] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S537>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S484>/Divide' */
          rtb_Square_dv[0] = rtb_Saturation_ga / rtb_Divide_jq;

          /* Product: '<S538>/Divide' */
          rtb_Divide_f0[1] = rtb_TmpSignalConversionAtMultip[1] /
            rtb_TmpSignalConversionAtMultip[2];

          /* Product: '<S537>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S484>/Divide' */
          rtb_Square_dv[1] = rtb_Saturation1_d / rtb_Divide_jq;

          /* Sum: '<S536>/Subtract' incorporates:
           *  Product: '<S536>/Multiply'
           *  Product: '<S536>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_f0[0] * rtb_P_ap[1] - rtb_Divide_f0[1] *
            rtb_P_ap[0];

          /* Signum: '<S531>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S531>/Sign1' */

          /* Switch: '<S531>/Switch2' incorporates:
           *  Constant: '<S531>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S531>/Switch2' */

          /* DotProduct: '<S531>/Dot Product' */
          rtb_Subtract1_o = rtb_P_ap[0] * rtb_Divide_f0[0] + rtb_P_ap[1] *
            rtb_Divide_f0[1];

          /* Trigonometry: '<S531>/Acos' incorporates:
           *  DotProduct: '<S531>/Dot Product'
           */
          if (rtb_Subtract1_o > 1.0F) {
            rtb_Subtract1_o = 1.0F;
          } else {
            if (rtb_Subtract1_o < -1.0F) {
              rtb_Subtract1_o = -1.0F;
            }
          }

          /* Product: '<S531>/Multiply' incorporates:
           *  Trigonometry: '<S531>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Subtract1_o);

          /* Saturate: '<S491>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S491>/Saturation' */

          /* Product: '<S491>/Divide' incorporates:
           *  Constant: '<S466>/L1'
           *  Constant: '<S491>/Constant'
           *  Gain: '<S491>/Gain'
           *  Math: '<S491>/Square'
           *  MinMax: '<S491>/Max'
           *  MinMax: '<S491>/Min'
           *  Product: '<S491>/Multiply1'
           *  Sqrt: '<S533>/Sqrt'
           *  Trigonometry: '<S491>/Sin'
           */
          rtb_Saturation1_p5 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S482>/Subtract' incorporates:
           *  Product: '<S482>/Multiply'
           *  Product: '<S482>/Multiply1'
           */
          rtb_Subtract1_o = rtb_Square_dv[0] * FMS_ConstB.Divide[1] -
            rtb_Square_dv[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S471>/Sign1' */
          if (rtb_Subtract1_o < 0.0F) {
            rtb_Subtract1_o = -1.0F;
          } else {
            if (rtb_Subtract1_o > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            }
          }

          /* End of Signum: '<S471>/Sign1' */

          /* Switch: '<S471>/Switch2' incorporates:
           *  Constant: '<S471>/Constant4'
           */
          if (rtb_Subtract1_o == 0.0F) {
            rtb_Subtract1_o = 1.0F;
          }

          /* End of Switch: '<S471>/Switch2' */

          /* DotProduct: '<S471>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide[0] * rtb_Square_dv[0] + FMS_ConstB.Divide
            [1] * rtb_Square_dv[1];

          /* Trigonometry: '<S471>/Acos' incorporates:
           *  DotProduct: '<S471>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S471>/Multiply' incorporates:
           *  Trigonometry: '<S471>/Acos'
           */
          rtb_Subtract1_o *= acosf(rtb_u_b);

          /* Math: '<S474>/Rem' incorporates:
           *  Constant: '<S474>/Constant1'
           *  Delay: '<S470>/Delay'
           *  Sum: '<S470>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Subtract1_o - FMS_DW.Delay_DSTATE_n,
            6.28318548F);

          /* Switch: '<S474>/Switch' incorporates:
           *  Abs: '<S474>/Abs'
           *  Constant: '<S474>/Constant'
           *  Constant: '<S480>/Constant'
           *  Product: '<S474>/Multiply'
           *  RelationalOperator: '<S480>/Compare'
           *  Sum: '<S474>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S474>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S474>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S474>/Switch' */

          /* Sum: '<S470>/Sum' incorporates:
           *  Delay: '<S470>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S479>/Multiply1' incorporates:
           *  Constant: '<S479>/const1'
           *  DiscreteIntegrator: '<S473>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S479>/Add' incorporates:
           *  DiscreteIntegrator: '<S473>/Integrator1'
           *  Sum: '<S473>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S479>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S479>/Sign' */

          /* Sum: '<S479>/Add2' incorporates:
           *  Abs: '<S479>/Abs'
           *  Gain: '<S479>/Gain'
           *  Gain: '<S479>/Gain1'
           *  Product: '<S479>/Multiply2'
           *  Product: '<S479>/Multiply3'
           *  Sqrt: '<S479>/Sqrt'
           *  Sum: '<S479>/Add1'
           *  Sum: '<S479>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_m) *
                           FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S479>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S479>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_m;

          /* Sum: '<S479>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_m;

          /* Signum: '<S479>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S479>/Sign1' */

          /* Signum: '<S479>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S479>/Sign2' */

          /* Sum: '<S479>/Add5' incorporates:
           *  Gain: '<S479>/Gain2'
           *  Product: '<S479>/Multiply4'
           *  Sum: '<S479>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S479>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_m;

          /* Sum: '<S479>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_m;

          /* Product: '<S479>/Divide' */
          rtb_Divide_jq = rtb_u_b / FMS_ConstB.d_m;

          /* Signum: '<S479>/Sign5' incorporates:
           *  Signum: '<S479>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_ke = -1.0F;

            /* Signum: '<S479>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_ke = 1.0F;

            /* Signum: '<S479>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_ke = rtb_u_b;

            /* Signum: '<S479>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S479>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S470>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract1_o -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S475>/Rem' incorporates:
           *  Constant: '<S475>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Subtract1_o, 6.28318548F);

          /* Switch: '<S475>/Switch' incorporates:
           *  Abs: '<S475>/Abs'
           *  Constant: '<S475>/Constant'
           *  Constant: '<S481>/Constant'
           *  Product: '<S475>/Multiply'
           *  RelationalOperator: '<S481>/Compare'
           *  Sum: '<S475>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S475>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Subtract1_o = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            } else {
              rtb_Subtract1_o = rtb_u_b;
            }

            /* End of Signum: '<S475>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Subtract1_o;
          }

          /* End of Switch: '<S475>/Switch' */

          /* Abs: '<S468>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S492>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S493>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S486>/Constant'
           *  RelationalOperator: '<S486>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S493>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S488>/Acceleration_Speed' incorporates:
           *  Constant: '<S488>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S492>/Divide1' */
          rtb_u_b = rtb_Saturation1_p5 / d;

          /* Saturate: '<S492>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S492>/Saturation' */

          /* Update for DiscreteIntegrator: '<S540>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_u_b;

          /* Update for Delay: '<S470>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S473>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S473>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S479>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S479>/Sign3' */

          /* Signum: '<S479>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S479>/Sign4' */

          /* Update for DiscreteIntegrator: '<S473>/Integrator' incorporates:
           *  Constant: '<S479>/const'
           *  Gain: '<S479>/Gain3'
           *  Product: '<S479>/Multiply5'
           *  Product: '<S479>/Multiply6'
           *  Sum: '<S479>/Subtract4'
           *  Sum: '<S479>/Subtract5'
           *  Sum: '<S479>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Divide_jq - rtb_Sign5_ke) *
            FMS_ConstB.Gain4_cu * ((rtb_Saturation_ga - rtb_Saturation1_d) *
            0.5F) - rtb_Saturation_o4 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S473>/Integrator' */
          /* End of Outputs for SubSystem: '<S462>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S465>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S465>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S351>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S351>/Unknown' incorporates:
           *  ActionPort: '<S464>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S351>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
         *  ActionPort: '<S350>/Action Port'
         */
        /* SwitchCase: '<S350>/Switch Case' */
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
            /* Disable for SwitchCase: '<S449>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S365>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S383>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S399>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S424>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S411>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S350>/Acro' incorporates:
           *  ActionPort: '<S355>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S355>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S355>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Gain: '<S360>/Gain'
           *  Gain: '<S360>/Gain1'
           *  Gain: '<S360>/Gain2'
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

          /* Saturate: '<S361>/Saturation' incorporates:
           *  Constant: '<S361>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  Sum: '<S361>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_u_b = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S361>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S361>/Constant5'
           *  Gain: '<S361>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S361>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_u_b), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S350>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S350>/Stabilize' incorporates:
             *  ActionPort: '<S358>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S350>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S445>/Integrator'
             *  DiscreteIntegrator: '<S445>/Integrator1'
             *  DiscreteIntegrator: '<S446>/Integrator'
             *  DiscreteIntegrator: '<S446>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S350>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S350>/Stabilize' incorporates:
             *  ActionPort: '<S358>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S350>/Switch Case' incorporates:
             *  Chart: '<S450>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S350>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S350>/Stabilize' incorporates:
           *  ActionPort: '<S358>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S440>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S450>/Motion State' incorporates:
           *  Abs: '<S450>/Abs'
           *  Abs: '<S450>/Abs1'
           *  Constant: '<S460>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S460>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S449>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S449>/Hold Control' incorporates:
               *  ActionPort: '<S452>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S449>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S449>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S449>/Hold Control' incorporates:
             *  ActionPort: '<S452>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S449>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S449>/Brake Control' incorporates:
             *  ActionPort: '<S451>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S449>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S449>/Move Control' incorporates:
               *  ActionPort: '<S453>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S449>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S449>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S449>/Move Control' incorporates:
             *  ActionPort: '<S453>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S449>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S449>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S442>/Switch' incorporates:
           *  Constant: '<S442>/Constant'
           *  Constant: '<S442>/Constant4'
           *  Constant: '<S442>/Constant5'
           *  Gain: '<S442>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S442>/Saturation'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S442>/Add'
           *  Sum: '<S442>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S442>/Saturation' */
              rtb_u_b = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S442>/Saturation' */
              rtb_u_b = 0.0F;
            } else {
              /* Saturate: '<S442>/Saturation' incorporates:
               *  Constant: '<S442>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S43>/Signal Copy2'
               *  Sum: '<S442>/Sum'
               */
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_u_b),
              65536.0F) + 1000U);
          }

          /* End of Switch: '<S442>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S358>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S358>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S358>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S440>/Data Type Conversion'
           *  DiscreteIntegrator: '<S445>/Integrator1'
           *  DiscreteIntegrator: '<S446>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S440>/Multiply'
           *  Product: '<S440>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S449>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S358>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S358>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S358>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S449>/Saturation' */

          /* BusAssignment: '<S358>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S448>/Multiply1' incorporates:
           *  Constant: '<S448>/const1'
           *  DiscreteIntegrator: '<S446>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S444>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S444>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S448>/Add' incorporates:
           *  DiscreteIntegrator: '<S446>/Integrator1'
           *  Gain: '<S440>/Gain1'
           *  Gain: '<S444>/Gain'
           *  Sum: '<S446>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S448>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S448>/Sign' */

          /* Sum: '<S448>/Add2' incorporates:
           *  Abs: '<S448>/Abs'
           *  Gain: '<S448>/Gain'
           *  Gain: '<S448>/Gain1'
           *  Product: '<S448>/Multiply2'
           *  Product: '<S448>/Multiply3'
           *  Sqrt: '<S448>/Sqrt'
           *  Sum: '<S448>/Add1'
           *  Sum: '<S448>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_g) * FMS_ConstB.d_g)
               - FMS_ConstB.d_g) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S448>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S448>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_g;

          /* Sum: '<S448>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_g;

          /* Signum: '<S448>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S448>/Sign1' */

          /* Signum: '<S448>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S448>/Sign2' */

          /* Sum: '<S448>/Add5' incorporates:
           *  Gain: '<S448>/Gain2'
           *  Product: '<S448>/Multiply4'
           *  Sum: '<S448>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S448>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_g;

          /* Sum: '<S448>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_g;

          /* Product: '<S448>/Divide' */
          rtb_Subtract1_o = d / FMS_ConstB.d_g;

          /* Signum: '<S448>/Sign5' incorporates:
           *  Signum: '<S448>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_jq = -1.0F;

            /* Signum: '<S448>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_jq = 1.0F;

            /* Signum: '<S448>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Divide_jq = d;

            /* Signum: '<S448>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S448>/Sign5' */

          /* Product: '<S447>/Multiply1' incorporates:
           *  Constant: '<S447>/const1'
           *  DiscreteIntegrator: '<S445>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S443>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S443>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S447>/Add' incorporates:
           *  DiscreteIntegrator: '<S445>/Integrator1'
           *  Gain: '<S440>/Gain'
           *  Gain: '<S443>/Gain'
           *  Sum: '<S445>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S447>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S447>/Sign' */

          /* Sum: '<S447>/Add2' incorporates:
           *  Abs: '<S447>/Abs'
           *  Gain: '<S447>/Gain'
           *  Gain: '<S447>/Gain1'
           *  Product: '<S447>/Multiply2'
           *  Product: '<S447>/Multiply3'
           *  Sqrt: '<S447>/Sqrt'
           *  Sum: '<S447>/Add1'
           *  Sum: '<S447>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_a) * FMS_ConstB.d_a)
               - FMS_ConstB.d_a) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S447>/Add4' */
          rtb_Sign5_ke = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S447>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_a;

          /* Sum: '<S447>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_a;

          /* Signum: '<S447>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S447>/Sign1' */

          /* Signum: '<S447>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S447>/Sign2' */

          /* Sum: '<S447>/Add5' incorporates:
           *  Gain: '<S447>/Gain2'
           *  Product: '<S447>/Multiply4'
           *  Sum: '<S447>/Subtract2'
           */
          d += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Sign5_ke;

          /* Update for DiscreteIntegrator: '<S445>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S445>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S446>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S446>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S448>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S448>/Sign3' */

          /* Signum: '<S448>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S448>/Sign4' */

          /* Update for DiscreteIntegrator: '<S446>/Integrator' incorporates:
           *  Constant: '<S448>/const'
           *  Gain: '<S448>/Gain3'
           *  Product: '<S448>/Multiply5'
           *  Product: '<S448>/Multiply6'
           *  Sum: '<S448>/Subtract4'
           *  Sum: '<S448>/Subtract5'
           *  Sum: '<S448>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Subtract1_o - rtb_Divide_jq) *
            FMS_ConstB.Gain4_o * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Sum: '<S447>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_a;

          /* Sum: '<S447>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_a;

          /* Signum: '<S447>/Sign5' incorporates:
           *  Signum: '<S447>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S447>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S447>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S447>/Sign6' */
            rtb_Subtract1_o = d;
          }

          /* End of Signum: '<S447>/Sign5' */

          /* Signum: '<S447>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S447>/Sign3' */

          /* Signum: '<S447>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S447>/Sign4' */

          /* Update for DiscreteIntegrator: '<S445>/Integrator' incorporates:
           *  Constant: '<S447>/const'
           *  Gain: '<S447>/Gain3'
           *  Product: '<S447>/Divide'
           *  Product: '<S447>/Multiply5'
           *  Product: '<S447>/Multiply6'
           *  Sum: '<S447>/Subtract4'
           *  Sum: '<S447>/Subtract5'
           *  Sum: '<S447>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((d / FMS_ConstB.d_a - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_k * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Subtract1_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S350>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S350>/Altitude' incorporates:
             *  ActionPort: '<S356>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S350>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator'
             *  DiscreteIntegrator: '<S379>/Integrator1'
             *  DiscreteIntegrator: '<S380>/Integrator'
             *  DiscreteIntegrator: '<S380>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S350>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S350>/Altitude' incorporates:
             *  ActionPort: '<S356>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S350>/Switch Case' incorporates:
             *  Chart: '<S366>/Motion Status'
             *  Chart: '<S384>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S350>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S350>/Altitude' incorporates:
           *  ActionPort: '<S356>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S366>/Motion Status' incorporates:
           *  Abs: '<S366>/Abs'
           *  Abs: '<S366>/Abs1'
           *  Constant: '<S375>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S375>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S365>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S365>/Hold Control' incorporates:
               *  ActionPort: '<S368>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S365>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S365>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S365>/Hold Control' incorporates:
             *  ActionPort: '<S368>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S365>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S365>/Brake Control' incorporates:
             *  ActionPort: '<S367>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S365>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S365>/Move Control' incorporates:
             *  ActionPort: '<S369>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S365>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S365>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S362>/Switch' incorporates:
           *  Constant: '<S362>/Constant'
           *  Saturate: '<S365>/Saturation1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_ga = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S365>/Saturation1' */
            rtb_Saturation_ga = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S365>/Saturation1' */
            rtb_Saturation_ga = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S365>/Saturation1' */
            rtb_Saturation_ga = FMS_B.Merge_l;
          }

          /* End of Switch: '<S362>/Switch' */

          /* Logic: '<S363>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S384>/Motion State' incorporates:
           *  Abs: '<S384>/Abs'
           *  Abs: '<S384>/Abs1'
           *  Constant: '<S394>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S394>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S383>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S383>/Hold Control' incorporates:
               *  ActionPort: '<S386>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S383>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_pi);

              /* End of SystemReset for SubSystem: '<S383>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S383>/Hold Control' incorporates:
             *  ActionPort: '<S386>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_pi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S383>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S383>/Brake Control' incorporates:
             *  ActionPort: '<S385>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S383>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S383>/Move Control' incorporates:
               *  ActionPort: '<S387>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S383>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S383>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S383>/Move Control' incorporates:
             *  ActionPort: '<S387>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S383>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S383>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S356>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S356>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S356>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S363>/Data Type Conversion'
           *  DiscreteIntegrator: '<S379>/Integrator1'
           *  DiscreteIntegrator: '<S380>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S363>/Multiply'
           *  Product: '<S363>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S383>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S356>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S356>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S356>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S383>/Saturation' */

          /* BusAssignment: '<S356>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;

          /* Product: '<S382>/Multiply1' incorporates:
           *  Constant: '<S382>/const1'
           *  DiscreteIntegrator: '<S380>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S378>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S378>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S382>/Add' incorporates:
           *  DiscreteIntegrator: '<S380>/Integrator1'
           *  Gain: '<S363>/Gain1'
           *  Gain: '<S378>/Gain'
           *  Sum: '<S380>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S382>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S382>/Sign' */

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
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_o) * FMS_ConstB.d_o)
               - FMS_ConstB.d_o) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S382>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S382>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_o;

          /* Sum: '<S382>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_o;

          /* Signum: '<S382>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S382>/Sign1' */

          /* Signum: '<S382>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S382>/Sign2' */

          /* Sum: '<S382>/Add5' incorporates:
           *  Gain: '<S382>/Gain2'
           *  Product: '<S382>/Multiply4'
           *  Sum: '<S382>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S382>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_o;

          /* Sum: '<S382>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_o;

          /* Product: '<S382>/Divide' */
          rtb_Subtract1_o = d / FMS_ConstB.d_o;

          /* Signum: '<S382>/Sign5' incorporates:
           *  Signum: '<S382>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_jq = -1.0F;

            /* Signum: '<S382>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_jq = 1.0F;

            /* Signum: '<S382>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Divide_jq = d;

            /* Signum: '<S382>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S382>/Sign5' */

          /* Product: '<S381>/Multiply1' incorporates:
           *  Constant: '<S381>/const1'
           *  DiscreteIntegrator: '<S379>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S377>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S377>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S381>/Add' incorporates:
           *  DiscreteIntegrator: '<S379>/Integrator1'
           *  Gain: '<S363>/Gain'
           *  Gain: '<S377>/Gain'
           *  Sum: '<S379>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S381>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
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
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_c) * FMS_ConstB.d_c)
               - FMS_ConstB.d_c) * 0.5F * d + rtb_Saturation1_p5;

          /* Sum: '<S381>/Add4' */
          rtb_Sign5_ke = (rtb_u_b - d) + rtb_Saturation1_p5;

          /* Sum: '<S381>/Add3' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_c;

          /* Sum: '<S381>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_c;

          /* Signum: '<S381>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign1' */

          /* Signum: '<S381>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign2' */

          /* Sum: '<S381>/Add5' incorporates:
           *  Gain: '<S381>/Gain2'
           *  Product: '<S381>/Multiply4'
           *  Sum: '<S381>/Subtract2'
           */
          d += (rtb_Saturation1_p5 - rtb_u_b) * 0.5F * rtb_Sign5_ke;

          /* Update for DiscreteIntegrator: '<S379>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S379>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S380>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S380>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S382>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S382>/Sign3' */

          /* Signum: '<S382>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S382>/Sign4' */

          /* Update for DiscreteIntegrator: '<S380>/Integrator' incorporates:
           *  Constant: '<S382>/const'
           *  Gain: '<S382>/Gain3'
           *  Product: '<S382>/Multiply5'
           *  Product: '<S382>/Multiply6'
           *  Sum: '<S382>/Subtract4'
           *  Sum: '<S382>/Subtract5'
           *  Sum: '<S382>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Subtract1_o - rtb_Divide_jq) *
            FMS_ConstB.Gain4_c * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 12.566371F) * 0.004F;

          /* Sum: '<S381>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_c;

          /* Sum: '<S381>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_c;

          /* Signum: '<S381>/Sign5' incorporates:
           *  Signum: '<S381>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S381>/Sign6' */
            rtb_Subtract1_o = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S381>/Sign6' */
            rtb_Subtract1_o = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S381>/Sign6' */
            rtb_Subtract1_o = d;
          }

          /* End of Signum: '<S381>/Sign5' */

          /* Signum: '<S381>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign3' */

          /* Signum: '<S381>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S381>/Sign4' */

          /* Update for DiscreteIntegrator: '<S379>/Integrator' incorporates:
           *  Constant: '<S381>/const'
           *  Gain: '<S381>/Gain3'
           *  Product: '<S381>/Divide'
           *  Product: '<S381>/Multiply5'
           *  Product: '<S381>/Multiply6'
           *  Sum: '<S381>/Subtract4'
           *  Sum: '<S381>/Subtract5'
           *  Sum: '<S381>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((d / FMS_ConstB.d_c - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_h * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Subtract1_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S350>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S350>/Position' incorporates:
             *  ActionPort: '<S357>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S350>/Switch Case' incorporates:
             *  Chart: '<S400>/Motion Status'
             *  Chart: '<S412>/Motion State'
             *  Chart: '<S425>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S350>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S350>/Position' incorporates:
           *  ActionPort: '<S357>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S400>/Motion Status' incorporates:
           *  Abs: '<S400>/Abs'
           *  Abs: '<S400>/Abs1'
           *  Constant: '<S409>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S409>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S399>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S399>/Hold Control' incorporates:
               *  ActionPort: '<S402>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S399>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S399>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S399>/Hold Control' incorporates:
             *  ActionPort: '<S402>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S399>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S399>/Brake Control' incorporates:
             *  ActionPort: '<S401>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S399>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S399>/Move Control' incorporates:
             *  ActionPort: '<S403>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S399>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S399>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S412>/Motion State' incorporates:
           *  Abs: '<S412>/Abs'
           *  Abs: '<S412>/Abs1'
           *  Constant: '<S422>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S422>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S425>/Logical Operator' incorporates:
           *  Abs: '<S425>/Abs1'
           *  Abs: '<S425>/Abs2'
           *  Constant: '<S437>/Constant'
           *  Constant: '<S438>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S437>/Compare'
           *  RelationalOperator: '<S438>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S425>/Motion State' */
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

          /* End of Chart: '<S425>/Motion State' */

          /* SwitchCase: '<S424>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S424>/Hold Control' incorporates:
               *  ActionPort: '<S426>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S424>/Switch Case' incorporates:
               *  Delay: '<S426>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S424>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S424>/Hold Control' incorporates:
             *  ActionPort: '<S426>/Action Port'
             */
            /* Delay: '<S426>/Delay' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            if (FMS_DW.icLoad != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Trigonometry: '<S430>/Trigonometric Function1' */
            rtb_VectorConcatenate[0] = rtb_Saturation_ga;

            /* Trigonometry: '<S430>/Trigonometric Function' */
            rtb_VectorConcatenate[1] = rtb_Saturation1_d;

            /* SignalConversion: '<S430>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S430>/Constant3'
             */
            rtb_VectorConcatenate[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S430>/Gain' incorporates:
             *  Gain: '<S429>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S430>/Trigonometric Function2'
             */
            rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S430>/Trigonometric Function3' */
            rtb_VectorConcatenate[4] = rtb_Saturation_ga;

            /* SignalConversion: '<S430>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S430>/Constant4'
             */
            rtb_VectorConcatenate[5] = 0.0F;

            /* SignalConversion: '<S430>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S426>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S426>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S426>/Sum'
             */
            d = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_jq = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S426>/Multiply' incorporates:
             *  SignalConversion: '<S426>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_a_0[rtb_n] = rtb_VectorConcatenate[rtb_n +
                3] * rtb_Divide_jq + rtb_VectorConcatenate[rtb_n] * d;
            }

            /* End of Product: '<S426>/Multiply' */

            /* Gain: '<S426>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_a_0[1];

            /* Update for Delay: '<S426>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S424>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S424>/Move Control' incorporates:
               *  ActionPort: '<S427>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S424>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S433>/Integrator'
               *  DiscreteIntegrator: '<S433>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S424>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S424>/Move Control' incorporates:
             *  ActionPort: '<S427>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S431>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S431>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S431>/Gain' */
            rtb_Saturation_o4 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S432>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S432>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S432>/Gain' */
            rtb_Saturation1_p5 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

            /* Sum: '<S434>/Sum of Elements' incorporates:
             *  Math: '<S434>/Square'
             *  SignalConversion: '<S434>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S435>/Sum of Elements'
             *  Switch: '<S427>/Switch'
             */
            rtb_u_b = rtb_Saturation_o4 * rtb_Saturation_o4 + rtb_Saturation1_p5
              * rtb_Saturation1_p5;

            /* Switch: '<S427>/Switch' incorporates:
             *  Product: '<S435>/Divide'
             *  Sqrt: '<S434>/Sqrt'
             *  Sum: '<S434>/Sum of Elements'
             */
            if (sqrtf(rtb_u_b) > 1.0F) {
              /* Math: '<S435>/Math Function1'
               *
               * About '<S435>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_u_b < 0.0F) {
                rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
              } else {
                rtb_Saturation_ga = sqrtf(rtb_u_b);
              }

              /* End of Math: '<S435>/Math Function1' */

              /* Switch: '<S435>/Switch' incorporates:
               *  Constant: '<S435>/Constant'
               *  Product: '<S435>/Product'
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

              /* End of Switch: '<S435>/Switch' */
              rtb_Saturation_o4 = rtb_TmpSignalConversionAtMultip[0] /
                rtb_TmpSignalConversionAtMultip[2];
              rtb_Saturation1_p5 = rtb_TmpSignalConversionAtMultip[1] /
                rtb_TmpSignalConversionAtMultip[2];
            }

            /* Product: '<S436>/Multiply1' incorporates:
             *  Constant: '<S436>/const1'
             *  DiscreteIntegrator: '<S433>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S436>/Add' incorporates:
             *  DiscreteIntegrator: '<S433>/Integrator1'
             *  Gain: '<S427>/Gain6'
             *  Sum: '<S433>/Subtract'
             */
            rtb_Subtract1_o = (FMS_DW.Integrator1_DSTATE[0] -
                               FMS_PARAM.VEL_XY_LIM * rtb_Saturation_o4) +
              rtb_Saturation1_d;

            /* Signum: '<S436>/Sign' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Subtract1_o > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Subtract1_o;
            }

            /* Sum: '<S436>/Add2' incorporates:
             *  Abs: '<S436>/Abs'
             *  Gain: '<S436>/Gain'
             *  Gain: '<S436>/Gain1'
             *  Product: '<S436>/Multiply2'
             *  Product: '<S436>/Multiply3'
             *  Sqrt: '<S436>/Sqrt'
             *  Sum: '<S436>/Add1'
             *  Sum: '<S436>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Subtract1_o) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S436>/Add4' */
            rtb_Saturation1_d += rtb_Subtract1_o - rtb_Saturation_o4;

            /* Sum: '<S436>/Add3' */
            rtb_Saturation_ga = rtb_Subtract1_o + FMS_ConstB.d;

            /* Sum: '<S436>/Subtract1' */
            rtb_Subtract1_o -= FMS_ConstB.d;

            /* Signum: '<S436>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S436>/Sign2' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_Subtract1_o = -1.0F;
            } else {
              if (rtb_Subtract1_o > 0.0F) {
                rtb_Subtract1_o = 1.0F;
              }
            }

            /* Sum: '<S436>/Add5' incorporates:
             *  Gain: '<S436>/Gain2'
             *  Product: '<S436>/Multiply4'
             *  Sum: '<S436>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Subtract1_o) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S433>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S433>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S433>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S433>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S436>/Sign4' incorporates:
             *  Sum: '<S436>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S436>/Sign3' incorporates:
             *  Sum: '<S436>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S436>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S436>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S436>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S436>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Subtract1_o = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            } else {
              rtb_Subtract1_o = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S433>/Integrator' incorporates:
             *  Constant: '<S436>/const'
             *  Gain: '<S436>/Gain3'
             *  Product: '<S436>/Divide'
             *  Product: '<S436>/Multiply5'
             *  Product: '<S436>/Multiply6'
             *  Sum: '<S436>/Subtract4'
             *  Sum: '<S436>/Subtract5'
             *  Sum: '<S436>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 39.224F) * 0.004F;

            /* Product: '<S436>/Multiply1' incorporates:
             *  Constant: '<S436>/const1'
             *  DiscreteIntegrator: '<S433>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S436>/Add' incorporates:
             *  DiscreteIntegrator: '<S433>/Integrator1'
             *  Gain: '<S427>/Gain6'
             *  Sum: '<S433>/Subtract'
             */
            rtb_Subtract1_o = (FMS_DW.Integrator1_DSTATE[1] -
                               FMS_PARAM.VEL_XY_LIM * rtb_Saturation1_p5) +
              rtb_Saturation1_d;

            /* Signum: '<S436>/Sign' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Subtract1_o > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Subtract1_o;
            }

            /* Sum: '<S436>/Add2' incorporates:
             *  Abs: '<S436>/Abs'
             *  Gain: '<S436>/Gain'
             *  Gain: '<S436>/Gain1'
             *  Product: '<S436>/Multiply2'
             *  Product: '<S436>/Multiply3'
             *  Sqrt: '<S436>/Sqrt'
             *  Sum: '<S436>/Add1'
             *  Sum: '<S436>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Subtract1_o) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S436>/Add4' */
            rtb_Saturation1_d += rtb_Subtract1_o - rtb_Saturation_o4;

            /* Sum: '<S436>/Add3' */
            rtb_Saturation_ga = rtb_Subtract1_o + FMS_ConstB.d;

            /* Sum: '<S436>/Subtract1' */
            rtb_Subtract1_o -= FMS_ConstB.d;

            /* Signum: '<S436>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S436>/Sign2' */
            if (rtb_Subtract1_o < 0.0F) {
              rtb_Subtract1_o = -1.0F;
            } else {
              if (rtb_Subtract1_o > 0.0F) {
                rtb_Subtract1_o = 1.0F;
              }
            }

            /* Sum: '<S436>/Add5' incorporates:
             *  Gain: '<S436>/Gain2'
             *  Product: '<S436>/Multiply4'
             *  Sum: '<S436>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Subtract1_o) * 0.5F *
              rtb_Saturation1_d;

            /* SignalConversion: '<S433>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S433>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S433>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S433>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S436>/Sign4' incorporates:
             *  Sum: '<S436>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S436>/Sign3' incorporates:
             *  Sum: '<S436>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S436>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S436>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S436>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S436>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Subtract1_o = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Subtract1_o = 1.0F;
            } else {
              rtb_Subtract1_o = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S433>/Integrator' incorporates:
             *  Constant: '<S436>/const'
             *  Gain: '<S436>/Gain3'
             *  Product: '<S436>/Divide'
             *  Product: '<S436>/Multiply5'
             *  Product: '<S436>/Multiply6'
             *  Sum: '<S436>/Subtract4'
             *  Sum: '<S436>/Subtract5'
             *  Sum: '<S436>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Subtract1_o * 39.224F) * 0.004F;

            /* End of Outputs for SubSystem: '<S424>/Move Control' */
            break;
          }

          /* SwitchCase: '<S411>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S411>/Hold Control' incorporates:
               *  ActionPort: '<S414>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S411>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S411>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S411>/Hold Control' incorporates:
             *  ActionPort: '<S414>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S411>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S411>/Brake Control' incorporates:
             *  ActionPort: '<S413>/Action Port'
             */
            FMS_BrakeControl_e(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S411>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S411>/Move Control' incorporates:
               *  ActionPort: '<S415>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S411>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S411>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S411>/Move Control' incorporates:
             *  ActionPort: '<S415>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S411>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S411>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S357>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S357>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S357>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S411>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S411>/Saturation' */

          /* Saturate: '<S424>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S424>/Saturation1' */

          /* Saturate: '<S399>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S357>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S399>/Saturation1' */
          /* End of Outputs for SubSystem: '<S350>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S350>/Unknown' incorporates:
           *  ActionPort: '<S359>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S350>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S50>/Manual' incorporates:
         *  ActionPort: '<S352>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S352>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S352>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S352>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S352>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S50>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S50>/Unknown' incorporates:
         *  ActionPort: '<S354>/Action Port'
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
   *  DiscreteIntegrator: '<S795>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S795>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S795>/Constant'
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
  FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;

  /* End of Start for SubSystem: '<S125>/Altitude' */

  /* Start for IfAction SubSystem: '<S125>/Position' */
  /* Start for SwitchCase: '<S181>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S166>/Switch Case' */
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
  /* Start for SwitchCase: '<S353>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S353>/Return' */
  /* Start for SwitchCase: '<S753>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S743>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S353>/Return' */

  /* Start for IfAction SubSystem: '<S353>/Hold' */
  /* Start for SwitchCase: '<S692>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S660>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S671>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S353>/Hold' */
  /* End of Start for SubSystem: '<S50>/SubMode' */

  /* Start for IfAction SubSystem: '<S50>/Auto' */
  /* Start for SwitchCase: '<S351>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S351>/Mission' */
  /* Start for Resettable SubSystem: '<S462>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S513>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S503>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S462>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S351>/Mission' */
  /* End of Start for SubSystem: '<S50>/Auto' */

  /* Start for IfAction SubSystem: '<S50>/Assist' */
  /* Start for SwitchCase: '<S350>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S350>/Stabilize' */
  /* Start for SwitchCase: '<S449>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S350>/Stabilize' */

  /* Start for IfAction SubSystem: '<S350>/Altitude' */
  /* Start for SwitchCase: '<S365>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S383>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S350>/Altitude' */

  /* Start for IfAction SubSystem: '<S350>/Position' */
  /* Start for SwitchCase: '<S399>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S424>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S411>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S350>/Position' */
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
  /* InitializeConditions for Delay: '<S293>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S288>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S128>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S49>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S126>/Mission' */
  /* InitializeConditions for UnitDelay: '<S249>/Delay Input1'
   *
   * Block description for '<S249>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S246>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S259>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_li = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S258>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_ew = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S259>/Integrator' */
  FMS_DW.Integrator_DSTATE_fk = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S258>/Integrator' */
  FMS_DW.Integrator_DSTATE_oc = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S246>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S126>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S49>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S125>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S239>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S239>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S240>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_oo = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S244>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jv = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S244>/Integrator' */
  FMS_DW.Integrator_DSTATE_jp = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S240>/Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_hv = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_ml = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
  FMS_DW.Integrator_DSTATE_kn = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Integrator' */
  FMS_DW.Integrator_DSTATE_k1 = 0.0F;

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
  /* InitializeConditions for DiscreteIntegrator: '<S170>/Integrator' */
  FMS_DW.Integrator_DSTATE_c5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S170>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S179>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S229>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S229>/Integrator' */
  FMS_DW.Integrator_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S179>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S167>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S182>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S181>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_b, &FMS_DW.HoldControl_b);

  /* End of SystemInitialize for SubSystem: '<S181>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S166>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S166>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S166>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S166>/Move Control' */

  /* SystemInitialize for Merge: '<S166>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S181>/Merge' */
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
  /* SystemInitialize for IfAction SubSystem: '<S353>/Takeoff' */
  /* InitializeConditions for Delay: '<S793>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S789>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S789>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S353>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S353>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S353>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S353>/Return' */
  /* InitializeConditions for Delay: '<S738>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S739>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S734>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S780>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S717>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S720>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S720>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S754>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S753>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S753>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S753>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S753>/Move Control' */

  /* SystemInitialize for Merge: '<S753>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S744>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S743>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S743>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S743>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_cg);

  /* End of SystemInitialize for SubSystem: '<S743>/Move Control' */

  /* SystemInitialize for Merge: '<S743>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S353>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S353>/Hold' */
  /* InitializeConditions for Delay: '<S673>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S685>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S685>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S661>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S672>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S693>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S692>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S692>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S692>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S692>/Move Control' */

  /* SystemInitialize for Merge: '<S692>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S660>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S660>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S660>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S660>/Move Control' */

  /* SystemInitialize for Merge: '<S660>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S671>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S671>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S671>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S671>/Move Control' */

  /* SystemInitialize for Merge: '<S671>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S353>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S50>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S351>/Mission' */
  /* InitializeConditions for UnitDelay: '<S465>/Delay Input1'
   *
   * Block description for '<S465>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S462>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S492>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S493>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S488>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S540>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S470>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S473>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S473>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S514>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S513>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S513>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S513>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S523>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S523>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S513>/Move Control' */

  /* SystemInitialize for Merge: '<S513>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S513>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S523>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S523>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S513>/Move Control' */

  /* SystemInitialize for Merge: '<S513>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S504>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S503>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S503>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S503>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S510>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S510>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S503>/Move Control' */

  /* SystemInitialize for Merge: '<S503>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S462>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S351>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S50>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S350>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S445>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S446>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S446>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S445>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S450>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S449>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S449>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S449>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S449>/Move Control' */

  /* SystemInitialize for Merge: '<S449>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S350>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S350>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S380>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S380>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S366>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S365>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S365>/Hold Control' */

  /* SystemInitialize for Merge: '<S365>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S384>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S383>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_pi);

  /* End of SystemInitialize for SubSystem: '<S383>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S383>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S383>/Move Control' */

  /* SystemInitialize for Merge: '<S383>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S350>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S350>/Position' */
  /* SystemInitialize for Chart: '<S400>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S399>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S399>/Hold Control' */

  /* SystemInitialize for Chart: '<S412>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S425>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S424>/Hold Control' */
  /* InitializeConditions for Delay: '<S426>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S424>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S424>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S433>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S433>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S424>/Move Control' */

  /* SystemInitialize for Merge: '<S424>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S424>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S433>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S433>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S424>/Move Control' */

  /* SystemInitialize for Merge: '<S424>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S399>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S411>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S411>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S411>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S411>/Move Control' */

  /* SystemInitialize for Merge: '<S411>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S350>/Position' */
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
