/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2002
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu May  4 12:14:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S40>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S75>/Motion State' */
#define FMS_IN_Brake_d                 ((uint8_T)1U)
#define FMS_IN_Hold_l                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)3U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)4U)
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
#define FMS_IN_Other                   ((uint8_T)5U)
#define FMS_IN_Position_f              ((uint8_T)6U)
#define FMS_IN_Stabilize_j             ((uint8_T)7U)

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
struct_LQbHTlAQVN7sVz7acpAn4 FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  2.5F,
  2.5F,
  1.04719806F,
  0.523599F,
  30.0F,
  13.0F,
  10.0F,
  55.0F,
  50.0F,
  1.0F,
  1.0F,
  1.0F,
  0.95F,
  8.0F,
  0.785398F,
  0.785398F,
  30.0F,

  { 1000.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1000.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S212>/Constant'
                                        *   '<S21>/Constant6'
                                        *   '<S22>/Constant6'
                                        *   '<S141>/Gain'
                                        *   '<S141>/Gain4'
                                        *   '<S141>/Gain5'
                                        *   '<S145>/Constant4'
                                        *   '<S146>/Constant4'
                                        *   '<S35>/Gain'
                                        *   '<S37>/Gain'
                                        *   '<S38>/Gain1'
                                        *   '<S56>/Gain'
                                        *   '<S58>/Gain1'
                                        *   '<S102>/Gain'
                                        *   '<S102>/Gain1'
                                        *   '<S103>/Gain1'
                                        *   '<S118>/Constant4'
                                        *   '<S148>/Gain2'
                                        *   '<S149>/L1'
                                        *   '<S149>/R'
                                        *   '<S166>/Gain'
                                        *   '<S166>/Saturation1'
                                        *   '<S188>/Gain'
                                        *   '<S188>/Saturation1'
                                        *   '<S39>/Saturation1'
                                        *   '<S50>/Dead Zone'
                                        *   '<S50>/Gain'
                                        *   '<S53>/Dead Zone'
                                        *   '<S53>/Gain'
                                        *   '<S60>/Saturation1'
                                        *   '<S71>/Dead Zone'
                                        *   '<S71>/Gain'
                                        *   '<S74>/Saturation1'
                                        *   '<S105>/Dead Zone'
                                        *   '<S105>/Gain'
                                        *   '<S106>/Dead Zone'
                                        *   '<S106>/Gain'
                                        *   '<S111>/Dead Zone'
                                        *   '<S111>/Gain'
                                        *   '<S119>/Gain'
                                        *   '<S119>/Saturation1'
                                        *   '<S171>/L1'
                                        *   '<S171>/Saturation1'
                                        *   '<S193>/L1'
                                        *   '<S193>/Saturation1'
                                        *   '<S42>/Gain2'
                                        *   '<S43>/Gain1'
                                        *   '<S48>/Constant'
                                        *   '<S63>/Gain2'
                                        *   '<S64>/Gain1'
                                        *   '<S69>/Constant'
                                        *   '<S77>/L1'
                                        *   '<S78>/Gain6'
                                        *   '<S98>/Constant'
                                        *   '<S124>/L1'
                                        *   '<S124>/Saturation1'
                                        *   '<S45>/Dead Zone'
                                        *   '<S45>/Gain'
                                        *   '<S66>/Dead Zone'
                                        *   '<S66>/Gain'
                                        *   '<S95>/Dead Zone'
                                        *   '<S95>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 70, 87, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 50, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S210>/Constant'
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
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_exit_internal_Auto(void);
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
 *    '<S195>/NearbyRefWP'
 *    '<S173>/NearbyRefWP'
 *    '<S126>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_i, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S199>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_i;
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
 *    '<S195>/OutRegionRegWP'
 *    '<S173>/OutRegionRegWP'
 *    '<S126>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_l, real32_T rty_P[2])
{
  real32_T u;
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S200>/TmpSignal ConversionAt SFunction Inport3' */
  P1P3_idx_0 = rtu_P3 - rtu_P1[0];
  P1P3_idx_1 = rtu_P3_l - rtu_P1[1];
  u_tmp = rty_P[0] * rty_P[0] + rty_P[1] * rty_P[1];
  u = (P1P3_idx_0 * rty_P[0] + P1P3_idx_1 * rty_P[1]) / u_tmp;
  if (u <= 0.0F) {
    rty_P[0] = rtu_P1[0];
    rty_P[1] = rtu_P1[1];
  } else if (u >= 1.0F) {
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    /* SignalConversion: '<S200>/TmpSignal ConversionAt SFunction Inport3' */
    P1P3_idx_0 = (u * rty_P[0] + rtu_P1[0]) - rtu_P3;
    P1P3_idx_1 = (u * rty_P[1] + rtu_P1[1]) - rtu_P3_l;
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
 *    '<S195>/SearchL1RefWP'
 *    '<S173>/SearchL1RefWP'
 *    '<S126>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2],
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

  /* SignalConversion: '<S201>/TmpSignal ConversionAt SFunction Inport3' */
  B = ((rtu_P2[0] - rtu_P1[0]) * (rtu_P1[0] - rtu_P3) + (rtu_P2[1] - rtu_P1[1]) *
       (rtu_P1[1] - rtu_P3_f)) * 2.0F;
  D = B * B - (((((rtu_P3 * rtu_P3 + rtu_P3_f * rtu_P3_f) + rtu_P1[0] * rtu_P1[0])
                 + rtu_P1[1] * rtu_P1[1]) - (rtu_P3 * rtu_P1[0] + rtu_P3_f *
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
 *    '<S26>/Unknown'
 *    '<S24>/Unknown'
 *    '<S23>/Unknown'
 *    '<S19>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S147>/Bus Assignment' incorporates:
   *  Constant: '<S147>/Constant'
   *  Constant: '<S147>/Constant2'
   *  SignalConversion: '<S147>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S147>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S39>/Hold Control'
 *    '<S60>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S42>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S39>/Hold Control'
 *    '<S60>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S42>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S39>/Hold Control'
 *    '<S60>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S42>/Delay' incorporates:
   *  Gain: '<S44>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S42>/Gain2' incorporates:
   *  Delay: '<S42>/Delay'
   *  Gain: '<S44>/Gain'
   *  Sum: '<S42>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S42>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S39>/Brake Control'
 *    '<S60>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S41>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S41>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S39>/Move Control'
 *    '<S60>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S45>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S45>/Dead Zone' */

  /* Gain: '<S43>/Gain1' incorporates:
   *  Gain: '<S45>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtu_FMS_In_0 *
    FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S40>/Motion Status'
 *    '<S61>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S40>/Motion Status'
 *    '<S61>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S40>/Motion Status'
 *    '<S61>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S40>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c17_FMS == 0U) {
    localDW->is_active_c17_FMS = 1U;
    localDW->is_c17_FMS = FMS_IN_Move;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c17_FMS) {
     case FMS_IN_Brake:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c17_FMS = FMS_IN_Hold;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c17_FMS = FMS_IN_Move;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S40>/Motion Status' */
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

/* Output and update for function-call system: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
void F_VehicleArmAutoMissionLLA2FLAT(const real_T rtu_lla[3], const real_T
  rtu_llo[2], real_T rtu_href, real_T rtu_psio, real32_T rty_pos[3], const
  ConstB_VehicleArmAutoMissionL_T *localC)
{
  real_T rtb_Sum2_m;
  real_T rtb_Gain_lq;
  real_T rtb_Sum3;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_d_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S214>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S215>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S215>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S215>/Multiply1' incorporates:
   *  Product: '<S215>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S215>/Divide' incorporates:
   *  Constant: '<S215>/Constant'
   *  Constant: '<S215>/R'
   *  Sqrt: '<S215>/Sqrt'
   *  Sum: '<S215>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S215>/Product3' incorporates:
   *  Constant: '<S215>/Constant1'
   *  Product: '<S215>/Multiply1'
   *  Sum: '<S215>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S215>/Multiply2' incorporates:
   *  Trigonometry: '<S215>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S214>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S219>/Abs' incorporates:
   *  Abs: '<S222>/Abs1'
   *  Switch: '<S219>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S219>/Switch1' incorporates:
   *  Abs: '<S219>/Abs'
   *  Bias: '<S219>/Bias2'
   *  Bias: '<S219>/Bias3'
   *  Constant: '<S216>/Constant'
   *  Constant: '<S216>/Constant1'
   *  Constant: '<S221>/Constant'
   *  Gain: '<S219>/Gain1'
   *  Product: '<S219>/Multiply'
   *  RelationalOperator: '<S221>/Compare'
   *  Switch: '<S216>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S222>/Switch1' incorporates:
     *  Bias: '<S222>/Bias2'
     *  Bias: '<S222>/Bias3'
     *  Constant: '<S222>/Constant'
     *  Constant: '<S223>/Constant'
     *  Math: '<S222>/Math Function'
     *  RelationalOperator: '<S223>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S222>/Switch1' */

    /* Signum: '<S219>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S219>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_d_0 = 180;
  } else {
    rtb_Compare_d_0 = 0;
  }

  /* Sum: '<S216>/Sum' incorporates:
   *  Sum: '<S214>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_d_0;

  /* Product: '<S214>/Multiply' incorporates:
   *  Gain: '<S214>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S218>/Switch1' incorporates:
   *  Abs: '<S218>/Abs1'
   *  Bias: '<S218>/Bias2'
   *  Bias: '<S218>/Bias3'
   *  Constant: '<S218>/Constant'
   *  Constant: '<S220>/Constant'
   *  Math: '<S218>/Math Function'
   *  RelationalOperator: '<S220>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S218>/Switch1' */

  /* Product: '<S214>/Multiply' incorporates:
   *  Gain: '<S214>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

  /* Gain: '<S214>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S217>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S217>/Sum2' incorporates:
   *  Product: '<S217>/Multiply1'
   *  Product: '<S217>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S217>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S217>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S217>/Sum3' */
  rtb_Sum3 = rtb_Gain_lq - rtb_Sum3;

  /* DataTypeConversion: '<S211>/Data Type Conversion' incorporates:
   *  Gain: '<S214>/Gain'
   *  Sum: '<S214>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_m;
  rty_pos[1] = (real32_T)rtb_Sum3;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Stabilize(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Stabilize;

    /* Delay: '<S7>/Delay' */
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

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S7>/Delay' */
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

    /* Delay: '<S7>/Delay' */
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

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S7>/Delay' */
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = false;
  switch (cmd_in) {
   case FMS_Cmd_Pause:
   case FMS_Cmd_Return:
    if (((ins_flag & 1U) != 0U) && ((ins_flag & 4U) != 0U) && ((ins_flag & 8U)
         != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) &&
        ((ins_flag & 128U) != 0U)) {
      valid = true;
    }
    break;

   case FMS_Cmd_PreArm:
    if (mode_in == PilotMode_Manual) {
      valid = true;
    } else if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag
                 & 8U) == 0U)) {
    } else {
      switch (mode_in) {
       case PilotMode_Position:
       case PilotMode_Mission:
        if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag &
              128U) != 0U)) {
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.Msg_FMS_Cmd_o
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_o[0] : NULL;
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
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
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
    FMS_B.state = VehicleState_Offboard;
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

  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S224>/Compare' incorporates:
   *  Abs: '<S213>/Abs'
   *  Constant: '<S224>/Constant'
   *  MinMax: '<S213>/Max'
   *  Sum: '<S213>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S3>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
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
      FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }
        break;

       case FMS_IN_Return:
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home_l[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home_l[1];

        /* Constant: '<Root>/ACCEPT_R' */
        if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
          FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
          FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
          FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
          FMS_DW.is_SubMode = FMS_IN_Hold_h;
          FMS_B.state = VehicleState_Hold;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            tmp_0 = FMS_getArmMode(FMS_B.target_mode);
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
                FMS_DW.is_Manual = FMS_IN_Manual_g;
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
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real32_T tmp[2];
  uint32_T qY;
  int32_T lla_tmp;
  real_T tmp_0;
  FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
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
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home_l[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home_l[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
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
          if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
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
            FMS_B.Cmd_In.cur_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.cur_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.cur_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_exit_internal_Auto();
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
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
              break;

             case FMS_IN_Mission:
              if (FMS_DW.mission_timestamp_prev !=
                  FMS_DW.mission_timestamp_start) {
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
                  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
                  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
                  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
                  FMS_DW.is_Vehicle = FMS_IN_Disarm;
                  FMS_B.state = VehicleState_Disarm;
                  break;

                 case FMS_IN_Loiter:
                  break;

                 case FMS_IN_NextWP:
                  if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Takeoff) {
                    FMS_DW.is_Mission = FMS_IN_Takeoff_d;
                    FMS_B.Cmd_In.cur_waypoint[0] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
                    FMS_B.Cmd_In.cur_waypoint[1] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                    FMS_B.Cmd_In.cur_waypoint[2] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.h_R;

                    /* Inport: '<Root>/Mission_Data' */
                    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                                     FMS_DW.home_l[2]);
                    FMS_B.llo[0] = FMS_DW.llo[0];
                    FMS_B.llo[1] = FMS_DW.llo[1];
                    FMS_B.href = 0.0;
                    FMS_B.psio = 0.0;

                    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo,
                      FMS_B.href, FMS_B.psio, FMS_B.DataTypeConversion,
                      &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

                    /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
                    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
                    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
                    FMS_B.state = VehicleState_Takeoff;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
                    FMS_DW.is_Mission = FMS_IN_Return_h;
                    FMS_B.Cmd_In.cur_waypoint[0] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
                    FMS_B.Cmd_In.cur_waypoint[1] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                    FMS_B.Cmd_In.cur_waypoint[2] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
                    FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home_l[0];
                    FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home_l[1];
                    FMS_B.Cmd_In.sp_waypoint[2] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
                    FMS_B.state = VehicleState_Return;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
                    FMS_DW.is_Mission = FMS_IN_Waypoint;
                    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
                    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
                    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
                    lla_tmp = FMS_B.wp_index - 1;

                    /* Inport: '<Root>/Mission_Data' */
                    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] *
                      1.0E-7;
                    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] *
                      1.0E-7;
                    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[lla_tmp] +
                                     FMS_DW.home_l[2]);
                    FMS_B.llo[0] = FMS_DW.llo[0];
                    FMS_B.llo[1] = FMS_DW.llo[1];
                    FMS_B.href = 0.0;
                    FMS_B.psio = 0.0;

                    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo,
                      FMS_B.href, FMS_B.psio, FMS_B.DataTypeConversion,
                      &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

                    /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
                    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
                    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
                    FMS_B.state = VehicleState_Mission;
                  } else {
                    FMS_DW.is_Mission = FMS_IN_Loiter;
                    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
                    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
                    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
                    FMS_B.state = VehicleState_Hold;
                  }
                  break;

                 case FMS_IN_Return_h:
                  tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                    FMS_DW.home_l[0];
                  tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                    FMS_DW.home_l[1];

                  /* Constant: '<Root>/ACCEPT_R' */
                  if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
                    lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                    if ((uint32_T)lla_tmp > 255U) {
                      lla_tmp = 255;
                    }

                    FMS_B.wp_index = (uint8_T)lla_tmp;
                    FMS_DW.is_Mission = FMS_IN_NextWP;

                    /* Inport: '<Root>/Mission_Data' */
                    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index
                        - 1];
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
                  tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                    FMS_B.Cmd_In.sp_waypoint[0];
                  tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                    FMS_B.Cmd_In.sp_waypoint[1];

                  /* Constant: '<Root>/ACCEPT_R' */
                  if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
                    lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                    if ((uint32_T)lla_tmp > 255U) {
                      lla_tmp = 255;
                    }

                    FMS_B.wp_index = (uint8_T)lla_tmp;
                    FMS_DW.is_Mission = FMS_IN_NextWP;

                    /* Inport: '<Root>/Mission_Data' */
                    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index
                        - 1];
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
                  tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                    FMS_B.Cmd_In.sp_waypoint[0];
                  tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                    FMS_B.Cmd_In.sp_waypoint[1];

                  /* Constant: '<Root>/ACCEPT_R' */
                  if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
                    lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                    if ((uint32_T)lla_tmp > 255U) {
                      lla_tmp = 255;
                    }

                    FMS_B.wp_index = (uint8_T)lla_tmp;
                    FMS_DW.is_Mission = FMS_IN_NextWP;

                    /* Inport: '<Root>/Mission_Data' */
                    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index
                        - 1];
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
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
              (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
            FMS_DW.durationLastReferenceTick_1_j =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
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
                (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
              FMS_DW.durationLastReferenceTick_1_j =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
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
            if (FMS_DW.chartAbsoluteTimeCounter -
                FMS_DW.durationLastReferenceTick_2 >= 500) {
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

      /* Outputs for Function Call SubSystem: '<S3>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S212>/Reshape' incorporates:
       *  Constant: '<S212>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S3>/Vehicle.PrepTakeoff' */
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.Reshape[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.Reshape[1];
      FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.Reshape[2];
      FMS_B.Cmd_In.sp_waypoint[2] += FMS_DW.home_l[2];
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_DW.home_l[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_DW.home_l[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.home_l[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.home_l[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_DW.home_l[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_DW.home_l[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.home_l[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.home_l[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
      FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      if (FMS_B.target_mode == PilotMode_Mission) {
        /* Inport: '<Root>/Mission_Data' */
        if ((FMS_U.Mission_Data.valid_items > 0) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = (FMS_DW.prep_takeoff == 1.0);
          FMS_B.state = VehicleState_Standby;
        } else {
          b_previousEvent = FMS_DW.sfEvent;
          FMS_DW.sfEvent = FMS_event_DisarmEvent;

          /* Chart: '<Root>/FMS State Machine' */
          FMS_c11_FMS();
          FMS_DW.sfEvent = b_previousEvent;
          if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
            FMS_B.state = VehicleState_Standby;
          }
        }

        /* End of Inport: '<Root>/Mission_Data' */
      } else {
        FMS_B.state = VehicleState_Standby;
      }

      if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_d = sf_internal_predicateOutput;
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
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
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
          FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
          FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_c > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
            FMS_DW.durationLastReferenceTick_2_j =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
              FMS_DW.durationLastReferenceTick_2_j =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
              FMS_DW.durationLastReferenceTick_1_c =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_DW.br;
          }
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_p, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_o[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T d1;
  boolean_T rtb_Compare_a4;
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion1_l;
  real32_T rtb_Saturation_fu;
  real32_T rtb_Saturation1_bl;
  real32_T rtb_Divide_h[2];
  real32_T rtb_Switch_fz[3];
  real32_T rtb_Saturation_bu;
  real32_T rtb_Switch_a[3];
  MotionState rtb_state_g;
  real32_T rtb_VectorConcatenate[9];
  MotionState rtb_state;
  real32_T rtb_P_ia[2];
  real32_T rtb_P_k[2];
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Switch_b_idx_2;
  real32_T rtb_Switch_b_idx_1;
  real32_T rtb_Switch_b_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/CommandProcess' */
  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S9>/FixPt Relational Operator'
   *  UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Delay: '<S7>/Delay'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  RelationalOperator: '<S8>/Compare'
   *  Switch: '<S7>/Switch1'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S7>/Switch1' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  Delay: '<S7>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Compare_a4 = (FMS_B.Switch1 == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S6>/SetHome' incorporates:
   *  TriggerPort: '<S13>/Trigger'
   */
  if (rtb_Compare_a4 && (FMS_PrevZCX.SetHome_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_Compare_a4;

  /* End of Outputs for SubSystem: '<S6>/SetHome' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  Switch: '<S6>/Switch2'
   *  UnitDelay: '<S11>/Delay Input1'
   *  UnitDelay: '<S12>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else {
    if (FMS_U.GCS_Cmd.cmd_1 == FMS_DW.DelayInput1_DSTATE_p) {
      FMS_B.Switch1 = FMS_Cmd_None;
    }
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Update for UnitDelay: '<S9>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  rtb_Saturation_bu = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation_bu < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Saturation_bu;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S12>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* End of Outputs for SubSystem: '<Root>/CommandProcess' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S7>/Delay'
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

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Mission_g:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
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

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Position_f:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
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

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  rtb_Compare_a4 = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Compare_a4) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = rtb_Compare_a4;
  rtb_Compare_a4 = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Compare_a4) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Compare_a4;
  FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
    FMS_DW.durationLastReferenceTick_2_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 4095U) {
    FMS_DW.temporalCounter_i1++;
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
  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  /* SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_fz[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_a[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_fz[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_a[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_fz[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_a[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* SwitchCase: '<S17>/Switch Case' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S19>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S26>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S24>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S23>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S39>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S74>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S60>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S19>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S17>/Disarm' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S20>/Bus Assignment'
     *  BusAssignment: '<S21>/Bus Assignment'
     *  Constant: '<S21>/Constant'
     *  SignalConversion: '<S21>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S21>/Bus Assignment' incorporates:
     *  BusAssignment: '<S20>/Bus Assignment'
     *  Constant: '<S21>/Constant2'
     *  DataTypeConversion: '<S21>/Data Type Conversion2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S21>/Data Type Conversion2' incorporates:
       *  Constant: '<S21>/Constant6'
       */
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);
    }

    /* End of Outputs for SubSystem: '<S17>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S17>/Standby' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S20>/Bus Assignment'
     *  BusAssignment: '<S22>/Bus Assignment'
     *  Constant: '<S22>/Constant'
     *  SignalConversion: '<S22>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S22>/Bus Assignment' incorporates:
     *  BusAssignment: '<S20>/Bus Assignment'
     *  Constant: '<S22>/Constant2'
     *  DataTypeConversion: '<S22>/Data Type Conversion3'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S22>/Data Type Conversion3' incorporates:
       *  Constant: '<S22>/Constant6'
       */
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);
    }

    /* End of Outputs for SubSystem: '<S17>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S17>/Arm' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* SwitchCase: '<S19>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

    /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S26>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S24>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S23>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S39>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S74>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S60>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 3:
       case 4:
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S19>/SubMode' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* SwitchCase: '<S26>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleState_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S26>/Takeoff' incorporates:
         *  ActionPort: '<S146>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S204>/TmpSignal ConversionAtSquareInport1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve;

        /* Sum: '<S205>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S205>/Math Function'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Sum: '<S204>/Sum of Elements'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S205>/Math Function1' incorporates:
         *  Sum: '<S205>/Sum of Elements'
         *
         * About '<S205>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S205>/Math Function1' */

        /* Switch: '<S205>/Switch' incorporates:
         *  Constant: '<S205>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S205>/Product'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (rtb_Saturation_fu > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_b_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_2 = rtb_Saturation_fu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S205>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S195>/NearbyRefWP' incorporates:
         *  Constant: '<S193>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation1_bl);

        /* MATLAB Function: '<S195>/SearchL1RefWP' incorporates:
         *  Constant: '<S193>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_fu);

        /* MATLAB Function: '<S195>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S195>/Switch1' incorporates:
         *  Constant: '<S198>/Constant'
         *  RelationalOperator: '<S198>/Compare'
         */
        if (rtb_Saturation1_bl > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S197>/Compare' incorporates:
           *  Constant: '<S197>/Constant'
           */
          rtb_Compare_a4 = (rtb_Saturation_fu >= 0.0F);

          /* Switch: '<S195>/Switch' */
          if (!rtb_Compare_a4) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S195>/Switch' */
        }

        /* End of Switch: '<S195>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S196>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S206>/Sum of Elements' incorporates:
         *  Math: '<S206>/Math Function'
         */
        rtb_Saturation_fu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S206>/Math Function1' incorporates:
         *  Sum: '<S206>/Sum of Elements'
         *
         * About '<S206>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S206>/Math Function1' */

        /* Switch: '<S206>/Switch' incorporates:
         *  Constant: '<S206>/Constant'
         *  Product: '<S206>/Product'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[0];
          rtb_Switch_fz[1] = rtb_Divide_h[1];
          rtb_Switch_fz[2] = rtb_Saturation_fu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S206>/Switch' */

        /* Product: '<S205>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S208>/Sum of Elements' incorporates:
         *  Math: '<S208>/Math Function'
         *  SignalConversion: '<S208>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S208>/Math Function1' incorporates:
         *  Sum: '<S208>/Sum of Elements'
         *
         * About '<S208>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S208>/Math Function1' */

        /* Switch: '<S208>/Switch' incorporates:
         *  Constant: '<S208>/Constant'
         *  Product: '<S208>/Product'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_fu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S208>/Switch' */

        /* Product: '<S206>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S209>/Sum of Elements' incorporates:
         *  Math: '<S209>/Math Function'
         *  SignalConversion: '<S209>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S209>/Math Function1' incorporates:
         *  Sum: '<S209>/Sum of Elements'
         *
         * About '<S209>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S209>/Math Function1' */

        /* Switch: '<S209>/Switch' incorporates:
         *  Constant: '<S209>/Constant'
         *  Product: '<S209>/Product'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Saturation_fu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S209>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S190>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_fu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation1_bl = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S209>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S208>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S190>/Sum1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S209>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S208>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S190>/Sum1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S190>/Divide' incorporates:
         *  Math: '<S191>/Square'
         *  Math: '<S192>/Square'
         *  Sqrt: '<S191>/Sqrt'
         *  Sqrt: '<S192>/Sqrt'
         *  Sum: '<S190>/Sum'
         *  Sum: '<S190>/Sum1'
         *  Sum: '<S191>/Sum of Elements'
         *  Sum: '<S192>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation1_bl * rtb_Saturation1_bl +
          rtb_Saturation_fu * rtb_Saturation_fu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S190>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S190>/Saturation' */

        /* Sum: '<S207>/Subtract' incorporates:
         *  Product: '<S207>/Multiply'
         *  Product: '<S207>/Multiply1'
         */
        rtb_Saturation_fu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S203>/Sign1' */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -1.0F;
        } else {
          if (rtb_Saturation_fu > 0.0F) {
            rtb_Saturation_fu = 1.0F;
          }
        }

        /* End of Signum: '<S203>/Sign1' */

        /* Switch: '<S203>/Switch2' incorporates:
         *  Constant: '<S203>/Constant4'
         */
        if (rtb_Saturation_fu == 0.0F) {
          rtb_Saturation_fu = 1.0F;
        }

        /* End of Switch: '<S203>/Switch2' */

        /* DotProduct: '<S203>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S203>/Acos' incorporates:
         *  DotProduct: '<S203>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S203>/Multiply' incorporates:
         *  Trigonometry: '<S203>/Acos'
         */
        rtb_Saturation_fu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S202>/Saturation' */
        if (rtb_Saturation_fu > 1.57079637F) {
          rtb_Saturation_fu = 1.57079637F;
        } else {
          if (rtb_Saturation_fu < -1.57079637F) {
            rtb_Saturation_fu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S202>/Saturation' */

        /* Sqrt: '<S204>/Sqrt' */
        rtb_Saturation1_bl = sqrtf(rtb_Saturation_bu);

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S146>/Bus Assignment'
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S146>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S146>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S146>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ok;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S202>/Divide' incorporates:
         *  Constant: '<S193>/L1'
         *  Gain: '<S202>/Gain'
         *  Math: '<S202>/Square'
         *  Product: '<S202>/Multiply1'
         *  Trigonometry: '<S202>/Sin'
         */
        rtb_Saturation_bu = rtb_Saturation1_bl * rtb_Saturation1_bl * 2.0F *
          arm_sin_f32(rtb_Saturation_fu) / FMS_PARAM.L1;

        /* Saturate: '<S193>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S193>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S188>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S190>/Multiply'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S188>/Sum2'
         *  Sum: '<S190>/Add'
         *  Sum: '<S190>/Subtract'
         */
        rtb_Saturation_bu = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S188>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S188>/Saturation1' */
        /* End of Outputs for SubSystem: '<S26>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S26>/Land' incorporates:
         *  ActionPort: '<S144>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S144>/Bus Assignment1'
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S144>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S144>/Constant'
         *  Constant: '<S144>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ml;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.v_cmd = 0.0F;
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S26>/Land' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S26>/Return' incorporates:
         *  ActionPort: '<S145>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S183>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S183>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S183>/Math Function'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S183>/Math Function1' incorporates:
         *  Sum: '<S183>/Sum of Elements'
         *
         * About '<S183>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S183>/Math Function1' */

        /* Switch: '<S183>/Switch' incorporates:
         *  Constant: '<S183>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S183>/Product'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (rtb_Saturation_bu > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_b_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_2 = rtb_Saturation_bu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S183>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S173>/NearbyRefWP' incorporates:
         *  Constant: '<S171>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation_fu);

        /* MATLAB Function: '<S173>/SearchL1RefWP' incorporates:
         *  Constant: '<S171>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_bu);

        /* MATLAB Function: '<S173>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S173>/Switch1' incorporates:
         *  Constant: '<S176>/Constant'
         *  RelationalOperator: '<S176>/Compare'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S175>/Compare' incorporates:
           *  Constant: '<S175>/Constant'
           */
          rtb_Compare_a4 = (rtb_Saturation_bu >= 0.0F);

          /* Switch: '<S173>/Switch' */
          if (!rtb_Compare_a4) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S173>/Switch' */
        }

        /* End of Switch: '<S173>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S174>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S184>/Sum of Elements' incorporates:
         *  Math: '<S184>/Math Function'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S184>/Math Function1' incorporates:
         *  Sum: '<S184>/Sum of Elements'
         *
         * About '<S184>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S184>/Math Function1' */

        /* Switch: '<S184>/Switch' incorporates:
         *  Constant: '<S184>/Constant'
         *  Product: '<S184>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[0];
          rtb_Switch_fz[1] = rtb_Divide_h[1];
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S184>/Switch' */

        /* Product: '<S183>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S186>/Sum of Elements' incorporates:
         *  Math: '<S186>/Math Function'
         *  SignalConversion: '<S186>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S186>/Math Function1' incorporates:
         *  Sum: '<S186>/Sum of Elements'
         *
         * About '<S186>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S186>/Math Function1' */

        /* Switch: '<S186>/Switch' incorporates:
         *  Constant: '<S186>/Constant'
         *  Product: '<S186>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_bu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S186>/Switch' */

        /* Product: '<S184>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S187>/Sum of Elements' incorporates:
         *  Math: '<S187>/Math Function'
         *  SignalConversion: '<S187>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S187>/Math Function1' incorporates:
         *  Sum: '<S187>/Sum of Elements'
         *
         * About '<S187>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S187>/Math Function1' */

        /* Switch: '<S187>/Switch' incorporates:
         *  Constant: '<S187>/Constant'
         *  Product: '<S187>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S187>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S168>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_fu = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S187>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S186>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S168>/Sum1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S187>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S186>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S168>/Sum1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S168>/Divide' incorporates:
         *  Math: '<S169>/Square'
         *  Math: '<S170>/Square'
         *  Sqrt: '<S169>/Sqrt'
         *  Sqrt: '<S170>/Sqrt'
         *  Sum: '<S168>/Sum'
         *  Sum: '<S168>/Sum1'
         *  Sum: '<S169>/Sum of Elements'
         *  Sum: '<S170>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu * rtb_Saturation_fu +
          rtb_Saturation_bu * rtb_Saturation_bu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S168>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S168>/Saturation' */

        /* Sum: '<S185>/Subtract' incorporates:
         *  Product: '<S185>/Multiply'
         *  Product: '<S185>/Multiply1'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S181>/Sign1' */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -1.0F;
        } else {
          if (rtb_Saturation_bu > 0.0F) {
            rtb_Saturation_bu = 1.0F;
          }
        }

        /* End of Signum: '<S181>/Sign1' */

        /* Switch: '<S181>/Switch2' incorporates:
         *  Constant: '<S181>/Constant4'
         */
        if (rtb_Saturation_bu == 0.0F) {
          rtb_Saturation_bu = 1.0F;
        }

        /* End of Switch: '<S181>/Switch2' */

        /* DotProduct: '<S181>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S181>/Acos' incorporates:
         *  DotProduct: '<S181>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S181>/Multiply' incorporates:
         *  Trigonometry: '<S181>/Acos'
         */
        rtb_Saturation_bu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S180>/Saturation' */
        if (rtb_Saturation_bu > 1.57079637F) {
          rtb_Saturation_bu = 1.57079637F;
        } else {
          if (rtb_Saturation_bu < -1.57079637F) {
            rtb_Saturation_bu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S180>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S182>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S182>/Square'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Sum: '<S182>/Sum of Elements'
         */
        rtb_Saturation_fu = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S145>/Bus Assignment1'
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S145>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S145>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S180>/Divide' incorporates:
         *  Constant: '<S171>/L1'
         *  Gain: '<S180>/Gain'
         *  Math: '<S180>/Square'
         *  Product: '<S180>/Multiply1'
         *  Trigonometry: '<S180>/Sin'
         */
        rtb_Saturation_bu = rtb_Saturation_fu * rtb_Saturation_fu * 2.0F *
          arm_sin_f32(rtb_Saturation_bu) / FMS_PARAM.L1;

        /* Saturate: '<S171>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S171>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S166>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S168>/Multiply'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S166>/Sum2'
         *  Sum: '<S168>/Add'
         *  Sum: '<S168>/Subtract'
         */
        rtb_Saturation_bu = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S166>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S145>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S166>/Saturation1' */
        /* End of Outputs for SubSystem: '<S26>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S26>/Hold' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S26>/Switch Case' incorporates:
           *  Delay: '<S148>/Delay'
           *  Delay: '<S153>/start_vel'
           */
          FMS_DW.icLoad_n = 1U;
          FMS_DW.icLoad_b = 1U;

          /* End of InitializeConditions for SubSystem: '<S26>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S26>/Hold' incorporates:
         *  ActionPort: '<S143>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S160>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S160>/Math Function'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S160>/Math Function1' incorporates:
         *  Sum: '<S160>/Sum of Elements'
         *
         * About '<S160>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S160>/Math Function1' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Constant: '<S160>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S160>/Product'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (rtb_Saturation_bu > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_fz[0] = FMS_U.INS_Out.vn;
          rtb_Switch_fz[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S160>/Switch' */

        /* Delay: '<S153>/start_vel' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (FMS_DW.icLoad_n != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.start_vel_DSTATE_g[0] = FMS_U.INS_Out.vn;
          FMS_DW.start_vel_DSTATE_g[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Sum: '<S165>/Sum of Elements' incorporates:
         *  Delay: '<S153>/start_vel'
         *  Math: '<S165>/Math Function'
         */
        rtb_Saturation_bu = FMS_DW.start_vel_DSTATE_g[0] *
          FMS_DW.start_vel_DSTATE_g[0] + FMS_DW.start_vel_DSTATE_g[1] *
          FMS_DW.start_vel_DSTATE_g[1];

        /* Math: '<S165>/Math Function1' incorporates:
         *  Sum: '<S165>/Sum of Elements'
         *
         * About '<S165>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S165>/Math Function1' */

        /* Switch: '<S165>/Switch' incorporates:
         *  Constant: '<S165>/Constant'
         *  Delay: '<S153>/start_vel'
         *  Product: '<S165>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_a[0] = FMS_DW.start_vel_DSTATE_g[0];
          rtb_Switch_a[1] = FMS_DW.start_vel_DSTATE_g[1];
          rtb_Switch_a[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_a[0] = 0.0F;
          rtb_Switch_a[1] = 0.0F;
          rtb_Switch_a[2] = 1.0F;
        }

        /* End of Switch: '<S165>/Switch' */

        /* Product: '<S160>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S163>/Sum of Elements' incorporates:
         *  Math: '<S163>/Math Function'
         *  SignalConversion: '<S163>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S163>/Math Function1' incorporates:
         *  Sum: '<S163>/Sum of Elements'
         *
         * About '<S163>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S163>/Math Function1' */

        /* Switch: '<S163>/Switch' incorporates:
         *  Constant: '<S163>/Constant'
         *  Product: '<S163>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S163>/Switch' */

        /* MinMax: '<S151>/Max' incorporates:
         *  Constant: '<S149>/L1'
         *  Constant: '<S149>/R'
         *  Gain: '<S151>/Gain'
         */
        rtb_Saturation_fu = fmaxf(FMS_PARAM.LOITER_R, 0.5F * FMS_PARAM.L1);

        /* MATLAB Function: '<S151>/SearchL1RefWP' incorporates:
         *  Constant: '<S149>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_k[0] = 0.0F;
        rtb_P_k[1] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.cur_waypoint[0]) &&
            (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.cur_waypoint[1]) &&
            (rtb_Saturation_fu == FMS_PARAM.L1)) {
          i = 0;
        } else {
          rtb_Switch_b_idx_0 = FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_P_ia[0] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0;
          rtb_Switch_b_idx_0 = FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R;
          rtb_Saturation_bu = sqrtf(rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0 +
            rtb_P_ia[0]);
          rtb_Saturation1_bl = FMS_PARAM.L1 * FMS_PARAM.L1;
          rtb_Switch_b_idx_2 = ((rtb_Saturation_bu * rtb_Saturation_bu +
            rtb_Saturation1_bl) - rtb_Saturation_fu * rtb_Saturation_fu) / (2.0F
            * rtb_Saturation_bu);
          rtb_Switch_b_idx_1 /= rtb_Saturation_bu;
          rtb_Switch_b_idx_0 /= rtb_Saturation_bu;
          rtb_Saturation_bu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_2;
          if (rtb_Saturation_bu > rtb_Saturation1_bl) {
            i = 0;
          } else if (rtb_Saturation_bu == rtb_Saturation1_bl) {
            i = 1;
            rtb_P_k[0] = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
              FMS_U.INS_Out.x_R;
            rtb_P_k[1] = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
              FMS_U.INS_Out.y_R;
          } else {
            i = 2;
            rtb_Saturation_bu = sqrtf(rtb_Saturation1_bl - rtb_Saturation_bu);
            rtb_P_k[0] = (rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
                          FMS_U.INS_Out.x_R) + rtb_Saturation_bu *
              -rtb_Switch_b_idx_0;
            rtb_P_k[1] = (rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
                          FMS_U.INS_Out.y_R) + rtb_Saturation_bu *
              rtb_Switch_b_idx_1;
          }
        }

        /* End of MATLAB Function: '<S151>/SearchL1RefWP' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* RelationalOperator: '<S154>/Compare' incorporates:
         *  Constant: '<S154>/Constant'
         */
        rtb_Compare_a4 = (i > 0);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S151>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_P_ia[0] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Switch_b_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_P_ia[1] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Switch: '<S151>/Switch' incorporates:
         *  Constant: '<S149>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S151>/OutRegionRegWP'
         *  Product: '<S165>/Divide'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (rtb_Compare_a4) {
          rtb_Saturation_bu = rtb_P_k[0];
        } else if (rtb_P_ia[0] + rtb_P_ia[1] > rtb_Saturation_fu *
                   rtb_Saturation_fu) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S151>/OutRegionRegWP' incorporates:
           *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_bu = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_bu = rtb_Switch_a[0] / rtb_Switch_a[2] * FMS_PARAM.L1 +
            FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S152>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Switch_b_idx_1 = rtb_Saturation_bu - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S151>/Switch' incorporates:
         *  Constant: '<S149>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S151>/OutRegionRegWP'
         *  Product: '<S165>/Divide'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (rtb_Compare_a4) {
          rtb_Saturation_bu = rtb_P_k[1];
        } else if (rtb_P_ia[0] + rtb_P_ia[1] > rtb_Saturation_fu *
                   rtb_Saturation_fu) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S151>/OutRegionRegWP' incorporates:
           *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_bu = FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_bu = rtb_Switch_a[1] / rtb_Switch_a[2] * FMS_PARAM.L1 +
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S152>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Switch_b_idx_0 = rtb_Saturation_bu - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S161>/Sum of Elements' incorporates:
         *  Math: '<S161>/Math Function'
         */
        rtb_Saturation_bu = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1 +
          rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Math: '<S161>/Math Function1' incorporates:
         *  Sum: '<S161>/Sum of Elements'
         *
         * About '<S161>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S161>/Math Function1' */

        /* Switch: '<S161>/Switch' incorporates:
         *  Constant: '<S161>/Constant'
         *  Product: '<S161>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_a[0] = rtb_Switch_b_idx_1;
          rtb_Switch_a[1] = rtb_Switch_b_idx_0;
          rtb_Switch_a[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_a[0] = 0.0F;
          rtb_Switch_a[1] = 0.0F;
          rtb_Switch_a[2] = 1.0F;
        }

        /* End of Switch: '<S161>/Switch' */

        /* Product: '<S161>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];
        rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

        /* Sum: '<S164>/Sum of Elements' incorporates:
         *  Math: '<S164>/Math Function'
         *  SignalConversion: '<S164>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S164>/Math Function1' incorporates:
         *  Sum: '<S164>/Sum of Elements'
         *
         * About '<S164>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S164>/Math Function1' */

        /* Switch: '<S164>/Switch' incorporates:
         *  Constant: '<S164>/Constant'
         *  Product: '<S164>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_a[0] = rtb_Divide_h[1];
          rtb_Switch_a[1] = rtb_Divide_h[0];
          rtb_Switch_a[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_a[0] = 0.0F;
          rtb_Switch_a[1] = 0.0F;
          rtb_Switch_a[2] = 1.0F;
        }

        /* End of Switch: '<S164>/Switch' */

        /* Product: '<S164>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];

        /* Product: '<S163>/Divide' */
        rtb_P_k[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S164>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

        /* Product: '<S163>/Divide' */
        rtb_P_k[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S159>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S159>/Square'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Sum: '<S159>/Sum of Elements'
         */
        rtb_Saturation_bu = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S157>/Square' */
        rtb_Switch_b_idx_0 = rtb_Saturation_bu * rtb_Saturation_bu;

        /* Sum: '<S162>/Subtract' incorporates:
         *  Product: '<S162>/Multiply'
         *  Product: '<S162>/Multiply1'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S158>/Sign1' */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -1.0F;
        } else {
          if (rtb_Saturation_bu > 0.0F) {
            rtb_Saturation_bu = 1.0F;
          }
        }

        /* End of Signum: '<S158>/Sign1' */

        /* Switch: '<S158>/Switch2' incorporates:
         *  Constant: '<S158>/Constant4'
         */
        if (rtb_Saturation_bu == 0.0F) {
          rtb_Saturation_bu = 1.0F;
        }

        /* End of Switch: '<S158>/Switch2' */

        /* DotProduct: '<S158>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S158>/Acos' incorporates:
         *  DotProduct: '<S158>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S158>/Multiply' incorporates:
         *  Trigonometry: '<S158>/Acos'
         */
        rtb_Saturation_bu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S157>/Saturation' */
        if (rtb_Saturation_bu > 1.57079637F) {
          rtb_Saturation_bu = 1.57079637F;
        } else {
          if (rtb_Saturation_bu < -1.57079637F) {
            rtb_Saturation_bu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S157>/Saturation' */

        /* Delay: '<S148>/Delay' incorporates:
         *  Gain: '<S150>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (FMS_DW.icLoad_b != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE = -FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S143>/Bus Assignment'
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S143>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S143>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S143>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
        FMS_Y.FMS_Out.u_cmd = 15.0F;

        /* Product: '<S157>/Divide' incorporates:
         *  Constant: '<S149>/L1'
         *  Gain: '<S157>/Gain'
         *  Product: '<S157>/Multiply1'
         *  Trigonometry: '<S157>/Sin'
         */
        rtb_Saturation_bu = 2.0F * rtb_Switch_b_idx_0 * arm_sin_f32
          (rtb_Saturation_bu) / FMS_PARAM.L1;

        /* Saturate: '<S152>/Saturation' */
        if (rtb_Saturation_bu > 9.81F) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = 9.81F;
        } else if (rtb_Saturation_bu < -9.81F) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -9.81F;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S152>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* BusAssignment: '<S143>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Delay: '<S148>/Delay'
         *  Gain: '<S148>/Gain2'
         *  Gain: '<S150>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Sum: '<S148>/Sum'
         */
        FMS_Y.FMS_Out.w_cmd = (FMS_DW.Delay_DSTATE - (-FMS_U.INS_Out.h_R)) *
          FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Update for Delay: '<S153>/start_vel' */
        FMS_DW.icLoad_n = 0U;

        /* Update for Delay: '<S148>/Delay' */
        FMS_DW.icLoad_b = 0U;

        /* End of Outputs for SubSystem: '<S26>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S26>/Unknown' incorporates:
         *  ActionPort: '<S147>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S26>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S26>/Switch Case' */
      /* End of Outputs for SubSystem: '<S19>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S19>/Auto' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SwitchCase: '<S24>/Switch Case' incorporates:
       *  RelationalOperator: '<S117>/FixPt Relational Operator'
       *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S117>/Delay Input1'
       *
       * Block description for '<S117>/Delay Input1':
       *
       *  Store in Global RAM
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Offboard:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 0;
        break;

       case VehicleState_Mission:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S24>/Offboard' incorporates:
         *  ActionPort: '<S115>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S115>/Bus Assignment'
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S115>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S115>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S24>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Mission' incorporates:
           *  ActionPort: '<S114>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  UnitDelay: '<S117>/Delay Input1'
           *
           * Block description for '<S117>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S24>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Mission' incorporates:
         *  ActionPort: '<S114>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S114>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S118>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Math: '<S136>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  RelationalOperator: '<S117>/FixPt Relational Operator'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S117>/Delay Input1'
         *
         * Block description for '<S117>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S136>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S136>/Math Function'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S136>/Math Function1' incorporates:
         *  Sum: '<S136>/Sum of Elements'
         *
         * About '<S136>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S136>/Math Function1' */

        /* Switch: '<S136>/Switch' incorporates:
         *  Constant: '<S136>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S136>/Product'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        if (rtb_Saturation_bu > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_b_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_2 = rtb_Saturation_bu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S136>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S126>/NearbyRefWP' incorporates:
         *  Constant: '<S124>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation_fu);

        /* MATLAB Function: '<S126>/SearchL1RefWP' incorporates:
         *  Constant: '<S124>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_bu);

        /* MATLAB Function: '<S126>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S126>/Switch1' incorporates:
         *  Constant: '<S129>/Constant'
         *  RelationalOperator: '<S129>/Compare'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S128>/Compare' incorporates:
           *  Constant: '<S128>/Constant'
           */
          rtb_Compare_a4 = (rtb_Saturation_bu >= 0.0F);

          /* Switch: '<S126>/Switch' */
          if (!rtb_Compare_a4) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S126>/Switch' */
        }

        /* End of Switch: '<S126>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S127>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S137>/Sum of Elements' incorporates:
         *  Math: '<S137>/Math Function'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S137>/Math Function1' incorporates:
         *  Sum: '<S137>/Sum of Elements'
         *
         * About '<S137>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S137>/Math Function1' */

        /* Switch: '<S137>/Switch' incorporates:
         *  Constant: '<S137>/Constant'
         *  Product: '<S137>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[0];
          rtb_Switch_fz[1] = rtb_Divide_h[1];
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S137>/Switch' */

        /* Product: '<S136>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S139>/Sum of Elements' incorporates:
         *  Math: '<S139>/Math Function'
         *  SignalConversion: '<S139>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S139>/Math Function1' incorporates:
         *  Sum: '<S139>/Sum of Elements'
         *
         * About '<S139>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S139>/Math Function1' */

        /* Switch: '<S139>/Switch' incorporates:
         *  Constant: '<S139>/Constant'
         *  Product: '<S139>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_bu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S139>/Switch' */

        /* Product: '<S137>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S140>/Sum of Elements' incorporates:
         *  Math: '<S140>/Math Function'
         *  SignalConversion: '<S140>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S140>/Math Function1' incorporates:
         *  Sum: '<S140>/Sum of Elements'
         *
         * About '<S140>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S140>/Math Function1' */

        /* Switch: '<S140>/Switch' incorporates:
         *  Constant: '<S140>/Constant'
         *  Product: '<S140>/Product'
         */
        if (rtb_Saturation_bu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S140>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S121>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_fu = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S140>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S139>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S121>/Sum1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S140>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S139>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S121>/Sum1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S121>/Divide' incorporates:
         *  Math: '<S122>/Square'
         *  Math: '<S123>/Square'
         *  Sqrt: '<S122>/Sqrt'
         *  Sqrt: '<S123>/Sqrt'
         *  Sum: '<S121>/Sum'
         *  Sum: '<S121>/Sum1'
         *  Sum: '<S122>/Sum of Elements'
         *  Sum: '<S123>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu * rtb_Saturation_fu +
          rtb_Saturation_bu * rtb_Saturation_bu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S121>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S121>/Saturation' */

        /* Sum: '<S138>/Subtract' incorporates:
         *  Product: '<S138>/Multiply'
         *  Product: '<S138>/Multiply1'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S134>/Sign1' */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -1.0F;
        } else {
          if (rtb_Saturation_bu > 0.0F) {
            rtb_Saturation_bu = 1.0F;
          }
        }

        /* End of Signum: '<S134>/Sign1' */

        /* Switch: '<S134>/Switch2' incorporates:
         *  Constant: '<S134>/Constant4'
         */
        if (rtb_Saturation_bu == 0.0F) {
          rtb_Saturation_bu = 1.0F;
        }

        /* End of Switch: '<S134>/Switch2' */

        /* DotProduct: '<S134>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S134>/Acos' incorporates:
         *  DotProduct: '<S134>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S134>/Multiply' incorporates:
         *  Trigonometry: '<S134>/Acos'
         */
        rtb_Saturation_bu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S133>/Saturation' */
        if (rtb_Saturation_bu > 1.57079637F) {
          rtb_Saturation_bu = 1.57079637F;
        } else {
          if (rtb_Saturation_bu < -1.57079637F) {
            rtb_Saturation_bu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S133>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S135>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S135>/Square'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Sum: '<S135>/Sum of Elements'
         */
        rtb_Saturation_fu = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S118>/Bus Assignment'
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S118>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S118>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S118>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S133>/Divide' incorporates:
         *  Constant: '<S124>/L1'
         *  Gain: '<S133>/Gain'
         *  Math: '<S133>/Square'
         *  Product: '<S133>/Multiply1'
         *  Trigonometry: '<S133>/Sin'
         */
        rtb_Saturation_bu = rtb_Saturation_fu * rtb_Saturation_fu * 2.0F *
          arm_sin_f32(rtb_Saturation_bu) / FMS_PARAM.L1;

        /* Saturate: '<S124>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S118>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S118>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S118>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S124>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S119>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S121>/Multiply'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S119>/Sum2'
         *  Sum: '<S121>/Add'
         *  Sum: '<S121>/Subtract'
         */
        rtb_Saturation_bu = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S119>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S118>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S118>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S118>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S119>/Saturation1' */
        /* End of Outputs for SubSystem: '<S114>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S117>/Delay Input1' incorporates:
         *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S117>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S24>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S116>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S24>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S24>/Switch Case' */
      /* End of Outputs for SubSystem: '<S19>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S19>/Assist' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* SwitchCase: '<S23>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Acro:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleState_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S39>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S74>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S60>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S23>/Acro' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S33>/Gain'
         *  Gain: '<S33>/Gain1'
         *  Gain: '<S33>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S34>/Saturation' incorporates:
         *  Constant: '<S34>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         *  Sum: '<S34>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_bu = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S34>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S34>/Constant5'
         *  Gain: '<S34>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S34>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_bu), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S23>/Acro' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S23>/Stabilize' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S31>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S105>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S105>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S102>/Gain'
         *  Gain: '<S105>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Saturation_bu * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S106>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S106>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S102>/Gain1'
         *  Gain: '<S106>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.theta_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Saturation_bu * -FMS_PARAM.PITCH_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S111>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S111>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S103>/Gain1'
         *  Gain: '<S111>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation_bu * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Saturate: '<S104>/Saturation' incorporates:
         *  Constant: '<S104>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         *  Sum: '<S104>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_bu = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S104>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Constant: '<S104>/Constant5'
         *  Gain: '<S104>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S104>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_bu), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S23>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S23>/Altitude' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S23>/Switch Case' incorporates:
           *  Chart: '<S40>/Motion Status'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S23>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S23>/Altitude' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S40>/Motion Status' incorporates:
         *  Abs: '<S40>/Abs'
         *  Abs: '<S40>/Abs1'
         *  Constant: '<S48>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S48>/Compare'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ,
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_g,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S39>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_g) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_m) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S39>/Hold Control' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S39>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S39>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S39>/Hold Control' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S39>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S39>/Brake Control' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S39>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S39>/Move Control' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S39>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S39>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  BusAssignment: '<S29>/Bus Assignment'
         *  Constant: '<S29>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S50>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S50>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S37>/Gain'
         *  Gain: '<S50>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Saturation_bu * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S53>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S53>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S38>/Gain1'
         *  Gain: '<S53>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation_bu * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S35>/Gain1' incorporates:
         *  Bias: '<S35>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        rtb_Saturation_bu = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S35>/Saturation' incorporates:
         *  Gain: '<S35>/Gain1'
         */
        if (rtb_Saturation_bu > 1.0F) {
          rtb_Saturation_bu = 1.0F;
        } else {
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Saturation_bu = 0.0F;
          }
        }

        /* End of Saturate: '<S35>/Saturation' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S35>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_bu;

        /* Saturate: '<S39>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S39>/Saturation1' */
        /* End of Outputs for SubSystem: '<S23>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S23>/Position' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S23>/Switch Case' incorporates:
           *  Chart: '<S61>/Motion Status'
           *  Chart: '<S75>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

          /* End of SystemReset for SubSystem: '<S23>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S23>/Position' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S101>/Trigonometric Function1' incorporates:
         *  Gain: '<S100>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Trigonometry: '<S101>/Trigonometric Function3'
         */
        rtb_Saturation_bu = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate[0] = rtb_Saturation_bu;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S101>/Trigonometric Function' incorporates:
         *  Gain: '<S100>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  Trigonometry: '<S101>/Trigonometric Function2'
         */
        rtb_Switch_b_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate[1] = rtb_Switch_b_idx_0;

        /* SignalConversion: '<S101>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S101>/Constant3'
         */
        rtb_VectorConcatenate[2] = 0.0F;

        /* Gain: '<S101>/Gain' */
        rtb_VectorConcatenate[3] = -rtb_Switch_b_idx_0;

        /* Trigonometry: '<S101>/Trigonometric Function3' */
        rtb_VectorConcatenate[4] = rtb_Saturation_bu;

        /* SignalConversion: '<S101>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S101>/Constant4'
         */
        rtb_VectorConcatenate[5] = 0.0F;

        /* SignalConversion: '<S101>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
        rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
        rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S61>/Motion Status' incorporates:
         *  Abs: '<S61>/Abs'
         *  Abs: '<S61>/Abs1'
         *  Constant: '<S69>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S69>/Compare'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ,
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_g,
                         &FMS_DW.sf_MotionStatus_j);

        /* RelationalOperator: '<S98>/Compare' incorporates:
         *  Abs: '<S75>/Abs1'
         *  Constant: '<S98>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        rtb_Compare_a4 = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S75>/Motion State' incorporates:
         *  Abs: '<S75>/Abs'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_h;
          rtb_state = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_d:
            rtb_state = MotionState_Brake;

            /* Product: '<S75>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S18>/Signal Copy1'
             */
            for (i = 0; i < 3; i++) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate[i + 3] *
                                    FMS_U.INS_Out.ve + rtb_VectorConcatenate[i] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }

            /* End of Product: '<S75>/Multiply' */
            if ((fabsf(rtb_VectorConcatenate_0[1]) <= 0.2) ||
                (FMS_DW.temporalCounter_i1_i >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_l;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_Compare_a4) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_h;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold_l:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_a4) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_h;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_a4) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_d;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S75>/Motion State' */

        /* SwitchCase: '<S74>/Switch Case' incorporates:
         *  Math: '<S88>/Square'
         *  Product: '<S94>/Divide'
         *  Sum: '<S80>/Subtract'
         *  Switch: '<S79>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state) {
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
            /* InitializeConditions for IfAction SubSystem: '<S74>/Hold Control' incorporates:
             *  ActionPort: '<S77>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S74>/Switch Case' incorporates:
             *  Delay: '<S81>/start_vel'
             *  Delay: '<S81>/start_wp'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_c = 1U;

            /* End of InitializeConditions for SubSystem: '<S74>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S74>/Hold Control' incorporates:
           *  ActionPort: '<S77>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S89>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S89>/Math Function'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S89>/Math Function1' incorporates:
           *  Sum: '<S89>/Sum of Elements'
           *
           * About '<S89>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_bu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_bu);
          }

          /* End of Math: '<S89>/Math Function1' */

          /* Switch: '<S89>/Switch' incorporates:
           *  Constant: '<S89>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S89>/Product'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_fz[0] = FMS_U.INS_Out.vn;
            rtb_Switch_fz[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_fz[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_fz[0] = 0.0F;
            rtb_Switch_fz[1] = 0.0F;
            rtb_Switch_fz[2] = 1.0F;
          }

          /* End of Switch: '<S89>/Switch' */

          /* Delay: '<S81>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Sum: '<S94>/Sum of Elements' incorporates:
           *  Delay: '<S81>/start_vel'
           *  Math: '<S94>/Math Function'
           */
          rtb_Saturation_bu = FMS_DW.start_vel_DSTATE[0] *
            FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
            FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S94>/Math Function1' incorporates:
           *  Sum: '<S94>/Sum of Elements'
           *
           * About '<S94>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_bu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_bu);
          }

          /* End of Math: '<S94>/Math Function1' */

          /* Switch: '<S94>/Switch' incorporates:
           *  Constant: '<S94>/Constant'
           *  Delay: '<S81>/start_vel'
           *  Product: '<S94>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_a[0] = FMS_DW.start_vel_DSTATE[0];
            rtb_Switch_a[1] = FMS_DW.start_vel_DSTATE[1];
            rtb_Switch_a[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_a[0] = 0.0F;
            rtb_Switch_a[1] = 0.0F;
            rtb_Switch_a[2] = 1.0F;
          }

          /* End of Switch: '<S94>/Switch' */

          /* Product: '<S89>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
          rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

          /* Sum: '<S92>/Sum of Elements' incorporates:
           *  Math: '<S92>/Math Function'
           *  SignalConversion: '<S92>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0]
            * rtb_Divide_h[0];

          /* Math: '<S92>/Math Function1' incorporates:
           *  Sum: '<S92>/Sum of Elements'
           *
           * About '<S92>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_bu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_bu);
          }

          /* End of Math: '<S92>/Math Function1' */

          /* Switch: '<S92>/Switch' incorporates:
           *  Constant: '<S92>/Constant'
           *  Product: '<S92>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_fz[0] = rtb_Divide_h[1];
            rtb_Switch_fz[1] = rtb_Divide_h[0];
            rtb_Switch_fz[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_fz[0] = 0.0F;
            rtb_Switch_fz[1] = 0.0F;
            rtb_Switch_fz[2] = 1.0F;
          }

          /* End of Switch: '<S92>/Switch' */

          /* Delay: '<S81>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S79>/SearchL1RefWP' incorporates:
           *  Delay: '<S81>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          rtb_Divide_h[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_h[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S94>/Divide' */
          rtb_Switch_b_idx_0 = rtb_Switch_a[0] / rtb_Switch_a[2];

          /* MATLAB Function: '<S79>/SearchL1RefWP' */
          rtb_Saturation_bu = rtb_Switch_b_idx_0 * rtb_Divide_h[0];
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0;

          /* Product: '<S94>/Divide' */
          rtb_Switch_b_idx_0 = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* MATLAB Function: '<S79>/SearchL1RefWP' incorporates:
           *  Constant: '<S77>/L1'
           *  Delay: '<S81>/start_wp'
           */
          rtb_Saturation_bu += rtb_Switch_b_idx_0 * rtb_Divide_h[1];
          rtb_Switch_b_idx_2 = 2.0F * rtb_Saturation_bu;
          rtb_P_k[0] = 0.0F;
          rtb_P_k[1] = 0.0F;
          rtb_Saturation_fu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_2 -
            ((rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
              rtb_Divide_h[1]) - FMS_PARAM.L1 * FMS_PARAM.L1) * 4.0F;
          rtb_Saturation_bu = -1.0F;
          if (rtb_Saturation_fu > 0.0F) {
            rtb_Saturation_bu = sqrtf(rtb_Saturation_fu);
            rtb_Saturation_bu = fmaxf((-rtb_Switch_b_idx_2 + rtb_Saturation_bu) /
              2.0F, (-rtb_Switch_b_idx_2 - rtb_Saturation_bu) / 2.0F);
            rtb_P_k[0] = rtb_Saturation_bu * rtb_Switch_b_idx_1 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_P_k[1] = rtb_Saturation_bu * rtb_Switch_b_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (rtb_Saturation_fu == 0.0F) {
              rtb_Saturation_bu = -rtb_Switch_b_idx_2 / 2.0F;
              rtb_P_k[0] = rtb_Saturation_bu * rtb_Switch_b_idx_1 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_P_k[1] = rtb_Saturation_bu * rtb_Switch_b_idx_0 +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S82>/Compare' incorporates:
           *  Constant: '<S82>/Constant'
           *  MATLAB Function: '<S79>/SearchL1RefWP'
           */
          rtb_Compare_a4 = (rtb_Saturation_bu > 0.0F);

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S79>/OutRegionRefWP' incorporates:
           *  Delay: '<S81>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          rtb_Saturation_bu = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_Switch_b_idx_1 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1])
            * rtb_Switch_b_idx_0;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_b_idx_2 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_fu = fabsf((rtb_Saturation_bu * rtb_Switch_b_idx_1 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Saturation_fu > 1.29246971E-26F) {
            d1 = 1.0F;
            rtb_Switch_b_idx_2 = rtb_Saturation_fu;
          } else {
            rtb_Saturation1_bl = rtb_Saturation_fu / 1.29246971E-26F;
            d1 = rtb_Saturation1_bl * rtb_Saturation1_bl;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_fu = fabsf((rtb_Saturation_bu * rtb_Switch_b_idx_0 +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Saturation_fu > rtb_Switch_b_idx_2) {
            rtb_Saturation1_bl = rtb_Switch_b_idx_2 / rtb_Saturation_fu;
            d1 = d1 * rtb_Saturation1_bl * rtb_Saturation1_bl + 1.0F;
            rtb_Switch_b_idx_2 = rtb_Saturation_fu;
          } else {
            rtb_Saturation1_bl = rtb_Saturation_fu / rtb_Switch_b_idx_2;
            d1 += rtb_Saturation1_bl * rtb_Saturation1_bl;
          }

          d1 = rtb_Switch_b_idx_2 * sqrtf(d1);
          rtb_Switch_b_idx_2 = d1 * 0.577350259F + rtb_Saturation_bu;

          /* Switch: '<S79>/Switch' incorporates:
           *  Delay: '<S81>/start_wp'
           *  MATLAB Function: '<S79>/OutRegionRefWP'
           */
          if (rtb_Compare_a4) {
            rtb_Saturation_bu = rtb_P_k[0];
          } else {
            rtb_Saturation_bu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S80>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          rtb_Switch_b_idx_1 = rtb_Saturation_bu - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S90>/Math Function' */
          rtb_Divide_h[0] = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;
          rtb_P_k[0] = rtb_Switch_b_idx_1;

          /* Switch: '<S79>/Switch' incorporates:
           *  Delay: '<S81>/start_wp'
           *  MATLAB Function: '<S79>/OutRegionRefWP'
           *  Sum: '<S80>/Subtract'
           */
          if (rtb_Compare_a4) {
            rtb_Saturation_bu = rtb_P_k[1];
          } else {
            rtb_Saturation_bu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S80>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S18>/Signal Copy1'
           */
          rtb_Switch_b_idx_1 = rtb_Saturation_bu - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S90>/Math Function' incorporates:
           *  Math: '<S88>/Square'
           */
          rtb_Saturation_bu = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;

          /* Sum: '<S90>/Sum of Elements' incorporates:
           *  Math: '<S90>/Math Function'
           */
          rtb_Saturation_fu = rtb_Saturation_bu + rtb_Divide_h[0];

          /* Math: '<S90>/Math Function1' incorporates:
           *  Sum: '<S90>/Sum of Elements'
           *
           * About '<S90>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_fu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_fu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu);
          }

          /* End of Math: '<S90>/Math Function1' */

          /* Switch: '<S90>/Switch' incorporates:
           *  Constant: '<S90>/Constant'
           *  Product: '<S90>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_a[0] = rtb_P_k[0];
            rtb_Switch_a[1] = rtb_Switch_b_idx_1;
            rtb_Switch_a[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_a[0] = 0.0F;
            rtb_Switch_a[1] = 0.0F;
            rtb_Switch_a[2] = 1.0F;
          }

          /* End of Switch: '<S90>/Switch' */

          /* Product: '<S90>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];
          rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* Sum: '<S93>/Sum of Elements' incorporates:
           *  Math: '<S93>/Math Function'
           *  SignalConversion: '<S93>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0]
            * rtb_Divide_h[0];

          /* Math: '<S93>/Math Function1' incorporates:
           *  Sum: '<S93>/Sum of Elements'
           *
           * About '<S93>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_fu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_fu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu);
          }

          /* End of Math: '<S93>/Math Function1' */

          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S93>/Constant'
           *  Product: '<S93>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_a[0] = rtb_Divide_h[1];
            rtb_Switch_a[1] = rtb_Divide_h[0];
            rtb_Switch_a[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_a[0] = 0.0F;
            rtb_Switch_a[1] = 0.0F;
            rtb_Switch_a[2] = 1.0F;
          }

          /* End of Switch: '<S93>/Switch' */

          /* Product: '<S93>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];

          /* Product: '<S92>/Divide' */
          rtb_P_ia[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
          rtb_P_k[0] *= rtb_P_k[0];

          /* Product: '<S93>/Divide' incorporates:
           *  Math: '<S88>/Square'
           */
          rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* Product: '<S92>/Divide' */
          rtb_P_ia[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sqrt: '<S87>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S87>/Square'
           *  SignalConversion: '<S18>/Signal Copy1'
           *  Sum: '<S87>/Sum of Elements'
           */
          rtb_Switch_b_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S85>/Gain' incorporates:
           *  Math: '<S85>/Square'
           */
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0 * 2.0F;

          /* Sum: '<S91>/Subtract' incorporates:
           *  Product: '<S91>/Multiply'
           *  Product: '<S91>/Multiply1'
           */
          rtb_Switch_b_idx_0 = rtb_Divide_h[0] * rtb_P_ia[1] - rtb_Divide_h[1] *
            rtb_P_ia[0];

          /* Signum: '<S86>/Sign1' */
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_b_idx_0 > 0.0F) {
              rtb_Switch_b_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S86>/Sign1' */

          /* Switch: '<S86>/Switch2' incorporates:
           *  Constant: '<S86>/Constant4'
           */
          if (rtb_Switch_b_idx_0 == 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }

          /* End of Switch: '<S86>/Switch2' */

          /* DotProduct: '<S86>/Dot Product' */
          rtb_Switch_b_idx_2 = rtb_P_ia[0] * rtb_Divide_h[0] + rtb_P_ia[1] *
            rtb_Divide_h[1];

          /* Trigonometry: '<S86>/Acos' incorporates:
           *  DotProduct: '<S86>/Dot Product'
           */
          if (rtb_Switch_b_idx_2 > 1.0F) {
            rtb_Switch_b_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_b_idx_2 < -1.0F) {
              rtb_Switch_b_idx_2 = -1.0F;
            }
          }

          /* Product: '<S86>/Multiply' incorporates:
           *  Trigonometry: '<S86>/Acos'
           */
          rtb_Switch_b_idx_0 *= acosf(rtb_Switch_b_idx_2);

          /* Saturate: '<S85>/Saturation' */
          if (rtb_Switch_b_idx_0 > 1.57079637F) {
            rtb_Switch_b_idx_0 = 1.57079637F;
          } else {
            if (rtb_Switch_b_idx_0 < -1.57079637F) {
              rtb_Switch_b_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S85>/Saturation' */

          /* Product: '<S85>/Divide' incorporates:
           *  Constant: '<S77>/L1'
           *  Constant: '<S85>/Constant'
           *  MinMax: '<S85>/Max'
           *  MinMax: '<S85>/Min'
           *  Product: '<S85>/Multiply1'
           *  Sqrt: '<S88>/Sqrt'
           *  Sum: '<S88>/Sum of Elements'
           *  Trigonometry: '<S85>/Sin'
           */
          FMS_B.Merge_p = arm_sin_f32(rtb_Switch_b_idx_0) * rtb_Switch_b_idx_1 /
            fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_bu + rtb_P_k[0]),
                   0.5F));

          /* Update for Delay: '<S81>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S81>/start_wp' */
          FMS_DW.icLoad_c = 0U;

          /* End of Outputs for SubSystem: '<S74>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S74>/Brake Control' incorporates:
           *  ActionPort: '<S76>/Action Port'
           */
          /* SignalConversion: '<S76>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
           *  Constant: '<S76>/Brake Speed'
           */
          FMS_B.Merge_p = 0.0F;

          /* End of Outputs for SubSystem: '<S74>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S74>/Move Control' incorporates:
           *  ActionPort: '<S78>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S95>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S18>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_bu = 0.0F;
          } else {
            rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S95>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S78>/Gain6' incorporates:
           *  Gain: '<S95>/Gain'
           */
          FMS_B.Merge_p = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_bu *
            FMS_PARAM.ACC_Y_LIM;

          /* End of Outputs for SubSystem: '<S74>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S74>/Switch Case' */

        /* SwitchCase: '<S60>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy1'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ba;
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
        switch (rtb_state_g) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_ba) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ba != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S60>/Hold Control' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S60>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_l);

            /* End of SystemReset for SubSystem: '<S60>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S60>/Hold Control' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S60>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S60>/Brake Control' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S60>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S60>/Move Control' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S60>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S60>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S30>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S30>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S71>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S71>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S30>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S58>/Gain1'
         *  Gain: '<S71>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation_bu * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S56>/Gain1' incorporates:
         *  Bias: '<S56>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S18>/Signal Copy2'
         */
        rtb_Saturation_bu = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S56>/Saturation' incorporates:
         *  Gain: '<S56>/Gain1'
         */
        if (rtb_Saturation_bu > 1.0F) {
          rtb_Saturation_bu = 1.0F;
        } else {
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Saturation_bu = 0.0F;
          }
        }

        /* End of Saturate: '<S56>/Saturation' */

        /* BusAssignment: '<S30>/Bus Assignment' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         *  Gain: '<S56>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_bu;

        /* Saturate: '<S74>/Saturation1' */
        if (FMS_B.Merge_p > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (FMS_B.Merge_p < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_p;
        }

        /* End of Saturate: '<S74>/Saturation1' */

        /* Saturate: '<S60>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S20>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S60>/Saturation1' */
        /* End of Outputs for SubSystem: '<S23>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S23>/Unknown' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S20>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S23>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S23>/Switch Case' */
      /* End of Outputs for SubSystem: '<S19>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S19>/Manual' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* Saturate: '<S142>/Saturation' incorporates:
       *  Constant: '<S142>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S18>/Signal Copy2'
       *  Sum: '<S142>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_Saturation_bu = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Saturation_bu = 0.0F;
      } else {
        rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S142>/Saturation' */
      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* DataTypeConversion: '<S141>/Data Type Conversion' incorporates:
       *  Constant: '<S142>/Constant5'
       *  Gain: '<S142>/Gain4'
       *  Sum: '<S142>/Add'
       */
      rtb_DataTypeConversion = (uint16_T)fmodf(floorf(500.0F * rtb_Saturation_bu
        + 1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S141>/Data Type Conversion1' incorporates:
       *  Bias: '<S141>/Bias1'
       *  Gain: '<S141>/Gain'
       *  Gain: '<S141>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S18>/Signal Copy2'
       */
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.MANUAL_ROLL_REV *
        FMS_U.Pilot_Cmd.stick_roll * 500.0F + 1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      rtb_DataTypeConversion1_l = (uint16_T)(rtb_Saturation_bu < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)(uint16_T)
        rtb_Saturation_bu);

      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S20>/Bus Assignment'
       *  BusAssignment: '<S25>/Bus Assignment'
       *  Constant: '<S25>/Constant'
       *  SignalConversion: '<S25>/TmpHiddenBufferAtBus AssignmentInport1'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S25>/Bus Assignment' incorporates:
       *  BusAssignment: '<S20>/Bus Assignment'
       *  Constant: '<S25>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
      FMS_Y.FMS_Out.actuator_cmd[0] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[1] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[2] = rtb_DataTypeConversion1_l;
      FMS_Y.FMS_Out.actuator_cmd[3] = rtb_DataTypeConversion1_l;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S141>/Data Type Conversion2' incorporates:
       *  Bias: '<S141>/Bias2'
       *  Gain: '<S141>/Gain2'
       *  Gain: '<S141>/Gain4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S18>/Signal Copy2'
       */
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.MANUAL_PITCH_REV *
        FMS_U.Pilot_Cmd.stick_pitch * -500.0F + 1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S25>/Bus Assignment' incorporates:
       *  BusAssignment: '<S20>/Bus Assignment'
       *  DataTypeConversion: '<S141>/Data Type Conversion2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S141>/Data Type Conversion3' incorporates:
       *  Bias: '<S141>/Bias3'
       *  Gain: '<S141>/Gain3'
       *  Gain: '<S141>/Gain5'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S18>/Signal Copy2'
       */
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.MANUAL_YAW_REV *
        FMS_U.Pilot_Cmd.stick_yaw * 500.0F + 1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S25>/Bus Assignment' incorporates:
       *  BusAssignment: '<S20>/Bus Assignment'
       *  DataTypeConversion: '<S141>/Data Type Conversion3'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);
      for (i = 0; i < 10; i++) {
        FMS_Y.FMS_Out.actuator_cmd[i + 6] = 0U;
      }

      /* End of Outputs for SubSystem: '<S19>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S19>/Unknown' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S20>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S19>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S19>/Switch Case' */
    /* End of Outputs for SubSystem: '<S17>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S17>/Switch Case' */

  /* BusAssignment: '<S20>/Bus Assignment' incorporates:
   *  Constant: '<S20>/Constant'
   *  DataStoreRead: '<S20>/Data Store Read'
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   *  DiscreteIntegrator: '<S210>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S18>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S20>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S210>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S210>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */
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
  /* Start for SwitchCase: '<S17>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S17>/Arm' */
  /* Start for SwitchCase: '<S19>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S19>/SubMode' */
  /* Start for SwitchCase: '<S26>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S19>/SubMode' */

  /* Start for IfAction SubSystem: '<S19>/Auto' */
  /* Start for SwitchCase: '<S24>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S19>/Auto' */

  /* Start for IfAction SubSystem: '<S19>/Assist' */
  /* Start for SwitchCase: '<S23>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S23>/Altitude' */
  /* Start for SwitchCase: '<S39>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* End of Start for SubSystem: '<S23>/Altitude' */

  /* Start for IfAction SubSystem: '<S23>/Position' */
  /* Start for SwitchCase: '<S74>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S60>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;

  /* End of Start for SubSystem: '<S23>/Position' */
  /* End of Start for SubSystem: '<S19>/Assist' */
  /* End of Start for SubSystem: '<S17>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

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
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
  /* SystemInitialize for IfAction SubSystem: '<S17>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S19>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S26>/Hold' */
  /* InitializeConditions for Delay: '<S153>/start_vel' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for Delay: '<S148>/Delay' */
  FMS_DW.icLoad_b = 1U;

  /* End of SystemInitialize for SubSystem: '<S26>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S19>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S19>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Mission' */
  /* InitializeConditions for UnitDelay: '<S117>/Delay Input1'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S24>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S19>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S19>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S23>/Altitude' */
  /* SystemInitialize for Chart: '<S40>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S39>/Hold Control' */

  /* SystemInitialize for Merge: '<S39>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S23>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S23>/Position' */
  /* SystemInitialize for Chart: '<S61>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S75>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S74>/Hold Control' */
  /* InitializeConditions for Delay: '<S81>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S81>/start_wp' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S74>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S60>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_l);

  /* End of SystemInitialize for SubSystem: '<S60>/Hold Control' */

  /* SystemInitialize for Merge: '<S60>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S74>/Merge' */
  FMS_B.Merge_p = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S23>/Position' */
  /* End of SystemInitialize for SubSystem: '<S19>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S17>/Arm' */
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
