/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1987
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 12:17:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S34>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S58>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Altitude                ((uint8_T)1U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)2U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)2U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)3U)
#define FMS_IN_Return                  ((uint8_T)2U)
#define FMS_IN_Return_h                ((uint8_T)3U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)4U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude_e              ((uint8_T)2U)
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
struct_d9c0tvJ8oGGPXhDK6NoMmH FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  6.0F,
  2.5F,
  30.0F,
  5.0F,
  50.0F,
  0.25F,
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S109>/vel'
                                        *   '<S31>/Gain6'
                                        *   '<S32>/Gain6'
                                        *   '<S45>/Gain6'
                                        *   '<S75>/Gain6'
                                        *   '<S76>/Gain6'
                                        *   '<S77>/Gain6'
                                        *   '<S85>/vel'
                                        *   '<S111>/Gain'
                                        *   '<S111>/Saturation1'
                                        *   '<S112>/L1'
                                        *   '<S33>/Saturation1'
                                        *   '<S42>/Dead Zone'
                                        *   '<S42>/Gain'
                                        *   '<S43>/Dead Zone'
                                        *   '<S43>/Gain'
                                        *   '<S47>/Saturation1'
                                        *   '<S56>/Dead Zone'
                                        *   '<S56>/Gain'
                                        *   '<S57>/Saturation1'
                                        *   '<S78>/Dead Zone'
                                        *   '<S78>/Gain'
                                        *   '<S79>/Dead Zone'
                                        *   '<S79>/Gain'
                                        *   '<S80>/Dead Zone'
                                        *   '<S80>/Gain'
                                        *   '<S86>/Gain'
                                        *   '<S86>/Saturation1'
                                        *   '<S87>/L1'
                                        *   '<S116>/AccToRate'
                                        *   '<S36>/Gain2'
                                        *   '<S37>/Gain1'
                                        *   '<S40>/Constant'
                                        *   '<S50>/Gain2'
                                        *   '<S51>/Gain1'
                                        *   '<S54>/Constant'
                                        *   '<S60>/Gain2'
                                        *   '<S61>/Gain6'
                                        *   '<S67>/Constant'
                                        *   '<S91>/AccToRate'
                                        *   '<S39>/Dead Zone'
                                        *   '<S39>/Gain'
                                        *   '<S53>/Dead Zone'
                                        *   '<S53>/Gain'
                                        *   '<S65>/Dead Zone'
                                        *   '<S65>/Gain'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT = {
  4U,

  { 83, 117, 98, 109, 97, 114, 105, 110, 101, 32, 70, 77, 83, 32, 118, 48, 46,
    48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S133>/Constant'
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
static real_T FMS_getArmMode(PilotMode pilotMode);
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
 *    '<S118>/NearbyRefWP'
 *    '<S93>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S122>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_p;
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
 *    '<S118>/OutRegionRegWP'
 *    '<S93>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_d, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S123>/TmpSignal ConversionAt SFunction Inport3' */
  P1P3_idx_0 = rtu_P3 - rtu_P1[0];
  P1P3_idx_1 = rtu_P3_d - rtu_P1[1];
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
 * Output and update for atomic system:
 *    '<S118>/SearchL1RefWP'
 *    '<S93>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2],
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

  /* SignalConversion: '<S124>/TmpSignal ConversionAt SFunction Inport3' */
  B = ((rtu_P2[0] - rtu_P1[0]) * (rtu_P1[0] - rtu_P3) + (rtu_P2[1] - rtu_P1[1]) *
       (rtu_P1[1] - rtu_P3_d)) * 2.0F;
  D = B * B - (((((rtu_P3 * rtu_P3 + rtu_P3_d * rtu_P3_d) + rtu_P1[0] * rtu_P1[0])
                 + rtu_P1[1] * rtu_P1[1]) - (rtu_P3 * rtu_P1[0] + rtu_P3_d *
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
 *    '<S24>/Unknown'
 *    '<S22>/Unknown'
 *    '<S21>/Unknown'
 *    '<S17>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S110>/Bus Assignment' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S110>/Constant2'
   *  SignalConversion: '<S110>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S110>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S33>/Hold Control'
 *    '<S47>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S36>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S33>/Hold Control'
 *    '<S47>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S36>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S33>/Hold Control'
 *    '<S47>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S36>/Delay' incorporates:
   *  Gain: '<S38>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S36>/Gain2' incorporates:
   *  Delay: '<S36>/Delay'
   *  Gain: '<S38>/Gain'
   *  Sum: '<S36>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S36>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S33>/Brake Control'
 *    '<S47>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_w_cmd_mPs)
{
  /* SignalConversion: '<S35>/OutportBuffer_InsertedFor_w_cmd_mPs_at_inport_0' incorporates:
   *  Constant: '<S35>/Brake Speed'
   */
  *rty_w_cmd_mPs = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S33>/Move Control'
 *    '<S47>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S39>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S39>/Dead Zone' */

  /* Gain: '<S37>/Gain1' incorporates:
   *  Gain: '<S39>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtu_FMS_In_0 *
    -FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S34>/Motion Status'
 *    '<S48>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S34>/Motion Status'
 *    '<S48>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S34>/Motion Status'
 *    '<S48>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S34>/Motion Status' */
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
      if ((rtu_speed <= 0.1) || (localDW->temporalCounter_i1 >= 375U)) {
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

  /* End of Chart: '<S34>/Motion Status' */
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_k, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = false;
  switch (cmd_in) {
   case FMS_Cmd_Takeoff:
   case FMS_Cmd_Land:
   case FMS_Cmd_Return:
   case FMS_Cmd_Pause:
    if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag & 8U) ==
         0U)) {
      valid = true;
    }

    if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag &
          128U) != 0U)) {
      valid = true;
    }
    break;

   case FMS_Cmd_PreArm:
    if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag & 8U) ==
         0U)) {
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_k, &FMS_DW.Msg_FMS_Cmd_d
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_d[0] : NULL;
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
    FMS_B.state = VehicleState_Offboard;
    break;

   case PilotMode_Mission:
    FMS_DW.is_Auto = FMS_IN_Mission;
    FMS_DW.llo[0] = FMS_B.BusConversion_InsertedFor_FMSSt.lat *
      57.295779513082323;
    FMS_DW.llo[1] = FMS_B.BusConversion_InsertedFor_FMSSt.lon *
      57.295779513082323;
    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
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
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real_T tmp;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S146>/Compare' incorporates:
   *  Abs: '<S135>/Abs'
   *  Constant: '<S146>/Constant'
   *  MinMax: '<S135>/Max'
   *  Sum: '<S135>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S3>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
    tmp = FMS_getArmMode(FMS_B.target_mode);
    if (tmp == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.target_mode) {
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Return:
        scale = 1.29246971E-26F;
        absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0]);
        if (absxk > 1.29246971E-26F) {
          y = 1.0F;
          scale = absxk;
        } else {
          t = absxk / 1.29246971E-26F;
          y = t * t;
        }

        absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }

        y = scale * sqrtf(y);

        /* Constant: '<Root>/ACCEPT_R' */
        if (y <= FMS_PARAM.ACCEPT_R) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
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
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_n;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_n;
    } else {
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_n;
    }

    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_n;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_n;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T b_sf_internal_predicateOutput;
  real_T rtb_Multiply2;
  real_T rtb_Sum2_m;
  real_T rtb_Gain;
  real_T rtb_Sum_d;
  real32_T tmp[2];
  real_T rtb_Sum_idx_0;
  uint32_T qY;
  int32_T lla_tmp;
  if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
       PilotMode_None)) {
    rtb_Sum_idx_0 = FMS_getArmMode(FMS_B.target_mode);
    if (rtb_Sum_idx_0 == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (rtb_Sum_idx_0 == 2.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.target_mode) {
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
    } else if (rtb_Sum_idx_0 == 1.0) {
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
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
        FMS_Cmd_Return);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
      FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Return;
      FMS_B.state = VehicleState_Return;
    } else {
      switch (FMS_DW.is_Arm) {
       case FMS_IN_Assist:
        if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
          FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }
        break;

       case FMS_IN_Auto:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Pause);
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          if (FMS_DW.is_Auto == FMS_IN_Mission) {
            FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_n;
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_n;
          } else {
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_n;
          }

          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
          FMS_DW.is_SubMode = FMS_IN_Hold_h;
          FMS_B.state = VehicleState_Hold;
        } else {
          switch (FMS_DW.is_Auto) {
           case FMS_IN_InvalidAutoMode:
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_n;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
            break;

           case FMS_IN_Mission:
            if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start)
            {
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
               case FMS_IN_Loiter:
                break;

               case FMS_IN_NextWP:
                if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
                  FMS_DW.is_Mission = FMS_IN_Waypoint;
                  lla_tmp = FMS_B.wp_index - 1;

                  /* Inport: '<Root>/Mission_Data' */
                  FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] * 1.0E-7;
                  FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] * 1.0E-7;
                  FMS_B.lla[2] = -FMS_U.Mission_Data.z[lla_tmp];
                  FMS_B.href = 0.0;
                  FMS_B.psio = 0.0;
                  FMS_B.llo[0] = FMS_DW.llo[0];

                  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Sum: '<S136>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S136>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S137>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S137>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S137>/Multiply1' incorporates:
                   *  Product: '<S137>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S137>/Divide' incorporates:
                   *  Constant: '<S137>/Constant'
                   *  Constant: '<S137>/R'
                   *  Sqrt: '<S137>/Sqrt'
                   *  Sum: '<S137>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S137>/Product3' incorporates:
                   *  Constant: '<S137>/Constant1'
                   *  Product: '<S137>/Multiply1'
                   *  Sum: '<S137>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S137>/Multiply2' incorporates:
                   *  Trigonometry: '<S137>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S141>/Abs' incorporates:
                   *  Abs: '<S144>/Abs1'
                   *  Switch: '<S141>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S141>/Switch1' incorporates:
                   *  Abs: '<S141>/Abs'
                   *  Bias: '<S141>/Bias2'
                   *  Bias: '<S141>/Bias3'
                   *  Constant: '<S138>/Constant'
                   *  Constant: '<S138>/Constant1'
                   *  Constant: '<S143>/Constant'
                   *  Gain: '<S141>/Gain1'
                   *  Product: '<S141>/Multiply'
                   *  RelationalOperator: '<S143>/Compare'
                   *  Switch: '<S138>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S144>/Switch1' incorporates:
                     *  Bias: '<S144>/Bias2'
                     *  Bias: '<S144>/Bias3'
                     *  Constant: '<S144>/Constant'
                     *  Constant: '<S145>/Constant'
                     *  Math: '<S144>/Math Function'
                     *  RelationalOperator: '<S145>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S144>/Switch1' */

                    /* Signum: '<S141>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S141>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S138>/Sum' incorporates:
                   *  Sum: '<S136>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S136>/Multiply' incorporates:
                   *  Gain: '<S136>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S140>/Switch1' incorporates:
                   *  Abs: '<S140>/Abs1'
                   *  Bias: '<S140>/Bias2'
                   *  Bias: '<S140>/Bias3'
                   *  Constant: '<S140>/Constant'
                   *  Constant: '<S142>/Constant'
                   *  Math: '<S140>/Math Function'
                   *  RelationalOperator: '<S142>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S140>/Switch1' */

                  /* Product: '<S136>/Multiply' incorporates:
                   *  Gain: '<S136>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S136>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S139>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S139>/Sum2' incorporates:
                   *  Product: '<S139>/Multiply1'
                   *  Product: '<S139>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S139>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S139>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S139>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S134>/Data Type Conversion' incorporates:
                   *  Gain: '<S136>/Gain'
                   *  Sum: '<S136>/Sum1'
                   */
                  FMS_B.DataTypeConversion[0] = (real32_T)rtb_Sum2_m;
                  FMS_B.DataTypeConversion[1] = (real32_T)rtb_Sum_d;
                  FMS_B.DataTypeConversion[2] = (real32_T)-(FMS_B.lla[2] +
                    FMS_B.href);

                  /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0] +
                    FMS_DW.home[0];
                  FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1] +
                    FMS_DW.home[1];
                  FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2] +
                    FMS_DW.home[2];
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
                  FMS_DW.is_Mission = FMS_IN_Loiter;
                  FMS_B.state = VehicleState_Hold;
                }
                break;

               case FMS_IN_Return_h:
                tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                  FMS_B.Cmd_In.sp_waypoint[0];
                tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                  FMS_B.Cmd_In.sp_waypoint[1];
                if (FMS_norm(tmp) < 0.5F) {
                  lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                  if ((uint32_T)lla_tmp > 255U) {
                    lla_tmp = 255;
                  }

                  FMS_B.wp_index = (uint8_T)lla_tmp;
                  FMS_DW.is_Mission = FMS_IN_NextWP;

                  /* Inport: '<Root>/Mission_Data' */
                  if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                    FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index -
                      1];
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
                  FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
                  FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
                  FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
                  lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                  if ((uint32_T)lla_tmp > 255U) {
                    lla_tmp = 255;
                  }

                  FMS_B.wp_index = (uint8_T)lla_tmp;
                  FMS_DW.is_Mission = FMS_IN_NextWP;

                  /* Inport: '<Root>/Mission_Data' */
                  if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                    FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index -
                      1];
                  } else {
                    FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
                    qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
                    if (qY > FMS_B.wp_index) {
                      qY = 0U;
                    }

                    FMS_B.wp_consume = (uint8_T)qY;
                  }
                }

                /* End of Constant: '<Root>/ACCEPT_R' */
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
        FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
        break;

       case FMS_IN_Manual:
        if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
          FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
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

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode)
{
  real_T trigger;
  trigger = 0.0;
  switch (pilot_cmd_mode) {
   case PilotMode_Stabilize:
   case PilotMode_Altitude:
   case PilotMode_Position:
    if (pilot_cmd_stick_throttle > 0.0F) {
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_n;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_mission = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_1))
      {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_n;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_n;
      break;
    }

    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    guard1 = false;
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
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_Vehicle = FMS_IN_Standby;
        FMS_DW.temporalCounter_i1 = 0U;
        guard2 = false;
        if (FMS_B.target_mode == PilotMode_Mission) {
          if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
            FMS_DW.prep_mission = 1.0;
            FMS_DW.condWasTrueAtLastTimeStep_1 = (FMS_DW.prep_mission == 1.0);
            guard2 = true;
          } else {
            b_previousEvent = FMS_DW.sfEvent;
            FMS_DW.sfEvent = FMS_event_DisarmEvent;

            /* Chart: '<Root>/FMS State Machine' */
            FMS_c11_FMS();
            FMS_DW.sfEvent = b_previousEvent;
            if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
            } else {
              guard2 = true;
            }
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
          FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
          FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
          FMS_B.state = VehicleState_Standby;
        }

        if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
          sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
        }
      }
      break;

     case FMS_IN_Standby:
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.target_mode != PilotMode_None)) {
        guard1 = true;
      } else if ((FMS_DW.temporalCounter_i1 >= 2500U) || (FMS_DW.sfEvent ==
                  FMS_event_DisarmEvent)) {
        FMS_DW.prep_mission = 0.0;
        sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 500) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      FMS_DW.prep_mission = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_1))
      {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_enter_internal_Arm();
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
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
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
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
          FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_h > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2 > 375) {
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
              FMS_DW.durationLastReferenceTick_1_h =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_k, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_d[1]);
}

/* Model step function */
void FMS_step(void)
{
  int8_T rtPrevAction;
  real32_T rtb_TmpSignalConversionAtSign_0[3];
  real32_T rtb_Saturation_k;
  real32_T rtb_AccToRate_k;
  real32_T rtb_Divide_c[2];
  real32_T rtb_Switch_f[3];
  MotionState rtb_state_cv;
  real32_T rtb_MatrixConcatenate1[9];
  MotionState rtb_state;
  real32_T rtb_u_h;
  boolean_T rtb_Compare_a;
  real32_T rtb_P_i[2];
  real32_T rtb_u;
  real32_T rtb_P_c[2];
  int32_T i;
  real32_T rtb_Switch_h_idx_0;
  real32_T rtb_Switch_h_idx_1;
  real32_T rtb_Switch_h_idx_2;
  real32_T rtb_MatrixConcatenate1_tmp;
  real32_T rtb_MatrixConcatenate1_tmp_0;
  real32_T rtb_MatrixConcatenate1_tmp_1;
  real32_T rtb_MatrixConcatenate1_tmp_2;
  real32_T rtb_MatrixConcatenate1_tmp_3;

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
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Delay: '<S7>/Delay'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator1'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/FixPt Relational Operator'
   *  RelationalOperator: '<S8>/Compare'
   *  Switch: '<S7>/Switch1'
   *  UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
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

  /* Switch: '<S6>/Switch1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  Switch: '<S6>/Switch2'
   *  UnitDelay: '<S10>/Delay Input1'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
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
  rtb_u = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_u < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_u;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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

     case FMS_IN_Altitude_e:
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_Compare_a = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_Compare_a) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_Compare_a;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
    FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
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
  /* SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_f[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_TmpSignalConversionAtSign_0[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_f[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_TmpSignalConversionAtSign_0[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_f[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_TmpSignalConversionAtSign_0[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* SwitchCase: '<S15>/Switch Case' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S17>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S24>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S22>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S21>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
       case 0:
       case 3:
        break;

       case 1:
        /* Disable for SwitchCase: '<S33>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S57>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S47>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S17>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S15>/Disarm' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  BusAssignment: '<S19>/Bus Assignment'
     *  Constant: '<S19>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S19>/Bus Assignment' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  Constant: '<S19>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a0;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_bg;

    /* End of Outputs for SubSystem: '<S15>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S15>/Standby' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  BusAssignment: '<S20>/Bus Assignment'
     *  Constant: '<S20>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S20>/Bus Assignment' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  Constant: '<S20>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_oj;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nz;

    /* End of Outputs for SubSystem: '<S15>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S15>/Arm' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* SwitchCase: '<S17>/Switch Case' */
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
        /* Disable for SwitchCase: '<S24>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S22>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S21>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S33>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S57>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S47>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        break;

       case 3:
       case 4:
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S17>/SubMode' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* SwitchCase: '<S24>/Switch Case' */
      switch (FMS_B.state) {
       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S109>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S126>/TmpSignal ConversionAtSquareInport1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_c[0] = FMS_U.INS_Out.vn;
        rtb_Divide_c[1] = FMS_U.INS_Out.ve;

        /* Sum: '<S128>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S128>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S126>/Sum of Elements'
         */
        rtb_u = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S128>/Math Function1' incorporates:
         *  Sum: '<S128>/Sum of Elements'
         *
         * About '<S128>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_u));
        } else {
          rtb_Saturation_k = sqrtf(rtb_u);
        }

        /* End of Math: '<S128>/Math Function1' */

        /* Switch: '<S128>/Switch' incorporates:
         *  Constant: '<S128>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S128>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Saturation_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_h_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_h_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_h_idx_2 = rtb_Saturation_k;
        } else {
          rtb_Switch_h_idx_0 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_h_idx_2 = 1.0F;
        }

        /* End of Switch: '<S128>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S118>/NearbyRefWP' incorporates:
         *  Constant: '<S112>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_f[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_c, &rtb_AccToRate_k);

        /* MATLAB Function: '<S118>/SearchL1RefWP' incorporates:
         *  Constant: '<S112>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_f[0],
                          FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                          rtb_P_c, &rtb_u_h);

        /* MATLAB Function: '<S118>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_f[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_i);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S118>/Switch1' incorporates:
         *  Constant: '<S121>/Constant'
         *  RelationalOperator: '<S121>/Compare'
         */
        if (rtb_AccToRate_k > 0.0F) {
          rtb_P_c[0] = rtb_Divide_c[0];
          rtb_P_c[1] = rtb_Divide_c[1];
        } else {
          /* RelationalOperator: '<S120>/Compare' incorporates:
           *  Constant: '<S120>/Constant'
           */
          rtb_Compare_a = (rtb_u_h >= 0.0F);

          /* Switch: '<S118>/Switch' */
          if (!rtb_Compare_a) {
            rtb_P_c[0] = rtb_P_i[0];
            rtb_P_c[1] = rtb_P_i[1];
          }

          /* End of Switch: '<S118>/Switch' */
        }

        /* End of Switch: '<S118>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S119>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_c[0] = rtb_P_c[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_c[1] = rtb_P_c[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S129>/Sum of Elements' incorporates:
         *  Math: '<S129>/Math Function'
         *  Sum: '<S127>/Sum of Elements'
         */
        rtb_u_h = rtb_Divide_c[0] * rtb_Divide_c[0] + rtb_Divide_c[1] *
          rtb_Divide_c[1];

        /* Math: '<S129>/Math Function1' incorporates:
         *  Sum: '<S129>/Sum of Elements'
         *
         * About '<S129>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u_h < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_u_h));
        } else {
          rtb_Saturation_k = sqrtf(rtb_u_h);
        }

        /* End of Math: '<S129>/Math Function1' */

        /* Switch: '<S129>/Switch' incorporates:
         *  Constant: '<S129>/Constant'
         *  Product: '<S129>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_f[0] = rtb_Divide_c[0];
          rtb_Switch_f[1] = rtb_Divide_c[1];
          rtb_Switch_f[2] = rtb_Saturation_k;
        } else {
          rtb_Switch_f[0] = 0.0F;
          rtb_Switch_f[1] = 0.0F;
          rtb_Switch_f[2] = 1.0F;
        }

        /* End of Switch: '<S129>/Switch' */

        /* Product: '<S128>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;
        rtb_Divide_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Sum: '<S131>/Sum of Elements' incorporates:
         *  Math: '<S131>/Math Function'
         *  SignalConversion: '<S131>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_k = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S131>/Math Function1' incorporates:
         *  Sum: '<S131>/Sum of Elements'
         *
         * About '<S131>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_Saturation_k));
        } else {
          rtb_Saturation_k = sqrtf(rtb_Saturation_k);
        }

        /* End of Math: '<S131>/Math Function1' */

        /* Switch: '<S131>/Switch' incorporates:
         *  Constant: '<S131>/Constant'
         *  Product: '<S131>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_h_idx_0 = rtb_Divide_c[1];
          rtb_Switch_h_idx_1 = rtb_Divide_c[0];
          rtb_Switch_h_idx_2 = rtb_Saturation_k;
        } else {
          rtb_Switch_h_idx_0 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_h_idx_2 = 1.0F;
        }

        /* End of Switch: '<S131>/Switch' */

        /* Product: '<S129>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_f[0] / rtb_Switch_f[2];
        rtb_Divide_c[1] = rtb_Switch_f[1] / rtb_Switch_f[2];

        /* Sum: '<S132>/Sum of Elements' incorporates:
         *  Math: '<S132>/Math Function'
         *  SignalConversion: '<S132>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_k = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S132>/Math Function1' incorporates:
         *  Sum: '<S132>/Sum of Elements'
         *
         * About '<S132>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_Saturation_k));
        } else {
          rtb_Saturation_k = sqrtf(rtb_Saturation_k);
        }

        /* End of Math: '<S132>/Math Function1' */

        /* Switch: '<S132>/Switch' incorporates:
         *  Constant: '<S132>/Constant'
         *  Product: '<S132>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_f[0] = rtb_Divide_c[1];
          rtb_Switch_f[1] = rtb_Divide_c[0];
          rtb_Switch_f[2] = rtb_Saturation_k;
        } else {
          rtb_Switch_f[0] = 0.0F;
          rtb_Switch_f[1] = 0.0F;
          rtb_Switch_f[2] = 1.0F;
        }

        /* End of Switch: '<S132>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S113>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_k = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_AccToRate_k = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S132>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_f[0] / rtb_Switch_f[2];

        /* Product: '<S131>/Divide' */
        rtb_P_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S113>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S132>/Divide' */
        rtb_Divide_c[1] = rtb_Switch_f[1] / rtb_Switch_f[2];

        /* Product: '<S131>/Divide' */
        rtb_P_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S113>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S113>/Divide' incorporates:
         *  Math: '<S114>/Square'
         *  Math: '<S115>/Square'
         *  Sqrt: '<S114>/Sqrt'
         *  Sqrt: '<S115>/Sqrt'
         *  Sum: '<S113>/Sum'
         *  Sum: '<S113>/Sum1'
         *  Sum: '<S114>/Sum of Elements'
         *  Sum: '<S115>/Sum of Elements'
         */
        rtb_Switch_h_idx_2 = sqrtf(rtb_AccToRate_k * rtb_AccToRate_k +
          rtb_Saturation_k * rtb_Saturation_k) / sqrtf(rtb_Switch_h_idx_0 *
          rtb_Switch_h_idx_0 + rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1);

        /* Saturate: '<S113>/Saturation' */
        if (rtb_Switch_h_idx_2 > 1.0F) {
          rtb_Switch_h_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_2 < 0.0F) {
            rtb_Switch_h_idx_2 = 0.0F;
          }
        }

        /* End of Saturate: '<S113>/Saturation' */

        /* Sum: '<S130>/Subtract' incorporates:
         *  Product: '<S130>/Multiply'
         *  Product: '<S130>/Multiply1'
         */
        rtb_Saturation_k = rtb_Divide_c[0] * rtb_P_c[1] - rtb_Divide_c[1] *
          rtb_P_c[0];

        /* Signum: '<S125>/Sign1' */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -1.0F;
        } else {
          if (rtb_Saturation_k > 0.0F) {
            rtb_Saturation_k = 1.0F;
          }
        }

        /* End of Signum: '<S125>/Sign1' */

        /* Switch: '<S125>/Switch2' incorporates:
         *  Constant: '<S125>/Constant4'
         */
        if (rtb_Saturation_k == 0.0F) {
          rtb_Saturation_k = 1.0F;
        }

        /* End of Switch: '<S125>/Switch2' */

        /* DotProduct: '<S125>/Dot Product' */
        rtb_Switch_h_idx_1 = rtb_P_c[0] * rtb_Divide_c[0] + rtb_P_c[1] *
          rtb_Divide_c[1];

        /* Trigonometry: '<S125>/Acos' incorporates:
         *  DotProduct: '<S125>/Dot Product'
         */
        if (rtb_Switch_h_idx_1 > 1.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_1 < -1.0F) {
            rtb_Switch_h_idx_1 = -1.0F;
          }
        }

        /* Product: '<S125>/Multiply' incorporates:
         *  Trigonometry: '<S125>/Acos'
         */
        rtb_Saturation_k *= acosf(rtb_Switch_h_idx_1);

        /* Saturate: '<S119>/Saturation' */
        if (rtb_Saturation_k > 1.57079637F) {
          rtb_Saturation_k = 1.57079637F;
        } else {
          if (rtb_Saturation_k < -1.57079637F) {
            rtb_Saturation_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S119>/Saturation' */

        /* Sqrt: '<S126>/Sqrt' */
        rtb_AccToRate_k = sqrtf(rtb_u);

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S109>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S109>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S109>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S109>/vel'
         *  Constant: '<S112>/L1'
         *  Constant: '<S119>/Constant'
         *  Gain: '<S116>/AccToRate'
         *  Gain: '<S119>/Gain'
         *  Math: '<S119>/Square'
         *  MinMax: '<S119>/Max'
         *  MinMax: '<S119>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S119>/Divide'
         *  Product: '<S119>/Multiply1'
         *  Sqrt: '<S127>/Sqrt'
         *  Trigonometry: '<S119>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = rtb_AccToRate_k * rtb_AccToRate_k * 2.0F *
          arm_sin_f32(rtb_Saturation_k) / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_u_h), 0.5F)) * FMS_PARAM.ACC2RATE;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S111>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S113>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S111>/Sum2'
         *  Sum: '<S113>/Add'
         *  Sum: '<S113>/Subtract'
         */
        rtb_u = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                   FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_h_idx_2 +
                  FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S111>/Saturation1' */
        if (rtb_u > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S109>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_u < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S109>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S109>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_u;
        }

        /* End of Saturate: '<S111>/Saturation1' */
        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S108>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S108>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S108>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S108>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S108>/Constant3'
         *  Constant: '<S108>/Constant4'
         *  Constant: '<S108>/Constant6'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.ay_cmd = 0.0F;
        FMS_Y.FMS_Out.w_cmd = 0.0F;

        /* End of Outputs for SubSystem: '<S24>/Hold' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S110>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S24>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S24>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S17>/Auto' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* SwitchCase: '<S22>/Switch Case' incorporates:
       *  RelationalOperator: '<S84>/FixPt Relational Operator'
       *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S84>/Delay Input1'
       *
       * Block description for '<S84>/Delay Input1':
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
        /* Outputs for IfAction SubSystem: '<S22>/Offboard' incorporates:
         *  ActionPort: '<S82>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S82>/Bus Assignment'
         *  Constant: '<S82>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S82>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S22>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S22>/Mission' incorporates:
           *  ActionPort: '<S81>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  UnitDelay: '<S84>/Delay Input1'
           *
           * Block description for '<S84>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S22>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S81>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S81>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S85>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Math: '<S103>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  RelationalOperator: '<S84>/FixPt Relational Operator'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S84>/Delay Input1'
         *
         * Block description for '<S84>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Divide_c[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_c[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S103>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S103>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_u = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S103>/Math Function1' incorporates:
         *  Sum: '<S103>/Sum of Elements'
         *
         * About '<S103>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u));
        } else {
          rtb_u_h = sqrtf(rtb_u);
        }

        /* End of Math: '<S103>/Math Function1' */

        /* Switch: '<S103>/Switch' incorporates:
         *  Constant: '<S103>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S103>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_u_h > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_h_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_h_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_h_idx_2 = rtb_u_h;
        } else {
          rtb_Switch_h_idx_0 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_h_idx_2 = 1.0F;
        }

        /* End of Switch: '<S103>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S93>/NearbyRefWP' incorporates:
         *  Constant: '<S87>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_f[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_c, &rtb_Saturation_k);

        /* MATLAB Function: '<S93>/SearchL1RefWP' incorporates:
         *  Constant: '<S87>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_f[0],
                          FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                          rtb_P_c, &rtb_u);

        /* MATLAB Function: '<S93>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_f[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_i);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S93>/Switch1' incorporates:
         *  Constant: '<S96>/Constant'
         *  RelationalOperator: '<S96>/Compare'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_P_c[0] = rtb_Divide_c[0];
          rtb_P_c[1] = rtb_Divide_c[1];
        } else {
          /* RelationalOperator: '<S95>/Compare' incorporates:
           *  Constant: '<S95>/Constant'
           */
          rtb_Compare_a = (rtb_u >= 0.0F);

          /* Switch: '<S93>/Switch' */
          if (!rtb_Compare_a) {
            rtb_P_c[0] = rtb_P_i[0];
            rtb_P_c[1] = rtb_P_i[1];
          }

          /* End of Switch: '<S93>/Switch' */
        }

        /* End of Switch: '<S93>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S94>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_c[0] = rtb_P_c[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_c[1] = rtb_P_c[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S104>/Sum of Elements' incorporates:
         *  Math: '<S104>/Math Function'
         *  Sum: '<S102>/Sum of Elements'
         */
        rtb_u = rtb_Divide_c[0] * rtb_Divide_c[0] + rtb_Divide_c[1] *
          rtb_Divide_c[1];

        /* Math: '<S104>/Math Function1' incorporates:
         *  Sum: '<S104>/Sum of Elements'
         *
         * About '<S104>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u));
        } else {
          rtb_u_h = sqrtf(rtb_u);
        }

        /* End of Math: '<S104>/Math Function1' */

        /* Switch: '<S104>/Switch' incorporates:
         *  Constant: '<S104>/Constant'
         *  Product: '<S104>/Product'
         */
        if (rtb_u_h > 0.0F) {
          rtb_Switch_f[0] = rtb_Divide_c[0];
          rtb_Switch_f[1] = rtb_Divide_c[1];
          rtb_Switch_f[2] = rtb_u_h;
        } else {
          rtb_Switch_f[0] = 0.0F;
          rtb_Switch_f[1] = 0.0F;
          rtb_Switch_f[2] = 1.0F;
        }

        /* End of Switch: '<S104>/Switch' */

        /* Product: '<S103>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;
        rtb_Divide_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Sum: '<S106>/Sum of Elements' incorporates:
         *  Math: '<S106>/Math Function'
         *  SignalConversion: '<S106>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_u_h = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S106>/Math Function1' incorporates:
         *  Sum: '<S106>/Sum of Elements'
         *
         * About '<S106>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u_h < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u_h));
        } else {
          rtb_u_h = sqrtf(rtb_u_h);
        }

        /* End of Math: '<S106>/Math Function1' */

        /* Switch: '<S106>/Switch' incorporates:
         *  Constant: '<S106>/Constant'
         *  Product: '<S106>/Product'
         */
        if (rtb_u_h > 0.0F) {
          rtb_Switch_h_idx_0 = rtb_Divide_c[1];
          rtb_Switch_h_idx_1 = rtb_Divide_c[0];
          rtb_Switch_h_idx_2 = rtb_u_h;
        } else {
          rtb_Switch_h_idx_0 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_h_idx_2 = 1.0F;
        }

        /* End of Switch: '<S106>/Switch' */

        /* Product: '<S104>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_f[0] / rtb_Switch_f[2];
        rtb_Divide_c[1] = rtb_Switch_f[1] / rtb_Switch_f[2];

        /* Sum: '<S107>/Sum of Elements' incorporates:
         *  Math: '<S107>/Math Function'
         *  SignalConversion: '<S107>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_u_h = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S107>/Math Function1' incorporates:
         *  Sum: '<S107>/Sum of Elements'
         *
         * About '<S107>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u_h < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u_h));
        } else {
          rtb_u_h = sqrtf(rtb_u_h);
        }

        /* End of Math: '<S107>/Math Function1' */

        /* Switch: '<S107>/Switch' incorporates:
         *  Constant: '<S107>/Constant'
         *  Product: '<S107>/Product'
         */
        if (rtb_u_h > 0.0F) {
          rtb_Switch_f[0] = rtb_Divide_c[1];
          rtb_Switch_f[1] = rtb_Divide_c[0];
          rtb_Switch_f[2] = rtb_u_h;
        } else {
          rtb_Switch_f[0] = 0.0F;
          rtb_Switch_f[1] = 0.0F;
          rtb_Switch_f[2] = 1.0F;
        }

        /* End of Switch: '<S107>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S88>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_u_h = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_k = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S107>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_f[0] / rtb_Switch_f[2];

        /* Product: '<S106>/Divide' */
        rtb_P_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S88>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S107>/Divide' */
        rtb_Divide_c[1] = rtb_Switch_f[1] / rtb_Switch_f[2];

        /* Product: '<S106>/Divide' */
        rtb_P_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S88>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S88>/Divide' incorporates:
         *  Math: '<S89>/Square'
         *  Math: '<S90>/Square'
         *  Sqrt: '<S89>/Sqrt'
         *  Sqrt: '<S90>/Sqrt'
         *  Sum: '<S88>/Sum'
         *  Sum: '<S88>/Sum1'
         *  Sum: '<S89>/Sum of Elements'
         *  Sum: '<S90>/Sum of Elements'
         */
        rtb_Switch_h_idx_2 = sqrtf(rtb_Saturation_k * rtb_Saturation_k + rtb_u_h
          * rtb_u_h) / sqrtf(rtb_Switch_h_idx_0 * rtb_Switch_h_idx_0 +
                             rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1);

        /* Saturate: '<S88>/Saturation' */
        if (rtb_Switch_h_idx_2 > 1.0F) {
          rtb_Switch_h_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_2 < 0.0F) {
            rtb_Switch_h_idx_2 = 0.0F;
          }
        }

        /* End of Saturate: '<S88>/Saturation' */

        /* Sum: '<S105>/Subtract' incorporates:
         *  Product: '<S105>/Multiply'
         *  Product: '<S105>/Multiply1'
         */
        rtb_u_h = rtb_Divide_c[0] * rtb_P_c[1] - rtb_Divide_c[1] * rtb_P_c[0];

        /* Signum: '<S100>/Sign1' */
        if (rtb_u_h < 0.0F) {
          rtb_u_h = -1.0F;
        } else {
          if (rtb_u_h > 0.0F) {
            rtb_u_h = 1.0F;
          }
        }

        /* End of Signum: '<S100>/Sign1' */

        /* Switch: '<S100>/Switch2' incorporates:
         *  Constant: '<S100>/Constant4'
         */
        if (rtb_u_h == 0.0F) {
          rtb_u_h = 1.0F;
        }

        /* End of Switch: '<S100>/Switch2' */

        /* DotProduct: '<S100>/Dot Product' */
        rtb_Switch_h_idx_1 = rtb_P_c[0] * rtb_Divide_c[0] + rtb_P_c[1] *
          rtb_Divide_c[1];

        /* Trigonometry: '<S100>/Acos' incorporates:
         *  DotProduct: '<S100>/Dot Product'
         */
        if (rtb_Switch_h_idx_1 > 1.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_1 < -1.0F) {
            rtb_Switch_h_idx_1 = -1.0F;
          }
        }

        /* Product: '<S100>/Multiply' incorporates:
         *  Trigonometry: '<S100>/Acos'
         */
        rtb_u_h *= acosf(rtb_Switch_h_idx_1);

        /* Saturate: '<S94>/Saturation' */
        if (rtb_u_h > 1.57079637F) {
          rtb_u_h = 1.57079637F;
        } else {
          if (rtb_u_h < -1.57079637F) {
            rtb_u_h = -1.57079637F;
          }
        }

        /* End of Saturate: '<S94>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S101>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S101>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S101>/Sum of Elements'
         */
        rtb_Saturation_k = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S85>/Bus Assignment'
         *  Constant: '<S85>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S85>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S85>/vel'
         *  Constant: '<S87>/L1'
         *  Constant: '<S94>/Constant'
         *  Gain: '<S91>/AccToRate'
         *  Gain: '<S94>/Gain'
         *  Math: '<S94>/Square'
         *  MinMax: '<S94>/Max'
         *  MinMax: '<S94>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S94>/Divide'
         *  Product: '<S94>/Multiply1'
         *  Sqrt: '<S102>/Sqrt'
         *  Trigonometry: '<S94>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = rtb_Saturation_k * rtb_Saturation_k * 2.0F *
          arm_sin_f32(rtb_u_h) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_u), 0.5F)) *
          FMS_PARAM.ACC2RATE;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S86>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S88>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S86>/Sum2'
         *  Sum: '<S88>/Add'
         *  Sum: '<S88>/Subtract'
         */
        rtb_u = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                   FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_h_idx_2 +
                  FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S86>/Saturation1' */
        if (rtb_u > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S85>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_u < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S85>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S85>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_u;
        }

        /* End of Saturate: '<S86>/Saturation1' */
        /* End of Outputs for SubSystem: '<S81>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S84>/Delay Input1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S84>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S83>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S22>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S22>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S17>/Assist' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* SwitchCase: '<S21>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 0;
        break;

       case VehicleState_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 1;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 2;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 3;
        break;
      }

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_p) {
        switch (rtPrevAction) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S33>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S57>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S47>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S21>/Stabilize' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S28>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_p;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S80>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S80>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S77>/Gain6'
         *  Gain: '<S80>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u *
          FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S79>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S79>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S76>/Gain6'
         *  Gain: '<S79>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u *
          FMS_PARAM.MAX_R;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S78>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_throttle - (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S78>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S75>/Gain6'
         *  Gain: '<S78>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_u *
          -FMS_PARAM.VEL_Z_LIM;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S34>/Motion Status'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S21>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Altitude' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S34>/Motion Status' incorporates:
         *  Abs: '<S34>/Abs'
         *  Abs: '<S34>/Abs1'
         *  Constant: '<S40>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S40>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                         FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                         &rtb_state_cv, &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S33>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bg;
        FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
        switch (rtb_state_cv) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_bg = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_bg = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_bg = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_bg) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bg != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S33>/Hold Control' incorporates:
             *  ActionPort: '<S36>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S33>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S33>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S33>/Hold Control' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_a, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S33>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S33>/Brake Control' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S33>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S33>/Move Control' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S33>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S33>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S26>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S43>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S43>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S32>/Gain6'
         *  Gain: '<S43>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u *
          FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S42>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S42>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S31>/Gain6'
         *  Gain: '<S42>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u *
          FMS_PARAM.MAX_R;

        /* Saturate: '<S33>/Saturation1' */
        if (FMS_B.Merge_a > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_a < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_a;
        }

        /* End of Saturate: '<S33>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Altitude' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S48>/Motion Status'
           *  Chart: '<S58>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_f);
          FMS_DW.temporalCounter_i1_j = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_n;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S74>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S74>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S74>/Sum of Elements'
         */
        rtb_Switch_h_idx_0 = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat
          [0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
          FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3]
          * FMS_U.INS_Out.quat[3]);

        /* Product: '<S70>/Divide' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_u = FMS_U.INS_Out.quat[0] / rtb_Switch_h_idx_0;
        rtb_Switch_h_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Switch_h_idx_0;
        rtb_Switch_h_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Switch_h_idx_0;
        rtb_Switch_h_idx_0 = FMS_U.INS_Out.quat[3] / rtb_Switch_h_idx_0;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S71>/Square' incorporates:
         *  Math: '<S72>/Square'
         *  Math: '<S73>/Square'
         */
        rtb_u_h = rtb_u * rtb_u;

        /* Math: '<S71>/Square2' incorporates:
         *  Math: '<S72>/Square2'
         *  Math: '<S73>/Square2'
         */
        rtb_Saturation_k = rtb_Switch_h_idx_2 * rtb_Switch_h_idx_2;

        /* Math: '<S71>/Square1' incorporates:
         *  Math: '<S72>/Square1'
         *  Math: '<S73>/Square1'
         */
        rtb_AccToRate_k = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1;

        /* Math: '<S71>/Square3' incorporates:
         *  Math: '<S72>/Square3'
         *  Math: '<S73>/Square3'
         */
        rtb_MatrixConcatenate1_tmp_1 = rtb_Switch_h_idx_0 * rtb_Switch_h_idx_0;

        /* Sum: '<S71>/Subtract' incorporates:
         *  Math: '<S71>/Square'
         *  Math: '<S71>/Square1'
         *  Math: '<S71>/Square2'
         *  Math: '<S71>/Square3'
         *  Sum: '<S71>/Add'
         *  Sum: '<S71>/Add1'
         */
        rtb_MatrixConcatenate1[0] = (rtb_u_h + rtb_AccToRate_k) -
          (rtb_Saturation_k + rtb_MatrixConcatenate1_tmp_1);

        /* Product: '<S71>/Multiply' incorporates:
         *  Product: '<S72>/Multiply'
         */
        rtb_MatrixConcatenate1_tmp = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_2;

        /* Product: '<S71>/Multiply1' incorporates:
         *  Product: '<S72>/Multiply1'
         */
        rtb_MatrixConcatenate1_tmp_0 = rtb_u * rtb_Switch_h_idx_0;

        /* Gain: '<S71>/Gain' incorporates:
         *  Product: '<S71>/Multiply'
         *  Product: '<S71>/Multiply1'
         *  Sum: '<S71>/Subtract1'
         */
        rtb_MatrixConcatenate1[1] = (rtb_MatrixConcatenate1_tmp -
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Product: '<S71>/Multiply2' incorporates:
         *  Product: '<S73>/Multiply'
         */
        rtb_MatrixConcatenate1_tmp_2 = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_0;

        /* Product: '<S71>/Multiply3' incorporates:
         *  Product: '<S73>/Multiply1'
         */
        rtb_MatrixConcatenate1_tmp_3 = rtb_u * rtb_Switch_h_idx_2;

        /* Gain: '<S71>/Gain1' incorporates:
         *  Product: '<S71>/Multiply2'
         *  Product: '<S71>/Multiply3'
         *  Sum: '<S71>/Add2'
         */
        rtb_MatrixConcatenate1[2] = (rtb_MatrixConcatenate1_tmp_2 +
          rtb_MatrixConcatenate1_tmp_3) * 2.0F;

        /* Gain: '<S72>/Gain' incorporates:
         *  Sum: '<S72>/Add3'
         */
        rtb_MatrixConcatenate1[3] = (rtb_MatrixConcatenate1_tmp +
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Sum: '<S72>/Subtract' incorporates:
         *  Sum: '<S72>/Add'
         *  Sum: '<S72>/Add1'
         */
        rtb_MatrixConcatenate1[4] = (rtb_u_h + rtb_Saturation_k) -
          (rtb_AccToRate_k + rtb_MatrixConcatenate1_tmp_1);

        /* Product: '<S72>/Multiply2' incorporates:
         *  Product: '<S73>/Multiply2'
         */
        rtb_MatrixConcatenate1_tmp = rtb_Switch_h_idx_2 * rtb_Switch_h_idx_0;

        /* Product: '<S72>/Multiply3' incorporates:
         *  Product: '<S73>/Multiply3'
         */
        rtb_MatrixConcatenate1_tmp_0 = rtb_u * rtb_Switch_h_idx_1;

        /* Gain: '<S72>/Gain1' incorporates:
         *  Product: '<S72>/Multiply2'
         *  Product: '<S72>/Multiply3'
         *  Sum: '<S72>/Subtract1'
         */
        rtb_MatrixConcatenate1[5] = (rtb_MatrixConcatenate1_tmp -
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Gain: '<S73>/Gain' incorporates:
         *  Sum: '<S73>/Subtract2'
         */
        rtb_MatrixConcatenate1[6] = (rtb_MatrixConcatenate1_tmp_2 -
          rtb_MatrixConcatenate1_tmp_3) * 2.0F;

        /* Gain: '<S73>/Gain1' incorporates:
         *  Sum: '<S73>/Add2'
         */
        rtb_MatrixConcatenate1[7] = (rtb_MatrixConcatenate1_tmp +
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Sum: '<S73>/Subtract' incorporates:
         *  Sum: '<S73>/Add'
         *  Sum: '<S73>/Add1'
         */
        rtb_MatrixConcatenate1[8] = (rtb_u_h + rtb_MatrixConcatenate1_tmp_1) -
          (rtb_AccToRate_k + rtb_Saturation_k);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S48>/Motion Status' incorporates:
         *  Abs: '<S48>/Abs'
         *  Abs: '<S48>/Abs1'
         *  Constant: '<S54>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S54>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                         FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                         &rtb_state_cv, &FMS_DW.sf_MotionStatus_f);

        /* RelationalOperator: '<S67>/Compare' incorporates:
         *  Abs: '<S58>/Abs2'
         *  Constant: '<S67>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Compare_a = (fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S58>/Motion State' */
        if (FMS_DW.temporalCounter_i1_j < 511U) {
          FMS_DW.temporalCounter_i1_j++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_p;
          rtb_state = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_b:
            rtb_state = MotionState_Brake;

            /* Product: '<S66>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S16>/Signal Copy1'
             */
            for (i = 0; i < 3; i++) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Switch_f[i] = rtb_MatrixConcatenate1[i + 6] * FMS_U.INS_Out.vd
                + (rtb_MatrixConcatenate1[i + 3] * FMS_U.INS_Out.ve +
                   rtb_MatrixConcatenate1[i] * FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }

            /* End of Product: '<S66>/Multiply' */
            if ((rtb_Switch_f[0] <= 0.1) || (FMS_DW.temporalCounter_i1_j >= 500U))
            {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_c;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_Compare_a) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_p;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold_c:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_a) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_p;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_a) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_b;
              FMS_DW.temporalCounter_i1_j = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S58>/Motion State' */

        /* SwitchCase: '<S57>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        switch (rtb_state) {
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
            /* InitializeConditions for IfAction SubSystem: '<S57>/Hold Control' incorporates:
             *  ActionPort: '<S60>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S57>/Switch Case' incorporates:
             *  Delay: '<S60>/Delay'
             */
            FMS_DW.icLoad = 1U;

            /* End of InitializeConditions for SubSystem: '<S57>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S57>/Hold Control' incorporates:
           *  ActionPort: '<S60>/Action Port'
           */
          /* Delay: '<S60>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.Delay_DSTATE = FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Trigonometry: '<S64>/Trigonometric Function1' incorporates:
           *  Gain: '<S63>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Trigonometry: '<S64>/Trigonometric Function3'
           */
          rtb_u_h = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_MatrixConcatenate1[0] = rtb_u_h;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Trigonometry: '<S64>/Trigonometric Function' incorporates:
           *  Gain: '<S63>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Trigonometry: '<S64>/Trigonometric Function2'
           */
          rtb_Saturation_k = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_MatrixConcatenate1[1] = rtb_Saturation_k;

          /* SignalConversion: '<S64>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S64>/Constant3'
           */
          rtb_MatrixConcatenate1[2] = 0.0F;

          /* Gain: '<S64>/Gain' */
          rtb_MatrixConcatenate1[3] = -rtb_Saturation_k;

          /* Trigonometry: '<S64>/Trigonometric Function3' */
          rtb_MatrixConcatenate1[4] = rtb_u_h;

          /* SignalConversion: '<S64>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S64>/Constant4'
           */
          rtb_MatrixConcatenate1[5] = 0.0F;

          /* SignalConversion: '<S64>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_MatrixConcatenate1[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_MatrixConcatenate1[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_MatrixConcatenate1[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Reshape: '<S60>/Reshape' incorporates:
           *  Delay: '<S60>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S60>/Sum'
           */
          rtb_u = FMS_DW.Delay_DSTATE - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S60>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Switch_f[i] = rtb_MatrixConcatenate1[i] * rtb_u;
          }

          /* Gain: '<S60>/Gain2' incorporates:
           *  Product: '<S60>/Multiply'
           */
          FMS_B.Merge_i = FMS_PARAM.X_P * rtb_Switch_f[0];

          /* Update for Delay: '<S60>/Delay' */
          FMS_DW.icLoad = 0U;

          /* End of Outputs for SubSystem: '<S57>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S57>/Brake Control' incorporates:
           *  ActionPort: '<S59>/Action Port'
           */
          /* SignalConversion: '<S59>/OutportBuffer_InsertedFor_u_cmd_mPs_at_inport_0' incorporates:
           *  Constant: '<S59>/Brake Speed'
           */
          FMS_B.Merge_i = 0.0F;

          /* End of Outputs for SubSystem: '<S57>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S57>/Move Control' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S65>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_u = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_u = 0.0F;
          } else {
            rtb_u = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S65>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S61>/Gain6' incorporates:
           *  Gain: '<S65>/Gain'
           */
          FMS_B.Merge_i = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u *
            FMS_PARAM.VEL_X_LIM;

          /* End of Outputs for SubSystem: '<S57>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S57>/Switch Case' */

        /* SwitchCase: '<S47>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_c;
        FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
        switch (rtb_state_cv) {
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
            /* SystemReset for IfAction SubSystem: '<S47>/Hold Control' incorporates:
             *  ActionPort: '<S50>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S47>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S47>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S47>/Hold Control' incorporates:
           *  ActionPort: '<S50>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S47>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S47>/Brake Control' incorporates:
           *  ActionPort: '<S49>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S47>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S47>/Move Control' incorporates:
           *  ActionPort: '<S51>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S47>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S47>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S27>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S27>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Saturate: '<S57>/Saturation1' */
        if (FMS_B.Merge_i > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (FMS_B.Merge_i < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_i;
        }

        /* End of Saturate: '<S57>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S56>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S56>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S45>/Gain6'
         *  Gain: '<S56>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u *
          FMS_PARAM.MAX_R;

        /* Saturate: '<S47>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S47>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Position' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S21>/Unknown' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_o);

        /* End of Outputs for SubSystem: '<S21>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S21>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S17>/Manual' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  BusAssignment: '<S23>/Bus Assignment'
       *  Constant: '<S23>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  Constant: '<S23>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S17>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S17>/Unknown' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S17>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S17>/Switch Case' */
    /* End of Outputs for SubSystem: '<S15>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S15>/Switch Case' */

  /* BusAssignment: '<S18>/Bus Assignment' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S18>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S133>/Constant'
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
  /* Start for SwitchCase: '<S15>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S15>/Arm' */
  /* Start for SwitchCase: '<S17>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S17>/SubMode' */
  /* Start for SwitchCase: '<S24>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S17>/SubMode' */

  /* Start for IfAction SubSystem: '<S17>/Auto' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S17>/Auto' */

  /* Start for IfAction SubSystem: '<S17>/Assist' */
  /* Start for SwitchCase: '<S21>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for IfAction SubSystem: '<S21>/Altitude' */
  /* Start for SwitchCase: '<S33>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;

  /* End of Start for SubSystem: '<S21>/Altitude' */

  /* Start for IfAction SubSystem: '<S21>/Position' */
  /* Start for SwitchCase: '<S57>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S47>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S15>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_n;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_n;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = FMS_Cmd_None;
  FMS_DW.bl = false;
  FMS_DW.br = false;
  FMS_DW.prep_mission = 0.0;
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S15>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Mission' */
  /* InitializeConditions for UnitDelay: '<S84>/Delay Input1'
   *
   * Block description for '<S84>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S22>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S17>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Altitude' */
  /* SystemInitialize for Chart: '<S34>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S33>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S33>/Hold Control' */

  /* SystemInitialize for Merge: '<S33>/Merge' */
  FMS_B.Merge_a = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S48>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_f);

  /* SystemInitialize for Chart: '<S58>/Motion State' */
  FMS_DW.temporalCounter_i1_j = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_n;

  /* SystemInitialize for IfAction SubSystem: '<S57>/Hold Control' */
  /* InitializeConditions for Delay: '<S60>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S57>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S47>/Hold Control' */

  /* SystemInitialize for Merge: '<S47>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S57>/Merge' */
  FMS_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Position' */
  /* End of SystemInitialize for SubSystem: '<S17>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S15>/Arm' */
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
