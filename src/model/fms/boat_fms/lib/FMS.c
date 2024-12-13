/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2009
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec  5 10:29:29 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S37>/Motion State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)1U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
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
struct_Gbvu0nA7ZOwZNsa8mFLQ7C FMS_PARAM = {
  { 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1550.0F, 1550.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  10.0F,
  3.0F,
  5.0F,
  4.0F,
  0.7F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S24>/Constant6'
                                        *   '<S25>/Constant6'
                                        *   '<S32>/Gain'
                                        *   '<S109>/L1'
                                        *   '<S109>/vel'
                                        *   '<S35>/Gain'
                                        *   '<S69>/L1'
                                        *   '<S69>/vel'
                                        *   '<S111>/AY_P'
                                        *   '<S71>/AY_P'
                                        *   '<S39>/L1'
                                        *   '<S39>/AY_P'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  10U,

  { 66, 111, 97, 116, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S10>/Constant1'
                                        *   '<S128>/Constant'
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
 *    '<S113>/NearbyRefWP'
 *    '<S74>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_k, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S117>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S29>/Unknown'
 *    '<S27>/Unknown'
 *    '<S26>/Unknown'
 *    '<S22>/Unknown'
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

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S141>/Compare' incorporates:
   *  Abs: '<S130>/Abs'
   *  Constant: '<S141>/Constant'
   *  MinMax: '<S130>/Max'
   *  Sum: '<S130>/Sum'
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
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
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
    } else {
      FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
    }

    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
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
        if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
          FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
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
            FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD;
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
          } else {
            FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD;
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
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
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
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
                  /* Sum: '<S131>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S131>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S132>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S132>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S132>/Multiply1' incorporates:
                   *  Product: '<S132>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S132>/Divide' incorporates:
                   *  Constant: '<S132>/Constant'
                   *  Constant: '<S132>/R'
                   *  Sqrt: '<S132>/Sqrt'
                   *  Sum: '<S132>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S132>/Product3' incorporates:
                   *  Constant: '<S132>/Constant1'
                   *  Product: '<S132>/Multiply1'
                   *  Sum: '<S132>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S132>/Multiply2' incorporates:
                   *  Trigonometry: '<S132>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S136>/Abs' incorporates:
                   *  Abs: '<S139>/Abs1'
                   *  Switch: '<S136>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S136>/Switch1' incorporates:
                   *  Abs: '<S136>/Abs'
                   *  Bias: '<S136>/Bias2'
                   *  Bias: '<S136>/Bias3'
                   *  Constant: '<S133>/Constant'
                   *  Constant: '<S133>/Constant1'
                   *  Constant: '<S138>/Constant'
                   *  Gain: '<S136>/Gain1'
                   *  Product: '<S136>/Multiply'
                   *  RelationalOperator: '<S138>/Compare'
                   *  Switch: '<S133>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S139>/Switch1' incorporates:
                     *  Bias: '<S139>/Bias2'
                     *  Bias: '<S139>/Bias3'
                     *  Constant: '<S139>/Constant'
                     *  Constant: '<S140>/Constant'
                     *  Math: '<S139>/Math Function'
                     *  RelationalOperator: '<S140>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S139>/Switch1' */

                    /* Signum: '<S136>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S136>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S133>/Sum' incorporates:
                   *  Sum: '<S131>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S131>/Multiply' incorporates:
                   *  Gain: '<S131>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S135>/Switch1' incorporates:
                   *  Abs: '<S135>/Abs1'
                   *  Bias: '<S135>/Bias2'
                   *  Bias: '<S135>/Bias3'
                   *  Constant: '<S135>/Constant'
                   *  Constant: '<S137>/Constant'
                   *  Math: '<S135>/Math Function'
                   *  RelationalOperator: '<S137>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S135>/Switch1' */

                  /* Product: '<S131>/Multiply' incorporates:
                   *  Gain: '<S131>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S131>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S134>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S134>/Sum2' incorporates:
                   *  Product: '<S134>/Multiply1'
                   *  Product: '<S134>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S134>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S134>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S134>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S129>/Data Type Conversion' incorporates:
                   *  Gain: '<S131>/Gain'
                   *  Sum: '<S131>/Sum1'
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
        FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
        break;

       case FMS_IN_Manual:
        if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
          FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_mission = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_1))
      {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
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
            FMS_DW.durationLastReferenceTick_1_j > 150) {
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
  real32_T A;
  real32_T D;
  uint8_T rtb_Switch_m;
  int8_T rtPrevAction;
  real32_T rtb_Saturation;
  real32_T rtb_Divide_aj[2];
  real32_T rtb_MathFunction_k[2];
  real32_T rtb_AY_P;
  real32_T rtb_Switch_fd[3];
  real32_T rtb_Gain;
  boolean_T rtb_Compare_as;
  real32_T rtb_Gain_cl;
  MotionState rtb_state;
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
  uint32_T rtb_Compare_i_tmp;
  boolean_T guard1 = false;

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
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_ak) {
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
  FMS_DW.DelayInput1_DSTATE_ak = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Gain;
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
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0U;
    rtb_Switch_m = 1U;
  } else {
    rtb_Switch_m = FMS_DW.Delay_DSTATE_p;
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
    (rtb_Switch_m != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_Compare_as = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_Compare_as) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_Compare_as;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_DW.br;
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
  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  /* SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_fd[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_fd[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_fd[2] = FMS_B.Cmd_In.sp_waypoint[2];

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
      if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
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
     *  SignalConversion: '<S24>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S24>/Bus Assignment' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  Constant: '<S24>/Constant2'
     *  DataTypeConversion: '<S24>/Data Type Conversion2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S24>/Data Type Conversion2' incorporates:
       *  Constant: '<S24>/Constant6'
       */
      rtb_Gain = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
    }

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
     *  SignalConversion: '<S25>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S25>/Bus Assignment' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  Constant: '<S25>/Constant2'
     *  DataTypeConversion: '<S25>/Data Type Conversion3'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S25>/Data Type Conversion3' incorporates:
       *  Constant: '<S25>/Constant6'
       */
      rtb_Gain = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
    }

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
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for SwitchCase: '<S36>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
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
      /* Outputs for IfAction SubSystem: '<S22>/SubMode' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* SwitchCase: '<S29>/Switch Case' incorporates:
       *  Product: '<S126>/Divide'
       *  Sum: '<S114>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S29>/Return' incorporates:
           *  ActionPort: '<S109>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S29>/Switch Case' incorporates:
           *  Delay: '<S112>/Delay'
           */
          FMS_DW.icLoad_c = 1U;

          /* End of InitializeConditions for SubSystem: '<S29>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Return' incorporates:
         *  ActionPort: '<S109>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S123>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S123>/Math Function'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S121>/Sum of Elements'
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S123>/Math Function1' incorporates:
         *  Sum: '<S123>/Sum of Elements'
         *
         * About '<S123>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_Saturation = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_Saturation = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S123>/Math Function1' */

        /* Switch: '<S123>/Switch' incorporates:
         *  Constant: '<S123>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S123>/Product'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (rtb_Saturation > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_Saturation;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S123>/Switch' */

        /* Product: '<S123>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S126>/Sum of Elements' incorporates:
         *  Math: '<S126>/Math Function'
         *  SignalConversion: '<S126>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S126>/Math Function1' incorporates:
         *  Sum: '<S126>/Sum of Elements'
         *
         * About '<S126>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_Saturation = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_Saturation = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S126>/Math Function1' */

        /* Switch: '<S126>/Switch' incorporates:
         *  Constant: '<S126>/Constant'
         *  Product: '<S126>/Product'
         */
        if (rtb_Saturation > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_aj[1];
          rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
          rtb_Switch_f_idx_2 = rtb_Saturation;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S126>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S113>/NearbyRefWP' incorporates:
         *  Constant: '<S109>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fd[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_aj, &rtb_AY_P);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Delay: '<S112>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S113>/SearchL1RefWP' incorporates:
         *  Constant: '<S109>/L1'
         *  Delay: '<S112>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S113>/OutRegionRegWP'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        A = rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation = (rtb_P_i_idx_0 * (FMS_DW.Delay_DSTATE[0] -
          FMS_U.INS_Out.x_R) + rtb_TmpSignalConversionAtMath_0 *
                          (FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation * rtb_Saturation - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_DW.Delay_DSTATE[0] * FMS_DW.Delay_DSTATE[0]) +
          FMS_DW.Delay_DSTATE[1] * FMS_DW.Delay_DSTATE[1]) - (FMS_U.INS_Out.x_R *
          FMS_DW.Delay_DSTATE[0] + FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE[1]) *
          2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Gain_cl = -1.0F;
        rtb_P_f_idx_0 = 0.0F;
        rtb_P_f_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation + u1_tmp) / (2.0F * A);
          rtb_Saturation = (-rtb_Saturation - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Saturation >= 0.0F) &&
              (rtb_Saturation <= 1.0F)) {
            rtb_Gain_cl = fmaxf(D, rtb_Saturation);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Gain_cl = D;
            guard1 = true;
          } else {
            if ((rtb_Saturation >= 0.0F) && (rtb_Saturation <= 1.0F)) {
              rtb_Gain_cl = rtb_Saturation;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Gain_cl = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_P_f_idx_0 = rtb_P_i_idx_0 * rtb_Gain_cl + FMS_DW.Delay_DSTATE[0];
          rtb_P_f_idx_1 = rtb_TmpSignalConversionAtMath_0 * rtb_Gain_cl +
            FMS_DW.Delay_DSTATE[1];
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S113>/OutRegionRegWP' incorporates:
         *  Delay: '<S112>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) *
                          rtb_TmpSignalConversionAtMath_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE[0]) * rtb_P_i_idx_0) / (rtb_P_i_idx_0 *
          rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Compare_as = (rtb_Saturation <= 0.0F);
        u = (rtb_Saturation >= 1.0F);
        if (rtb_Compare_as) {
          rtb_P_i_idx_0 = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          rtb_P_i_idx_0 = rtb_Saturation * rtb_P_i_idx_0 + FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S113>/Switch1' incorporates:
         *  Constant: '<S116>/Constant'
         *  RelationalOperator: '<S116>/Compare'
         */
        if (rtb_AY_P <= 0.0F) {
          /* Switch: '<S113>/Switch' incorporates:
           *  Constant: '<S115>/Constant'
           *  MATLAB Function: '<S113>/SearchL1RefWP'
           *  RelationalOperator: '<S115>/Compare'
           */
          if (rtb_Gain_cl >= 0.0F) {
            rtb_Divide_aj[0] = rtb_P_f_idx_0;
            rtb_Divide_aj[1] = rtb_P_f_idx_1;
          } else {
            rtb_Divide_aj[0] = rtb_P_i_idx_0;

            /* MATLAB Function: '<S113>/OutRegionRegWP' incorporates:
             *  Delay: '<S112>/Delay'
             *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_as) {
              rtb_Divide_aj[1] = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_Divide_aj[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else {
              rtb_Divide_aj[1] = rtb_Saturation *
                rtb_TmpSignalConversionAtMath_0 + FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S113>/Switch' */
        }

        /* End of Switch: '<S113>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S114>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Gain_cl = rtb_Divide_aj[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S124>/Math Function' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Gain_cl * rtb_Gain_cl;
        rtb_Divide_aj[0] = rtb_Gain_cl;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S114>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Gain_cl = rtb_Divide_aj[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S124>/Math Function' incorporates:
         *  Math: '<S122>/Square'
         */
        rtb_P_i_idx_0 = rtb_Gain_cl * rtb_Gain_cl;

        /* Sum: '<S124>/Sum of Elements' incorporates:
         *  Math: '<S124>/Math Function'
         */
        rtb_Saturation = rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S124>/Math Function1' incorporates:
         *  Sum: '<S124>/Sum of Elements'
         *
         * About '<S124>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation < 0.0F) {
          rtb_Saturation = -sqrtf(fabsf(rtb_Saturation));
        } else {
          rtb_Saturation = sqrtf(rtb_Saturation);
        }

        /* End of Math: '<S124>/Math Function1' */

        /* Switch: '<S124>/Switch' incorporates:
         *  Constant: '<S124>/Constant'
         *  Product: '<S124>/Product'
         */
        if (rtb_Saturation > 0.0F) {
          rtb_Switch_fd[0] = rtb_Divide_aj[0];
          rtb_Switch_fd[1] = rtb_Gain_cl;
          rtb_Switch_fd[2] = rtb_Saturation;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S124>/Switch' */

        /* Product: '<S124>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_fd[0] / rtb_Switch_fd[2];
        rtb_P_f_idx_0 = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Sum: '<S127>/Sum of Elements' incorporates:
         *  Math: '<S127>/Math Function'
         *  SignalConversion: '<S127>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation = rtb_P_f_idx_0 * rtb_P_f_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S127>/Math Function1' incorporates:
         *  Sum: '<S127>/Sum of Elements'
         *
         * About '<S127>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation < 0.0F) {
          rtb_Saturation = -sqrtf(fabsf(rtb_Saturation));
        } else {
          rtb_Saturation = sqrtf(rtb_Saturation);
        }

        /* End of Math: '<S127>/Math Function1' */

        /* Switch: '<S127>/Switch' incorporates:
         *  Constant: '<S127>/Constant'
         *  Product: '<S127>/Product'
         */
        if (rtb_Saturation > 0.0F) {
          rtb_Switch_fd[0] = rtb_P_f_idx_0;
          rtb_Switch_fd[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_fd[2] = rtb_Saturation;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S127>/Switch' */

        /* Product: '<S127>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_fd[0] / rtb_Switch_fd[2];

        /* Math: '<S122>/Square' */
        rtb_MathFunction_k[0] = rtb_Divide_aj[0] * rtb_Divide_aj[0];
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S127>/Divide' incorporates:
         *  Product: '<S126>/Divide'
         */
        rtb_P_f_idx_0 = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Product: '<S126>/Divide' */
        rtb_Gain_cl = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sqrt: '<S121>/Sqrt' */
        rtb_Saturation = sqrtf(rtb_Gain);

        /* Gain: '<S114>/Gain' incorporates:
         *  Math: '<S114>/Square'
         */
        rtb_Gain = rtb_Saturation * rtb_Saturation * 2.0F;

        /* Sum: '<S125>/Subtract' incorporates:
         *  Product: '<S125>/Multiply'
         *  Product: '<S125>/Multiply1'
         */
        rtb_Saturation = rtb_TmpSignalConversionAtMath_0 * rtb_Gain_cl -
          rtb_P_f_idx_0 * rtb_Divide_aj[0];

        /* Signum: '<S120>/Sign1' */
        if (rtb_Saturation < 0.0F) {
          rtb_Saturation = -1.0F;
        } else {
          if (rtb_Saturation > 0.0F) {
            rtb_Saturation = 1.0F;
          }
        }

        /* End of Signum: '<S120>/Sign1' */

        /* Switch: '<S120>/Switch2' incorporates:
         *  Constant: '<S120>/Constant4'
         */
        if (rtb_Saturation == 0.0F) {
          rtb_Saturation = 1.0F;
        }

        /* End of Switch: '<S120>/Switch2' */

        /* DotProduct: '<S120>/Dot Product' */
        rtb_Gain_cl = rtb_Divide_aj[0] * rtb_TmpSignalConversionAtMath_0 +
          rtb_Gain_cl * rtb_P_f_idx_0;

        /* Trigonometry: '<S120>/Acos' incorporates:
         *  DotProduct: '<S120>/Dot Product'
         */
        if (rtb_Gain_cl > 1.0F) {
          rtb_Gain_cl = 1.0F;
        } else {
          if (rtb_Gain_cl < -1.0F) {
            rtb_Gain_cl = -1.0F;
          }
        }

        /* Product: '<S120>/Multiply' incorporates:
         *  Trigonometry: '<S120>/Acos'
         */
        rtb_Saturation *= acosf(rtb_Gain_cl);

        /* Saturate: '<S114>/Saturation' */
        if (rtb_Saturation > 1.57079637F) {
          rtb_Saturation = 1.57079637F;
        } else {
          if (rtb_Saturation < -1.57079637F) {
            rtb_Saturation = -1.57079637F;
          }
        }

        /* End of Saturate: '<S114>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S109>/Bus Assignment1'
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S109>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S109>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S109>/L1'
         *  Constant: '<S109>/vel'
         *  Constant: '<S114>/Constant'
         *  Gain: '<S111>/AY_P'
         *  MinMax: '<S114>/Max'
         *  MinMax: '<S114>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S114>/Divide'
         *  Product: '<S114>/Multiply1'
         *  Sqrt: '<S122>/Sqrt'
         *  Sum: '<S122>/Sum of Elements'
         *  Trigonometry: '<S114>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.psi_rate_cmd = arm_sin_f32(rtb_Saturation) * rtb_Gain /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_P_i_idx_0 + rtb_MathFunction_k[0]),
                 0.5F)) * FMS_PARAM.AY_P;

        /* Update for Delay: '<S112>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* End of Outputs for SubSystem: '<S29>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S29>/Hold' incorporates:
         *  ActionPort: '<S108>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S108>/Bus Assignment'
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S108>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S108>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S108>/Constant3'
         *  Constant: '<S108>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.r_cmd = 0.0F;

        /* End of Outputs for SubSystem: '<S29>/Hold' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
         *  ActionPort: '<S110>/Action Port'
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
      /* SwitchCase: '<S27>/Switch Case' */
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
         *  ActionPort: '<S66>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* S-Function (sfix_bitop): '<S98>/u_cmd valid' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  S-Function (sfix_bitop): '<S89>/u_cmd'
         *  SignalConversion: '<S21>/Signal Copy'
         */
        rtb_Compare_i_tmp = FMS_U.Auto_Cmd.cmd_mask & 8192U;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* RelationalOperator: '<S101>/Compare' incorporates:
         *  Constant: '<S101>/Constant'
         *  S-Function (sfix_bitop): '<S98>/u_cmd valid'
         */
        rtb_Compare_as = (rtb_Compare_i_tmp > 0U);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S90>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S100>/Multiply3'
         *  Product: '<S90>/Multiply'
         *  Product: '<S99>/Multiply'
         *  SignalConversion: '<S21>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S103>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S103>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S103>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* Trigonometry: '<S103>/Trigonometric Function3' incorporates:
           *  Gain: '<S102>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S103>/Trigonometric Function1'
           */
          rtb_Gain = arm_cos_f32(-FMS_U.INS_Out.psi);
          rtb_VectorConcatenate[4] = rtb_Gain;

          /* Trigonometry: '<S103>/Trigonometric Function2' incorporates:
           *  Gain: '<S102>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S103>/Trigonometric Function'
           */
          rtb_Switch_f_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S103>/Gain' incorporates:
           *  Trigonometry: '<S103>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -rtb_Switch_f_idx_1;

          /* SignalConversion: '<S103>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S103>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Trigonometry: '<S103>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Switch_f_idx_1;

          /* Trigonometry: '<S103>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Gain;

          /* Product: '<S90>/Multiply' */
          rtb_Gain = rtb_Compare_as ? FMS_U.Auto_Cmd.u_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_Switch_fd[i] = rtb_VectorConcatenate[i] * rtb_Gain;
          }
          break;

         case 1:
          /* SignalConversion: '<S105>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_o[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_o[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* SignalConversion: '<S105>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S105>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* Gain: '<S104>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S100>/Subtract'
           */
          rtb_Switch_f_idx_1 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S105>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S105>/Trigonometric Function1'
           */
          rtb_Gain = arm_cos_f32(rtb_Switch_f_idx_1);
          rtb_VectorConcatenate[4] = rtb_Gain;

          /* Trigonometry: '<S105>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S105>/Trigonometric Function'
           */
          rtb_Switch_f_idx_1 = arm_sin_f32(rtb_Switch_f_idx_1);

          /* Gain: '<S105>/Gain' incorporates:
           *  Trigonometry: '<S105>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -rtb_Switch_f_idx_1;

          /* SignalConversion: '<S105>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S105>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Trigonometry: '<S105>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_Switch_f_idx_1;

          /* Trigonometry: '<S105>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Gain;

          /* Product: '<S90>/Multiply' */
          rtb_Gain = rtb_Compare_as ? FMS_U.Auto_Cmd.u_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_Switch_fd[i] = rtb_VectorConcatenate[i] * rtb_Gain;
          }
          break;

         default:
          rtb_Switch_fd[0] = rtb_Compare_as ? FMS_U.Auto_Cmd.u_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S90>/Index Vector' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S66>/Bus Assignment'
         *  Constant: '<S66>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S66>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S91>/Constant'
         *  Constant: '<S92>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S93>/bit_shift'
         *  MATLAB Function: '<S94>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S91>/Compare'
         *  RelationalOperator: '<S92>/Compare'
         *  S-Function (sfix_bitop): '<S89>/psi_rate_cmd'
         *  SignalConversion: '<S21>/Signal Copy'
         *  Sum: '<S89>/Add'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_c;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_fd[0];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.psi_rate_cmd = FMS_U.Auto_Cmd.psi_rate_cmd;

        /* Outputs for Atomic SubSystem: '<S89>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S89>/u_cmd_valid' */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask
          & 64U) > 0U) << 5) + ((rtb_Compare_i_tmp > 0U) << 6));

        /* End of Outputs for SubSystem: '<S89>/u_cmd_valid' */
        /* End of Outputs for SubSystem: '<S89>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S27>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S27>/Mission' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S27>/Switch Case' incorporates:
           *  UnitDelay: '<S68>/Delay Input1'
           *
           * Block description for '<S68>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S27>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S27>/Mission' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S65>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S27>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S70>/Integrator'
           *  DiscreteIntegrator: '<S70>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;

          /* End of SystemReset for SubSystem: '<S65>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S27>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S27>/Mission' incorporates:
         *  ActionPort: '<S65>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* RelationalOperator: '<S68>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S68>/Delay Input1'
         *
         * Block description for '<S68>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_as = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S65>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S69>/Reset'
         */
        if (rtb_Compare_as && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
                               POS_ZCSIG)) {
          /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator1' */
          FMS_DW.Integrator1_DSTATE = 0.0F;

          /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator' */
          FMS_DW.Integrator_DSTATE = 0.0F;
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Compare_as;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S84>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S84>/Math Function'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S84>/Math Function1' incorporates:
         *  Sum: '<S84>/Sum of Elements'
         *
         * About '<S84>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S84>/Math Function1' */

        /* Switch: '<S84>/Switch' incorporates:
         *  Constant: '<S84>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S84>/Product'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S84>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S74>/NearbyRefWP' incorporates:
         *  Constant: '<S69>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fd[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_MathFunction_k, &rtb_Gain);

        /* MATLAB Function: '<S74>/SearchL1RefWP' incorporates:
         *  Constant: '<S69>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S74>/OutRegionRegWP'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        A = rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation = (rtb_P_i_idx_0 * (FMS_B.Cmd_In.cur_waypoint[0] -
          FMS_U.INS_Out.x_R) + rtb_TmpSignalConversionAtMath_0 *
                          (FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R)) *
          2.0F;
        D = rtb_Saturation * rtb_Saturation - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_B.Cmd_In.cur_waypoint[0] * FMS_B.Cmd_In.cur_waypoint[0]) +
          FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint[1]) -
          (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0] + FMS_U.INS_Out.y_R *
           FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) *
          (4.0F * A);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Gain_cl = -1.0F;
        rtb_Divide_aj[0] = 0.0F;
        rtb_Divide_aj[1] = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation + u1_tmp) / (2.0F * A);
          rtb_Saturation = (-rtb_Saturation - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Saturation >= 0.0F) &&
              (rtb_Saturation <= 1.0F)) {
            rtb_Gain_cl = fmaxf(D, rtb_Saturation);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Gain_cl = D;
            guard1 = true;
          } else {
            if ((rtb_Saturation >= 0.0F) && (rtb_Saturation <= 1.0F)) {
              rtb_Gain_cl = rtb_Saturation;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Gain_cl = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Divide_aj[0] = rtb_P_i_idx_0 * rtb_Gain_cl +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_aj[1] = rtb_TmpSignalConversionAtMath_0 * rtb_Gain_cl +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S74>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                          rtb_TmpSignalConversionAtMath_0 + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_P_i_idx_0) / (rtb_P_i_idx_0 *
          rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Compare_as = (rtb_Saturation <= 0.0F);
        u = (rtb_Saturation >= 1.0F);
        if (rtb_Compare_as) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Saturation * rtb_P_i_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Switch: '<S74>/Switch1' incorporates:
         *  Constant: '<S77>/Constant'
         *  RelationalOperator: '<S77>/Compare'
         */
        if (rtb_Gain <= 0.0F) {
          /* Switch: '<S74>/Switch' incorporates:
           *  Constant: '<S76>/Constant'
           *  MATLAB Function: '<S74>/SearchL1RefWP'
           *  RelationalOperator: '<S76>/Compare'
           */
          if (rtb_Gain_cl >= 0.0F) {
            rtb_MathFunction_k[0] = rtb_Divide_aj[0];
            rtb_MathFunction_k[1] = rtb_Divide_aj[1];
          } else {
            rtb_MathFunction_k[0] = rtb_P_f_idx_0;

            /* MATLAB Function: '<S74>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_as) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_MathFunction_k[1] = rtb_Saturation *
                rtb_TmpSignalConversionAtMath_0 + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            }
          }

          /* End of Switch: '<S74>/Switch' */
        }

        /* End of Switch: '<S74>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S75>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_k[0] -
          FMS_U.INS_Out.x_R;
        rtb_P_f_idx_0 = rtb_MathFunction_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S85>/Math Function' incorporates:
         *  Math: '<S83>/Square'
         */
        rtb_Gain_cl = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;
        rtb_Gain = rtb_P_f_idx_0 * rtb_P_f_idx_0;

        /* Sum: '<S85>/Sum of Elements' incorporates:
         *  Math: '<S85>/Math Function'
         */
        rtb_P_i_idx_0 = rtb_Gain_cl + rtb_Gain;

        /* Math: '<S85>/Math Function1' incorporates:
         *  Sum: '<S85>/Sum of Elements'
         *
         * About '<S85>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S85>/Math Function1' */

        /* Switch: '<S85>/Switch' incorporates:
         *  Constant: '<S85>/Constant'
         *  Product: '<S85>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_fd[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_fd[1] = rtb_P_f_idx_0;
          rtb_Switch_fd[2] = rtb_P_i_idx_0;
        } else {
          rtb_Switch_fd[0] = 0.0F;
          rtb_Switch_fd[1] = 0.0F;
          rtb_Switch_fd[2] = 1.0F;
        }

        /* End of Switch: '<S85>/Switch' */

        /* Product: '<S84>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S87>/Sum of Elements' incorporates:
         *  Math: '<S87>/Math Function'
         *  SignalConversion: '<S87>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S87>/Math Function1' incorporates:
         *  Sum: '<S87>/Sum of Elements'
         *
         * About '<S87>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S87>/Math Function1' */

        /* Switch: '<S87>/Switch' incorporates:
         *  Constant: '<S87>/Constant'
         *  Product: '<S87>/Product'
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

        /* End of Switch: '<S87>/Switch' */

        /* Product: '<S85>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_fd[0] / rtb_Switch_fd[2];
        rtb_Divide_aj[1] = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Sum: '<S88>/Sum of Elements' incorporates:
         *  Math: '<S88>/Math Function'
         *  SignalConversion: '<S88>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S88>/Math Function1' incorporates:
         *  Sum: '<S88>/Sum of Elements'
         *
         * About '<S88>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S88>/Math Function1' */

        /* Switch: '<S88>/Switch' incorporates:
         *  Constant: '<S88>/Constant'
         *  Product: '<S88>/Product'
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

        /* End of Switch: '<S88>/Switch' */

        /* Product: '<S88>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_fd[0] / rtb_Switch_fd[2];

        /* Product: '<S87>/Divide' */
        rtb_MathFunction_k[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S88>/Divide' */
        rtb_Divide_aj[1] = rtb_Switch_fd[1] / rtb_Switch_fd[2];

        /* Product: '<S87>/Divide' */
        rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S82>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S82>/Square'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S82>/Sum of Elements'
         */
        rtb_P_i_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S75>/Gain' incorporates:
         *  Math: '<S75>/Square'
         */
        rtb_Switch_f_idx_1 = rtb_P_i_idx_0 * rtb_P_i_idx_0 * 2.0F;

        /* Sum: '<S86>/Subtract' incorporates:
         *  Product: '<S86>/Multiply'
         *  Product: '<S86>/Multiply1'
         */
        rtb_P_i_idx_0 = rtb_Divide_aj[0] * rtb_MathFunction_k[1] -
          rtb_Divide_aj[1] * rtb_MathFunction_k[0];

        /* Signum: '<S81>/Sign1' */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -1.0F;
        } else {
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_P_i_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S81>/Sign1' */

        /* Switch: '<S81>/Switch2' incorporates:
         *  Constant: '<S81>/Constant4'
         */
        if (rtb_P_i_idx_0 == 0.0F) {
          rtb_P_i_idx_0 = 1.0F;
        }

        /* End of Switch: '<S81>/Switch2' */

        /* DotProduct: '<S81>/Dot Product' */
        rtb_Switch_f_idx_2 = rtb_MathFunction_k[0] * rtb_Divide_aj[0] +
          rtb_MathFunction_k[1] * rtb_Divide_aj[1];

        /* Trigonometry: '<S81>/Acos' incorporates:
         *  DotProduct: '<S81>/Dot Product'
         */
        if (rtb_Switch_f_idx_2 > 1.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_f_idx_2 < -1.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          }
        }

        /* Product: '<S81>/Multiply' incorporates:
         *  Trigonometry: '<S81>/Acos'
         */
        rtb_P_i_idx_0 *= acosf(rtb_Switch_f_idx_2);

        /* Saturate: '<S75>/Saturation' */
        if (rtb_P_i_idx_0 > 1.57079637F) {
          rtb_P_i_idx_0 = 1.57079637F;
        } else {
          if (rtb_P_i_idx_0 < -1.57079637F) {
            rtb_P_i_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S75>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S69>/Bus Assignment'
         *  Constant: '<S69>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S69>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S69>/L1'
         *  Constant: '<S75>/Constant'
         *  DiscreteIntegrator: '<S70>/Integrator1'
         *  Gain: '<S71>/AY_P'
         *  MinMax: '<S75>/Max'
         *  MinMax: '<S75>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S75>/Divide'
         *  Product: '<S75>/Multiply1'
         *  Sqrt: '<S83>/Sqrt'
         *  Sum: '<S83>/Sum of Elements'
         *  Trigonometry: '<S75>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.psi_rate_cmd = arm_sin_f32(rtb_P_i_idx_0) *
          rtb_Switch_f_idx_1 / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain +
          rtb_Gain_cl), 0.5F)) * FMS_PARAM.AY_P;

        /* Product: '<S73>/Multiply1' incorporates:
         *  Constant: '<S73>/const1'
         *  DiscreteIntegrator: '<S70>/Integrator'
         */
        rtb_Switch_f_idx_2 = FMS_DW.Integrator_DSTATE * 0.5F;

        /* Sum: '<S73>/Add' incorporates:
         *  Constant: '<S69>/vel'
         *  DiscreteIntegrator: '<S70>/Integrator1'
         *  Sum: '<S70>/Subtract'
         */
        rtb_Switch_f_idx_1 = (FMS_DW.Integrator1_DSTATE - FMS_PARAM.CRUISE_SPEED)
          + rtb_Switch_f_idx_2;

        /* Signum: '<S73>/Sign' */
        if (rtb_Switch_f_idx_1 < 0.0F) {
          rtb_Gain = -1.0F;
        } else if (rtb_Switch_f_idx_1 > 0.0F) {
          rtb_Gain = 1.0F;
        } else {
          rtb_Gain = rtb_Switch_f_idx_1;
        }

        /* End of Signum: '<S73>/Sign' */

        /* Sum: '<S73>/Add2' incorporates:
         *  Abs: '<S73>/Abs'
         *  Gain: '<S73>/Gain'
         *  Gain: '<S73>/Gain1'
         *  Product: '<S73>/Multiply2'
         *  Product: '<S73>/Multiply3'
         *  Sqrt: '<S73>/Sqrt'
         *  Sum: '<S73>/Add1'
         *  Sum: '<S73>/Subtract'
         */
        rtb_Gain = (sqrtf((8.0F * fabsf(rtb_Switch_f_idx_1) + FMS_ConstB.d) *
                          FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Gain +
          rtb_Switch_f_idx_2;

        /* Sum: '<S73>/Add4' */
        rtb_Switch_f_idx_2 += rtb_Switch_f_idx_1 - rtb_Gain;

        /* Sum: '<S73>/Add3' */
        rtb_Gain_cl = rtb_Switch_f_idx_1 + FMS_ConstB.d;

        /* Sum: '<S73>/Subtract1' */
        rtb_Switch_f_idx_1 -= FMS_ConstB.d;

        /* Signum: '<S73>/Sign1' */
        if (rtb_Gain_cl < 0.0F) {
          rtb_Gain_cl = -1.0F;
        } else {
          if (rtb_Gain_cl > 0.0F) {
            rtb_Gain_cl = 1.0F;
          }
        }

        /* End of Signum: '<S73>/Sign1' */

        /* Signum: '<S73>/Sign2' */
        if (rtb_Switch_f_idx_1 < 0.0F) {
          rtb_Switch_f_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_f_idx_1 > 0.0F) {
            rtb_Switch_f_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S73>/Sign2' */

        /* Sum: '<S73>/Add5' incorporates:
         *  Gain: '<S73>/Gain2'
         *  Product: '<S73>/Multiply4'
         *  Sum: '<S73>/Subtract2'
         */
        rtb_Gain += (rtb_Gain_cl - rtb_Switch_f_idx_1) * 0.5F *
          rtb_Switch_f_idx_2;

        /* Update for DiscreteIntegrator: '<S70>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S70>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.01F * FMS_DW.Integrator_DSTATE;

        /* Sum: '<S73>/Subtract3' */
        rtb_Gain_cl = rtb_Gain - FMS_ConstB.d;

        /* Sum: '<S73>/Add6' */
        rtb_Saturation = rtb_Gain + FMS_ConstB.d;

        /* Signum: '<S73>/Sign5' */
        if (rtb_Gain < 0.0F) {
          rtb_Switch_f_idx_1 = -1.0F;
        } else if (rtb_Gain > 0.0F) {
          rtb_Switch_f_idx_1 = 1.0F;
        } else {
          rtb_Switch_f_idx_1 = rtb_Gain;
        }

        /* End of Signum: '<S73>/Sign5' */

        /* Signum: '<S73>/Sign3' */
        if (rtb_Saturation < 0.0F) {
          rtb_Saturation = -1.0F;
        } else {
          if (rtb_Saturation > 0.0F) {
            rtb_Saturation = 1.0F;
          }
        }

        /* End of Signum: '<S73>/Sign3' */

        /* Signum: '<S73>/Sign4' */
        if (rtb_Gain_cl < 0.0F) {
          rtb_Gain_cl = -1.0F;
        } else {
          if (rtb_Gain_cl > 0.0F) {
            rtb_Gain_cl = 1.0F;
          }
        }

        /* End of Signum: '<S73>/Sign4' */

        /* Signum: '<S73>/Sign6' */
        if (rtb_Gain < 0.0F) {
          rtb_Switch_f_idx_2 = -1.0F;
        } else if (rtb_Gain > 0.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          rtb_Switch_f_idx_2 = rtb_Gain;
        }

        /* End of Signum: '<S73>/Sign6' */

        /* Update for DiscreteIntegrator: '<S70>/Integrator' incorporates:
         *  Constant: '<S73>/const'
         *  Gain: '<S73>/Gain3'
         *  Product: '<S73>/Divide'
         *  Product: '<S73>/Multiply5'
         *  Product: '<S73>/Multiply6'
         *  Sum: '<S73>/Subtract4'
         *  Sum: '<S73>/Subtract5'
         *  Sum: '<S73>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Gain / FMS_ConstB.d -
          rtb_Switch_f_idx_1) * FMS_ConstB.Gain4 * ((rtb_Saturation -
          rtb_Gain_cl) * 0.5F) - rtb_Switch_f_idx_2 * 19.612F) * 0.01F;

        /* End of Outputs for SubSystem: '<S65>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S68>/Delay Input1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S68>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S27>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S27>/Unknown' incorporates:
         *  ActionPort: '<S67>/Action Port'
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
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) && (rtPrevAction
           == 1)) {
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S26>/Stabilize' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S32>/Bus Assignment'
         *  Constant: '<S32>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S63>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S63>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S32>/Gain'
         *  Gain: '<S63>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S64>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - -0.05F;
        }

        /* End of DeadZone: '<S64>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S64>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.05263162F * rtb_Gain;

        /* End of Outputs for SubSystem: '<S26>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S26>/Position' incorporates:
           *  ActionPort: '<S31>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S26>/Switch Case' incorporates:
           *  Chart: '<S37>/Motion State'
           */
          FMS_DW.temporalCounter_i1_o = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD;

          /* End of SystemReset for SubSystem: '<S26>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S26>/Position' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S62>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S62>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S35>/Gain' incorporates:
         *  Gain: '<S62>/Gain'
         */
        rtb_Gain_cl = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* RelationalOperator: '<S60>/Compare' incorporates:
         *  Abs: '<S37>/Abs1'
         *  Constant: '<S60>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        rtb_Compare_as = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > 0.05F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S37>/Motion State' */
        if (FMS_DW.temporalCounter_i1_o < 255U) {
          FMS_DW.temporalCounter_i1_o++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move;
          rtb_state = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake:
            rtb_state = MotionState_Brake;
            if (rtb_Compare_as) {
              FMS_DW.is_c16_FMS = FMS_IN_Move;
              rtb_state = MotionState_Move;
            } else {
              if (FMS_DW.temporalCounter_i1_o >= 150U) {
                FMS_DW.is_c16_FMS = FMS_IN_Hold;
                rtb_state = MotionState_Hold;
              }
            }
            break;

           case FMS_IN_Hold:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_as) {
              FMS_DW.is_c16_FMS = FMS_IN_Move;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_as) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake;
              FMS_DW.temporalCounter_i1_o = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S37>/Motion State' */

        /* SwitchCase: '<S36>/Switch Case' incorporates:
         *  Math: '<S50>/Square'
         *  Product: '<S57>/Divide'
         *  Sum: '<S42>/Subtract'
         *  Switch: '<S41>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_d;
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
        switch (rtb_state) {
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
            /* InitializeConditions for IfAction SubSystem: '<S36>/Hold Control' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
             *  Delay: '<S43>/start_vel'
             *  Delay: '<S43>/start_wp'
             *  UnitDelay: '<S56>/Delay Input1'
             *
             * Block description for '<S56>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE = 0.0F;
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_o = 1U;

            /* End of InitializeConditions for SubSystem: '<S36>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S36>/Hold Control' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S51>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S51>/Math Function'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S51>/Math Function1' incorporates:
           *  Sum: '<S51>/Sum of Elements'
           *
           * About '<S51>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_Gain = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_Gain = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S51>/Math Function1' */

          /* Switch: '<S51>/Switch' incorporates:
           *  Constant: '<S51>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S51>/Product'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          if (rtb_Gain > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            rtb_Switch_fd[0] = FMS_U.INS_Out.vn;
            rtb_Switch_fd[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            rtb_Switch_fd[2] = rtb_Gain;
          } else {
            rtb_Switch_fd[0] = 0.0F;
            rtb_Switch_fd[1] = 0.0F;
            rtb_Switch_fd[2] = 1.0F;
          }

          /* End of Switch: '<S51>/Switch' */

          /* Switch: '<S58>/Switch' incorporates:
           *  Constant: '<S58>/Constant'
           *  Constant: '<S58>/Constant1'
           */
          if (rtb_Gain_cl >= 0.0F) {
            i = 1;
          } else {
            i = -1;
          }

          /* End of Switch: '<S58>/Switch' */

          /* RelationalOperator: '<S56>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S56>/Delay Input1'
           *
           * Block description for '<S56>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_as = (i != FMS_DW.DelayInput1_DSTATE);

          /* Delay: '<S43>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S43>/Multiply'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S43>/Cos'
           *  Trigonometry: '<S43>/Cos1'
           */
          if (rtb_Compare_as && (FMS_PrevZCX.start_vel_Reset_ZCE != POS_ZCSIG))
          {
            FMS_DW.icLoad = 1U;
          }

          FMS_PrevZCX.start_vel_Reset_ZCE = rtb_Compare_as;
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = arm_cos_f32(FMS_U.INS_Out.psi) *
              (real32_T)i;
            FMS_DW.start_vel_DSTATE[1] = arm_sin_f32(FMS_U.INS_Out.psi) *
              (real32_T)i;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Sum: '<S57>/Sum of Elements' incorporates:
           *  Delay: '<S43>/start_vel'
           *  Math: '<S57>/Math Function'
           */
          rtb_Gain = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
            FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S57>/Math Function1' incorporates:
           *  Sum: '<S57>/Sum of Elements'
           *
           * About '<S57>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S57>/Math Function1' */

          /* Switch: '<S57>/Switch' incorporates:
           *  Constant: '<S57>/Constant'
           *  Delay: '<S43>/start_vel'
           *  Product: '<S57>/Product'
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

          /* End of Switch: '<S57>/Switch' */

          /* Product: '<S51>/Divide' */
          rtb_Divide_aj[0] = rtb_Switch_fd[0] / rtb_Switch_fd[2];
          rtb_Divide_aj[1] = rtb_Switch_fd[1] / rtb_Switch_fd[2];

          /* Sum: '<S54>/Sum of Elements' incorporates:
           *  Math: '<S54>/Math Function'
           *  SignalConversion: '<S54>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Gain = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
            rtb_Divide_aj[0];

          /* Math: '<S54>/Math Function1' incorporates:
           *  Sum: '<S54>/Sum of Elements'
           *
           * About '<S54>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S54>/Math Function1' */

          /* Switch: '<S54>/Switch' incorporates:
           *  Constant: '<S54>/Constant'
           *  Product: '<S54>/Product'
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

          /* End of Switch: '<S54>/Switch' */

          /* Delay: '<S43>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          if (rtb_Compare_as && (FMS_PrevZCX.start_wp_Reset_ZCE != POS_ZCSIG)) {
            FMS_DW.icLoad_o = 1U;
          }

          FMS_PrevZCX.start_wp_Reset_ZCE = rtb_Compare_as;
          if (FMS_DW.icLoad_o != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S41>/SearchL1RefWP' incorporates:
           *  Delay: '<S43>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_DW.start_wp_DSTATE[0] -
            FMS_U.INS_Out.x_R;
          rtb_P_f_idx_0 = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S57>/Divide' */
          rtb_Gain = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S41>/SearchL1RefWP' */
          rtb_Switch_f_idx_0 = rtb_Gain * rtb_TmpSignalConversionAtMath_0;
          rtb_P_i_idx_0 = rtb_Gain;

          /* Product: '<S57>/Divide' */
          rtb_Gain = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S41>/SearchL1RefWP' incorporates:
           *  Constant: '<S39>/L1'
           *  Delay: '<S43>/start_wp'
           */
          rtb_Switch_f_idx_0 += rtb_Gain * rtb_P_f_idx_0;
          rtb_Saturation = 2.0F * rtb_Switch_f_idx_0;
          rtb_MathFunction_k[0] = 0.0F;
          rtb_MathFunction_k[1] = 0.0F;
          D = rtb_Saturation * rtb_Saturation -
            ((rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0
              + rtb_P_f_idx_0 * rtb_P_f_idx_0) - FMS_PARAM.L1 * FMS_PARAM.L1) *
            4.0F;
          rtb_Switch_f_idx_1 = -1.0F;
          if (D > 0.0F) {
            rtb_Switch_f_idx_1 = sqrtf(D);
            rtb_Switch_f_idx_1 = fmaxf((-rtb_Saturation + rtb_Switch_f_idx_1) /
              2.0F, (-rtb_Saturation - rtb_Switch_f_idx_1) / 2.0F);
            rtb_MathFunction_k[0] = rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 * rtb_Gain +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (D == 0.0F) {
              rtb_Switch_f_idx_1 = -rtb_Saturation / 2.0F;
              rtb_MathFunction_k[0] = rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 * rtb_Gain +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S44>/Compare' incorporates:
           *  Constant: '<S44>/Constant'
           *  MATLAB Function: '<S41>/SearchL1RefWP'
           */
          rtb_Compare_as = (rtb_Switch_f_idx_1 > 0.0F);

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S41>/OutRegionRefWP' incorporates:
           *  Delay: '<S43>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_P_i_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
            rtb_Gain;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > 1.29246971E-26F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_0;
          } else {
            rtb_Saturation = rtb_Switch_f_idx_0 / 1.29246971E-26F;
            rtb_TmpSignalConversionAtMath_0 = rtb_Saturation * rtb_Saturation;
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Switch_f_idx_1 * rtb_Gain +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > rtb_Switch_f_idx_2) {
            rtb_Saturation = rtb_Switch_f_idx_2 / rtb_Switch_f_idx_0;
            rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_0 *
              rtb_Saturation * rtb_Saturation + 1.0F;
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_0;
          } else {
            rtb_Saturation = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
            rtb_TmpSignalConversionAtMath_0 += rtb_Saturation * rtb_Saturation;
          }

          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_2 * sqrtf
            (rtb_TmpSignalConversionAtMath_0);
          rtb_Switch_f_idx_2 = rtb_TmpSignalConversionAtMath_0 * 0.577350259F +
            rtb_Switch_f_idx_1;

          /* Switch: '<S41>/Switch' incorporates:
           *  Delay: '<S43>/start_wp'
           *  MATLAB Function: '<S41>/OutRegionRefWP'
           */
          if (rtb_Compare_as) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[0];
          } else {
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2 * rtb_P_i_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S42>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S52>/Math Function' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 *
            rtb_Switch_f_idx_1;
          rtb_MathFunction_k[0] = rtb_Switch_f_idx_1;

          /* Switch: '<S41>/Switch' incorporates:
           *  Delay: '<S43>/start_wp'
           *  MATLAB Function: '<S41>/OutRegionRefWP'
           *  Sum: '<S42>/Subtract'
           */
          if (rtb_Compare_as) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[1];
          } else {
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2 * rtb_Gain +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S42>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S52>/Math Function' incorporates:
           *  Math: '<S50>/Square'
           */
          rtb_Gain = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

          /* Sum: '<S52>/Sum of Elements' incorporates:
           *  Math: '<S52>/Math Function'
           */
          rtb_P_i_idx_0 = rtb_Gain + rtb_TmpSignalConversionAtMath_0;

          /* Math: '<S52>/Math Function1' incorporates:
           *  Sum: '<S52>/Sum of Elements'
           *
           * About '<S52>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
          }

          /* End of Math: '<S52>/Math Function1' */

          /* Switch: '<S52>/Switch' incorporates:
           *  Constant: '<S52>/Constant'
           *  Product: '<S52>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_MathFunction_k[0];
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S52>/Switch' */

          /* Product: '<S52>/Divide' */
          rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S55>/Sum of Elements' incorporates:
           *  Math: '<S55>/Math Function'
           *  SignalConversion: '<S55>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_P_i_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0]
            * rtb_Divide_aj[0];

          /* Math: '<S55>/Math Function1' incorporates:
           *  Sum: '<S55>/Sum of Elements'
           *
           * About '<S55>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
          }

          /* End of Math: '<S55>/Math Function1' */

          /* Switch: '<S55>/Switch' incorporates:
           *  Constant: '<S55>/Constant'
           *  Product: '<S55>/Product'
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

          /* End of Switch: '<S55>/Switch' */

          /* Product: '<S55>/Divide' */
          rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Product: '<S54>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_fd[0] / rtb_Switch_fd[2];
          rtb_MathFunction_k[0] *= rtb_MathFunction_k[0];

          /* Product: '<S55>/Divide' incorporates:
           *  Math: '<S50>/Square'
           */
          rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Product: '<S54>/Divide' */
          rtb_P_f_idx_0 = rtb_Switch_fd[1] / rtb_Switch_fd[2];

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sqrt: '<S49>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S49>/Square'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Sum: '<S49>/Sum of Elements'
           */
          rtb_P_i_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                                FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S47>/Square' */
          rtb_Switch_f_idx_1 = rtb_P_i_idx_0 * rtb_P_i_idx_0;

          /* Sum: '<S53>/Subtract' incorporates:
           *  Product: '<S53>/Multiply'
           *  Product: '<S53>/Multiply1'
           */
          rtb_P_i_idx_0 = rtb_Divide_aj[0] * rtb_P_f_idx_0 - rtb_Divide_aj[1] *
            rtb_TmpSignalConversionAtMath_0;

          /* Signum: '<S48>/Sign1' */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -1.0F;
          } else {
            if (rtb_P_i_idx_0 > 0.0F) {
              rtb_P_i_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S48>/Sign1' */

          /* Switch: '<S48>/Switch2' incorporates:
           *  Constant: '<S48>/Constant4'
           */
          if (rtb_P_i_idx_0 == 0.0F) {
            rtb_P_i_idx_0 = 1.0F;
          }

          /* End of Switch: '<S48>/Switch2' */

          /* DotProduct: '<S48>/Dot Product' */
          rtb_Switch_f_idx_2 = rtb_TmpSignalConversionAtMath_0 * rtb_Divide_aj[0]
            + rtb_P_f_idx_0 * rtb_Divide_aj[1];

          /* Trigonometry: '<S48>/Acos' incorporates:
           *  DotProduct: '<S48>/Dot Product'
           */
          if (rtb_Switch_f_idx_2 > 1.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_2 < -1.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            }
          }

          /* Product: '<S48>/Multiply' incorporates:
           *  Trigonometry: '<S48>/Acos'
           */
          rtb_P_i_idx_0 *= acosf(rtb_Switch_f_idx_2);

          /* Saturate: '<S47>/Saturation' */
          if (rtb_P_i_idx_0 > 1.57079637F) {
            rtb_P_i_idx_0 = 1.57079637F;
          } else {
            if (rtb_P_i_idx_0 < -1.57079637F) {
              rtb_P_i_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S47>/Saturation' */

          /* Gain: '<S39>/AY_P' incorporates:
           *  Constant: '<S39>/L1'
           *  Constant: '<S47>/Constant'
           *  Gain: '<S47>/Gain'
           *  MinMax: '<S47>/Max'
           *  MinMax: '<S47>/Min'
           *  Product: '<S47>/Divide'
           *  Product: '<S47>/Multiply1'
           *  Sqrt: '<S50>/Sqrt'
           *  Sum: '<S50>/Sum of Elements'
           *  Trigonometry: '<S47>/Sin'
           */
          FMS_B.Merge = 2.0F * rtb_Switch_f_idx_1 * arm_sin_f32(rtb_P_i_idx_0) /
            fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_MathFunction_k[0]),
                   0.5F)) * FMS_PARAM.AY_P;

          /* Update for UnitDelay: '<S56>/Delay Input1'
           *
           * Block description for '<S56>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE = (real32_T)i;

          /* Update for Delay: '<S43>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S43>/start_wp' */
          FMS_DW.icLoad_o = 0U;

          /* End of Outputs for SubSystem: '<S36>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S36>/Brake Control' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* SignalConversion: '<S38>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
           *  Constant: '<S38>/Constant'
           */
          FMS_B.Merge = 0.0F;

          /* End of Outputs for SubSystem: '<S36>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S36>/Move Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* DeadZone: '<S59>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S21>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > 0.05F) {
            rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - 0.05F;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -0.05F) {
            rtb_Gain = 0.0F;
          } else {
            rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - -0.05F;
          }

          /* End of DeadZone: '<S59>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Gain: '<S59>/Gain' */
          FMS_B.Merge = 1.05263162F * rtb_Gain;

          /* End of Outputs for SubSystem: '<S36>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S36>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S31>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.u_cmd = rtb_Gain_cl;
        FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge;

        /* End of Outputs for SubSystem: '<S26>/Position' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S26>/Unknown' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

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
       *  SignalConversion: '<S28>/TmpHiddenBufferAtBus AssignmentInport1'
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
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* Saturate: '<S107>/Saturation' incorporates:
       *  Constant: '<S107>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S21>/Signal Copy2'
       *  Sum: '<S107>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_Gain = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Gain = 0.0F;
      } else {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S107>/Saturation' */
      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* BusAssignment: '<S28>/Bus Assignment' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  Constant: '<S107>/Constant5'
       *  DataTypeConversion: '<S106>/Data Type Conversion'
       *  Gain: '<S107>/Gain4'
       *  Outport: '<Root>/FMS_Out'
       *  Sum: '<S107>/Add'
       */
      FMS_Y.FMS_Out.actuator_cmd[0] = (uint16_T)fmodf(floorf(500.0F * rtb_Gain +
        1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* DataTypeConversion: '<S106>/Data Type Conversion1' incorporates:
       *  Bias: '<S106>/Bias1'
       *  Gain: '<S106>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S21>/Signal Copy2'
       */
      rtb_Gain = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_roll + 1500.0F),
                       65536.0F);

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* BusAssignment: '<S28>/Bus Assignment' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  DataTypeConversion: '<S106>/Data Type Conversion1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[1] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
      for (i = 0; i < 14; i++) {
        FMS_Y.FMS_Out.actuator_cmd[i + 2] = 0U;
      }

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
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S128>/Constant'
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
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = (uint32_T)rtb_Gain;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S8>/Delay' */
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
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S26>/Position' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* End of Start for SubSystem: '<S26>/Position' */
  /* End of Start for SubSystem: '<S22>/Assist' */
  /* End of Start for SubSystem: '<S20>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;
  FMS_PrevZCX.start_vel_Reset_ZCE = POS_ZCSIG;
  FMS_PrevZCX.start_wp_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
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
  /* SystemInitialize for IfAction SubSystem: '<S22>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/Return' */
  /* InitializeConditions for Delay: '<S112>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S29>/Return' */
  /* End of SystemInitialize for SubSystem: '<S22>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S27>/Mission' */
  /* InitializeConditions for UnitDelay: '<S68>/Delay Input1'
   *
   * Block description for '<S68>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S65>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S65>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S27>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S22>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S26>/Position' */
  /* SystemInitialize for Chart: '<S37>/Motion State' */
  FMS_DW.temporalCounter_i1_o = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for IfAction SubSystem: '<S36>/Hold Control' */
  /* InitializeConditions for UnitDelay: '<S56>/Delay Input1'
   *
   * Block description for '<S56>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S43>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S43>/start_wp' */
  FMS_DW.icLoad_o = 1U;

  /* End of SystemInitialize for SubSystem: '<S36>/Hold Control' */

  /* SystemInitialize for Merge: '<S36>/Merge' */
  FMS_B.Merge = 0.0F;

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
