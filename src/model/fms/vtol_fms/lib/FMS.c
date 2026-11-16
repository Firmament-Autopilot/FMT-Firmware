/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2602
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov 16 10:22:39 2026
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

/* Named constants for Chart: '<S425>/Motion State' */
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
                                        *   '<S781>/Constant1'
                                        *   '<S782>/Constant'
                                        *   '<S784>/Constant1'
                                        *   '<S785>/FW_ACCEPT_R'
                                        *   '<S785>/MC_ACCEPT_R'
                                        *   '<S788>/Constant'
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
                                        *   '<S254>/Dead Zone'
                                        *   '<S254>/Gain'
                                        *   '<S255>/Dead Zone'
                                        *   '<S255>/Gain'
                                        *   '<S256>/Dead Zone'
                                        *   '<S256>/Gain'
                                        *   '<S257>/Dead Zone'
                                        *   '<S257>/Gain'
                                        *   '<S260>/Constant4'
                                        *   '<S261>/Constant4'
                                        *   '<S634>/L1'
                                        *   '<S56>/L1'
                                        *   '<S57>/Gain6'
                                        *   '<S95>/Constant'
                                        *   '<S96>/Constant'
                                        *   '<S119>/Gain'
                                        *   '<S120>/Gain1'
                                        *   '<S121>/Saturation1'
                                        *   '<S144>/Gain1'
                                        *   '<S146>/Saturation1'
                                        *   '<S212>/Gain'
                                        *   '<S212>/Gain1'
                                        *   '<S213>/Gain1'
                                        *   '<S263>/Gain2'
                                        *   '<S263>/Saturation1'
                                        *   '<S264>/L1'
                                        *   '<S264>/R'
                                        *   '<S264>/Saturation1'
                                        *   '<S281>/Gain'
                                        *   '<S281>/Saturation1'
                                        *   '<S303>/Gain'
                                        *   '<S303>/Saturation1'
                                        *   '<S338>/Gain'
                                        *   '<S338>/Gain1'
                                        *   '<S415>/Gain'
                                        *   '<S415>/Gain1'
                                        *   '<S417>/Constant'
                                        *   '<S441>/L1'
                                        *   '<S527>/Saturation'
                                        *   '<S528>/Saturation1'
                                        *   '<S528>/Saturation2'
                                        *   '<S528>/Saturation3'
                                        *   '<S685>/Land_Speed'
                                        *   '<S686>/Saturation1'
                                        *   '<S770>/Takeoff_Speed'
                                        *   '<S771>/Gain2'
                                        *   '<S771>/Saturation1'
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
                                        *   '<S209>/Constant'
                                        *   '<S209>/Constant1'
                                        *   '<S209>/Constant2'
                                        *   '<S215>/Dead Zone'
                                        *   '<S215>/Gain'
                                        *   '<S216>/Dead Zone'
                                        *   '<S216>/Gain'
                                        *   '<S221>/Dead Zone'
                                        *   '<S221>/Gain'
                                        *   '<S229>/Gain'
                                        *   '<S229>/Saturation1'
                                        *   '<S230>/Constant4'
                                        *   '<S230>/Saturation'
                                        *   '<S286>/L1'
                                        *   '<S286>/Saturation1'
                                        *   '<S308>/L1'
                                        *   '<S308>/Saturation1'
                                        *   '<S340>/Saturation1'
                                        *   '<S352>/Dead Zone'
                                        *   '<S352>/Gain'
                                        *   '<S353>/Dead Zone'
                                        *   '<S353>/Gain'
                                        *   '<S358>/Saturation'
                                        *   '<S374>/Saturation1'
                                        *   '<S386>/Saturation'
                                        *   '<S399>/Saturation1'
                                        *   '<S418>/Dead Zone'
                                        *   '<S418>/Gain'
                                        *   '<S419>/Dead Zone'
                                        *   '<S419>/Gain'
                                        *   '<S424>/Saturation'
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
                                        *   '<S124>/Gain2'
                                        *   '<S125>/Gain1'
                                        *   '<S132>/Constant'
                                        *   '<S149>/Gain2'
                                        *   '<S150>/Gain1'
                                        *   '<S157>/Constant'
                                        *   '<S164>/L1'
                                        *   '<S165>/Gain6'
                                        *   '<S204>/Constant'
                                        *   '<S205>/Constant'
                                        *   '<S237>/L1'
                                        *   '<S237>/Saturation1'
                                        *   '<S343>/Gain2'
                                        *   '<S344>/Gain1'
                                        *   '<S350>/Constant'
                                        *   '<S361>/Gain2'
                                        *   '<S362>/Gain1'
                                        *   '<S369>/Constant'
                                        *   '<S377>/Gain2'
                                        *   '<S378>/Gain1'
                                        *   '<S384>/Constant'
                                        *   '<S389>/Gain2'
                                        *   '<S390>/Gain1'
                                        *   '<S397>/Constant'
                                        *   '<S401>/Gain2'
                                        *   '<S402>/Gain6'
                                        *   '<S412>/Constant'
                                        *   '<S413>/Constant'
                                        *   '<S427>/Gain2'
                                        *   '<S428>/Gain1'
                                        *   '<S435>/Constant'
                                        *   '<S460>/Gain'
                                        *   '<S460>/Saturation1'
                                        *   '<S463>/Constant'
                                        *   '<S463>/vel'
                                        *   '<S463>/Switch'
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
                                        *   '<S128>/Dead Zone'
                                        *   '<S128>/Gain'
                                        *   '<S153>/Dead Zone'
                                        *   '<S153>/Gain'
                                        *   '<S201>/Dead Zone'
                                        *   '<S201>/Gain'
                                        *   '<S346>/Land_Speed'
                                        *   '<S347>/Constant'
                                        *   '<S349>/Dead Zone'
                                        *   '<S349>/Gain'
                                        *   '<S366>/Dead Zone'
                                        *   '<S366>/Gain'
                                        *   '<S380>/Land_Speed'
                                        *   '<S381>/Constant'
                                        *   '<S383>/Dead Zone'
                                        *   '<S383>/Gain'
                                        *   '<S394>/Dead Zone'
                                        *   '<S394>/Gain'
                                        *   '<S406>/Dead Zone'
                                        *   '<S406>/Gain'
                                        *   '<S407>/Dead Zone'
                                        *   '<S407>/Gain'
                                        *   '<S432>/Dead Zone'
                                        *   '<S432>/Gain'
                                        *   '<S447>/Gain2'
                                        *   '<S447>/Saturation'
                                        *   '<S448>/Integrator'
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
                                        *   '<S478>/Saturation1'
                                        *   '<S488>/Saturation1'
                                        *   '<S726>/Gain2'
                                        *   '<S727>/Gain1'
                                        *   '<S736>/Gain2'
                                        *   '<S737>/Gain6'
                                        *   '<S481>/Gain2'
                                        *   '<S482>/Gain1'
                                        *   '<S491>/Gain2'
                                        *   '<S492>/Gain6'
                                        *   '<S729>/Dead Zone'
                                        *   '<S729>/Gain'
                                        *   '<S741>/Dead Zone'
                                        *   '<S741>/Gain'
                                        *   '<S742>/Dead Zone'
                                        *   '<S742>/Gain'
                                        *   '<S484>/Dead Zone'
                                        *   '<S484>/Gain'
                                        *   '<S496>/Dead Zone'
                                        *   '<S496>/Gain'
                                        *   '<S497>/Dead Zone'
                                        *   '<S497>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S7>/Constant1'
                                        *   '<S26>/Constant1'
                                        *   '<S780>/Constant'
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
 *    '<S310>/NearbyRefWP'
 *    '<S288>/NearbyRefWP'
 *    '<S239>/NearbyRefWP'
 *    '<S716>/NearbyRefWP'
 *    '<S465>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S314>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S310>/SearchL1RefWP'
 *    '<S288>/SearchL1RefWP'
 *    '<S239>/SearchL1RefWP'
 *    '<S716>/SearchL1RefWP'
 *    '<S465>/SearchL1RefWP'
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

  /* SignalConversion: '<S316>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S288>/OutRegionRegWP'
 *    '<S239>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S293>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S328>/Unknown'
 *    '<S326>/Unknown'
 *    '<S325>/Unknown'
 *    '<S50>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S262>/Bus Assignment' incorporates:
   *  Constant: '<S262>/Constant'
   *  Constant: '<S262>/Constant2'
   *  SignalConversion: '<S262>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S262>/Bus Assignment' */
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
 *    '<S341>/Motion Status'
 *    '<S375>/Motion Status'
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
 *    '<S341>/Motion Status'
 *    '<S375>/Motion Status'
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
 *    '<S341>/Motion Status'
 *    '<S375>/Motion Status'
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

  /* InitializeConditions for DiscreteIntegrator: '<S198>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S198>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S200>/Discrete-Time Integrator1' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S198>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localC->Constant;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S198>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S200>/Discrete-Time Integrator1' */
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
  real32_T rtb_VectorConcatenate_f[3];
  int32_T i;
  real32_T rtb_Square_kg_idx_0;
  real32_T rtb_Square_kg_idx_1;
  real32_T rtb_Square_kg_idx_2;
  real32_T rtb_Switch_fz_idx_1;
  real32_T rtb_VectorConcatenate_f_tmp;
  real32_T rtb_VectorConcatenate_f_tmp_0;

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
  rtb_VectorConcatenate_f_tmp = rtb_Square_kg_idx_1 *
    rtb_DiscreteTimeIntegrator1_ex;

  /* Product: '<S173>/Multiply3' incorporates:
   *  Product: '<S175>/Multiply1'
   */
  rtb_VectorConcatenate_f_tmp_0 = rtb_Square_kg_idx_0 * rtb_Square_kg_idx_2;

  /* Gain: '<S173>/Gain1' incorporates:
   *  Product: '<S173>/Multiply2'
   *  Product: '<S173>/Multiply3'
   *  Sum: '<S173>/Add2'
   */
  rtb_VectorConcatenate_l[2] = (rtb_VectorConcatenate_f_tmp +
    rtb_VectorConcatenate_f_tmp_0) * 2.0F;

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
  rtb_VectorConcatenate_l[6] = (rtb_VectorConcatenate_f_tmp -
    rtb_VectorConcatenate_f_tmp_0) * 2.0F;

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

  /* Trigonometry: '<S196>/Trigonometric Function1' incorporates:
   *  Gain: '<S195>/Gain'
   *  Trigonometry: '<S196>/Trigonometric Function3'
   */
  rtb_Sign_hw = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[0] = rtb_Sign_hw;

  /* Trigonometry: '<S196>/Trigonometric Function' incorporates:
   *  Gain: '<S195>/Gain'
   *  Trigonometry: '<S196>/Trigonometric Function2'
   */
  rtb_Switch_fz_idx_1 = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_l[1] = rtb_Switch_fz_idx_1;

  /* SignalConversion: '<S196>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S196>/Constant3'
   */
  rtb_VectorConcatenate_l[2] = 0.0F;

  /* Gain: '<S196>/Gain' */
  rtb_VectorConcatenate_l[3] = -rtb_Switch_fz_idx_1;

  /* Trigonometry: '<S196>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_Sign_hw;

  /* SignalConversion: '<S196>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S196>/Constant4'
   */
  rtb_VectorConcatenate_l[5] = 0.0F;

  /* SignalConversion: '<S196>/ConcatBufferAtVector ConcatenateIn3' */
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

  /* Product: '<S194>/Multiply' incorporates:
   *  SignalConversion: '<S194>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_f[i] = rtb_VectorConcatenate_l[i + 3] * rtu_FMS_In_h +
      rtb_VectorConcatenate_l[i] * rtu_FMS_In_c;
  }

  /* End of Product: '<S194>/Multiply' */

  /* DiscreteIntegrator: '<S198>/Discrete-Time Integrator' */
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

  /* DiscreteIntegrator: '<S200>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S192>/Constant'
   *  Sum: '<S192>/Sum'
   */
  if (localDW->DiscreteTimeIntegrator1_IC_LOAD != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_f[1];
  }

  if (localDW->DiscreteTimeIntegrator1_PrevRes != 0) {
    localDW->DiscreteTimeIntegrator1_DSTATE = 0.0F - rtb_VectorConcatenate_f[1];
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
   *  Constant: '<S192>/Constant'
   *  Constant: '<S199>/kp'
   *  DiscreteIntegrator: '<S198>/Discrete-Time Integrator'
   *  Gain: '<S180>/Gain'
   *  Math: '<S180>/Square'
   *  Math: '<S183>/Square'
   *  Math: '<S185>/Math Function'
   *  MinMax: '<S180>/Max'
   *  MinMax: '<S180>/Min'
   *  Product: '<S180>/Divide'
   *  Product: '<S180>/Multiply1'
   *  Product: '<S199>/Multiply'
   *  Sqrt: '<S183>/Sqrt'
   *  Sum: '<S168>/Subtract'
   *  Sum: '<S183>/Sum of Elements'
   *  Sum: '<S192>/Sum'
   *  Sum: '<S193>/Add'
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
    *rty_ay_cmd_mPs2 = (0.0F - rtb_VectorConcatenate_f[1]) * 1.2F +
      localDW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Switch: '<S164>/Switch' */

  /* Update for Delay: '<S169>/start_vel' */
  localDW->icLoad = 0U;

  /* Update for Delay: '<S169>/start_wp' */
  localDW->icLoad_e = 0U;

  /* Update for DiscreteIntegrator: '<S198>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S192>/Constant'
   *  Constant: '<S198>/ki'
   *  Product: '<S198>/Multiply'
   *  Sum: '<S192>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += (0.0F - rtb_VectorConcatenate_f[1]) *
    0.5F * 0.004F;
  if (localDW->DiscreteTimeIntegrator_DSTATE >= 1.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE = 1.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <= -1.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE = -1.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevRese = 0;

  /* End of Update for DiscreteIntegrator: '<S198>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S200>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S192>/Constant'
   *  Gain: '<S200>/Gain'
   *  Sum: '<S192>/Sum'
   *  Sum: '<S200>/Sum5'
   */
  localDW->DiscreteTimeIntegrator1_IC_LOAD = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE += ((0.0F - rtb_VectorConcatenate_f[1])
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
 *    '<S723>/Hold Control'
 *    '<S640>/Hold Control'
 *    '<S478>/Hold Control'
 *    '<S340>/Hold Control'
 *    '<S374>/Hold Control'
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
 *    '<S478>/Hold Control'
 *    '<S340>/Hold Control'
 *    '<S374>/Hold Control'
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
 *    '<S478>/Hold Control'
 *    '<S340>/Hold Control'
 *    '<S374>/Hold Control'
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
 * Output and update for action system:
 *    '<S723>/Brake Control'
 *    '<S640>/Brake Control'
 *    '<S651>/Brake Control'
 *    '<S478>/Brake Control'
 *    '<S424>/Brake Control'
 *    '<S340>/Brake Control'
 *    '<S358>/Brake Control'
 *    '<S374>/Brake Control'
 *    '<S386>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S725>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S725>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
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
  real32_T rtb_Add3_ho;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S731>/Multiply1' incorporates:
   *  Constant: '<S731>/const1'
   *  DiscreteIntegrator: '<S730>/Integrator'
   */
  rtb_Add3_ho = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S729>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S729>/Dead Zone' */

  /* Sum: '<S731>/Add' incorporates:
   *  DiscreteIntegrator: '<S730>/Integrator1'
   *  Gain: '<S727>/Gain1'
   *  Gain: '<S729>/Gain'
   *  Sum: '<S730>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_ho;

  /* Signum: '<S731>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
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
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_ho;

  /* Sum: '<S731>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_ho;

  /* Sum: '<S731>/Add3' */
  rtb_Add3_ho = rtb_Subtract3_d + localC->d;

  /* Sum: '<S731>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S731>/Sign1' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign1' */

  /* Signum: '<S731>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign2' */

  /* Sum: '<S731>/Add5' incorporates:
   *  Gain: '<S731>/Gain2'
   *  Product: '<S731>/Multiply4'
   *  Sum: '<S731>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_ho - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S730>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S730>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S730>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S730>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S731>/Add6' */
  rtb_Add3_ho = rtb_a_o + localC->d;

  /* Sum: '<S731>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S731>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S731>/Sign5' */

  /* Signum: '<S731>/Sign3' */
  if (rtb_Add3_ho < 0.0F) {
    rtb_Add3_ho = -1.0F;
  } else {
    if (rtb_Add3_ho > 0.0F) {
      rtb_Add3_ho = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign3' */

  /* Signum: '<S731>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S731>/Sign4' */

  /* Signum: '<S731>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
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
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_ho - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S724>/Motion Status'
 *    '<S641>/Motion Status'
 *    '<S479>/Motion Status'
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
 *    '<S479>/Motion Status'
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
 *    '<S479>/Motion Status'
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
 *    '<S488>/Hold Control'
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
 *    '<S488>/Hold Control'
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
 *    '<S488>/Hold Control'
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
 *    '<S488>/Brake Control'
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
  real32_T rtb_Subtract3_jp;
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
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S744>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
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
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

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
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
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
    rtb_Subtract3_jp * 58.836F) * 0.004F;

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
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S744>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S744>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
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
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

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
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
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
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S743>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S734>/Motion State'
 *    '<S673>/Motion State'
 *    '<S489>/Motion State'
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
 *    '<S489>/Motion State'
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
 *    '<S489>/Motion State'
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
 *    '<S465>/OutRegionRegWP'
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
 *    '<S424>/Hold Control'
 *    '<S358>/Hold Control'
 *    '<S386>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S655>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S651>/Hold Control'
 *    '<S424>/Hold Control'
 *    '<S358>/Hold Control'
 *    '<S386>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S655>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S651>/Hold Control'
 *    '<S424>/Hold Control'
 *    '<S358>/Hold Control'
 *    '<S386>/Hold Control'
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
 *    '<S424>/Move Control'
 *    '<S358>/Move Control'
 *    '<S386>/Move Control'
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
 *    '<S424>/Move Control'
 *    '<S358>/Move Control'
 *    '<S386>/Move Control'
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
 *    '<S424>/Move Control'
 *    '<S358>/Move Control'
 *    '<S386>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_px;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S662>/Multiply1' incorporates:
   *  Constant: '<S662>/const1'
   *  DiscreteIntegrator: '<S661>/Integrator'
   */
  rtb_Add3_px = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S660>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S660>/Dead Zone' */

  /* Sum: '<S662>/Add' incorporates:
   *  DiscreteIntegrator: '<S661>/Integrator1'
   *  Gain: '<S656>/Gain1'
   *  Gain: '<S660>/Gain'
   *  Sum: '<S661>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_px;

  /* Signum: '<S662>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
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
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_px;

  /* Sum: '<S662>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_px;

  /* Sum: '<S662>/Add3' */
  rtb_Add3_px = rtb_Subtract3_e + localC->d;

  /* Sum: '<S662>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S662>/Sign1' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign1' */

  /* Signum: '<S662>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign2' */

  /* Sum: '<S662>/Add5' incorporates:
   *  Gain: '<S662>/Gain2'
   *  Product: '<S662>/Multiply4'
   *  Sum: '<S662>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_px - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S661>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S661>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S661>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S661>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S662>/Add6' */
  rtb_Add3_px = rtb_a_h + localC->d;

  /* Sum: '<S662>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S662>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S662>/Sign5' */

  /* Signum: '<S662>/Sign3' */
  if (rtb_Add3_px < 0.0F) {
    rtb_Add3_px = -1.0F;
  } else {
    if (rtb_Add3_px > 0.0F) {
      rtb_Add3_px = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign3' */

  /* Signum: '<S662>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S662>/Sign4' */

  /* Signum: '<S662>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
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
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_px - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S425>/Motion State'
 *    '<S359>/Motion State'
 *    '<S387>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S425>/Motion State'
 *    '<S359>/Motion State'
 *    '<S387>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S425>/Motion State'
 *    '<S359>/Motion State'
 *    '<S387>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S425>/Motion State' */
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

  /* End of Chart: '<S425>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S340>/Move Control'
 *    '<S374>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S349>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S349>/Dead Zone' */

  /* Gain: '<S344>/Gain1' incorporates:
   *  Gain: '<S349>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S344>/Switch' incorporates:
   *  Constant: '<S346>/Land_Speed'
   *  Constant: '<S347>/Constant'
   *  Constant: '<S348>/Constant'
   *  Gain: '<S346>/Gain'
   *  Logic: '<S344>/Logical Operator'
   *  MinMax: '<S346>/Min'
   *  RelationalOperator: '<S347>/Compare'
   *  RelationalOperator: '<S348>/Compare'
   *  S-Function (sfix_bitop): '<S344>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S344>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S785>/Switch' incorporates:
   *  Constant: '<S785>/FW_ACCEPT_R'
   *  Constant: '<S785>/MC_ACCEPT_R'
   *  Constant: '<S792>/Constant'
   *  RelationalOperator: '<S792>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S785>/Switch' */
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

  /* Math: '<S803>/Rem' incorporates:
   *  Constant: '<S803>/Constant1'
   *  Sum: '<S787>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S803>/Switch' incorporates:
   *  Abs: '<S803>/Abs'
   *  Constant: '<S803>/Constant'
   *  Constant: '<S804>/Constant'
   *  Product: '<S803>/Multiply'
   *  RelationalOperator: '<S804>/Compare'
   *  Sum: '<S803>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S803>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S803>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S803>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a2_idx_1;

  /* Sum: '<S790>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S809>/Sum of Elements' incorporates:
   *  Math: '<S809>/Math Function'
   *  SignalConversion: '<S809>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S809>/Math Function1' incorporates:
   *  Sum: '<S809>/Sum of Elements'
   *
   * About '<S809>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S809>/Math Function1' */

  /* Switch: '<S809>/Switch' incorporates:
   *  Constant: '<S809>/Constant'
   *  Product: '<S809>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a2_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a2_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S809>/Switch' */

  /* Product: '<S809>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a2_idx_1 / rtb_Switch2_b;

  /* Sum: '<S807>/Subtract' incorporates:
   *  Product: '<S807>/Multiply'
   *  Product: '<S807>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S806>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S806>/Sign1' */

  /* Switch: '<S806>/Switch2' incorporates:
   *  Constant: '<S806>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S806>/Switch2' */

  /* DotProduct: '<S806>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S806>/Acos' incorporates:
   *  DotProduct: '<S806>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S806>/Multiply' incorporates:
   *  Trigonometry: '<S806>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S790>/Switch' incorporates:
   *  Bias: '<S790>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S790>/Switch' */
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

  /* Gain: '<S793>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S794>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S794>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S794>/Multiply1' incorporates:
   *  Product: '<S794>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S794>/Divide' incorporates:
   *  Constant: '<S794>/Constant'
   *  Constant: '<S794>/R'
   *  Sqrt: '<S794>/Sqrt'
   *  Sum: '<S794>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S794>/Product3' incorporates:
   *  Constant: '<S794>/Constant1'
   *  Product: '<S794>/Multiply1'
   *  Sum: '<S794>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S794>/Multiply2' incorporates:
   *  Trigonometry: '<S794>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S793>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S798>/Abs' incorporates:
   *  Abs: '<S801>/Abs1'
   *  Switch: '<S798>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S798>/Switch1' incorporates:
   *  Abs: '<S798>/Abs'
   *  Bias: '<S798>/Bias2'
   *  Bias: '<S798>/Bias3'
   *  Constant: '<S795>/Constant'
   *  Constant: '<S795>/Constant1'
   *  Constant: '<S800>/Constant'
   *  Gain: '<S798>/Gain1'
   *  Product: '<S798>/Multiply'
   *  RelationalOperator: '<S800>/Compare'
   *  Switch: '<S795>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S801>/Switch1' incorporates:
     *  Bias: '<S801>/Bias2'
     *  Bias: '<S801>/Bias3'
     *  Constant: '<S801>/Constant'
     *  Constant: '<S802>/Constant'
     *  Math: '<S801>/Math Function'
     *  RelationalOperator: '<S802>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S801>/Switch1' */

    /* Signum: '<S798>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S798>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S795>/Sum' incorporates:
   *  Sum: '<S793>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S793>/Multiply' incorporates:
   *  Gain: '<S793>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S797>/Switch1' incorporates:
   *  Abs: '<S797>/Abs1'
   *  Bias: '<S797>/Bias2'
   *  Bias: '<S797>/Bias3'
   *  Constant: '<S797>/Constant'
   *  Constant: '<S799>/Constant'
   *  Math: '<S797>/Math Function'
   *  RelationalOperator: '<S799>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S797>/Switch1' */

  /* Product: '<S793>/Multiply' incorporates:
   *  Gain: '<S793>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S793>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S796>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S796>/Sum2' incorporates:
   *  Product: '<S796>/Multiply1'
   *  Product: '<S796>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S796>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S796>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S796>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S786>/Data Type Conversion' incorporates:
   *  Gain: '<S793>/Gain'
   *  Sum: '<S793>/Sum1'
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
  /* RelationalOperator: '<S805>/Compare' incorporates:
   *  Abs: '<S789>/Abs'
   *  Constant: '<S805>/Constant'
   *  MinMax: '<S789>/Max'
   *  Sum: '<S789>/Sum'
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
      /* Reshape: '<S788>/Reshape' incorporates:
       *  Constant: '<S788>/Constant'
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
          /* RelationalOperator: '<S791>/Compare' incorporates:
           *  Constant: '<S791>/Constant'
           *  S-Function (sfix_bitop): '<S783>/Bitwise AND'
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
          /* RelationalOperator: '<S784>/Relational Operator1' incorporates:
           *  Constant: '<S784>/Constant1'
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
        /* RelationalOperator: '<S782>/Relational Operator' incorporates:
         *  Constant: '<S782>/Constant'
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
          /* RelationalOperator: '<S781>/Relational Operator1' incorporates:
           *  Constant: '<S781>/Constant1'
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
  real32_T rtb_Saturation1_p5;
  int32_T rtb_n;
  real32_T rtb_Switch_ov[3];
  real32_T rtb_a_bx;
  real32_T rtb_Integrator1_bx;
  real32_T rtb_Divide_ox;
  real32_T rtb_Divide_ic;
  real32_T rtb_Sign5_af;
  real32_T rtb_Divide_e;
  real32_T rtb_Sign5_i;
  real32_T rtb_Add4_pb;
  MotionState rtb_state_ej;
  MotionState rtb_state_fg;
  boolean_T rtb_LogicalOperator_e;
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

  /* Sqrt: '<S821>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S821>/Square'
   *  Sqrt: '<S21>/Sqrt'
   *  Sum: '<S821>/Sum of Elements'
   *  Switch: '<S1>/Switch'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S817>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Sqrt: '<S821>/Sqrt'
   */
  rtb_Divide_lr_idx_0 = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S818>/Square' incorporates:
   *  Math: '<S819>/Square'
   *  Math: '<S820>/Square'
   */
  rtb_Saturation_ga = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

  /* Math: '<S818>/Square2' incorporates:
   *  Math: '<S819>/Square2'
   *  Math: '<S820>/Square2'
   */
  rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S818>/Square1' incorporates:
   *  Math: '<S819>/Square1'
   *  Math: '<S820>/Square1'
   */
  rtb_Saturation1_d = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S818>/Square3' incorporates:
   *  Math: '<S819>/Square3'
   *  Math: '<S820>/Square3'
   */
  rtb_Saturation1_p5 = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

  /* Sum: '<S818>/Subtract' incorporates:
   *  Math: '<S818>/Square'
   *  Math: '<S818>/Square1'
   *  Math: '<S818>/Square2'
   *  Math: '<S818>/Square3'
   *  Sum: '<S818>/Add'
   *  Sum: '<S818>/Add1'
   */
  rtb_VectorConcatenate_or[0] = (rtb_Saturation_ga + rtb_Saturation1_d) -
    (rtb_P_f_idx_0 + rtb_Saturation1_p5);

  /* Product: '<S818>/Multiply' incorporates:
   *  Product: '<S819>/Multiply'
   */
  d = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S818>/Multiply1' incorporates:
   *  Product: '<S819>/Multiply1'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_3;

  /* Gain: '<S818>/Gain' incorporates:
   *  Product: '<S818>/Multiply'
   *  Product: '<S818>/Multiply1'
   *  Sum: '<S818>/Subtract1'
   */
  rtb_VectorConcatenate_or[1] = (d - rtb_Integrator1_bx) * 2.0F;

  /* Product: '<S818>/Multiply2' incorporates:
   *  Product: '<S820>/Multiply'
   */
  rtb_a_bx = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_3;

  /* Product: '<S818>/Multiply3' incorporates:
   *  Product: '<S820>/Multiply1'
   */
  rtb_Divide_ox = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_2;

  /* Gain: '<S818>/Gain1' incorporates:
   *  Product: '<S818>/Multiply2'
   *  Product: '<S818>/Multiply3'
   *  Sum: '<S818>/Add2'
   */
  rtb_VectorConcatenate_or[2] = (rtb_a_bx + rtb_Divide_ox) * 2.0F;

  /* Gain: '<S819>/Gain' incorporates:
   *  Sum: '<S819>/Add3'
   */
  rtb_VectorConcatenate_or[3] = (d + rtb_Integrator1_bx) * 2.0F;

  /* Sum: '<S819>/Subtract' incorporates:
   *  Sum: '<S819>/Add'
   *  Sum: '<S819>/Add1'
   */
  rtb_VectorConcatenate_or[4] = (rtb_Saturation_ga + rtb_P_f_idx_0) -
    (rtb_Saturation1_d + rtb_Saturation1_p5);

  /* Product: '<S819>/Multiply2' incorporates:
   *  Product: '<S820>/Multiply2'
   */
  d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_3;

  /* Product: '<S819>/Multiply3' incorporates:
   *  Product: '<S820>/Multiply3'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1;

  /* Gain: '<S819>/Gain1' incorporates:
   *  Product: '<S819>/Multiply2'
   *  Product: '<S819>/Multiply3'
   *  Sum: '<S819>/Subtract1'
   */
  rtb_VectorConcatenate_or[5] = (d - rtb_Integrator1_bx) * 2.0F;

  /* Gain: '<S820>/Gain' incorporates:
   *  Sum: '<S820>/Subtract2'
   */
  rtb_VectorConcatenate_or[6] = (rtb_a_bx - rtb_Divide_ox) * 2.0F;

  /* Gain: '<S820>/Gain1' incorporates:
   *  Sum: '<S820>/Add2'
   */
  rtb_VectorConcatenate_or[7] = (d + rtb_Integrator1_bx) * 2.0F;

  /* Sum: '<S820>/Subtract' incorporates:
   *  Sum: '<S820>/Add'
   *  Sum: '<S820>/Add1'
   */
  rtb_VectorConcatenate_or[8] = (rtb_Saturation_ga + rtb_Saturation1_p5) -
    (rtb_Saturation1_d + rtb_P_f_idx_0);

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

  /* DiscreteIntegrator: '<S812>/Discrete-Time Integrator5' */
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
   *  ActionPort: '<S325>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S325>/Position' incorporates:
   *  ActionPort: '<S332>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S399>/Hold Control' incorporates:
   *  ActionPort: '<S401>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S326>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S326>/Offboard' incorporates:
   *  ActionPort: '<S438>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S328>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S328>/Land' incorporates:
   *  ActionPort: '<S633>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S328>/Takeoff' incorporates:
   *  ActionPort: '<S635>/Action Port'
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
   *  MultiPortSwitch: '<S525>/Index Vector'
   *  MultiPortSwitch: '<S590>/Index Vector'
   *  MultiPortSwitch: '<S591>/Index Vector'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S326>/Switch Case'
   *  SwitchCase: '<S328>/Switch Case'
   *  SwitchCase: '<S399>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S15>/Trigonometric Function1'
   *  Trigonometry: '<S15>/Trigonometric Function3'
   *  Trigonometry: '<S208>/Trigonometric Function1'
   *  Trigonometry: '<S208>/Trigonometric Function3'
   *  Trigonometry: '<S405>/Trigonometric Function1'
   *  Trigonometry: '<S405>/Trigonometric Function3'
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
   *  Trigonometry: '<S779>/Trigonometric Function1'
   *  Trigonometry: '<S779>/Trigonometric Function3'
   *  Trigonometry: '<S99>/Trigonometric Function1'
   *  Trigonometry: '<S99>/Trigonometric Function3'
   */
  rtb_Saturation_ga = arm_cos_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S109>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S328>/Takeoff' */
  /* End of Outputs for SubSystem: '<S328>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S326>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S399>/Hold Control' */
  /* End of Outputs for SubSystem: '<S325>/Position' */
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
   *  ActionPort: '<S325>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S325>/Position' incorporates:
   *  ActionPort: '<S332>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S399>/Hold Control' incorporates:
   *  ActionPort: '<S401>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S326>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S326>/Offboard' incorporates:
   *  ActionPort: '<S438>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S328>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S328>/Land' incorporates:
   *  ActionPort: '<S633>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S328>/Takeoff' incorporates:
   *  ActionPort: '<S635>/Action Port'
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
   *  MultiPortSwitch: '<S525>/Index Vector'
   *  MultiPortSwitch: '<S590>/Index Vector'
   *  MultiPortSwitch: '<S591>/Index Vector'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S326>/Switch Case'
   *  SwitchCase: '<S328>/Switch Case'
   *  SwitchCase: '<S399>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   *  Trigonometry: '<S15>/Trigonometric Function'
   *  Trigonometry: '<S15>/Trigonometric Function2'
   *  Trigonometry: '<S208>/Trigonometric Function'
   *  Trigonometry: '<S405>/Trigonometric Function'
   *  Trigonometry: '<S536>/Trigonometric Function'
   *  Trigonometry: '<S599>/Trigonometric Function'
   *  Trigonometry: '<S603>/Trigonometric Function'
   *  Trigonometry: '<S629>/Trigonometric Function'
   *  Trigonometry: '<S693>/Trigonometric Function'
   *  Trigonometry: '<S779>/Trigonometric Function'
   *  Trigonometry: '<S99>/Trigonometric Function'
   */
  rtb_P_f_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

  /* End of Outputs for SubSystem: '<S109>/Position' */
  /* End of Outputs for SubSystem: '<S49>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S44>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S328>/Takeoff' */
  /* End of Outputs for SubSystem: '<S328>/Land' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S326>/Offboard' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S399>/Hold Control' */
  /* End of Outputs for SubSystem: '<S325>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Trigonometry: '<S15>/Trigonometric Function' */
  rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

  /* SignalConversion: '<S15>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S15>/Constant3'
   */
  rtb_VectorConcatenate_or[2] = 0.0F;

  /* Gain: '<S15>/Gain' */
  rtb_VectorConcatenate_or[3] = -rtb_P_f_idx_0;

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
    rtb_Saturation1_d = rtb_Divide_p3p[0] * rtb_Divide_p3p[0];

    /* Math: '<S20>/Square2' incorporates:
     *  Math: '<S18>/Square2'
     *  Math: '<S19>/Square2'
     */
    rtb_Saturation1_p5 = rtb_Divide_p3p[2] * rtb_Divide_p3p[2];

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
    rtb_MatrixConcatenate1[8] = (rtb_Saturation1_d + rtb_Divide_lr_idx_0) -
      (rtb_DiscreteTimeIntegrator_n + rtb_Saturation1_p5);

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
    rtb_MatrixConcatenate1[4] = (rtb_Saturation1_d + rtb_Saturation1_p5) -
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
    rtb_MatrixConcatenate1[0] = (rtb_Saturation1_d +
      rtb_DiscreteTimeIntegrator_n) - (rtb_Saturation1_p5 + rtb_Divide_lr_idx_0);

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

  /* DiscreteIntegrator: '<S814>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S814>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_L_af != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_a_bx = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_a_bx > 1.0F) {
    rtb_a_bx = 1.0F;
  } else {
    if (rtb_a_bx < 0.9F) {
      rtb_a_bx = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_lr_idx_0 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_a_bx;

  /* DiscreteIntegrator: '<S813>/Discrete-Time Integrator5' */
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
   *  Constant: '<S810>/Constant'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S812>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S813>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S814>/Discrete-Time Integrator5'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S815>/AND'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S810>/Compare'
   *  RelationalOperator: '<S815>/Lower Test'
   *  RelationalOperator: '<S815>/Upper Test'
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
    rtb_Switch_ga = FMS_DW.Delay_DSTATE_o;
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
   *  ActionPort: '<S224>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S224>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S228>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S49>/SubMode' incorporates:
   *  ActionPort: '<S112>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Return' incorporates:
   *  ActionPort: '<S260>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Takeoff' incorporates:
   *  ActionPort: '<S261>/Action Port'
   */
  /* SwitchCase: '<S110>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S249>/Math Function'
   *  Math: '<S298>/Math Function'
   *  Math: '<S320>/Math Function'
   *  SwitchCase: '<S112>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   */
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S112>/Takeoff' */
  /* End of Outputs for SubSystem: '<S112>/Return' */
  /* End of Outputs for SubSystem: '<S224>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S110>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */

  /* Outputs for IfAction SubSystem: '<S44>/MC_Mode' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
   *  ActionPort: '<S326>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S326>/Mission' incorporates:
   *  ActionPort: '<S437>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S437>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S441>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S50>/SubMode' incorporates:
   *  ActionPort: '<S328>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S328>/Return' incorporates:
   *  ActionPort: '<S634>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Hold' incorporates:
   *  ActionPort: '<S258>/Action Port'
   */
  /* SwitchCase: '<S112>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S275>/Sum of Elements'
   *  Sum: '<S509>/Sum of Elements'
   *  Sum: '<S754>/Sum of Elements'
   *  SwitchCase: '<S326>/Switch Case'
   *  SwitchCase: '<S328>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Integrator1_bx = rtb_Divide_lr_idx_2 + rtb_Divide_lr_idx_3;

  /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
   *  ActionPort: '<S325>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S325>/Position' incorporates:
   *  ActionPort: '<S332>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S49>/Auto' incorporates:
   *  ActionPort: '<S110>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S110>/Mission' incorporates:
   *  ActionPort: '<S224>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S224>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S228>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S112>/Return' incorporates:
   *  ActionPort: '<S260>/Action Port'
   */
  /* SwitchCase: '<S110>/Switch Case' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S248>/Sqrt'
   *  Sqrt: '<S274>/Sqrt'
   *  Sqrt: '<S297>/Sqrt'
   *  Sqrt: '<S400>/Sqrt'
   *  Sqrt: '<S507>/Sqrt'
   *  Sqrt: '<S752>/Sqrt'
   *  Sum: '<S1>/Add'
   *  SwitchCase: '<S112>/Switch Case'
   *  SwitchCase: '<S325>/Switch Case'
   *  SwitchCase: '<S326>/Switch Case'
   *  SwitchCase: '<S328>/Switch Case'
   *  SwitchCase: '<S42>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S49>/Switch Case'
   *  SwitchCase: '<S50>/Switch Case'
   */
  rtb_Saturation1_p5 = sqrtf(rtb_Integrator1_bx);

  /* End of Outputs for SubSystem: '<S112>/Return' */
  /* End of Outputs for SubSystem: '<S224>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S110>/Mission' */
  /* End of Outputs for SubSystem: '<S49>/Auto' */
  /* End of Outputs for SubSystem: '<S325>/Position' */
  /* End of Outputs for SubSystem: '<S50>/Assist' */
  /* End of Outputs for SubSystem: '<S112>/Hold' */
  /* End of Outputs for SubSystem: '<S328>/Return' */
  /* End of Outputs for SubSystem: '<S50>/SubMode' */
  /* End of Outputs for SubSystem: '<S437>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S326>/Mission' */
  /* End of Outputs for SubSystem: '<S50>/Auto' */
  /* End of Outputs for SubSystem: '<S44>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S49>/SubMode' */
  /* End of Outputs for SubSystem: '<S44>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S42>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   */
  rtb_Divide_lr_idx_1 *= rtb_Saturation1_p5;

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

  /* RelationalOperator: '<S811>/Compare' incorporates:
   *  Constant: '<S811>/Constant'
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
        /* Disable for SwitchCase: '<S328>/Switch Case' */
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
        /* Disable for SwitchCase: '<S326>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S437>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S488>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S478>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S437>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S325>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S424>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S340>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S358>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S374>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S399>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S386>/Switch Case' */
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
          /* Disable for SwitchCase: '<S328>/Switch Case' */
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
          /* Disable for SwitchCase: '<S326>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S437>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S488>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S478>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S437>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S325>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S424>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S340>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S358>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S374>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S399>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S386>/Switch Case' */
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
           *  ActionPort: '<S261>/Action Port'
           */
          /* Sum: '<S320>/Sum of Elements' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 + rtb_Divide_lr_idx_3;

          /* Math: '<S320>/Math Function1' incorporates:
           *  Sum: '<S320>/Sum of Elements'
           *
           * About '<S320>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S320>/Math Function1' */

          /* Switch: '<S320>/Switch' incorporates:
           *  Constant: '<S320>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S320>/Product'
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

          /* End of Switch: '<S320>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S310>/NearbyRefWP' incorporates:
           *  Constant: '<S308>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_c14,
                          &rtb_Saturation1_d);

          /* MATLAB Function: '<S310>/SearchL1RefWP' incorporates:
           *  Constant: '<S308>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_ap, &rtb_u_b);

          /* MATLAB Function: '<S310>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S305>/Sum'
           *  Sum: '<S305>/Sum1'
           */
          rtb_Saturation1_p5 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_bx = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_ox = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_a_bx * rtb_a_bx;
          rtb_Saturation_ga = (rtb_Divide_ox * rtb_a_bx + d * rtb_Saturation1_p5)
            / (rtb_P_f_idx_0 + rtb_Saturation1_p5 * rtb_Saturation1_p5);
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
            rtb_Integrator1_bx = (rtb_Saturation_ga * rtb_Saturation1_p5 +
                                  FMS_B.Cmd_In.cur_waypoint[0]) -
              FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Integrator1_bx * rtb_Integrator1_bx;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Integrator1_bx = (rtb_Saturation_ga * rtb_a_bx +
                                  FMS_B.Cmd_In.cur_waypoint[1]) -
              FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_ga += sqrtf(rtb_Integrator1_bx * rtb_Integrator1_bx +
              rtb_Subtract_hb[0]) * 0.5774F / sqrtf(rtb_Saturation1_p5 *
              rtb_Saturation1_p5 + rtb_P_f_idx_0);
            if (rtb_Saturation_ga > 1.0F) {
              rtb_Saturation_ga = 1.0F;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = rtb_Saturation_ga * rtb_Saturation1_p5 +
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_ga = rtb_Saturation_ga * rtb_a_bx +
              FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S310>/OutRegionRegWP' */

          /* Switch: '<S310>/Switch1' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           */
          if (rtb_Saturation1_d <= 0.0F) {
            /* Switch: '<S310>/Switch' incorporates:
             *  Constant: '<S312>/Constant'
             *  RelationalOperator: '<S312>/Compare'
             */
            if (rtb_u_b >= 0.0F) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            } else {
              rtb_Divide_c14[0] = rtb_P_f_idx_0;
              rtb_Divide_c14[1] = rtb_Saturation_ga;
            }

            /* End of Switch: '<S310>/Switch' */
          }

          /* End of Switch: '<S310>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S311>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S321>/Sum of Elements' incorporates:
           *  Math: '<S321>/Math Function'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S321>/Math Function1' incorporates:
           *  Sum: '<S321>/Sum of Elements'
           *
           * About '<S321>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S321>/Math Function1' */

          /* Switch: '<S321>/Switch' incorporates:
           *  Constant: '<S321>/Constant'
           *  Product: '<S321>/Product'
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

          /* End of Switch: '<S321>/Switch' */

          /* Product: '<S320>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S323>/Sum of Elements' incorporates:
           *  Math: '<S323>/Math Function'
           *  SignalConversion: '<S323>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S323>/Math Function1' incorporates:
           *  Sum: '<S323>/Sum of Elements'
           *
           * About '<S323>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S323>/Math Function1' */

          /* Switch: '<S323>/Switch' incorporates:
           *  Constant: '<S323>/Constant'
           *  Product: '<S323>/Product'
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

          /* End of Switch: '<S323>/Switch' */

          /* Product: '<S321>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S324>/Sum of Elements' incorporates:
           *  Math: '<S324>/Math Function'
           *  SignalConversion: '<S324>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S324>/Math Function1' incorporates:
           *  Sum: '<S324>/Sum of Elements'
           *
           * About '<S324>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S324>/Math Function1' */

          /* Switch: '<S324>/Switch' incorporates:
           *  Constant: '<S324>/Constant'
           *  Product: '<S324>/Product'
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

          /* End of Switch: '<S324>/Switch' */

          /* Product: '<S324>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S323>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S324>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S323>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S305>/Divide' incorporates:
           *  Math: '<S306>/Square'
           *  Math: '<S307>/Square'
           *  Sqrt: '<S306>/Sqrt'
           *  Sqrt: '<S307>/Sqrt'
           *  Sum: '<S306>/Sum of Elements'
           *  Sum: '<S307>/Sum of Elements'
           */
          rtb_Saturation1_p5 = sqrtf(rtb_Divide_ox * rtb_Divide_ox + d * d) /
            sqrtf(rtb_Saturation1_p5 * rtb_Saturation1_p5 + rtb_a_bx * rtb_a_bx);

          /* Saturate: '<S305>/Saturation' */
          if (rtb_Saturation1_p5 > 1.0F) {
            rtb_Saturation1_p5 = 1.0F;
          } else {
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation1_p5 = 0.0F;
            }
          }

          /* End of Saturate: '<S305>/Saturation' */

          /* Sum: '<S322>/Subtract' incorporates:
           *  Product: '<S322>/Multiply'
           *  Product: '<S322>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S318>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S318>/Sign1' */

          /* Switch: '<S318>/Switch2' incorporates:
           *  Constant: '<S318>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S318>/Switch2' */

          /* DotProduct: '<S318>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S318>/Acos' incorporates:
           *  DotProduct: '<S318>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S318>/Multiply' incorporates:
           *  Trigonometry: '<S318>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S317>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S317>/Saturation' */

          /* Sqrt: '<S319>/Sqrt' incorporates:
           *  Sum: '<S319>/Sum of Elements'
           */
          rtb_Saturation1_d = sqrtf(rtb_Divide_lr_idx_2 + rtb_Divide_lr_idx_3);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S261>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S261>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S261>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S261>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S317>/Divide' incorporates:
           *  Constant: '<S308>/L1'
           *  Gain: '<S317>/Gain'
           *  Math: '<S317>/Square'
           *  Product: '<S317>/Multiply1'
           *  Trigonometry: '<S317>/Sin'
           */
          rtb_a_bx = rtb_Saturation1_d * rtb_Saturation1_d * 2.0F * arm_sin_f32
            (rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S308>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S261>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S261>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S261>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S308>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S303>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S305>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S303>/Sum2'
           *  Sum: '<S305>/Add'
           *  Sum: '<S305>/Subtract'
           */
          rtb_a_bx = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_p5 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S303>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S261>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S261>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S261>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S303>/Saturation1' */
          /* End of Outputs for SubSystem: '<S112>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S112>/Land' incorporates:
           *  ActionPort: '<S259>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S259>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S259>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S259>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S259>/Constant'
           *  Constant: '<S259>/Constant4'
           *  Constant: '<S259>/Constant5'
           *  Constant: '<S259>/Constant7'
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
           *  ActionPort: '<S260>/Action Port'
           */
          /* Math: '<S298>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Divide_lr_idx_2;
          rtb_Subtract_hb[1] = rtb_Divide_lr_idx_3;

          /* Sum: '<S298>/Sum of Elements' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 + rtb_Divide_lr_idx_3;

          /* Math: '<S298>/Math Function1' incorporates:
           *  Sum: '<S298>/Sum of Elements'
           *
           * About '<S298>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_P_f_idx_0 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S298>/Math Function1' */

          /* Switch: '<S298>/Switch' incorporates:
           *  Constant: '<S298>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S298>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_P_f_idx_0 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_P_f_idx_0;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S298>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S288>/NearbyRefWP' incorporates:
           *  Constant: '<S286>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S288>/SearchL1RefWP' incorporates:
           *  Constant: '<S286>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_c14, &rtb_Saturation1_d);

          /* MATLAB Function: '<S288>/OutRegionRegWP' incorporates:
           *  Constant: '<S286>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S288>/Switch1' incorporates:
           *  Constant: '<S291>/Constant'
           *  RelationalOperator: '<S291>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_c14[0] = rtb_Subtract_hb[0];
            rtb_Divide_c14[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S290>/Compare' incorporates:
             *  Constant: '<S290>/Constant'
             */
            rtb_Compare_o3 = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S288>/Switch' */
            if (!rtb_Compare_o3) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S288>/Switch' */
          }

          /* End of Switch: '<S288>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S289>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S299>/Sum of Elements' incorporates:
           *  Math: '<S299>/Math Function'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S299>/Math Function1' incorporates:
           *  Sum: '<S299>/Sum of Elements'
           *
           * About '<S299>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_P_f_idx_0 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S299>/Math Function1' */

          /* Switch: '<S299>/Switch' incorporates:
           *  Constant: '<S299>/Constant'
           *  Product: '<S299>/Product'
           */
          if (rtb_P_f_idx_0 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[2] = rtb_P_f_idx_0;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S299>/Switch' */

          /* Product: '<S298>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S301>/Sum of Elements' incorporates:
           *  Math: '<S301>/Math Function'
           *  SignalConversion: '<S301>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S301>/Math Function1' incorporates:
           *  Sum: '<S301>/Sum of Elements'
           *
           * About '<S301>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_P_f_idx_0 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S301>/Math Function1' */

          /* Switch: '<S301>/Switch' incorporates:
           *  Constant: '<S301>/Constant'
           *  Product: '<S301>/Product'
           */
          if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_P_f_idx_0;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S301>/Switch' */

          /* Product: '<S299>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S302>/Sum of Elements' incorporates:
           *  Math: '<S302>/Math Function'
           *  SignalConversion: '<S302>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S302>/Math Function1' incorporates:
           *  Sum: '<S302>/Sum of Elements'
           *
           * About '<S302>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_P_f_idx_0 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S302>/Math Function1' */

          /* Switch: '<S302>/Switch' incorporates:
           *  Constant: '<S302>/Constant'
           *  Product: '<S302>/Product'
           */
          if (rtb_P_f_idx_0 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Subtract_hb[1];
            rtb_MatrixConcatenate3[1] = rtb_Subtract_hb[0];
            rtb_MatrixConcatenate3[2] = rtb_P_f_idx_0;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S302>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S283>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S302>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S301>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S283>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_bx = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S302>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S301>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S283>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S283>/Divide' incorporates:
           *  Math: '<S284>/Square'
           *  Math: '<S285>/Square'
           *  Sqrt: '<S284>/Sqrt'
           *  Sqrt: '<S285>/Sqrt'
           *  Sum: '<S283>/Sum'
           *  Sum: '<S283>/Sum1'
           *  Sum: '<S284>/Sum of Elements'
           *  Sum: '<S285>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 +
            rtb_Saturation1_d * rtb_Saturation1_d) / sqrtf(rtb_a_bx * rtb_a_bx +
            rtb_Saturation_ga * rtb_Saturation_ga);

          /* Saturate: '<S283>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S283>/Saturation' */

          /* Sum: '<S300>/Subtract' incorporates:
           *  Product: '<S300>/Multiply'
           *  Product: '<S300>/Multiply1'
           */
          rtb_P_f_idx_0 = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S296>/Sign1' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S296>/Sign1' */

          /* Switch: '<S296>/Switch2' incorporates:
           *  Constant: '<S296>/Constant4'
           */
          if (rtb_P_f_idx_0 == 0.0F) {
            rtb_P_f_idx_0 = 1.0F;
          }

          /* End of Switch: '<S296>/Switch2' */

          /* DotProduct: '<S296>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S296>/Acos' incorporates:
           *  DotProduct: '<S296>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S296>/Multiply' incorporates:
           *  Trigonometry: '<S296>/Acos'
           */
          rtb_P_f_idx_0 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S295>/Saturation' */
          if (rtb_P_f_idx_0 > 1.57079637F) {
            rtb_P_f_idx_0 = 1.57079637F;
          } else {
            if (rtb_P_f_idx_0 < -1.57079637F) {
              rtb_P_f_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S295>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S260>/Bus Assignment1'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S260>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S260>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S295>/Divide' incorporates:
           *  Constant: '<S286>/L1'
           *  Gain: '<S295>/Gain'
           *  Math: '<S295>/Square'
           *  Product: '<S295>/Multiply1'
           *  Trigonometry: '<S295>/Sin'
           */
          rtb_a_bx = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F *
            arm_sin_f32(rtb_P_f_idx_0) / FMS_PARAM.FW_L1;

          /* Saturate: '<S286>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S286>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S281>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S283>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S281>/Sum2'
           *  Sum: '<S283>/Add'
           *  Sum: '<S283>/Subtract'
           */
          rtb_a_bx = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S281>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S260>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S281>/Saturation1' */
          /* End of Outputs for SubSystem: '<S112>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S112>/Hold' incorporates:
             *  ActionPort: '<S258>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S112>/Switch Case' incorporates:
             *  Delay: '<S263>/Delay'
             *  Delay: '<S268>/start_vel'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S112>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S112>/Hold' incorporates:
           *  ActionPort: '<S258>/Action Port'
           */
          /* Math: '<S275>/Math Function1'
           *
           * About '<S275>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S275>/Math Function1' */

          /* Switch: '<S275>/Switch' incorporates:
           *  Constant: '<S275>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S275>/Product'
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

          /* End of Switch: '<S275>/Switch' */

          /* Delay: '<S268>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S280>/Sum of Elements' incorporates:
           *  Delay: '<S268>/start_vel'
           *  Math: '<S280>/Math Function'
           */
          rtb_Saturation1_d = FMS_DW.start_vel_DSTATE[0] *
            FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
            FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S280>/Math Function1' incorporates:
           *  Sum: '<S280>/Sum of Elements'
           *
           * About '<S280>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S280>/Math Function1' */

          /* Switch: '<S280>/Switch' incorporates:
           *  Constant: '<S280>/Constant'
           *  Delay: '<S268>/start_vel'
           *  Product: '<S280>/Product'
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

          /* End of Switch: '<S280>/Switch' */

          /* Product: '<S275>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S278>/Sum of Elements' incorporates:
           *  Math: '<S278>/Math Function'
           *  SignalConversion: '<S278>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Divide_c14[1] * rtb_Divide_c14[1] +
            rtb_Divide_c14[0] * rtb_Divide_c14[0];

          /* Math: '<S278>/Math Function1' incorporates:
           *  Sum: '<S278>/Sum of Elements'
           *
           * About '<S278>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S278>/Math Function1' */

          /* Switch: '<S278>/Switch' incorporates:
           *  Constant: '<S278>/Constant'
           *  Product: '<S278>/Product'
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

          /* End of Switch: '<S278>/Switch' */

          /* MinMax: '<S266>/Max' incorporates:
           *  Constant: '<S264>/L1'
           *  Constant: '<S264>/R'
           *  Gain: '<S266>/Gain'
           */
          rtb_Saturation_ga = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S266>/SearchL1RefWP' incorporates:
           *  Constant: '<S264>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S271>/TmpSignal ConversionAt SFunction Inport2'
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
            rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 +
                      rtb_Saturation1_d * rtb_Saturation1_d);
            rtb_Divide_lr_idx_3 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_P_f_idx_0 = ((d * d + rtb_Divide_lr_idx_3) - rtb_Saturation_ga *
                             rtb_Saturation_ga) / (2.0F * d);
            rtb_Square_ds[0] = rtb_Saturation1_d / d;
            rtb_Divide_lr_idx_2 /= d;
            rtb_Saturation1_d = rtb_P_f_idx_0 * rtb_P_f_idx_0;
            if (rtb_Saturation1_d > rtb_Divide_lr_idx_3) {
              rtb_n = 0;
            } else if (rtb_Saturation1_d == rtb_Divide_lr_idx_3) {
              rtb_n = 1;
              rtb_P_ap[0] = rtb_P_f_idx_0 * rtb_Square_ds[0] + FMS_U.INS_Out.x_R;
              rtb_P_ap[1] = rtb_P_f_idx_0 * rtb_Divide_lr_idx_2 +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation1_d = sqrtf(rtb_Divide_lr_idx_3 - rtb_Saturation1_d);
              rtb_P_ap[0] = (rtb_P_f_idx_0 * rtb_Square_ds[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation1_d *
                -rtb_Divide_lr_idx_2;
              rtb_P_ap[1] = (rtb_P_f_idx_0 * rtb_Divide_lr_idx_2 +
                             FMS_U.INS_Out.y_R) + rtb_Saturation1_d *
                rtb_Square_ds[0];
            }
          }

          /* End of MATLAB Function: '<S266>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S269>/Compare' incorporates:
           *  Constant: '<S269>/Constant'
           */
          rtb_Compare_o3 = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S266>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract_hb[0] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Saturation1_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract_hb[1] = rtb_Saturation1_d * rtb_Saturation1_d;

          /* Switch: '<S266>/Switch' incorporates:
           *  Constant: '<S264>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S266>/OutRegionRegWP'
           *  Product: '<S280>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Compare_o3) {
            rtb_Saturation1_d = rtb_P_ap[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S266>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S267>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_ds[0] = rtb_Saturation1_d - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S266>/Switch' incorporates:
           *  Constant: '<S264>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S266>/OutRegionRegWP'
           *  Product: '<S280>/Divide'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Compare_o3) {
            rtb_Saturation1_d = rtb_P_ap[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] > rtb_Saturation_ga
                     * rtb_Saturation_ga) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S266>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S267>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Square_ds[1] = rtb_Saturation1_d - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S276>/Sum of Elements' incorporates:
           *  Math: '<S276>/Math Function'
           */
          rtb_Saturation1_d = rtb_Square_ds[0] * rtb_Square_ds[0] +
            rtb_Square_ds[1] * rtb_Square_ds[1];

          /* Math: '<S276>/Math Function1' incorporates:
           *  Sum: '<S276>/Sum of Elements'
           *
           * About '<S276>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S276>/Math Function1' */

          /* Switch: '<S276>/Switch' incorporates:
           *  Constant: '<S276>/Constant'
           *  Product: '<S276>/Product'
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

          /* End of Switch: '<S276>/Switch' */

          /* Product: '<S276>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];
          rtb_Divide_c14[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Sum: '<S279>/Sum of Elements' incorporates:
           *  Math: '<S279>/Math Function'
           *  SignalConversion: '<S279>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Divide_c14[1] * rtb_Divide_c14[1] +
            rtb_Divide_c14[0] * rtb_Divide_c14[0];

          /* Math: '<S279>/Math Function1' incorporates:
           *  Sum: '<S279>/Sum of Elements'
           *
           * About '<S279>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S279>/Math Function1' */

          /* Switch: '<S279>/Switch' incorporates:
           *  Constant: '<S279>/Constant'
           *  Product: '<S279>/Product'
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

          /* End of Switch: '<S279>/Switch' */

          /* Product: '<S279>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_ov[0] / rtb_Switch_ov[2];

          /* Product: '<S278>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S279>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_ov[1] / rtb_Switch_ov[2];

          /* Product: '<S278>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S277>/Subtract' incorporates:
           *  Product: '<S277>/Multiply'
           *  Product: '<S277>/Multiply1'
           */
          rtb_Saturation_ga = rtb_Divide_c14[0] * rtb_Subtract_hb[1] -
            rtb_Divide_c14[1] * rtb_Subtract_hb[0];

          /* Signum: '<S273>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S273>/Sign1' */

          /* Switch: '<S273>/Switch2' incorporates:
           *  Constant: '<S273>/Constant4'
           */
          if (rtb_Saturation_ga == 0.0F) {
            rtb_Saturation_ga = 1.0F;
          }

          /* End of Switch: '<S273>/Switch2' */

          /* DotProduct: '<S273>/Dot Product' */
          rtb_Divide_lr_idx_2 = rtb_Subtract_hb[0] * rtb_Divide_c14[0] +
            rtb_Subtract_hb[1] * rtb_Divide_c14[1];

          /* Trigonometry: '<S273>/Acos' incorporates:
           *  DotProduct: '<S273>/Dot Product'
           */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < -1.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            }
          }

          /* Product: '<S273>/Multiply' incorporates:
           *  Trigonometry: '<S273>/Acos'
           */
          rtb_Saturation_ga *= acosf(rtb_Divide_lr_idx_2);

          /* Saturate: '<S272>/Saturation' */
          if (rtb_Saturation_ga > 1.57079637F) {
            rtb_Saturation_ga = 1.57079637F;
          } else {
            if (rtb_Saturation_ga < -1.57079637F) {
              rtb_Saturation_ga = -1.57079637F;
            }
          }

          /* End of Saturate: '<S272>/Saturation' */

          /* Delay: '<S263>/Delay' incorporates:
           *  Gain: '<S265>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S258>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S258>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S258>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S258>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S272>/Divide' incorporates:
           *  Constant: '<S264>/L1'
           *  Gain: '<S272>/Gain'
           *  Math: '<S272>/Square'
           *  Product: '<S272>/Multiply1'
           *  Trigonometry: '<S272>/Sin'
           */
          rtb_a_bx = 2.0F * (rtb_Saturation1_p5 * rtb_Saturation1_p5) *
            arm_sin_f32(rtb_Saturation_ga) / FMS_PARAM.FW_L1;

          /* Saturate: '<S264>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S258>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S264>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S263>/Gain2' incorporates:
           *  Delay: '<S263>/Delay'
           *  Gain: '<S265>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S263>/Sum'
           */
          rtb_a_bx = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S263>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S258>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S258>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S263>/Saturation1' */

          /* Update for Delay: '<S268>/start_vel' */
          FMS_DW.icLoad_l = 0U;

          /* Update for Delay: '<S263>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S112>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S112>/Unknown' incorporates:
           *  ActionPort: '<S262>/Action Port'
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
           *  ActionPort: '<S225>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S225>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S225>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S225>/Bus Assignment' incorporates:
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
             *  ActionPort: '<S224>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S110>/Switch Case' incorporates:
             *  UnitDelay: '<S227>/Delay Input1'
             *
             * Block description for '<S227>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S110>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S110>/Mission' incorporates:
             *  ActionPort: '<S224>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S224>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S110>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S235>/Integrator'
             *  DiscreteIntegrator: '<S235>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;
            FMS_DW.Integrator_DSTATE_fk = 0.0F;

            /* End of SystemReset for SubSystem: '<S224>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S110>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S110>/Mission' incorporates:
           *  ActionPort: '<S224>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S227>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S227>/Delay Input1'
           *
           * Block description for '<S227>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S224>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S228>/Reset'
           */
          if (rtb_Compare_o3 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k !=
                                 POS_ZCSIG)) {
            /* InitializeConditions for DiscreteIntegrator: '<S235>/Integrator1' */
            FMS_DW.Integrator1_DSTATE_li = 0.0F;

            /* InitializeConditions for DiscreteIntegrator: '<S235>/Integrator' */
            FMS_DW.Integrator_DSTATE_fk = 0.0F;
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = rtb_Compare_o3;

          /* Math: '<S249>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Divide_lr_idx_2;
          rtb_Subtract_hb[1] = rtb_Divide_lr_idx_3;

          /* Sum: '<S249>/Sum of Elements' */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 + rtb_Divide_lr_idx_3;

          /* Math: '<S249>/Math Function1' incorporates:
           *  Sum: '<S249>/Sum of Elements'
           *
           * About '<S249>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S249>/Math Function1' */

          /* Switch: '<S249>/Switch' incorporates:
           *  Constant: '<S249>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S249>/Product'
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

          /* End of Switch: '<S249>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S239>/NearbyRefWP' incorporates:
           *  Constant: '<S237>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Saturation_ga);

          /* MATLAB Function: '<S239>/SearchL1RefWP' incorporates:
           *  Constant: '<S237>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_c14, &rtb_Saturation1_d);

          /* MATLAB Function: '<S239>/OutRegionRegWP' incorporates:
           *  Constant: '<S237>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_ap);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S239>/Switch1' incorporates:
           *  Constant: '<S242>/Constant'
           *  RelationalOperator: '<S242>/Compare'
           */
          if (rtb_Saturation_ga > 0.0F) {
            rtb_Divide_c14[0] = rtb_Subtract_hb[0];
            rtb_Divide_c14[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S241>/Compare' incorporates:
             *  Constant: '<S241>/Constant'
             */
            rtb_Compare_o3 = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S239>/Switch' */
            if (!rtb_Compare_o3) {
              rtb_Divide_c14[0] = rtb_P_ap[0];
              rtb_Divide_c14[1] = rtb_P_ap[1];
            }

            /* End of Switch: '<S239>/Switch' */
          }

          /* End of Switch: '<S239>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S240>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_c14[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_c14[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S250>/Sum of Elements' incorporates:
           *  Math: '<S250>/Math Function'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S250>/Math Function1' incorporates:
           *  Sum: '<S250>/Sum of Elements'
           *
           * About '<S250>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S250>/Math Function1' */

          /* Switch: '<S250>/Switch' incorporates:
           *  Constant: '<S250>/Constant'
           *  Product: '<S250>/Product'
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

          /* End of Switch: '<S250>/Switch' */

          /* Product: '<S249>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S252>/Sum of Elements' incorporates:
           *  Math: '<S252>/Math Function'
           *  SignalConversion: '<S252>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S252>/Math Function1' incorporates:
           *  Sum: '<S252>/Sum of Elements'
           *
           * About '<S252>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S252>/Math Function1' */

          /* Switch: '<S252>/Switch' incorporates:
           *  Constant: '<S252>/Constant'
           *  Product: '<S252>/Product'
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

          /* End of Switch: '<S252>/Switch' */

          /* Product: '<S250>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S253>/Sum of Elements' incorporates:
           *  Math: '<S253>/Math Function'
           *  SignalConversion: '<S253>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S253>/Math Function1' incorporates:
           *  Sum: '<S253>/Sum of Elements'
           *
           * About '<S253>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S253>/Math Function1' */

          /* Switch: '<S253>/Switch' incorporates:
           *  Constant: '<S253>/Constant'
           *  Product: '<S253>/Product'
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

          /* End of Switch: '<S253>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S232>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S253>/Divide' */
          rtb_Subtract_hb[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S252>/Divide' */
          rtb_Divide_c14[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S232>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_bx = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S253>/Divide' */
          rtb_Subtract_hb[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S252>/Divide' */
          rtb_Divide_c14[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S232>/Sum1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_ga = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S232>/Divide' incorporates:
           *  Math: '<S233>/Square'
           *  Math: '<S234>/Square'
           *  Sqrt: '<S233>/Sqrt'
           *  Sqrt: '<S234>/Sqrt'
           *  Sum: '<S232>/Sum'
           *  Sum: '<S232>/Sum1'
           *  Sum: '<S233>/Sum of Elements'
           *  Sum: '<S234>/Sum of Elements'
           */
          rtb_Saturation_ga = sqrtf(rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 +
            rtb_Saturation1_d * rtb_Saturation1_d) / sqrtf(rtb_a_bx * rtb_a_bx +
            rtb_Saturation_ga * rtb_Saturation_ga);

          /* Saturate: '<S232>/Saturation' */
          if (rtb_Saturation_ga > 1.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = 0.0F;
            }
          }

          /* End of Saturate: '<S232>/Saturation' */

          /* Sum: '<S251>/Subtract' incorporates:
           *  Product: '<S251>/Multiply'
           *  Product: '<S251>/Multiply1'
           */
          rtb_P_f_idx_0 = rtb_Subtract_hb[0] * rtb_Divide_c14[1] -
            rtb_Subtract_hb[1] * rtb_Divide_c14[0];

          /* Signum: '<S247>/Sign1' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S247>/Sign1' */

          /* Switch: '<S247>/Switch2' incorporates:
           *  Constant: '<S247>/Constant4'
           */
          if (rtb_P_f_idx_0 == 0.0F) {
            rtb_P_f_idx_0 = 1.0F;
          }

          /* End of Switch: '<S247>/Switch2' */

          /* DotProduct: '<S247>/Dot Product' */
          rtb_Saturation1_d = rtb_Divide_c14[0] * rtb_Subtract_hb[0] +
            rtb_Divide_c14[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S247>/Acos' incorporates:
           *  DotProduct: '<S247>/Dot Product'
           */
          if (rtb_Saturation1_d > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            if (rtb_Saturation1_d < -1.0F) {
              rtb_Saturation1_d = -1.0F;
            }
          }

          /* Product: '<S247>/Multiply' incorporates:
           *  Trigonometry: '<S247>/Acos'
           */
          rtb_P_f_idx_0 *= acosf(rtb_Saturation1_d);

          /* Saturate: '<S246>/Saturation' */
          if (rtb_P_f_idx_0 > 1.57079637F) {
            rtb_P_f_idx_0 = 1.57079637F;
          } else {
            if (rtb_P_f_idx_0 < -1.57079637F) {
              rtb_P_f_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S246>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S228>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S228>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S228>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Saturate: '<S230>/Saturation' */
          if (FMS_DW.Integrator1_DSTATE_li > FMS_PARAM.FW_SPEED_MAX) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MAX;
          } else if (FMS_DW.Integrator1_DSTATE_li < FMS_PARAM.FW_SPEED_MIN) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_SPEED_MIN;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_li;
          }

          /* End of Saturate: '<S230>/Saturation' */

          /* Product: '<S246>/Divide' incorporates:
           *  Constant: '<S237>/L1'
           *  Gain: '<S246>/Gain'
           *  Math: '<S246>/Square'
           *  Product: '<S246>/Multiply1'
           *  Trigonometry: '<S246>/Sin'
           */
          rtb_a_bx = rtb_Saturation1_p5 * rtb_Saturation1_p5 * 2.0F *
            arm_sin_f32(rtb_P_f_idx_0) / FMS_PARAM.FW_L1;

          /* Saturate: '<S237>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S237>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S229>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S232>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S229>/Sum2'
           *  Sum: '<S232>/Add'
           *  Sum: '<S232>/Subtract'
           */
          rtb_a_bx = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_ga +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S229>/Saturation1' */
          if (rtb_a_bx > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S229>/Saturation1' */

          /* Product: '<S236>/Multiply1' incorporates:
           *  Constant: '<S236>/const1'
           *  DiscreteIntegrator: '<S235>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_fk * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S230>/Switch' incorporates:
           *  Constant: '<S230>/Constant4'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            rtb_Saturation1_d = FMS_B.Cmd_In.set_speed;
          } else {
            rtb_Saturation1_d = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S230>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S236>/Add' incorporates:
           *  DiscreteIntegrator: '<S235>/Integrator1'
           *  Sum: '<S235>/Subtract'
           */
          rtb_P_f_idx_0 = (FMS_DW.Integrator1_DSTATE_li - rtb_Saturation1_d) +
            rtb_Saturation_ga;

          /* Signum: '<S236>/Sign' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            rtb_Saturation1_d = rtb_P_f_idx_0;
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
          rtb_Saturation1_d = (sqrtf((8.0F * fabsf(rtb_P_f_idx_0) +
            FMS_ConstB.d_cy) * FMS_ConstB.d_cy) - FMS_ConstB.d_cy) * 0.5F *
            rtb_Saturation1_d + rtb_Saturation_ga;

          /* Sum: '<S236>/Add4' */
          rtb_Saturation1_p5 = (rtb_P_f_idx_0 - rtb_Saturation1_d) +
            rtb_Saturation_ga;

          /* Sum: '<S236>/Add3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_cy;

          /* Sum: '<S236>/Subtract1' */
          rtb_P_f_idx_0 -= FMS_ConstB.d_cy;

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
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign2' */

          /* Sum: '<S236>/Add5' incorporates:
           *  Gain: '<S236>/Gain2'
           *  Product: '<S236>/Multiply4'
           *  Sum: '<S236>/Subtract2'
           */
          rtb_Saturation1_d += (rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F *
            rtb_Saturation1_p5;

          /* Update for DiscreteIntegrator: '<S235>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S235>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_li += 0.004F * FMS_DW.Integrator_DSTATE_fk;

          /* Sum: '<S236>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_d - FMS_ConstB.d_cy;

          /* Sum: '<S236>/Add6' */
          rtb_P_f_idx_0 = rtb_Saturation1_d + FMS_ConstB.d_cy;

          /* Signum: '<S236>/Sign5' incorporates:
           *  Signum: '<S236>/Sign6'
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S236>/Sign6' */
            d = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S236>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation1_d;

            /* Signum: '<S236>/Sign6' */
            d = rtb_Saturation1_d;
          }

          /* End of Signum: '<S236>/Sign5' */

          /* Signum: '<S236>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign3' */

          /* Signum: '<S236>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign4' */

          /* Update for DiscreteIntegrator: '<S235>/Integrator' incorporates:
           *  Constant: '<S236>/const'
           *  Gain: '<S236>/Gain3'
           *  Product: '<S236>/Divide'
           *  Product: '<S236>/Multiply5'
           *  Product: '<S236>/Multiply6'
           *  Sum: '<S236>/Subtract4'
           *  Sum: '<S236>/Subtract5'
           *  Sum: '<S236>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_fk += ((rtb_Saturation1_d / FMS_ConstB.d_cy -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_ka * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 78.448F) * 0.004F;

          /* End of Outputs for SubSystem: '<S224>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S227>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S227>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S110>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S110>/Unknown' incorporates:
           *  ActionPort: '<S226>/Action Port'
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
             *  DiscreteIntegrator: '<S217>/Integrator'
             *  DiscreteIntegrator: '<S217>/Integrator1'
             *  DiscreteIntegrator: '<S218>/Integrator'
             *  DiscreteIntegrator: '<S218>/Integrator1'
             *  DiscreteIntegrator: '<S222>/Integrator'
             *  DiscreteIntegrator: '<S222>/Integrator1'
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
          /* Product: '<S219>/Multiply1' incorporates:
           *  Constant: '<S219>/const1'
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S215>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S215>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S219>/Add' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  Gain: '<S212>/Gain'
           *  Gain: '<S215>/Gain'
           *  Sum: '<S217>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * FMS_PARAM.FW_ROLL_LIM) +
            rtb_a_bx;

          /* Signum: '<S219>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_d;
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
          rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Saturation_ga + rtb_a_bx;

          /* Sum: '<S219>/Add4' */
          rtb_Saturation1_p5 = (rtb_Saturation1_d - rtb_Integrator1_bx) +
            rtb_a_bx;

          /* Sum: '<S219>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_ny;

          /* Sum: '<S219>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_ny;

          /* Signum: '<S219>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign1' */

          /* Signum: '<S219>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign2' */

          /* Sum: '<S219>/Add5' incorporates:
           *  Gain: '<S219>/Gain2'
           *  Product: '<S219>/Multiply4'
           *  Sum: '<S219>/Subtract2'
           */
          rtb_Integrator1_bx += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation1_p5;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S116>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S116>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  DiscreteIntegrator: '<S218>/Integrator1'
           *  DiscreteIntegrator: '<S222>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_oo;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_jv;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S214>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation1_d = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S214>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S214>/Constant5'
           *  Gain: '<S214>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S214>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_Saturation1_d), 65536.0F) + 1000U);

          /* Product: '<S223>/Multiply1' incorporates:
           *  Constant: '<S223>/const1'
           *  DiscreteIntegrator: '<S222>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_j * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S221>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S221>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S223>/Add' incorporates:
           *  DiscreteIntegrator: '<S222>/Integrator1'
           *  Gain: '<S213>/Gain1'
           *  Gain: '<S221>/Gain'
           *  Sum: '<S222>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jv - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation1_d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_bx;

          /* Signum: '<S223>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S223>/Sign' */

          /* Sum: '<S223>/Add2' incorporates:
           *  Abs: '<S223>/Abs'
           *  Gain: '<S223>/Gain'
           *  Gain: '<S223>/Gain1'
           *  Product: '<S223>/Multiply2'
           *  Product: '<S223>/Multiply3'
           *  Sqrt: '<S223>/Sqrt'
           *  Sum: '<S223>/Add1'
           *  Sum: '<S223>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_mq) * FMS_ConstB.d_mq) - FMS_ConstB.d_mq) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_a_bx;

          /* Sum: '<S223>/Add4' */
          rtb_P_f_idx_0 = (rtb_Saturation1_d - rtb_Saturation1_p5) + rtb_a_bx;

          /* Sum: '<S223>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_mq;

          /* Sum: '<S223>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_mq;

          /* Signum: '<S223>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S223>/Sign1' */

          /* Signum: '<S223>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S223>/Sign2' */

          /* Sum: '<S223>/Add5' incorporates:
           *  Gain: '<S223>/Gain2'
           *  Product: '<S223>/Multiply4'
           *  Sum: '<S223>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_P_f_idx_0;

          /* Sum: '<S223>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_mq;

          /* Sum: '<S223>/Subtract3' */
          rtb_P_f_idx_0 = rtb_Saturation1_p5 - FMS_ConstB.d_mq;

          /* Product: '<S223>/Divide' */
          rtb_Divide_ox = rtb_Saturation1_p5 / FMS_ConstB.d_mq;

          /* Signum: '<S223>/Sign5' incorporates:
           *  Signum: '<S223>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_u_b = -1.0F;

            /* Signum: '<S223>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_u_b = 1.0F;

            /* Signum: '<S223>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_u_b = rtb_Saturation1_p5;

            /* Signum: '<S223>/Sign6' */
            rtb_Divide_lr_idx_2 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S223>/Sign5' */

          /* Product: '<S220>/Multiply1' incorporates:
           *  Constant: '<S220>/const1'
           *  DiscreteIntegrator: '<S218>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S216>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S216>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S220>/Add' incorporates:
           *  DiscreteIntegrator: '<S218>/Integrator1'
           *  Gain: '<S212>/Gain1'
           *  Gain: '<S216>/Gain'
           *  Sum: '<S218>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_oo - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation1_d * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S220>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S220>/Sign' */

          /* Sum: '<S220>/Add2' incorporates:
           *  Abs: '<S220>/Abs'
           *  Gain: '<S220>/Gain'
           *  Gain: '<S220>/Gain1'
           *  Product: '<S220>/Multiply2'
           *  Product: '<S220>/Multiply3'
           *  Sqrt: '<S220>/Sqrt'
           *  Sum: '<S220>/Add1'
           *  Sum: '<S220>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_my) *
                            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Saturation1_p5;

          /* Sum: '<S220>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_Saturation1_d - rtb_a_bx) +
            rtb_Saturation1_p5;

          /* Sum: '<S220>/Add3' */
          rtb_Saturation1_p5 = rtb_Saturation1_d + FMS_ConstB.d_my;

          /* Sum: '<S220>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_my;

          /* Signum: '<S220>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S220>/Sign1' */

          /* Signum: '<S220>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S220>/Sign2' */

          /* Sum: '<S220>/Add5' incorporates:
           *  Gain: '<S220>/Gain2'
           *  Product: '<S220>/Multiply4'
           *  Sum: '<S220>/Subtract2'
           */
          rtb_a_bx += (rtb_Saturation1_p5 - rtb_Saturation1_d) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Update for DiscreteIntegrator: '<S217>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S219>/Subtract3' */
          rtb_Saturation1_p5 = rtb_Integrator1_bx - FMS_ConstB.d_ny;

          /* Sum: '<S219>/Add6' */
          rtb_Divide_lr_idx_3 = rtb_Integrator1_bx + FMS_ConstB.d_ny;

          /* Signum: '<S219>/Sign5' incorporates:
           *  Signum: '<S219>/Sign6'
           */
          if (rtb_Integrator1_bx < 0.0F) {
            d = -1.0F;

            /* Signum: '<S219>/Sign6' */
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_Integrator1_bx > 0.0F) {
            d = 1.0F;

            /* Signum: '<S219>/Sign6' */
            rtb_Saturation1_d = 1.0F;
          } else {
            d = rtb_Integrator1_bx;

            /* Signum: '<S219>/Sign6' */
            rtb_Saturation1_d = rtb_Integrator1_bx;
          }

          /* End of Signum: '<S219>/Sign5' */

          /* Signum: '<S219>/Sign3' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S219>/Sign3' */

          /* Signum: '<S219>/Sign4' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_av += ((rtb_Integrator1_bx / FMS_ConstB.d_ny
            - d) * FMS_ConstB.Gain4_ko * ((rtb_Divide_lr_idx_3 -
            rtb_Saturation1_p5) * 0.5F) - rtb_Saturation1_d * 12.566371F) *
            0.004F;

          /* Update for DiscreteIntegrator: '<S218>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S218>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_oo += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S222>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S222>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_jv += 0.004F * FMS_DW.Integrator_DSTATE_j;

          /* Signum: '<S223>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S223>/Sign3' */

          /* Signum: '<S223>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S223>/Sign4' */

          /* Update for DiscreteIntegrator: '<S222>/Integrator' incorporates:
           *  Constant: '<S223>/const'
           *  Gain: '<S223>/Gain3'
           *  Product: '<S223>/Multiply5'
           *  Product: '<S223>/Multiply6'
           *  Sum: '<S223>/Subtract4'
           *  Sum: '<S223>/Subtract5'
           *  Sum: '<S223>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_j += ((rtb_Divide_ox - rtb_u_b) *
            FMS_ConstB.Gain4_b * ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) -
            rtb_Divide_lr_idx_2 * 15.707963F) * 0.004F;

          /* Sum: '<S220>/Subtract3' */
          rtb_Saturation_ga = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S220>/Add6' */
          rtb_P_f_idx_0 = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S220>/Sign5' incorporates:
           *  Signum: '<S220>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S220>/Sign6' */
            d = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S220>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_a_bx;

            /* Signum: '<S220>/Sign6' */
            d = rtb_a_bx;
          }

          /* End of Signum: '<S220>/Sign5' */

          /* Signum: '<S220>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S220>/Sign3' */

          /* Signum: '<S220>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S220>/Sign4' */

          /* Update for DiscreteIntegrator: '<S218>/Integrator' incorporates:
           *  Constant: '<S220>/const'
           *  Gain: '<S220>/Gain3'
           *  Product: '<S220>/Divide'
           *  Product: '<S220>/Multiply5'
           *  Product: '<S220>/Multiply6'
           *  Sum: '<S220>/Subtract4'
           *  Sum: '<S220>/Subtract5'
           *  Sum: '<S220>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_bx / FMS_ConstB.d_my -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_k2 * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 12.566371F) * 0.004F;

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
            rtb_Saturation1_d = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_lj < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_Saturation1_d = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_Saturation1_d = FMS_B.Merge_lj;
          }

          /* End of Saturate: '<S122>/Saturation1' */

          /* Sum: '<S131>/Add' incorporates:
           *  DiscreteIntegrator: '<S126>/Integrator1'
           *  Sum: '<S126>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_a - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S131>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Saturation1_p5 = 1.0F;
          } else {
            rtb_Saturation1_p5 = rtb_Saturation1_d;
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
            rtb_Saturation1_p5 + rtb_Saturation_ga;

          /* Sum: '<S131>/Add4' */
          rtb_Saturation1_p5 = (rtb_Saturation1_d - rtb_a_bx) +
            rtb_Saturation_ga;

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
            rtb_Saturation1_p5;

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
          rtb_u_b = FMS_DW.Integrator_DSTATE_n * 0.05F;

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
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_o - rtb_Saturation_ga)
            + rtb_u_b;

          /* Signum: '<S142>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_Saturation1_d;
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
          rtb_Divide_ox = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_e) * FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F *
            rtb_Add4_pb + rtb_u_b;

          /* Sum: '<S142>/Add4' */
          rtb_Saturation1_p5 = (rtb_Saturation1_d - rtb_Divide_ox) + rtb_u_b;

          /* Sum: '<S142>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_e;

          /* Sum: '<S142>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_e;

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
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S142>/Sign2' */

          /* Sum: '<S142>/Add5' incorporates:
           *  Gain: '<S142>/Gain2'
           *  Product: '<S142>/Multiply4'
           *  Sum: '<S142>/Subtract2'
           */
          rtb_Divide_ox += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation1_p5;

          /* Sum: '<S142>/Add6' */
          rtb_Saturation_ga = rtb_Divide_ox + FMS_ConstB.d_e;

          /* Sum: '<S142>/Subtract3' */
          rtb_P_f_idx_0 = rtb_Divide_ox - FMS_ConstB.d_e;

          /* Product: '<S142>/Divide' */
          rtb_Divide_ic = rtb_Divide_ox / FMS_ConstB.d_e;

          /* Signum: '<S142>/Sign5' incorporates:
           *  Signum: '<S142>/Sign6'
           */
          if (rtb_Divide_ox < 0.0F) {
            rtb_Sign5_af = -1.0F;

            /* Signum: '<S142>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Divide_ox > 0.0F) {
            rtb_Sign5_af = 1.0F;

            /* Signum: '<S142>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_af = rtb_Divide_ox;

            /* Signum: '<S142>/Sign6' */
            rtb_Divide_lr_idx_2 = rtb_Divide_ox;
          }

          /* End of Signum: '<S142>/Sign5' */

          /* Product: '<S139>/Multiply1' incorporates:
           *  Constant: '<S139>/const1'
           *  DiscreteIntegrator: '<S138>/Integrator'
           */
          rtb_Divide_ox = FMS_DW.Integrator_DSTATE_er * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S137>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S137>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S139>/Add' incorporates:
           *  DiscreteIntegrator: '<S138>/Integrator1'
           *  Gain: '<S120>/Gain1'
           *  Gain: '<S137>/Gain'
           *  Sum: '<S138>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_jl - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation1_d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_ox;

          /* Signum: '<S139>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_Saturation1_d;
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
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_cb) *
                           FMS_ConstB.d_cb) - FMS_ConstB.d_cb) * 0.5F *
            rtb_Add4_pb + rtb_Divide_ox;

          /* Sum: '<S139>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_Saturation1_d - rtb_u_b) + rtb_Divide_ox;

          /* Sum: '<S139>/Add3' */
          rtb_Saturation1_p5 = rtb_Saturation1_d + FMS_ConstB.d_cb;

          /* Sum: '<S139>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_cb;

          /* Signum: '<S139>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign1' */

          /* Signum: '<S139>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign2' */

          /* Sum: '<S139>/Add5' incorporates:
           *  Gain: '<S139>/Gain2'
           *  Product: '<S139>/Multiply4'
           *  Sum: '<S139>/Subtract2'
           */
          rtb_u_b += (rtb_Saturation1_p5 - rtb_Saturation1_d) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S139>/Add6' */
          rtb_Saturation1_p5 = rtb_u_b + FMS_ConstB.d_cb;

          /* Sum: '<S139>/Subtract3' */
          rtb_Divide_lr_idx_3 = rtb_u_b - FMS_ConstB.d_cb;

          /* Product: '<S139>/Divide' */
          rtb_Divide_e = rtb_u_b / FMS_ConstB.d_cb;

          /* Signum: '<S139>/Sign5' incorporates:
           *  Signum: '<S139>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Sign5_i = -1.0F;

            /* Signum: '<S139>/Sign6' */
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Sign5_i = 1.0F;

            /* Signum: '<S139>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Sign5_i = rtb_u_b;

            /* Signum: '<S139>/Sign6' */
            d = rtb_u_b;
          }

          /* End of Signum: '<S139>/Sign5' */

          /* Product: '<S136>/Multiply1' incorporates:
           *  Constant: '<S136>/const1'
           *  DiscreteIntegrator: '<S135>/Integrator'
           */
          rtb_Divide_ox = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S134>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S134>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S136>/Add' incorporates:
           *  DiscreteIntegrator: '<S135>/Integrator1'
           *  Gain: '<S119>/Gain'
           *  Gain: '<S134>/Gain'
           *  Sum: '<S135>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Divide_ox;

          /* Signum: '<S136>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Add4_pb = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Add4_pb = 1.0F;
          } else {
            rtb_Add4_pb = rtb_Saturation1_d;
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
          rtb_u_b = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_bi) *
                           FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Add4_pb + rtb_Divide_ox;

          /* Sum: '<S136>/Add4' */
          rtb_Add4_pb = (rtb_Saturation1_d - rtb_u_b) + rtb_Divide_ox;

          /* Sum: '<S136>/Add3' */
          rtb_Divide_ox = rtb_Saturation1_d + FMS_ConstB.d_bi;

          /* Sum: '<S136>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_bi;

          /* Signum: '<S136>/Sign1' */
          if (rtb_Divide_ox < 0.0F) {
            rtb_Divide_ox = -1.0F;
          } else {
            if (rtb_Divide_ox > 0.0F) {
              rtb_Divide_ox = 1.0F;
            }
          }

          /* End of Signum: '<S136>/Sign1' */

          /* Signum: '<S136>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S136>/Sign2' */

          /* Sum: '<S136>/Add5' incorporates:
           *  Gain: '<S136>/Gain2'
           *  Product: '<S136>/Multiply4'
           *  Sum: '<S136>/Subtract2'
           */
          rtb_u_b += (rtb_Divide_ox - rtb_Saturation1_d) * 0.5F * rtb_Add4_pb;

          /* Sum: '<S131>/Subtract3' */
          rtb_Divide_ox = rtb_a_bx - FMS_ConstB.d_ar;

          /* Sum: '<S131>/Add6' */
          rtb_Add4_pb = rtb_a_bx + FMS_ConstB.d_ar;

          /* Signum: '<S131>/Sign5' incorporates:
           *  Signum: '<S131>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Saturation1_d = -1.0F;

            /* Signum: '<S131>/Sign6' */
            y = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Saturation1_d = 1.0F;

            /* Signum: '<S131>/Sign6' */
            y = 1.0F;
          } else {
            rtb_Saturation1_d = rtb_a_bx;

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
          if (rtb_Divide_ox < 0.0F) {
            rtb_Divide_ox = -1.0F;
          } else {
            if (rtb_Divide_ox > 0.0F) {
              rtb_Divide_ox = 1.0F;
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
          FMS_DW.Integrator_DSTATE_hd += ((rtb_a_bx / FMS_ConstB.d_ar -
            rtb_Saturation1_d) * FMS_ConstB.Gain4_am * ((rtb_Add4_pb -
            rtb_Divide_ox) * 0.5F) - y * 78.448F) * 0.004F;

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
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_n += ((rtb_Divide_ic - rtb_Sign5_af) *
            FMS_ConstB.Gain4_l * ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) -
            rtb_Divide_lr_idx_2 * 78.448F) * 0.004F;

          /* Signum: '<S139>/Sign3' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S139>/Sign3' */

          /* Signum: '<S139>/Sign4' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_er += ((rtb_Divide_e - rtb_Sign5_i) *
            FMS_ConstB.Gain4_ci * ((rtb_Saturation1_p5 - rtb_Divide_lr_idx_3) *
            0.5F) - d * 15.707963F) * 0.004F;

          /* Sum: '<S136>/Subtract3' */
          rtb_Saturation_ga = rtb_u_b - FMS_ConstB.d_bi;

          /* Sum: '<S136>/Add6' */
          rtb_P_f_idx_0 = rtb_u_b + FMS_ConstB.d_bi;

          /* Signum: '<S136>/Sign5' incorporates:
           *  Signum: '<S136>/Sign6'
           */
          if (rtb_u_b < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S136>/Sign6' */
            d = -1.0F;
          } else if (rtb_u_b > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S136>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_u_b;

            /* Signum: '<S136>/Sign6' */
            d = rtb_u_b;
          }

          /* End of Signum: '<S136>/Sign5' */

          /* Signum: '<S136>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_u_b / FMS_ConstB.d_bi -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_d1 * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 12.566371F) * 0.004F;

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
             *  DiscreteIntegrator: '<S210>/Integrator'
             *  DiscreteIntegrator: '<S210>/Integrator1'
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
          /* Trigonometry: '<S208>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S208>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

          /* SignalConversion: '<S208>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S208>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S208>/Gain' incorporates:
           *  Gain: '<S207>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S208>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S208>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S208>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S208>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S208>/ConcatBufferAtVector ConcatenateIn3' */
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
           *  Constant: '<S204>/Constant'
           *  Constant: '<S205>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Logic: '<S163>/Logical Operator'
           *  RelationalOperator: '<S204>/Compare'
           *  RelationalOperator: '<S205>/Compare'
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
            /* DeadZone: '<S201>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S201>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S165>/Gain6' incorporates:
             *  Gain: '<S201>/Gain'
             */
            FMS_B.Merge_be = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation1_d * FMS_PARAM.FW_ACC_Y_LIM;

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
          rtb_Divide_ox = FMS_DW.Integrator_DSTATE_c5 * 0.05F;

          /* Saturate: '<S147>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_Saturation1_d = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            rtb_Saturation1_d = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            rtb_Saturation1_d = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S147>/Saturation1' */

          /* Sum: '<S156>/Add' incorporates:
           *  DiscreteIntegrator: '<S151>/Integrator1'
           *  Sum: '<S151>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_i - rtb_Saturation1_d)
            + rtb_Divide_ox;

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
            rtb_Saturation_ga + rtb_Divide_ox;

          /* Sum: '<S156>/Add4' */
          rtb_Saturation1_p5 = (rtb_Saturation1_d - rtb_a_bx) + rtb_Divide_ox;

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
            rtb_Saturation1_p5;

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

          /* Product: '<S211>/Multiply1' incorporates:
           *  Constant: '<S211>/const1'
           *  DiscreteIntegrator: '<S210>/Integrator'
           */
          rtb_Saturation1_d = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Switch: '<S209>/Switch' incorporates:
           *  Constant: '<S209>/Constant'
           *  Constant: '<S209>/Constant1'
           *  Constant: '<S209>/Constant2'
           *  Product: '<S209>/Multiply'
           *  Product: '<S209>/Multiply1'
           *  Sum: '<S209>/Subtract'
           *  Sum: '<S209>/Subtract1'
           *  Sum: '<S209>/Sum'
           *  Sum: '<S209>/Sum1'
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

          /* End of Switch: '<S209>/Switch' */

          /* Sum: '<S211>/Add' incorporates:
           *  DiscreteIntegrator: '<S210>/Integrator1'
           *  Sum: '<S210>/Subtract'
           */
          rtb_Divide_ox = (FMS_DW.Integrator1_DSTATE_nd - rtb_Saturation_ga) +
            rtb_Saturation1_d;

          /* Signum: '<S211>/Sign' */
          if (rtb_Divide_ox < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Divide_ox > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Divide_ox;
          }

          /* End of Signum: '<S211>/Sign' */

          /* Sum: '<S211>/Add2' incorporates:
           *  Abs: '<S211>/Abs'
           *  Gain: '<S211>/Gain'
           *  Gain: '<S211>/Gain1'
           *  Product: '<S211>/Multiply2'
           *  Product: '<S211>/Multiply3'
           *  Sqrt: '<S211>/Sqrt'
           *  Sum: '<S211>/Add1'
           *  Sum: '<S211>/Subtract'
           */
          rtb_Saturation1_p5 = (sqrtf((8.0F * fabsf(rtb_Divide_ox) +
            FMS_ConstB.d_ad) * FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F *
            rtb_Saturation_ga + rtb_Saturation1_d;

          /* Sum: '<S211>/Add4' */
          rtb_Saturation1_d += rtb_Divide_ox - rtb_Saturation1_p5;

          /* Sum: '<S211>/Add3' */
          rtb_Saturation_ga = rtb_Divide_ox + FMS_ConstB.d_ad;

          /* Sum: '<S211>/Subtract1' */
          rtb_Divide_ox -= FMS_ConstB.d_ad;

          /* Signum: '<S211>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S211>/Sign1' */

          /* Signum: '<S211>/Sign2' */
          if (rtb_Divide_ox < 0.0F) {
            rtb_Divide_ox = -1.0F;
          } else {
            if (rtb_Divide_ox > 0.0F) {
              rtb_Divide_ox = 1.0F;
            }
          }

          /* End of Signum: '<S211>/Sign2' */

          /* Sum: '<S211>/Add5' incorporates:
           *  Gain: '<S211>/Gain2'
           *  Product: '<S211>/Multiply4'
           *  Sum: '<S211>/Subtract2'
           */
          rtb_Saturation1_p5 += (rtb_Saturation_ga - rtb_Divide_ox) * 0.5F *
            rtb_Saturation1_d;

          /* Sum: '<S211>/Add6' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_ad;

          /* Sum: '<S211>/Subtract3' */
          rtb_P_f_idx_0 = rtb_Saturation1_p5 - FMS_ConstB.d_ad;

          /* Product: '<S211>/Divide' */
          rtb_u_b = rtb_Saturation1_p5 / FMS_ConstB.d_ad;

          /* Signum: '<S211>/Sign5' incorporates:
           *  Signum: '<S211>/Sign6'
           */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Divide_ic = -1.0F;

            /* Signum: '<S211>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Divide_ic = 1.0F;

            /* Signum: '<S211>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_ic = rtb_Saturation1_p5;

            /* Signum: '<S211>/Sign6' */
            rtb_Divide_lr_idx_2 = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S211>/Sign5' */

          /* Product: '<S161>/Multiply1' incorporates:
           *  Constant: '<S161>/const1'
           *  DiscreteIntegrator: '<S160>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S159>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S159>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S161>/Add' incorporates:
           *  DiscreteIntegrator: '<S160>/Integrator1'
           *  Gain: '<S144>/Gain1'
           *  Gain: '<S159>/Gain'
           *  Sum: '<S160>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_l5 - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation1_d * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S161>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
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
          rtb_Divide_ox = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Saturation1_p5;

          /* Sum: '<S161>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_Saturation1_d - rtb_Divide_ox) +
            rtb_Saturation1_p5;

          /* Sum: '<S161>/Add3' */
          rtb_Saturation1_p5 = rtb_Saturation1_d + FMS_ConstB.d_l;

          /* Sum: '<S161>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_l;

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
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S161>/Sign2' */

          /* Sum: '<S161>/Add5' incorporates:
           *  Gain: '<S161>/Gain2'
           *  Product: '<S161>/Multiply4'
           *  Sum: '<S161>/Subtract2'
           */
          rtb_Divide_ox += (rtb_Saturation1_p5 - rtb_Saturation1_d) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S156>/Subtract3' */
          rtb_Saturation1_p5 = rtb_a_bx - FMS_ConstB.d_av;

          /* Sum: '<S156>/Add6' */
          rtb_Divide_lr_idx_3 = rtb_a_bx + FMS_ConstB.d_av;

          /* Signum: '<S156>/Sign5' incorporates:
           *  Signum: '<S156>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            d = -1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            d = 1.0F;

            /* Signum: '<S156>/Sign6' */
            rtb_Saturation1_d = 1.0F;
          } else {
            d = rtb_a_bx;

            /* Signum: '<S156>/Sign6' */
            rtb_Saturation1_d = rtb_a_bx;
          }

          /* End of Signum: '<S156>/Sign5' */

          /* Signum: '<S156>/Sign3' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S156>/Sign3' */

          /* Signum: '<S156>/Sign4' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_c5 += ((rtb_a_bx / FMS_ConstB.d_av - d) *
            FMS_ConstB.Gain4_p5 * ((rtb_Divide_lr_idx_3 - rtb_Saturation1_p5) *
            0.5F) - rtb_Saturation1_d * 78.448F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S151>/Integrator1' */
          FMS_DW.Integrator1_DSTATE_i += 0.004F * rtb_Integrator1_bx;

          /* Update for DiscreteIntegrator: '<S160>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S160>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l5 += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S210>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S210>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S211>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S211>/Sign3' */

          /* Signum: '<S211>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S211>/Sign4' */

          /* Update for DiscreteIntegrator: '<S210>/Integrator' incorporates:
           *  Constant: '<S211>/const'
           *  Gain: '<S211>/Gain3'
           *  Product: '<S211>/Multiply5'
           *  Product: '<S211>/Multiply6'
           *  Sum: '<S211>/Subtract4'
           *  Sum: '<S211>/Subtract5'
           *  Sum: '<S211>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_u_b - rtb_Divide_ic) *
            FMS_ConstB.Gain4_f * ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) -
            rtb_Divide_lr_idx_2 * 78.448F) * 0.004F;

          /* Sum: '<S161>/Subtract3' */
          rtb_Saturation_ga = rtb_Divide_ox - FMS_ConstB.d_l;

          /* Sum: '<S161>/Add6' */
          rtb_P_f_idx_0 = rtb_Divide_ox + FMS_ConstB.d_l;

          /* Signum: '<S161>/Sign5' incorporates:
           *  Signum: '<S161>/Sign6'
           */
          if (rtb_Divide_ox < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S161>/Sign6' */
            d = -1.0F;
          } else if (rtb_Divide_ox > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S161>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Divide_ox;

            /* Signum: '<S161>/Sign6' */
            d = rtb_Divide_ox;
          }

          /* End of Signum: '<S161>/Sign5' */

          /* Signum: '<S161>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_ha += ((rtb_Divide_ox / FMS_ConstB.d_l -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_ak * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 15.707963F) * 0.004F;

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
        /* DeadZone: '<S254>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation1_d = 0.0F;
        } else {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S254>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S254>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Saturation1_d;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S255>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation1_d = 0.0F;
        } else {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S255>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S111>/Gain'
         *  Gain: '<S255>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Saturation1_d);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S256>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation1_d = 0.0F;
        } else {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S256>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S256>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation1_d;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S257>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S43>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle -
            FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_Saturation1_d = 0.0F;
        } else {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle -
            (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S257>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S111>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Gain: '<S257>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) *
          rtb_Saturation1_d;

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
      rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

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
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation1_d = 0.0F;
        } else {
          rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S92>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S57>/Gain6' incorporates:
         *  Gain: '<S92>/Gain'
         */
        FMS_B.Merge_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d *
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
        rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
      } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
        rtb_Saturation1_d = 0.0F;
      } else {
        rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
      }

      /* End of DeadZone: '<S102>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S107>/Add' incorporates:
       *  DiscreteIntegrator: '<S104>/Integrator1'
       *  Gain: '<S102>/Gain'
       *  Gain: '<S52>/Gain2'
       *  Sum: '<S104>/Subtract'
       */
      rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_hf - 1.0F / (1.0F -
        FMS_PARAM.YAW_DZ) * rtb_Saturation1_d * (FMS_PARAM.YAW_RATE_LIM / 2.0F))
        + rtb_Integrator1_bx;

      /* Signum: '<S107>/Sign' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Divide_e = -1.0F;
      } else if (rtb_Saturation1_d > 0.0F) {
        rtb_Divide_e = 1.0F;
      } else {
        rtb_Divide_e = rtb_Saturation1_d;
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
      rtb_Divide_ox = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) + FMS_ConstB.d_j) *
        FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Divide_e +
        rtb_Integrator1_bx;

      /* Sum: '<S107>/Add4' */
      rtb_Saturation1_p5 = (rtb_Saturation1_d - rtb_Divide_ox) +
        rtb_Integrator1_bx;

      /* Sum: '<S107>/Add3' */
      rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_j;

      /* Sum: '<S107>/Subtract1' */
      rtb_Saturation1_d -= FMS_ConstB.d_j;

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
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S107>/Sign2' */

      /* Sum: '<S107>/Add5' incorporates:
       *  Gain: '<S107>/Gain2'
       *  Product: '<S107>/Multiply4'
       *  Sum: '<S107>/Subtract2'
       */
      rtb_Divide_ox += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
        rtb_Saturation1_p5;

      /* Sum: '<S107>/Add6' */
      rtb_Saturation_ga = rtb_Divide_ox + FMS_ConstB.d_j;

      /* Sum: '<S107>/Subtract3' */
      rtb_P_f_idx_0 = rtb_Divide_ox - FMS_ConstB.d_j;

      /* Product: '<S107>/Divide' */
      rtb_a_bx = rtb_Divide_ox / FMS_ConstB.d_j;

      /* Signum: '<S107>/Sign5' incorporates:
       *  Signum: '<S107>/Sign6'
       */
      if (rtb_Divide_ox < 0.0F) {
        rtb_u_b = -1.0F;

        /* Signum: '<S107>/Sign6' */
        rtb_Divide_lr_idx_2 = -1.0F;
      } else if (rtb_Divide_ox > 0.0F) {
        rtb_u_b = 1.0F;

        /* Signum: '<S107>/Sign6' */
        rtb_Divide_lr_idx_2 = 1.0F;
      } else {
        rtb_u_b = rtb_Divide_ox;

        /* Signum: '<S107>/Sign6' */
        rtb_Divide_lr_idx_2 = rtb_Divide_ox;
      }

      /* End of Signum: '<S107>/Sign5' */

      /* Product: '<S108>/Multiply1' incorporates:
       *  Constant: '<S108>/const1'
       *  DiscreteIntegrator: '<S105>/Integrator'
       */
      rtb_Divide_ox = FMS_DW.Integrator_DSTATE_l * 0.1F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S100>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.THROTTLE_DZ) {
        rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.THROTTLE_DZ;
      } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.THROTTLE_DZ) {
        rtb_Saturation1_d = 0.0F;
      } else {
        rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
          (-FMS_PARAM.THROTTLE_DZ);
      }

      /* End of DeadZone: '<S100>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S108>/Add' incorporates:
       *  DiscreteIntegrator: '<S105>/Integrator1'
       *  Gain: '<S100>/Gain'
       *  Gain: '<S52>/Gain1'
       *  Sum: '<S105>/Subtract'
       */
      rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_mb - 1.0F / (1.0F -
        FMS_PARAM.THROTTLE_DZ) * rtb_Saturation1_d * (-FMS_PARAM.VEL_Z_LIM /
        2.0F)) + rtb_Divide_ox;

      /* Signum: '<S108>/Sign' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Divide_e = -1.0F;
      } else if (rtb_Saturation1_d > 0.0F) {
        rtb_Divide_e = 1.0F;
      } else {
        rtb_Divide_e = rtb_Saturation1_d;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
        FMS_ConstB.d_m2) * FMS_ConstB.d_m2) - FMS_ConstB.d_m2) * 0.5F *
        rtb_Divide_e + rtb_Divide_ox;

      /* Sum: '<S108>/Add4' */
      rtb_Divide_lr_idx_3 = (rtb_Saturation1_d - rtb_Integrator1_bx) +
        rtb_Divide_ox;

      /* Sum: '<S108>/Add3' */
      rtb_Saturation1_p5 = rtb_Saturation1_d + FMS_ConstB.d_m2;

      /* Sum: '<S108>/Subtract1' */
      rtb_Saturation1_d -= FMS_ConstB.d_m2;

      /* Signum: '<S108>/Sign1' */
      if (rtb_Saturation1_p5 < 0.0F) {
        rtb_Saturation1_p5 = -1.0F;
      } else {
        if (rtb_Saturation1_p5 > 0.0F) {
          rtb_Saturation1_p5 = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign1' */

      /* Signum: '<S108>/Sign2' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign2' */

      /* Sum: '<S108>/Add5' incorporates:
       *  Gain: '<S108>/Gain2'
       *  Product: '<S108>/Multiply4'
       *  Sum: '<S108>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_Saturation1_p5 - rtb_Saturation1_d) * 0.5F *
        rtb_Divide_lr_idx_3;

      /* Sum: '<S108>/Add6' */
      rtb_Saturation1_p5 = rtb_Integrator1_bx + FMS_ConstB.d_m2;

      /* Sum: '<S108>/Subtract3' */
      rtb_Divide_lr_idx_3 = rtb_Integrator1_bx - FMS_ConstB.d_m2;

      /* Product: '<S108>/Divide' */
      rtb_Divide_ic = rtb_Integrator1_bx / FMS_ConstB.d_m2;

      /* Signum: '<S108>/Sign5' incorporates:
       *  Signum: '<S108>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Sign5_af = -1.0F;

        /* Signum: '<S108>/Sign6' */
        d = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Sign5_af = 1.0F;

        /* Signum: '<S108>/Sign6' */
        d = 1.0F;
      } else {
        rtb_Sign5_af = rtb_Integrator1_bx;

        /* Signum: '<S108>/Sign6' */
        d = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S108>/Sign5' */

      /* Product: '<S106>/Multiply1' incorporates:
       *  Constant: '<S106>/const1'
       *  DiscreteIntegrator: '<S103>/Integrator'
       */
      rtb_Divide_ox = FMS_DW.Integrator_DSTATE_oy * 0.1F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* DeadZone: '<S101>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S43>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
        rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
      } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
        rtb_Saturation1_d = 0.0F;
      } else {
        rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
      }

      /* End of DeadZone: '<S101>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Sum: '<S106>/Add' incorporates:
       *  DiscreteIntegrator: '<S103>/Integrator1'
       *  Gain: '<S101>/Gain'
       *  Gain: '<S52>/Gain6'
       *  Sum: '<S103>/Subtract'
       */
      rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
        FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * (FMS_PARAM.VEL_XY_LIM / 2.0F))
        + rtb_Divide_ox;

      /* Signum: '<S106>/Sign' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Divide_e = -1.0F;
      } else if (rtb_Saturation1_d > 0.0F) {
        rtb_Divide_e = 1.0F;
      } else {
        rtb_Divide_e = rtb_Saturation1_d;
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
      rtb_Integrator1_bx = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
        FMS_ConstB.d_oj) * FMS_ConstB.d_oj) - FMS_ConstB.d_oj) * 0.5F *
        rtb_Divide_e + rtb_Divide_ox;

      /* Sum: '<S106>/Add4' */
      rtb_Divide_e = (rtb_Saturation1_d - rtb_Integrator1_bx) + rtb_Divide_ox;

      /* Sum: '<S106>/Add3' */
      rtb_Divide_ox = rtb_Saturation1_d + FMS_ConstB.d_oj;

      /* Sum: '<S106>/Subtract1' */
      rtb_Saturation1_d -= FMS_ConstB.d_oj;

      /* Signum: '<S106>/Sign1' */
      if (rtb_Divide_ox < 0.0F) {
        rtb_Divide_ox = -1.0F;
      } else {
        if (rtb_Divide_ox > 0.0F) {
          rtb_Divide_ox = 1.0F;
        }
      }

      /* End of Signum: '<S106>/Sign1' */

      /* Signum: '<S106>/Sign2' */
      if (rtb_Saturation1_d < 0.0F) {
        rtb_Saturation1_d = -1.0F;
      } else {
        if (rtb_Saturation1_d > 0.0F) {
          rtb_Saturation1_d = 1.0F;
        }
      }

      /* End of Signum: '<S106>/Sign2' */

      /* Sum: '<S106>/Add5' incorporates:
       *  Gain: '<S106>/Gain2'
       *  Product: '<S106>/Multiply4'
       *  Sum: '<S106>/Subtract2'
       */
      rtb_Integrator1_bx += (rtb_Divide_ox - rtb_Saturation1_d) * 0.5F *
        rtb_Divide_e;

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
      if (rtb_P_f_idx_0 < 0.0F) {
        rtb_P_f_idx_0 = -1.0F;
      } else {
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_P_f_idx_0 = 1.0F;
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
      FMS_DW.Integrator_DSTATE_e += ((rtb_a_bx - rtb_u_b) * FMS_ConstB.Gain4_oc *
        ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) - rtb_Divide_lr_idx_2 *
        15.707963F) * 0.004F;

      /* Signum: '<S108>/Sign3' */
      if (rtb_Saturation1_p5 < 0.0F) {
        rtb_Saturation1_p5 = -1.0F;
      } else {
        if (rtb_Saturation1_p5 > 0.0F) {
          rtb_Saturation1_p5 = 1.0F;
        }
      }

      /* End of Signum: '<S108>/Sign3' */

      /* Signum: '<S108>/Sign4' */
      if (rtb_Divide_lr_idx_3 < 0.0F) {
        rtb_Divide_lr_idx_3 = -1.0F;
      } else {
        if (rtb_Divide_lr_idx_3 > 0.0F) {
          rtb_Divide_lr_idx_3 = 1.0F;
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
      FMS_DW.Integrator_DSTATE_l += ((rtb_Divide_ic - rtb_Sign5_af) *
        FMS_ConstB.Gain4_ht * ((rtb_Saturation1_p5 - rtb_Divide_lr_idx_3) * 0.5F)
        - d * 39.224F) * 0.004F;

      /* Sum: '<S106>/Subtract3' */
      rtb_Saturation_ga = rtb_Integrator1_bx - FMS_ConstB.d_oj;

      /* Sum: '<S106>/Add6' */
      rtb_P_f_idx_0 = rtb_Integrator1_bx + FMS_ConstB.d_oj;

      /* Signum: '<S106>/Sign5' incorporates:
       *  Signum: '<S106>/Sign6'
       */
      if (rtb_Integrator1_bx < 0.0F) {
        rtb_Divide_lr_idx_2 = -1.0F;

        /* Signum: '<S106>/Sign6' */
        d = -1.0F;
      } else if (rtb_Integrator1_bx > 0.0F) {
        rtb_Divide_lr_idx_2 = 1.0F;

        /* Signum: '<S106>/Sign6' */
        d = 1.0F;
      } else {
        rtb_Divide_lr_idx_2 = rtb_Integrator1_bx;

        /* Signum: '<S106>/Sign6' */
        d = rtb_Integrator1_bx;
      }

      /* End of Signum: '<S106>/Sign5' */

      /* Signum: '<S106>/Sign3' */
      if (rtb_P_f_idx_0 < 0.0F) {
        rtb_P_f_idx_0 = -1.0F;
      } else {
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_P_f_idx_0 = 1.0F;
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
        rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_i3 * ((rtb_P_f_idx_0 -
        rtb_Saturation_ga) * 0.5F) - d * 39.224F) * 0.004F;

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
          /* Disable for SwitchCase: '<S328>/Switch Case' */
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
          /* Disable for SwitchCase: '<S326>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S437>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S488>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S478>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S437>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S325>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S424>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S340>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S358>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S374>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S399>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S386>/Switch Case' */
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
         *  ActionPort: '<S328>/Action Port'
         */
        /* SwitchCase: '<S328>/Switch Case' incorporates:
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
            /* InitializeConditions for IfAction SubSystem: '<S328>/Takeoff' incorporates:
             *  ActionPort: '<S635>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S328>/Switch Case' incorporates:
             *  Delay: '<S778>/cur_waypoint'
             *  DiscreteIntegrator: '<S774>/Integrator'
             *  DiscreteIntegrator: '<S774>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S328>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S328>/Takeoff' incorporates:
           *  ActionPort: '<S635>/Action Port'
           */
          /* Delay: '<S778>/cur_waypoint' incorporates:
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
          /* Product: '<S778>/Divide' incorporates:
           *  Delay: '<S778>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S778>/Sum1'
           *  Sum: '<S778>/Sum2'
           */
          rtb_Divide_lr_idx_2 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S778>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S778>/Saturation' */

          /* Trigonometry: '<S779>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S779>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

          /* SignalConversion: '<S779>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S779>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S779>/Gain' incorporates:
           *  Gain: '<S777>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S779>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S779>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S779>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S779>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S779>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Saturate: '<S771>/Saturation1' */
          rtb_Saturation_ga = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Saturation1_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S771>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S778>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S778>/Multiply'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S771>/Sum'
           *  Sum: '<S778>/Sum3'
           *  Sum: '<S778>/Sum4'
           */
          rtb_Saturation1_p5 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_lr_idx_2 +
                                FMS_DW.cur_waypoint_DSTATE[0]) -
            FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_lr_idx_2 +
                                FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S771>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] *
              rtb_Saturation1_p5;
          }

          /* Saturate: '<S771>/Saturation1' incorporates:
           *  Gain: '<S771>/Gain2'
           *  Product: '<S771>/Multiply'
           */
          rtb_a_bx = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

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

          /* Saturate: '<S771>/Saturation1' */
          if (rtb_a_bx > rtb_Saturation_ga) {
            /* BusAssignment: '<S635>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_ga;
          } else if (rtb_a_bx < rtb_Saturation1_d) {
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
            FMS_Y.FMS_Out.u_cmd = rtb_a_bx;
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
           *  DiscreteIntegrator: '<S774>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S775>/Multiply1' incorporates:
           *  Constant: '<S775>/const1'
           *  DiscreteIntegrator: '<S774>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S770>/Switch' incorporates:
           *  Abs: '<S770>/Abs'
           *  Abs: '<S770>/Abs1'
           *  Constant: '<S770>/Takeoff_Speed'
           *  Constant: '<S772>/Constant'
           *  Constant: '<S773>/Constant'
           *  Gain: '<S770>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S770>/Logical Operator'
           *  RelationalOperator: '<S772>/Compare'
           *  RelationalOperator: '<S773>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S770>/Sum'
           *  Sum: '<S770>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_Saturation1_d = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_Saturation1_d = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S770>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S775>/Add' incorporates:
           *  DiscreteIntegrator: '<S774>/Integrator1'
           *  Sum: '<S774>/Subtract'
           */
          rtb_Saturation1_p5 = (FMS_DW.Integrator1_DSTATE_f - rtb_Saturation1_d)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S775>/Sign' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_Saturation1_p5;
          }

          /* End of Signum: '<S775>/Sign' */

          /* Sum: '<S775>/Add2' incorporates:
           *  Abs: '<S775>/Abs'
           *  Gain: '<S775>/Gain'
           *  Gain: '<S775>/Gain1'
           *  Product: '<S775>/Multiply2'
           *  Product: '<S775>/Multiply3'
           *  Sqrt: '<S775>/Sqrt'
           *  Sum: '<S775>/Add1'
           *  Sum: '<S775>/Subtract'
           */
          rtb_Saturation1_d = (sqrtf((8.0F * fabsf(rtb_Saturation1_p5) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Saturation_ga + rtb_Divide_lr_idx_2;

          /* Sum: '<S775>/Add4' */
          rtb_P_f_idx_0 = (rtb_Saturation1_p5 - rtb_Saturation1_d) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S775>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_b;

          /* Sum: '<S775>/Subtract1' */
          rtb_Saturation1_p5 -= FMS_ConstB.d_b;

          /* Signum: '<S775>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S775>/Sign1' */

          /* Signum: '<S775>/Sign2' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S775>/Sign2' */

          /* Sum: '<S775>/Add5' incorporates:
           *  Gain: '<S775>/Gain2'
           *  Product: '<S775>/Multiply4'
           *  Sum: '<S775>/Subtract2'
           */
          rtb_Saturation1_d += (rtb_Saturation_ga - rtb_Saturation1_p5) * 0.5F *
            rtb_P_f_idx_0;

          /* Update for Delay: '<S778>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S774>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S774>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S775>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_d - FMS_ConstB.d_b;

          /* Sum: '<S775>/Add6' */
          rtb_P_f_idx_0 = rtb_Saturation1_d + FMS_ConstB.d_b;

          /* Signum: '<S775>/Sign5' incorporates:
           *  Signum: '<S775>/Sign6'
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S775>/Sign6' */
            d = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S775>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation1_d;

            /* Signum: '<S775>/Sign6' */
            d = rtb_Saturation1_d;
          }

          /* End of Signum: '<S775>/Sign5' */

          /* Signum: '<S775>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S775>/Sign3' */

          /* Signum: '<S775>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S775>/Sign4' */

          /* Update for DiscreteIntegrator: '<S774>/Integrator' incorporates:
           *  Constant: '<S775>/const'
           *  Gain: '<S775>/Gain3'
           *  Product: '<S775>/Divide'
           *  Product: '<S775>/Multiply5'
           *  Product: '<S775>/Multiply6'
           *  Sum: '<S775>/Subtract4'
           *  Sum: '<S775>/Subtract5'
           *  Sum: '<S775>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation1_d / FMS_ConstB.d_b -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_i * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S328>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S328>/Land' incorporates:
             *  ActionPort: '<S633>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S328>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S688>/Integrator'
             *  DiscreteIntegrator: '<S688>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S328>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S328>/Land' incorporates:
           *  ActionPort: '<S633>/Action Port'
           */
          /* Trigonometry: '<S693>/Trigonometric Function1' */
          rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

          /* Trigonometry: '<S693>/Trigonometric Function' */
          rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

          /* SignalConversion: '<S693>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S693>/Constant3'
           */
          rtb_VectorConcatenate_or[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S693>/Gain' incorporates:
           *  Gain: '<S692>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Trigonometry: '<S693>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S693>/Trigonometric Function3' */
          rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

          /* SignalConversion: '<S693>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S693>/Constant4'
           */
          rtb_VectorConcatenate_or[5] = 0.0F;

          /* SignalConversion: '<S693>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S686>/Saturation1' */
          rtb_Divide_lr_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S690>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S690>/Sum'
           */
          rtb_Saturation1_p5 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_bx = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S690>/Multiply' incorporates:
           *  SignalConversion: '<S690>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S690>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3]
              * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] *
              rtb_Saturation1_p5;
          }

          /* End of Product: '<S690>/Multiply' */

          /* Saturate: '<S686>/Saturation1' incorporates:
           *  Gain: '<S690>/Gain2'
           */
          rtb_a_bx = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
          rtb_Saturation1_p5 = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

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
          if (rtb_a_bx > rtb_Divide_lr_idx_2) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_lr_idx_2;
          } else if (rtb_a_bx < d) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = d;
          } else {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_a_bx;
          }

          if (rtb_Saturation1_p5 > rtb_Divide_lr_idx_2) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_2;
          } else if (rtb_Saturation1_p5 < d) {
            /* BusAssignment: '<S633>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = d;
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
            rtb_Saturation1_d = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_Saturation1_d = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S685>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S689>/Add' incorporates:
           *  DiscreteIntegrator: '<S688>/Integrator1'
           *  Sum: '<S688>/Subtract'
           */
          rtb_Saturation1_p5 = (FMS_DW.Integrator1_DSTATE_g - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S689>/Sign' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            rtb_Saturation1_d = rtb_Saturation1_p5;
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
          rtb_Saturation1_d = (sqrtf((8.0F * fabsf(rtb_Saturation1_p5) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Saturation1_d + rtb_Saturation_ga;

          /* Sum: '<S689>/Add4' */
          rtb_P_f_idx_0 = (rtb_Saturation1_p5 - rtb_Saturation1_d) +
            rtb_Saturation_ga;

          /* Sum: '<S689>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_om;

          /* Sum: '<S689>/Subtract1' */
          rtb_Saturation1_p5 -= FMS_ConstB.d_om;

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
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S689>/Sign2' */

          /* Sum: '<S689>/Add5' incorporates:
           *  Gain: '<S689>/Gain2'
           *  Product: '<S689>/Multiply4'
           *  Sum: '<S689>/Subtract2'
           */
          rtb_Saturation1_d += (rtb_Saturation_ga - rtb_Saturation1_p5) * 0.5F *
            rtb_P_f_idx_0;

          /* Update for DiscreteIntegrator: '<S688>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S688>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S689>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_d - FMS_ConstB.d_om;

          /* Sum: '<S689>/Add6' */
          rtb_P_f_idx_0 = rtb_Saturation1_d + FMS_ConstB.d_om;

          /* Signum: '<S689>/Sign5' incorporates:
           *  Signum: '<S689>/Sign6'
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S689>/Sign6' */
            d = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S689>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation1_d;

            /* Signum: '<S689>/Sign6' */
            d = rtb_Saturation1_d;
          }

          /* End of Signum: '<S689>/Sign5' */

          /* Signum: '<S689>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Saturation1_d / FMS_ConstB.d_om -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_p * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S328>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S328>/Return' incorporates:
             *  ActionPort: '<S634>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S328>/Switch Case' incorporates:
             *  Delay: '<S697>/Delay'
             *  Delay: '<S718>/Delay'
             *  Delay: '<S718>/Delay1'
             *  DiscreteIntegrator: '<S700>/Integrator'
             *  DiscreteIntegrator: '<S700>/Integrator1'
             *  DiscreteIntegrator: '<S714>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S719>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S762>/Discrete-Time Integrator'
             */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Delay1_DSTATE_a = false;
            FMS_DW.icLoad_c = 1U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_n = 0.0F;
            FMS_DW.DiscreteTimeIntegrator_PrevRe_j = 0;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S328>/Return' */

            /* SystemReset for IfAction SubSystem: '<S328>/Return' incorporates:
             *  ActionPort: '<S634>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S328>/Switch Case' incorporates:
             *  Chart: '<S724>/Motion Status'
             *  Chart: '<S734>/Motion State'
             */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S328>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S328>/Return' incorporates:
           *  ActionPort: '<S634>/Action Port'
           */
          /* RelationalOperator: '<S713>/Compare' incorporates:
           *  Constant: '<S769>/Constant'
           *  DiscreteIntegrator: '<S719>/Discrete-Time Integrator'
           *  RelationalOperator: '<S769>/Compare'
           */
          rtb_Compare_o3 = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* Logic: '<S718>/Logical Operator' incorporates:
           *  Delay: '<S718>/Delay1'
           */
          rtb_LogicalOperator_e = (rtb_Compare_o3 || FMS_DW.Delay1_DSTATE_a);

          /* Delay: '<S718>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if ((((FMS_PrevZCX.Delay_Reset_ZCE_h == POS_ZCSIG) != (int32_T)
                rtb_LogicalOperator_e) && (FMS_PrevZCX.Delay_Reset_ZCE_h !=
                UNINITIALIZED_ZCSIG)) || rtb_LogicalOperator_e) {
            FMS_DW.icLoad_c = 1U;
          }

          FMS_PrevZCX.Delay_Reset_ZCE_h = rtb_LogicalOperator_e;
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_g[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_g[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S718>/Sum' incorporates:
           *  Delay: '<S718>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_g[0];
          rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_g[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S714>/Acceleration_Speed' */
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

          /* DiscreteIntegrator: '<S762>/Discrete-Time Integrator' */
          if (rtb_LogicalOperator_e || (FMS_DW.DiscreteTimeIntegrator_PrevRe_j
               != 0)) {
            FMS_DW.l1_heading_n = 0.0F;
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
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
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
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
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
           */
          if (rtb_Compare_o3) {
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
            /* Sum: '<S714>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];
            d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S720>/Sqrt' incorporates:
             *  Math: '<S720>/Square'
             *  Sum: '<S714>/Sum'
             *  Sum: '<S720>/Sum of Elements'
             */
            rtb_Saturation1_d = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d + d *
              d);

            /* SignalConversion: '<S768>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_f[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_f[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_f[2];

            /* SignalConversion: '<S768>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S768>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S767>/Gain' incorporates:
             *  DiscreteIntegrator: '<S762>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S762>/Add'
             */
            rtb_P_f_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S768>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S768>/Trigonometric Function1'
             */
            rtb_Saturation_ga = arm_cos_f32(rtb_P_f_idx_0);
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Trigonometry: '<S768>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S768>/Trigonometric Function'
             */
            rtb_P_f_idx_0 = arm_sin_f32(rtb_P_f_idx_0);

            /* Gain: '<S768>/Gain' incorporates:
             *  Trigonometry: '<S768>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -rtb_P_f_idx_0;

            /* SignalConversion: '<S768>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S768>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S768>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

            /* Trigonometry: '<S768>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* Switch: '<S714>/Switch' incorporates:
             *  Constant: '<S714>/vel'
             */
            if (rtb_Saturation1_d > FMS_PARAM.L1) {
              rtb_P_f_idx_0 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S714>/Gain' */
              rtb_P_f_idx_0 = 0.5F * rtb_Saturation1_d;

              /* Saturate: '<S714>/Saturation' */
              if (rtb_P_f_idx_0 > FMS_PARAM.CRUISE_SPEED) {
                rtb_P_f_idx_0 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_P_f_idx_0 < 0.5F) {
                  rtb_P_f_idx_0 = 0.5F;
                }
              }

              /* End of Saturate: '<S714>/Saturation' */
            }

            /* End of Switch: '<S714>/Switch' */

            /* Switch: '<S714>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S714>/Acceleration_Speed'
             *  Sum: '<S714>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S714>/Switch1' */

            /* Sum: '<S763>/Sum of Elements' incorporates:
             *  Math: '<S763>/Math Function'
             *  SignalConversion: '<S763>/TmpSignal ConversionAtMath FunctionInport1'
             */
            rtb_Saturation1_d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 +
              rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

            /* Math: '<S763>/Math Function1' incorporates:
             *  Sum: '<S763>/Sum of Elements'
             *
             * About '<S763>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
            } else {
              rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
            }

            /* End of Math: '<S763>/Math Function1' */

            /* Switch: '<S763>/Switch' incorporates:
             *  Constant: '<S763>/Constant'
             *  Product: '<S763>/Product'
             */
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Divide_p3p[0] = rtb_Divide_lr_idx_2;
              rtb_Divide_p3p[1] = rtb_Divide_lr_idx_3;
              rtb_Divide_p3p[3] = rtb_Saturation_ga;
            } else {
              rtb_Divide_p3p[0] = 0.0F;
              rtb_Divide_p3p[1] = 0.0F;
              rtb_Divide_p3p[3] = 1.0F;
            }

            /* End of Switch: '<S763>/Switch' */

            /* Product: '<S760>/Multiply2' incorporates:
             *  Product: '<S763>/Divide'
             */
            rtb_Saturation_ga = rtb_Divide_p3p[0] / rtb_Divide_p3p[3] *
              rtb_P_f_idx_0;
            rtb_Saturation1_d = rtb_Divide_p3p[1] / rtb_Divide_p3p[3] *
              rtb_P_f_idx_0;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_c2[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Saturation1_d + rtb_VectorConcatenate_or[rtb_n] *
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
          d = rt_remf(FMS_DW.Integrator1_DSTATE_b - FMS_U.INS_Out.psi,
                      6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S704>/Switch' incorporates:
           *  Abs: '<S704>/Abs'
           *  Constant: '<S704>/Constant'
           *  Constant: '<S705>/Constant'
           *  Product: '<S704>/Multiply'
           *  RelationalOperator: '<S705>/Compare'
           *  Sum: '<S704>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S704>/Sign' */
            if (d < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (d > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = d;
            }

            /* End of Signum: '<S704>/Sign' */
            d -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S704>/Switch' */

          /* Gain: '<S699>/Gain2' */
          d *= FMS_PARAM.YAW_P;

          /* Saturate: '<S699>/Saturation' */
          if (d > FMS_PARAM.YAW_RATE_LIM) {
            d = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (d < -FMS_PARAM.YAW_RATE_LIM) {
              d = -FMS_PARAM.YAW_RATE_LIM;
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
          FMS_Y.FMS_Out.psi_rate_cmd = d;

          /* Sum: '<S765>/Sum of Elements' incorporates:
           *  Math: '<S765>/Math Function'
           *  SignalConversion: '<S765>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 +
            rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

          /* Math: '<S765>/Math Function1' incorporates:
           *  Sum: '<S765>/Sum of Elements'
           *
           * About '<S765>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            d = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            d = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S765>/Math Function1' */

          /* Switch: '<S765>/Switch' incorporates:
           *  Constant: '<S765>/Constant'
           *  Product: '<S765>/Product'
           */
          if (d > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_lr_idx_3;
            rtb_Switch_c2[1] = rtb_Divide_lr_idx_2;
            rtb_Switch_c2[2] = d;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S765>/Switch' */

          /* Math: '<S754>/Math Function1'
           *
           * About '<S754>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            d = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            d = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S754>/Math Function1' */

          /* Switch: '<S754>/Switch' incorporates:
           *  Constant: '<S754>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S754>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = FMS_U.INS_Out.vn;
            rtb_Saturation_ga = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Integrator1_bx = d;
          } else {
            rtb_P_f_idx_0 = 0.0F;
            rtb_Saturation_ga = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S754>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S634>/Sum' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_ox = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_e = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S711>/Sum of Elements' incorporates:
           *  Math: '<S711>/Math Function'
           *  Sum: '<S634>/Sum'
           */
          rtb_Saturation1_d = rtb_Divide_e * rtb_Divide_e + rtb_Divide_ox *
            rtb_Divide_ox;

          /* Math: '<S711>/Math Function1' incorporates:
           *  Sum: '<S711>/Sum of Elements'
           *
           * About '<S711>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            d = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            d = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S711>/Math Function1' */

          /* Switch: '<S711>/Switch' incorporates:
           *  Constant: '<S711>/Constant'
           *  Product: '<S711>/Product'
           */
          if (d > 0.0F) {
            rtb_u_b = d;
          } else {
            rtb_Divide_e = 0.0F;
            rtb_Divide_ox = 0.0F;
            rtb_u_b = 1.0F;
          }

          /* End of Switch: '<S711>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S718>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_ic = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_P_ap[0] = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Sign5_i = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
          rtb_P_ap[1] = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S766>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S718>/Sum1'
           */
          rtb_Divide_c14[0] = rtb_Sign5_i;
          rtb_Divide_c14[1] = rtb_Divide_ic;

          /* Math: '<S766>/Math Function' incorporates:
           *  Sum: '<S718>/Sum1'
           */
          rtb_Square_ds[0] = rtb_Sign5_i * rtb_Sign5_i;
          rtb_Square_ds[1] = rtb_Divide_ic * rtb_Divide_ic;

          /* Sum: '<S766>/Sum of Elements' */
          rtb_Saturation1_d = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S766>/Math Function1' incorporates:
           *  Sum: '<S766>/Sum of Elements'
           *
           * About '<S766>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            d = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            d = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S766>/Math Function1' */

          /* Switch: '<S766>/Switch' incorporates:
           *  Constant: '<S766>/Constant'
           *  Product: '<S766>/Product'
           */
          if (d > 0.0F) {
            rtb_Sign5_af = d;
          } else {
            rtb_Sign5_i = 0.0F;
            rtb_Divide_ic = 0.0F;
            rtb_Sign5_af = 1.0F;
          }

          /* End of Switch: '<S766>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S716>/NearbyRefWP' incorporates:
           *  Constant: '<S634>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_c14,
                          &rtb_Divide_lr_idx_3);

          /* MATLAB Function: '<S716>/SearchL1RefWP' incorporates:
           *  Constant: '<S634>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_ap, &rtb_Saturation1_d);

          /* MATLAB Function: '<S716>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S716>/Switch1' incorporates:
           *  Constant: '<S747>/Constant'
           *  RelationalOperator: '<S747>/Compare'
           */
          if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_c14[0];
            rtb_P_ap[1] = rtb_Divide_c14[1];
          } else {
            /* RelationalOperator: '<S746>/Compare' incorporates:
             *  Constant: '<S746>/Constant'
             */
            rtb_Compare_aij = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S716>/Switch' */
            if (!rtb_Compare_aij) {
              rtb_P_ap[0] = rtb_Square_ds[0];
              rtb_P_ap[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S716>/Switch' */
          }

          /* End of Switch: '<S716>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S717>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_a_bx;
          rtb_Subtract_hb[0] = rtb_a_bx * rtb_a_bx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S717>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S755>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S755>/Sum of Elements' incorporates:
           *  Math: '<S755>/Math Function'
           *  Sum: '<S753>/Sum of Elements'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[0] + rtb_a_bx * rtb_a_bx;

          /* Math: '<S755>/Math Function1' incorporates:
           *  Sum: '<S755>/Sum of Elements'
           *
           * About '<S755>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            d = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            d = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S755>/Math Function1' */

          /* Switch: '<S755>/Switch' incorporates:
           *  Constant: '<S755>/Constant'
           *  Product: '<S755>/Product'
           */
          if (d > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_P_ap[0];
            rtb_MatrixConcatenate3[1] = rtb_a_bx;
            rtb_MatrixConcatenate3[2] = d;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S755>/Switch' */

          /* Product: '<S754>/Divide' */
          rtb_Divide_c14[0] = rtb_P_f_idx_0 / rtb_Integrator1_bx;
          rtb_Divide_c14[1] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Sum: '<S757>/Sum of Elements' incorporates:
           *  Math: '<S757>/Math Function'
           *  SignalConversion: '<S757>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_c14[1] * rtb_Divide_c14[1] +
            rtb_Divide_c14[0] * rtb_Divide_c14[0];

          /* Math: '<S757>/Math Function1' incorporates:
           *  Sum: '<S757>/Sum of Elements'
           *
           * About '<S757>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            d = -sqrtf(fabsf(rtb_Divide_lr_idx_2));
          } else {
            d = sqrtf(rtb_Divide_lr_idx_2);
          }

          /* End of Math: '<S757>/Math Function1' */

          /* Switch: '<S757>/Switch' incorporates:
           *  Constant: '<S757>/Constant'
           *  Product: '<S757>/Product'
           */
          if (d > 0.0F) {
            rtb_P_f_idx_0 = rtb_Divide_c14[1];
            rtb_Saturation_ga = rtb_Divide_c14[0];
            rtb_Integrator1_bx = d;
          } else {
            rtb_P_f_idx_0 = 0.0F;
            rtb_Saturation_ga = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S757>/Switch' */

          /* Product: '<S755>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S758>/Sum of Elements' incorporates:
           *  Math: '<S758>/Math Function'
           *  SignalConversion: '<S758>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_c14[1] * rtb_Divide_c14[1] +
            rtb_Divide_c14[0] * rtb_Divide_c14[0];

          /* Math: '<S758>/Math Function1' incorporates:
           *  Sum: '<S758>/Sum of Elements'
           *
           * About '<S758>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            d = -sqrtf(fabsf(rtb_Divide_lr_idx_2));
          } else {
            d = sqrtf(rtb_Divide_lr_idx_2);
          }

          /* End of Math: '<S758>/Math Function1' */

          /* Switch: '<S758>/Switch' incorporates:
           *  Constant: '<S758>/Constant'
           *  Product: '<S758>/Product'
           */
          if (d > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Divide_c14[1];
            rtb_MatrixConcatenate3[1] = rtb_Divide_c14[0];
            rtb_MatrixConcatenate3[2] = d;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S758>/Switch' */

          /* Product: '<S758>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S757>/Divide' */
          rtb_P_ap[0] = rtb_P_f_idx_0 / rtb_Integrator1_bx;

          /* Product: '<S766>/Divide' */
          rtb_Square_ds[0] = rtb_Sign5_i / rtb_Sign5_af;

          /* Product: '<S711>/Divide' */
          rtb_P_f_idx_0 = rtb_Divide_e / rtb_u_b;

          /* Product: '<S765>/Divide' */
          rtb_a_bx = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S758>/Divide' */
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S757>/Divide' */
          rtb_P_ap[1] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S766>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_ic / rtb_Sign5_af;

          /* Product: '<S711>/Divide' */
          rtb_Saturation_ga = rtb_Divide_ox / rtb_u_b;

          /* Product: '<S765>/Divide' */
          rtb_Integrator1_bx = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S764>/Subtract' incorporates:
           *  Product: '<S764>/Multiply'
           *  Product: '<S764>/Multiply1'
           */
          d = rtb_Square_ds[0] * rtb_Integrator1_bx - rtb_Square_ds[1] *
            rtb_a_bx;

          /* Signum: '<S761>/Sign1' */
          if (d < 0.0F) {
            d = -1.0F;
          } else {
            if (d > 0.0F) {
              d = 1.0F;
            }
          }

          /* End of Signum: '<S761>/Sign1' */

          /* Switch: '<S761>/Switch2' incorporates:
           *  Constant: '<S761>/Constant4'
           */
          if (d == 0.0F) {
            d = 1.0F;
          }

          /* End of Switch: '<S761>/Switch2' */

          /* DotProduct: '<S761>/Dot Product' */
          rtb_Integrator1_bx = rtb_a_bx * rtb_Square_ds[0] + rtb_Integrator1_bx *
            rtb_Square_ds[1];

          /* Trigonometry: '<S761>/Acos' incorporates:
           *  DotProduct: '<S761>/Dot Product'
           */
          if (rtb_Integrator1_bx > 1.0F) {
            rtb_Integrator1_bx = 1.0F;
          } else {
            if (rtb_Integrator1_bx < -1.0F) {
              rtb_Integrator1_bx = -1.0F;
            }
          }

          /* Product: '<S761>/Multiply' incorporates:
           *  Trigonometry: '<S761>/Acos'
           */
          d *= acosf(rtb_Integrator1_bx);

          /* Abs: '<S718>/Abs' */
          d = fabsf(d);

          /* RelationalOperator: '<S759>/Compare' incorporates:
           *  Constant: '<S759>/Constant'
           *  Delay: '<S718>/Delay1'
           */
          FMS_DW.Delay1_DSTATE_a = (d > 1.57079637F);

          /* Sum: '<S756>/Subtract' incorporates:
           *  Product: '<S756>/Multiply'
           *  Product: '<S756>/Multiply1'
           */
          rtb_Integrator1_bx = rtb_Divide_c14[0] * rtb_P_ap[1] - rtb_Divide_c14
            [1] * rtb_P_ap[0];

          /* Signum: '<S751>/Sign1' */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Integrator1_bx = -1.0F;
          } else {
            if (rtb_Integrator1_bx > 0.0F) {
              rtb_Integrator1_bx = 1.0F;
            }
          }

          /* End of Signum: '<S751>/Sign1' */

          /* Switch: '<S751>/Switch2' incorporates:
           *  Constant: '<S751>/Constant4'
           */
          if (rtb_Integrator1_bx == 0.0F) {
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S751>/Switch2' */

          /* DotProduct: '<S751>/Dot Product' */
          rtb_a_bx = rtb_P_ap[0] * rtb_Divide_c14[0] + rtb_P_ap[1] *
            rtb_Divide_c14[1];

          /* Trigonometry: '<S751>/Acos' incorporates:
           *  DotProduct: '<S751>/Dot Product'
           */
          if (rtb_a_bx > 1.0F) {
            rtb_a_bx = 1.0F;
          } else {
            if (rtb_a_bx < -1.0F) {
              rtb_a_bx = -1.0F;
            }
          }

          /* Product: '<S751>/Multiply' incorporates:
           *  Trigonometry: '<S751>/Acos'
           */
          rtb_Integrator1_bx *= acosf(rtb_a_bx);

          /* Saturate: '<S717>/Saturation' */
          if (rtb_Integrator1_bx > 1.57079637F) {
            rtb_Integrator1_bx = 1.57079637F;
          } else {
            if (rtb_Integrator1_bx < -1.57079637F) {
              rtb_Integrator1_bx = -1.57079637F;
            }
          }

          /* End of Saturate: '<S717>/Saturation' */

          /* Trigonometry: '<S717>/Sin' */
          rtb_Divide_ox = arm_sin_f32(rtb_Integrator1_bx);

          /* Sum: '<S709>/Subtract' incorporates:
           *  Product: '<S709>/Multiply'
           *  Product: '<S709>/Multiply1'
           */
          rtb_Integrator1_bx = rtb_P_f_idx_0 * FMS_ConstB.Divide_m[1] -
            rtb_Saturation_ga * FMS_ConstB.Divide_m[0];

          /* Signum: '<S698>/Sign1' */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Integrator1_bx = -1.0F;
          } else {
            if (rtb_Integrator1_bx > 0.0F) {
              rtb_Integrator1_bx = 1.0F;
            }
          }

          /* End of Signum: '<S698>/Sign1' */

          /* Switch: '<S698>/Switch2' incorporates:
           *  Constant: '<S698>/Constant4'
           */
          if (rtb_Integrator1_bx == 0.0F) {
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S698>/Switch2' */

          /* DotProduct: '<S698>/Dot Product' */
          rtb_a_bx = FMS_ConstB.Divide_m[0] * rtb_P_f_idx_0 +
            FMS_ConstB.Divide_m[1] * rtb_Saturation_ga;

          /* Trigonometry: '<S698>/Acos' incorporates:
           *  DotProduct: '<S698>/Dot Product'
           */
          if (rtb_a_bx > 1.0F) {
            rtb_a_bx = 1.0F;
          } else {
            if (rtb_a_bx < -1.0F) {
              rtb_a_bx = -1.0F;
            }
          }

          /* Product: '<S698>/Multiply' incorporates:
           *  Trigonometry: '<S698>/Acos'
           */
          rtb_Integrator1_bx *= acosf(rtb_a_bx);

          /* Math: '<S701>/Rem' incorporates:
           *  Constant: '<S701>/Constant1'
           *  Delay: '<S697>/Delay'
           *  Sum: '<S697>/Sum2'
           */
          d = rt_remf(rtb_Integrator1_bx - FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S701>/Switch' incorporates:
           *  Abs: '<S701>/Abs'
           *  Constant: '<S701>/Constant'
           *  Constant: '<S707>/Constant'
           *  Product: '<S701>/Multiply'
           *  RelationalOperator: '<S707>/Compare'
           *  Sum: '<S701>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S701>/Sign' */
            if (d < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (d > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = d;
            }

            /* End of Signum: '<S701>/Sign' */
            d -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S701>/Switch' */

          /* Sum: '<S697>/Sum' incorporates:
           *  Delay: '<S697>/Delay'
           */
          rtb_Saturation_ga = d + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S706>/Multiply1' incorporates:
           *  Constant: '<S706>/const1'
           *  DiscreteIntegrator: '<S700>/Integrator'
           */
          d = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S706>/Add' incorporates:
           *  DiscreteIntegrator: '<S700>/Integrator1'
           *  Sum: '<S700>/Subtract'
           */
          rtb_P_f_idx_0 = (FMS_DW.Integrator1_DSTATE_b - rtb_Saturation_ga) + d;

          /* Signum: '<S706>/Sign' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_P_f_idx_0;
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
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_P_f_idx_0) +
            FMS_ConstB.d_n) * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Saturation_ga + d;

          /* Sum: '<S706>/Add4' */
          rtb_Divide_lr_idx_2 = (rtb_P_f_idx_0 - rtb_Divide_lr_idx_3) + d;

          /* Sum: '<S706>/Add3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S706>/Subtract1' */
          rtb_P_f_idx_0 -= FMS_ConstB.d_n;

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
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S706>/Sign2' */

          /* Sum: '<S706>/Add5' incorporates:
           *  Gain: '<S706>/Gain2'
           *  Product: '<S706>/Multiply4'
           *  Sum: '<S706>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F *
            rtb_Divide_lr_idx_2;

          /* Sum: '<S706>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d_n;

          /* Sum: '<S706>/Subtract3' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_n;

          /* Product: '<S706>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_n;

          /* Signum: '<S706>/Sign5' incorporates:
           *  Signum: '<S706>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_u_b = -1.0F;

            /* Signum: '<S706>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_u_b = 1.0F;

            /* Signum: '<S706>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_u_b = rtb_Divide_lr_idx_3;

            /* Signum: '<S706>/Sign6' */
            rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S706>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S697>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Integrator1_bx -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S702>/Rem' incorporates:
           *  Constant: '<S702>/Constant1'
           */
          rtb_Divide_lr_idx_3 = rt_remf(rtb_Integrator1_bx, 6.28318548F);

          /* Switch: '<S702>/Switch' incorporates:
           *  Abs: '<S702>/Abs'
           *  Constant: '<S702>/Constant'
           *  Constant: '<S708>/Constant'
           *  Product: '<S702>/Multiply'
           *  RelationalOperator: '<S708>/Compare'
           *  Sum: '<S702>/Add'
           */
          if (fabsf(rtb_Divide_lr_idx_3) > 3.14159274F) {
            /* Signum: '<S702>/Sign' */
            if (rtb_Divide_lr_idx_3 < 0.0F) {
              rtb_Integrator1_bx = -1.0F;
            } else if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Integrator1_bx = 1.0F;
            } else {
              rtb_Integrator1_bx = rtb_Divide_lr_idx_3;
            }

            /* End of Signum: '<S702>/Sign' */
            rtb_Divide_lr_idx_3 -= 6.28318548F * rtb_Integrator1_bx;
          }

          /* End of Switch: '<S702>/Switch' */

          /* Abs: '<S695>/Abs' */
          rtb_Divide_lr_idx_3 = fabsf(rtb_Divide_lr_idx_3);

          /* Update for DiscreteIntegrator: '<S719>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S712>/Constant'
           *  RelationalOperator: '<S712>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_a = (uint8_T)((uint32_T)
            (rtb_Divide_lr_idx_3 <= 0.17453292F) +
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S719>/Discrete-Time Integrator' */

          /* Update for Delay: '<S718>/Delay' */
          FMS_DW.icLoad_c = 0U;

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

          FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_o3;

          /* End of Update for DiscreteIntegrator: '<S714>/Acceleration_Speed' */

          /* Product: '<S718>/Divide1' incorporates:
           *  Constant: '<S634>/L1'
           *  Constant: '<S714>/vel'
           *  Constant: '<S717>/Constant'
           *  Gain: '<S717>/Gain'
           *  Math: '<S717>/Square'
           *  MinMax: '<S717>/Max'
           *  MinMax: '<S717>/Min'
           *  Product: '<S717>/Divide'
           *  Product: '<S717>/Multiply1'
           *  Sqrt: '<S753>/Sqrt'
           */
          rtb_a_bx = rtb_Divide_ox * (rtb_Saturation1_p5 * rtb_Saturation1_p5 *
            2.0F) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation1_d), 0.5F)) /
            FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S718>/Saturation' */
          if (rtb_a_bx > 0.314159274F) {
            rtb_a_bx = 0.314159274F;
          } else {
            if (rtb_a_bx < -0.314159274F) {
              rtb_a_bx = -0.314159274F;
            }
          }

          /* End of Saturate: '<S718>/Saturation' */

          /* Update for DiscreteIntegrator: '<S762>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_n += 0.004F * rtb_a_bx;
          FMS_DW.DiscreteTimeIntegrator_PrevRe_j = (int8_T)rtb_LogicalOperator_e;

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
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_f += ((d - rtb_u_b) * FMS_ConstB.Gain4_d *
            ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) - rtb_Divide_lr_idx_2 *
            1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S700>/Integrator' */
          /* End of Outputs for SubSystem: '<S328>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S328>/Hold' incorporates:
             *  ActionPort: '<S632>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S328>/Switch Case' incorporates:
             *  Delay: '<S653>/Delay'
             *  DiscreteIntegrator: '<S665>/Integrator'
             *  DiscreteIntegrator: '<S665>/Integrator1'
             */
            FMS_DW.icLoad_nd = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S328>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S328>/Hold' incorporates:
             *  ActionPort: '<S632>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S328>/Switch Case' incorporates:
             *  Chart: '<S641>/Motion Status'
             *  Chart: '<S652>/Motion State'
             *  Chart: '<S673>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S328>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S328>/Hold' incorporates:
           *  ActionPort: '<S632>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S641>/Motion Status' incorporates:
           *  Abs: '<S641>/Abs'
           *  Constant: '<S641>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
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
          rtb_Compare_o3 = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S653>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_nd != 0) {
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

          if (rtb_Compare_o3 || (FMS_DW.Integrator1_PrevResetState != 0)) {
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

          /* Product: '<S670>/Multiply1' incorporates:
           *  Constant: '<S670>/const1'
           *  DiscreteIntegrator: '<S665>/Integrator'
           */
          rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S670>/Add' incorporates:
           *  DiscreteIntegrator: '<S665>/Integrator1'
           *  Sum: '<S665>/Subtract'
           */
          rtb_Saturation1_p5 = (FMS_DW.Integrator1_DSTATE_jz - rtb_Saturation1_d)
            + rtb_Saturation_ga;

          /* Signum: '<S670>/Sign' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else if (rtb_Saturation1_p5 > 0.0F) {
            rtb_Saturation1_d = 1.0F;
          } else {
            rtb_Saturation1_d = rtb_Saturation1_p5;
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
          rtb_Saturation1_d = (sqrtf((8.0F * fabsf(rtb_Saturation1_p5) +
            FMS_ConstB.d_k) * FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Saturation1_d + rtb_Saturation_ga;

          /* Sum: '<S670>/Add4' */
          rtb_P_f_idx_0 = (rtb_Saturation1_p5 - rtb_Saturation1_d) +
            rtb_Saturation_ga;

          /* Sum: '<S670>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d_k;

          /* Sum: '<S670>/Subtract1' */
          rtb_Saturation1_p5 -= FMS_ConstB.d_k;

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
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S670>/Sign2' */

          /* Sum: '<S670>/Add5' incorporates:
           *  Gain: '<S670>/Gain2'
           *  Product: '<S670>/Multiply4'
           *  Sum: '<S670>/Subtract2'
           */
          rtb_Saturation1_d += (rtb_Saturation_ga - rtb_Saturation1_p5) * 0.5F *
            rtb_P_f_idx_0;

          /* Update for Delay: '<S653>/Delay' */
          FMS_DW.icLoad_nd = 0U;

          /* Update for DiscreteIntegrator: '<S665>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S665>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)rtb_Compare_o3;

          /* Sum: '<S670>/Subtract3' */
          rtb_Saturation_ga = rtb_Saturation1_d - FMS_ConstB.d_k;

          /* Sum: '<S670>/Add6' */
          rtb_P_f_idx_0 = rtb_Saturation1_d + FMS_ConstB.d_k;

          /* Signum: '<S670>/Sign5' incorporates:
           *  Signum: '<S670>/Sign6'
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S670>/Sign6' */
            d = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S670>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation1_d;

            /* Signum: '<S670>/Sign6' */
            d = rtb_Saturation1_d;
          }

          /* End of Signum: '<S670>/Sign5' */

          /* Signum: '<S670>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
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
          FMS_DW.Integrator_DSTATE_hi += ((rtb_Saturation1_d / FMS_ConstB.d_k -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_a * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          FMS_DW.Integrator_PrevResetState = (int8_T)rtb_Compare_o3;

          /* End of Update for DiscreteIntegrator: '<S665>/Integrator' */
          /* End of Outputs for SubSystem: '<S328>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S328>/Unknown' incorporates:
           *  ActionPort: '<S636>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S328>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S50>/Auto' incorporates:
         *  ActionPort: '<S326>/Action Port'
         */
        /* SwitchCase: '<S326>/Switch Case' incorporates:
         *  Math: '<S510>/Math Function'
         *  Sum: '<S466>/Subtract'
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
          /* Disable for Resettable SubSystem: '<S437>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S488>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S478>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S437>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S326>/Offboard' incorporates:
           *  ActionPort: '<S438>/Action Port'
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
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S603>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S603>/Gain' incorporates:
             *  Gain: '<S602>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S603>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S603>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S603>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S603>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

            /* Trigonometry: '<S603>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S603>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_j[0];

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
              rtb_Saturation1_d = (real32_T)(rtb_Multiply_g_idx_0 *
                FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation1_d = FMS_U.Auto_Cmd.x_cmd;
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
            rtb_Saturation1_p5 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation1_d -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S603>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_j[1];

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
              rtb_Saturation1_d = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation1_d = FMS_U.Auto_Cmd.y_cmd;
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
            rtb_Integrator1_bx = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation1_d -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S603>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_j[2];

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
              rtb_Saturation1_d = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                -FMS_U.INS_Out.alt_0);
            } else {
              rtb_Saturation1_d = FMS_U.Auto_Cmd.z_cmd;
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
            d = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation1_d -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * d + (rtb_VectorConcatenate_or[rtb_n + 3] * rtb_Integrator1_bx
                       + rtb_VectorConcatenate_or[rtb_n] * rtb_Saturation1_p5);
            }

            /* SignalConversion: '<S536>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S536>/Constant4'
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  Product: '<S594>/Multiply1'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S536>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S536>/Gain' incorporates:
             *  Gain: '<S535>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S536>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S536>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S536>/Constant3'
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S536>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

            /* Trigonometry: '<S536>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S536>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S525>/Multiply' incorporates:
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/ax_cmd valid'
             */
            rtb_Saturation1_p5 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S536>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S525>/Multiply' incorporates:
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/ay_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S536>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S525>/Multiply' incorporates:
             *  Constant: '<S534>/Constant'
             *  RelationalOperator: '<S534>/Compare'
             *  S-Function (sfix_bitop): '<S531>/az_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd
              : 0.0F;

            /* MultiPortSwitch: '<S525>/Index Vector' incorporates:
             *  Product: '<S532>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] * d +
                (rtb_VectorConcatenate_or[rtb_n + 3] * rtb_Integrator1_bx +
                 rtb_VectorConcatenate_or[rtb_n] * rtb_Saturation1_p5);
            }
            break;

           case 1:
            /* SignalConversion: '<S606>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S606>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S606>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S604>/Gain'
             *  Trigonometry: '<S606>/Trigonometric Function1'
             */
            rtb_Saturation1_d = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_or[4] = rtb_Saturation1_d;

            /* Trigonometry: '<S606>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S604>/Gain'
             *  Trigonometry: '<S606>/Trigonometric Function'
             */
            rtb_Saturation1_p5 = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S606>/Gain' incorporates:
             *  Trigonometry: '<S606>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -rtb_Saturation1_p5;

            /* SignalConversion: '<S606>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S606>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S606>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_Saturation1_p5;

            /* Trigonometry: '<S606>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation1_d;

            /* SignalConversion: '<S607>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S607>/Constant4'
             */
            rtb_MatrixConcatenate1[5] = 0.0F;

            /* Gain: '<S605>/Gain' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S537>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S595>/Subtract'
             */
            rtb_Divide_lr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S607>/Trigonometric Function3' incorporates:
             *  Gain: '<S605>/Gain'
             *  Trigonometry: '<S607>/Trigonometric Function1'
             */
            rtb_Saturation1_d = arm_cos_f32(rtb_Divide_lr_idx_2);
            rtb_MatrixConcatenate1[4] = rtb_Saturation1_d;

            /* Trigonometry: '<S607>/Trigonometric Function2' incorporates:
             *  Gain: '<S605>/Gain'
             *  Trigonometry: '<S607>/Trigonometric Function'
             */
            rtb_Saturation1_p5 = arm_sin_f32(rtb_Divide_lr_idx_2);

            /* Gain: '<S607>/Gain' incorporates:
             *  Trigonometry: '<S607>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1[3] = -rtb_Saturation1_p5;

            /* SignalConversion: '<S607>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S607>/Constant3'
             */
            rtb_MatrixConcatenate1[2] = 0.0F;

            /* Trigonometry: '<S607>/Trigonometric Function' */
            rtb_MatrixConcatenate1[1] = rtb_Saturation1_p5;

            /* Trigonometry: '<S607>/Trigonometric Function1' */
            rtb_MatrixConcatenate1[0] = rtb_Saturation1_d;

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
            rtb_MatrixConcatenate1_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S596>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S606>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S607>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S595>/Sum' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation1_p5 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S606>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S607>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S595>/Sum' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Integrator1_bx = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S606>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S607>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S595>/Sum' incorporates:
             *  DataStoreRead: '<S595>/Data Store Read'
             *  Gain: '<S597>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            d = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

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
                rtb_Saturation1_d = rtb_MatrixConcatenate1_0[rtb_n];
              } else {
                rtb_Saturation1_d = rtb_Switch_c2[rtb_n];
              }

              /* Product: '<S595>/Multiply' incorporates:
               *  Logic: '<S593>/Logical Operator'
               *  Product: '<S595>/Multiply2'
               *  Sum: '<S595>/Sum'
               *  Sum: '<S595>/Sum2'
               */
              rtb_Switch_ov[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation1_d - ((rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] *
                rtb_Saturation1_p5) + rtb_VectorConcatenate_or[rtb_n + 6] * d) :
                0.0F;
            }

            /* SignalConversion: '<S538>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S538>/Constant4'
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S538>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Divide_lr_idx_2);

            /* Gain: '<S538>/Gain' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             *  Trigonometry: '<S538>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Divide_lr_idx_2);

            /* SignalConversion: '<S538>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S538>/Constant3'
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S538>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Divide_lr_idx_2);

            /* Trigonometry: '<S538>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S525>/Index Vector'
             */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Divide_lr_idx_2);

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
              rtb_VectorConcatenate_or[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S525>/Multiply' */
              rtb_MatrixConcatenate1_0[rtb_n] = tmp[rtb_n] ? rtb_Switch_c2[rtb_n]
                : 0.0F;
              rtb_MatrixConcatenate3[rtb_n] = rtb_MatrixConcatenate1[rtb_n + 6] *
                rtb_Switch_ov[2] + (rtb_MatrixConcatenate1[rtb_n + 3] *
                                    rtb_Switch_ov[1] +
                                    rtb_MatrixConcatenate1[rtb_n] *
                                    rtb_Switch_ov[0]);
            }

            /* MultiPortSwitch: '<S525>/Index Vector' incorporates:
             *  Product: '<S533>/Multiply3'
             *  Product: '<S595>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ov[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6] *
                rtb_MatrixConcatenate1_0[2] + (rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_MatrixConcatenate1_0[1] +
                rtb_VectorConcatenate_or[rtb_n] * rtb_MatrixConcatenate1_0[0]);
            }
            break;

           default:
            /* SignalConversion: '<S599>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S599>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S599>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S599>/Gain' incorporates:
             *  Gain: '<S598>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S599>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S599>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S599>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S599>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

            /* Trigonometry: '<S599>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

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
            rtb_MatrixConcatenate1_0[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_MatrixConcatenate1_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S596>/Switch' */
            rtb_Switch_c2[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_Switch_c2[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_Switch_c2[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S599>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Sum: '<S592>/Sum' incorporates:
             *  DataStoreRead: '<S592>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Saturation1_p5 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S599>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Sum: '<S592>/Sum' incorporates:
             *  DataStoreRead: '<S592>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S599>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Sum: '<S592>/Sum' incorporates:
             *  DataStoreRead: '<S592>/Data Store Read'
             *  Gain: '<S597>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            rtb_Divide_lr_idx_3 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

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
                rtb_Saturation1_d = rtb_MatrixConcatenate1_0[rtb_n];
              } else {
                rtb_Saturation1_d = rtb_Switch_c2[rtb_n];
              }

              rtb_MatrixConcatenate3[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation1_d - ((rtb_VectorConcatenate_or[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_or[rtb_n] *
                rtb_Saturation1_p5) + rtb_VectorConcatenate_or[rtb_n + 6] *
                rtb_Divide_lr_idx_3) : 0.0F;
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
          rtb_Saturation1_d = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S587>/Abs' */
          rtb_Saturation1_p5 = fabsf(rtb_Saturation1_d);

          /* Switch: '<S587>/Switch' incorporates:
           *  Constant: '<S587>/Constant'
           *  Constant: '<S588>/Constant'
           *  Product: '<S587>/Multiply'
           *  RelationalOperator: '<S588>/Compare'
           *  Sum: '<S587>/Subtract'
           */
          if (rtb_Saturation1_p5 > 3.14159274F) {
            /* Signum: '<S587>/Sign' */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else {
              if (rtb_Saturation1_d > 0.0F) {
                rtb_Saturation1_d = 1.0F;
              }
            }

            /* End of Signum: '<S587>/Sign' */
            rtb_Saturation1_d *= rtb_Saturation1_p5 - 6.28318548F;
          }

          /* End of Switch: '<S587>/Switch' */

          /* Saturate: '<S586>/Saturation' */
          if (rtb_Saturation1_d > 0.314159274F) {
            rtb_Saturation1_d = 0.314159274F;
          } else {
            if (rtb_Saturation1_d < -0.314159274F) {
              rtb_Saturation1_d = -0.314159274F;
            }
          }

          /* End of Saturate: '<S586>/Saturation' */

          /* Gain: '<S583>/Gain2' */
          rtb_Saturation1_d *= FMS_PARAM.YAW_P;

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
          rtb_a_bx = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Saturation1_d :
                      0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
                               FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S590>/Gain1' */
          rtb_Divide_lr_idx_2 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
          rtb_Divide_lr_idx_3 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

          /* Gain: '<S590>/Gain2' */
          rtb_Saturation1_d = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

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
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Trigonometry: '<S629>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* Gain: '<S629>/Gain' incorporates:
             *  Gain: '<S628>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S629>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S629>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S629>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S629>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

            /* Trigonometry: '<S629>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* SignalConversion: '<S629>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/u_cmd valid'
             */
            rtb_Saturation1_p5 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S629>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S629>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/w_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ? FMS_U.Auto_Cmd.w_cmd :
              0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * d + (rtb_VectorConcatenate_or[rtb_n + 3] * rtb_Integrator1_bx
                       + rtb_VectorConcatenate_or[rtb_n] * rtb_Saturation1_p5);
            }
            break;

           case 1:
            /* SignalConversion: '<S631>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S631>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

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
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Saturation_ga);

            /* Gain: '<S631>/Gain' incorporates:
             *  Gain: '<S630>/Gain'
             *  Trigonometry: '<S631>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S631>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S631>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S631>/Trigonometric Function' incorporates:
             *  Gain: '<S630>/Gain'
             */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Saturation_ga);

            /* Trigonometry: '<S631>/Trigonometric Function1' incorporates:
             *  Gain: '<S630>/Gain'
             */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Saturation_ga);

            /* SignalConversion: '<S631>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_gjo[0];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/u_cmd valid'
             */
            rtb_Saturation1_p5 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S631>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_gjo[1];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/v_cmd valid'
             */
            rtb_Integrator1_bx = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S631>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_gjo[2];

            /* Product: '<S591>/Multiply' incorporates:
             *  Constant: '<S627>/Constant'
             *  RelationalOperator: '<S627>/Compare'
             *  S-Function (sfix_bitop): '<S623>/w_cmd valid'
             */
            d = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ? FMS_U.Auto_Cmd.w_cmd :
              0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate3[rtb_n] = rtb_VectorConcatenate_or[rtb_n + 6]
                * d + (rtb_VectorConcatenate_or[rtb_n + 3] * rtb_Integrator1_bx
                       + rtb_VectorConcatenate_or[rtb_n] * rtb_Saturation1_p5);
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
          rtb_MatrixConcatenate3[0] += rtb_Divide_lr_idx_2;
          rtb_MatrixConcatenate3[1] += rtb_Divide_lr_idx_3;

          /* Sum: '<S528>/Sum1' */
          rtb_Saturation_ga = rtb_Saturation1_d + rtb_MatrixConcatenate3[2];

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
            rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_Compare_o3 = rtb_LogicalOperator_e;
          } else {
            rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_Compare_o3 = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U);
          }

          /* End of Switch: '<S546>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S526>/u_cmd_valid' */
          /* MATLAB Function: '<S558>/bit_shift' incorporates:
           *  DataTypeConversion: '<S526>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_LogicalOperator_e << 6);

          /* End of Outputs for SubSystem: '<S526>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S526>/v_cmd_valid' */
          /* MATLAB Function: '<S559>/bit_shift' incorporates:
           *  DataTypeConversion: '<S526>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_Compare_o3 << 7);

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
            rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_Compare_o3 = rtb_LogicalOperator_e;
          } else {
            rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_Compare_o3 = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
          }

          /* End of Switch: '<S547>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S438>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S438>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S438>/Bus Assignment' incorporates:
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
          if (rtb_a_bx > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_a_bx < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_a_bx;
          }

          /* End of Saturate: '<S527>/Saturation' */

          /* Saturate: '<S528>/Saturation2' */
          if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
          }

          /* End of Saturate: '<S528>/Saturation2' */

          /* Saturate: '<S528>/Saturation1' */
          if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
          }

          /* End of Saturate: '<S528>/Saturation1' */

          /* Saturate: '<S528>/Saturation3' */
          if (rtb_Saturation_ga > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_ga < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S438>/Bus Assignment' incorporates:
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
          /* BusAssignment: '<S438>/Bus Assignment' incorporates:
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
            (rtb_LogicalOperator_e << 9)) + (rtb_Compare_o3 << 10)) +
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
          /* End of Outputs for SubSystem: '<S326>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S326>/Mission' incorporates:
             *  ActionPort: '<S437>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S326>/Switch Case' incorporates:
             *  UnitDelay: '<S440>/Delay Input1'
             *
             * Block description for '<S440>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S326>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S326>/Mission' incorporates:
             *  ActionPort: '<S437>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S437>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S326>/Switch Case' incorporates:
             *  Chart: '<S479>/Motion Status'
             *  Chart: '<S489>/Motion State'
             *  Delay: '<S445>/Delay'
             *  Delay: '<S467>/Delay'
             *  Delay: '<S467>/Delay1'
             *  DiscreteIntegrator: '<S448>/Integrator'
             *  DiscreteIntegrator: '<S448>/Integrator1'
             *  DiscreteIntegrator: '<S463>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S468>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S517>/Discrete-Time Integrator'
             */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            FMS_DW.Delay1_DSTATE = false;
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.DiscreteTimeIntegrator_PrevRe_i = 0;
            FMS_DW.icLoad_m = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);

            /* End of SystemReset for SubSystem: '<S437>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S326>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S326>/Mission' incorporates:
           *  ActionPort: '<S437>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S440>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S440>/Delay Input1'
           *
           * Block description for '<S440>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S437>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S441>/Reset'
           */
          if (rtb_Compare_o3 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
                                 POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S488>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S478>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for DiscreteIntegrator: '<S468>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for Delay: '<S467>/Delay1' */
            FMS_DW.Delay1_DSTATE = false;

            /* InitializeConditions for Delay: '<S467>/Delay' */
            FMS_DW.icLoad_n = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S463>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S517>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.DiscreteTimeIntegrator_PrevRe_i = 0;

            /* InitializeConditions for Delay: '<S445>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S489>/Motion State' */
            FMS_MotionState_f_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S479>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Compare_o3;

          /* DiscreteIntegrator: '<S468>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S440>/Delay Input1'
           *
           * Block description for '<S440>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S462>/Compare' incorporates:
           *  Constant: '<S524>/Constant'
           *  RelationalOperator: '<S524>/Compare'
           *  UnitDelay: '<S440>/Delay Input1'
           *
           * Block description for '<S440>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_o3 = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* Logic: '<S467>/Logical Operator' incorporates:
           *  Delay: '<S467>/Delay1'
           */
          rtb_LogicalOperator_e = (rtb_Compare_o3 || FMS_DW.Delay1_DSTATE);

          /* Delay: '<S467>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if ((((FMS_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) != (int32_T)
                rtb_LogicalOperator_e) && (FMS_PrevZCX.Delay_Reset_ZCE !=
                UNINITIALIZED_ZCSIG)) || rtb_LogicalOperator_e) {
            FMS_DW.icLoad_n = 1U;
          }

          FMS_PrevZCX.Delay_Reset_ZCE = rtb_LogicalOperator_e;
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_d[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_d[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S467>/Sum' incorporates:
           *  Delay: '<S467>/Delay'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract_hb[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_d[0];
          rtb_Subtract_hb[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_d[1];

          /* RelationalOperator: '<S472>/Compare' incorporates:
           *  Constant: '<S472>/Constant'
           *  Delay: '<S467>/Delay1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          FMS_DW.Delay1_DSTATE = (FMS_B.Cmd_In.set_speed > 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S463>/Switch2' incorporates:
           *  Constant: '<S463>/vel'
           *  Delay: '<S467>/Delay1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_DW.Delay1_DSTATE) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.set_speed;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            rtb_Divide_lr_idx_3 = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S463>/Switch2' */

          /* DiscreteIntegrator: '<S463>/Acceleration_Speed' */
          if (rtb_Compare_o3 || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* DiscreteIntegrator: '<S517>/Discrete-Time Integrator' */
          if (rtb_LogicalOperator_e || (FMS_DW.DiscreteTimeIntegrator_PrevRe_i
               != 0)) {
            FMS_DW.l1_heading = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S489>/Motion State' incorporates:
           *  Constant: '<S489>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S489>/Square'
           *  Math: '<S489>/Square1'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sqrt: '<S489>/Sqrt'
           *  Sum: '<S489>/Add'
           */
          FMS_MotionState_p(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S488>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S498>/Integrator1'
           *  Gain: '<S492>/Gain6'
           *  Gain: '<S496>/Gain'
           *  Gain: '<S497>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S498>/Subtract'
           *  Sum: '<S499>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S488>/Hold Control' incorporates:
               *  ActionPort: '<S491>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S488>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S488>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S488>/Hold Control' incorporates:
             *  ActionPort: '<S491>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S488>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S488>/Brake Control' incorporates:
             *  ActionPort: '<S490>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S488>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S488>/Move Control' incorporates:
               *  ActionPort: '<S492>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S488>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S498>/Integrator'
               *  DiscreteIntegrator: '<S498>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S488>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S488>/Move Control' incorporates:
             *  ActionPort: '<S492>/Action Port'
             */
            /* SignalConversion: '<S492>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S499>/Multiply1' incorporates:
             *  Constant: '<S499>/const1'
             *  DiscreteIntegrator: '<S498>/Integrator'
             */
            rtb_Divide_c14[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S492>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S499>/Multiply1' incorporates:
             *  Constant: '<S499>/const1'
             *  DiscreteIntegrator: '<S498>/Integrator'
             */
            rtb_Divide_c14[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S496>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S499>/Add' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator1'
             *  Gain: '<S492>/Gain6'
             *  Gain: '<S496>/Gain'
             *  Sum: '<S498>/Subtract'
             */
            rtb_P_ap[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_Saturation1_d * FMS_PARAM.VEL_XY_LIM) +
              rtb_Divide_c14[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S497>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S499>/Add' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator1'
             *  Gain: '<S492>/Gain6'
             *  Gain: '<S497>/Gain'
             *  Sum: '<S498>/Subtract'
             */
            rtb_P_ap[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * FMS_PARAM.VEL_XY_LIM) +
              rtb_Divide_c14[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S496>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_a_bx = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_Saturation1_d * FMS_PARAM.VEL_XY_LIM) +
              rtb_Divide_c14[0];

            /* Signum: '<S499>/Sign' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator1'
             *  Gain: '<S492>/Gain6'
             *  Gain: '<S496>/Gain'
             *  Sum: '<S498>/Subtract'
             *  Sum: '<S499>/Add'
             */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* Sum: '<S499>/Add2' incorporates:
             *  Abs: '<S499>/Abs'
             *  Gain: '<S499>/Gain'
             *  Gain: '<S499>/Gain1'
             *  Product: '<S499>/Multiply2'
             *  Product: '<S499>/Multiply3'
             *  Signum: '<S499>/Sign'
             *  Sqrt: '<S499>/Sqrt'
             *  Sum: '<S499>/Add1'
             *  Sum: '<S499>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_P_ap[0]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_a_bx + rtb_Divide_c14[0];

            /* Sum: '<S499>/Add3' incorporates:
             *  Signum: '<S499>/Sign'
             */
            rtb_Saturation_ga = rtb_P_ap[0] + FMS_ConstB.d_oe;

            /* Sum: '<S499>/Subtract1' incorporates:
             *  Signum: '<S499>/Sign'
             */
            rtb_a_bx = rtb_P_ap[0] - FMS_ConstB.d_oe;

            /* Signum: '<S499>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S499>/Sign2' */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* Sum: '<S499>/Add5' incorporates:
             *  Gain: '<S499>/Gain2'
             *  Product: '<S499>/Multiply4'
             *  Signum: '<S499>/Sign'
             *  Sum: '<S499>/Add2'
             *  Sum: '<S499>/Add4'
             *  Sum: '<S499>/Subtract2'
             */
            rtb_Divide_lr_idx_2 += ((rtb_P_ap[0] - rtb_Divide_lr_idx_2) +
              rtb_Divide_c14[0]) * ((rtb_Saturation_ga - rtb_a_bx) * 0.5F);

            /* Update for DiscreteIntegrator: '<S498>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S499>/Sign4' incorporates:
             *  Sum: '<S499>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_2 - FMS_ConstB.d_oe;

            /* Signum: '<S499>/Sign3' incorporates:
             *  Sum: '<S499>/Add6'
             */
            rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_oe;

            /* Signum: '<S499>/Sign5' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Divide_lr_idx_2;
            }

            /* Signum: '<S499>/Sign3' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = -1.0F;
            } else {
              if (rtb_P_f_idx_0 > 0.0F) {
                rtb_P_f_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S499>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S499>/Sign6' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              d = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_Divide_lr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S498>/Integrator' incorporates:
             *  Constant: '<S499>/const'
             *  Gain: '<S499>/Gain3'
             *  Product: '<S499>/Divide'
             *  Product: '<S499>/Multiply5'
             *  Product: '<S499>/Multiply6'
             *  Sum: '<S499>/Subtract4'
             *  Sum: '<S499>/Subtract5'
             *  Sum: '<S499>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Divide_lr_idx_2 /
              FMS_ConstB.d_oe - rtb_Saturation1_d) * FMS_ConstB.Gain4_g *
              ((rtb_P_f_idx_0 - rtb_Saturation_ga) * 0.5F) - d * 58.836F) *
              0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S497>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_a_bx = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * FMS_PARAM.VEL_XY_LIM) +
              rtb_Divide_c14[1];

            /* Signum: '<S499>/Sign' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator1'
             *  Gain: '<S492>/Gain6'
             *  Gain: '<S497>/Gain'
             *  Sum: '<S498>/Subtract'
             *  Sum: '<S499>/Add'
             */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* Sum: '<S499>/Add2' incorporates:
             *  Abs: '<S499>/Abs'
             *  Gain: '<S499>/Gain'
             *  Gain: '<S499>/Gain1'
             *  Product: '<S499>/Multiply2'
             *  Product: '<S499>/Multiply3'
             *  Signum: '<S499>/Sign'
             *  Sqrt: '<S499>/Sqrt'
             *  Sum: '<S499>/Add1'
             *  Sum: '<S499>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_P_ap[1]) +
              FMS_ConstB.d_oe) * FMS_ConstB.d_oe) - FMS_ConstB.d_oe) * 0.5F *
              rtb_a_bx + rtb_Divide_c14[1];

            /* Sum: '<S499>/Add3' incorporates:
             *  Signum: '<S499>/Sign'
             */
            rtb_Saturation_ga = rtb_P_ap[1] + FMS_ConstB.d_oe;

            /* Sum: '<S499>/Subtract1' incorporates:
             *  Signum: '<S499>/Sign'
             */
            rtb_a_bx = rtb_P_ap[1] - FMS_ConstB.d_oe;

            /* Signum: '<S499>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S499>/Sign2' */
            if (rtb_a_bx < 0.0F) {
              rtb_a_bx = -1.0F;
            } else {
              if (rtb_a_bx > 0.0F) {
                rtb_a_bx = 1.0F;
              }
            }

            /* Sum: '<S499>/Add5' incorporates:
             *  Gain: '<S499>/Gain2'
             *  Product: '<S499>/Multiply4'
             *  Signum: '<S499>/Sign'
             *  Sum: '<S499>/Add2'
             *  Sum: '<S499>/Add4'
             *  Sum: '<S499>/Subtract2'
             */
            rtb_Divide_lr_idx_2 += ((rtb_P_ap[1] - rtb_Divide_lr_idx_2) +
              rtb_Divide_c14[1]) * ((rtb_Saturation_ga - rtb_a_bx) * 0.5F);

            /* Update for DiscreteIntegrator: '<S498>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S498>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S499>/Sign4' incorporates:
             *  Sum: '<S499>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_2 - FMS_ConstB.d_oe;

            /* Signum: '<S499>/Sign3' incorporates:
             *  Sum: '<S499>/Add6'
             */
            rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_oe;

            /* Signum: '<S499>/Sign5' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Divide_lr_idx_2;
            }

            /* Signum: '<S499>/Sign3' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = -1.0F;
            } else {
              if (rtb_P_f_idx_0 > 0.0F) {
                rtb_P_f_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S499>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S499>/Sign6' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              d = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              d = 1.0F;
            } else {
              d = rtb_Divide_lr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S498>/Integrator' incorporates:
             *  Constant: '<S499>/const'
             *  Gain: '<S499>/Gain3'
             *  Product: '<S499>/Divide'
             *  Product: '<S499>/Multiply5'
             *  Product: '<S499>/Multiply6'
             *  Sum: '<S499>/Subtract4'
             *  Sum: '<S499>/Subtract5'
             *  Sum: '<S499>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Divide_lr_idx_2 /
              FMS_ConstB.d_oe - rtb_Saturation1_d) * FMS_ConstB.Gain4_g *
              ((rtb_P_f_idx_0 - rtb_Saturation_ga) * 0.5F) - d * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S488>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S488>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S479>/Motion Status' incorporates:
           *  Abs: '<S479>/Abs'
           *  Constant: '<S479>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_ej,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S478>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S478>/Hold Control' incorporates:
               *  ActionPort: '<S481>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S478>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S478>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S478>/Hold Control' incorporates:
             *  ActionPort: '<S481>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S478>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S478>/Brake Control' incorporates:
             *  ActionPort: '<S480>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S478>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S478>/Move Control' incorporates:
               *  ActionPort: '<S482>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S478>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S485>/Integrator'
               *  DiscreteIntegrator: '<S485>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S478>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S478>/Move Control' incorporates:
             *  ActionPort: '<S482>/Action Port'
             */
            /* Product: '<S486>/Multiply1' incorporates:
             *  Constant: '<S486>/const1'
             *  DiscreteIntegrator: '<S485>/Integrator'
             */
            rtb_Saturation_ga = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S484>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle -
                FMS_PARAM.THROTTLE_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ)
            {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle -
                (-FMS_PARAM.THROTTLE_DZ);
            }

            /* End of DeadZone: '<S484>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S486>/Add' incorporates:
             *  DiscreteIntegrator: '<S485>/Integrator1'
             *  Gain: '<S482>/Gain1'
             *  Gain: '<S484>/Gain'
             *  Sum: '<S485>/Subtract'
             */
            rtb_P_f_idx_0 = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_Saturation1_d * -FMS_PARAM.VEL_Z_LIM)
              + rtb_Saturation_ga;

            /* Signum: '<S486>/Sign' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_P_f_idx_0 > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_P_f_idx_0;
            }

            /* End of Signum: '<S486>/Sign' */

            /* Sum: '<S486>/Add2' incorporates:
             *  Abs: '<S486>/Abs'
             *  Gain: '<S486>/Gain'
             *  Gain: '<S486>/Gain1'
             *  Product: '<S486>/Multiply2'
             *  Product: '<S486>/Multiply3'
             *  Sqrt: '<S486>/Sqrt'
             *  Sum: '<S486>/Add1'
             *  Sum: '<S486>/Subtract'
             */
            rtb_Saturation1_d = (sqrtf((8.0F * fabsf(rtb_P_f_idx_0) +
              FMS_ConstB.d_oc) * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation1_d + rtb_Saturation_ga;

            /* Sum: '<S486>/Add4' */
            rtb_Divide_lr_idx_2 = (rtb_P_f_idx_0 - rtb_Saturation1_d) +
              rtb_Saturation_ga;

            /* Sum: '<S486>/Add3' */
            rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_oc;

            /* Sum: '<S486>/Subtract1' */
            rtb_P_f_idx_0 -= FMS_ConstB.d_oc;

            /* Signum: '<S486>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S486>/Sign1' */

            /* Signum: '<S486>/Sign2' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = -1.0F;
            } else {
              if (rtb_P_f_idx_0 > 0.0F) {
                rtb_P_f_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S486>/Sign2' */

            /* Sum: '<S486>/Add5' incorporates:
             *  Gain: '<S486>/Gain2'
             *  Product: '<S486>/Multiply4'
             *  Sum: '<S486>/Subtract2'
             */
            rtb_Saturation1_d += (rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F *
              rtb_Divide_lr_idx_2;

            /* SignalConversion: '<S482>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S485>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S485>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S485>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S486>/Subtract3' */
            rtb_Saturation_ga = rtb_Saturation1_d - FMS_ConstB.d_oc;

            /* Sum: '<S486>/Add6' */
            rtb_P_f_idx_0 = rtb_Saturation1_d + FMS_ConstB.d_oc;

            /* Signum: '<S486>/Sign5' incorporates:
             *  Signum: '<S486>/Sign6'
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;

              /* Signum: '<S486>/Sign6' */
              d = -1.0F;
            } else if (rtb_Saturation1_d > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;

              /* Signum: '<S486>/Sign6' */
              d = 1.0F;
            } else {
              rtb_Divide_lr_idx_2 = rtb_Saturation1_d;

              /* Signum: '<S486>/Sign6' */
              d = rtb_Saturation1_d;
            }

            /* End of Signum: '<S486>/Sign5' */

            /* Signum: '<S486>/Sign3' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = -1.0F;
            } else {
              if (rtb_P_f_idx_0 > 0.0F) {
                rtb_P_f_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S486>/Sign3' */

            /* Signum: '<S486>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* End of Signum: '<S486>/Sign4' */

            /* Update for DiscreteIntegrator: '<S485>/Integrator' incorporates:
             *  Constant: '<S486>/const'
             *  Gain: '<S486>/Gain3'
             *  Product: '<S486>/Divide'
             *  Product: '<S486>/Multiply5'
             *  Product: '<S486>/Multiply6'
             *  Sum: '<S486>/Subtract4'
             *  Sum: '<S486>/Subtract5'
             *  Sum: '<S486>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_Saturation1_d / FMS_ConstB.d_oc
              - rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_j * ((rtb_P_f_idx_0 -
              rtb_Saturation_ga) * 0.5F) - d * 78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S478>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S478>/Switch Case' */

          /* Switch: '<S443>/Switch' incorporates:
           *  Product: '<S467>/Multiply'
           */
          if (rtb_Compare_o3) {
            /* Saturate: '<S488>/Saturation1' */
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

            /* End of Saturate: '<S488>/Saturation1' */

            /* Saturate: '<S478>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S478>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S463>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];
            d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S475>/Sqrt' incorporates:
             *  Math: '<S475>/Square'
             *  Sum: '<S463>/Sum'
             *  Sum: '<S475>/Sum of Elements'
             */
            rtb_Saturation_ga = sqrtf(rtb_Saturation1_d * rtb_Saturation1_d + d *
              d);

            /* SignalConversion: '<S523>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_p[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_p[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_p[2];

            /* SignalConversion: '<S523>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S523>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S522>/Gain' incorporates:
             *  DiscreteIntegrator: '<S517>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S517>/Add'
             */
            rtb_Saturation1_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S523>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = arm_cos_f32(rtb_Saturation1_d);

            /* Gain: '<S523>/Gain' incorporates:
             *  Trigonometry: '<S523>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(rtb_Saturation1_d);

            /* SignalConversion: '<S523>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S523>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Trigonometry: '<S523>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = arm_sin_f32(rtb_Saturation1_d);

            /* Trigonometry: '<S523>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = arm_cos_f32(rtb_Saturation1_d);

            /* Switch: '<S474>/Switch2' incorporates:
             *  Constant: '<S463>/Constant2'
             *  DiscreteIntegrator: '<S463>/Acceleration_Speed'
             *  RelationalOperator: '<S474>/LowerRelop1'
             *  RelationalOperator: '<S474>/UpperRelop'
             *  Switch: '<S474>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Divide_lr_idx_3) {
              rtb_Saturation1_d = rtb_Divide_lr_idx_3;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S474>/Switch' incorporates:
               *  Constant: '<S463>/Constant2'
               */
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S474>/Switch2' */

            /* Switch: '<S463>/Switch' */
            if (rtb_Saturation_ga > FMS_PARAM.L1) {
              rtb_Saturation_ga = rtb_Divide_lr_idx_3;
            } else {
              /* Gain: '<S463>/Gain' */
              rtb_Saturation_ga *= 0.5F;

              /* Switch: '<S473>/Switch2' incorporates:
               *  Constant: '<S463>/Constant1'
               *  RelationalOperator: '<S473>/LowerRelop1'
               *  RelationalOperator: '<S473>/UpperRelop'
               *  Switch: '<S473>/Switch'
               */
              if (rtb_Saturation_ga > rtb_Divide_lr_idx_3) {
                rtb_Saturation_ga = rtb_Divide_lr_idx_3;
              } else {
                if (rtb_Saturation_ga < 0.5F) {
                  /* Switch: '<S473>/Switch' incorporates:
                   *  Constant: '<S463>/Constant1'
                   */
                  rtb_Saturation_ga = 0.5F;
                }
              }

              /* End of Switch: '<S473>/Switch2' */
            }

            /* End of Switch: '<S463>/Switch' */

            /* Switch: '<S463>/Switch1' incorporates:
             *  Sum: '<S463>/Sum1'
             */
            if (rtb_Saturation1_d - rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = rtb_Saturation1_d;
            }

            /* End of Switch: '<S463>/Switch1' */

            /* Sum: '<S518>/Sum of Elements' incorporates:
             *  Math: '<S518>/Math Function'
             *  SignalConversion: '<S518>/TmpSignal ConversionAtMath FunctionInport1'
             */
            rtb_Saturation1_d = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
              rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

            /* Math: '<S518>/Math Function1' incorporates:
             *  Sum: '<S518>/Sum of Elements'
             *
             * About '<S518>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation1_d < 0.0F) {
              rtb_Saturation1_d = -sqrtf(fabsf(rtb_Saturation1_d));
            } else {
              rtb_Saturation1_d = sqrtf(rtb_Saturation1_d);
            }

            /* End of Math: '<S518>/Math Function1' */

            /* Switch: '<S518>/Switch' incorporates:
             *  Constant: '<S518>/Constant'
             *  Product: '<S518>/Product'
             */
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Divide_p3p[0] = rtb_Subtract_hb[0];
              rtb_Divide_p3p[1] = rtb_Subtract_hb[1];
              rtb_Divide_p3p[3] = rtb_Saturation1_d;
            } else {
              rtb_Divide_p3p[0] = 0.0F;
              rtb_Divide_p3p[1] = 0.0F;
              rtb_Divide_p3p[3] = 1.0F;
            }

            /* End of Switch: '<S518>/Switch' */

            /* Product: '<S515>/Multiply2' incorporates:
             *  Product: '<S518>/Divide'
             */
            rtb_P_f_idx_0 = rtb_Divide_p3p[0] / rtb_Divide_p3p[3] *
              rtb_Saturation_ga;
            rtb_Saturation_ga *= rtb_Divide_p3p[1] / rtb_Divide_p3p[3];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S469>/Sum1' incorporates:
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation1_d = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S469>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
              [0];
            rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S469>/Divide' incorporates:
             *  Math: '<S470>/Square'
             *  Math: '<S471>/Square'
             *  Sqrt: '<S470>/Sqrt'
             *  Sqrt: '<S471>/Sqrt'
             *  Sum: '<S469>/Sum'
             *  Sum: '<S469>/Sum1'
             *  Sum: '<S470>/Sum of Elements'
             *  Sum: '<S471>/Sum of Elements'
             */
            rtb_Saturation1_d = sqrtf(rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2
              + rtb_a_bx * rtb_a_bx) / sqrtf(rtb_Saturation1_d *
              rtb_Saturation1_d + d * d);

            /* Saturate: '<S469>/Saturation' */
            if (rtb_Saturation1_d > 1.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              if (rtb_Saturation1_d < 0.0F) {
                rtb_Saturation1_d = 0.0F;
              }
            }

            /* End of Saturate: '<S469>/Saturation' */

            /* Product: '<S467>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_Saturation_ga + rtb_VectorConcatenate_or[rtb_n] *
                rtb_P_f_idx_0;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S460>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S469>/Multiply'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S460>/Sum2'
             *  Sum: '<S469>/Add'
             *  Sum: '<S469>/Subtract'
             */
            rtb_a_bx = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation1_d +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_MatrixConcatenate1_0[0];
            rtb_Switch_c2[1] = rtb_MatrixConcatenate1_0[1];

            /* Saturate: '<S460>/Saturation1' incorporates:
             *  Product: '<S467>/Multiply'
             */
            if (rtb_a_bx > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_a_bx < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_a_bx;
            }

            /* End of Saturate: '<S460>/Saturation1' */
          }

          /* End of Switch: '<S443>/Switch' */

          /* Delay: '<S445>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S448>/Integrator1' incorporates:
           *  Delay: '<S445>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S452>/Rem' incorporates:
           *  Constant: '<S452>/Constant1'
           *  DiscreteIntegrator: '<S448>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  Sum: '<S447>/Sum'
           */
          rtb_Divide_lr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S452>/Switch' incorporates:
           *  Abs: '<S452>/Abs'
           *  Constant: '<S452>/Constant'
           *  Constant: '<S453>/Constant'
           *  Product: '<S452>/Multiply'
           *  RelationalOperator: '<S453>/Compare'
           *  Sum: '<S452>/Add'
           */
          if (fabsf(rtb_Divide_lr_idx_2) > 3.14159274F) {
            /* Signum: '<S452>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Divide_lr_idx_2;
            }

            /* End of Signum: '<S452>/Sign' */
            rtb_Divide_lr_idx_2 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S452>/Switch' */

          /* Gain: '<S447>/Gain2' */
          rtb_Divide_lr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S447>/Saturation' */
          if (rtb_Divide_lr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_lr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_lr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_lr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S447>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S441>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S441>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S441>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_lr_idx_2;

          /* Sum: '<S520>/Sum of Elements' incorporates:
           *  Math: '<S520>/Math Function'
           *  SignalConversion: '<S520>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation1_d = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S520>/Math Function1' incorporates:
           *  Sum: '<S520>/Sum of Elements'
           *
           * About '<S520>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S520>/Math Function1' */

          /* Switch: '<S520>/Switch' incorporates:
           *  Constant: '<S520>/Constant'
           *  Product: '<S520>/Product'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Divide_lr_idx_2;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S520>/Switch' */

          /* Math: '<S509>/Math Function1'
           *
           * About '<S509>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Integrator1_bx));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Integrator1_bx);
          }

          /* End of Math: '<S509>/Math Function1' */

          /* Switch: '<S509>/Switch' incorporates:
           *  Constant: '<S509>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S509>/Product'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_f_idx_0 = FMS_U.INS_Out.vn;
            rtb_Saturation_ga = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Integrator1_bx = rtb_Divide_lr_idx_2;
          } else {
            rtb_P_f_idx_0 = 0.0F;
            rtb_Saturation_ga = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S509>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S441>/Sum' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_ox = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_e = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S459>/Sum of Elements' incorporates:
           *  Math: '<S459>/Math Function'
           *  Sum: '<S441>/Sum'
           */
          rtb_Saturation1_d = rtb_Divide_e * rtb_Divide_e + rtb_Divide_ox *
            rtb_Divide_ox;

          /* Math: '<S459>/Math Function1' incorporates:
           *  Sum: '<S459>/Sum of Elements'
           *
           * About '<S459>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S459>/Math Function1' */

          /* Switch: '<S459>/Switch' incorporates:
           *  Constant: '<S459>/Constant'
           *  Product: '<S459>/Product'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_u_b = rtb_Divide_lr_idx_2;
          } else {
            rtb_Divide_e = 0.0F;
            rtb_Divide_ox = 0.0F;
            rtb_u_b = 1.0F;
          }

          /* End of Switch: '<S459>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S467>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_ic = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_P_ap[0] = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Sign5_i = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
          rtb_P_ap[1] = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S521>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S467>/Sum1'
           */
          rtb_Divide_c14[0] = rtb_Sign5_i;
          rtb_Divide_c14[1] = rtb_Divide_ic;

          /* Math: '<S521>/Math Function' incorporates:
           *  Sum: '<S467>/Sum1'
           */
          rtb_Square_ds[0] = rtb_Sign5_i * rtb_Sign5_i;
          rtb_Square_ds[1] = rtb_Divide_ic * rtb_Divide_ic;

          /* Sum: '<S521>/Sum of Elements' */
          rtb_Saturation1_d = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S521>/Math Function1' incorporates:
           *  Sum: '<S521>/Sum of Elements'
           *
           * About '<S521>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S521>/Math Function1' */

          /* Switch: '<S521>/Switch' incorporates:
           *  Constant: '<S521>/Constant'
           *  Product: '<S521>/Product'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_af = rtb_Divide_lr_idx_2;
          } else {
            rtb_Sign5_i = 0.0F;
            rtb_Divide_ic = 0.0F;
            rtb_Sign5_af = 1.0F;
          }

          /* End of Switch: '<S521>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S465>/NearbyRefWP' incorporates:
           *  Constant: '<S441>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_c14, &d);

          /* MATLAB Function: '<S465>/SearchL1RefWP' incorporates:
           *  Constant: '<S441>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_ap, &rtb_Saturation1_d);

          /* MATLAB Function: '<S465>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ov[0], &rtb_MatrixConcatenate3[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S465>/Switch1' incorporates:
           *  Constant: '<S502>/Constant'
           *  RelationalOperator: '<S502>/Compare'
           */
          if (d > 0.0F) {
            rtb_P_ap[0] = rtb_Divide_c14[0];
            rtb_P_ap[1] = rtb_Divide_c14[1];
          } else {
            /* RelationalOperator: '<S501>/Compare' incorporates:
             *  Constant: '<S501>/Constant'
             */
            rtb_Compare_aij = (rtb_Saturation1_d >= 0.0F);

            /* Switch: '<S465>/Switch' */
            if (!rtb_Compare_aij) {
              rtb_P_ap[0] = rtb_Square_ds[0];
              rtb_P_ap[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S465>/Switch' */
          }

          /* End of Switch: '<S465>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S466>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rtb_P_ap[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_ap[0] = rtb_a_bx;
          rtb_Divide_lr_idx_2 = rtb_a_bx * rtb_a_bx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S466>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S510>/Math Function'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_a_bx = rtb_P_ap[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S510>/Sum of Elements' incorporates:
           *  Math: '<S510>/Math Function'
           *  Sum: '<S508>/Sum of Elements'
           */
          rtb_Saturation1_d = rtb_Divide_lr_idx_2 + rtb_a_bx * rtb_a_bx;

          /* Math: '<S510>/Math Function1' incorporates:
           *  Sum: '<S510>/Sum of Elements'
           *
           * About '<S510>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Saturation1_d));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation1_d);
          }

          /* End of Math: '<S510>/Math Function1' */

          /* Switch: '<S510>/Switch' incorporates:
           *  Constant: '<S510>/Constant'
           *  Product: '<S510>/Product'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_P_ap[0];
            rtb_MatrixConcatenate3[1] = rtb_a_bx;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_2;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S510>/Switch' */

          /* Product: '<S509>/Divide' */
          rtb_Divide_c14[0] = rtb_P_f_idx_0 / rtb_Integrator1_bx;
          rtb_Divide_c14[1] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Sum: '<S512>/Sum of Elements' incorporates:
           *  Math: '<S512>/Math Function'
           *  SignalConversion: '<S512>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_c14[1] * rtb_Divide_c14[1] +
            rtb_Divide_c14[0] * rtb_Divide_c14[0];

          /* Math: '<S512>/Math Function1' incorporates:
           *  Sum: '<S512>/Sum of Elements'
           *
           * About '<S512>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_2));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Divide_lr_idx_2);
          }

          /* End of Math: '<S512>/Math Function1' */

          /* Switch: '<S512>/Switch' incorporates:
           *  Constant: '<S512>/Constant'
           *  Product: '<S512>/Product'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_P_f_idx_0 = rtb_Divide_c14[1];
            rtb_Saturation_ga = rtb_Divide_c14[0];
            rtb_Integrator1_bx = rtb_Divide_lr_idx_2;
          } else {
            rtb_P_f_idx_0 = 0.0F;
            rtb_Saturation_ga = 0.0F;
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S512>/Switch' */

          /* Product: '<S510>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Sum: '<S513>/Sum of Elements' incorporates:
           *  Math: '<S513>/Math Function'
           *  SignalConversion: '<S513>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_c14[1] * rtb_Divide_c14[1] +
            rtb_Divide_c14[0] * rtb_Divide_c14[0];

          /* Math: '<S513>/Math Function1' incorporates:
           *  Sum: '<S513>/Sum of Elements'
           *
           * About '<S513>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_2));
          } else {
            rtb_Divide_lr_idx_2 = sqrtf(rtb_Divide_lr_idx_2);
          }

          /* End of Math: '<S513>/Math Function1' */

          /* Switch: '<S513>/Switch' incorporates:
           *  Constant: '<S513>/Constant'
           *  Product: '<S513>/Product'
           */
          if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Divide_c14[1];
            rtb_MatrixConcatenate3[1] = rtb_Divide_c14[0];
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_2;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S513>/Switch' */

          /* Product: '<S513>/Divide' */
          rtb_Divide_c14[0] = rtb_MatrixConcatenate3[0] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S512>/Divide' */
          rtb_P_ap[0] = rtb_P_f_idx_0 / rtb_Integrator1_bx;

          /* Product: '<S521>/Divide' */
          rtb_Square_ds[0] = rtb_Sign5_i / rtb_Sign5_af;

          /* Product: '<S459>/Divide' */
          rtb_P_f_idx_0 = rtb_Divide_e / rtb_u_b;

          /* Product: '<S520>/Divide' */
          rtb_a_bx = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S513>/Divide' */
          rtb_Divide_c14[1] = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];

          /* Product: '<S512>/Divide' */
          rtb_P_ap[1] = rtb_Saturation_ga / rtb_Integrator1_bx;

          /* Product: '<S521>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_ic / rtb_Sign5_af;

          /* Product: '<S459>/Divide' */
          rtb_Saturation_ga = rtb_Divide_ox / rtb_u_b;

          /* Product: '<S520>/Divide' */
          rtb_Integrator1_bx = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S519>/Subtract' incorporates:
           *  Product: '<S519>/Multiply'
           *  Product: '<S519>/Multiply1'
           */
          rtb_Divide_lr_idx_2 = rtb_Square_ds[0] * rtb_Integrator1_bx -
            rtb_Square_ds[1] * rtb_a_bx;

          /* Signum: '<S516>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S516>/Sign1' */

          /* Switch: '<S516>/Switch2' incorporates:
           *  Constant: '<S516>/Constant4'
           */
          if (rtb_Divide_lr_idx_2 == 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S516>/Switch2' */

          /* DotProduct: '<S516>/Dot Product' */
          rtb_Integrator1_bx = rtb_a_bx * rtb_Square_ds[0] + rtb_Integrator1_bx *
            rtb_Square_ds[1];

          /* Trigonometry: '<S516>/Acos' incorporates:
           *  DotProduct: '<S516>/Dot Product'
           */
          if (rtb_Integrator1_bx > 1.0F) {
            rtb_Integrator1_bx = 1.0F;
          } else {
            if (rtb_Integrator1_bx < -1.0F) {
              rtb_Integrator1_bx = -1.0F;
            }
          }

          /* Product: '<S516>/Multiply' incorporates:
           *  Trigonometry: '<S516>/Acos'
           */
          rtb_Divide_lr_idx_2 *= acosf(rtb_Integrator1_bx);

          /* Abs: '<S467>/Abs' */
          rtb_Divide_lr_idx_2 = fabsf(rtb_Divide_lr_idx_2);

          /* RelationalOperator: '<S514>/Compare' incorporates:
           *  Constant: '<S514>/Constant'
           *  Delay: '<S467>/Delay1'
           */
          FMS_DW.Delay1_DSTATE = (rtb_Divide_lr_idx_2 > 1.57079637F);

          /* Sum: '<S511>/Subtract' incorporates:
           *  Product: '<S511>/Multiply'
           *  Product: '<S511>/Multiply1'
           */
          rtb_Integrator1_bx = rtb_Divide_c14[0] * rtb_P_ap[1] - rtb_Divide_c14
            [1] * rtb_P_ap[0];

          /* Signum: '<S506>/Sign1' */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Integrator1_bx = -1.0F;
          } else {
            if (rtb_Integrator1_bx > 0.0F) {
              rtb_Integrator1_bx = 1.0F;
            }
          }

          /* End of Signum: '<S506>/Sign1' */

          /* Switch: '<S506>/Switch2' incorporates:
           *  Constant: '<S506>/Constant4'
           */
          if (rtb_Integrator1_bx == 0.0F) {
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S506>/Switch2' */

          /* DotProduct: '<S506>/Dot Product' */
          rtb_a_bx = rtb_P_ap[0] * rtb_Divide_c14[0] + rtb_P_ap[1] *
            rtb_Divide_c14[1];

          /* Trigonometry: '<S506>/Acos' incorporates:
           *  DotProduct: '<S506>/Dot Product'
           */
          if (rtb_a_bx > 1.0F) {
            rtb_a_bx = 1.0F;
          } else {
            if (rtb_a_bx < -1.0F) {
              rtb_a_bx = -1.0F;
            }
          }

          /* Product: '<S506>/Multiply' incorporates:
           *  Trigonometry: '<S506>/Acos'
           */
          rtb_Integrator1_bx *= acosf(rtb_a_bx);

          /* Saturate: '<S466>/Saturation' */
          if (rtb_Integrator1_bx > 1.57079637F) {
            rtb_Integrator1_bx = 1.57079637F;
          } else {
            if (rtb_Integrator1_bx < -1.57079637F) {
              rtb_Integrator1_bx = -1.57079637F;
            }
          }

          /* End of Saturate: '<S466>/Saturation' */

          /* Trigonometry: '<S466>/Sin' */
          rtb_Divide_ox = arm_sin_f32(rtb_Integrator1_bx);

          /* Sum: '<S457>/Subtract' incorporates:
           *  Product: '<S457>/Multiply'
           *  Product: '<S457>/Multiply1'
           */
          rtb_Integrator1_bx = rtb_P_f_idx_0 * FMS_ConstB.Divide[1] -
            rtb_Saturation_ga * FMS_ConstB.Divide[0];

          /* Signum: '<S446>/Sign1' */
          if (rtb_Integrator1_bx < 0.0F) {
            rtb_Integrator1_bx = -1.0F;
          } else {
            if (rtb_Integrator1_bx > 0.0F) {
              rtb_Integrator1_bx = 1.0F;
            }
          }

          /* End of Signum: '<S446>/Sign1' */

          /* Switch: '<S446>/Switch2' incorporates:
           *  Constant: '<S446>/Constant4'
           */
          if (rtb_Integrator1_bx == 0.0F) {
            rtb_Integrator1_bx = 1.0F;
          }

          /* End of Switch: '<S446>/Switch2' */

          /* DotProduct: '<S446>/Dot Product' */
          rtb_a_bx = FMS_ConstB.Divide[0] * rtb_P_f_idx_0 + FMS_ConstB.Divide[1]
            * rtb_Saturation_ga;

          /* Trigonometry: '<S446>/Acos' incorporates:
           *  DotProduct: '<S446>/Dot Product'
           */
          if (rtb_a_bx > 1.0F) {
            rtb_a_bx = 1.0F;
          } else {
            if (rtb_a_bx < -1.0F) {
              rtb_a_bx = -1.0F;
            }
          }

          /* Product: '<S446>/Multiply' incorporates:
           *  Trigonometry: '<S446>/Acos'
           */
          rtb_Integrator1_bx *= acosf(rtb_a_bx);

          /* Math: '<S449>/Rem' incorporates:
           *  Constant: '<S449>/Constant1'
           *  Delay: '<S445>/Delay'
           *  Sum: '<S445>/Sum2'
           */
          rtb_Divide_lr_idx_2 = rt_remf(rtb_Integrator1_bx -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S449>/Switch' incorporates:
           *  Abs: '<S449>/Abs'
           *  Constant: '<S449>/Constant'
           *  Constant: '<S455>/Constant'
           *  Product: '<S449>/Multiply'
           *  RelationalOperator: '<S455>/Compare'
           *  Sum: '<S449>/Add'
           */
          if (fabsf(rtb_Divide_lr_idx_2) > 3.14159274F) {
            /* Signum: '<S449>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Divide_lr_idx_2;
            }

            /* End of Signum: '<S449>/Sign' */
            rtb_Divide_lr_idx_2 -= 6.28318548F * rtb_Saturation_ga;
          }

          /* End of Switch: '<S449>/Switch' */

          /* Sum: '<S445>/Sum' incorporates:
           *  Delay: '<S445>/Delay'
           */
          rtb_Saturation_ga = rtb_Divide_lr_idx_2 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S454>/Multiply1' incorporates:
           *  Constant: '<S454>/const1'
           *  DiscreteIntegrator: '<S448>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S454>/Add' incorporates:
           *  DiscreteIntegrator: '<S448>/Integrator1'
           *  Sum: '<S448>/Subtract'
           */
          rtb_P_f_idx_0 = (FMS_DW.Integrator1_DSTATE_mf - rtb_Saturation_ga) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S454>/Sign' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else if (rtb_P_f_idx_0 > 0.0F) {
            rtb_Saturation_ga = 1.0F;
          } else {
            rtb_Saturation_ga = rtb_P_f_idx_0;
          }

          /* End of Signum: '<S454>/Sign' */

          /* Sum: '<S454>/Add2' incorporates:
           *  Abs: '<S454>/Abs'
           *  Gain: '<S454>/Gain'
           *  Gain: '<S454>/Gain1'
           *  Product: '<S454>/Multiply2'
           *  Product: '<S454>/Multiply3'
           *  Sqrt: '<S454>/Sqrt'
           *  Sum: '<S454>/Add1'
           *  Sum: '<S454>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_P_f_idx_0) + FMS_ConstB.d_m) *
                     FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Saturation_ga + rtb_Divide_lr_idx_2;

          /* Sum: '<S454>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_P_f_idx_0 - d;

          /* Sum: '<S454>/Add3' */
          rtb_Saturation_ga = rtb_P_f_idx_0 + FMS_ConstB.d_m;

          /* Sum: '<S454>/Subtract1' */
          rtb_P_f_idx_0 -= FMS_ConstB.d_m;

          /* Signum: '<S454>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S454>/Sign1' */

          /* Signum: '<S454>/Sign2' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S454>/Sign2' */

          /* Sum: '<S454>/Add5' incorporates:
           *  Gain: '<S454>/Gain2'
           *  Product: '<S454>/Multiply4'
           *  Sum: '<S454>/Subtract2'
           */
          d += (rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F * rtb_Divide_lr_idx_2;

          /* Sum: '<S454>/Add6' */
          rtb_Saturation_ga = d + FMS_ConstB.d_m;

          /* Sum: '<S454>/Subtract3' */
          rtb_P_f_idx_0 = d - FMS_ConstB.d_m;

          /* Product: '<S454>/Divide' */
          rtb_u_b = d / FMS_ConstB.d_m;

          /* Signum: '<S454>/Sign5' incorporates:
           *  Signum: '<S454>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_ic = -1.0F;

            /* Signum: '<S454>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_ic = 1.0F;

            /* Signum: '<S454>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_ic = d;

            /* Signum: '<S454>/Sign6' */
            rtb_Divide_lr_idx_2 = d;
          }

          /* End of Signum: '<S454>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S445>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S43>/Signal Copy1'
           */
          rtb_Integrator1_bx -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S450>/Rem' incorporates:
           *  Constant: '<S450>/Constant1'
           */
          d = rt_remf(rtb_Integrator1_bx, 6.28318548F);

          /* Switch: '<S450>/Switch' incorporates:
           *  Abs: '<S450>/Abs'
           *  Constant: '<S450>/Constant'
           *  Constant: '<S456>/Constant'
           *  Product: '<S450>/Multiply'
           *  RelationalOperator: '<S456>/Compare'
           *  Sum: '<S450>/Add'
           */
          if (fabsf(d) > 3.14159274F) {
            /* Signum: '<S450>/Sign' */
            if (d < 0.0F) {
              rtb_Integrator1_bx = -1.0F;
            } else if (d > 0.0F) {
              rtb_Integrator1_bx = 1.0F;
            } else {
              rtb_Integrator1_bx = d;
            }

            /* End of Signum: '<S450>/Sign' */
            d -= 6.28318548F * rtb_Integrator1_bx;
          }

          /* End of Switch: '<S450>/Switch' */

          /* Abs: '<S443>/Abs' */
          d = fabsf(d);

          /* Update for DiscreteIntegrator: '<S468>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S461>/Constant'
           *  RelationalOperator: '<S461>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(d <=
            0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S468>/Discrete-Time Integrator' */

          /* Update for Delay: '<S467>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S463>/Acceleration_Speed' incorporates:
           *  Constant: '<S463>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_o3;

          /* Product: '<S467>/Divide1' incorporates:
           *  Constant: '<S441>/L1'
           *  Constant: '<S466>/Constant'
           *  Gain: '<S466>/Gain'
           *  Math: '<S466>/Square'
           *  MinMax: '<S466>/Max'
           *  MinMax: '<S466>/Min'
           *  Product: '<S466>/Divide'
           *  Product: '<S466>/Multiply1'
           *  Sqrt: '<S508>/Sqrt'
           */
          rtb_a_bx = rtb_Divide_ox * (rtb_Saturation1_p5 * rtb_Saturation1_p5 *
            2.0F) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation1_d), 0.5F)) /
            rtb_Divide_lr_idx_3;

          /* Saturate: '<S467>/Saturation' */
          if (rtb_a_bx > 0.314159274F) {
            rtb_a_bx = 0.314159274F;
          } else {
            if (rtb_a_bx < -0.314159274F) {
              rtb_a_bx = -0.314159274F;
            }
          }

          /* End of Saturate: '<S467>/Saturation' */

          /* Update for DiscreteIntegrator: '<S517>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_a_bx;
          FMS_DW.DiscreteTimeIntegrator_PrevRe_i = (int8_T)rtb_LogicalOperator_e;

          /* Update for Delay: '<S445>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S448>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S448>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S454>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S454>/Sign3' */

          /* Signum: '<S454>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S454>/Sign4' */

          /* Update for DiscreteIntegrator: '<S448>/Integrator' incorporates:
           *  Constant: '<S454>/const'
           *  Gain: '<S454>/Gain3'
           *  Product: '<S454>/Multiply5'
           *  Product: '<S454>/Multiply6'
           *  Sum: '<S454>/Subtract4'
           *  Sum: '<S454>/Subtract5'
           *  Sum: '<S454>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_u_b - rtb_Divide_ic) *
            FMS_ConstB.Gain4_cu * ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) -
            rtb_Divide_lr_idx_2 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S448>/Integrator' */
          /* End of Outputs for SubSystem: '<S437>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S440>/Delay Input1' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S440>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S326>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S326>/Unknown' incorporates:
           *  ActionPort: '<S439>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S326>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S50>/Assist' incorporates:
         *  ActionPort: '<S325>/Action Port'
         */
        /* SwitchCase: '<S325>/Switch Case' */
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
            /* Disable for SwitchCase: '<S424>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S340>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S358>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S374>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S399>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S386>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S325>/Acro' incorporates:
           *  ActionPort: '<S330>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S330>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S330>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S330>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Gain: '<S335>/Gain'
           *  Gain: '<S335>/Gain1'
           *  Gain: '<S335>/Gain2'
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

          /* Saturate: '<S336>/Saturation' incorporates:
           *  Constant: '<S336>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  Sum: '<S336>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_Saturation1_d = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S336>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S330>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S336>/Constant5'
           *  Gain: '<S336>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S336>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Saturation1_d), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S325>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S325>/Stabilize' incorporates:
             *  ActionPort: '<S333>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S325>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S420>/Integrator'
             *  DiscreteIntegrator: '<S420>/Integrator1'
             *  DiscreteIntegrator: '<S421>/Integrator'
             *  DiscreteIntegrator: '<S421>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S325>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S325>/Stabilize' incorporates:
             *  ActionPort: '<S333>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S325>/Switch Case' incorporates:
             *  Chart: '<S425>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S325>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S325>/Stabilize' incorporates:
           *  ActionPort: '<S333>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S415>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_Compare_o3 = !FMS_B.Compare;

          /* Chart: '<S425>/Motion State' incorporates:
           *  Abs: '<S425>/Abs'
           *  Abs: '<S425>/Abs1'
           *  Constant: '<S435>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S435>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S424>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S424>/Hold Control' incorporates:
               *  ActionPort: '<S427>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S424>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S424>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S424>/Hold Control' incorporates:
             *  ActionPort: '<S427>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S424>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S424>/Brake Control' incorporates:
             *  ActionPort: '<S426>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S424>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S424>/Move Control' incorporates:
               *  ActionPort: '<S428>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S424>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S424>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S424>/Move Control' incorporates:
             *  ActionPort: '<S428>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S424>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S424>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S417>/Switch' incorporates:
           *  Constant: '<S417>/Constant'
           *  Constant: '<S417>/Constant4'
           *  Constant: '<S417>/Constant5'
           *  Gain: '<S417>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S417>/Saturation'
           *  SignalConversion: '<S43>/Signal Copy2'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S417>/Add'
           *  Sum: '<S417>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S417>/Saturation' */
              rtb_Saturation1_d = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S417>/Saturation' */
              rtb_Saturation1_d = 0.0F;
            } else {
              /* Saturate: '<S417>/Saturation' incorporates:
               *  Constant: '<S417>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S43>/Signal Copy2'
               *  Sum: '<S417>/Sum'
               */
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              rtb_Saturation1_d), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S417>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S333>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S333>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S333>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S415>/Data Type Conversion'
           *  DiscreteIntegrator: '<S420>/Integrator1'
           *  DiscreteIntegrator: '<S421>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S415>/Multiply'
           *  Product: '<S415>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S424>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S333>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S333>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S333>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S424>/Saturation' */

          /* BusAssignment: '<S333>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S423>/Multiply1' incorporates:
           *  Constant: '<S423>/const1'
           *  DiscreteIntegrator: '<S421>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S419>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S419>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S423>/Add' incorporates:
           *  DiscreteIntegrator: '<S421>/Integrator1'
           *  Gain: '<S415>/Gain1'
           *  Gain: '<S419>/Gain'
           *  Sum: '<S421>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation1_d * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S423>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S423>/Sign' */

          /* Sum: '<S423>/Add2' incorporates:
           *  Abs: '<S423>/Abs'
           *  Gain: '<S423>/Gain'
           *  Gain: '<S423>/Gain1'
           *  Product: '<S423>/Multiply2'
           *  Product: '<S423>/Multiply3'
           *  Sqrt: '<S423>/Sqrt'
           *  Sum: '<S423>/Add1'
           *  Sum: '<S423>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Saturation1_p5;

          /* Sum: '<S423>/Add4' */
          rtb_Saturation1_p5 += rtb_Saturation1_d - rtb_Divide_lr_idx_3;

          /* Sum: '<S423>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_g;

          /* Sum: '<S423>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_g;

          /* Signum: '<S423>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S423>/Sign1' */

          /* Signum: '<S423>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S423>/Sign2' */

          /* Sum: '<S423>/Add5' incorporates:
           *  Gain: '<S423>/Gain2'
           *  Product: '<S423>/Multiply4'
           *  Sum: '<S423>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation1_p5;

          /* Sum: '<S423>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d_g;

          /* Sum: '<S423>/Subtract3' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_g;

          /* Product: '<S423>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_g;

          /* Signum: '<S423>/Sign5' incorporates:
           *  Signum: '<S423>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S423>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S423>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Integrator1_bx = rtb_Divide_lr_idx_3;

            /* Signum: '<S423>/Sign6' */
            rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S423>/Sign5' */

          /* Product: '<S422>/Multiply1' incorporates:
           *  Constant: '<S422>/const1'
           *  DiscreteIntegrator: '<S420>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S418>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S418>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S422>/Add' incorporates:
           *  DiscreteIntegrator: '<S420>/Integrator1'
           *  Gain: '<S415>/Gain'
           *  Gain: '<S418>/Gain'
           *  Sum: '<S420>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S422>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
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
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Saturation1_p5;

          /* Sum: '<S422>/Add4' */
          rtb_a_bx = (rtb_Saturation1_d - rtb_Divide_lr_idx_3) +
            rtb_Saturation1_p5;

          /* Sum: '<S422>/Add3' */
          rtb_Saturation1_p5 = rtb_Saturation1_d + FMS_ConstB.d_a;

          /* Sum: '<S422>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_a;

          /* Signum: '<S422>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign1' */

          /* Signum: '<S422>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign2' */

          /* Sum: '<S422>/Add5' incorporates:
           *  Gain: '<S422>/Gain2'
           *  Product: '<S422>/Multiply4'
           *  Sum: '<S422>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Saturation1_p5 - rtb_Saturation1_d) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S420>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S420>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S421>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S421>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S423>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S423>/Sign3' */

          /* Signum: '<S423>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S423>/Sign4' */

          /* Update for DiscreteIntegrator: '<S421>/Integrator' incorporates:
           *  Constant: '<S423>/const'
           *  Gain: '<S423>/Gain3'
           *  Product: '<S423>/Multiply5'
           *  Product: '<S423>/Multiply6'
           *  Sum: '<S423>/Subtract4'
           *  Sum: '<S423>/Subtract5'
           *  Sum: '<S423>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((d - rtb_Integrator1_bx) *
            FMS_ConstB.Gain4_o * ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) -
            rtb_Divide_lr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S422>/Subtract3' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_3 - FMS_ConstB.d_a;

          /* Sum: '<S422>/Add6' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_a;

          /* Signum: '<S422>/Sign5' incorporates:
           *  Signum: '<S422>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S422>/Sign6' */
            d = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S422>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S422>/Sign6' */
            d = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S422>/Sign5' */

          /* Signum: '<S422>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign3' */

          /* Signum: '<S422>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign4' */

          /* Update for DiscreteIntegrator: '<S420>/Integrator' incorporates:
           *  Constant: '<S422>/const'
           *  Gain: '<S422>/Gain3'
           *  Product: '<S422>/Divide'
           *  Product: '<S422>/Multiply5'
           *  Product: '<S422>/Multiply6'
           *  Sum: '<S422>/Subtract4'
           *  Sum: '<S422>/Subtract5'
           *  Sum: '<S422>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_a -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_k * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S325>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S325>/Altitude' incorporates:
             *  ActionPort: '<S331>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S325>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S354>/Integrator'
             *  DiscreteIntegrator: '<S354>/Integrator1'
             *  DiscreteIntegrator: '<S355>/Integrator'
             *  DiscreteIntegrator: '<S355>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S325>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S325>/Altitude' incorporates:
             *  ActionPort: '<S331>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S325>/Switch Case' incorporates:
             *  Chart: '<S341>/Motion Status'
             *  Chart: '<S359>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S325>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S325>/Altitude' incorporates:
           *  ActionPort: '<S331>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S341>/Motion Status' incorporates:
           *  Abs: '<S341>/Abs'
           *  Abs: '<S341>/Abs1'
           *  Constant: '<S350>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S350>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S340>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S340>/Hold Control' incorporates:
               *  ActionPort: '<S343>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S340>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S340>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S340>/Hold Control' incorporates:
             *  ActionPort: '<S343>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S340>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S340>/Brake Control' incorporates:
             *  ActionPort: '<S342>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S340>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S340>/Move Control' incorporates:
             *  ActionPort: '<S344>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S340>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S340>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S337>/Switch' incorporates:
           *  Constant: '<S337>/Constant'
           *  Saturate: '<S340>/Saturation1'
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Saturation_ga = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S340>/Saturation1' */
            rtb_Saturation_ga = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S340>/Saturation1' */
            rtb_Saturation_ga = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S340>/Saturation1' */
            rtb_Saturation_ga = FMS_B.Merge_l;
          }

          /* End of Switch: '<S337>/Switch' */

          /* Logic: '<S338>/Logical Operator' incorporates:
           *  SignalConversion: '<S43>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_Compare_o3 = !FMS_B.Compare;

          /* Chart: '<S359>/Motion State' incorporates:
           *  Abs: '<S359>/Abs'
           *  Abs: '<S359>/Abs1'
           *  Constant: '<S369>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S369>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S358>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S358>/Hold Control' incorporates:
               *  ActionPort: '<S361>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S358>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_pi);

              /* End of SystemReset for SubSystem: '<S358>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S358>/Hold Control' incorporates:
             *  ActionPort: '<S361>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_pi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S358>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S358>/Brake Control' incorporates:
             *  ActionPort: '<S360>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S358>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S358>/Move Control' incorporates:
               *  ActionPort: '<S362>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S358>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S358>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S358>/Move Control' incorporates:
             *  ActionPort: '<S362>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S358>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S358>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S331>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S331>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S331>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  DataTypeConversion: '<S338>/Data Type Conversion'
           *  DiscreteIntegrator: '<S354>/Integrator1'
           *  DiscreteIntegrator: '<S355>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S338>/Multiply'
           *  Product: '<S338>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_Compare_o3 *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S358>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S331>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
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
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S358>/Saturation' */

          /* BusAssignment: '<S331>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_ga;

          /* Product: '<S357>/Multiply1' incorporates:
           *  Constant: '<S357>/const1'
           *  DiscreteIntegrator: '<S355>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S353>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S353>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S357>/Add' incorporates:
           *  DiscreteIntegrator: '<S355>/Integrator1'
           *  Gain: '<S338>/Gain1'
           *  Gain: '<S353>/Gain'
           *  Sum: '<S355>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation1_d * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Saturation1_p5;

          /* Signum: '<S357>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
          }

          /* End of Signum: '<S357>/Sign' */

          /* Sum: '<S357>/Add2' incorporates:
           *  Abs: '<S357>/Abs'
           *  Gain: '<S357>/Gain'
           *  Gain: '<S357>/Gain1'
           *  Product: '<S357>/Multiply2'
           *  Product: '<S357>/Multiply3'
           *  Sqrt: '<S357>/Sqrt'
           *  Sum: '<S357>/Add1'
           *  Sum: '<S357>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Saturation1_p5;

          /* Sum: '<S357>/Add4' */
          rtb_Saturation1_p5 += rtb_Saturation1_d - rtb_Divide_lr_idx_3;

          /* Sum: '<S357>/Add3' */
          rtb_Saturation_ga = rtb_Saturation1_d + FMS_ConstB.d_o;

          /* Sum: '<S357>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_o;

          /* Signum: '<S357>/Sign1' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S357>/Sign1' */

          /* Signum: '<S357>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S357>/Sign2' */

          /* Sum: '<S357>/Add5' incorporates:
           *  Gain: '<S357>/Gain2'
           *  Product: '<S357>/Multiply4'
           *  Sum: '<S357>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Saturation_ga - rtb_Saturation1_d) * 0.5F *
            rtb_Saturation1_p5;

          /* Sum: '<S357>/Add6' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_3 + FMS_ConstB.d_o;

          /* Sum: '<S357>/Subtract3' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_o;

          /* Product: '<S357>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_o;

          /* Signum: '<S357>/Sign5' incorporates:
           *  Signum: '<S357>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Integrator1_bx = -1.0F;

            /* Signum: '<S357>/Sign6' */
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Integrator1_bx = 1.0F;

            /* Signum: '<S357>/Sign6' */
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Integrator1_bx = rtb_Divide_lr_idx_3;

            /* Signum: '<S357>/Sign6' */
            rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S357>/Sign5' */

          /* Product: '<S356>/Multiply1' incorporates:
           *  Constant: '<S356>/const1'
           *  DiscreteIntegrator: '<S354>/Integrator'
           */
          rtb_Saturation1_p5 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S352>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation1_d = 0.0F;
          } else {
            rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S352>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S356>/Add' incorporates:
           *  DiscreteIntegrator: '<S354>/Integrator1'
           *  Gain: '<S338>/Gain'
           *  Gain: '<S352>/Gain'
           *  Sum: '<S354>/Subtract'
           */
          rtb_Saturation1_d = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation1_d * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Saturation1_p5;

          /* Signum: '<S356>/Sign' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation1_d > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation1_d;
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
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation1_d) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Saturation1_p5;

          /* Sum: '<S356>/Add4' */
          rtb_a_bx = (rtb_Saturation1_d - rtb_Divide_lr_idx_3) +
            rtb_Saturation1_p5;

          /* Sum: '<S356>/Add3' */
          rtb_Saturation1_p5 = rtb_Saturation1_d + FMS_ConstB.d_c;

          /* Sum: '<S356>/Subtract1' */
          rtb_Saturation1_d -= FMS_ConstB.d_c;

          /* Signum: '<S356>/Sign1' */
          if (rtb_Saturation1_p5 < 0.0F) {
            rtb_Saturation1_p5 = -1.0F;
          } else {
            if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign1' */

          /* Signum: '<S356>/Sign2' */
          if (rtb_Saturation1_d < 0.0F) {
            rtb_Saturation1_d = -1.0F;
          } else {
            if (rtb_Saturation1_d > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign2' */

          /* Sum: '<S356>/Add5' incorporates:
           *  Gain: '<S356>/Gain2'
           *  Product: '<S356>/Multiply4'
           *  Sum: '<S356>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Saturation1_p5 - rtb_Saturation1_d) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S354>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S354>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S355>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S355>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S357>/Sign3' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S357>/Sign3' */

          /* Signum: '<S357>/Sign4' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S357>/Sign4' */

          /* Update for DiscreteIntegrator: '<S355>/Integrator' incorporates:
           *  Constant: '<S357>/const'
           *  Gain: '<S357>/Gain3'
           *  Product: '<S357>/Multiply5'
           *  Product: '<S357>/Multiply6'
           *  Sum: '<S357>/Subtract4'
           *  Sum: '<S357>/Subtract5'
           *  Sum: '<S357>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((d - rtb_Integrator1_bx) *
            FMS_ConstB.Gain4_c * ((rtb_Saturation_ga - rtb_P_f_idx_0) * 0.5F) -
            rtb_Divide_lr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S356>/Subtract3' */
          rtb_Saturation_ga = rtb_Divide_lr_idx_3 - FMS_ConstB.d_c;

          /* Sum: '<S356>/Add6' */
          rtb_P_f_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_c;

          /* Signum: '<S356>/Sign5' incorporates:
           *  Signum: '<S356>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;

            /* Signum: '<S356>/Sign6' */
            d = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;

            /* Signum: '<S356>/Sign6' */
            d = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S356>/Sign6' */
            d = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S356>/Sign5' */

          /* Signum: '<S356>/Sign3' */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_P_f_idx_0 = -1.0F;
          } else {
            if (rtb_P_f_idx_0 > 0.0F) {
              rtb_P_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign3' */

          /* Signum: '<S356>/Sign4' */
          if (rtb_Saturation_ga < 0.0F) {
            rtb_Saturation_ga = -1.0F;
          } else {
            if (rtb_Saturation_ga > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            }
          }

          /* End of Signum: '<S356>/Sign4' */

          /* Update for DiscreteIntegrator: '<S354>/Integrator' incorporates:
           *  Constant: '<S356>/const'
           *  Gain: '<S356>/Gain3'
           *  Product: '<S356>/Divide'
           *  Product: '<S356>/Multiply5'
           *  Product: '<S356>/Multiply6'
           *  Sum: '<S356>/Subtract4'
           *  Sum: '<S356>/Subtract5'
           *  Sum: '<S356>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_c -
            rtb_Divide_lr_idx_2) * FMS_ConstB.Gain4_h * ((rtb_P_f_idx_0 -
            rtb_Saturation_ga) * 0.5F) - d * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S325>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S325>/Position' incorporates:
             *  ActionPort: '<S332>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S325>/Switch Case' incorporates:
             *  Chart: '<S375>/Motion Status'
             *  Chart: '<S387>/Motion State'
             *  Chart: '<S400>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S325>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S325>/Position' incorporates:
           *  ActionPort: '<S332>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S375>/Motion Status' incorporates:
           *  Abs: '<S375>/Abs'
           *  Abs: '<S375>/Abs1'
           *  Constant: '<S384>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S384>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_ej, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S374>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S374>/Hold Control' incorporates:
               *  ActionPort: '<S377>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S374>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S374>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S374>/Hold Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S374>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S374>/Brake Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S374>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S374>/Move Control' incorporates:
             *  ActionPort: '<S378>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S374>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S374>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S387>/Motion State' incorporates:
           *  Abs: '<S387>/Abs'
           *  Abs: '<S387>/Abs1'
           *  Constant: '<S397>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S397>/Compare'
           *  SignalConversion: '<S43>/Signal Copy1'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_ej,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S400>/Logical Operator' incorporates:
           *  Abs: '<S400>/Abs1'
           *  Abs: '<S400>/Abs2'
           *  Constant: '<S412>/Constant'
           *  Constant: '<S413>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S412>/Compare'
           *  RelationalOperator: '<S413>/Compare'
           *  SignalConversion: '<S43>/Signal Copy2'
           */
          rtb_Compare_o3 = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                             FMS_PARAM.PITCH_DZ) || (fabsf
            (FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S400>/Motion State' */
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

          /* End of Chart: '<S400>/Motion State' */

          /* SwitchCase: '<S399>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S399>/Hold Control' incorporates:
               *  ActionPort: '<S401>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S399>/Switch Case' incorporates:
               *  Delay: '<S401>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S399>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S399>/Hold Control' incorporates:
             *  ActionPort: '<S401>/Action Port'
             */
            /* Delay: '<S401>/Delay' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             */
            if (FMS_DW.icLoad != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Trigonometry: '<S405>/Trigonometric Function1' */
            rtb_VectorConcatenate_or[0] = rtb_Saturation_ga;

            /* Trigonometry: '<S405>/Trigonometric Function' */
            rtb_VectorConcatenate_or[1] = rtb_P_f_idx_0;

            /* SignalConversion: '<S405>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S405>/Constant3'
             */
            rtb_VectorConcatenate_or[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S405>/Gain' incorporates:
             *  Gain: '<S404>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Trigonometry: '<S405>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_or[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S405>/Trigonometric Function3' */
            rtb_VectorConcatenate_or[4] = rtb_Saturation_ga;

            /* SignalConversion: '<S405>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S405>/Constant4'
             */
            rtb_VectorConcatenate_or[5] = 0.0F;

            /* SignalConversion: '<S405>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_or[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate_or[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate_or[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S401>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S401>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S43>/Signal Copy1'
             *  Sum: '<S401>/Sum'
             */
            rtb_Saturation1_p5 = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Integrator1_bx = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S401>/Multiply' incorporates:
             *  SignalConversion: '<S401>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_MatrixConcatenate1_0[rtb_n] = rtb_VectorConcatenate_or[rtb_n +
                3] * rtb_Integrator1_bx + rtb_VectorConcatenate_or[rtb_n] *
                rtb_Saturation1_p5;
            }

            /* End of Product: '<S401>/Multiply' */

            /* Gain: '<S401>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate1_0[1];

            /* Update for Delay: '<S401>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S399>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S399>/Move Control' incorporates:
               *  ActionPort: '<S402>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S399>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S408>/Integrator'
               *  DiscreteIntegrator: '<S408>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S399>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S399>/Move Control' incorporates:
             *  ActionPort: '<S402>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S406>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S406>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S406>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
              rtb_Saturation1_d;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S407>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S43>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation1_d = 0.0F;
            } else {
              rtb_Saturation1_d = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S407>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S407>/Gain' */
            rtb_Divide_lr_idx_3 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation1_d;

            /* Sum: '<S409>/Sum of Elements' incorporates:
             *  Math: '<S409>/Square'
             *  SignalConversion: '<S409>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S410>/Sum of Elements'
             *  Switch: '<S402>/Switch'
             */
            rtb_Saturation1_d = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 +
              rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

            /* Switch: '<S402>/Switch' incorporates:
             *  Product: '<S410>/Divide'
             *  Sqrt: '<S409>/Sqrt'
             *  Sum: '<S409>/Sum of Elements'
             */
            if (sqrtf(rtb_Saturation1_d) > 1.0F) {
              /* Math: '<S410>/Math Function1'
               *
               * About '<S410>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Saturation1_d < 0.0F) {
                rtb_Saturation_ga = -sqrtf(fabsf(rtb_Saturation1_d));
              } else {
                rtb_Saturation_ga = sqrtf(rtb_Saturation1_d);
              }

              /* End of Math: '<S410>/Math Function1' */

              /* Switch: '<S410>/Switch' incorporates:
               *  Constant: '<S410>/Constant'
               *  Product: '<S410>/Product'
               */
              if (rtb_Saturation_ga > 0.0F) {
                rtb_MatrixConcatenate3[0] = rtb_Divide_lr_idx_2;
                rtb_MatrixConcatenate3[1] = rtb_Divide_lr_idx_3;
                rtb_MatrixConcatenate3[2] = rtb_Saturation_ga;
              } else {
                rtb_MatrixConcatenate3[0] = 0.0F;
                rtb_MatrixConcatenate3[1] = 0.0F;
                rtb_MatrixConcatenate3[2] = 1.0F;
              }

              /* End of Switch: '<S410>/Switch' */
              rtb_Divide_lr_idx_2 = rtb_MatrixConcatenate3[0] /
                rtb_MatrixConcatenate3[2];
              rtb_Divide_lr_idx_3 = rtb_MatrixConcatenate3[1] /
                rtb_MatrixConcatenate3[2];
            }

            /* Product: '<S411>/Multiply1' incorporates:
             *  Constant: '<S411>/const1'
             *  DiscreteIntegrator: '<S408>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S411>/Add' incorporates:
             *  DiscreteIntegrator: '<S408>/Integrator1'
             *  Gain: '<S402>/Gain6'
             *  Sum: '<S408>/Subtract'
             */
            rtb_Saturation1_p5 = (FMS_DW.Integrator1_DSTATE[0] -
                                  FMS_PARAM.VEL_XY_LIM * rtb_Divide_lr_idx_2) +
              rtb_Saturation1_d;

            /* Signum: '<S411>/Sign' */
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation1_p5;
            }

            /* Sum: '<S411>/Add2' incorporates:
             *  Abs: '<S411>/Abs'
             *  Gain: '<S411>/Gain'
             *  Gain: '<S411>/Gain1'
             *  Product: '<S411>/Multiply2'
             *  Product: '<S411>/Multiply3'
             *  Sqrt: '<S411>/Sqrt'
             *  Sum: '<S411>/Add1'
             *  Sum: '<S411>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation1_p5) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S411>/Add4' */
            rtb_Saturation1_d += rtb_Saturation1_p5 - rtb_Divide_lr_idx_2;

            /* Sum: '<S411>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d;

            /* Sum: '<S411>/Subtract1' */
            rtb_Saturation1_p5 -= FMS_ConstB.d;

            /* Signum: '<S411>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S411>/Sign2' */
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation1_p5 = -1.0F;
            } else {
              if (rtb_Saturation1_p5 > 0.0F) {
                rtb_Saturation1_p5 = 1.0F;
              }
            }

            /* Sum: '<S411>/Add5' incorporates:
             *  Gain: '<S411>/Gain2'
             *  Product: '<S411>/Multiply4'
             *  Sum: '<S411>/Subtract2'
             */
            rtb_Divide_lr_idx_2 += (rtb_Saturation_ga - rtb_Saturation1_p5) *
              0.5F * rtb_Saturation1_d;

            /* SignalConversion: '<S408>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S408>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S408>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S408>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S411>/Sign4' incorporates:
             *  Sum: '<S411>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S411>/Sign3' incorporates:
             *  Sum: '<S411>/Add6'
             */
            rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S411>/Sign5' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Divide_lr_idx_2;
            }

            /* Signum: '<S411>/Sign3' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = -1.0F;
            } else {
              if (rtb_P_f_idx_0 > 0.0F) {
                rtb_P_f_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S411>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S411>/Sign6' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation1_p5 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            } else {
              rtb_Saturation1_p5 = rtb_Divide_lr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S408>/Integrator' incorporates:
             *  Constant: '<S411>/const'
             *  Gain: '<S411>/Gain3'
             *  Product: '<S411>/Divide'
             *  Product: '<S411>/Multiply5'
             *  Product: '<S411>/Multiply6'
             *  Sum: '<S411>/Subtract4'
             *  Sum: '<S411>/Subtract5'
             *  Sum: '<S411>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d
              - rtb_Saturation1_d) * FMS_ConstB.Gain4 * ((rtb_P_f_idx_0 -
              rtb_Saturation_ga) * 0.5F) - rtb_Saturation1_p5 * 39.224F) *
              0.004F;

            /* Product: '<S411>/Multiply1' incorporates:
             *  Constant: '<S411>/const1'
             *  DiscreteIntegrator: '<S408>/Integrator'
             */
            rtb_Saturation1_d = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S411>/Add' incorporates:
             *  DiscreteIntegrator: '<S408>/Integrator1'
             *  Gain: '<S402>/Gain6'
             *  Sum: '<S408>/Subtract'
             */
            rtb_Saturation1_p5 = (FMS_DW.Integrator1_DSTATE[1] -
                                  FMS_PARAM.VEL_XY_LIM * rtb_Divide_lr_idx_3) +
              rtb_Saturation1_d;

            /* Signum: '<S411>/Sign' */
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else if (rtb_Saturation1_p5 > 0.0F) {
              rtb_Saturation_ga = 1.0F;
            } else {
              rtb_Saturation_ga = rtb_Saturation1_p5;
            }

            /* Sum: '<S411>/Add2' incorporates:
             *  Abs: '<S411>/Abs'
             *  Gain: '<S411>/Gain'
             *  Gain: '<S411>/Gain1'
             *  Product: '<S411>/Multiply2'
             *  Product: '<S411>/Multiply3'
             *  Sqrt: '<S411>/Sqrt'
             *  Sum: '<S411>/Add1'
             *  Sum: '<S411>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation1_p5) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Saturation_ga + rtb_Saturation1_d;

            /* Sum: '<S411>/Add4' */
            rtb_Saturation1_d += rtb_Saturation1_p5 - rtb_Divide_lr_idx_2;

            /* Sum: '<S411>/Add3' */
            rtb_Saturation_ga = rtb_Saturation1_p5 + FMS_ConstB.d;

            /* Sum: '<S411>/Subtract1' */
            rtb_Saturation1_p5 -= FMS_ConstB.d;

            /* Signum: '<S411>/Sign1' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S411>/Sign2' */
            if (rtb_Saturation1_p5 < 0.0F) {
              rtb_Saturation1_p5 = -1.0F;
            } else {
              if (rtb_Saturation1_p5 > 0.0F) {
                rtb_Saturation1_p5 = 1.0F;
              }
            }

            /* Sum: '<S411>/Add5' incorporates:
             *  Gain: '<S411>/Gain2'
             *  Product: '<S411>/Multiply4'
             *  Sum: '<S411>/Subtract2'
             */
            rtb_Divide_lr_idx_2 += (rtb_Saturation_ga - rtb_Saturation1_p5) *
              0.5F * rtb_Saturation1_d;

            /* SignalConversion: '<S408>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S408>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S408>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S408>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S411>/Sign4' incorporates:
             *  Sum: '<S411>/Subtract3'
             */
            rtb_Saturation_ga = rtb_Divide_lr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S411>/Sign3' incorporates:
             *  Sum: '<S411>/Add6'
             */
            rtb_P_f_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S411>/Sign5' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation1_d = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation1_d = 1.0F;
            } else {
              rtb_Saturation1_d = rtb_Divide_lr_idx_2;
            }

            /* Signum: '<S411>/Sign3' */
            if (rtb_P_f_idx_0 < 0.0F) {
              rtb_P_f_idx_0 = -1.0F;
            } else {
              if (rtb_P_f_idx_0 > 0.0F) {
                rtb_P_f_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S411>/Sign4' */
            if (rtb_Saturation_ga < 0.0F) {
              rtb_Saturation_ga = -1.0F;
            } else {
              if (rtb_Saturation_ga > 0.0F) {
                rtb_Saturation_ga = 1.0F;
              }
            }

            /* Signum: '<S411>/Sign6' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Saturation1_p5 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Saturation1_p5 = 1.0F;
            } else {
              rtb_Saturation1_p5 = rtb_Divide_lr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S408>/Integrator' incorporates:
             *  Constant: '<S411>/const'
             *  Gain: '<S411>/Gain3'
             *  Product: '<S411>/Divide'
             *  Product: '<S411>/Multiply5'
             *  Product: '<S411>/Multiply6'
             *  Sum: '<S411>/Subtract4'
             *  Sum: '<S411>/Subtract5'
             *  Sum: '<S411>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d
              - rtb_Saturation1_d) * FMS_ConstB.Gain4 * ((rtb_P_f_idx_0 -
              rtb_Saturation_ga) * 0.5F) - rtb_Saturation1_p5 * 39.224F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S399>/Move Control' */
            break;
          }

          /* SwitchCase: '<S386>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S386>/Hold Control' incorporates:
               *  ActionPort: '<S389>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S386>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S386>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S386>/Hold Control' incorporates:
             *  ActionPort: '<S389>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S386>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S386>/Brake Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S386>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S386>/Move Control' incorporates:
               *  ActionPort: '<S390>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S386>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S386>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S386>/Move Control' incorporates:
             *  ActionPort: '<S390>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S386>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S386>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S332>/Bus Assignment'
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Constant: '<S332>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S386>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
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
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S386>/Saturation' */

          /* Saturate: '<S399>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S399>/Saturation1' */

          /* Saturate: '<S374>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S332>/Bus Assignment' incorporates:
             *  BusAssignment: '<S45>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S374>/Saturation1' */
          /* End of Outputs for SubSystem: '<S325>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S325>/Unknown' incorporates:
           *  ActionPort: '<S334>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S45>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S325>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S50>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S50>/Manual' incorporates:
         *  ActionPort: '<S327>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S327>/Bus Assignment'
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S327>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S327>/Bus Assignment' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S327>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S50>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S50>/Unknown' incorporates:
         *  ActionPort: '<S329>/Action Port'
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
   *  DiscreteIntegrator: '<S780>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S780>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S780>/Constant'
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

  /* Update for DiscreteIntegrator: '<S812>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S812>/Gain'
   *  Sum: '<S812>/Sum5'
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
  rtb_Saturation1_d = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation1_d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Saturation1_d;
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

  /* Update for DiscreteIntegrator: '<S814>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S814>/Gain'
   *  Sum: '<S814>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_L_af = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S813>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S813>/Gain'
   *  Sum: '<S813>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_lr_idx_0 -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_Saturation1_d = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_c +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation1_d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_c = (uint32_T)rtb_Saturation1_d;
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
  rtb_Saturation1_d = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation1_d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Saturation1_d;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* Update for Delay: '<S24>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;

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
  /* Start for SwitchCase: '<S328>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S328>/Return' */
  /* Start for SwitchCase: '<S733>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S723>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S328>/Return' */

  /* Start for IfAction SubSystem: '<S328>/Hold' */
  /* Start for SwitchCase: '<S672>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S640>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S651>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S328>/Hold' */
  /* End of Start for SubSystem: '<S50>/SubMode' */

  /* Start for IfAction SubSystem: '<S50>/Auto' */
  /* Start for SwitchCase: '<S326>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S326>/Mission' */
  /* Start for Resettable SubSystem: '<S437>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S488>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S478>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S437>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S326>/Mission' */
  /* End of Start for SubSystem: '<S50>/Auto' */

  /* Start for IfAction SubSystem: '<S50>/Assist' */
  /* Start for SwitchCase: '<S325>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S325>/Stabilize' */
  /* Start for SwitchCase: '<S424>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S325>/Stabilize' */

  /* Start for IfAction SubSystem: '<S325>/Altitude' */
  /* Start for SwitchCase: '<S340>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S358>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S325>/Altitude' */

  /* Start for IfAction SubSystem: '<S325>/Position' */
  /* Start for SwitchCase: '<S374>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S399>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S386>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S325>/Position' */
  /* End of Start for SubSystem: '<S50>/Assist' */
  /* End of Start for SubSystem: '<S44>/MC_Mode' */
  /* End of Start for SubSystem: '<S42>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = POS_ZCSIG;
  FMS_PrevZCX.Delay_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  FMS_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S812>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S814>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_L_af = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S813>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S268>/start_vel' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S263>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S112>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S49>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S110>/Mission' */
  /* InitializeConditions for UnitDelay: '<S227>/Delay Input1'
   *
   * Block description for '<S227>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S224>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S235>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_li = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S235>/Integrator' */
  FMS_DW.Integrator_DSTATE_fk = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S224>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S110>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S49>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S49>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S109>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S218>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_oo = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S222>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jv = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S222>/Integrator' */
  FMS_DW.Integrator_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S218>/Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator' */
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
  /* SystemInitialize for IfAction SubSystem: '<S328>/Takeoff' */
  /* InitializeConditions for Delay: '<S778>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S774>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S774>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S328>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S328>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S688>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S688>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S328>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S328>/Return' */
  /* InitializeConditions for DiscreteIntegrator: '<S719>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for Delay: '<S718>/Delay1' */
  FMS_DW.Delay1_DSTATE_a = false;

  /* InitializeConditions for Delay: '<S718>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S714>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S762>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_n = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_j = 0;

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

  /* End of SystemInitialize for SubSystem: '<S328>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S328>/Hold' */
  /* InitializeConditions for Delay: '<S653>/Delay' */
  FMS_DW.icLoad_nd = 1U;

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

  /* End of SystemInitialize for SubSystem: '<S328>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S50>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S326>/Mission' */
  /* InitializeConditions for UnitDelay: '<S440>/Delay Input1'
   *
   * Block description for '<S440>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S437>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S468>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for Delay: '<S467>/Delay1' */
  FMS_DW.Delay1_DSTATE = false;

  /* InitializeConditions for Delay: '<S467>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S463>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S517>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_i = 0;

  /* InitializeConditions for Delay: '<S445>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S489>/Motion State' */
  FMS_MotionState_c_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S488>/Hold Control' */
  FMS_HoldControl_l0_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S488>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S488>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S498>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S498>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S488>/Move Control' */

  /* SystemInitialize for Merge: '<S488>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S488>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S498>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S498>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S488>/Move Control' */

  /* SystemInitialize for Merge: '<S488>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S479>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S478>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S478>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S478>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S485>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S485>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S478>/Move Control' */

  /* SystemInitialize for Merge: '<S478>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S437>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S326>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S50>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S325>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S420>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S421>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S421>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S420>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S425>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S424>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S424>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S424>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S424>/Move Control' */

  /* SystemInitialize for Merge: '<S424>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S325>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S325>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S355>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S355>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S341>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S340>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S340>/Hold Control' */

  /* SystemInitialize for Merge: '<S340>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S359>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S358>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_pi);

  /* End of SystemInitialize for SubSystem: '<S358>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S358>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S358>/Move Control' */

  /* SystemInitialize for Merge: '<S358>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S325>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S325>/Position' */
  /* SystemInitialize for Chart: '<S375>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S374>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S374>/Hold Control' */

  /* SystemInitialize for Chart: '<S387>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S400>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S399>/Hold Control' */
  /* InitializeConditions for Delay: '<S401>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S399>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S399>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S408>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S408>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S399>/Move Control' */

  /* SystemInitialize for Merge: '<S399>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S399>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S408>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S408>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S399>/Move Control' */

  /* SystemInitialize for Merge: '<S399>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S374>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S386>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S386>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S386>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S386>/Move Control' */

  /* SystemInitialize for Merge: '<S386>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S325>/Position' */
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
