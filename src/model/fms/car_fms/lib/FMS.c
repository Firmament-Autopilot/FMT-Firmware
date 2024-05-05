/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1971
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun May  5 15:03:56 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S32>/Motion State' */
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
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)3U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
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
struct_JZsp0rjS1ITw1R2rJuIi FMS_PARAM = {
  { 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F },

  { 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F },
  10.0F,
  3.0F,
  5.0F,
  4.0F,
  0.52359879F,
  0.5F,
  5.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S19>/Constant6'
                                        *   '<S20>/Constant6'
                                        *   '<S27>/Gain'
                                        *   '<S27>/Gain1'
                                        *   '<S88>/L1'
                                        *   '<S88>/vel'
                                        *   '<S30>/Gain'
                                        *   '<S67>/L1'
                                        *   '<S67>/vel'
                                        *   '<S90>/AccToRate'
                                        *   '<S31>/AccToRate'
                                        *   '<S68>/AccToRate'
                                        *   '<S34>/L1'
                                        *   '<S35>/Gain6'
                                        */

struct_jgVLU9PsiazymsYzo6u6IH FMS_EXPORT = {
  10U,

  { 67, 97, 114, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S107>/Constant'
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
static void FMS_enter_internal_Arm(void);
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
 *    '<S92>/NearbyRefWP'
 *    '<S70>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_k, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S96>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S24>/Unknown'
 *    '<S22>/Unknown'
 *    '<S21>/Unknown'
 *    '<S17>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S89>/Bus Assignment' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S89>/Constant2'
   *  SignalConversion: '<S89>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S89>/Bus Assignment' */
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
static void FMS_enter_internal_Arm(void)
{
  uint32_T qY;
  real_T tmp;
  tmp = FMS_getArmMode(FMS_B.target_mode);
  if (tmp == 3.0) {
    FMS_DW.is_Arm = FMS_IN_Auto;
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
static void FMS_exit_internal_Arm(void)
{
  if (FMS_DW.is_Arm == FMS_IN_Auto) {
    if (FMS_DW.is_Auto == FMS_IN_Mission) {
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
    } else {
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
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
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
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
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
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        break;
      }
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
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
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
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

                  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Sum: '<S110>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S110>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S111>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S111>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S111>/Multiply1' incorporates:
                   *  Product: '<S111>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S111>/Divide' incorporates:
                   *  Constant: '<S111>/Constant'
                   *  Constant: '<S111>/R'
                   *  Sqrt: '<S111>/Sqrt'
                   *  Sum: '<S111>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S111>/Product3' incorporates:
                   *  Constant: '<S111>/Constant1'
                   *  Product: '<S111>/Multiply1'
                   *  Sum: '<S111>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S111>/Multiply2' incorporates:
                   *  Trigonometry: '<S111>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S115>/Abs' incorporates:
                   *  Abs: '<S118>/Abs1'
                   *  Switch: '<S115>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S115>/Switch1' incorporates:
                   *  Abs: '<S115>/Abs'
                   *  Bias: '<S115>/Bias2'
                   *  Bias: '<S115>/Bias3'
                   *  Constant: '<S112>/Constant'
                   *  Constant: '<S112>/Constant1'
                   *  Constant: '<S117>/Constant'
                   *  Gain: '<S115>/Gain1'
                   *  Product: '<S115>/Multiply'
                   *  RelationalOperator: '<S117>/Compare'
                   *  Switch: '<S112>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S118>/Switch1' incorporates:
                     *  Bias: '<S118>/Bias2'
                     *  Bias: '<S118>/Bias3'
                     *  Constant: '<S118>/Constant'
                     *  Constant: '<S119>/Constant'
                     *  Math: '<S118>/Math Function'
                     *  RelationalOperator: '<S119>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S118>/Switch1' */

                    /* Signum: '<S115>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S115>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S112>/Sum' incorporates:
                   *  Sum: '<S110>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S110>/Multiply' incorporates:
                   *  Gain: '<S110>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S114>/Switch1' incorporates:
                   *  Abs: '<S114>/Abs1'
                   *  Bias: '<S114>/Bias2'
                   *  Bias: '<S114>/Bias3'
                   *  Constant: '<S114>/Constant'
                   *  Constant: '<S116>/Constant'
                   *  Math: '<S114>/Math Function'
                   *  RelationalOperator: '<S116>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S114>/Switch1' */

                  /* Product: '<S110>/Multiply' incorporates:
                   *  Gain: '<S110>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S110>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S113>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S113>/Sum2' incorporates:
                   *  Product: '<S113>/Multiply1'
                   *  Product: '<S113>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S113>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S113>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S113>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S108>/Data Type Conversion' incorporates:
                   *  Gain: '<S110>/Gain'
                   *  Sum: '<S110>/Sum1'
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
        FMS_B.stick_val[0] = FMS_DW.stick_val[0];
        FMS_B.stick_val[1] = FMS_DW.stick_val[1];
        FMS_B.stick_val[2] = FMS_DW.stick_val[2];
        FMS_B.stick_val[3] = FMS_DW.stick_val[3];
        FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

        /* Outputs for Function Call SubSystem: '<S3>/Vehicle.StickMoved' */
        /* RelationalOperator: '<S120>/Compare' incorporates:
         *  Abs: '<S109>/Abs'
         *  Constant: '<S120>/Constant'
         *  MinMax: '<S109>/Max'
         *  Sum: '<S109>/Sum'
         */
        FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
          FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
          FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
          FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
          FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

        /* End of Outputs for SubSystem: '<S3>/Vehicle.StickMoved' */
        if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
          rtb_Sum_idx_0 = FMS_getArmMode(FMS_B.target_mode);
          if (rtb_Sum_idx_0 == 3.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
            FMS_DW.is_Arm = FMS_IN_Auto;
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
              FMS_B.Cmd_In.cur_waypoint[0] =
                FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
              FMS_B.Cmd_In.cur_waypoint[1] =
                FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
              FMS_B.Cmd_In.cur_waypoint[2] =
                FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
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
              break;

             default:
              FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
              break;
            }
          } else if (rtb_Sum_idx_0 == 2.0) {
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
          } else if (rtb_Sum_idx_0 == 1.0) {
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
            b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
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
              absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                            FMS_DW.home[0]);
              if (absxk > 1.29246971E-26F) {
                y = 1.0F;
                scale = absxk;
              } else {
                t = absxk / 1.29246971E-26F;
                y = t * t;
              }

              absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                            FMS_DW.home[1]);
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
              break;
            }
          }
        }
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
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 200) {
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
            FMS_DW.durationLastReferenceTick_1_h > 150) {
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
  real32_T A;
  real32_T D;
  int8_T rtPrevAction;
  real32_T rtb_Saturation_k;
  real32_T rtb_Divide_aj[2];
  real32_T rtb_MathFunction_k[2];
  real32_T rtb_AccToRate_c;
  real32_T rtb_Switch_h[3];
  real32_T rtb_Gain;
  real32_T rtb_VectorConcatenate[9];
  boolean_T rtb_Compare_c;
  MotionState rtb_state;
  real32_T rtb_AccToRate_d;
  real32_T rtb_sign_u_est_C;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  boolean_T u;
  real32_T rtb_Switch_f_idx_0;
  real32_T rtb_Switch_f_idx_1;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_P_f_idx_0;
  real32_T rtb_P_f_idx_1;
  real32_T a_tmp;
  real32_T u1_tmp;
  boolean_T guard1 = false;

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
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
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
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  rtb_AccToRate_d = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_AccToRate_d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_AccToRate_d;
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.target_mode = PilotMode_Acro;
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
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      }
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.target_mode = PilotMode_Stabilize;
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
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
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

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_Compare_c = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_Compare_c) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_Compare_c;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
    FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
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
  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  /* SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_h[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_h[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_h[2] = FMS_B.Cmd_In.sp_waypoint[2];

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
      if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
        /* Disable for SwitchCase: '<S31>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
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
     *  SignalConversion: '<S19>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S19>/Bus Assignment' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  Constant: '<S19>/Constant2'
     *  DataTypeConversion: '<S19>/Data Type Conversion2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
       *  Constant: '<S19>/Constant6'
       */
      rtb_AccToRate_d = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_AccToRate_d < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_AccToRate_d : (int32_T)
        (uint16_T)rtb_AccToRate_d);
    }

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
     *  SignalConversion: '<S20>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S20>/Bus Assignment' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  Constant: '<S20>/Constant2'
     *  DataTypeConversion: '<S20>/Data Type Conversion3'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
       *  Constant: '<S20>/Constant6'
       */
      rtb_AccToRate_d = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_AccToRate_d < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_AccToRate_d : (int32_T)
        (uint16_T)rtb_AccToRate_d);
    }

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
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for SwitchCase: '<S31>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S17>/SubMode' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SwitchCase: '<S24>/Switch Case' incorporates:
       *  Product: '<S105>/Divide'
       *  Sum: '<S93>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S91>/Delay'
           */
          FMS_DW.icLoad_c = 1U;

          /* End of InitializeConditions for SubSystem: '<S24>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S102>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S102>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S100>/Sum of Elements'
         */
        rtb_AccToRate_d = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
          * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S102>/Math Function1' incorporates:
         *  Sum: '<S102>/Sum of Elements'
         *
         * About '<S102>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_AccToRate_d < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_AccToRate_d));
        } else {
          rtb_Saturation_k = sqrtf(rtb_AccToRate_d);
        }

        /* End of Math: '<S102>/Math Function1' */

        /* Switch: '<S102>/Switch' incorporates:
         *  Constant: '<S102>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S102>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Saturation_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Gain = rtb_Saturation_k;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Gain = 1.0F;
        }

        /* End of Switch: '<S102>/Switch' */

        /* Product: '<S102>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Gain;
        rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Gain;

        /* Sum: '<S105>/Sum of Elements' incorporates:
         *  Math: '<S105>/Math Function'
         *  SignalConversion: '<S105>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_f_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S105>/Math Function1' incorporates:
         *  Sum: '<S105>/Sum of Elements'
         *
         * About '<S105>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_f_idx_0 < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_P_f_idx_0));
        } else {
          rtb_Saturation_k = sqrtf(rtb_P_f_idx_0);
        }

        /* End of Math: '<S105>/Math Function1' */

        /* Switch: '<S105>/Switch' incorporates:
         *  Constant: '<S105>/Constant'
         *  Product: '<S105>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_aj[1];
          rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
          rtb_Gain = rtb_Saturation_k;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Gain = 1.0F;
        }

        /* End of Switch: '<S105>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S92>/NearbyRefWP' incorporates:
         *  Constant: '<S88>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_h[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_aj, &rtb_AccToRate_c);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Delay: '<S91>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S92>/SearchL1RefWP' incorporates:
         *  Constant: '<S88>/L1'
         *  Delay: '<S91>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S92>/OutRegionRegWP'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        a_tmp = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];
        rtb_sign_u_est_C = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        A = a_tmp * a_tmp + rtb_sign_u_est_C * rtb_sign_u_est_C;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_k = (a_tmp * (FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R)
                            + rtb_sign_u_est_C * (FMS_DW.Delay_DSTATE[1] -
          FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation_k * rtb_Saturation_k - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_DW.Delay_DSTATE[0] * FMS_DW.Delay_DSTATE[0]) +
          FMS_DW.Delay_DSTATE[1] * FMS_DW.Delay_DSTATE[1]) - (FMS_U.INS_Out.x_R *
          FMS_DW.Delay_DSTATE[0] + FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE[1]) *
          2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_P_f_idx_0 = 0.0F;
        rtb_P_f_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation_k + u1_tmp) / (2.0F * A);
          rtb_Saturation_k = (-rtb_Saturation_k - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Saturation_k >= 0.0F) &&
              (rtb_Saturation_k <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, rtb_Saturation_k);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((rtb_Saturation_k >= 0.0F) && (rtb_Saturation_k <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = rtb_Saturation_k;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation_k / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_P_f_idx_0 = a_tmp * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE[0];
          rtb_P_f_idx_1 = rtb_sign_u_est_C * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE[1];
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S92>/OutRegionRegWP' incorporates:
         *  Delay: '<S91>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        D = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) * rtb_sign_u_est_C +
             (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE[0]) * a_tmp) / (a_tmp *
          a_tmp + rtb_sign_u_est_C * rtb_sign_u_est_C);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Compare_c = (D <= 0.0F);
        u = (D >= 1.0F);
        if (rtb_Compare_c) {
          rtb_Saturation_k = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_k = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          rtb_Saturation_k = D * a_tmp + FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S92>/Switch1' incorporates:
         *  Constant: '<S95>/Constant'
         *  RelationalOperator: '<S95>/Compare'
         */
        if (rtb_AccToRate_c <= 0.0F) {
          /* Switch: '<S92>/Switch' incorporates:
           *  Constant: '<S94>/Constant'
           *  MATLAB Function: '<S92>/SearchL1RefWP'
           *  RelationalOperator: '<S94>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_Divide_aj[0] = rtb_P_f_idx_0;
            rtb_Divide_aj[1] = rtb_P_f_idx_1;
          } else {
            rtb_Divide_aj[0] = rtb_Saturation_k;

            /* MATLAB Function: '<S92>/OutRegionRegWP' incorporates:
             *  Delay: '<S91>/Delay'
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_c) {
              rtb_Divide_aj[1] = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_aj[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              rtb_Divide_aj[1] = D * rtb_sign_u_est_C + FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S92>/Switch' */
        }

        /* End of Switch: '<S92>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S93>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_sign_u_est_C = rtb_Divide_aj[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S103>/Math Function' */
        rtb_TmpSignalConversionAtMath_0 = rtb_sign_u_est_C * rtb_sign_u_est_C;
        rtb_Divide_aj[0] = rtb_sign_u_est_C;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S93>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_sign_u_est_C = rtb_Divide_aj[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S103>/Math Function' incorporates:
         *  Math: '<S101>/Square'
         */
        rtb_P_f_idx_0 = rtb_sign_u_est_C * rtb_sign_u_est_C;

        /* Sum: '<S103>/Sum of Elements' incorporates:
         *  Math: '<S103>/Math Function'
         */
        rtb_Saturation_k = rtb_P_f_idx_0 + rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S103>/Math Function1' incorporates:
         *  Sum: '<S103>/Sum of Elements'
         *
         * About '<S103>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_Saturation_k));
        } else {
          rtb_Saturation_k = sqrtf(rtb_Saturation_k);
        }

        /* End of Math: '<S103>/Math Function1' */

        /* Switch: '<S103>/Switch' incorporates:
         *  Constant: '<S103>/Constant'
         *  Product: '<S103>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_h[0] = rtb_Divide_aj[0];
          rtb_Switch_h[1] = rtb_sign_u_est_C;
          rtb_Switch_h[2] = rtb_Saturation_k;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S103>/Switch' */

        /* Product: '<S103>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_h[0] / rtb_Switch_h[2];
        rtb_AccToRate_c = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Sum: '<S106>/Sum of Elements' incorporates:
         *  Math: '<S106>/Math Function'
         *  SignalConversion: '<S106>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_k = rtb_AccToRate_c * rtb_AccToRate_c +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S106>/Math Function1' incorporates:
         *  Sum: '<S106>/Sum of Elements'
         *
         * About '<S106>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -sqrtf(fabsf(rtb_Saturation_k));
        } else {
          rtb_Saturation_k = sqrtf(rtb_Saturation_k);
        }

        /* End of Math: '<S106>/Math Function1' */

        /* Switch: '<S106>/Switch' incorporates:
         *  Constant: '<S106>/Constant'
         *  Product: '<S106>/Product'
         */
        if (rtb_Saturation_k > 0.0F) {
          rtb_Switch_h[0] = rtb_AccToRate_c;
          rtb_Switch_h[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_h[2] = rtb_Saturation_k;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S106>/Switch' */

        /* Product: '<S106>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_h[0] / rtb_Switch_h[2];

        /* Math: '<S101>/Square' */
        rtb_MathFunction_k[0] = rtb_Divide_aj[0] * rtb_Divide_aj[0];
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Gain;

        /* Product: '<S106>/Divide' incorporates:
         *  Product: '<S105>/Divide'
         */
        rtb_AccToRate_c = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Product: '<S105>/Divide' */
        rtb_sign_u_est_C = rtb_Switch_f_idx_1 / rtb_Gain;

        /* Sqrt: '<S100>/Sqrt' */
        rtb_Saturation_k = sqrtf(rtb_AccToRate_d);

        /* Gain: '<S93>/Gain' incorporates:
         *  Math: '<S93>/Square'
         */
        rtb_Gain = rtb_Saturation_k * rtb_Saturation_k * 2.0F;

        /* Sum: '<S104>/Subtract' incorporates:
         *  Product: '<S104>/Multiply'
         *  Product: '<S104>/Multiply1'
         */
        rtb_Saturation_k = rtb_TmpSignalConversionAtMath_0 * rtb_sign_u_est_C -
          rtb_AccToRate_c * rtb_Divide_aj[0];

        /* Signum: '<S99>/Sign1' */
        if (rtb_Saturation_k < 0.0F) {
          rtb_Saturation_k = -1.0F;
        } else {
          if (rtb_Saturation_k > 0.0F) {
            rtb_Saturation_k = 1.0F;
          }
        }

        /* End of Signum: '<S99>/Sign1' */

        /* Switch: '<S99>/Switch2' incorporates:
         *  Constant: '<S99>/Constant4'
         */
        if (rtb_Saturation_k == 0.0F) {
          rtb_Saturation_k = 1.0F;
        }

        /* End of Switch: '<S99>/Switch2' */

        /* DotProduct: '<S99>/Dot Product' */
        rtb_sign_u_est_C = rtb_Divide_aj[0] * rtb_TmpSignalConversionAtMath_0 +
          rtb_sign_u_est_C * rtb_AccToRate_c;

        /* Trigonometry: '<S99>/Acos' incorporates:
         *  DotProduct: '<S99>/Dot Product'
         */
        if (rtb_sign_u_est_C > 1.0F) {
          rtb_sign_u_est_C = 1.0F;
        } else {
          if (rtb_sign_u_est_C < -1.0F) {
            rtb_sign_u_est_C = -1.0F;
          }
        }

        /* Product: '<S99>/Multiply' incorporates:
         *  Trigonometry: '<S99>/Acos'
         */
        rtb_Saturation_k *= acosf(rtb_sign_u_est_C);

        /* Saturate: '<S93>/Saturation' */
        if (rtb_Saturation_k > 1.57079637F) {
          rtb_Saturation_k = 1.57079637F;
        } else {
          if (rtb_Saturation_k < -1.57079637F) {
            rtb_Saturation_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S93>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S88>/Bus Assignment1'
         *  Constant: '<S88>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S88>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S88>/L1'
         *  Constant: '<S88>/vel'
         *  Constant: '<S93>/Constant'
         *  Gain: '<S90>/AccToRate'
         *  MinMax: '<S93>/Max'
         *  MinMax: '<S93>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S93>/Divide'
         *  Product: '<S93>/Multiply1'
         *  Sqrt: '<S101>/Sqrt'
         *  Sum: '<S101>/Sum of Elements'
         *  Trigonometry: '<S93>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = arm_sin_f32(rtb_Saturation_k) * rtb_Gain / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_P_f_idx_0 + rtb_MathFunction_k[0]),
            0.5F)) * FMS_PARAM.ACC2RATE;

        /* Update for Delay: '<S91>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S87>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S87>/Bus Assignment'
         *  Constant: '<S87>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S87>/Constant3'
         *  Constant: '<S87>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.r_cmd = 0.0F;

        /* End of Outputs for SubSystem: '<S24>/Hold' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S89>/Action Port'
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
       *  RelationalOperator: '<S66>/FixPt Relational Operator'
       *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S66>/Delay Input1'
       *
       * Block description for '<S66>/Delay Input1':
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
         *  ActionPort: '<S64>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S64>/Bus Assignment'
         *  Constant: '<S64>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S64>/Bus Assignment' incorporates:
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
           *  ActionPort: '<S63>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  UnitDelay: '<S66>/Delay Input1'
           *
           * Block description for '<S66>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S22>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S63>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S63>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S67>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Sum: '<S80>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S80>/Math Function'
         *  RelationalOperator: '<S66>/FixPt Relational Operator'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S66>/Delay Input1'
         *
         * Block description for '<S66>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_AccToRate_d = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
          * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S80>/Math Function1' incorporates:
         *  Sum: '<S80>/Sum of Elements'
         *
         * About '<S80>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_AccToRate_d < 0.0F) {
          rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_AccToRate_d));
        } else {
          rtb_P_f_idx_0 = sqrtf(rtb_AccToRate_d);
        }

        /* End of Math: '<S80>/Math Function1' */

        /* Switch: '<S80>/Switch' incorporates:
         *  Constant: '<S80>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S80>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_P_f_idx_0 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Gain = rtb_P_f_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Gain = 1.0F;
        }

        /* End of Switch: '<S80>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S70>/NearbyRefWP' incorporates:
         *  Constant: '<S67>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_h[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_MathFunction_k, &rtb_AccToRate_d);

        /* MATLAB Function: '<S70>/SearchL1RefWP' incorporates:
         *  Constant: '<S67>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S70>/OutRegionRegWP'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        a_tmp = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_sign_u_est_C = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        A = a_tmp * a_tmp + rtb_sign_u_est_C * rtb_sign_u_est_C;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_k = (a_tmp * (FMS_B.Cmd_In.cur_waypoint[0] -
          FMS_U.INS_Out.x_R) + rtb_sign_u_est_C * (FMS_B.Cmd_In.cur_waypoint[1]
          - FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation_k * rtb_Saturation_k - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_B.Cmd_In.cur_waypoint[0] * FMS_B.Cmd_In.cur_waypoint[0]) +
          FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint[1]) -
          (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0] + FMS_U.INS_Out.y_R *
           FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) *
          (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_Divide_aj[0] = 0.0F;
        rtb_Divide_aj[1] = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation_k + u1_tmp) / (2.0F * A);
          rtb_Saturation_k = (-rtb_Saturation_k - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Saturation_k >= 0.0F) &&
              (rtb_Saturation_k <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, rtb_Saturation_k);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((rtb_Saturation_k >= 0.0F) && (rtb_Saturation_k <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = rtb_Saturation_k;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation_k / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Divide_aj[0] = a_tmp * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_aj[1] = rtb_sign_u_est_C * rtb_TmpSignalConversionAtMath_0
            + FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S70>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        D = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
             rtb_sign_u_est_C + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0])
             * a_tmp) / (a_tmp * a_tmp + rtb_sign_u_est_C * rtb_sign_u_est_C);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Compare_c = (D <= 0.0F);
        u = (D >= 1.0F);
        if (rtb_Compare_c) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_f_idx_0 = D * a_tmp + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Switch: '<S70>/Switch1' incorporates:
         *  Constant: '<S73>/Constant'
         *  RelationalOperator: '<S73>/Compare'
         */
        if (rtb_AccToRate_d <= 0.0F) {
          /* Switch: '<S70>/Switch' incorporates:
           *  Constant: '<S72>/Constant'
           *  MATLAB Function: '<S70>/SearchL1RefWP'
           *  RelationalOperator: '<S72>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_MathFunction_k[0] = rtb_Divide_aj[0];
            rtb_MathFunction_k[1] = rtb_Divide_aj[1];
          } else {
            rtb_MathFunction_k[0] = rtb_P_f_idx_0;

            /* MATLAB Function: '<S70>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_c) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_MathFunction_k[1] = D * rtb_sign_u_est_C +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }
          }

          /* End of Switch: '<S70>/Switch' */
        }

        /* End of Switch: '<S70>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S71>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_k[0] -
          FMS_U.INS_Out.x_R;
        rtb_AccToRate_c = rtb_MathFunction_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S81>/Math Function' incorporates:
         *  Math: '<S79>/Square'
         */
        rtb_sign_u_est_C = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;
        rtb_AccToRate_d = rtb_AccToRate_c * rtb_AccToRate_c;

        /* Sum: '<S81>/Sum of Elements' incorporates:
         *  Math: '<S81>/Math Function'
         */
        rtb_P_f_idx_0 = rtb_sign_u_est_C + rtb_AccToRate_d;

        /* Math: '<S81>/Math Function1' incorporates:
         *  Sum: '<S81>/Sum of Elements'
         *
         * About '<S81>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_f_idx_0 < 0.0F) {
          rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_P_f_idx_0));
        } else {
          rtb_P_f_idx_0 = sqrtf(rtb_P_f_idx_0);
        }

        /* End of Math: '<S81>/Math Function1' */

        /* Switch: '<S81>/Switch' incorporates:
         *  Constant: '<S81>/Constant'
         *  Product: '<S81>/Product'
         */
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_Switch_h[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_h[1] = rtb_AccToRate_c;
          rtb_Switch_h[2] = rtb_P_f_idx_0;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S81>/Switch' */

        /* Product: '<S80>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_f_idx_0 / rtb_Gain;
        rtb_Divide_aj[1] = rtb_Switch_f_idx_1 / rtb_Gain;

        /* Sum: '<S83>/Sum of Elements' incorporates:
         *  Math: '<S83>/Math Function'
         *  SignalConversion: '<S83>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_f_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S83>/Math Function1' incorporates:
         *  Sum: '<S83>/Sum of Elements'
         *
         * About '<S83>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_f_idx_0 < 0.0F) {
          rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_P_f_idx_0));
        } else {
          rtb_P_f_idx_0 = sqrtf(rtb_P_f_idx_0);
        }

        /* End of Math: '<S83>/Math Function1' */

        /* Switch: '<S83>/Switch' incorporates:
         *  Constant: '<S83>/Constant'
         *  Product: '<S83>/Product'
         */
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_aj[1];
          rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
          rtb_Gain = rtb_P_f_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Gain = 1.0F;
        }

        /* End of Switch: '<S83>/Switch' */

        /* Product: '<S81>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_h[0] / rtb_Switch_h[2];
        rtb_Divide_aj[1] = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Sum: '<S84>/Sum of Elements' incorporates:
         *  Math: '<S84>/Math Function'
         *  SignalConversion: '<S84>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_f_idx_0 = rtb_Divide_aj[1] * rtb_Divide_aj[1] + rtb_Divide_aj[0] *
          rtb_Divide_aj[0];

        /* Math: '<S84>/Math Function1' incorporates:
         *  Sum: '<S84>/Sum of Elements'
         *
         * About '<S84>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_f_idx_0 < 0.0F) {
          rtb_P_f_idx_0 = -sqrtf(fabsf(rtb_P_f_idx_0));
        } else {
          rtb_P_f_idx_0 = sqrtf(rtb_P_f_idx_0);
        }

        /* End of Math: '<S84>/Math Function1' */

        /* Switch: '<S84>/Switch' incorporates:
         *  Constant: '<S84>/Constant'
         *  Product: '<S84>/Product'
         */
        if (rtb_P_f_idx_0 > 0.0F) {
          rtb_Switch_h[0] = rtb_Divide_aj[1];
          rtb_Switch_h[1] = rtb_Divide_aj[0];
          rtb_Switch_h[2] = rtb_P_f_idx_0;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S84>/Switch' */

        /* Product: '<S84>/Divide' */
        rtb_Divide_aj[0] = rtb_Switch_h[0] / rtb_Switch_h[2];

        /* Product: '<S83>/Divide' */
        rtb_MathFunction_k[0] = rtb_Switch_f_idx_0 / rtb_Gain;

        /* Product: '<S84>/Divide' */
        rtb_Divide_aj[1] = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Product: '<S83>/Divide' */
        rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 / rtb_Gain;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S78>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S78>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S78>/Sum of Elements'
         */
        rtb_P_f_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Gain: '<S71>/Gain' incorporates:
         *  Math: '<S71>/Square'
         */
        rtb_Gain = rtb_P_f_idx_0 * rtb_P_f_idx_0 * 2.0F;

        /* Sum: '<S82>/Subtract' incorporates:
         *  Product: '<S82>/Multiply'
         *  Product: '<S82>/Multiply1'
         */
        rtb_P_f_idx_0 = rtb_Divide_aj[0] * rtb_MathFunction_k[1] -
          rtb_Divide_aj[1] * rtb_MathFunction_k[0];

        /* Signum: '<S77>/Sign1' */
        if (rtb_P_f_idx_0 < 0.0F) {
          rtb_P_f_idx_0 = -1.0F;
        } else {
          if (rtb_P_f_idx_0 > 0.0F) {
            rtb_P_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S77>/Sign1' */

        /* Switch: '<S77>/Switch2' incorporates:
         *  Constant: '<S77>/Constant4'
         */
        if (rtb_P_f_idx_0 == 0.0F) {
          rtb_P_f_idx_0 = 1.0F;
        }

        /* End of Switch: '<S77>/Switch2' */

        /* DotProduct: '<S77>/Dot Product' */
        rtb_Switch_f_idx_1 = rtb_MathFunction_k[0] * rtb_Divide_aj[0] +
          rtb_MathFunction_k[1] * rtb_Divide_aj[1];

        /* Trigonometry: '<S77>/Acos' incorporates:
         *  DotProduct: '<S77>/Dot Product'
         */
        if (rtb_Switch_f_idx_1 > 1.0F) {
          rtb_Switch_f_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_f_idx_1 < -1.0F) {
            rtb_Switch_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S77>/Multiply' incorporates:
         *  Trigonometry: '<S77>/Acos'
         */
        rtb_P_f_idx_0 *= acosf(rtb_Switch_f_idx_1);

        /* Saturate: '<S71>/Saturation' */
        if (rtb_P_f_idx_0 > 1.57079637F) {
          rtb_P_f_idx_0 = 1.57079637F;
        } else {
          if (rtb_P_f_idx_0 < -1.57079637F) {
            rtb_P_f_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S71>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S67>/Bus Assignment'
         *  Constant: '<S67>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S67>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S67>/L1'
         *  Constant: '<S67>/vel'
         *  Constant: '<S71>/Constant'
         *  Gain: '<S68>/AccToRate'
         *  MinMax: '<S71>/Max'
         *  MinMax: '<S71>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S71>/Divide'
         *  Product: '<S71>/Multiply1'
         *  Sqrt: '<S79>/Sqrt'
         *  Sum: '<S79>/Sum of Elements'
         *  Trigonometry: '<S71>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = arm_sin_f32(rtb_P_f_idx_0) * rtb_Gain / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_AccToRate_d + rtb_sign_u_est_C), 0.5F))
          * FMS_PARAM.ACC2RATE;

        /* End of Outputs for SubSystem: '<S63>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S66>/Delay Input1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S66>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S65>/Action Port'
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
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) && (rtPrevAction
           == 1)) {
        /* Disable for SwitchCase: '<S31>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S21>/Stabilize' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S27>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S61>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_AccToRate_d = 0.0F;
        } else {
          rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S61>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S27>/Gain'
         *  Gain: '<S61>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.05263162F * rtb_AccToRate_d * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S62>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > 0.05F) {
          rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_roll - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -0.05F) {
          rtb_AccToRate_d = 0.0F;
        } else {
          rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_roll - -0.05F;
        }

        /* End of DeadZone: '<S62>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S27>/Gain1'
         *  Gain: '<S62>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.05263162F * rtb_AccToRate_d * FMS_PARAM.MAX_R;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S32>/Motion State'
           */
          FMS_DW.temporalCounter_i1_o = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outputs for IfAction SubSystem: '<S31>/Hold Control' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SwitchCase: '<S31>/Switch Case' incorporates:
         *  Gain: '<S58>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S55>/Trigonometric Function1'
         *  Trigonometry: '<S55>/Trigonometric Function3'
         *  Trigonometry: '<S59>/Trigonometric Function1'
         *  Trigonometry: '<S59>/Trigonometric Function3'
         */
        rtb_Gain = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S31>/Hold Control' */

        /* Trigonometry: '<S59>/Trigonometric Function1' */
        rtb_VectorConcatenate[0] = rtb_Gain;

        /* Outputs for IfAction SubSystem: '<S31>/Hold Control' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SwitchCase: '<S31>/Switch Case' incorporates:
         *  Gain: '<S58>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S55>/Trigonometric Function'
         *  Trigonometry: '<S59>/Trigonometric Function'
         *  Trigonometry: '<S59>/Trigonometric Function2'
         */
        rtb_AccToRate_d = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S31>/Hold Control' */

        /* Trigonometry: '<S59>/Trigonometric Function' */
        rtb_VectorConcatenate[1] = rtb_AccToRate_d;

        /* SignalConversion: '<S59>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S59>/Constant3'
         */
        rtb_VectorConcatenate[2] = 0.0F;

        /* Gain: '<S59>/Gain' */
        rtb_VectorConcatenate[3] = -rtb_AccToRate_d;

        /* Trigonometry: '<S59>/Trigonometric Function3' */
        rtb_VectorConcatenate[4] = rtb_Gain;

        /* SignalConversion: '<S59>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S59>/Constant4'
         */
        rtb_VectorConcatenate[5] = 0.0F;

        /* SignalConversion: '<S59>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
        rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
        rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* RelationalOperator: '<S56>/Compare' incorporates:
         *  Abs: '<S32>/Abs1'
         *  Constant: '<S56>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Compare_c = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > 0.05F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S32>/Motion State' incorporates:
         *  Abs: '<S32>/Abs'
         */
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

            /* Product: '<S32>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S16>/Signal Copy1'
             */
            for (i = 0; i < 3; i++) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate[i + 3] *
                                    FMS_U.INS_Out.ve + rtb_VectorConcatenate[i] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }

            /* End of Product: '<S32>/Multiply' */
            if ((fabsf(rtb_VectorConcatenate_0[1]) <= 0.2) ||
                (FMS_DW.temporalCounter_i1_o >= 250U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_Compare_c) {
                FMS_DW.is_c16_FMS = FMS_IN_Move;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_c) {
              FMS_DW.is_c16_FMS = FMS_IN_Move;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_c) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake;
              FMS_DW.temporalCounter_i1_o = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S32>/Motion State' */

        /* SwitchCase: '<S31>/Switch Case' incorporates:
         *  Math: '<S45>/Square'
         *  Product: '<S53>/Divide'
         *  Sum: '<S37>/Subtract'
         *  Switch: '<S36>/Switch'
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
            /* InitializeConditions for IfAction SubSystem: '<S31>/Hold Control' incorporates:
             *  ActionPort: '<S34>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S31>/Switch Case' incorporates:
             *  Delay: '<S38>/start_vel'
             *  Delay: '<S38>/start_wp'
             *  UnitDelay: '<S52>/Delay Input1'
             *
             * Block description for '<S52>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE = 0.0F;
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_o = 1U;

            /* End of InitializeConditions for SubSystem: '<S31>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S31>/Hold Control' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          /* Trigonometry: '<S55>/Trigonometric Function1' */
          rtb_VectorConcatenate[0] = rtb_Gain;

          /* Trigonometry: '<S55>/Trigonometric Function' */
          rtb_VectorConcatenate[1] = rtb_AccToRate_d;

          /* SignalConversion: '<S55>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S55>/Constant3'
           */
          rtb_VectorConcatenate[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S55>/Gain' incorporates:
           *  Gain: '<S54>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Trigonometry: '<S55>/Trigonometric Function2'
           */
          rtb_VectorConcatenate[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Trigonometry: '<S55>/Trigonometric Function3' */
          rtb_VectorConcatenate[4] = rtb_Gain;

          /* SignalConversion: '<S55>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S55>/Constant4'
           */
          rtb_VectorConcatenate[5] = 0.0F;

          /* SignalConversion: '<S55>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3_o[0];
          rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3_o[1];
          rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S46>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S46>/Math Function'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_AccToRate_d = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S46>/Math Function1' incorporates:
           *  Sum: '<S46>/Sum of Elements'
           *
           * About '<S46>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_AccToRate_d < 0.0F) {
            rtb_Gain = -sqrtf(fabsf(rtb_AccToRate_d));
          } else {
            rtb_Gain = sqrtf(rtb_AccToRate_d);
          }

          /* End of Math: '<S46>/Math Function1' */

          /* Switch: '<S46>/Switch' incorporates:
           *  Constant: '<S46>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S46>/Product'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_Gain > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_h[0] = FMS_U.INS_Out.vn;
            rtb_Switch_h[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_h[2] = rtb_Gain;
          } else {
            rtb_Switch_h[0] = 0.0F;
            rtb_Switch_h[1] = 0.0F;
            rtb_Switch_h[2] = 1.0F;
          }

          /* End of Switch: '<S46>/Switch' */

          /* Product: '<S46>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_h[0] / rtb_Switch_h[2];
          rtb_AccToRate_c = rtb_Switch_h[1] / rtb_Switch_h[2];

          /* Sum: '<S49>/Sum of Elements' incorporates:
           *  Math: '<S49>/Math Function'
           *  SignalConversion: '<S49>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_AccToRate_d = rtb_AccToRate_c * rtb_AccToRate_c +
            rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

          /* Math: '<S49>/Math Function1' incorporates:
           *  Sum: '<S49>/Sum of Elements'
           *
           * About '<S49>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_AccToRate_d < 0.0F) {
            rtb_Gain = -sqrtf(fabsf(rtb_AccToRate_d));
          } else {
            rtb_Gain = sqrtf(rtb_AccToRate_d);
          }

          /* End of Math: '<S49>/Math Function1' */

          /* Switch: '<S49>/Switch' incorporates:
           *  Constant: '<S49>/Constant'
           *  Product: '<S49>/Product'
           */
          if (rtb_Gain > 0.0F) {
            rtb_Switch_h[0] = rtb_AccToRate_c;
            rtb_Switch_h[1] = rtb_TmpSignalConversionAtMath_0;
            rtb_Switch_h[2] = rtb_Gain;
          } else {
            rtb_Switch_h[0] = 0.0F;
            rtb_Switch_h[1] = 0.0F;
            rtb_Switch_h[2] = 1.0F;
          }

          /* End of Switch: '<S49>/Switch' */

          /* Product: '<S51>/Multiply' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          for (i = 0; i < 3; i++) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
              FMS_U.INS_Out.ve + rtb_VectorConcatenate[i] * FMS_U.INS_Out.vn;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* End of Product: '<S51>/Multiply' */

          /* Signum: '<S38>/Sign' */
          if (rtb_VectorConcatenate_0[0] < 0.0F) {
            rtb_sign_u_est_C = -1.0F;
          } else if (rtb_VectorConcatenate_0[0] > 0.0F) {
            rtb_sign_u_est_C = 1.0F;
          } else {
            rtb_sign_u_est_C = rtb_VectorConcatenate_0[0];
          }

          /* End of Signum: '<S38>/Sign' */

          /* RelationalOperator: '<S52>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S52>/Delay Input1'
           *
           * Block description for '<S52>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_c = (rtb_sign_u_est_C != FMS_DW.DelayInput1_DSTATE);

          /* Delay: '<S38>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_Compare_c && (FMS_PrevZCX.start_vel_Reset_ZCE != POS_ZCSIG)) {
            FMS_DW.icLoad = 1U;
          }

          FMS_PrevZCX.start_vel_Reset_ZCE = rtb_Compare_c;
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Sum: '<S53>/Sum of Elements' incorporates:
           *  Delay: '<S38>/start_vel'
           *  Math: '<S53>/Math Function'
           */
          rtb_AccToRate_d = FMS_DW.start_vel_DSTATE[0] *
            FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
            FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S53>/Math Function1' incorporates:
           *  Sum: '<S53>/Sum of Elements'
           *
           * About '<S53>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_AccToRate_d < 0.0F) {
            rtb_Gain = -sqrtf(fabsf(rtb_AccToRate_d));
          } else {
            rtb_Gain = sqrtf(rtb_AccToRate_d);
          }

          /* End of Math: '<S53>/Math Function1' */

          /* Switch: '<S53>/Switch' incorporates:
           *  Constant: '<S53>/Constant'
           *  Delay: '<S38>/start_vel'
           *  Product: '<S53>/Product'
           */
          if (rtb_Gain > 0.0F) {
            rtb_Switch_f_idx_0 = FMS_DW.start_vel_DSTATE[0];
            rtb_Switch_f_idx_1 = FMS_DW.start_vel_DSTATE[1];
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Gain = 1.0F;
          }

          /* End of Switch: '<S53>/Switch' */

          /* Delay: '<S38>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_Compare_c && (FMS_PrevZCX.start_wp_Reset_ZCE != POS_ZCSIG)) {
            FMS_DW.icLoad_o = 1U;
          }

          FMS_PrevZCX.start_wp_Reset_ZCE = rtb_Compare_c;
          if (FMS_DW.icLoad_o != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S36>/SearchL1RefWP' incorporates:
           *  Delay: '<S38>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_DW.start_wp_DSTATE[0] -
            FMS_U.INS_Out.x_R;
          rtb_AccToRate_c = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S53>/Divide' */
          rtb_AccToRate_d = rtb_Switch_f_idx_0 / rtb_Gain;

          /* MATLAB Function: '<S36>/SearchL1RefWP' */
          rtb_Switch_f_idx_0 = rtb_AccToRate_d * rtb_TmpSignalConversionAtMath_0;
          rtb_P_f_idx_0 = rtb_AccToRate_d;

          /* Product: '<S53>/Divide' */
          rtb_AccToRate_d = rtb_Switch_f_idx_1 / rtb_Gain;

          /* MATLAB Function: '<S36>/SearchL1RefWP' incorporates:
           *  Constant: '<S34>/L1'
           *  Delay: '<S38>/start_wp'
           */
          rtb_Switch_f_idx_0 += rtb_AccToRate_d * rtb_AccToRate_c;
          rtb_Saturation_k = 2.0F * rtb_Switch_f_idx_0;
          rtb_Divide_aj[0] = 0.0F;
          rtb_Divide_aj[1] = 0.0F;
          D = rtb_Saturation_k * rtb_Saturation_k -
            ((rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0
              + rtb_AccToRate_c * rtb_AccToRate_c) - FMS_PARAM.L1 * FMS_PARAM.L1)
            * 4.0F;
          rtb_Gain = -1.0F;
          if (D > 0.0F) {
            rtb_Gain = sqrtf(D);
            rtb_Gain = fmaxf((-rtb_Saturation_k + rtb_Gain) / 2.0F,
                             (-rtb_Saturation_k - rtb_Gain) / 2.0F);
            rtb_Divide_aj[0] = rtb_Gain * rtb_P_f_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_Divide_aj[1] = rtb_Gain * rtb_AccToRate_d +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (D == 0.0F) {
              rtb_Gain = -rtb_Saturation_k / 2.0F;
              rtb_Divide_aj[0] = rtb_Gain * rtb_P_f_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_Divide_aj[1] = rtb_Gain * rtb_AccToRate_d +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S39>/Compare' incorporates:
           *  Constant: '<S39>/Constant'
           *  MATLAB Function: '<S36>/SearchL1RefWP'
           */
          rtb_Compare_c = (rtb_Gain > 0.0F);

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S36>/OutRegionRefWP' incorporates:
           *  Delay: '<S38>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Gain = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_P_f_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
            rtb_AccToRate_d;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_1 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Gain * rtb_P_f_idx_0 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > 1.29246971E-26F) {
            rtb_Saturation_k = 1.0F;
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_0;
          } else {
            rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_0 /
              1.29246971E-26F;
            rtb_Saturation_k = rtb_TmpSignalConversionAtMath_0 *
              rtb_TmpSignalConversionAtMath_0;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Gain * rtb_AccToRate_d +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > rtb_Switch_f_idx_1) {
            rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 /
              rtb_Switch_f_idx_0;
            rtb_Saturation_k = rtb_Saturation_k *
              rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0
              + 1.0F;
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_0;
          } else {
            rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_0 /
              rtb_Switch_f_idx_1;
            rtb_Saturation_k += rtb_TmpSignalConversionAtMath_0 *
              rtb_TmpSignalConversionAtMath_0;
          }

          rtb_Saturation_k = rtb_Switch_f_idx_1 * sqrtf(rtb_Saturation_k);
          rtb_Gain += rtb_Saturation_k * 0.577350259F;

          /* Switch: '<S36>/Switch' incorporates:
           *  Delay: '<S38>/start_wp'
           *  MATLAB Function: '<S36>/OutRegionRefWP'
           */
          if (rtb_Compare_c) {
            rtb_Switch_f_idx_1 = rtb_Divide_aj[0];
          } else {
            rtb_Switch_f_idx_1 = rtb_Gain * rtb_P_f_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S37>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S47>/Math Function' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 *
            rtb_Switch_f_idx_1;
          rtb_Divide_aj[0] = rtb_Switch_f_idx_1;

          /* Switch: '<S36>/Switch' incorporates:
           *  Delay: '<S38>/start_wp'
           *  MATLAB Function: '<S36>/OutRegionRefWP'
           *  Sum: '<S37>/Subtract'
           */
          if (rtb_Compare_c) {
            rtb_Switch_f_idx_1 = rtb_Divide_aj[1];
          } else {
            rtb_Switch_f_idx_1 = rtb_Gain * rtb_AccToRate_d +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S37>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S47>/Math Function' incorporates:
           *  Math: '<S45>/Square'
           */
          rtb_AccToRate_d = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

          /* Sum: '<S47>/Sum of Elements' incorporates:
           *  Math: '<S47>/Math Function'
           */
          rtb_P_f_idx_0 = rtb_AccToRate_d + rtb_TmpSignalConversionAtMath_0;

          /* Math: '<S47>/Math Function1' incorporates:
           *  Sum: '<S47>/Sum of Elements'
           *
           * About '<S47>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Gain = -sqrtf(fabsf(rtb_P_f_idx_0));
          } else {
            rtb_Gain = sqrtf(rtb_P_f_idx_0);
          }

          /* End of Math: '<S47>/Math Function1' */

          /* Switch: '<S47>/Switch' incorporates:
           *  Constant: '<S47>/Constant'
           *  Product: '<S47>/Product'
           */
          if (rtb_Gain > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_aj[0];
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Gain = 1.0F;
          }

          /* End of Switch: '<S47>/Switch' */

          /* Product: '<S47>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_0 / rtb_Gain;
          rtb_AccToRate_c = rtb_Switch_f_idx_1 / rtb_Gain;

          /* Sum: '<S50>/Sum of Elements' incorporates:
           *  Math: '<S50>/Math Function'
           *  SignalConversion: '<S50>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_P_f_idx_0 = rtb_AccToRate_c * rtb_AccToRate_c +
            rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

          /* Math: '<S50>/Math Function1' incorporates:
           *  Sum: '<S50>/Sum of Elements'
           *
           * About '<S50>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_f_idx_0 < 0.0F) {
            rtb_Gain = -sqrtf(fabsf(rtb_P_f_idx_0));
          } else {
            rtb_Gain = sqrtf(rtb_P_f_idx_0);
          }

          /* End of Math: '<S50>/Math Function1' */

          /* Switch: '<S50>/Switch' incorporates:
           *  Constant: '<S50>/Constant'
           *  Product: '<S50>/Product'
           */
          if (rtb_Gain > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_AccToRate_c;
            rtb_Switch_f_idx_1 = rtb_TmpSignalConversionAtMath_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Gain = 1.0F;
          }

          /* End of Switch: '<S50>/Switch' */

          /* Product: '<S50>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_0 / rtb_Gain;

          /* Product: '<S49>/Divide' */
          rtb_Saturation_k = rtb_Switch_h[0] / rtb_Switch_h[2];
          rtb_Divide_aj[0] *= rtb_Divide_aj[0];

          /* Product: '<S50>/Divide' incorporates:
           *  Math: '<S45>/Square'
           */
          rtb_AccToRate_c = rtb_Switch_f_idx_1 / rtb_Gain;

          /* Product: '<S49>/Divide' */
          rtb_P_f_idx_0 = rtb_Switch_h[1] / rtb_Switch_h[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sqrt: '<S44>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S44>/Square'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S44>/Sum of Elements'
           */
          rtb_Gain = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S42>/Gain' incorporates:
           *  Math: '<S42>/Square'
           */
          rtb_Switch_f_idx_1 = rtb_Gain * rtb_Gain * 2.0F;

          /* Sum: '<S48>/Subtract' incorporates:
           *  Product: '<S48>/Multiply'
           *  Product: '<S48>/Multiply1'
           */
          rtb_Gain = rtb_TmpSignalConversionAtMath_0 * rtb_P_f_idx_0 -
            rtb_AccToRate_c * rtb_Saturation_k;

          /* Signum: '<S43>/Sign1' */
          if (rtb_Gain < 0.0F) {
            rtb_Gain = -1.0F;
          } else {
            if (rtb_Gain > 0.0F) {
              rtb_Gain = 1.0F;
            }
          }

          /* End of Signum: '<S43>/Sign1' */

          /* Switch: '<S43>/Switch2' incorporates:
           *  Constant: '<S43>/Constant4'
           */
          if (rtb_Gain == 0.0F) {
            rtb_Gain = 1.0F;
          }

          /* End of Switch: '<S43>/Switch2' */

          /* DotProduct: '<S43>/Dot Product' */
          rtb_P_f_idx_0 = rtb_Saturation_k * rtb_TmpSignalConversionAtMath_0 +
            rtb_P_f_idx_0 * rtb_AccToRate_c;

          /* Trigonometry: '<S43>/Acos' incorporates:
           *  DotProduct: '<S43>/Dot Product'
           */
          if (rtb_P_f_idx_0 > 1.0F) {
            rtb_P_f_idx_0 = 1.0F;
          } else {
            if (rtb_P_f_idx_0 < -1.0F) {
              rtb_P_f_idx_0 = -1.0F;
            }
          }

          /* Product: '<S43>/Multiply' incorporates:
           *  Trigonometry: '<S43>/Acos'
           */
          rtb_Gain *= acosf(rtb_P_f_idx_0);

          /* Saturate: '<S42>/Saturation' */
          if (rtb_Gain > 1.57079637F) {
            rtb_Gain = 1.57079637F;
          } else {
            if (rtb_Gain < -1.57079637F) {
              rtb_Gain = -1.57079637F;
            }
          }

          /* End of Saturate: '<S42>/Saturation' */

          /* Product: '<S42>/Divide' incorporates:
           *  Constant: '<S34>/L1'
           *  Constant: '<S42>/Constant'
           *  MinMax: '<S42>/Max'
           *  MinMax: '<S42>/Min'
           *  Product: '<S42>/Multiply1'
           *  Sqrt: '<S45>/Sqrt'
           *  Sum: '<S45>/Sum of Elements'
           *  Trigonometry: '<S42>/Sin'
           */
          FMS_B.Merge = arm_sin_f32(rtb_Gain) * rtb_Switch_f_idx_1 / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_AccToRate_d + rtb_Divide_aj[0]), 0.5F));

          /* Update for UnitDelay: '<S52>/Delay Input1'
           *
           * Block description for '<S52>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE = rtb_sign_u_est_C;

          /* Update for Delay: '<S38>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S38>/start_wp' */
          FMS_DW.icLoad_o = 0U;

          /* End of Outputs for SubSystem: '<S31>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S31>/Brake Control' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* SignalConversion: '<S33>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
           *  Constant: '<S33>/Brake Speed'
           */
          FMS_B.Merge = 0.0F;

          /* End of Outputs for SubSystem: '<S31>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S31>/Move Control' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S35>/Gain6' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          FMS_B.Merge = FMS_PARAM.MAX_R / FMS_PARAM.ACC2RATE *
            FMS_U.Pilot_Cmd.stick_roll;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S31>/Move Control' */
          break;
        }

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S60>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_AccToRate_d = 0.0F;
        } else {
          rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S60>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S30>/Gain'
         *  Gain: '<S31>/AccToRate'
         *  Gain: '<S60>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.05263162F * rtb_AccToRate_d * FMS_PARAM.MAX_VEL;
        FMS_Y.FMS_Out.r_cmd = FMS_PARAM.ACC2RATE * FMS_B.Merge;

        /* End of Outputs for SubSystem: '<S21>/Position' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S21>/Unknown' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

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
       *  SignalConversion: '<S23>/TmpHiddenBufferAtBus AssignmentInport1'
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
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* Saturate: '<S86>/Saturation' incorporates:
       *  Constant: '<S86>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       *  Sum: '<S86>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_AccToRate_d = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_AccToRate_d = 0.0F;
      } else {
        rtb_AccToRate_d = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S86>/Saturation' */
      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  Constant: '<S86>/Constant5'
       *  DataTypeConversion: '<S85>/Data Type Conversion'
       *  Gain: '<S86>/Gain4'
       *  Outport: '<Root>/FMS_Out'
       *  Sum: '<S86>/Add'
       */
      FMS_Y.FMS_Out.actuator_cmd[0] = (uint16_T)fmodf(floorf(500.0F *
        rtb_AccToRate_d + 1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S85>/Data Type Conversion1' incorporates:
       *  Bias: '<S85>/Bias1'
       *  Gain: '<S85>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_AccToRate_d = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_roll +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S85>/Data Type Conversion1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[1] = (uint16_T)(rtb_AccToRate_d < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_AccToRate_d : (int32_T)
        (uint16_T)rtb_AccToRate_d);
      for (i = 0; i < 14; i++) {
        FMS_Y.FMS_Out.actuator_cmd[i + 2] = 0U;
      }

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
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S107>/Constant'
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
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S21>/Position' */
  /* Start for SwitchCase: '<S31>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S15>/Arm' */
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
  /* SystemInitialize for IfAction SubSystem: '<S15>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Return' */
  /* InitializeConditions for Delay: '<S91>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S24>/Return' */
  /* End of SystemInitialize for SubSystem: '<S17>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Mission' */
  /* InitializeConditions for UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S22>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S17>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S32>/Motion State' */
  FMS_DW.temporalCounter_i1_o = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for IfAction SubSystem: '<S31>/Hold Control' */
  /* InitializeConditions for UnitDelay: '<S52>/Delay Input1'
   *
   * Block description for '<S52>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S38>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S38>/start_wp' */
  FMS_DW.icLoad_o = 1U;

  /* End of SystemInitialize for SubSystem: '<S31>/Hold Control' */

  /* SystemInitialize for Merge: '<S31>/Merge' */
  FMS_B.Merge = 0.0F;

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
