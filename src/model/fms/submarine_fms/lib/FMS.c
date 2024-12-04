/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1996
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Dec  4 12:14:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S39>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S63>/Motion State' */
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
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)4U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Other                   ((uint8_T)4U)
#define FMS_IN_Position_f              ((uint8_T)5U)
#define FMS_IN_Stabilize_j             ((uint8_T)6U)

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
                                        *   '<S127>/vel'
                                        *   '<S36>/Gain6'
                                        *   '<S37>/Gain6'
                                        *   '<S50>/Gain6'
                                        *   '<S80>/Gain6'
                                        *   '<S81>/Gain6'
                                        *   '<S82>/Gain6'
                                        *   '<S90>/vel'
                                        *   '<S129>/Gain'
                                        *   '<S129>/Saturation1'
                                        *   '<S130>/L1'
                                        *   '<S38>/Saturation1'
                                        *   '<S47>/Dead Zone'
                                        *   '<S47>/Gain'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S52>/Saturation1'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S62>/Saturation1'
                                        *   '<S83>/Dead Zone'
                                        *   '<S83>/Gain'
                                        *   '<S84>/Dead Zone'
                                        *   '<S84>/Gain'
                                        *   '<S85>/Dead Zone'
                                        *   '<S85>/Gain'
                                        *   '<S91>/Gain'
                                        *   '<S91>/Saturation1'
                                        *   '<S92>/L1'
                                        *   '<S134>/AccToRate'
                                        *   '<S41>/Gain2'
                                        *   '<S42>/Gain1'
                                        *   '<S45>/Constant'
                                        *   '<S55>/Gain2'
                                        *   '<S56>/Gain1'
                                        *   '<S59>/Constant'
                                        *   '<S65>/Gain2'
                                        *   '<S66>/Gain6'
                                        *   '<S72>/Constant'
                                        *   '<S96>/AccToRate'
                                        *   '<S44>/Dead Zone'
                                        *   '<S44>/Gain'
                                        *   '<S58>/Dead Zone'
                                        *   '<S58>/Gain'
                                        *   '<S70>/Dead Zone'
                                        *   '<S70>/Gain'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT = {
  4U,

  { 83, 117, 98, 109, 97, 114, 105, 110, 101, 32, 70, 77, 83, 32, 118, 48, 46,
    48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S10>/Constant1'
                                        *   '<S151>/Constant'
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
 *    '<S136>/NearbyRefWP'
 *    '<S98>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S140>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S136>/OutRegionRegWP'
 *    '<S98>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_d, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S141>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S136>/SearchL1RefWP'
 *    '<S98>/SearchL1RefWP'
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

  /* SignalConversion: '<S142>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S29>/Unknown'
 *    '<S27>/Unknown'
 *    '<S26>/Unknown'
 *    '<S22>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S128>/Bus Assignment' incorporates:
   *  Constant: '<S128>/Constant'
   *  Constant: '<S128>/Constant2'
   *  SignalConversion: '<S128>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S128>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S38>/Hold Control'
 *    '<S52>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S41>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S38>/Hold Control'
 *    '<S52>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S41>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S38>/Hold Control'
 *    '<S52>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S41>/Delay' incorporates:
   *  Gain: '<S43>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S41>/Gain2' incorporates:
   *  Delay: '<S41>/Delay'
   *  Gain: '<S43>/Gain'
   *  Sum: '<S41>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S41>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S38>/Brake Control'
 *    '<S52>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_w_cmd_mPs)
{
  /* SignalConversion: '<S40>/OutportBuffer_InsertedFor_w_cmd_mPs_at_inport_0' incorporates:
   *  Constant: '<S40>/Brake Speed'
   */
  *rty_w_cmd_mPs = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S38>/Move Control'
 *    '<S52>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S44>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S44>/Dead Zone' */

  /* Gain: '<S42>/Gain1' incorporates:
   *  Gain: '<S44>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtu_FMS_In_0 *
    -FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S39>/Motion Status'
 *    '<S53>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S39>/Motion Status'
 *    '<S53>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S39>/Motion Status'
 *    '<S53>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S39>/Motion Status' */
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

  /* End of Chart: '<S39>/Motion Status' */
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_e, &FMS_DW.M_msgReservedData);
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
       case PilotMode_Offboard:
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_e, &FMS_DW.Msg_FMS_Cmd_l
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_l[0] : NULL;
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

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S164>/Compare' incorporates:
   *  Abs: '<S153>/Abs'
   *  Constant: '<S164>/Constant'
   *  MinMax: '<S153>/Max'
   *  Sum: '<S153>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S4>/Vehicle.StickMoved' */
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
      FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_n;
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
            FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_n;
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

                  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Sum: '<S154>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S154>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S155>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S155>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S155>/Multiply1' incorporates:
                   *  Product: '<S155>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S155>/Divide' incorporates:
                   *  Constant: '<S155>/Constant'
                   *  Constant: '<S155>/R'
                   *  Sqrt: '<S155>/Sqrt'
                   *  Sum: '<S155>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S155>/Product3' incorporates:
                   *  Constant: '<S155>/Constant1'
                   *  Product: '<S155>/Multiply1'
                   *  Sum: '<S155>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S155>/Multiply2' incorporates:
                   *  Trigonometry: '<S155>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S159>/Abs' incorporates:
                   *  Abs: '<S162>/Abs1'
                   *  Switch: '<S159>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S159>/Switch1' incorporates:
                   *  Abs: '<S159>/Abs'
                   *  Bias: '<S159>/Bias2'
                   *  Bias: '<S159>/Bias3'
                   *  Constant: '<S156>/Constant'
                   *  Constant: '<S156>/Constant1'
                   *  Constant: '<S161>/Constant'
                   *  Gain: '<S159>/Gain1'
                   *  Product: '<S159>/Multiply'
                   *  RelationalOperator: '<S161>/Compare'
                   *  Switch: '<S156>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S162>/Switch1' incorporates:
                     *  Bias: '<S162>/Bias2'
                     *  Bias: '<S162>/Bias3'
                     *  Constant: '<S162>/Constant'
                     *  Constant: '<S163>/Constant'
                     *  Math: '<S162>/Math Function'
                     *  RelationalOperator: '<S163>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S162>/Switch1' */

                    /* Signum: '<S159>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S159>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S156>/Sum' incorporates:
                   *  Sum: '<S154>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S154>/Multiply' incorporates:
                   *  Gain: '<S154>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S158>/Switch1' incorporates:
                   *  Abs: '<S158>/Abs1'
                   *  Bias: '<S158>/Bias2'
                   *  Bias: '<S158>/Bias3'
                   *  Constant: '<S158>/Constant'
                   *  Constant: '<S160>/Constant'
                   *  Math: '<S158>/Math Function'
                   *  RelationalOperator: '<S160>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S158>/Switch1' */

                  /* Product: '<S154>/Multiply' incorporates:
                   *  Gain: '<S154>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S154>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S157>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S157>/Sum2' incorporates:
                   *  Product: '<S157>/Multiply1'
                   *  Product: '<S157>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S157>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S157>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S157>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S152>/Data Type Conversion' incorporates:
                   *  Gain: '<S154>/Gain'
                   *  Sum: '<S154>/Sum1'
                   */
                  FMS_B.DataTypeConversion[0] = (real32_T)rtb_Sum2_m;
                  FMS_B.DataTypeConversion[1] = (real32_T)rtb_Sum_d;
                  FMS_B.DataTypeConversion[2] = (real32_T)-(FMS_B.lla[2] +
                    FMS_B.href);

                  /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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
        if ((FMS_DW.chartAbsoluteTimeCounter -
             FMS_DW.durationLastReferenceTick_1 >= 500) || ((FMS_B.target_mode ==
              PilotMode_Offboard) && FMS_B.LogicalOperator)) {
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
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
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
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_j > 375) {
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
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
              FMS_DW.durationLastReferenceTick_1_j =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_e, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_l[1]);
}

/* Model step function */
void FMS_step(void)
{
  uint8_T rtb_Switch_k;
  int8_T rtPrevAction;
  real32_T rtb_TmpSignalConversionAtSign_0[3];
  real32_T rtb_Saturation_k;
  real32_T rtb_AccToRate_k;
  real32_T rtb_Divide_c[2];
  real32_T rtb_Switch_av[3];
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
  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S14>/FixPt Relational Operator'
   *  UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Delay: '<S12>/Delay'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S12>/Logical Operator'
   *  Logic: '<S12>/Logical Operator1'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch1'
   *  UnitDelay: '<S19>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S12>/Switch1' incorporates:
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       *  Delay: '<S12>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S12>/Switch' */

  /* Switch: '<S11>/Switch1' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  Switch: '<S11>/Switch2'
   *  UnitDelay: '<S15>/Delay Input1'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S11>/Switch2' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S11>/Switch2' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_u = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_u < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_u;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S19>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S15>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* End of Outputs for SubSystem: '<Root>/CommandProcess' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S12>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    switch (FMS_DW.Delay_DSTATE_c) {
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
      FMS_DW.is_c3_FMS = FMS_IN_Mission;
      break;

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Altitude:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_B.target_mode = PilotMode_Altitude;
        switch (FMS_DW.Delay_DSTATE_c) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
      break;

     case FMS_IN_Mission:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_B.target_mode = PilotMode_Mission;
        switch (FMS_DW.Delay_DSTATE_c) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      }
      break;

     case FMS_IN_Offboard:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_B.target_mode = PilotMode_Offboard;
        switch (FMS_DW.Delay_DSTATE_c) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
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
        FMS_DW.is_c3_FMS = FMS_IN_Mission;
        break;

       case PilotMode_Offboard:
        FMS_DW.is_c3_FMS = FMS_IN_Offboard;
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
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.target_mode = PilotMode_Stabilize;
        switch (FMS_DW.Delay_DSTATE_c) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      }
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

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Delay: '<S8>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S7>/FixPt Relational Operator'
   *  Switch: '<S8>/Switch'
   *  UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0U;
    rtb_Switch_k = 1U;
  } else {
    rtb_Switch_k = FMS_DW.Delay_DSTATE_k;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S9>/Upper Limit'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S9>/Upper Test'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE < 1000U) &&
    (rtb_Switch_k != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_Compare_a = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_Compare_a) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_Compare_a;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
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
  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  /* SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_av[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_TmpSignalConversionAtSign_0[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_av[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_TmpSignalConversionAtSign_0[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_av[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_TmpSignalConversionAtSign_0[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* SwitchCase: '<S20>/Switch Case' incorporates:
   *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S22>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S29>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S27>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S26>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
       case 0:
       case 3:
        break;

       case 1:
        /* Disable for SwitchCase: '<S38>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S62>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S52>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S22>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S20>/Disarm' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  BusAssignment: '<S24>/Bus Assignment'
     *  Constant: '<S24>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S24>/Bus Assignment' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  Constant: '<S24>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_bg;

    /* End of Outputs for SubSystem: '<S20>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S20>/Standby' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  BusAssignment: '<S25>/Bus Assignment'
     *  Constant: '<S25>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S25>/Bus Assignment' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  Constant: '<S25>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_oj;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

    /* End of Outputs for SubSystem: '<S20>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S20>/Arm' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* SwitchCase: '<S22>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

    /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S29>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S27>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S26>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S38>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S62>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S52>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S22>/SubMode' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* SwitchCase: '<S29>/Switch Case' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S29>/Return' incorporates:
         *  ActionPort: '<S127>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S144>/TmpSignal ConversionAtSquareInport1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Divide_c[0] = FMS_U.INS_Out.vn;
        rtb_Divide_c[1] = FMS_U.INS_Out.ve;

        /* Sum: '<S146>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S146>/Math Function'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S144>/Sum of Elements'
         */
        rtb_u = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S146>/Math Function1' incorporates:
         *  Sum: '<S146>/Sum of Elements'
         *
         * About '<S146>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_u));
        } else {
          rtb_Saturation_k = sqrtf(rtb_u);
        }

        /* End of Math: '<S146>/Math Function1' */

        /* Switch: '<S146>/Switch' incorporates:
         *  Constant: '<S146>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S146>/Product'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (rtb_Saturation_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_h_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_h_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_h_idx_2 = rtb_Saturation_k;
        } else {
          rtb_Switch_h_idx_0 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_h_idx_2 = 1.0F;
        }

        /* End of Switch: '<S146>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S136>/NearbyRefWP' incorporates:
         *  Constant: '<S130>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_av[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_c, &rtb_AccToRate_k);

        /* MATLAB Function: '<S136>/SearchL1RefWP' incorporates:
         *  Constant: '<S130>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_av[0],
                          FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                          rtb_P_c, &rtb_u_h);

        /* MATLAB Function: '<S136>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_av[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_i);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S136>/Switch1' incorporates:
         *  Constant: '<S139>/Constant'
         *  RelationalOperator: '<S139>/Compare'
         */
        if (rtb_AccToRate_k > 0.0F) {
          rtb_P_c[0] = rtb_Divide_c[0];
          rtb_P_c[1] = rtb_Divide_c[1];
        } else {
          /* RelationalOperator: '<S138>/Compare' incorporates:
           *  Constant: '<S138>/Constant'
           */
          rtb_Compare_a = (rtb_u_h >= 0.0F);

          /* Switch: '<S136>/Switch' */
          if (!rtb_Compare_a) {
            rtb_P_c[0] = rtb_P_i[0];
            rtb_P_c[1] = rtb_P_i[1];
          }

          /* End of Switch: '<S136>/Switch' */
        }

        /* End of Switch: '<S136>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S137>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Divide_c[0] = rtb_P_c[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_c[1] = rtb_P_c[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S147>/Sum of Elements' incorporates:
         *  Math: '<S147>/Math Function'
         *  Sum: '<S145>/Sum of Elements'
         */
        rtb_u_h = rtb_Divide_c[0] * rtb_Divide_c[0] + rtb_Divide_c[1] *
          rtb_Divide_c[1];

        /* Math: '<S147>/Math Function1' incorporates:
         *  Sum: '<S147>/Sum of Elements'
         *
         * About '<S147>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u_h < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_u_h));
        } else {
          rtb_Saturation_k = sqrtf(rtb_u_h);
        }

        /* End of Math: '<S147>/Math Function1' */

        /* Switch: '<S147>/Switch' incorporates:
         *  Constant: '<S147>/Constant'
         *  Product: '<S147>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_av[0] = rtb_Divide_c[0];
          rtb_Switch_av[1] = rtb_Divide_c[1];
          rtb_Switch_av[2] = rtb_Saturation_k;
        } else {
          rtb_Switch_av[0] = 0.0F;
          rtb_Switch_av[1] = 0.0F;
          rtb_Switch_av[2] = 1.0F;
        }

        /* End of Switch: '<S147>/Switch' */

        /* Product: '<S146>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;
        rtb_Divide_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Sum: '<S149>/Sum of Elements' incorporates:
         *  Math: '<S149>/Math Function'
         *  SignalConversion: '<S149>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_k = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S149>/Math Function1' incorporates:
         *  Sum: '<S149>/Sum of Elements'
         *
         * About '<S149>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_Saturation_k));
        } else {
          rtb_Saturation_k = sqrtf(rtb_Saturation_k);
        }

        /* End of Math: '<S149>/Math Function1' */

        /* Switch: '<S149>/Switch' incorporates:
         *  Constant: '<S149>/Constant'
         *  Product: '<S149>/Product'
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

        /* End of Switch: '<S149>/Switch' */

        /* Product: '<S147>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_av[0] / rtb_Switch_av[2];
        rtb_Divide_c[1] = rtb_Switch_av[1] / rtb_Switch_av[2];

        /* Sum: '<S150>/Sum of Elements' incorporates:
         *  Math: '<S150>/Math Function'
         *  SignalConversion: '<S150>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_k = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S150>/Math Function1' incorporates:
         *  Sum: '<S150>/Sum of Elements'
         *
         * About '<S150>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_Saturation_k));
        } else {
          rtb_Saturation_k = sqrtf(rtb_Saturation_k);
        }

        /* End of Math: '<S150>/Math Function1' */

        /* Switch: '<S150>/Switch' incorporates:
         *  Constant: '<S150>/Constant'
         *  Product: '<S150>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_av[0] = rtb_Divide_c[1];
          rtb_Switch_av[1] = rtb_Divide_c[0];
          rtb_Switch_av[2] = rtb_Saturation_k;
        } else {
          rtb_Switch_av[0] = 0.0F;
          rtb_Switch_av[1] = 0.0F;
          rtb_Switch_av[2] = 1.0F;
        }

        /* End of Switch: '<S150>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S131>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_k = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_AccToRate_k = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S150>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_av[0] / rtb_Switch_av[2];

        /* Product: '<S149>/Divide' */
        rtb_P_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S131>/Sum1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S150>/Divide' */
        rtb_Divide_c[1] = rtb_Switch_av[1] / rtb_Switch_av[2];

        /* Product: '<S149>/Divide' */
        rtb_P_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S131>/Sum1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S131>/Divide' incorporates:
         *  Math: '<S132>/Square'
         *  Math: '<S133>/Square'
         *  Sqrt: '<S132>/Sqrt'
         *  Sqrt: '<S133>/Sqrt'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S131>/Sum1'
         *  Sum: '<S132>/Sum of Elements'
         *  Sum: '<S133>/Sum of Elements'
         */
        rtb_Switch_h_idx_2 = sqrtf(rtb_AccToRate_k * rtb_AccToRate_k +
          rtb_Saturation_k * rtb_Saturation_k) / sqrtf(rtb_Switch_h_idx_0 *
          rtb_Switch_h_idx_0 + rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1);

        /* Saturate: '<S131>/Saturation' */
        if (rtb_Switch_h_idx_2 > 1.0F) {
          rtb_Switch_h_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_2 < 0.0F) {
            rtb_Switch_h_idx_2 = 0.0F;
          }
        }

        /* End of Saturate: '<S131>/Saturation' */

        /* Sum: '<S148>/Subtract' incorporates:
         *  Product: '<S148>/Multiply'
         *  Product: '<S148>/Multiply1'
         */
        rtb_Saturation_k = rtb_Divide_c[0] * rtb_P_c[1] - rtb_Divide_c[1] *
          rtb_P_c[0];

        /* Signum: '<S143>/Sign1' */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -1.0F;
        } else {
          if (rtb_Saturation_k > 0.0F) {
            rtb_Saturation_k = 1.0F;
          }
        }

        /* End of Signum: '<S143>/Sign1' */

        /* Switch: '<S143>/Switch2' incorporates:
         *  Constant: '<S143>/Constant4'
         */
        if (rtb_Saturation_k == 0.0F) {
          rtb_Saturation_k = 1.0F;
        }

        /* End of Switch: '<S143>/Switch2' */

        /* DotProduct: '<S143>/Dot Product' */
        rtb_Switch_h_idx_1 = rtb_P_c[0] * rtb_Divide_c[0] + rtb_P_c[1] *
          rtb_Divide_c[1];

        /* Trigonometry: '<S143>/Acos' incorporates:
         *  DotProduct: '<S143>/Dot Product'
         */
        if (rtb_Switch_h_idx_1 > 1.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_1 < -1.0F) {
            rtb_Switch_h_idx_1 = -1.0F;
          }
        }

        /* Product: '<S143>/Multiply' incorporates:
         *  Trigonometry: '<S143>/Acos'
         */
        rtb_Saturation_k *= acosf(rtb_Switch_h_idx_1);

        /* Saturate: '<S137>/Saturation' */
        if (rtb_Saturation_k > 1.57079637F) {
          rtb_Saturation_k = 1.57079637F;
        } else {
          if (rtb_Saturation_k < -1.57079637F) {
            rtb_Saturation_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S137>/Saturation' */

        /* Sqrt: '<S144>/Sqrt' */
        rtb_AccToRate_k = sqrtf(rtb_u);

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S127>/Bus Assignment1'
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S127>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S127>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S127>/vel'
         *  Constant: '<S130>/L1'
         *  Constant: '<S137>/Constant'
         *  Gain: '<S134>/AccToRate'
         *  Gain: '<S137>/Gain'
         *  Math: '<S137>/Square'
         *  MinMax: '<S137>/Max'
         *  MinMax: '<S137>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S137>/Divide'
         *  Product: '<S137>/Multiply1'
         *  Sqrt: '<S145>/Sqrt'
         *  Trigonometry: '<S137>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = rtb_AccToRate_k * rtb_AccToRate_k * 2.0F *
          arm_sin_f32(rtb_Saturation_k) / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_u_h), 0.5F)) * FMS_PARAM.ACC2RATE;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S129>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S131>/Multiply'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S129>/Sum2'
         *  Sum: '<S131>/Add'
         *  Sum: '<S131>/Subtract'
         */
        rtb_u = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                   FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_h_idx_2 +
                  FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S129>/Saturation1' */
        if (rtb_u > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S127>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_u < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S127>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S127>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_u;
        }

        /* End of Saturate: '<S129>/Saturation1' */
        /* End of Outputs for SubSystem: '<S29>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S29>/Hold' incorporates:
         *  ActionPort: '<S126>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S126>/Bus Assignment'
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S126>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S126>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S126>/Constant3'
         *  Constant: '<S126>/Constant4'
         *  Constant: '<S126>/Constant6'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.ay_cmd = 0.0F;
        FMS_Y.FMS_Out.w_cmd = 0.0F;

        /* End of Outputs for SubSystem: '<S29>/Hold' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
         *  ActionPort: '<S128>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S29>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S29>/Switch Case' */
      /* End of Outputs for SubSystem: '<S22>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S22>/Auto' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* SwitchCase: '<S27>/Switch Case' incorporates:
       *  RelationalOperator: '<S89>/FixPt Relational Operator'
       *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S89>/Delay Input1'
       *
       * Block description for '<S89>/Delay Input1':
       *
       *  Store in Global RAM
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S27>/Offboard' incorporates:
         *  ActionPort: '<S87>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S87>/Bus Assignment'
         *  Constant: '<S87>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S114>/Constant'
         *  Constant: '<S115>/Constant'
         *  Constant: '<S116>/Constant'
         *  Constant: '<S117>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S118>/bit_shift'
         *  MATLAB Function: '<S119>/bit_shift'
         *  MATLAB Function: '<S120>/bit_shift'
         *  MATLAB Function: '<S121>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S114>/Compare'
         *  RelationalOperator: '<S115>/Compare'
         *  RelationalOperator: '<S116>/Compare'
         *  RelationalOperator: '<S117>/Compare'
         *  S-Function (sfix_bitop): '<S113>/r_cmd'
         *  S-Function (sfix_bitop): '<S113>/theta_cmd'
         *  S-Function (sfix_bitop): '<S113>/u_cmd'
         *  S-Function (sfix_bitop): '<S113>/w_cmd'
         *  SignalConversion: '<S21>/Signal Copy'
         *  Sum: '<S113>/Add'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_bv;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.r_cmd = FMS_U.Auto_Cmd.psi_rate_cmd;
        FMS_Y.FMS_Out.theta_cmd = FMS_U.Auto_Cmd.theta_cmd;
        FMS_Y.FMS_Out.u_cmd = FMS_U.Auto_Cmd.u_cmd;
        FMS_Y.FMS_Out.w_cmd = FMS_U.Auto_Cmd.w_cmd;

        /* Outputs for Atomic SubSystem: '<S113>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S113>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S113>/u_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S113>/w_cmd_valid' */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((uint32_T)
          (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2) +
          (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U) << 6)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U) << 8));

        /* End of Outputs for SubSystem: '<S113>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S113>/u_cmd_valid' */
        /* End of Outputs for SubSystem: '<S113>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S113>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S27>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S27>/Mission' incorporates:
           *  ActionPort: '<S86>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S27>/Switch Case' incorporates:
           *  UnitDelay: '<S89>/Delay Input1'
           *
           * Block description for '<S89>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S27>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S27>/Mission' incorporates:
         *  ActionPort: '<S86>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S86>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S90>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Math: '<S108>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  RelationalOperator: '<S89>/FixPt Relational Operator'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S89>/Delay Input1'
         *
         * Block description for '<S89>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Divide_c[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_c[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S108>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S108>/Math Function'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_u = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S108>/Math Function1' incorporates:
         *  Sum: '<S108>/Sum of Elements'
         *
         * About '<S108>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u));
        } else {
          rtb_u_h = sqrtf(rtb_u);
        }

        /* End of Math: '<S108>/Math Function1' */

        /* Switch: '<S108>/Switch' incorporates:
         *  Constant: '<S108>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S108>/Product'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (rtb_u_h > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_h_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_h_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_h_idx_2 = rtb_u_h;
        } else {
          rtb_Switch_h_idx_0 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_h_idx_2 = 1.0F;
        }

        /* End of Switch: '<S108>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S98>/NearbyRefWP' incorporates:
         *  Constant: '<S92>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_av[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_c, &rtb_Saturation_k);

        /* MATLAB Function: '<S98>/SearchL1RefWP' incorporates:
         *  Constant: '<S92>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_av[0],
                          FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                          rtb_P_c, &rtb_u);

        /* MATLAB Function: '<S98>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtSign_0[0], &rtb_Switch_av[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_i);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S98>/Switch1' incorporates:
         *  Constant: '<S101>/Constant'
         *  RelationalOperator: '<S101>/Compare'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_P_c[0] = rtb_Divide_c[0];
          rtb_P_c[1] = rtb_Divide_c[1];
        } else {
          /* RelationalOperator: '<S100>/Compare' incorporates:
           *  Constant: '<S100>/Constant'
           */
          rtb_Compare_a = (rtb_u >= 0.0F);

          /* Switch: '<S98>/Switch' */
          if (!rtb_Compare_a) {
            rtb_P_c[0] = rtb_P_i[0];
            rtb_P_c[1] = rtb_P_i[1];
          }

          /* End of Switch: '<S98>/Switch' */
        }

        /* End of Switch: '<S98>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S99>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Divide_c[0] = rtb_P_c[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_c[1] = rtb_P_c[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S109>/Sum of Elements' incorporates:
         *  Math: '<S109>/Math Function'
         *  Sum: '<S107>/Sum of Elements'
         */
        rtb_u = rtb_Divide_c[0] * rtb_Divide_c[0] + rtb_Divide_c[1] *
          rtb_Divide_c[1];

        /* Math: '<S109>/Math Function1' incorporates:
         *  Sum: '<S109>/Sum of Elements'
         *
         * About '<S109>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u));
        } else {
          rtb_u_h = sqrtf(rtb_u);
        }

        /* End of Math: '<S109>/Math Function1' */

        /* Switch: '<S109>/Switch' incorporates:
         *  Constant: '<S109>/Constant'
         *  Product: '<S109>/Product'
         */
        if (rtb_u_h > 0.0F) {
          rtb_Switch_av[0] = rtb_Divide_c[0];
          rtb_Switch_av[1] = rtb_Divide_c[1];
          rtb_Switch_av[2] = rtb_u_h;
        } else {
          rtb_Switch_av[0] = 0.0F;
          rtb_Switch_av[1] = 0.0F;
          rtb_Switch_av[2] = 1.0F;
        }

        /* End of Switch: '<S109>/Switch' */

        /* Product: '<S108>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;
        rtb_Divide_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Sum: '<S111>/Sum of Elements' incorporates:
         *  Math: '<S111>/Math Function'
         *  SignalConversion: '<S111>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_u_h = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S111>/Math Function1' incorporates:
         *  Sum: '<S111>/Sum of Elements'
         *
         * About '<S111>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u_h < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u_h));
        } else {
          rtb_u_h = sqrtf(rtb_u_h);
        }

        /* End of Math: '<S111>/Math Function1' */

        /* Switch: '<S111>/Switch' incorporates:
         *  Constant: '<S111>/Constant'
         *  Product: '<S111>/Product'
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

        /* End of Switch: '<S111>/Switch' */

        /* Product: '<S109>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_av[0] / rtb_Switch_av[2];
        rtb_Divide_c[1] = rtb_Switch_av[1] / rtb_Switch_av[2];

        /* Sum: '<S112>/Sum of Elements' incorporates:
         *  Math: '<S112>/Math Function'
         *  SignalConversion: '<S112>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_u_h = rtb_Divide_c[1] * rtb_Divide_c[1] + rtb_Divide_c[0] *
          rtb_Divide_c[0];

        /* Math: '<S112>/Math Function1' incorporates:
         *  Sum: '<S112>/Sum of Elements'
         *
         * About '<S112>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_u_h < 0.0F) {
          rtb_u_h = -sqrtf(fabsf(rtb_u_h));
        } else {
          rtb_u_h = sqrtf(rtb_u_h);
        }

        /* End of Math: '<S112>/Math Function1' */

        /* Switch: '<S112>/Switch' incorporates:
         *  Constant: '<S112>/Constant'
         *  Product: '<S112>/Product'
         */
        if (rtb_u_h > 0.0F) {
          rtb_Switch_av[0] = rtb_Divide_c[1];
          rtb_Switch_av[1] = rtb_Divide_c[0];
          rtb_Switch_av[2] = rtb_u_h;
        } else {
          rtb_Switch_av[0] = 0.0F;
          rtb_Switch_av[1] = 0.0F;
          rtb_Switch_av[2] = 1.0F;
        }

        /* End of Switch: '<S112>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S93>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_u_h = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_k = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S112>/Divide' */
        rtb_Divide_c[0] = rtb_Switch_av[0] / rtb_Switch_av[2];

        /* Product: '<S111>/Divide' */
        rtb_P_c[0] = rtb_Switch_h_idx_0 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S93>/Sum1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S112>/Divide' */
        rtb_Divide_c[1] = rtb_Switch_av[1] / rtb_Switch_av[2];

        /* Product: '<S111>/Divide' */
        rtb_P_c[1] = rtb_Switch_h_idx_1 / rtb_Switch_h_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S93>/Sum1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S93>/Divide' incorporates:
         *  Math: '<S94>/Square'
         *  Math: '<S95>/Square'
         *  Sqrt: '<S94>/Sqrt'
         *  Sqrt: '<S95>/Sqrt'
         *  Sum: '<S93>/Sum'
         *  Sum: '<S93>/Sum1'
         *  Sum: '<S94>/Sum of Elements'
         *  Sum: '<S95>/Sum of Elements'
         */
        rtb_Switch_h_idx_2 = sqrtf(rtb_Saturation_k * rtb_Saturation_k + rtb_u_h
          * rtb_u_h) / sqrtf(rtb_Switch_h_idx_0 * rtb_Switch_h_idx_0 +
                             rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1);

        /* Saturate: '<S93>/Saturation' */
        if (rtb_Switch_h_idx_2 > 1.0F) {
          rtb_Switch_h_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_2 < 0.0F) {
            rtb_Switch_h_idx_2 = 0.0F;
          }
        }

        /* End of Saturate: '<S93>/Saturation' */

        /* Sum: '<S110>/Subtract' incorporates:
         *  Product: '<S110>/Multiply'
         *  Product: '<S110>/Multiply1'
         */
        rtb_u_h = rtb_Divide_c[0] * rtb_P_c[1] - rtb_Divide_c[1] * rtb_P_c[0];

        /* Signum: '<S105>/Sign1' */
        if (rtb_u_h < 0.0F) {
          rtb_u_h = -1.0F;
        } else {
          if (rtb_u_h > 0.0F) {
            rtb_u_h = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign1' */

        /* Switch: '<S105>/Switch2' incorporates:
         *  Constant: '<S105>/Constant4'
         */
        if (rtb_u_h == 0.0F) {
          rtb_u_h = 1.0F;
        }

        /* End of Switch: '<S105>/Switch2' */

        /* DotProduct: '<S105>/Dot Product' */
        rtb_Switch_h_idx_1 = rtb_P_c[0] * rtb_Divide_c[0] + rtb_P_c[1] *
          rtb_Divide_c[1];

        /* Trigonometry: '<S105>/Acos' incorporates:
         *  DotProduct: '<S105>/Dot Product'
         */
        if (rtb_Switch_h_idx_1 > 1.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_h_idx_1 < -1.0F) {
            rtb_Switch_h_idx_1 = -1.0F;
          }
        }

        /* Product: '<S105>/Multiply' incorporates:
         *  Trigonometry: '<S105>/Acos'
         */
        rtb_u_h *= acosf(rtb_Switch_h_idx_1);

        /* Saturate: '<S99>/Saturation' */
        if (rtb_u_h > 1.57079637F) {
          rtb_u_h = 1.57079637F;
        } else {
          if (rtb_u_h < -1.57079637F) {
            rtb_u_h = -1.57079637F;
          }
        }

        /* End of Saturate: '<S99>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S106>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S106>/Square'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S106>/Sum of Elements'
         */
        rtb_Saturation_k = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S90>/Bus Assignment'
         *  Constant: '<S90>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S90>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S90>/vel'
         *  Constant: '<S92>/L1'
         *  Constant: '<S99>/Constant'
         *  Gain: '<S96>/AccToRate'
         *  Gain: '<S99>/Gain'
         *  Math: '<S99>/Square'
         *  MinMax: '<S99>/Max'
         *  MinMax: '<S99>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S99>/Divide'
         *  Product: '<S99>/Multiply1'
         *  Sqrt: '<S107>/Sqrt'
         *  Trigonometry: '<S99>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = rtb_Saturation_k * rtb_Saturation_k * 2.0F *
          arm_sin_f32(rtb_u_h) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_u), 0.5F)) *
          FMS_PARAM.ACC2RATE;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S91>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S93>/Multiply'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S91>/Sum2'
         *  Sum: '<S93>/Add'
         *  Sum: '<S93>/Subtract'
         */
        rtb_u = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
                   FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_h_idx_2 +
                  FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S91>/Saturation1' */
        if (rtb_u > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S90>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_u < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S90>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S90>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_u;
        }

        /* End of Saturate: '<S91>/Saturation1' */
        /* End of Outputs for SubSystem: '<S86>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S89>/Delay Input1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S89>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S27>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S27>/Unknown' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S27>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S27>/Switch Case' */
      /* End of Outputs for SubSystem: '<S22>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S22>/Assist' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* SwitchCase: '<S26>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_p) {
        switch (rtPrevAction) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S38>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S62>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S52>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S26>/Stabilize' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S33>/Bus Assignment'
         *  Constant: '<S33>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S33>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_p;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S85>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S85>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S82>/Gain6'
         *  Gain: '<S85>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u *
          FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S84>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S84>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S81>/Gain6'
         *  Gain: '<S84>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u *
          FMS_PARAM.MAX_R;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S83>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_throttle - (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S83>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S80>/Gain6'
         *  Gain: '<S83>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_u *
          -FMS_PARAM.VEL_Z_LIM;

        /* End of Outputs for SubSystem: '<S26>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S26>/Altitude' incorporates:
           *  ActionPort: '<S31>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S26>/Switch Case' incorporates:
           *  Chart: '<S39>/Motion Status'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S26>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S26>/Altitude' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S39>/Motion Status' incorporates:
         *  Abs: '<S39>/Abs'
         *  Abs: '<S39>/Abs1'
         *  Constant: '<S45>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S45>/Compare'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                         FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                         &rtb_state_cv, &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S38>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S38>/Hold Control' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S38>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S38>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S38>/Hold Control' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_a, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S38>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S38>/Brake Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S38>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S38>/Move Control' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S38>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S38>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S31>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S31>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S48>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S48>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S37>/Gain6'
         *  Gain: '<S48>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u *
          FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S47>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S47>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S36>/Gain6'
         *  Gain: '<S47>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u *
          FMS_PARAM.MAX_R;

        /* Saturate: '<S38>/Saturation1' */
        if (FMS_B.Merge_a > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S31>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_a < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S31>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S31>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_a;
        }

        /* End of Saturate: '<S38>/Saturation1' */
        /* End of Outputs for SubSystem: '<S26>/Altitude' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S26>/Position' incorporates:
           *  ActionPort: '<S32>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S26>/Switch Case' incorporates:
           *  Chart: '<S53>/Motion Status'
           *  Chart: '<S63>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_f);
          FMS_DW.temporalCounter_i1_j = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_n;

          /* End of SystemReset for SubSystem: '<S26>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S26>/Position' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S79>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S79>/Square'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S79>/Sum of Elements'
         */
        rtb_Switch_h_idx_0 = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat
          [0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
          FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3]
          * FMS_U.INS_Out.quat[3]);

        /* Product: '<S75>/Divide' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_u = FMS_U.INS_Out.quat[0] / rtb_Switch_h_idx_0;
        rtb_Switch_h_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Switch_h_idx_0;
        rtb_Switch_h_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Switch_h_idx_0;
        rtb_Switch_h_idx_0 = FMS_U.INS_Out.quat[3] / rtb_Switch_h_idx_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S76>/Square' incorporates:
         *  Math: '<S77>/Square'
         *  Math: '<S78>/Square'
         */
        rtb_u_h = rtb_u * rtb_u;

        /* Math: '<S76>/Square2' incorporates:
         *  Math: '<S77>/Square2'
         *  Math: '<S78>/Square2'
         */
        rtb_Saturation_k = rtb_Switch_h_idx_2 * rtb_Switch_h_idx_2;

        /* Math: '<S76>/Square1' incorporates:
         *  Math: '<S77>/Square1'
         *  Math: '<S78>/Square1'
         */
        rtb_AccToRate_k = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1;

        /* Math: '<S76>/Square3' incorporates:
         *  Math: '<S77>/Square3'
         *  Math: '<S78>/Square3'
         */
        rtb_MatrixConcatenate1_tmp_1 = rtb_Switch_h_idx_0 * rtb_Switch_h_idx_0;

        /* Sum: '<S76>/Subtract' incorporates:
         *  Math: '<S76>/Square'
         *  Math: '<S76>/Square1'
         *  Math: '<S76>/Square2'
         *  Math: '<S76>/Square3'
         *  Sum: '<S76>/Add'
         *  Sum: '<S76>/Add1'
         */
        rtb_MatrixConcatenate1[0] = (rtb_u_h + rtb_AccToRate_k) -
          (rtb_Saturation_k + rtb_MatrixConcatenate1_tmp_1);

        /* Product: '<S76>/Multiply' incorporates:
         *  Product: '<S77>/Multiply'
         */
        rtb_MatrixConcatenate1_tmp = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_2;

        /* Product: '<S76>/Multiply1' incorporates:
         *  Product: '<S77>/Multiply1'
         */
        rtb_MatrixConcatenate1_tmp_0 = rtb_u * rtb_Switch_h_idx_0;

        /* Gain: '<S76>/Gain' incorporates:
         *  Product: '<S76>/Multiply'
         *  Product: '<S76>/Multiply1'
         *  Sum: '<S76>/Subtract1'
         */
        rtb_MatrixConcatenate1[1] = (rtb_MatrixConcatenate1_tmp -
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Product: '<S76>/Multiply2' incorporates:
         *  Product: '<S78>/Multiply'
         */
        rtb_MatrixConcatenate1_tmp_2 = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_0;

        /* Product: '<S76>/Multiply3' incorporates:
         *  Product: '<S78>/Multiply1'
         */
        rtb_MatrixConcatenate1_tmp_3 = rtb_u * rtb_Switch_h_idx_2;

        /* Gain: '<S76>/Gain1' incorporates:
         *  Product: '<S76>/Multiply2'
         *  Product: '<S76>/Multiply3'
         *  Sum: '<S76>/Add2'
         */
        rtb_MatrixConcatenate1[2] = (rtb_MatrixConcatenate1_tmp_2 +
          rtb_MatrixConcatenate1_tmp_3) * 2.0F;

        /* Gain: '<S77>/Gain' incorporates:
         *  Sum: '<S77>/Add3'
         */
        rtb_MatrixConcatenate1[3] = (rtb_MatrixConcatenate1_tmp +
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Sum: '<S77>/Subtract' incorporates:
         *  Sum: '<S77>/Add'
         *  Sum: '<S77>/Add1'
         */
        rtb_MatrixConcatenate1[4] = (rtb_u_h + rtb_Saturation_k) -
          (rtb_AccToRate_k + rtb_MatrixConcatenate1_tmp_1);

        /* Product: '<S77>/Multiply2' incorporates:
         *  Product: '<S78>/Multiply2'
         */
        rtb_MatrixConcatenate1_tmp = rtb_Switch_h_idx_2 * rtb_Switch_h_idx_0;

        /* Product: '<S77>/Multiply3' incorporates:
         *  Product: '<S78>/Multiply3'
         */
        rtb_MatrixConcatenate1_tmp_0 = rtb_u * rtb_Switch_h_idx_1;

        /* Gain: '<S77>/Gain1' incorporates:
         *  Product: '<S77>/Multiply2'
         *  Product: '<S77>/Multiply3'
         *  Sum: '<S77>/Subtract1'
         */
        rtb_MatrixConcatenate1[5] = (rtb_MatrixConcatenate1_tmp -
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Gain: '<S78>/Gain' incorporates:
         *  Sum: '<S78>/Subtract2'
         */
        rtb_MatrixConcatenate1[6] = (rtb_MatrixConcatenate1_tmp_2 -
          rtb_MatrixConcatenate1_tmp_3) * 2.0F;

        /* Gain: '<S78>/Gain1' incorporates:
         *  Sum: '<S78>/Add2'
         */
        rtb_MatrixConcatenate1[7] = (rtb_MatrixConcatenate1_tmp +
          rtb_MatrixConcatenate1_tmp_0) * 2.0F;

        /* Sum: '<S78>/Subtract' incorporates:
         *  Sum: '<S78>/Add'
         *  Sum: '<S78>/Add1'
         */
        rtb_MatrixConcatenate1[8] = (rtb_u_h + rtb_MatrixConcatenate1_tmp_1) -
          (rtb_AccToRate_k + rtb_Saturation_k);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S53>/Motion Status' incorporates:
         *  Abs: '<S53>/Abs'
         *  Abs: '<S53>/Abs1'
         *  Constant: '<S59>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S59>/Compare'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                         FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                         &rtb_state_cv, &FMS_DW.sf_MotionStatus_f);

        /* RelationalOperator: '<S72>/Compare' incorporates:
         *  Abs: '<S63>/Abs2'
         *  Constant: '<S72>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        rtb_Compare_a = (fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S63>/Motion State' */
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

            /* Product: '<S71>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S21>/Signal Copy1'
             */
            for (i = 0; i < 3; i++) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_Switch_av[i] = rtb_MatrixConcatenate1[i + 6] *
                FMS_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
                                    FMS_U.INS_Out.ve + rtb_MatrixConcatenate1[i]
                                    * FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            }

            /* End of Product: '<S71>/Multiply' */
            if ((rtb_Switch_av[0] <= 0.1) || (FMS_DW.temporalCounter_i1_j >=
                 500U)) {
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

        /* End of Chart: '<S63>/Motion State' */

        /* SwitchCase: '<S62>/Switch Case' */
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
            /* InitializeConditions for IfAction SubSystem: '<S62>/Hold Control' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S62>/Switch Case' incorporates:
             *  Delay: '<S65>/Delay'
             */
            FMS_DW.icLoad = 1U;

            /* End of InitializeConditions for SubSystem: '<S62>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S62>/Hold Control' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* Delay: '<S65>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.Delay_DSTATE = FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Trigonometry: '<S69>/Trigonometric Function1' incorporates:
           *  Gain: '<S68>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S69>/Trigonometric Function3'
           */
          rtb_u_h = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_MatrixConcatenate1[0] = rtb_u_h;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Trigonometry: '<S69>/Trigonometric Function' incorporates:
           *  Gain: '<S68>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S69>/Trigonometric Function2'
           */
          rtb_Saturation_k = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_MatrixConcatenate1[1] = rtb_Saturation_k;

          /* SignalConversion: '<S69>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S69>/Constant3'
           */
          rtb_MatrixConcatenate1[2] = 0.0F;

          /* Gain: '<S69>/Gain' */
          rtb_MatrixConcatenate1[3] = -rtb_Saturation_k;

          /* Trigonometry: '<S69>/Trigonometric Function3' */
          rtb_MatrixConcatenate1[4] = rtb_u_h;

          /* SignalConversion: '<S69>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S69>/Constant4'
           */
          rtb_MatrixConcatenate1[5] = 0.0F;

          /* SignalConversion: '<S69>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_MatrixConcatenate1[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_MatrixConcatenate1[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_MatrixConcatenate1[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Reshape: '<S65>/Reshape' incorporates:
           *  Delay: '<S65>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Sum: '<S65>/Sum'
           */
          rtb_u = FMS_DW.Delay_DSTATE - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S65>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Switch_av[i] = rtb_MatrixConcatenate1[i] * rtb_u;
          }

          /* Gain: '<S65>/Gain2' incorporates:
           *  Product: '<S65>/Multiply'
           */
          FMS_B.Merge_i = FMS_PARAM.X_P * rtb_Switch_av[0];

          /* Update for Delay: '<S65>/Delay' */
          FMS_DW.icLoad = 0U;

          /* End of Outputs for SubSystem: '<S62>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S62>/Brake Control' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          /* SignalConversion: '<S64>/OutportBuffer_InsertedFor_u_cmd_mPs_at_inport_0' incorporates:
           *  Constant: '<S64>/Brake Speed'
           */
          FMS_B.Merge_i = 0.0F;

          /* End of Outputs for SubSystem: '<S62>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S62>/Move Control' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* DeadZone: '<S70>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S21>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_u = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_u = 0.0F;
          } else {
            rtb_u = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S70>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Gain: '<S66>/Gain6' incorporates:
           *  Gain: '<S70>/Gain'
           */
          FMS_B.Merge_i = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_u *
            FMS_PARAM.VEL_X_LIM;

          /* End of Outputs for SubSystem: '<S62>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S62>/Switch Case' */

        /* SwitchCase: '<S52>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S52>/Hold Control' incorporates:
             *  ActionPort: '<S55>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S52>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S52>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S52>/Hold Control' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S52>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S52>/Brake Control' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S52>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S52>/Move Control' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S52>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S52>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S32>/Bus Assignment'
         *  Constant: '<S32>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S32>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Saturate: '<S62>/Saturation1' */
        if (FMS_B.Merge_i > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S32>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (FMS_B.Merge_i < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S32>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S32>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_i;
        }

        /* End of Saturate: '<S62>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S61>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_u = 0.0F;
        } else {
          rtb_u = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S61>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S50>/Gain6'
         *  Gain: '<S61>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_u *
          FMS_PARAM.MAX_R;

        /* Saturate: '<S52>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S32>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S32>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S32>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S52>/Saturation1' */
        /* End of Outputs for SubSystem: '<S26>/Position' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S26>/Unknown' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_o);

        /* End of Outputs for SubSystem: '<S26>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S26>/Switch Case' */
      /* End of Outputs for SubSystem: '<S22>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S22>/Manual' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  BusAssignment: '<S28>/Bus Assignment'
       *  Constant: '<S28>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S28>/Bus Assignment' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  Constant: '<S28>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S22>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S22>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S22>/Switch Case' */
    /* End of Outputs for SubSystem: '<S20>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S20>/Switch Case' */

  /* BusAssignment: '<S23>/Bus Assignment' incorporates:
   *  Constant: '<S23>/Constant'
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  DiscreteIntegrator: '<S151>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S23>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* Update for DiscreteIntegrator: '<S151>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S151>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for UnitDelay: '<S7>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_u = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_u < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = (uint32_T)rtb_u;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S8>/Delay' */
  FMS_DW.Delay_DSTATE_k = rtb_Switch_k;
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
  /* Start for SwitchCase: '<S20>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S20>/Arm' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S22>/SubMode' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S22>/SubMode' */

  /* Start for IfAction SubSystem: '<S22>/Auto' */
  /* Start for SwitchCase: '<S27>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S22>/Auto' */

  /* Start for IfAction SubSystem: '<S22>/Assist' */
  /* Start for SwitchCase: '<S26>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for IfAction SubSystem: '<S26>/Altitude' */
  /* Start for SwitchCase: '<S38>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bg = -1;

  /* End of Start for SubSystem: '<S26>/Altitude' */

  /* Start for IfAction SubSystem: '<S26>/Position' */
  /* Start for SwitchCase: '<S62>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S52>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S26>/Position' */
  /* End of Start for SubSystem: '<S22>/Assist' */
  /* End of Start for SubSystem: '<S20>/Arm' */
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
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_n;
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
  /* SystemInitialize for IfAction SubSystem: '<S20>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S27>/Mission' */
  /* InitializeConditions for UnitDelay: '<S89>/Delay Input1'
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S27>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S22>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S26>/Altitude' */
  /* SystemInitialize for Chart: '<S39>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S38>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S38>/Hold Control' */

  /* SystemInitialize for Merge: '<S38>/Merge' */
  FMS_B.Merge_a = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S26>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S26>/Position' */
  /* SystemInitialize for Chart: '<S53>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_f);

  /* SystemInitialize for Chart: '<S63>/Motion State' */
  FMS_DW.temporalCounter_i1_j = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_n;

  /* SystemInitialize for IfAction SubSystem: '<S62>/Hold Control' */
  /* InitializeConditions for Delay: '<S65>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S62>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S52>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S52>/Hold Control' */

  /* SystemInitialize for Merge: '<S52>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S62>/Merge' */
  FMS_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S26>/Position' */
  /* End of SystemInitialize for SubSystem: '<S22>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S20>/Arm' */
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
