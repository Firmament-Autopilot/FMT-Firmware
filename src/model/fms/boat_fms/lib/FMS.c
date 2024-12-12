/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2038
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec 12 10:12:05 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S71>/Motion State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)1U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)
#define FMS_IN_NextWP                  ((uint8_T)2U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)2U)
#define FMS_IN_Return                  ((uint8_T)2U)
#define FMS_IN_Return_h                ((uint8_T)3U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)3U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Manual_b                ((uint8_T)1U)
#define FMS_IN_Other                   ((uint8_T)4U)
#define FMS_IN_Position_h              ((uint8_T)5U)
#define FMS_IN_Stabilize_m             ((uint8_T)6U)

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
struct_U5lw6bCUkWz4DxN5NeKa6F FMS_PARAM = {
  { 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1550.0F, 1550.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  10.0F,
  3.0F,
  5.0F,
  4.0F,
  0.7F,
  1.0F,
  10U,
  1U
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S23>/Constant'
                                        *   '<S29>/Constant6'
                                        *   '<S30>/Constant6'
                                        *   '<S127>/L1'
                                        *   '<S127>/vel'
                                        *   '<S40>/Gain'
                                        *   '<S86>/L1'
                                        *   '<S86>/vel'
                                        *   '<S130>/AY_P'
                                        *   '<S88>/AY_P'
                                        *   '<S44>/L1'
                                        *   '<S44>/AY_P'
                                        *   '<S73>/Gain2'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  10U,

  { 66, 111, 97, 116, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S11>/Constant1'
                                        *   '<S148>/Constant'
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
 *    '<S133>/NearbyRefWP'
 *    '<S91>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_k, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S137>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_k;
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
 * Output and update for action system:
 *    '<S34>/Unknown'
 *    '<S32>/Unknown'
 *    '<S31>/Unknown'
 *    '<S27>/Unknown'
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
 * Output and update for action system:
 *    '<S70>/Brake Control'
 *    '<S41>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S72>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S72>/Constant'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S70>/Move Control'
 *    '<S41>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S78>/Dead Zone' */
  if (rtu_FMS_In > 0.05F) {
    rtu_FMS_In_0 = rtu_FMS_In - 0.05F;
  } else if (rtu_FMS_In >= -0.05F) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - -0.05F;
  }

  /* End of DeadZone: '<S78>/Dead Zone' */

  /* Gain: '<S78>/Gain' */
  *rty_psi_rate_cmd_radPs = 1.05263162F * rtu_FMS_In_0;
}

/*
 * System initialize for atomic system:
 *    '<S71>/Motion State'
 *    '<S42>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S71>/Motion State'
 *    '<S42>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S71>/Motion State'
 *    '<S42>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, MotionState *rty_state,
                     DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S71>/Motion State' */
  if (localDW->temporalCounter_i1 < 255U) {
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
      if (rtu_motion_req) {
        localDW->is_c10_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      } else {
        if (localDW->temporalCounter_i1 >= 150U) {
          localDW->is_c10_FMS = FMS_IN_Hold;
          *rty_state = MotionState_Hold;
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

  /* End of Chart: '<S71>/Motion State' */
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_g, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = false;
  if ((ins_flag & 1U) != 0U) {
    switch (cmd_in) {
     case FMS_Cmd_Return:
     case FMS_Cmd_Pause:
      if (((ins_flag & 8U) != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag &
            64U) != 0U)) {
        valid = true;
      }
      break;

     case FMS_Cmd_PreArm:
      switch (mode_in) {
       case PilotMode_Position:
       case PilotMode_Offboard:
        if (((ins_flag & 8U) != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag &
              64U) != 0U)) {
          valid = true;
        }
        break;

       case PilotMode_Mission:
        if (((ins_flag & 8U) != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag &
              32U) != 0U) && ((ins_flag & 64U) != 0U)) {
          valid = true;
        }
        break;

       case PilotMode_Stabilize:
        valid = true;
        break;

       case PilotMode_Manual:
        valid = true;
        break;
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_g, &FMS_DW.Msg_FMS_Cmd_a
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
    FMS_DW.llo[0] = FMS_B.BusConversion_InsertedFor_FMSSt.lat_0 *
      57.295779513082323;
    FMS_DW.llo[1] = FMS_B.BusConversion_InsertedFor_FMSSt.lon_0 *
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

  /* Outputs for Function Call SubSystem: '<S5>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S161>/Compare' incorporates:
   *  Abs: '<S150>/Abs'
   *  Constant: '<S161>/Constant'
   *  MinMax: '<S150>/Max'
   *  Sum: '<S150>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S5>/Vehicle.StickMoved' */
  if (FMS_B.Compare_k && (FMS_B.target_mode != PilotMode_None)) {
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
      FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
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
        if (FMS_B.Compare) {
          FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_n;
          FMS_DW.is_Vehicle = FMS_IN_Arm;
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
          if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_n;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_n;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
          }
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

                  /* Outputs for Function Call SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Sum: '<S151>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S151>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S152>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S152>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S152>/Multiply1' incorporates:
                   *  Product: '<S152>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S152>/Divide' incorporates:
                   *  Constant: '<S152>/Constant'
                   *  Constant: '<S152>/R'
                   *  Sqrt: '<S152>/Sqrt'
                   *  Sum: '<S152>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S152>/Product3' incorporates:
                   *  Constant: '<S152>/Constant1'
                   *  Product: '<S152>/Multiply1'
                   *  Sum: '<S152>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S152>/Multiply2' incorporates:
                   *  Trigonometry: '<S152>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S156>/Abs' incorporates:
                   *  Abs: '<S159>/Abs1'
                   *  Switch: '<S156>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S156>/Switch1' incorporates:
                   *  Abs: '<S156>/Abs'
                   *  Bias: '<S156>/Bias2'
                   *  Bias: '<S156>/Bias3'
                   *  Constant: '<S153>/Constant'
                   *  Constant: '<S153>/Constant1'
                   *  Constant: '<S158>/Constant'
                   *  Gain: '<S156>/Gain1'
                   *  Product: '<S156>/Multiply'
                   *  RelationalOperator: '<S158>/Compare'
                   *  Switch: '<S153>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S159>/Switch1' incorporates:
                     *  Bias: '<S159>/Bias2'
                     *  Bias: '<S159>/Bias3'
                     *  Constant: '<S159>/Constant'
                     *  Constant: '<S160>/Constant'
                     *  Math: '<S159>/Math Function'
                     *  RelationalOperator: '<S160>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S159>/Switch1' */

                    /* Signum: '<S156>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S156>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S153>/Sum' incorporates:
                   *  Sum: '<S151>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S151>/Multiply' incorporates:
                   *  Gain: '<S151>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S155>/Switch1' incorporates:
                   *  Abs: '<S155>/Abs1'
                   *  Bias: '<S155>/Bias2'
                   *  Bias: '<S155>/Bias3'
                   *  Constant: '<S155>/Constant'
                   *  Constant: '<S157>/Constant'
                   *  Math: '<S155>/Math Function'
                   *  RelationalOperator: '<S157>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S155>/Switch1' */

                  /* Product: '<S151>/Multiply' incorporates:
                   *  Gain: '<S151>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S151>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S154>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S154>/Sum2' incorporates:
                   *  Product: '<S154>/Multiply1'
                   *  Product: '<S154>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S154>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S154>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S154>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S149>/Data Type Conversion' incorporates:
                   *  Gain: '<S151>/Gain'
                   *  Sum: '<S151>/Sum1'
                   */
                  FMS_B.DataTypeConversion[0] = (real32_T)rtb_Sum2_m;
                  FMS_B.DataTypeConversion[1] = (real32_T)rtb_Sum_d;
                  FMS_B.DataTypeConversion[2] = (real32_T)-(FMS_B.lla[2] +
                    FMS_B.href);

                  /* End of Outputs for SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0] +
                    FMS_DW.home[0];
                  FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1] +
                    FMS_DW.home[1];
                  FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2] +
                    FMS_DW.home[2];
                  FMS_B.state = VehicleState_Mission;
                } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
                  FMS_DW.is_Mission = FMS_IN_Return_h;
                  FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
                  FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
                  FMS_B.Cmd_In.sp_waypoint[2] = FMS_DW.home[2];
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
   case PilotMode_Manual:
   case PilotMode_Stabilize:
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
      } else if ((FMS_DW.temporalCounter_i1 >= 1000U) || (FMS_DW.sfEvent ==
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
             FMS_DW.durationLastReferenceTick_1 >= 200) || ((FMS_B.target_mode ==
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
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
    FMS_DW.is_active_Lost_Return = 1U;
    FMS_DW.is_Lost_Return = FMS_IN_Connect;
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
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_k > 150) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2 > 150) {
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
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
              FMS_DW.durationLastReferenceTick_1_k =
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_g, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_a[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T A;
  real32_T B;
  real32_T D;
  boolean_T rtb_FixPtRelationalOperator;
  uint8_T rtb_Switch_m;
  int8_T rtPrevAction;
  real32_T rtb_Integrator1_b;
  real32_T rtb_Divide_aj[2];
  real32_T rtb_MathFunction_k[2];
  real32_T rtb_a_a;
  real32_T rtb_Switch_fd[3];
  real32_T rtb_Gain;
  MotionState rtb_state_d;
  real32_T rtb_VectorConcatenate[9];
  int32_T i;
  boolean_T u;
  real32_T rtb_Switch_f_idx_0;
  real32_T rtb_Switch_f_idx_1;
  real32_T rtb_Switch_f_idx_2;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_P_f_idx_0;
  real32_T rtb_P_f_idx_1;
  real32_T rtb_P_i_idx_0;
  real32_T u1_tmp;
  uint32_T rtb_Compare_iv_tmp;
  boolean_T guard1 = false;

  /* Outputs for Atomic SubSystem: '<Root>/CommandProcess' */
  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  UnitDelay: '<S15>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_ak) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Delay: '<S13>/Delay'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  Switch: '<S13>/Switch1'
   *  UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S13>/Switch1' incorporates:
       *  DataTypeConversion: '<S13>/Data Type Conversion1'
       *  Delay: '<S13>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S13>/Switch' */

  /* Switch: '<S12>/Switch1' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch2'
   *  UnitDelay: '<S16>/Delay Input1'
   *  UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S12>/Switch2' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Update for UnitDelay: '<S15>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_ak = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Gain;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S20>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* End of Outputs for SubSystem: '<Root>/CommandProcess' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S13>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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
     case FMS_IN_Manual_b:
      FMS_B.target_mode = PilotMode_Manual;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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

     case FMS_IN_Mission:
      if (((FMS_U.INS_Out.flag & 8U) != 0U) && ((FMS_U.INS_Out.flag & 32U) != 0U))
      {
        FMS_B.target_mode = PilotMode_Mission;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
      }
      break;

     case FMS_IN_Offboard:
      if (((FMS_U.INS_Out.flag & 8U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U))
      {
        FMS_B.target_mode = PilotMode_Offboard;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
      }
      break;

     case FMS_IN_Other:
      FMS_B.target_mode = FMS_DW.Delay_DSTATE_c;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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

     case FMS_IN_Position_h:
      if (((FMS_U.INS_Out.flag & 8U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U))
      {
        FMS_B.target_mode = PilotMode_Position;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
      }
      break;

     default:
      if ((FMS_U.INS_Out.flag & 8U) != 0U) {
        FMS_B.target_mode = PilotMode_Stabilize;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_m;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_h;
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
        FMS_DW.is_c3_FMS = FMS_IN_Manual_b;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S22>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = (FMS_U.Pilot_Cmd.timestamp !=
    FMS_DW.DelayInput1_DSTATE_d);

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  RelationalOperator: '<S21>/FixPt Relational Operator'
   *  UnitDelay: '<S21>/Delay Input1'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.GCS_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) ||
      rtb_FixPtRelationalOperator || (FMS_PARAM.LOST_RETURN_EN == 0)) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S23>/Compare'
   */
  FMS_B.LogicalOperator2 = ((FMS_DW.DiscreteTimeIntegrator_DSTATE >=
    FMS_PARAM.LOST_RETURN_TIME) && (FMS_PARAM.LOST_RETURN_EN != 0));

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */
  if (rtb_FixPtRelationalOperator) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Delay: '<S9>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S8>/FixPt Relational Operator'
   *  Switch: '<S9>/Switch'
   *  UnitDelay: '<S8>/Delay Input1'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_j = 0U;
    rtb_Switch_m = 1U;
  } else {
    rtb_Switch_m = FMS_DW.Delay_DSTATE_p;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S10>/Upper Limit'
   *  Constant: '<S7>/Constant'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S10>/Upper Test'
   *  RelationalOperator: '<S7>/Compare'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_j < 1000U) &&
    (rtb_Switch_m != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_FixPtRelationalOperator = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_FixPtRelationalOperator) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_FixPtRelationalOperator;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 1023U) {
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
  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  /* SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_fd[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_fd[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_fd[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

  /* SwitchCase: '<S25>/Switch Case' incorporates:
   *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S27>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S34>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S32>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S31>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Disable for SwitchCase: '<S70>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S41>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
        break;

       case 2:
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S27>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S25>/Disarm' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S28>/Bus Assignment'
     *  BusAssignment: '<S29>/Bus Assignment'
     *  Constant: '<S29>/Constant'
     *  SignalConversion: '<S29>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S29>/Bus Assignment' incorporates:
     *  BusAssignment: '<S28>/Bus Assignment'
     *  Constant: '<S29>/Constant2'
     *  DataTypeConversion: '<S29>/Data Type Conversion2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S29>/Data Type Conversion2' incorporates:
       *  Constant: '<S29>/Constant6'
       */
      rtb_Gain = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
    }

    /* End of Outputs for SubSystem: '<S25>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S25>/Standby' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S28>/Bus Assignment'
     *  BusAssignment: '<S30>/Bus Assignment'
     *  Constant: '<S30>/Constant'
     *  SignalConversion: '<S30>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S30>/Bus Assignment' incorporates:
     *  BusAssignment: '<S28>/Bus Assignment'
     *  Constant: '<S30>/Constant2'
     *  DataTypeConversion: '<S30>/Data Type Conversion3'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S30>/Data Type Conversion3' incorporates:
       *  Constant: '<S30>/Constant6'
       */
      rtb_Gain = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
    }

    /* End of Outputs for SubSystem: '<S25>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S25>/Arm' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SwitchCase: '<S27>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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

    /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S34>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S32>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S31>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Disable for SwitchCase: '<S70>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S41>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
          break;

         case 2:
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
      /* Outputs for IfAction SubSystem: '<S27>/SubMode' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* SwitchCase: '<S34>/Switch Case' incorporates:
       *  Product: '<S146>/Divide'
       *  Sum: '<S134>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Return' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Delay: '<S131>/Delay'
           *  DiscreteIntegrator: '<S129>/Integrator'
           *  DiscreteIntegrator: '<S129>/Integrator1'
           */
          FMS_DW.icLoad_c = 1U;
          FMS_DW.Integrator1_DSTATE_n = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Return' incorporates:
         *  ActionPort: '<S127>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S143>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S143>/Math Function'
         *  SignalConversion: '<S26>/Signal Copy1'
         *  Sum: '<S141>/Sum of Elements'
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S143>/Math Function1' incorporates:
         *  Sum: '<S143>/Sum of Elements'
         *
         * About '<S143>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_Integrator1_b = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_Integrator1_b = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S143>/Math Function1' */

        /* Switch: '<S143>/Switch' incorporates:
         *  Constant: '<S143>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S143>/Product'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        if (rtb_Integrator1_b > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_Integrator1_b;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S143>/Switch' */

        /* Product: '<S143>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S146>/Sum of Elements' incorporates:
         *  Math: '<S146>/Math Function'
         *  SignalConversion: '<S146>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S146>/Math Function1' incorporates:
         *  Sum: '<S146>/Sum of Elements'
         *
         * About '<S146>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_Integrator1_b = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_Integrator1_b = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S146>/Math Function1' */

        /* Switch: '<S146>/Switch' incorporates:
         *  Constant: '<S146>/Constant'
         *  Product: '<S146>/Product'
         */
        if (rtb_Integrator1_b > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_aj[1];
          rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
          rtb_Switch_f_idx_2 = rtb_Integrator1_b;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S146>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S133>/NearbyRefWP' incorporates:
         *  Constant: '<S127>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fd[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_aj, &rtb_a_a);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Delay: '<S131>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_f[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_f[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S133>/SearchL1RefWP' incorporates:
         *  Constant: '<S127>/L1'
         *  Delay: '<S131>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S133>/OutRegionRegWP'
         *  SignalConversion: '<S26>/Signal Copy1'
         *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_f[0];
        rtb_Integrator1_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_f
          [1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        A = rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_Integrator1_b *
          rtb_Integrator1_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_P_i_idx_0 * (FMS_DW.Delay_DSTATE_f[0] - FMS_U.INS_Out.x_R) +
             rtb_Integrator1_b * (FMS_DW.Delay_DSTATE_f[1] - FMS_U.INS_Out.y_R))
          * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_f[0] * FMS_DW.Delay_DSTATE_f[0]) +
                       FMS_DW.Delay_DSTATE_f[1] * FMS_DW.Delay_DSTATE_f[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_f[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_f[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_P_f_idx_0 = 0.0F;
        rtb_P_f_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          B = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (B >= 0.0F) && (B <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, B);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((B >= 0.0F) && (B <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = B;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_P_f_idx_0 = rtb_P_i_idx_0 * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE_f[0];
          rtb_P_f_idx_1 = rtb_Integrator1_b * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE_f[1];
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S133>/OutRegionRegWP' incorporates:
         *  Delay: '<S131>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        B = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_f[1]) * rtb_Integrator1_b
             + (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_f[0]) * rtb_P_i_idx_0) /
          (rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_Integrator1_b * rtb_Integrator1_b);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator = (B <= 0.0F);
        u = (B >= 1.0F);
        if (rtb_FixPtRelationalOperator) {
          rtb_P_i_idx_0 = FMS_DW.Delay_DSTATE_f[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          rtb_P_i_idx_0 = B * rtb_P_i_idx_0 + FMS_DW.Delay_DSTATE_f[0];
        }

        /* Switch: '<S133>/Switch1' incorporates:
         *  Constant: '<S136>/Constant'
         *  RelationalOperator: '<S136>/Compare'
         */
        if (rtb_a_a <= 0.0F) {
          /* Switch: '<S133>/Switch' incorporates:
           *  Constant: '<S135>/Constant'
           *  MATLAB Function: '<S133>/SearchL1RefWP'
           *  RelationalOperator: '<S135>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_Divide_aj[0] = rtb_P_f_idx_0;
            rtb_Divide_aj[1] = rtb_P_f_idx_1;
          } else {
            rtb_Divide_aj[0] = rtb_P_i_idx_0;

            /* MATLAB Function: '<S133>/OutRegionRegWP' incorporates:
             *  Delay: '<S131>/Delay'
             *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator) {
              rtb_Divide_aj[1] = FMS_DW.Delay_DSTATE_f[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Divide_aj[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Divide_aj[1] = B * rtb_Integrator1_b + FMS_DW.Delay_DSTATE_f[1];
            }
          }

          /* End of Switch: '<S133>/Switch' */
        }

        /* End of Switch: '<S133>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S134>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        B = rtb_Divide_aj[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S144>/Math Function' */
        rtb_TmpSignalConversionAtMath_0 = B * B;
        rtb_Divide_aj[0] = B;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S134>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        B = rtb_Divide_aj[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S144>/Math Function' incorporates:
         *  Math: '<S142>/Square'
         */
        rtb_P_i_idx_0 = B * B;

        /* Sum: '<S144>/Sum of Elements' incorporates:
         *  Math: '<S144>/Math Function'
         */
        rtb_Integrator1_b = rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S144>/Math Function1' incorporates:
         *  Sum: '<S144>/Sum of Elements'
         *
         * About '<S144>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Integrator1_b < 0.0F) {
          rtb_Integrator1_b = -sqrtf(fabsf(rtb_Integrator1_b));
        } else {
          rtb_Integrator1_b = sqrtf(rtb_Integrator1_b);
        }

        /* End of Math: '<S144>/Math Function1' */

        /* Switch: '<S144>/Switch' incorporates:
         *  Constant: '<S144>/Constant'
         *  Product: '<S144>/Product'
         */
        if (rtb_Integrator1_b > 0.0F) {
          rtb_Switch_fd[0] = rtb_Divide_aj[0];
          rtb_Switch_fd[1] = B;
          rtb_Switch_fd[2] = rtb_Integrator1_b;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S144>/Switch' */

        /* Product: '<S144>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_fd[0] / rtb_Switch_fd[2];
        rtb_a_a = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Sum: '<S147>/Sum of Elements' incorporates:
         *  Math: '<S147>/Math Function'
         *  SignalConversion: '<S147>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Integrator1_b = rtb_a_a * rtb_a_a + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S147>/Math Function1' incorporates:
         *  Sum: '<S147>/Sum of Elements'
         *
         * About '<S147>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Integrator1_b < 0.0F) {
          rtb_Integrator1_b = -sqrtf(fabsf(rtb_Integrator1_b));
        } else {
          rtb_Integrator1_b = sqrtf(rtb_Integrator1_b);
        }

        /* End of Math: '<S147>/Math Function1' */

        /* Switch: '<S147>/Switch' incorporates:
         *  Constant: '<S147>/Constant'
         *  Product: '<S147>/Product'
         */
        if (rtb_Integrator1_b > 0.0F) {
          rtb_Switch_fd[0] = rtb_a_a;
          rtb_Switch_fd[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_fd[2] = rtb_Integrator1_b;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S147>/Switch' */

        /* Product: '<S147>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_fd[0] / rtb_Switch_fd[2];

        /* Math: '<S142>/Square' */
        rtb_MathFunction_k[0] = rtb_Divide_aj[0] * rtb_Divide_aj[0];
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S147>/Divide' incorporates:
         *  Product: '<S146>/Divide'
         */
        rtb_a_a = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Product: '<S146>/Divide' */
        B = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sqrt: '<S141>/Sqrt' */
        rtb_Integrator1_b = sqrtf(rtb_Gain);

        /* Gain: '<S134>/Gain' incorporates:
         *  Math: '<S134>/Square'
         */
        rtb_Gain = rtb_Integrator1_b * rtb_Integrator1_b * 2.0F;

        /* Sum: '<S145>/Subtract' incorporates:
         *  Product: '<S145>/Multiply'
         *  Product: '<S145>/Multiply1'
         */
        rtb_Integrator1_b = rtb_TmpSignalConversionAtMath_0 * B - rtb_a_a *
          rtb_Divide_aj[0];

        /* Signum: '<S140>/Sign1' */
        if (rtb_Integrator1_b < 0.0F) {
          rtb_Integrator1_b = -1.0F;
        } else {
          if (rtb_Integrator1_b > 0.0F) {
            rtb_Integrator1_b = 1.0F;
          }
        }

        /* End of Signum: '<S140>/Sign1' */

        /* Switch: '<S140>/Switch2' incorporates:
         *  Constant: '<S140>/Constant4'
         */
        if (rtb_Integrator1_b == 0.0F) {
          rtb_Integrator1_b = 1.0F;
        }

        /* End of Switch: '<S140>/Switch2' */

        /* DotProduct: '<S140>/Dot Product' */
        B = rtb_Divide_aj[0] * rtb_TmpSignalConversionAtMath_0 + B * rtb_a_a;

        /* Trigonometry: '<S140>/Acos' incorporates:
         *  DotProduct: '<S140>/Dot Product'
         */
        if (B > 1.0F) {
          B = 1.0F;
        } else {
          if (B < -1.0F) {
            B = -1.0F;
          }
        }

        /* Product: '<S140>/Multiply' incorporates:
         *  Trigonometry: '<S140>/Acos'
         */
        rtb_Integrator1_b *= acosf(B);

        /* Saturate: '<S134>/Saturation' */
        if (rtb_Integrator1_b > 1.57079637F) {
          rtb_Integrator1_b = 1.57079637F;
        } else {
          if (rtb_Integrator1_b < -1.57079637F) {
            rtb_Integrator1_b = -1.57079637F;
          }
        }

        /* End of Saturate: '<S134>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S127>/Bus Assignment1'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S127>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S127>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S127>/L1'
         *  Constant: '<S134>/Constant'
         *  DiscreteIntegrator: '<S129>/Integrator1'
         *  Gain: '<S130>/AY_P'
         *  MinMax: '<S134>/Max'
         *  MinMax: '<S134>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S134>/Divide'
         *  Product: '<S134>/Multiply1'
         *  Sqrt: '<S142>/Sqrt'
         *  Sum: '<S142>/Sum of Elements'
         *  Trigonometry: '<S134>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_n;
        FMS_Y.FMS_Out.psi_rate_cmd = arm_sin_f32(rtb_Integrator1_b) * rtb_Gain /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_P_i_idx_0 + rtb_MathFunction_k[0]),
                 0.5F)) * FMS_PARAM.AY_P;

        /* Product: '<S132>/Multiply1' incorporates:
         *  Constant: '<S132>/const1'
         *  DiscreteIntegrator: '<S129>/Integrator'
         */
        rtb_Switch_f_idx_1 = FMS_DW.Integrator_DSTATE_c * 0.5F;

        /* Sum: '<S132>/Add' incorporates:
         *  Constant: '<S127>/vel'
         *  DiscreteIntegrator: '<S129>/Integrator1'
         *  Sum: '<S129>/Subtract'
         */
        rtb_Gain = (FMS_DW.Integrator1_DSTATE_n - FMS_PARAM.CRUISE_SPEED) +
          rtb_Switch_f_idx_1;

        /* Signum: '<S132>/Sign' */
        if (rtb_Gain < 0.0F) {
          rtb_Switch_f_idx_2 = -1.0F;
        } else if (rtb_Gain > 0.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          rtb_Switch_f_idx_2 = rtb_Gain;
        }

        /* End of Signum: '<S132>/Sign' */

        /* Sum: '<S132>/Add2' incorporates:
         *  Abs: '<S132>/Abs'
         *  Gain: '<S132>/Gain'
         *  Gain: '<S132>/Gain1'
         *  Product: '<S132>/Multiply2'
         *  Product: '<S132>/Multiply3'
         *  Sqrt: '<S132>/Sqrt'
         *  Sum: '<S132>/Add1'
         *  Sum: '<S132>/Subtract'
         */
        rtb_a_a = (sqrtf((8.0F * fabsf(rtb_Gain) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Switch_f_idx_2 + rtb_Switch_f_idx_1;

        /* Sum: '<S132>/Add4' */
        rtb_Switch_f_idx_1 += rtb_Gain - rtb_a_a;

        /* Sum: '<S132>/Add3' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Gain + FMS_ConstB.d_l;

        /* Sum: '<S132>/Subtract1' */
        rtb_Gain -= FMS_ConstB.d_l;

        /* Signum: '<S132>/Sign1' */
        if (rtb_TmpSignalConversionAtMath_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_0 > 0.0F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign1' */

        /* Signum: '<S132>/Sign2' */
        if (rtb_Gain < 0.0F) {
          rtb_Gain = -1.0F;
        } else {
          if (rtb_Gain > 0.0F) {
            rtb_Gain = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign2' */

        /* Sum: '<S132>/Add5' incorporates:
         *  Gain: '<S132>/Gain2'
         *  Product: '<S132>/Multiply4'
         *  Sum: '<S132>/Subtract2'
         */
        rtb_a_a += (rtb_TmpSignalConversionAtMath_0 - rtb_Gain) * 0.5F *
          rtb_Switch_f_idx_1;

        /* Update for Delay: '<S131>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for DiscreteIntegrator: '<S129>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S129>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.01F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S132>/Subtract3' */
        rtb_TmpSignalConversionAtMath_0 = rtb_a_a - FMS_ConstB.d_l;

        /* Sum: '<S132>/Add6' */
        B = rtb_a_a + FMS_ConstB.d_l;

        /* Signum: '<S132>/Sign5' */
        if (rtb_a_a < 0.0F) {
          rtb_Gain = -1.0F;
        } else if (rtb_a_a > 0.0F) {
          rtb_Gain = 1.0F;
        } else {
          rtb_Gain = rtb_a_a;
        }

        /* End of Signum: '<S132>/Sign5' */

        /* Signum: '<S132>/Sign3' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign3' */

        /* Signum: '<S132>/Sign4' */
        if (rtb_TmpSignalConversionAtMath_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_0 > 0.0F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign4' */

        /* Signum: '<S132>/Sign6' */
        if (rtb_a_a < 0.0F) {
          rtb_Switch_f_idx_1 = -1.0F;
        } else if (rtb_a_a > 0.0F) {
          rtb_Switch_f_idx_1 = 1.0F;
        } else {
          rtb_Switch_f_idx_1 = rtb_a_a;
        }

        /* End of Signum: '<S132>/Sign6' */

        /* Update for DiscreteIntegrator: '<S129>/Integrator' incorporates:
         *  Constant: '<S132>/const'
         *  Gain: '<S132>/Gain3'
         *  Product: '<S132>/Divide'
         *  Product: '<S132>/Multiply5'
         *  Product: '<S132>/Multiply6'
         *  Sum: '<S132>/Subtract4'
         *  Sum: '<S132>/Subtract5'
         *  Sum: '<S132>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_a_a / FMS_ConstB.d_l - rtb_Gain) *
          FMS_ConstB.Gain4_i * ((B - rtb_TmpSignalConversionAtMath_0) * 0.5F) -
          rtb_Switch_f_idx_1 * 19.612F) * 0.01F;

        /* End of Outputs for SubSystem: '<S34>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S34>/Hold' incorporates:
         *  ActionPort: '<S126>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S126>/Bus Assignment'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S126>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S126>/Bus Assignment' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S126>/Constant3'
         *  Constant: '<S126>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* End of Outputs for SubSystem: '<S34>/Hold' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S34>/Unknown' incorporates:
         *  ActionPort: '<S128>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S34>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S34>/Switch Case' */
      /* End of Outputs for SubSystem: '<S27>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S27>/Auto' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* SwitchCase: '<S32>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S32>/Offboard' incorporates:
         *  ActionPort: '<S83>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* S-Function (sfix_bitop): '<S115>/u_cmd valid' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  S-Function (sfix_bitop): '<S106>/u_cmd'
         *  SignalConversion: '<S26>/Signal Copy'
         */
        rtb_Compare_iv_tmp = FMS_U.Auto_Cmd.cmd_mask & 8192U;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* RelationalOperator: '<S118>/Compare' incorporates:
         *  Constant: '<S118>/Constant'
         *  S-Function (sfix_bitop): '<S115>/u_cmd valid'
         */
        rtb_FixPtRelationalOperator = (rtb_Compare_iv_tmp > 0U);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S107>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S107>/Multiply'
         *  Product: '<S116>/Multiply'
         *  Product: '<S117>/Multiply3'
         *  SignalConversion: '<S26>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S120>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S120>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S120>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* Trigonometry: '<S120>/Trigonometric Function3' incorporates:
           *  Gain: '<S119>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           *  Trigonometry: '<S120>/Trigonometric Function1'
           */
          rtb_Gain = arm_cos_f32(-FMS_U.INS_Out.psi);
          rtb_VectorConcatenate[4] = rtb_Gain;

          /* Trigonometry: '<S120>/Trigonometric Function2' incorporates:
           *  Gain: '<S119>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           *  Trigonometry: '<S120>/Trigonometric Function'
           */
          rtb_Switch_f_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S120>/Gain' incorporates:
           *  Trigonometry: '<S120>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -rtb_Switch_f_idx_1;

          /* SignalConversion: '<S120>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S120>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Trigonometry: '<S120>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Switch_f_idx_1;

          /* Trigonometry: '<S120>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Gain;

          /* Product: '<S107>/Multiply' */
          rtb_Gain = rtb_FixPtRelationalOperator ? FMS_U.Auto_Cmd.u_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_Switch_fd[i] = rtb_VectorConcatenate[i] * rtb_Gain;
          }
          break;

         case 1:
          /* SignalConversion: '<S122>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_o[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_o[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* SignalConversion: '<S122>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S122>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* Gain: '<S121>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S117>/Subtract'
           */
          rtb_Switch_f_idx_1 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S122>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S122>/Trigonometric Function1'
           */
          rtb_Gain = arm_cos_f32(rtb_Switch_f_idx_1);
          rtb_VectorConcatenate[4] = rtb_Gain;

          /* Trigonometry: '<S122>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S122>/Trigonometric Function'
           */
          rtb_Switch_f_idx_1 = arm_sin_f32(rtb_Switch_f_idx_1);

          /* Gain: '<S122>/Gain' incorporates:
           *  Trigonometry: '<S122>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -rtb_Switch_f_idx_1;

          /* SignalConversion: '<S122>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S122>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Trigonometry: '<S122>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Switch_f_idx_1;

          /* Trigonometry: '<S122>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Gain;

          /* Product: '<S107>/Multiply' */
          rtb_Gain = rtb_FixPtRelationalOperator ? FMS_U.Auto_Cmd.u_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_Switch_fd[i] = rtb_VectorConcatenate[i] * rtb_Gain;
          }
          break;

         default:
          rtb_Switch_fd[0] = rtb_FixPtRelationalOperator ? FMS_U.Auto_Cmd.u_cmd :
            0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S107>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  BusAssignment: '<S83>/Bus Assignment'
         *  Constant: '<S83>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S83>/Bus Assignment' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S108>/Constant'
         *  Constant: '<S109>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S110>/bit_shift'
         *  MATLAB Function: '<S111>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S108>/Compare'
         *  RelationalOperator: '<S109>/Compare'
         *  S-Function (sfix_bitop): '<S106>/psi_rate_cmd'
         *  SignalConversion: '<S26>/Signal Copy'
         *  Sum: '<S106>/Add'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_c;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_fd[0];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        FMS_Y.FMS_Out.psi_rate_cmd = FMS_U.Auto_Cmd.psi_rate_cmd;

        /* Outputs for Atomic SubSystem: '<S106>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S106>/u_cmd_valid' */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask
          & 64U) > 0U) << 5) + ((rtb_Compare_iv_tmp > 0U) << 6));

        /* End of Outputs for SubSystem: '<S106>/u_cmd_valid' */
        /* End of Outputs for SubSystem: '<S106>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S32>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S32>/Mission' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S32>/Switch Case' incorporates:
           *  UnitDelay: '<S85>/Delay Input1'
           *
           * Block description for '<S85>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S32>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S32>/Mission' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S82>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S32>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S87>/Integrator'
           *  DiscreteIntegrator: '<S87>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;

          /* End of SystemReset for SubSystem: '<S82>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S32>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Mission' incorporates:
         *  ActionPort: '<S82>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S85>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S85>/Delay Input1'
         *
         * Block description for '<S85>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S82>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S86>/Reset'
         */
        if (rtb_FixPtRelationalOperator &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator1' */
          FMS_DW.Integrator1_DSTATE = 0.0F;

          /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator' */
          FMS_DW.Integrator_DSTATE = 0.0F;
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S101>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S101>/Math Function'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S101>/Math Function1' incorporates:
         *  Sum: '<S101>/Sum of Elements'
         *
         * About '<S101>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S101>/Math Function1' */

        /* Switch: '<S101>/Switch' incorporates:
         *  Constant: '<S101>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S101>/Product'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S101>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S91>/NearbyRefWP' incorporates:
         *  Constant: '<S86>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fd[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_MathFunction_k, &rtb_Gain);

        /* MATLAB Function: '<S91>/SearchL1RefWP' incorporates:
         *  Constant: '<S86>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S91>/OutRegionRegWP'
         *  SignalConversion: '<S26>/Signal Copy1'
         *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_Integrator1_b = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        A = rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_Integrator1_b *
          rtb_Integrator1_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_P_i_idx_0 * (FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R)
             + rtb_Integrator1_b * (FMS_B.Cmd_In.cur_waypoint[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_B.Cmd_In.cur_waypoint[0] *
                        FMS_B.Cmd_In.cur_waypoint[0]) +
                       FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint
                       [1]) - (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0]
          + FMS_U.INS_Out.y_R * FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_Divide_aj[0] = 0.0F;
        rtb_Divide_aj[1] = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          B = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (B >= 0.0F) && (B <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, B);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((B >= 0.0F) && (B <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = B;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Divide_aj[0] = rtb_P_i_idx_0 * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_aj[1] = rtb_Integrator1_b * rtb_TmpSignalConversionAtMath_0
            + FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S91>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        B = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
             rtb_Integrator1_b + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
              [0]) * rtb_P_i_idx_0) / (rtb_P_i_idx_0 * rtb_P_i_idx_0 +
          rtb_Integrator1_b * rtb_Integrator1_b);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator = (B <= 0.0F);
        u = (B >= 1.0F);
        if (rtb_FixPtRelationalOperator) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_f_idx_0 = B * rtb_P_i_idx_0 + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S91>/Switch1' incorporates:
         *  Constant: '<S94>/Constant'
         *  RelationalOperator: '<S94>/Compare'
         */
        if (rtb_Gain <= 0.0F) {
          /* Switch: '<S91>/Switch' incorporates:
           *  Constant: '<S93>/Constant'
           *  MATLAB Function: '<S91>/SearchL1RefWP'
           *  RelationalOperator: '<S93>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_MathFunction_k[0] = rtb_Divide_aj[0];
            rtb_MathFunction_k[1] = rtb_Divide_aj[1];
          } else {
            rtb_MathFunction_k[0] = rtb_P_f_idx_0;

            /* MATLAB Function: '<S91>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_MathFunction_k[1] = B * rtb_Integrator1_b +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }
          }

          /* End of Switch: '<S91>/Switch' */
        }

        /* End of Switch: '<S91>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S92>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S26>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_k[0] -
          FMS_U.INS_Out.x_R;
        rtb_a_a = rtb_MathFunction_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S102>/Math Function' incorporates:
         *  Math: '<S100>/Square'
         */
        B = rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;
        rtb_Gain = rtb_a_a * rtb_a_a;

        /* Sum: '<S102>/Sum of Elements' incorporates:
         *  Math: '<S102>/Math Function'
         */
        rtb_P_i_idx_0 = B + rtb_Gain;

        /* Math: '<S102>/Math Function1' incorporates:
         *  Sum: '<S102>/Sum of Elements'
         *
         * About '<S102>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S102>/Math Function1' */

        /* Switch: '<S102>/Switch' incorporates:
         *  Constant: '<S102>/Constant'
         *  Product: '<S102>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_fd[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_fd[1] = rtb_a_a;
          rtb_Switch_fd[2] = rtb_P_i_idx_0;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S102>/Switch' */

        /* Product: '<S101>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S104>/Sum of Elements' incorporates:
         *  Math: '<S104>/Math Function'
         *  SignalConversion: '<S104>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S104>/Math Function1' incorporates:
         *  Sum: '<S104>/Sum of Elements'
         *
         * About '<S104>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S104>/Math Function1' */

        /* Switch: '<S104>/Switch' incorporates:
         *  Constant: '<S104>/Constant'
         *  Product: '<S104>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_aj[1];
          rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
          rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S104>/Switch' */

        /* Product: '<S102>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_fd[0] / rtb_Switch_fd[2];
        rtb_Divide_aj[1] = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Sum: '<S105>/Sum of Elements' incorporates:
         *  Math: '<S105>/Math Function'
         *  SignalConversion: '<S105>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S105>/Math Function1' incorporates:
         *  Sum: '<S105>/Sum of Elements'
         *
         * About '<S105>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S105>/Math Function1' */

        /* Switch: '<S105>/Switch' incorporates:
         *  Constant: '<S105>/Constant'
         *  Product: '<S105>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_fd[0] = rtb_Divide_aj[1];
          rtb_Switch_fd[1] = rtb_Divide_aj[0];
          rtb_Switch_fd[2] = rtb_P_i_idx_0;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S105>/Switch' */

        /* Product: '<S105>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_fd[0] / rtb_Switch_fd[2];

        /* Product: '<S104>/Divide' */
        rtb_MathFunction_k[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S105>/Divide' */
        rtb_Divide_aj[1] = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Product: '<S104>/Divide' */
        rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S99>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S99>/Square'
         *  SignalConversion: '<S26>/Signal Copy1'
         *  Sum: '<S99>/Sum of Elements'
         */
        rtb_P_i_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S92>/Gain' incorporates:
         *  Math: '<S92>/Square'
         */
        rtb_Switch_f_idx_1 = rtb_P_i_idx_0 * rtb_P_i_idx_0 * 2.0F;

        /* Sum: '<S103>/Subtract' incorporates:
         *  Product: '<S103>/Multiply'
         *  Product: '<S103>/Multiply1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[0] * rtb_MathFunction_k[1] -
          rtb_Divide_aj[1] * rtb_MathFunction_k[0];

        /* Signum: '<S98>/Sign1' */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -1.0F;
        } else {
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_P_i_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S98>/Sign1' */

        /* Switch: '<S98>/Switch2' incorporates:
         *  Constant: '<S98>/Constant4'
         */
        if (rtb_P_i_idx_0 == 0.0F) {
          rtb_P_i_idx_0 = 1.0F;
        }

        /* End of Switch: '<S98>/Switch2' */

        /* DotProduct: '<S98>/Dot Product' */
        rtb_Switch_f_idx_2 = rtb_MathFunction_k[0] * rtb_Divide_aj[0] +
          rtb_MathFunction_k[1] * rtb_Divide_aj[1];

        /* Trigonometry: '<S98>/Acos' incorporates:
         *  DotProduct: '<S98>/Dot Product'
         */
        if (rtb_Switch_f_idx_2 > 1.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_f_idx_2 < -1.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          }
        }

        /* Product: '<S98>/Multiply' incorporates:
         *  Trigonometry: '<S98>/Acos'
         */
        rtb_P_i_idx_0 *= acosf(rtb_Switch_f_idx_2);

        /* Saturate: '<S92>/Saturation' */
        if (rtb_P_i_idx_0 > 1.57079637F) {
          rtb_P_i_idx_0 = 1.57079637F;
        } else {
          if (rtb_P_i_idx_0 < -1.57079637F) {
            rtb_P_i_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S92>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  BusAssignment: '<S86>/Bus Assignment'
         *  Constant: '<S86>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S86>/Bus Assignment' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S86>/L1'
         *  Constant: '<S92>/Constant'
         *  DiscreteIntegrator: '<S87>/Integrator1'
         *  Gain: '<S88>/AY_P'
         *  MinMax: '<S92>/Max'
         *  MinMax: '<S92>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S92>/Divide'
         *  Product: '<S92>/Multiply1'
         *  Sqrt: '<S100>/Sqrt'
         *  Sum: '<S100>/Sum of Elements'
         *  Trigonometry: '<S92>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.psi_rate_cmd = arm_sin_f32(rtb_P_i_idx_0) *
          rtb_Switch_f_idx_1 / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + B),
          0.5F)) * FMS_PARAM.AY_P;

        /* Product: '<S90>/Multiply1' incorporates:
         *  Constant: '<S90>/const1'
         *  DiscreteIntegrator: '<S87>/Integrator'
         */
        rtb_Switch_f_idx_2 = FMS_DW.Integrator_DSTATE * 0.5F;

        /* Sum: '<S90>/Add' incorporates:
         *  Constant: '<S86>/vel'
         *  DiscreteIntegrator: '<S87>/Integrator1'
         *  Sum: '<S87>/Subtract'
         */
        rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE - FMS_PARAM.CRUISE_SPEED)
          + rtb_Switch_f_idx_2;

        /* Signum: '<S90>/Sign' */
        if (rtb_Switch_f_idx_1 < 0.0F) {
          rtb_Gain = -1.0F;
        } else if (rtb_Switch_f_idx_1 > 0.0F) {
          rtb_Gain = 1.0F;
        } else {
          rtb_Gain = rtb_Switch_f_idx_1;
        }

        /* End of Signum: '<S90>/Sign' */

        /* Sum: '<S90>/Add2' incorporates:
         *  Abs: '<S90>/Abs'
         *  Gain: '<S90>/Gain'
         *  Gain: '<S90>/Gain1'
         *  Product: '<S90>/Multiply2'
         *  Product: '<S90>/Multiply3'
         *  Sqrt: '<S90>/Sqrt'
         *  Sum: '<S90>/Add1'
         *  Sum: '<S90>/Subtract'
         */
        rtb_Gain = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d) *
                          FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Gain +
          rtb_Switch_f_idx_2;

        /* Sum: '<S90>/Add4' */
        rtb_Switch_f_idx_2 += rtb_Switch_f_idx_1 - rtb_Gain;

        /* Sum: '<S90>/Add3' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 + FMS_ConstB.d;

        /* Sum: '<S90>/Subtract1' */
        rtb_Switch_f_idx_1 -= FMS_ConstB.d;

        /* Signum: '<S90>/Sign1' */
        if (rtb_TmpSignalConversionAtMath_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_0 > 0.0F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
          }
        }

        /* End of Signum: '<S90>/Sign1' */

        /* Signum: '<S90>/Sign2' */
        if (rtb_Switch_f_idx_1 < 0.0F) {
          rtb_Switch_f_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Switch_f_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S90>/Sign2' */

        /* Sum: '<S90>/Add5' incorporates:
         *  Gain: '<S90>/Gain2'
         *  Product: '<S90>/Multiply4'
         *  Sum: '<S90>/Subtract2'
         */
        rtb_Gain += (rtb_TmpSignalConversionAtMath_0 - rtb_Switch_f_idx_1) *
          0.5F * rtb_Switch_f_idx_2;

        /* Update for DiscreteIntegrator: '<S87>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S87>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.01F * FMS_DW.Integrator_DSTATE;

        /* Sum: '<S90>/Subtract3' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Gain - FMS_ConstB.d;

        /* Sum: '<S90>/Add6' */
        B = rtb_Gain + FMS_ConstB.d;

        /* Signum: '<S90>/Sign5' */
        if (rtb_Gain < 0.0F) {
          rtb_Switch_f_idx_1 = -1.0F;
        } else if (rtb_Gain > 0.0F) {
          rtb_Switch_f_idx_1 = 1.0F;
        } else {
          rtb_Switch_f_idx_1 = rtb_Gain;
        }

        /* End of Signum: '<S90>/Sign5' */

        /* Signum: '<S90>/Sign3' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S90>/Sign3' */

        /* Signum: '<S90>/Sign4' */
        if (rtb_TmpSignalConversionAtMath_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_0 > 0.0F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
          }
        }

        /* End of Signum: '<S90>/Sign4' */

        /* Signum: '<S90>/Sign6' */
        if (rtb_Gain < 0.0F) {
          rtb_Switch_f_idx_2 = -1.0F;
        } else if (rtb_Gain > 0.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          rtb_Switch_f_idx_2 = rtb_Gain;
        }

        /* End of Signum: '<S90>/Sign6' */

        /* Update for DiscreteIntegrator: '<S87>/Integrator' incorporates:
         *  Constant: '<S90>/const'
         *  Gain: '<S90>/Gain3'
         *  Product: '<S90>/Divide'
         *  Product: '<S90>/Multiply5'
         *  Product: '<S90>/Multiply6'
         *  Sum: '<S90>/Subtract4'
         *  Sum: '<S90>/Subtract5'
         *  Sum: '<S90>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Gain / FMS_ConstB.d -
          rtb_Switch_f_idx_1) * FMS_ConstB.Gain4 * ((B -
          rtb_TmpSignalConversionAtMath_0) * 0.5F) - rtb_Switch_f_idx_2 *
          19.612F) * 0.01F;

        /* End of Outputs for SubSystem: '<S82>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Update for UnitDelay: '<S85>/Delay Input1' incorporates:
         *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S85>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S32>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S32>/Unknown' incorporates:
         *  ActionPort: '<S84>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S32>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S32>/Switch Case' */
      /* End of Outputs for SubSystem: '<S27>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S27>/Assist' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* SwitchCase: '<S31>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
          /* Disable for SwitchCase: '<S70>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S41>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
          break;

         case 2:
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S31>/Stabilize' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S31>/Switch Case' incorporates:
           *  Chart: '<S71>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);

          /* End of SystemReset for SubSystem: '<S31>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S31>/Stabilize' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S71>/Motion State' incorporates:
         *  Abs: '<S71>/Abs1'
         *  Abs: '<S71>/Abs2'
         *  Constant: '<S79>/Constant'
         *  Constant: '<S80>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Logic: '<S71>/Logical Operator'
         *  RelationalOperator: '<S79>/Compare'
         *  RelationalOperator: '<S80>/Compare'
         *  SignalConversion: '<S26>/Signal Copy2'
         */
        FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > 0.05F) || (fabsf
          (FMS_U.Pilot_Cmd.stick_throttle) <= 0.05F), &rtb_state_d,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S70>/Switch Case' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S26>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_n;
        FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
        switch (rtb_state_d) {
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
            /* InitializeConditions for IfAction SubSystem: '<S70>/Hold Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S70>/Switch Case' incorporates:
             *  Delay: '<S73>/Delay'
             */
            FMS_DW.icLoad_n = 1U;

            /* End of InitializeConditions for SubSystem: '<S70>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S70>/Hold Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Delay: '<S73>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S73>/Sum' incorporates:
           *  Delay: '<S73>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          rtb_Gain = FMS_DW.Delay_DSTATE - FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Abs: '<S76>/Abs' */
          rtb_Switch_f_idx_1 = fabsf(rtb_Gain);

          /* Switch: '<S76>/Switch' incorporates:
           *  Constant: '<S76>/Constant'
           *  Constant: '<S77>/Constant'
           *  Product: '<S76>/Multiply'
           *  RelationalOperator: '<S77>/Compare'
           *  Sum: '<S76>/Subtract'
           */
          if (rtb_Switch_f_idx_1 > 3.14159274F) {
            /* Signum: '<S76>/Sign' */
            if (rtb_Gain < 0.0F) {
              rtb_Gain = -1.0F;
            } else {
              if (rtb_Gain > 0.0F) {
                rtb_Gain = 1.0F;
              }
            }

            /* End of Signum: '<S76>/Sign' */
            rtb_Gain *= rtb_Switch_f_idx_1 - 6.28318548F;
          }

          /* End of Switch: '<S76>/Switch' */

          /* Gain: '<S73>/Gain2' */
          FMS_B.Merge_h = FMS_PARAM.YAW_P * rtb_Gain;

          /* Update for Delay: '<S73>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* End of Outputs for SubSystem: '<S70>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S70>/Brake Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_h);

          /* End of Outputs for SubSystem: '<S70>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S70>/Move Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_roll, &FMS_B.Merge_h);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S70>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S70>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  BusAssignment: '<S37>/Bus Assignment'
         *  Constant: '<S37>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S37>/Bus Assignment' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S67>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S26>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S67>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S67>/Gain' */
        rtb_Gain *= 1.05263162F;

        /* Saturate: '<S69>/Saturation' */
        if (rtb_Gain > 1.0F) {
          rtb_Gain = 1.0F;
        } else {
          if (rtb_Gain < 0.0F) {
            rtb_Gain = 0.0F;
          }
        }

        /* End of Saturate: '<S69>/Saturation' */

        /* BusAssignment: '<S37>/Bus Assignment' incorporates:
         *  Bias: '<S69>/Bias'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  DataTypeConversion: '<S69>/Data Type Conversion3'
         *  Gain: '<S69>/Gain1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)fmodf(floorf(1000.0F * rtb_Gain +
          1000.0F), 65536.0F);
        FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;

        /* End of Outputs for SubSystem: '<S31>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S31>/Position' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S31>/Switch Case' incorporates:
           *  Chart: '<S42>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S31>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S31>/Position' incorporates:
         *  ActionPort: '<S36>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S42>/Motion State' incorporates:
         *  Abs: '<S42>/Abs1'
         *  Abs: '<S42>/Abs2'
         *  Constant: '<S63>/Constant'
         *  Constant: '<S64>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Logic: '<S42>/Logical Operator'
         *  RelationalOperator: '<S63>/Compare'
         *  RelationalOperator: '<S64>/Compare'
         *  SignalConversion: '<S26>/Signal Copy2'
         */
        FMS_MotionState((fabsf(FMS_U.Pilot_Cmd.stick_roll) > 0.05F) || (fabsf
          (FMS_U.Pilot_Cmd.stick_throttle) <= 0.05F), &rtb_state_d,
                        &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S41>/Switch Case' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  Math: '<S55>/Square'
         *  Product: '<S61>/Divide'
         *  SignalConversion: '<S26>/Signal Copy2'
         *  Sum: '<S47>/Subtract'
         *  Switch: '<S46>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_d;
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
        switch (rtb_state_d) {
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
            /* InitializeConditions for IfAction SubSystem: '<S41>/Hold Control' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S41>/Switch Case' incorporates:
             *  Delay: '<S48>/start_vel'
             *  Delay: '<S48>/start_wp'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_o = 1U;

            /* End of InitializeConditions for SubSystem: '<S41>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S41>/Hold Control' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S56>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S56>/Math Function'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S56>/Math Function1' incorporates:
           *  Sum: '<S56>/Sum of Elements'
           *
           * About '<S56>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S56>/Math Function1' */

          /* Switch: '<S56>/Switch' incorporates:
           *  Constant: '<S56>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S56>/Product'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_fd[0] = FMS_U.INS_Out.vn;
            rtb_Switch_fd[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_fd[2] = rtb_P_i_idx_0;
          } else {
            rtb_Switch_fd[0] = 0.0F;
            rtb_Switch_fd[1] = 0.0F;
            rtb_Switch_fd[2] = 1.0F;
          }

          /* End of Switch: '<S56>/Switch' */

          /* Delay: '<S48>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           *  Trigonometry: '<S48>/Cos'
           *  Trigonometry: '<S48>/Cos1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = arm_cos_f32(FMS_U.INS_Out.psi);
            FMS_DW.start_vel_DSTATE[1] = arm_sin_f32(FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Sum: '<S61>/Sum of Elements' incorporates:
           *  Delay: '<S48>/start_vel'
           *  Math: '<S61>/Math Function'
           */
          rtb_Gain = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S61>/Math Function1' incorporates:
           *  Sum: '<S61>/Sum of Elements'
           *
           * About '<S61>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S61>/Math Function1' */

          /* Switch: '<S61>/Switch' incorporates:
           *  Constant: '<S61>/Constant'
           *  Delay: '<S48>/start_vel'
           *  Product: '<S61>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = FMS_DW.start_vel_DSTATE[0];
            rtb_Switch_f_idx_1 = FMS_DW.start_vel_DSTATE[1];
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S61>/Switch' */

          /* Product: '<S56>/Divide' */
          rtb_Divide_aj[0] = rtb_Switch_fd[0] / rtb_Switch_fd[2];
          rtb_Divide_aj[1] = rtb_Switch_fd[1] / rtb_Switch_fd[2];

          /* Sum: '<S59>/Sum of Elements' incorporates:
           *  Math: '<S59>/Math Function'
           *  SignalConversion: '<S59>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Gain = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
            rtb_Divide_aj[0];

          /* Math: '<S59>/Math Function1' incorporates:
           *  Sum: '<S59>/Sum of Elements'
           *
           * About '<S59>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S59>/Math Function1' */

          /* Switch: '<S59>/Switch' incorporates:
           *  Constant: '<S59>/Constant'
           *  Product: '<S59>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_fd[0] = rtb_Divide_aj[1];
            rtb_Switch_fd[1] = rtb_Divide_aj[0];
            rtb_Switch_fd[2] = rtb_P_i_idx_0;
          } else {
            rtb_Switch_fd[0] = 0.0F;
            rtb_Switch_fd[1] = 0.0F;
            rtb_Switch_fd[2] = 1.0F;
          }

          /* End of Switch: '<S59>/Switch' */

          /* Delay: '<S48>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          if (FMS_DW.icLoad_o != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S46>/SearchL1RefWP' incorporates:
           *  Delay: '<S48>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_DW.start_wp_DSTATE[0] -
            FMS_U.INS_Out.x_R;
          rtb_a_a = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S61>/Divide' */
          rtb_Gain = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S46>/SearchL1RefWP' */
          rtb_Switch_f_idx_0 = rtb_Gain * rtb_TmpSignalConversionAtMath_0;
          rtb_P_i_idx_0 = rtb_Gain;

          /* Product: '<S61>/Divide' */
          rtb_Gain = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S46>/SearchL1RefWP' incorporates:
           *  Constant: '<S44>/L1'
           *  Delay: '<S48>/start_wp'
           */
          rtb_Switch_f_idx_0 += rtb_Gain * rtb_a_a;
          B = 2.0F * rtb_Switch_f_idx_0;
          rtb_MathFunction_k[0] = 0.0F;
          rtb_MathFunction_k[1] = 0.0F;
          D = B * B - ((rtb_TmpSignalConversionAtMath_0 *
                        rtb_TmpSignalConversionAtMath_0 + rtb_a_a * rtb_a_a) -
                       FMS_PARAM.L1 * FMS_PARAM.L1) * 4.0F;
          rtb_Switch_f_idx_1 = -1.0F;
          if (D > 0.0F) {
            rtb_Switch_f_idx_1 = sqrtf(D);
            rtb_Switch_f_idx_1 = fmaxf((-B + rtb_Switch_f_idx_1) / 2.0F, (-B -
              rtb_Switch_f_idx_1) / 2.0F);
            rtb_MathFunction_k[0] = rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 * rtb_Gain +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (D == 0.0F) {
              rtb_Switch_f_idx_1 = -B / 2.0F;
              rtb_MathFunction_k[0] = rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 * rtb_Gain +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S49>/Compare' incorporates:
           *  Constant: '<S49>/Constant'
           *  MATLAB Function: '<S46>/SearchL1RefWP'
           */
          rtb_FixPtRelationalOperator = (rtb_Switch_f_idx_1 > 0.0F);

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S46>/OutRegionRefWP' incorporates:
           *  Delay: '<S48>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_P_i_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
            rtb_Gain;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_2 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > 1.29246971E-26F) {
            rtb_a_a = 1.0F;
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_0;
          } else {
            rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_0 /
              1.29246971E-26F;
            rtb_a_a = rtb_TmpSignalConversionAtMath_0 *
              rtb_TmpSignalConversionAtMath_0;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Switch_f_idx_1 * rtb_Gain +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > rtb_Switch_f_idx_2) {
            rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_2 /
              rtb_Switch_f_idx_0;
            rtb_a_a = rtb_a_a * rtb_TmpSignalConversionAtMath_0 *
              rtb_TmpSignalConversionAtMath_0 + 1.0F;
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_0;
          } else {
            rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_0 /
              rtb_Switch_f_idx_2;
            rtb_a_a += rtb_TmpSignalConversionAtMath_0 *
              rtb_TmpSignalConversionAtMath_0;
          }

          rtb_a_a = rtb_Switch_f_idx_2 * sqrtf(rtb_a_a);
          rtb_Switch_f_idx_2 = rtb_a_a * 0.577350259F + rtb_Switch_f_idx_1;

          /* Switch: '<S46>/Switch' incorporates:
           *  Delay: '<S48>/start_wp'
           *  MATLAB Function: '<S46>/OutRegionRefWP'
           */
          if (rtb_FixPtRelationalOperator) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[0];
          } else {
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2 * rtb_P_i_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S47>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S57>/Math Function' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 *
            rtb_Switch_f_idx_1;
          rtb_MathFunction_k[0] = rtb_Switch_f_idx_1;

          /* Switch: '<S46>/Switch' incorporates:
           *  Delay: '<S48>/start_wp'
           *  MATLAB Function: '<S46>/OutRegionRefWP'
           *  Sum: '<S47>/Subtract'
           */
          if (rtb_FixPtRelationalOperator) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[1];
          } else {
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2 * rtb_Gain +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S47>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S26>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S57>/Math Function' incorporates:
           *  Math: '<S55>/Square'
           */
          rtb_Gain = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

          /* Sum: '<S57>/Sum of Elements' incorporates:
           *  Math: '<S57>/Math Function'
           */
          rtb_P_i_idx_0 = rtb_Gain + rtb_TmpSignalConversionAtMath_0;

          /* Math: '<S57>/Math Function1' incorporates:
           *  Sum: '<S57>/Sum of Elements'
           *
           * About '<S57>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
          }

          /* End of Math: '<S57>/Math Function1' */

          /* Switch: '<S57>/Switch' incorporates:
           *  Constant: '<S57>/Constant'
           *  Product: '<S57>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_MathFunction_k[0];
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S57>/Switch' */

          /* Product: '<S57>/Divide' */
          rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S60>/Sum of Elements' incorporates:
           *  Math: '<S60>/Math Function'
           *  SignalConversion: '<S60>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0]
            * rtb_Divide_aj[0];

          /* Math: '<S60>/Math Function1' incorporates:
           *  Sum: '<S60>/Sum of Elements'
           *
           * About '<S60>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
          }

          /* End of Math: '<S60>/Math Function1' */

          /* Switch: '<S60>/Switch' incorporates:
           *  Constant: '<S60>/Constant'
           *  Product: '<S60>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_aj[1];
            rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S60>/Switch' */

          /* Product: '<S60>/Divide' */
          rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Product: '<S59>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_fd[0] / rtb_Switch_fd[2];
          rtb_MathFunction_k[0] *= rtb_MathFunction_k[0];

          /* Product: '<S60>/Divide' incorporates:
           *  Math: '<S55>/Square'
           */
          rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Product: '<S59>/Divide' */
          rtb_a_a = rtb_Switch_fd[1] / rtb_Switch_fd[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S54>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S54>/Square'
           *  SignalConversion: '<S26>/Signal Copy1'
           *  Sum: '<S54>/Sum of Elements'
           */
          rtb_P_i_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                                FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S52>/Square' */
          rtb_Switch_f_idx_1 = rtb_P_i_idx_0 * rtb_P_i_idx_0;

          /* Sum: '<S58>/Subtract' incorporates:
           *  Product: '<S58>/Multiply'
           *  Product: '<S58>/Multiply1'
           */
          rtb_P_i_idx_0 = rtb_Divide_aj[0] * rtb_a_a - rtb_Divide_aj[1] *
            rtb_TmpSignalConversionAtMath_0;

          /* Signum: '<S53>/Sign1' */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -1.0F;
          } else {
            if (rtb_P_i_idx_0 > 0.0F) {
              rtb_P_i_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S53>/Sign1' */

          /* Switch: '<S53>/Switch2' incorporates:
           *  Constant: '<S53>/Constant4'
           */
          if (rtb_P_i_idx_0 == 0.0F) {
            rtb_P_i_idx_0 = 1.0F;
          }

          /* End of Switch: '<S53>/Switch2' */

          /* DotProduct: '<S53>/Dot Product' */
          rtb_Switch_f_idx_2 = rtb_TmpSignalConversionAtMath_0 * rtb_Divide_aj[0]
            + rtb_a_a * rtb_Divide_aj[1];

          /* Trigonometry: '<S53>/Acos' incorporates:
           *  DotProduct: '<S53>/Dot Product'
           */
          if (rtb_Switch_f_idx_2 > 1.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_2 < -1.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            }
          }

          /* Product: '<S53>/Multiply' incorporates:
           *  Trigonometry: '<S53>/Acos'
           */
          rtb_P_i_idx_0 *= acosf(rtb_Switch_f_idx_2);

          /* Saturate: '<S52>/Saturation' */
          if (rtb_P_i_idx_0 > 1.57079637F) {
            rtb_P_i_idx_0 = 1.57079637F;
          } else {
            if (rtb_P_i_idx_0 < -1.57079637F) {
              rtb_P_i_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S52>/Saturation' */

          /* Gain: '<S44>/AY_P' incorporates:
           *  Constant: '<S44>/L1'
           *  Constant: '<S52>/Constant'
           *  Gain: '<S52>/Gain'
           *  MinMax: '<S52>/Max'
           *  MinMax: '<S52>/Min'
           *  Product: '<S52>/Divide'
           *  Product: '<S52>/Multiply1'
           *  Sqrt: '<S55>/Sqrt'
           *  Sum: '<S55>/Sum of Elements'
           *  Trigonometry: '<S52>/Sin'
           */
          FMS_B.Merge = 2.0F * rtb_Switch_f_idx_1 * arm_sin_f32(rtb_P_i_idx_0) /
            fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_MathFunction_k[0]),
                   0.5F)) * FMS_PARAM.AY_P;

          /* Update for Delay: '<S48>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S48>/start_wp' */
          FMS_DW.icLoad_o = 0U;

          /* End of Outputs for SubSystem: '<S41>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S41>/Brake Control' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S41>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S41>/Move Control' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_roll, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S41>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S41>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  BusAssignment: '<S36>/Bus Assignment'
         *  Constant: '<S36>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S66>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S26>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S66>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Gain: '<S40>/Gain'
         *  Gain: '<S66>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;
        FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge;

        /* End of Outputs for SubSystem: '<S31>/Position' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S31>/Unknown' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S31>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S31>/Switch Case' */
      /* End of Outputs for SubSystem: '<S27>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S27>/Manual' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S28>/Bus Assignment'
       *  BusAssignment: '<S33>/Bus Assignment'
       *  Constant: '<S33>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S33>/Bus Assignment' incorporates:
       *  BusAssignment: '<S28>/Bus Assignment'
       *  Constant: '<S33>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      /* DeadZone: '<S123>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S26>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
        rtb_Gain = 0.0F;
      } else {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
      }

      /* End of DeadZone: '<S123>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

      /* Gain: '<S123>/Gain' */
      rtb_Gain *= 1.05263162F;

      /* Saturate: '<S125>/Saturation' */
      if (rtb_Gain > 1.0F) {
        rtb_Gain = 1.0F;
      } else {
        if (rtb_Gain < 0.0F) {
          rtb_Gain = 0.0F;
        }
      }

      /* End of Saturate: '<S125>/Saturation' */

      /* BusAssignment: '<S33>/Bus Assignment' incorporates:
       *  Bias: '<S125>/Bias'
       *  BusAssignment: '<S28>/Bus Assignment'
       *  DataTypeConversion: '<S125>/Data Type Conversion3'
       *  Gain: '<S125>/Gain1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.throttle_cmd = (uint16_T)fmodf(floorf(1000.0F * rtb_Gain +
        1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      /* DeadZone: '<S124>/Dead Zone' incorporates:
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S26>/Signal Copy2'
       */
      if (FMS_U.Pilot_Cmd.stick_roll > 0.05F) {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - 0.05F;
      } else if (FMS_U.Pilot_Cmd.stick_roll >= -0.05F) {
        rtb_Gain = 0.0F;
      } else {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - -0.05F;
      }

      /* End of DeadZone: '<S124>/Dead Zone' */
      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

      /* BusAssignment: '<S33>/Bus Assignment' incorporates:
       *  BusAssignment: '<S28>/Bus Assignment'
       *  Gain: '<S124>/Gain'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.psi_rate_cmd = 1.05263162F * rtb_Gain;

      /* End of Outputs for SubSystem: '<S27>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S27>/Unknown' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S28>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S27>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S27>/Switch Case' */
    /* End of Outputs for SubSystem: '<S25>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S25>/Switch Case' */

  /* BusAssignment: '<S28>/Bus Assignment' incorporates:
   *  Constant: '<S28>/Constant'
   *  DataTypeConversion: '<S28>/Data Type Conversion'
   *  DiscreteIntegrator: '<S148>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S26>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S28>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

  /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S148>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for UnitDelay: '<S21>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S22>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += 0.01F;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator1_DSTATE += 0.01F;
  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S8>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_j + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_j = (uint32_T)rtb_Gain;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_j = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S9>/Delay' */
  FMS_DW.Delay_DSTATE_p = rtb_Switch_m;
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
  /* Start for SwitchCase: '<S25>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S25>/Arm' */
  /* Start for SwitchCase: '<S27>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S27>/SubMode' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S27>/SubMode' */

  /* Start for IfAction SubSystem: '<S27>/Auto' */
  /* Start for SwitchCase: '<S32>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S27>/Auto' */

  /* Start for IfAction SubSystem: '<S27>/Assist' */
  /* Start for SwitchCase: '<S31>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S31>/Stabilize' */
  /* Start for SwitchCase: '<S70>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* End of Start for SubSystem: '<S31>/Stabilize' */

  /* Start for IfAction SubSystem: '<S31>/Position' */
  /* Start for SwitchCase: '<S41>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* End of Start for SubSystem: '<S31>/Position' */
  /* End of Start for SubSystem: '<S27>/Assist' */
  /* End of Start for SubSystem: '<S25>/Arm' */
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
  FMS_DW.is_active_Lost_Return = 0U;
  FMS_DW.is_Lost_Return = FMS_IN_NO_ACTIVE_CHILD_n;
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
  /* SystemInitialize for IfAction SubSystem: '<S25>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S27>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S34>/Return' */
  /* InitializeConditions for Delay: '<S131>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Return' */
  /* End of SystemInitialize for SubSystem: '<S27>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S32>/Mission' */
  /* InitializeConditions for UnitDelay: '<S85>/Delay Input1'
   *
   * Block description for '<S85>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S82>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S82>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S32>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S27>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S31>/Stabilize' */
  /* SystemInitialize for Chart: '<S71>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S70>/Hold Control' */
  /* InitializeConditions for Delay: '<S73>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* End of SystemInitialize for SubSystem: '<S70>/Hold Control' */

  /* SystemInitialize for Merge: '<S70>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S31>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S31>/Position' */
  /* SystemInitialize for Chart: '<S42>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S41>/Hold Control' */
  /* InitializeConditions for Delay: '<S48>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S48>/start_wp' */
  FMS_DW.icLoad_o = 1U;

  /* End of SystemInitialize for SubSystem: '<S41>/Hold Control' */

  /* SystemInitialize for Merge: '<S41>/Merge' */
  FMS_B.Merge = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S31>/Position' */
  /* End of SystemInitialize for SubSystem: '<S27>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S25>/Arm' */
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
