/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1975
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 15:43:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S62>/Motion State' */
#define FMS_IN_Hold                    ((uint8_T)1U)
#define FMS_IN_Move                    ((uint8_T)2U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
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
                                        *   '<S113>/L1'
                                        *   '<S113>/vel'
                                        *   '<S31>/Gain'
                                        *   '<S92>/L1'
                                        *   '<S92>/vel'
                                        *   '<S115>/AccToRate'
                                        *   '<S93>/AccToRate'
                                        *   '<S63>/L1'
                                        *   '<S63>/AccToRate'
                                        *   '<S64>/Gain6'
                                        */

struct_jgVLU9PsiazymsYzo6u6IH FMS_EXPORT = {
  10U,

  { 67, 97, 114, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S132>/Constant'
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
 *    '<S117>/NearbyRefWP'
 *    '<S95>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_k, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S121>/TmpSignal ConversionAt SFunction Inport2' */
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

  /* BusAssignment: '<S114>/Bus Assignment' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S114>/Constant2'
   *  SignalConversion: '<S114>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S114>/Bus Assignment' */
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
  /* RelationalOperator: '<S145>/Compare' incorporates:
   *  Abs: '<S134>/Abs'
   *  Constant: '<S145>/Constant'
   *  MinMax: '<S134>/Max'
   *  Sum: '<S134>/Sum'
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
      FMS_DW.is_SubMode = FMS_IN_Hold;
      FMS_B.state = VehicleState_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold:
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
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
          }

          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
          FMS_DW.is_SubMode = FMS_IN_Hold;
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
                  /* Sum: '<S135>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S135>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S136>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S136>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S136>/Multiply1' incorporates:
                   *  Product: '<S136>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S136>/Divide' incorporates:
                   *  Constant: '<S136>/Constant'
                   *  Constant: '<S136>/R'
                   *  Sqrt: '<S136>/Sqrt'
                   *  Sum: '<S136>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S136>/Product3' incorporates:
                   *  Constant: '<S136>/Constant1'
                   *  Product: '<S136>/Multiply1'
                   *  Sum: '<S136>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S136>/Multiply2' incorporates:
                   *  Trigonometry: '<S136>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S140>/Abs' incorporates:
                   *  Abs: '<S143>/Abs1'
                   *  Switch: '<S140>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S140>/Switch1' incorporates:
                   *  Abs: '<S140>/Abs'
                   *  Bias: '<S140>/Bias2'
                   *  Bias: '<S140>/Bias3'
                   *  Constant: '<S137>/Constant'
                   *  Constant: '<S137>/Constant1'
                   *  Constant: '<S142>/Constant'
                   *  Gain: '<S140>/Gain1'
                   *  Product: '<S140>/Multiply'
                   *  RelationalOperator: '<S142>/Compare'
                   *  Switch: '<S137>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S143>/Switch1' incorporates:
                     *  Bias: '<S143>/Bias2'
                     *  Bias: '<S143>/Bias3'
                     *  Constant: '<S143>/Constant'
                     *  Constant: '<S144>/Constant'
                     *  Math: '<S143>/Math Function'
                     *  RelationalOperator: '<S144>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S143>/Switch1' */

                    /* Signum: '<S140>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S140>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S137>/Sum' incorporates:
                   *  Sum: '<S135>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S135>/Multiply' incorporates:
                   *  Gain: '<S135>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S139>/Switch1' incorporates:
                   *  Abs: '<S139>/Abs1'
                   *  Bias: '<S139>/Bias2'
                   *  Bias: '<S139>/Bias3'
                   *  Constant: '<S139>/Constant'
                   *  Constant: '<S141>/Constant'
                   *  Math: '<S139>/Math Function'
                   *  RelationalOperator: '<S141>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S139>/Switch1' */

                  /* Product: '<S135>/Multiply' incorporates:
                   *  Gain: '<S135>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S135>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S138>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S138>/Sum2' incorporates:
                   *  Product: '<S138>/Multiply1'
                   *  Product: '<S138>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S138>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S138>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S138>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S133>/Data Type Conversion' incorporates:
                   *  Gain: '<S135>/Gain'
                   *  Sum: '<S135>/Sum1'
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
  real32_T rtb_Saturation_gm;
  real32_T rtb_Divide_g[2];
  real32_T rtb_MathFunction_k[2];
  real32_T rtb_AccToRate_c;
  real32_T rtb_Switch_h[3];
  real32_T rtb_Gain;
  real32_T rtb_Gain_n;
  boolean_T rtb_Compare_m;
  MotionState rtb_state;
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
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Gain;
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
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_Compare_m = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_Compare_m) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_Compare_m;
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
        /* Disable for SwitchCase: '<S61>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
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
      rtb_Gain = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
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
      rtb_Gain = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
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
          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
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
       *  Product: '<S130>/Divide'
       *  Sum: '<S118>/Subtract'
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
           *  ActionPort: '<S113>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S116>/Delay'
           */
          FMS_DW.icLoad_c = 1U;

          /* End of InitializeConditions for SubSystem: '<S24>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S113>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S127>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S127>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S125>/Sum of Elements'
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S127>/Math Function1' incorporates:
         *  Sum: '<S127>/Sum of Elements'
         *
         * About '<S127>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S127>/Math Function1' */

        /* Switch: '<S127>/Switch' incorporates:
         *  Constant: '<S127>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S127>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Saturation_gm > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_Saturation_gm;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S127>/Switch' */

        /* Product: '<S127>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S130>/Sum of Elements' incorporates:
         *  Math: '<S130>/Math Function'
         *  SignalConversion: '<S130>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
          rtb_Divide_g[0];

        /* Math: '<S130>/Math Function1' incorporates:
         *  Sum: '<S130>/Sum of Elements'
         *
         * About '<S130>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S130>/Math Function1' */

        /* Switch: '<S130>/Switch' incorporates:
         *  Constant: '<S130>/Constant'
         *  Product: '<S130>/Product'
         */
        if (rtb_Saturation_gm > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_g[1];
          rtb_Switch_f_idx_1 = rtb_Divide_g[0];
          rtb_Switch_f_idx_2 = rtb_Saturation_gm;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S130>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S117>/NearbyRefWP' incorporates:
         *  Constant: '<S113>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_h[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_g, &rtb_AccToRate_c);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Delay: '<S116>/Delay' incorporates:
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
        /* MATLAB Function: '<S117>/SearchL1RefWP' incorporates:
         *  Constant: '<S113>/L1'
         *  Delay: '<S116>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S117>/OutRegionRegWP'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];
        rtb_Gain_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        A = rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_Gain_n * rtb_Gain_n;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_gm = (rtb_P_i_idx_0 * (FMS_DW.Delay_DSTATE[0] -
          FMS_U.INS_Out.x_R) + rtb_Gain_n * (FMS_DW.Delay_DSTATE[1] -
          FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation_gm * rtb_Saturation_gm - (((((FMS_U.INS_Out.x_R *
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
          D = (-rtb_Saturation_gm + u1_tmp) / (2.0F * A);
          rtb_Saturation_gm = (-rtb_Saturation_gm - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Saturation_gm >= 0.0F) &&
              (rtb_Saturation_gm <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, rtb_Saturation_gm);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((rtb_Saturation_gm >= 0.0F) && (rtb_Saturation_gm <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = rtb_Saturation_gm;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation_gm / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_P_f_idx_0 = rtb_P_i_idx_0 * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE[0];
          rtb_P_f_idx_1 = rtb_Gain_n * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE[1];
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S117>/OutRegionRegWP' incorporates:
         *  Delay: '<S116>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_gm = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) *
                             rtb_Gain_n + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE[0]) * rtb_P_i_idx_0) / (rtb_P_i_idx_0 *
          rtb_P_i_idx_0 + rtb_Gain_n * rtb_Gain_n);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Compare_m = (rtb_Saturation_gm <= 0.0F);
        u = (rtb_Saturation_gm >= 1.0F);
        if (rtb_Compare_m) {
          rtb_P_i_idx_0 = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          rtb_P_i_idx_0 = rtb_Saturation_gm * rtb_P_i_idx_0 +
            FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S117>/Switch1' incorporates:
         *  Constant: '<S120>/Constant'
         *  RelationalOperator: '<S120>/Compare'
         */
        if (rtb_AccToRate_c <= 0.0F) {
          /* Switch: '<S117>/Switch' incorporates:
           *  Constant: '<S119>/Constant'
           *  MATLAB Function: '<S117>/SearchL1RefWP'
           *  RelationalOperator: '<S119>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_Divide_g[0] = rtb_P_f_idx_0;
            rtb_Divide_g[1] = rtb_P_f_idx_1;
          } else {
            rtb_Divide_g[0] = rtb_P_i_idx_0;

            /* MATLAB Function: '<S117>/OutRegionRegWP' incorporates:
             *  Delay: '<S116>/Delay'
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_m) {
              rtb_Divide_g[1] = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_g[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              rtb_Divide_g[1] = rtb_Saturation_gm * rtb_Gain_n +
                FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S117>/Switch' */
        }

        /* End of Switch: '<S117>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S118>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Gain_n = rtb_Divide_g[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S128>/Math Function' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Gain_n * rtb_Gain_n;
        rtb_Divide_g[0] = rtb_Gain_n;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S118>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Gain_n = rtb_Divide_g[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S128>/Math Function' incorporates:
         *  Math: '<S126>/Square'
         */
        rtb_P_i_idx_0 = rtb_Gain_n * rtb_Gain_n;

        /* Sum: '<S128>/Sum of Elements' incorporates:
         *  Math: '<S128>/Math Function'
         */
        rtb_Saturation_gm = rtb_P_i_idx_0 + rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S128>/Math Function1' incorporates:
         *  Sum: '<S128>/Sum of Elements'
         *
         * About '<S128>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_gm < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_Saturation_gm));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_Saturation_gm);
        }

        /* End of Math: '<S128>/Math Function1' */

        /* Switch: '<S128>/Switch' incorporates:
         *  Constant: '<S128>/Constant'
         *  Product: '<S128>/Product'
         */
        if (rtb_Saturation_gm > 0.0F) {
          rtb_Switch_h[0] = rtb_Divide_g[0];
          rtb_Switch_h[1] = rtb_Gain_n;
          rtb_Switch_h[2] = rtb_Saturation_gm;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S128>/Switch' */

        /* Product: '<S128>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_h[0] / rtb_Switch_h[2];
        rtb_P_f_idx_0 = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Sum: '<S131>/Sum of Elements' incorporates:
         *  Math: '<S131>/Math Function'
         *  SignalConversion: '<S131>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_gm = rtb_P_f_idx_0 * rtb_P_f_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S131>/Math Function1' incorporates:
         *  Sum: '<S131>/Sum of Elements'
         *
         * About '<S131>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_gm < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_Saturation_gm));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_Saturation_gm);
        }

        /* End of Math: '<S131>/Math Function1' */

        /* Switch: '<S131>/Switch' incorporates:
         *  Constant: '<S131>/Constant'
         *  Product: '<S131>/Product'
         */
        if (rtb_Saturation_gm > 0.0F) {
          rtb_Switch_h[0] = rtb_P_f_idx_0;
          rtb_Switch_h[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_h[2] = rtb_Saturation_gm;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S131>/Switch' */

        /* Product: '<S131>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_h[0] / rtb_Switch_h[2];

        /* Math: '<S126>/Square' */
        rtb_MathFunction_k[0] = rtb_Divide_g[0] * rtb_Divide_g[0];
        rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S131>/Divide' incorporates:
         *  Product: '<S130>/Divide'
         */
        rtb_P_f_idx_0 = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Product: '<S130>/Divide' */
        rtb_Gain_n = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sqrt: '<S125>/Sqrt' */
        rtb_Saturation_gm = sqrtf(rtb_Gain);

        /* Gain: '<S118>/Gain' incorporates:
         *  Math: '<S118>/Square'
         */
        rtb_Gain = rtb_Saturation_gm * rtb_Saturation_gm * 2.0F;

        /* Sum: '<S129>/Subtract' incorporates:
         *  Product: '<S129>/Multiply'
         *  Product: '<S129>/Multiply1'
         */
        rtb_Saturation_gm = rtb_TmpSignalConversionAtMath_0 * rtb_Gain_n -
          rtb_P_f_idx_0 * rtb_Divide_g[0];

        /* Signum: '<S124>/Sign1' */
        if (rtb_Saturation_gm < 0.0F) {
          rtb_Saturation_gm = -1.0F;
        } else {
          if (rtb_Saturation_gm > 0.0F) {
            rtb_Saturation_gm = 1.0F;
          }
        }

        /* End of Signum: '<S124>/Sign1' */

        /* Switch: '<S124>/Switch2' incorporates:
         *  Constant: '<S124>/Constant4'
         */
        if (rtb_Saturation_gm == 0.0F) {
          rtb_Saturation_gm = 1.0F;
        }

        /* End of Switch: '<S124>/Switch2' */

        /* DotProduct: '<S124>/Dot Product' */
        rtb_Gain_n = rtb_Divide_g[0] * rtb_TmpSignalConversionAtMath_0 +
          rtb_Gain_n * rtb_P_f_idx_0;

        /* Trigonometry: '<S124>/Acos' incorporates:
         *  DotProduct: '<S124>/Dot Product'
         */
        if (rtb_Gain_n > 1.0F) {
          rtb_Gain_n = 1.0F;
        } else {
          if (rtb_Gain_n < -1.0F) {
            rtb_Gain_n = -1.0F;
          }
        }

        /* Product: '<S124>/Multiply' incorporates:
         *  Trigonometry: '<S124>/Acos'
         */
        rtb_Saturation_gm *= acosf(rtb_Gain_n);

        /* Saturate: '<S118>/Saturation' */
        if (rtb_Saturation_gm > 1.57079637F) {
          rtb_Saturation_gm = 1.57079637F;
        } else {
          if (rtb_Saturation_gm < -1.57079637F) {
            rtb_Saturation_gm = -1.57079637F;
          }
        }

        /* End of Saturate: '<S118>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S113>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S113>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S113>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S113>/L1'
         *  Constant: '<S113>/vel'
         *  Constant: '<S118>/Constant'
         *  Gain: '<S115>/AccToRate'
         *  MinMax: '<S118>/Max'
         *  MinMax: '<S118>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S118>/Divide'
         *  Product: '<S118>/Multiply1'
         *  Sqrt: '<S126>/Sqrt'
         *  Sum: '<S126>/Sum of Elements'
         *  Trigonometry: '<S118>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = arm_sin_f32(rtb_Saturation_gm) * rtb_Gain / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_P_i_idx_0 + rtb_MathFunction_k[0]),
            0.5F)) * FMS_PARAM.ACC2RATE;

        /* Update for Delay: '<S116>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S112>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S112>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S112>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S112>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S112>/Constant3'
         *  Constant: '<S112>/Constant4'
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
         *  ActionPort: '<S114>/Action Port'
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
       *  RelationalOperator: '<S91>/FixPt Relational Operator'
       *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S91>/Delay Input1'
       *
       * Block description for '<S91>/Delay Input1':
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
         *  ActionPort: '<S89>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S89>/Bus Assignment'
         *  Constant: '<S89>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S89>/Bus Assignment' incorporates:
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
           *  ActionPort: '<S88>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  UnitDelay: '<S91>/Delay Input1'
           *
           * Block description for '<S91>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S22>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S88>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S92>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Sum: '<S105>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S105>/Math Function'
         *  RelationalOperator: '<S91>/FixPt Relational Operator'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S91>/Delay Input1'
         *
         * Block description for '<S91>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S105>/Math Function1' incorporates:
         *  Sum: '<S105>/Sum of Elements'
         *
         * About '<S105>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S105>/Math Function1' */

        /* Switch: '<S105>/Switch' incorporates:
         *  Constant: '<S105>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S105>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S105>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S95>/NearbyRefWP' incorporates:
         *  Constant: '<S92>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_h[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_MathFunction_k, &rtb_Gain);

        /* MATLAB Function: '<S95>/SearchL1RefWP' incorporates:
         *  Constant: '<S92>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S95>/OutRegionRegWP'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_Gain_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        A = rtb_P_i_idx_0 * rtb_P_i_idx_0 + rtb_Gain_n * rtb_Gain_n;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_gm = (rtb_P_i_idx_0 * (FMS_B.Cmd_In.cur_waypoint[0] -
          FMS_U.INS_Out.x_R) + rtb_Gain_n * (FMS_B.Cmd_In.cur_waypoint[1] -
          FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation_gm * rtb_Saturation_gm - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_B.Cmd_In.cur_waypoint[0] * FMS_B.Cmd_In.cur_waypoint[0]) +
          FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint[1]) -
          (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0] + FMS_U.INS_Out.y_R *
           FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) *
          (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_Divide_g[0] = 0.0F;
        rtb_Divide_g[1] = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation_gm + u1_tmp) / (2.0F * A);
          rtb_Saturation_gm = (-rtb_Saturation_gm - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Saturation_gm >= 0.0F) &&
              (rtb_Saturation_gm <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, rtb_Saturation_gm);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((rtb_Saturation_gm >= 0.0F) && (rtb_Saturation_gm <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = rtb_Saturation_gm;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation_gm / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Divide_g[0] = rtb_P_i_idx_0 * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_g[1] = rtb_Gain_n * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S95>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_gm = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                             rtb_Gain_n + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_P_i_idx_0) / (rtb_P_i_idx_0 *
          rtb_P_i_idx_0 + rtb_Gain_n * rtb_Gain_n);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Compare_m = (rtb_Saturation_gm <= 0.0F);
        u = (rtb_Saturation_gm >= 1.0F);
        if (rtb_Compare_m) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Saturation_gm * rtb_P_i_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Switch: '<S95>/Switch1' incorporates:
         *  Constant: '<S98>/Constant'
         *  RelationalOperator: '<S98>/Compare'
         */
        if (rtb_Gain <= 0.0F) {
          /* Switch: '<S95>/Switch' incorporates:
           *  Constant: '<S97>/Constant'
           *  MATLAB Function: '<S95>/SearchL1RefWP'
           *  RelationalOperator: '<S97>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_MathFunction_k[0] = rtb_Divide_g[0];
            rtb_MathFunction_k[1] = rtb_Divide_g[1];
          } else {
            rtb_MathFunction_k[0] = rtb_P_f_idx_0;

            /* MATLAB Function: '<S95>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_m) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_MathFunction_k[1] = rtb_Saturation_gm * rtb_Gain_n +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }
          }

          /* End of Switch: '<S95>/Switch' */
        }

        /* End of Switch: '<S95>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S96>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_k[0] -
          FMS_U.INS_Out.x_R;
        rtb_P_f_idx_0 = rtb_MathFunction_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S106>/Math Function' incorporates:
         *  Math: '<S104>/Square'
         */
        rtb_Gain_n = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;
        rtb_Gain = rtb_P_f_idx_0 * rtb_P_f_idx_0;

        /* Sum: '<S106>/Sum of Elements' incorporates:
         *  Math: '<S106>/Math Function'
         */
        rtb_P_i_idx_0 = rtb_Gain_n + rtb_Gain;

        /* Math: '<S106>/Math Function1' incorporates:
         *  Sum: '<S106>/Sum of Elements'
         *
         * About '<S106>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S106>/Math Function1' */

        /* Switch: '<S106>/Switch' incorporates:
         *  Constant: '<S106>/Constant'
         *  Product: '<S106>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_h[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_h[1] = rtb_P_f_idx_0;
          rtb_Switch_h[2] = rtb_P_i_idx_0;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S106>/Switch' */

        /* Product: '<S105>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S108>/Sum of Elements' incorporates:
         *  Math: '<S108>/Math Function'
         *  SignalConversion: '<S108>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
          rtb_Divide_g[0];

        /* Math: '<S108>/Math Function1' incorporates:
         *  Sum: '<S108>/Sum of Elements'
         *
         * About '<S108>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S108>/Math Function1' */

        /* Switch: '<S108>/Switch' incorporates:
         *  Constant: '<S108>/Constant'
         *  Product: '<S108>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_g[1];
          rtb_Switch_f_idx_1 = rtb_Divide_g[0];
          rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S108>/Switch' */

        /* Product: '<S106>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_h[0] / rtb_Switch_h[2];
        rtb_Divide_g[1] = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Sum: '<S109>/Sum of Elements' incorporates:
         *  Math: '<S109>/Math Function'
         *  SignalConversion: '<S109>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_P_i_idx_0 = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
          rtb_Divide_g[0];

        /* Math: '<S109>/Math Function1' incorporates:
         *  Sum: '<S109>/Sum of Elements'
         *
         * About '<S109>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
        } else {
          rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
        }

        /* End of Math: '<S109>/Math Function1' */

        /* Switch: '<S109>/Switch' incorporates:
         *  Constant: '<S109>/Constant'
         *  Product: '<S109>/Product'
         */
        if (rtb_P_i_idx_0 > 0.0F) {
          rtb_Switch_h[0] = rtb_Divide_g[1];
          rtb_Switch_h[1] = rtb_Divide_g[0];
          rtb_Switch_h[2] = rtb_P_i_idx_0;
        } else {
          rtb_Switch_h[0] = 0.0F;
          rtb_Switch_h[1] = 0.0F;
          rtb_Switch_h[2] = 1.0F;
        }

        /* End of Switch: '<S109>/Switch' */

        /* Product: '<S109>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_h[0] / rtb_Switch_h[2];

        /* Product: '<S108>/Divide' */
        rtb_MathFunction_k[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S109>/Divide' */
        rtb_Divide_g[1] = rtb_Switch_h[1] / rtb_Switch_h[2];

        /* Product: '<S108>/Divide' */
        rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S103>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S103>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S103>/Sum of Elements'
         */
        rtb_P_i_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Gain: '<S96>/Gain' incorporates:
         *  Math: '<S96>/Square'
         */
        rtb_Switch_f_idx_1 = rtb_P_i_idx_0 * rtb_P_i_idx_0 * 2.0F;

        /* Sum: '<S107>/Subtract' incorporates:
         *  Product: '<S107>/Multiply'
         *  Product: '<S107>/Multiply1'
         */
        rtb_P_i_idx_0 = rtb_Divide_g[0] * rtb_MathFunction_k[1] - rtb_Divide_g[1]
          * rtb_MathFunction_k[0];

        /* Signum: '<S102>/Sign1' */
        if (rtb_P_i_idx_0 < 0.0F) {
          rtb_P_i_idx_0 = -1.0F;
        } else {
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_P_i_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S102>/Sign1' */

        /* Switch: '<S102>/Switch2' incorporates:
         *  Constant: '<S102>/Constant4'
         */
        if (rtb_P_i_idx_0 == 0.0F) {
          rtb_P_i_idx_0 = 1.0F;
        }

        /* End of Switch: '<S102>/Switch2' */

        /* DotProduct: '<S102>/Dot Product' */
        rtb_Switch_f_idx_2 = rtb_MathFunction_k[0] * rtb_Divide_g[0] +
          rtb_MathFunction_k[1] * rtb_Divide_g[1];

        /* Trigonometry: '<S102>/Acos' incorporates:
         *  DotProduct: '<S102>/Dot Product'
         */
        if (rtb_Switch_f_idx_2 > 1.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_f_idx_2 < -1.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          }
        }

        /* Product: '<S102>/Multiply' incorporates:
         *  Trigonometry: '<S102>/Acos'
         */
        rtb_P_i_idx_0 *= acosf(rtb_Switch_f_idx_2);

        /* Saturate: '<S96>/Saturation' */
        if (rtb_P_i_idx_0 > 1.57079637F) {
          rtb_P_i_idx_0 = 1.57079637F;
        } else {
          if (rtb_P_i_idx_0 < -1.57079637F) {
            rtb_P_i_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S96>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S92>/Bus Assignment'
         *  Constant: '<S92>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S92>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S92>/L1'
         *  Constant: '<S92>/vel'
         *  Constant: '<S96>/Constant'
         *  Gain: '<S93>/AccToRate'
         *  MinMax: '<S96>/Max'
         *  MinMax: '<S96>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S96>/Divide'
         *  Product: '<S96>/Multiply1'
         *  Sqrt: '<S104>/Sqrt'
         *  Sum: '<S104>/Sum of Elements'
         *  Trigonometry: '<S96>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = arm_sin_f32(rtb_P_i_idx_0) * rtb_Switch_f_idx_1 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_Gain_n), 0.5F)) *
          FMS_PARAM.ACC2RATE;

        /* End of Outputs for SubSystem: '<S88>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S91>/Delay Input1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S91>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S90>/Action Port'
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
        /* Disable for SwitchCase: '<S61>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
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
        /* DeadZone: '<S86>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S86>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S27>/Gain'
         *  Gain: '<S86>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S87>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - -0.05F;
        }

        /* End of DeadZone: '<S87>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S27>/Gain1'
         *  Gain: '<S87>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_R;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S62>/Motion State'
           */
          FMS_DW.is_active_c10_FMS = 0U;
          FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S85>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S85>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Gain: '<S31>/Gain' incorporates:
         *  Gain: '<S85>/Gain'
         */
        rtb_Gain_n = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* RelationalOperator: '<S83>/Compare' incorporates:
         *  Abs: '<S62>/Abs1'
         *  Constant: '<S83>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Compare_m = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > 0.05F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S62>/Motion State' */
        if (FMS_DW.is_active_c10_FMS == 0U) {
          FMS_DW.is_active_c10_FMS = 1U;
          FMS_DW.is_c10_FMS = FMS_IN_Move;
          rtb_state = MotionState_Move;
        } else if (FMS_DW.is_c10_FMS == FMS_IN_Hold) {
          rtb_state = MotionState_Hold;
          if (rtb_Compare_m) {
            FMS_DW.is_c10_FMS = FMS_IN_Move;
            rtb_state = MotionState_Move;
          }
        } else {
          rtb_state = MotionState_Move;
          if (!rtb_Compare_m) {
            FMS_DW.is_c10_FMS = FMS_IN_Hold;
            rtb_state = MotionState_Hold;
          }
        }

        /* End of Chart: '<S62>/Motion State' */

        /* SwitchCase: '<S61>/Switch Case' incorporates:
         *  Math: '<S74>/Square'
         *  Product: '<S67>/Multiply'
         *  Product: '<S81>/Divide'
         *  Sum: '<S66>/Subtract'
         *  Switch: '<S65>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        switch (rtb_state) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 0;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_g) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S61>/Hold Control' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S61>/Switch Case' incorporates:
             *  Delay: '<S67>/start_vel'
             *  Delay: '<S67>/start_wp'
             *  UnitDelay: '<S80>/Delay Input1'
             *
             * Block description for '<S80>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.DelayInput1_DSTATE = 0.0F;
            FMS_DW.icLoad_f = 1U;

            /* End of InitializeConditions for SubSystem: '<S61>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S61>/Hold Control' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S75>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S75>/Math Function'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S75>/Math Function1' incorporates:
           *  Sum: '<S75>/Sum of Elements'
           *
           * About '<S75>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S75>/Math Function1' */

          /* Switch: '<S75>/Switch' incorporates:
           *  Constant: '<S75>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S75>/Product'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_h[0] = FMS_U.INS_Out.vn;
            rtb_Switch_h[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_h[2] = rtb_P_i_idx_0;
          } else {
            rtb_Switch_h[0] = 0.0F;
            rtb_Switch_h[1] = 0.0F;
            rtb_Switch_h[2] = 1.0F;
          }

          /* End of Switch: '<S75>/Switch' */

          /* Switch: '<S82>/Switch' incorporates:
           *  Constant: '<S82>/Constant'
           *  Constant: '<S82>/Constant1'
           */
          if (rtb_Gain_n >= 0.0F) {
            i = 1;
          } else {
            i = -1;
          }

          /* End of Switch: '<S82>/Switch' */

          /* Delay: '<S67>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Trigonometry: '<S67>/Cos'
           *  Trigonometry: '<S67>/Cos1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = arm_cos_f32(FMS_U.INS_Out.psi);
            FMS_DW.start_vel_DSTATE[1] = arm_sin_f32(FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Product: '<S67>/Multiply' incorporates:
           *  Delay: '<S67>/start_vel'
           */
          rtb_Switch_f_idx_1 = FMS_DW.start_vel_DSTATE[0] * (real32_T)i;

          /* Math: '<S81>/Math Function' */
          rtb_Divide_g[0] = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1;

          /* Product: '<S67>/Multiply' incorporates:
           *  Delay: '<S67>/start_vel'
           */
          rtb_Switch_f_idx_1 = FMS_DW.start_vel_DSTATE[1] * (real32_T)i;

          /* Sum: '<S81>/Sum of Elements' incorporates:
           *  Math: '<S81>/Math Function'
           */
          rtb_Gain = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1 + rtb_Divide_g[0];

          /* Math: '<S81>/Math Function1' incorporates:
           *  Sum: '<S81>/Sum of Elements'
           *
           * About '<S81>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S81>/Math Function1' */

          /* Switch: '<S81>/Switch' incorporates:
           *  Constant: '<S81>/Constant'
           *  Product: '<S81>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_TmpSignalConversionAtMath_0;
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S81>/Switch' */

          /* Product: '<S75>/Divide' */
          rtb_Divide_g[0] = rtb_Switch_h[0] / rtb_Switch_h[2];
          rtb_Divide_g[1] = rtb_Switch_h[1] / rtb_Switch_h[2];

          /* Sum: '<S78>/Sum of Elements' incorporates:
           *  Math: '<S78>/Math Function'
           *  SignalConversion: '<S78>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Gain = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
            rtb_Divide_g[0];

          /* Math: '<S78>/Math Function1' incorporates:
           *  Sum: '<S78>/Sum of Elements'
           *
           * About '<S78>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S78>/Math Function1' */

          /* Switch: '<S78>/Switch' incorporates:
           *  Constant: '<S78>/Constant'
           *  Product: '<S78>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_h[0] = rtb_Divide_g[1];
            rtb_Switch_h[1] = rtb_Divide_g[0];
            rtb_Switch_h[2] = rtb_P_i_idx_0;
          } else {
            rtb_Switch_h[0] = 0.0F;
            rtb_Switch_h[1] = 0.0F;
            rtb_Switch_h[2] = 1.0F;
          }

          /* End of Switch: '<S78>/Switch' */

          /* RelationalOperator: '<S80>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S80>/Delay Input1'
           *
           * Block description for '<S80>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_m = (i != FMS_DW.DelayInput1_DSTATE);

          /* Delay: '<S67>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_Compare_m && (FMS_PrevZCX.start_wp_Reset_ZCE != POS_ZCSIG)) {
            FMS_DW.icLoad_f = 1U;
          }

          FMS_PrevZCX.start_wp_Reset_ZCE = rtb_Compare_m;
          if (FMS_DW.icLoad_f != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S65>/SearchL1RefWP' incorporates:
           *  Delay: '<S67>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_DW.start_wp_DSTATE[0] -
            FMS_U.INS_Out.x_R;
          rtb_P_f_idx_0 = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S81>/Divide' */
          rtb_Gain = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S65>/SearchL1RefWP' */
          rtb_Switch_f_idx_0 = rtb_Gain * rtb_TmpSignalConversionAtMath_0;
          rtb_P_i_idx_0 = rtb_Gain;

          /* Product: '<S81>/Divide' */
          rtb_Gain = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S65>/SearchL1RefWP' incorporates:
           *  Constant: '<S63>/L1'
           *  Delay: '<S67>/start_wp'
           */
          rtb_Switch_f_idx_0 += rtb_Gain * rtb_P_f_idx_0;
          rtb_Saturation_gm = 2.0F * rtb_Switch_f_idx_0;
          rtb_MathFunction_k[0] = 0.0F;
          rtb_MathFunction_k[1] = 0.0F;
          D = rtb_Saturation_gm * rtb_Saturation_gm -
            ((rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0
              + rtb_P_f_idx_0 * rtb_P_f_idx_0) - FMS_PARAM.L1 * FMS_PARAM.L1) *
            4.0F;
          rtb_Switch_f_idx_1 = -1.0F;
          if (D > 0.0F) {
            rtb_Switch_f_idx_1 = sqrtf(D);
            rtb_Switch_f_idx_1 = fmaxf((-rtb_Saturation_gm + rtb_Switch_f_idx_1)
              / 2.0F, (-rtb_Saturation_gm - rtb_Switch_f_idx_1) / 2.0F);
            rtb_MathFunction_k[0] = rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 * rtb_Gain +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (D == 0.0F) {
              rtb_Switch_f_idx_1 = -rtb_Saturation_gm / 2.0F;
              rtb_MathFunction_k[0] = rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 * rtb_Gain +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S68>/Compare' incorporates:
           *  Constant: '<S68>/Constant'
           *  MATLAB Function: '<S65>/SearchL1RefWP'
           */
          rtb_Compare_m = (rtb_Switch_f_idx_1 > 0.0F);

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S65>/OutRegionRefWP' incorporates:
           *  Delay: '<S67>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_P_i_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
            rtb_Gain;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_2 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Switch_f_idx_1 * rtb_P_i_idx_0 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > 1.29246971E-26F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_0;
          } else {
            rtb_Saturation_gm = rtb_Switch_f_idx_0 / 1.29246971E-26F;
            rtb_TmpSignalConversionAtMath_0 = rtb_Saturation_gm *
              rtb_Saturation_gm;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_f_idx_0 = fabsf((rtb_Switch_f_idx_1 * rtb_Gain +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Switch_f_idx_0 > rtb_Switch_f_idx_2) {
            rtb_Saturation_gm = rtb_Switch_f_idx_2 / rtb_Switch_f_idx_0;
            rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_0 *
              rtb_Saturation_gm * rtb_Saturation_gm + 1.0F;
            rtb_Switch_f_idx_2 = rtb_Switch_f_idx_0;
          } else {
            rtb_Saturation_gm = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
            rtb_TmpSignalConversionAtMath_0 += rtb_Saturation_gm *
              rtb_Saturation_gm;
          }

          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_2 * sqrtf
            (rtb_TmpSignalConversionAtMath_0);
          rtb_Switch_f_idx_2 = rtb_TmpSignalConversionAtMath_0 * 0.577350259F +
            rtb_Switch_f_idx_1;

          /* Switch: '<S65>/Switch' incorporates:
           *  Delay: '<S67>/start_wp'
           *  MATLAB Function: '<S65>/OutRegionRefWP'
           */
          if (rtb_Compare_m) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[0];
          } else {
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2 * rtb_P_i_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S66>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S76>/Math Function' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 *
            rtb_Switch_f_idx_1;
          rtb_MathFunction_k[0] = rtb_Switch_f_idx_1;

          /* Switch: '<S65>/Switch' incorporates:
           *  Delay: '<S67>/start_wp'
           *  MATLAB Function: '<S65>/OutRegionRefWP'
           *  Sum: '<S66>/Subtract'
           */
          if (rtb_Compare_m) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[1];
          } else {
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2 * rtb_Gain +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S66>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S76>/Math Function' incorporates:
           *  Math: '<S74>/Square'
           */
          rtb_Gain = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

          /* Sum: '<S76>/Sum of Elements' incorporates:
           *  Math: '<S76>/Math Function'
           */
          rtb_P_i_idx_0 = rtb_Gain + rtb_TmpSignalConversionAtMath_0;

          /* Math: '<S76>/Math Function1' incorporates:
           *  Sum: '<S76>/Sum of Elements'
           *
           * About '<S76>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
          }

          /* End of Math: '<S76>/Math Function1' */

          /* Switch: '<S76>/Switch' incorporates:
           *  Constant: '<S76>/Constant'
           *  Product: '<S76>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_MathFunction_k[0];
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S76>/Switch' */

          /* Product: '<S76>/Divide' */
          rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S79>/Sum of Elements' incorporates:
           *  Math: '<S79>/Math Function'
           *  SignalConversion: '<S79>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_P_i_idx_0 = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
            rtb_Divide_g[0];

          /* Math: '<S79>/Math Function1' incorporates:
           *  Sum: '<S79>/Sum of Elements'
           *
           * About '<S79>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -sqrtf(fabsf(rtb_P_i_idx_0));
          } else {
            rtb_P_i_idx_0 = sqrtf(rtb_P_i_idx_0);
          }

          /* End of Math: '<S79>/Math Function1' */

          /* Switch: '<S79>/Switch' incorporates:
           *  Constant: '<S79>/Constant'
           *  Product: '<S79>/Product'
           */
          if (rtb_P_i_idx_0 > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_g[1];
            rtb_Switch_f_idx_1 = rtb_Divide_g[0];
            rtb_Switch_f_idx_2 = rtb_P_i_idx_0;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S79>/Switch' */

          /* Product: '<S79>/Divide' */
          rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Product: '<S78>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_h[0] / rtb_Switch_h[2];
          rtb_MathFunction_k[0] *= rtb_MathFunction_k[0];

          /* Product: '<S79>/Divide' incorporates:
           *  Math: '<S74>/Square'
           */
          rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Product: '<S78>/Divide' */
          rtb_P_f_idx_0 = rtb_Switch_h[1] / rtb_Switch_h[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sqrt: '<S73>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S73>/Square'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S73>/Sum of Elements'
           */
          rtb_P_i_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                                FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S71>/Square' */
          rtb_Switch_f_idx_1 = rtb_P_i_idx_0 * rtb_P_i_idx_0;

          /* Sum: '<S77>/Subtract' incorporates:
           *  Product: '<S77>/Multiply'
           *  Product: '<S77>/Multiply1'
           */
          rtb_P_i_idx_0 = rtb_Divide_g[0] * rtb_P_f_idx_0 - rtb_Divide_g[1] *
            rtb_TmpSignalConversionAtMath_0;

          /* Signum: '<S72>/Sign1' */
          if (rtb_P_i_idx_0 < 0.0F) {
            rtb_P_i_idx_0 = -1.0F;
          } else {
            if (rtb_P_i_idx_0 > 0.0F) {
              rtb_P_i_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S72>/Sign1' */

          /* Switch: '<S72>/Switch2' incorporates:
           *  Constant: '<S72>/Constant4'
           */
          if (rtb_P_i_idx_0 == 0.0F) {
            rtb_P_i_idx_0 = 1.0F;
          }

          /* End of Switch: '<S72>/Switch2' */

          /* DotProduct: '<S72>/Dot Product' */
          rtb_Switch_f_idx_2 = rtb_TmpSignalConversionAtMath_0 * rtb_Divide_g[0]
            + rtb_P_f_idx_0 * rtb_Divide_g[1];

          /* Trigonometry: '<S72>/Acos' incorporates:
           *  DotProduct: '<S72>/Dot Product'
           */
          if (rtb_Switch_f_idx_2 > 1.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_2 < -1.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            }
          }

          /* Product: '<S72>/Multiply' incorporates:
           *  Trigonometry: '<S72>/Acos'
           */
          rtb_P_i_idx_0 *= acosf(rtb_Switch_f_idx_2);

          /* Saturate: '<S71>/Saturation' */
          if (rtb_P_i_idx_0 > 1.57079637F) {
            rtb_P_i_idx_0 = 1.57079637F;
          } else {
            if (rtb_P_i_idx_0 < -1.57079637F) {
              rtb_P_i_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S71>/Saturation' */

          /* Gain: '<S63>/AccToRate' incorporates:
           *  Constant: '<S63>/L1'
           *  Constant: '<S71>/Constant'
           *  Gain: '<S71>/Gain'
           *  MinMax: '<S71>/Max'
           *  MinMax: '<S71>/Min'
           *  Product: '<S71>/Divide'
           *  Product: '<S71>/Multiply1'
           *  Sqrt: '<S74>/Sqrt'
           *  Sum: '<S74>/Sum of Elements'
           *  Trigonometry: '<S71>/Sin'
           */
          FMS_B.Merge = 2.0F * rtb_Switch_f_idx_1 * arm_sin_f32(rtb_P_i_idx_0) /
            fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_MathFunction_k[0]),
                   0.5F)) * FMS_PARAM.ACC2RATE;

          /* Update for Delay: '<S67>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for UnitDelay: '<S80>/Delay Input1'
           *
           * Block description for '<S80>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE = (real32_T)i;

          /* Update for Delay: '<S67>/start_wp' */
          FMS_DW.icLoad_f = 0U;

          /* End of Outputs for SubSystem: '<S61>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S61>/Move Control' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S64>/Gain6' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          FMS_B.Merge = FMS_PARAM.MAX_R * FMS_U.Pilot_Cmd.stick_roll;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S61>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S61>/Switch Case' */

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
        FMS_Y.FMS_Out.u_cmd = rtb_Gain_n;
        FMS_Y.FMS_Out.r_cmd = FMS_B.Merge;

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
      /* Saturate: '<S111>/Saturation' incorporates:
       *  Constant: '<S111>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       *  Sum: '<S111>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_Gain = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Gain = 0.0F;
      } else {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S111>/Saturation' */
      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  Constant: '<S111>/Constant5'
       *  DataTypeConversion: '<S110>/Data Type Conversion'
       *  Gain: '<S111>/Gain4'
       *  Outport: '<Root>/FMS_Out'
       *  Sum: '<S111>/Add'
       */
      FMS_Y.FMS_Out.actuator_cmd[0] = (uint16_T)fmodf(floorf(500.0F * rtb_Gain +
        1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S110>/Data Type Conversion1' incorporates:
       *  Bias: '<S110>/Bias1'
       *  Gain: '<S110>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_Gain = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_roll + 1500.0F),
                       65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S110>/Data Type Conversion1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[1] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
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
   *  DiscreteIntegrator: '<S132>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S132>/Constant'
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
  /* Start for SwitchCase: '<S61>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S15>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;
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
  /* InitializeConditions for Delay: '<S116>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S24>/Return' */
  /* End of SystemInitialize for SubSystem: '<S17>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Mission' */
  /* InitializeConditions for UnitDelay: '<S91>/Delay Input1'
   *
   * Block description for '<S91>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S22>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S17>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S62>/Motion State' */
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for IfAction SubSystem: '<S61>/Hold Control' */
  /* InitializeConditions for Delay: '<S67>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for UnitDelay: '<S80>/Delay Input1'
   *
   * Block description for '<S80>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S67>/start_wp' */
  FMS_DW.icLoad_f = 1U;

  /* End of SystemInitialize for SubSystem: '<S61>/Hold Control' */

  /* SystemInitialize for Merge: '<S61>/Merge' */
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
