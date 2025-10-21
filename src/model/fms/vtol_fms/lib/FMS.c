/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2597
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 21 16:52:21 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S123>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S163>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<S718>/Motion Status' */
#define FMS_IN_Brake_bq                ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S728>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_ol                 ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S424>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S646>/Motion State' */
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
struct_I9zhY9cxiv5dGpkYkLPNKB FMS_PARAM = {
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
  1.0F,
  5.0F,
  5.0F,
  2.0F,
  1.0F,
  0.5F,
  0.6F,
  120U,
  1U,
  1300U,
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
  100.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S4>/Constant1'
                                        *   '<S7>/Land_Lock_Thro'
                                        *   '<S40>/Constant'
                                        *   '<S770>/Constant1'
                                        *   '<S771>/Constant'
                                        *   '<S773>/Constant1'
                                        *   '<S774>/FW_ACCEPT_R'
                                        *   '<S774>/MC_ACCEPT_R'
                                        *   '<S777>/Constant'
                                        *   '<S52>/Gain1'
                                        *   '<S52>/Gain2'
                                        *   '<S52>/Gain6'
                                        *   '<S53>/Saturation1'
                                        *   '<S100>/Dead Zone'
                                        *   '<S100>/Gain'
                                        *   '<S101>/Dead Zone'
                                        *   '<S101>/Gain'
                                        *   '<S102>/Dead Zone'
                                        *   '<S102>/Gain'
                                        *   '<S253>/Dead Zone'
                                        *   '<S253>/Gain'
                                        *   '<S254>/Dead Zone'
                                        *   '<S254>/Gain'
                                        *   '<S255>/Dead Zone'
                                        *   '<S255>/Gain'
                                        *   '<S256>/Dead Zone'
                                        *   '<S256>/Gain'
                                        *   '<S259>/Constant4'
                                        *   '<S260>/Constant4'
                                        *   '<S628>/L1'
                                        *   '<S56>/L1'
                                        *   '<S57>/Gain6'
                                        *   '<S95>/Constant'
                                        *   '<S96>/Constant'
                                        *   '<S119>/Gain'
                                        *   '<S120>/Gain1'
                                        *   '<S121>/Saturation1'
                                        *   '<S144>/Gain1'
                                        *   '<S146>/Saturation1'
                                        *   '<S211>/Gain'
                                        *   '<S211>/Gain1'
                                        *   '<S212>/Gain1'
                                        *   '<S262>/Gain2'
                                        *   '<S262>/Saturation1'
                                        *   '<S263>/L1'
                                        *   '<S263>/R'
                                        *   '<S263>/Saturation1'
                                        *   '<S280>/Gain'
                                        *   '<S280>/Saturation1'
                                        *   '<S302>/Gain'
                                        *   '<S302>/Saturation1'
                                        *   '<S337>/Gain'
                                        *   '<S337>/Gain1'
                                        *   '<S414>/Gain'
                                        *   '<S414>/Gain1'
                                        *   '<S416>/Constant'
                                        *   '<S440>/L1'
                                        *   '<S521>/Saturation'
                                        *   '<S522>/Saturation1'
                                        *   '<S522>/Saturation2'
                                        *   '<S522>/Saturation3'
                                        *   '<S679>/Land_Speed'
                                        *   '<S680>/Saturation1'
                                        *   '<S759>/Takeoff_Speed'
                                        *   '<S760>/Gain2'
                                        *   '<S760>/Saturation1'
                                        *   '<S92>/Dead Zone'
                                        *   '<S92>/Gain'
                                        *   '<S122>/Saturation1'
                                        *   '<S134>/Dead Zone'
                                        *   '<S134>/Gain'
                                        *   '<S137>/Dead Zone'
                                        *   '<S137>/Gain'
                                        *   '<S140>/Constant'
                                        *   '<S140>/Constant1'
                                        *   '<S140>/Constant2'
                                        *   '<S147>/Saturation1'
                                        *   '<S159>/Dead Zone'
                                        *   '<S159>/Gain'
                                        *   '<S162>/Saturation1'
                                        *   '<S208>/Constant'
                                        *   '<S208>/Constant1'
                                        *   '<S208>/Constant2'
                                        *   '<S214>/Dead Zone'
                                        *   '<S214>/Gain'
                                        *   '<S215>/Dead Zone'
                                        *   '<S215>/Gain'
                                        *   '<S220>/Dead Zone'
                                        *   '<S220>/Gain'
                                        *   '<S228>/Gain'
                                        *   '<S228>/Saturation1'
                                        *   '<S229>/Constant4'
                                        *   '<S229>/Saturation'
                                        *   '<S285>/L1'
                                        *   '<S285>/Saturation1'
                                        *   '<S307>/L1'
                                        *   '<S307>/Saturation1'
                                        *   '<S339>/Saturation1'
                                        *   '<S351>/Dead Zone'
                                        *   '<S351>/Gain'
                                        *   '<S352>/Dead Zone'
                                        *   '<S352>/Gain'
                                        *   '<S357>/Saturation'
                                        *   '<S373>/Saturation1'
                                        *   '<S385>/Saturation'
                                        *   '<S398>/Saturation1'
                                        *   '<S417>/Dead Zone'
                                        *   '<S417>/Gain'
                                        *   '<S418>/Dead Zone'
                                        *   '<S418>/Gain'
                                        *   '<S423>/Saturation'
                                        *   '<S577>/Gain2'
                                        *   '<S584>/Gain1'
                                        *   '<S584>/Gain2'
                                        *   '<S634>/Saturation1'
                                        *   '<S645>/Saturation'
                                        *   '<S666>/Saturation1'
                                        *   '<S681>/Constant'
                                        *   '<S684>/Gain2'
                                        *   '<S708>/Constant'
                                        *   '<S708>/vel'
                                        *   '<S708>/Acceleration_Speed'
                                        *   '<S708>/Saturation'
                                        *   '<S708>/Switch'
                                        *   '<S712>/Constant'
                                        *   '<S124>/Gain2'
                                        *   '<S125>/Gain1'
                                        *   '<S132>/Constant'
                                        *   '<S149>/Gain2'
                                        *   '<S150>/Gain1'
                                        *   '<S157>/Constant'
                                        *   '<S164>/L1'
                                        *   '<S165>/Gain6'
                                        *   '<S203>/Constant'
                                        *   '<S204>/Constant'
                                        *   '<S236>/L1'
                                        *   '<S236>/Saturation1'
                                        *   '<S342>/Gain2'
                                        *   '<S343>/Gain1'
                                        *   '<S349>/Constant'
                                        *   '<S360>/Gain2'
                                        *   '<S361>/Gain1'
                                        *   '<S368>/Constant'
                                        *   '<S376>/Gain2'
                                        *   '<S377>/Gain1'
                                        *   '<S383>/Constant'
                                        *   '<S388>/Gain2'
                                        *   '<S389>/Gain1'
                                        *   '<S396>/Constant'
                                        *   '<S400>/Gain2'
                                        *   '<S401>/Gain6'
                                        *   '<S411>/Constant'
                                        *   '<S412>/Constant'
                                        *   '<S426>/Gain2'
                                        *   '<S427>/Gain1'
                                        *   '<S434>/Constant'
                                        *   '<S459>/Gain'
                                        *   '<S459>/Saturation1'
                                        *   '<S462>/Constant'
                                        *   '<S462>/vel'
                                        *   '<S462>/Switch'
                                        *   '<S637>/Gain2'
                                        *   '<S638>/Gain1'
                                        *   '<S649>/Gain2'
                                        *   '<S650>/Gain1'
                                        *   '<S658>/Gain2'
                                        *   '<S658>/Saturation'
                                        *   '<S659>/Integrator'
                                        *   '<S669>/Gain2'
                                        *   '<S670>/Gain6'
                                        *   '<S693>/Gain2'
                                        *   '<S693>/Saturation'
                                        *   '<S694>/Integrator'
                                        *   '<S128>/Dead Zone'
                                        *   '<S128>/Gain'
                                        *   '<S153>/Dead Zone'
                                        *   '<S153>/Gain'
                                        *   '<S200>/Dead Zone'
                                        *   '<S200>/Gain'
                                        *   '<S345>/Land_Speed'
                                        *   '<S346>/Constant'
                                        *   '<S348>/Dead Zone'
                                        *   '<S348>/Gain'
                                        *   '<S365>/Dead Zone'
                                        *   '<S365>/Gain'
                                        *   '<S379>/Land_Speed'
                                        *   '<S380>/Constant'
                                        *   '<S382>/Dead Zone'
                                        *   '<S382>/Gain'
                                        *   '<S393>/Dead Zone'
                                        *   '<S393>/Gain'
                                        *   '<S405>/Dead Zone'
                                        *   '<S405>/Gain'
                                        *   '<S406>/Dead Zone'
                                        *   '<S406>/Gain'
                                        *   '<S431>/Dead Zone'
                                        *   '<S431>/Gain'
                                        *   '<S446>/Gain2'
                                        *   '<S446>/Saturation'
                                        *   '<S447>/Integrator'
                                        *   '<S640>/Dead Zone'
                                        *   '<S640>/Gain'
                                        *   '<S654>/Dead Zone'
                                        *   '<S654>/Gain'
                                        *   '<S674>/Dead Zone'
                                        *   '<S674>/Gain'
                                        *   '<S675>/Dead Zone'
                                        *   '<S675>/Gain'
                                        *   '<S717>/Saturation1'
                                        *   '<S727>/Saturation1'
                                        *   '<S477>/Saturation1'
                                        *   '<S487>/Saturation1'
                                        *   '<S720>/Gain2'
                                        *   '<S721>/Gain1'
                                        *   '<S730>/Gain2'
                                        *   '<S731>/Gain6'
                                        *   '<S480>/Gain2'
                                        *   '<S481>/Gain1'
                                        *   '<S490>/Gain2'
                                        *   '<S491>/Gain6'
                                        *   '<S723>/Dead Zone'
                                        *   '<S723>/Gain'
                                        *   '<S735>/Dead Zone'
                                        *   '<S735>/Gain'
                                        *   '<S736>/Dead Zone'
                                        *   '<S736>/Gain'
                                        *   '<S483>/Dead Zone'
                                        *   '<S483>/Gain'
                                        *   '<S495>/Dead Zone'
                                        *   '<S495>/Gain'
                                        *   '<S496>/Dead Zone'
                                        *   '<S496>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S7>/Constant1'
                                        *   '<S26>/Constant1'
                                        *   '<S769>/Constant'
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
 *    '<S309>/NearbyRefWP'
 *    '<S287>/NearbyRefWP'
 *    '<S238>/NearbyRefWP'
 *    '<S710>/NearbyRefWP'
 *    '<S464>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S313>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S309>/SearchL1RefWP'
 *    '<S287>/SearchL1RefWP'
 *    '<S238>/SearchL1RefWP'
 *    '<S710>/SearchL1RefWP'
 *    '<S464>/SearchL1RefWP'
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

  /* SignalConversion: '<S315>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S287>/OutRegionRegWP'
 *    '<S238>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S292>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S112>/Unknown'
 *    '<S110>/Unknown'
 *    '<S109>/Unknown'
 *    '<S49>/Unknown'
 *    '<S327>/Unknown'
 *    '<S325>/Unknown'
 *    '<S324>/Unknown'
 *    '<S50>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S261>/Bus Assignment' incorporates:
   *  Constant: '<S261>/Constant'
   *  Constant: '<S261>/Constant2'
   *  SignalConversion: '<S261>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S261>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S122>/Hold Control'
 *    '<S147>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S124>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S122>/Hold Control'
 *    '<S147>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S124>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S122>/Hold Control'
 *    '<S147>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S124>/Delay' incorporates:
   *  Gain: '<S127>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S124>/Gain2' incorporates:
   *  Delay: '<S124>/Delay'
   *  Gain: '<S127>/Gain'
   *  Sum: '<S124>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S124>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S122>/Move Control'
 *    '<S147>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S122>/Move Control'
 *    '<S147>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S122>/Move Control'
 *    '<S147>/Move Control'
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

  /* Product: '<S130>/Multiply1' incorporates:
   *  Constant: '<S130>/const1'
   *  DiscreteIntegrator: '<S129>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S128>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_ft = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_ft = 0.0F;
  } else {
    rtb_a_ft = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S128>/Dead Zone' */

  /* Sum: '<S130>/Add' incorporates:
   *  DiscreteIntegrator: '<S129>/Integrator1'
   *  Gain: '<S125>/Gain1'
   *  Gain: '<S128>/Gain'
   *  Sum: '<S129>/Subtract'
   */
  rtb_Subtract3_cx = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_ft * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_a;

  /* Signum: '<S130>/Sign' */
  if (rtb_Subtract3_cx < 0.0F) {
    rtb_a_ft = -1.0F;
  } else if (rtb_Subtract3_cx > 0.0F) {
    rtb_a_ft = 1.0F;
  } else {
    rtb_a_ft = rtb_Subtract3_cx;
  }

  /* End of Signum: '<S130>/Sign' */

  /* Sum: '<S130>/Add2' incorporates:
   *  Abs: '<S130>/Abs'
   *  Gain: '<S130>/Gain'
   *  Gain: '<S130>/Gain1'
   *  Product: '<S130>/Multiply2'
   *  Product: '<S130>/Multiply3'
   *  Sqrt: '<S130>/Sqrt'
   *  Sum: '<S130>/Add1'
   *  Sum: '<S130>/Subtract'
   */
  rtb_a_ft = (sqrtf((8.0F * fabsf(rtb_Subtract3_cx) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_ft + rtb_Add3_a;

  /* Sum: '<S130>/Add4' */
  rtb_Add4_pq = (rtb_Subtract3_cx - rtb_a_ft) + rtb_Add3_a;

  /* Sum: '<S130>/Add3' */
  rtb_Add3_a = rtb_Subtract3_cx + localC->d;

  /* Sum: '<S130>/Subtract1' */
  rtb_Subtract3_cx -= localC->d;

  /* Signum: '<S130>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S130>/Sign1' */

  /* Signum: '<S130>/Sign2' */
  if (rtb_Subtract3_cx < 0.0F) {
    rtb_Subtract3_cx = -1.0F;
  } else {
    if (rtb_Subtract3_cx > 0.0F) {
      rtb_Subtract3_cx = 1.0F;
    }
  }

  /* End of Signum: '<S130>/Sign2' */

  /* Sum: '<S130>/Add5' incorporates:
   *  Gain: '<S130>/Gain2'
   *  Product: '<S130>/Multiply4'
   *  Sum: '<S130>/Subtract2'
   */
  rtb_a_ft += (rtb_Add3_a - rtb_Subtract3_cx) * 0.5F * rtb_Add4_pq;

  /* SignalConversion: '<S125>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S129>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S129>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S129>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S130>/Add6' */
  rtb_Add3_a = rtb_a_ft + localC->d;

  /* Sum: '<S130>/Subtract3' */
  rtb_Subtract3_cx = rtb_a_ft - localC->d;

  /* Signum: '<S130>/Sign5' */
  if (rtb_a_ft < 0.0F) {
    rtb_Add4_pq = -1.0F;
  } else if (rtb_a_ft > 0.0F) {
    rtb_Add4_pq = 1.0F;
  } else {
    rtb_Add4_pq = rtb_a_ft;
  }

  /* End of Signum: '<S130>/Sign5' */

  /* Signum: '<S130>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S130>/Sign3' */

  /* Signum: '<S130>/Sign4' */
  if (rtb_Subtract3_cx < 0.0F) {
    rtb_Subtract3_cx = -1.0F;
  } else {
    if (rtb_Subtract3_cx > 0.0F) {
      rtb_Subtract3_cx = 1.0F;
    }
  }

  /* End of Signum: '<S130>/Sign4' */

  /* Signum: '<S130>/Sign6' */
  if (rtb_a_ft < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_ft > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_ft;
  }

  /* End of Signum: '<S130>/Sign6' */

  /* Update for DiscreteIntegrator: '<S129>/Integrator' incorporates:
   *  Constant: '<S130>/const'
   *  Gain: '<S130>/Gain3'
   *  Product: '<S130>/Divide'
   *  Product: '<S130>/Multiply5'
   *  Product: '<S130>/Multiply6'
   *  Sum: '<S130>/Subtract4'
   *  Sum: '<S130>/Subtract5'
   *  Sum: '<S130>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_ft / localC->d - rtb_Add4_pq) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_cx) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S123>/Motion Status'
 *    '<S148>/Motion Status'
 *    '<S340>/Motion Status'
 *    '<S374>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S123>/Motion Status'
 *    '<S148>/Motion Status'
 *    '<S340>/Motion Status'
 *    '<S374>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S123>/Motion Status'
 *    '<S148>/Motion Status'
 *    '<S340>/Motion Status'
 *    '<S374>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S123>/Motion Status' */
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

  /* End of Chart: '<S123>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S162>/Hold Control'
 *    '<S53>/Hold Control'
 */
void FMS_HoldControl_l_Init(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S169>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S169>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System reset for action system:
 *    '<S162>/Hold Control'
 *    '<S53>/Hold Control'
 */
void FMS_HoldControl_g_Reset(const ConstB_HoldControl_FMS_i_T *localC,
  DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S169>/start_vel' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S169>/start_wp' */
  localDW->icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 1U;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * Output and update for action system:
 *    '<S162>/Hold Control'
 *    '<S53>/Hold Control'
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

  /* Sqrt: '<S176>/Sqrt' incorporates:
   *  Math: '<S176>/Square'
   *  Sum: '<S176>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_ex = sqrtf(((rtu_FMS_In[0] * rtu_FMS_In[0] +
    rtu_FMS_In[1] * rtu_FMS_In[1]) + rtu_FMS_In[2] * rtu_FMS_In[2]) +
    rtu_FMS_In[3] * rtu_FMS_In[3]);

  /* Product: '<S172>/Divide' */
  rtb_Square_kg_idx_0 = rtu_FMS_In[0] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_1 = rtu_FMS_In[1] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_Square_kg_idx_2 = rtu_FMS_In[2] / rtb_DiscreteTimeIntegrator1_ex;
  rtb_DiscreteTimeIntegrator1_ex = rtu_FMS_In[3] /
    rtb_DiscreteTimeIntegrator1_ex;

  /* Math: '<S173>/Square' incorporates:
   *  Math: '<S174>/Square'
   *  Math: '<S175>/Square'
   */
  rtb_Sign_hw = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_0;

  /* Math: '<S173>/Square2' incorporates:
   *  Math: '<S174>/Square2'
   *  Math: '<S175>/Square2'
   */
  rtb_Switch_fz_idx_1 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2;

  /* Math: '<S173>/Square1' incorporates:
   *  Math: '<S174>/Square1'
   *  Math: '<S175>/Square1'
   */
  D = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1;

  /* Math: '<S173>/Square3' incorporates:
   *  Math: '<S174>/Square3'
   *  Math: '<S175>/Square3'
   */
  absxk = rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex;

  /* Sum: '<S173>/Subtract' incorporates:
   *  Math: '<S173>/Square'
   *  Math: '<S173>/Square1'
   *  Math: '<S173>/Square2'
   *  Math: '<S173>/Square3'
   *  Sum: '<S173>/Add'
   *  Sum: '<S173>/Add1'
   */
  rtb_VectorConcatenate_l[0] = (rtb_Sign_hw + D) - (rtb_Switch_fz_idx_1 + absxk);

  /* Product: '<S173>/Multiply' incorporates:
   *  Product: '<S174>/Multiply'
   */
  b_t = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_2;

  /* Product: '<S173>/Multiply1' incorporates:
   *  Product: '<S174>/Multiply1'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_DiscreteTimeIntegrator1_ex;

  /* Gain: '<S173>/Gain' incorporates:
   *  Product: '<S173>/Multiply'
   *  Product: '<S173>/Multiply1'
   *  Sum: '<S173>/Subtract1'
   */
  rtb_VectorConcatenate_l[1] = (b_t - d1) * 2.0F;

  /* Product: '<S173>/Multiply2' incorporates:
   *  Product: '<S175>/Multiply'
   */
  rtb_VectorConcatenate_fy_tmp = rtb_Square_kg_idx_1 *
    rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S173>/Multiply3' incorporates:
   *  Product: '<S175>/Multiply1'
   */
  rtb_VectorConcatenate_fy_tmp_0 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_2;

  /* Gain: '<S173>/Gain1' incorporates:
   *  Product: '<S173>/Multiply2'
   *  Product: '<S173>/Multiply3'
   *  Sum: '<S173>/Add2'
   */
  rtb_VectorConcatenate_l[2] = (rtb_VectorConcatenate_fy_tmp +
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S174>/Gain' incorporates:
   *  Sum: '<S174>/Add3'
   */
  rtb_VectorConcatenate_l[3] = (b_t + d1) * 2.0F;

  /* Sum: '<S174>/Subtract' incorporates:
   *  Sum: '<S174>/Add'
   *  Sum: '<S174>/Add1'
   */
  rtb_VectorConcatenate_l[4] = (rtb_Sign_hw + rtb_Switch_fz_idx_1) - (D + absxk);

  /* Product: '<S174>/Multiply2' incorporates:
   *  Product: '<S175>/Multiply2'
   */
  b_t = rtb_Square_kg_idx_2 * rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S174>/Multiply3' incorporates:
   *  Product: '<S175>/Multiply3'
   */
  d1 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_1;

  /* Gain: '<S174>/Gain1' incorporates:
   *  Product: '<S174>/Multiply2'
   *  Product: '<S174>/Multiply3'
   *  Sum: '<S174>/Subtract1'
   */
  rtb_VectorConcatenate_l[5] = (b_t - d1) * 2.0F;

  /* Gain: '<S175>/Gain' incorporates:
   *  Sum: '<S175>/Subtract2'
   */
  rtb_VectorConcatenate_l[6] = (rtb_VectorConcatenate_fy_tmp -
    rtb_VectorConcatenate_fy_tmp_0) * 2.0F;

  /* Gain: '<S175>/Gain1' incorporates:
   *  Sum: '<S175>/Add2'
   */
  rtb_VectorConcatenate_l[7] = (b_t + d1) * 2.0F;

  /* Sum: '<S175>/Subtract' incorporates:
   *  Sum: '<S175>/Add'
   *  Sum: '<S175>/Add1'
   */
  rtb_VectorConcatenate_l[8] = (rtb_Sign_hw + absxk) - (D + rtb_Switch_fz_idx_1);

  /* Product: '<S166>/Multiply' incorporates:
   *  SignalConversion: '<S166>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_ppg[i] = rtb_VectorConcatenate_l[i + 6] * rtu_FMS_In_g +
      (rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h + rtb_VectorConcatenate_l[i]
       * rtu_FMS_In_c);
  }

  /* End of Product: '<S166>/Multiply' */

  /* Trigonometry: '<S195>/Trigonometric Function1' incorporates:
   *  Gain: '<S194>/Gain'
   *  Trigonometry: '<S195>/Trigonometric Function3'
   */
  rtb_Sign_hw = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[0] = rtb_Sign_hw;

  /* Trigonometry: '<S195>/Trigonometric Function' incorporates:
   *  Gain: '<S194>/Gain'
   *  Trigonometry: '<S195>/Trigonometric Function2'
   */
  rtb_Switch_fz_idx_1 = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[1] = rtb_Switch_fz_idx_1;

  /* SignalConversion: '<S195>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S195>/Constant3'
   */
  rtb_VectorConcatenate_l[2] = 0.0F;

  /* Gain: '<S195>/Gain' */
  rtb_VectorConcatenate_l[3] = -rtb_Switch_fz_idx_1;

  /* Trigonometry: '<S195>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_Sign_hw;

  /* SignalConversion: '<S195>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S195>/Constant4'
   */
  rtb_VectorConcatenate_l[5] = 0.0F;

  /* SignalConversion: '<S195>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_l[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_l[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_l[8] = localC->VectorConcatenate3[2];

  /* Delay: '<S169>/start_vel' incorporates:
   *  SignalConversion: '<S182>/TmpSignal ConversionAtSquareInport1'
   */
  if (localDW->icLoad != 0) {
    localDW->start_vel_DSTATE[0] = rtu_FMS_In_c;
    localDW->start_vel_DSTATE[1] = rtu_FMS_In_h;
  }

  /* Sum: '<S190>/Sum of Elements' incorporates:
   *  Delay: '<S169>/start_vel'
   *  Math: '<S190>/Math Function'
   */
  rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[0] * localDW->
    start_vel_DSTATE[0] + localDW->start_vel_DSTATE[1] *
    localDW->start_vel_DSTATE[1];

  /* Math: '<S190>/Math Function1' incorporates:
   *  Sum: '<S190>/Sum of Elements'
   *
   * About '<S190>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_fz_idx_1 < 0.0F) {
    rtb_Sign_hw = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
  } else {
    rtb_Sign_hw = sqrtf(rtb_Switch_fz_idx_1);
  }

  /* End of Math: '<S190>/Math Function1' */

  /* Switch: '<S190>/Switch' incorporates:
   *  Constant: '<S190>/Constant'
   *  Delay: '<S169>/start_vel'
   *  Product: '<S190>/Product'
   */
  if (rtb_Sign_hw > 0.0F) {
    rtb_Square_kg_idx_2 = localDW->start_vel_DSTATE[0];
    rtb_Switch_fz_idx_1 = localDW->start_vel_DSTATE[1];
  } else {
    rtb_Square_kg_idx_2 = 0.0F;
    rtb_Switch_fz_idx_1 = 0.0F;
    rtb_Sign_hw = 1.0F;
  }

  /* End of Switch: '<S190>/Switch' */

  /* Delay: '<S169>/start_wp' incorporates:
   *  SignalConversion: '<S169>/TmpSignal ConversionAtstart_wpInport2'
   */
  if (localDW->icLoad_e != 0) {
    localDW->start_wp_DSTATE[0] = rtu_FMS_In_l;
    localDW->start_wp_DSTATE[1] = rtu_FMS_In_m;
  }

  /* MATLAB Function: '<S167>/SearchL1RefWP' incorporates:
   *  Delay: '<S169>/start_wp'
   *  SignalConversion: '<S179>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_Square_kg_idx_0 = localDW->start_wp_DSTATE[0] - rtu_FMS_In_l;
  rtb_Square_kg_idx_1 = localDW->start_wp_DSTATE[1] - rtu_FMS_In_m;

  /* Product: '<S190>/Divide' */
  rtb_Square_kg_idx_2 /= rtb_Sign_hw;

  /* MATLAB Function: '<S167>/SearchL1RefWP' */
  D = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_0;

  /* Product: '<S190>/Divide' */
  rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_2;
  rtb_Square_kg_idx_2 = rtb_Switch_fz_idx_1 / rtb_Sign_hw;

  /* MATLAB Function: '<S167>/SearchL1RefWP' incorporates:
   *  Constant: '<S164>/L1'
   *  Delay: '<S169>/start_wp'
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

  /* MATLAB Function: '<S167>/OutRegionRefWP' incorporates:
   *  Delay: '<S169>/start_wp'
   *  SignalConversion: '<S169>/TmpSignal ConversionAtstart_wpInport2'
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

  /* Product: '<S193>/Multiply' incorporates:
   *  SignalConversion: '<S193>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_fy[i] = rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h
      + rtb_VectorConcatenate_l[i] * rtu_FMS_In_c;
  }

  /* End of Product: '<S193>/Multiply' */

  /* DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */
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

  /* DiscreteIntegrator: '<S199>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S191>/Constant'
   *  Sum: '<S191>/Sum'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  if (localDW->DiscreteTimeIntegrator1_PrevRes != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_fy[1];
  }

  /* Signum: '<S166>/Sign' */
  if (rtb_Multiply_ppg[0] < 0.0F) {
    rtb_Switch_fz_idx_1 = -1.0F;
  } else if (rtb_Multiply_ppg[0] > 0.0F) {
    rtb_Switch_fz_idx_1 = 1.0F;
  } else {
    rtb_Switch_fz_idx_1 = rtb_Multiply_ppg[0];
  }

  /* End of Signum: '<S166>/Sign' */

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S164>/L1'
   *  Constant: '<S180>/Constant'
   *  Constant: '<S191>/Constant'
   *  Constant: '<S198>/kp'
   *  DiscreteIntegrator: '<S197>/Discrete-Time Integrator'
   *  Gain: '<S180>/Gain'
   *  Math: '<S180>/Square'
   *  Math: '<S183>/Square'
   *  Math: '<S185>/Math Function'
   *  MinMax: '<S180>/Max'
   *  MinMax: '<S180>/Min'
   *  Product: '<S180>/Divide'
   *  Product: '<S180>/Multiply1'
   *  Product: '<S198>/Multiply'
   *  Sqrt: '<S183>/Sqrt'
   *  Sum: '<S168>/Subtract'
   *  Sum: '<S183>/Sum of Elements'
   *  Sum: '<S191>/Sum'
   *  Sum: '<S192>/Add'
   */
  if (rtb_Switch_fz_idx_1 > 0.0F) {
    /* Sum: '<S184>/Sum of Elements' incorporates:
     *  Math: '<S184>/Math Function'
     *  SignalConversion: '<S182>/TmpSignal ConversionAtSquareInport1'
     *  Sum: '<S182>/Sum of Elements'
     */
    rtb_Switch_fz_idx_1 = rtu_FMS_In_c * rtu_FMS_In_c + rtu_FMS_In_h *
      rtu_FMS_In_h;

    /* Math: '<S184>/Math Function1' incorporates:
     *  Sum: '<S184>/Sum of Elements'
     *
     * About '<S184>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Switch_fz_idx_1 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Switch_fz_idx_1));
    } else {
      d1 = sqrtf(rtb_Switch_fz_idx_1);
    }

    /* End of Math: '<S184>/Math Function1' */

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/Constant'
     *  Product: '<S184>/Product'
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

    /* End of Switch: '<S184>/Switch' */

    /* Product: '<S184>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* RelationalOperator: '<S177>/Compare' incorporates:
     *  Constant: '<S177>/Constant'
     *  MATLAB Function: '<S167>/SearchL1RefWP'
     */
    rtb_Compare_dd1 = (rtb_Sign_hw > 0.0F);

    /* Switch: '<S167>/Switch' incorporates:
     *  Delay: '<S169>/start_wp'
     *  MATLAB Function: '<S167>/OutRegionRefWP'
     */
    if (!rtb_Compare_dd1) {
      rtb_Square_kg_idx_0 = b_t * rtb_DiscreteTimeIntegrator1_ex +
        localDW->start_wp_DSTATE[0];
      rtb_Square_kg_idx_1 = b_t * rtb_Square_kg_idx_2 + localDW->
        start_wp_DSTATE[1];
    }

    /* End of Switch: '<S167>/Switch' */

    /* Sum: '<S168>/Subtract' incorporates:
     *  SignalConversion: '<S169>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_0 - rtu_FMS_In_l;
    rtb_Square_kg_idx_0 = rtb_DiscreteTimeIntegrator1_ex;
    rtb_Sign_hw = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex;

    /* Sum: '<S168>/Subtract' incorporates:
     *  Math: '<S185>/Math Function'
     *  SignalConversion: '<S169>/TmpSignal ConversionAtstart_wpInport2'
     */
    rtb_DiscreteTimeIntegrator1_ex = rtb_Square_kg_idx_1 - rtu_FMS_In_m;

    /* Sum: '<S185>/Sum of Elements' incorporates:
     *  Math: '<S185>/Math Function'
     */
    rtb_Square_kg_idx_2 = rtb_DiscreteTimeIntegrator1_ex *
      rtb_DiscreteTimeIntegrator1_ex + rtb_Sign_hw;

    /* Math: '<S185>/Math Function1' incorporates:
     *  Sum: '<S185>/Sum of Elements'
     *
     * About '<S185>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S185>/Math Function1' */

    /* Switch: '<S185>/Switch' incorporates:
     *  Constant: '<S185>/Constant'
     *  Product: '<S185>/Product'
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

    /* End of Switch: '<S185>/Switch' */

    /* Product: '<S185>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_0 *= rtb_Square_kg_idx_0;

    /* Product: '<S185>/Divide' incorporates:
     *  Math: '<S183>/Square'
     */
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S187>/Sum of Elements' incorporates:
     *  Math: '<S187>/Math Function'
     *  SignalConversion: '<S187>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = absxk * absxk + D * D;

    /* Math: '<S187>/Math Function1' incorporates:
     *  Sum: '<S187>/Sum of Elements'
     *
     * About '<S187>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S187>/Math Function1' */

    /* Switch: '<S187>/Switch' incorporates:
     *  Constant: '<S187>/Constant'
     *  Product: '<S187>/Product'
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

    /* End of Switch: '<S187>/Switch' */

    /* Product: '<S187>/Divide' */
    D = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    absxk = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S188>/Sum of Elements' incorporates:
     *  Math: '<S188>/Math Function'
     *  SignalConversion: '<S188>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_Square_kg_idx_2 = rtb_Square_kg_idx_1 * rtb_Square_kg_idx_1 +
      rtb_Sign_hw * rtb_Sign_hw;

    /* Math: '<S188>/Math Function1' incorporates:
     *  Sum: '<S188>/Sum of Elements'
     *
     * About '<S188>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      d1 = -sqrtf(fabsf(rtb_Square_kg_idx_2));
    } else {
      d1 = sqrtf(rtb_Square_kg_idx_2);
    }

    /* End of Math: '<S188>/Math Function1' */

    /* Switch: '<S188>/Switch' incorporates:
     *  Constant: '<S188>/Constant'
     *  Product: '<S188>/Product'
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

    /* End of Switch: '<S188>/Switch' */

    /* Product: '<S188>/Divide' */
    rtb_Sign_hw = rtb_Multiply_ppg[0] / rtb_Multiply_ppg[2];
    rtb_Square_kg_idx_1 = rtb_Multiply_ppg[1] / rtb_Multiply_ppg[2];

    /* Sum: '<S186>/Subtract' incorporates:
     *  Product: '<S186>/Multiply'
     *  Product: '<S186>/Multiply1'
     */
    rtb_Square_kg_idx_2 = rtb_Sign_hw * absxk - rtb_Square_kg_idx_1 * D;

    /* Signum: '<S181>/Sign1' */
    if (rtb_Square_kg_idx_2 < 0.0F) {
      rtb_Square_kg_idx_2 = -1.0F;
    } else {
      if (rtb_Square_kg_idx_2 > 0.0F) {
        rtb_Square_kg_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S181>/Sign1' */

    /* Switch: '<S181>/Switch2' incorporates:
     *  Constant: '<S181>/Constant4'
     */
    if (rtb_Square_kg_idx_2 == 0.0F) {
      rtb_Square_kg_idx_2 = 1.0F;
    }

    /* End of Switch: '<S181>/Switch2' */

    /* DotProduct: '<S181>/Dot Product' */
    rtb_Square_kg_idx_1 = D * rtb_Sign_hw + absxk * rtb_Square_kg_idx_1;

    /* Trigonometry: '<S181>/Acos' incorporates:
     *  DotProduct: '<S181>/Dot Product'
     */
    if (rtb_Square_kg_idx_1 > 1.0F) {
      rtb_Square_kg_idx_1 = 1.0F;
    } else {
      if (rtb_Square_kg_idx_1 < -1.0F) {
        rtb_Square_kg_idx_1 = -1.0F;
      }
    }

    /* Product: '<S181>/Multiply' incorporates:
     *  Trigonometry: '<S181>/Acos'
     */
    rtb_Square_kg_idx_2 *= acosf(rtb_Square_kg_idx_1);

    /* Saturate: '<S180>/Saturation' */
    if (rtb_Square_kg_idx_2 > 1.57079637F) {
      rtb_Square_kg_idx_2 = 1.57079637F;
    } else {
      if (rtb_Square_kg_idx_2 < -1.57079637F) {
        rtb_Square_kg_idx_2 = -1.57079637F;
      }
    }

    /* End of Saturate: '<S180>/Saturation' */

    /* Trigonometry: '<S180>/Sin' */
    rtb_Square_kg_idx_1 = arm_sin_f32(rtb_Square_kg_idx_2);

    /* Sqrt: '<S182>/Sqrt' */
    rtb_Square_kg_idx_2 = sqrtf(rtb_Switch_fz_idx_1);
    *rty_ay_cmd_mPs2 = rtb_Square_kg_idx_2 * rtb_Square_kg_idx_2 * 2.0F *
      rtb_Square_kg_idx_1 / fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf
      (rtb_DiscreteTimeIntegrator1_ex * rtb_DiscreteTimeIntegrator1_ex +
       rtb_Square_kg_idx_0), 0.5F));
  } else {
    *rty_ay_cmd_mPs2 = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
      localDW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Switch: '<S164>/Switch' */

  /* Update for Delay: '<S169>/start_vel' */
  localDW->icLoad = 0U;

  /* Update for Delay: '<S169>/start_wp' */
  localDW->icLoad_e = 0U;

  /* Update for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S191>/Constant'
   *  Constant: '<S197>/ki'
   *  Product: '<S197>/Multiply'
   *  Sum: '<S191>/Sum'
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

  /* End of Update for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S199>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S191>/Constant'
   *  Gain: '<S199>/Gain'
   *  Sum: '<S191>/Sum'
   *  Sum: '<S199>/Sum5'
   */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE += ((0.0F - rtb_VectorConcatenate_fy[1])
    - localDW->DiscreteTimeIntegrator1_DSTATE) * 62.831852F * 0.004F;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;
}

/*
 * System initialize for atomic system:
 *    '<S163>/Motion State'
 *    '<S54>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c26_FMS = 0U;
  localDW->is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
}

/*
 * System reset for atomic system:
 *    '<S163>/Motion State'
 *    '<S54>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c26_FMS = 0U;
  localDW->is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
}

/*
 * Output and update for atomic system:
 *    '<S163>/Motion State'
 *    '<S54>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S163>/Motion State' */
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

  /* End of Chart: '<S163>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S717>/Hold Control'
 *    '<S634>/Hold Control'
 *    '<S477>/Hold Control'
 *    '<S339>/Hold Control'
 *    '<S373>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S720>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S717>/Hold Control'
 *    '<S634>/Hold Control'
 *    '<S477>/Hold Control'
 *    '<S339>/Hold Control'
 *    '<S373>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S720>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S717>/Hold Control'
 *    '<S634>/Hold Control'
 *    '<S477>/Hold Control'
 *    '<S339>/Hold Control'
 *    '<S373>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S720>/Delay' incorporates:
   *  Gain: '<S722>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S720>/Gain2' incorporates:
   *  Delay: '<S720>/Delay'
   *  Gain: '<S722>/Gain'
   *  Sum: '<S720>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S720>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S717>/Brake Control'
 *    '<S634>/Brake Control'
 *    '<S645>/Brake Control'
 *    '<S477>/Brake Control'
 *    '<S423>/Brake Control'
 *    '<S339>/Brake Control'
 *    '<S357>/Brake Control'
 *    '<S373>/Brake Control'
 *    '<S385>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S719>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S719>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S717>/Move Control'
 *    '<S634>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S724>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S724>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S717>/Move Control'
 *    '<S634>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S724>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S724>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S717>/Move Control'
 *    '<S634>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_ho;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S725>/Multiply1' incorporates:
   *  Constant: '<S725>/const1'
   *  DiscreteIntegrator: '<S724>/Integrator'
   */
  rtb_Add3_ho = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S723>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S723>/Dead Zone' */

  /* Sum: '<S725>/Add' incorporates:
   *  DiscreteIntegrator: '<S724>/Integrator1'
   *  Gain: '<S721>/Gain1'
   *  Gain: '<S723>/Gain'
   *  Sum: '<S724>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_ho;

  /* Signum: '<S725>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S725>/Sign' */

  /* Sum: '<S725>/Add2' incorporates:
   *  Abs: '<S725>/Abs'
   *  Gain: '<S725>/Gain'
   *  Gain: '<S725>/Gain1'
   *  Product: '<S725>/Multiply2'
   *  Product: '<S725>/Multiply3'
   *  Sqrt: '<S725>/Sqrt'
   *  Sum: '<S725>/Add1'
   *  Sum: '<S725>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_ho;

  /* Sum: '<S725>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_ho;

  /* Sum: '<S725>/Add3' */
  rtb_Add3_ho = rtb_Subtract3_d + localC->d;

  /* Sum: '<S725>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S725>/Sign1' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S725>/Sign1' */

  /* Signum: '<S725>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S725>/Sign2' */

  /* Sum: '<S725>/Add5' incorporates:
   *  Gain: '<S725>/Gain2'
   *  Product: '<S725>/Multiply4'
   *  Sum: '<S725>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_ho - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S724>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S724>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S724>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S724>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S725>/Add6' */
  rtb_Add3_ho = rtb_a_o + localC->d;

  /* Sum: '<S725>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S725>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S725>/Sign5' */

  /* Signum: '<S725>/Sign3' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S725>/Sign3' */

  /* Signum: '<S725>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S725>/Sign4' */

  /* Signum: '<S725>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S725>/Sign6' */

  /* Update for DiscreteIntegrator: '<S724>/Integrator' incorporates:
   *  Constant: '<S725>/const'
   *  Gain: '<S725>/Gain3'
   *  Product: '<S725>/Divide'
   *  Product: '<S725>/Multiply5'
   *  Product: '<S725>/Multiply6'
   *  Sum: '<S725>/Subtract4'
   *  Sum: '<S725>/Subtract5'
   *  Sum: '<S725>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_ho - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S718>/Motion Status'
 *    '<S635>/Motion Status'
 *    '<S478>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S718>/Motion Status'
 *    '<S635>/Motion Status'
 *    '<S478>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S718>/Motion Status'
 *    '<S635>/Motion Status'
 *    '<S478>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S718>/Motion Status' */
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

  /* End of Chart: '<S718>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S727>/Hold Control'
 *    '<S666>/Hold Control'
 *    '<S487>/Hold Control'
 */
void FMS_HoldControl_l0_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S730>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S727>/Hold Control'
 *    '<S666>/Hold Control'
 *    '<S487>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S730>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S727>/Hold Control'
 *    '<S666>/Hold Control'
 *    '<S487>/Hold Control'
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

  /* Delay: '<S730>/Delay' incorporates:
   *  SignalConversion: '<S730>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S734>/Trigonometric Function1' incorporates:
   *  Gain: '<S733>/Gain'
   *  Trigonometry: '<S734>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S734>/Trigonometric Function' incorporates:
   *  Gain: '<S733>/Gain'
   *  Trigonometry: '<S734>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_hl[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S734>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S734>/Constant3'
   */
  rtb_VectorConcatenate_hl[2] = 0.0F;

  /* Gain: '<S734>/Gain' */
  rtb_VectorConcatenate_hl[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S734>/Trigonometric Function3' */
  rtb_VectorConcatenate_hl[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S734>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S734>/Constant4'
   */
  rtb_VectorConcatenate_hl[5] = 0.0F;

  /* SignalConversion: '<S734>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_hl[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_hl[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_hl[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S730>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S730>/Delay'
   *  SignalConversion: '<S730>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S730>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S730>/Multiply' incorporates:
   *  SignalConversion: '<S730>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_hl[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_hl[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S730>/Multiply' */

  /* Gain: '<S730>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S730>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S727>/Brake Control'
 *    '<S666>/Brake Control'
 *    '<S487>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S729>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S727>/Move Control'
 *    '<S666>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S727>/Move Control'
 *    '<S666>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S737>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S727>/Move Control'
 *    '<S666>/Move Control'
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

  /* DiscreteIntegrator: '<S737>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S738>/Multiply1' incorporates:
   *  Constant: '<S738>/const1'
   *  DiscreteIntegrator: '<S737>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S737>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S738>/Multiply1' incorporates:
   *  Constant: '<S738>/const1'
   *  DiscreteIntegrator: '<S737>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S735>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S735>/Dead Zone' */

  /* Sum: '<S738>/Add' incorporates:
   *  DiscreteIntegrator: '<S737>/Integrator1'
   *  Gain: '<S731>/Gain6'
   *  Gain: '<S735>/Gain'
   *  Sum: '<S737>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S736>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S736>/Dead Zone' */

  /* Sum: '<S738>/Add' incorporates:
   *  DiscreteIntegrator: '<S737>/Integrator1'
   *  Gain: '<S731>/Gain6'
   *  Gain: '<S736>/Gain'
   *  Sum: '<S737>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S738>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S738>/Add2' incorporates:
   *  Abs: '<S738>/Abs'
   *  Gain: '<S738>/Gain'
   *  Gain: '<S738>/Gain1'
   *  Product: '<S738>/Multiply2'
   *  Product: '<S738>/Multiply3'
   *  Signum: '<S738>/Sign'
   *  Sqrt: '<S738>/Sqrt'
   *  Sum: '<S738>/Add1'
   *  Sum: '<S738>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S738>/Add3' incorporates:
   *  Signum: '<S738>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S738>/Subtract1' incorporates:
   *  Signum: '<S738>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S738>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S738>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S738>/Add5' incorporates:
   *  Gain: '<S738>/Gain2'
   *  Product: '<S738>/Multiply4'
   *  Signum: '<S738>/Sign'
   *  Sum: '<S738>/Add2'
   *  Sum: '<S738>/Add4'
   *  Sum: '<S738>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S737>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S737>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S738>/Sign3' incorporates:
   *  Sum: '<S738>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S738>/Sign4' incorporates:
   *  Sum: '<S738>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S738>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S738>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S738>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S738>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S737>/Integrator' incorporates:
   *  Constant: '<S738>/const'
   *  Gain: '<S738>/Gain3'
   *  Product: '<S738>/Divide'
   *  Product: '<S738>/Multiply5'
   *  Product: '<S738>/Multiply6'
   *  Sum: '<S738>/Subtract4'
   *  Sum: '<S738>/Subtract5'
   *  Sum: '<S738>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S737>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S738>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S738>/Add2' incorporates:
   *  Abs: '<S738>/Abs'
   *  Gain: '<S738>/Gain'
   *  Gain: '<S738>/Gain1'
   *  Product: '<S738>/Multiply2'
   *  Product: '<S738>/Multiply3'
   *  Signum: '<S738>/Sign'
   *  Sqrt: '<S738>/Sqrt'
   *  Sum: '<S738>/Add1'
   *  Sum: '<S738>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S738>/Add3' incorporates:
   *  Signum: '<S738>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S738>/Subtract1' incorporates:
   *  Signum: '<S738>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S738>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S738>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S738>/Add5' incorporates:
   *  Gain: '<S738>/Gain2'
   *  Product: '<S738>/Multiply4'
   *  Signum: '<S738>/Sign'
   *  Sum: '<S738>/Add2'
   *  Sum: '<S738>/Add4'
   *  Sum: '<S738>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S737>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S737>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S738>/Sign3' incorporates:
   *  Sum: '<S738>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S738>/Sign4' incorporates:
   *  Sum: '<S738>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S738>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S738>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S738>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S738>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S737>/Integrator' incorporates:
   *  Constant: '<S738>/const'
   *  Gain: '<S738>/Gain3'
   *  Product: '<S738>/Divide'
   *  Product: '<S738>/Multiply5'
   *  Product: '<S738>/Multiply6'
   *  Sum: '<S738>/Subtract4'
   *  Sum: '<S738>/Subtract5'
   *  Sum: '<S738>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S737>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S728>/Motion State'
 *    '<S667>/Motion State'
 *    '<S488>/Motion State'
 */
void FMS_MotionState_c_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S728>/Motion State'
 *    '<S667>/Motion State'
 *    '<S488>/Motion State'
 */
void FMS_MotionState_f_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S728>/Motion State'
 *    '<S667>/Motion State'
 *    '<S488>/Motion State'
 */
void FMS_MotionState_p(real32_T rtu_motion_req, real32_T rtu_speed, MotionState *
  rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S728>/Motion State' */
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

  /* End of Chart: '<S728>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S710>/OutRegionRegWP'
 *    '<S464>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S743>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S645>/Hold Control'
 *    '<S423>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S385>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S649>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S645>/Hold Control'
 *    '<S423>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S385>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S649>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S645>/Hold Control'
 *    '<S423>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S385>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S649>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S649>/Sum' incorporates:
   *  Delay: '<S649>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S652>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S652>/Switch' incorporates:
   *  Constant: '<S652>/Constant'
   *  Constant: '<S653>/Constant'
   *  Product: '<S652>/Multiply'
   *  RelationalOperator: '<S653>/Compare'
   *  Sum: '<S652>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S652>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S652>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S652>/Switch' */

  /* Gain: '<S649>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S649>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S645>/Move Control'
 *    '<S423>/Move Control'
 *    '<S357>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S655>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S655>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S645>/Move Control'
 *    '<S423>/Move Control'
 *    '<S357>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S655>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S655>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S645>/Move Control'
 *    '<S423>/Move Control'
 *    '<S357>/Move Control'
 *    '<S385>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_px;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S656>/Multiply1' incorporates:
   *  Constant: '<S656>/const1'
   *  DiscreteIntegrator: '<S655>/Integrator'
   */
  rtb_Add3_px = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S654>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S654>/Dead Zone' */

  /* Sum: '<S656>/Add' incorporates:
   *  DiscreteIntegrator: '<S655>/Integrator1'
   *  Gain: '<S650>/Gain1'
   *  Gain: '<S654>/Gain'
   *  Sum: '<S655>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_px;

  /* Signum: '<S656>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
  }

  /* End of Signum: '<S656>/Sign' */

  /* Sum: '<S656>/Add2' incorporates:
   *  Abs: '<S656>/Abs'
   *  Gain: '<S656>/Gain'
   *  Gain: '<S656>/Gain1'
   *  Product: '<S656>/Multiply2'
   *  Product: '<S656>/Multiply3'
   *  Sqrt: '<S656>/Sqrt'
   *  Sum: '<S656>/Add1'
   *  Sum: '<S656>/Subtract'
   */
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_px;

  /* Sum: '<S656>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_px;

  /* Sum: '<S656>/Add3' */
  rtb_Add3_px = rtb_Subtract3_e + localC->d;

  /* Sum: '<S656>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S656>/Sign1' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S656>/Sign1' */

  /* Signum: '<S656>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S656>/Sign2' */

  /* Sum: '<S656>/Add5' incorporates:
   *  Gain: '<S656>/Gain2'
   *  Product: '<S656>/Multiply4'
   *  Sum: '<S656>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_px - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S655>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S655>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S655>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S655>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S656>/Add6' */
  rtb_Add3_px = rtb_a_h + localC->d;

  /* Sum: '<S656>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S656>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S656>/Sign5' */

  /* Signum: '<S656>/Sign3' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S656>/Sign3' */

  /* Signum: '<S656>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S656>/Sign4' */

  /* Signum: '<S656>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S656>/Sign6' */

  /* Update for DiscreteIntegrator: '<S655>/Integrator' incorporates:
   *  Constant: '<S656>/const'
   *  Gain: '<S656>/Gain3'
   *  Product: '<S656>/Divide'
   *  Product: '<S656>/Multiply5'
   *  Product: '<S656>/Multiply6'
   *  Sum: '<S656>/Subtract4'
   *  Sum: '<S656>/Subtract5'
   *  Sum: '<S656>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_px - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S424>/Motion State'
 *    '<S358>/Motion State'
 *    '<S386>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S424>/Motion State'
 *    '<S358>/Motion State'
 *    '<S386>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S424>/Motion State'
 *    '<S358>/Motion State'
 *    '<S386>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S424>/Motion State' */
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

  /* End of Chart: '<S424>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S339>/Move Control'
 *    '<S373>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S348>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S348>/Dead Zone' */

  /* Gain: '<S343>/Gain1' incorporates:
   *  Gain: '<S348>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S343>/Switch' incorporates:
   *  Constant: '<S345>/Land_Speed'
   *  Constant: '<S346>/Constant'
   *  Constant: '<S347>/Constant'
   *  Gain: '<S345>/Gain'
   *  Logic: '<S343>/Logical Operator'
   *  MinMax: '<S345>/Min'
   *  RelationalOperator: '<S346>/Compare'
   *  RelationalOperator: '<S347>/Compare'
   *  S-Function (sfix_bitop): '<S343>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S343>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S774>/Switch' incorporates:
   *  Constant: '<S774>/FW_ACCEPT_R'
   *  Constant: '<S774>/MC_ACCEPT_R'
   *  Constant: '<S781>/Constant'
   *  RelationalOperator: '<S781>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S774>/Switch' */
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

  /* Math: '<S792>/Rem' incorporates:
   *  Constant: '<S792>/Constant1'
   *  Sum: '<S776>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S792>/Switch' incorporates:
   *  Abs: '<S792>/Abs'
   *  Constant: '<S792>/Constant'
   *  Constant: '<S793>/Constant'
   *  Product: '<S792>/Multiply'
   *  RelationalOperator: '<S793>/Compare'
   *  Sum: '<S792>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S792>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S792>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S792>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S779>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S798>/Sum of Elements' incorporates:
   *  Math: '<S798>/Math Function'
   *  SignalConversion: '<S798>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S798>/Math Function1' incorporates:
   *  Sum: '<S798>/Sum of Elements'
   *
   * About '<S798>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S798>/Math Function1' */

  /* Switch: '<S798>/Switch' incorporates:
   *  Constant: '<S798>/Constant'
   *  Product: '<S798>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S798>/Switch' */

  /* Product: '<S798>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S796>/Subtract' incorporates:
   *  Product: '<S796>/Multiply'
   *  Product: '<S796>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S795>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S795>/Sign1' */

  /* Switch: '<S795>/Switch2' incorporates:
   *  Constant: '<S795>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S795>/Switch2' */

  /* DotProduct: '<S795>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S795>/Acos' incorporates:
   *  DotProduct: '<S795>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S795>/Multiply' incorporates:
   *  Trigonometry: '<S795>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S779>/Switch' incorporates:
   *  Bias: '<S779>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S779>/Switch' */
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

  /* Gain: '<S782>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S783>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S783>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S783>/Multiply1' incorporates:
   *  Product: '<S783>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S783>/Divide' incorporates:
   *  Constant: '<S783>/Constant'
   *  Constant: '<S783>/R'
   *  Sqrt: '<S783>/Sqrt'
   *  Sum: '<S783>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S783>/Product3' incorporates:
   *  Constant: '<S783>/Constant1'
   *  Product: '<S783>/Multiply1'
   *  Sum: '<S783>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S783>/Multiply2' incorporates:
   *  Trigonometry: '<S783>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S782>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S787>/Abs' incorporates:
   *  Abs: '<S790>/Abs1'
   *  Switch: '<S787>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S787>/Switch1' incorporates:
   *  Abs: '<S787>/Abs'
   *  Bias: '<S787>/Bias2'
   *  Bias: '<S787>/Bias3'
   *  Constant: '<S784>/Constant'
   *  Constant: '<S784>/Constant1'
   *  Constant: '<S789>/Constant'
   *  Gain: '<S787>/Gain1'
   *  Product: '<S787>/Multiply'
   *  RelationalOperator: '<S789>/Compare'
   *  Switch: '<S784>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S790>/Switch1' incorporates:
     *  Bias: '<S790>/Bias2'
     *  Bias: '<S790>/Bias3'
     *  Constant: '<S790>/Constant'
     *  Constant: '<S791>/Constant'
     *  Math: '<S790>/Math Function'
     *  RelationalOperator: '<S791>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S790>/Switch1' */

    /* Signum: '<S787>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S787>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S784>/Sum' incorporates:
   *  Sum: '<S782>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S782>/Multiply' incorporates:
   *  Gain: '<S782>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S786>/Switch1' incorporates:
   *  Abs: '<S786>/Abs1'
   *  Bias: '<S786>/Bias2'
   *  Bias: '<S786>/Bias3'
   *  Constant: '<S786>/Constant'
   *  Constant: '<S788>/Constant'
   *  Math: '<S786>/Math Function'
   *  RelationalOperator: '<S788>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S786>/Switch1' */

  /* Product: '<S782>/Multiply' incorporates:
   *  Gain: '<S782>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S782>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S785>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S785>/Sum2' incorporates:
   *  Product: '<S785>/Multiply1'
   *  Product: '<S785>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S785>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S785>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S785>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S775>/Data Type Conversion' incorporates:
   *  Gain: '<S782>/Gain'
   *  Sum: '<S782>/Sum1'
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
  /* RelationalOperator: '<S794>/Compare' incorporates:
   *  Abs: '<S778>/Abs'
   *  Constant: '<S794>/Constant'
   *  MinMax: '<S778>/Max'
   *  Sum: '<S778>/Sum'
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
      /* Reshape: '<S777>/Reshape' incorporates:
       *  Constant: '<S777>/Constant'
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
          /* RelationalOperator: '<S780>/Compare' incorporates:
           *  Constant: '<S780>/Constant'
           *  S-Function (sfix_bitop): '<S772>/Bitwise AND'
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
          /* RelationalOperator: '<S773>/Relational Operator1' incorporates:
           *  Constant: '<S773>/Constant1'
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
        /* RelationalOperator: '<S771>/Relational Operator' incorporates:
         *  Constant: '<S771>/Constant'
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
          /* RelationalOperator: '<S770>/Relational Operator1' incorporates:
           *  Constant: '<S770>/Constant1'
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

  /* Sqrt: '<S810>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S810>/Square'
   *  Sqrt: '<S21>/Sqrt'
   *  Sum: '<S810>/Sum of Elements'
   *  Switch: '<S1>/Switch'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S806>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Sqrt: '<S810>/Sqrt'
   */
  rtb_Divide_lr_idx_0 = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S807>/Square' incorporates:
   *  Math: '<S808>/Square'
   *  Math: '<S809>/Square'
   */
  rtb_Saturation_ga = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

  /* Math: '<S807>/Square2' incorporates:
   *  Math: '<S808>/Square2'
   *  Math: '<S809>/Square2'
   */
  rtb_Saturation1_d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S807>/Square1' incorporates:
   *  Math: '<S808>/Square1'
   *  Math: '<S809>/Square1'
   */
  rtb_Saturation_o4 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S807>/Square3' incorporates:
   *  Math: '<S808>/Square3'
   *  Math: '<S809>/Square3'
   */
  rtb_u_b = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

  /* Sum: '<S807>/Subtract' incorporates:
   *  Math: '<S807>/Square'
   *  Math: '<S807>/Square1'
   *  Math: '<S807>/Square2'
   *  Math: '<S807>/Square3'
   *  Sum: '<S807>/Add'
   *  Sum: '<S807>/Add1'
   */
  rtb_VectorConcatenate_or[0] = (rtb_Saturation_ga + rtb_Saturation_o4) -
    (rtb_Saturation1_d + rtb_u_b);

  /* Product: '<S807>/Multiply' incorporates:
   *  Product: '<S808>/Multiply'
   */
  d = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S807>/Multiply1' incorporates:
   *  Product: '<S808>/Multiply1'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_3;

  /* Gain: '<S807>/Gain' incorporates:
   *  Product: '<S807>/Multiply'
   *  Product: '<S807>/Multiply1'
   *  Sum: '<S807>/Subtract1'
   */
  rtb_VectorConcatenate_or[1] = (d - rtb_Integrator1_bx) * 2.0F;

  /* Product: '<S807>/Multiply2' incorporates:
   *  Product: '<S809>/Multiply'
   */
  rtb_a_bx = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_3;

  /* Product: '<S807>/Multiply3' incorporates:
   *  Product: '<S809>/Multiply1'
   */
  rtb_P_f_idx_0 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_2;

  /* Gain: '<S807>/Gain1' incorporates:
   *  Product: '<S807>/Multiply2'
   *  Product: '<S807>/Multiply3'
   *  Sum: '<S807>/Add2'
   */
  rtb_VectorConcatenate_or[2] = (rtb_a_bx + rtb_P_f_idx_0) * 2.0F;

  /* Gain: '<S808>/Gain' incorporates:
   *  Sum: '<S808>/Add3'
   */
  rtb_VectorConcatenate_or[3] = (d + rtb_Integrator1_bx) * 2.0F;

  /* Sum: '<S808>/Subtract' incorporates:
   *  Sum: '<S808>/Add'
   *  Sum: '<S808>/Add1'
   */
  rtb_VectorConcatenate_or[4] = (rtb_Saturation_ga + rtb_Saturation1_d) -
    (rtb_Saturation_o4 + rtb_u_b);

  /* Product: '<S808>/Multiply2' incorporates:
   *  Product: '<S809>/Multiply2'
   */
  d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_3;

  /* Product: '<S808>/Multiply3' incorporates:
   *  Product: '<S809>/Multiply3'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1;

  /* Gain: '<S808>/Gain1' incorporates:
   *  Product: '<S808>/Multiply2'
   *  Product: '<S808>/Multiply3'
   *  Sum: '<S808>/Subtract1'
   */
  rtb_VectorConcatenate_or[5] = (d - rtb_Integrator1_bx) * 2.0F;

  /* Gain: '<S809>/Gain' incorporates:
   *  Sum: '<S809>/Subtract2'
   */
  rtb_VectorConcatenate_or[6] = (rtb_a_bx - rtb_P_f_idx_0) * 2.0F;

  /* Gain: '<S809>/Gain1' incorporates:
   *  Sum: '<S809>/Add2'
   */
  rtb_VectorConcatenate_or[7] = (d + rtb_Integrator1_bx) * 2.0F;

  /* Sum: '<S809>/Subtract' incorporates:
   *  Sum: '<S809>/Add'
   *  Sum: '<S809>/Add1'
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

  /* DiscreteIntegrator: '<S801>/Discrete-Time Integrator5' */
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
   *  ActionPort: '<S324>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S324>/Position' incorporates:
   *  ActionPort: '<S331>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S398>/Hold Control' incorporates:
   *  ActionPort: '<S400>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S325>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S325>/Offboard' incorporates:
   *  ActionPort: '<S437>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S327>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S327>/Land' incorporates:
   *  ActionPort: '<S627>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S327>/Takeoff' incorporates:
   *  ActionPort: '<S629>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
   *  ActionPort: '<S109>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S109>/Position' incorporates:
   *  ActionPort: '<S115>/Action Port'
   */
  /* SwitchCase: '<S109>/Switch Case' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  MultiPortSwitch: '<S519>/Index Vector'
   *  MultiPortSwitch: '<S584>/Index Vector'
   *  MultiPortSwitch: '<S585>/Index Vector'
   *  SwitchCase: '<S324>/Switch Case'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S327>/Switch Case'
   *  SwitchCase: '<S398>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S15>/Trigonometric Function1'
   *  Trigonometry: '<S15>/Trigonometric Function3'
   *  Trigonometry: '<S207>/Trigonometric Function1'
   *  Trigonometry: '<S207>/Trigonometric Function3'
   *  Trigonometry: '<S404>/Trigonometric Function1'
   *  Trigonometry: '<S404>/Trigonometric Function3'
   *  Trigonometry: '<S530>/Trigonometric Function1'
   *  Trigonometry: '<S530>/Trigonometric Function3'
   *  Trigonometry: '<S593>/Trigonometric Function1'
   *  Trigonometry: '<S593>/Trigonometric Function3'
   *  Trigonometry: '<S597>/Trigonometric Function1'
   *  Trigonometry: '<S597>/Trigonometric Function3'
   *  Trigonometry: '<S623>/Trigonometric Function1'
   *  Trigonometry: '<S623>/Trigonometric Function3'
   *  Trigonometry: '<S687>/Trigonometric Function1'
   *  Trigonometry: '<S687>/Trigonometric Function3'
   *  Trigonometry: '<S768>/Trigonometric Function1'
   *  Trigonometry: '<S768>/Trigonometric Function3'
   *  Trigonometry: '<S99>/Trigonometric Function1'
   *  Trigonometry: '<S99>/Trigonometric Function3'
   */
  rtb_Saturation_ga = arm_cos_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S109>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S327>/Takeoff' */
  /* End of Outputs for SubSystem: '<S327>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S325>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S398>/Hold Control' */
  /* End of Outputs for SubSystem: '<S324>/Position' */
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
   *  ActionPort: '<S324>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S324>/Position' incorporates:
   *  ActionPort: '<S331>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S398>/Hold Control' incorporates:
   *  ActionPort: '<S400>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S325>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S325>/Offboard' incorporates:
   *  ActionPort: '<S437>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S327>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S327>/Land' incorporates:
   *  ActionPort: '<S627>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S327>/Takeoff' incorporates:
   *  ActionPort: '<S629>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/FW_Mode' incorporates:
   *  ActionPort: '<S49>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
   *  ActionPort: '<S109>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S109>/Position' incorporates:
   *  ActionPort: '<S115>/Action Port'
   */
  /* SwitchCase: '<S109>/Switch Case' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  MultiPortSwitch: '<S519>/Index Vector'
   *  MultiPortSwitch: '<S584>/Index Vector'
   *  MultiPortSwitch: '<S585>/Index Vector'
   *  SwitchCase: '<S324>/Switch Case'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S327>/Switch Case'
   *  SwitchCase: '<S398>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S15>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function2'
   *  Trigonometry: '<S207>/Trigonometric Function'
   *  Trigonometry: '<S404>/Trigonometric Function'
   *  Trigonometry: '<S530>/Trigonometric Function'
   *  Trigonometry: '<S593>/Trigonometric Function'
   *  Trigonometry: '<S597>/Trigonometric Function'
   *  Trigonometry: '<S623>/Trigonometric Function'
   *  Trigonometry: '<S687>/Trigonometric Function'
   *  Trigonometry: '<S768>/Trigonometric Function'
   *  Trigonometry: '<S99>/Trigonometric Function'
   */
  rtb_Saturation1_d = arm_sin_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S109>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S327>/Takeoff' */
  /* End of Outputs for SubSystem: '<S327>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S325>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S398>/Hold Control' */
  /* End of Outputs for SubSystem: '<S324>/Position' */
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

  /* DiscreteIntegrator: '<S803>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S803>/Data Type Conversion'
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

  /* DiscreteIntegrator: '<S802>/Discrete-Time Integrator5' */
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
   *  Constant: '<S799>/Constant'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S801>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S802>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S803>/Discrete-Time Integrator5'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S804>/AND'
   *  RelationalOperator: '<S799>/Compare'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S804>/Lower Test'
   *  RelationalOperator: '<S804>/Upper Test'
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
   *  ActionPort: '<S110>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S110>/Mission' incorporates:
   *  ActionPort: '<S223>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S223>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S227>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
   *  ActionPort: '<S112>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Return' incorporates:
   *  ActionPort: '<S259>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Takeoff' incorporates:
   *  ActionPort: '<S260>/Action Port'
   */
  /* SwitchCase: '<S110>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S248>/Math Function'
   *  Math: '<S297>/Math Function'
   *  Math: '<S319>/Math Function'
   *  SwitchCase: '<S112>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   */
  rtb_Saturation_o4 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S112>/Takeoff' */
  /* End of Outputs for SubSystem: '<S112>/Return' */
  /* End of Outputs for SubSystem: '<S223>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S110>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */

  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S325>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S325>/Mission' incorporates:
   *  ActionPort: '<S436>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S436>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S440>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S327>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S327>/Return' incorporates:
   *  ActionPort: '<S628>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Hold' incorporates:
   *  ActionPort: '<S257>/Action Port'
   */
  /* SwitchCase: '<S112>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S274>/Sum of Elements'
   *  Sum: '<S508>/Sum of Elements'
   *  Sum: '<S748>/Sum of Elements'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S327>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Integrator1_bx = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S324>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S324>/Position' incorporates:
   *  ActionPort: '<S331>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S110>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S110>/Mission' incorporates:
   *  ActionPort: '<S223>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S223>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S227>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Return' incorporates:
   *  ActionPort: '<S259>/Action Port'
   */
  /* SwitchCase: '<S110>/Switch Case' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S247>/Sqrt'
   *  Sqrt: '<S273>/Sqrt'
   *  Sqrt: '<S296>/Sqrt'
   *  Sqrt: '<S399>/Sqrt'
   *  Sqrt: '<S506>/Sqrt'
   *  Sqrt: '<S746>/Sqrt'
   *  Sum: '<S1>/Add'
   *  SwitchCase: '<S112>/Switch Case'
   *  SwitchCase: '<S324>/Switch Case'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S327>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Divide_lr_idx_2 = sqrtf(rtb_Integrator1_bx);

  /* End of Outputs for SubSystem: '<S112>/Return' */
  /* End of Outputs for SubSystem: '<S223>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S110>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */
  /* End of Outputs for SubSystem: '<S324>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S112>/Hold' */
  /* End of Outputs for SubSystem: '<S327>/Return' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S436>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S325>/Mission' */
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

  /* RelationalOperator: '<S800>/Compare' incorporates:
   *  Constant: '<S800>/Constant'
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
        /* Disable for SwitchCase: '<S112>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S110>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S109>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S122>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S162>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S147>/Switch Case' */
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
      /* Disable for SwitchCase: '<S53>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S50>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S327>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S727>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S717>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S666>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S634>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S645>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S325>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S436>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S487>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S477>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S436>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S324>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S423>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S339>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S357>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S398>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S385>/Switch Case' */
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
          /* Disable for SwitchCase: '<S112>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S110>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S109>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S122>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S162>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S147>/Switch Case' */
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
        /* Disable for SwitchCase: '<S53>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S50>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S327>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S727>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S717>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S666>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S645>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S325>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S436>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S487>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S477>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S436>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S324>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S423>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S339>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S357>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S373>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S398>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S385>/Switch Case' */
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
          /* Disable for SwitchCase: '<S112>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S110>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S109>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S122>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S162>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S147>/Switch Case' */
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
         *  ActionPort: '<S112>/Action Port'
         */
        /* SwitchCase: '<S112>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S112>/Takeoff' incorporates:
           *  ActionPort: '<S260>/Action Port'
           */
          /* Sum: '<S319>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

          /* Math: '<S319>/Math Function1' incorporates:
           *  Sum: '<S319>/Sum of Elements'
           *
           * About '<S319>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S319>/Math Function1' */

          /* Switch: '<S319>/Switch' incorporates:
           *  Constant: '<S319>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S319>/Product'
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

          /* End of Switch: '<S319>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S309>/NearbyRefWP' incorporates:
           *  Constant: '<S307>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_c14,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S309>/SearchL1RefWP' incorporates:
           *  Constant: '<S307>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_ap, &rtb_u_b);

          /* MATLAB Function: '<S309>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S304>/Sum'
           *  Sum: '<S304>/Sum1'
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

          /* End of MATLAB Function: '<S309>/OutRegionRegWP' */

          /* Switch: '<S309>/Switch1' incorporates:
           *  Constant: '<S312>/Constant'
           *  RelationalOperator: '<S312>/Compare'
           */
          if (rtb_Saturation1_d <= 0.0F) {
            /* Switch: '<S309>/Switch' incorporates:
             *  Constant: '<S311>/Constant'
             *  RelationalOperator: '<S311>/Compare'
             */
            if (rtb_u_b >= 0.0F) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            } else {
              rtb_Divide_c14[0] = rtb_P_f_idx_0;
              rtb_Divide_c14[1] = rtb_Saturation_ga;
            }

            /* End of Switch: '<S309>/Switch' */
          }

          /* End of Switch: '<S309>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S310>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S320>/Sum of Elements' incorporates:
           *  Math: '<S320>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S320>/Math Function1' incorporates:
           *  Sum: '<S320>/Sum of Elements'
           *
           * About '<S320>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S320>/Math Function1' */

          /* Switch: '<S320>/Switch' incorporates:
           *  Constant: '<S320>/Constant'
           *  Product: '<S320>/Product'
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

          /* End of Switch: '<S320>/Switch' */

          /* Product: '<S319>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S322>/Sum of Elements' incorporates:
           *  Math: '<S322>/Math Function'
           *  SignalConversion: '<S322>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S322>/Math Function1' incorporates:
           *  Sum: '<S322>/Sum of Elements'
           *
           * About '<S322>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S322>/Math Function1' */

          /* Switch: '<S322>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  Product: '<S322>/Product'
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

          /* End of Switch: '<S322>/Switch' */

          /* Product: '<S320>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S323>/Sum of Elements' incorporates:
           *  Math: '<S323>/Math Function'
           *  SignalConversion: '<S323>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S323>/Math Function1' incorporates:
           *  Sum: '<S323>/Sum of Elements'
           *
           * About '<S323>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S323>/Math Function1' */

          /* Switch: '<S323>/Switch' incorporates:
           *  Constant: '<S323>/Constant'
           *  Product: '<S323>/Product'
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

          /* End of Switch: '<S323>/Switch' */

          /* Product: '<S323>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S322>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S323>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S322>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S304>/Divide' incorporates:
           *  Math: '<S305>/Square'
           *  Math: '<S306>/Square'
           *  Sqrt: '<S305>/Sqrt'
           *  Sqrt: '<S306>/Sqrt'
           *  Sum: '<S305>/Sum of Elements'
           *  Sum: '<S306>/Sum of Elements'
           */
          rtb_Divide_lr_idx_2 = sqrtf(rtb_a_bx * rtb_a_bx + d * d) / sqrtf
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 + rtb_Integrator1_bx *
             rtb_Integrator1_bx);

          /* Saturate: '<S304>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S304>/Saturation' */

          /* Sum: '<S321>/Subtract' incorporates:
           *  Product: '<S321>/Multiply'
           *  Product: '<S321>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S317>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S317>/Sign1' */

          /* Switch: '<S317>/Switch2' incorporates:
           *  Constant: '<S317>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S317>/Switch2' */

          /* DotProduct: '<S317>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S317>/Acos' incorporates:
           *  DotProduct: '<S317>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S317>/Multiply' incorporates:
           *  Trigonometry: '<S317>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S316>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S316>/Saturation' */

          /* Sqrt: '<S318>/Sqrt' incorporates:
           *  Sum: '<S318>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(rtb_Saturation_o4 + rtb_Divide_lr_idx_3);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S260>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S260>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S260>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S260>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S316>/Divide' incorporates:
           *  Constant: '<S307>/L1'
           *  Gain: '<S316>/Gain'
           *  Math: '<S316>/Square'
           *  Product: '<S316>/Multiply1'
           *  Trigonometry: '<S316>/Sin'
           */
          rtb_u_b = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F * arm_sin_f32
            (rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S307>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S307>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S302>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S304>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S302>/Sum2'
           *  Sum: '<S304>/Add'
           *  Sum: '<S304>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_lr_idx_2 +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S302>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S302>/Saturation1' */
          /* End of Outputs for SubSystem: '<S112>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S112>/Land' incorporates:
           *  ActionPort: '<S258>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S258>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S258>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S258>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S258>/Constant'
           *  Constant: '<S258>/Constant4'
           *  Constant: '<S258>/Constant5'
           *  Constant: '<S258>/Constant7'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S112>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S112>/Return' incorporates:
           *  ActionPort: '<S259>/Action Port'
           */
          /* Math: '<S297>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Divide_lr_idx_3;

          /* Sum: '<S297>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

          /* Math: '<S297>/Math Function1' incorporates:
           *  Sum: '<S297>/Sum of Elements'
           *
           * About '<S297>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S297>/Math Function1' */

          /* Switch: '<S297>/Switch' incorporates:
           *  Constant: '<S297>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S297>/Product'
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

          /* End of Switch: '<S297>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S287>/NearbyRefWP' incorporates:
           *  Constant: '<S285>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S287>/SearchL1RefWP' incorporates:
           *  Constant: '<S285>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_c14, &rtb_Saturation1_d);

          /* MATLAB Function: '<S287>/OutRegionRegWP' incorporates:
           *  Constant: '<S285>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S287>/Switch1' incorporates:
           *  Constant: '<S290>/Constant'
           *  RelationalOperator: '<S290>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_c14[0] = rtb_Subtract_hb[0];
            rtb_Divide_c14[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S289>/Compare' incorporates:
             *  Constant: '<S289>/Constant'
             */
            rtb_Compare_o3 = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S287>/Switch' */
            if (!rtb_Compare_o3) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S287>/Switch' */
          }

          /* End of Switch: '<S287>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S288>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S298>/Sum of Elements' incorporates:
           *  Math: '<S298>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S298>/Math Function1' incorporates:
           *  Sum: '<S298>/Sum of Elements'
           *
           * About '<S298>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S298>/Math Function1' */

          /* Switch: '<S298>/Switch' incorporates:
           *  Constant: '<S298>/Constant'
           *  Product: '<S298>/Product'
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

          /* End of Switch: '<S298>/Switch' */

          /* Product: '<S297>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S300>/Sum of Elements' incorporates:
           *  Math: '<S300>/Math Function'
           *  SignalConversion: '<S300>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S300>/Math Function1' incorporates:
           *  Sum: '<S300>/Sum of Elements'
           *
           * About '<S300>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S300>/Math Function1' */

          /* Switch: '<S300>/Switch' incorporates:
           *  Constant: '<S300>/Constant'
           *  Product: '<S300>/Product'
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

          /* End of Switch: '<S300>/Switch' */

          /* Product: '<S298>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S301>/Sum of Elements' incorporates:
           *  Math: '<S301>/Math Function'
           *  SignalConversion: '<S301>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S301>/Math Function1' incorporates:
           *  Sum: '<S301>/Sum of Elements'
           *
           * About '<S301>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S301>/Math Function1' */

          /* Switch: '<S301>/Switch' incorporates:
           *  Constant: '<S301>/Constant'
           *  Product: '<S301>/Product'
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

          /* End of Switch: '<S301>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S282>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S301>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S300>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S282>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S301>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S300>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S282>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S282>/Divide' incorporates:
           *  Math: '<S283>/Square'
           *  Math: '<S284>/Square'
           *  Sqrt: '<S283>/Sqrt'
           *  Sqrt: '<S284>/Sqrt'
           *  Sum: '<S282>/Sum'
           *  Sum: '<S282>/Sum1'
           *  Sum: '<S283>/Sum of Elements'
           *  Sum: '<S284>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_a_bx * rtb_a_bx + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S282>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S282>/Saturation' */

          /* Sum: '<S299>/Subtract' incorporates:
           *  Product: '<S299>/Multiply'
           *  Product: '<S299>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S295>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S295>/Sign1' */

          /* Switch: '<S295>/Switch2' incorporates:
           *  Constant: '<S295>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S295>/Switch2' */

          /* DotProduct: '<S295>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S295>/Acos' incorporates:
           *  DotProduct: '<S295>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S295>/Multiply' incorporates:
           *  Trigonometry: '<S295>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S294>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S294>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S259>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S259>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S259>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S294>/Divide' incorporates:
           *  Constant: '<S285>/L1'
           *  Gain: '<S294>/Gain'
           *  Math: '<S294>/Square'
           *  Product: '<S294>/Multiply1'
           *  Trigonometry: '<S294>/Sin'
           */
          rtb_u_b = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S285>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S285>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S280>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S282>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S280>/Sum2'
           *  Sum: '<S282>/Add'
           *  Sum: '<S282>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S280>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S280>/Saturation1' */
          /* End of Outputs for SubSystem: '<S112>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S112>/Hold' incorporates:
             *  ActionPort: '<S257>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S112>/Switch Case' incorporates:
             *  Delay: '<S262>/Delay'
             *  Delay: '<S267>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S112>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S112>/Hold' incorporates:
           *  ActionPort: '<S257>/Action Port'
           */
          /* Math: '<S274>/Math Function1'
           *
           * About '<S274>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Integrator1_bx);
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
            rtb_MatrixConcatenate3[0] = FMS_U.INS_Out.vn;
            rtb_MatrixConcatenate3[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S274>/Switch' */

          /* Delay: '<S267>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S279>/Sum of Elements' incorporates:
           *  Delay: '<S267>/start_vel'
           *  Math: '<S279>/Math Function'
           */
          rtb_u_b = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S279>/Math Function1' incorporates:
           *  Sum: '<S279>/Sum of Elements'
           *
           * About '<S279>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S279>/Math Function1' */

          /* Switch: '<S279>/Switch' incorporates:
           *  Constant: '<S279>/Constant'
           *  Delay: '<S267>/start_vel'
           *  Product: '<S279>/Product'
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

          /* End of Switch: '<S279>/Switch' */

          /* Product: '<S274>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S277>/Sum of Elements' incorporates:
           *  Math: '<S277>/Math Function'
           *  SignalConversion: '<S277>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

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
            rtb_MatrixConcatenate3[0] = rtb_Divide_c14[1];
            rtb_MatrixConcatenate3[1] = rtb_Divide_c14[0];
            rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S277>/Switch' */

          /* MinMax: '<S265>/Max' incorporates:
           *  Constant: '<S263>/L1'
           *  Constant: '<S263>/R'
           *  Gain: '<S265>/Gain'
           */
          rtb_Saturation_ga = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S265>/SearchL1RefWP' incorporates:
           *  Constant: '<S263>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S270>/TmpSignal ConversionAt SFunction Inport2'
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

          /* End of MATLAB Function: '<S265>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S268>/Compare' incorporates:
           *  Constant: '<S268>/Constant'
           */
          rtb_Compare_o3 = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S265>/OutRegionRegWP' incorporates:
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

          /* Switch: '<S265>/Switch' incorporates:
           *  Constant: '<S263>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S265>/OutRegionRegWP'
           *  Product: '<S279>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Compare_o3) {
            rtb_Saturation1_d = rtb_P_ap[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S265>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S266>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_ds[0] = rtb_Saturation1_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S265>/Switch' incorporates:
           *  Constant: '<S263>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S265>/OutRegionRegWP'
           *  Product: '<S279>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Compare_o3) {
            rtb_Saturation1_d = rtb_P_ap[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S265>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S266>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_ds[1] = rtb_Saturation1_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S275>/Sum of Elements' incorporates:
           *  Math: '<S275>/Math Function'
           */
          rtb_u_b = rtb_Square_ds[0] * rtb_Square_ds[0] + rtb_Square_ds[1] *
            rtb_Square_ds[1];

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
            rtb_Switch_ov[0] = rtb_Square_ds[0];
            rtb_Switch_ov[1] = rtb_Square_ds[1];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S275>/Switch' */

          /* Product: '<S275>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_c14[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S278>/Sum of Elements' incorporates:
           *  Math: '<S278>/Math Function'
           *  SignalConversion: '<S278>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

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
            rtb_Switch_ov[0] = rtb_Divide_c14[1];
            rtb_Switch_ov[1] = rtb_Divide_c14[0];
            rtb_Switch_ov[2] = rtb_Saturation_ga;
          } else {
            rtb_Switch_ov[0] = 0.0F;
            rtb_Switch_ov[1] = 0.0F;
            rtb_Switch_ov[2] = 1.0F;
          }

          /* End of Switch: '<S278>/Switch' */

          /* Product: '<S278>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S277>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S278>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S277>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S276>/Subtract' incorporates:
           *  Product: '<S276>/Multiply'
           *  Product: '<S276>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Divide_c14[0] * rtb_Subtract_hb[1] -
            rtb_Divide_c14[1] * rtb_Subtract_hb[0];

          /* Signum: '<S272>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S272>/Sign1' */

          /* Switch: '<S272>/Switch2' incorporates:
           *  Constant: '<S272>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S272>/Switch2' */

          /* DotProduct: '<S272>/Dot Product' */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_c14[0] +
            rtb_Subtract_hb[1] * rtb_Divide_c14[1];

          /* Trigonometry: '<S272>/Acos' incorporates:
           *  DotProduct: '<S272>/Dot Product'
           */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < -1.0F) {
              rtb_Saturation_o4 = -1.0F;
            }
          }

          /* Product: '<S272>/Multiply' incorporates:
           *  Trigonometry: '<S272>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation_o4);

          /* Saturate: '<S271>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S271>/Saturation' */

          /* Delay: '<S262>/Delay' incorporates:
           *  Gain: '<S264>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S257>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S257>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S257>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S257>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S271>/Divide' incorporates:
           *  Constant: '<S263>/L1'
           *  Gain: '<S271>/Gain'
           *  Math: '<S271>/Square'
           *  Product: '<S271>/Multiply1'
           *  Trigonometry: '<S271>/Sin'
           */
          rtb_u_b = 2.0F * (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2) *
            arm_sin_f32(rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S263>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S257>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S257>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S257>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S263>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S262>/Gain2' incorporates:
           *  Delay: '<S262>/Delay'
           *  Gain: '<S264>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S262>/Sum'
           */
          rtb_u_b = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S262>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S257>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S257>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S257>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S262>/Saturation1' */

          /* Update for Delay: '<S267>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S262>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S112>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S112>/Unknown' incorporates:
           *  ActionPort: '<S261>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S112>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
         *  ActionPort: '<S110>/Action Port'
         */
        /* SwitchCase: '<S110>/Switch Case' */
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
          /* Outputs for IfAction SubSystem: '<S110>/Offboard' incorporates:
           *  ActionPort: '<S224>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S224>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S224>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S224>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S110>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_hd != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S110>/Mission' incorporates:
             *  ActionPort: '<S223>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S110>/Switch Case' incorporates:
             *  UnitDelay: '<S226>/Delay Input1'
             *
             * Block description for '<S226>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S110>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S110>/Mission' incorporates:
             *  ActionPort: '<S223>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S223>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S110>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S234>/Integrator'
             *  DiscreteIntegrator: '<S234>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;
            FMS_DW.Integrator_DSTATE_fk = 0.0F;

            /* End of SystemReset for SubSystem: '<S223>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S110>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S110>/Mission' incorporates:
           *  ActionPort: '<S223>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S226>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S226>/Delay Input1'
           *
           * Block description for '<S226>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S223>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S227>/Reset'
           */
          if (rtb_Compare_o3 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k !=
                                 POS_ZCSIG)) {
            /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator1' */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;

            /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator' */
            FMS_DW.Integrator_DSTATE_fk = 0.0F;
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = rtb_Compare_o3;

          /* Math: '<S248>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Saturation_o4;
          rtb_Subtract_hb[1] = rtb_Divide_lr_idx_3;

          /* Sum: '<S248>/Sum of Elements' */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3;

          /* Math: '<S248>/Math Function1' incorporates:
           *  Sum: '<S248>/Sum of Elements'
           *
           * About '<S248>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S248>/Math Function1' */

          /* Switch: '<S248>/Switch' incorporates:
           *  Constant: '<S248>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S248>/Product'
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

          /* End of Switch: '<S248>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S238>/NearbyRefWP' incorporates:
           *  Constant: '<S236>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S238>/SearchL1RefWP' incorporates:
           *  Constant: '<S236>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_c14, &rtb_Saturation1_d);

          /* MATLAB Function: '<S238>/OutRegionRegWP' incorporates:
           *  Constant: '<S236>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S238>/Switch1' incorporates:
           *  Constant: '<S241>/Constant'
           *  RelationalOperator: '<S241>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_c14[0] = rtb_Subtract_hb[0];
            rtb_Divide_c14[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S240>/Compare' incorporates:
             *  Constant: '<S240>/Constant'
             */
            rtb_Compare_o3 = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S238>/Switch' */
            if (!rtb_Compare_o3) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S238>/Switch' */
          }

          /* End of Switch: '<S238>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S239>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S249>/Sum of Elements' incorporates:
           *  Math: '<S249>/Math Function'
           */
          rtb_u_b = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] + rtb_Subtract_hb[1]
            * rtb_Subtract_hb[1];

          /* Math: '<S249>/Math Function1' incorporates:
           *  Sum: '<S249>/Sum of Elements'
           *
           * About '<S249>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S249>/Math Function1' */

          /* Switch: '<S249>/Switch' incorporates:
           *  Constant: '<S249>/Constant'
           *  Product: '<S249>/Product'
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

          /* End of Switch: '<S249>/Switch' */

          /* Product: '<S248>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S251>/Sum of Elements' incorporates:
           *  Math: '<S251>/Math Function'
           *  SignalConversion: '<S251>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S251>/Math Function1' incorporates:
           *  Sum: '<S251>/Sum of Elements'
           *
           * About '<S251>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S251>/Math Function1' */

          /* Switch: '<S251>/Switch' incorporates:
           *  Constant: '<S251>/Constant'
           *  Product: '<S251>/Product'
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

          /* End of Switch: '<S251>/Switch' */

          /* Product: '<S249>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S252>/Sum of Elements' incorporates:
           *  Math: '<S252>/Math Function'
           *  SignalConversion: '<S252>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_u_b = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] + rtb_Subtract_hb[0]
            * rtb_Subtract_hb[0];

          /* Math: '<S252>/Math Function1' incorporates:
           *  Sum: '<S252>/Sum of Elements'
           *
           * About '<S252>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S252>/Math Function1' */

          /* Switch: '<S252>/Switch' incorporates:
           *  Constant: '<S252>/Constant'
           *  Product: '<S252>/Product'
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

          /* End of Switch: '<S252>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S231>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_u_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S252>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S251>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S231>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S252>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S251>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S231>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
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
          rtb_Saturation_ga = sqrtf(rtb_a_bx * rtb_a_bx + rtb_u_b * rtb_u_b) /
            sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_Saturation_o4 *
                  rtb_Saturation_o4);

          /* Saturate: '<S231>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S231>/Saturation' */

          /* Sum: '<S250>/Subtract' incorporates:
           *  Product: '<S250>/Multiply'
           *  Product: '<S250>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S246>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S246>/Sign1' */

          /* Switch: '<S246>/Switch2' incorporates:
           *  Constant: '<S246>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S246>/Switch2' */

          /* DotProduct: '<S246>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S246>/Acos' incorporates:
           *  DotProduct: '<S246>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S246>/Multiply' incorporates:
           *  Trigonometry: '<S246>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S245>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S245>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S227>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S227>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S227>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Saturate: '<S229>/Saturation' */
          if (FMS_DW.Integrator1_DSTATE_li > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_li < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_li;
          }

          /* End of Saturate: '<S229>/Saturation' */

          /* Product: '<S245>/Divide' incorporates:
           *  Constant: '<S236>/L1'
           *  Gain: '<S245>/Gain'
           *  Math: '<S245>/Square'
           *  Product: '<S245>/Multiply1'
           *  Trigonometry: '<S245>/Sin'
           */
          rtb_u_b = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_o4) / FMS_PARAM.FW_L1;

          /* Saturate: '<S236>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S236>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S228>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S231>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S228>/Sum2'
           *  Sum: '<S231>/Add'
           *  Sum: '<S231>/Subtract'
           */
          rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S228>/Saturation1' */
          if (rtb_u_b > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_u_b < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S227>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S228>/Saturation1' */

          /* Product: '<S235>/Multiply1' incorporates:
           *  Constant: '<S235>/const1'
           *  DiscreteIntegrator: '<S234>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_fk * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S229>/Switch' incorporates:
           *  Constant: '<S229>/Constant4'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            rtb_u_b = FMS_B.Cmd_In.set_speed;
          } else {
            rtb_u_b = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S229>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S235>/Add' incorporates:
           *  DiscreteIntegrator: '<S234>/Integrator1'
           *  Sum: '<S234>/Subtract'
           */
          rtb_Saturation_o4 = (FMS_DW.Integrator1_DSTATE_li - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S235>/Sign' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_Saturation_o4 > 0.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            rtb_Saturation1_d = rtb_Saturation_o4;
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
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation_o4) + FMS_ConstB.d_cy) *
                           FMS_ConstB.d_cy) - FMS_ConstB.d_cy) * 0.5F *
            rtb_Saturation1_d + rtb_Saturation_ga;

          /* Sum: '<S235>/Add4' */
          rtb_Saturation1_d = (rtb_Saturation_o4 - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S235>/Add3' */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_ConstB.d_cy;

          /* Sum: '<S235>/Subtract1' */
          rtb_Saturation_o4 -= FMS_ConstB.d_cy;

          /* Signum: '<S235>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S235>/Sign1' */

          /* Signum: '<S235>/Sign2' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S235>/Sign2' */

          /* Sum: '<S235>/Add5' incorporates:
           *  Gain: '<S235>/Gain2'
           *  Product: '<S235>/Multiply4'
           *  Sum: '<S235>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation_o4) * 0.5F *
            rtb_Saturation1_d;

          /* Update for DiscreteIntegrator: '<S234>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S234>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_li += 0.004F * FMS_DW.Integrator_DSTATE_fk;

          /* Sum: '<S235>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_cy;

          /* Sum: '<S235>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_cy;

          /* Signum: '<S235>/Sign5' incorporates:
           *  Signum: '<S235>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S235>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S235>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S235>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
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

          /* Update for DiscreteIntegrator: '<S234>/Integrator' incorporates:
           *  Constant: '<S235>/const'
           *  Gain: '<S235>/Gain3'
           *  Product: '<S235>/Divide'
           *  Product: '<S235>/Multiply5'
           *  Product: '<S235>/Multiply6'
           *  Sum: '<S235>/Subtract4'
           *  Sum: '<S235>/Subtract5'
           *  Sum: '<S235>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_fk += ((rtb_u_b / FMS_ConstB.d_cy -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ka * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 78.448F) * 0.004F;

          /* End of Outputs for SubSystem: '<S223>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S226>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S226>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S110>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S110>/Unknown' incorporates:
           *  ActionPort: '<S225>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S110>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S49>/Assist' incorporates:
         *  ActionPort: '<S109>/Action Port'
         */
        /* SwitchCase: '<S109>/Switch Case' */
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
            /* Disable for SwitchCase: '<S122>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S162>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S147>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S109>/Stabilize' incorporates:
             *  ActionPort: '<S116>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S109>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S216>/Integrator'
             *  DiscreteIntegrator: '<S216>/Integrator1'
             *  DiscreteIntegrator: '<S217>/Integrator'
             *  DiscreteIntegrator: '<S217>/Integrator1'
             *  DiscreteIntegrator: '<S221>/Integrator'
             *  DiscreteIntegrator: '<S221>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_av = 0.0F;
            FMS_DW.Integrator1_DSTATE_oo = 0.0F;
            FMS_DW.Integrator1_DSTATE_jv = 0.0F;
            FMS_DW.Integrator_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S109>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S109>/Stabilize' incorporates:
           *  ActionPort: '<S116>/Action Port'
           */
          /* Product: '<S218>/Multiply1' incorporates:
           *  Constant: '<S218>/const1'
           *  DiscreteIntegrator: '<S216>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_av * 0.04F;

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

          /* Sum: '<S218>/Add' incorporates:
           *  DiscreteIntegrator: '<S216>/Integrator1'
           *  Gain: '<S211>/Gain'
           *  Gain: '<S214>/Gain'
           *  Sum: '<S216>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) + rtb_a_bx;

          /* Signum: '<S218>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
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
          rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_ga + rtb_a_bx;

          /* Sum: '<S218>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_Integrator1_bx) +
            rtb_a_bx;

          /* Sum: '<S218>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S218>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

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
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign2' */

          /* Sum: '<S218>/Add5' incorporates:
           *  Gain: '<S218>/Gain2'
           *  Product: '<S218>/Multiply4'
           *  Sum: '<S218>/Subtract2'
           */
          rtb_Integrator1_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S116>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S116>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S216>/Integrator1'
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  DiscreteIntegrator: '<S221>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_oo;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_jv;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S213>/Saturation' incorporates:
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

          /* End of Saturate: '<S213>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S213>/Constant5'
           *  Gain: '<S213>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S213>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_u_b), 65536.0F) + 1000U);

          /* Product: '<S222>/Multiply1' incorporates:
           *  Constant: '<S222>/const1'
           *  DiscreteIntegrator: '<S221>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_j * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S220>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S220>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S222>/Add' incorporates:
           *  DiscreteIntegrator: '<S221>/Integrator1'
           *  Gain: '<S212>/Gain1'
           *  Gain: '<S220>/Gain'
           *  Sum: '<S221>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_jv - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_bx;

          /* Signum: '<S222>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S222>/Sign' */

          /* Sum: '<S222>/Add2' incorporates:
           *  Abs: '<S222>/Abs'
           *  Gain: '<S222>/Gain'
           *  Gain: '<S222>/Gain1'
           *  Product: '<S222>/Multiply2'
           *  Product: '<S222>/Multiply3'
           *  Sqrt: '<S222>/Sqrt'
           *  Sum: '<S222>/Add1'
           *  Sum: '<S222>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_mq)
            * FMS_ConstB.d_mq) - FMS_ConstB.d_mq) * 0.5F * rtb_Divide_lr_idx_3 +
            rtb_a_bx;

          /* Sum: '<S222>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_Divide_lr_idx_2) + rtb_a_bx;

          /* Sum: '<S222>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_mq;

          /* Sum: '<S222>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_mq;

          /* Signum: '<S222>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S222>/Sign1' */

          /* Signum: '<S222>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S222>/Sign2' */

          /* Sum: '<S222>/Add5' incorporates:
           *  Gain: '<S222>/Gain2'
           *  Product: '<S222>/Multiply4'
           *  Sum: '<S222>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S222>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_2 + FMS_ConstB.d_mq;

          /* Sum: '<S222>/Subtract3' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 - FMS_ConstB.d_mq;

          /* Product: '<S222>/Divide' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 / FMS_ConstB.d_mq;

          /* Signum: '<S222>/Sign5' incorporates:
           *  Signum: '<S222>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_p2 = -1.0F;

            /* Signum: '<S222>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_p2 = 1.0F;

            /* Signum: '<S222>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_p2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S222>/Sign6' */
            rtb_Saturation_o4 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S222>/Sign5' */

          /* Product: '<S219>/Multiply1' incorporates:
           *  Constant: '<S219>/const1'
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S215>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S215>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S219>/Add' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  Gain: '<S211>/Gain1'
           *  Gain: '<S215>/Gain'
           *  Sum: '<S217>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_oo - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S219>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S219>/Sign' */

          /* Sum: '<S219>/Add2' incorporates:
           *  Abs: '<S219>/Abs'
           *  Gain: '<S219>/Gain'
           *  Gain: '<S219>/Gain1'
           *  Product: '<S219>/Multiply2'
           *  Product: '<S219>/Multiply3'
           *  Sqrt: '<S219>/Sqrt'
           *  Sum: '<S219>/Add1'
           *  Sum: '<S219>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_my) *
                            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S219>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_a_bx) + rtb_Divide_lr_idx_2;

          /* Sum: '<S219>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_my;

          /* Sum: '<S219>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_my;

          /* Signum: '<S219>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign1' */

          /* Signum: '<S219>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign2' */

          /* Sum: '<S219>/Add5' incorporates:
           *  Gain: '<S219>/Gain2'
           *  Product: '<S219>/Multiply4'
           *  Sum: '<S219>/Subtract2'
           */
          rtb_a_bx += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Update for DiscreteIntegrator: '<S216>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S216>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S218>/Subtract3' */
          rtb_Divide_lr_idx_2 = rtb_Integrator1_bx - FMS_ConstB.d_ny;

          /* Sum: '<S218>/Add6' */
          d = rtb_Integrator1_bx + FMS_ConstB.d_ny;

          /* Signum: '<S218>/Sign5' incorporates:
           *  Signum: '<S218>/Sign6'
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;

            /* Signum: '<S218>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (rtb_Integrator1_bx > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;

            /* Signum: '<S218>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Integrator1_bx;

            /* Signum: '<S218>/Sign6' */
            rtb_u_b = rtb_Integrator1_bx;
          }

          /* End of Signum: '<S218>/Sign5' */

          /* Signum: '<S218>/Sign3' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign3' */

          /* Signum: '<S218>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign4' */

          /* Update for DiscreteIntegrator: '<S216>/Integrator' incorporates:
           *  Constant: '<S218>/const'
           *  Gain: '<S218>/Gain3'
           *  Product: '<S218>/Divide'
           *  Product: '<S218>/Multiply5'
           *  Product: '<S218>/Multiply6'
           *  Sum: '<S218>/Subtract4'
           *  Sum: '<S218>/Subtract5'
           *  Sum: '<S218>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((rtb_Integrator1_bx / FMS_ConstB.d_ny
            - rtb_Divide_lr_idx_3) * FMS_ConstB.Gain4_ko * ((d -
            rtb_Divide_lr_idx_2) * 0.5F) - rtb_u_b * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S217>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_oo += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S221>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S221>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jv += 0.004F * FMS_DW.Integrator_DSTATE_j;

          /* Signum: '<S222>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S222>/Sign3' */

          /* Signum: '<S222>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S222>/Sign4' */

          /* Update for DiscreteIntegrator: '<S221>/Integrator' incorporates:
           *  Constant: '<S222>/const'
           *  Gain: '<S222>/Gain3'
           *  Product: '<S222>/Multiply5'
           *  Product: '<S222>/Multiply6'
           *  Sum: '<S222>/Subtract4'
           *  Sum: '<S222>/Subtract5'
           *  Sum: '<S222>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_j += ((rtb_P_f_idx_0 - rtb_Sign5_p2) *
            FMS_ConstB.Gain4_b * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 15.707963F) * 0.004F;

          /* Sum: '<S219>/Subtract3' */
          rtb_Saturation_ga = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S219>/Add6' */
          rtb_Saturation1_d = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S219>/Sign5' incorporates:
           *  Signum: '<S219>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S219>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S219>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_a_bx;

            /* Signum: '<S219>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_a_bx;
          }

          /* End of Signum: '<S219>/Sign5' */

          /* Signum: '<S219>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign3' */

          /* Signum: '<S219>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign4' */

          /* Update for DiscreteIntegrator: '<S217>/Integrator' incorporates:
           *  Constant: '<S219>/const'
           *  Gain: '<S219>/Gain3'
           *  Product: '<S219>/Divide'
           *  Product: '<S219>/Multiply5'
           *  Product: '<S219>/Multiply6'
           *  Sum: '<S219>/Subtract4'
           *  Sum: '<S219>/Subtract5'
           *  Sum: '<S219>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_bx / FMS_ConstB.d_my -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_k2 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S109>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S109>/Altitude' incorporates:
             *  ActionPort: '<S114>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S109>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S126>/Integrator'
             *  DiscreteIntegrator: '<S126>/Integrator1'
             *  DiscreteIntegrator: '<S135>/Integrator'
             *  DiscreteIntegrator: '<S135>/Integrator1'
             *  DiscreteIntegrator: '<S138>/Integrator'
             *  DiscreteIntegrator: '<S138>/Integrator1'
             *  DiscreteIntegrator: '<S141>/Integrator'
             *  DiscreteIntegrator: '<S141>/Integrator1'
             */
            FMS_DW.Integrator_DSTATE_hd = 0.0F;
            FMS_DW.Integrator1_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_jl = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator_DSTATE_n = 0.0F;
            FMS_DW.Integrator_DSTATE_er = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S109>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S109>/Altitude' incorporates:
             *  ActionPort: '<S114>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S109>/Switch Case' incorporates:
             *  Chart: '<S123>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S109>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S109>/Altitude' incorporates:
           *  ActionPort: '<S114>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S123>/Motion Status' incorporates:
           *  Abs: '<S123>/Abs'
           *  Abs: '<S123>/Abs1'
           *  Constant: '<S132>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S132>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S122>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S122>/Hold Control' incorporates:
               *  ActionPort: '<S124>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S122>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S122>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S122>/Hold Control' incorporates:
             *  ActionPort: '<S124>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_lj,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S122>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ah != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S122>/Move Control' incorporates:
               *  ActionPort: '<S125>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S122>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S122>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S122>/Move Control' incorporates:
             *  ActionPort: '<S125>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_lj,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S122>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S122>/Switch Case' */

          /* DiscreteIntegrator: '<S126>/Integrator' */
          rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_hd;

          /* Product: '<S131>/Multiply1' incorporates:
           *  Constant: '<S131>/const1'
           *  DiscreteIntegrator: '<S126>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hd * 0.05F;

          /* Saturate: '<S122>/Saturation1' */
          if (FMS_B.Merge_lj > FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_lj < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_u_b = FMS_B.Merge_lj;
          }

          /* End of Saturate: '<S122>/Saturation1' */

          /* Sum: '<S131>/Add' incorporates:
           *  DiscreteIntegrator: '<S126>/Integrator1'
           *  Sum: '<S126>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_a - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S131>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S131>/Sign' */

          /* Sum: '<S131>/Add2' incorporates:
           *  Abs: '<S131>/Abs'
           *  Gain: '<S131>/Gain'
           *  Gain: '<S131>/Gain1'
           *  Product: '<S131>/Multiply2'
           *  Product: '<S131>/Multiply3'
           *  Sqrt: '<S131>/Sqrt'
           *  Sum: '<S131>/Add1'
           *  Sum: '<S131>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_ar) *
                            FMS_ConstB.d_ar) - FMS_ConstB.d_ar) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S131>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_a_bx) + rtb_Saturation_ga;

          /* Sum: '<S131>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ar;

          /* Sum: '<S131>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ar;

          /* Signum: '<S131>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S131>/Sign1' */

          /* Signum: '<S131>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S131>/Sign2' */

          /* Sum: '<S131>/Add5' incorporates:
           *  Gain: '<S131>/Gain2'
           *  Product: '<S131>/Multiply4'
           *  Sum: '<S131>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S114>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S114>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S114>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S135>/Integrator1'
           *  DiscreteIntegrator: '<S138>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_jl;

          /* Saturate: '<S121>/Saturation1' */
          if (FMS_DW.Integrator1_DSTATE_o > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S114>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_o < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S114>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S114>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_o;
          }

          /* End of Saturate: '<S121>/Saturation1' */

          /* BusAssignment: '<S114>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S126>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S121>/Saturation' incorporates:
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

          /* End of Saturate: '<S121>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S142>/Multiply1' incorporates:
           *  Constant: '<S142>/const1'
           *  DiscreteIntegrator: '<S141>/Integrator'
           */
          rtb_Sign5_p2 = FMS_DW.Integrator_DSTATE_n * 0.05F;

          /* Switch: '<S140>/Switch' incorporates:
           *  Constant: '<S140>/Constant'
           *  Constant: '<S140>/Constant1'
           *  Constant: '<S140>/Constant2'
           *  Product: '<S140>/Multiply'
           *  Product: '<S140>/Multiply1'
           *  Sum: '<S140>/Subtract'
           *  Sum: '<S140>/Subtract1'
           *  Sum: '<S140>/Sum'
           *  Sum: '<S140>/Sum1'
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

          /* End of Switch: '<S140>/Switch' */

          /* Sum: '<S142>/Add' incorporates:
           *  DiscreteIntegrator: '<S141>/Integrator1'
           *  Sum: '<S141>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_o - rtb_Saturation_ga) +
            rtb_Sign5_p2;

          /* Signum: '<S142>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
          }

          /* End of Signum: '<S142>/Sign' */

          /* Sum: '<S142>/Add2' incorporates:
           *  Abs: '<S142>/Abs'
           *  Gain: '<S142>/Gain'
           *  Gain: '<S142>/Gain1'
           *  Product: '<S142>/Multiply2'
           *  Product: '<S142>/Multiply3'
           *  Sqrt: '<S142>/Sqrt'
           *  Sum: '<S142>/Add1'
           *  Sum: '<S142>/Subtract'
           */
          rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_e) *
            FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F * rtb_Add4_pb +
            rtb_Sign5_p2;

          /* Sum: '<S142>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - rtb_P_f_idx_0) + rtb_Sign5_p2;

          /* Sum: '<S142>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_e;

          /* Sum: '<S142>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_e;

          /* Signum: '<S142>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S142>/Sign1' */

          /* Signum: '<S142>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S142>/Sign2' */

          /* Sum: '<S142>/Add5' incorporates:
           *  Gain: '<S142>/Gain2'
           *  Product: '<S142>/Multiply4'
           *  Sum: '<S142>/Subtract2'
           */
          rtb_P_f_idx_0 += (rtb_Saturation_ga - rtb_u_b) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S142>/Add6' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_e;

          /* Sum: '<S142>/Subtract3' */
          rtb_Saturation1_d = rtb_P_f_idx_0 - FMS_ConstB.d_e;

          /* Product: '<S142>/Divide' */
          rtb_Divide_hw = rtb_P_f_idx_0 / FMS_ConstB.d_e;

          /* Signum: '<S142>/Sign5' incorporates:
           *  Signum: '<S142>/Sign6'
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Sign5_i = -1.0F;

            /* Signum: '<S142>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Sign5_i = 1.0F;

            /* Signum: '<S142>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Sign5_i = rtb_P_f_idx_0;

            /* Signum: '<S142>/Sign6' */
            rtb_Saturation_o4 = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S142>/Sign5' */

          /* Product: '<S139>/Multiply1' incorporates:
           *  Constant: '<S139>/const1'
           *  DiscreteIntegrator: '<S138>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_er * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S137>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S137>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S139>/Add' incorporates:
           *  DiscreteIntegrator: '<S138>/Integrator1'
           *  Gain: '<S120>/Gain1'
           *  Gain: '<S137>/Gain'
           *  Sum: '<S138>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_jl - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_P_f_idx_0;

          /* Signum: '<S139>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
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
          rtb_Sign5_p2 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_cb) *
                                FMS_ConstB.d_cb) - FMS_ConstB.d_cb) * 0.5F *
            rtb_Add4_pb + rtb_P_f_idx_0;

          /* Sum: '<S139>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_Sign5_p2) + rtb_P_f_idx_0;

          /* Sum: '<S139>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_cb;

          /* Sum: '<S139>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_cb;

          /* Signum: '<S139>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign1' */

          /* Signum: '<S139>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign2' */

          /* Sum: '<S139>/Add5' incorporates:
           *  Gain: '<S139>/Gain2'
           *  Product: '<S139>/Multiply4'
           *  Sum: '<S139>/Subtract2'
           */
          rtb_Sign5_p2 += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S139>/Add6' */
          rtb_Divide_lr_idx_2 = rtb_Sign5_p2 + FMS_ConstB.d_cb;

          /* Sum: '<S139>/Subtract3' */
          d = rtb_Sign5_p2 - FMS_ConstB.d_cb;

          /* Product: '<S139>/Divide' */
          rtb_Divide_pq = rtb_Sign5_p2 / FMS_ConstB.d_cb;

          /* Signum: '<S139>/Sign5' incorporates:
           *  Signum: '<S139>/Sign6'
           */
          if (rtb_Sign5_p2 < 0.0F) {
            rtb_Sign5_kq = -1.0F;

            /* Signum: '<S139>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Sign5_p2 > 0.0F) {
            rtb_Sign5_kq = 1.0F;

            /* Signum: '<S139>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Sign5_kq = rtb_Sign5_p2;

            /* Signum: '<S139>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_Sign5_p2;
          }

          /* End of Signum: '<S139>/Sign5' */

          /* Product: '<S136>/Multiply1' incorporates:
           *  Constant: '<S136>/const1'
           *  DiscreteIntegrator: '<S135>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S134>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S134>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S136>/Add' incorporates:
           *  DiscreteIntegrator: '<S135>/Integrator1'
           *  Gain: '<S119>/Gain'
           *  Gain: '<S134>/Gain'
           *  Sum: '<S135>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.FW_ROLL_LIM) +
            rtb_P_f_idx_0;

          /* Signum: '<S136>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_u_b;
          }

          /* End of Signum: '<S136>/Sign' */

          /* Sum: '<S136>/Add2' incorporates:
           *  Abs: '<S136>/Abs'
           *  Gain: '<S136>/Gain'
           *  Gain: '<S136>/Gain1'
           *  Product: '<S136>/Multiply2'
           *  Product: '<S136>/Multiply3'
           *  Sqrt: '<S136>/Sqrt'
           *  Sum: '<S136>/Add1'
           *  Sum: '<S136>/Subtract'
           */
          rtb_Sign5_p2 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_bi) *
                                FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Add4_pb + rtb_P_f_idx_0;

          /* Sum: '<S136>/Add4' */
          rtb_Add4_pb = (rtb_u_b - rtb_Sign5_p2) + rtb_P_f_idx_0;

          /* Sum: '<S136>/Add3' */
          rtb_P_f_idx_0 = rtb_u_b + FMS_ConstB.d_bi;

          /* Sum: '<S136>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_bi;

          /* Signum: '<S136>/Sign1' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S136>/Sign1' */

          /* Signum: '<S136>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S136>/Sign2' */

          /* Sum: '<S136>/Add5' incorporates:
           *  Gain: '<S136>/Gain2'
           *  Product: '<S136>/Multiply4'
           *  Sum: '<S136>/Subtract2'
           */
          rtb_Sign5_p2 += (rtb_P_f_idx_0 - rtb_u_b) * 0.5F * rtb_Add4_pb;

          /* Sum: '<S131>/Subtract3' */
          rtb_P_f_idx_0 = rtb_a_bx - FMS_ConstB.d_ar;

          /* Sum: '<S131>/Add6' */
          rtb_Add4_pb = rtb_a_bx + FMS_ConstB.d_ar;

          /* Signum: '<S131>/Sign5' incorporates:
           *  Signum: '<S131>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_u_b = -1.0F;

            /* Signum: '<S131>/Sign6' */
            y = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_u_b = 1.0F;

            /* Signum: '<S131>/Sign6' */
            y = 1.0F;
          } else {
            rtb_u_b = rtb_a_bx;

            /* Signum: '<S131>/Sign6' */
            y = rtb_a_bx;
          }

          /* End of Signum: '<S131>/Sign5' */

          /* Signum: '<S131>/Sign3' */
          if (rtb_Add4_pb < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else {
            if (rtb_Add4_pb > 0.0F) {
              rtb_Add4_pb = 1.0F;
            }
          }

          /* End of Signum: '<S131>/Sign3' */

          /* Signum: '<S131>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S131>/Sign4' */

          /* Update for DiscreteIntegrator: '<S126>/Integrator' incorporates:
           *  Constant: '<S131>/const'
           *  Gain: '<S131>/Gain3'
           *  Product: '<S131>/Divide'
           *  Product: '<S131>/Multiply5'
           *  Product: '<S131>/Multiply6'
           *  Sum: '<S131>/Subtract4'
           *  Sum: '<S131>/Subtract5'
           *  Sum: '<S131>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hd += ((rtb_a_bx / FMS_ConstB.d_ar - rtb_u_b)
            * FMS_ConstB.Gain4_am * ((rtb_Add4_pb - rtb_P_f_idx_0) * 0.5F) - y *
            78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S126>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_a += 0.004F * rtb_Integrator1_bx;

          /* Update for DiscreteIntegrator: '<S135>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S135>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S138>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S138>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jl += 0.004F * FMS_DW.Integrator_DSTATE_er;

          /* Update for DiscreteIntegrator: '<S141>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S141>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_n;

          /* Signum: '<S142>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S142>/Sign3' */

          /* Signum: '<S142>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S142>/Sign4' */

          /* Update for DiscreteIntegrator: '<S141>/Integrator' incorporates:
           *  Constant: '<S142>/const'
           *  Gain: '<S142>/Gain3'
           *  Product: '<S142>/Multiply5'
           *  Product: '<S142>/Multiply6'
           *  Sum: '<S142>/Subtract4'
           *  Sum: '<S142>/Subtract5'
           *  Sum: '<S142>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_n += ((rtb_Divide_hw - rtb_Sign5_i) *
            FMS_ConstB.Gain4_l * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 78.448F) * 0.004F;

          /* Signum: '<S139>/Sign3' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign3' */

          /* Signum: '<S139>/Sign4' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign4' */

          /* Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
           *  Constant: '<S139>/const'
           *  Gain: '<S139>/Gain3'
           *  Product: '<S139>/Multiply5'
           *  Product: '<S139>/Multiply6'
           *  Sum: '<S139>/Subtract4'
           *  Sum: '<S139>/Subtract5'
           *  Sum: '<S139>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_er += ((rtb_Divide_pq - rtb_Sign5_kq) *
            FMS_ConstB.Gain4_ci * ((rtb_Divide_lr_idx_2 - d) * 0.5F) -
            rtb_Divide_lr_idx_3 * 15.707963F) * 0.004F;

          /* Sum: '<S136>/Subtract3' */
          rtb_Saturation_ga = rtb_Sign5_p2 - FMS_ConstB.d_bi;

          /* Sum: '<S136>/Add6' */
          rtb_Saturation1_d = rtb_Sign5_p2 + FMS_ConstB.d_bi;

          /* Signum: '<S136>/Sign5' incorporates:
           *  Signum: '<S136>/Sign6'
           */
          if (rtb_Sign5_p2 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S136>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Sign5_p2 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S136>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Sign5_p2;

            /* Signum: '<S136>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_Sign5_p2;
          }

          /* End of Signum: '<S136>/Sign5' */

          /* Signum: '<S136>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S136>/Sign3' */

          /* Signum: '<S136>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S136>/Sign4' */

          /* Update for DiscreteIntegrator: '<S135>/Integrator' incorporates:
           *  Constant: '<S136>/const'
           *  Gain: '<S136>/Gain3'
           *  Product: '<S136>/Divide'
           *  Product: '<S136>/Multiply5'
           *  Product: '<S136>/Multiply6'
           *  Sum: '<S136>/Subtract4'
           *  Sum: '<S136>/Subtract5'
           *  Sum: '<S136>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_Sign5_p2 / FMS_ConstB.d_bi -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_d1 * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S109>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S109>/Position' incorporates:
             *  ActionPort: '<S115>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S109>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S151>/Integrator'
             *  DiscreteIntegrator: '<S151>/Integrator1'
             *  DiscreteIntegrator: '<S160>/Integrator'
             *  DiscreteIntegrator: '<S160>/Integrator1'
             *  DiscreteIntegrator: '<S209>/Integrator'
             *  DiscreteIntegrator: '<S209>/Integrator1'
             */
            FMS_DW.Integrator_DSTATE_c5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_i = 0.0F;
            FMS_DW.Integrator1_DSTATE_l5 = 0.0F;
            FMS_DW.Integrator1_DSTATE_nd = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S109>/Position' */

            /* SystemReset for IfAction SubSystem: '<S109>/Position' incorporates:
             *  ActionPort: '<S115>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S109>/Switch Case' incorporates:
             *  Chart: '<S148>/Motion Status'
             *  Chart: '<S163>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState);

            /* End of SystemReset for SubSystem: '<S109>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S109>/Position' incorporates:
           *  ActionPort: '<S115>/Action Port'
           */
          /* Trigonometry: '<S207>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S207>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S207>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S207>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S207>/Gain' incorporates:
           *  Gain: '<S206>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S207>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S207>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S207>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S207>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S207>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S148>/Motion Status' incorporates:
           *  Abs: '<S148>/Abs'
           *  Abs: '<S148>/Abs1'
           *  Constant: '<S157>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S157>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S163>/Multiply' incorporates:
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

          /* End of Product: '<S163>/Multiply' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S163>/Motion State' incorporates:
           *  Abs: '<S163>/Abs'
           *  Abs: '<S163>/Abs1'
           *  Abs: '<S163>/Abs2'
           *  Constant: '<S203>/Constant'
           *  Constant: '<S204>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Logic: '<S163>/Logical Operator'
           *  RelationalOperator: '<S203>/Compare'
           *  RelationalOperator: '<S204>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ)
                          || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
                              FMS_PARAM.YAW_DZ), fabsf(rtb_MatrixConcatenate1_0
            [0]), &rtb_state_fg, &FMS_DW.sf_MotionState);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S162>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S162>/Hold Control' incorporates:
               *  ActionPort: '<S164>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S162>/Switch Case' */
              FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_b,
                &FMS_DW.HoldControl_b);

              /* End of SystemReset for SubSystem: '<S162>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S162>/Hold Control' incorporates:
             *  ActionPort: '<S164>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_b(rtb_Divide_p3p, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                              FMS_U.INS_Out.vd, FMS_U.INS_Out.psi,
                              FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              &FMS_B.Merge_be, &FMS_ConstB.HoldControl_b,
                              &FMS_DW.HoldControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S162>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S162>/Move Control' incorporates:
             *  ActionPort: '<S165>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S200>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S200>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S165>/Gain6' incorporates:
             *  Gain: '<S200>/Gain'
             */
            FMS_B.Merge_be = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
              FMS_PARAM.FW_ACC_Y_LIM;

            /* End of Outputs for SubSystem: '<S162>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S162>/Switch Case' */

          /* SwitchCase: '<S147>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S147>/Hold Control' incorporates:
               *  ActionPort: '<S149>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S147>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S147>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S147>/Hold Control' incorporates:
             *  ActionPort: '<S149>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S147>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S147>/Move Control' incorporates:
               *  ActionPort: '<S150>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S147>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S147>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S147>/Move Control' incorporates:
             *  ActionPort: '<S150>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S147>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S147>/Switch Case' */

          /* DiscreteIntegrator: '<S151>/Integrator' */
          rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_c5;

          /* Product: '<S156>/Multiply1' incorporates:
           *  Constant: '<S156>/const1'
           *  DiscreteIntegrator: '<S151>/Integrator'
           */
          rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_c5 * 0.05F;

          /* Saturate: '<S147>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_u_b = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_u_b = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S147>/Saturation1' */

          /* Sum: '<S156>/Add' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  Sum: '<S151>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_i - rtb_u_b) +
            rtb_P_f_idx_0;

          /* Signum: '<S156>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
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
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_av) *
                            FMS_ConstB.d_av) - FMS_ConstB.d_av) * 0.5F *
            rtb_Saturation_ga + rtb_P_f_idx_0;

          /* Sum: '<S156>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_a_bx) + rtb_P_f_idx_0;

          /* Sum: '<S156>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_av;

          /* Sum: '<S156>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_av;

          /* Signum: '<S156>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign1' */

          /* Signum: '<S156>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign2' */

          /* Sum: '<S156>/Add5' incorporates:
           *  Gain: '<S156>/Gain2'
           *  Product: '<S156>/Multiply4'
           *  Sum: '<S156>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S115>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S115>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S115>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S160>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l5;

          /* Saturate: '<S146>/Saturation1' */
          if (FMS_DW.Integrator1_DSTATE_nd > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S115>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_nd < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S115>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S115>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_nd;
          }

          /* End of Saturate: '<S146>/Saturation1' */

          /* Saturate: '<S162>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S115>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S115>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S115>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S162>/Saturation1' */

          /* BusAssignment: '<S115>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_i;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S146>/Saturation' incorporates:
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

          /* End of Saturate: '<S146>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S210>/Multiply1' incorporates:
           *  Constant: '<S210>/const1'
           *  DiscreteIntegrator: '<S209>/Integrator'
           */
          rtb_u_b = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Switch: '<S208>/Switch' incorporates:
           *  Constant: '<S208>/Constant'
           *  Constant: '<S208>/Constant1'
           *  Constant: '<S208>/Constant2'
           *  Product: '<S208>/Multiply'
           *  Product: '<S208>/Multiply1'
           *  Sum: '<S208>/Subtract'
           *  Sum: '<S208>/Subtract1'
           *  Sum: '<S208>/Sum'
           *  Sum: '<S208>/Sum1'
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

          /* End of Switch: '<S208>/Switch' */

          /* Sum: '<S210>/Add' incorporates:
           *  DiscreteIntegrator: '<S209>/Integrator1'
           *  Sum: '<S209>/Subtract'
           */
          rtb_P_f_idx_0 = (FMS_DW.Integrator1_DSTATE_nd - rtb_Saturation_ga) +
            rtb_u_b;

          /* Signum: '<S210>/Sign' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_P_f_idx_0;
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
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_P_f_idx_0) +
            FMS_ConstB.d_ad) * FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F *
            rtb_Saturation_ga + rtb_u_b;

          /* Sum: '<S210>/Add4' */
          rtb_Saturation1_d = (rtb_P_f_idx_0 - rtb_Divide_lr_idx_2) + rtb_u_b;

          /* Sum: '<S210>/Add3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_ad;

          /* Sum: '<S210>/Subtract1' */
          rtb_P_f_idx_0 -= FMS_ConstB.d_ad;

          /* Signum: '<S210>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S210>/Sign1' */

          /* Signum: '<S210>/Sign2' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S210>/Sign2' */

          /* Sum: '<S210>/Add5' incorporates:
           *  Gain: '<S210>/Gain2'
           *  Product: '<S210>/Multiply4'
           *  Sum: '<S210>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S210>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ad;

          /* Sum: '<S210>/Subtract3' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 - FMS_ConstB.d_ad;

          /* Product: '<S210>/Divide' */
          rtb_Sign5_p2 = rtb_Divide_lr_idx_2 / FMS_ConstB.d_ad;

          /* Signum: '<S210>/Sign5' incorporates:
           *  Signum: '<S210>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_hw = -1.0F;

            /* Signum: '<S210>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_hw = 1.0F;

            /* Signum: '<S210>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Divide_hw = rtb_Divide_lr_idx_2;

            /* Signum: '<S210>/Sign6' */
            rtb_Saturation_o4 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S210>/Sign5' */

          /* Product: '<S161>/Multiply1' incorporates:
           *  Constant: '<S161>/const1'
           *  DiscreteIntegrator: '<S160>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S159>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S159>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S161>/Add' incorporates:
           *  DiscreteIntegrator: '<S160>/Integrator1'
           *  Gain: '<S144>/Gain1'
           *  Gain: '<S159>/Gain'
           *  Sum: '<S160>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_l5 - 1.0F / (1.0F -
                      FMS_PARAM.YAW_DZ) * rtb_u_b * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S161>/Sign' */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_u_b;
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
          rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_l) *
            FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Divide_lr_idx_3 +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S161>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_P_f_idx_0) + rtb_Divide_lr_idx_2;

          /* Sum: '<S161>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_l;

          /* Sum: '<S161>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_l;

          /* Signum: '<S161>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
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
          rtb_P_f_idx_0 += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S156>/Subtract3' */
          rtb_Divide_lr_idx_2 = rtb_a_bx - FMS_ConstB.d_av;

          /* Sum: '<S156>/Add6' */
          d = rtb_a_bx + FMS_ConstB.d_av;

          /* Signum: '<S156>/Sign5' incorporates:
           *  Signum: '<S156>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_u_b = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_u_b = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_a_bx;

            /* Signum: '<S156>/Sign6' */
            rtb_u_b = rtb_a_bx;
          }

          /* End of Signum: '<S156>/Sign5' */

          /* Signum: '<S156>/Sign3' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign3' */

          /* Signum: '<S156>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign4' */

          /* Update for DiscreteIntegrator: '<S151>/Integrator' incorporates:
           *  Constant: '<S156>/const'
           *  Gain: '<S156>/Gain3'
           *  Product: '<S156>/Divide'
           *  Product: '<S156>/Multiply5'
           *  Product: '<S156>/Multiply6'
           *  Sum: '<S156>/Subtract4'
           *  Sum: '<S156>/Subtract5'
           *  Sum: '<S156>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c5 += ((rtb_a_bx / FMS_ConstB.d_av -
            rtb_Divide_lr_idx_3) * FMS_ConstB.Gain4_p5 * ((d -
            rtb_Divide_lr_idx_2) * 0.5F) - rtb_u_b * 78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S151>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_i += 0.004F * rtb_Integrator1_bx;

          /* Update for DiscreteIntegrator: '<S160>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S160>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l5 += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S209>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S209>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S210>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S210>/Sign3' */

          /* Signum: '<S210>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S210>/Sign4' */

          /* Update for DiscreteIntegrator: '<S209>/Integrator' incorporates:
           *  Constant: '<S210>/const'
           *  Gain: '<S210>/Gain3'
           *  Product: '<S210>/Multiply5'
           *  Product: '<S210>/Multiply6'
           *  Sum: '<S210>/Subtract4'
           *  Sum: '<S210>/Subtract5'
           *  Sum: '<S210>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Sign5_p2 - rtb_Divide_hw) *
            FMS_ConstB.Gain4_f * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F)
            - rtb_Saturation_o4 * 78.448F) * 0.004F;

          /* Sum: '<S161>/Subtract3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 - FMS_ConstB.d_l;

          /* Sum: '<S161>/Add6' */
          rtb_Saturation1_d = rtb_P_f_idx_0 + FMS_ConstB.d_l;

          /* Signum: '<S161>/Sign5' incorporates:
           *  Signum: '<S161>/Sign6'
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S161>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S161>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_P_f_idx_0;

            /* Signum: '<S161>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S161>/Sign5' */

          /* Signum: '<S161>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign3' */

          /* Signum: '<S161>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign4' */

          /* Update for DiscreteIntegrator: '<S160>/Integrator' incorporates:
           *  Constant: '<S161>/const'
           *  Gain: '<S161>/Gain3'
           *  Product: '<S161>/Divide'
           *  Product: '<S161>/Multiply5'
           *  Product: '<S161>/Multiply6'
           *  Sum: '<S161>/Subtract4'
           *  Sum: '<S161>/Subtract5'
           *  Sum: '<S161>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_P_f_idx_0 / FMS_ConstB.d_l -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_ak * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 15.707963F) *
            0.004F;

          /* End of Outputs for SubSystem: '<S109>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S109>/Unknown' incorporates:
           *  ActionPort: '<S117>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S109>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S49>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S49>/Manual' incorporates:
         *  ActionPort: '<S111>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S111>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S111>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S111>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S253>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S253>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S253>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S254>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S254>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S111>/Gain'
         *  Gain: '<S254>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S255>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S255>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S255>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_u_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S256>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S256>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S256>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_u_b;

        /* End of Outputs for SubSystem: '<S49>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S49>/Unknown' incorporates:
         *  ActionPort: '<S113>/Action Port'
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
         *  DiscreteIntegrator: '<S103>/Integrator'
         *  DiscreteIntegrator: '<S103>/Integrator1'
         *  DiscreteIntegrator: '<S104>/Integrator'
         *  DiscreteIntegrator: '<S104>/Integrator1'
         *  DiscreteIntegrator: '<S105>/Integrator'
         *  DiscreteIntegrator: '<S105>/Integrator1'
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
         *  Chart: '<S54>/Motion State'
         */
        FMS_MotionState_Reset(&FMS_DW.sf_MotionState_j);

        /* End of SystemReset for SubSystem: '<S44>/BackwardTrans_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S44>/BackwardTrans_Mode' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* Trigonometry: '<S99>/Trigonometric Function1' */
      rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

      /* Trigonometry: '<S99>/Trigonometric Function' */
      rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

      /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S99>/Constant3'
       */
      rtb_VectorConcatenate_or[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S99>/Gain' incorporates:
       *  Gain: '<S98>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S43>/Signal Copy1'
       *  Trigonometry: '<S99>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Trigonometry: '<S99>/Trigonometric Function3' */
      rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

      /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S99>/Constant4'
       */
      rtb_VectorConcatenate_or[5] = 0.0F;

      /* SignalConversion: '<S99>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_du[0];
      rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_du[1];
      rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_du[2];

      /* Product: '<S54>/Multiply' incorporates:
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

      /* End of Product: '<S54>/Multiply' */

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Chart: '<S54>/Motion State' incorporates:
       *  Abs: '<S54>/Abs'
       *  Abs: '<S54>/Abs1'
       *  Abs: '<S54>/Abs2'
       *  Constant: '<S95>/Constant'
       *  Constant: '<S96>/Constant'
       *  Inport: '<Root>/Pilot_Cmd'
       *  Logic: '<S54>/Logical Operator'
       *  RelationalOperator: '<S95>/Compare'
       *  RelationalOperator: '<S96>/Compare'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ) ||
                      (fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ),
                      fabsf(rtb_MatrixConcatenate1_0[0]), &rtb_state_ej,
                      &FMS_DW.sf_MotionState_j);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SwitchCase: '<S53>/Switch Case' incorporates:
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
          /* SystemReset for IfAction SubSystem: '<S53>/Hold Control' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S53>/Switch Case' */
          FMS_HoldControl_g_Reset(&FMS_ConstB.HoldControl_p,
            &FMS_DW.HoldControl_p);

          /* End of SystemReset for SubSystem: '<S53>/Hold Control' */
        }

        /* Outputs for IfAction SubSystem: '<S53>/Hold Control' incorporates:
         *  ActionPort: '<S56>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_HoldControl_b(rtb_Divide_p3p, FMS_U.INS_Out.vn, FMS_U.INS_Out.ve,
                          FMS_U.INS_Out.vd, FMS_U.INS_Out.psi, FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, &FMS_B.Merge_n,
                          &FMS_ConstB.HoldControl_p, &FMS_DW.HoldControl_p);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S53>/Hold Control' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S53>/Brake Control' incorporates:
         *  ActionPort: '<S55>/Action Port'
         */
        /* SignalConversion: '<S55>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
         *  Constant: '<S55>/Brake Speed'
         */
        FMS_B.Merge_n = 0.0F;

        /* End of Outputs for SubSystem: '<S53>/Brake Control' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S53>/Move Control' incorporates:
         *  ActionPort: '<S57>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S92>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S92>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S57>/Gain6' incorporates:
         *  Gain: '<S92>/Gain'
         */
        FMS_B.Merge_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b *
          (FMS_PARAM.FW_ACC_Y_LIM / 2.0F);

        /* End of Outputs for SubSystem: '<S53>/Move Control' */
        break;
      }

      /* End of SwitchCase: '<S53>/Switch Case' */

      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  BusAssignment: '<S48>/Bus Assignment'
       *  Constant: '<S48>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S48>/Bus Assignment' incorporates:
       *  BusAssignment: '<S45>/Bus Assignment'
       *  Constant: '<S48>/Constant3'
       *  DiscreteIntegrator: '<S103>/Integrator1'
       *  DiscreteIntegrator: '<S104>/Integrator1'
       *  DiscreteIntegrator: '<S105>/Integrator1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_g;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_i;
      FMS_Y.FMS_Out.u_cmd = 0.0F;
      FMS_Y.FMS_Out.v_cmd = FMS_DW.Integrator1_DSTATE_l;
      FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_mb;
      FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_hf;

      /* Saturate: '<S53>/Saturation1' */
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

      /* End of Saturate: '<S53>/Saturation1' */

      /* Product: '<S107>/Multiply1' incorporates:
       *  Constant: '<S107>/const1'
       *  DiscreteIntegrator: '<S104>/Integrator'
       */
      rtb_Integrator1_bx = FMS_DW.Integrator_DSTATE_e * 0.02F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S102>/Dead Zone' incorporates:
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

      /* End of DeadZone: '<S102>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S107>/Add' incorporates:
       *  DiscreteIntegrator: '<S104>/Integrator1'
       *  Gain: '<S102>/Gain'
       *  Gain: '<S52>/Gain2'
       *  Sum: '<S104>/Subtract'
       */
      rtb_u_b = (FMS_DW.Integrator1_DSTATE_hf - 1.0F / (1.0F - FMS_PARAM.YAW_DZ)
                 * rtb_u_b * (FMS_PARAM.YAW_RATE_LIM / 2.0F)) +
        rtb_Integrator1_bx;

      /* Signum: '<S107>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_pq = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_pq = 1.0F;
      } else {
        rtb_Divide_pq = rtb_u_b;
      }

      /* End of Signum: '<S107>/Sign' */

      /* Sum: '<S107>/Add2' incorporates:
       *  Abs: '<S107>/Abs'
       *  Gain: '<S107>/Gain'
       *  Gain: '<S107>/Gain1'
       *  Product: '<S107>/Multiply2'
       *  Product: '<S107>/Multiply3'
       *  Sqrt: '<S107>/Sqrt'
       *  Sum: '<S107>/Add1'
       *  Sum: '<S107>/Subtract'
       */
      rtb_P_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_j) *
        FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Divide_pq +
        rtb_Integrator1_bx;

      /* Sum: '<S107>/Add4' */
      rtb_Saturation1_d = (rtb_u_b - rtb_P_f_idx_0) + rtb_Integrator1_bx;

      /* Sum: '<S107>/Add3' */
      rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_j;

      /* Sum: '<S107>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_j;

      /* Signum: '<S107>/Sign1' */
      if (rtb_Saturation_ga < 0.0F) {
        rtb_Saturation_ga = -1.0F;
      } else {
        if (rtb_Saturation_ga > 0.0F) {
          rtb_Saturation_ga = 1.0F;
        }
      }

      /* End of Signum: '<S107>/Sign1' */

      /* Signum: '<S107>/Sign2' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S107>/Sign2' */

      /* Sum: '<S107>/Add5' incorporates:
       *  Gain: '<S107>/Gain2'
       *  Product: '<S107>/Multiply4'
       *  Sum: '<S107>/Subtract2'
       */
      rtb_P_f_idx_0 += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

      /* Sum: '<S107>/Add6' */
      rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_j;

      /* Sum: '<S107>/Subtract3' */
      rtb_Saturation1_d = rtb_P_f_idx_0 - FMS_ConstB.d_j;

      /* Product: '<S107>/Divide' */
      rtb_a_bx = rtb_P_f_idx_0 / FMS_ConstB.d_j;

      /* Signum: '<S107>/Sign5' incorporates:
       *  Signum: '<S107>/Sign6'
       */
      if (rtb_P_f_idx_0 < 0.0F) {
        rtb_Sign5_p2 = -1.0F;

        /* Signum: '<S107>/Sign6' */
        rtb_Saturation_o4 = -1.0F;
      } else if (rtb_P_f_idx_0 > 0.0F) {
        rtb_Sign5_p2 = 1.0F;

        /* Signum: '<S107>/Sign6' */
        rtb_Saturation_o4 = 1.0F;
      } else {
        rtb_Sign5_p2 = rtb_P_f_idx_0;

        /* Signum: '<S107>/Sign6' */
        rtb_Saturation_o4 = rtb_P_f_idx_0;
      }

      /* End of Signum: '<S107>/Sign5' */

      /* Product: '<S108>/Multiply1' incorporates:
       *  Constant: '<S108>/const1'
       *  DiscreteIntegrator: '<S105>/Integrator'
       */
      rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_l * 0.1F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S100>/Dead Zone' incorporates:
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

      /* End of DeadZone: '<S100>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S108>/Add' incorporates:
       *  DiscreteIntegrator: '<S105>/Integrator1'
       *  Gain: '<S100>/Gain'
       *  Gain: '<S52>/Gain1'
       *  Sum: '<S105>/Subtract'
       */
      rtb_u_b = (FMS_DW.Integrator1_DSTATE_mb - 1.0F / (1.0F -
                  FMS_PARAM.THROTTLE_DZ) * rtb_u_b * (-FMS_PARAM.VEL_Z_LIM /
                  2.0F)) + rtb_P_f_idx_0;

      /* Signum: '<S108>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_pq = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_pq = 1.0F;
      } else {
        rtb_Divide_pq = rtb_u_b;
      }

      /* End of Signum: '<S108>/Sign' */

      /* Sum: '<S108>/Add2' incorporates:
       *  Abs: '<S108>/Abs'
       *  Gain: '<S108>/Gain'
       *  Gain: '<S108>/Gain1'
       *  Product: '<S108>/Multiply2'
       *  Product: '<S108>/Multiply3'
       *  Sqrt: '<S108>/Sqrt'
       *  Sum: '<S108>/Add1'
       *  Sum: '<S108>/Subtract'
       */
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_m2) *
        FMS_ConstB.d_m2) - FMS_ConstB.d_m2) * 0.5F * rtb_Divide_pq +
        rtb_P_f_idx_0;

      /* Sum: '<S108>/Add4' */
      rtb_Divide_lr_idx_3 = (rtb_u_b - rtb_Integrator1_bx) + rtb_P_f_idx_0;

      /* Sum: '<S108>/Add3' */
      rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_m2;

      /* Sum: '<S108>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_m2;

      /* Signum: '<S108>/Sign1' */
      if (rtb_Divide_lr_idx_2 < 0.0F) {
        rtb_Divide_lr_idx_2 = -1.0F;
      } else {
        if (rtb_Divide_lr_idx_2 > 0.0F) {
          rtb_Divide_lr_idx_2 = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign1' */

      /* Signum: '<S108>/Sign2' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign2' */

      /* Sum: '<S108>/Add5' incorporates:
       *  Gain: '<S108>/Gain2'
       *  Product: '<S108>/Multiply4'
       *  Sum: '<S108>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F *
        rtb_Divide_lr_idx_3;

      /* Sum: '<S108>/Add6' */
      rtb_Divide_lr_idx_2 = rtb_Integrator1_bx + FMS_ConstB.d_m2;

      /* Sum: '<S108>/Subtract3' */
      d = rtb_Integrator1_bx - FMS_ConstB.d_m2;

      /* Product: '<S108>/Divide' */
      rtb_Divide_hw = rtb_Integrator1_bx / FMS_ConstB.d_m2;

      /* Signum: '<S108>/Sign5' incorporates:
       *  Signum: '<S108>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Sign5_i = -1.0F;

        /* Signum: '<S108>/Sign6' */
        rtb_Divide_lr_idx_3 = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Sign5_i = 1.0F;

        /* Signum: '<S108>/Sign6' */
        rtb_Divide_lr_idx_3 = 1.0F;
      } else {
        rtb_Sign5_i = rtb_Integrator1_bx;

        /* Signum: '<S108>/Sign6' */
        rtb_Divide_lr_idx_3 = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S108>/Sign5' */

      /* Product: '<S106>/Multiply1' incorporates:
       *  Constant: '<S106>/const1'
       *  DiscreteIntegrator: '<S103>/Integrator'
       */
      rtb_P_f_idx_0 = FMS_DW.Integrator_DSTATE_oy * 0.1F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S101>/Dead Zone' incorporates:
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

      /* End of DeadZone: '<S101>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S106>/Add' incorporates:
       *  DiscreteIntegrator: '<S103>/Integrator1'
       *  Gain: '<S101>/Gain'
       *  Gain: '<S52>/Gain6'
       *  Sum: '<S103>/Subtract'
       */
      rtb_u_b = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F - FMS_PARAM.ROLL_DZ)
                 * rtb_u_b * (FMS_PARAM.VEL_XY_LIM / 2.0F)) + rtb_P_f_idx_0;

      /* Signum: '<S106>/Sign' */
      if (rtb_u_b < 0.0F) {
        rtb_Divide_pq = -1.0F;
      } else if (rtb_u_b > 0.0F) {
        rtb_Divide_pq = 1.0F;
      } else {
        rtb_Divide_pq = rtb_u_b;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_oj) *
        FMS_ConstB.d_oj) - FMS_ConstB.d_oj) * 0.5F * rtb_Divide_pq +
        rtb_P_f_idx_0;

      /* Sum: '<S106>/Add4' */
      rtb_Divide_pq = (rtb_u_b - rtb_Integrator1_bx) + rtb_P_f_idx_0;

      /* Sum: '<S106>/Add3' */
      rtb_P_f_idx_0 = rtb_u_b + FMS_ConstB.d_oj;

      /* Sum: '<S106>/Subtract1' */
      rtb_u_b -= FMS_ConstB.d_oj;

      /* Signum: '<S106>/Sign1' */
      if (rtb_P_f_idx_0 < 0.0F) {
        rtb_P_f_idx_0 = -1.0F;
      } else {
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_P_f_idx_0 = 1.0F;
        }
      }

      /* End of Signum: '<S106>/Sign1' */

      /* Signum: '<S106>/Sign2' */
      if (rtb_u_b < 0.0F) {
        rtb_u_b = -1.0F;
      } else {
        if (rtb_u_b > 0.0F) {
          rtb_u_b = 1.0F;
        }
      }

      /* End of Signum: '<S106>/Sign2' */

      /* Sum: '<S106>/Add5' incorporates:
       *  Gain: '<S106>/Gain2'
       *  Product: '<S106>/Multiply4'
       *  Sum: '<S106>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_P_f_idx_0 - rtb_u_b) * 0.5F * rtb_Divide_pq;

      /* Update for DiscreteIntegrator: '<S103>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S103>/Integrator'
       */
      FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_oy;

      /* Update for DiscreteIntegrator: '<S105>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S105>/Integrator'
       */
      FMS_DW.Integrator1_DSTATE_mb += 0.004F * FMS_DW.Integrator_DSTATE_l;

      /* Update for DiscreteIntegrator: '<S104>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S104>/Integrator'
       */
      FMS_DW.Integrator1_DSTATE_hf += 0.004F * FMS_DW.Integrator_DSTATE_e;

      /* Signum: '<S107>/Sign3' */
      if (rtb_Saturation_ga < 0.0F) {
        rtb_Saturation_ga = -1.0F;
      } else {
        if (rtb_Saturation_ga > 0.0F) {
          rtb_Saturation_ga = 1.0F;
        }
      }

      /* End of Signum: '<S107>/Sign3' */

      /* Signum: '<S107>/Sign4' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S107>/Sign4' */

      /* Update for DiscreteIntegrator: '<S104>/Integrator' incorporates:
       *  Constant: '<S107>/const'
       *  Gain: '<S107>/Gain3'
       *  Product: '<S107>/Multiply5'
       *  Product: '<S107>/Multiply6'
       *  Sum: '<S107>/Subtract4'
       *  Sum: '<S107>/Subtract5'
       *  Sum: '<S107>/Subtract6'
       */
      FMS_DW.Integrator_DSTATE_e += ((rtb_a_bx - rtb_Sign5_p2) *
        FMS_ConstB.Gain4_oc * ((rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F) -
        rtb_Saturation_o4 * 15.707963F) * 0.004F;

      /* Signum: '<S108>/Sign3' */
      if (rtb_Divide_lr_idx_2 < 0.0F) {
        rtb_Divide_lr_idx_2 = -1.0F;
      } else {
        if (rtb_Divide_lr_idx_2 > 0.0F) {
          rtb_Divide_lr_idx_2 = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign3' */

      /* Signum: '<S108>/Sign4' */
      if (d < 0.0F) {
        d = -1.0F;
      } else {
        if (d > 0.0F) {
          d = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign4' */

      /* Update for DiscreteIntegrator: '<S105>/Integrator' incorporates:
       *  Constant: '<S108>/const'
       *  Gain: '<S108>/Gain3'
       *  Product: '<S108>/Multiply5'
       *  Product: '<S108>/Multiply6'
       *  Sum: '<S108>/Subtract4'
       *  Sum: '<S108>/Subtract5'
       *  Sum: '<S108>/Subtract6'
       */
      FMS_DW.Integrator_DSTATE_l += ((rtb_Divide_hw - rtb_Sign5_i) *
        FMS_ConstB.Gain4_ht * ((rtb_Divide_lr_idx_2 - d) * 0.5F) -
        rtb_Divide_lr_idx_3 * 39.224F) * 0.004F;

      /* Sum: '<S106>/Subtract3' */
      rtb_Saturation_ga = rtb_Integrator1_bx - FMS_ConstB.d_oj;

      /* Sum: '<S106>/Add6' */
      rtb_Saturation1_d = rtb_Integrator1_bx + FMS_ConstB.d_oj;

      /* Signum: '<S106>/Sign5' incorporates:
       *  Signum: '<S106>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Saturation_o4 = -1.0F;

        /* Signum: '<S106>/Sign6' */
        rtb_Divide_lr_idx_3 = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Saturation_o4 = 1.0F;

        /* Signum: '<S106>/Sign6' */
        rtb_Divide_lr_idx_3 = 1.0F;
      } else {
        rtb_Saturation_o4 = rtb_Integrator1_bx;

        /* Signum: '<S106>/Sign6' */
        rtb_Divide_lr_idx_3 = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S106>/Sign5' */

      /* Signum: '<S106>/Sign3' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S106>/Sign3' */

      /* Signum: '<S106>/Sign4' */
      if (rtb_Saturation_ga < 0.0F) {
        rtb_Saturation_ga = -1.0F;
      } else {
        if (rtb_Saturation_ga > 0.0F) {
          rtb_Saturation_ga = 1.0F;
        }
      }

      /* End of Signum: '<S106>/Sign4' */

      /* Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
       *  Constant: '<S106>/const'
       *  Gain: '<S106>/Gain3'
       *  Product: '<S106>/Divide'
       *  Product: '<S106>/Multiply5'
       *  Product: '<S106>/Multiply6'
       *  Sum: '<S106>/Subtract4'
       *  Sum: '<S106>/Subtract5'
       *  Sum: '<S106>/Subtract6'
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
          /* Disable for SwitchCase: '<S327>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S727>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S717>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S666>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S645>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S325>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S436>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S487>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S477>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S436>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S324>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S423>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S339>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S357>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S373>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S398>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S385>/Switch Case' */
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
         *  ActionPort: '<S327>/Action Port'
         */
        /* SwitchCase: '<S327>/Switch Case' incorporates:
         *  Math: '<S749>/Math Function'
         *  Sum: '<S711>/Subtract'
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
            /* Disable for SwitchCase: '<S727>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S717>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S666>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S645>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S327>/Takeoff' incorporates:
             *  ActionPort: '<S629>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S327>/Switch Case' incorporates:
             *  Delay: '<S767>/cur_waypoint'
             *  DiscreteIntegrator: '<S763>/Integrator'
             *  DiscreteIntegrator: '<S763>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S327>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S327>/Takeoff' incorporates:
           *  ActionPort: '<S629>/Action Port'
           */
          /* Delay: '<S767>/cur_waypoint' incorporates:
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
          /* Product: '<S767>/Divide' incorporates:
           *  Delay: '<S767>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S767>/Sum1'
           *  Sum: '<S767>/Sum2'
           */
          rtb_Saturation_o4 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S767>/Saturation' */
          if (rtb_Saturation_o4 > 1.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_o4 = 0.0F;
            }
          }

          /* End of Saturate: '<S767>/Saturation' */

          /* Trigonometry: '<S768>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S768>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S768>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S768>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S768>/Gain' incorporates:
           *  Gain: '<S766>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S768>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S768>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S768>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S768>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S768>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S760>/Saturation1' */
          rtb_Saturation_ga = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Saturation1_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S760>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S767>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S767>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S760>/Sum'
           *  Sum: '<S767>/Sum3'
           *  Sum: '<S767>/Sum4'
           */
          d = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0]) *
               rtb_Saturation_o4 + FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_o4 +
                                FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S760>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d;
          }

          /* Saturate: '<S760>/Saturation1' incorporates:
           *  Gain: '<S760>/Gain2'
           *  Product: '<S760>/Multiply'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S629>/Bus Assignment1'
           *  Constant: '<S629>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S629>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S760>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_ga) {
            /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_ga;
          } else if (rtb_u_b < rtb_Saturation1_d) {
            /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Divide_lr_idx_2 > rtb_Saturation_ga) {
            /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_ga;
          } else if (rtb_Divide_lr_idx_2 < rtb_Saturation1_d) {
            /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation1_d;
          } else {
            /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_2;
          }

          /* BusAssignment: '<S629>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S763>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S764>/Multiply1' incorporates:
           *  Constant: '<S764>/const1'
           *  DiscreteIntegrator: '<S763>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S759>/Switch' incorporates:
           *  Abs: '<S759>/Abs'
           *  Abs: '<S759>/Abs1'
           *  Constant: '<S759>/Takeoff_Speed'
           *  Constant: '<S761>/Constant'
           *  Constant: '<S762>/Constant'
           *  Gain: '<S759>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S759>/Logical Operator'
           *  RelationalOperator: '<S761>/Compare'
           *  RelationalOperator: '<S762>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S759>/Sum'
           *  Sum: '<S759>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_u_b = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_u_b = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S759>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S764>/Add' incorporates:
           *  DiscreteIntegrator: '<S763>/Integrator1'
           *  Sum: '<S763>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_f - rtb_u_b) +
            rtb_Saturation_o4;

          /* Signum: '<S764>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S764>/Sign' */

          /* Sum: '<S764>/Add2' incorporates:
           *  Abs: '<S764>/Abs'
           *  Gain: '<S764>/Gain'
           *  Gain: '<S764>/Gain1'
           *  Product: '<S764>/Multiply2'
           *  Product: '<S764>/Multiply3'
           *  Sqrt: '<S764>/Sqrt'
           *  Sum: '<S764>/Add1'
           *  Sum: '<S764>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_b) *
                           FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S764>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S764>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Sum: '<S764>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_b;

          /* Signum: '<S764>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S764>/Sign1' */

          /* Signum: '<S764>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S764>/Sign2' */

          /* Sum: '<S764>/Add5' incorporates:
           *  Gain: '<S764>/Gain2'
           *  Product: '<S764>/Multiply4'
           *  Sum: '<S764>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S767>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S763>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S763>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S764>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_b;

          /* Sum: '<S764>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_b;

          /* Signum: '<S764>/Sign5' incorporates:
           *  Signum: '<S764>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S764>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S764>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S764>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S764>/Sign5' */

          /* Signum: '<S764>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S764>/Sign3' */

          /* Signum: '<S764>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S764>/Sign4' */

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
          FMS_DW.Integrator_DSTATE_k += ((rtb_u_b / FMS_ConstB.d_b -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_i * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S327>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S327>/Land' incorporates:
             *  ActionPort: '<S627>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S327>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S682>/Integrator'
             *  DiscreteIntegrator: '<S682>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S327>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S327>/Land' incorporates:
           *  ActionPort: '<S627>/Action Port'
           */
          /* Trigonometry: '<S687>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S687>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

          /* SignalConversion: '<S687>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S687>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S687>/Gain' incorporates:
           *  Gain: '<S686>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S687>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S687>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S687>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S687>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S687>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S680>/Saturation1' */
          rtb_Saturation_o4 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Divide_lr_idx_3 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S684>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S684>/Sum'
           */
          d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S684>/Multiply' incorporates:
           *  SignalConversion: '<S684>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S684>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d;
          }

          /* End of Product: '<S684>/Multiply' */

          /* Saturate: '<S680>/Saturation1' incorporates:
           *  Gain: '<S684>/Gain2'
           */
          rtb_u_b = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S627>/Bus Assignment1'
           *  Constant: '<S627>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S627>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S680>/Saturation1' */
          if (rtb_u_b > rtb_Saturation_o4) {
            /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_o4;
          } else if (rtb_u_b < rtb_Divide_lr_idx_3) {
            /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_lr_idx_3;
          } else {
            /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_u_b;
          }

          if (rtb_Divide_lr_idx_2 > rtb_Saturation_o4) {
            /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Saturation_o4;
          } else if (rtb_Divide_lr_idx_2 < rtb_Divide_lr_idx_3) {
            /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_3;
          } else {
            /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_2;
          }

          /* BusAssignment: '<S627>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S682>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S683>/Multiply1' incorporates:
           *  Constant: '<S683>/const1'
           *  DiscreteIntegrator: '<S682>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S679>/Switch' incorporates:
           *  Constant: '<S679>/Land_Speed'
           *  Constant: '<S681>/Constant'
           *  Gain: '<S679>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S679>/Logical Operator'
           *  RelationalOperator: '<S681>/Compare'
           *  S-Function (sfix_bitop): '<S679>/cmd_p valid'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_u_b = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_u_b = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S679>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S683>/Add' incorporates:
           *  DiscreteIntegrator: '<S682>/Integrator1'
           *  Sum: '<S682>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_g - rtb_u_b) +
            rtb_Saturation_ga;

          /* Signum: '<S683>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S683>/Sign' */

          /* Sum: '<S683>/Add2' incorporates:
           *  Abs: '<S683>/Abs'
           *  Gain: '<S683>/Gain'
           *  Gain: '<S683>/Gain1'
           *  Product: '<S683>/Multiply2'
           *  Product: '<S683>/Multiply3'
           *  Sqrt: '<S683>/Sqrt'
           *  Sum: '<S683>/Add1'
           *  Sum: '<S683>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_om) *
                           FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S683>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S683>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Sum: '<S683>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_om;

          /* Signum: '<S683>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S683>/Sign1' */

          /* Signum: '<S683>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S683>/Sign2' */

          /* Sum: '<S683>/Add5' incorporates:
           *  Gain: '<S683>/Gain2'
           *  Product: '<S683>/Multiply4'
           *  Sum: '<S683>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for DiscreteIntegrator: '<S682>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S682>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S683>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_om;

          /* Sum: '<S683>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_om;

          /* Signum: '<S683>/Sign5' incorporates:
           *  Signum: '<S683>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S683>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S683>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S683>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S683>/Sign5' */

          /* Signum: '<S683>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S683>/Sign3' */

          /* Signum: '<S683>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S683>/Sign4' */

          /* Update for DiscreteIntegrator: '<S682>/Integrator' incorporates:
           *  Constant: '<S683>/const'
           *  Gain: '<S683>/Gain3'
           *  Product: '<S683>/Divide'
           *  Product: '<S683>/Multiply5'
           *  Product: '<S683>/Multiply6'
           *  Sum: '<S683>/Subtract4'
           *  Sum: '<S683>/Subtract5'
           *  Sum: '<S683>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_u_b / FMS_ConstB.d_om -
            rtb_Saturation_o4) * FMS_ConstB.Gain4_p * ((rtb_Saturation1_d -
            rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S327>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S327>/Return' incorporates:
             *  ActionPort: '<S628>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S327>/Switch Case' incorporates:
             *  Delay: '<S691>/Delay'
             *  Delay: '<S712>/Delay'
             *  DiscreteIntegrator: '<S694>/Integrator'
             *  DiscreteIntegrator: '<S694>/Integrator1'
             *  DiscreteIntegrator: '<S708>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S713>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S754>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S327>/Return' */

            /* SystemReset for IfAction SubSystem: '<S327>/Return' incorporates:
             *  ActionPort: '<S628>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S327>/Switch Case' incorporates:
             *  Chart: '<S718>/Motion Status'
             *  Chart: '<S728>/Motion State'
             */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S327>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S327>/Return' incorporates:
           *  ActionPort: '<S628>/Action Port'
           */
          /* Delay: '<S712>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S707>/Compare' incorporates:
           *  Constant: '<S758>/Constant'
           *  DiscreteIntegrator: '<S713>/Discrete-Time Integrator'
           *  RelationalOperator: '<S758>/Compare'
           */
          rtb_Compare_o3 = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S708>/Acceleration_Speed' */
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
          /* Chart: '<S728>/Motion State' incorporates:
           *  Constant: '<S728>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S728>/Square'
           *  Math: '<S728>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S728>/Sqrt'
           *  Sum: '<S728>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S727>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S727>/Hold Control' incorporates:
               *  ActionPort: '<S730>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S727>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S727>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S727>/Hold Control' incorporates:
             *  ActionPort: '<S730>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S727>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S727>/Brake Control' incorporates:
             *  ActionPort: '<S729>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S727>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S727>/Move Control' incorporates:
               *  ActionPort: '<S731>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S727>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S727>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S727>/Move Control' incorporates:
             *  ActionPort: '<S731>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S727>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S727>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S718>/Motion Status' incorporates:
           *  Abs: '<S718>/Abs'
           *  Constant: '<S718>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S717>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S717>/Hold Control' incorporates:
               *  ActionPort: '<S720>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S717>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S717>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S717>/Hold Control' incorporates:
             *  ActionPort: '<S720>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S717>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S717>/Brake Control' incorporates:
             *  ActionPort: '<S719>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S717>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S717>/Move Control' incorporates:
               *  ActionPort: '<S721>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S717>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_cg);

              /* End of SystemReset for SubSystem: '<S717>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S717>/Move Control' incorporates:
             *  ActionPort: '<S721>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_cg, &FMS_DW.MoveControl_cg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S717>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S717>/Switch Case' */

          /* Switch: '<S689>/Switch' incorporates:
           *  Product: '<S712>/Multiply'
           *  Sum: '<S712>/Sum'
           */
          if (rtb_Compare_o3) {
            /* Saturate: '<S727>/Saturation1' */
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

            /* End of Saturate: '<S727>/Saturation1' */

            /* Saturate: '<S717>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S717>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S712>/Sum' incorporates:
             *  Delay: '<S712>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S755>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_lr_idx_3;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S708>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_o4 = rtb_Divide_lr_idx_3;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S712>/Sum' incorporates:
             *  Delay: '<S712>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S708>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S714>/Sqrt' incorporates:
             *  Math: '<S714>/Square'
             *  Sum: '<S708>/Sum'
             *  Sum: '<S714>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
                            rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S757>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S757>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S757>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S756>/Gain' incorporates:
             *  DiscreteIntegrator: '<S754>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S754>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S757>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S757>/Trigonometric Function1'
             */
            rtb_Saturation_ga = arm_cos_f32(rtb_Saturation1_d);
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Trigonometry: '<S757>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S757>/Trigonometric Function'
             */
            rtb_Saturation1_d = arm_sin_f32(rtb_Saturation1_d);

            /* Gain: '<S757>/Gain' incorporates:
             *  Trigonometry: '<S757>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -rtb_Saturation1_d;

            /* SignalConversion: '<S757>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S757>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S757>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S757>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* Switch: '<S708>/Switch' incorporates:
             *  Constant: '<S708>/vel'
             */
            if (rtb_u_b > FMS_PARAM.L1) {
              rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S708>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_u_b;

              /* Saturate: '<S708>/Saturation' */
              if (rtb_Saturation1_d > FMS_PARAM.CRUISE_SPEED) {
                rtb_Saturation1_d = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Saturate: '<S708>/Saturation' */
            }

            /* End of Switch: '<S708>/Switch' */

            /* Switch: '<S708>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S708>/Acceleration_Speed'
             *  Sum: '<S708>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S708>/Switch1' */

            /* Sum: '<S755>/Sum of Elements' incorporates:
             *  Math: '<S755>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Divide_lr_idx_3 *
              rtb_Divide_lr_idx_3;

            /* Math: '<S755>/Math Function1' incorporates:
             *  Sum: '<S755>/Sum of Elements'
             *
             * About '<S755>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_Saturation_ga = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S755>/Math Function1' */

            /* Switch: '<S755>/Switch' incorporates:
             *  Constant: '<S755>/Constant'
             *  Product: '<S755>/Product'
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

            /* End of Switch: '<S755>/Switch' */

            /* Product: '<S753>/Multiply2' incorporates:
             *  Product: '<S755>/Divide'
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

          /* End of Switch: '<S689>/Switch' */

          /* Delay: '<S691>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S694>/Integrator1' incorporates:
           *  Delay: '<S691>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S698>/Rem' incorporates:
           *  Constant: '<S698>/Constant1'
           *  DiscreteIntegrator: '<S694>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S693>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S698>/Switch' incorporates:
           *  Abs: '<S698>/Abs'
           *  Constant: '<S698>/Constant'
           *  Constant: '<S699>/Constant'
           *  Product: '<S698>/Multiply'
           *  RelationalOperator: '<S699>/Compare'
           *  Sum: '<S698>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S698>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S698>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S698>/Switch' */

          /* Gain: '<S693>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S693>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S693>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S628>/Bus Assignment1'
           *  Constant: '<S628>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S628>/Bus Assignment1' incorporates:
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

          /* Math: '<S748>/Math Function1'
           *
           * About '<S748>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S748>/Math Function1' */

          /* Switch: '<S748>/Switch' incorporates:
           *  Constant: '<S748>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S748>/Product'
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

          /* End of Switch: '<S748>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S628>/Sum' incorporates:
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

          /* SignalConversion: '<S705>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S628>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S705>/Math Function' incorporates:
           *  Sum: '<S628>/Sum'
           */
          rtb_Square_ds[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_ds[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S705>/Sum of Elements' */
          rtb_u_b = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S705>/Math Function1' incorporates:
           *  Sum: '<S705>/Sum of Elements'
           *
           * About '<S705>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S705>/Math Function1' */

          /* Switch: '<S705>/Switch' incorporates:
           *  Constant: '<S705>/Constant'
           *  Product: '<S705>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Integrator1_bx = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S705>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S710>/NearbyRefWP' incorporates:
           *  Constant: '<S628>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_c14,
                          &rtb_u_b);

          /* MATLAB Function: '<S710>/SearchL1RefWP' incorporates:
           *  Constant: '<S628>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S710>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S710>/Switch1' incorporates:
           *  Constant: '<S741>/Constant'
           *  RelationalOperator: '<S741>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_c14[0];
            rtb_P_ap[1] = rtb_Divide_c14[1];
          } else {
            /* RelationalOperator: '<S740>/Compare' incorporates:
             *  Constant: '<S740>/Constant'
             */
            rtb_Compare_aij = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S710>/Switch' */
            if (!rtb_Compare_aij) {
              rtb_P_ap[0] = rtb_Square_ds[0];
              rtb_P_ap[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S710>/Switch' */
          }

          /* End of Switch: '<S710>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S711>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Divide_lr_idx_3;
          rtb_Subtract_hb[0] = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S711>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S749>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S749>/Sum of Elements' incorporates:
           *  Math: '<S749>/Math Function'
           *  Sum: '<S747>/Sum of Elements'
           */
          rtb_u_b = rtb_Subtract_hb[0] + rtb_Divide_lr_idx_3 *
            rtb_Divide_lr_idx_3;

          /* Math: '<S749>/Math Function1' incorporates:
           *  Sum: '<S749>/Sum of Elements'
           *
           * About '<S749>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S749>/Math Function1' */

          /* Switch: '<S749>/Switch' incorporates:
           *  Constant: '<S749>/Constant'
           *  Product: '<S749>/Product'
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

          /* End of Switch: '<S749>/Switch' */

          /* Product: '<S748>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S751>/Sum of Elements' incorporates:
           *  Math: '<S751>/Math Function'
           *  SignalConversion: '<S751>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S751>/Math Function1' incorporates:
           *  Sum: '<S751>/Sum of Elements'
           *
           * About '<S751>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S751>/Math Function1' */

          /* Switch: '<S751>/Switch' incorporates:
           *  Constant: '<S751>/Constant'
           *  Product: '<S751>/Product'
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

          /* End of Switch: '<S751>/Switch' */

          /* Product: '<S749>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S752>/Sum of Elements' incorporates:
           *  Math: '<S752>/Math Function'
           *  SignalConversion: '<S752>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S752>/Math Function1' incorporates:
           *  Sum: '<S752>/Sum of Elements'
           *
           * About '<S752>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S752>/Math Function1' */

          /* Switch: '<S752>/Switch' incorporates:
           *  Constant: '<S752>/Constant'
           *  Product: '<S752>/Product'
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

          /* End of Switch: '<S752>/Switch' */

          /* Product: '<S752>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S751>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S705>/Divide' */
          rtb_Square_ds[0] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S752>/Divide' */
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S751>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S705>/Divide' */
          rtb_Square_ds[1] = rtb_Saturation1_d / rtb_Integrator1_bx;

          /* Sum: '<S750>/Subtract' incorporates:
           *  Product: '<S750>/Multiply'
           *  Product: '<S750>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_c14[0] * rtb_P_ap[1] - rtb_Divide_c14[1]
            * rtb_P_ap[0];

          /* Signum: '<S745>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S745>/Sign1' */

          /* Switch: '<S745>/Switch2' incorporates:
           *  Constant: '<S745>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S745>/Switch2' */

          /* DotProduct: '<S745>/Dot Product' */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] * rtb_Divide_c14[0] + rtb_P_ap[1] *
            rtb_Divide_c14[1];

          /* Trigonometry: '<S745>/Acos' incorporates:
           *  DotProduct: '<S745>/Dot Product'
           */
          if (rtb_Divide_lr_idx_3 > 1.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 < -1.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            }
          }

          /* Product: '<S745>/Multiply' incorporates:
           *  Trigonometry: '<S745>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Divide_lr_idx_3);

          /* Saturate: '<S711>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S711>/Saturation' */

          /* Product: '<S711>/Divide' incorporates:
           *  Constant: '<S628>/L1'
           *  Constant: '<S711>/Constant'
           *  Gain: '<S711>/Gain'
           *  Math: '<S711>/Square'
           *  MinMax: '<S711>/Max'
           *  MinMax: '<S711>/Min'
           *  Product: '<S711>/Multiply1'
           *  Sqrt: '<S747>/Sqrt'
           *  Trigonometry: '<S711>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S703>/Subtract' incorporates:
           *  Product: '<S703>/Multiply'
           *  Product: '<S703>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S692>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S692>/Sign1' */

          /* Switch: '<S692>/Switch2' incorporates:
           *  Constant: '<S692>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S692>/Switch2' */

          /* DotProduct: '<S692>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide_m[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S692>/Acos' incorporates:
           *  DotProduct: '<S692>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S692>/Multiply' incorporates:
           *  Trigonometry: '<S692>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_u_b);

          /* Math: '<S695>/Rem' incorporates:
           *  Constant: '<S695>/Constant1'
           *  Delay: '<S691>/Delay'
           *  Sum: '<S691>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S695>/Switch' incorporates:
           *  Abs: '<S695>/Abs'
           *  Constant: '<S695>/Constant'
           *  Constant: '<S701>/Constant'
           *  Product: '<S695>/Multiply'
           *  RelationalOperator: '<S701>/Compare'
           *  Sum: '<S695>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S695>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S695>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S695>/Switch' */

          /* Sum: '<S691>/Sum' incorporates:
           *  Delay: '<S691>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S700>/Multiply1' incorporates:
           *  Constant: '<S700>/const1'
           *  DiscreteIntegrator: '<S694>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S700>/Add' incorporates:
           *  DiscreteIntegrator: '<S694>/Integrator1'
           *  Sum: '<S694>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S700>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
          }

          /* End of Signum: '<S700>/Sign' */

          /* Sum: '<S700>/Add2' incorporates:
           *  Abs: '<S700>/Abs'
           *  Gain: '<S700>/Gain'
           *  Gain: '<S700>/Gain1'
           *  Product: '<S700>/Multiply2'
           *  Product: '<S700>/Multiply3'
           *  Sqrt: '<S700>/Sqrt'
           *  Sum: '<S700>/Add1'
           *  Sum: '<S700>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_n) *
                           FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S700>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S700>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_n;

          /* Sum: '<S700>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_n;

          /* Signum: '<S700>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S700>/Sign1' */

          /* Signum: '<S700>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S700>/Sign2' */

          /* Sum: '<S700>/Add5' incorporates:
           *  Gain: '<S700>/Gain2'
           *  Product: '<S700>/Multiply4'
           *  Sum: '<S700>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S700>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_n;

          /* Sum: '<S700>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_n;

          /* Product: '<S700>/Divide' */
          d = rtb_u_b / FMS_ConstB.d_n;

          /* Signum: '<S700>/Sign5' incorporates:
           *  Signum: '<S700>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S700>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S700>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = rtb_u_b;

            /* Signum: '<S700>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S700>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S691>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S696>/Rem' incorporates:
           *  Constant: '<S696>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S696>/Switch' incorporates:
           *  Abs: '<S696>/Abs'
           *  Constant: '<S696>/Constant'
           *  Constant: '<S702>/Constant'
           *  Product: '<S696>/Multiply'
           *  RelationalOperator: '<S702>/Compare'
           *  Sum: '<S696>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S696>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_u_b;
            }

            /* End of Signum: '<S696>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S696>/Switch' */

          /* Abs: '<S689>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S712>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S713>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S706>/Constant'
           *  RelationalOperator: '<S706>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S713>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S708>/Acceleration_Speed' incorporates:
           *  Constant: '<S708>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S708>/Acceleration_Speed' */

          /* Product: '<S712>/Divide1' incorporates:
           *  Constant: '<S712>/Constant'
           */
          rtb_u_b = rtb_Divide_lr_idx_2 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S712>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S712>/Saturation' */

          /* Update for DiscreteIntegrator: '<S754>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_u_b;

          /* Update for Delay: '<S691>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S694>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S694>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S700>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S700>/Sign3' */

          /* Signum: '<S700>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S700>/Sign4' */

          /* Update for DiscreteIntegrator: '<S694>/Integrator' incorporates:
           *  Constant: '<S700>/const'
           *  Gain: '<S700>/Gain3'
           *  Product: '<S700>/Multiply5'
           *  Product: '<S700>/Multiply6'
           *  Sum: '<S700>/Subtract4'
           *  Sum: '<S700>/Subtract5'
           *  Sum: '<S700>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S694>/Integrator' */
          /* End of Outputs for SubSystem: '<S327>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S327>/Hold' incorporates:
             *  ActionPort: '<S626>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S327>/Switch Case' incorporates:
             *  Delay: '<S647>/Delay'
             *  DiscreteIntegrator: '<S659>/Integrator'
             *  DiscreteIntegrator: '<S659>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S327>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S327>/Hold' incorporates:
             *  ActionPort: '<S626>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S327>/Switch Case' incorporates:
             *  Chart: '<S635>/Motion Status'
             *  Chart: '<S646>/Motion State'
             *  Chart: '<S667>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S327>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S327>/Hold' incorporates:
           *  ActionPort: '<S626>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S635>/Motion Status' incorporates:
           *  Abs: '<S635>/Abs'
           *  Constant: '<S635>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S646>/Motion State' incorporates:
           *  Abs: '<S646>/Abs'
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

          /* End of Chart: '<S646>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S667>/Motion State' incorporates:
           *  Constant: '<S667>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S667>/Square'
           *  Math: '<S667>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S667>/Sqrt'
           *  Sum: '<S667>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                            &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S666>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S666>/Hold Control' incorporates:
               *  ActionPort: '<S669>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S666>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S666>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S666>/Hold Control' incorporates:
             *  ActionPort: '<S669>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S666>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S666>/Brake Control' incorporates:
             *  ActionPort: '<S668>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S666>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S666>/Move Control' incorporates:
               *  ActionPort: '<S670>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S666>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S666>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S666>/Move Control' incorporates:
             *  ActionPort: '<S670>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S666>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S666>/Switch Case' */

          /* SwitchCase: '<S634>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S634>/Hold Control' incorporates:
               *  ActionPort: '<S637>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S634>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S634>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S634>/Hold Control' incorporates:
             *  ActionPort: '<S637>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S634>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S634>/Brake Control' incorporates:
             *  ActionPort: '<S636>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S634>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S634>/Move Control' incorporates:
               *  ActionPort: '<S638>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S634>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S634>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S634>/Move Control' incorporates:
             *  ActionPort: '<S638>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S634>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S634>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S644>/Compare' incorporates:
           *  Constant: '<S644>/Constant'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Compare_o3 = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S647>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S659>/Integrator1' incorporates:
           *  Delay: '<S647>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_Compare_o3 || (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S645>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S645>/Hold Control' incorporates:
               *  ActionPort: '<S649>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S645>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S645>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S645>/Hold Control' incorporates:
             *  ActionPort: '<S649>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S645>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S645>/Brake Control' incorporates:
             *  ActionPort: '<S648>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S645>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S645>/Move Control' incorporates:
               *  ActionPort: '<S650>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S645>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S645>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S645>/Move Control' incorporates:
             *  ActionPort: '<S650>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S645>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S645>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S632>/Switch' incorporates:
           *  Saturate: '<S645>/Saturation'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S662>/Rem' incorporates:
             *  Constant: '<S662>/Constant1'
             *  DiscreteIntegrator: '<S659>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S658>/Sum'
             */
            rtb_Saturation_ga = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S662>/Switch' incorporates:
             *  Abs: '<S662>/Abs'
             *  Constant: '<S662>/Constant'
             *  Constant: '<S663>/Constant'
             *  Product: '<S662>/Multiply'
             *  RelationalOperator: '<S663>/Compare'
             *  Sum: '<S662>/Add'
             */
            if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
              /* Signum: '<S662>/Sign' */
              if (rtb_Saturation_ga < 0.0F) {
                rtb_Saturation1_d = -1.0F;
              } else if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              } else {
                rtb_Saturation1_d = rtb_Saturation_ga;
              }

              /* End of Signum: '<S662>/Sign' */
              rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
            }

            /* End of Switch: '<S662>/Switch' */

            /* Gain: '<S658>/Gain2' */
            rtb_Saturation_ga *= FMS_PARAM.YAW_P;

            /* Saturate: '<S658>/Saturation' */
            if (rtb_Saturation_ga > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Saturation_ga < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S658>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S645>/Saturation' */
            rtb_Saturation_ga = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S645>/Saturation' */
            rtb_Saturation_ga = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S645>/Saturation' */
            rtb_Saturation_ga = FMS_B.Merge_h;
          }

          /* End of Switch: '<S632>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  BusAssignment: '<S626>/Bus Assignment'
           *  Constant: '<S626>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S626>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_ga;

          /* Saturate: '<S666>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S666>/Saturation1' */

          /* Saturate: '<S634>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S626>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S634>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S660>/Rem' incorporates:
           *  Constant: '<S660>/Constant1'
           *  Delay: '<S647>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S647>/Sum2'
           */
          rtb_Saturation_ga = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S660>/Switch' incorporates:
           *  Abs: '<S660>/Abs'
           *  Constant: '<S660>/Constant'
           *  Constant: '<S665>/Constant'
           *  Product: '<S660>/Multiply'
           *  RelationalOperator: '<S665>/Compare'
           *  Sum: '<S660>/Add'
           */
          if (fabsf(rtb_Saturation_ga) > 3.14159274F) {
            /* Signum: '<S660>/Sign' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Saturation_ga;
            }

            /* End of Signum: '<S660>/Sign' */
            rtb_Saturation_ga -= 6.28318548F * rtb_Saturation1_d;
          }

          /* End of Switch: '<S660>/Switch' */

          /* Sum: '<S647>/Sum' incorporates:
           *  Delay: '<S647>/Delay'
           */
          rtb_Saturation1_d = rtb_Saturation_ga + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S659>/Integrator' */
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

          /* Product: '<S664>/Multiply1' incorporates:
           *  Constant: '<S664>/const1'
           *  DiscreteIntegrator: '<S659>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S664>/Add' incorporates:
           *  DiscreteIntegrator: '<S659>/Integrator1'
           *  Sum: '<S659>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jz - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S664>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S664>/Sign' */

          /* Sum: '<S664>/Add2' incorporates:
           *  Abs: '<S664>/Abs'
           *  Gain: '<S664>/Gain'
           *  Gain: '<S664>/Gain1'
           *  Product: '<S664>/Multiply2'
           *  Product: '<S664>/Multiply3'
           *  Sqrt: '<S664>/Sqrt'
           *  Sum: '<S664>/Add1'
           *  Sum: '<S664>/Subtract'
           */
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_k) *
                           FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Saturation_o4 + rtb_Saturation_ga;

          /* Sum: '<S664>/Add4' */
          rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) + rtb_Saturation_ga;

          /* Sum: '<S664>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_k;

          /* Sum: '<S664>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_k;

          /* Signum: '<S664>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S664>/Sign1' */

          /* Signum: '<S664>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S664>/Sign2' */

          /* Sum: '<S664>/Add5' incorporates:
           *  Gain: '<S664>/Gain2'
           *  Product: '<S664>/Multiply4'
           *  Sum: '<S664>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Update for Delay: '<S647>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S659>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S659>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)rtb_Compare_o3;

          /* Sum: '<S664>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_k;

          /* Sum: '<S664>/Add6' */
          rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_k;

          /* Signum: '<S664>/Sign5' incorporates:
           *  Signum: '<S664>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S664>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S664>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = rtb_u_b;

            /* Signum: '<S664>/Sign6' */
            rtb_Divide_lr_idx_3 = rtb_u_b;
          }

          /* End of Signum: '<S664>/Sign5' */

          /* Signum: '<S664>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S664>/Sign3' */

          /* Signum: '<S664>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S664>/Sign4' */

          /* Update for DiscreteIntegrator: '<S659>/Integrator' incorporates:
           *  Constant: '<S664>/const'
           *  Gain: '<S664>/Gain3'
           *  Product: '<S664>/Divide'
           *  Product: '<S664>/Multiply5'
           *  Product: '<S664>/Multiply6'
           *  Sum: '<S664>/Subtract4'
           *  Sum: '<S664>/Subtract5'
           *  Sum: '<S664>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S659>/Integrator' */
          /* End of Outputs for SubSystem: '<S327>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S327>/Unknown' incorporates:
           *  ActionPort: '<S630>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S327>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
         *  ActionPort: '<S325>/Action Port'
         */
        /* SwitchCase: '<S325>/Switch Case' incorporates:
         *  Math: '<S509>/Math Function'
         *  Sum: '<S465>/Subtract'
         *  Sum: '<S522>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S436>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S487>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S477>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S436>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S325>/Offboard' incorporates:
           *  ActionPort: '<S437>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S603>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S606>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S607>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S607>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S607>/Multiply1' incorporates:
           *  Product: '<S607>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S607>/Divide' incorporates:
           *  Constant: '<S607>/Constant'
           *  Constant: '<S607>/R'
           *  Sqrt: '<S607>/Sqrt'
           *  Sum: '<S607>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S607>/Product3' incorporates:
           *  Constant: '<S607>/Constant1'
           *  Product: '<S607>/Multiply1'
           *  Sum: '<S607>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S607>/Multiply2' incorporates:
           *  Trigonometry: '<S607>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S606>/Sum' incorporates:
           *  Gain: '<S603>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S611>/Abs' incorporates:
           *  Abs: '<S614>/Abs1'
           *  Switch: '<S611>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S611>/Switch1' incorporates:
           *  Abs: '<S611>/Abs'
           *  Bias: '<S611>/Bias2'
           *  Bias: '<S611>/Bias3'
           *  Constant: '<S608>/Constant'
           *  Constant: '<S608>/Constant1'
           *  Constant: '<S613>/Constant'
           *  Gain: '<S611>/Gain1'
           *  Product: '<S611>/Multiply'
           *  RelationalOperator: '<S613>/Compare'
           *  Switch: '<S608>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S614>/Switch1' incorporates:
             *  Bias: '<S614>/Bias2'
             *  Bias: '<S614>/Bias3'
             *  Constant: '<S614>/Constant'
             *  Constant: '<S615>/Constant'
             *  Math: '<S614>/Math Function'
             *  RelationalOperator: '<S615>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S614>/Switch1' */

            /* Signum: '<S611>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S611>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S608>/Sum' incorporates:
           *  Gain: '<S603>/Gain1'
           *  Gain: '<S603>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S606>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S606>/Multiply' incorporates:
           *  Gain: '<S606>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S610>/Switch1' incorporates:
           *  Abs: '<S610>/Abs1'
           *  Bias: '<S610>/Bias2'
           *  Bias: '<S610>/Bias3'
           *  Constant: '<S610>/Constant'
           *  Constant: '<S612>/Constant'
           *  Math: '<S610>/Math Function'
           *  RelationalOperator: '<S612>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S610>/Switch1' */

          /* Product: '<S606>/Multiply' incorporates:
           *  Gain: '<S606>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S584>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S588>/Multiply1'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S597>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S597>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S597>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S597>/Gain' incorporates:
             *  Gain: '<S596>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S597>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S597>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S597>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S597>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S597>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S597>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S590>/Switch' incorporates:
             *  Constant: '<S605>/Constant'
             *  DataTypeConversion: '<S603>/Data Type Conversion1'
             *  Product: '<S609>/Multiply1'
             *  Product: '<S609>/Multiply2'
             *  RelationalOperator: '<S605>/Compare'
             *  S-Function (sfix_bitop): '<S602>/lat_cmd valid'
             *  Sum: '<S609>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o2 +
                                   rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S588>/Multiply' incorporates:
             *  Constant: '<S594>/Constant'
             *  Constant: '<S595>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S587>/Logical Operator'
             *  RelationalOperator: '<S594>/Compare'
             *  RelationalOperator: '<S595>/Compare'
             *  S-Function (sfix_bitop): '<S587>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/x_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S588>/Sum1'
             */
            d = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S597>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S590>/Switch' incorporates:
             *  Constant: '<S605>/Constant'
             *  DataTypeConversion: '<S603>/Data Type Conversion1'
             *  Product: '<S609>/Multiply3'
             *  Product: '<S609>/Multiply4'
             *  RelationalOperator: '<S605>/Compare'
             *  S-Function (sfix_bitop): '<S602>/lon_cmd valid'
             *  Sum: '<S609>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_u_b = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                   rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S588>/Multiply' incorporates:
             *  Constant: '<S594>/Constant'
             *  Constant: '<S595>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S587>/Logical Operator'
             *  RelationalOperator: '<S594>/Compare'
             *  RelationalOperator: '<S595>/Compare'
             *  S-Function (sfix_bitop): '<S587>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/y_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S588>/Sum1'
             */
            rtb_Integrator1_bx = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_u_b -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S597>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S590>/Switch' incorporates:
             *  Constant: '<S605>/Constant'
             *  DataTypeConversion: '<S603>/Data Type Conversion'
             *  DataTypeConversion: '<S603>/Data Type Conversion1'
             *  Gain: '<S603>/Gain2'
             *  Gain: '<S606>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S605>/Compare'
             *  S-Function (sfix_bitop): '<S602>/alt_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S606>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_u_b = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                                    -FMS_U.INS_Out.alt_0);
            } else {
              rtb_u_b = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S588>/Multiply' incorporates:
             *  Constant: '<S594>/Constant'
             *  Constant: '<S595>/Constant'
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S587>/Logical Operator'
             *  RelationalOperator: '<S594>/Compare'
             *  RelationalOperator: '<S595>/Compare'
             *  S-Function (sfix_bitop): '<S587>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/z_cmd valid'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S588>/Sum1'
             */
            rtb_Divide_lr_idx_3 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_u_b -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * rtb_Divide_lr_idx_3 + (rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d);
            }

            /* SignalConversion: '<S530>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S530>/Constant4'
             *  MultiPortSwitch: '<S519>/Index Vector'
             *  Product: '<S588>/Multiply1'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S530>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S530>/Gain' incorporates:
             *  Gain: '<S529>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S519>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S530>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S530>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S530>/Constant3'
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S530>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S530>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S530>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S519>/Multiply' incorporates:
             *  Constant: '<S528>/Constant'
             *  RelationalOperator: '<S528>/Compare'
             *  S-Function (sfix_bitop): '<S525>/ax_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ? FMS_U.Auto_Cmd.ax_cmd :
              0.0F;

            /* SignalConversion: '<S530>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S519>/Multiply' incorporates:
             *  Constant: '<S528>/Constant'
             *  RelationalOperator: '<S528>/Compare'
             *  S-Function (sfix_bitop): '<S525>/ay_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S530>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S519>/Multiply' incorporates:
             *  Constant: '<S528>/Constant'
             *  RelationalOperator: '<S528>/Compare'
             *  S-Function (sfix_bitop): '<S525>/az_cmd valid'
             */
            rtb_Divide_lr_idx_3 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S519>/Index Vector' incorporates:
             *  Product: '<S526>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
                rtb_Divide_lr_idx_3 + (rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d);
            }
            break;

           case 1:
            /* SignalConversion: '<S600>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S600>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S600>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S589>/Data Store Read'
             *  Gain: '<S598>/Gain'
             *  Trigonometry: '<S600>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_or[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S600>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S589>/Data Store Read'
             *  Gain: '<S598>/Gain'
             *  Trigonometry: '<S600>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S600>/Gain' incorporates:
             *  Trigonometry: '<S600>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -rtb_u_b;

            /* SignalConversion: '<S600>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S600>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S600>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_u_b;

            /* Trigonometry: '<S600>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_o4;

            /* SignalConversion: '<S601>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S601>/Constant4'
             */
            rtb_MatrixConcatenate1[5] = 0.0F;

            /* Gain: '<S599>/Gain' incorporates:
             *  DataStoreRead: '<S589>/Data Store Read'
             *  Gain: '<S531>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S519>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S589>/Subtract'
             */
            rtb_Divide_lr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S601>/Trigonometric Function3' incorporates:
             *  Gain: '<S599>/Gain'
             *  Trigonometry: '<S601>/Trigonometric Function1'
             */
            rtb_Saturation_o4 = arm_cos_f32(rtb_Divide_lr_idx_2);
            rtb_MatrixConcatenate1[4] = rtb_Saturation_o4;

            /* Trigonometry: '<S601>/Trigonometric Function2' incorporates:
             *  Gain: '<S599>/Gain'
             *  Trigonometry: '<S601>/Trigonometric Function'
             */
            rtb_u_b = arm_sin_f32(rtb_Divide_lr_idx_2);

            /* Gain: '<S601>/Gain' incorporates:
             *  Trigonometry: '<S601>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1[3] = -rtb_u_b;

            /* SignalConversion: '<S601>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S601>/Constant3'
             */
            rtb_MatrixConcatenate1[2] = 0.0F;

            /* Trigonometry: '<S601>/Trigonometric Function' */
            rtb_MatrixConcatenate1[1] = rtb_u_b;

            /* Trigonometry: '<S601>/Trigonometric Function1' */
            rtb_MatrixConcatenate1[0] = rtb_Saturation_o4;

            /* RelationalOperator: '<S605>/Compare' incorporates:
             *  Constant: '<S605>/Constant'
             *  S-Function (sfix_bitop): '<S602>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S602>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S602>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S603>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S603>/Data Type Conversion'
             *  Gain: '<S603>/Gain2'
             *  Gain: '<S606>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S609>/Multiply1'
             *  Product: '<S609>/Multiply2'
             *  Product: '<S609>/Multiply3'
             *  Product: '<S609>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S606>/Sum1'
             *  Sum: '<S609>/Sum2'
             *  Sum: '<S609>/Sum3'
             */
            rtb_MatrixConcatenate1_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S590>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S600>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S601>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S589>/Sum' incorporates:
             *  DataStoreRead: '<S589>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            d = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S600>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S601>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S589>/Sum' incorporates:
             *  DataStoreRead: '<S589>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Integrator1_bx = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S600>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S601>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S589>/Sum' incorporates:
             *  DataStoreRead: '<S589>/Data Store Read'
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_3 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S594>/Compare' incorporates:
             *  Constant: '<S594>/Constant'
             *  S-Function (sfix_bitop): '<S587>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S595>/Compare' incorporates:
             *  Constant: '<S595>/Constant'
             *  S-Function (sfix_bitop): '<S587>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S589>/Sum2' incorporates:
               *  Product: '<S589>/Multiply2'
               *  Switch: '<S590>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_u_b = rtb_MatrixConcatenate1_0[rtb_n];
              } else {
                rtb_u_b = rtb_Switch_c2[rtb_n];
              }

              /* Product: '<S589>/Multiply' incorporates:
               *  Logic: '<S587>/Logical Operator'
               *  Product: '<S589>/Multiply2'
               *  Sum: '<S589>/Sum'
               *  Sum: '<S589>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ? rtb_u_b -
                ((rtb_VectorConcatenate_or[rtb_n + 3] * rtb_Integrator1_bx +
                  rtb_VectorConcatenate_or[rtb_n] * d) +
                 rtb_VectorConcatenate_or[rtb_n + 6] * rtb_Divide_lr_idx_3) :
                0.0F;
            }

            /* SignalConversion: '<S532>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S532>/Constant4'
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S532>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Divide_lr_idx_2);

            /* Gain: '<S532>/Gain' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             *  Trigonometry: '<S532>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Divide_lr_idx_2);

            /* SignalConversion: '<S532>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S532>/Constant3'
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S532>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Divide_lr_idx_2);

            /* Trigonometry: '<S532>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S519>/Index Vector'
             */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Divide_lr_idx_2);

            /* Product: '<S519>/Multiply' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S528>/Compare' incorporates:
             *  Constant: '<S528>/Constant'
             *  S-Function (sfix_bitop): '<S525>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S525>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S525>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S532>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S519>/Index Vector'
               */
              rtb_VectorConcatenate_or[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S519>/Multiply' */
              rtb_MatrixConcatenate1_0[rtb_n] = tmp[rtb_n] ? rtb_Switch_c2[rtb_n]
                : 0.0F;
              rtb_MatrixConcatenate3[rtb_n] = rtb_MatrixConcatenate1[rtb_n + 6] *
                rtb_Switch_ov[2] + (rtb_MatrixConcatenate1[rtb_n + 3] *
                                    rtb_Switch_ov[1] +
                                    rtb_MatrixConcatenate1[rtb_n] *
                                    rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S519>/Index Vector' incorporates:
             *  Product: '<S527>/Multiply3'
             *  Product: '<S589>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
                rtb_MatrixConcatenate1_0[2] + (rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_MatrixConcatenate1_0[1] +
                rtb_VectorConcatenate_or[rtb_n] * rtb_MatrixConcatenate1_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S593>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S593>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S593>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S593>/Gain' incorporates:
             *  Gain: '<S592>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S593>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S593>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S593>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S593>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S593>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* S-Function (sfix_bitop): '<S602>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S587>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S605>/Compare' incorporates:
             *  Constant: '<S605>/Constant'
             *  S-Function (sfix_bitop): '<S602>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S602>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S587>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S605>/Compare' incorporates:
             *  Constant: '<S605>/Constant'
             *  S-Function (sfix_bitop): '<S602>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S602>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S587>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S605>/Compare' incorporates:
             *  Constant: '<S605>/Constant'
             *  S-Function (sfix_bitop): '<S602>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S603>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S603>/Data Type Conversion'
             *  Gain: '<S603>/Gain2'
             *  Gain: '<S606>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S609>/Multiply1'
             *  Product: '<S609>/Multiply2'
             *  Product: '<S609>/Multiply3'
             *  Product: '<S609>/Multiply4'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S606>/Sum1'
             *  Sum: '<S609>/Sum2'
             *  Sum: '<S609>/Sum3'
             */
            rtb_MatrixConcatenate1_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S590>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S593>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Sum: '<S586>/Sum' incorporates:
             *  DataStoreRead: '<S586>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation_o4 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S593>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Sum: '<S586>/Sum' incorporates:
             *  DataStoreRead: '<S586>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S593>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Sum: '<S586>/Sum' incorporates:
             *  DataStoreRead: '<S586>/Data Store Read'
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_3 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S594>/Compare' incorporates:
             *  Constant: '<S594>/Constant'
             *  S-Function (sfix_bitop): '<S587>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S587>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S595>/Compare' incorporates:
             *  Constant: '<S595>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S586>/Sum2' incorporates:
             *  Logic: '<S587>/Logical Operator'
             *  Product: '<S586>/Multiply'
             *  Product: '<S586>/Multiply2'
             *  Sum: '<S586>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S590>/Switch' incorporates:
               *  Product: '<S586>/Multiply2'
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

            /* End of Sum: '<S586>/Sum2' */

            /* MultiPortSwitch: '<S519>/Index Vector' incorporates:
             *  Constant: '<S528>/Constant'
             *  Product: '<S519>/Multiply'
             *  RelationalOperator: '<S528>/Compare'
             *  S-Function (sfix_bitop): '<S525>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S525>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S525>/az_cmd valid'
             */
            rtb_Switch_ov[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ov[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ov[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* Sum: '<S580>/Sum1' incorporates:
           *  Constant: '<S580>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S580>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S581>/Abs' */
          rtb_Saturation_o4 = fabsf(rtb_a_bx);

          /* Switch: '<S581>/Switch' incorporates:
           *  Constant: '<S581>/Constant'
           *  Constant: '<S582>/Constant'
           *  Product: '<S581>/Multiply'
           *  RelationalOperator: '<S582>/Compare'
           *  Sum: '<S581>/Subtract'
           */
          if (rtb_Saturation_o4 > 3.14159274F) {
            /* Signum: '<S581>/Sign' */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* End of Signum: '<S581>/Sign' */
            rtb_a_bx *= rtb_Saturation_o4 - 6.28318548F;
          }

          /* End of Switch: '<S581>/Switch' */

          /* Saturate: '<S580>/Saturation' */
          if (rtb_a_bx > 0.314159274F) {
            rtb_a_bx = 0.314159274F;
          } else {
            if (rtb_a_bx < -0.314159274F) {
              rtb_a_bx = -0.314159274F;
            }
          }

          /* End of Saturate: '<S580>/Saturation' */

          /* Gain: '<S577>/Gain2' */
          rtb_a_bx *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S521>/Sum' incorporates:
           *  Constant: '<S579>/Constant'
           *  Constant: '<S583>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S577>/Multiply2'
           *  Product: '<S578>/Multiply1'
           *  RelationalOperator: '<S579>/Compare'
           *  RelationalOperator: '<S583>/Compare'
           *  S-Function (sfix_bitop): '<S577>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S578>/psi_rate_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          rtb_u_b = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_a_bx : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S584>/Gain1' */
          rtb_Saturation_o4 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

          /* Gain: '<S584>/Gain2' */
          rtb_a_bx = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S585>/Index Vector' incorporates:
           *  Constant: '<S621>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S585>/Multiply'
           *  Product: '<S618>/Multiply'
           *  Product: '<S619>/Multiply3'
           *  RelationalOperator: '<S621>/Compare'
           *  S-Function (sfix_bitop): '<S617>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S617>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S617>/w_cmd valid'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S623>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S623>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S623>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S623>/Gain' incorporates:
             *  Gain: '<S622>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S623>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S623>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S623>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S623>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* Trigonometry: '<S623>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S623>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S585>/Multiply' incorporates:
             *  Constant: '<S621>/Constant'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S617>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S623>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S585>/Multiply' incorporates:
             *  Constant: '<S621>/Constant'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S617>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S623>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S585>/Multiply' incorporates:
             *  Constant: '<S621>/Constant'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S617>/w_cmd valid'
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
            /* SignalConversion: '<S625>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S625>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Gain: '<S624>/Gain' incorporates:
             *  DataStoreRead: '<S619>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S619>/Subtract'
             */
            rtb_Saturation_ga = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S625>/Trigonometric Function3' incorporates:
             *  Gain: '<S624>/Gain'
             */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Saturation_ga);

            /* Gain: '<S625>/Gain' incorporates:
             *  Gain: '<S624>/Gain'
             *  Trigonometry: '<S625>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S625>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S625>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S625>/Trigonometric Function' incorporates:
             *  Gain: '<S624>/Gain'
             */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Saturation_ga);

            /* Trigonometry: '<S625>/Trigonometric Function1' incorporates:
             *  Gain: '<S624>/Gain'
             */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S625>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gjo[0];

            /* Product: '<S585>/Multiply' incorporates:
             *  Constant: '<S621>/Constant'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S617>/u_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ? FMS_U.Auto_Cmd.u_cmd :
              0.0F;

            /* SignalConversion: '<S625>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gjo[1];

            /* Product: '<S585>/Multiply' incorporates:
             *  Constant: '<S621>/Constant'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S617>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S625>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gjo[2];

            /* Product: '<S585>/Multiply' incorporates:
             *  Constant: '<S621>/Constant'
             *  RelationalOperator: '<S621>/Compare'
             *  S-Function (sfix_bitop): '<S617>/w_cmd valid'
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

          /* Sum: '<S522>/Sum1' */
          rtb_Saturation_ga = rtb_a_bx + rtb_MatrixConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S540>/Switch' incorporates:
           *  Constant: '<S555>/Constant'
           *  Constant: '<S557>/Constant'
           *  Constant: '<S558>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S555>/Compare'
           *  RelationalOperator: '<S557>/Compare'
           *  RelationalOperator: '<S558>/Compare'
           *  S-Function (sfix_bitop): '<S540>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S540>/y_v_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S540>/Logical Operator' incorporates:
             *  Constant: '<S556>/Constant'
             *  Constant: '<S557>/Constant'
             *  Constant: '<S558>/Constant'
             *  RelationalOperator: '<S556>/Compare'
             *  RelationalOperator: '<S557>/Compare'
             *  RelationalOperator: '<S558>/Compare'
             *  S-Function (sfix_bitop): '<S540>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S540>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S540>/y_v_cmd'
             */
            rtb_Compare_aij = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
                               ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
                               ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_Compare_o3 = rtb_Compare_aij;
          } else {
            rtb_Compare_aij = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_Compare_o3 = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U);
          }

          /* End of Switch: '<S540>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S520>/u_cmd_valid' */
          /* MATLAB Function: '<S552>/bit_shift' incorporates:
           *  DataTypeConversion: '<S520>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_aij << 6);

          /* End of Outputs for SubSystem: '<S520>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S520>/v_cmd_valid' */
          /* MATLAB Function: '<S553>/bit_shift' incorporates:
           *  DataTypeConversion: '<S520>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_Compare_o3 << 7);

          /* End of Outputs for SubSystem: '<S520>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S541>/Switch' incorporates:
           *  Constant: '<S560>/Constant'
           *  Constant: '<S561>/Constant'
           *  Constant: '<S563>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S560>/Compare'
           *  RelationalOperator: '<S561>/Compare'
           *  RelationalOperator: '<S563>/Compare'
           *  S-Function (sfix_bitop): '<S541>/ax_cmd'
           *  S-Function (sfix_bitop): '<S541>/ay_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S541>/Logical Operator' incorporates:
             *  Constant: '<S561>/Constant'
             *  Constant: '<S563>/Constant'
             *  RelationalOperator: '<S561>/Compare'
             *  RelationalOperator: '<S563>/Compare'
             *  S-Function (sfix_bitop): '<S541>/ax_cmd'
             *  S-Function (sfix_bitop): '<S541>/ay_cmd'
             */
            rtb_Compare_aij = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                               ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_Compare_o3 = rtb_Compare_aij;
          } else {
            rtb_Compare_aij = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_Compare_o3 = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
          }

          /* End of Switch: '<S541>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S437>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S437>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S437>/Bus Assignment' incorporates:
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

          /* Saturate: '<S521>/Saturation' */
          if (rtb_u_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_u_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_u_b;
          }

          /* End of Saturate: '<S521>/Saturation' */

          /* Saturate: '<S522>/Saturation2' */
          if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
          }

          /* End of Saturate: '<S522>/Saturation2' */

          /* Saturate: '<S522>/Saturation1' */
          if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
          }

          /* End of Saturate: '<S522>/Saturation1' */

          /* Saturate: '<S522>/Saturation3' */
          if (rtb_Saturation_ga > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_ga < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S437>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;
          }

          /* End of Saturate: '<S522>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S520>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S520>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S520>/throttle_cmd_valid' */
          /* BusAssignment: '<S437>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S533>/Constant'
           *  Constant: '<S534>/Constant'
           *  Constant: '<S535>/Constant'
           *  Constant: '<S536>/Constant'
           *  Constant: '<S537>/Constant'
           *  Constant: '<S538>/Constant'
           *  Constant: '<S539>/Constant'
           *  Constant: '<S559>/Constant'
           *  Constant: '<S562>/Constant'
           *  DataTypeConversion: '<S520>/Data Type Conversion10'
           *  DataTypeConversion: '<S520>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S542>/bit_shift'
           *  MATLAB Function: '<S543>/bit_shift'
           *  MATLAB Function: '<S544>/bit_shift'
           *  MATLAB Function: '<S546>/bit_shift'
           *  MATLAB Function: '<S547>/bit_shift'
           *  MATLAB Function: '<S548>/bit_shift'
           *  MATLAB Function: '<S549>/bit_shift'
           *  MATLAB Function: '<S550>/bit_shift'
           *  MATLAB Function: '<S551>/bit_shift'
           *  MATLAB Function: '<S554>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S533>/Compare'
           *  RelationalOperator: '<S534>/Compare'
           *  RelationalOperator: '<S535>/Compare'
           *  RelationalOperator: '<S536>/Compare'
           *  RelationalOperator: '<S537>/Compare'
           *  RelationalOperator: '<S538>/Compare'
           *  RelationalOperator: '<S539>/Compare'
           *  RelationalOperator: '<S559>/Compare'
           *  RelationalOperator: '<S562>/Compare'
           *  S-Function (sfix_bitop): '<S520>/p_cmd'
           *  S-Function (sfix_bitop): '<S520>/phi_cmd'
           *  S-Function (sfix_bitop): '<S520>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S520>/q_cmd'
           *  S-Function (sfix_bitop): '<S520>/r_cmd'
           *  S-Function (sfix_bitop): '<S520>/theta_cmd'
           *  S-Function (sfix_bitop): '<S520>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S540>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S541>/az_cmd'
           *  SignalConversion: '<S43>/Signal Copy'
           *  Sum: '<S520>/Add'
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

          /* End of Outputs for SubSystem: '<S520>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S520>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S520>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S325>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S325>/Mission' incorporates:
             *  ActionPort: '<S436>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S325>/Switch Case' incorporates:
             *  UnitDelay: '<S439>/Delay Input1'
             *
             * Block description for '<S439>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S325>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S325>/Mission' incorporates:
             *  ActionPort: '<S436>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S436>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S325>/Switch Case' incorporates:
             *  Chart: '<S478>/Motion Status'
             *  Chart: '<S488>/Motion State'
             *  Delay: '<S444>/Delay'
             *  Delay: '<S466>/Delay'
             *  DiscreteIntegrator: '<S447>/Integrator'
             *  DiscreteIntegrator: '<S447>/Integrator1'
             *  DiscreteIntegrator: '<S462>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S467>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S514>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S436>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S325>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S325>/Mission' incorporates:
           *  ActionPort: '<S436>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S439>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S439>/Delay Input1'
           *
           * Block description for '<S439>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S436>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S440>/Reset'
           */
          if (rtb_Compare_o3 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
                                 POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S487>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S477>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S466>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S467>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S462>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S514>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S444>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S447>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S447>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S488>/Motion State' */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S478>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Compare_o3;

          /* Delay: '<S466>/Delay' incorporates:
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
          /* Switch: '<S462>/Switch2' incorporates:
           *  Constant: '<S462>/vel'
           *  Constant: '<S471>/Constant'
           *  RelationalOperator: '<S471>/Compare'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S462>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S467>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S439>/Delay Input1'
           *
           * Block description for '<S439>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S461>/Compare' incorporates:
           *  Constant: '<S518>/Constant'
           *  RelationalOperator: '<S518>/Compare'
           *  UnitDelay: '<S439>/Delay Input1'
           *
           * Block description for '<S439>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S462>/Acceleration_Speed' */
          if (rtb_Compare_o3 || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S488>/Motion State' incorporates:
           *  Constant: '<S488>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S488>/Square'
           *  Math: '<S488>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S488>/Sqrt'
           *  Sum: '<S488>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S487>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S497>/Integrator1'
           *  Gain: '<S491>/Gain6'
           *  Gain: '<S495>/Gain'
           *  Gain: '<S496>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S497>/Subtract'
           *  Sum: '<S498>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S487>/Hold Control' incorporates:
               *  ActionPort: '<S490>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S487>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S487>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S487>/Hold Control' incorporates:
             *  ActionPort: '<S490>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S487>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S487>/Brake Control' incorporates:
             *  ActionPort: '<S489>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S487>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S487>/Move Control' incorporates:
               *  ActionPort: '<S491>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S487>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S497>/Integrator'
               *  DiscreteIntegrator: '<S497>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S487>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S487>/Move Control' incorporates:
             *  ActionPort: '<S491>/Action Port'
             */
            /* SignalConversion: '<S491>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S498>/Multiply1' incorporates:
             *  Constant: '<S498>/const1'
             *  DiscreteIntegrator: '<S497>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S491>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S498>/Multiply1' incorporates:
             *  Constant: '<S498>/const1'
             *  DiscreteIntegrator: '<S497>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S495>/Dead Zone' incorporates:
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

            /* Sum: '<S498>/Add' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator1'
             *  Gain: '<S491>/Gain6'
             *  Gain: '<S495>/Gain'
             *  Sum: '<S497>/Subtract'
             */
            rtb_Divide_c14[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S496>/Dead Zone' incorporates:
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

            /* Sum: '<S498>/Add' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator1'
             *  Gain: '<S491>/Gain6'
             *  Gain: '<S496>/Gain'
             *  Sum: '<S497>/Subtract'
             */
            rtb_Divide_c14[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S495>/Dead Zone' incorporates:
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

            /* Signum: '<S498>/Sign' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator1'
             *  Gain: '<S491>/Gain6'
             *  Gain: '<S495>/Gain'
             *  Sum: '<S497>/Subtract'
             *  Sum: '<S498>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S498>/Add2' incorporates:
             *  Abs: '<S498>/Abs'
             *  Gain: '<S498>/Gain'
             *  Gain: '<S498>/Gain1'
             *  Product: '<S498>/Multiply2'
             *  Product: '<S498>/Multiply3'
             *  Signum: '<S498>/Sign'
             *  Sqrt: '<S498>/Sqrt'
             *  Sum: '<S498>/Add1'
             *  Sum: '<S498>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Divide_c14[0]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_Saturation1_d + rtb_Subtract_hb[0];

            /* Sum: '<S498>/Add3' incorporates:
             *  Signum: '<S498>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_c14[0] + FMS_ConstB.d_oe;

            /* Sum: '<S498>/Subtract1' incorporates:
             *  Signum: '<S498>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_c14[0] - FMS_ConstB.d_oe;

            /* Signum: '<S498>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S498>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S498>/Add5' incorporates:
             *  Gain: '<S498>/Gain2'
             *  Product: '<S498>/Multiply4'
             *  Signum: '<S498>/Sign'
             *  Sum: '<S498>/Add2'
             *  Sum: '<S498>/Add4'
             *  Sum: '<S498>/Subtract2'
             */
            rtb_Divide_lr_idx_3 += ((rtb_Divide_c14[0] - rtb_Divide_lr_idx_3) +
              rtb_Subtract_hb[0]) * ((rtb_Saturation_ga - rtb_Saturation1_d) *
              0.5F);

            /* Update for DiscreteIntegrator: '<S497>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S498>/Sign4' incorporates:
             *  Sum: '<S498>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 - FMS_ConstB.d_oe;

            /* Signum: '<S498>/Sign3' incorporates:
             *  Sum: '<S498>/Add6'
             */
            rtb_Saturation1_d = rtb_Divide_lr_idx_3 + FMS_ConstB.d_oe;

            /* Signum: '<S498>/Sign5' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Divide_lr_idx_3;
            }

            /* Signum: '<S498>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S498>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S498>/Sign6' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Divide_lr_idx_3;
            }

            /* Update for DiscreteIntegrator: '<S497>/Integrator' incorporates:
             *  Constant: '<S498>/const'
             *  Gain: '<S498>/Gain3'
             *  Product: '<S498>/Divide'
             *  Product: '<S498>/Multiply5'
             *  Product: '<S498>/Multiply6'
             *  Sum: '<S498>/Subtract4'
             *  Sum: '<S498>/Subtract5'
             *  Sum: '<S498>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Divide_lr_idx_3 /
              FMS_ConstB.d_oe - rtb_Saturation_o4) * FMS_ConstB.Gain4_g *
              ((rtb_Saturation1_d - rtb_Saturation_ga) * 0.5F) - rtb_u_b *
              58.836F) * 0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S496>/Dead Zone' incorporates:
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

            /* Signum: '<S498>/Sign' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator1'
             *  Gain: '<S491>/Gain6'
             *  Gain: '<S496>/Gain'
             *  Sum: '<S497>/Subtract'
             *  Sum: '<S498>/Add'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S498>/Add2' incorporates:
             *  Abs: '<S498>/Abs'
             *  Gain: '<S498>/Gain'
             *  Gain: '<S498>/Gain1'
             *  Product: '<S498>/Multiply2'
             *  Product: '<S498>/Multiply3'
             *  Signum: '<S498>/Sign'
             *  Sqrt: '<S498>/Sqrt'
             *  Sum: '<S498>/Add1'
             *  Sum: '<S498>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Divide_c14[1]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_Saturation1_d + rtb_Subtract_hb[1];

            /* Sum: '<S498>/Add3' incorporates:
             *  Signum: '<S498>/Sign'
             */
            rtb_Saturation_ga = rtb_Divide_c14[1] + FMS_ConstB.d_oe;

            /* Sum: '<S498>/Subtract1' incorporates:
             *  Signum: '<S498>/Sign'
             */
            rtb_Saturation1_d = rtb_Divide_c14[1] - FMS_ConstB.d_oe;

            /* Signum: '<S498>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S498>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Sum: '<S498>/Add5' incorporates:
             *  Gain: '<S498>/Gain2'
             *  Product: '<S498>/Multiply4'
             *  Signum: '<S498>/Sign'
             *  Sum: '<S498>/Add2'
             *  Sum: '<S498>/Add4'
             *  Sum: '<S498>/Subtract2'
             */
            rtb_Divide_lr_idx_3 += ((rtb_Divide_c14[1] - rtb_Divide_lr_idx_3) +
              rtb_Subtract_hb[1]) * ((rtb_Saturation_ga - rtb_Saturation1_d) *
              0.5F);

            /* Update for DiscreteIntegrator: '<S497>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S497>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S498>/Sign4' incorporates:
             *  Sum: '<S498>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 - FMS_ConstB.d_oe;

            /* Signum: '<S498>/Sign3' incorporates:
             *  Sum: '<S498>/Add6'
             */
            rtb_Saturation1_d = rtb_Divide_lr_idx_3 + FMS_ConstB.d_oe;

            /* Signum: '<S498>/Sign5' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Divide_lr_idx_3;
            }

            /* Signum: '<S498>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S498>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S498>/Sign6' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Divide_lr_idx_3;
            }

            /* Update for DiscreteIntegrator: '<S497>/Integrator' incorporates:
             *  Constant: '<S498>/const'
             *  Gain: '<S498>/Gain3'
             *  Product: '<S498>/Divide'
             *  Product: '<S498>/Multiply5'
             *  Product: '<S498>/Multiply6'
             *  Sum: '<S498>/Subtract4'
             *  Sum: '<S498>/Subtract5'
             *  Sum: '<S498>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Divide_lr_idx_3 /
              FMS_ConstB.d_oe - rtb_Saturation_o4) * FMS_ConstB.Gain4_g *
              ((rtb_Saturation1_d - rtb_Saturation_ga) * 0.5F) - rtb_u_b *
              58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S487>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S487>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S478>/Motion Status' incorporates:
           *  Abs: '<S478>/Abs'
           *  Constant: '<S478>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S477>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S477>/Hold Control' incorporates:
               *  ActionPort: '<S480>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S477>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S477>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S477>/Hold Control' incorporates:
             *  ActionPort: '<S480>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S477>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S477>/Brake Control' incorporates:
             *  ActionPort: '<S479>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S477>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S477>/Move Control' incorporates:
               *  ActionPort: '<S481>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S477>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S484>/Integrator'
               *  DiscreteIntegrator: '<S484>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S477>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S477>/Move Control' incorporates:
             *  ActionPort: '<S481>/Action Port'
             */
            /* Product: '<S485>/Multiply1' incorporates:
             *  Constant: '<S485>/const1'
             *  DiscreteIntegrator: '<S484>/Integrator'
             */
            rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S483>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S483>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S485>/Add' incorporates:
             *  DiscreteIntegrator: '<S484>/Integrator1'
             *  Gain: '<S481>/Gain1'
             *  Gain: '<S483>/Gain'
             *  Sum: '<S484>/Subtract'
             */
            rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_u_b * -FMS_PARAM.VEL_Z_LIM) +
              rtb_Saturation_ga;

            /* Signum: '<S485>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation_o4 = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_Saturation1_d;
            }

            /* End of Signum: '<S485>/Sign' */

            /* Sum: '<S485>/Add2' incorporates:
             *  Abs: '<S485>/Abs'
             *  Gain: '<S485>/Gain'
             *  Gain: '<S485>/Gain1'
             *  Product: '<S485>/Multiply2'
             *  Product: '<S485>/Multiply3'
             *  Sqrt: '<S485>/Sqrt'
             *  Sum: '<S485>/Add1'
             *  Sum: '<S485>/Subtract'
             */
            rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_oc)
                             * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_o4 + rtb_Saturation_ga;

            /* Sum: '<S485>/Add4' */
            rtb_Saturation_o4 = (rtb_Saturation1_d - rtb_u_b) +
              rtb_Saturation_ga;

            /* Sum: '<S485>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_oc;

            /* Sum: '<S485>/Subtract1' */
            rtb_Saturation1_d -= FMS_ConstB.d_oc;

            /* Signum: '<S485>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S485>/Sign1' */

            /* Signum: '<S485>/Sign2' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S485>/Sign2' */

            /* Sum: '<S485>/Add5' incorporates:
             *  Gain: '<S485>/Gain2'
             *  Product: '<S485>/Multiply4'
             *  Sum: '<S485>/Subtract2'
             */
            rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
              rtb_Saturation_o4;

            /* SignalConversion: '<S481>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S484>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S484>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S484>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S485>/Subtract3' */
            rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_oc;

            /* Sum: '<S485>/Add6' */
            rtb_Saturation1_d = rtb_u_b + FMS_ConstB.d_oc;

            /* Signum: '<S485>/Sign5' incorporates:
             *  Signum: '<S485>/Sign6'
             */
            if (rtb_u_b < 0.0F) {
              rtb_Saturation_o4 = -1.0F;

              /* Signum: '<S485>/Sign6' */
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Saturation_o4 = 1.0F;

              /* Signum: '<S485>/Sign6' */
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Saturation_o4 = rtb_u_b;

              /* Signum: '<S485>/Sign6' */
              rtb_Divide_lr_idx_3 = rtb_u_b;
            }

            /* End of Signum: '<S485>/Sign5' */

            /* Signum: '<S485>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S485>/Sign3' */

            /* Signum: '<S485>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S485>/Sign4' */

            /* Update for DiscreteIntegrator: '<S484>/Integrator' incorporates:
             *  Constant: '<S485>/const'
             *  Gain: '<S485>/Gain3'
             *  Product: '<S485>/Divide'
             *  Product: '<S485>/Multiply5'
             *  Product: '<S485>/Multiply6'
             *  Sum: '<S485>/Subtract4'
             *  Sum: '<S485>/Subtract5'
             *  Sum: '<S485>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_u_b / FMS_ConstB.d_oc -
              rtb_Saturation_o4) * FMS_ConstB.Gain4_j * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 78.448F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S477>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S477>/Switch Case' */

          /* Switch: '<S442>/Switch' incorporates:
           *  Product: '<S466>/Multiply'
           *  Sum: '<S466>/Sum'
           */
          if (rtb_Compare_o3) {
            /* Saturate: '<S487>/Saturation1' */
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

            /* End of Saturate: '<S487>/Saturation1' */

            /* Saturate: '<S477>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S477>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S466>/Sum' incorporates:
             *  Delay: '<S466>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S515>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S462>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Saturation_o4;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S466>/Sum' incorporates:
             *  Delay: '<S466>/Delay'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S462>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_ga = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S474>/Sqrt' incorporates:
             *  Math: '<S474>/Square'
             *  Sum: '<S462>/Sum'
             *  Sum: '<S474>/Sum of Elements'
             */
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d +
              rtb_Saturation_ga * rtb_Saturation_ga);

            /* SignalConversion: '<S517>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S517>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S517>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S516>/Gain' incorporates:
             *  DiscreteIntegrator: '<S514>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S514>/Add'
             */
            rtb_u_b = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S517>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_u_b);

            /* Gain: '<S517>/Gain' incorporates:
             *  Trigonometry: '<S517>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_u_b);

            /* SignalConversion: '<S517>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S517>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S517>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_u_b);

            /* Trigonometry: '<S517>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_u_b);

            /* Switch: '<S473>/Switch2' incorporates:
             *  Constant: '<S462>/Constant2'
             *  DiscreteIntegrator: '<S462>/Acceleration_Speed'
             *  RelationalOperator: '<S473>/LowerRelop1'
             *  RelationalOperator: '<S473>/UpperRelop'
             *  Switch: '<S473>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_u_b = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S473>/Switch' incorporates:
               *  Constant: '<S462>/Constant2'
               */
              rtb_u_b = 0.0F;
            } else {
              rtb_u_b = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S473>/Switch2' */

            /* Switch: '<S462>/Switch' */
            if (rtb_Saturation_ga > FMS_PARAM.L1) {
              rtb_Saturation1_d = d;
            } else {
              /* Gain: '<S462>/Gain' */
              rtb_Saturation1_d = 0.5F * rtb_Saturation_ga;

              /* Switch: '<S472>/Switch2' incorporates:
               *  Constant: '<S462>/Constant1'
               *  RelationalOperator: '<S472>/LowerRelop1'
               *  RelationalOperator: '<S472>/UpperRelop'
               *  Switch: '<S472>/Switch'
               */
              if (rtb_Saturation1_d > d) {
                rtb_Saturation1_d = d;
              } else {
                if (rtb_Saturation1_d < 0.5F) {
                  /* Switch: '<S472>/Switch' incorporates:
                   *  Constant: '<S462>/Constant1'
                   */
                  rtb_Saturation1_d = 0.5F;
                }
              }

              /* End of Switch: '<S472>/Switch2' */
            }

            /* End of Switch: '<S462>/Switch' */

            /* Switch: '<S462>/Switch1' incorporates:
             *  Sum: '<S462>/Sum1'
             */
            if (rtb_u_b - rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = rtb_u_b;
            }

            /* End of Switch: '<S462>/Switch1' */

            /* Sum: '<S515>/Sum of Elements' incorporates:
             *  Math: '<S515>/Math Function'
             */
            rtb_u_b = rtb_Switch_c2[0] * rtb_Switch_c2[0] + rtb_Saturation_o4 *
              rtb_Saturation_o4;

            /* Math: '<S515>/Math Function1' incorporates:
             *  Sum: '<S515>/Sum of Elements'
             *
             * About '<S515>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_u_b < 0.0F) {
              rtb_u_b = -sqrtf(fabsf(rtb_u_b));
            } else {
              rtb_u_b = sqrtf(rtb_u_b);
            }

            /* End of Math: '<S515>/Math Function1' */

            /* Switch: '<S515>/Switch' incorporates:
             *  Constant: '<S515>/Constant'
             *  Product: '<S515>/Product'
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

            /* End of Switch: '<S515>/Switch' */

            /* Product: '<S513>/Multiply2' incorporates:
             *  Product: '<S515>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_p3p[0] / rtb_Divide_p3p[3] *
              rtb_Saturation1_d;
            rtb_Saturation1_d *= rtb_Divide_p3p[1] / rtb_Divide_p3p[3];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S468>/Sum1' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_o4 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_u_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S468>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_3 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
              [0];
            rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S468>/Divide' incorporates:
             *  Math: '<S469>/Square'
             *  Math: '<S470>/Square'
             *  Sqrt: '<S469>/Sqrt'
             *  Sqrt: '<S470>/Sqrt'
             *  Sum: '<S468>/Sum'
             *  Sum: '<S468>/Sum1'
             *  Sum: '<S469>/Sum of Elements'
             *  Sum: '<S470>/Sum of Elements'
             */
            rtb_u_b = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 + rtb_a_bx
                            * rtb_a_bx) / sqrtf(rtb_Saturation_o4 *
              rtb_Saturation_o4 + rtb_u_b * rtb_u_b);

            /* Saturate: '<S468>/Saturation' */
            if (rtb_u_b > 1.0F) {
              rtb_u_b = 1.0F;
            } else {
              if (rtb_u_b < 0.0F) {
                rtb_u_b = 0.0F;
              }
            }

            /* End of Saturate: '<S468>/Saturation' */

            /* Product: '<S466>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_Saturation1_d + rtb_VectorConcatenate_or[rtb_n] *
                rtb_Saturation_ga;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S459>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S468>/Multiply'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S459>/Sum2'
             *  Sum: '<S468>/Add'
             *  Sum: '<S468>/Subtract'
             */
            rtb_u_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_u_b +
                        FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_MatrixConcatenate1_0[0];
            rtb_Switch_c2[1] = rtb_MatrixConcatenate1_0[1];

            /* Saturate: '<S459>/Saturation1' incorporates:
             *  Product: '<S466>/Multiply'
             */
            if (rtb_u_b > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_u_b < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_u_b;
            }

            /* End of Saturate: '<S459>/Saturation1' */
          }

          /* End of Switch: '<S442>/Switch' */

          /* Delay: '<S444>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S447>/Integrator1' incorporates:
           *  Delay: '<S444>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S451>/Rem' incorporates:
           *  Constant: '<S451>/Constant1'
           *  DiscreteIntegrator: '<S447>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S446>/Sum'
           */
          rtb_Saturation_o4 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S451>/Switch' incorporates:
           *  Abs: '<S451>/Abs'
           *  Constant: '<S451>/Constant'
           *  Constant: '<S452>/Constant'
           *  Product: '<S451>/Multiply'
           *  RelationalOperator: '<S452>/Compare'
           *  Sum: '<S451>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S451>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S451>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S451>/Switch' */

          /* Gain: '<S446>/Gain2' */
          rtb_Saturation_o4 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S446>/Saturation' */
          if (rtb_Saturation_o4 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Saturation_o4 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Saturation_o4 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Saturation_o4 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S446>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S440>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S440>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S440>/Bus Assignment' incorporates:
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

          /* Math: '<S508>/Math Function1'
           *
           * About '<S508>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S508>/Math Function1' */

          /* Switch: '<S508>/Switch' incorporates:
           *  Constant: '<S508>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S508>/Product'
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

          /* End of Switch: '<S508>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S440>/Sum' incorporates:
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

          /* SignalConversion: '<S458>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S440>/Sum'
           */
          rtb_P_ap[0] = rtb_Saturation_ga;
          rtb_P_ap[1] = rtb_Saturation1_d;

          /* Math: '<S458>/Math Function' incorporates:
           *  Sum: '<S440>/Sum'
           */
          rtb_Square_ds[0] = rtb_Saturation_ga * rtb_Saturation_ga;
          rtb_Square_ds[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Sum: '<S458>/Sum of Elements' */
          rtb_u_b = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S458>/Math Function1' incorporates:
           *  Sum: '<S458>/Sum of Elements'
           *
           * About '<S458>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S458>/Math Function1' */

          /* Switch: '<S458>/Switch' incorporates:
           *  Constant: '<S458>/Constant'
           *  Product: '<S458>/Product'
           */
          if (rtb_Saturation_o4 > 0.0F) {
            rtb_Integrator1_bx = rtb_Saturation_o4;
          } else {
            rtb_Saturation_ga = 0.0F;
            rtb_Saturation1_d = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S458>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S464>/NearbyRefWP' incorporates:
           *  Constant: '<S440>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_c14,
                          &rtb_u_b);

          /* MATLAB Function: '<S464>/SearchL1RefWP' incorporates:
           *  Constant: '<S440>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_ap, &rtb_Saturation_o4);

          /* MATLAB Function: '<S464>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S464>/Switch1' incorporates:
           *  Constant: '<S501>/Constant'
           *  RelationalOperator: '<S501>/Compare'
           */
          if (rtb_u_b > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_c14[0];
            rtb_P_ap[1] = rtb_Divide_c14[1];
          } else {
            /* RelationalOperator: '<S500>/Compare' incorporates:
             *  Constant: '<S500>/Constant'
             */
            rtb_Compare_aij = (rtb_Saturation_o4 >= 0.0F);

            /* Switch: '<S464>/Switch' */
            if (!rtb_Compare_aij) {
              rtb_P_ap[0] = rtb_Square_ds[0];
              rtb_P_ap[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S464>/Switch' */
          }

          /* End of Switch: '<S464>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S465>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_Divide_lr_idx_3;
          rtb_Saturation_o4 = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S465>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S509>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S509>/Sum of Elements' incorporates:
           *  Math: '<S509>/Math Function'
           *  Sum: '<S507>/Sum of Elements'
           */
          rtb_u_b = rtb_Saturation_o4 + rtb_Divide_lr_idx_3 *
            rtb_Divide_lr_idx_3;

          /* Math: '<S509>/Math Function1' incorporates:
           *  Sum: '<S509>/Sum of Elements'
           *
           * About '<S509>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_u_b < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_u_b));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_u_b);
          }

          /* End of Math: '<S509>/Math Function1' */

          /* Switch: '<S509>/Switch' incorporates:
           *  Constant: '<S509>/Constant'
           *  Product: '<S509>/Product'
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

          /* End of Switch: '<S509>/Switch' */

          /* Product: '<S508>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S511>/Sum of Elements' incorporates:
           *  Math: '<S511>/Math Function'
           *  SignalConversion: '<S511>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S511>/Math Function1' incorporates:
           *  Sum: '<S511>/Sum of Elements'
           *
           * About '<S511>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S511>/Math Function1' */

          /* Switch: '<S511>/Switch' incorporates:
           *  Constant: '<S511>/Constant'
           *  Product: '<S511>/Product'
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

          /* End of Switch: '<S511>/Switch' */

          /* Product: '<S509>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S512>/Sum of Elements' incorporates:
           *  Math: '<S512>/Math Function'
           *  SignalConversion: '<S512>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_bx = rtb_Divide_c14[1] * rtb_Divide_c14[1] + rtb_Divide_c14[0] *
            rtb_Divide_c14[0];

          /* Math: '<S512>/Math Function1' incorporates:
           *  Sum: '<S512>/Sum of Elements'
           *
           * About '<S512>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation_o4 = -sqrtf(fabsf(rtb_a_bx));
          } else {
            rtb_Saturation_o4 = sqrtf(rtb_a_bx);
          }

          /* End of Math: '<S512>/Math Function1' */

          /* Switch: '<S512>/Switch' incorporates:
           *  Constant: '<S512>/Constant'
           *  Product: '<S512>/Product'
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

          /* End of Switch: '<S512>/Switch' */

          /* Product: '<S512>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S511>/Divide' */
          rtb_P_ap[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S458>/Divide' */
          rtb_Square_ds[0] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S512>/Divide' */
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S511>/Divide' */
          rtb_P_ap[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S458>/Divide' */
          rtb_Square_ds[1] = rtb_Saturation1_d / rtb_Integrator1_bx;

          /* Sum: '<S510>/Subtract' incorporates:
           *  Product: '<S510>/Multiply'
           *  Product: '<S510>/Multiply1'
           */
          rtb_Saturation_o4 = rtb_Divide_c14[0] * rtb_P_ap[1] - rtb_Divide_c14[1]
            * rtb_P_ap[0];

          /* Signum: '<S505>/Sign1' */
          if (rtb_Saturation_o4 < 0.0F) {
            rtb_Saturation_o4 = -1.0F;
          } else {
            if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_o4 = 1.0F;
            }
          }

          /* End of Signum: '<S505>/Sign1' */

          /* Switch: '<S505>/Switch2' incorporates:
           *  Constant: '<S505>/Constant4'
           */
          if (rtb_Saturation_o4 == 0.0F) {
            rtb_Saturation_o4 = 1.0F;
          }

          /* End of Switch: '<S505>/Switch2' */

          /* DotProduct: '<S505>/Dot Product' */
          rtb_Divide_lr_idx_3 = rtb_P_ap[0] * rtb_Divide_c14[0] + rtb_P_ap[1] *
            rtb_Divide_c14[1];

          /* Trigonometry: '<S505>/Acos' incorporates:
           *  DotProduct: '<S505>/Dot Product'
           */
          if (rtb_Divide_lr_idx_3 > 1.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 < -1.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            }
          }

          /* Product: '<S505>/Multiply' incorporates:
           *  Trigonometry: '<S505>/Acos'
           */
          rtb_Saturation_o4 *= acosf(rtb_Divide_lr_idx_3);

          /* Saturate: '<S465>/Saturation' */
          if (rtb_Saturation_o4 > 1.57079637F) {
            rtb_Saturation_o4 = 1.57079637F;
          } else {
            if (rtb_Saturation_o4 < -1.57079637F) {
              rtb_Saturation_o4 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S465>/Saturation' */

          /* Product: '<S465>/Divide' incorporates:
           *  Constant: '<S440>/L1'
           *  Constant: '<S465>/Constant'
           *  Gain: '<S465>/Gain'
           *  Math: '<S465>/Square'
           *  MinMax: '<S465>/Max'
           *  MinMax: '<S465>/Min'
           *  Product: '<S465>/Multiply1'
           *  Sqrt: '<S507>/Sqrt'
           *  Trigonometry: '<S465>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Saturation_o4) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_u_b), 0.5F));

          /* Sum: '<S456>/Subtract' incorporates:
           *  Product: '<S456>/Multiply'
           *  Product: '<S456>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S445>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S445>/Sign1' */

          /* Switch: '<S445>/Switch2' incorporates:
           *  Constant: '<S445>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S445>/Switch2' */

          /* DotProduct: '<S445>/Dot Product' */
          rtb_u_b = FMS_ConstB.Divide[0] * rtb_Square_ds[0] + FMS_ConstB.Divide
            [1] * rtb_Square_ds[1];

          /* Trigonometry: '<S445>/Acos' incorporates:
           *  DotProduct: '<S445>/Dot Product'
           */
          if (rtb_u_b > 1.0F) {
            rtb_u_b = 1.0F;
          } else {
            if (rtb_u_b < -1.0F) {
              rtb_u_b = -1.0F;
            }
          }

          /* Product: '<S445>/Multiply' incorporates:
           *  Trigonometry: '<S445>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_u_b);

          /* Math: '<S448>/Rem' incorporates:
           *  Constant: '<S448>/Constant1'
           *  Delay: '<S444>/Delay'
           *  Sum: '<S444>/Sum2'
           */
          rtb_Saturation_o4 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S448>/Switch' incorporates:
           *  Abs: '<S448>/Abs'
           *  Constant: '<S448>/Constant'
           *  Constant: '<S454>/Constant'
           *  Product: '<S448>/Multiply'
           *  RelationalOperator: '<S454>/Compare'
           *  Sum: '<S448>/Add'
           */
          if (fabsf(rtb_Saturation_o4) > 3.14159274F) {
            /* Signum: '<S448>/Sign' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation_o4;
            }

            /* End of Signum: '<S448>/Sign' */
            rtb_Saturation_o4 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S448>/Switch' */

          /* Sum: '<S444>/Sum' incorporates:
           *  Delay: '<S444>/Delay'
           */
          rtb_Saturation_ga = rtb_Saturation_o4 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S453>/Multiply1' incorporates:
           *  Constant: '<S453>/const1'
           *  DiscreteIntegrator: '<S447>/Integrator'
           */
          rtb_Saturation_o4 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S453>/Add' incorporates:
           *  DiscreteIntegrator: '<S447>/Integrator1'
           *  Sum: '<S447>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_ga)
            + rtb_Saturation_o4;

          /* Signum: '<S453>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
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
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_m) *
                           FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation_o4;

          /* Sum: '<S453>/Add4' */
          rtb_Saturation_o4 += rtb_Saturation1_d - rtb_u_b;

          /* Sum: '<S453>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_m;

          /* Sum: '<S453>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_m;

          /* Signum: '<S453>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S453>/Sign1' */

          /* Signum: '<S453>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S453>/Sign2' */

          /* Sum: '<S453>/Add5' incorporates:
           *  Gain: '<S453>/Gain2'
           *  Product: '<S453>/Multiply4'
           *  Sum: '<S453>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation_o4;

          /* Sum: '<S453>/Add6' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_m;

          /* Sum: '<S453>/Subtract3' */
          rtb_Saturation1_d = rtb_u_b - FMS_ConstB.d_m;

          /* Product: '<S453>/Divide' */
          rtb_Integrator1_bx = rtb_u_b / FMS_ConstB.d_m;

          /* Signum: '<S453>/Sign5' incorporates:
           *  Signum: '<S453>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_a_bx = -1.0F;

            /* Signum: '<S453>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_a_bx = 1.0F;

            /* Signum: '<S453>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_a_bx = rtb_u_b;

            /* Signum: '<S453>/Sign6' */
            rtb_Saturation_o4 = rtb_u_b;
          }

          /* End of Signum: '<S453>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S444>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S449>/Rem' incorporates:
           *  Constant: '<S449>/Constant1'
           */
          rtb_u_b = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S449>/Switch' incorporates:
           *  Abs: '<S449>/Abs'
           *  Constant: '<S449>/Constant'
           *  Constant: '<S455>/Constant'
           *  Product: '<S449>/Multiply'
           *  RelationalOperator: '<S455>/Compare'
           *  Sum: '<S449>/Add'
           */
          if (fabsf(rtb_u_b) > 3.14159274F) {
            /* Signum: '<S449>/Sign' */
            if (rtb_u_b < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_u_b > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_u_b;
            }

            /* End of Signum: '<S449>/Sign' */
            rtb_u_b -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S449>/Switch' */

          /* Abs: '<S442>/Abs' */
          rtb_u_b = fabsf(rtb_u_b);

          /* Update for Delay: '<S466>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S467>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S460>/Constant'
           *  RelationalOperator: '<S460>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S467>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S462>/Acceleration_Speed' incorporates:
           *  Constant: '<S462>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_o3;

          /* Product: '<S466>/Divide1' */
          rtb_u_b = rtb_Divide_lr_idx_2 / d;

          /* Saturate: '<S466>/Saturation' */
          if (rtb_u_b > 0.314159274F) {
            rtb_u_b = 0.314159274F;
          } else {
            if (rtb_u_b < -0.314159274F) {
              rtb_u_b = -0.314159274F;
            }
          }

          /* End of Saturate: '<S466>/Saturation' */

          /* Update for DiscreteIntegrator: '<S514>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_u_b;

          /* Update for Delay: '<S444>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S447>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S447>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S453>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S453>/Sign3' */

          /* Signum: '<S453>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S453>/Sign4' */

          /* Update for DiscreteIntegrator: '<S447>/Integrator' incorporates:
           *  Constant: '<S453>/const'
           *  Gain: '<S453>/Gain3'
           *  Product: '<S453>/Multiply5'
           *  Product: '<S453>/Multiply6'
           *  Sum: '<S453>/Subtract4'
           *  Sum: '<S453>/Subtract5'
           *  Sum: '<S453>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S447>/Integrator' */
          /* End of Outputs for SubSystem: '<S436>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S439>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S439>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S325>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S325>/Unknown' incorporates:
           *  ActionPort: '<S438>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S325>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
         *  ActionPort: '<S324>/Action Port'
         */
        /* SwitchCase: '<S324>/Switch Case' */
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
            /* Disable for SwitchCase: '<S423>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S339>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S357>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S373>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S398>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S385>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S324>/Acro' incorporates:
           *  ActionPort: '<S329>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S329>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S329>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Gain: '<S334>/Gain'
           *  Gain: '<S334>/Gain1'
           *  Gain: '<S334>/Gain2'
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

          /* Saturate: '<S335>/Saturation' incorporates:
           *  Constant: '<S335>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  Sum: '<S335>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_u_b = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_u_b = 0.0F;
          } else {
            rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S335>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S335>/Constant5'
           *  Gain: '<S335>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S335>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_u_b), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S324>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S324>/Stabilize' incorporates:
             *  ActionPort: '<S332>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S324>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S419>/Integrator'
             *  DiscreteIntegrator: '<S419>/Integrator1'
             *  DiscreteIntegrator: '<S420>/Integrator'
             *  DiscreteIntegrator: '<S420>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S324>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S324>/Stabilize' incorporates:
             *  ActionPort: '<S332>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S324>/Switch Case' incorporates:
             *  Chart: '<S424>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S324>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S324>/Stabilize' incorporates:
           *  ActionPort: '<S332>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S414>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_Compare_o3 = !FMS_B.Compare;

          /* Chart: '<S424>/Motion State' incorporates:
           *  Abs: '<S424>/Abs'
           *  Abs: '<S424>/Abs1'
           *  Constant: '<S434>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S434>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S423>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S423>/Hold Control' incorporates:
               *  ActionPort: '<S426>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S423>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S423>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S423>/Hold Control' incorporates:
             *  ActionPort: '<S426>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S423>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S423>/Brake Control' incorporates:
             *  ActionPort: '<S425>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S423>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S423>/Move Control' incorporates:
               *  ActionPort: '<S427>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S423>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S423>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S423>/Move Control' incorporates:
             *  ActionPort: '<S427>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S423>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S423>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S416>/Switch' incorporates:
           *  Constant: '<S416>/Constant'
           *  Constant: '<S416>/Constant4'
           *  Constant: '<S416>/Constant5'
           *  Gain: '<S416>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S416>/Saturation'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S416>/Add'
           *  Sum: '<S416>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S416>/Saturation' */
              rtb_u_b = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S416>/Saturation' */
              rtb_u_b = 0.0F;
            } else {
              /* Saturate: '<S416>/Saturation' incorporates:
               *  Constant: '<S416>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S43>/Signal Copy2'
               *  Sum: '<S416>/Sum'
               */
              rtb_u_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_u_b),
              65536.0F) + 1000U);
          }

          /* End of Switch: '<S416>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S332>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S332>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S414>/Data Type Conversion'
           *  DiscreteIntegrator: '<S419>/Integrator1'
           *  DiscreteIntegrator: '<S420>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S414>/Multiply'
           *  Product: '<S414>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S423>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S423>/Saturation' */

          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S422>/Multiply1' incorporates:
           *  Constant: '<S422>/const1'
           *  DiscreteIntegrator: '<S420>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S418>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S418>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S422>/Add' incorporates:
           *  DiscreteIntegrator: '<S420>/Integrator1'
           *  Gain: '<S414>/Gain1'
           *  Gain: '<S418>/Gain'
           *  Sum: '<S420>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S422>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S422>/Sign' */

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
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_g) * FMS_ConstB.d_g)
               - FMS_ConstB.d_g) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S422>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S422>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_g;

          /* Sum: '<S422>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_g;

          /* Signum: '<S422>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign1' */

          /* Signum: '<S422>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign2' */

          /* Sum: '<S422>/Add5' incorporates:
           *  Gain: '<S422>/Gain2'
           *  Product: '<S422>/Multiply4'
           *  Sum: '<S422>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S422>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_g;

          /* Sum: '<S422>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_g;

          /* Product: '<S422>/Divide' */
          rtb_Divide_lr_idx_3 = d / FMS_ConstB.d_g;

          /* Signum: '<S422>/Sign5' incorporates:
           *  Signum: '<S422>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S422>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S422>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = d;

            /* Signum: '<S422>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S422>/Sign5' */

          /* Product: '<S421>/Multiply1' incorporates:
           *  Constant: '<S421>/const1'
           *  DiscreteIntegrator: '<S419>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S417>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S417>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S421>/Add' incorporates:
           *  DiscreteIntegrator: '<S419>/Integrator1'
           *  Gain: '<S414>/Gain'
           *  Gain: '<S417>/Gain'
           *  Sum: '<S419>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S421>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
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
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_a) * FMS_ConstB.d_a)
               - FMS_ConstB.d_a) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S421>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S421>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_a;

          /* Sum: '<S421>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_a;

          /* Signum: '<S421>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign1' */

          /* Signum: '<S421>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign2' */

          /* Sum: '<S421>/Add5' incorporates:
           *  Gain: '<S421>/Gain2'
           *  Product: '<S421>/Multiply4'
           *  Sum: '<S421>/Subtract2'
           */
          d += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S419>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S419>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S420>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S420>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S422>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign3' */

          /* Signum: '<S422>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign4' */

          /* Update for DiscreteIntegrator: '<S420>/Integrator' incorporates:
           *  Constant: '<S422>/const'
           *  Gain: '<S422>/Gain3'
           *  Product: '<S422>/Multiply5'
           *  Product: '<S422>/Multiply6'
           *  Sum: '<S422>/Subtract4'
           *  Sum: '<S422>/Subtract5'
           *  Sum: '<S422>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Divide_lr_idx_3 -
            rtb_Integrator1_bx) * FMS_ConstB.Gain4_o * ((rtb_Saturation_ga -
            rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4 * 12.566371F) *
            0.004F;

          /* Sum: '<S421>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_a;

          /* Sum: '<S421>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_a;

          /* Signum: '<S421>/Sign5' incorporates:
           *  Signum: '<S421>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S421>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S421>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S421>/Sign6' */
            rtb_Divide_lr_idx_3 = d;
          }

          /* End of Signum: '<S421>/Sign5' */

          /* Signum: '<S421>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign3' */

          /* Signum: '<S421>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign4' */

          /* Update for DiscreteIntegrator: '<S419>/Integrator' incorporates:
           *  Constant: '<S421>/const'
           *  Gain: '<S421>/Gain3'
           *  Product: '<S421>/Divide'
           *  Product: '<S421>/Multiply5'
           *  Product: '<S421>/Multiply6'
           *  Sum: '<S421>/Subtract4'
           *  Sum: '<S421>/Subtract5'
           *  Sum: '<S421>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((d / FMS_ConstB.d_a - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_k * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S324>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S324>/Altitude' incorporates:
             *  ActionPort: '<S330>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S324>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S353>/Integrator'
             *  DiscreteIntegrator: '<S353>/Integrator1'
             *  DiscreteIntegrator: '<S354>/Integrator'
             *  DiscreteIntegrator: '<S354>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S324>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S324>/Altitude' incorporates:
             *  ActionPort: '<S330>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S324>/Switch Case' incorporates:
             *  Chart: '<S340>/Motion Status'
             *  Chart: '<S358>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S324>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S324>/Altitude' incorporates:
           *  ActionPort: '<S330>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S340>/Motion Status' incorporates:
           *  Abs: '<S340>/Abs'
           *  Abs: '<S340>/Abs1'
           *  Constant: '<S349>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S349>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S339>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S339>/Hold Control' incorporates:
               *  ActionPort: '<S342>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S339>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S339>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S339>/Hold Control' incorporates:
             *  ActionPort: '<S342>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S339>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S339>/Brake Control' incorporates:
             *  ActionPort: '<S341>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S339>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S339>/Move Control' incorporates:
             *  ActionPort: '<S343>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S339>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S339>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S336>/Switch' incorporates:
           *  Constant: '<S336>/Constant'
           *  Saturate: '<S339>/Saturation1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_ga = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S339>/Saturation1' */
            rtb_Saturation_ga = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S339>/Saturation1' */
            rtb_Saturation_ga = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S339>/Saturation1' */
            rtb_Saturation_ga = FMS_B.Merge_l;
          }

          /* End of Switch: '<S336>/Switch' */

          /* Logic: '<S337>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_Compare_o3 = !FMS_B.Compare;

          /* Chart: '<S358>/Motion State' incorporates:
           *  Abs: '<S358>/Abs'
           *  Abs: '<S358>/Abs1'
           *  Constant: '<S368>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S368>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S357>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S357>/Hold Control' incorporates:
               *  ActionPort: '<S360>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S357>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_pi);

              /* End of SystemReset for SubSystem: '<S357>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S357>/Hold Control' incorporates:
             *  ActionPort: '<S360>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_pi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S357>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S357>/Brake Control' incorporates:
             *  ActionPort: '<S359>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S357>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S357>/Move Control' incorporates:
               *  ActionPort: '<S361>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S357>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S357>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S357>/Move Control' incorporates:
             *  ActionPort: '<S361>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S357>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S357>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S330>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S330>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S330>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S337>/Data Type Conversion'
           *  DiscreteIntegrator: '<S353>/Integrator1'
           *  DiscreteIntegrator: '<S354>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S337>/Multiply'
           *  Product: '<S337>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S357>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S330>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S330>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S330>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S357>/Saturation' */

          /* BusAssignment: '<S330>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;

          /* Product: '<S356>/Multiply1' incorporates:
           *  Constant: '<S356>/const1'
           *  DiscreteIntegrator: '<S354>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S352>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S352>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S356>/Add' incorporates:
           *  DiscreteIntegrator: '<S354>/Integrator1'
           *  Gain: '<S337>/Gain1'
           *  Gain: '<S352>/Gain'
           *  Sum: '<S354>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
                      FMS_PARAM.PITCH_DZ) * rtb_u_b * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S356>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S356>/Sign' */

          /* Sum: '<S356>/Add2' incorporates:
           *  Abs: '<S356>/Abs'
           *  Gain: '<S356>/Gain'
           *  Gain: '<S356>/Gain1'
           *  Product: '<S356>/Multiply2'
           *  Product: '<S356>/Multiply3'
           *  Sqrt: '<S356>/Sqrt'
           *  Sum: '<S356>/Add1'
           *  Sum: '<S356>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_o) * FMS_ConstB.d_o)
               - FMS_ConstB.d_o) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S356>/Add4' */
          rtb_Saturation1_d = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S356>/Add3' */
          rtb_Saturation_ga = rtb_u_b + FMS_ConstB.d_o;

          /* Sum: '<S356>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_o;

          /* Signum: '<S356>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign1' */

          /* Signum: '<S356>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign2' */

          /* Sum: '<S356>/Add5' incorporates:
           *  Gain: '<S356>/Gain2'
           *  Product: '<S356>/Multiply4'
           *  Sum: '<S356>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_u_b) * 0.5F * rtb_Saturation1_d;

          /* Sum: '<S356>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_o;

          /* Sum: '<S356>/Subtract3' */
          rtb_Saturation1_d = d - FMS_ConstB.d_o;

          /* Product: '<S356>/Divide' */
          rtb_Divide_lr_idx_3 = d / FMS_ConstB.d_o;

          /* Signum: '<S356>/Sign5' incorporates:
           *  Signum: '<S356>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S356>/Sign6' */
            rtb_Saturation_o4 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S356>/Sign6' */
            rtb_Saturation_o4 = 1.0F;
          } else {
            rtb_Integrator1_bx = d;

            /* Signum: '<S356>/Sign6' */
            rtb_Saturation_o4 = d;
          }

          /* End of Signum: '<S356>/Sign5' */

          /* Product: '<S355>/Multiply1' incorporates:
           *  Constant: '<S355>/const1'
           *  DiscreteIntegrator: '<S353>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S351>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S351>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S355>/Add' incorporates:
           *  DiscreteIntegrator: '<S353>/Integrator1'
           *  Gain: '<S337>/Gain'
           *  Gain: '<S351>/Gain'
           *  Sum: '<S353>/Subtract'
           */
          rtb_u_b = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
                      FMS_PARAM.ROLL_DZ) * rtb_u_b * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S355>/Sign' */
          if (rtb_u_b < 0.0F) {
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            d = 1.0F;
          } else {
            d = rtb_u_b;
          }

          /* End of Signum: '<S355>/Sign' */

          /* Sum: '<S355>/Add2' incorporates:
           *  Abs: '<S355>/Abs'
           *  Gain: '<S355>/Gain'
           *  Gain: '<S355>/Gain1'
           *  Product: '<S355>/Multiply2'
           *  Product: '<S355>/Multiply3'
           *  Sqrt: '<S355>/Sqrt'
           *  Sum: '<S355>/Add1'
           *  Sum: '<S355>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_u_b) + FMS_ConstB.d_c) * FMS_ConstB.d_c)
               - FMS_ConstB.d_c) * 0.5F * d + rtb_Divide_lr_idx_2;

          /* Sum: '<S355>/Add4' */
          rtb_a_bx = (rtb_u_b - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S355>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_u_b + FMS_ConstB.d_c;

          /* Sum: '<S355>/Subtract1' */
          rtb_u_b -= FMS_ConstB.d_c;

          /* Signum: '<S355>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S355>/Sign1' */

          /* Signum: '<S355>/Sign2' */
          if (rtb_u_b < 0.0F) {
            rtb_u_b = -1.0F;
          } else {
            if (rtb_u_b > 0.0F) {
              rtb_u_b = 1.0F;
            }
          }

          /* End of Signum: '<S355>/Sign2' */

          /* Sum: '<S355>/Add5' incorporates:
           *  Gain: '<S355>/Gain2'
           *  Product: '<S355>/Multiply4'
           *  Sum: '<S355>/Subtract2'
           */
          d += (rtb_Divide_lr_idx_2 - rtb_u_b) * 0.5F * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S353>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S353>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S354>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S354>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S356>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign3' */

          /* Signum: '<S356>/Sign4' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign4' */

          /* Update for DiscreteIntegrator: '<S354>/Integrator' incorporates:
           *  Constant: '<S356>/const'
           *  Gain: '<S356>/Gain3'
           *  Product: '<S356>/Multiply5'
           *  Product: '<S356>/Multiply6'
           *  Sum: '<S356>/Subtract4'
           *  Sum: '<S356>/Subtract5'
           *  Sum: '<S356>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Divide_lr_idx_3 -
            rtb_Integrator1_bx) * FMS_ConstB.Gain4_c * ((rtb_Saturation_ga -
            rtb_Saturation1_d) * 0.5F) - rtb_Saturation_o4 * 12.566371F) *
            0.004F;

          /* Sum: '<S355>/Subtract3' */
          rtb_Saturation_ga = d - FMS_ConstB.d_c;

          /* Sum: '<S355>/Add6' */
          rtb_Saturation1_d = d + FMS_ConstB.d_c;

          /* Signum: '<S355>/Sign5' incorporates:
           *  Signum: '<S355>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Saturation_o4 = -1.0F;

            /* Signum: '<S355>/Sign6' */
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Saturation_o4 = 1.0F;

            /* Signum: '<S355>/Sign6' */
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Saturation_o4 = d;

            /* Signum: '<S355>/Sign6' */
            rtb_Divide_lr_idx_3 = d;
          }

          /* End of Signum: '<S355>/Sign5' */

          /* Signum: '<S355>/Sign3' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S355>/Sign3' */

          /* Signum: '<S355>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S355>/Sign4' */

          /* Update for DiscreteIntegrator: '<S353>/Integrator' incorporates:
           *  Constant: '<S355>/const'
           *  Gain: '<S355>/Gain3'
           *  Product: '<S355>/Divide'
           *  Product: '<S355>/Multiply5'
           *  Product: '<S355>/Multiply6'
           *  Sum: '<S355>/Subtract4'
           *  Sum: '<S355>/Subtract5'
           *  Sum: '<S355>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((d / FMS_ConstB.d_c - rtb_Saturation_o4)
            * FMS_ConstB.Gain4_h * ((rtb_Saturation1_d - rtb_Saturation_ga) *
            0.5F) - rtb_Divide_lr_idx_3 * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S324>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S324>/Position' incorporates:
             *  ActionPort: '<S331>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S324>/Switch Case' incorporates:
             *  Chart: '<S374>/Motion Status'
             *  Chart: '<S386>/Motion State'
             *  Chart: '<S399>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S324>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S324>/Position' incorporates:
           *  ActionPort: '<S331>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S374>/Motion Status' incorporates:
           *  Abs: '<S374>/Abs'
           *  Abs: '<S374>/Abs1'
           *  Constant: '<S383>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S383>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S373>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S373>/Hold Control' incorporates:
               *  ActionPort: '<S376>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S373>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S373>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S373>/Hold Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S373>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S373>/Brake Control' incorporates:
             *  ActionPort: '<S375>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S373>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S373>/Move Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S373>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S373>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S386>/Motion State' incorporates:
           *  Abs: '<S386>/Abs'
           *  Abs: '<S386>/Abs1'
           *  Constant: '<S396>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S396>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S399>/Logical Operator' incorporates:
           *  Abs: '<S399>/Abs1'
           *  Abs: '<S399>/Abs2'
           *  Constant: '<S411>/Constant'
           *  Constant: '<S412>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S411>/Compare'
           *  RelationalOperator: '<S412>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtb_Compare_o3 = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                             FMS_PARAM.PITCH_DZ) || (fabsf
            (FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S399>/Motion State' */
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

          /* End of Chart: '<S399>/Motion State' */

          /* SwitchCase: '<S398>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S398>/Hold Control' incorporates:
               *  ActionPort: '<S400>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S398>/Switch Case' incorporates:
               *  Delay: '<S400>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S398>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S398>/Hold Control' incorporates:
             *  ActionPort: '<S400>/Action Port'
             */
            /* Delay: '<S400>/Delay' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            if (FMS_DW.icLoad != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Trigonometry: '<S404>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* Trigonometry: '<S404>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_d;

            /* SignalConversion: '<S404>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S404>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S404>/Gain' incorporates:
             *  Gain: '<S403>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S404>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S404>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* SignalConversion: '<S404>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S404>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* SignalConversion: '<S404>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S400>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S400>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S400>/Sum'
             */
            d = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Integrator1_bx = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S400>/Multiply' incorporates:
             *  SignalConversion: '<S400>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] * d;
            }

            /* End of Product: '<S400>/Multiply' */

            /* Gain: '<S400>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

            /* Update for Delay: '<S400>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S398>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S398>/Move Control' incorporates:
               *  ActionPort: '<S401>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S398>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S407>/Integrator'
               *  DiscreteIntegrator: '<S407>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S398>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S398>/Move Control' incorporates:
             *  ActionPort: '<S401>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S405>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S405>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S405>/Gain' */
            rtb_Saturation_o4 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u_b;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S406>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S406>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S406>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u_b;

            /* Sum: '<S408>/Sum of Elements' incorporates:
             *  Math: '<S408>/Square'
             *  SignalConversion: '<S408>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S409>/Sum of Elements'
             *  Switch: '<S401>/Switch'
             */
            rtb_u_b = rtb_Saturation_o4 * rtb_Saturation_o4 +
              rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

            /* Switch: '<S401>/Switch' incorporates:
             *  Product: '<S409>/Divide'
             *  Sqrt: '<S408>/Sqrt'
             *  Sum: '<S408>/Sum of Elements'
             */
            if (sqrtf(rtb_u_b) > 1.0F) {
              /* Math: '<S409>/Math Function1'
               *
               * About '<S409>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_u_b < 0.0F) {
                rtb_Saturation_ga = -sqrtf(fabsf(rtb_u_b));
              } else {
                rtb_Saturation_ga = sqrtf(rtb_u_b);
              }

              /* End of Math: '<S409>/Math Function1' */

              /* Switch: '<S409>/Switch' incorporates:
               *  Constant: '<S409>/Constant'
               *  Product: '<S409>/Product'
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

              /* End of Switch: '<S409>/Switch' */
              rtb_Saturation_o4 = rtb_MatrixConcatenate3[0] /
                rtb_MatrixConcatenate3[2];
              rtb_Divide_lr_idx_2 = rtb_MatrixConcatenate3[1] /
                rtb_MatrixConcatenate3[2];
            }

            /* Product: '<S410>/Multiply1' incorporates:
             *  Constant: '<S410>/const1'
             *  DiscreteIntegrator: '<S407>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S410>/Add' incorporates:
             *  DiscreteIntegrator: '<S407>/Integrator1'
             *  Gain: '<S401>/Gain6'
             *  Sum: '<S407>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE[0] -
              FMS_PARAM.VEL_XY_LIM * rtb_Saturation_o4) + rtb_Saturation1_d;

            /* Signum: '<S410>/Sign' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Divide_lr_idx_3;
            }

            /* Sum: '<S410>/Add2' incorporates:
             *  Abs: '<S410>/Abs'
             *  Gain: '<S410>/Gain'
             *  Gain: '<S410>/Gain1'
             *  Product: '<S410>/Multiply2'
             *  Product: '<S410>/Multiply3'
             *  Sqrt: '<S410>/Sqrt'
             *  Sum: '<S410>/Add1'
             *  Sum: '<S410>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S410>/Add4' */
            rtb_Saturation1_d += rtb_Divide_lr_idx_3 - rtb_Saturation_o4;

            /* Sum: '<S410>/Add3' */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d;

            /* Sum: '<S410>/Subtract1' */
            rtb_Divide_lr_idx_3 -= FMS_ConstB.d;

            /* Signum: '<S410>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S410>/Sign2' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_3 > 0.0F) {
                rtb_Divide_lr_idx_3 = 1.0F;
              }
            }

            /* Sum: '<S410>/Add5' incorporates:
             *  Gain: '<S410>/Gain2'
             *  Product: '<S410>/Multiply4'
             *  Sum: '<S410>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Divide_lr_idx_3) *
              0.5F * rtb_Saturation1_d;

            /* SignalConversion: '<S407>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S407>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S407>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S407>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S410>/Sign4' incorporates:
             *  Sum: '<S410>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S410>/Sign3' incorporates:
             *  Sum: '<S410>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S410>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S410>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S410>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S410>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S407>/Integrator' incorporates:
             *  Constant: '<S410>/const'
             *  Gain: '<S410>/Gain3'
             *  Product: '<S410>/Divide'
             *  Product: '<S410>/Multiply5'
             *  Product: '<S410>/Multiply6'
             *  Sum: '<S410>/Subtract4'
             *  Sum: '<S410>/Subtract5'
             *  Sum: '<S410>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 39.224F) *
              0.004F;

            /* Product: '<S410>/Multiply1' incorporates:
             *  Constant: '<S410>/const1'
             *  DiscreteIntegrator: '<S407>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S410>/Add' incorporates:
             *  DiscreteIntegrator: '<S407>/Integrator1'
             *  Gain: '<S401>/Gain6'
             *  Sum: '<S407>/Subtract'
             */
            rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE[1] -
              FMS_PARAM.VEL_XY_LIM * rtb_Divide_lr_idx_2) + rtb_Saturation1_d;

            /* Signum: '<S410>/Sign' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Divide_lr_idx_3;
            }

            /* Sum: '<S410>/Add2' incorporates:
             *  Abs: '<S410>/Abs'
             *  Gain: '<S410>/Gain'
             *  Gain: '<S410>/Gain1'
             *  Product: '<S410>/Multiply2'
             *  Product: '<S410>/Multiply3'
             *  Sqrt: '<S410>/Sqrt'
             *  Sum: '<S410>/Add1'
             *  Sum: '<S410>/Subtract'
             */
            rtb_Saturation_o4 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S410>/Add4' */
            rtb_Saturation1_d += rtb_Divide_lr_idx_3 - rtb_Saturation_o4;

            /* Sum: '<S410>/Add3' */
            rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d;

            /* Sum: '<S410>/Subtract1' */
            rtb_Divide_lr_idx_3 -= FMS_ConstB.d;

            /* Signum: '<S410>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S410>/Sign2' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_3 > 0.0F) {
                rtb_Divide_lr_idx_3 = 1.0F;
              }
            }

            /* Sum: '<S410>/Add5' incorporates:
             *  Gain: '<S410>/Gain2'
             *  Product: '<S410>/Multiply4'
             *  Sum: '<S410>/Subtract2'
             */
            rtb_Saturation_o4 += (rtb_Saturation_ga - rtb_Divide_lr_idx_3) *
              0.5F * rtb_Saturation1_d;

            /* SignalConversion: '<S407>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S407>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S407>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S407>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S410>/Sign4' incorporates:
             *  Sum: '<S410>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Saturation_o4 - FMS_ConstB.d;

            /* Signum: '<S410>/Sign3' incorporates:
             *  Sum: '<S410>/Add6'
             */
            rtb_Saturation1_d = rtb_Saturation_o4 + FMS_ConstB.d;

            /* Signum: '<S410>/Sign5' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_u_b = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_u_b = 1.0F;
            } else {
              rtb_u_b = rtb_Saturation_o4;
            }

            /* Signum: '<S410>/Sign3' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* Signum: '<S410>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S410>/Sign6' */
            if (rtb_Saturation_o4 < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_o4 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_o4;
            }

            /* Update for DiscreteIntegrator: '<S407>/Integrator' incorporates:
             *  Constant: '<S410>/const'
             *  Gain: '<S410>/Gain3'
             *  Product: '<S410>/Divide'
             *  Product: '<S410>/Multiply5'
             *  Product: '<S410>/Multiply6'
             *  Sum: '<S410>/Subtract4'
             *  Sum: '<S410>/Subtract5'
             *  Sum: '<S410>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Saturation_o4 / FMS_ConstB.d -
              rtb_u_b) * FMS_ConstB.Gain4 * ((rtb_Saturation1_d -
              rtb_Saturation_ga) * 0.5F) - rtb_Divide_lr_idx_3 * 39.224F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S398>/Move Control' */
            break;
          }

          /* SwitchCase: '<S385>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S385>/Hold Control' incorporates:
               *  ActionPort: '<S388>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S385>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S385>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S385>/Hold Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S385>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S385>/Brake Control' incorporates:
             *  ActionPort: '<S387>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S385>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S385>/Move Control' incorporates:
               *  ActionPort: '<S389>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S385>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S385>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S385>/Move Control' incorporates:
             *  ActionPort: '<S389>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S385>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S385>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S331>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S331>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S331>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S385>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S385>/Saturation' */

          /* Saturate: '<S398>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S398>/Saturation1' */

          /* Saturate: '<S373>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S373>/Saturation1' */
          /* End of Outputs for SubSystem: '<S324>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S324>/Unknown' incorporates:
           *  ActionPort: '<S333>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S324>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S50>/Manual' incorporates:
         *  ActionPort: '<S326>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S326>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S326>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S326>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S326>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S50>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S50>/Unknown' incorporates:
         *  ActionPort: '<S328>/Action Port'
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
   *  DiscreteIntegrator: '<S769>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S769>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S769>/Constant'
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

  /* Update for DiscreteIntegrator: '<S801>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S801>/Gain'
   *  Sum: '<S801>/Sum5'
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

  /* Update for DiscreteIntegrator: '<S803>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S803>/Gain'
   *  Sum: '<S803>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_L_af = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S802>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S802>/Gain'
   *  Sum: '<S802>/Sum5'
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
  /* Start for SwitchCase: '<S112>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S49>/SubMode' */

  /* Start for IfAction SubSystem: '<S49>/Auto' */
  /* Start for SwitchCase: '<S110>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;

  /* End of Start for SubSystem: '<S49>/Auto' */

  /* Start for IfAction SubSystem: '<S49>/Assist' */
  /* Start for SwitchCase: '<S109>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S109>/Altitude' */
  /* Start for SwitchCase: '<S122>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ah = -1;

  /* End of Start for SubSystem: '<S109>/Altitude' */

  /* Start for IfAction SubSystem: '<S109>/Position' */
  /* Start for SwitchCase: '<S162>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S147>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S109>/Position' */
  /* End of Start for SubSystem: '<S49>/Assist' */
  /* End of Start for SubSystem: '<S44>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S44>/BackwardTrans_Mode' */
  /* Start for SwitchCase: '<S53>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ff = -1;

  /* End of Start for SubSystem: '<S44>/BackwardTrans_Mode' */

  /* Start for IfAction SubSystem: '<S44>/MC_Mode' */
  /* Start for SwitchCase: '<S50>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S50>/SubMode' */
  /* Start for SwitchCase: '<S327>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S327>/Return' */
  /* Start for SwitchCase: '<S727>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S717>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S327>/Return' */

  /* Start for IfAction SubSystem: '<S327>/Hold' */
  /* Start for SwitchCase: '<S666>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S634>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S645>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S327>/Hold' */
  /* End of Start for SubSystem: '<S50>/SubMode' */

  /* Start for IfAction SubSystem: '<S50>/Auto' */
  /* Start for SwitchCase: '<S325>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S325>/Mission' */
  /* Start for Resettable SubSystem: '<S436>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S487>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S477>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S436>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S325>/Mission' */
  /* End of Start for SubSystem: '<S50>/Auto' */

  /* Start for IfAction SubSystem: '<S50>/Assist' */
  /* Start for SwitchCase: '<S324>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S324>/Stabilize' */
  /* Start for SwitchCase: '<S423>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S324>/Stabilize' */

  /* Start for IfAction SubSystem: '<S324>/Altitude' */
  /* Start for SwitchCase: '<S339>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S357>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S324>/Altitude' */

  /* Start for IfAction SubSystem: '<S324>/Position' */
  /* Start for SwitchCase: '<S373>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S398>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S385>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S324>/Position' */
  /* End of Start for SubSystem: '<S50>/Assist' */
  /* End of Start for SubSystem: '<S44>/MC_Mode' */
  /* End of Start for SubSystem: '<S42>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S801>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S803>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_L_af = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S802>/Discrete-Time Integrator5' */
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
  /* SystemInitialize for IfAction SubSystem: '<S112>/Hold' */
  /* InitializeConditions for Delay: '<S267>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S262>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S112>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S49>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S110>/Mission' */
  /* InitializeConditions for UnitDelay: '<S226>/Delay Input1'
   *
   * Block description for '<S226>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S223>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_li = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator' */
  FMS_DW.Integrator_DSTATE_fk = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S223>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S110>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S49>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S109>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S216>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_oo = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S221>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jv = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S221>/Integrator' */
  FMS_DW.Integrator_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integrator' */
  FMS_DW.Integrator_DSTATE_hd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator' */
  FMS_DW.Integrator_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
  FMS_DW.Integrator_DSTATE_er = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* SystemInitialize for Chart: '<S123>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S122>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S122>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S122>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S122>/Move Control' */

  /* SystemInitialize for Merge: '<S122>/Merge' */
  FMS_B.Merge_lj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator' */
  FMS_DW.Integrator_DSTATE_c5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l5 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S148>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S163>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S162>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_b, &FMS_DW.HoldControl_b);

  /* End of SystemInitialize for SubSystem: '<S162>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S147>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S147>/Move Control' */

  /* SystemInitialize for Merge: '<S147>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S162>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/Position' */
  /* End of SystemInitialize for SubSystem: '<S49>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S44>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/BackwardTrans_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S103>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mb = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_hf = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator' */
  FMS_DW.Integrator_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S103>/Integrator' */
  FMS_DW.Integrator_DSTATE_oy = 0.0F;

  /* SystemInitialize for Chart: '<S54>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for IfAction SubSystem: '<S53>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_ConstB.HoldControl_p, &FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S53>/Hold Control' */

  /* SystemInitialize for Merge: '<S53>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S44>/BackwardTrans_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S44>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S50>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S327>/Takeoff' */
  /* InitializeConditions for Delay: '<S767>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S763>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S327>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S327>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S682>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S682>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S327>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S327>/Return' */
  /* InitializeConditions for Delay: '<S712>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S713>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S708>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S754>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S691>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S694>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S694>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S728>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S727>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S727>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S727>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S727>/Move Control' */

  /* SystemInitialize for Merge: '<S727>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S718>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S717>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S717>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S717>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_cg);

  /* End of SystemInitialize for SubSystem: '<S717>/Move Control' */

  /* SystemInitialize for Merge: '<S717>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S327>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S327>/Hold' */
  /* InitializeConditions for Delay: '<S647>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S659>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S659>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S635>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S646>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S667>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S666>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S666>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S666>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S666>/Move Control' */

  /* SystemInitialize for Merge: '<S666>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S634>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S634>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S634>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S634>/Move Control' */

  /* SystemInitialize for Merge: '<S634>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S645>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S645>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S645>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S645>/Move Control' */

  /* SystemInitialize for Merge: '<S645>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S327>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S50>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S325>/Mission' */
  /* InitializeConditions for UnitDelay: '<S439>/Delay Input1'
   *
   * Block description for '<S439>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S436>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S466>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S467>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S462>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S514>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S444>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S447>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S447>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S488>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S487>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S487>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S487>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S497>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S497>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S487>/Move Control' */

  /* SystemInitialize for Merge: '<S487>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S487>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S497>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S497>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S487>/Move Control' */

  /* SystemInitialize for Merge: '<S487>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S478>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S477>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S477>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S477>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S484>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S484>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S477>/Move Control' */

  /* SystemInitialize for Merge: '<S477>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S436>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S325>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S50>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S324>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S420>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S420>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S424>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S423>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S423>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S423>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S423>/Move Control' */

  /* SystemInitialize for Merge: '<S423>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S324>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S324>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S353>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S353>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S340>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S339>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S339>/Hold Control' */

  /* SystemInitialize for Merge: '<S339>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S358>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S357>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_pi);

  /* End of SystemInitialize for SubSystem: '<S357>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S357>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S357>/Move Control' */

  /* SystemInitialize for Merge: '<S357>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S324>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S324>/Position' */
  /* SystemInitialize for Chart: '<S374>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S373>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S373>/Hold Control' */

  /* SystemInitialize for Chart: '<S386>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S399>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S398>/Hold Control' */
  /* InitializeConditions for Delay: '<S400>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S398>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S398>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S407>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S407>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S398>/Move Control' */

  /* SystemInitialize for Merge: '<S398>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S398>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S407>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S407>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S398>/Move Control' */

  /* SystemInitialize for Merge: '<S398>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S373>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S385>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S385>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S385>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S385>/Move Control' */

  /* SystemInitialize for Merge: '<S385>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S324>/Position' */
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
